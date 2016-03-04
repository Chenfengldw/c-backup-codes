#include<iostream>
using namespace std;

int main()
{
    int clk[10];
    for(int i=1;i<=9;++i)cin>>clk[i];

    for(int i9=0;i9<4;++i9)
    {
    for(int i8=0;i8<4;++i8)
    {
    for(int i7=0;i7<4;++i7)
    {
    for(int i6=0;i6<4;++i6)
    {
     for(int i5=0;i5<4;++i5)
    {
     for(int i4=0;i4<4;++i4)
    {
     for(int i3=0;i3<4;++i3)
    {
     for(int i2=0;i2<4;++i2)
    {
     for(int i1=0;i1<4;++i1)
    {
        int tmp1=(clk[1]+3*(i1+i2+i4))%12;
        int tmp2=(clk[2]+3*(i1+i2+i3+i5))%12;
        int tmp3=(clk[3]+3*(i3+i2+i6))%12;
        int tmp4=(clk[4]+3*(i1+i7+i5+i4))%12;
        int tmp5=(clk[5]+3*(i1+i7+i9+i3+i5))%12;
        int tmp6=(clk[6]+3*(i3+i5+i9+i6))%12;
        int tmp7=(clk[7]+3*(i8+i7+i4))%12;
        int tmp8=(clk[8]+3*(i5+i7+i8+i9))%12;
        int tmp9=(clk[9]+3*(i6+i9+i8))%12;
        if(tmp1==0&&tmp2==0&&tmp3==0&&tmp4==0&&tmp5==0&&tmp6==0&&tmp7==0&&tmp8==0&&tmp9==0)
        {
            for(int j=0;j<i1;++j)cout<<1<<' ';
            for(int j=0;j<i2;++j)cout<<2<<' ';
            for(int j=0;j<i3;++j)cout<<3<<' ';
            for(int j=0;j<i4;++j)cout<<4<<' ';
            for(int j=0;j<i5;++j)cout<<5<<' ';
            for(int j=0;j<i6;++j)cout<<6<<' ';
            for(int j=0;j<i7;++j)cout<<7<<' ';
            for(int j=0;j<i8;++j)cout<<8<<' ';
            for(int j=0;j<i9;++j)cout<<9<<' ';
            return 0;
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
 return 0;
}
