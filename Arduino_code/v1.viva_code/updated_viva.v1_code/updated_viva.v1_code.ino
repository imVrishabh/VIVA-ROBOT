#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BT(2,3);
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
#define TRIG_PIN 12
#define ECHO_PIN 13

bool autoMode = false;

void setup()
{
  BT.begin(9600);

  hand.attach(SERVO_PIN);
  hand.write(90);

  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);

  analogWrite(ENA,180);
  analogWrite(ENB,180);

  stopRobot();
}

void loop()
{
  if(BT.available())
  {
    char c=BT.read();

    switch(c)
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

      case 'H':
        shakeHand();
        break;

      case 'A':
        autoMode=true;
        break;

      case 'M':
        autoMode=false;
        stopRobot();
        break;
    }
  }

  if(autoMode)
  {
    obstacleMode();
  }
}

long getDistance()
{
  digitalWrite(TRIG_PIN,LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN,HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN,LOW);

  long duration=pulseIn(ECHO_PIN,HIGH,30000);

  if(duration==0)
    return 999;

  return duration*0.034/2;
}

void obstacleMode()
{
  long distance=getDistance();

  if(distance>40)
  {
    forward();
  }
  else
  {
    stopRobot();

    delay(300);

    backward();

    delay(500);

    stopRobot();

    delay(200);

    right();

    delay(500);

    stopRobot();
  }
}

// ================= Motor Functions =================

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

// ================= Servo =================

void shakeHand()
{
  stopRobot();

  hand.write(180);
  delay(700);

  delay(5000);

  hand.write(90);
  delay(700);
}