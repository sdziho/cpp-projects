#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <type_traits>

template <typename tip>

auto KreirajIzvrnutiNiz(tip p1, tip p2)-> typename std::remove_reference<decltype(*p1)>::type*{
	try{
		int a(0);
		tip pomocni(p1);
		while(pomocni!=p2){ 
			a++;
			pomocni++;
		}
		auto pok(new typename std::remove_reference<decltype(*p1)>::type[a]);
		auto pomocni2(pok);
		for(int i=a-1;i>=0;i--){
			*(pok+i)=*p1;
			p1++;
		}
		return pomocni2;
	}
	catch(...){
		throw;
	}
}
int main (){
	try{
		int n;
		std::cout << "Koliko zelite elemenata: ";
		std::cin >> n;
		double *pok(new double[n]);
		std::cout << "Unesite elemente: ";
		for(int i=0;i<n;i++){
			double broj;
			std::cin >> broj;
			*(pok+i)=broj;
		}
	
		double *p(KreirajIzvrnutiNiz(pok,pok+n));
		std::cout << "Kreirani niz: ";
		for(int i=0;i<n;i++) std::cout << *(p+i)<<" ";
      	delete[] p;
      	delete[] pok;
	}catch(...){
		std::cout<< "Nedovoljno memorije!";
	}
	return 0;
}