#include <Servo.h>

const int PIN_BUTTON = 4;
const int PIN_LED = 13;
const int PIN_SERVO = 10;

const int SERVO_RANGE = 60;
const int SERVO_STEPS = 20;
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

 currentButtonState = digitalRead(PIN_BUTTON);
 Serial.println(currentButtonState);
 
  umbrella.attach(PIN_SERVO);
  umbrella.write(currentPosition);
}

void loop() 
{
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
    while(currentPosition > (-1 * SERVO_RANGE))
    {
      Serial.println(currentPosition);

      currentPosition -= SERVO_RANGE / SERVO_STEPS;
      umbrella.write(currentPosition);
      delay(SERVO_DELAY);
    }
  } 
  else 
  {
    // turn LED off:
    digitalWrite(PIN_LED, HIGH);

    // move servo UP
    while(currentPosition < SERVO_RANGE)
    {
      Serial.println(currentPosition);

      currentPosition += SERVO_RANGE / SERVO_STEPS;
      umbrella.write(currentPosition);
      delay(SERVO_DELAY);
    }
  }
}
