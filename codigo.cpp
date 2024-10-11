#include <Servo.h>



const int trigPin = 2;
const int echoPin = 3;
long distancia;
long distancia2;

const int led1 = 4;
const int led2 = 5;
const int led3 = 6;

const int trigPin2 = 7;
const int echoPin2 = 8;

void setup() {
  
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  // Medindo a distância para LED1
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duracao = pulseIn(echoPin, HIGH);
  distancia = duracao * 0.034 / 2;
  

  
  if (distancia < 10) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
  delay(100);

  // Medindo a distância para LED2 e LED3
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  long duracao2 = pulseIn(echoPin2, HIGH);
  distancia2 = duracao2 * 0.034 / 2;             

 
  
  if (distancia2 < 10) {       
    digitalWrite(led2, HIGH);
     // LED3 apagada
  } else if  (distancia2>40) {
    digitalWrite(led3, HIGH);
    digitalWrite(led2, LOW); // LED2 apagada
  } else{
    digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW); 
  }
  
  delay(100);
}
