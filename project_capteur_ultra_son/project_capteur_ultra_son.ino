

AF_DCMotor top_left(4);
AF_DCMotor top_right(5);
AF_DCMotor bottom_left(6);
AF_DCMotor bottom_right(7);


int  TRIGGER_PIN = 2; // Broche TRIGGER
int  ECHO_PIN = 3;    // Broche ECHO
 
void setup() 
{
   /* Initialise le port série */
  Serial.begin(115200);
   
  /* Initialise les broches */
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);

  
  top_left.setSpeed(200);
  top_right.setSpeed(200);
  bottom_left.setSpeed(200);
  bottom_right.setSpeed(200);
//  motor.run(RELEASE);
}

void loop() 
{
  uint8_t i;

  /* 1. Lance une mesure de distance sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  mesure = pulseIn(echo,HIGH);
  dist = mesure /58;
  

  if (dist < 50) {
     top_left.run(RELEASE);
      top_right.run(RELEASE);
      bottom_left.run(RELEASE);
      bottom_right.run(RELEASE);

      top_left.run(BACKWARD);
      top_right.run(BACKWARD);
      bottom_left.run(BACKWARD);
      bottom_right.run(BACKWARD); 
      delay(2000);
    } else {
       top_left.setSpeed(128);
        top_right.setSpeed(128);
        bottom_left.setSpeed(128);
        bottom_right.setSpeed(128);
      
        top_left.run(BACKWARD);
        top_right.run(BACKWARD);
        bottom_left.run(BACKWARD);
        bottom_right.run(BACKWARD);
        delay(2000);
    }
  

 
  delay(1500);
}
