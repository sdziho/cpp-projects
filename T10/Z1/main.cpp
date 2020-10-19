/* 
    TP 16/17 (Tutorijal 10, Zadatak 1)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>

class StedniRacun{
 	  double stanje;
 	public:
 	  StedniRacun(){stanje=0;}
 	  StedniRacun(double x){
 	  	if(x<0) throw std::logic_error("Nedozvoljeno pocetno stanje");
 	  	stanje=x;
 	  }
 	  void Ulozi(double x){
 	  	if(stanje<-x) throw std::logic_error("Transakcija odbijena");
 	  	stanje+=x;
 	  }
 	  void Podigni(double x){
 	  	if(x>stanje) throw std::logic_error("Transakcija odbijena");
 	  	stanje-=x;
 	  }
 	  double DajStanje() const {return stanje;}
 	  void ObracunajKamatu(double x){
 	  	if(x<0) throw std::logic_error("Nedozvoljena kamatna stopa");
 	  	stanje+=(stanje*(x/100));
 	  }
	
};


int main (){
	StedniRacun s1; 
	const int a(20);
	s1.Ulozi(a);
	s1.ObracunajKamatu(10);
	std::cout << s1.DajStanje()<<std::endl;
	s1=50; 
	s1.ObracunajKamatu(5);
	std::cout << s1.DajStanje()<<std::endl;
	s1.Ulozi(-10);
	s1.Podigni(2);
	std::cout << s1.DajStanje()<<std::endl;
	return 0;
}