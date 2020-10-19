/* TP 2016/2017: Tutorijal 3, Zadatak 7

   Autotestove pisao Haris Hasic. Sva pitanja
   sugestije i prijave gresaka mozete slati na
   mail: hhasic2@etf.unsa.ba
   
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<int>> Matrica;

Matrica PascalovTrougao(int n){
   if(n<0) throw std::domain_error("Broj redova ne smije biti negativan");
   Matrica m;
   m.resize(n);
   for(int i=0;i<n;i++){
      m[i].resize(i+1);
      for(int j=0;j<m[i].size();j++){
         if(j==0 || j==m[i].size()-1){
            m[i][j]=1;
            continue;
         } 
         m[i][j]=m[i-1][j]+m[i-1][j-1];
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
   int n;
   std::cout << "Unesite broj redova: "<<std::endl;
   std::cin >> n;
   try{
      Matrica m(PascalovTrougao(n));
      for(int i=0;i<n;i++){
         for(int j=0;j<m[i].size();j++)
            std::cout << std::setw(NajvecaSirina(m)+1)<<m[i][j];
         
         std::cout<<std::endl;
      }
   }catch(std::domain_error izuzetak){
      std::cout << izuzetak.what() << std::endl;
   }
	return 0;
}