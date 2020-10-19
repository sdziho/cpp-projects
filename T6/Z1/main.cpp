
#include <iostream>
#include <stdexcept>
#include <limits>
template<typename tip>
tip *GenerirajStepeneDvojke(int n){
	if(n<=0) throw std::domain_error("Broj elemenata mora biti pozitivan");
	tip *pok;
	try{
		pok=new tip[n];
	}
	catch(...){
		throw std::runtime_error("Alokacija nije uspjela");

	}
		tip kvadrat(1);
		for(int i=0;i<n;i++){ 
			*(pok+i)=kvadrat;
			kvadrat*=2;
			if (*(pok+i)<0 || *(pok+i)>std::numeric_limits<tip>::max()){
				delete[] pok;
				throw std::overflow_error("Prekoracen dozvoljeni opseg");
				
			}
			
		}
	
	
	return pok;
}



int main (){
	int n;
	std::cout << "Koliko zelite elemenata: ";
	std::cin >> n;
	try{
		auto p(GenerirajStepeneDvojke<int>(n));
		for(int i=0;i<n;i++) std::cout << p[i]<<" ";
		delete[] p;
	}
	catch(std::domain_error izuzetak1){
		std::cout << "Izuzetak: " <<izuzetak1.what()<< std::endl;
	}
	catch(std::overflow_error izuzetak2){
		std::cout << "Izuzetak: " <<izuzetak2.what()<< std::endl;
	}
	catch(std::runtime_error izuzetak3){
		std::cout << "Izuzetak: " <<izuzetak3.what()<< std::endl;
	}
	
	
	return 0;
}