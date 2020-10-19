/* TP 2016/2017 (Tutorijal 4, Zadatak 5)

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
template <typename tip>
 std::vector<tip> Presjek(std::vector<tip> v1, std::vector<tip> v2){
        std::vector<tip> v;
        int brojac(1);
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                if(v1[i]==v2[j]){
                    bool postoji(false);
                    for(int k=0;k<v.size();k++){
                        if(v[k]==v1[i]) postoji=true;
                    }
                    if(postoji==false){
                        v.resize(brojac);
                        v[brojac-1]=v1[i];
                        brojac++;
                    }
                }
            }


        }
        return v;


    }
int main(){
    int n1,n2;
    std::cout << "Test za realne brojeve...\nUnesite broj elemenata prvog vektora: ";
    std::cin >> n1;
    std::vector<int> v1;
    v1.resize(n1);
    std::cout << "Unesite elemente prvog vektora: ";
    for(int i=0;i<n1;i++)
        std::cin >> v1[i];
    std::cout << "Unesite broj elemenata drugog vektora: " ;
    std::cin >> n2;
    std::vector<int> v2;
    v2.resize(n2);
    std::cout << "Unesite elemente drugog vektora: ";
    for(int i=0;i<n2;i++)
        std::cin >> v2[i];
    std::vector<int> vp(Presjek(v1,v2));
    std::cout << "Zajednicki elementi su: ";
    for(auto i:vp) std::cout<<i<<" ";
  
  
    int a1,a2;
    std::cout << "\n\nTest za stringove...\nUnesite broj elemenata prvog vektora: ";
    std::cin >> a1;
    std::vector<std::string> s1;
    s1.resize(a1);
    std::cout << "Unesite elemente prvog vektora (ENTER nakon svakog unosa): ";
    std::cin>>std::ws;
    for(int i=0;i<a1;i++){
        std::string s;
        std::getline(std::cin,s);
        s1.push_back(s);
    }
    std::cout << "Unesite broj elemenata drugog vektora: " ;
    std::cin >> a2;
    std::vector<std::string> s2;
    s2.resize(a2);
    std::cout << "Unesite elemente drugog vektora (ENTER nakon svakog unosa): ";
    std::cin>>std::ws;
    for(int i=0;i<a2;i++){
        std::string s;
        std::getline(std::cin,s);
        s2.push_back(s);
    }
    std::vector<std::string> sp(Presjek(s1,s2));
    std::cout << "Zajednicki elementi su: "<<std::endl;
    for(auto s:sp) std::cout<<s<<std::endl;
    
    
    
    return 0;

}
