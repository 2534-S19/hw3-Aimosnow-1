/*
 * myGPIO.h
 *
 *  Created on:
 *      Author:
 *
 */

#ifndef MYGPIO_H_
#define MYGPIO_H_

#define PRESSED 0
#define RELEASED 1

#define Left_LED BIT0

#define Launchpad_S1 BIT1            // P1.1
#define Launchpad_S2 BIT4       //P1.4

//bitmask for the 3 LED light for the LED on the right
#define RGBLED_Launchpad_RED BIT0   //P2.0
#define RGBLED_Launchpad_GREEN BIT1 //P2.1
#define RGBLED_Launchpad_BLUE BIT2  //P2.2

//define the two button on the booster pack
#define Boosterpad_S1 BIT1             //J4.33 P5.1
#define Boosterpad_S2 BIT5             //J4.32 P3.5

//define the three LED on the booster pack
#define RGBLED_Boosterpad_BLUE BIT6 //J4.37 P5.6
#define RGBLED_Boosterpad_GREEN BIT4    //J4.38 P2.4
#define RGBLED_Boosterpad_RED BIT6  //J4.39 P2.6




// This function initializes the peripherals used in the program.
void initGPIO();
// This function returns the value of Launchpad S1.
unsigned char checkStatus_LaunchpadS1();
// This function returns the value of Launchpad S2.
unsigned char checkStatus_LaunchpadS2();
// This function returns the value of Boosterpack S1.
unsigned char checkStatus_BoosterpackS1();
// This function returns the value of Boosterpack S2.
unsigned char checkStatus_BoosterpackS2();
// This function turns on Launchpad LED1.
void turnOn_LaunchpadLED1();
// This function turns off Launchpad LED1.
void turnOff_LaunchpadLED1();
// This function turns on Launchpad Red LED2.
void turnOn_LaunchpadLED2Red();
// This function turns off Launchpad Red LED2.
void turnOff_LaunchpadLED2Red();
// This function turns on Launchpad Blue LED2.
void turnOn_LaunchpadLED2Blue();
// This function turns off Launchpad Blue LED2.
void turnOff_LaunchpadLED2Blue();
// This function turns on Launchpad Green LED2.
void turnOn_LaunchpadLED2Green();
// This function turns off Launchpad Green LED2.
void turnOff_LaunchpadLED2Green();
// This function turns on Boosterpack Red LED.
void turnOn_BoosterpackLEDRed();
// This function turns off Boosterpack Red LED.
void turnOff_BoosterpackLEDRed();
// This function turns on Boosterpack Green LED.
void turnOn_BoosterpackLEDGreen();
// This function turns off Boosterpack Green LED.
void turnOff_BoosterpackLEDGreen();
// This function turns on Boosterpack Blue LED.
void turnOn_BoosterpackLEDBlue();
// This function turns off Boosterpack Blue LED.
void turnOff_BoosterpackLEDBlue();

// TODO: Define any constants that are local to myGPIO.c using #define


#endif /* MYGPIO_H_ */
