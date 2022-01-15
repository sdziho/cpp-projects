#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <tuple>
#include <set>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string,int,int>>> Objekt;
                                        //poglavlje, stranca, pozicija rijeci na str

int BrojSlova(std::string s, int index){
    int brojac(0);
    for(int i=index;i<s.length();i++){
        if((s[i]<'A'&& s[i]>'9') || (s[i]>'Z'&&s[i]<'a') || s[i]>'z' || s[i]<'0') break;
        brojac++;
    }
    return brojac;
}

Objekt KreirajIndeksPojmova(Knjiga k){
    Objekt mapa;
    int brojac(0);
    for(auto it=k.begin();it!=k.end();it++){
        for(int str=0;str<(it->second).size();str++){
            std::string s=it->second.at(str);
            for(int i=0;i<s.length();i++){
                if((s[i]<'A'&& s[i]>'9') || (s[i]>'Z'&&s[i]<'a') || s[i]>'z' || s[i]<'0') continue;
                else{
                    std::string s2(s.substr(i,BrojSlova(s,i)));
                    std::transform(s2.begin(),s2.end(),s2.begin(),::tolower);
                    mapa[s2].insert({it->first,str+1,i});
                    i+=BrojSlova(s,i)-1;
                }
            }
        }
    }

    return mapa;
}

void IspisiIndeksPojmova(Objekt mapa){
    for(auto it=mapa.begin();it!=mapa.end();it++){
        std::cout << it->first << ": ";
        int brojac(0);
        for(auto y:mapa[it->first]){
            if(brojac== (mapa[it->first]).size()-1){
                std::cout<<std::get<0>(y)<<"/"<<std::get<1>(y)<<"/"<<std::get<2>(y);
            }
            else{
                std::cout<<std::get<0>(y)<<"/"<<std::get<1>(y)<<"/"<<std::get<2>(y);
                std::cout << ", ";
            }
            brojac++;
            
        }
        std::cout<<std::endl;
    }
}

std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string s, Objekt mapa){
    if(!mapa.count(s)) throw std::logic_error("Pojam nije nadjen");
    return mapa[s];
}

int main(){
    Knjiga k;
    do{
        std::cout<<"Unesite naziv poglavlja: ";
        std::string poglavlje;
        std::getline(std::cin,poglavlje);
        if(poglavlje==".")break;
        int brojac(1);
        std::vector<std::string> v;
        do{
            std::cout<<"Unesite sadrzaj stranice "<<brojac<<": ";
            std::string s;
            std::getline(std::cin,s);
            if(s==".")break;
            v.push_back(s);
            brojac++;
        } while (1);
        
        k[poglavlje]=v;
    }while(1);
    
    Objekt mapa(KreirajIndeksPojmova(k));
    std::cout<<"Kreirani indeks pojmova:\n";
    IspisiIndeksPojmova(mapa);
    
    do{
        std::cout<<"Unesite rijec: ";
        std::string s2;
        std::getline(std::cin,s2);
        if(s2==".") break;
        try{
            for(auto y:PretraziIndeksPojmova(s2,mapa)) std::cout<<std::get<0>(y)<<"/"<<std::get<1>(y)<<"/"<<std::get<2>(y)<<" ";
        }
        catch(std::logic_error e){
            std::cout << "Unesena rijec nije nadjena!";
        }
        std::cout<<std::endl;
    }while(1);
    return 0;
}