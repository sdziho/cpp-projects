/* 
    TP 16/17 (Tutorijal 7, Zadatak 10)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <functional>

std::function<int(int)> Kompozicija(std::function<int(int)> f, std::function<int(int)> g) {
	 return [f,g](int x) { return g(f(x)); };
	}
std::function<int(int)> IteriranaFunkcija(int fun(int), int n){
	if(n<=0) return[fun](int x){return x;};
	if(n==1) return[fun](int x){return fun(x);};
	auto f(Kompozicija(fun,fun));
	for(int i=2;i<n;i++){
		f=Kompozicija(fun,f);
	}
	return[f](int x){return f(x);};
}
int main (){
	std::cout << IteriranaFunkcija([](int x) { return x * x; }, 2)(3) << std::endl;
	std::function<double(double)> g{IteriranaFunkcija([](int x) { return x + 3; }, 5)};
	std::cout << g(7) << std::endl;
	return 0;
}