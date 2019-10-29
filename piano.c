#include <src/i2c.c>

class Test
{
     public :
          int i ;
} ;


int main() {


     Test* test = new Test; 
     Test copy ;

     copy = &test ;

     test->i = 5;

     printf(" Copy : %i Test : %i \n", copy->i, test->i );





     return 1;
     MCP23017* piano = new MCP23017( 1, 0x20 );

//     piano->load('keyboard.map');

     try
     {
          piano->poll();
     }
     catch( int e  )
     {
          printf("Failure : %i\n", e );

     }

}
