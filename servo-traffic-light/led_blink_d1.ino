#include <Servo.h>

Servo s;

void setup()
{
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    s.attach(D7);
    s.write(0);
}

void loop()
{

    turnOn(D0);
    delay(6000);
    turnOn(D2);
    s.write(180);
    delay(5000);
    turnOn(D1);
    delay(1000);
    s.write(-180);
}

void changeServo(int pos)
{
    Serial.write(pos);
}

void turnOn(int led)
{
    turnAllOff();
    digitalWrite(led, HIGH);
}

void turnAllOff()
{
    digitalWrite(D0, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
}