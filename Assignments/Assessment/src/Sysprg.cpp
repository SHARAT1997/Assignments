#include <bits/stdc++.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main(int argc ,char **argv)
{
    vector <string> tokens;

    for(int i=1;i<argc;i++)
        {
              stringstream check1(argv[i]);

            string intermediate;

    while(getline(check1, intermediate, ' '))
 	{
        tokens.push_back(intermediate);
    	}
	  for(int i = 0; i < tokens.size(); i++)
        	cout << tokens[i] << '\n';
        int N, status;
	N= fork();
	if(N==0)
        {
  
   	 cout << "Even: ";
    	for (int i = 1; i <= 2 * N; i++) {
  
      
        if (i % 2 == 0)
            cout << i << " ";
	exit(0); 
	cout<<"EXIT_SUCCESS"<<endl;
	}
}	

	else

	{
		wait(&status);

		if((status & 0xff))
			cout<<"\nAbnormal Child termination"<<endl;
	 	cout << "\nOdd: ";
    		for (int i = 1; i <= 2 * N; i++) {

        	if (i % 2 != 0)
            	cout << i << " ";

    	}
}	       
}
}
  
