const int buzzer = 8;
const int toneTable[7][5]={  
  { 66, 131, 262, 523, 1046},  // C Do
  { 74, 147, 294, 587, 1175},  // D Re
  { 83, 165, 330, 659, 1318},  // E Mi
  { 88, 175, 349, 698, 1397},  // F Fa
  { 98, 196, 392, 784, 1568},  // G So
  {110, 220, 440, 880, 1760},  // A La
  {124, 247, 494, 988, 1976}   // B Si
};
char toneName[]="CDEFGAB";
char beeTone[]="CDEGFEDCEGACDEBCGACDEAGEDCEGACDEBCGA";
//char starTone[]="CCGGAAGFFEEDDCGGFFEEDGGFFEEDCCGGAAGFFEEDDC";
 
int beeBeat[]={
   1,1,2,2,2,2,2,2,4,
  1,1,2,2,2,2,2,2,4,
  1,1,2,2,2,2,2,2,4,
  1,1,2,2,2,2,2,2,4,

};

int getTone(char symbol) {
  int toneNo = 0;
  for ( int ii=0; ii<7; ii++ ) {
      if ( toneName[ii]==symbol ) {
          toneNo = ii;
          break;
      }
  }
  return toneNo;
}
void setup() {
  pinMode(buzzer,OUTPUT);
  noTone(buzzer);
}
 
void loop() {
  int ii, length, toneNo;
  int duration;
   
    // bee
  length = sizeof(beeTone)-1;
  for ( ii=0; ii<length; ii++ ) {
      toneNo = getTone(beeTone[ii]);
      duration = beeBeat[ii]*333;
      tone(buzzer,toneTable[toneNo][3]);
      delay(duration);
      noTone(buzzer);
  }
  delay(2000);
}

