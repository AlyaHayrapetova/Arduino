int i=0;
char data;
String temp_command ="";
String command = "null";
String new_command = "";
bool flag  = false;
char n;
char c;


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
//           Serial.println(command.length());
              Serial.println();
              n = getCommandCount(command);
              Serial.println(n);
               // Serial.println(getCommand(command));
               c = getArrayFromCommandNumber(command);
              

              
           


}
}


char getCommandCount(String comm){
  char number;
  for(int i =0; i<comm.length(); i++){
            if(comm[i]=='|'){
              number = comm[i+1];
              break;
            }
            temp_command+=comm[i];
           }
           return number;
//           Serial.println(number);
//           Serial.println(temp_command);
           
     }


 String getCommand(String comm){
  String temp_command = "";
  for(int i =0; i<comm.length(); i++){
            if(comm[i]=='|'){
              break;
            }
            temp_command+=comm[i];
           }
           return  temp_command;     
     }


char getArrayFromCommandNumber(String command){
  int len = getCommandCount(command) - 48;
  Serial.println(len);
  String line = getCommand(command);
  String newArray[len+1];
  int i = 0;

while(i<(len+1)){
  for(int j = 0; j < command.length(); j++){
    if(command[j]== '&'){
     break;
    }
    newArray[i]+=command[j];
  }
  Serial.println(newArray[i]);
  i++;
}
 
}
     



