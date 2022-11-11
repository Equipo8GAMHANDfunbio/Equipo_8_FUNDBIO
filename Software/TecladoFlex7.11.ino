#include "Keyboard.h"		// incluye libreria Keyboard

int LED1=3;
int LED2=5;
int LED3=7;
int conta=0; 

void setup() {
  pinMode(2,INPUT); //boton
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);

  pinMode(A0,INPUT);	// pin 0A como entrada del flex 41
  pinMode(A1,INPUT);  // pin 1A como entrada del flex 19
  Keyboard.begin();				// inicio de emulacion de teclado
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(2) == HIGH ){// BOTON INICIO
  delay(700);
    if(digitalRead(2) == LOW ){ //contador de aprentar el boton
      conta++;
    if(conta == 4){
      conta=0;
    }
    Serial.println(conta);
    delay(500);

    } 
    if(conta==0){
    if(digitalRead(2)== LOW){
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    Serial.println("APAGADO");
    }
    

  }

    if(conta==1){
    if(digitalRead(2)== LOW){
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    Serial.println("AMARILLO");
    Serial.println("FACIL");
    }
 
  }
  
    if(conta==2){
    if(digitalRead(2)== LOW){
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,LOW);
    Serial.println("ROJO");
    Serial.println("NORMAL");
    }
    
  }

    if(conta==3){
    if(digitalRead(2)== LOW){
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,HIGH);
    Serial.println("VERDE");
    Serial.println("DIFICIL");
    }
  }
  }// BOTON FIN
  //CALCULOS DE FLEX
  //
  float ax=analogRead(A0);
  // //calculo en porcentaje 
  float ay=(ax-997)/19;
  // //mostrar el porcentaje que fue doblado el flex
  // // Serial.println(ay);
  // //CALCULO DEL FLEX2
  float bx=analogRead(A1);
  // //calculo en porcentaje 
  float by=(bx-991)/20;
  // //mostrar el porcentaje que fue doblado el flex
  // // Serial.println(by);

//APAGADO
  if(conta==0){
    Serial.println("CERO");
  }
// FACIL  
  if(conta==1){
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
  }

  //NORMAL
  if(conta==2){
        if (ay>0.54) {		// si el dedo hace flexion 
        Keyboard.press(KEY_LEFT_ARROW);
      }

      if (ay <-0.32) {		// si el dedo hace extension
        Keyboard.press(KEY_RIGHT_ARROW);
      }
      if (ay < 0.54 && ay> -0.32){ // si el dedo esta en reposo
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
  }

  //DIFICL
  if(conta==3){
        if (ay>0.74) {		// si el dedo hace flexion 
        Keyboard.press(KEY_LEFT_ARROW);
      }

      if (ay <-0.60) {		// si el dedo hace extension
        Keyboard.press(KEY_RIGHT_ARROW);
      }
      if (ay < 0.74 && ay> -0.60){ // si el dedo esta en reposo
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
  }
  
}