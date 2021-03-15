//LIBRARIES------------
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"
#include "wifi-credentials.h"

//DEFINITIONS
// #define s1 A0
// #define s2 A1
// #define s3 A2

//float sensorPin1 = A0;  
//float sensorPin2 = A1;  
//float sensorPin3 = A2;  

float sensorPin1 = 0;  
float sensorPin2 = 1;  
float sensorPin3 = 2;  



//VARIABLES
float sensor1=-1;
float sensor2=-1;
float sensor3=-1;
const char* ssid = SSID;
const char* password = PASSWORD;

String sensorRead(){
  /*//average of 100 samplings
  for (int i = 0; i <= 100; i++) { 
    sensor1 = sensor1 + analogRead(A0); 
    sensor2 = sensor2 + analogRead(A1); 
    sensor3 = sensor3 + analogRead(A2); 
    delay(1); 
  } 
  sensor1 = sensor1/100.0; 
  sensor2 = sensor2/100.0; 
  sensor3 = sensor3/100.0; 
  delay(30);*/

    sensor1 = sensor1 + digitalRead(0); 
    sensor2 = sensor2 + digitalRead(1); 
    sensor3 = sensor3 + digitalRead(2); 
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

  // Initialize SPIFFS
  if(!SPIFFS.begin()){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html");
  });

  server.on("/values", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", sensorRead().c_str());
  });

  // Start server
  server.begin();
}

void loop() {}
