#include <sys/time.h>

#define INVALID_VALUE 0x01

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

          long getMicrotime()
          {
               struct timeval currentTime;
               gettimeofday(&currentTime, NULL);
               return currentTime.tv_sec * (int) 1e6 + currentTime.tv_usec;
          }

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

                    this->timer = this->getMicrotime();
               }
          }/*}}}*/

          void setLower( int bit )/*{{{*/
          {
               if ( this->value[1] != bit )
               {
                    this->value[1] = bit ;

                    if ( bit )
                         printf( "noteon 1 %i %i\n", this->key, 100 );
                    else
                         printf( "noteoff 1 %i \n", this->key ) ;


                    long ts = this->getMicrotime() - this->timer ;

                    // printf( "Took %i to press the key\n", this->timer ) ;

               }
          }/*}}}*/



}; 
