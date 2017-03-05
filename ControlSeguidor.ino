int inA1 = 4; // input 1 of the stepper 1
int inA2 = 5; // input 2 of the stepper 1
int inB1 = 6; // input 3 of the stepper 1
int inB2 = 7; // input 4 of the stepper 1
int inC1 = 10;//10;//1; // input 1 of the stepper 2
int inC2 = 11;//11;//2; // input 2 of the stepper 2
int inD1 = 12; // input 3 of the stepper 2
int inD2 = 13; // input 4 of the stepper 2
int stepDelay1 = 5; // Delay between steps in milliseconds

//Sensores

//const int sensor1 = A0; // Extremo Derecho
//const int sensor2 = A1; // Derecho Central
//const int sensor3 = A2; // Izquierdo Central
//const int sensor4 = A3; // Izquierdo Extremo

int sensor1 = 2; // Extremo Derecho
int sensor2 = 3; // Derecho Central
int sensor3 = 8; // Izquierdo Central
int sensor4 = 9; // Izquierdo Extremo

void setup() {                
  pinMode(inC1, OUTPUT);     
  pinMode(inC2, OUTPUT);    
  pinMode(inD1, OUTPUT);     
  pinMode(inD2, OUTPUT);  
  pinMode(inA1, OUTPUT);     
  pinMode(inA2, OUTPUT);     
  pinMode(inB1, OUTPUT);     
  pinMode(inB2, OUTPUT);  

  //Sensores
  Serial.begin(9600);
  pinMode(sensor1, INPUT); //Extremo Derecho
  pinMode(sensor2, INPUT); //Derecho central
  pinMode(sensor3, INPUT); //Izquierdo Medio
  pinMode(sensor4, INPUT); // Izquierdo Extremo

}

void stepi(int a, int b, int c, int d, int a1, int b1, int c1, int d1) {
  digitalWrite(inC1, a);   
  digitalWrite(inC2, b);   
  digitalWrite(inD1, c);   
  digitalWrite(inD2, d);  
  digitalWrite(inA1, a1);   
  digitalWrite(inA2, b1);   
  digitalWrite(inB1, c1);   
  digitalWrite(inB2, d1);   
}

//ADELANTE
void adelante(int param){
int j = 0;

int matriz[][8]={ {1,1,0,0, 0,0,0,0},
                  {0,0,0,0, 1,1,0,0},
                  {0,1,1,0, 0,0,0,0},
                  {0,0,0,0, 0,1,1,0},
                  {0,0,1,1, 0,0,0,0},
                  {0,0,0,0, 0,0,1,1},
                  {1,0,0,1, 0,0,0,0},
                  {0,0,0,0, 1,0,0,1}};
while(j<param)
{                 
    for(int i=0;i<8;i=i+2)
    {
      stepi(matriz[i][0],matriz[i][1],matriz[i][2],matriz[i][3],matriz[i][4],matriz[i][5],matriz[i][6],matriz[i][7]);
      delay(3);
      stepi(matriz[i+1][0],matriz[i+1][1],matriz[i+1][2],matriz[i+1][3],matriz[i+1][4],matriz[i+1][5],matriz[i+1][6],matriz[i+1][7]);
      delay(stepDelay1); 
    }
    j++;
}
}

//ATRAS
void atras(int param)
{
int j = 0;
int matriz[][8]={     {1,0,0,1,0,0,0,0},
                      {0,0,0,0,1,0,0,1},
                      {0,0,1,1,0,0,0,0},
                      {0,0,0,0,0,0,1,1},
                      {0,1,1,0,0,0,0,0},
                      {0,0,0,0,0,1,1,0},
                      {1,1,0,0,0,0,0,0},
                      {0,0,0,0,1,1,0,0}};
while(j<param)
{
    
                      
    for(int i=0;i<8;i=i+2)
    {
      stepi(matriz[i][0],matriz[i][1],matriz[i][2],matriz[i][3],matriz[i][4],matriz[i][5],matriz[i][6],matriz[i][7]);
      delay(stepDelay1);
      stepi(matriz[i+1][0],matriz[i+1][1],matriz[i+1][2],matriz[i+1][3],matriz[i+1][4],matriz[i+1][5],matriz[i+1][6],matriz[i+1][7]);
      delay(stepDelay1); 
    //Para verificar  
//    Serial.print(matriz[i][0],BIN);Serial.print(matriz[i][1],BIN);Serial.print(matriz[i][2],BIN);Serial.print(matriz[i][3],BIN);Serial.print(matriz[i][4],BIN);Serial.print(matriz[i][5],BIN);Serial.print(matriz[i][6],BIN);Serial.print(matriz[i][7],BIN);
//    Serial.println();
//    Serial.print(matriz[i+1][0],BIN);Serial.print(matriz[i+1][1],BIN);Serial.print(matriz[i+1][2],BIN);Serial.print(matriz[i+1][3],BIN);Serial.print(matriz[i+1][4],BIN);Serial.print(matriz[i+1][5],BIN);Serial.print(matriz[i+1][6],BIN);Serial.print(matriz[i+1][7],BIN);
//    Serial.println();
      j++;
    }
}
}

//Izquierda
void izquierda(int param){
int j=0;

int matriz[][8]={ {1,1,0,0, 0,0,0,0},
                  {0,0,0,0, 1,0,0,1},
                  {0,1,1,0, 0,0,0,0},
                  {0,0,0,0, 0,0,1,1},
                  {0,0,1,1, 0,0,0,0},
                  {0,0,0,0, 0,1,1,0},
                  {1,0,0,1, 0,0,0,0},
                  {0,0,0,0, 1,1,0,0}};

while(j<param)
{                      
    for(int i=0;i<8;i=i+2)
    {
      stepi(matriz[i][0],matriz[i][1],matriz[i][2],matriz[i][3],matriz[i][4],matriz[i][5],matriz[i][6],matriz[i][7]);
      delay(stepDelay1);
      stepi(matriz[i+1][0],matriz[i+1][1],matriz[i+1][2],matriz[i+1][3],matriz[i+1][4],matriz[i+1][5],matriz[i+1][6],matriz[i+1][7]);
      delay(stepDelay1); 
      j++;
    }
}
}

//Derecha
void derecha(int param){
int j=0;

                      
int matriz[][8]={ {1,0,0,1, 0,0,0,0},
                  {0,0,0,0, 1,1,0,0},
                  {0,0,1,1, 0,0,0,0},
                  {0,0,0,0, 0,1,1,0},
                  {0,1,1,0, 0,0,0,0},
                  {0,0,0,0, 0,0,1,1},
                  {1,1,0,0, 0,0,0,0},
                  {0,0,0,0, 1,0,0,1}};
while(j<param)
{                      
    for(int i=0;i<8;i=i+2)
    {
      stepi(matriz[i][0],matriz[i][1],matriz[i][2],matriz[i][3],matriz[i][4],matriz[i][5],matriz[i][6],matriz[i][7]);
      delay(stepDelay1);
      stepi(matriz[i+1][0],matriz[i+1][1],matriz[i+1][2],matriz[i+1][3],matriz[i+1][4],matriz[i+1][5],matriz[i+1][6],matriz[i+1][7]);
      delay(stepDelay1); 
      j++;
    }
}
}
// the loop routine runs over and over again forever:

void loop() {

int s_s1;
int s_s2;
int s_s3;
int s_s4;

s_s1 = digitalRead(sensor1);
s_s2 = digitalRead(sensor2);
s_s3 = digitalRead(sensor3);
s_s4 = digitalRead(sensor4);


if ((!s_s1 && s_s2 &&s_s3&&!s_s4 )){
    adelante(1);
}

if ((!s_s1 && s_s2 &&!s_s3&&!s_s4 )){
    adelante(10);
    izquierda(1);
}

if ((!s_s1 &&!s_s2 &&s_s3&&!s_s4 )){
  adelante(10);
    derecha(1);
}

if ((s_s1 && s_s2 &&!s_s3&&!s_s4 )){
    izquierda(1);
}
if ((s_s1 && !s_s2 &&!s_s3&&!s_s4 )){
    izquierda(1);
}

if ((!s_s1 && !s_s2 &&s_s3&&s_s4 )){
    derecha(1);
}
if ((!s_s1 && !s_s2 &&!s_s3&&s_s4 )){
    derecha(1);
}
if ((!s_s1 && !s_s2 &&!s_s3&&!s_s4 )){
    atras(1);
}
}
