#include<iostream>
using namespace std;
int main()
{   int y,d,i,m,leapyear;char *month[12]={"Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec"};
    cout<<"please enter the year and the date"<<endl;
    cin>>y>>d;
    if (y%4==0 && y%100!=0 || y%400==0) leapyear=29;
    else leapyear=28;

    for (i=1;i<=12;++i){
            if (d<=31) {i=0;break;}
            switch(i){
                case 1:d-=31;if (d<=leapyear) break;
                case 2:d-=leapyear;if (d<=31) break;
                case 3:d-=31;if (d<=30) break;
                case 4:d-=30;if (d<=31) break;
                case 5:d-=31;if (d<=30) break;
                case 6:d-=30;if (d<=31) break;
                case 7:d-=31;if (d<=31) break;
                case 8:d-=31;if (d<=30) break;
                case 9:d-=30;if (d<=31) break;
                case 10:d-=31;if (d<=30) break;
                case 11:d-=30;
            }
        }
        cout<<i<<endl;
        cout<<month[i]<<' '<<d<<endl;
    return 0;
}
