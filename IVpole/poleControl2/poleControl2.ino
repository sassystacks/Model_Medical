#include "MedianFilter.h"

const int medianNum = 3b;
MedianFilter fsens1(medianNum,0);
MedianFilter fsens2(medianNum,0);
MedianFilter fsens3(medianNum,0);
MedianFilter fsens4(medianNum,0);
MedianFilter fsens5(medianNum,0);
MedianFilter Ref1(medianNum,0);

const int sensnum = 5;

//trigger is even pins
int trigPins[]={2,4,6,8,10};
//echo is odd pins
int echoPins[]={3,5,7,9,11};

int distances[sensnum];
int sensors[sensnum];


//
//               Pin 12     Pin 13
// FORWARDS  =>     1           0
// BACKWARDS =>     0           1
// STOP      =>     0           0
// BRAKE     =>     1           1
//


//Need to change Pins
const int fwdPin         = 12;
const int bwdPin         = 13;
const int speedPin       = 10;
const int referencePin   = 11;


int referenceState = 0;

int closest = 0;
int target = 0;
int reference = 5;
int directio = 0; 

MedianFilter fsensor[sensnum] = {fsens1,fsens2,fsens3,fsens4,fsens5};
//MedianFilter fsensor[sensnum] = {fsens1,fsens2};

void setup() 
{

for (int i =0; i<sensnum; i++)
  {
    pinMode(trigPins[i],OUTPUT);
    pinMode(echoPins[i],INPUT);
    sensors[i]=i+1;
  }
    Serial.begin(9600);


}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~      Main Loop      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


void loop() 
{

  //Get sensor data
  getSensorData(&echoPins[0],&trigPins[0],&distances[0],&fsensor[0], sensnum);
  /*
   for (int i = 0; i<sensnum;i++)
  {
     int a = fsensor[i].in(distances[i]);
     distances[i]= a;
  }
  */
  //Print data
  //printSens(&fsensor[0], sensnum);
  
  ///Find Closest sensor
  closest = checkClosest(&distances[0], &sensors[0], sensnum, Ref1);

  //Set Direction
  //directio = getDirection(closest,reference, sensnum);
  
  //Get Reference Pin
  getRef(closest, reference,referencePin,directio, sensnum);


  
  //Print Results from Sensors
  printSens2(closest, reference,referencePin,directio);
    
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~      Functions      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ~~~ Send Motor Commands ~~~
void runMotor(int direct)
{
  if      (direct == 0) // Stop
  {
    //analogWrite(speedPin, 0);
    digitalWrite(fwdPin, LOW);
    digitalWrite(bwdPin, LOW);
  }
  else if (direct == 999) // BRAKE
  {
   // analogWrite(speedPin, 0);
    digitalWrite(fwdPin, HIGH);
    digitalWrite(bwdPin, HIGH);
  }
  else if (direct == 1) // Forwards
  {
    //analogWrite(speedPin, 127);
    digitalWrite(fwdPin, HIGH);
    digitalWrite(bwdPin, LOW);
  }
  else if (direct == -1) // Backwards
  {
    //analogWrite(speedPin, 127);
    digitalWrite(fwdPin, LOW);
    digitalWrite(bwdPin, HIGH);
  }
}

void getSensorData(int *echoPin, int *trigPin, int *distances, MedianFilter *fsens, int num)
{

  for (int i = 0; i < num; i++)
  {
    digitalWrite(trigPin[i], LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin[i], HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin[i], LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    long dur = pulseIn(echoPin[i], HIGH);   
    int d = 0.034*dur/2;
    fsens[i].in(d);
    distances[i] = fsens[i].out();
        
  }
}

// ~~ Check Closest Sensor ~~
int checkClosest(int *distance, int *sensors, int num, MedianFilter ref)
{
  int closest_sensor = sensors[0];
  //float minimum = sqrt((distance[0] - 50)^2);
  int minD = distance[0];
 
  for (int i = 0; i < num; i++)
  {
    /*
    float comp = sqrt((distance[i]-50)^2);
    if ( comp < minimum) 
    {
      int minD = distance[i];
      closest_sensor = sensors[i];
    }
    */
     if ( distance[i] < minD) 
    {
      minD = distance[i];
      closest_sensor = sensors[i];
    
    }  

 } 
   if (minD < 10 || minD > 100)
  {
    closest_sensor = reference;
  }
  
  Ref1.in(closest_sensor);
  closest_sensor = Ref1.out(); 
   
  return closest_sensor;
}
//Send Motor Command


// ~~ Print Sensor Data ~~
//Prints the distance on the Serial Monitor
void printSens(MedianFilter *fsens, int num)
{
for(int i=0;i<sensnum;i++)
{

String strDisp1 = "Distance " + String(i+1) + " - " ;
String strDisp2 = String(fsens[i].out()) + ", ";
String strDisp = strDisp1 + strDisp2;


Serial.print(strDisp);

}
Serial.println(" ");
}

// ~~~~ Print Sensor Data Second Method ~~~
void printSens2(int clost, int ref,int refP,int direct)
{

  Serial.print("Closest is " + String(closest));
  
  Serial.print(" ");
  
  Serial.print("Reference is " + String(reference));
  
  Serial.print(" Direction is: " + String(direct)); 
  Serial.println(" ");
  
}

  // Get reference
void getRef(int clost, int ref,int refP,int direct, int num)
{
  int refstate = digitalRead(refP);
  
  if(refstate == HIGH)
  {
    reference = clost;
  
  }
  else
  {
    directio = getDirection(clost, reference, num);
    runMotor(directio); 
  }
}
int getDirection(int closes, int ref, int num)
{

 /* if (ref != 0 && ref != closes)
  {
    if     (closes - ref > num/2 || closes - ref < -num/2)
    {
      return 1;
    }
    else if(closes - ref < num/2 || closes - ref > -num/2)
    {
      return -1;
    }
   
  }
  */
  if(ref != 0 && ref != closes)

  {
    if     (closes - ref >= -2 )
    {
      return 1;
    }
     if     (closes - ref <= -3 )
    {
      return -1;
    }   
  }
  else
  {
    return 0;
  }
}
