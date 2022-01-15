#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <string>
bool cmp(const std::pair<double,double> &a, const double &b){
    return a.first<b;
}
double xsinx (double x){return x*x+sin(x);}
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> v){   
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(v.at(i).first>v.at(j).first){
                auto temp=v.at(i);
                v.at(i)=v.at(j);
                v.at(j)=temp;
            }
        }
    }

    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(v.at(i).first==v.at(j).first) throw std::domain_error("Neispravni cvorovi.");
        }
    }
    //for(int i=0;i<v.size();i++) std::cout<<v.at(i).first;
    return [v] (double x){
        if(x>v.at(v.size()-1).first || x<v.at(0).first) throw std::range_error("Argument izvan opsega.");
        double xi,yi,xi1,yi1;
        auto it(std::lower_bound(v.begin(),v.end(),x,cmp));
        
        /*for(int i=0;i<v.size()-1;i++){
            if(v.at(i).first<x && v.at(i+1).first>x){
                xi=v.at(i).first;
                yi=v.at(i).second;
                xi1=v.at(i+1).first;
                yi1=v.at(i+1).second;
                break;
            }
        }*/
        xi1=(*it).first;
        yi1=(*it).second;
        it--;
        xi=(*it).first;
        yi=(*it).second;
        return yi+(yi1-yi)/(xi1-xi)*(x-xi);
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f,double x_min, double x_max, double dx){ 
    if(x_min>x_max || dx<=0) throw std::domain_error("Nekorektni parametri.");
    std::vector<std::pair<double,double>> v;
    v.push_back(std::make_pair(x_min,f(x_min)));
    x_min+=dx;
    for(;;){
        if(x_min>x_max) break;
        v.push_back(std::make_pair(x_min,f(x_min)));
        x_min+=dx;
    }
    return LinearnaInterpolacija(v);
}
double Str2Num(std::string str){
    int tacka(str.length());
    if(str.find('.')<0) tacka=str.find('.');
    else tacka=str.length();
    double zarez=0;
    double desetice=10.0;
    for(int i=tacka+1;i<str.length();i++){
        if(i>=str.length())break;
        zarez+=(str.at(i)-'0')/desetice;
        desetice*=10;
    }
    double suma=0;
    desetice=1;
    bool negativno=false;
    for(int i=tacka-1;i>=0;i--){
        if(i==0 && str.at(i)=='-'){
            negativno=true;
            break;
        }
        suma+=(str.at(i)-'0')*desetice;
        desetice*=10;
    }
    if(negativno) return(-(suma+zarez));
    return suma+zarez;
}
int main(){
    int d;
    double x_min,x_max,dx;
    std::vector<std::pair<double,double>> v;
    do{
        
        bool dobro(true);
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int unos;
        std::cin>> unos;
        if(!unos) break;
        if(unos==1){
            std::cout << "Unesite broj cvorova: ";
            int n; std::cin>>n;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i=0;i<n;i++){
                double x,y;
                std::cin >> x>>y;
                v.push_back(std::make_pair(x,y));
            }
            std::cin.ignore(10000,'\n');
            do{
                try{
                auto fja(LinearnaInterpolacija(v));
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::string str;
                std::getline(std::cin,str);
                if(str=="kraj"){ dobro=false; break;}
                double a=Str2Num(str);
                auto rez(fja(a));
                std::cout << "f(" <<a<<") = "<<rez<< std::endl;
                }catch(std::range_error e){
                    std::cout << e.what() << std::endl;
                }catch(std::domain_error e){
                    std::cout << e.what() << std::endl;
                    return 0;
                }
            }while(1);
            
            
        }
        if(!dobro) break;
        bool dobro2(true);
        if(unos==2){
            
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin>>x_min>>x_max>>dx;
            double x_min2(x_min);
            v.push_back(std::make_pair(x_min2,xsinx(x_min2)));
            x_min2+=dx;
            for(;;){
                if(x_min2>x_max) break;
                v.push_back(std::make_pair(x_min2,xsinx(x_min2)));
                x_min2+=dx;
            }
            std::cin.ignore(10000,'\n');
            do{
                try{
                auto fja=LinearnaInterpolacija(xsinx,x_min,x_max,dx);
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::string str;
                std::getline(std::cin,str);
                if(str=="kraj"){ dobro=false; break;}
                double a=Str2Num(str);
                auto rez(fja(a));
                std::cout << "f("<<a<<") = "<<xsinx(a)<< " ";
                std::cout << "fapprox("<<a<<") = "<<rez<< std::endl;
                }catch(std::range_error e){
                    std::cout << e.what() << std::endl;
                }catch(std::domain_error e){
                    std::cout << e.what() << std::endl;
                    return 0;
                }
            }while(1);
            
        }
        if(!dobro2) break;
        
        
    }while(1);
    
    
}


/*
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v, int d){
    if(d<0||d>v.size()) throw std::domain_error("Nedozvoljen red");
    return [v,d](double x) { 
        for(int i=0;i<v.size();i++){
            if(x==v[i].first) return v[i].second;
        }
        int n=v.size();
        int i=0;
        auto f1(double((w(n,d,i,v[i].first,v)*(v[i].second))/(x-v[i].first)));
        auto f2((w(n,d,i,v[i].first,v))/(x-v[i].first));
        for(i=1;i<n;i++){       //<=
            f1=f1+(w(n,d,i,v[i].first,v)*(v[i].second))/(x-v[i].first);
            f2=f2+(w(n,d,i,v[i].first,v))/(x-v[i].first);
        }
        return f1/f2;};
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f,double x_min,double x_max,double dx, int d){ //mozda double kod min i max
    if(x_min>x_max || dx<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    v.push_back(std::make_pair(x_min,f(x_min)));
    x_min+=dx;
    for(;;){
        if(x_min>x_max) break;
        v.push_back(std::make_pair(x_min,f(x_min)));
        x_min+=dx;
    }
    return BaricentricnaInterpolacija(v,d);
    
}*/