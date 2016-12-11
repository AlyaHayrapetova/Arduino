char command[] = "update&r1&r2";
int i =0;
char *p = strtok(command,"&");
char *newArray[3];



void setup() {

    Serial.begin(9600);
    while(p!=NULL){
      newArray[i++]=p;
      p = strtok(NULL,"&");
    }
    for(i = 0; i<3; ++i){
      Serial.println(newArray[i]);
    }
}

void loop() {
  // put your main code here, to run repeatedly:

}
