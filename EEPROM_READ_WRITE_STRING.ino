#include <EEPROM.h>

int adress = 0;
char data;
char* name;
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

  while(Serial.available() == 0){}
  data = Serial.read();
  Serial.println(data);
  writeData(data);
  name = getData();
  Serial.println(name);
  delay(1000);
  if(name == "on"){
    Serial.println("Yes");
  }
}


   void writeData(char data){
    EEPROM.write(adress,data);      
}

char* getData(){
  byte len = EEPROM.read(adress);
  char* object;
  for(int i = 0; i < len; i++){
   object[i]= EEPROM.read(i);
  }
  return object;
}


