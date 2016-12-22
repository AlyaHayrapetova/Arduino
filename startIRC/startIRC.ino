#include <ArduinoJson.h>

char data;
String line ;

int jsonBufferSize = 200;

  char json[] = "{\"command\":\"get\",\"count\":1,\"room\":\"R1\",\"device\":\"L1\",\"val\":\"*\"}";
  char multiCommand[] = "{\"command\":\"get\",\"count\":3,\"multiCommand\":[{\"room\":\"R1\",\"device\":\"L1\",\"val\":\"*\"},{\"room\":\"R1\",\"device\":\"L1\",\"val\":\"*\"},{\"room\":\"R1\",\"device\":\"L1\",\"val\":\"*\" }]}";


////




void setup() {
    Serial.begin (250000);
     while (!Serial) {
  }
}
void loop() {
        while(Serial.available() == 0){
         }
        data = Serial.read();
        if (data!='*'&&data!='!'){
           line+=data;
        }
        if (data=='!'){
            line="";
          }
        if (data=='*'){
           Serial.println (line);
           bool sender = checkJsonString(line);
           if (sender){
              line ="";
            }
        }                
}




//////////    CUSTOM METHODS ///////////
bool checkJsonString(String json){
    StaticJsonBuffer<200> jsonBuffer;
    Serial.println(json);
    JsonObject& root = jsonBuffer.parseObject(json);
        // Test if parsing succeeds.
        if (!root.success()) {
          Serial.println("********   ERROR 403   *********");
          return false;
        }


     if (root.containsKey("multiCommand")){
          
          //// call muticommand
          
       }
     else {
        singlCommandPrinter(root);
        singlCommandHandler(root);        
     }    
     return true;
}
bool singlCommandHandler (JsonObject& root){
    String command = root["command"];
    String count = root["count"]; 
    String room = root["room"];
    String device = root["device"];
    int  number = root["number"];
    int val = root["val"];
    
    if (command.equals("set")){
        if (device.equals("light")){
              analogWrite(number,val);         
          }      
      }   
}

void singlCommandPrinter (JsonObject& root){
      String data = root["command"];
      String count = root["count"]; 
      String room = root["room"];
      String device = root["device"];
      String number = root["number"];
      String val = root["val"];
      // Print values.
      Serial.println ("***IRC SYSTEMS COMMAND***");
      Serial.println ("***SINGL COMMAND***");
      Serial.println("command type:"+data);
      Serial.println("command count:"+count);
      Serial.println("room:"+room);
      Serial.println("device:"+device);
      Serial.println("number:"+number);
      Serial.println("value:"+val);
      Serial.println("***********************");
  }
















