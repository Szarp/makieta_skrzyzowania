###2 Programowanie Arduino.
 Arduino aby działać musi zostać zaprogramowane. Programuje się je w języku Arduino, opartym na językach C/C++.
Program jest kompilowany, czyli przetwarzany na język zrozumiały dla urządzenia, oraz na nie wgrywany za pomocą
Arduino IDE.
![Arduino IDE](https://www.arduino.cc/en/pub/skins/arduinoWide/img/ArduinoAPP-01.svg)

####2.1 Budowa.
  Język Arduino można podzielić na 3 główne części:
  1. Strukturę
  2. Zmienne
  3. Funkcje

#####2.1.1  Struktura
Aby program działał niezbędne są dwie funkcje:

  * void setup() - wykonywana tylko raz na początku programu
  * void loop() - wykonywana cały czas po wykonaniu funkcji "setup"
  
Wśród struktur możemy wyróżnić także:

  * Struktury kontrolne:

    * if - wykonuje kod zawary w nawiasach klamrowych, jeśli warunek w zwykłych nawiasach jest spełniony.
		if(wartosc1 o wartosc2){}
		najczęściej stosuje się:
		> - jest większe
		< - jest mniejsze
		== - jest równe
		!= - jest różne od
    * else - wykonuje kod zawary w nawiasach klamrowych, jeśli warunek w if nie jest spełniony. **Używany tylko razem z "if".**
	for - jest to pętla, której zawartość w klamrach zostanie tyle razy wykonana, ile razy spełniony jest warunek na wejściu 
	for(index, warunek dla którego funkcja ma się wykonywać, co zrobić z indeksem po wykonaniu)
	for (int x=0;x<3;x++){}
  * Dalszą składnię
  
  * Operatory arytmetyczne
  * Operatory porównawcze
  * Operatory logiczne
  * Operatory wskazujące
  * Operatory bitowe
  * Operatory złożone

[https://www.arduino.cc/en/Guide/Introduction, https://www.arduino.cc/en/Reference/HomePage]
