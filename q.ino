// 3색 LED, DC모터, 온도 센서
#define RED 13 
#define BLUE 12
#define GREEN 11
#define DC_MOTOR 10
#define TEMP_SENSOR A0

void setup()
{
    pinMode(DC_MOTOR, OUTPUT);
    pinMode(RED, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(TEMP_SENSOR, INPUT);
    Serial.begin(9600);
}

void loop()
{
    float voltage = analogRead(TEMP_SENSOR) * 5.0 / 1024.0;
    float temperature = voltage * 100 - 50;
    Serial.println(temperature);

    if (temperature <= 20) {
      digitalWrite(RED, LOW);
      digitalWrite(BLUE, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(DC_MOTOR, LOW);
    }

    else if (temperature <= 21) {
      digitalWrite(RED, LOW);
      digitalWrite(BLUE, LOW);
      digitalWrite(GREEN, HIGH);
      digitalWrite(DC_MOTOR, LOW);
    }

    else if (temperature <= 30) {
      digitalWrite(RED, LOW);
      digitalWrite(BLUE, LOW);
      digitalWrite(GREEN, HIGH);
      digitalWrite(DC_MOTOR, LOW);
    }

    else
      digitalWrite(RED, HIGH);
      digitalWrite(BLUE, LOW);
      digitalWrite(GREEN, LOW);
      digitalWrite(DC_MOTOR, HIGH);
}
