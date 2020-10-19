/* 
    TP 2016/2017 (Tutorijal 5, Zadatak 6)
	
	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.
	
	NAPOMENA: autotestovi ce biti konacni TEK pred pocetak tutorijala,
	          odnosno mogu se do tada mijenjati, pa su studenti u toku
			  tutorijala duzni da ponovo testiraju SVE zadatke!
	
	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.
			  
			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <algorithm>
#include <vector>

void Unesi(double &n){
	std::cin >> n;
}
int SumaCifara(int a, int suma){
	if(a==0) return suma;
	suma+=abs(a)%10;
	a/=10;
	return SumaCifara(a,suma);
}
bool Proedjenje(int x, int y){
	int a(SumaCifara(x,0));
	int b(SumaCifara(y,0));
	if(a==b) return x<y;
	return a<b;
}
void Ispisi(int n){
	std::cout << n<<" ";
}
int main (){
	int n;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	std::vector<double> v;
	v.resize(n);
	std::cout << "Unesite elemente: ";
	std::for_each(v.begin(),v.end(),Unesi);
	std::sort(v.begin(),v.end(),Proedjenje);
	std::cout << "Niz sortiran po sumi cifara glasi: ";
	std::for_each(v.begin(),v.end(),Ispisi);
	std::cout << "\nUnesite broj koji trazite: ";
	int n2;
	std::cin >> n2;
	int pozicija(n-(v.end()-std::find(v.begin(),v.end(),n2)));
	if(pozicija==n) std::cout << "Trazeni broj ne nalazi se u nizu!" << std::endl;
	else std::cout << "Trazeni broj nalazi se na poziciji "<<pozicija;	
	return 0;
}