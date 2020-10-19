/* TP 2016/2017: Tutorijal 3, Zadatak 1

   Autotestove pisao Haris Hasic. Sva pitanja
   sugestije i prijave gresaka mozete slati na
   mail: hhasic2@etf.unsa.ba
   
*/
#include <iostream>
#include <vector>

bool suma_parna(int n){
   int suma(0);
   do{
      int cifra;
      cifra=n%10;
      suma+=cifra;
      n/=10;
   }while(n!=0);
   
   if(suma%2==0) return true;
   else return false;
}


std::vector<int> IzdvojiElemente(std::vector<int> v, bool iskaz){
   std::vector<int> parni;
   std::vector<int> neparni;
   for(int i:v){
      if(suma_parna(i))
         parni.push_back(i);
      else
         neparni.push_back(i);
         
   }
   if(iskaz) return parni;
   else return neparni;
   
}
int main (){
   int n;
   std::cout << "Koliko zelite unijeti elemenata: ";
   std::cin >> n;
   if(n<=0){
       std::cout << "Broj elemenata mora biti veci od 0!" << std::endl;
       return 0;
   }
   std::vector<int> a;
   std::cout << "Unesite elemente: ";
   for(int i=0;i<n;i++){
      int broj;
      std::cin >> broj;
      a.push_back(broj);
      
   }
   std::vector<int> b(IzdvojiElemente(a,true));
   std::vector<int> c(IzdvojiElemente(a,false));
   
   for(int i:b)
      std::cout << i << " ";
   std::cout<<std::endl;
   for(int i:c)
      std::cout<<i<<" ";
   
	return 0;
}