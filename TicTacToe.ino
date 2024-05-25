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
#define XTLI 2
#define XTMI 3
#define XTRI 4
#define XMLI 5
#define XMMI 6
#define XMRI 7
#define XBLI 8
#define XBMI 9
#define XBRI 10

#define QTLI 22
#define QTMI 23
#define QTRI 24
#define QMLI 25
#define QMMI 26
#define QMRI 27
#define QBLI 28
#define QBMI 29
#define QBRI 30

#define XTLO 31
#define XTMO 32
#define XTRO 33
#define XMLO 34
#define XMMO 35
#define XMRO 36
#define XBLO 37
#define XBMO 38
#define XBRO 39

#define QTLO 40
#define QTMO 41
#define QTRO 42
#define QMLO 43
#define QMMO 44
#define QMRO 45
#define QBLO 46
#define QBMO 47
#define QBRO 48

#define RESET 51
#define XTURN 52
#define QTURN 53

/*-------SIMPLIFICATION TOOLS-------*/
int REN[9] = {0,0,0,0,0,0,0,0,0};

int XSEL[9] = {XTLI,XTMI,XTRI,XMLI,XMMI,XMRI,XBLI,XBMI,XBRI};
int QSEL[9] = {QTLI,QTMI,QTRI,QMLI,QMMI,QMRI,QBLI,QBMI,QBRI};

int XGEN[9] = {XTLO,XTMO,XTRO,XMLO,XMMO,XMRO,XBLO,XBMO,XBRO};
int QGEN[9] = {QTLO,QTMO,QTRO,QMLO,QMMO,QMRO,QBLO,QBMO,QBRO};

/*-------SYS VARIABLES-------*/
int i;
bool turn = true; // true = X, false =Q

/*-------I/O INIZIALIZATION-------*/
void setup() {
  Serial.begin(9600);
  for(i = 0; i < 9; i++){
    pinMode(XSEL[i], INPUT);
    pinMode(QSEL[i], INPUT);

    pinMode(XGEN[i], OUTPUT);
    pinMode(QGEN[i], OUTPUT);
  }
  pinMode(RESET, INPUT);
  pinMode(XTURN, OUTPUT);
  pinMode(QTURN, OUTPUT);
}

void loop() {
  debug();
  wins();
  reset();
  turnSys();
  TL();
  TM();
  TR();
  ML();
  MM();
  MR();
  BL();
  BM();
  BR();
}

/*-------TOOL FUNCTIONS-------*/
void on(int pin){
  digitalWrite(pin, HIGH);
}

void off(int pin){
  digitalWrite(pin, LOW);
}

/*-------SYS FUNCTIONS-------*/
void clean() {
  for(i = 0; i < 9; i++){
    off(XGEN[i]);
    off(QGEN[i]);
    REN[i] = 0;
  }
}

void reset(){
  if(digitalRead(RESET) == HIGH){
    clean();
    turn = true;
  }
}

void turnSys(){
  if(turn == true){
    on(XTURN);
    off(QTURN);
  } else {
    off(XTURN);
    on(QTURN);
  }
}

/*-------I/O FUNCTIONS-------*/
void TL(){
  if(REN[0] == 0){
    if(turn == true){
      if(digitalRead(XSEL[0]) == HIGH){
        on(XGEN[0]);
        REN[0] = 1;
        turn = false;
      }
    } else {
      if(digitalRead(QSEL[0]) == HIGH){
        on(QGEN[0]);
        REN[0] = 2;
        turn = true;
      }
    }
  }
}

void TM(){
  if(REN[1] == 0){
    if(turn == true){
      if(digitalRead(XSEL[1]) == HIGH){
        on(XGEN[1]);
        REN[1] = 1;
        turn = false;
      }
    } else {
      if(digitalRead(QSEL[1]) == HIGH){
        on(QGEN[1]);
        REN[1] = 2;
        turn = true;
      }
    }
  }
}

void TR(){
  if(REN[2] == 0){
    if(turn == true){
      if(digitalRead(XSEL[2]) == HIGH){
        on(XGEN[2]);
        REN[2] = 1;
        turn = false;
      }
    } else {
      if(digitalRead(QSEL[2]) == HIGH){
        on(QGEN[2]);
        REN[2] = 2;
        turn = true;
      }
    }
  }
}

void ML(){
  if(REN[3] == 0){
    if(turn == true){
      if(digitalRead(XSEL[3]) == HIGH){
        on(XGEN[3]);
        REN[3] = 1;
        turn = false;
      }
    } else {
      if(digitalRead(QSEL[3]) == HIGH){
        on(QGEN[3]);
        REN[3] = 2;
        turn = true;
      }
    }
  }
}

void MM(){
  if(REN[4] == 0){
    if(turn == true){
      if(digitalRead(XSEL[4]) == HIGH){
        on(XGEN[4]);
        REN[4] = 1;
        turn = false;
      }
    } else {
      if(digitalRead(QSEL[4]) == HIGH){
        on(QGEN[4]);
        REN[4] = 2;
        turn = true;
      }
    }
  }
}

void MR(){
  if(REN[5] == 0){
    if(turn == true){
      if(digitalRead(XSEL[5]) == HIGH){
        on(XGEN[5]);
        REN[5] = 1;
        turn = false;
      }
    } else {
      if(digitalRead(QSEL[5]) == HIGH){
        on(QGEN[5]);
        REN[5] = 2;
        turn = true;
      }
    }
  }
}

void BL(){
  if(REN[6] == 0){
    if(turn == true){
      if(digitalRead(XSEL[6]) == HIGH){
        on(XGEN[6]);
        REN[6] = 1;
        turn = false;
      }
    } else {
      if(digitalRead(QSEL[6]) == HIGH){
        on(QGEN[6]);
        REN[6] = 2;
        turn = true;
      }
    }
  }
}

void BM(){
  if(REN[7] == 0){
    if(turn == true){
      if(digitalRead(XSEL[7]) == HIGH){
        on(XGEN[7]);
        REN[7] = 1;
        turn = false;
      }
    } else {
      if(digitalRead(QSEL[7]) == HIGH){
        on(QGEN[7]);
        REN[7] = 2;
        turn = true;
      }
    }
  }
}

void BR(){
  if(REN[8] == 0){
    if(turn == true){
      if(digitalRead(XSEL[8]) == HIGH){
        on(XGEN[8]);
        REN[8] = 1;
        turn = false;
      }
    } else {
      if(digitalRead(QSEL[8]) == HIGH){
        on(QGEN[8]);
        REN[8] = 2;
        turn = true;
      }
    }
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

void win(int a, int b, int c, int p) {
  if(REN[a] == p && REN[b] == p && REN[c] == p) {
    clean();
    for(i = 0; i<9; i++) {
      REN[i] = 3;
    }
    digitalWrite(REN[a], HIGH);
    digitalWrite(REN[b], HIGH);
    digitalWrite(REN[c], HIGH);
  }
}

void debug(){
	Serial.print(turn);
	Serial.print(" REN[");
	Serial.print(REN[0]);
	Serial.print(REN[1]);
	Serial.print(REN[2]);
	Serial.print(REN[3]);
	Serial.print(REN[4]);
	Serial.print(REN[5]);
	Serial.print(REN[6]);
	Serial.print(REN[7]);
	Serial.print(REN[8]);
	Serial.print("] ");
	Serial.print(" XGEN[");
	Serial.print(digitalRead(XGEN[0]));
	Serial.print(digitalRead(XGEN[1]));
	Serial.print(digitalRead(XGEN[2]));
	Serial.print(digitalRead(XGEN[3]));
	Serial.print(digitalRead(XGEN[4]));
	Serial.print(digitalRead(XGEN[5]));
	Serial.print(digitalRead(XGEN[6]));
	Serial.print(digitalRead(XGEN[7]));
	Serial.print(digitalRead(XGEN[8]));
	Serial.println("] ");
  Serial.print(" QGEN[");
	Serial.print(digitalRead(QGEN[0]));
	Serial.print(digitalRead(QGEN[1]));
	Serial.print(digitalRead(QGEN[2]));
	Serial.print(digitalRead(QGEN[3]));
	Serial.print(digitalRead(QGEN[4]));
	Serial.print(digitalRead(QGEN[5]));
	Serial.print(digitalRead(QGEN[6]));
	Serial.print(digitalRead(QGEN[7]));
	Serial.print(digitalRead(QGEN[8]));
	Serial.println("] ");
}
