
/*
  Vibro shaker musical instrument controlled by Arduino Every Nano board

  Operation: 

  by circuitapps
  January 2024
*/
#include <avr/io.h>

// PORT DEFINITIONS
#define PE3_D8 8
#define PA1_D7 7
#define PF4_D6 6
#define PB2_D5 5
#define PC6_D4 4

// Application pin definitions used in the code for simplicity
#define SHAKER_1 PE3_D8
#define SHAKER_2 PA1_D7
#define SHAKER_3 PF4_D6
#define SHAKER_4 PB2_D5
#define SHAKER_5 PC6_D4

#define SHAKER_1_ON (PORTE.OUTSET = 1<<3)
#define SHAKER_1_OFF (PORTE.OUTCLR = 1<<3)

#define SHAKER_2_ON (PORTA.OUTSET = 1<<1)
#define SHAKER_2_OFF (PORTA.OUTCLR = 1<<1)

#define SHAKER_3_ON (PORTF.OUTSET = 1<<4)
#define SHAKER_3_OFF (PORTF.OUTCLR = 1<<4)

#define SHAKER_4_ON (PORTB.OUTSET = 1<<2)
#define SHAKER_4_OFF (PORTB.OUTCLR = 1<<2)

#define SHAKER_5_ON (PORTC.OUTSET = 1<<6)
#define SHAKER_5_OFF (PORTC.OUTCLR = 1<<6)


#define HIGH_PIN 0
#define LOW_PIN 1

void mute_all()
{
  SHAKER_1_OFF;
  SHAKER_2_OFF;
  SHAKER_3_OFF;
  SHAKER_4_OFF;
  SHAKER_5_OFF;
}

void drum_and_bass_1()
{
  #define BASE_PERIOD_MS 1017
  #define DELAY_1 50
  #define DELAY_2 50
  #define DELAY_3 100

  #define RESIDUAL_DELAY (BASE_PERIOD_MS - DELAY_1 - DELAY_2 - DELAY_3)
  //#define RESIDUAL_DELAY 818

  // SHAKER_1
  SHAKER_1_ON;
  delay(DELAY_1);
  SHAKER_1_OFF;

  // SHAKER_2
  SHAKER_2_ON;
  delay(DELAY_2);
  SHAKER_2_OFF;

  // SHAKER_3
  SHAKER_3_ON;
  delay(DELAY_3);
  SHAKER_3_OFF;

  delay(RESIDUAL_DELAY);

  /*
  #define BASE_PERIOD_MS 1018

  #define DELAY_1 100
  #define DELAY_2 100

  //#define RESIDUAL_DELAY (BASE_PERIOD_MS - DELAY_1 - DELAY_2)
  #define RESIDUAL_DELAY 818

  digitalWrite(SHAKER_1, HIGH);
  delay(100);
  digitalWrite(SHAKER_1, LOW);

  digitalWrite(SHAKER_2, HIGH);
  delay(100);
  digitalWrite(SHAKER_2, LOW);

  delay(BASE_PERIOD_MS);
  */
}


void malibu_loop_1()
{
  #define BASE_PERIOD_MS 1331
  #define DELAY_50 50
  #define DELAY_60 60
  #define DELAY_70 70
  #define DELAY_80 80
  #define DELAY_90 90
  #define DELAY_100 100

  #define RESIDUAL_DELAY (BASE_PERIOD_MS - (7*DELAY_50) - (2*DELAY_80) - DELAY_90 - (2*DELAY_100))

  SHAKER_2_ON;
  delay(DELAY_50);
  SHAKER_2_OFF;
  
  delay(DELAY_90);

  SHAKER_1_ON;
  delay(DELAY_50);
  SHAKER_1_OFF;

  delay(DELAY_80);

  SHAKER_1_ON;
  delay(DELAY_50);
  SHAKER_1_OFF;

  delay(DELAY_80);

  SHAKER_2_ON;
  SHAKER_4_ON;
  delay(DELAY_50);
  SHAKER_2_OFF;
  delay(DELAY_50);
  SHAKER_4_OFF;

  delay(DELAY_50);

  SHAKER_5_ON;
  delay(DELAY_100);
  delay(DELAY_50);
  SHAKER_5_OFF;

  delay(DELAY_100);

  delay(RESIDUAL_DELAY);
  

  /*
  #define BASE_PERIOD_MS 1018

  #define DELAY_1 100
  #define DELAY_2 100

  //#define RESIDUAL_DELAY (BASE_PERIOD_MS - DELAY_1 - DELAY_2)
  #define RESIDUAL_DELAY 818

  digitalWrite(SHAKER_1, HIGH);
  delay(100);
  digitalWrite(SHAKER_1, LOW);

  digitalWrite(SHAKER_2, HIGH);
  delay(100);
  digitalWrite(SHAKER_2, LOW);

  delay(BASE_PERIOD_MS);
  */
}

void swing_loop_1()
{
  #define DELAY_50 50
  #define DELAY_60 60
  #define DELAY_450 450
  #define DELAY_482 482

  ///////////////////////////
  SHAKER_1_ON;
  delay(DELAY_60);
  SHAKER_1_OFF;
  delay(DELAY_482);

  ////////////////////////////

  SHAKER_1_ON;
  delay(DELAY_60);
  SHAKER_1_OFF;
  delay(DELAY_482);

  ////////////////////////////

  SHAKER_1_ON;
  delay(DELAY_60);
  SHAKER_1_OFF;
  delay(DELAY_482);

  ////////////////////////////
  
  SHAKER_1_ON;
  SHAKER_2_ON;
  SHAKER_3_ON;
  SHAKER_4_ON;
  delay(DELAY_60);
  SHAKER_1_OFF;
  SHAKER_2_OFF;
  SHAKER_3_OFF;
  delay(DELAY_50);
  SHAKER_4_OFF;

  delay(DELAY_450);
}

// the setup function runs once when you press reset or power the board
void setup()
{
  pinMode(SHAKER_1, OUTPUT);
  pinMode(SHAKER_2, OUTPUT);
  pinMode(SHAKER_3, OUTPUT);
  pinMode(SHAKER_4, OUTPUT);
  pinMode(SHAKER_5, OUTPUT);

  mute_all();

}

// the loop function runs over and over again forever

void loop()
{
  //drum_and_bass_1();
  //malibu_loop_1();
  swing_loop_1();
}
