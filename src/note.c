#include <sys/time.h>

#define INVALID_VALUE 0x01

#define TIME_UNIT 1000

#define usec 1000000

#define max(a,b) \
     ({ __typeof__ (a) _a = (a); \
      __typeof__ (b) _b = (b); \
      _a > _b ? _a : _b; })

class Note 
{
     private :
          int start[3] ;
          int end[3] ;

          int value[2]; 

          long int timer ;

          int key ;

          int first ;

     public:

          Note( int key, int start_x, int start_y, int end_x, int end_y  )/*{{{*/
          {
               this->first = 0;

               this->start[0] = start_x ;
               this->start[1] = start_y ;

               this->end[0] = end_x;
               this->end[1] = end_y;


               this->key = key ;

          }/*}}}*/

          long getTime()/*{{{*/
          {
               struct timeval currentTime;
               int f = 1 ; 

               gettimeofday(&currentTime, NULL);

               int time = currentTime.tv_sec ;

               int microtime =currentTime.tv_usec ;

               time = ( time % 1000 ) * 10e5;

               time = time + microtime;

               return time; 
          }/*}}}*/

          int set( int x, int y, int value )/*{{{*/
          {
               if ( x == this->start[0] && y == this->start[1] )
                    return this->setUpper( value ) ;
               else if ( x == this->end[0] && y == this->end[1] )
                    return this->setLower( value );
               else
                    throw 0x03;
          }/*}}}*/

      private:

          int setUpper( int bit )/*{{{*/
          {
               if ( this->value[0] != bit )
               {
                    this->value[0] = bit ;

                    if ( bit ) 
                    {
                         this->timer = this->getTime() ;
                    }
                    else
                    {
                         this->timer = 0;
                    }
                    return this->timer ;
               }
               return 0 ;
          }/*}}}*/

          int setLower( int bit )/*{{{*/
          {
               if ( this->value[1] != bit )
               {
                    int end   = this->getTime();

                    this->value[1] = bit ;

                    if ( bit )
                    {
                         int force ;

                         if ( this->timer == 0 )
                         {
                              // debounce

                              return 0;
                         }
                         else
                         {
                              int start = this->timer;

                              int diff = this->getTime() - this->timer; 

                              // Add 5, determined from human testing
                              force = 127 - round ( diff / TIME_UNIT ) + 5 ;
                         }
                         printf( "noteon 1 %i %i\n", this->key, force );
                    }
                    else
                    {
                         printf( "noteoff 1 %i \n", this->key ) ;
                    }


                    this->timer = 0;
                    return end ;
               }

               return 0;
          }/*}}}*/



}; 
