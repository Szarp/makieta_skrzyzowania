//Światła nr 1:
//*dla samochodów
#define ziel1 0
#define czer1 1
//*dla pieszych
#define zielp1 4
#define czerp1 5
//pomarańczowe światło dla wszystkich
#define pom 7
//Światła nr 2:
//*dla samochodów
#define ziel2 9
#define czer2 10
//*dla pieszych
#define zielp2 12
#define czerp2 13
//Definicje stanu dla włączonych i wyłączonych świateł
#define on LOW
#define off HIGH
//Przyciski dla przejść
//*1
#define btn1 2
//*2
#define btn2 3
//Światła przycisków
#define swiatloBtn1 6
#define swiatloBtn2 11
//Definicje czasów
#define migDelay 500 //Czas świecenia i nieświecenia zielonej diody podczas migania (normaline ok. 0,5s)
#define zielPrzejscie 15000 //Czas świecenia zielonego na przejsciu. 
#define pomDelay 2000 //Czas świecenia pomarańczowego.
#define czerCale 2000 //Czas świecenia czerwonego wszędzie, żeby "rozładować" skrzyżowanie.
#define piesiDelay1 500 //Czas przez, który piesi jeszcze przejść nie mogą, ale auta już tak.
#define piesiDelay2 500 //Czas przez, który piesi już przejść nie mogą, ale auta jeszcze tak.
//Inne definicje:
#define nMig 5 //liczba mignięć zielonego przed zapaleniem czerwonego światła na przejścu dla pieszych (normalnie 5)

//Stany przycisków na przejściach
int btnState1 = 0;
int btnState2 = 0;

void start(){
  digitalWrite(ziel1, on);
  digitalWrite(czer1, off);
  digitalWrite(zielp1, off);
  digitalWrite(czerp1, on);
  digitalWrite(pom, off);
  digitalWrite(ziel2, off);
  digitalWrite(czer2, on);
  digitalWrite(zielp2, on);
  digitalWrite(czerp2, off);
}

void setup(){
  pinMode(ziel1, OUTPUT);
  pinMode(czer1, OUTPUT);
  pinMode(zielp1, OUTPUT);
  pinMode(czerp1, OUTPUT);
  pinMode(pom, OUTPUT);
  pinMode(ziel2, OUTPUT);
  pinMode(czer2, OUTPUT);
  pinMode(zielp2, OUTPUT);
  pinMode(czerp2, OUTPUT);
  pinMode(swiatloBtn1, OUTPUT);
  pinMode(swiatloBtn2, OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(btn1), przycisk1, RISING);
  attachInterrupt(digitalPinToInterrupt(btn2), przycisk2, RISING);
  start();
}

void przycisk1(){
  btnState1 = 1;
  digitalWrite(swiatloBtn1, on);
}

void przycisk2(){
  btnState2 = 1;
  digitalWrite(swiatloBtn2, on);
}

void migaj(int nrPrzejscia){
  int a;
  int b;
  switch(nrPrzejscia){
    case 1:
      a = zielp1;
      b = czerp1;
      break;
    case 2:
      a = zielp2;
      b = czerp2;
      break;
  }
  for(int x = 0; x < nMig; x++){
    digitalWrite(a, off);
    delay(migDelay);
    if(x < (nMig-1)){
      digitalWrite(a, on);
      delay(migDelay);
    }
  }
  digitalWrite(b, on);
  delay(piesiDelay2);
}

void loop(){
  delay(zielPrzejscie);
  /*for(int x = 0; x < 5; x++){
    digitalWrite(zielp2, off);
    delay(500);
    if(x<4){
      digitalWrite(zielp2, on);
      delay(500);
    }
  }
  digitalWrite(czerp2, on);
  delay(500);
  */
  migaj(2);
  digitalWrite(ziel1, off);
  digitalWrite(pom, on);
  delay(pomDelay);
  digitalWrite(pom, off);
  digitalWrite(czer1, on);
  delay(czerCale);
  digitalWrite(czer2, off);
  digitalWrite(ziel2, on);
  delay(piesiDelay1);
  digitalWrite(czerp1, off);
  if(btnState1 == 1){
    digitalWrite(swiatloBtn1, off);
    digitalWrite(zielp1, on);
    btnState1 = 0;
  }
  delay(zielPrzejscie);
  /*for(int x = 0; x < 5; x++){
    digitalWrite(zielp1, off);
    delay(500);
    if(x<4){
      digitalWrite(zielp1, on);
      delay(500);
    }
  }
  digitalWrite(czerp1, on);
  delay(500);
  */
  migaj(1);
  digitalWrite(ziel2, off);
  digitalWrite(pom, on);
  delay(pomDelay);
  digitalWrite(pom, off);
  digitalWrite(czer2, on);
  delay(czerCale);
  digitalWrite(czer1, off);
  digitalWrite(ziel1, on);
  delay(piesiDelay1);
  digitalWrite(czerp2, off);
  if(btnState2 == 1){
    digitalWrite(swiatloBtn2, off);
    digitalWrite(zielp2, on);
    btnState2 = 0;
  }
}
