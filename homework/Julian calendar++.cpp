#include<iostream>
using namespace std;
int main()
{   int y,d,i;
    int dayInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    char *month[12]={"Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec"};
    cout<<"please enter the year and the date"<<endl;
    cin>>y>>d;
    if (y%4==0 && y%100!=0 || y%400==0) ++dayInMonth[1];
    for (i=0;d>dayInMonth[i];++i) d-=dayInMonth[i];
    cout<<month[i]<<' '<<d<<endl;
    return 0;
}
