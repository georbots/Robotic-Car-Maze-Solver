//L293D
//Distances i-front, j-left, k-right
const int i=50;
const int j=50;
const int k=50;

//Motor A
const int motorPin1  = 9;  // Pin 14 of L293
const int motorPin2  = 10;  // Pin 10 of L293
//Motor B
const int motorPin3  = 6; // Pin  7 of L293
const int motorPin4  = 5;  // Pin  2 of L293

// defines pins numbers
const int trigPin1 = 11;
const int echoPin1 = 12;
const int trigPin2 = 2;
const int echoPin2 = 3;
const int trigPin3 = 7;
const int echoPin3 = 8;

// defines variables
long duration;
int distance_front , distance_left,distance_right;
void setup() {
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin3, INPUT); // Sets the echoPin as an Input


Serial.begin(9600); // Starts the serial communication


    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    
    //Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4

//This will run only one time.
}
void loop(){
    // Clears the trigPin
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin1, HIGH);
// Calculating the distance
distance_right= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance Right: ");
Serial.println(distance_right);

// Clears the trigPin
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin2, HIGH);
// Calculating the distance
distance_left= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance Left: ");
Serial.println(distance_left);

// Clears the trigPin
digitalWrite(trigPin3, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin3, HIGH);
// Calculating the distance
distance_front= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance Front: ");
Serial.println(distance_front);



if(distance_left <j && distance_right>k && distance_front>i){   // wall LEFT so keep going straight ahead
   analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 120);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 170);
}

else if(distance_left>j){    // NO LEFT wall so turn left
    analogWrite(motorPin1, 140);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 140);
    delay(200);
     analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 120);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 170);
    delay(200);
    
}

else if(distance_front <i && distance_left <j && distance_right>k){ //wall LEFT and FRONT so turn right
   analogWrite(motorPin1, 0);
   analogWrite(motorPin2, 140);
   analogWrite(motorPin3, 140);
   analogWrite(motorPin4, 0);
   delay(700);
}

else if(distance_front < i && distance_left < j && distance_right < k){  //walls everywhere so turn around 
    
 analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 140);
    analogWrite(motorPin3, 140);
    analogWrite(motorPin4, 0);
    delay(1400);
  
}


}
