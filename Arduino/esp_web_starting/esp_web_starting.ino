#include <ESP8266WiFi.h>

// Replace with your network credentials
const char* ssid = "BRODAH GENE";
const char* password = "genedawilly";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  // Connect to Wi-Fi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");  
  
  // Start the server
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Wait for a client to connect
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait for the client to send a request
  Serial.println("New client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  
  // Return a response
  String response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  response += "<!DOCTYPE HTML>\r\n<html>\r\n";
  response += "<head><title>ESP8266 Web Server</title></head>\r\n";
  response += "<body><h1>Welcome Dawilly Gene!</h1></body>\r\n";
  response += "<form>\r\n";
  response += "<input  id="">\r\n";
  response += "<input type="password" name="" id="" placeholder="Enter your password">\r\n";
  response += "<input type="submit">\r\n";
  response += "</form>\r\n";
  response += "</body>\r\n";
  response += "</html>\r\n";
  client.print(response);
  
  // Wait for the client to close the connection
  delay(1);
  Serial.println("Client disconnected");
}
