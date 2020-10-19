/* TP 2016/2017 (Tutorijal 4, Zadatak 1)

   Autotestovi by Eldar Kurtic, sva pitanja, sugestije i prijave gresaka javite na 
   mail ekurtic3@etf.unsa.ba
   
   NAPOMENA: testovi ce biti konacni TEK pred pocetak tutorijala. Zbog toga pokrenite
   testove za SVE zadatke na tutorijalu, da se ne bi desila situacija da neko uradi
   zadatak ranije i prolazi mu npr. 5/5 testova a naknadno dodano jos 2 testa koja mu
   padaju!
   
*/
#include <iostream>
#include <cstdlib>
int Cifre(long long int n, int &c_min, int &c_max){
    int brojac(0);
    int max(0), min(10);
    do{
        int cifra(abs(n%10));
        if(max<cifra) max=cifra;
        if(min>cifra) min=cifra;
        n=n/10;
        brojac++;
    }while(n!=0);
    c_min=min;
    c_max=max;
    
    return brojac;
   

}

int main(){
    int min,max;
    long long int n;
    std::cout << "Unesite broj: ";
    std::cin >> n;
    int e(Cifre(n,min,max));
    std::cout << "Broj " <<n<<" ima "<<e<<" cifara, najveca je "<<max<<" a najmanja "<<min<<".";
    
   


    return 0;
}