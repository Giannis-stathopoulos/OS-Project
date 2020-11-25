#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int i;
	int pid;
	
	//Kanw printf to pid tis main, gia na fanei poio einai wste na ektupwthei apo to prwto paidi
	printf("EIMAI H MAIN : Father = %5i, Id = %5i\n", getppid(), getpid());

	for (i=0; i<10; i++)
	{
		pid = fork();

		if (pid > 0)
		{
			if(i>0){ //i>0: thelw na paraleipsw tin prwti epanalipsi kathws tha ektupwne tin main
				printf(" Father = %5i, Id = %5i, Child = %5i\n", getppid(), getpid(), pid);
			}
			wait(NULL);
			break; //break sto patera wste na treksei i fork mono sto paidi meta gia na ginei chain process
		}

		if(i==9) //thelw stin teleutaia epanalipsi na mou emfanisei ta stoixeia kai tou teleutaiou paidiou ksexwrista se
		{	 //kainouria grammi
			if(pid==0)
			printf(" Father = %5i, Id = %5i Child =  eimai teleutaia diergasia ara den exw paidi\n", getppid(), getpid());
		}
	}
	return (0);
}