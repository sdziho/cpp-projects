/* TP 2016/2017 (Tutorijal 4, Zadatak 2)

   Autotestovi by Eldar Kurtic, sva pitanja, sugestije i prijave gresaka javite na 
   mail ekurtic3@etf.unsa.ba
   
   NAPOMENA: testovi ce biti konacni TEK pred pocetak tutorijala. Zbog toga pokrenite
   testove za SVE zadatke na tutorijalu, da se ne bi desila situacija da neko uradi
   zadatak ranije i prolazi mu npr. 5/5 testova a naknadno dodano jos 2 testa koja mu
   padaju!
   
*/
#include <iostream>
#include <string>

void IzvrniString(std::string &s){
    std::string zamjena(s);
    for(int i=0;i<zamjena.length()/2;i++){
        char pomocni=s[i];
        s[i]=s[zamjena.length()-1-i];
        s[zamjena.length()-1-i]=pomocni;
    }
}

int main(){
    std::cout << "Unesi string: ";
    std::string s;
    std::getline(std::cin,s);
    IzvrniString(s);
    std::cout<<"Izvrnuti string je: "<<s;
    return 0;
}
