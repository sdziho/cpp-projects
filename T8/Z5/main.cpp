//TP 2016/2017: Tutorijal 8, Zadatak 5
#include <iostream>

template <typename TipElementa>
struct Cvor{
    TipElementa element;
    Cvor *veza;
};
template <typename TipElemenata>
Cvor<TipElemenata> *KreirajPovezanuListu(TipElemenata zavrsni){
    Cvor<TipElemenata> *pocetak(nullptr), *prethodni;
    for(;;){
        TipElemenata el;
        std::cin >> el;
        if(el==zavrsni) break;
        Cvor<TipElemenata> *novi(new Cvor<TipElemenata>);
        novi->element=el;
        novi->veza=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->veza=novi;
        prethodni=novi;
    }
    return pocetak;
}
template <typename TipElemenata>
    int BrojElemenata(Cvor<TipElemenata> *pocetak){
        int brojac(0);
        for(;pocetak!=nullptr;pocetak=pocetak->veza) brojac++;
        return brojac;
    }
template <typename TipElemenata>
    TipElemenata SumaElemenata(Cvor<TipElemenata> *pocetak){
        TipElemenata suma(0);
        for(;pocetak!=nullptr;pocetak=pocetak->veza) suma+=pocetak->element;
        return suma;
    }
template <typename TipElemenata>
    int BrojVecihOd(Cvor<TipElemenata> *pocetak, TipElemenata prag){
        int brojac(0);
        for(;pocetak!=nullptr;pocetak=pocetak->veza){
            //std::cout << prag <<" < "<<pocetak->element<<" "<<bool(prag<pocetak->element)<< std::endl;
            if(prag<pocetak->element) brojac++;
        }
        return brojac;
    }
template <typename TipElemenata>
    void UnistiListu(Cvor<TipElemenata> *pocetak){
        auto p(pocetak);
        Cvor<TipElemenata> *novi(pocetak->veza);
        
        while(novi!=nullptr){
            pocetak->veza=novi->veza;
            novi->veza=nullptr;
            delete novi;
            novi=pocetak->veza;
        }
        p->veza=nullptr;
        delete p;
       
    }
int main (){
    std::cout << "Unesite slijed brojeva (0 za kraj): ";
    Cvor<double> *pocetak(KreirajPovezanuListu(0.));
    std::cout << "U slijedu ima " << BrojVecihOd(pocetak,SumaElemenata(pocetak)/BrojElemenata(pocetak))<<" brojeva vecih od njihove aritmeticke sredine"<< std::endl;
	UnistiListu(pocetak);
	return 0;
}
