int sensor1 = A0;
int sensor2 = A1;
int people = 0;
int led=13;
int sensor1_value = 0;
int sensor2_value = 0;
int normal_value = 400;
int low = 0;
int high = 0;
int high2 = 0;
int low2 = 0;
int buzzer = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode (led,OUTPUT);
  
}

void loop()
{
  
  int sensor1_value = analogRead(sensor1);
  int sensor2_value = analogRead(sensor2);


  if (sensor1_value < normal_value)
  {
    high = 1;

  }

  if (sensor1_value > normal_value && high == 1 )
    low = 1;

  if (high == 1 && low == 1 && people < 6)
  {
    delay(2000);
    high = 0;   // when high and lo ==1 we add one person in the room 
    low = 0;
    ++people;

  }

  if (sensor2_value > normal_value)
  {
    
    high2 = 1;

  }

  if (sensor2_value < normal_value && high2 == 1)
   
    low2 = 1;

  if (high2 == 1 && low2 == 1 && people > -1 )
  {
    delay(2000);
    high2 = 0;
    low2 = 0;     // when high2 and low2 ==1 we subtract one person  from the room  
    --people;

  }
  if (people>5){
  digitalWrite(led,HIGH); // when people >5 the buzzer rings and a red led shine until number of peoples =5 again
  delay(500);
  digitalWrite(led,LOW);
  delay(500);






  }
  while (1)
  {
    
      
 
  
    
    if (people > 5)
    {
      tone(buzzer, 1000);
       
      break;
    }

    else
    { noTone(buzzer);
      break;
    }

  }
  if (people<0){
    people=0;     // the value of people inside the room cant be less than zero
  }
 
}
      
    
    
    
