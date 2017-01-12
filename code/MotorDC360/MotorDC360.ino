/*  ----------------------------------------------------------------
    Proyecto: RadArduino
    
    Movimiento 360º motor paso 28BYJ-48 arduino.
    
--------------------------------------------------------------------  
*/
#define IN1  12
#define IN2  11
#define IN3  10
#define IN4  9

int steps_left=4095;
int Steps = 0;

int Paso [ 8 ][ 4 ] =
      {   {1, 0, 0, 0},
          {1, 1, 0, 0},
          {0, 1, 0, 0},
          {0, 1, 1, 0},
          {0, 0, 1, 0},
          {0, 0, 1, 1},
          {0, 0, 0, 1},
          {1, 0, 0, 1}
       };

void setup()
{
    Serial.begin(115200);
    pinMode(IN1, OUTPUT); 
    pinMode(IN2, OUTPUT); 
    pinMode(IN3, OUTPUT); 
    pinMode(IN4, OUTPUT); 
}

void loop() 
{     
  while(steps_left>0)
  {
      Serial.println(steps_left);
      stepper() ;    // Avanza un paso
      steps_left-- ;  // Un paso menos
      delay (2) ;
   }
   steps_left=4095;
}

void stepper()      //Avanza un paso
{
  digitalWrite( IN1, Paso[Steps][0] );
  digitalWrite( IN2, Paso[Steps][1] );
  digitalWrite( IN3, Paso[Steps][2] );
  digitalWrite( IN4, Paso[Steps][3] );
  
  Steps++;
  if(Steps > 7)
  {
     Steps = 0; 
   }
}

void switchDir()
{
    
  
}

