#include <Arduino.h>

#define pinLEDR 8 //LED ROJO PIN 8 
#define pinLEDV 9 //LED VERDE PIN 9
#define pinLEDA 10 //LED AMARILLO PIN 10
#define pinLEDS 11// PULSADOR 
int CONT=0;

int STOP=0;
int READY=1;
int START=2;
int BANDERA=0;
char DATA=0;
int ESTADOPULS=0;
int CANTPULS=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinLEDV, OUTPUT);
  pinMode(pinLEDR, OUTPUT);
  pinMode(pinLEDA, OUTPUT);
  pinMode(pinLEDS, INPUT);
 
}

void loop() {
  if (Serial.available()>0)
  {
    DATA=Serial.read();
  
    switch(DATA){


        case 'r':
        
//            Serial.println(DATA);
            digitalWrite (pinLEDR,LOW);
            digitalWrite (pinLEDV, HIGH);
            digitalWrite (pinLEDA, LOW);
            BANDERA=READY;
            break;
        
        case 's':
 //           Serial.println(DATA);
            digitalWrite (pinLEDR, LOW);
            digitalWrite (pinLEDV, LOW);
            digitalWrite (pinLEDA, HIGH);
            BANDERA=START;
            break;
        
        case 'S':
 //           Serial.println(DATA);
            digitalWrite (pinLEDR,HIGH);
            digitalWrite (pinLEDV, LOW);
            digitalWrite (pinLEDA, LOW);
            BANDERA=STOP;
            CONT=0;
            break;
        
        default:
          digitalWrite (pinLEDR,HIGH);
          digitalWrite (pinLEDV,HIGH);
          digitalWrite (pinLEDA,HIGH);
          break;
    }  

  } 
    
  else {
    if(BANDERA==READY)
    {
      ESTADOPULS=digitalRead(pinLEDS);
      if (ESTADOPULS==1){
        CONT=CONT+1;
        CANTPULS=CONT;
        Serial.write(CANTPULS);
      }
      
    }
    
  }
  // put your main code here, to run repeatedly:
  

}
