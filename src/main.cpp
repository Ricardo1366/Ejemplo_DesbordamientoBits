#include <Arduino.h>

#define VALORINICIAL 248
#define VALORAMEDIR 5

byte milis;
byte siguiente1;
byte siguiente2;
byte intervalo;
bool continuar;

void setup() {
  Serial.begin(115200);
  milis = VALORINICIAL;
  intervalo = VALORAMEDIR;
  siguiente1 = milis + intervalo;
  siguiente2 = milis;
  

  while (!continuar)
  {
    Serial.print(F("milis = "))  ;Serial.print(milis);
    Serial.print(F(" | siguiente1 "));Serial.print(siguiente1);
    Serial.print(F(" | siguiente2 "));Serial.println(siguiente2);

    Serial.print(milis); Serial.print(" >= "); Serial.print(siguiente1) ; Serial.print( " -> "); Serial.println((bool)(milis >= siguiente1));
    Serial.print(milis); Serial.print(" - "); Serial.print(siguiente2) ; Serial.print( " = "); Serial.print(milis - siguiente2);
    Serial.print( " >= "); Serial.print(intervalo);
    Serial.print( " -> "); Serial.println((bool)(milis - siguiente2 >= intervalo));
    
    if (milis >= siguiente1)
    {
      Serial.println(F(" Se ha cumplido la condición milis >= siguiente"));
    }
    if (milis - siguiente2 >= intervalo)
    {
      Serial.print(F(" Se ha cumplido la condición siguiente - milis >= intervalo"));
      continuar = true;
    }
    milis++;
    delay(50);
  }
  Serial.println("\n---------------------------------------------------------------------");

  continuar = false;
  siguiente1 = milis + intervalo;
  siguiente2 = milis;

  while (!continuar)
  {
    Serial.print(F("milis = "))  ;Serial.print(milis);
    Serial.print(F(" | siguiente1 "));Serial.print(siguiente1);
    Serial.print(F(" | siguiente2 "));Serial.println(siguiente2);

    Serial.print(milis); Serial.print(" >= "); Serial.print(siguiente1) ; Serial.print( " -> "); Serial.println((milis >= siguiente1));
    Serial.print(milis); Serial.print(" - "); Serial.print(siguiente2) ; Serial.print( " = "); Serial.print((byte)(milis - siguiente2));
    Serial.print( " >= "); Serial.print(intervalo);
    Serial.print( " -> "); Serial.println((milis - siguiente2 >= intervalo));
    
    if (milis >= siguiente1)
    {
      Serial.println(F(" Se ha cumplido la condición milis >= siguiente"));
    }
    if ((byte)(milis - siguiente2) >= intervalo)
    {
      Serial.print(F(" Se ha cumplido la condición siguiente - milis >= intervalo"));
      continuar = true;
    }
    milis++;
    delay(50);
    if(milis==10){continuar = true;}
  }

}

void loop() {
  // put your main code here, to run repeatedly:
}

