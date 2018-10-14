#include <Servo.h>

const int PIN_LED = 13;
const int PIN_SERVO = 10;

const int SERVO_MAX = 95;
const int SERVO_MIN = 5;

const int SERVO_STEPS = 40;
const int SERVO_DELAY = 15;

const int FLASH_COUNT = 2;
const int FLASH_DELAY = 250;

int windSpeed = 0;
bool windQuiteHigh = false;
bool windTooHigh = false;

int precipitationChance = 0;

Servo umbrella;
int currentPosition = 0;
int targetPosition = SERVO_MAX;

void setup() 
{
 Serial.begin(9600);

  pinMode(PIN_LED, OUTPUT);
  
  while(!Serial)
 {
 }

  umbrella.attach(PIN_SERVO);
}

void loop() 
{
  if(Serial.available())
  {
    String command = Serial.readString();

    switch(command.charAt(0))
    {
      case 'w':
      case 'W':
        windSpeed = command.substring(1).toInt();
        windQuiteHigh = windSpeed > 30;
        windTooHigh = windSpeed > 40;

        Serial.println("Wind: " + String(windSpeed) + "kmh");

        if(windQuiteHigh && !windTooHigh)
        {
          Serial.println("That's quite high. Light on.");
        }

        if(windTooHigh)
        {
          Serial.println("That's very high, FLASH!");
        }
      break;
      case 'p':
      case 'P':
        precipitationChance = command.substring(1).toInt();
        targetPosition = 100 - precipitationChance;

        Serial.println("Precip Chance: " + String(precipitationChance) + "%");
        Serial.println("Servo position " + String(targetPosition) + "deg");
      break;
    }
  }

  if(windQuiteHigh && !windTooHigh)
  {
    digitalWrite(PIN_LED, HIGH);
  }
  else
  {
    if(windTooHigh)
    {
      for(int i=0;i<FLASH_COUNT;i++)
      {
        digitalWrite(PIN_LED, HIGH);
        delay(FLASH_DELAY);
        digitalWrite(PIN_LED, LOW);
        delay(FLASH_DELAY);
      }
    }
    else
    {
    digitalWrite(PIN_LED, LOW);      
    }
  }  

  targetPosition = targetPosition > SERVO_MAX ? SERVO_MAX : targetPosition;
  targetPosition = targetPosition < SERVO_MIN ? SERVO_MIN : targetPosition;

    while(currentPosition > targetPosition)
    {
      if((currentPosition - targetPosition) < (SERVO_MAX / SERVO_STEPS))
      {
        currentPosition = targetPosition;
      }
      else
      {
      currentPosition -= SERVO_MAX / SERVO_STEPS;
      }
      umbrella.write(currentPosition);
      delay(SERVO_DELAY);
    }

    while(currentPosition < targetPosition)
    {
      if((targetPosition - currentPosition) < (SERVO_MAX / SERVO_STEPS))
      {
        currentPosition = targetPosition;
      }
      else
      {
      currentPosition += SERVO_MAX / SERVO_STEPS;
      }

      umbrella.write(currentPosition);
      delay(SERVO_DELAY);
    }
}
