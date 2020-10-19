/* 
    TP 16/17 (Tutorijal 9, Zadatak 4)
	
	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <stdexcept>
class Sat{
		int sati,minuta,sekundi;
	public:
		static bool DaLiJeIspravno (int h, int min, int sec){ return (h<=24 && min<=60 && sec<=60 && h>=0 && min>=0 && sec>=0);}
		void Postavi (int h, int min, int sec);
		void PostaviNormalizirano (int h, int min, int sec);
		Sat Sljedeci();
		Sat Prethodni();
		Sat PomjeriZa(int br);
		void Ispisi() const;
		int DajSate() const {return sati;}
		int DajMinute ()const {return minuta;}
		int DajSekunde() const {return sekundi;}
		friend int BrojSekundiIzmedju(const Sat &s, const Sat &s2);
		static int Razmak(const Sat &s1, const Sat &s2){
			int sec1(s1.DajSate()*3600+s1.DajMinute()*60+s1.DajSekunde());
			int sec2(s2.DajSate()*3600+s2.DajMinute()*60+s2.DajSekunde());
			return sec1-sec2;
		}
	
};
int main (){
	Sat s;
	s.PostaviNormalizirano(-2, 3, 10);
	s.Ispisi(); std::cout << std::endl;
	s.PostaviNormalizirano(15, -30, 0);
	s.Ispisi(); std::cout << std::endl;
	s.PostaviNormalizirano(20, 30, -15);
	s.Ispisi(); std::cout << std::endl;
	
	s.PostaviNormalizirano(30, 10, 15);
	s.Ispisi(); std::cout << std::endl;
	s.PostaviNormalizirano(20, 70, 15);
	s.Ispisi(); std::cout << std::endl;
	s.PostaviNormalizirano(20, 10, 360);
	s.Ispisi(); std::cout << std::endl;
	
	s.PostaviNormalizirano(-1234, 1234, 2134);
	s.Ispisi();
	return 0;
}

void Sat::Postavi(int h, int min, int sec){
	if(DaLiJeIspravno(h,min,sec)){sati=h; minuta=min; sekundi=sec;}
	else throw std::domain_error("Neispravno vrijeme");
}

Sat Sat::PomjeriZa(int br){
	if(br>0){
		for(int i=0;i<br;i++) Sljedeci();
	}
	else{
		for(int i=0;i<-br;i++) Prethodni();
	}
	return *this;
}

void Sat::Ispisi() const{
	if(sati<10)std::cout <<0<< sati <<":";
	else std::cout << sati <<":";
	if(minuta<10)std::cout<<0<<minuta<<":";
	else std::cout << minuta <<":";
	if(sekundi<10)std::cout<<0<<sekundi;
	else std::cout << sekundi;
}
int BrojSekundiIzmedju(const Sat &s1, const Sat &s2){
	int sec1(s1.DajSate()*3600+s1.DajMinute()*60+s1.DajSekunde());
	int sec2(s2.DajSate()*3600+s2.DajMinute()*60+s2.DajSekunde());
	
	return sec1-sec2;
}
void Sat::PostaviNormalizirano (int h, int min, int sec){
	while(sec<0){
		sec=60+sec;
		if(min==0){
			min=59;
			if(h==0) h=23;
		}
		else min--;
	}
	if(sec>60){
		int ostatak_sec(sec/60);
		sec-=ostatak_sec*60;
		min+=ostatak_sec;
	}
	while(min<0){
		min=60+min;
		if(h==0) h=23;
		else h--;
	}
	if(min>60){
		int ostatak_min(min/60);
		min-=ostatak_min*60;
		h+=ostatak_min;
	}
	

	while(h<0)h+=24;

	if(h>24){
		int ostatak_h(h/24);
		h-=ostatak_h*24;
	}
	
	sati=h;
	minuta=min;
	sekundi=sec;
}

Sat Sat::Sljedeci(){
	sekundi++;
	if(sekundi==60) sekundi=0,minuta++;
	if(minuta==60) minuta=0,sati++;
	if(sati==24) sati=0;
	return *this;
}

Sat Sat::Prethodni(){
	sekundi--;
	if(sekundi<0) sekundi=59,minuta--;
	if(minuta<0) minuta=59,sati--;
	if(sati<0) sati=23;
	return *this;
}