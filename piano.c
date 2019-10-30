#include <src/i2c.c>

class Test
{
     public :
          int i ;
} ;


int main() {

     MCP23017* piano = new MCP23017( 1, 0x20 );

     //printf("reverb on\n");
     printf("gain 4\n");
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
