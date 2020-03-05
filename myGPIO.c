/*
 * GPIO.c
 *
 *  Created on:
 *      Author:
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.
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



#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1

    // Launchpad S2

    // Boosterpack S1

    // Boosterpack S2

    // Launchpad LED1

    // Launchpad LED2 Red

    // Launchpad LED2 Green

    // Launchpad LED2 Blue

    // Boosterpack LED Red

    // Boosterpack LED Green

    // Boosterpack LED Blue
    P1DIR |= Left_LED;
    P2DIR |= RGBLED_Launchpad_RED;  //P2.0
    P2DIR |= RGBLED_Launchpad_GREEN;    //P2.1
    P2DIR |= RGBLED_Launchpad_BLUE; //P2.2
    P5DIR |= RGBLED_Boosterpad_RED;    //J4.37 P5.6
    P2DIR |= RGBLED_Boosterpad_GREEN;   //J4.38 P2.4
    P2DIR |= RGBLED_Boosterpad_BLUE;     //J4.39 P2.6



    P5DIR &= ~Boosterpad_S1;
    P3DIR &= ~Boosterpad_S2;
    P1DIR &= ~Launchpad_S1;
    P1DIR &= ~Launchpad_S2;

    P5REN |= Boosterpad_S1;
    P3REN |= Boosterpad_S2;
    P1REN |= Launchpad_S1;
    P1REN |= Launchpad_S2;

    P5OUT |= Boosterpad_S1;
    P3OUT |= Boosterpad_S2;
    P1OUT |= Launchpad_S1;
    P1OUT |= Launchpad_S2;
    // Turn off all LEDs at the start.
    P2OUT &= ~RGBLED_Launchpad_RED;
    P2OUT &= ~RGBLED_Launchpad_GREEN;
    P2OUT &= ~RGBLED_Launchpad_BLUE;
    P2OUT &= ~RGBLED_Boosterpad_RED;
    P2OUT &= ~RGBLED_Boosterpad_GREEN;
    P2OUT &= ~RGBLED_Boosterpad_BLUE;

}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return (GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN1));
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return (GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN4));
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return (GPIO_getInputPinValue(GPIO_PORT_P5, GPIO_PIN1));
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return (GPIO_getInputPinValue(GPIO_PORT_P3, GPIO_PIN5));
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void BoosterpackLEDRed()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void BoosterpackLEDGreen()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN6);
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN4);
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN4);
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN6);
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
}
