//TP 2016/2017: Tutorijal 1, Zadatak 1
#include <iostream>

int main ()
{
    int duzina, sirina, dubina;
    std::cout << "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    std::cin >> duzina >> sirina >> dubina;
    int d;
    std::cout << "Unesite sirinu plocice u centimetrima: ";
    std::cin >> d;
    int povrsina=duzina*sirina+dubina*sirina*2+dubina*duzina*2;
    povrsina*=10000;
    int plocica=d*d;
    if(povrsina%plocica==0){
        std::cout<<"\nZa poplocavanje bazena dimenzija "<<duzina<<"x"<<sirina<<"x"<<dubina<<"m sa plocicama dimenzija "<<d<<"x"<<d  
            <<"cm \npotrebno je "<<povrsina/plocica<<" plocica."<<std::endl;
    }
    else{
        std::cout<<"\nPoplocavanje bazena dimenzija "<<duzina<<"x"<<sirina<<"x"<<dubina<<"m sa plocicama dimenzija "<<d<<"x"<<d  
            <<"cm \nnije izvodljivo bez lomljenja plocica!"<<std::endl;
    }
    
    
    
    
	return 0;
}