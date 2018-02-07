/*
  Roaming with Whiskers.c

  Go forward until object detected by whisker(s).  Then, back up, turn
  and go a new direction.

  http://learn.parallax.com/activitybot/roaming-whiskers
*/

#include "simpletools.h"                        // Include simpletools library
#include "abdrive360.h"                            // Include abdrive library

int main()                                      // main function
{
  freqout(4, 2000, 3000);                       // Speaker tone: 2 s, 3 kHz

  while(1)                                      // Main loop
  {
    // Go forward for 1/50th of a second.
    drive_speed(64, 64);                      // Go forward

    // Check whisker states.
    int wL = input(7);                          // Left whisker -> wL variable
    int wR = input(8);                          // Right whisker -> wR variable

    // If whisker(s) pressed, avoid obstacle.
    if(wR == 0)                                 // Just right whisker
    {
      drive_speed(-64, -64);                  // Back up 0.5 seconds
      pause(1500);
      drive_speed(-64, 64);                   // Turn left 0.22 seconds
      pause(750);
    }
    else if(wL == 0)                            // Just left whisker
    {
      drive_speed(-64, -64);                  // Back up 0.5 seconds
      pause(1500);
      drive_speed(64, -64);                   // Turn right 0.25 seconds
      pause(750);
    }
  }
}