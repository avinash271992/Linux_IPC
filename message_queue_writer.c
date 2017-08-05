#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/ipc.h> 
#include<sys/msg.h>
#include<string.h>
struct msgbuff
{
int mtype;
char mtext[20];
};

int main(int argc,char **argv)
{
int id;
id=msgget(1,IPC_CREAT|0666);
struct msgbuff v;
bzero(&v.mtext,20);
v.mtype=atoi(argv[1]);
printf("write something in message queue \n");
scanf("%s",v.mtext);
if(msgsnd(id,&v,strlen(v.mtext),0)==-1)
perror("msgsnd");
else
printf("success\n");
}
