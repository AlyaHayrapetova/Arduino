int i=0;
char data;
String temp_command ="";
String command = "null";
String new_command = "";
bool flag  = false;


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
           Serial.print (command);
           Serial.println(command.length());
     }


}


