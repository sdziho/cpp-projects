/*
	TP 2016/2017 (Tutorijal 2, Zadatak 1)
	NAPOMENA: za Autotest 8 procitati dodatak 
			  "Prekoracenja i nepredznacna aritmetika"
	Link: https://c2.etf.unsa.ba/mod/resource/view.php?id=34456
	
	ZABRANJENA je svaka vrsta stimanja/hardkodiranja, posebno
	gdje se navode konstante, tipa if (x == 123)
*/
#include <iostream>
#include <vector> 
#include <limits>
#include <cmath>

bool DaLiJeProst(int n){
	bool iskaz=true;
	if(n<2) return false;
	for(int i=2;i<sqrt(n+1);i++){
		if(n%i==0){
			iskaz=false; 
			break;
		}
	}
	return iskaz;
}

std::vector<int> ProstiBrojeviUOpsegu(int a, int b){
	std::vector<int> rezultat ;
	for(int i=a;i<=b;i++){
		if (DaLiJeProst(i)) 
			rezultat.push_back(i);
		if(i==std::numeric_limits<int>::max()) break;
	}
	return rezultat;
}

int main ()
{
	int a,b;
	std::cout << "Unesite pocetnu i krajnju vrijednost: " ;
	std::cin >>a>>b;
	std::vector<int> v=ProstiBrojeviUOpsegu(a,b) ;
	if(v.size()==0){
		std::cout<<"Nema prostih brojeva u rasponu od "<<a<<" do "<<b<<"!";
	}
	else{
		std::cout<<"Prosti brojevi u rasponu od "<<a<<" do "<<b<<" su: ";
		for(int i=0;i<v.size();i++){
			if(i==v.size()-1)
				std::cout<<v[i]<<std::endl;
			else
				std::cout<<v[i]<<", ";
		}
	}
	
	return 0;
}