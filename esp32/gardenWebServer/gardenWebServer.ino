//LIBRARIES------------
#include "WiFi.h"
#include "ESPAsyncWebServer.h"

//DEFINITIONS
#define s1 A0
#define s2 A1
#define s3 A2

//VARIABLES
float sensor1=-1;
float sensor2=-1;
float sensor3=-1;
const char* ssid = "Urla e avrai il WiFi.";
const char* password = "";

String sensorRead(){
  //average of 100 samplings
  for (int i = 0; i <= 100; i++) { 
    senso1 = sensor1 + analogRead(s1); 
    senso2 = sensor2 + analogRead(s2); 
    senso3 = sensor3 + analogRead(s3); 
    delay(1); 
  } 
  senso1 = sensor1/100.0; 
  senso2 = sensor2/100.0; 
  senso3 = sensor3/100.0; 
  delay(30);
}

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);  
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });
  // server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
  //   request->send_P(200, "text/plain", readDHTTemperature().c_str());
  // });

  // Start server
  server.begin();
}

void loop() { 

}
