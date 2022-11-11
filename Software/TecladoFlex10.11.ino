#include "Keyboard.h"		// incluye libreria Keyboard

int LED11=3;  //primer grupo de leds 
int LED12=4;
int LED13=5;
int contaA=0;  //contador del boton 1
int LED21=6;   //segundo grupo de leds
int LED22=8;
int LED23=10;
int contaB=0;  //contador del boton2
int pausaA=1;  //pausa para no spam de APAGADO 
int pausaB=1; //pausa para no spam de APAGADO 

void setup() {
  pinMode(2,INPUT); //declarar como entrada boton1
  pinMode(7,INPUT); //declarar como entrada boton2
  pinMode(3,OUTPUT);  //declarar salidas de los LEDS
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);

  pinMode(A0,INPUT);	// pin 0A como entrada del flex 19 (indice)
  pinMode(A1,INPUT);  // pin 1A como entrada del flex 41 (pulgar)
  Keyboard.begin();				// inicio de emulacion de teclado
  Serial.begin(9600);
}

void loop() {
  //BOTON 1 FLEX 41 (pulgar)
  if(digitalRead(2) == HIGH ){// BOTON1 INICIO
  delay(300);
    if(digitalRead(2) == LOW ){ //contador de aprentar el boton1
      contaA++;
      pausaA=1;
    if(contaA == 4){
      contaA=0;
    }
    Serial.print ("FLEX 41: ");            //muestra en el monitor serie la dificultad de cada flex/dedo 
    Serial.print(contaA);
    Serial.print ("  |  FLEX 19: ");
    Serial.println(contaB);
    }
    if(contaA==0){
    if(digitalRead(2)== LOW){
    digitalWrite(LED11,LOW);
    digitalWrite(LED12,LOW);
    digitalWrite(LED13,LOW);
    Serial.println("APAGADO");
    }
  }

    if(contaA==1){
    if(digitalRead(2)== LOW){
    digitalWrite(LED11,HIGH);
    digitalWrite(LED12,LOW);
    digitalWrite(LED13,LOW);
    Serial.println("ROJO");
    Serial.println("FACIL");
    }
  }
  
    if(contaA==2){
    if(digitalRead(2)== LOW){
    digitalWrite(LED11,LOW);
    digitalWrite(LED12,HIGH);
    digitalWrite(LED13,LOW);
    Serial.println("VERDE");
    Serial.println("NORMAL");
    }   
  }

    if(contaA==3){
    if(digitalRead(2)== LOW){
    digitalWrite(LED11,LOW);
    digitalWrite(LED12,LOW);
    digitalWrite(LED13,HIGH);
    Serial.println("AZUL");
    Serial.println("DIFICIL");
    }
  }
  //FIN BOTON1
  
  // if(contaB==0){
  //   Serial.print ("               APAGADO"); 
  //   Serial.println();
  // }
  // if(contaB==1){
  //   Serial.println("               AMARILLO");
  //   Serial.println("               FACIL");    
  // }
 }
//BOTON 2 que controla al FLEX 19(INDICE)
  if(digitalRead(7) == HIGH ){// BOTON2 INICIO
    delay(300);
    if(digitalRead(7) == LOW ){ //contador de aprentar el boton2
      contaB++;
      pausaB=1;
    if(contaB == 4){
      contaB=0;
    }
    Serial.print ("FLEX 41: ");    //muestra en el monitor serie la dificultad de cada flex/dedo 
    Serial.print(contaA);
    Serial.print ("  |  FLEX 19: ");
    Serial.println(contaB);
    } 

    if(contaB==0){
    if(digitalRead(7)== LOW){
    digitalWrite(LED21,LOW);
    digitalWrite(LED22,LOW);
    digitalWrite(LED23,LOW);
    Serial.println("               APAGADO");
    }
  }

    if(contaB==1){
    if(digitalRead(7)== LOW){
    digitalWrite(LED21,HIGH);
    digitalWrite(LED22,LOW);
    digitalWrite(LED23,LOW);
    Serial.println("               ROJO");
    Serial.println("               FACIL");
    }
  }
  
    if(contaB==2){
    if(digitalRead(7)== LOW){
    digitalWrite(LED21,LOW);
    digitalWrite(LED22,HIGH);
    digitalWrite(LED23,LOW);
    Serial.println("               VERDE");
    Serial.println("               NORMAL");
    } 
  }

    if(contaB==3){
    if(digitalRead(7)== LOW){
    digitalWrite(LED21,LOW);
    digitalWrite(LED22,LOW);
    digitalWrite(LED23,HIGH);
    Serial.println("               AZUL");
    Serial.println("               DIFICIL");
    }
  }
  }// BOTON2 FIN
  //CALCULOS DE FLEXS
  
  //CALCULO DEL FLEX 41 (indice)
  float ax=analogRead(A1);
  //calculo en porcentaje 
  float ay=(ax-997)/19;
  //mostrar el porcentaje que fue doblado el flex
  // Serial.println(by);
  
  //CALCULO FLEX 19 (pulgar)
  float bx=analogRead(A0);
  //calculo en porcentaje 
  float by=(bx-991)/20;
  //mostrar el porcentaje que fue doblado el flex
  // Serial.println(ay);


//APAGADO
  if(contaA==0 && pausaA == 1){
    pausaA=0;
    Keyboard.releaseAll();
    //Serial.println("CERO");
  }
  if(contaB==0 && pausaB == 1){
    pausaB=0;
    Keyboard.releaseAll();
    //Serial.println("               ZERO");
  }

// FACIL  
  if(contaA==1){
    if (ay>0.15) {		// si el dedo hace flexion 
      Keyboard.press(KEY_LEFT_ARROW);
     }
    if (ay <-0.10) {		// si el dedo hace extension
      Keyboard.press(KEY_RIGHT_ARROW);
    }
    if (ay < 0.15 && ay> -0.10){ // si el dedo esta en reposo
      Keyboard.releaseAll(); // para dejar de presionar algun boton si no se hace nada con el dedo
    }
  }
  if(contaB==1){
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
  if(contaA==2){
    if (ay>0.54) {		// si el dedo hace flexion 
      Keyboard.press(KEY_LEFT_ARROW);
    }
    if (ay <-0.32) {		// si el dedo hace extension
      Keyboard.press(KEY_RIGHT_ARROW);
    }
    if (ay < 0.54 && ay> -0.32){ // si el dedo esta en reposo
      Keyboard.releaseAll(); // para dejar de presionar algun boton si no se hace nada con el dedo
    }
  }
  if(contaB==2){
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
  if(contaA==3){
    if (ay>0.74) {		// si el dedo hace flexion 
      Keyboard.press(KEY_LEFT_ARROW);
    }
    if (ay <-0.60) {		// si el dedo hace extension
      Keyboard.press(KEY_RIGHT_ARROW);
    }
    if (ay < 0.74 && ay> -0.60){ // si el dedo esta en reposo
      Keyboard.releaseAll(); // para dejar de presionar algun boton si no se hace nada con el dedo
    }
  }
  if(contaB==3){
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