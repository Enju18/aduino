// 3색 LED, DC모터, 온도 센서, LCD
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);

#define RED 8 // DC모터까지 디지털 신호
#define BLUE 9
#define GREEN 10
#define DC_MOTOR 11
#define TEMP_SENSOR A0 // 아날로그 신호

void lcd_init()
{
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
}

void setup()
{
    lcd_init();
    Serial.begin(9600);
    pinMode(DC_MOTOR, OUTPUT);
    pinMode(RED, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(TEMP_SENSOR, INPUT);
}

void lcd_print(int row, int col, char *str)
{
    lcd.setBacklight(1);
    lcd.setCursor(col, row);
    lcd.print(str);
}

int r, g, b;
int val = 255;

void loop()
{
    float voltage = analogRead(TEMP_SENSOR) * 5.0 / 1024.0;
    float temperature = voltage * 100 - 50;
    delay(1000);
    Serial.println(temperature);

    float voltage = analogRead(TEMP_SENSOR) * 5.0 / 1024.0;
    float temperature = voltage * 100 - 50;

    lcd_print(1, 2, "Hello World");
    delay(1000);
    lcd.clear();
    delay(1000);

    analogWrite(DC_MOTOR, val);
    delay(1000);
    val = val - 10;
    if (val < 0)
    {
        val = 255;
    }
}
