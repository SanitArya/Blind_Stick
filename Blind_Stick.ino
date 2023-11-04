#define TRIGGER_PIN1 2
#define ECHO_PIN1 3
#define TRIGGER_PIN2 4
#define ECHO_PIN2 5
#define TRIGGER_PIN3 6
#define ECHO_PIN3 7
#define TRIGGER_PIN4 8
#define ECHO_PIN4 9
#define BUZZER 10
#define VIBRATOR 11

long duration_1, duration_2, duration_3, duration_4;
float distance_1, distance_2, distance_3, distance_4;

void setup() {
  Serial.begin(9600);

  pinMode(TRIGGER_PIN1, OUTPUT);
  pinMode(TRIGGER_PIN2, OUTPUT);
  pinMode(TRIGGER_PIN3, OUTPUT);
  pinMode(TRIGGER_PIN4, OUTPUT);

  pinMode(ECHO_PIN1, INPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(ECHO_PIN3, INPUT);
  pinMode(ECHO_PIN4, INPUT);

  pinMode(BUZZER, OUTPUT);
  pinMode(VIBRATOR, OUTPUT);

  digitalWrite(BUZZER, LOW);
  digitalWrite(VIBRATOR, LOW);

}

void loop() {

  // Sensor No. 01
  digitalWrite(TRIGGER_PIN1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN1, LOW);
  duration_1 = pulseIn(ECHO_PIN1, HIGH);
  distance_1 = (duration_1 * 0.034) / 2;

  // Sensor No. 02
  digitalWrite(TRIGGER_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN2, LOW);
  duration_2 = pulseIn(ECHO_PIN2, HIGH);
  distance_2 = (duration_2 * 0.034) / 2;

  // Sensor No. 03
  digitalWrite(TRIGGER_PIN3, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN3, LOW);
  duration_3 = pulseIn(ECHO_PIN3, HIGH);
  distance_3 = (duration_3 * 0.034) / 2;

  // Sensor No. 04
  digitalWrite(TRIGGER_PIN4, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN4, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN4, LOW);
  duration_4 = pulseIn(ECHO_PIN4, HIGH);
  distance_4 = (duration_4 * 0.034) / 2;

  if (distance_1 < 30 || distance_2 < 30 || distance_3 < 30 || distance_4 < 30)
  {
    digitalWrite(BUZZER, HIGH);
    digitalWrite(VIBRATOR, HIGH);
  }
  else
  {
    digitalWrite(BUZZER, LOW);
    digitalWrite(VIBRATOR, LOW);
  }
}
