#include <src/note.c>

class Notes 
{
     Note* buttons[8][8] ;

     public: 

     Notes()/*{{{*/
     {
          this->buttons[4][0] = this->buttons[1][0] =  new Note ( 49, 0, 1, 0, 4 ); 
          this->buttons[4][1] = this->buttons[1][1] =  new Note ( 51, 1, 1, 1, 4 ); 
          this->buttons[4][2] = this->buttons[1][2] =  new Note ( 48, 2, 1, 2, 4 ); 
          this->buttons[4][3] = this->buttons[1][3] =  new Note ( 53, 3, 1, 3, 4 ); 
          this->buttons[4][4] = this->buttons[1][4] =  new Note ( 55, 4, 1, 4, 4 ); 
          this->buttons[4][5] = this->buttons[1][5] =  new Note ( 54, 5, 1, 5, 4 ); 
          this->buttons[4][6] = this->buttons[1][6] =  new Note ( 50, 6, 1, 6, 4 ); 
          this->buttons[4][7] = this->buttons[1][7] =  new Note ( 52, 7, 1, 7, 4 ); 
          this->buttons[5][0] = this->buttons[3][0] =  new Note ( 65, 0, 3, 0, 5 ); 
          this->buttons[5][1] = this->buttons[3][1] =  new Note ( 67, 1, 3, 1, 5 ); 
          this->buttons[5][2] = this->buttons[3][2] =  new Note ( 64, 2, 3, 2, 5 ); 
          this->buttons[5][3] = this->buttons[3][3] =  new Note ( 69, 3, 3, 3, 5 ); 
          this->buttons[5][4] = this->buttons[3][4] =  new Note ( 71, 4, 3, 4, 5 );
          this->buttons[5][5] = this->buttons[3][5] =  new Note ( 70, 5, 3, 5, 5 ); 
          this->buttons[5][6] = this->buttons[3][6] =  new Note ( 66, 6, 3, 6, 5 ); 
          this->buttons[5][7] = this->buttons[3][7] =  new Note ( 68, 7, 3, 7, 5 ); 
          this->buttons[6][0] = this->buttons[2][0] =  new Note ( 57, 0, 2, 0, 6 ); 
          this->buttons[6][1] = this->buttons[2][1] =  new Note ( 59, 1, 2, 1, 6 ); 
          this->buttons[6][2] = this->buttons[2][2] =  new Note ( 56, 2, 2, 2, 6 ); 
          this->buttons[6][3] = this->buttons[2][3] =  new Note ( 61, 3, 2, 3, 6 ); 
          this->buttons[6][4] = this->buttons[2][4] =  new Note ( 63, 4, 2, 4, 6 ); 
          this->buttons[6][5] = this->buttons[2][5] =  new Note ( 62, 5, 2, 5, 6 ); 
          this->buttons[6][6] = this->buttons[2][6] =  new Note ( 58, 6, 2, 6, 6 ); 
          this->buttons[6][7] = this->buttons[2][7] =  new Note ( 60, 7, 2, 7, 6 ); 
          this->buttons[7][0] = this->buttons[0][0] =  new Note ( 41, 0, 0, 0, 7 ); 
          this->buttons[7][1] = this->buttons[0][1] =  new Note ( 43, 1, 0, 1, 7 ); 
          this->buttons[7][2] = this->buttons[0][2] =  new Note ( 40, 2, 0, 2, 7 ); 
          this->buttons[7][3] = this->buttons[0][3] =  new Note ( 45, 3, 0, 3, 7 ); 
          this->buttons[7][4] = this->buttons[0][4] =  new Note ( 47, 4, 0, 4, 7 ); 
          this->buttons[7][5] = this->buttons[0][5] =  new Note ( 46, 5, 0, 5, 7 ); 
          this->buttons[7][6] = this->buttons[0][6] =  new Note ( 42, 6, 0, 6, 7 ); 
          this->buttons[7][7] = this->buttons[0][7] =  new Note ( 44, 7, 0, 7, 7 ); 
     }/*}}}*/

     void set( int output, int input, int bit )/*{{{*/
     {
          this->buttons[input][output]->set( output, input, bit );
     }/*}}}*/

}; 
