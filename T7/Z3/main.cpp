/* 
    TP 16/17 (Tutorijal 7, Zadatak 2)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>




int main (){
	int brojac(0);
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;		
	std::cin.ignore(10000, '\n');
	std::string **recenice(nullptr);
	std::cout << "Unesite recenice: "<<std::endl;
	
	try{
		recenice=new std::string*[n];
		std::string s;
		for(int i=0;i<n;i++){
			recenice[i]=new std::string();
			std::getline(std::cin,*recenice[i]);
			brojac++;
		}
		
		std::sort(recenice,recenice+n,[](const std::string *x,const std::string *y){return *x<*y;});
		std::cout << "Sortirane recenice: " << std::endl;
		for(int i=0;i<n;i++){ 
			std::cout << *(recenice[i])<< std::endl;
		}
		for(int i=0;i<n;i++) delete recenice[i];
		delete[] recenice;
	}
	catch(...){
		for(int i=0;i<brojac;i++) delete recenice[i];
		delete[] recenice;
		std::cout << "Problemi s memorijom!" ;
	}
	return 0;
}