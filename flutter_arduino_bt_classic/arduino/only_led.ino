uint8_t led = 5;
char data;

void setup()
{
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    if (Serial.available() > 0)
    {
        data = Serial.read();
    }
    switch (data)
    {
    case '1':
        digitalWrite(led, HIGH);
        break;

    case '0':
        digitalWrite(led, LOW);
        break;

    default:
        break;
    }
    
    delay(10);
}
