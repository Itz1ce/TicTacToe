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
int sel;
int i;
int randomNum;
bool turn = true; // true = X-Player1, false = Q-Player2

/*-------I/O INIZIALIZATION-------*/
void setup() {
	Serial.begin(9600);
	for(i = 0; i < 9; i++) {
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
	wins();
	reset();
	turnSys();
	if(digitalRead(XSEL[0]) == HIGH || digitalRead(QSEL[0]) == HIGH) {	sel=0;}
	if(digitalRead(XSEL[1]) == HIGH || digitalRead(QSEL[1]) == HIGH) {	sel=1;}
	if(digitalRead(XSEL[2]) == HIGH || digitalRead(QSEL[2]) == HIGH) {	sel=2;}
	if(digitalRead(XSEL[3]) == HIGH || digitalRead(QSEL[3]) == HIGH) {	sel=3;}
	if(digitalRead(XSEL[4]) == HIGH || digitalRead(QSEL[4]) == HIGH) {	sel=4;}
	if(digitalRead(XSEL[5]) == HIGH || digitalRead(QSEL[5]) == HIGH) {	sel=5;}
	if(digitalRead(XSEL[6]) == HIGH || digitalRead(QSEL[6]) == HIGH) {	sel=6;}
	if(digitalRead(XSEL[7]) == HIGH || digitalRead(QSEL[7]) == HIGH) {	sel=7;}
	if(digitalRead(XSEL[8]) == HIGH || digitalRead(QSEL[8]) == HIGH) {	sel=8;}
	if(REN[sel] == 0) {
		if(turn == true) {
			digitalWrite(XGEN[sel], HIGH);
			REN[sel] = 1;
		} else {
			digitalWrite(QGEN[sel], HIGH);
			REN[sel] = 2;
		}
		turn != turn;
	}
}

/*-------SYS FUNCTIONS-------*/
void clean() {
	for(i = 0; i < 9; i++) {
		digitalWrite(XGEN[i], LOW);
		digitalWrite(QGEN[i], LOW);
		REN[i] = 0;
	}
}

void reset() {
	if(digitalRead(RESET) == HIGH) {
		clean();
		turn = true;
	}
}

void turnSys() {
	if(turn == true) {
		digitalWrite(XTURN, HIGH);
		digitalWrite(QTURN, LOW);
	} else {
		digitalWrite(XTURN, LOW);
		digitalWrite(QTURN, HIGH);
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
