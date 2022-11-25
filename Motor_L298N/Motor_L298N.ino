#include <RH_ASK.h>
#include <SPI.h>

 RH_ASK rf_driver;

//motor 1
int ENA = 9;
int IN1 = 7;
int IN2 = 6;

//motor 2
int IN3 = 5;
int IN4 = 4;
int ENB = 3;



void setup ()
{

  rf_driver.init();
  Serial.begin(57600);

  // Declaramos todos los pines como salidas

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENB, OUTPUT);

  //Serial.begin(9600);

}

uint8_t buff[5];
uint8_t bufflen = sizeof(buff);

void loop()
{

  
  float numero;
  String salida ="";
   if(rf_driver.recv(buff, &bufflen)){
      
      salida =+((char*)buff);
      
      numero = salida.toFloat();
      Serial.print(numero);
      Serial.print('\n');
 


      if ((numero > -4.0) && (numero < 4.0)){
        detener();
        Serial.print("detener");
        Serial.print('\n');
      }
      else if (numero < -4.0){
        adelante();
        Serial.print("abajo");
        Serial.print('\n');
      }
      else if (numero > 4.0){
        atras();
        Serial.print("arriba");
        Serial.print('\n');
      }

      
    }



/*
  if (Serial.available()){
      char inByte = Serial.read();
      if (inByte == 'w'){
        Serial.write("ingresada una w");
        adelante();
        delay(100);
        detener();
      }
      else if (inByte == 's'){
        Serial.write("ingresada una s");
        atras();
        delay(100);
        detener();
      }
      else if (inByte == 'e'){
        Serial.write("ingresada una s");
        adelanteYderecha();
        delay(100);
        detener();
      }
      else if (inByte == 'q'){
        Serial.write("ingresada una s");
        adelanteEizquierda();
        delay(100);
        detener();
      }
  }
 
  */


}

void adelante()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  //delay(500);
}

void atras()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  //delay(500);

}
void izquierda()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  //delay(500);
}

void derecha()
{

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  //delay(500);
}

void adelanteYderecha(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 100);
  analogWrite(ENB, 150);
}

void adelanteEizquierda(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 100);
}

void bajarMarcha(){
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
}

void detener(){
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
