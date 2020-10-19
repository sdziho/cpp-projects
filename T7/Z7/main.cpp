/* 
    TP 16/17 (Tutorijal 7, Zadatak 7)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <set>
#include <algorithm>

template <typename tip>
std::set<tip> Presjek(std::set<tip> s1, std::set<tip> s2){
	std::set<tip> skup;
	for(auto x:s1){
		if(s2.find(x)!=s2.end()) skup.insert(x);
	}
	return skup;
}
template <typename tip2>
std::set<tip2> Unija(std::set<tip2> s1, std::set<tip2> s2){
	std::set<tip2> skup;
	for(auto x:s1) skup.insert(x);
	for(auto x:s2) skup.insert(x);
	return skup;
}
int main (){
	std::set<std::string> s1{"A", "B", "C", "C", "C"}, s2{"B", "B", "D"};
	for(auto x: Unija(s1, s2)) std::cout << x << " ";
	std::cout << std::endl;
	for(auto x: Presjek(s1, s2)) std::cout << x << " ";
	std::cout << std::endl;
	return 0;
}