/* 
    TP 16/17 (Tutorijal 6, Zadatak 3)
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <stdexcept>
int	**KreirajTrougao(int n){
	if(n<=0) throw std::domain_error("Broj redova mora biti pozitivan");
	int **niz_pok(nullptr);
	try{
		niz_pok=new int*[n];
		niz_pok[0]=new int[n*n];
		for(int i=1;i<n;i++){ 
			niz_pok[i]=niz_pok[i-1]+1+2*(i-1);
		}
		niz_pok[0][0]=1;
		for(int i=1;i<n;i++){
			int k(i+1);
			int brojac(1);
			for(int j=0;j<1+2*i;j++){
				if(i==j){ 
					k=2;
					niz_pok[i][j]=1; 
					continue;
				}
				niz_pok[i][j]=k;
				if(brojac<(1+2*i)/2) k--;
				else k++;
				brojac++;
			}
		}
	}
	catch(...){
		delete [] niz_pok;
		throw ;
	}
	return niz_pok;
		
}
int main (){
	try{
		int n;
		std::cout << "Koliko zelite redova: ";
		std::cin>>n;
		int **pok(KreirajTrougao(n));
		for(int i=0;i<n;i++){
			for(int j=0;j<1+2*i;j++){
				std::cout << pok[i][j]<<" ";
			}
			std::cout << std::endl;
		}
		delete[] pok[0];
		delete []pok;
	}
	catch(std::domain_error e){
		std::cout<< "Izuzetak: "<<e.what();
	}
	catch(...){
		std::cout<< "Izuzetak: Nedovoljno memorije!";
	}
	return 0;
}