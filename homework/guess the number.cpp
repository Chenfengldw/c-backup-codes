//this programe is used to guess a number.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{ int x,y,i;
  srand(time(NULL));
  x=rand()%100;
  for(i=0;i<10;++i){
      if (i==0) {
           cout<<"Please guess!"<<endl;
           cin>>y;
           if (x==y) {cout<<"You are right!"<<endl;break;}
           if (x<y) cout<<"You are too big!Guess again!"<<endl;
           if (x>y) cout<<"You are too small!Guess again!"<<endl;
      }
      else {
           cin>>y;
           if (x==y) {cout<<"You are right!"<<endl; break;}
           if (x<y) cout<<"You are too big!Guess again!"<<endl;
           if (x>y) cout<<"You are too small!Guess again!"<<endl;
      }
  }
  if (i==10) cout<<"you have used up you chances."<<endl;
  return 0;
}




