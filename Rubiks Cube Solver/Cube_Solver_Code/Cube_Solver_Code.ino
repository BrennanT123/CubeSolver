
#include <Stepper.h>


const int stepsPerRevolution = 200;

const int dirPin1 = 42;
const int stepPin1 = 44;

const int dirPin2 = 4;
const int stepPin2 = 5;
const int dirPin3 = 6;
const int stepPin3 = 7;
const int dirPin4 = 8;
const int stepPin4 = 9;
const int dirPin5 = 10;
const int stepPin5 = 11;
const int dirPin6 = 38;
const int stepPin6 = 40;


Stepper stepper1 = Stepper(stepsPerRevolution, 42, 44); //F
Stepper stepper2 = Stepper(stepsPerRevolution, 4, 5);  //L
Stepper stepper3 = Stepper(stepsPerRevolution, 6, 7); //B
Stepper stepper4 = Stepper(stepsPerRevolution, 8, 9); //R
Stepper stepper5 = Stepper(stepsPerRevolution, 10, 11); //D
Stepper stepper6 = Stepper(stepsPerRevolution, 38, 40); //U


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
  {'F', 'F', 'F'},
  {'F', 'F', 'F'},
  {'F', 'F', 'F'}
};


char Rface[3][3] =
{
  {'R', 'R', 'R'},
  {'R', 'R', 'R'},
  {'R', 'R', 'R'}
};


char Lface[3][3] =
{
  {'L', 'L', 'L'},
  {'L', 'L', 'L'},
  {'L', 'L', 'L'}
};


char Dface[3][3] =
{
  {'D', 'D', 'D'},
  {'D', 'D', 'D'},
  {'D', 'D', 'D'}
};


char Uface[3][3] =
{
  {'U', 'U', 'U'},
  {'U', 'U', 'U'},
  {'U', 'U', 'U'}
};

char Bface[3][3] = {

  {'B', 'B', 'B'},
  {'B', 'B', 'B'},
  {'B', 'B', 'B'}
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
  stepper6.setSpeed(700);

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
  pinMode(stepPin6, OUTPUT);
  pinMode(dirPin6, OUTPUT);

}

void loop() {
  char customKey = customKeypad.getKey();

  switch (customKey) {
    case '1'://F
      stepper1.step(-stepsPerRevolution);
      setTempVariables();

      Fface[0][0] = OldFface[2][0];
      Fface[0][1] = OldFface[1][0];
      Fface[0][2] = OldFface[0][0];
      Fface[1][0] = OldFface[2][1];
      Fface[1][1] = OldFface[1][1];
      Fface[1][2] = OldFface[0][1];
      Fface[2][0] = OldFface[2][2];
      Fface[2][1] = OldFface[1][2];
      Fface[2][2] = OldFface[0][2];

      Uface[2][0] = OldLface[2][2];
      Uface[2][1] = OldLface[1][2];
      Uface[2][2] = OldLface[0][2];

      Rface[0][0] = OldUface[2][0];
      Rface[1][0] = OldUface[2][1];
      Rface[2][0] = OldUface[2][2];

      Dface[0][0] = OldRface[2][0];
      Dface[0][1] = OldRface[1][0];
      Dface[0][2] = OldRface[0][0];

      Lface[0][2] = OldDface[0][0];
      Lface[1][2] = OldDface[0][1];
      Lface[2][2] = OldDface[0][2];
      Serial.println("F");



      break;
    case '2': //F'
      stepper1.step(stepsPerRevolution);

      setTempVariables();

      Fface[0][0] = OldFface[0][2];
      Fface[0][1] = OldFface[1][2];
      Fface[0][2] = OldFface[2][2];
      Fface[1][0] = OldFface[0][1];
      Fface[1][1] = OldFface[1][1];
      Fface[1][2] = OldFface[2][1];
      Fface[2][0] = OldFface[0][0];
      Fface[2][1] = OldFface[1][0];
      Fface[2][2] = OldFface[2][0];

      Uface[2][0] = OldRface[0][0];
      Uface[2][1] = OldRface[1][0];
      Uface[2][2] = OldRface[2][0];

      Rface[0][0] = OldDface[0][2];
      Rface[1][0] = OldDface[0][1];
      Rface[2][0] = OldDface[0][0];

      Dface[0][0] = OldLface[0][2];
      Dface[0][1] = OldLface[1][2];
      Dface[0][2] = OldLface[2][2];

      Lface[0][2] = OldUface[2][2];
      Lface[1][2] = OldUface[2][1];
      Lface[2][2] = OldUface[2][0];
      Serial.println("F''''");



      break;
    case '3'://L
      stepper2.step(-stepsPerRevolution);
      setTempVariables();

      Lface[0][0] = OldLface[2][0];
      Lface[0][1] = OldLface[1][0];
      Lface[0][2] = OldLface[0][0];
      Lface[1][0] = OldLface[2][1];
      Lface[1][1] = OldLface[1][1];
      Lface[1][2] = OldLface[0][1];
      Lface[2][0] = OldLface[2][2];
      Lface[2][1] = OldLface[1][2];
      Lface[2][2] = OldLface[0][2];

      Uface[0][0] = OldBface[2][2];
      Uface[1][0] = OldBface[1][2];
      Uface[2][0] = OldBface[0][2];

      Fface[0][0] = OldUface[0][0];
      Fface[1][0] = OldUface[1][0];
      Fface[2][0] = OldUface[2][0];

      Dface[0][0] = OldFface[0][0];
      Dface[1][0] = OldFface[1][0];
      Dface[2][0] = OldFface[2][0];

      Bface[0][2] = OldDface[2][0];
      Bface[1][2] = OldDface[1][0];
      Bface[2][2] = OldDface[0][0];
      Serial.println("L");



      break;
    case '4': //L'
      stepper2.step(stepsPerRevolution);
      setTempVariables();


      //Face being turned
      Lface[0][0] = OldLface[0][2];
      Lface[0][1] = OldLface[1][2];
      Lface[0][2] = OldLface[2][2];
      Lface[1][0] = OldLface[0][1];
      Lface[1][1] = OldLface[1][1];
      Lface[1][2] = OldLface[2][1];
      Lface[2][0] = OldLface[0][0];
      Lface[2][1] = OldLface[1][0];
      Lface[2][2] = OldLface[2][0];

      //Other faces being changed
      Uface[0][0] = OldFface[0][0];
      Uface[1][0] = OldFface[1][0];
      Uface[2][0] = OldFface[2][0];

      Fface[0][0] = OldDface[0][0];
      Fface[1][0] = OldDface[1][0];
      Fface[2][0] = OldDface[2][0];

      Dface[0][0] = OldBface[2][2];
      Dface[1][0] = OldBface[1][2];
      Dface[2][0] = OldBface[0][2];

      Bface[0][2] = OldUface[2][0];
      Bface[1][2] = OldUface[1][0];
      Bface[2][2] = OldUface[0][0];

      Serial.println("L'");


      break;
    case '5'://B
      stepper3.step(-stepsPerRevolution);

      setTempVariables();


      Bface[0][0] = OldBface[2][0];
      Bface[0][1] = OldBface[1][0];
      Bface[0][2] = OldBface[0][0];
      Bface[1][0] = OldBface[2][1];
      Bface[1][1] = OldBface[1][1];
      Bface[1][2] = OldBface[0][1];
      Bface[2][0] = OldBface[2][2];
      Bface[2][1] = OldBface[1][2];
      Bface[2][2] = OldBface[0][2];

      Uface[0][0] = OldRface[0][2];
      Uface[0][1] = OldRface[1][2];
      Uface[0][2] = OldRface[2][2];

      Rface[0][2] = OldDface[2][2];
      Rface[1][2] = OldDface[2][1];
      Rface[2][2] = OldDface[2][0];

      Dface[2][0] = OldLface[0][0];
      Dface[2][1] = OldLface[1][0];
      Dface[2][2] = OldLface[2][0];

      Lface[0][0] = OldUface[0][2];
      Lface[1][0] = OldUface[0][1];
      Lface[2][0] = OldUface[0][0];
      Serial.println("B");

      break;
    case '6': //B'
      stepper3.step(stepsPerRevolution);

      setTempVariables();

      Bface[0][0] = OldBface[0][2]; Bface[0][1] = OldBface[1][2]; Bface[0][2] = OldBface[2][2];
      Bface[1][0] = OldBface[0][1]; Bface[1][1] = OldBface[1][1]; Bface[1][2] = OldBface[2][1];
      Bface[2][0] = OldBface[0][0]; Bface[2][1] = OldBface[1][0]; Bface[2][2] = OldBface[2][0];


      Uface[0][0] = OldLface[2][0];
      Uface[0][1] = OldLface[1][0];
      Uface[0][2] = OldLface[0][0];

      Lface[0][0] = OldDface[2][0];
      Lface[1][0] = OldDface[2][1];
      Lface[2][0] = OldDface[2][2];

      Dface[2][0] = OldRface[2][2];
      Dface[2][1] = OldRface[1][2];
      Dface[2][2] = OldRface[0][2];

      Rface[0][2] = OldUface[0][0];
      Rface[1][2] = OldUface[0][1];
      Rface[2][2] = OldUface[0][2];
      Serial.println("B");




      break;
    case '7': // R
      stepper4.step(-stepsPerRevolution);
      setTempVariables();

      Rface[0][0] = OldRface[2][0]; Rface[0][1] = OldRface[1][0]; Rface[0][2] = OldRface[0][0];
      Rface[1][0] = OldRface[2][1]; Rface[1][1] = OldRface[1][1]; Rface[1][2] = OldRface[0][1];
      Rface[2][0] = OldRface[2][2]; Rface[2][1] = OldRface[1][2]; Rface[2][2] = OldRface[0][2];
      Uface[0][2] = OldFface[0][2]; Uface[1][2] = OldFface[1][2]; Uface[2][2] = OldFface[2][2];
      Fface[0][2] = OldDface[0][2]; Fface[1][2] = OldDface[1][2]; Fface[2][2] = OldDface[2][2];
      Dface[0][2] = OldBface[2][0]; Dface[1][2] = OldBface[1][0]; Dface[2][2] = OldBface[0][0];
      Bface[0][0] = OldUface[2][2]; Bface[1][0] = OldUface[1][2]; Bface[2][0] = OldUface[0][2];
      Serial.println("R");

      break;
    case '8': // R'
      stepper4.step(stepsPerRevolution);
      setTempVariables();

      Rface[0][0] = OldRface[0][2]; Rface[0][1] = OldRface[1][2]; Rface[0][2] = OldRface[2][2];
      Rface[1][0] = OldRface[0][1]; Rface[1][1] = OldRface[1][1]; Rface[1][2] = OldRface[2][1];
      Rface[2][0] = OldRface[0][0]; Rface[2][1] = OldRface[1][0]; Rface[2][2] = OldRface[2][0];
      Uface[0][2] = OldBface[2][0]; Uface[1][2] = OldBface[1][0]; Uface[2][2] = OldBface[0][0];
      Fface[0][2] = OldUface[0][2]; Fface[1][2] = OldUface[1][2]; Fface[2][2] = OldUface[2][2];
      Dface[0][2] = OldFface[0][2]; Dface[1][2] = OldFface[1][2]; Dface[2][2] = OldFface[2][2];
      Bface[0][0] = OldDface[2][2]; Bface[1][0] = OldDface[1][2]; Bface[2][0] = OldDface[0][2];

      Serial.println("R'");
      break;
    case '9': // D
      stepper5.step(stepsPerRevolution);
      setTempVariables();

      Dface[0][0] = OldDface[2][0]; Dface[0][1] = OldDface[1][0]; Dface[0][2] = OldDface[0][0];
      Dface[1][0] = OldDface[2][1]; Dface[1][1] = OldDface[1][1]; Dface[1][2] = OldDface[0][1];
      Dface[2][0] = OldDface[2][2]; Dface[2][1] = OldDface[1][2]; Dface[2][2] = OldDface[0][2];
      Fface[2][0] = OldLface[2][0]; Fface[2][1] = OldLface[2][1]; Fface[2][2] = OldLface[2][2];
      Rface[2][0] = OldFface[2][0]; Rface[2][1] = OldFface[2][1]; Rface[2][2] = OldFface[2][2];
      Bface[2][0] = OldRface[2][0]; Bface[2][1] = OldRface[2][1]; Bface[2][2] = OldRface[2][2];
      Lface[2][0] = OldBface[2][0]; Lface[2][1] = OldBface[2][1]; Lface[2][2] = OldBface[2][2];
      Serial.println("D");

      break;
    case '0': // D';
      stepper5.step(-stepsPerRevolution);
      setTempVariables();

      Dface[0][0] = OldDface[0][2]; Dface[0][1] = OldDface[1][2]; Dface[0][2] = OldDface[2][2];
      Dface[1][0] = OldDface[0][1]; Dface[1][1] = OldDface[1][1]; Dface[1][2] = OldDface[2][1];
      Dface[2][0] = OldDface[0][0]; Dface[2][1] = OldDface[1][0]; Dface[2][2] = OldDface[2][0];
      Fface[2][0] = OldRface[2][0]; Fface[2][1] = OldRface[2][1]; Fface[2][2] = OldRface[2][2];
      Rface[2][0] = OldBface[2][0]; Rface[2][1] = OldBface[2][1]; Rface[2][2] = OldBface[2][2];
      Bface[2][0] = OldLface[2][0]; Bface[2][1] = OldLface[2][1]; Bface[2][2] = OldLface[2][2];
      Lface[2][0] = OldFface[2][0]; Lface[2][1] = OldFface[2][1]; Lface[2][2] = OldFface[2][2];
      Serial.println("D'");

      break;
    case 'A': // U
      stepper6.step(-stepsPerRevolution);
      setTempVariables();
      Uface[0][0] = OldUface[2][0]; Uface[0][1] = OldUface[1][0]; Uface[0][2] = OldUface[0][0];
      Uface[1][0] = OldUface[2][1]; Uface[1][1] = OldUface[1][1]; Uface[1][2] = OldUface[0][1];
      Uface[2][0] = OldUface[2][2]; Uface[2][1] = OldUface[1][2]; Uface[2][2] = OldUface[0][2];
      Fface[0][0] = OldRface[0][0]; Fface[0][1] = OldRface[0][1]; Fface[0][2] = OldRface[0][2];
      Rface[0][0] = OldBface[0][0]; Rface[0][1] = OldBface[0][1]; Rface[0][2] = OldBface[0][2];
      Bface[0][0] = OldLface[0][0]; Bface[0][1] = OldLface[0][1]; Bface[0][2] = OldLface[0][2];
      Lface[0][0] = OldFface[0][0]; Lface[0][1] = OldFface[0][1]; Lface[0][2] = OldFface[0][2];
      Serial.println("U");

      break;
    case 'B': // U'
      stepper6.step(stepsPerRevolution);
      setTempVariables();
      Uface[0][0] = OldUface[0][2]; Uface[0][1] = OldUface[1][2]; Uface[0][2] = OldUface[2][2];
      Uface[1][0] = OldUface[0][1]; Uface[1][1] = OldUface[1][1]; Uface[1][2] = OldUface[2][1];
      Uface[2][0] = OldUface[0][0]; Uface[2][1] = OldUface[1][0]; Uface[2][2] = OldUface[2][0];
      Fface[0][0] = OldLface[0][0]; Fface[0][1] = OldLface[0][1]; Fface[0][2] = OldLface[0][2];
      Rface[0][0] = OldFface[0][0]; Rface[0][1] = OldFface[0][1]; Rface[0][2] = OldFface[0][2];
      Bface[0][0] = OldRface[0][0]; Bface[0][1] = OldRface[0][1]; Bface[0][2] = OldRface[0][2];
      Lface[0][0] = OldBface[0][0]; Lface[0][1] = OldBface[0][1]; Lface[0][2] = OldBface[0][2];
      Serial.println("U'");

      break;
    case 'C': //printing the cube out
      printCube();
      break;

    case 'D': //resetting the cube state
      initCube();
      Serial.println("Cube reset");
      break;

    case '*'://send the state to the PC and solve
      delay(5000);
      char (*cubeFaces[])[3][3] = {&Uface, &Rface, &Fface, &Dface, &Lface, &Bface};
      String cubeState = "Solve:";
      bool solutionRecieved = false;
      String solution = "";

      for (int i = 0; i < 6; i++)
      {
        for (int j = 0; j < 3; j++)
        {
          for (int k = 0; k <  3; k++)
          {
            cubeState += (*cubeFaces[i])[j][k];
          }
        }
      }
      Serial.println(cubeState);

      while (!solutionRecieved)
      {
        if (Serial.available() > 0)
        {
          solution = Serial.readStringUntil('\n');
          solutionRecieved = true;
        }
      }

      unsigned long startTime = millis();
      
      for (int i = 0; i < solution.length(); i++)
      {

        switch (solution[i])
        {
          case 'F':
            stepper1.step(-stepsPerRevolution);
            break;
          case 'L':
            stepper2.step(-stepsPerRevolution);
            break;
          case 'B':
            stepper3.step(-stepsPerRevolution);
            break;
          case 'R':
            stepper4.step(-stepsPerRevolution);
            break;
          case 'D':
            stepper5.step(stepsPerRevolution);
            break;
          case 'U':
            stepper6.step(-stepsPerRevolution);
            break;
        }
        delay(2);

      }
      unsigned long endTime = millis();

      Serial.println(endTime-startTime);
      initCube();

      break;
  }

}

void initCube()
{
  char initF[3][3] = {{'F', 'F', 'F'}, {'F', 'F', 'F'}, {'F', 'F', 'F'}};
  char initR[3][3] = {{'R', 'R', 'R'}, {'R', 'R', 'R'}, {'R', 'R', 'R'}};
  char initL[3][3] = {{'L', 'L', 'L'}, {'L', 'L', 'L'}, {'L', 'L', 'L'}};
  char initD[3][3] = {{'D', 'D', 'D'}, {'D', 'D', 'D'}, {'D', 'D', 'D'}};
  char initU[3][3] = {{'U', 'U', 'U'}, {'U', 'U', 'U'}, {'U', 'U', 'U'}};
  char initB[3][3] = {{'B', 'B', 'B'}, {'B', 'B', 'B'}, {'B', 'B', 'B'}};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      Fface[i][j] = initF[i][j];
      Rface[i][j] = initR[i][j];
      Lface[i][j] = initL[i][j];
      Dface[i][j] = initD[i][j];
      Uface[i][j] = initU[i][j];
      Bface[i][j] = initB[i][j];
    }
  }
}


//Sets up old variables
void setTempVariables()
{

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      OldUface[i][j] = Uface[i][j];
      OldDface[i][j] = Dface[i][j];
      OldLface[i][j] = Lface[i][j];
      OldRface[i][j] = Rface[i][j];
      OldFface[i][j] = Fface[i][j];
      OldBface[i][j] = Bface[i][j];
    }
  }
}

//For debugging
void printCube()
{
  Serial.println("F Face");
  for (int i = 0; i < 3; i++) {
    Serial.print(Fface[i][0]);
    Serial.print(Fface[i][1]);
    Serial.println(Fface[i][2]);
  }
  Serial.println("R Face ");
  for (int i = 0; i < 3; i++) {
    Serial.print(Rface[i][0]);
    Serial.print(Rface[i][1]);
    Serial.println(Rface[i][2]);
  }
  Serial.println("L Face ");
  for (int i = 0; i < 3; i++) {
    Serial.print(Lface[i][0]);
    Serial.print(Lface[i][1]);
    Serial.println(Lface[i][2]);
  }
  Serial.println("U Face ");
  for (int i = 0; i < 3; i++) {
    Serial.print(Uface[i][0]);
    Serial.print(Uface[i][1]);
    Serial.println(Uface[i][2]);
  }
  Serial.println("D Face ");
  for (int i = 0; i < 3; i++) {
    Serial.print(Dface[i][0]);
    Serial.print(Dface[i][1]);
    Serial.println(Dface[i][2]);
  }
  Serial.println("B Face ");
  for (int i = 0; i < 3; i++) {
    Serial.print(Bface[i][0]);
    Serial.print(Bface[i][1]);
    Serial.println(Bface[i][2]);
  }
}
