/*
  Capitulo 20 de Arduino desde cero en Español.
  Programa que utiliza el modulo controlador de motor L298N para hacer girar dos
  motores hacia adelante y asi verificar la correcta conexion.

  Autor: bitwiseAr  

*/


int IN1 = 6;      // IN1 a pin digital 2
int IN2 = 7;      // IN2 a pin digital 3
int ENA = 9;      // ENA a pin digital 5
int IN3 = 5;      // IN3 a pin digital 7
int IN4 = 4;      // IN4 a pin digital 8
int ENB = 3;      // ENA a pin digital 9

void setup(){
  pinMode(IN1, OUTPUT);   // IN1 como salida  
  pinMode(IN2, OUTPUT);   // IN2 como salida
  pinMode(ENA, OUTPUT);   // ENA como salida
  pinMode(IN3, OUTPUT);   // IN3 como salida
  pinMode(IN4, OUTPUT);   // IN4 como salida
  pinMode(ENB, OUTPUT);   // ENB como salida
}

void loop(){


  avanzar();
  delay(2000);      // demora de 2 seg.
  avanzarDerecha();
  delay(2000);
  avanzarIzquierda();
  delay(2000);
  detenerse();
  delay(2000);
  retroceder();
  delay(2000);
  retrocederIzquierda();
  delay(2000);
  retrocederDerecha();
  delay(2000);
  detenerse();
  delay(15000);
}

void avanzar(){
  analogWrite(ENA, 120);  // ENA en alto habilita motor A
  digitalWrite(IN1, HIGH); // IN1 en cero logico
  digitalWrite(IN2, LOW);  // IN2 en uno logico

  analogWrite(ENB, 120);  // ENB en alto habilita motor B
  digitalWrite(IN3, HIGH); // IN3 en cero logico
  digitalWrite(IN4, LOW);  // IN4 en uno logico
  }

  void detenerse()
  {
  digitalWrite(ENA, LOW); // ENA en bajo deshabilita motor A
  digitalWrite(ENB, LOW); // ENB en bajo deshabilita motor B
  }

  void avanzarIzquierda() //El motor B tiene que ir mas despacio
  {
    analogWrite(ENA, 120);  // ENA en alto habilita motor A
    digitalWrite(IN1, HIGH); // IN1 en cero logico
    digitalWrite(IN2, LOW);  // IN2 en uno logico

    analogWrite(ENB, 0);  // ENB en alto habilita motor B
    digitalWrite(IN3, HIGH); // IN3 en cero logico
    digitalWrite(IN4, LOW);  // IN4 en uno logico
  }

  void avanzarDerecha() //El motor A debe ir mas despacio
  {
    analogWrite(ENA, 0);  // ENA en alto habilita motor A
    digitalWrite(IN1, HIGH); // IN1 en cero logico
    digitalWrite(IN2, LOW);  // IN2 en uno logico

    analogWrite(ENB, 120);  // ENB en alto habilita motor B
    digitalWrite(IN3, HIGH); // IN3 en cero logico
    digitalWrite(IN4, LOW);  // IN4 en uno logico
  }

  void retroceder()
  {
  analogWrite(ENA, 120);  // ENA en alto habilita motor A
  digitalWrite(IN1, LOW); // IN1 en cero logico
  digitalWrite(IN2, HIGH);  // IN2 en uno logico

  analogWrite(ENB, 120);  // ENB en alto habilita motor B
  digitalWrite(IN3, LOW); // IN3 en cero logico
  digitalWrite(IN4, HIGH);  // IN4 en uno logico
  }

  void retrocederIzquierda() //El motor B debe ir mas despacio
  {
  analogWrite(ENA, 120);  // ENA en alto habilita motor A
  digitalWrite(IN1, LOW); // IN1 en cero logico
  digitalWrite(IN2, HIGH);  // IN2 en uno logico

  analogWrite(ENB, 0);  // ENB en alto habilita motor B
  digitalWrite(IN3, LOW); // IN3 en cero logico
  digitalWrite(IN4, HIGH);  // IN4 en uno logico
  }

void retrocederDerecha() //El motor A debe ir mas despacio
{
  analogWrite(ENA, 0);  // ENA en alto habilita motor A
  digitalWrite(IN1, LOW); // IN1 en cero logico
  digitalWrite(IN2, HIGH);  // IN2 en uno logico

  analogWrite(ENB, 120);  // ENB en alto habilita motor B
  digitalWrite(IN3, LOW); // IN3 en cero logico
  digitalWrite(IN4, HIGH);  // IN4 en uno logico  
}
  
