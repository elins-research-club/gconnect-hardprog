#include "Gsoil_lib.h"

int limas;// titik terbasah (Ngambil dari nilai analog read, ini merupakan proses kalibrasinya, biar bisa menentukan 0% itu kayak gimana dan 100% itu kayak gimana)
int liwah;// titik terkering



void Tuning(int a,int b){
  limas = a;
  liwah = b;
}

int Soilread(int pin){

int value;
for (int z=0; z<100; z++){
  int a = analogRead(pin);
  value=value+a;
}
int presentage = value/100;
  Serial.print("Analog output: ");

  Serial.println(value);

  int x = map(presentage, liwah ,limas,0,100 );

  return x;

}
