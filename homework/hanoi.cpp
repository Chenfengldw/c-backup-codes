#include <iostream.h>
int main()
{	void hanoi(int n,  char start, char finish, char temp);
	int m;
	cout<<"Enter the number of diskes:";    cin>>m;
	cout<<"the steps to moving "<<m<<" diskes:"<<endl;
	hanoi(m,'A','C','B');
	return 0;
	}
void  hanoi(int n,  char start, char finish, char temp)
{ if (n==1)  cout << start << "->" << finish << endl;
   else {   hanoi(n-1, start, temp, finish);
               cout << start << "->" << finish << endl;
               hanoi(n-1, temp, finish, start);            }
}
