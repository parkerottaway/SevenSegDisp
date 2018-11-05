/*
 * Author:      Parker Ottaway
 * Date:        04 November 2018
 * Board:       ELEGOO MEGA2560 R3
 * Version:     0.1
 * Description: The sketch creates a single BCD translater
 *              object num that accepts an integer (0-9) and
 *              outputs either HIGH or LOW for each 
 *              segment of a seven segment display
 *              (including one bit for decimal point).
 *              Pins 31, 33, 35, 37, 39, 41, 43, 45 were
 *              used. The lowest pin number represents
 *              segment A, and the highest representes the
 *              decimal point.
 */ 

#include "BCD.hpp"
#define START_PIN 31 // Starting pin number
#define DELAY_TIME_MS 200 // Delay time in milliseconds
#define STEP_SIZE 2 // Step between assignment pins (31 -> 33 -> 35 -> ...)

BCD num; // Instantiate translator object.

void setup() {
  int sPin = START_PIN; // Pin to start at.

  // Define all pins as outputs.
  for( int ii = 0; ii < 8; ii++ ){
    pinMode(sPin,OUTPUT);
    sPin+=STEP_SIZE;
  }
}

void loop() {
  /*  Count 0 to 9, incrementing the
   *  counter every 0.2 seconds. */
  for( int jj = 0; jj < 10; jj++ ){
    num.dispInt(jj);
    delay(DELAY_TIME_MS);
  }
}
