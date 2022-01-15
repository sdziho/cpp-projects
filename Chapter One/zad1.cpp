#include <iostream>
#include <vector>
enum class Kriterij {Veca, Manja, Jednaka};

int ProizvodBrojeva(int n){
    int proizvod(1);
    //1234
    while(n!=0){
        int cifra=n%10; //4     3
        proizvod*=cifra; //1*4=4    4*3=12
        n=n/10; //n=1234/10=123     123/10=12
    }
    return proizvod;
}
                        //1234        2           Veca
std::vector<int> IBSZMU(std::vector<int> v, int broj, Kriterij k){
    std::vector<int> novi; //stavljamo brojeve koji zadovolajvaju uslov         prazan vektor
    if(k==Kriterij::Veca){ //true
        for(int i=0;i<v.size();i++){ //i=1234
            int brojac=0;
            int pom=v.at(i);
            while(pom>=10){ //50   0
                pom=ProizvodBrojeva(pom);//pom=50   pom=0
                brojac++;//1 2
            }
            if(brojac>broj) //1234
                novi.push_back(v.at(i));//1234
        }
    }
    else if(k==Kriterij::Manja){
        for(int i=0;i<v.size();i++){ //i=1234
            int brojac=0;
            int pom=v.at(i);
            while(pom>=10){ //50   0
                pom=ProizvodBrojeva(pom);//pom=50   pom=0
                brojac++;//1 2
            }
            if(brojac<broj) //1234
                novi.push_back(v.at(i));//1234
        }
    }
    else if(k==Kriterij::Jednaka){
        for(int i=0;i<v.size();i++){ //i=1234
            int brojac=0;
            int pom=v.at(i);
            while(pom>=10){ //50   0
                pom=ProizvodBrojeva(pom);//pom=50   pom=0
                brojac++;//1 2
            }
            if(brojac==broj) //1234
                novi.push_back(v.at(i));//1234
        }
    }
    return novi;
}


int main(){
    std::vector<int> v;
    v.push_back(6788);
    Kriterij nova= Kriterij::Manja;
    std::vector<int> izbacene_vrijednosti=IBSZMU(v,4,nova);
    std::cout<<izbacene_vrijednosti.at(0);
}