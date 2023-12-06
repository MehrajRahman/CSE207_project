#include <stdio.h>
#include <time.h>
#include <unistd.h>

void timer()
{
    for (int i = 0; i >= 0; i--)
    {
        for (int j = 2; j >= 0; j--)
        {
            sleep(1); // sleep for 1 second
        }
    }
}