/*
SparkFun Inventor’s Kit
Modified Circuit 1D-RGB Nightlight

Turns an RGB LED on or off based on the light level read by a photoresistor.
Once on, the LED pulses roughly through the colors of the rainbow

This sketch was written by SparkFun Electronics, with lots of help from the Arduino community, modified by Charles Glass.
This code is completely free for any use.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
 */

int photoresistor = A0;          //variable for storing the photoresistor value

//LEDs are connected to these pins
int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;

//values that are changed incrementally to give pulsating effect
int redvalue=0;
int greenvalue=0;
int bluevalue=0;

//flags that signify whether values should be incremented or decremented (1 for getting brighter, 0 for fading down)
int redflag=1;
int greenflag=1;
int blueflag=1;

//counters that time-out each color after they go through one pulse
int redcounter=0;
int orangecounter=0;
int yellowcounter=0;
int greencounter=0;
int cyancounter=0;
int bluecounter=0;
int magentacounter=0;
int pinkcounter=0;

void setup() {
  Serial.begin(9600);           //start a serial connection with the computer

  //set the LED pins to output
  pinMode(RedPin,OUTPUT);
  pinMode(GreenPin,OUTPUT);
  pinMode(BluePin,OUTPUT);
}

void loop() {
  
  photoresistor = analogRead(A0);         //read the value of the photoresistor

  //print the photoresistor value to the serial monitor
    Serial.print("Photoresistor value: ");
    Serial.print(photoresistor);  
    Serial.println();
    
  if(photoresistor < 650){          //if it's darker than roughly a room with lights on then cycle through colors
    //start pulse function
      pulse();
    //print rgb values to see the brightness and color changes in the form RGB(Red,Green,Blue)
      Serial.print("RGB(");
      Serial.print(redvalue);
      Serial.print(", ");
      Serial.print(greenvalue);
      Serial.print(", ");
      Serial.print(bluevalue);
      Serial.print(")");
      Serial.println();
      
  } 
  else {                                
    //if not dark enough, set all 3 pins to zero brightness
    turnOff();   
  }
  delay(100);                             //short delay so that the printout is easier to read
}

/* Pulse function. 
 * See var declarations for info on values and flags. 
 * The reason this program is full spaghetti is because there seem to
problems with synchronization with the rgb pins. Having individual
functions that get called one after another does not result in the
expected behavior. Similar thing with having less variables and reusing
them in the big function. meh


  FOR MODIFYING 
-------------------
TO CHANGE PULSE SPEED: 
To make speed faster, lower values and thresholds but 
roughly preserve the ratio of the counter threshold to the 
value threshold to ensure the values still get to 0 before timed out. 
e.g. making redcounter<=49 --> redcounter<=11 and redvalue>=50 --> redvalue>=12 will result in much faster red
To make slower do the opposite. Also note that a similar effect can be done by modifying 
the counter threshold and the redvalue incrementation.

TO ADD/REMOVE COLORS:
The current colors correspond to the variable names,
so removing whichever color you want should be easy.
Just make sure the logic flow is preserved (brackets are
in proper place and it goes if --> else if --> else).
Adding colors is roughly the same, I would play around with
values in the example functions, then when happy copy everything        
inside the outermost brackets and paste it where you want 
in the pulse function. Again, preserve if --> else if --> else and it should work fine.

CHANGING BRIGHTNESS:
If you want it to be less bright but pulse the same amount of length,
you'll have to make the color values increment more slowly,
the value threshold be lower, and the counter threshold the same.
e.g. redvalue+=2 --> redcounter+=1 and redvalue>=50 --> redvalue>=25
It can also go brighter up to a total value of 255 if you're looking to do the opposite.

STROBE WITH PULSE/COLOR CHANGE:
Adding something like if(redvalue%5==0){ 
                        turnOff();
                      }
at the bottom of each inner if() that ends in incrementing (so after redcounter++; for example) 
is a good starting place. This will turn the led off every time the value it's checking against 
is divisible by 5. Modifying this value will result in a faster or slower strobe, 
but if too fast (value%1==0), then the led will just stay turned off.

*/ 
void pulse (){
  if(redcounter<=41){
    if(redvalue==0 and redflag==0){
      redflag=1;
      redvalue+=2.5;
      analogWrite(RedPin, redvalue);
      redcounter++;
    }
    else if(redvalue>=50 and redflag==1){
      redflag=0;
      redvalue-=2.5;
      analogWrite(RedPin, redvalue);
      redcounter++;
    }
    if(redflag==1){
      redvalue+=2.5;
      analogWrite(RedPin,redvalue);
      redcounter++;
    }
    if(redflag==0){
      redvalue-=2.5;
      analogWrite(RedPin,redvalue);
      redcounter++;
    }
  }
  else if(orangecounter<=199){
    if(redvalue==0 and redflag==0){
      redflag=1;
      redvalue+=10;
      greenvalue++;
      analogWrite(RedPin, redvalue);
      analogWrite(GreenPin, greenvalue);
      orangecounter+=5;
    }
    else if(redvalue>=200 and redflag==1){
      redflag=0;
      redvalue-=10;
      greenvalue--;
      analogWrite(RedPin, redvalue);
      analogWrite(GreenPin, greenvalue);
      orangecounter+=5;
    }
    if(redflag==1){
      redvalue+=10;
      greenvalue++;
      analogWrite(RedPin, redvalue);
      analogWrite(GreenPin, greenvalue);
      orangecounter+=5;
    }
    if(redflag==0){
      redvalue-=10;
      greenvalue--;
      analogWrite(RedPin, redvalue);
      analogWrite(GreenPin, greenvalue);
      orangecounter+=5;
    }
  }
  else if(yellowcounter<=45){
    if(redvalue==0 and redflag==0){
      redflag=1;
      redvalue+=4;
      analogWrite(RedPin, redvalue);
      greenvalue+=1;
      analogWrite(GreenPin, greenvalue);
      yellowcounter+=1.5;
    }
    else if(redvalue>=90 and redflag==1){
      redflag=0;
      redvalue-=4;
      analogWrite(RedPin, redvalue);
      greenvalue-=1;
      analogWrite(GreenPin, greenvalue);
      yellowcounter+=1.5;
    }
    if(redflag==1){
      redvalue+=4;
      analogWrite(RedPin,redvalue);
      greenvalue+=1;
      analogWrite(GreenPin, greenvalue);
      yellowcounter+=1.5;
    }
    if(redflag==0){
      redvalue-=4;
      analogWrite(RedPin,redvalue);
      greenvalue-=1;
      analogWrite(GreenPin, greenvalue);
      yellowcounter+=1.5;
    }
  }
  else if(greencounter<=41){
    if(greenvalue==0 and greenflag==0){
      greenflag=1;
      greenvalue+=2.5;
      analogWrite(GreenPin, greenvalue);
      greencounter++;
    }
    else if(greenvalue>=50 and greenflag==1){
      greenflag=0;
      greenvalue-=2.5;
      analogWrite(GreenPin, greenvalue);
      greencounter++;
    }
    if(greenflag==1){
      greenvalue+=2.5;
      analogWrite(GreenPin,greenvalue);
      greencounter++;
    }
    if(greenflag==0){
      greenvalue-=2.5;
      analogWrite(GreenPin,greenvalue);
      greencounter++;
    }
  }
  else if(cyancounter<=45){
    if(greenvalue==0 and greenflag==0){
      greenflag=1;
      greenvalue+=4;
      analogWrite(GreenPin, greenvalue);
      bluevalue+=1;
      analogWrite(BluePin, bluevalue);
      cyancounter+=1.5;
    }
    else if(greenvalue>=90 and greenflag==1){
      greenflag=0;
      greenvalue-=4;
      analogWrite(GreenPin, greenvalue);
      bluevalue-=1;
      analogWrite(BluePin, bluevalue);
      cyancounter+=1.5;
    }
    if(greenflag==1){
      greenvalue+=4;
      analogWrite(GreenPin,greenvalue);
      bluevalue+=1;
      analogWrite(BluePin, bluevalue);
      cyancounter+=1.5;
    }
    if(greenflag==0){
      greenvalue-=4;
      analogWrite(GreenPin,greenvalue);
      bluevalue-=1;
      analogWrite(BluePin, bluevalue);
      cyancounter+=1.5;
    }
  }
  else if(bluecounter<=41){
    if(bluevalue==0 and blueflag==0){
      blueflag=1;
      bluevalue+=2.5;
      analogWrite(BluePin, bluevalue);
      bluecounter++;
    }
    else if(bluevalue>=50 and blueflag==1){
      blueflag=0;
      bluevalue-=2.5;
      analogWrite(BluePin, bluevalue);
      bluecounter++;
    }
    if(blueflag==1){
      bluevalue+=2.5;
      analogWrite(BluePin,bluevalue);
      bluecounter++;
    }
    if(blueflag==0){
      bluevalue-=2.5;
      analogWrite(BluePin,bluevalue);
      bluecounter++;
    }
  }
  else if(magentacounter<=45){
    if(bluevalue==0 and blueflag==0){
      blueflag=1;
      bluevalue+=4;
      analogWrite(BluePin, bluevalue);
      redvalue+=1;
      analogWrite(RedPin, redvalue);
      magentacounter+=1.5;
    }
    else if(bluevalue>=90 and blueflag==1){
      blueflag=0;
      bluevalue-=4;
      analogWrite(BluePin, bluevalue);
      redvalue-=1;
      analogWrite(RedPin, redvalue);
      magentacounter+=1.5;
    }
    if(blueflag==1){
      bluevalue+=4;
      analogWrite(BluePin,bluevalue);
      redvalue+=1;
      analogWrite(RedPin, redvalue);
      magentacounter+=1.5;
    }
    if(blueflag==0){
      bluevalue-=4;
      analogWrite(BluePin,bluevalue);
      redvalue-=1;
      analogWrite(RedPin, redvalue);
      magentacounter+=1.5;
    }
  }
  else if(pinkcounter<=45){
    if(redvalue==0 and redflag==0){
      redflag=1;
      redvalue+=4;
      analogWrite(RedPin, redvalue);
      bluevalue+=1;
      analogWrite(BluePin, bluevalue);
      pinkcounter+=1.5;
    }
    else if(redvalue>=90 and redflag==1){
      redflag=0;
      redvalue-=4;
      analogWrite(RedPin, redvalue);
      bluevalue-=1;
      analogWrite(BluePin, bluevalue);
      pinkcounter+=1.5;
    }
    if(redflag==1){
      redvalue+=4;
      analogWrite(RedPin,redvalue);
      bluevalue+=1;
      analogWrite(BluePin, bluevalue);
      pinkcounter+=1.5;
    }
    if(redflag==0){
      redvalue-=4;
      analogWrite(RedPin,redvalue);
      bluevalue-=1;
      analogWrite(BluePin, bluevalue);
      pinkcounter+=1.5;
    }
  }
  else{
    //cycled through all colors? cool, reset counters so no one's in timeout
    redcounter=0;
    orangecounter=0;
    yellowcounter=0;
    greencounter=0;
    cyancounter=0;
    bluecounter=0;
    magentacounter=0;
    pinkcounter=0;
  }
}

//example function that shows off a faster pulse for red
void example (){
  if(redcounter<=11){
    if(redvalue==0 and redflag==0){
      redflag=1;
      redvalue+=2;
      analogWrite(RedPin, redvalue);
      redcounter++;
    }
    else if(redvalue>=12 and redflag==1){
      redflag=0;
      redvalue-=2;
      analogWrite(RedPin, redvalue);
      redcounter++;
    }
    if(redflag==1){
      redvalue+=2;
      analogWrite(RedPin,redvalue);
      redcounter++;
    }
    if(redflag==0){
      redvalue-=2;
      analogWrite(RedPin,redvalue);
      redcounter++;
    }
  }
}

//example function that shows off a less bright, standard length pulse for red
void example2 (){
  if(redcounter<=49){
    if(redvalue==0 and redflag==0){
      redflag=1;
      redvalue++;
      analogWrite(RedPin, redvalue);
      redcounter++;
    }
    else if(redvalue>=25 and redflag==1){
      redflag=0;
      redvalue--;
      analogWrite(RedPin, redvalue);
      redcounter++;
    }
    if(redflag==1){
      redvalue++;
      analogWrite(RedPin,redvalue);
      redcounter++;
    }
    if(redflag==0){
      redvalue--;
      analogWrite(RedPin,redvalue);
      redcounter++;
    }
  }
}

//turn off the led
void turnOff (){
  
    //set all three LED pins to 0 or OFF
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 0);
}
