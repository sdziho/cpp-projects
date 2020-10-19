//TP 2016/2017: Tutorijal 8, Zadatak 1
#include <iostream>
#include <iomanip>
#include <stdexcept>
struct Vrijeme{
    int sati,minute,sekunde;
};
void TestirajVrijeme(Vrijeme v2){
    if(v2.sati>=24 || v2.minute>=60 || v2.sekunde>=60 || v2.sati<0 || v2.minute<0 || v2.sekunde<0)throw std::domain_error("Neispravno vrijeme");
}
void IspisiVrijeme(Vrijeme vrijeme){
    try{
        TestirajVrijeme(vrijeme);
    }
    catch(std::domain_error e){
        throw e;
    }
    if(vrijeme.sati<10) std::cout<<0<< vrijeme.sati<<":";
    else std::cout<< vrijeme.sati<<":";
    if(vrijeme.minute<10) std::cout<<0<< vrijeme.minute<<":";
    else std::cout<< vrijeme.minute<<":";
    if(vrijeme.sekunde<10) std::cout<<0<< vrijeme.sekunde;
    else std::cout<< vrijeme.sekunde;
}

Vrijeme SaberiVrijeme(Vrijeme v1,Vrijeme v2){
    Vrijeme v3;
    try{
        TestirajVrijeme(v1);
        TestirajVrijeme(v2);
    }
    catch(std::domain_error){
        throw;
    }
    v3.sati=v2.sati+v1.sati;
    v3.minute=v2.minute+v1.minute;
    v3.sekunde=v2.sekunde+v1.sekunde;
    if(v3.sekunde>=60){
        v3.sekunde-=60;
        v3.minute++;
    }
    if(v3.minute>=60){
        v3.minute-=60;
        v3.sati++;
    }
    if(v3.sati>=24) v3.sati-=24;
    return v3;
}

int main (){
    try{
        std::cout << "Unesite prvo vrijeme (h m s): ";
        Vrijeme v1;
        std::cin >> v1.sati>>v1.minute>>v1.sekunde;
        TestirajVrijeme(v1);
        std::cout << "Unesite drugo vrijeme (h m s): ";
        Vrijeme v2;
        std::cin >> v2.sati>>v2.minute>>v2.sekunde;
        TestirajVrijeme(v2);
    
        std::cout<<"Prvo vrijeme: ";
        IspisiVrijeme(v1);
        std::cout  << std::endl;
        std::cout<<"Drugo vrijeme: ";
        IspisiVrijeme(v2);
        std::cout<<std::endl;
        Vrijeme v3(SaberiVrijeme(v1,v2));
        std::cout<<"Zbir vremena: ";
        IspisiVrijeme(v3);
    }
    catch(std::domain_error e){
        std::cout << e.what() << std::endl;
    }
	return 0;
}