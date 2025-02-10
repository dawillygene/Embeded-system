#include<ESP8266WIFI.h>
#include<PubSubClient.h>
#include<aREST.h>

WifiClient espClient;
PubSubClient client(espClient);

aREST rest = aREST(client);
char* device_id = "9u2co4";

const char* ssid = "wifi-name";
const char* password = "dawilly";

void setup()
{
  Serial.begin(115200);
  client.setCallback(callback);
   rest.set_id(device_id);
   rest.set_name("device control");


WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
Serial.println("WiFi connected");
char* out_topic = rest.get_topic();
Serial.println("");
}

  }

void loop()
{
  // Connect to the cloud
rest.handle(client);
  }

// Handles message arrived on subscribed topic(s)
void callback(char* topic, byte* payload, unsigned int length) {
rest.handle_callback(client, topic, payload, length);
}

  
