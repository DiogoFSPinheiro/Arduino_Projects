#define PIN_TRIG 3
#define PIN_ECHO 2

void setup() {
  Serial.begin(9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop() {

  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10); // to get a pulse
  digitalWrite(PIN_TRIG, LOW);

  int duration = pulseIn(PIN_ECHO, HIGH);
  int dist = duration / 58; // to get the value em Centemeters or /148 to get in Inches

  Serial.print("Distance em CM: ");
  Serial.println(dist);

  int pitch = map(dist, 0, 190, 50, 4000); // map the values of the distance to "tone" values

  if (dist > 10) 
  {
    tone(4, pitch);
  } 
  else 
  {
    noTone(4);
  }
  delay(10);
}
