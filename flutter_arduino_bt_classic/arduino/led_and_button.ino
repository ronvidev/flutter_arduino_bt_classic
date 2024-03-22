uint8_t led = 5;
uint8_t button = 6;
uint8_t bajada = 0;
char data;

void setup()
{
    pinMode(led, OUTPUT);
    pinMode(button, INPUT);
    Serial.begin(9600);
}

void loop()
{
    // Detectar cuando a presionado el botón con flanco de bajada
    if (digitalRead(button) == HIGH && bajada == 0)
    {   
        bajada = 1;
        Serial.write("p");
    }

    if (digitalRead(button) == LOW && bajada == 1) {
        bajada = 0;
    }

    // 
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
