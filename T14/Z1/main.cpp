/* 
    TP 16/17 (Tutorijal 14, Zadatak 1)
	Autotestovi by Enil Pajic.
	NOTE: ukoliko smatrate da je greska u autotestu, radite po postavci, bice uvazeno
	NOTE: vrsit ce se provjera na prepisivanje tutorijala (i kaznjavati sa oduzimanjem poena od ukupno osvojenih)
	NOTE: ovaj tutorijal se salje kao zadaca na Zamger
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
struct Student{
	std::string ime,datum;
	int indeks;
	double prosjek;
};
int main (){
	std::vector<Student> v;
	std::ifstream ulaz("STUDENTI.TXT");
	if(!ulaz){
		std::cout << "Datoteka STUDENTI.TXT ne postoji!" << std::endl;
	}
	else{
		std::ofstream izlaz("IZVJESTAJ.TXT");
		izlaz<<"Student                       Indeks    Datum rodjenja      Prosjek   "<<std::endl;
		izlaz<<"-------                       ------    --------------      -------   "<<std::endl;
		while(1){
			std::string ime,dat;
			int indeks;
			double prosjek(0);
			char znak;
			std::getline(ulaz,ime);
			ulaz>>indeks;
			ulaz.ignore(1000,'\n');
			std::getline(ulaz,dat);
			int brojac(0);
			int ocjene;
			while(ulaz>>ocjene) {
				if(ocjene!=5){
					brojac++;
					prosjek+=ocjene;
				}
				if(ulaz.peek()==','){
					ulaz>>znak; continue;
				}
			}
			prosjek/=brojac;
			if(!ulaz.eof()) ulaz.clear();
			v.resize(v.size()+1);
			v[v.size()-1].ime=ime;
			v[v.size()-1].datum=dat;
			v[v.size()-1].indeks=indeks;
			v[v.size()-1].prosjek=prosjek;
			
			if(!ulaz) break;
		}
		std::sort(v.begin(),v.end(),[](Student x, Student y){
			if(x.prosjek!=y.prosjek) return x.prosjek>y.prosjek;
			else return x.indeks<y.indeks;
		});
		for(int i=0;i<v.size();i++){
			izlaz.width(30);
			izlaz<<std::left<<v[i].ime;
			izlaz.width(10);
			izlaz<<v[i].indeks;
			izlaz.width(20);
			izlaz<<v[i].datum;
			izlaz.width(10);
			izlaz<<std::fixed<<std::setprecision(2)<<v[i].prosjek<<std::endl;
		}
	}
	return 0;
}