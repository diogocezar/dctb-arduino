int incomingValue = 0;
int pinR = 11;
int pinG = 10;
int pinB = 9;
int r = 0;
int g = 0;
int b = 0;
String inputString = "";

void setup()
{
    delay(2000);
    Serial.begin(9600);
    pinMode(pinR, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(pinB, OUTPUT);
}

void loop()
{
    while (Serial.available())
    {
        char inChar = (char)Serial.read();
        switch (inChar)
        {
        case 'R':
            r = inputString.toInt();
            inputString = "";
            break;
        case 'G':
            g = inputString.toInt();
            inputString = "";
            break;
        case 'B':
            b = inputString.toInt();
            inputString = "";
            break;
        default:
            inputString += inChar;
            break;
        }
        delay(50);
    }
    setColor(r, g, b);
    inputString = "";
    printRgb(r, g, b);
    delay(1000);
}

void printRgb(int red, int green, int blue)
{
    Serial.print("LOG => [ R: ");
    Serial.print(red);
    Serial.print(", G: ");
    Serial.print(green);
    Serial.print(", B: ");
    Serial.print(blue);
    Serial.println(" ]");
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
