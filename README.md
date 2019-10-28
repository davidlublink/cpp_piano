# A simple user-space driver for piano

Introduction

This project aims to replace the OEM computer inside of a Roland 230 electronic piano with a general purpose computer to interpret signals from the keyboard and synthesize the appropriate sounds. I tried to write this in php, but it didn't work out because of the lack of read, write and ioctl. I put aside the PHP project and decided to write the adapter in C++ ( I wanted objects ).


How to use it :

not sure, but here is my setup  :

1. Raspberry Pi ( 2011 ) *
2. Friend's bread board
3. MCP23017 chip
4. 32 jumper wires **
5. LED and resistor
6. Roland 230 Electronic Piano
7. FluidSynth ( sudo apt-get install fluidsynth )
8. nc  ( apt-get install nc )


What I did : 

I wired the MCP23017 to the matrix and mapped the inputs / outputs to notes. 

All the outputs are on bank B and all the inputs on bank A.

The matrix conversion table is in notes.c coded directly in C.

In one terminal I run fluid synth : 

     fluidsynth -a alsa -s

In the second terminal I run piano :
     
     ./piano | nc 127.0.0.1 9800

With this running, you can here the piano from the synthesizer.     


Known issues
 * Code is not documented
 * Sounds like keyboard is being pounded
 * Only has 32 notes out of 88
 * The code was written for my specific setup


 === State of development ===



