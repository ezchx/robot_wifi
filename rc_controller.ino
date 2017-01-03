/***********************
 RC Controller
***********************/

// Initialize variables

// Set pins
int enableLeft = 9; // left side enable pin
int pinLeft1 = 2; // left side control pin 1
int pinLeft2 = 3; // left side control pin 2
int enableRight = 6; // right side enable pin
int pinRight1 = 4; // right side control pin 1
int pinRight2 = 5; // right side control pin 2

// Set directional commands
static String forwardCmd = "a"; // forward
static String backwardCmd = "c"; // backward
static String leftCmd = "d"; // left
static String rightCmd = "b"; // right
static String stopCmd = "g"; // stop

// Set other variables
static String inputBuffer;
int motorSpeed = 200; // motor speed


// Setup routine

void setup() {

  // Configure the drive motor pin modes
  pinMode(enableLeft, OUTPUT);
  pinMode(pinLeft1, OUTPUT);
  pinMode(pinLeft2, OUTPUT);
  pinMode(enableRight, OUTPUT);
  pinMode(pinRight1, OUTPUT);
  pinMode(pinRight2, OUTPUT);

  // Open the serial port
  Serial.begin(9600);

}


// Main program

void loop() {
  
  if (Serial.available() > 0) {

    inputBuffer = "";
    inputBuffer.concat((char)Serial.read());

    // forward
    if (inputBuffer == forwardCmd) {
      Serial.println("Forward");
      analogWrite(enableLeft, motorSpeed);
      analogWrite(enableRight, motorSpeed);
      digitalWrite(pinLeft1, HIGH);
      digitalWrite(pinLeft2, LOW);
      digitalWrite(pinRight1, LOW);
      digitalWrite(pinRight2, HIGH);
    }

    // backward
    if (inputBuffer == backwardCmd) {
      Serial.println("Backward");
      analogWrite(enableLeft, motorSpeed);
      analogWrite(enableRight, motorSpeed);
      digitalWrite(pinLeft1, LOW);
      digitalWrite(pinLeft2, HIGH);
      digitalWrite(pinRight1, HIGH);
      digitalWrite(pinRight2, LOW);
    }

    // left
    if (inputBuffer == leftCmd) {
      Serial.println("Left");
      analogWrite(enableLeft, motorSpeed+55);
      analogWrite(enableRight, motorSpeed+55);
      digitalWrite(pinLeft1, LOW);
      digitalWrite(pinLeft2, HIGH);
      digitalWrite(pinRight1, LOW);
      digitalWrite(pinRight2, HIGH);
    }

    // right
    if (inputBuffer == rightCmd) {
      Serial.println("Right");
      analogWrite(enableLeft, motorSpeed+55);
      analogWrite(enableRight, motorSpeed+55);
      digitalWrite(pinLeft1, HIGH);
      digitalWrite(pinLeft2, LOW);
      digitalWrite(pinRight1, HIGH);
      digitalWrite(pinRight2, LOW);
    }

    // stop
    if (inputBuffer == stopCmd) {
      Serial.println("Stop");
      digitalWrite(pinLeft1, HIGH);
      digitalWrite(pinLeft2, HIGH);
      digitalWrite(pinRight1, HIGH);
      digitalWrite(pinRight2, HIGH);
    }

  }

}
