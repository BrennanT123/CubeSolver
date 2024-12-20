
#include <Stepper.h>


const int stepsPerRevolution = 200;

const int dirPin1 = 2;
const int stepPin1 = 3;

const int dirPin2 = 4;
const int stepPin2 = 5;
const int dirPin3 = 6;
const int stepPin3 = 7;
const int dirPin4 = 8;
const int stepPin4 = 9;
const int dirPin5 = 10;
const int stepPin5 = 11;


Stepper stepper1 = Stepper(stepsPerRevolution, 2, 3);
Stepper stepper2 = Stepper(stepsPerRevolution, 4, 5);
Stepper stepper3 = Stepper(stepsPerRevolution, 6, 7);
Stepper stepper4 = Stepper(stepsPerRevolution, 8, 9);
Stepper stepper5 = Stepper(stepsPerRevolution, 10, 11);


String stepnum;

#include <Keypad.h>
const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

char Fface[3][3] = 
{
  {'g','g','g'},
  {'g','g','g'},
  {'g','g','g'}
};


char Rface[3][3] = 
{
  {'o','o','o'},
  {'o','o','o'},
  {'o','o','o'}
};


char Lface[3][3] = 
{
  {'r','r','r'},
  {'r','r','r'},
  {'r','r','r'}
};


char Dface[3][3] = 
{
  {'w','w','w'},
  {'w','w','w'},
  {'w','w','w'}
};


char Uface[3][3] = 
{
  {'y','y','y'},
  {'y','y','y'},
  {'y','y','y'}
};

char Bface[3][3] = {

  {'b','b','b'},
  {'b','b','b'},
  {'b','b','b'}
};

char OldFface[3][3]; //Temporary face used when reordering faces
char OldLface[3][3];
char OldBface[3][3];
char OldRface[3][3];
char OldDface[3][3];
char OldUface[3][3];

byte rowPins[ROWS] = {22, 24, 26, 28}; 
byte colPins[COLS] = {30, 32, 34, 36}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  stepper1.setSpeed(700);
  stepper2.setSpeed(700);
  stepper3.setSpeed(700);
  stepper4.setSpeed(700);
  stepper5.setSpeed(700);

  Serial.begin(9600);

  pinMode(stepPin1, OUTPUT);
	pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
	pinMode(dirPin2, OUTPUT);
  pinMode(stepPin3, OUTPUT);
	pinMode(dirPin3, OUTPUT);
  pinMode(stepPin4, OUTPUT);
	pinMode(dirPin4, OUTPUT);
  pinMode(stepPin5, OUTPUT);
	pinMode(dirPin5, OUTPUT);

}

void loop() {
  char customKey = customKeypad.getKey();

  switch(customKey){
    case '1'://F
      stepper1.step(stepsPerRevolution);

      OldUface = Uface;
      OldFface = Fface;
      OldLface = Fface;
      OldRface = Fface;
      OldDface = Fface;
      Fface[1][1] = OldFface[3][1];
      Fface[1][2] = OldFface[2][1];
      Fface[1][3] = OldFface[1][1];
      Fface[2][1] = OldFface[3][2];
      Fface[2][2] = OldFface[2][2];
      Fface[2][3] = OldFface[1][2];
      Fface[3][1] = OldFface[3][3];
      Fface[3][2] = OldFface[2][3];
      Fface[3][3] = OldFface[1][3];

      Uface[3][1] = OldLface[3][3];
      Uface[3][2] = OldLface[2][3];
      Uface[3][3] = OldLface[1][3];

      Rface[1][1] = OldUface[3][1];
      Rface[2][1] = OldUface[3][2];
      Rface[3][1] = OldUface[3][3];

      Dface[1][1] = OldRface[3][1];
      Dface[1][2] = OldRface[2][1];
      Dface[1][3] = OldRface[1][1];

      Lface[1][3] = OldRface[1][1];
      Lface[2][3] = OldRface[1][2];
      Lface[3][3] = OldRface[1][3];
      
      serial.println(Fface);
      serial.println(Rface);
      serial.println(Lface);
      serial.println(Dface);
      serial.println(Uface);
      serial.println(Bface);

      break;
    case '2':
      stepper1.step(-stepsPerRevolution);
      break;
    case '3'://L
      stepper2.step(stepsPerRevolution);
      break;
    case '4':
      stepper2.step(-stepsPerRevolution);
      break;
    case '5'://B
      stepper3.step(stepsPerRevolution);
      break;
    case '6':
      stepper3.step(-stepsPerRevolution);
      break;
    case '7'://R
      stepper4.step(stepsPerRevolution);
      break;
    case '8':
      stepper4.step(-stepsPerRevolution);
      break;
    case '9'://D
      stepper5.step(stepsPerRevolution);
      break;
    case '0':
      stepper5.step(-stepsPerRevolution);
      break;
  }

}
