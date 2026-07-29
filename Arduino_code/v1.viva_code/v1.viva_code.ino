/*
  VIVA Robot
  Features:
  - Bluetooth Control (HC-05)
  - Obstacle Detection (HC-SR04)
  - Auto Mode
  - Manual Mode
  - Servo Handshake
  - L298N Motor Driver
  - 4 Motors (2 Left + 2 Right)

  Bluetooth Commands
  ------------------
  F = Forward
  B = Backward
  L = Left
  R = Right
  S = Stop
  A = Auto Mode
  M = Manual Mode
  H = Hand Shake
*/

#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(2,3);     // RX,TX
Servo hand;

// ---------------- Motor Pins ----------------
#define ENA 5
#define ENB 6

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

// ---------------- Servo ----------------
#define SERVO_PIN 7

// ---------------- Ultrasonic ----------------
#define TRIG 12
#define ECHO 13

bool autoMode=false;

int speedValue=200;

void setup()
{

Serial.begin(9600);
BT.begin(9600);

pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);

pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);

pinMode(TRIG,OUTPUT);
pinMode(ECHO,INPUT);

analogWrite(ENA,speedValue);
analogWrite(ENB,speedValue);

hand.attach(SERVO_PIN);
hand.write(90);

stopRobot();

}

//======================================================

void loop()
{

// Bluetooth Receive

if(BT.available())
{

char cmd=BT.read();

switch(cmd)
{

case 'F':
autoMode=false;
forward();
break;

case 'B':
autoMode=false;
backward();
break;

case 'L':
autoMode=false;
left();
break;

case 'R':
autoMode=false;
right();
break;

case 'S':
autoMode=false;
stopRobot();
break;

case 'A':
autoMode=true;
break;

case 'M':
autoMode=false;
stopRobot();
break;

case 'H':
handShake();
break;

}

}

// Auto Mode

if(autoMode)
{

int d=getDistance();

if(d<=40)
{

stopRobot();
delay(300);

backward();
delay(700);

right();
delay(600);

stopRobot();
delay(200);

}
else
{

forward();

}

}

// Manual Safety

if(!autoMode)
{

int d=getDistance();

if(d<=40)
{

stopRobot();

}

}

}

//======================================================

int getDistance()
{

digitalWrite(TRIG,LOW);
delayMicroseconds(2);

digitalWrite(TRIG,HIGH);
delayMicroseconds(10);

digitalWrite(TRIG,LOW);

long duration=pulseIn(ECHO,HIGH,30000);

int distance=duration*0.034/2;

if(distance==0)
distance=400;

return distance;

}

//======================================================

void forward()
{

digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);

digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);

}

void backward()
{

digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);

digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);

}

void left()
{

digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);

digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);

}

void right()
{

digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);

digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);

}

void stopRobot()
{

digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);

digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);

}

//======================================================

void handShake()
{

stopRobot();

for(int i=90;i<=180;i++)
{
hand.write(i);
delay(10);
}

delay(500);

for(int i=180;i>=90;i--)
{
hand.write(i);
delay(10);
}

}