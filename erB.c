#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){

    int i, tmp;
    pid_t pid[10];

    for (i=0;i<10;i++) { //ftiaxnw 10 child processes
	
        pid[i] = fork();

	//kanw break se kathe child wste na min treksei tin fork meta kai oles oi diergasies na exoun ton idio patera
        if (pid[i] == 0) {
            break;
        }
    }

    if (pid[0] !=0 && pid[1] !=0 && pid[2] !=0 && pid[3] !=0 && pid[4] !=0 && pid[5] !=0 && pid[6] !=0 && pid[7] !=0 && pid[8] !=0 && pid[9] !=0 && pid[10] !=0) 
	{

        // Autos einai o pateras kai perimenei gia ola ta paidia
        printf("I'm the father [pid: %d, my parent's pid: %d]\n", getpid(), getppid());

        for(i=0;i<10;i++) {
            wait(NULL);
        }

    } else {
        //To paidi ektupwnei to pid tou, kai to pid tou patera tou, to opoio einai koino se ola ta paidia
        printf("I'm one of the children [pid: %d, parent pid: %d]\n",getpid(),getppid());
    }
    return 0;
}