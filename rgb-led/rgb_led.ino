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
    int x, y, z;
    y = z = 0;
    for (x = 255; x > 0; x--, y++, z += 5)
    {
        setColor(x, y, z);
        delay(20);
    }
    // setColor(255, 0, 0);
    // delay(500);
    // setColor(0, 255, 0);
    // delay(500);
    // setColor(0, 0, 255);
    // delay(500);
    // setColor(255, 255, 0);
    // delay(500);
    // setColor(80, 0, 80);
    // delay(500);
    // setColor(0, 255, 255);
    // delay(500);
}

void setColor(int red, int green, int blue)
{
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
    analogWrite(pinR, red);
    analogWrite(pinG, green);
    analogWrite(pinB, blue);
}