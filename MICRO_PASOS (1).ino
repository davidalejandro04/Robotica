
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
void adelante(int par){
  
int i = 0;
while(i <  par){
    stepi(1,1,0,0,0,0,0,0); 
    delay(1);
    stepi(0,0,0,0,1,1,0,0); 
    delay(stepDelay1);
    
    stepi(0,1,1,0,0,0,0,0); 
    delay(1);
    stepi(0,0,0,0,0,1,1,0); 
    delay(stepDelay1);
    
    stepi(0,0,1,1,0,0,0,0);
    delay(1);
    stepi(0,0,0,0,0,0,1,1); 
    delay(stepDelay1);
    
    stepi(1,0,0,1,0,0,0,0);
    delay(1);
    stepi(0,0,0,0,1,0,0,1); 
    delay(stepDelay1);

    i++;
}
}

//ATRAS
void atras(int par){
  
int i = 0;

while(i<par ){
 
    
     stepi(1,0,0,1,0,0,0,0);
    delay(1);
    stepi(0,0,0,0,1,0,0,1); 
    delay(stepDelay1);
    
    stepi(0,0,1,1,0,0,0,0);
    delay(1);
    stepi(0,0,0,0,0,0,1,1); 
    delay(stepDelay1);

     stepi(0,1,1,0,0,0,0,0); 
    delay(1);
    stepi(0,0,0,0,0,1,1,0); 
    delay(stepDelay1);

    stepi(1,1,0,0,0,0,0,0); 
    delay(1);
    stepi(0,0,0,0,1,1,0,0); 
    delay(stepDelay1);
    
    i++;
    
    
}
}

//Derecha
void derecha(int par){
  
int i = 0;

while(i<par ){
 
  
    stepi(0,0,0,0,1,1,0,0); 
    delay(stepDelay1);
   
    stepi(0,0,0,0,0,1,1,0); 
    delay(stepDelay1);

    stepi(0,0,0,0,0,0,1,1); 
    delay(stepDelay1);

    
    stepi(0,0,0,0,1,0,0,1); 
    delay(stepDelay1);
    
        
    i++;
    
    
}
}

void izquierda(int par){

int i = 0;

while(i<par ){
 
     stepi(1,0,0,1,0,0,0,0); 
    delay(stepDelay1);
    stepi(0,0,1,1,0,0,0,0); 
    delay(stepDelay1);
    stepi(0,1,1,0,0,0,0,0);
    delay(stepDelay1);
    stepi(1,1,0,0,0,0,0,0); 
     delay(stepDelay1);
        
    i++;
    
    
}
}
// the loop routine runs over and over again forever:

void loop() {

//ADELANTE
//
//adelante(100);
//
//delay(1000);
//////ATRAS
//
//atras(100);
//delay(1000);

//DERECHA
derecha(100);
delay(1000);

izquierda(100);
delay(1000);
}




