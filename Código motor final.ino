
int inA1 = 4; // input 1 of the stepper 1
int inA2 = 5; // input 2 of the stepper 1
int inB1 = 6; // input 3 of the stepper 1
int inB2 = 7; // input 4 of the stepper 1
int inC1 = 10;//10;//1; // input 1 of the stepper 2
int inC2 = 11;//11;//2; // input 2 of the stepper 2
int inD1 = 12; // input 3 of the stepper 2
int inD2 = 13; // input 4 of the stepper 2
int stepDelay1 = 5; // Delay between steps in milliseconds



void setup() {                
  pinMode(inC1, OUTPUT);     
  pinMode(inC2, OUTPUT);    
  pinMode(inD1, OUTPUT);     
  pinMode(inD2, OUTPUT);  
  pinMode(inA1, OUTPUT);     
  pinMode(inA2, OUTPUT);     
  pinMode(inB1, OUTPUT);     
  pinMode(inB2, OUTPUT);  

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
      delay(stepDelay1);
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

//Derecha
void derecha(int param){
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

void izquierda(int param){
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

Serial.begin(9600);

adelante(100);
delay(1000);
atras(100);
delay(1000);
derecha(1000);
delay(1000);
izquierda(2000);
delay(1000);

}




