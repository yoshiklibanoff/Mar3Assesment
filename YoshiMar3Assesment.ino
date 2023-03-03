// Define Trig and Echo pins
const int trigPin = 4;
const int echoPin = 5;
const int dangerLED = 10;
const int warningLED = 11;
const int safeLED = 12;


void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
 
  // Set Trig pin as output and Echo pin as input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
 
  // Send a pulse to Trig pin for 10 microseconds
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
long duration = pulseIn(echoPin, HIGH);

// Calculate the distance in centimeters by dividing the duration by 58

int distance = duration / 58;

Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");

if((float)distance < 4){
  digitalWrite(dangerLED, HIGH);
  digitalWrite(warningLED, LOW);
  digitalWrite(safeLED, LOW);  
}
else if(distance < 7){
  digitalWrite(warningLED, HIGH);
  digitalWrite(dangerLED, LOW);
  digitalWrite(safeLED, LOW);  
}
else{
  digitalWrite(safeLED, HIGH);
  digitalWrite(dangerLED, LOW);
  digitalWrite(warningLED, LOW);
}
delay(500);

}
