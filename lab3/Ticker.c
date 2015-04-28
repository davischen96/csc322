#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int main(int argc, char* argv[]) {

    int Delay = atoi(argv[1]);

    while (1) {
        printf("Time passes you by in lumps of %d ...\n",Delay);
        fflush(stdout);
        sleep(Delay);
    }

    return(0);
}
//-----------------------------------------------------------------------------
