/* 
    TP 16/17 (Tutorijal 9, Zadatak 1)
	
	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cmath>
class Vektor3d{
		double x,y,z;
	public:
		void Postavi (double x, double y, double z){
			Vektor3d::x=x; Vektor3d::y=y; Vektor3d::z=z;
		}
		void Ocitaj (double &x, double &y, double &z) const {
			x=Vektor3d::x; y=Vektor3d::y; z=Vektor3d::z;
		}
		double DajX() const { return x; }
		double DajY() const { return y; }
 		double DajZ() const { return z; }
 		double DajDuzinu() const { return std::sqrt(x*x+y*y+z*z);}
 		Vektor3d &PomnoziSaSkalarom(double s) {
 			x *= s; y *= s; z *= s; 
 			return *this;
 		}
		Vektor3d &SaberiSa(const Vektor3d &v1) { 
			x+=v1.x; y+=v1.y; z+=v1.z;
			return *this;
		}
		void PostaviX(double x){ Vektor3d::x=x;}
		void PostaviY(double y){ Vektor3d::y=y;}
		void PostaviZ(double z){ Vektor3d::z=z;}
		void Ispisi() const {std::cout << "{" <<x<<","<<y<<","<<z<<"}";}
		friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);

};
int main (){
	Vektor3d v1, v2;
	v1.Postavi(1,2,3);
	v2.PostaviX(1.2);
	v2.PostaviY(2.2);
	v2.PostaviZ(3.2);
//	v1.SaberiSa(v2);
	v1.Ispisi();
	v2.Ispisi();
	return 0;
}
Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2) {
 	Vektor3d v3;
 	v3.x = v1.x + v2.x; v3.y = v1.y + v2.y; v3.z = v1.z + v2.z;
 	return v3;
}