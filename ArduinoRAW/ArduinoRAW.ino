#include <HP20x_dev.h>
#include "Arduino.h"
#include "Wire.h"
#include <KalmanFilter.h>
#include <math.h>
unsigned char ret = 0;

/* Instance */
KalmanFilter t_filter;    //temperature filter
KalmanFilter p_filter;    //pressure filter
KalmanFilter a_filter;    //altitude filter

float deltaP=0;//variable globale
unsigned int count=0;

void setup() {
    Serial.begin(9600);        // start serial for output
    Serial.println("Code de test pour Arduino UNO pour calcul de l'altitude Anthony - Theotime");
    /* Power up,delay 150ms,until voltage is stable */
    delay(150);
    /* Reset HP20x_dev */
    HP20x.begin();
    delay(100);
}
void loop() {
    Serial.println("------------------\n");
    float t=13+273.15; // 13 étant la température d'aujourd'hui en °C
    Serial.println(t);
    float altitude_ref = 505; // notre altitude lors du premier démarrage en mètres
    long p_QFE_RAW = HP20x.ReadPressure();
    float p_QFE= p_QFE_RAW / 100.0; //le type float est important pour avoir une précision à 2chiffres après la virgule
    Serial.println("QFE mesuré:");
    Serial.println(p_QFE);
    float p_QNH=1010; // récupéré sur la station météo d'Andrézieux-Bouthéon
    Serial.println("QNH :");
    Serial.println(p_QNH);
    float p_QFE_ref=  p_QNH*exp((-7*9.81)/(2*1006*t)*altitude_ref);
    Serial.println("QFE référence :");
    Serial.println(p_QFE_ref);
    Serial.println("Rapport :");
    if(count<2)
    {
      deltaP=p_QFE_ref-p_QFE;
      count++;
    }
    float rapport=(p_QFE+deltaP)/p_QNH;
    Serial.println("testlog:");
    float ln=log(rapport);
    Serial.print(ln);
    float z=-(2*1006*t*ln)/(7*9.81);
    Serial.println("Altitude :");
    Serial.print(z);
    Serial.println("mètres");
    delay(1000); // pour n'avoir qu'une sortie par seconde
}
