int pinR = 11;
int pinG = 10;
int pinB = 9;

void setup()
{
    delay(5000);
    pinMode(pinR, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(pinB, OUTPUT);
}

void loop()
{
    setColor(255, 0, 0);
    delay(500);
    setColor(0, 255, 0);
    delay(500);
    setColor(0, 0, 255);
    delay(500);
    setColor(255, 255, 0);
    delay(500);
    setColor(80, 0, 80);
    delay(500);
    setColor(0, 255, 255);
    delay(500);
}
