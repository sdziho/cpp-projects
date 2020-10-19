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
int main (){
	int brojac(0);
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;		
	std::cin.ignore(10000, '\n');
	char **recenice;
	std::cout << "Unesite recenice: "<<std::endl;
	try{
		recenice=new char*[n];
		
		for(int i=0;i<n;i++){
			char prostor[1000];
			std::cin.getline(prostor,sizeof prostor);
			recenice[i]=new char[strlen(prostor)+1];
			brojac++;
			strcpy(recenice[i],prostor);
			
		}
		std::sort(recenice,recenice+n,[](const char *x,const char *y){return strcmp(x,y)<0;});
		std::cout << "Sortirane recenice: " << std::endl;
		for(int i=0;i<n;i++) std::cout << recenice[i] << std::endl;
		
		for(int i=0;i<n;i++) delete[]recenice[i];
		delete[] recenice;
	}
	catch(...){
		for(int i=0;i<brojac;i++) delete[]recenice[i];
		delete[] recenice;
		std::cout << "Problemi s memorijom!" ;
	}
	return 0;
}