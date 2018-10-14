#include <Servo.h>

const int PIN_BUTTON = 4;
const int PIN_LED = 13;
const int PIN_SERVO = 10;
const int PIN_MOTOR = 11;

const int SERVO_RANGE = 50;
const int SERVO_STEPS = 20;
const int SERVO_DELAY = 15;

const int MOTOR_MIN = 0;
const int MOTOR_MAX = 255;
const int MOTOR_STEPS = 9;

Servo umbrella;

int currentPosition = SERVO_RANGE;
int currentButtonState = LOW;

int windForce = 0;

void setup() 
{
 Serial.begin(9600);
 Serial.print("Up if raining, down if not raining");

  pinMode(PIN_BUTTON, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_MOTOR, OUTPUT);

 currentButtonState = digitalRead(PIN_BUTTON);
 Serial.println(currentButtonState);

  umbrella.write(SERVO_RANGE * 2);
  umbrella.attach(PIN_SERVO);
  umbrella.write(SERVO_RANGE * 2);

// analogWrite(PIN_MOTOR, MOTOR_MIN);
}

void loop() 
{
//  analogWrite(PIN_MOTOR, 255);
  
  int newButtonState = digitalRead(PIN_BUTTON);

  if(newButtonState != currentButtonState)
  {
    currentButtonState = newButtonState;
    Serial.println(currentButtonState == HIGH ? "RAINING" : "NOT RAINING");
  }

  if (currentButtonState == HIGH) 
  {
    // turn LED on:
    digitalWrite(PIN_LED, LOW);

    // move servo DOWN
    while(currentPosition > 0)
    {
      currentPosition -= SERVO_RANGE / SERVO_STEPS;
      umbrella.write(currentPosition);
      delay(SERVO_DELAY);
    }
      Serial.println(currentPosition);
  } 
  else 
  {
    // turn LED off:
    digitalWrite(PIN_LED, HIGH);

    // move servo UP
    while(currentPosition < (SERVO_RANGE * 2))
    {
      currentPosition += SERVO_RANGE / SERVO_STEPS;
      umbrella.write(currentPosition);
      delay(SERVO_DELAY);
    }

        Serial.println(currentPosition);
}
}

/*
 *  char test[] = "This,is,a,test,of,the,string,tokenizer,function";

   char *a;
   char *brkb;

   a = strtok_r(test, "," ,&brkb);
   Serial.print("1: ");
   Serial.println(a);
   
 */
