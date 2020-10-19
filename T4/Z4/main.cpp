/* TP 2016/2017 (Tutorijal 4, Zadatak 4)

   Autotestovi by Eldar Kurtic, sva pitanja, sugestije i prijave gresaka javite na 
   mail ekurtic3@etf.unsa.ba
   
   NAPOMENA: testovi ce biti konacni TEK pred pocetak tutorijala. Zbog toga pokrenite
   testove za SVE zadatke na tutorijalu, da se ne bi desila situacija da neko uradi
   zadatak ranije i prolazi mu npr. 5/5 testova a naknadno dodano jos 2 testa koja mu
   padaju!
   
*/
#include <iostream>
#include <string>

void UnosBroja(std::string unos, std::string greska, double &n){
    std::cout<<unos;
    double a;
    std::cin >> a;
    
    
    do{
        while(!std::cin || a==' '){
            std::cout<<greska<<std::endl;
            std::cout<<unos;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cin >> a;
         }
        if((std::cin.peek()>='A'&&std::cin.peek()<='z')){
            std::cout<<greska<<std::endl;
            std::cout<<unos;
            std::cin.ignore(10000, '\n');
            std::cin>> a;
            continue;
         }
        break;
    }while(1);
    n=a;
    
}
void UnosBroja(std::string unos, std::string greska, int &n){
    std::cout<<unos;
    int a;
    std::cin >> a;
    
    
    
    do{
        while(!std::cin){
            std::cout<<greska<<std::endl;
            std::cout<<unos;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cin >> a;
        }
        if(std::cin.peek()>='A'&&std::cin.peek()<='z' || std::cin.peek()=='.'){
            std::cout<<greska<<std::endl;
            std::cout<<unos;
            std::cin.ignore(10000, '\n');
            std::cin>> a;
            continue;
         }
        break;
    }while(1);
    n=a;
    
}
int main(){
    int eksponent;
    double baza;
    UnosBroja("Unesite bazu: \n", "Neispravan unos, pokusajte ponovo...", baza);
    UnosBroja("Unesite cjelobrojni eksponent: \n", "Neispravan unos, pokusajte ponovo...", eksponent);
    std::cout << baza <<" na "<<eksponent<<" iznosi ";
    double rezultat(baza);
    for(int i=1;i<abs(eksponent);i++) rezultat*=baza;
    if(eksponent<0) rezultat=1./rezultat;
    std::cout<<rezultat;
    return 0;
}