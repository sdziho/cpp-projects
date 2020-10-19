//TP 2016/2017 (Tutorijal 2, Zadatak 4)
//NAPOMENA: za ovaj zadatak je DOZVOLJENO prekopirati
//			prethodni i napraviti potrebne izmjene
#include <iostream>
#include <complex>

int main ()
{
    int n;
    std::cout << "Unesite broj elemenata: " << std::endl;
    std::cin >> n;
    std::complex<double> suma(0,0);
    for(int i=1;i<=n;i++){
        double R,X;
        std::cout << "R" <<i<<" = "<< "X"<<i<<" = "<<std::endl;
        std::cin >> R>>X;
        std::complex<double> z1=std::complex<double>(R,X);
        suma+=(1./z1);
    }
    suma=1./suma;
    std:: cout<<"\nParalelna veza ovih elemenata ima R = "<<real(suma) <<" i X = "<<imag(suma)<<"."<<std::endl;
	return 0;
}