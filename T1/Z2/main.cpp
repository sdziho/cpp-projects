//TP 2016/2017: Tutorijal 1, Zadatak 2
#include <iostream>
#include <cmath>

int main ()
{
    std::cout<<"Unesite tri broja: ";
    double a,b,c;
    std::cin>>a>>b>>c;
    if((a>0 && b>0 && c>0) && ((a+b)>c && (a+c)>b && (c+b)>a)){
        std::cout<<"Obim trougla sa duzinama stranica "<<a<<", "<<b<<" i "<<c<<" iznosi "<<a+b+c<<".\n";
        double s=(a+b+c)/2;
        double p=sqrt(s*(s-a)*(s-b)*(s-c));
        std::cout<<"Njegova povrsina iznosi "<<p<<".\n";
        double alfa=acos((c*c+b*b-a*a)/(2*c*b));
        double beta=acos((c*c+a*a-b*b)/(2*c*a));
        double gama=acos((a*a+b*b-c*c)/(2*a*b));
        if(alfa<=beta && alfa<=gama){
             double step=(alfa*180)/(4*atan(1));
             double stepeni=static_cast<int>(step);
             double min=(step-stepeni)*60;
             double minuta=static_cast<int>(min);
             double sekundi=static_cast<int>((min-minuta)*60);
            std::cout<<"Njegov najmanji ugao ima "<<stepeni<<" stepeni, "<<minuta<<" minuta i "<<sekundi<<" sekundi.\n";
            return 0;
        }
        if(beta<=alfa && beta<=gama){
             double step=(beta*180)/(4*atan(1));
             double stepeni=static_cast<int>(step);
             double min=(step-stepeni)*60;
             double minuta=static_cast<int>(min);
             double sekundi=static_cast<int>((min-minuta)*60);
            std::cout<<"Njegov najmanji ugao ima "<<stepeni<<" stepeni, "<<minuta<<" minuta i "<<sekundi<<" sekundi.\n";
            return 0;
        }    
        if(gama<=beta && gama<=alfa){
             double step=(gama*180)/(4*atan(1));
             double stepeni=static_cast<int>(step);
             double min=(step-stepeni)*60;
             double minuta=static_cast<int>(min);
             double sekundi=static_cast<int>((min-minuta)*60);
            std::cout<<"Njegov najmanji ugao ima "<<stepeni<<" stepeni, "<<minuta<<" minuta i "<<sekundi<<" sekundi.\n";
            return 0;
        }
    }else{
        std::cout<<"Ne postoji trougao cije su duzine stranica "<<a<<", "<<b<<" i "<<c<<"!\n";
    }
	return 0;
}