#define  led_red 11
#define  led_gre 10
#define  led_blu 9
#define wait_time 2000

void setup() {
  Serial.begin(9600);
  pinMode(led_red, OUTPUT);
  pinMode(led_gre, OUTPUT);
  pinMode(led_blu, OUTPUT);

  // put your setup code here, to run once:

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
   {analogWrite(led, color);
   delay(5);
   }

}

void loop() {
    int l = random(9,12);
    flow(l);
    Serial.print(l);
    delay(500);
    

}
