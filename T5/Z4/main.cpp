/* 
    TP 2016/2017 (Tutorijal 5, Zadatak 4)
	
	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.
	
	NAPOMENA: autotestovi ce biti konacni TEK pred pocetak tutorijala,
	          odnosno mogu se do tada mijenjati, pa su studenti u toku
			  tutorijala duzni da ponovo testiraju SVE zadatke!
	
	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje dek[i] ili simulacija indeksiranja
			  npr. *(dek + i); dalje, da su zabranjene for petlje i slicno.
			  
			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <string>

int main (){
	int n;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	std::cout << "Unesite elemente: ";
	std::deque<double> v;
	v.resize(n);
	std::for_each(v.begin(),v.end(),[](double &n){std::cin >> n;});
	
	std::cout << "Najveci element deka je " <<*std::max_element(v.begin(),v.end())<< std::endl;
	int min(*std::min_element(v.begin(),v.end()));
	std::cout << "Najmanji element deka se pojavljuje " <<std::count(v.begin(),v.end(),min)<< " puta u deku"<<std::endl;
	std::cout << "U deku ima " <<std::count_if(v.begin(),v.end(),[](int n)->bool{
		double c(std::sqrt(double(n)));
		int d(std::sqrt(n));
		if(c==d) return true;
		else return false;
	});
	std::cout<<" brojeva koji su potpuni kvadrati"<< std::endl;
	std::cout << "Prvi element sa najmanjim brojem cifara je " <<*std::min_element(v.begin(),v.end(),[](int x, int y)->bool{
		std::string s1(std::to_string(abs(x)));
		std::string s2(std::to_string(abs(y)));
		return s1.length()<s2.length();
	})<<std::endl;
	std::cout << "Elementi koji nisu trocifreni su: ";
    std::for_each(v.begin(),v.end(),[](int n){	std::string s(std::to_string(abs(n)));	if(s.length()!=3) std::cout << n<<" ";});

	return 0;
}