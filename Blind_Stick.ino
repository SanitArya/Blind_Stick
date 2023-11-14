int trig1 = 2;
int echo1 = 3;
int trig2 = 4;
int echo2 = 5;
int trig3 = 6;
int echo3 = 7;
int trig4 = 8;
int echo4 = 9;
int buzzer = 11;
int vibrator = 12;

long duration_1, duration_2, duration_3, duration_4;
float distance_1, distance_2, distance_3, distance_4;

int range = 50;
int bottom_range = 21;

void setup() {
  Serial.begin(9600);

  pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(trig3, OUTPUT);
  pinMode(trig4, OUTPUT);

  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(echo3, INPUT);
  pinMode(echo4, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(vibrator, OUTPUT);

  digitalWrite(buzzer, LOW);
  digitalWrite(vibrator, LOW);

}

void loop() {

  distance_1 = Measure_Distance(trig1, echo1);
  distance_2 = Measure_Distance(trig2, echo2);
  distance_3 = Measure_Distance(trig3, echo3);
  distance_4 = Measure_Distance(trig4, echo4);

  Check_For_Distance();
}

int Measure_Distance(int trig, int echo)
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int duration = pulseIn(echo, HIGH);
  int dis = (duration * 0.034) / 2;
  return dis;
}

void Check_For_Distance()
{
  if (distance_1 < range)
  {
    Produce_Continuous_Sound();
    Serial.print("D1 \n");
  }
  else if (distance_2 < range)
  {
    Produce_Continuous_Sound();
    Serial.print("D2 \n");
  }
  else if (distance_3 < range)
  {
    Produce_Continuous_Sound();
    Serial.print("D3 \n");
  }
  else if (distance_4 > bottom_range)
  {
    Produce_Beep_Sound();
    Serial.print("D4 \n");
  }
  else
  {
    Stop_Sound();
  }
}

void Produce_Continuous_Sound()
{
  digitalWrite(buzzer, HIGH);
  digitalWrite(vibrator, HIGH);
}

void Produce_Beep_Sound()
{
  digitalWrite(buzzer, HIGH);
  digitalWrite(vibrator, HIGH);
  delay(80);
  digitalWrite(buzzer, LOW);
  digitalWrite(vibrator, LOW);
  delay(80);
}

void Stop_Sound()
{
  digitalWrite(buzzer, LOW);
  digitalWrite(vibrator, LOW);
}
