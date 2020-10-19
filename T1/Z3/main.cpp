//TP 2016/2017: Tutorijal 1, Zadatak 3
#include <iostream>
#include <cmath>
#include <iomanip>
int main ()
{
    int a,b;
    std::cout<<"Unesite pocetnu i krajnju vrijednost: ";
    std::cin>>a>>b;
    std::cout<<"\n+---------+----------+----------+-----------+\n";
    std::cout<<"| Brojevi | Kvadrati | Korijeni | Logaritmi |\n";
    std::cout<<"+---------+----------+----------+-----------+\n";
    
    for(;a<=b;a++){
        std::cout<<"| "<<std::left<<std::setw(8)<<a;
        std::cout<<"|"<<std::right<<std::setw(9)<<a*a;
        std::cout<<" |"<<std::right<<std::setw(9)<<std::fixed<<std::setprecision(3)<<sqrt(a);
        std::cout<<" |"<<std::right<<std::setw(10)<<std::fixed<<std::setprecision(5)<<log(a)<<" |\n";
        
    }
    std::cout<<"+---------+----------+----------+-----------+";
	return 0;
}
