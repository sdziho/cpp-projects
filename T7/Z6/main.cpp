/* 
    TP 16/17 (Tutorijal 7, Zadatak 6)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <list>
template <typename tip>
void SortirajListu(std::list<tip> &lista){
    auto it(lista.begin());
    auto it2(it);
    while(it!=lista.end()){
    	it2=it;
    	it2++;
    	while(it2!=lista.end()){
    		if(*it2<*it){
    		    auto pomocni(*it);
    		    *it=*it2;
    		    *it2=pomocni;
    		}
    		it2++;
    	}
    	it++;
    }
}
int main(){
    std::cout << "Koliko ima elemenata: ";
    int n;
    std::cin >> n;
    std::list<int>lista;
    std::cout << "Unesite elemente: ";
    for(int i=0;i<n;i++){
        double broj;
        std::cin >> broj;
        lista.push_back(broj);
    }
	SortirajListu(lista);
	std::cout << "Sortirana lista: ";
	for(auto it=lista.begin();it!=lista.end();it++) std::cout << *it <<" ";
	return 0;
}