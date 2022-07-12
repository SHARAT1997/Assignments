#include "Employee.h"
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
//#define BUF_SIZE 2000
#include <string>

int main( )
{
	int N;
	fstream f;
	cout<<"\nEnter How many Employees: ";
	cin>>N;
        Employee *E = new Employee[N];
	int pid;
	//char buf[BUF_SIZE];
	pid = fork();
	if(pid == 0)
	{
		cout<<"Child Starts"<<endl;
		f.open("Emp.txt",ios::out);
       		 if(!f)
        	{
                cout<<"Unable to open the file"<<endl;
                exit(0);
        	}
        for(int i=0;i<N;i++){
                E[i].getEmpDetails();
                f.write(reinterpret_cast<char *>(&E[i]), sizeof(Employee));
        	}
		f.close();
		cout<<"Child terminates"<<endl;

	}
	else
	{
		wait((int *)0);
		cout<<"Parent Starts"<<endl;

		f.open("Emp.txt", ios::in);
	
		if(!f)
		{
			cout<<"\nUnable to open the file"<<endl;
			exit(0);
		}

		cout<<"\nPrint Employee Details"<<endl;

        	for(int i=0;i<N;i++){
        

		f.read(reinterpret_cast<char*>(&E[i]),sizeof(Employee));
		 E[i].display();
		}
		f.close();
		cout<<"Parent terminates"<<endl;
	}

	


	return 0;
}
