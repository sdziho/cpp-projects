//TP 2016/2017: Tutorijal 8, Zadatak 4
#include <iostream>
#include <map>
#include <string>
int BrojSlova(std::string s, int index){
    int brojac(0);
    for(int i=index;i<s.length();i++){
        if(s[i]==' ') break;
        brojac++;
    }
    return brojac;
}


std::string ZamijeniPremaRjecniku(std::string s, std::map<std::string,std::string> mapa){
    std::string zamjenjeni;    
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            std::string rijec(s.substr(i,BrojSlova(s,i)));
            for(auto it=mapa.begin();it!=mapa.end();it++){
                if(rijec==it->first) rijec=it->second;
            }
            zamjenjeni+=rijec;
            i+=BrojSlova(s,i)-1;
        }
        else zamjenjeni+=' ';
    }
    return zamjenjeni;
}
int main (){
    std::map<std::string, std::string> moj_rjecnik{{"jabuka", "apple"},
    {"da", "yes"}, {"kako", "how"}, {"ne", "no"}, {"majmun", "monkey"}};
    std::cout << ZamijeniPremaRjecniku("kako da ne", moj_rjecnik);

	return 0;
}