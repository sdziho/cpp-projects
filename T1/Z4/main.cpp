//TP 2016/2017: Tutorijal 1, Zadatak 4
#include <iostream>

int main ()
{
    
    do{
        double unos1;
        std::cout<<"Unesite prirodan broj ili 0 za kraj: ";
        std::cin>>unos1;
        int unos=static_cast<int>(unos1);
        if(unos<0 || (!std::cin) || (unos!=unos1)){
            std::cout<<"Niste unijeli prirodan broj!\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            continue;
        }
        if(unos==0)
            break;

        
        int suma(0);
        for(int i=1;i<unos;i++){
            if(unos%i==0)
                suma+=i;
        }
        if(suma==unos)
            std::cout<<"Broj "<<unos<<" je savrsen!\n";
            
        if(suma>unos)
            std::cout<<"Broj "<<unos<<" je obilan!\n";
        
        if(suma<unos)
            std::cout<<"Broj "<<unos<<" je manjkav!\n";
        
        
    }while(1);
    
    std::cout<<"Dovidjenja!\n";
    
	return 0;
}