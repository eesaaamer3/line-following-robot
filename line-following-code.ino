// Eesa Aamer 
// Date Created: 06/05/19
// Last Modified: 06/06/19
// This program serves as the main code the robot uses for line-following

//Motor A
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293
//Motor B
const int motorPin3  = 10; // Pin  7 of L293
const int motorPin4  = 9;  // Pin  2 of L293
// Ultrasonic Sensor Output Ports
const int trigPin = 12;
const int echoPin = 13;

// Defines variables for Ultrasonic Sensor 
long duration;
int distance;

void setup(){
 
    // DC Motors
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);

    // Ultrasonic Sensor
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication    
}

void loop(){

  // Infrared Sensors
  digitalWrite(trigPin, LOW); // trigPin is always set to low at the start
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); // trigPin set to high for 10 microseconds generates an ultrasound wave
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // trigPin is turned off
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration*0.034/2;

  
  if ((RCTime(3) > 50) && (RCTime(2) > 50) && (RCTime(4) > 50)) { // If all three sensors detect a black line, the robot stops 
   analogWrite(motorPin1, 0);
   analogWrite(motorPin2, 0);
   analogWrite(motorPin3, 0);
   analogWrite(motorPin4, 0);
  } else if (RCTime(3) > 50 && RCTime(4) > 50) { // If the middle and left sensor detect a black line, the right motor is turned on to turn the robot slightly left
   analogWrite(motorPin1, 140);
   analogWrite(motorPin2, 0);
   analogWrite(motorPin3, 0);
   analogWrite(motorPin4, 0);
  } else if (RCTime(3) > 50 && RCTime(2) > 50) { // If the middle and right sensor detect a black line, the left motor is turned on to turn the robot slightly right
   analogWrite(motorPin1, 0);
   analogWrite(motorPin2, 0);
   analogWrite(motorPin3, 80);
   analogWrite(motorPin4, 0);
  } else if (RCTime(4) > 20) { // If only the left sensor detects a black line, the left motor is turned on to make a hard right
   analogWrite(motorPin1, 100);
   analogWrite(motorPin2, 0);
   analogWrite(motorPin3, 0);
   analogWrite(motorPin4, 0);
  } else if (RCTime(2) > 50) { // If only the right sensor detects a black line, the right motor is turned on to make a hard left 
   analogWrite(motorPin1, 0);
   analogWrite(motorPin2, 0);
   analogWrite(motorPin3, 120);
   analogWrite(motorPin4, 0);
  } else if (RCTime(3) > 50) { // If only the middle sensor detects a black line, both motors are turned on to make the robot go straight 
   analogWrite(motorPin1, 140);
   analogWrite(motorPin2, 0);
   analogWrite(motorPin3, 120);
   analogWrite(motorPin4, 0);
  } else { // If no sensor detects a black line, the robot does not move
   analogWrite(motorPin1, 0);
   analogWrite(motorPin2, 0);
   analogWrite(motorPin3, 0);
   analogWrite(motorPin4, 0);
    
  }

  if (distance < 10) { // If the ultrasonic sensor detects an object less than 10 centimetres away from the robot, the motors will stop 
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  }
  
}

// Runs the infrared sensors and returns the reflectivity of the surface on a scale from 0 to 2000
long RCTime(int sensorIn){
   long duration = 0;
   pinMode(sensorIn, OUTPUT);     // Make pin OUTPUT
   digitalWrite(sensorIn, HIGH);  // Pin HIGH (discharge capacitor)
   delay(1);                      // Wait 1ms
   pinMode(sensorIn, INPUT);      // Make pin INPUT
   digitalWrite(sensorIn, LOW);   // Turn off internal pullups
   while(digitalRead(sensorIn)){  // Wait for pin to go LOW
      duration++;
   }
   return duration;
}
