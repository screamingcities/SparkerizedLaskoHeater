/* Lasko Space Heater IR remote clone.
Jason Stewart 01-20-2015
*/

#include "IRremote.h"
int commadDevice(String args);

//Sets the pin to send the IR codes on.
IRsend irsend(D3);

//Remote uses RAW codes.

//Power on/off
unsigned int powerCycle[] = {1200, 450, 1200, 450, 350, 1300, 1150, 500, 1150, 500, 350, 1300, 350, 1300, 400, 1300, 350, 1300, 350, 1300, 350, 1300, 1200};
int powerSize = sizeof(powerCycle)/sizeof(int);
//Temperature Up
unsigned int heatUp[] = {1150, 500, 1150, 450, 400, 1300, 1150, 500, 1150, 500, 350, 1300, 350, 1300, 1200, 450, 350, 1300, 400, 1300, 350, 1300, 350};
int heatUpSize = sizeof(heatUp)/sizeof(int);
//Temperature Down
unsigned int heatDown[] = {1200, 450, 1150, 500, 350, 1300, 1150, 500, 1150, 500, 350, 1300, 1200, 450, 350, 1300, 400, 1300, 350, 1300, 350, 1300, 350};
int heatDownSize = sizeof(heatDown)/sizeof(int);
//Turn ocscillation on/off
unsigned int oscilateSet[] = {1200, 450, 1200, 450, 400, 1250, 1200, 450, 1200, 500, 300, 1350, 350, 1300, 350, 1300, 1200, 450, 350, 1300, 400, 1300, 350};
int ocsilateSize = sizeof(oscilateSet)/sizeof(int);
//Switch from High to Low
unsigned int highLow[] = {1200, 450, 1200, 450, 400, 1250, 1200, 450, 1150, 500, 400, 1250, 400, 1300, 350, 1300, 350, 1300, 1200, 450, 350, 1300, 400};
int highLowSize = sizeof(highLow)/sizeof(int);
//Set the timer
unsigned int setTimer[] = {1150, 450, 1200, 450, 400, 1250, 1200, 450, 1200, 500, 350, 1300, 350, 1300, 350, 1300, 400, 1250, 400, 1300, 1200, 450, 350};
int timerSize = sizeof(setTimer)/sizeof(int);


//Our Settup Function
void setup()
{
  //Take control of the LED and turn it off
  RGB.control(true);
  RGB.brightness(0);
  Spark.function("toggle", commadDevice);
}


//Our mainfunction to command the device

int commadDevice(String args)
{
  int choice = args.toInt();

  switch (choice){
    case 1:
      //Heater On/Off
      for(int x = 0; x < 4; x++){
      irsend.sendRaw(powerCycle, powerSize, 38);
      delay(100);
      }
      break;

    case 2:
      //Temperature Up
      for(int x = 0; x < 4; x++){
      irsend.sendRaw(heatUp, heatUpSize, 38);
      delay(100);
      }
      break;

    case 3:
      //Temperature Down
      for(int x = 0; x < 4; x++){
      irsend.sendRaw(heatDown, heatDownSize, 38);
      delay(100);
      }
      break;

    case 4:
      //Oscillation on/off
      for(int x = 0; x < 4; x++){
      irsend.sendRaw(oscilateSet, ocsilateSize, 38);
      delay(100);
      }
      break;

    case 5:
      //Set High or Low
      for(int x = 0; x < 4; x++){
      irsend.sendRaw(highLow, highLowSize, 38);
      delay(100);
    }
      break;

    case 6:
      //Set Timer Interval
      for(int x = 0; x < 4; x++){
      irsend.sendRaw(setTimer, timerSize, 38);
      delay(100);
    }

      break;
  }

    return 1;
}
