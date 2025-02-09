#include <LCD_screen.h>
#include <LCD_screen_font.h>
#include <LCD_utilities.h>
#include <screen_HX8353E.h>
#include <Terminal12e.h>
#include <Terminal6e.h>
#include <Terminal8e.h>

Screen_HX8353E myScreen;
const int xpin = 23;        // x-axis of the accelerometer
const int ypin = 24;        // y-axis
const int zpin = 25;        // z-axis (only on 3-axis models)

void setup()
{
    Serial.begin(9600);
    myScreen.begin();
    myScreen.setPenSolid(true);
    delay(2000);

    // Clear screen and put header and footer on screen
    myScreen.clear();
}

void loop()
{
    int x = analogRead(xpin);
    int y = analogRead(ypin);
    int z = analogRead(zpin);

    myScreen.gText(20, 30, "X-Axis: " + String(x));
    myScreen.gText(20, 60, "Y-Axis: " + String(y));
    myScreen.gText(20, 90, "Z-Axis: " + String(z));

    // print the sensor values:
    Serial.print((int)x);
    // print a tab between values:
    Serial.print("\t");
    Serial.print(y);
    // print a tab between values:
    Serial.print("\t");
    Serial.print(z);
    Serial.println();

    // delay before next reading:
    delay(100);
}
