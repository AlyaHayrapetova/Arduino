int i=0;
char data;
String temp_command ="";
String command = "null";
String new_command = "";
bool flag  = false;
char* new_data;
int adress = 0;


void setup() {
Serial.begin(9600);
}

void loop() {
 
  while(Serial.available() == 0){}
  data = Serial.read();
 if (data != '*'){
   temp_command += data;
 }else {
   command = temp_command;
   flag = true;
   temp_command = "";
   
 }
 Serial.print (i);
 Serial.print (" ");
 Serial.print (command);
 Serial.print (" ");
 Serial.println (data);
 
 i++;
   if (flag){ 
     Serial.flush();
     Serial.print ("command:");
//           Serial.print(command);
           Serial.println();
//           Serial.print(command.length());
              new_data = getArray(command);
              Serial.println(new_data); 

              
     }
     


}


//Put string in array
char* getArray(String name1){
  int len = name1.length();
  char* new_array = (char*)malloc(len + 1);
  if(new_array == NULL)
  exit(1);
  for(int i = 0; i < len; i++){
    new_array[i]=name1[i];
  }
  return new_array;
  
  free(new_array);

}


// void writeData(String data){
//    for(int i = 0; i < data.length(); i++){
//     EEPROM.write(adress,data[i]);
//     Serial.print(data[i]);
//     adress++;
//    }      
//}
//
//char* getData(){
// int len = data.length();
//  char* object;
//  for(int i = 0; i < len; i++){
//   object[i]=(char) EEPROM.read(i);
//  }
//  return object;
//}




