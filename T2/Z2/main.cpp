//TP 2016/2017: Tutorijal 2, Zadatak 2
#include <iostream>
#include <vector>
#include <cmath>

bool TestPerioda(std::vector<double> v, int p){
  
    bool period=true;
    if(v.size()<=p || p<1) return false;
    for(int i=0;;i++){
        if(p+i>=v.size()) break;
        if(v.at(i)!=v.at(p+i)){
            period=false;
            break;
        }
    }
    return period;
}

int OdrediOsnovniPeriod(std::vector<double> v){
    
    for(int i=1;i<v.size();i++){
        if(TestPerioda(v,i))
            return i;
    }
    return 0;
}
int main ()
{
    std::vector<double> v;
    std::cout<<"Unesite slijed brojeva (0 za kraj): ";
    for(int i=0;;i++){
        double n;
        std::cin >> n;
        if(n==0) break;
        v.push_back(n);
    }
   
   
   if(OdrediOsnovniPeriod(v)>0)
        std::cout << "Slijed je periodican sa osnovnim periodom " <<OdrediOsnovniPeriod(v)<<"."<<std::endl;
    else
        std::cout << "Slijed nije periodican!" << std::endl;
	return 0;
}