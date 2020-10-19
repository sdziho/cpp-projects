/* 
    TP 16/17 (Tutorijal 11, Zadatak 3)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <iomanip>
class Tim{
		char ime_tima[20];
		int broj_odigranih;
		int broj_pobjeda;
		int broj_nerijesenih;
		int broj_poraza;
		int broj_datih;
		int broj_primljenih;
		int broj_poena;
	public:
		Tim(const char ime[]){
			if(strlen(ime)>20) throw std::range_error("Predugacko ime tima");
			strcpy(ime_tima,ime);
			broj_odigranih=broj_datih=broj_nerijesenih=broj_pobjeda=broj_poena=broj_poraza=broj_primljenih=0;
		}
		void ObradiUtakmicu(int broj_datih, int broj_primljenih){
			if(broj_datih<0||broj_primljenih<0 ) throw std::range_error("Neispravan broj golova");
			if(broj_datih>broj_primljenih) broj_poena+=3,broj_pobjeda++;
			if(broj_datih==broj_primljenih) broj_poena++,broj_nerijesenih++;
			if(broj_datih<broj_primljenih) broj_poraza++;
			Tim::broj_datih+=broj_datih;
			Tim::broj_primljenih+=broj_primljenih;
			broj_odigranih++;
		}
		const char *DajImeTima() const{return ime_tima;}
		int DajBrojPoena() const{return broj_poena;}
		int DajGolRazliku() const{return broj_datih-broj_primljenih;}
		void IspisiPodatke() const{
			std::cout<<std::setw(20)<<std::left<<ime_tima<<std::setw(4)<<std::right<<broj_odigranih<<std::setw(4)<<broj_pobjeda<<std::setw(4)<<
			broj_nerijesenih<<std::setw(4)<<broj_poraza<<std::setw(4)<<broj_datih<<std::setw(4)<<broj_primljenih<<std::setw(4)<<broj_poena<<std::endl;
		}
};
int main ()
{
	Tim t1("NK Zeljeznicar");
	Tim t2("FK Sarajevo");
	Tim t3("HSK Zrinjski");
	  
	t1.ObradiUtakmicu(1, 0);
	t1.ObradiUtakmicu(3, 0);
	t1.ObradiUtakmicu(2, 1);
	t2.ObradiUtakmicu(1, 1);
	t2.ObradiUtakmicu(1, 0);
	t2.ObradiUtakmicu(0, 5);
	t3.ObradiUtakmicu(0, 1);
	t3.ObradiUtakmicu(0, 2);
	t3.ObradiUtakmicu(1, 1);
	   
	t1.IspisiPodatke();
	t2.IspisiPodatke();
	t3.IspisiPodatke();
	return 0;
}