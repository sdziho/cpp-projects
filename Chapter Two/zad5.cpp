#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstring>

int PotencijalniKrivci(char **&znakovi,std::vector<std::string> imena){
    int inicijalizovano(0);
    try{
        znakovi=new char*[imena.size()];
        for(int i=0;i<imena.size();i++){
            znakovi[i]=nullptr;
            znakovi[i]=new char[imena[i].length()+1];
            for(int j=0;j<imena[i].length();j++){
                znakovi[i][j]=imena[i][j];
                znakovi[i][j+1]='\0';
            }
            inicijalizovano++;
        }
    }
    catch(...){
        for(int i=0;i<inicijalizovano;i++) delete[] znakovi[i];
        delete[] znakovi;
        throw;
    }
    return inicijalizovano;
    
}

int OdbaciOptuzbu(char **&imena, int vel, std::string s){
    bool flag(false);
    for(int i=0;i<vel;i++){
		if(imena[i]==s){
			delete [] imena[i];
			imena[i]=nullptr;
            flag=true;
		}
	}
	if(!flag) throw std::domain_error(std::string("Osoba sa imenom ")+s+std::string(" nije bila optuzena"));
    
	int brojac(0);
	for(int i=0;i<vel;i++){
		if(imena[i]==nullptr) brojac++;
	}
	
	if(brojac>=10){
        int nova_vel(0);
		char **novi(new char*[vel-brojac]);
		for(int i=0;i<vel;i++){
			if(imena[i]!=nullptr){
				novi[nova_vel]=imena[i];
				nova_vel++;
			}
		}
		for(int i=0;i<vel;i++)delete [] imena[i];
		delete [] imena;
		return nova_vel;
	}
    return vel;
	
}

int DodajOptuzbu(char **&imena,int vel, std::string s){
	char** novi;
	char* optuzeni;
    int inicijalizovano(0);
	try{
		optuzeni=new char[s.length()+1];
		for(int i=0;i<s.length();i++) optuzeni[i]=s[i];
		optuzeni[s.length()]='\0';
		for(int i=0;i<vel;i++){
			if(imena[i]==nullptr){
				imena[i]=optuzeni;
				return vel;
			}
		}
		
		novi=new char *[vel+1];
		for(int i=0;i<vel;i++){
			//if(imena[i]==nullptr) continue;
			int velicina(strlen(imena[i]));
			novi[i]=new char[velicina+1];
            inicijalizovano++;
            int j;
			for(j=0;j<velicina;j++) novi[i][j]=imena[i][j];
			novi[i][j]='\0';
		}
		
		novi[vel]=optuzeni;
		char** p(imena);
		imena=novi;
		vel++;
		
		for(int i=0;i<vel-1;i++) delete[] p[i];
		delete [] p;
		return vel;
	}catch(...){
		for(int i=0;i<inicijalizovano;i++) delete[] novi[i];
		delete [] novi;
		throw ;
	}
	
	
}

void IzlistajOptuzbu(char **imena,int n){
	for(int i=0;i<n;i++){
		if(imena[i]==nullptr) continue;
		for(int j=0;j<strlen(imena[i]);j++) std::cout << imena[i][j];
		
		std::cout << std::endl;
	}
}
int main(){
	try{
		std::vector<std::string> v;
		int n;
		char**imena;
		std::cout << "Unesite broj ljudi koji su optuzeni za prepisivanje/prodavanje zadace:" << std::endl;
		std::cin >> n;
		v.resize(n);
		std::cin.ignore(10000,'\n');
		
		for(int i=0;i<n;i++){
			std::cout << "Unesite ime optuzenog: ";
			std::getline(std::cin,v[i]);
		}
		int vel(PotencijalniKrivci(imena,v));
		std::cout<<"Duzina spiska: "<<vel;
		std::cout<<"\nSpisak trenutno optuzenih:\n";
		IzlistajOptuzbu(imena,vel);
		std::cout<<"Uneiste ime osobe oslobodjene optuzbi: ";
		std::string novo_ime;
		std::getline(std::cin,novo_ime);
		vel=OdbaciOptuzbu(imena,vel,novo_ime);
		std::cout<<"Spisak trenutno optuzenih:\n";
		IzlistajOptuzbu(imena,vel);

		std::cout<<"Uneiste ime novog optuzenog: ";
		std::getline(std::cin,novo_ime);
		vel=DodajOptuzbu(imena,vel,novo_ime);
		std::cout<<"Spisak trenutno optuzenih:\n";
		IzlistajOptuzbu(imena,vel);
	}
	catch(std::domain_error e){
		std::cout << e.what();
	}
	catch(...){
		std::cout << "Neuspjela alokacija" << std::endl;
	}
    return 0;
}