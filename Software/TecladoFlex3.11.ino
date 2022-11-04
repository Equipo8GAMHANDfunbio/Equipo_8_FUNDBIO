#include "Keyboard.h"		// incluye libreria Keyboard

int LED1=3;
int LED2=5;
int LED3=7;
int estadoLed=1;
int boton=2;  

void setup() {
  pinMode(2,INPUT); //boton
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);

  pinMode(A0,INPUT);	// pin 0A como entrada del flex
  pinMode(A1,INPUT);
  Keyboard.begin();				// inicio de emulacion de teclado
}

void loop() {
  float ax=analogRead(A0);
  //calculo en porcentaje 
 float ay=(ax-992)/19;
  //mostrar el porcentaje que fue doblado el flex
  Serial.println(ay);
  //CALCULO DEL FLEX2
  float bx=analogRead(A1);
  //calculo en porcentaje 
  float by=(bx-991)/20;
  //mostrar el porcentaje que fue doblado el flex
  Serial.println(by);
  
  if (digitalRead(2)==1){
    estadoLed++;
    if(estadoLed==4){
      estadoLed=0;
    }
    }
    switch(estadoLed){
      case 0:

      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
      Serial.println("APAGADO");
      break;
      case 1:
      //facil
      if (ay>0.15) {		// si el dedo hace flexion 
        Keyboard.press(KEY_LEFT_ARROW);
      }

      if (ay <-0.10) {		// si el dedo hace extension
        Keyboard.press(KEY_RIGHT_ARROW);
      }
      if (ay < 0.15 && ay> -0.10){ // si el dedo esta en reposo
       Keyboard.releaseAll(); // para dejar de presionar algun boton si no se hace nada con el dedo
      }

       if (by>0.14) {		// si el dedo hace flexion 
        Keyboard.press(KEY_DOWN_ARROW);
      }

      if (by <-0.09) {		// si el dedo hace extension
        Keyboard.press(KEY_UP_ARROW);
      }
      if (by < 0.14 && by> -0.09){ // si el dedo esta en reposo
       Keyboard.releaseAll(); // para dejar de presionar algun boton si no se hace nada con el dedo
      }
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
      Serial.println("AMARILLO");

      break;
      case 2:
      //normal
        if (ay>0.30) {		// si el dedo hace flexion 
        Keyboard.press(KEY_LEFT_ARROW);
      }

      if (ay <-0.20) {		// si el dedo hace extension
        Keyboard.press(KEY_RIGHT_ARROW);
      }
      if (ay < 0.30 && ay> -0.20){ // si el dedo esta en reposo
       Keyboard.releaseAll(); // para dejar de presionar algun boton si no se hace nada con el dedo
      }

       if (by>0.39) {		// si el dedo hace flexion 
        Keyboard.press(KEY_DOWN_ARROW);
      }

      if (by <-0.19) {		// si el dedo hace extension
        Keyboard.press(KEY_UP_ARROW);
      }
      if (by < 0.39 && by> -0.19){ // si el dedo esta en reposo
       Keyboard.releaseAll(); // para dejar de presionar algun boton si no se hace nada con el dedo
      }
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);
      Serial.println("VERDE");
      break;
      case 3:
      //dificl
        if (ay>0.54) {		// si el dedo hace flexion 
        Keyboard.press(KEY_LEFT_ARROW);
      }

      if (ay <-0.30) {		// si el dedo hace extension
        Keyboard.press(KEY_RIGHT_ARROW);
      }
      if (ay < 0.54 && ay> -0.30){ // si el dedo esta en reposo
       Keyboard.releaseAll(); // para dejar de presionar algun boton si no se hace nada con el dedo
      }

       if (by>0.64) {		// si el dedo hace flexion 
        Keyboard.press(KEY_DOWN_ARROW);
      }

      if (by <-0.29) {		// si el dedo hace extension
        Keyboard.press(KEY_UP_ARROW);
      }
      if (by < 0.64 && by> -0.29){ // si el dedo esta en reposo
       Keyboard.releaseAll(); // para dejar de presionar algun boton si no se hace nada con el dedo
      }
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,HIGH);
      Serial.println("ROJO");
      break;
    }
  while(digitalRead(2)==1){ //anti rebote

  }
}