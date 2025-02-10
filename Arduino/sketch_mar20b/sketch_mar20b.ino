#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YOUR_SSID";  // Replace with your network name
const char* password = "YOUR_PASSWORD";  // Replace with your network password

WebServer server(80);  // Create a web server listening on port 80

const int ledPin = 2;  // Set the LED pin number

void handleRoot() {
  String html = "<!DOCTYPE html>\n";
  html += "<html>\n";
  html += "<head>\n";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>\n";
  html += "<style>\n";
  html += "button {";
  html += "font-size: 20px;";
  html += "padding: 10px 20px;";
  html += "border-radius: 5px;";
  html += "background-color: #4CAF50;";
  html += "color: white;";
  html += "}\n";
  html += "</style>\n";
  html += "</head>\n";
  html += "<body>\n";
  html += "<button onclick='toggleLED()'>Toggle LED</button>\n";
  html += "<script>\n";
  html += "function toggleLED() {\n";
  html += "var xhr = new XMLHttpRequest();\n";
  html += "xhr.open('GET', '/led', true);\n";
  html += "xhr.send();\n";
  html += "}\n";
  html += "</script>\n";
  html += "</body>\n";
  html += "</html>\n";
  server.send(200, "text/html", html);
}

void handleLED() {
  static bool ledState = false;
  ledState = !ledState;  // Toggle the LED state
  digitalWrite(ledPin, ledState);
  server.send(200, "text/plain", "LED state toggled");
}

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  // Turn off the LED initially
  
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
  
  server.on("/", handleRoot);
  server.on("/led", handleLED);
  server.begin();
}

void loop() {
  server.handleClient();
}
