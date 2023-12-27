#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "../headers/timer.h"

void timer()
{
    for (int i = 0; i >= 0; i--)
    {
        for (int j = 1; j >= 0; j--)
        {
            sleep(1); // sleep for 1 second
        }
    }
}

