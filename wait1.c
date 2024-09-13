#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
pid_t q;
printf("Hello! It is Before fork\n\n");
printf("PID=%d\n",getpid());
q=fork();
if(q<0)
{
printf("Error");
}
else
if(q==0)
{
printf("I am Child,having pid%d\n",getpid());
}
else
{
wait(NULL);
printf("I am Parent\n");
printf("My child's pid is %d\n",q);
}
printf("Good Bye!\n");
return 0;
}

