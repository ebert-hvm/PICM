// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 200;



// Endstops
int LEndstop = 1;
int REndstop = 2;

//Joystick

int x_key = A0;                                                                                   
int x_pos;



// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);






void setup()
{
  //pinMode(LEndstop, INPUT_PULLUP);
  //pinMode(REndstop, INPUT_PULLUP);
    
    // set the speed at 100 rpm:
  myStepper.setSpeed(100);
  // initialize the serial port for testing / logging:
  //Serial.begin(9600);
}


//If the stepper motor is not hit (ie 1 all good, else 0 )

void loop() 
{

int Lsensor = digitalRead(LEndstop);
int Rsensor = digitalRead(REndstop);
x_pos = analogRead (x_key) ;  

  //print out the value of the pushbutton
 // Serial.println(Lsensor);
  //Serial.println(Rsensor);
  //Serial.println(x_pos);

// stop immediately if endstop hit

  if (Lsensor or Rsensor == 0){
    myStepper.step(0);
  
                               }



// if the endstops are default (ie open default =1)

if (Lsensor and Rsensor == 1){

// determine horizontal joystick input
                          
                                  if (x_pos > 600){
                                    
                                     // Serial.println("clockwise");
                                      myStepper.step(stepsPerRevolution);
                                                 }
                                                    
                                  if (x_pos < 450){
                                    
                                    //  Serial.println("Anticlockwise");
                                      myStepper.step(-stepsPerRevolution);
                                                 }
                         
                              }
                                     




 
}