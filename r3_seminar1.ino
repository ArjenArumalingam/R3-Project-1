double pot;
int in1;
int in2;
int in3;
int in4;


void setup()
{
  pinMode(A0,INPUT); //Potentiometer

  pinMode(11,INPUT); //Input for chip
  pinMode(10,INPUT);
  pinMode(9,INPUT);
  pinMode(8,INPUT);
  
  pinMode(7,INPUT);  //Dip Switch
  pinMode(6,INPUT);
  pinMode(5,INPUT);
  pinMode(4,INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  // Input 
  pot = map(analogRead(A0),0,1023,0,255);
  Serial.println(pot);
  in1 = digitalRead(4);
  in2 = digitalRead(5);
  in3 = digitalRead(6);
  in4 = digitalRead(7);
  delay(25);
  
  //Movement
  if (in1 == 0 && in2 == 0 && in3 == 0 && in4 == 0) { 
  	digitalWrite(8, LOW);
    digitalWrite(9, LOW);	
    digitalWrite(10, pot);
    digitalWrite(11, pot);	
    delay(25);
  }
  else if (in1 == 0 && in2 == 0 && in3 == 0 && in4 == 1) { //Left
  	digitalWrite(8, pot);
    digitalWrite(9, LOW);	
    digitalWrite(10, pot);	
    digitalWrite(11, LOW);	
    delay(25);
  }
  else if (in1 == 0 && in2 == 0 && in3 == 1 && in4 == 0) { //Right
  	digitalWrite(8, LOW);
    digitalWrite(9, pot);	
    digitalWrite(10, LOW);	
    digitalWrite(11, pot);	
    delay(25);
  }
  else if (in1 == 0 && in2 == 1 && in3 == 0 && in4 == 0) { //Reverse
  	digitalWrite(8, LOW);
    digitalWrite(9, pot);
    digitalWrite(10, pot);	
    digitalWrite(11, LOW);	
    delay(25);
  }
  else if (in1 == 1 && in2 == 0 && in3 == 0 && in4 == 0) { //Front
  	digitalWrite(8, pot);
    digitalWrite(9, LOW);	
    digitalWrite(10, LOW);	
    digitalWrite(11, pot);	
    delay(25);
  }
}