/*  ----------------------------------------------------------------
    http://www.prometec.net/motor-28byj-48                                        Prog_4_2
    
    Moviendo un motor paso a paso 28BYJ-48 con Arduino
--------------------------------------------------------------------  
*/
#define IN1  12
#define IN2  11
#define IN3  10
#define IN4  9

int steps_left=4095;
boolean Direction = true;
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
{     while(steps_left>0)
         {
           Serial.println(steps_left);
           stepper() ;    // Avanza un paso
           steps_left-- ;  // Un paso menos
           delay (1) ;
         }
      delay(300);
      Direction=!Direction;
      steps_left=4095;
}

void stepper()            //Avanza un paso
{
  digitalWrite( IN1, Paso[Steps][ 0] );
  digitalWrite( IN2, Paso[Steps][ 1] );
  digitalWrite( IN3, Paso[Steps][ 2] );
  digitalWrite( IN4, Paso[Steps][ 3] );
  
  SetDirection();
}

void SetDirection()
{
    if(Direction)
        Steps++;
    else 
        Steps--; 
     
    Steps = ( Steps + 7 ) % 7 ;
}
