#include "arduino.h"
#include "motor.h"

using namespace std;

motor::motor(int pin1, int pin2, int pin3, int pin4, int penb, int pena)
{
    in1= pin1;
    in2= pin2;
    in3= pin3;
    in4= pin4;
    enb= penb;
    ena= pena;

    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(enb, OUTPUT);
    pinMode(ena, OUTPUT);

}

motor::~motor()
{

}

void motor::reculer()
{
    analogWrite(ena, vitesse);
    analogWrite(enb, vitesse);

    digitalWrite(in4, LOW);
    digitalWrite(in3, HIGH);

    digitalWrite(in2, LOW);
    digitalWrite(in1, HIGH);

    delay(100);

}

void motor::avancer()
{
    analogWrite(ena, vitesse);
    analogWrite(enb, vitesse);

    digitalWrite(in4, HIGH);
    digitalWrite(in3, LOW);

    digitalWrite(in2, HIGH);
    digitalWrite(in1, LOW);

    delay(10);
}

void motor::gauche()
{

    analogWrite(ena, 0);
    analogWrite(enb, vitesse);

    digitalWrite(in4, HIGH); //faite touner les roue de droite
    digitalWrite(in3, LOW);

    digitalWrite(in2, LOW);
    digitalWrite(in1, HIGH);

    delay(10);
    
}

void motor::droite()
{
    analogWrite(ena, vitesse);
    analogWrite(enb, 0);

    digitalWrite(in4, LOW);
    digitalWrite(in3, HIGH);

    digitalWrite(in2, HIGH);
    digitalWrite(in1, LOW);

    delay(10);
    
}

void motor::arret()
{
    digitalWrite(ena, LOW);
    digitalWrite(enb, LOW);

    digitalWrite(in4, LOW);
    digitalWrite(in3, LOW);

    digitalWrite(in2, LOW);
    digitalWrite(in1, LOW);

    delay(20);
  

}
