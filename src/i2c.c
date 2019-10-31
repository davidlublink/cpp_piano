#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>


#include <src/notes.c>
#include </usr/include/linux/i2c-dev.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

 
#define IODIR   0x00
#define IPOL    0x02
#define GPINTEN 0x04

#define DEFVAL  0x06
#define INTCON  0x08
#define IOCON   0x0A

#define GPPU    0x0C
#define INTF    0x0E
#define INTCAP  0x10
#define GPIO    0x12
#define OLAT    0x14

#define PINS    8 

#define BANK_A  0
#define BANK_B  1

class MCP23017
{
     public:
          int adapter ;
          int address ;
          int file;

          MCP23017( int adapter, int address )/*{{{*/
          {
               char filename[20];

               this->address = address ;

               snprintf(filename, 19, "/dev/i2c-%d", adapter);

               file = open(filename, O_RDWR);
               if (file < 0) {
                    throw 0x06 ;
               }

               ioctl( file, I2C_SLAVE, address );

               // in
               writeRegister( BANK_A, IODIR, 0xff );
               writeRegister( BANK_A, GPPU, 0xff) ;

               // out
               writeRegister( BANK_B, IODIR, 0x00 );
               writeRegister( BANK_B, GPPU, 0x00 );


               setbuf(stdout, NULL);
          }/*}}}*/

          bool writeRegister( int bank, int reg, int value )/*{{{*/
          {
               char buf[2];
               buf[0] = reg + bank;
               buf[1] = value ;

               return write( file, buf, 2 ) == 2;
          }/*}}}*/

          int readRegister( int bank, int reg )/*{{{*/
          {
               char buf[1];
               buf[0] = reg + bank;

               if (write(file, buf, 1) != 1) {
                    throw 0x07 ;
               }

               read( file, buf, 1 ) ;

               return (int) buf[0] ;
          }/*}}}*/

          void activateSequentialMode()
          {
               writeRegister( BANK_B, IOCON, pow(2,7) ) ;
               writeRegister( BANK_A, IOCON, pow(2,7) ) ;
          }

          int fastRead( )/*{{{*/
          {
               char buf[1];

               read( file, buf, 1 ) ;

               return (int) buf[0] ;
          }/*}}}*/

          bool fastWrite( int value )/*{{{*/
          {
               char buf[1];
               buf[0] = value ;

               return write( file, buf, 1 ) == 1;
          }/*}}}*/

          int poll()/*{{{*/
          {
               Notes* notes = new Notes ;

               int i = 10000;

               //activateSequentialMode();
               // writeRegister( BANK_B, GPIO, 255 );

               while( 1 || i-- > 0  )
               {
                    for ( int output = 0; output < PINS ; output++ )
                    {
                         //fastWrite( 255 - pow( 2, output ) );
                         writeRegister( BANK_B, OLAT, 255 - pow(2,output) ); 

                         //int raw = 255 - fastRead();
                         int raw = 255 - readRegister( BANK_A, GPIO );

                         for ( int input = 0; input < 8 ; input++ )
                         {
                              int bit = ( raw & (int) pow( 2, input ) ) != 0 ;

                              notes->set( output, input, bit );
                         }
                    }
               }

               return 0;
          }/*}}}*/

} ;

