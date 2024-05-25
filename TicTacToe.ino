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
void reset(){
  if(digitalRead(RESET) == HIGH){
    for(i = 0; i < 9; i++){
      off(XGEN[i]);
      off(QGEN[i]);
      REN[i] = 0;
      turn = true;
    }
    
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