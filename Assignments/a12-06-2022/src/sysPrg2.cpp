#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#define BUF_SIZE 2000
#include <string>

using namespace std;


class Employee
{
protected:
	string name;
        string empid;
        int sal;
        string role;
	char gender;
public:
        Employee(){}
        Employee( string n,char g,string e,string r,char g){
                empid=e;
		sal = s;
                role= r;
		gender= g;
        }
       void display()
{
		cout<<"\nEmployee Details"<<endl;
		cout<<"\nName: "<<name;
		cout<<"\nGender: "<<gender;
		cout<<"\nEmployee ID: "<<empid;
		cout<<"\nSalary: "<<sal;
		cout<<"\nRole: "<<role;
		cout<<"\n\n";
}
void getEmpDetails()
{
	cout<<"\nEnter Employee Details"<<endl;
	cout<<"\nE Name: ";
	cin>>name;
	cout<<"\nGender: ";
	cin>>gender;
	cout<<"\nEmp ID: ";
	cin>>empid;
	cout<<"\nSalary: ";
	cin>>sal;
	cout<<"\nRole: ";
	cin>>role;

}

};


int main( )
{
	int N;
	fstream f;
	/*cout<<"\nEnter How many Employees: ";
	cin>>N;
	Employee *E = new Employee[N];
	
	fs.open("Emp.txt", ios::in|ios::out);
	if(!fs)
	{
		cout<<"Unable to open the file"<<endl;
		exit(0);
	}
	for(int i=0;i<N;i++){
		E[i].getEmpDetails();
		fs.write(reinterpret_cast<char *>(&E[i]), sizeof(Employee));
	}

	fs.close();


	/*cout<<"\nPrint Employee Details"<<endl;
	
	for(int i=0;i<N;i++){
		E[i].display();
	}*/
	cout<<"\nEnter How many Employees: ";
	cin>>N;
        Employee *E = new Employee[N];
	int pid;
	char buf[BUF_SIZE];
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

		cout<<"Sizeof buf : "<<sizeof(buf)<<endl;
		cout<<"\nPrint Employee Details"<<endl;

        	for(int i=0;i<N;i++){
                E[i].display();
        

		f.read(reinterpret_cast<char*>(&buf),sizeof(buf));
		}
		f.close();
		cout<<"Parent terminates"<<endl;
	}

	


	return 0;
}
