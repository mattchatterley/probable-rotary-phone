#include <Servo.h>

const int PIN_BUTTON = 4;
const int PIN_LED = 13;
const int PIN_SERVO = 10;
const int PIN_MOTOR = 11;

const int SERVO_RANGE = 100;
const int SERVO_STEPS = 40;
const int SERVO_DELAY = 15;

int currentButtonState = LOW;

Servo umbrella;
int currentPosition = 0;

void setup() 
{
 Serial.begin(9600);
 Serial.print("Up if raining, down if not raining");

  pinMode(PIN_BUTTON, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_MOTOR, OUTPUT);
  
 currentButtonState = digitalRead(PIN_BUTTON);
 Serial.println(currentButtonState);
 
  umbrella.attach(PIN_SERVO);
}

void loop() 
{
  analogWrite(PIN_MOTOR, 255);
  
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
    while(currentPosition < SERVO_RANGE)
    {
      currentPosition += SERVO_RANGE / SERVO_STEPS;
      umbrella.write(currentPosition);
      delay(SERVO_DELAY);
    }
  } 
  else 
  {
    // turn LED off:
    digitalWrite(PIN_LED, HIGH);

    // move servo UP
    while(currentPosition > 0)
    {
      currentPosition -= SERVO_RANGE / SERVO_STEPS;
      umbrella.write(currentPosition);
      delay(SERVO_DELAY);
    }
  }
}
