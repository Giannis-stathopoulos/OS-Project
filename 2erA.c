#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
int pid1;
int pid2;

pid1 = fork();

if (pid1 < 0){
printf("Could not create any child,  \n");
}else{

pid2 = fork();

}
if (pid2 < 0){
printf("Could not create any child\n");
}
else if ( (pid1 < 0) && (pid2 < 0)){
printf("to lathos sto else if , %i \n",getpid());
printf("to lathos sto else if , %i \n",getppid());
kill(pid1,9);
printf("meta to kil paidia, %i \n",getpid());
printf("meta to kil goneis, %i \n",getpid());
}
printf("Child ID:, %i \n",getpid());
printf("Parent ID:, %i \n",getppid());
sleep(20);

return (0);
}