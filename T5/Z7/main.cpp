/* 
    TP 2016/2017 (Tutorijal 5, Zadatak 7)
	
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
#include <deque>
#include <string>
#include <stdexcept>
template <typename tip>
auto SumaBloka(tip p1, tip p2) ->decltype(*p1+*p1){
	if(p1==p2) throw std::range_error("Blok je prazan");
	auto suma(*p1);
	p1++;
	while(p1!=p2){
		suma+=*p1;
		p1++;
	}
	return suma;
}
int main (){
	std::deque<std::string> d (0);
	std::string suma = SumaBloka (d.begin(), d.end());
	std::cout << "'" << suma << "'";
	return 0;
}