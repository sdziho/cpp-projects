/* TP 2016/2017 (Tutorijal 4, Zadatak 3)

   Autotestovi by Eldar Kurtic, sva pitanja, sugestije i prijave gresaka javite na 
   mail ekurtic3@etf.unsa.ba
   
   NAPOMENA: testovi ce biti konacni TEK pred pocetak tutorijala. Zbog toga pokrenite
   testove za SVE zadatke na tutorijalu, da se ne bi desila situacija da neko uradi
   zadatak ranije i prolazi mu npr. 5/5 testova a naknadno dodano jos 2 testa koja mu
   padaju!
   
*/
#include <iostream>
#include <string>
#include <vector>

void IzdvojiKrajnjeRijeci(std::vector<std::string> rijeci, std::string &prva, std::string &zadnja){
    if(rijeci.size()==0) rijeci.resize(1);
    
    prva=rijeci[0];
    zadnja=rijeci[0];
    for(int i=1;i<rijeci.size();i++){
        std::string s(rijeci[i]);
        for(int j=0;j<rijeci[i].length();j++){
            if(s[j]>='A'&&s[j]<='Z') 
                s[j]+=('a'-'A');
        }
        std::string s2(prva);
        for(int j=0;j<s2.length();j++){
            if(s2[j]>='A'&&s2[j]<='Z') 
                s2[j]+=('a'-'A');
        }
        std::string s3(zadnja);
        for(int j=0;j<s3.length();j++){
            if(s3[j]>='A'&&s3[j]<='Z') 
                s3[j]+=('a'-'A');
        }
        if(s<s2) prva=rijeci[i];
        if(s>s3) zadnja=rijeci[i];
    }
}

void ZadrziDuplikate(std::vector<std::string> &rijeci){
    std::vector<std::string> zamjena;
    int brojac(0);
    std::vector<int> bila(rijeci.size(),0);
    for(int i=0;i<rijeci.size();i++){
        for(int j=0;j<rijeci.size();j++){
            if(i==j) continue;
            if(bila[j]==1)  continue;
            if(bila[i]==1)  continue;
            if(rijeci[i]==rijeci[j]){
                bila[i]=1;
                bila[j]=1;
                for(int k=j+1;k<rijeci.size();k++)
                     if(rijeci[i]==rijeci[k]) bila[k]=1;
                
                brojac++;
                zamjena.resize(brojac);
                zamjena[brojac-1]=rijeci[i];
                break;
            }
        }
    }
    rijeci.resize(zamjena.size());
    for(int i=0;i<zamjena.size();i++){
        rijeci[i]=zamjena[i];
    }

}
int main(){
    int n;
    std::string prva,zadnja;
    std::cout << "Koliko zelite unijeti rijeci: " ;
    std::cin >> n;
    std::vector<std::string> v;
    v.resize(n);
    std::cout << "Unesite rijeci: " ;
    for(int i=0;i<n;i++)
        std::cin >> v[i];
    IzdvojiKrajnjeRijeci(v,prva,zadnja);
    std::cout << "Prva rijec po abecednom poretku je: " << prva<< std::endl;
    std::cout << "Posljednja rijec po abecednom poretku je: " << zadnja<< std::endl;
    ZadrziDuplikate(v);
    std::cout << "Rijeci koje se ponavljaju su: ";
    for(auto x:v){
        std::cout << x <<" ";
    }
    return 0;
}
