#include <stdio.h>
#include <time.h>     
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include "common/progress_timer.h"
    
int checkSignal()
{
        sigset_t waitset;
        siginfo_t info;
        struct timespec timeout;

        sigemptyset( &waitset );
        sigaddset( &waitset, SIGALRM );
        sigprocmask( SIG_BLOCK, &waitset, NULL );

        timeout.tv_sec = 0;     
        timeout.tv_nsec = 1000;

        return (sigtimedwait( &waitset, &info, &timeout ) == SIGALRM);
}

void formatDiff(time_t time1, time_t time2, char* buf)
{
    int dif = difftime(time1, time2);
    int hh = dif / 3600;
    int mm = (dif - hh * 3600) / 60;
    int ss = dif % 60;
    sprintf(buf, "%02d:%02d:%02d", hh, mm, ss);    
}

int progressTimer(const char* s)
{
    int code = fork();
    
    if (code == 0)
    {
        time_t start;
        time_t now;
        char buf[64];
        
        // if parent is not alive then exit
        if (kill(getppid(), SIGCONT) == -1)
        {
            exit(0);
        }

        printf("%s", s);
        fflush(stdout);
            
        time(&start);            
        
        while(1)
        {
            time(&now);
            formatDiff(now, start, buf);
            printf("Elapsed time:   %s", buf);
            fflush(stdout);
            sleep(1);
            
            // if parent is not alive then exit
            if (kill(getppid(), SIGCONT) == -1)
            {
                exit(0);
            }            
            
            // if parent asked to stop then exit
            if (checkSignal())
            {
                exit(0);
            }
            
            printf("\r");
            fflush(stdout);
        }
    }
    return code;        
}

int launchProgressTimer(int estimate)
{
    char prompt[256];
    char buf[64];
    
    formatDiff(estimate, 0, buf);
    sprintf(prompt, "Estimated time: %s\n", buf);
    
    return progressTimer(prompt);
}
