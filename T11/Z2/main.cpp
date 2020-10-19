/* 
    TP 16/17 (Tutorijal 11, Zadatak 2)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>

class StedniRacun{
 	  double stanje;
 	  static int ukupno;
 	  static int zivih;
 	public:
 	  StedniRacun(){
 	  	stanje=0;
 	  	ukupno++;
 	  	zivih++;
 	  }
 	  explicit StedniRacun(double x){
 	  	if(x<0) throw std::logic_error("Nedozvoljeno pocetno stanje");
 	  	stanje=x;
 	  	ukupno++;
 	  	zivih++;
 	  }
 	  StedniRacun(const StedniRacun &x){
 	  	if(x.stanje<0) throw std::logic_error("Nedozvoljeno pocetno stanje");
 	  	stanje=x.stanje;
 	  	ukupno++;
 	  	zivih++;
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
 	  static int DajBrojKreiranih(){ return ukupno;}
 	  static int DajBrojAktivnih(){ return zivih;}
 	  ~StedniRacun(){zivih--;}
};

int StedniRacun::ukupno(0);
int StedniRacun::zivih(0);

int main (){
	StedniRacun s1, s2(100);
	{ StedniRacun s3(50); } // Nakon } s3 više ne postoji...
	std::cout << StedniRacun::DajBrojKreiranih()<< " " << StedniRacun::DajBrojAktivnih(); 
	return 0;
}