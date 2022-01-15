#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
typedef std::deque<std::deque<double>> Matrica;

Matrica EkspanzijaMatrice(Matrica m, int p, int q){
    Matrica nova;
    if(p<=0||q<=0) throw(std::domain_error("Nelegalni parametri"));
    for(int i=1;i<m.size();i++){
        if(m.at(i).size()!=m.at(0).size()) throw(std::domain_error("Nekorektna matrica"));
    }
    nova.resize(m.size()*p);
    for(int i=0;i<m.size();i++){
        for(int z=0;z<p;z++){
            for(int j=0;j<m.at(0).size();j++){
                for(int k=0;k<q;k++){
                    nova.at(i*p+z).push_back(m.at(i).at(j));
                }
            }
        }

    }
    return nova;
}

int main(){
    Matrica m;
    m.resize(3);
    m.at(0).push_back(3);
    m.at(0).push_back(5);
    m.at(1).push_back(4);
    m.at(1).push_back(-1);
    m.at(2).push_back(0);
    try{
        Matrica nova=EkspanzijaMatrice(m,2,4);
        for(int i=0;i<nova.size();i++){
        for(int j=0;j<nova.at(0).size();j++){
            std::cout<<nova.at(i).at(j);
        }
        std::cout<<std::endl;
    }
    }
    catch(std::domain_error e){
        std::cout<<e.what();
    }
    
}   