#include "Employee.h"

void Employee :: display()
{
		cout<<"\nEmployee Details"<<endl;
		cout<<"\nName: "<<name;
		cout<<"\nGender: "<<gender;
		cout<<"\nEmployee ID: "<<empid;
		cout<<"\nSalary: "<<sal;
		cout<<"\nRole: "<<role;
		cout<<"\n\n";
}
void Employee :: getEmpDetails()
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
