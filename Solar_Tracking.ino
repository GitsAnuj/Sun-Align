#include <Servo.h>

#define eastLDR A0
#define westLDR A1
Servo servo ;



//int westLDR = 1;

int east = 0;

int west = 0;

int error = 0;

int calibration = 600;

int servoposition = 90;

void setup()

{

  servo.attach(9);
  Serial.begin(9600);

}

void loop()

{

  east = calibration + analogRead(eastLDR);

  west = analogRead(westLDR);
  Serial.print("Westr");
  Serial.println(analogRead(eastLDR));
  Serial.print("East");
  Serial.println(analogRead(eastLDR));

  if (east < 350 && west < 350)

  {

    while (servoposition <= 150)

    {

      servoposition++;

      servo.write(servoposition);

      delay(100);

    }

  }

  error = east - west;

  if (error > 15)

  {

    if (servoposition <= 150)

    {

      servoposition++;

      servo.write(servoposition);

    }

  }

  else if (error < -15)

  {

    if (servoposition > 20)

    {

      servoposition--;

      servo.write(servoposition);

    }

  }

  delay(1000);

}