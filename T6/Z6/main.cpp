/* 
    TP 16/17 (Tutorijal 6, Zadatak 5)
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <type_traits>
#include <vector>
#include <deque>
#include <string>
template <typename tip>

auto KreirajDinamickuKopiju2D(tip matrica) -> typename std::remove_reference<decltype (matrica[0][0])>::type **{
	typedef typename std::remove_reference<decltype (matrica[0][0])>::type matrica_pokazivac;
	matrica_pokazivac **pok;
	try{
		int velicina(0);
		for(int i=0;i<matrica.size();i++) velicina+=matrica[i].size();
		pok=new matrica_pokazivac*[matrica.size()];
		pok[0]=new matrica_pokazivac[velicina];
		for(int i=1;i<matrica.size();i++) pok[i]=pok[i-1]+matrica[i-1].size();
	}
	catch(...){

		delete [] pok;
		throw;
	}
	
	for(int i=0;i<matrica.size();i++){
		for(int j=0;j<matrica[i].size();j++){
			pok[i][j]=matrica[i][j];
		}
	}
	return pok;
}
int main (){
	try{
		int n;
		std::cout << "Unesite broj redova kvadratne matrice: ";
		std::cin>>n;
		std::vector<std::vector<int>> matrica;
		matrica.resize(n);
		for(int i=0;i<n;i++) matrica[i].resize(n);
		std::cout << "Unesite elemente matrice: ";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				std::cin >> matrica[i][j];
			}
				
		}
		int** pok(KreirajDinamickuKopiju2D(matrica));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				std::cout << pok[i][j]<<" ";
			}
			std::cout << std::endl;
				
		}

		delete []pok;
	}
	catch(...){
		std::cout<< "Nedovoljno memorije";
	}
	return 0;
}