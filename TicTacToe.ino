/*
Tic Tac Toe
 - MADE BY BOTAN DENIS 4AAT-2023/24
 
LEGEND:
  X = PLAYER WITH X
  Q = PLAYER WITH O
  I = INPUT
  O = OUTPUT
  T = TOP
  M = MIDDLE
  B = BOTTOM
  L = LEFT
  R = RIGHT
*/

/*------- PIN INIZIALIZATION-------*/
#define Q1R 23
#define Q2R 25
#define Q3R 27
#define Q4R 29
#define Q5R 31
#define Q6R 33
#define Q7R 35
#define Q8R 37
#define Q9R 39

#define Q1V 22
#define Q2V 24
#define Q3V 26
#define Q4V 28
#define Q5V 30
#define Q6V 32
#define Q7V 34
#define Q8V 36
#define Q9V 38

#define P1R 40
#define P2R 41
#define P3R 42
#define P4R 43
#define P5R 44
#define P6R 45
#define P7R 46
#define P8R 47
#define P9R 48

#define P1V 2
#define P2V 3
#define P3V 4
#define P4V 5
#define P5V 6
#define P6V 7
#define P7V 8
#define P8V 9
#define P9V 10

#define debugPin 13

/*-------SYS VARIABLES-------*/
int ledState = HIGH;

int turn = false;

/*-------SIMPLIFICATION TOOLS-------*/
int CH[9] = {0,0,0,0,0,0,0,0,0};

int QR[9] = {Q1R,Q2R,Q3R,Q4R,Q5R,Q6R,Q7R,Q8R,Q9R};
int QV[9] = {Q1V,Q2V,Q3V,Q4V,Q5V,Q6V,Q7V,Q8V,Q9V};

int PR[9] = {P1R,P2R,P3R,P4R,P5R,P6R,P7R,P8R,P9R};
int PV[9] = {P1V,P2V,P3V,P4V,P5V,P6V,P7V,P8V,P9V};

/*-------I/O INIZIALIZATION-------*/
void setup() {
  for(int i = 0; i < 9; i++){
    pinMode(PR[i], INPUT);
    pinMode(PV[i], INPUT);

    pinMode(QR[i], OUTPUT);
    pinMode(QV[i], OUTPUT);
  }
}

/*-------I/O ENGINE-------*/
void loop() {
  if (digitalRead(debugPin) == HIGH) {
    for(int i = 0; i < 9; i++){
      if(digitalRead(PR[i]) == HIGH) {
        digitalWrite(QR[i], HIGH);
      }
      if(digitalRead(PV[i]) == HIGH) {
        digitalWrite(QV[i], HIGH);
      }
    }
  } else {
    wins();
    for(int i = 0; i < 9; i++){
      if(digitalRead(PR[i]) == HIGH && turn == true && CH[i] == 0) {
        digitalWrite(QR[i], HIGH);
        turn = false;
        CH[i] = 1;
      }
      if(digitalRead(PV[i]) == HIGH && turn == false && CH[i] == 0) {
        digitalWrite(QV[i], HIGH);
        turn = true;
        CH[i] = 2;
      }
    }
  }
}

/*-------SYS FUNCTIONS-------*/
void clean() {
  for(int i = 0; i < 9; i++){
    digitalWrite(QR[i], LOW);
    digitalWrite(QV[i], LOW);
    CH[i] = 0;
  }
}

void win(int a, int b, int c, int p) {
  if(CH[a] == p && CH[b] == p && CH[c] == p) {
    if(p == 2){
      for(int i = 0; i < 4; i++){
        digitalWrite(QV[a], HIGH);
        digitalWrite(QV[b], HIGH);
        digitalWrite(QV[c], HIGH);
        delay(1000);
        digitalWrite(QV[a], LOW);
        digitalWrite(QV[b], LOW);
        digitalWrite(QV[c], LOW);
        delay(1000);
      }
    }
    if(p == 1){
      for(int i = 0; i < 4; i++){
        digitalWrite(QR[a], HIGH);
        digitalWrite(QR[b], HIGH);
        digitalWrite(QR[c], HIGH);
        delay(1000);
        digitalWrite(QR[a], LOW);
        digitalWrite(QR[b], LOW);
        digitalWrite(QR[c], LOW);
        delay(1000);
      }
    }
    for(int i = 0; i<9; i++) {
      CH[i] = 3;
    }
    clean();
  }
}

void wins() {
  //top-left->right
  win(0, 1, 2, 1);
  win(0, 1, 2, 2);
  //middle-left->right
  win(3, 4, 5, 1);
  win(3, 4, 5, 2);
  //bottom-left->right
  win(6, 7, 8, 1);
  win(6, 7, 8, 2);
  //left-top->bottom
  win(0, 3, 6, 1);
  win(0, 3, 6, 2);
  //middle-top->bottom
  win(1, 4, 7, 1);
  win(1, 4, 7, 2);
  //right-top->bottom
  win(2, 5, 8, 1);
  win(2, 5, 8, 2);
  //top-left->bottom-right
  win(0, 4, 8, 1);
  win(0, 4, 8, 2);
  //top-right->bottom-left
  win(2, 4, 6, 1);
  win(2, 4, 6, 2);
}
