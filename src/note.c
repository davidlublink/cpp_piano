#include <sys/time.h>

#define INVALID_VALUE 0x01

#define usec 1000000

#define max(a,b) \
     ({ __typeof__ (a) _a = (a); \
      __typeof__ (b) _b = (b); \
      _a > _b ? _a : _b; })

class Note 
{
     private :
          int upper[2] ;
          int lower[2] ;

          int value[2]; 

          long int timer ;

          int key ;

     public:

          Note( int key, int upper_out, int upper_in, int lower_out, int lower_in  )/*{{{*/
          {
               this->upper[0] = upper_out ;
               this->upper[1] = upper_in ;
               this->lower[0] = lower_out ;
               this->lower[1] = lower_in ;

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

          void set( int output, int input, int bit )/*{{{*/
          {
               if ( output == this->upper[0] && input == this->upper[1] )
                    return this->setUpper( bit ) ;
               else if ( output == this->lower[0] && input == this->lower[1] )
                    return this->setLower( bit );
               else
                    throw 0x03;
          }/*}}}*/

      private:

          void setUpper( int bit )/*{{{*/
          {
               if ( this->value[0] != bit )
               {
                    this->value[0] = bit ;

                    this->timer = this->getTime() ;
               }
          }/*}}}*/

          void setLower( int bit )/*{{{*/
          {
               if ( this->value[1] != bit )
               {
                    this->value[1] = bit ;

                    if ( bit )
                    {
                         int force ;
                         if ( this->timer == 0 )
                         {
                              force = 0;
                         }
                         else
                         {
                              float start = this->timer;
                              float end   = this->getTime();

                              float diff = this->getTime() - this->timer; 

                              force = max( 0, 127 - diff / 10e6 * 700 ) ;

                         }
                         printf( "noteon 1 %i %i\n", this->key, force );
                    }
                    else
                         printf( "noteoff 1 %i \n", this->key ) ;


               }
          }/*}}}*/



}; 
