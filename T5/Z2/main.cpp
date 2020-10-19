/* 
    TP 2016/2017 (Tutorijal 5, Zadatak 2)
	
	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.
	
	NAPOMENA: autotestovi ce biti konacni TEK pred pocetak tutorijala,
	          odnosno mogu se do tada mijenjati, pa su studenti u toku
			  tutorijala duzni da ponovo testiraju SVE zadatke!
	
	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.
			  
			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <string>
#include <vector> 
#include <deque>
template <typename tip1, typename tip2, typename tip3>
tip3 RazmijeniBlokove(tip1 p1, tip2 p2, tip3 p3){
	while(p1!=p2){
		auto pomocni(*p3);
		*p3=*p1;
		*p1=pomocni;
		p1++;
		p3++;
	}
	return p3;
}
int main (){
	std::deque<double> a{1, 2, 3, 4, 5}, b{6, 7, 8, 9, 10};
	std::deque<double>::iterator iza_kraja = RazmijeniBlokove(a.begin(), a.end(), b.begin());
	for (auto it = b.begin(); it != iza_kraja; ++it)
	std::cout << *it << " ";
	std::cout << "\nPoslije razmjene:\n";
	std::cout << "Prvi niz: ";
	for(int x : a) std::cout << x << " ";
	std::cout << "\nDrugi niz: ";
	for(int x : b) std::cout << x << " ";
	std::cout << std::endl;
	
}