#include <src/note.c>

class Notes 
{
     Note* buttons[8][8] ;

     int last_ts ;

     public: 

     Notes()/*{{{*/
     {
          this->addNote( 40, 0, 2,  7, 2); 
          this->addNote( 41, 0, 0,  7, 0); 
          this->addNote( 42, 0, 6,  7, 6); 
          this->addNote( 43, 0, 1,  7, 1); 
          this->addNote( 44, 0, 7,  7, 7); 
          this->addNote( 45, 0, 3,  7, 3); 
          this->addNote( 46, 0, 5,  7, 5); 
          this->addNote( 47, 0, 4,  7, 4); 
          this->addNote( 48, 1, 2,  4, 2); 
          this->addNote( 49, 1, 0,  4, 0); 
          this->addNote( 50, 1, 6,  4, 6); 
          this->addNote( 51, 1, 1,  4, 1); 
          this->addNote( 52, 1, 7,  4, 7); 
          this->addNote( 53, 1, 3,  4, 3); 
          this->addNote( 54, 1, 5,  4, 5); 
          this->addNote( 55, 1, 4,  4, 4); 
          this->addNote( 56, 2, 2,  6, 2); 
          this->addNote( 57, 2, 0,  6, 0); 
          this->addNote( 58, 2, 6,  6, 6); 
          this->addNote( 59, 2, 1,  6, 1); 
          this->addNote( 60, 2, 7,  6, 7); 
          this->addNote( 61, 2, 3,  6, 3); 
          this->addNote( 62, 2, 5,  6, 5); 
          this->addNote( 63, 2, 4,  6, 4); 
          this->addNote( 64, 3, 2,  5, 2); 
          this->addNote( 65, 3, 0,  5, 0); 
          this->addNote( 66, 3, 6,  5, 6); 
          this->addNote( 67, 3, 1,  5, 1); 
          this->addNote( 68, 3, 7,  5, 7); 
          this->addNote( 69, 3, 3,  5, 3); 
          this->addNote( 70, 3, 5,  5, 5); 
          this->addNote( 71, 3, 4,  5, 4);
     }/*}}}*/

     void addNote( int note, int x2, int y2, int x1, int y1 )/*{{{*/
     {
          Note* n = new Note( note + 1, x1, y1, x2, y2 ) ;
          this->buttons[ x1 ][ y1 ] = n;
          this->buttons[ x2 ][ y2 ] = n;


     }/*}}}*/

     void set( int output, int input, int bit )/*{{{*/
     {
          int current_ts = 0;
          if ( 0 < ( current_ts = this->buttons[input][output]->set( input, output, bit ) ) ) 
          {
               int diff = current_ts - this->last_ts;
               
               fprintf( stderr , "You should sleep %0.20f seconds\n", diff / 1000 ) ;
          }
     }/*}}}*/

}; 
