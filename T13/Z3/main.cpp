/* 
    TP 16/17 (Tutorijal 13, Zadatak 3)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
/* 
    TP 16/17 (Tutorijal 13, Zadatak 2)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
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




class Fakultet{
	std::vector<ApstraktniStudent*> studenti;
public:
	~Fakultet(){for(int i=0;i<studenti.size();i++)delete studenti[i];}
	Fakultet()=default;
	Fakultet(const Fakultet &f){
		for(int i=0;i<f.studenti.size();i++) studenti.push_back(f.studenti[i]->DajKopiju());
		
	}
	Fakultet &operator=(const Fakultet &f){
		for(int i=0;i<studenti.size();i++)delete studenti[i];
		studenti.resize(0);
		for(int i=0;i<f.studenti.size();i++) studenti.push_back(f.studenti[i]->DajKopiju());
		return *this;
	}
	Fakultet(Fakultet &&f){std::swap(studenti,f.studenti);}
	Fakultet &operator =(Fakultet &&f){
		for(int i=0;i<studenti.size();i++)delete studenti[i];
		std::swap(studenti,f.studenti);
		f.studenti.resize(0);
		return *this;
	}
	void UpisiStudenta(std::string ime, std::string prez, int ind){
		for(int i=0;i<studenti.size();i++){
			if(ind==studenti[i]->DajBrojIndeksa()) {
				throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
			}
		}
		studenti.push_back(new StudentBachelor(ime,prez,ind));
	}
	void UpisiStudenta( std::string ime, std::string prez, int ind, int god){
		for(int i=0;i<studenti.size();i++){
			if(ind==studenti[i]->DajBrojIndeksa()) {
				throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
			}
		}
		studenti.push_back(new StudentMaster(ime,prez,ind,god));
	}
	void ObrisiStudenta(int ind){
		for(int i=0;i<studenti.size();i++){
			if(ind==studenti[i]->DajBrojIndeksa()) {
				delete studenti[i];
				std::swap(studenti[i],studenti[studenti.size()-1]);
				studenti.resize(studenti.size()-1);
				return;
			}
		}
		throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	}
	
	ApstraktniStudent &operator [](int ind) const{
		for(int i=0;i<studenti.size();i++){
			if(ind==studenti[i]->DajBrojIndeksa()) {
				return *studenti[i];
			}
		}
		throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	}
	void IspisiSveStudente()const {
		std::vector<ApstraktniStudent*> pomocni;
		pomocni.resize(studenti.size());
		for(int i=0;i<studenti.size();i++){
			pomocni[i]=studenti[i];
		}
		
		std::sort(pomocni.begin(),pomocni.end(),[](ApstraktniStudent *x, ApstraktniStudent *y){
			if(x->DajProsjek()!=y->DajProsjek())return x->DajProsjek()>y->DajProsjek();
			else return x->DajBrojIndeksa()<y->DajBrojIndeksa();
		});
		for(int i=0;i<studenti.size();i++){
			pomocni[i]->IspisiPodatke();
		}
	}
	
};

int main ()
{
	 Fakultet f1; //3 studenta
  f1.UpisiStudenta("Meho", "Mehic", 3412);
  f1.UpisiStudenta("Ibro", "Ibric", 3124, 2015);
  f1.UpisiStudenta("Pero", "Peric", 1243);
 
  Fakultet f2;  //2 studenta
  f2.UpisiStudenta("Meho", "Mehic", 1111);
  f2.UpisiStudenta("Ibro", "Ibric", 2222, 2015);
  
  f1 = f2;  //dodjela manjeg većem, sadai f1 i f2 imaju 2 elementa
  std::cout << "KOPIRAJUCI OPERATOR DODJELE - manji većem" << std::endl;
  std::cout << "Original prije promjene: " << std::endl;
  std::cout << "----------------------" << std::endl;
  f1.IspisiSveStudente();
  std::cout << "Kopija prije promjene: " << std::endl;
  std::cout << "----------------------" << std::endl;
  f2.IspisiSveStudente();
  
  f2.ObrisiStudenta(1111);  //f2 sada ima 1 element
  std::cout << "Original nakon promjene: " << std::endl;
  std::cout << "----------------------" << std::endl;
  f1.IspisiSveStudente();
  std::cout << "Kopija nakon promjene: " << std::endl;
  std::cout << "----------------------" << std::endl;
  f2.IspisiSveStudente();
  
  
  f2 = f1;  //f2 sada opet ima 2 elementa
    std::cout << "KOPIRAJUCI OPERATOR DODJELE - veći manjem" << std::endl;
  std::cout << "Original prije promjene: " << std::endl;
  std::cout << "----------------------" << std::endl;
  f1.IspisiSveStudente();
  std::cout << "Kopija prije promjene: " << std::endl;
  std::cout << "----------------------" << std::endl;
  f2.IspisiSveStudente();
  
  f2.ObrisiStudenta(1111); //f2 ima 1 element
  std::cout << "Original nakon promjene: " << std::endl;
  std::cout << "----------------------" << std::endl;
  f1.IspisiSveStudente();
  std::cout << "Kopija nakon promjene: " << std::endl;
  std::cout << "----------------------" << std::endl;
  f2.IspisiSveStudente();
  
  
  Fakultet f3; //3 studenta
  f3.UpisiStudenta("Meho", "Mehic", 3412);
  f3.UpisiStudenta("Ibro", "Ibric", 3124, 2015);
  f3.UpisiStudenta("Pero", "Peric", 1243);
 
  Fakultet f4;  //2 studenta
  f4.UpisiStudenta("Meho", "Mehic", 1111);
  f4.UpisiStudenta("Ibro", "Ibric", 2222, 2015);
 
  std::cout << std::endl << std::endl;
  f3 = std::move(f4);  //dodjela manjeg većem, sadai f3 i f4 imaju 2 elementa
  std::cout << "POMIJERAJUCI OPERATOR DODJELE - manji većem" << std::endl;
  f4.IspisiSveStudente(); //f4 je prazno
  
  f4.UpisiStudenta("Meho", "Mehic", 3412);
  f4.UpisiStudenta("Ibro", "Ibric", 3124, 2015);
  f4.UpisiStudenta("Pero", "Peric", 1243);
  f3 = std::move(f4);  //f3 je prazno
  f4.IspisiSveStudente();
	return 0;
}