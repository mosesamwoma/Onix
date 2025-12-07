#include <stdio.h>
#include <time.h>
#include <unistd.h>

void displayClock(int hour, int min, int sec) {
    printf("\r%02d:%02d:%02d", hour, min, sec);
    fflush(stdout);
}

int main() {
    time_t rawtime;
    struct tm * timeinfo;
    
    while (1) {
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        displayClock(timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
        
        sleep(1);  // Wait for 1 second
    }

    return 0;
}
