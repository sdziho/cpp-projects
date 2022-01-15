
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
int brojDjelioca(int n){
    int brojac(0);
    for(int i=1;i<=n;i++)brojac++;
    return brojac;
}
bool KriterijSortiranja(int x, int y){
	return brojDjelioca(x)>brojDjelioca(y);
}

void SortirajPoBrojuDjelilaca(int *p, int n){
	std::sort(p,p+n,KriterijSortiranja);

}

bool PretraziBinarno(int *p, int n, int broj){
    std::vector<int> v(p,p+n);
    std::sort(v.begin(),v.end());
    return std::binary_search(v.begin(),v.end(),broj);
}
int main(){
    int n;
    std::cout<<"Unesite broj elemenata niza: \n";
    std::cin>>n;
	int *niz(new int[n]);
    std::cout<<"Unesite elemente niza: \n";
    for(int i=0;i<n;i++){
        int element;
        std::cin>>element;
        niz[i]=element;
    }
    SortirajPoBrojuDjelilaca(niz,n);
    std::cout<<"Sortiran niz glasi: ";
    for(int i=0;i<n;i++)std::cout<<niz[i]<<" ";
    std::cout<<"\nUnesite element koji treba binarno pretraziti: ";
    int unos;
    std::cin>>unos;
    if(PretraziBinarno(niz,n,unos)) std::cout<<"Trazeni element se nalazi u nizu.";
    else std::cout<<"Trazeni element se ne nalazi u nizu.";
    delete[] niz;

}