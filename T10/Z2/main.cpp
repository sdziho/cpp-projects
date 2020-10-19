/* 
    TP 16/17 (Tutorijal 10, Zadatak 2)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
class Krug{
		double r;
	public:
		explicit Krug(double x){
			if(x<=0) throw std::domain_error("Neispravan poluprecnik");
			r=x;
			
		}
		void Postavi(double x){
			if(x<=0) throw std::domain_error("Neispravan poluprecnik");
			r=x;
		}
		double DajPoluprecnik() const {return r;}
		double DajObim() const { return 8*r*(std::atan(1));}
		double DajPovrsinu() const { return r*r*4*(std::atan(1));}
		void Skaliraj(double x) {
			if(x<=0) throw std::domain_error("Neispravan faktor skaliranja");
			r*=x;
		}
		void Ispisi () const {
			std::cout<< "R=" <<r<<std::fixed<<std::setprecision(5)<<" O="<<DajObim()<<" P="<<DajPovrsinu();
		}
		
};
class Valjak{
		Krug baza;
		double visina;
	public: 
		Valjak (double r, double v): baza(r){
			if(r<0) throw std::domain_error("Neispravan poluprecnik");
			if(v<0) throw std::domain_error("Neispravna visina");
			visina=v;
		}
		void Postavi (double r, double v) {
			if(r<0) throw std::domain_error("Neispravan poluprecnik");
			if(v<0) throw std::domain_error("Neispravna visina");
			visina=v;
			baza.Postavi(r);
		}
		Krug DajBazu() const {return baza;}
		double DajPoluprecnikBaze() const {return baza.DajPoluprecnik();}
		double DajVisinu() const {return visina;}
		double DajPovrsinu () const {return baza.DajPovrsinu()*2+baza.DajObim()*visina;}
		double DajZapreminu() const {return baza.DajPovrsinu()*visina;}
		void Skaliraj(double x) {
			if(x<=0) throw std::domain_error("Neispravan faktor skaliranja");
			baza.Skaliraj(x);
			visina*=x;
		}
		void Ispisi () const {
			std::cout <<std::fixed<<std::setprecision(5)<< "R=" <<baza.DajPoluprecnik()<<" H="<<visina<<" P="<<DajPovrsinu()<<" V="<<DajZapreminu();
		}
};
int main (){
	Krug k1(5);
	Valjak v1(1,9);
	k1.Postavi(6);
	const Krug k2(k1);                          
	const Valjak v2(v1);
	Valjak v(2, 2);
	v.Skaliraj(3);
	std::cout<<v1.DajPoluprecnikBaze() << " "<< v1.DajVisinu() << " " << v1.DajPovrsinu() << " " << v1.DajZapreminu() << std::endl;
	k2.Ispisi(); std::cout << std::endl;
	v2.Ispisi(); std::cout << std::endl;
	return 0;
}