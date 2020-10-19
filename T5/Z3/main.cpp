/* 
    TP 2016/2017 (Tutorijal 5, Zadatak 3)
	
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
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
bool PotpunKvadrat(int n){
	double c(std::sqrt(double(n)));
	int d(std::sqrt(n));
	if(c==d) return true;
	else return false;
}

bool BrojCifra(int x, int y){
	std::string s1(std::to_string(abs(x)));
	std::string s2(std::to_string(abs(y)));
	return s1.length()<s2.length();
}
void Ispisi(int n){
	std::string s(std::to_string(abs(n)));
	if(s.length()!=3) 
	std::cout << n<<" ";
}
void Unesi(double &n){
	std::cin >> n;
}
int main (){
	int n;
	std::cout << "Unesite broj elemenata (max. 1000): ";
	std::cin >> n;
	std::cout << "Unesite elemente: ";
	std::vector<double> v;
	v.resize(n);
	std::for_each(v.begin(),v.end(),Unesi);
	
	std::cout << "Najveci element niza je " <<*std::max_element(v.begin(),v.end())<< std::endl;
	int min(*std::min_element(v.begin(),v.end()));
	std::cout << "Najmanji element niza se pojavljuje " <<std::count(v.begin(),v.end(),min)<< " puta u nizu"<<std::endl;
	std::cout << "U nizu ima " <<std::count_if(v.begin(),v.end(),PotpunKvadrat)<<" brojeva koji su potpuni kvadrati"<< std::endl;
	std::cout << "Prvi element sa najmanjim brojem cifara je " <<*std::min_element(v.begin(),v.end(),BrojCifra)<<std::endl;
	std::cout << "Elementi koji nisu trocifreni su: ";
    std::for_each(v.begin(),v.end(),Ispisi);

	return 0;
}