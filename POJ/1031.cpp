#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>
using namespace std;

const double pi = 3.14159265358979;

struct point{
    double x,y;
}p[105];

double k,h,sum,min_angle,max_angle;
int n;

double get_angle(int i,int j){
    double ans= atan2(p[i].y,p[i].x)-atan2(p[j].y,p[j].x);
    if (ans>pi) ans-=2*pi;
    if (ans<-pi) ans+=2*pi;
    return ans;
}

int main(){
    scanf("%lf %lf %d", &k, &h, &n);
    for (int i=0;i<n;i++){
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }
    p[n]=p[0];
    for (int i=0;i<n;i++){//i,i+1
        double angle=get_angle(i,i+1);
        sum+=angle;
        if (sum>max_angle) max_angle=sum;
        if (sum<min_angle) min_angle=sum;
    }
    if (max_angle-min_angle<2*pi)
        cout<<fixed<<setprecision(2)<<(max_angle-min_angle)*k*h;
    else
        cout<<fixed<<setprecision(2)<<2*pi*k*h;
    return 0;
}
