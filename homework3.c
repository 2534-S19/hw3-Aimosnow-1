#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"
#include <stdio.h>


#define PRESSED 0
#define RELEASED 1

unsigned int getBit(unsigned int number, unsigned int i)

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    typedef enum {Stable_0, Tran_0to1, Stable_1, Tran_1to0} debounce_state_t;
    static debounce_state_t S = Stable_0;
    char NowbuttonStatus=checkStatus_BoosterpackS1();
    bool pressed=false;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c



        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c

        if(timer0Expired())
        {
            count0++;
        }

        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.

        bool fsmBoosterpackButtonS1(unsigned int buttonhistory)

        // TODO: If a completed, debounced button press has occurred, increment count1.

        if(pressed=true)
        {
            count1++;
        }


    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{   //get the last three bits of the count number
    int a;
    int b;
    int c;
    a=getBit(count,0);
    b=getBit(count,1);
    c=getBit(count,2);
 //assigned LEDs based on the last three bit of the count
    if(a=0,b=0,c=0)
    {
        turnOn_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
    }
    if(a=1,b=0,c=0)
    {
        turnOn_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
    }
    if(a=0,b=1,c=0)
    {
        turnOff_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
    }
    if(a=1,b=1,c=0)
    {
        turnOff_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Blue();
    }
    if(a=0,b=0,c=1)
    {
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Blue();
    }
    if(a=1,b=0,c=1)
    {
        turnOn_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Blue();
    }
    if(a=1,b=1,c=1)
    {
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
    }
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    int a;
        int b;
        int c;
        a=getBit(count,0);
        b=getBit(count,1);
        c=getBit(count,2);

        if(a=0,b=0,c=0)
        {
            turnOn_BoosterpackLEDRed();
            turnOff_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
        }
        if(a=1,b=0,c=0)
        {
            turnOn_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
        }
        if(a=0,b=1,c=0)
        {
            turnOff_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
        }
        if(a=1,b=1,c=0)
        {
            turnOff_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
            turnOn_BoosterpackLEDBlue();
        }
        if(a=0,b=0,c=1)
        {
            turnOff_BoosterpackLEDRed();
            turnOff_BoosterpackLEDGreen();
            turnOn_BoosterpackLEDBlue();
        }
        if(a=1,b=0,c=1)
        {
            turnOn_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
            turnOn_BoosterpackLEDBlue();
        }
        if(a=1,b=1,c=1)
        {
            turnOff_BoosterpackLEDRed();
            turnOff_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
        }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned int buttonhistory)
{   typedef enum {Stable_0, Tran_0to1, Stable_1, Tran_1to0} debounce_state_t;//Define different switch cases.
    static debounce_state_t S = Stable_0;
    char NowbuttonStatus=checkStatus_BoosterpackS1();
    bool pressed = false;
//assign different situation in different switch cases.
    switch(S)
    {
    case Stable_0:
        pressed=false;
        if(NowbuttonStatus = PRESSED)
        {
            S=Tran_0to1;
        }
        break;
    case Tran_0to1:
        pressed=false;
        if(NowbuttonStatus = PRESSED)
        {
            S=Stable_1;
        }
        else if(timer1Expired(void))
        {
            S=Stable_0;
        }
        break;
    case Stable_0:
        pressed=true;
        if(NowbuttonStatus != PRESSED)
        {
            S=Tran_1to0;
        }
        break;
    case Tran_0to1:
        pressed=false;
        if(NowbuttonStatus != PRESSED)
        {
            S=Stable_0;
        }
        else if(timer1Expired(void))
        {
            S=Stable_1;
        }
        break;
    }



    return pressed;
}
//function to get specific bits from number.
unsigned int getBit(unsigned int number, unsigned int i)
{
    int value=0;
    int change=number | (1<<i);
    if (number==change)
    {
        value=1;
    }
    else
    {
    value=0;
    }
    return value;
}


