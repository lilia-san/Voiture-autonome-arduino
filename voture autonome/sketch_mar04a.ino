// Motor  connections
int motor_en = 9;
int motor_in1 = 11;
int motor_in2 = 12;

//capteur de proximiter a ultrasong
  #include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position


void setup() {
  // Set all the motor control pins to outputs
  pinMode(motor_en, OUTPUT);
  pinMode(motor_in1, OUTPUT);
  pinMode(motor_in2, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(motor_in1, LOW);
  digitalWrite(motor_in2, LOW);
  //capteur de proximiter
    myservo.attach(2);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  objet();
  speedControl();
  delay(1000);
 
}


int objet() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

// This function lets you control speed of the motors
void speedControl() {
  // Turn on motors
  digitalWrite(motor_in1, HIGH);
  digitalWrite(motor_in2, HIGH);
  
  // Accelerate from zero to maximum speed
  for (int i = 0; i < 120; i++) {
    analogWrite(motor_en, i);
    delay(100);
//    if ()
  }
  
  // Decelerate from maximum speed to zero
  for (int i = 120; i >= 0; --i) {
    analogWrite(motor_en, i);
    delay(100);
  }
  
  // Now turn off motors
  digitalWrite(motor_in1, LOW);
  digitalWrite(motor_in2, LOW);
}
