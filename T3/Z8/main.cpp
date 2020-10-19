/* TP 2016/2017: Tutorijal 3, Zadatak 8

   Autotestove pisao Haris Hasic. Sva pitanja
   sugestije i prijave gresaka mozete slati na
   mail: hhasic2@etf.unsa.ba
   
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

int BrojSlova(std::string s, int index){
   int brojac(0);
   for(int i=index;i<s.length();i++){
      if(s[i]==' ') break;
      brojac++;
   }
   return brojac;
}
std::string IzdvojiRijec(std::string s, int n){
   int brojac(1);
   for(int i=0;i<s.length();i++){
      if(s[i]!=' '){
         if(brojac==n) return s.substr(i,BrojSlova(s,i));
         while(s[i]!=' ') i++;
         brojac++;
      }
   }
    
   throw std::range_error("IZUZETAK: Pogresan redni broj rijeci!");
}
int main (){
   int n;
   std::cout << "Unesite redni broj rijeci: ";
   std::cin >> n;
   std::string recenica;
   std::cin.ignore(10000, '\n');
   std::cout << "Unesite recenicu: ";
   std::getline(std::cin,recenica);
   try{
      std::cout << "Rijec na poziciji " <<n<<" je "<<IzdvojiRijec(recenica,n);
   }
   catch(std::range_error izuzetak){
      std::cout << izuzetak.what() << std::endl;
   }
	return 0;
}