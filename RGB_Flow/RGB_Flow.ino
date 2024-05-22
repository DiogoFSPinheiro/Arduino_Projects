#define  led_red 11
#define  led_gre 10
#define  led_blu 9
#define  wait_time 2000

void setup() 
{
  Serial.begin(9600);
  pinMode(led_red, OUTPUT);
  pinMode(led_gre, OUTPUT);
  pinMode(led_blu, OUTPUT);
}

void flow(int led)
{
  int color = 0;
  while(color++ < 255)
  {
    analogWrite(led, color);
    delay(5);
  }
  while(color-- > 0)
  {
    analogWrite(led, color);
    delay(5);
  }
}

void loop() 
{
    flow(random(9,12));
    delay(500);
}
