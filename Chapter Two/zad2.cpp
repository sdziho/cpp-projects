#include <iostream>
#include <vector>
#include <math.h>
#include <stdexcept>

void SumaCetiriKvadrata(int n, int &a, int &b, int &c, int &d){
    if(n<0) throw std::domain_error("Broj koji se rastavlja mora biti nenegativan");
    std::vector<int> v;
    for(int i=0;i<4;i++){
        int kvadrat=std::sqrt(n);
        v.push_back(kvadrat);
        n=n-pow(kvadrat,2);
    }
    a=v.at(0);
    b=v.at(1);
    c=v.at(2);
    d=v.at(3);
}
int main(){
    int a,b,c,d;
    SumaCetiriKvadrata(145,a,b,c,d);
    std::cout<<a<<" "<<b<<" "<<c<<" "<<d;
    return 0;
}