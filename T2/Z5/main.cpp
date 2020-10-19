//TP 2016/2017 (Tutorijal 2, Zadatak 5)
//NAPOMENA: za ovaj zadatak je DOZVOLJENO prekopirati
//			prethodni i napraviti potrebne izmjene

#include <iostream>
#include <complex>

int main ()
{
    int n;
    std::cout << "Unesi broj elemenata: " << std::endl;
    std::cin >> n;
    std::complex<double> suma(0,0);
    for(int i=1;i<=n;i++){
        double fi, Z;
        std::cout << "Z" <<i<<" = "<< "fi"<<i<<" =\n";
        std::cin >> Z>>fi;
        fi=(fi*(4*atan(1)))/180;
        std::complex<double> z1=std::polar(Z,fi);
        suma+=(1./z1);
    }
    suma=1./suma;
    std:: cout<<"Paralelna veza ovih elemenata ima Z = "<<abs(suma) <<" i fi = "<<(arg(suma)*180)/(4*atan(1))<<"."<<std::endl;
	return 0;
}