#include<iostream>
using namespace std;

int main(){
    int a1,b1,c1,a2,b2,c2;
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    if( a1*1.0 / a2 == b1*1.0 /b2){
        if( a1*1.0 / a2 == c1*1.0 /c2) cout<<"Vo so nghiem";
        else cout<<"Vo nghiem";
    }
    else {
        double x= ( c2- b2*c1/b1)/ ( a2 - a1*b2/b1);
        cout<<"x = " << x<<", y = "<< (c1 -a1*x)/b1;
    }
}
