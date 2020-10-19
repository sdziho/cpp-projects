/* 
    TP 16/17 (Tutorijal 13, Zadatak 2)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
class ApstraktniStudent {
	 std::string ime;
	 std::string prezime;
	 int indeks,polozeni;
	 double prosjek;
public:
	 ApstraktniStudent(std::string ime,std::string prez, int ind) : ime(ime),prezime(prez), indeks(ind) { polozeni=0,prosjek=5;}
	 std::string DajIme() const { return ime; }
	 std::string DajPrezime() const{ return prezime;}
	 int DajBrojIndeksa() const { return indeks; }
	 int DajBrojPolozenih() const {return polozeni;}
	 double DajProsjek() const {return prosjek;}
	 void RegistrirajIspit(int ocjena){
	 	if(ocjena<5||ocjena>10) throw std::domain_error("Neispravna ocjena");
	 	if(ocjena!=5) polozeni++;
	 	else return;
	 	if(prosjek==5) prosjek=ocjena;
	 	else prosjek=((polozeni-1)*prosjek+ocjena)/polozeni;
	 }
	 void PonistiOcjene(){
	 	polozeni=0;
	 	prosjek=5;
	 }
	 virtual ApstraktniStudent* DajKopiju(){
	 	return new ApstraktniStudent(*this);
	 }
	 virtual void IspisiPodatke(){}
	 virtual ~ApstraktniStudent()=default;
	 
};
class StudentBachelor: public ApstraktniStudent{
public:
	StudentBachelor(std::string ime,std::string prez, int ind): ApstraktniStudent(ime,prez,ind){}
	ApstraktniStudent* DajKopiju(){
	 	return new StudentBachelor(*this);
	 }
	void IspisiPodatke(){
		std::cout<<"Student bachelor studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<
		"ima prosjek "<<DajProsjek()<<"."<<std::endl;
	}
};
class StudentMaster: public ApstraktniStudent{
	int zavrsio;
public:
	StudentMaster(std::string ime,std::string prez, int ind,int zav): ApstraktniStudent(ime,prez,ind){zavrsio=zav;}
	ApstraktniStudent* DajKopiju(){
	 	return new StudentMaster(*this);
	 }
	void IspisiPodatke(){
		std::cout<<"Student master studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<
		"zavrsio bachelor studij godine "<<zavrsio<<",ima prosjek "<<DajProsjek()<<"."<<std::endl;
	}
};
int main ()
{
	ApstraktniStudent *ps;                                
  ps = new StudentBachelor("Dusko", "Dugousko", 1234);
  ps->RegistrirajIspit(7); ps->RegistrirajIspit(6); ps->RegistrirajIspit(5);
  ps->RegistrirajIspit(10); ps->RegistrirajIspit(7);
  std::cout << ps->DajIme() << " " << ps->DajPrezime() << " " << ps->DajBrojIndeksa()
    << " " << ps->DajBrojPolozenih() << " " << ps->DajProsjek() << std::endl;
  ps->IspisiPodatke();
  delete ps;
  ps = new StudentMaster("Paja", "Patak", 4312, 2015);
  ps->RegistrirajIspit(7); ps->RegistrirajIspit(6); ps->RegistrirajIspit(5);
  ps->RegistrirajIspit(10); ps->RegistrirajIspit(7);
  std::cout << ps->DajIme() << " " << ps->DajPrezime() << " " << ps->DajBrojIndeksa()
    << " " << ps->DajBrojPolozenih() << " " << ps->DajProsjek() << std::endl;
  ps->IspisiPodatke();
  delete ps;
	return 0;
}