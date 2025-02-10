#include "esp_camera.h"
#include <WiFi.h>

//
// WARNING!!! PSRAM IC required for UXGA resolution and high JPEG quality
//            Ensure ESP32 Wrover Module or other board with PSRAM is selected
//            Partial images will be transmitted if image exceeds buffer size
//
//            You must select partition scheme from the board menu that has at least 3MB APP space.
//            Face Recognition is DISABLED for ESP32 and ESP32-S2, because it takes up from 15 
//            seconds to process single frame. Face Detection is ENABLED if PSRAM is enabled as well

// ===================
// Select camera model
// ===================
//#define CAMERA_MODEL_WROVER_KIT // Has PSRAM
//#define CAMERA_MODEL_ESP_EYE // Has PSRAM
//#define CAMERA_MODEL_ESP32S3_EYE // Has PSRAM
//#define CAMERA_MODEL_M5STACK_PSRAM // Has PSRAM
//#define CAMERA_MODEL_M5STACK_V2_PSRAM // M5Camera version B Has PSRAM
//#define CAMERA_MODEL_M5STACK_WIDE // Has PSRAM
//#define CAMERA_MODEL_M5STACK_ESP32CAM // No PSRAM
//#define CAMERA_MODEL_M5STACK_UNITCAM // No PSRAM
#define CAMERA_MODEL_AI_THINKER // Has PSRAM
//#define CAMERA_MODEL_TTGO_T_JOURNAL // No PSRAM
// ** Espressif Internal Boards **
//#define CAMERA_MODEL_ESP32_CAM_BOARD
//#define CAMERA_MODEL_ESP32S2_CAM_BOARD
//#define CAMERA_MODEL_ESP32S3_CAM_LCD

#include "camera_pins.h"

// ===========================
// Enter your WiFi credentials
// ===========================
const char* ssid = "HOSTPOT";
const char* password = "wewe11111";

void startCameraServer();

int blinker = 33;
int ledState = LOW;
int flashlight = 4;
int ldr = 12;
//int reed = 2;

#define timeSeconds 3

const int motionSensor = 14;
const int relay = 13;
// Timer: Auxiliary variables

#define timeSeconds 10

 

// Timer: Auxiliary variables
unsigned long now = millis();
unsigned long lastTrigger = 0;
unsigned long blink_lastTrigger = 0;
boolean startTimer = false;
// Checks if button input was detected, sets LED HIGH and starts a timer

void IRAM_ATTR detectsMovement() {
  Serial.println("MOTION DETECTED!!!");
  digitalWrite(blinker, HIGH);
  // digitalWrite(flashlight, HIGH);
  startTimer = true;
  lastTrigger = millis();
}

void wifi_setup(){
  WiFi.begin(ssid, password);
  WiFi.setSleep(false);

   while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("wifi not connected...");
  }
  
      Serial.println("");
  Serial.println("WiFi connected");

  startCameraServer();

  Serial.print("Camera Ready! Use 'http://");
  Serial.print(WiFi.localIP());
  Serial.println("' to connect");
    

  
  }
 
void setup() {
  Serial.begin(115200);
 Serial.println("Begin setup...");
pinMode(motionSensor, INPUT);
pinMode(ldr, INPUT);
//pinMode(reed, INPUT);

//attachInterrupt(digitalPinToInterrupt(motionSensor), detectsMovement, RISING);
// Set LED to LOW

pinMode(blinker, OUTPUT);
pinMode(relay, OUTPUT);
pinMode(flashlight, OUTPUT);

digitalWrite(relay, HIGH); // turn OFF relay i.e low triggered relay
digitalWrite(flashlight, LOW);
  
  Serial.setDebugOutput(true);
  Serial.println();

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.frame_size = FRAMESIZE_UXGA;
  config.pixel_format = PIXFORMAT_JPEG; // for streaming
  //config.pixel_format = PIXFORMAT_RGB565; // for face detection/recognition
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 12;
  config.fb_count = 1;
  
  // if PSRAM IC present, init with UXGA resolution and higher JPEG quality
  //                      for larger pre-allocated frame buffer.
  if(config.pixel_format == PIXFORMAT_JPEG){
    if(psramFound()){
      config.jpeg_quality = 10;
      config.fb_count = 2;
      config.grab_mode = CAMERA_GRAB_LATEST;
    } else {
      // Limit the frame size when PSRAM is not available
      config.frame_size = FRAMESIZE_SVGA;
      config.fb_location = CAMERA_FB_IN_DRAM;
    }
  } else {
    // Best option for face detection/recognition
    config.frame_size = FRAMESIZE_240X240;
#if CONFIG_IDF_TARGET_ESP32S3
    config.fb_count = 2;
#endif
  }



  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  sensor_t * s = esp_camera_sensor_get();
  // initial sensors are flipped vertically and colors are a bit saturated
  if (s->id.PID == OV3660_PID) {
    s->set_vflip(s, 1); // flip it back
    s->set_brightness(s, 1); // up the brightness just a bit
    s->set_saturation(s, -2); // lower the saturation
  }
  // drop down frame size for higher initial frame rate
  if(config.pixel_format == PIXFORMAT_JPEG){
    s->set_framesize(s, FRAMESIZE_QVGA);
  }

#if defined(CAMERA_MODEL_M5STACK_WIDE) || defined(CAMERA_MODEL_M5STACK_ESP32CAM)
  s->set_vflip(s, 1);
  s->set_hmirror(s, 1);
#endif

#if defined(CAMERA_MODEL_ESP32S3_EYE)
  s->set_vflip(s, 1);
#endif

wifi_setup();

}



void loop() {
      int isDetected = digitalRead(motionSensor);
      int ldr_status = digitalRead(ldr);
      // int reed_status = digitalRead(reed);
      Serial.println("motion variable is "+String(isDetected));
      Serial.println("LDR STATUS is "+String(ldr_status));
     //  Serial.println("REED STATUS is "+String(reed_status));
// if ldr_status is 0 means it's dark therefore the system is activated
if(ldr_status == 0){

// --------- action taken only when it's dark outside -------------
      if(isDetected == 0 ){
      Serial.println("Presence detected");
      digitalWrite(flashlight, HIGH);
    digitalWrite(relay, LOW); //turn relay ON
      startTimer = true;
  lastTrigger = millis();
      delay(3000);
     // wifi_setup();
    }
  
  }
  else{
    digitalWrite(flashlight, LOW);
    digitalWrite(relay, HIGH); //turn relay OFF
    }
      

    if(isDetected == 0){
       digitalWrite(relay, HIGH);//turn relay off
       digitalWrite(flashlight, LOW); // turn flashlight OFF
      }
  // Current time
  now = millis();
  // Turn off the LED after the number of seconds defined in the timeSeconds variable
  if(startTimer && (now - lastTrigger > (timeSeconds*1000))) {
    Serial.println("Motion stopped...");
    digitalWrite(relay, HIGH);
    digitalWrite(flashlight, LOW);
    startTimer = false;
  //  wifi_setup();
  }

  if(now - blink_lastTrigger > 1000){    
         // toggle state of LED
    ledState = !ledState;
    digitalWrite(blinker, ledState);
    //digitalWrite(relay, ledState);
    blink_lastTrigger = millis();
    }
 //wifi_setup();

  
  delay(1000);
 //  delay(10000);
}
