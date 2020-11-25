#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

void foo()  //orizetai i sunartisi foo
{
	int x=0;
	x=x+1;
}

time_t time(time_t *t);

int main(){

	int k, status, count=0, i=0;
	pid_t pid[1000];
	time_t start, end, diff;
	start = time(NULL);  //ekteleitai i time kai apothikeutai sti metabliti start
	float mo;
	printf("Arxiki timi deuteroleptwn %ld\n", start);

	while(i<1000)
	{
		pid[i] = fork();
		if(pid[i]==0){
			foo();
			exit(0);//o pateras dimiourgei ta paidia kai oxi i kathe paidi ena allo
		}
		i++;
	}

	for(k=0; k<1000; k++){
		if(pid[k]>0){
			waitpid (pid[k], &status, 0); //o pateras perimenei kathe paidi ksexwrista
		}
	}

	end = time(NULL); //mesw tis time() pairnei timi end
	printf("Teliki timi deuteroleptwn %ld\n", end);
	diff = end-start;
	printf("diff=%ld\n", diff );
	mo=(diff/1000.0); //upologizw ton meso oro
	printf("mesos oros %lf\n", mo);
	return 0;
}
//Gia 100 diergasies otan trexei to programma den parathreitai kapoia diafora stis times twn start, end opote i diafora tous
//einai 0. Epomenws trexoume to programma gia 1000 diergasies opou paratireitai diafora 1, ara mesos oros mo=0,001