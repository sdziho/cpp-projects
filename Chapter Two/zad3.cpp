#include <iostream>
#include <vector>
#include <deque>

template <typename Tip1, typename Tip2, typename Tip3>

auto ZajednickiElementiBlokova(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 p5){
    auto pocetni3=p5;
    while(p1!=p2){
        auto broj=*p1++;
        auto pocetak=p3;
        while(pocetak!=p4){
            if(broj==*pocetak++){
                bool flag(true);
                auto pomocni=pocetni3;
                while(pomocni!=p5){
                    if(*pomocni++==broj) flag=false;
                }
                if(flag)*p5++=broj;
            }
        }
    }
    return p5;
}


int main(){
    std::deque<int> d;
    std::vector<int> v(100);
    int niz[100];
    std::cout<<"Uneiste elemente niza (-1 za kraj): ";
    int n,vel;
    for(int i=0;;i++){
        vel=i;
        std::cin>>n;
        if(n==-1)break;
        niz[i]=n;
    }
    std::cout<<"Uneiste elemente deka (-1 za kraj): ";
    for(int i=0;;i++){
        std::cin>>n;
        if(n==-1)break;
        d.push_back(n);
    }
    auto kraj=ZajednickiElementiBlokova(niz,niz+vel,d.begin(),d.end(),v.begin());
    int duzina=0;
    std::cout<<"Zajednicki elementi su: ";

    for (auto it = v.begin(); it != kraj; ++it) duzina++;
    v.resize(duzina);
    
    for(auto i:v)std::cout<<i<<" ";
}