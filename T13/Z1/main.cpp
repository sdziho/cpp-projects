/* 
    TP 16/17 (Tutorijal 13, Zadatak 1)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>
#include <cmath>
class Lik{
	public:
	virtual void IspisiSpecificnosti(){
		std::cout << "Obim: " <<DajObim();
		std::cout << " Povrsina: " <<DajPovrsinu()<< std::endl;
	}
	virtual double DajObim()const {return 0;}
	virtual double DajPovrsinu()const {return 0;}
	void Ispisi(){
		IspisiSpecificnosti();
	}
};
class Krug: public Lik{
	double r;
 	static constexpr double PI = 3.141592653589793;
 public:
 	Krug (double pol){
 		if(pol<=0) throw std::domain_error("Neispravni parametri");
 		r=pol;
 	}
 	double DajObim()const {return  2 * PI * r;}
 	double DajPovrsinu() const { return r * r * PI; }
 	void IspisiSpecificnosti(){
 		std::cout << "Krug poluprecnika " <<r<< std::endl;
 		Lik::IspisiSpecificnosti();
 	}

};
class Pravougaonik: public Lik{
	double a,b;
 public:
 	Pravougaonik (double a1,double b1){
 		if(a1<=0||b1<=0) throw std::domain_error("Neispravni parametri");
 		a=a1;b=b1;
 	}
 	double DajObim()const {return  2*a+2*b;}
 	double DajPovrsinu() const { return a*b ; }
 	void IspisiSpecificnosti(){
 		std::cout << "Pravougaonik sa stranicama duzine " <<a<<" i "<<b<< std::endl;
 		Lik::IspisiSpecificnosti();
 	}

};
class Trougao: public Lik {
	double a,b,c;
 public:
 	Trougao (double a1,double b1, double c1){
 		if(a1<=0||b1<=0||c1<=0) throw std::domain_error("Neispravni parametri");
 		if(a1+b1<=c1) throw std::domain_error("Neispravni parametri");
 		if(a1+c1<=b1) throw std::domain_error("Neispravni parametri");
 		if(c1+b1<=a1) throw std::domain_error("Neispravni parametri");
 		a=a1;b=b1;c=c1;
 	}
 	double DajObim()const {return  a+b+c;}
 	double DajPovrsinu() const { 
 		double s=(a+b+c)/2;
		return sqrt(s*(s-a)*(s-b)*(s-c)); }
 	void IspisiSpecificnosti(){
 		std::cout << "Trougao sa stranicama duzine " <<a<<", "<<b<<" i "<<c<< std::endl;
 		Lik::IspisiSpecificnosti();
 	}

};
int main (){
	std::cout<<"Koliko zelite likova: ";
	int n;std::cin>>n;
	std::vector<std::shared_ptr<Lik>> likovi;
	for(int i=0;i<n;i++){
		std::cout << "Lik " << i+1<<": ";
		char slovo,zarez(',');
		std::cin>>slovo;
		if(slovo=='P'){
			int a,b;
			std::cin >> a>>zarez>>b;
			if(!std::cin){
				std::cin.clear();
				i--;
				continue;
			}
			else likovi.push_back(std::make_shared<Pravougaonik>(a,b));
		}
		if(slovo=='K'){
			int a;
			std::cin >> a;
			while(!std::cin){
				std::cin.ignore(1000,'\n');
				std::cin.clear();
				std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
				std::cin >> a;
			}
			 likovi.push_back(std::make_shared<Krug>(a));
		}
		if(slovo=='T'){
			int a,b,c;
			std::cin >> a>>zarez>>b>>zarez>>c;
			if(!std::cin){
				std::cin.clear();
				i--;
				continue;
			}
			else likovi.push_back(std::make_shared<Trougao>(a,b,c));
		}
	}
	
	
	for(auto x : likovi) x->Ispisi();
	return 0;
}