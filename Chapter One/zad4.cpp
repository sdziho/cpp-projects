#include <iostream>
#include <vector>
#include <string>

int BrojSlova(std::string s, int index){
    int brojac(0);
    for(int i=index;i<s.length();i++){
        if(s.at(i)==' ') break;
        brojac++;
    }
    return brojac;
}

std::string ZamjenaRijeci(std::string s, std::vector<std::string> rijeci, std::vector<std::string> zamjena){
    for(int i=0;i<s.length();i++){
        if(s.at(i)!=' '){
            int index=i;
            for(int j=0;j<rijeci.size();j++){
                if(rijeci.at(j)==s.substr(index,BrojSlova(s,index))&&rijeci.at(j).length()==BrojSlova(s,index)){ 
                    s.erase(index,BrojSlova(s,index));
                    s.insert(index,zamjena.at(j));
                    break;
                }

            }
            i+=BrojSlova(s, index)-1;
        }
    }
    return s;
    
}

int main(){
    try {
    std::vector<std::string> vektor1 {"tko", "nitko" , "nje", "ko"};
    std::vector<std::string> vektor2 {"ko", "niko", "menitost", "tko"};
    std::cout<<ZamjenaRijeci("tko sta zna nitko nista ne zna krhko je znanje",vektor1,vektor2)<<("\n");
    }
    catch (std::domain_error e)
    {
    std::cout<<e.what();
    }

}