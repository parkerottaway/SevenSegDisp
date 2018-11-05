/*
 *           A
 *          ---
 *       F |   | B
 *         | G |
 *          ---
 *       E |   | C
 *         |   |
 *          --- o DP
 *           D
 *   
 *   segments { DP, G, F, E, D, C, B, A }
 */
 #include "BCD.hpp"
 #include <Arduino.h>
 #define START_PIN 31
 #define STEP_SIZE 2

// Constructor
BCD::BCD(){
  this->segments = 0b00000000;
}

// Translator function
void BCD::dispInt(int n){
  int startPin = START_PIN;
  unsigned char mask = 1;

  for( int ii = 0; ii < 8; ii++ ){
    digitalWrite(startPin,0);
    startPin+=STEP_SIZE;
  }
  
  switch(n){
    case (0):
      segments = 0;
      segments = 63;
      break;
      
    case (1):
      segments = 0;
      segments = 6;
      break;
    case (2):
      segments = 0;
      segments = 91;
      break;
      
    case (3):
      segments = 0;
      segments = 79;
      break;
      
    case (4):
      segments = 0;
      segments = 102;
      break;
      
    case (5):
      segments = 0;
      segments = 109;
      break;
      
    case (6):
      segments = 0;
      segments = 125;
      break;
      
    case (7):
      segments = 0;
      segments = 7;
      break;
      
    case (8):
      segments = 0;
      segments = 127;
      break;
      
    case (9):
      segments = 0;
      segments = 111;
      break;

    default:
      segments = 0;
      break;
  }

  // Use bit masking to determine if high or low output.
  startPin = START_PIN;
  for( int ii = 0; ii < 8; ii++ ){
    digitalWrite(startPin,(mask & segments));
    mask <<= 1; // Shift through the number.
    startPin+=STEP_SIZE;// Change assignment pin.
  }
}
