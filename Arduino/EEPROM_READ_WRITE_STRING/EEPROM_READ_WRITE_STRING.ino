#include <EEPROM.h>

int adress = 0;
String data = "Hello";
String name;
// char name[] = "Smart Home";
//    byte len = (byte)strlen(name);
 




void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
//    pinMode(led,OUTPUT);
//   
//    EEPROM.write(0,len);
//    for(int i = 0; i < len; i++){
//      EEPROM.write(i+1, name[i]);
//    }


}

void loop() {

//byte len = EEPROM.read(0);
//for(int i = 0; i < len; i++){
////   output [i] = (char)EEPROM.read(1 + i);
//  Serial.print((char)EEPROM.read(1 + i));
//}

//  while(Serial.available() == 0){}
//  data = Serial.read();
//  Serial.print(data);
  writeData(data);
  name = getData();
  Serial.println(name);
  delay(2000);
//  if(name == 'h'){
//    Serial.println("Yes");
//  }
}


   void writeData(String data){
    for(int i = 0; i < data.length(); i++){
     EEPROM.write(adress,data[i]);
     Serial.print(data[i]);
     adress++;
    }      
}

char* getData(){
 int len = data.length();
  char* object;
  for(int i = 0; i < len; i++){
   object[i]=(char) EEPROM.read(i);
  }
  return object;
}


