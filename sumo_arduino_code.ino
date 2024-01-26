
// Define pin numbers for sensors and motors
const int leftMotorPinFWD = 2;
const int leftMotorPinBWD= 3;
const int rightMotorPinFWD = 4;
const int rightMotorPinBWD= 5;

const int leftSensorPin = 6;  // line detection sensor interface
const int rightSensorPin = 7;
int valLeft;            // variable to store sensor reading
int valRight;

long currentTime;
const long backupDuration = 500;       // duration for running the function (in milliseconds)
const long oneeightyDuration = 600;
const long turnDuration = 100; 
const long forwardstimedDuration = 500;
const long turnDuration2 = 300;

const int trigPin = 8;
const int echoPin = 9;
int counter = 0;
int even = 0;

int startup = 0;


void setup()
{
  Serial.begin(9600);

  pinMode(rightMotorPinFWD,OUTPUT);
  pinMode(rightMotorPinBWD,OUTPUT);
  pinMode(leftMotorPinFWD,OUTPUT);
  pinMode(leftMotorPinBWD,OUTPUT);

  pinMode(rightSensorPin, INPUT);  // define sensor as input
  pinMode(leftSensorPin, INPUT);  

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop()
{
  if (startup == 0)     //test
  {
    delay(8
    000);
    forwards_timed3();
    startup = 1;
  }

  //ULTRASONIC////////////
  long duration, cm;

  //SENSORS////////////
  
  valLeft = digitalRead(leftSensorPin);  // read value from sensor
  valRight = digitalRead(rightSensorPin);

  digitalWrite (rightMotorPinFWD, LOW);                           
  digitalWrite (leftMotorPinFWD, LOW);
  digitalWrite (rightMotorPinBWD, LOW);      

  digitalWrite (leftMotorPinBWD, LOW);

if (valLeft != HIGH && valRight != HIGH)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  
  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(2);

  
  if (cm < 50)
  {
      forwards();    
  }
  
  else
  {
    if (counter < 3)
    {
      turn_right();
      counter ++;  
    }
    else
    {
      if (even % 2 == 0)
      {
        counter = 0;
        forwards_timed();
      }
      else
      {
        counter = 0;
        forwards_timed2();
      }
      
    }

    Serial.println("counter:"+counter);

  }
}

else
{
  if (valLeft == HIGH && valRight == HIGH) // straight on
  {
    backwards();
    one_eighty();
    delay(10);
  }


  if(valLeft != HIGH and valRight == HIGH)   //hits right sensor
  {                       
    backwards();
    one_eighty();
    delay (5);      
  }

  if(valLeft == HIGH and valRight != HIGH)   //hits left sensor
  {
    backwards();
    one_eighty();                         
    delay (5);      
  }
}
  
  //LESS than the center value --> WHITE (light) area. However, if a sensor reads MORE/GREATER than the center value --> BLACK (dark) area
  
}

/////////FUNCTIONS////////////

void forwards()
{
  digitalWrite (rightMotorPinFWD, HIGH);                           
  digitalWrite (leftMotorPinFWD, HIGH);
  delay (5);  
}

void forwards_timed()
{
  currentTime = millis();
  
  while (millis() < currentTime + turnDuration)
  {
    digitalWrite(rightMotorPinFWD, HIGH);
    digitalWrite(leftMotorPinFWD, HIGH);
    delay(10); // Add a small delay to prevent blocking
  }

  digitalWrite(rightMotorPinFWD, LOW);
  digitalWrite(leftMotorPinFWD, LOW);
}
void forwards_timed2()
{
  currentTime = millis();
  
  while (millis() < currentTime + turnDuration2)
  {
    digitalWrite(rightMotorPinFWD, HIGH);
    digitalWrite(leftMotorPinFWD, HIGH);
    delay(10); // Add a small delay to prevent blocking
  }

  digitalWrite(rightMotorPinFWD, LOW);
  digitalWrite(leftMotorPinFWD, LOW);
}

void forwards_timed3()
{
  currentTime = millis();
  
  while (millis() < currentTime + 750)
  
  {
    digitalWrite(rightMotorPinFWD, HIGH);
    digitalWrite(leftMotorPinFWD, HIGH);
    delay(10); // Add a small delay to prevent blocking
  }

  digitalWrite(rightMotorPinFWD, LOW);
  digitalWrite(leftMotorPinFWD, LOW);
}

void backwards()
{
  currentTime = millis();
  
  while (millis() < currentTime + backupDuration)
  {
    digitalWrite(rightMotorPinBWD, HIGH);
    digitalWrite(leftMotorPinBWD, HIGH);
    delay(10); // Add a small delay to prevent blocking
  }

  digitalWrite(rightMotorPinBWD, LOW);
  digitalWrite(leftMotorPinBWD, LOW);
}

void turn_right()
{
  currentTime = millis();

  while (millis() < currentTime + 45)
  {
    digitalWrite(leftMotorPinBWD,HIGH);
    digitalWrite(rightMotorPinFWD,HIGH);
    delay(10);
  }

  digitalWrite(leftMotorPinBWD,LOW);
  digitalWrite(rightMotorPinFWD,LOW);

  delay(400);
}

void one_eighty()
{
  currentTime = millis();

  while (millis() < currentTime + oneeightyDuration)
  {
    digitalWrite(leftMotorPinBWD,HIGH);
    digitalWrite(rightMotorPinFWD,HIGH);
    delay(10);
  }

  digitalWrite(leftMotorPinBWD,LOW);
  digitalWrite(rightMotorPinFWD,LOW);
}


long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
