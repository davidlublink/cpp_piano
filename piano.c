#include <src/i2c.c>
#include <src/note.c>



int main() {

     MCP23017* piano = new MCP23017( 1, 0x20 );

//     piano->load('keyboard.map');

     piano->poll();

}
