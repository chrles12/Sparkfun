/*
SparkFun Inventor’s Kit
Circuit 2A - Buzzer

Play notes using a buzzer connected to pin 10

This sketch was written by SparkFun Electronics, with lots of help from the Arduino community, modified by Charles Glass.
This code is completely free for any use.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

#include "pitches.h"



int speakerPin = 10;               //the pin that the buzzer is connected to
int led[] = {3,5,7,9};            //led array
int beatLength = 0;
int lights = 0;

void setup()
{
  pinMode(speakerPin, OUTPUT);    //set the output pin for the speaker
  //set all of the blue LED pins to output
  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  pinMode(led[2], OUTPUT);
  pinMode(led[3], OUTPUT);

  pinMode(6, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
}

void loop()
{
  /*  
  play('g', 2);       //ha
  play('g', 1);       //ppy
  play('a', 4);       //birth
  play('g', 4);       //day
  play('C', 4);       //to
  play('b', 4);       //you
  
  play(' ', 2);       //pause for 2 beats
  
  play('g', 2);       //ha     
  play('g', 1);       //ppy
  play('a', 4);       //birth
  play('g', 4);       //day
  play('D', 4);       //to
  play('C', 4);       //you

  play(' ', 2);   */
  
  if(digitalRead(2) == LOW){        //if the first key is pressed
     hurt();        
  }
  else if(digitalRead(6) == LOW){  //if the second key is pressed
     blue();                    
  }
  else{
    noTone(speakerPin);                        //if no key is pressed turn the buzzer off
  }      
}

void playFrequency(int frequency, int beats){ //refer to chart for frequency. beats is num beats to play frequency for
  
  tone(speakerPin, frequency, beats * beatLength);   
  delay(beats* beatLength);   //wait for the length of the tone so that it has time to play
  delay(50);                  //a little delay between the notes makes the song sound more natural

}

void play(char note, int beats)
{
  int numNotes = 16;  // number of notes in our note and frequency array (17 values each)
  
  //Note: these notes are C major (there are no sharps or flats - modified to include 2 flats: x->A# in C major, X->D# one octave up)

  //this array is used to look up the notes
  char notes[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'x', 'b', 'C', 'D', 'X', 'E', 'F', 'G', 'A', 'B', 'Z', ' '};
  //this array matches frequencies with each letter (e.g. the 4th note is 'f', the 4th frequency is 175)
  int frequencies[] = {131, 147, 165, 175, 196, 220, 234, 247, 262, 294, 312, 330, 349, 392, 440, 494, 0};
  
  int currentFrequency = 0;    //the frequency that we find when we look up a frequency in the arrays

  //look up the frequency that corresponds to the note
  for (int i = 0; i < numNotes; i++)  // check each value in notes from 0 to 16
  {
    if (notes[i] == note)             // does the letter passed to the play function match the letter in the array?
    {
      currentFrequency = frequencies[i];   // Yes! Set the current frequency to match that note
    }
    if(lights==0){
    digitalWrite(led[random(0,4)], HIGH);//pick a random led to light up after finding a note
    digitalWrite(led[random(0,4)], LOW);//pick a random led to turn off after finding a note
    }
    else if(lights==1){
      
    }
  }

  //play the frequency that matched our letter for the number of beats passed to the play function
  tone(speakerPin, currentFrequency, beats * beatLength);   
  delay(beats* beatLength);   //wait for the length of the tone so that it has time to play
  delay(50);                  //a little delay between the notes makes the song sound more natural

}

void hurt(){
  beatLength = 350;
  lights = 2;
  playFrequency(110, 1);
  playFrequency(165, 1);
  playFrequency(220, 2);
  playFrequency(0, 3);
  playFrequency(131, 1);
  playFrequency(196, 1);
  playFrequency(262, 1);
  playFrequency(0, 1);
  playFrequency(147, 1);
  playFrequency(220, 1);
  playFrequency(294, 1);
  playFrequency(0, 1);
  playFrequency(110, 1);
  playFrequency(165, 1);
  playFrequency(220, 2);
  playFrequency(0, 3);
  playFrequency(131, 1);
  playFrequency(196, 1);
  playFrequency(262, 1);
  playFrequency(0, 1);
  playFrequency(147, 1);
  playFrequency(220, 1);
  playFrequency(294, 1);
  playFrequency(0, 1);
  playFrequency(110, 1);
  playFrequency(165, 1);
  playFrequency(220, 2);
  playFrequency(0, 2);
  playFrequency(659, 1);
  playFrequency(0, 1);
  playFrequency(784, 1);
  playFrequency(659, 1);
  playFrequency(262, 1);
  playFrequency(587, 1);
  playFrequency(147, 1);
  playFrequency(220, 1);
  playFrequency(294, 1);
  playFrequency(523, 1);
  playFrequency(659, 1);
  playFrequency(165, 1);
  playFrequency(220, 1);
  }

void blue(){
  
  beatLength = 200;
  lights = 0;
  play('a', 2);       //im  
  play('x', 1);       //blue
  play('d', 1);       //da
  play('g', 1);       //ba
  play('x', 1);       //dee
  play('C', 1);       
  play('f', 1);       //da
  play('a', 1);       //ba
  play('x', 1);       //di
  
  play(' ', 1);
       
  play('g', 1);       //da
  play('x', 1);       //ba
  play('D', 1);       //dee
  play('X', 1);       //da
  play('g', 1);       //ba
  play('D', 1);       //di
  play('C', 1);       //da
  play('x', 1);       //ba
  play('d', 1);       //dee
  play('g', 1);       //da
  play('x', 1);       //ba
  play('C', 1);       
  play('f', 1);       //di. end of bar 2
  
  play('a', 1);       
  play('x', 1);       
  play(' ', 1);       
  play('g', 1);       
  play('x', 1);       
  play('D', 1);       
  play('X', 1);       
  play('g', 1);       
  play('D', 1);       
  play('C', 1);       
  play('x', 1);       
  play('d', 1);       
  play('g', 1);       
  
  play('x', 1);       
  play('a', 1);       
  play('c', 1);       
  play('f', 1);       
  play('g', 1);       
  play(' ', 1);       
  play('g', 1);       
  play(' ', 1);       
  play('g', 1);       
  play(' ', 1);       
  play('g', 1);       

  //turn pins off
  digitalWrite(led[0], LOW);
  digitalWrite(led[1], LOW);
  digitalWrite(led[2], LOW);
  digitalWrite(led[3], LOW);
  digitalWrite(led[4], LOW);

}

void ratherbe(){
  beatLength=100;
  playFrequency(523, 1);
  playFrequency(659, 1);
  playFrequency(880, 1);
  playFrequency(1047, 1);
  playFrequency(0, 2);
  playFrequency(1175, 1);
  playFrequency(0, 1);
  playFrequency(988, 2);
  playFrequency(0, 4);
  playFrequency(440, 1);
  playFrequency(523, 1);
  playFrequency(784, 1);
  playFrequency(880, 1);
  playFrequency(0, 2);
  playFrequency(784, 1);
  playFrequency(0, 1);
  playFrequency(659, 1);
  playFrequency(0, 2);
  playFrequency(784, 2);
  playFrequency(523, 2);
  playFrequency(659, 1);
  playFrequency(880, 1);
  playFrequency(1047, 1);
  playFrequency(0, 2);
  playFrequency(1175, 1);
  playFrequency(0, 1);
  playFrequency(988, 2);
  playFrequency(0, 2);
  playFrequency(784, 1);
  playFrequency(659, 1);
  playFrequency(523, 1);
  playFrequency(440, 1);
  playFrequency(523, 1);
  playFrequency(784, 1);
  playFrequency(880, 1);
  playFrequency(0, 2);
  playFrequency(784, 1);
  playFrequency(0, 1);
  playFrequency(659, 2);
  playFrequency(0, 2);
  playFrequency(784, 2);
  }

  void shrek(){
  beatLength = 125;
  playFrequency(466, 1);
  playFrequency(0, 1);
  playFrequency(370, 1);
  playFrequency(0, 3);
  playFrequency(370, 1);
  playFrequency(349, 1);
  playFrequency(370, 1);
  playFrequency(0, 1);
  playFrequency(370, 1);
  playFrequency(0, 3);
  playFrequency(370, 1);
  playFrequency(349, 1);
  playFrequency(370, 1);
  playFrequency(0, 1);
  playFrequency(370, 1);
  playFrequency(0, 3);
  playFrequency(370, 1);
  playFrequency(0, 3);
  playFrequency(466, 1);
  playFrequency(0, 5);
  playFrequency(466, 1);
  playFrequency(0, 1);
  playFrequency(370, 1);
  playFrequency(0, 3);
  playFrequency(370, 1);
  playFrequency(349, 1);
  playFrequency(370, 1);
  playFrequency(0, 1);
  playFrequency(370, 1);
  playFrequency(0, 3);
  playFrequency(370, 1);
  playFrequency(349, 1);
  playFrequency(370, 1);
  playFrequency(0, 1);
  playFrequency(370, 1);
  playFrequency(0, 3);
  playFrequency(370, 1);
  playFrequency(0, 3);
  playFrequency(466, 1);
  playFrequency(0, 5);
  playFrequency(233, 1);
  playFrequency(0, 3);
  playFrequency(277, 1);
  playFrequency(0, 3);
  playFrequency(247, 1);
  playFrequency(0, 1);
  playFrequency(208, 1);
  playFrequency(0, 1);
  playFrequency(185, 1);
  playFrequency(0, 1);
  playFrequency(370, 2);
  playFrequency(0, 5);
  playFrequency(185, 1);
  playFrequency(0, 1);
  playFrequency(185, 1);
  playFrequency(0, 1);
  playFrequency(208, 1);
  playFrequency(0, 1);
  playFrequency(185, 1);
  playFrequency(0, 1);
  playFrequency(277, 1);
  playFrequency(0, 1);
  playFrequency(233, 1);
  playFrequency(0, 5);
  playFrequency(208, 1);
  playFrequency(0, 1);
  playFrequency(185, 1);
  playFrequency(0, 3);
  playFrequency(208, 1);
  playFrequency(0, 1);
  playFrequency(233, 1);
  playFrequency(0, 1);
  playFrequency(156, 2);

  }

  void tiktok(){
    play('G', 2);       //Don't
  play('F', 1);       //stop
  play(' ', 1);
  play('F', 1);       //make
  play('F', 1);       //it
  play('F', 1);       //pop
  
  play(' ', 1);       //pause for a beat
  
  play('F', 1);       //d     
  play('F', 1);       //j
  play('F', 1);       //blow
  play('F', 1);       //my
  play('F', 1);       //speak
  play('F', 1);       //ers
  play('F', 1);       //up

  play(' ', 1);       //pause for a beata

  play('G', 2);       //To
  play('F', 1);       //night
  play(' ', 1);
  play('F', 1);       //im
  play('F', 1);       //ma
  play('F', 1);       //fight
  
  play(' ', 1);       //pause for a beat
  
  play('F', 1);       //till     
  play('F', 1);       //we
  play('F', 1);       //see
  play('F', 1);       //the
  play('E', 2);       //sun
  play('D', 1);       //light
  }
  
/* 
SIMPLE CHART OF FREQUENCIES FOR NOTES IN C MAJOR
Note      Frequency (Hz)
c        131
d        147
e        165
f        175
g        196
a        220
x (A#)   234
b        247
C        262
D        294
X (D#)   312
E        330
F        349
G        392
A        440
B        494

FULL SCALE

NOTE_B0  31
NOTE_C1  33
NOTE_CS1 35
NOTE_D1  37
NOTE_DS1 39
NOTE_E1  41
NOTE_F1  44
NOTE_FS1 46
NOTE_G1  49
NOTE_GS1 52
NOTE_A1  55
NOTE_AS1 58
NOTE_B1  62
NOTE_C2  65
NOTE_CS2 69
NOTE_D2  73
NOTE_DS2 78
NOTE_E2  82
NOTE_F2  87
NOTE_FS2 93
NOTE_G2  98
NOTE_GS2 104
NOTE_A2  110
NOTE_AS2 117
NOTE_B2  123
NOTE_C3  131
NOTE_CS3 139
NOTE_D3  147
NOTE_DS3 156
NOTE_E3  165
NOTE_F3  175
NOTE_FS3 185
NOTE_G3  196
NOTE_GS3 208
NOTE_A3  220
NOTE_AS3 233
NOTE_B3  247
NOTE_C4  262
NOTE_CS4 277
NOTE_D4  294
NOTE_DS4 311
NOTE_E4  330
NOTE_F4  349
NOTE_FS4 370
NOTE_G4  392
NOTE_GS4 415
NOTE_A4  440
NOTE_AS4 466
NOTE_B4  494
NOTE_C5  523
NOTE_CS5 554
NOTE_D5  587
NOTE_DS5 622
NOTE_E5  659
NOTE_F5  698
NOTE_FS5 740
NOTE_G5  784
NOTE_GS5 831
NOTE_A5  880
NOTE_AS5 932
NOTE_B5  988
NOTE_C6  1047
NOTE_CS6 1109
NOTE_D6  1175
NOTE_DS6 1245
NOTE_E6  1319
NOTE_F6  1397
NOTE_FS6 1480
NOTE_G6  1568
NOTE_GS6 1661
NOTE_A6  1760
NOTE_AS6 1865
NOTE_B6  1976
NOTE_C7  2093
NOTE_CS7 2217
NOTE_D7  2349
NOTE_DS7 2489
NOTE_E7  2637
NOTE_F7  2794
NOTE_FS7 2960
NOTE_G7  3136
NOTE_GS7 3322
NOTE_A7  3520
NOTE_AS7 3729
NOTE_B7  3951
NOTE_C8  4186
NOTE_CS8 4435
NOTE_D8  4699
NOTE_DS8 4978

*/
