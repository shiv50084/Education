#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

char* ssid = "******";
char* password = "******";
 
ESP8266WebServer server(80);

void handleRoot() 
{
 server.send(200, "text/html", "Toto je nasa stranka!");
}

void setup(void)
{
  Serial.begin(9600);
  
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
 
  Serial.print("\n");
  Serial.print("Connected to ");
  Serial.print(ssid);
  Serial.print("\n");
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());
  Serial.print("\n");
 
  server.on("/", handleRoot);
  server.begin();
}

void loop(void)
{
  server.handleClient();
}