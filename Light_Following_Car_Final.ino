// light following car using L293D and 2 LDR

//L293D
const int enable_pin_a = 10;
const int enable_pin_b = 11;
// const int switch_pin = 7; 
// const int pot_pin = A2;
//left motor
const int motorPin1  = 6;  // Pin 4 of L293D
const int motorPin2  = 7;  // Pin 7 of L293D
//Right motor
const int motorPin3  = 12; // Pin  8 of L293D
const int motorPin4  = 13;  // Pin  9 of L293D
// for LDR 
const int LDR_R= A0;  // pin A0 for Right LDR
const int LDR_L= A1;   // pin A1 for left LDR



void setup() 
{ 
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(enable_pin_a,OUTPUT);
    pinMode(enable_pin_b,OUTPUT);
   
    //set pins as input
    pinMode(LDR_R,INPUT);
    pinMode(LDR_L,INPUT);
    Serial.begin(9600);
}

void loop ()
{
  
 
  int left_LDR = digitalRead(LDR_L);
  Serial.print("Left LDR");
  Serial.print(left_LDR);
  int right_LDR = digitalRead(LDR_R);
  Serial.print("Right LDR");
  Serial.println(right_LDR);
  delay(500);


  if ((right_LDR==1)&&(left_LDR==1)) //forward
  {
    stop();
  } 
  else if ((right_LDR==0)&&(left_LDR==1)) //left
  {
    right();
  }
  else if ((right_LDR==1)&&(left_LDR==0)) //right
  {
    right();
  }
  else if ((right_LDR==0)&&(left_LDR==0)) //left
  {
    forward();
  }
  else //stop
  {
   stop();
  }
  //delay(500);
}
void forward()  // move forward 
{
    digitalWrite(motorPin1,HIGH);
    digitalWrite(motorPin2,LOW);
    digitalWrite(motorPin3,HIGH);
    digitalWrite(motorPin4,LOW);
    analogWrite(enable_pin_a, 250);
    analogWrite(enable_pin_b, 250);
}

void left()  // move left
{   
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2,HIGH);
    digitalWrite(motorPin3,HIGH);
    digitalWrite(motorPin4,LOW);
    analogWrite(enable_pin_a, 200);
    analogWrite(enable_pin_b, 200);
}
void right() // move right
{
    digitalWrite(motorPin1,HIGH);
    digitalWrite(motorPin2,LOW);
    digitalWrite(motorPin3,LOW);
    digitalWrite(motorPin4,HIGH);
    analogWrite(enable_pin_a, 200);
    analogWrite(enable_pin_b, 200);
}
void stop() // stop
{
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2,LOW);
    digitalWrite(motorPin3,LOW);
    digitalWrite(motorPin4,LOW);
}

