    #define S0 4
    #define S1 5
    #define S2 6
    #define S3 7
    #define sensorOut 3
    const int frequencyR = 7; //1 = bleu /--/ 4 = orange /--/ 7 = blanc |
    const int frequencyG = 8; //2 = bleu /--/ 5 = orange /--/ 8 = blanc |
    const int frequencyB = 9; //3 = bleu /--/ 6 = orange /--/ 9 = blanc |
    int cylindre = 1;
    
//-----------------------------------------------------------------------------
const int pingPin = A0; // capteur avant
const int pingPin1 = A1; // capteur avant droite
const int pingPin2 = A2; // capteur avant gauche

// déclaration des variable pour le temps entre deux ondes et la distance
long duration, cm=0;
long duration1, cm1=0;
long duration2, cm2=0;

//-----------------------------------------------------------------------------
int lm1 = 8 ;
int lm2 = 11;
int lms = 9;
int rm1 = 12;
int rm2 = 13;
int rms = 10;

void setup() {
  
 // initialise la communication série
  Serial.begin(9600);
//------------------------------------------------------------------------------
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(lms,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(rms,OUTPUT);
//------------------------------------------------------------------------------
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
      
   // Setting frequency-scaling to 20%
  digitalWrite(S0,LOW);
  digitalWrite(S1,HIGH);
}

void loop()
{
  
  pinMode(pingPin, OUTPUT); 
  
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

// on utilise pulseIn pour recevoir une durée de type long
  pinMode(pingPin, INPUT);

  duration = pulseIn(pingPin, HIGH);

  // On converti la durée en distance grâce à une fonction que vous trouverez plus bas
  cm = microsecondsToCentimeters(duration);
  
  
  delay(100);

  
 //---------------------------------------------------------------------------------

  pinMode(pingPin1, OUTPUT); 
  
  digitalWrite(pingPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin1, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin1, LOW);

// on utilise pulseIn pour recevoir une durée de type long
  pinMode(pingPin1, INPUT);

  duration1 = pulseIn(pingPin1, HIGH);

  // On converti la durée en distance grâce à une fonction que vous trouverez plus bas
  cm1 = microsecondsToCentimeters(duration1);
  
  
  delay(100);
  //---------------------------------------------------------------------------------
 pinMode(pingPin2, OUTPUT); 
  
  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin2, LOW);

// on utilise pulseIn pour recevoir une durée de type long
  pinMode(pingPin2, INPUT);

  duration2 = pulseIn(pingPin2, HIGH);

  // On converti la durée en distance grâce à une fonction que vous trouverez plus bas
  cm2 = microsecondsToCentimeters(duration2);
  
  
  delay(100);
  //---------------------------------------------------------------------------------
      // Setting red filtered photodiodes to be read
      digitalWrite(S2,LOW);
      digitalWrite(S3,LOW);
      // Reading the output frequency
      //frequencyR = pulseIn(sensorOut, LOW);
      //Remaping the value of the frequency to the RGB Model of 0 to 255
      //frequencyR = map(frequencyR, -30000,30000,0,255);
      // Printing the value on the serial monitor
      
      delay(100);
  //---------------------------------------------------------------------------------
      // Setting Green filtered photodiodes to be read
      digitalWrite(S2,HIGH);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      //frequencyG = pulseIn(sensorOut, LOW);
      //Remaping the value of the frequency to the RGB Model of 0 to 255
      //frequencyG = map(frequencyG,-30000,30000,0,255);
      // Printing the value on the serial monitor
      
      delay(100);
 //---------------------------------------------------------------------------------
      // Setting Blue filtered photodiodes to be read
      digitalWrite(S2,LOW);
      digitalWrite(S3,HIGH);
      // Reading the output frequency
      //frequencyB = pulseIn(sensorOut, LOW);
      //Remaping the value of the frequency to the RGB Model of 0 to 255
      //frequencyB = map(frequencyB,-30000,30000,0,255);
      // Printing the value on the serial monitor
      
      delay(100);
  //---------------------------------------------------------------------------------
 
      if (cm > 15){
    analogWrite(lms,60);
    analogWrite(rms,60); 
    digitalWrite(lm2,HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1,LOW);
    digitalWrite(rm1,HIGH);}
          else if (cm < 15){
          analogWrite(lms,0);
          analogWrite(rms,0);
          digitalWrite(lm2,LOW);
          digitalWrite(rm2,LOW);
          digitalWrite(lm1,HIGH);
          digitalWrite(rm1,HIGH);
          delay(2000);
              if (((frequencyR==1 && frequencyG==2 && frequencyB==3)||(frequencyR==4 && frequencyG==5 && frequencyB==6))&&(cylindre==0)){
              Serial.print("MANOEUVRE DE RECUPERATION\n");
              cylindre++;}
               else if ((frequencyR==7 && frequencyG==8 && frequencyB==9)&&(cylindre == 1)){
                Serial.print("MANOEUVRE ZONE");
               }
                 else{
                 analogWrite(lms,0);
                 analogWrite(rms,0);
                 digitalWrite(lm2,LOW);
                 digitalWrite(rm2,LOW);
                 digitalWrite(lm1,HIGH);
                 digitalWrite(rm1,HIGH);
                 delay(2000);
                  analogWrite(lms,60);
                  analogWrite(rms,60);
                  digitalWrite(lm2,LOW);
                  digitalWrite(rm2,LOW);
                  digitalWrite(lm1,HIGH);
                  digitalWrite(rm1,HIGH);
                  delay(3000);}}
                  
      if (cm1 > 15){
      analogWrite(lms,60);
      analogWrite(rms,60); 
      digitalWrite(lm2,HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,LOW);
      digitalWrite(rm1,HIGH);}
          else if (cm1 < 15){
          analogWrite(lms,0);
          analogWrite(rms,0);
          digitalWrite(lm2,LOW);
          digitalWrite(rm2,LOW);
          digitalWrite(lm1,HIGH);
          digitalWrite(rm1,HIGH);
          delay(2000);
          Serial.print("ALLIGNEMENT DU ROBOT PAR RAPPORT AU CAPTEUR DROIT\n");
                 if (((frequencyR==1 && frequencyG==2 && frequencyB==3)||(frequencyR==4 && frequencyG==5 && frequencyB==6))&&(cylindre==0)){
                 Serial.print("MANOEUVRE DE RECUPERATION\n");
                 cylindre++;}
                  else if ((frequencyR==7 && frequencyG==8 && frequencyB==9)&&(cylindre == 1)){
                  Serial.print("MANOEUVRE ZONE");}
                   else { 
                   analogWrite(lms,0);
                   analogWrite(rms,0);
                   digitalWrite(lm2,LOW);
                   digitalWrite(rm2,LOW);
                   digitalWrite(lm1,HIGH);
                   digitalWrite(rm1,HIGH);
                   delay(2000);
                    analogWrite(lms,60);
                    analogWrite(rms,60);
                    digitalWrite(lm2,LOW);
                    digitalWrite(rm2,LOW);
                    digitalWrite(lm1,HIGH);
                    digitalWrite(rm1,HIGH);
                    delay(3000);}}

      if (cm2 > 15){
      analogWrite(lms,60);
      analogWrite(rms,60); 
      digitalWrite(lm2,HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,LOW);
      digitalWrite(rm1,HIGH);}
          else if (cm2 < 15){
          analogWrite(lms,0);
          analogWrite(rms,0);
          digitalWrite(lm2,LOW);
          digitalWrite(rm2,LOW);
          digitalWrite(lm1,HIGH);
          digitalWrite(rm1,HIGH);
          delay(2000);
          Serial.print("ALLIGNEMENT DU ROBOT PAR RAPPORT AU CAPTEUR GAUCHE\n");
                 if (((frequencyR==1 && frequencyG==2 && frequencyB==3)||(frequencyR==4 && frequencyG==5 && frequencyB==6))&&(cylindre==0)){
                  Serial.print("MANOEUVRE DE RECUPERATION\n");
                  cylindre++;}
                   else if ((frequencyR==7 && frequencyG==8 && frequencyB==9)&&(cylindre == 1)){
                   Serial.print("MANOEUVRE ZONE");}
                     else{
                     analogWrite(lms,0);
                     analogWrite(rms,0);
                     digitalWrite(lm2,LOW);
                     digitalWrite(rm2,LOW);
                     digitalWrite(lm1,HIGH);
                     digitalWrite(rm1,HIGH);
                     delay(2000);
                      analogWrite(lms,60);
                      analogWrite(rms,60);
                      digitalWrite(lm2,HIGH);
                      digitalWrite(rm2,HIGH);
                      digitalWrite(lm1,LOW);
                      digitalWrite(rm1,LOW);
                      delay(3000);} }       
                Serial.print(cylindre);                     
}
long microsecondsToCentimeters(long microseconds)
{
  // Comme expliqué auparavant nous divisons la durée par la vitesse et par 2 pour avoir la distance d’un aller simple.
  return microseconds / 29 / 2;
}

  
