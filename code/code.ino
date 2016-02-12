#define ziel1 1
#define czer1 3
#define zielp1 5
#define czerp1 6
#define pom 7
#define ziel2 9
#define czer2 10
#define zielp2 12
#define czerp2 13
#define on LOW
#define off HIGH
#define btn1 4
#define btn2 11
#define nMig 5 //liczba mignięć zielonego przed zapaleniem czerwonego światła na przejścu dla pieszych (normalnie 5)
#define migDelay 500 //Czas świecenia i nieświecenia zielonej diody podczas migania (normaline ok. 0,5s)
#define zielPrzejscie 1500 //Czas zielonego na przejsciu. Całkowity czas fazy jest sumą tego, czasu migania (migDelay*9), czasu 

//unsigned long czas = millis();
//unsigned long currentTime;

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
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  start();
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
  delay(500);
}

void loop(){
  delay(15000);
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
  delay(2000);
  digitalWrite(pom, off);
  digitalWrite(czer1, on);
  delay(2000);
  digitalWrite(czer2, off);
  digitalWrite(ziel2, on);
  delay(500);
  digitalWrite(czerp1, off);
  digitalWrite(zielp1, on);
  delay(15000);
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
  delay(2000);
  digitalWrite(pom, off);
  digitalWrite(czer2, on);
  delay(2000);
  digitalWrite(czer1, off);
  digitalWrite(ziel1, on);
  delay(500);
  digitalWrite(czerp2, off);
  digitalWrite(zielp2, on);
}
