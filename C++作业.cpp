#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define Pi 3.14159

int main(){
    int a,b;
    cin>>a>>b;
    int x=b%100+b/100*60-(a%100)-a/100*60;
    cout<<setw(2)<<setfill('0')<<x/60<<":"<<setw(2)<<setfill('0')<<x%60<<endl;
}
