int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;
int LED7 = 8;
int LED8 = 9;
int LED9 = 10;
int LED10 = 11;

int ledPins[] = {2,3,4,5,6,7,8,9,10,11};
int numberOfPins = sizeof(ledPins)/sizeof(int);

void setup() {
  Serial.begin(9600);
  for(int startPin = 0; startPin<sizeof(ledPins); startPin++)
  {
      pinMode(ledPins[startPin], OUTPUT);
  }
}

void loop() {
  collideAndReverse(500,3);
  stopAndGo(100);

  for(int counter=0; counter<3; counter++)
  {
      topToBottom(150);
      bottomToTop(150);
  }
}

void stopAndGo(int pause)
{
  for(int count = 0; count<10; count++)
  {
    topToBottom(0);
    delay(pause);
    bottomToTop(0); 
    delay(pause);
  }
}

void topToBottom(int pause)
{
  for(int pinsA = 0; pinsA<numberOfPins; pinsA++)
  {
    digitalWrite(ledPins[pinsA], HIGH);   
    delay(pause);  
  }
}

void bottomToTop(int pause)
{
  for(int pinsB = numberOfPins; pinsB>0; pinsB--)
  {  
    digitalWrite(ledPins[pinsB-1], LOW);   
    delay(pause); 
  }
}

void collideAndReverse(int pause, int times)
{     
  for(int repeat = 0; repeat < times; repeat++)
  {
      int counter = 0; 

      for(int pinsC = numberOfPins; pinsC>numberOfPins/2; pinsC--)
      {      
        digitalWrite(ledPins[pinsC-1], HIGH); 
        digitalWrite(ledPins[counter], HIGH);   
        counter++;
        delay(pause); 
      }
    
      for(int pinsD = numberOfPins/2; pinsD<numberOfPins; pinsD++)
      {      
        digitalWrite(ledPins[pinsD], LOW); 
        digitalWrite(ledPins[counter-1], LOW);   
        counter--;
        delay(pause); 
      }
  }
}
