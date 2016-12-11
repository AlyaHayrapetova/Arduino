int i=0;
char data;
String temp_command ="";
String command = "null";
String new_command = "";
bool flag  = false;
char n;
String c;
char name2;


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
              c = getCommand(command);
//            Serial.println(c);
//            name2  = getArrayFromCommandNumber(c);
//            Serial.println(name2);
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


char* getArrayFromCommandNumber(char command){
  char line [] ="(String) getCommand((String)command)"; //string for split
  int len = getCommandCount((String)command) - 48; // newArray size
  Serial.println(len+1);
  char *p = strtok(line,"&");
  char* newArray[len+1]; //newArray
  char *b;
  int i = 0;

  while(p!=NULL){
    newArray[i++] = p;
    p = strtok(NULL,"&");
  }
//  for(i = 0; i < (len+1); i++){
//    Serial.println(newArray[i]);
//  }
return newArray;



}
     



