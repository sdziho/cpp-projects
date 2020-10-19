/* TP 2016/2017: Tutorijal 3, Zadatak 6

   Autotestove pisao Haris Hasic. Sva pitanja
   sugestije i prijave gresaka mozete slati na
   mail: hhasic2@etf.unsa.ba
   
*/
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<int>> Matrica;

Matrica KroneckerovProizvod(std::vector<int> a, std::vector<int> b){
   Matrica m;
   m.resize(a.size());
   for(int i=0;i<m.size();i++) m[i].resize(b.size());
   for(int i=0;i<a.size();i++){
      for(int j=0;j<b.size();j++){
         m[i][j]=a[i]*b[j];
      }
   }
   return m;
}
int NajvecaSirina(Matrica m){
   int max(0);
   for(int i=0;i<m.size();i++){
      for(int j=0;j<m[i].size();j++){
         int brojac=0;
         if(m[i][j]<0){
            m[i][j]*=(-1);
            brojac=1;
         }
         do{
            m[i][j]/=10;
            brojac++;
         }while(m[i][j]!=0);
         if(brojac>max) max=brojac;
      }
   }
   return max;
}
int main ()
{
   int n1,n2;
   std::cout << "Unesite broj elemenata prvog vektora: ";
   std::cin >> n1;
   std::cout << "Unesite elemente prvog vektora: ";
   std::vector<int> a;
   for(int i=0;i<n1;i++){
      int broj;
      std::cin >> broj;
      a.push_back(broj);
   }
   std::cout << "Unesite broj elemenata drugog vektora: ";
   std::cin >> n2;
   std::cout << "Unesite elemente drugog vektora: ";
   std::vector<int> b;
   for(int i=0;i<n2;i++){
      int broj;
      std::cin >> broj;
      b.push_back(broj);
   }
   std::cout << std::endl;
   Matrica m(KroneckerovProizvod(a,b));
   for(int i=0;i<a.size();i++){
      for(int j=0;j<b.size();j++){
         std::cout << std::setw(NajvecaSirina(m)+1) << m[i][j];
      }
      std::cout<<std::endl;
   }
	return 0;
}