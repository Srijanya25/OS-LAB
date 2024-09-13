#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
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
printf("I am child,having pid%d\n",getpid());
printf("\n Call hello.c from child processes\n");
char*args[]={"./hello",NULL};
execv(args[0],args);
printf("\n Coming back to child processes\n");
}
else
{
printf("I am parent\n");
printf("My child's pid is %d\n",q);
}
printf("Good bye!\n");
return 0;
}
