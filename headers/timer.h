#ifndef TIME_H
#define TIME_H

#ifdef __unix__
#include <unistd.h>
#elif defined _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif

#include <stdio.h>
#include <time.h>
#include <unistd.h>

void timer()
{

    // scanf("%d", &minutes);
    for (int i = 0; i >= 0; i--)
    {
        for (int j = 2; j >= 0; j--)
        {
            sleep(1); // sleep for 1 second
        }
    }
}


// void stopwatch() {
//     int seconds = 0;
//     printf("Stopwatch started. Press 'q' to stop.\n");
//     while (getchar() != 'q') {
//         printf("Time elapsed: %d:%d\n", seconds / 60, seconds % 60);
//         sleep(1); // sleep for 1 second
//         seconds++;
//     }
//     printf("Stopwatch stopped.\n");
// }

// int main() {
//     int choice;
//     printf("1. Timer\n2. Stopwatch\nEnter your choice: ");
//     scanf("%d", &choice);
//     if (choice == 1) {
//         timer();
//     } else if (choice == 2) {
//         stopwatch();
//     } else {
//         printf("Invalid choice.\n");
//     }
//     return 0;
// }

#endif