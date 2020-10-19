/* TP 2016/2017: Tutorijal 3, Zadatak 3

   Autotestove pisao Haris Hasic. Sva pitanja
   sugestije i prijave gresaka mozete slati na
   mail: hhasic2@etf.unsa.ba
   
*/
#include <deque>
#include <iostream>

bool suma_parna(long int n){
   long int suma(0);
   do{
      long int cifra;
      cifra=n%10;
      suma+=cifra;
      n/=10;
   }while(n!=0);
   
   if(suma%2==0) return true;
   else return false;
}


std::deque<int> IzdvojiElemente(std::deque<int> v, bool iskaz){
   std::deque<int> parni;
   std::deque<int> neparni;
   for(int i=v.size()-1;i>=0;i--){
      if(suma_parna(v[i]))
         parni.push_front(v[i]);
      else
         neparni.push_front(v[i]);
         
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
   std::deque<int> a;
   a.resize(n);
   std::cout << "Unesite elemente: ";
   for(int i=0;i<n;i++){
      int broj;
      std::cin >> broj;
      a[i]=broj;
      
   }
   std::deque<int> b(IzdvojiElemente(a,true));
   std::deque<int> c(IzdvojiElemente(a,false));
   
   for(int i=0;i<b.size();i++){
      if(i!=b.size()-1)
         std::cout << b[i] << ",";
      else
         std::cout << b[i];
   }
   std::cout<<std::endl;
   for(int i=0;i<c.size();i++){
      if(i!=c.size()-1)
         std::cout << c[i] << ",";
      else
         std::cout << c[i];
   }
   
	return 0;
}