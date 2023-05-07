
int val = 0;
int whatActive = 0;

void turnOn10(){
  while(digitalRead(2) == LOW){
   digitalWrite(3, HIGH);
   delayMicroseconds(50); // Approximately 5% duty cycle @ 1KHz
   digitalWrite(3, LOW);
   delayMicroseconds(1000 - 50);
   
   digitalWrite(5, HIGH);
   delayMicroseconds(50); // Approximately 5% duty cycle @ 1KHz
   digitalWrite(5, LOW);
   delayMicroseconds(1000 - 50);
   
   digitalWrite(6, HIGH);
   delayMicroseconds(50); // Approximately 5% duty cycle @ 1KHz
   digitalWrite(6, LOW);
   delayMicroseconds(1000 - 50);
   
   digitalWrite(9, HIGH);
   delayMicroseconds(50); // Approximately 5% duty cycle @ 1KHz
   digitalWrite(9, LOW);
   delayMicroseconds(1000 - 50);

   digitalWrite(10, HIGH);
   delayMicroseconds(50); // Approximately 5% duty cycle @ 1KHz
   digitalWrite(10, LOW);
   delayMicroseconds(1000 - 50);

   digitalWrite(11, HIGH);
   delayMicroseconds(50); // Approximately 5% duty cycle @ 1KHz
   digitalWrite(11, LOW);
   delayMicroseconds(1000 - 50);
    
  }
   digitalWrite(3, LOW);
   digitalWrite(5, LOW); 
   digitalWrite(6, LOW); 
   digitalWrite(9, LOW); 
   digitalWrite(10, LOW); 
   digitalWrite(11, LOW); 
}

void turnOn25(){
  while(digitalRead(2) == LOW){
   digitalWrite(3, HIGH);
   delayMicroseconds(250); // Approximately 25% duty cycle @ 1KHz
   digitalWrite(3, LOW);
   delayMicroseconds(1000 - 250);
   
   digitalWrite(5, HIGH);
   delayMicroseconds(50); // Approximately 25% duty cycle @ 1KHz
   digitalWrite(5, LOW);
   delayMicroseconds(1000 - 250);
   
   digitalWrite(6, HIGH);
   delayMicroseconds(250); // Approximately 25% duty cycle @ 1KHz
   digitalWrite(6, LOW);
   delayMicroseconds(1000 - 250);
   
   digitalWrite(9, HIGH);
   delayMicroseconds(250); // Approximately 25% duty cycle @ 1KHz
   digitalWrite(9, LOW);
   delayMicroseconds(1000 - 250);

   digitalWrite(10, HIGH);
   delayMicroseconds(250); // Approximately 25% duty cycle @ 1KHz
   digitalWrite(10, LOW);
   delayMicroseconds(1000 - 250);

   digitalWrite(11, HIGH);
   delayMicroseconds(250); // Approximately 25% duty cycle @ 1KHz
   digitalWrite(11, LOW);
   delayMicroseconds(1000 - 250);
    
  }
   digitalWrite(3, LOW);
   digitalWrite(5, LOW); 
   digitalWrite(6, LOW); 
   digitalWrite(9, LOW); 
   digitalWrite(10, LOW); 
   digitalWrite(11, LOW); 
}

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP); 
  pinMode(4, INPUT_PULLUP); 
  pinMode(7, INPUT_PULLUP); 
  pinMode(8, INPUT_PULLUP); 
  pinMode(3, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  // Something wrong here ?
  if( digitalRead(2) == LOW) {
    whatActive = 2;
  } else if(digitalRead(4) == LOW){
    whatActive = 4;
  } else if(digitalRead(7) == LOW){
    whatActive = 7;
  } else if(digitalRead(8) == LOW){
    whatActive = 8;
  }
  
  switch (whatActive){
    case 2:   
      turnOn10(); 
      break;
    case 4:
      turnOn25();
      break;
    case 7:
      break;
    case 8:
      break;
  }

}