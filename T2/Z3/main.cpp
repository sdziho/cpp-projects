//TP 2016/2017 (Tutorijal 2, Zadatak 3)
//NAPOMENA: OBAVEZNO je koristenje <complex> biblioteke!
#include <iostream>
#include <complex>

int main ()
{
    int n;
    std::cout << "Unesite broj elemenata: " << std::endl;
    std::cin >> n;
    std::complex<double> z1, suma(0,0);
    for(int i=1;i<=n;i++){
        std::cout << "Z_" <<i<<" = ";
        std::cin >> z1;
        suma+=(1./z1);
    }
    suma=1./suma;
    std:: cout<<"\nParalelna veza ovih elemenata ima impedansu Z_ = "<<suma <<"."<<std::endl;
	return 0;
}