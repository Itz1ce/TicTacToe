/*

Tic Tac Toe
 - MADE BY BOTAN DENIS 4AAT-2023/24

*/
/*------- PIN INIZIALIZATION-------*/
/*--OUTPUT--*/
#define Q1R 23
#define Q2R 25
#define Q3R 27
#define Q4R 29
#define Q5R 31
#define Q6R 33
#define Q7R 35
#define Q8R 37
#define Q9R 39

#define Q1G 22
#define Q2G 24
#define Q3G 26
#define Q4G 28
#define Q5G 30
#define Q6G 32
#define Q7G 34
#define Q8G 36
#define Q9G 38

/*--INPUT--*/
#define P1R 2
#define P2R 3
#define P3R 4
#define P4R 5
#define P5R 6
#define P6R 7
#define P7R 8
#define P8R 9
#define P9R 10

#define P1G 45
#define P2G 43
#define P3G 41
#define P4G 50
#define P5G 48
#define P6G 46
#define P7G 44
#define P8G 42
#define P9G 40

/*--TURN LED--*/
#define TR 11
#define TG 12

#define debugPin 13

/*-------SYS VARIABLES-------*/
int turn = false, time = 500, ledState = HIGH;
int CH[9] = {0,0,0,0,0,0,0,0,0}; //Led state array

/*-------PIN ARRAYS-------*/
int QR[9] = {Q1R,Q2R,Q3R,Q4R,Q5R,Q6R,Q7R,Q8R,Q9R};
int QG[9] = {Q1G,Q2G,Q3G,Q4G,Q5G,Q6G,Q7G,Q8G,Q9G};

int PR[9] = {P1R,P2R,P3R,P4R,P5R,P6R,P7R,P8R,P9R};
int PG[9] = {P1G,P2G,P3G,P4G,P5G,P6G,P7G,P8G,P9G};

/*-------I/O INIZIALIZATION-------*/
void setup() {
  pinMode(debugPin, INPUT);
  for(int i = 0; i < 9; i++) {
    pinMode(PR[i], INPUT);
    pinMode(PG[i], INPUT);

    pinMode(QR[i], OUTPUT);
    pinMode(QG[i], OUTPUT);
  }
}

/*-------I/O ENGINE-------*/
void loop() {
  turnLed();
  full();
  /*--Debug Mode (without turns)--*/
  if (digitalRead(debugPin) == LOW) {
    for(int i = 0; i < 9; i++) {
      if(digitalRead(PR[i]) == HIGH) {
        digitalWrite(QR[i], HIGH);
        CH[i] = 9;
      }
      if(digitalRead(PG[i]) == HIGH) {
        digitalWrite(QG[i], HIGH);
        CH[i] = 9;
      }
    }
  } else {
    /*--Default Mode--*/
    wins();
    for(int i = 0; i < 9; i++) {
      if(digitalRead(PR[i]) == HIGH && turn == true && CH[i] == 0) {
        digitalWrite(QR[i], HIGH);
        turn = false;
        CH[i] = 1;
      }
      if(digitalRead(PG[i]) == HIGH && turn == false && CH[i] == 0) {
        digitalWrite(QG[i], HIGH);
        turn = true;
        CH[i] = 2;
      }
    }
  }
}

/*-------SYS FUNCTIONS-------*/
/*--Turn led handling--*/
void turnLed() {
  if(turn == true) {
    digitalWrite(TR, HIGH);
    digitalWrite(TG, LOW);
  } else {
    digitalWrite(TR, LOW);
    digitalWrite(TG, HIGH);
  }
}

/*--Board Reset--*/
void clean() { 
  for(int i = 0; i < 9; i++) {
    digitalWrite(QR[i], LOW);
    digitalWrite(QG[i], LOW);
    CH[i] = 0;
  }
}

/*--Board Reset handling--*/
void full() {
  if(CH[0] != 0 && CH[1] != 0 && CH[2] != 0 && CH[3] != 0 && CH[4] != 0 && CH[5] != 0 && CH[6] != 0 && CH[7] != 0 && CH[8] != 0) {
    clean();
  }
}

/*--Win handling--*/
void win(int a, int b, int c, int p) {
  if(CH[a] == p && CH[b] == p && CH[c] == p) {
    if(p == 2){
      int CHG[3] = {a,b,c};
      for(int i = 0; i < 3; i++) {
        for(int i = 0; i < 3; i++) {
          digitalWrite(QG[CHG[i]], HIGH);
        }
        delay(time);
        for(int i = 0; i < 3; i++) {
          digitalWrite(QG[CHG[i]], LOW);
        }
        delay(time);
      }
    }
    if(p == 1) {
      int CHR[3] = {a,b,c};
      for(int i = 0; i < 3; i++) {
        for(int i = 0; i < 3; i++) {
          digitalWrite(QR[CHR[i]], HIGH);
        }
        delay(time);
        for(int i = 0; i < 3; i++) {
          digitalWrite(QR[CHR[i]], LOW);
        }
        delay(time);
      }
    }
    for(int i = 0; i<9; i++) {
      CH[i] = 3;
    }
    clean();
  }
}

/*--Win triggers--*/
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
