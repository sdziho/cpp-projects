#include <iostream>
#include <vector>
#include <array>

typedef std::vector<std::vector<double>> Matrica;

std::array<int, 4> RasponMatrice(Matrica m){
    int i_min=0, i_max=0;
    int j_min=0, j_max=0;
    for(int j=0;j<m.at(0).size();j++){
        bool flag=true;
        
        for(int i=0;i<m.size();i++){
            if(m.at(i).at(j)!=0){
                flag=false;
                break;
            }
        }
        if(flag) j_min++;
        
        else break;
        
        
    }
    for(int j=m.at(0).size()-1;j>=0;j--){
            bool flag=true;
            for(int i=0;i<m.size();i++){
                if(m.at(i).at(j)!=0){
                    flag=false;
                    break;
                }
            }
            
            if(flag) j_max++;
            else break;
    }
    
    for(int i=0;i<m.size();i++){
        bool flag=true;
        
        for(int j=0;j<m.at(0).size();j++){
            if(m.at(i).at(j)!=0){
                flag=false;
                break;
            }
        }
        if(flag) i_min++;
        else break;
    }
    for(int i=m.size()-1;i>=0;i--){
            bool flag=true;
            for(int j=0;j<m.at(0).size();j++){
                if(m.at(i).at(j)!=0){
                    flag=false;
                    break;
                }
            }

            if(flag) i_max++;
            else break;
    }

    int var1=m.size()-i_max;
    int var2=m.at(0).size()-j_max;
    std::array<int, 4> a={i_min+1,j_min+1,var1,var2};
                        //2 2 3 5   
    return a;

}



int main(){
  std::vector<std::vector<double>> v{
        {
            0,0,0,0,0,0,0
        },
        {
            0,0,0,0,0,0,0
        },
        {
            0,0,0,0,0,0,0
        },
        {
            0,0,0,0,0,0,0
        },
        {
            0,0,0,0,0,0,0
        },
        {
            0,0,0,0,0,0,0
        },
        {
            -1e-8,0,0,0,0,0,0
        }
        };

        try
        {
            std::array<int, 4> rezultat = RasponMatrice(v);

            for (int i{};i<4;i++)
                std::cout<<rezultat.at(i)<<" ";

        }
        catch(std::domain_error e)
        {
            std::cout<<e.what();
        }
    return 0;
}