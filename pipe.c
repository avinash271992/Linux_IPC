#include<stdio.h>
#include<system/sys.h>
int main (void)
{
int a[2];
int temp=0,ret;
ret= pipe(a);
if(ret==-1)
perror(ret);
if(fork())
{
sleep(10);
read(p[0],&temp,4);
printf("messgage read from IPC is % d\n",temp);
}
else
{
printf("writting data into Ipc %d\n",++temp);
write(p[1],&temp,4);
}
}

