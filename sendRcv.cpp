#include <iostream>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<sys/wait.h>

#define PERMS 0666
#define MAXBUF 10

using namespace std;

struct msg_buf{
	long msg_type;
	char msg_txt[100];
};

typedef struct msg_buf MSG;

int main()
{
	MSG m,d;

	key_t key;
	int msgid;


	// o gen unique key
	key = ftok("myfile", 100);

	msgid = msgget(key, PERMS | IPC_CREAT);
	if(msgid<0)
	{
		perror("msgget() error");
		exit(EXIT_FAILURE);
	}
	
	key=fork();
	if(key==0){
	m.msg_type = 1;
	cout<<"\nEnter a msg to be sent\n";
	fgets(m.msg_txt, MAXBUF, stdin);

	msgsnd(msgid, &m, sizeof(m),0);

	cout<<"\nTransfered data : "<<m.msg_txt<<endl;

	
	}
	else
	{
	    wait(0);
	    while(msgrcv(msgid, &m, sizeof(m),1,0)){

		cout<<"\nReceived data : "<<m.msg_txt<<endl;
	}
	msgctl(msgid, IPC_RMID, NULL);

	}
	return (EXIT_SUCCESS);
}
