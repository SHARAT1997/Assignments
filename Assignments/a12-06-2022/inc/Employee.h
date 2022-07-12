#pragma once

#include <iostream>
#include <string>
#include <cstring>

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
        Employee( string n,string e,int s,string r,char g){
                empid=e;
		sal = s;
                role= r;
		gender= g;
        }
       void display();
void getEmpDetails();

};
