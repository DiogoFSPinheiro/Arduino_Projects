#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SCL, SDA pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

const int sensor = 7;
Servo myServo;
int pos = 0;

void setup() {
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  Serial.begin(9600);
  myServo.attach(9);
  pinMode(sensor, INPUT);
  drawEyes();
  display.display();
}

void drawEyes() {
  // Left Eye
  display.clearDisplay();
  display.fillCircle(40, 20, 20, WHITE); // x, y, radius, color
  display.fillCircle(40, 40, 20, WHITE); // x, y, radius, color
  display.fillRect(20, 20, 41, 20, WHITE); // x, y, largura, altura
  
  // Right Eye
  display.fillCircle(88, 20, 20, WHITE); // x, y, radius, color
  display.fillCircle(88, 40, 20, WHITE); // x, y, radius, color
  display.fillRect(68, 20, 41, 20, WHITE); // x, y, largura, altura
  display.display();
}

void drawEyesWave() {
  // Left Eye
  display.clearDisplay();
  display.fillCircle(40, 30, 20, WHITE); // x, y, radius, color
  display.fillCircle(40, 35, 19, BLACK); // x, y, radius, color

  // Right Eye
  display.fillCircle(88, 30, 20, WHITE); // x, y, radius, color
  display.fillCircle(88, 35, 19, BLACK); // x, y, radius, color
  display.display();
}

void loop() {
  myServo.write(40);
  int c = 0;
  if (digitalRead(sensor) == HIGH)
  {
    drawEyesWave();
    while (c < 10)
    {
      for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        myServo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(2);                      // waits 15ms for the servo to reach the position
      }
      for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees back to 0 degrees
        myServo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(2);                       // waits 15ms for the servo to reach the position
      }
      c++;
      Serial.print(c);
      Serial.print("\n");
    }
    //myServo.write(40);
  }
  drawEyes();
}