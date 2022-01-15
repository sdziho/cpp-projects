#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>


template < typename TipElemenata >
  struct Matrica {
    char ime_matrice; // Koristi se samo u funkciji "UnesiMatricu"
    int br_redova, br_kolona;
    TipElemenata ** elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!!!
  };
template < typename TipElemenata >
  void UnistiMatricu(Matrica < TipElemenata > & mat) {
    if (!mat.elementi) return;
    for (int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
  }
template < typename TipElemenata >
  Matrica < TipElemenata > StvoriMatricu(int br_redova, int br_kolona, char ime = 0) {
    Matrica < TipElemenata > mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.ime_matrice = ime;
    mat.elementi = new TipElemenata * [br_redova] {};
    try {
      for (int i = 0; i < br_redova; i++)
        mat.elementi[i] = new TipElemenata[br_kolona];
    } catch (...) {
      UnistiMatricu(mat);
      throw;
    }
    return mat;
  }
template < typename TipElemenata >
  void UnesiMatricu(Matrica < TipElemenata > & mat) {
    for (int i = 0; i < mat.br_redova; i++)
      for (int j = 0; j < mat.br_kolona; j++) {
        std::cout << mat.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
        std::cin >> mat.elementi[i][j];
      }
  }

template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=6 , bool treba_brisati=false) {
        for(int i = 0; i < mat.br_redova; i++) {
            for(int j = 0; j < mat.br_kolona; j++)
                std::cout <<std::setprecision(preciznost)<< std::setw(sirina_ispisa) << mat.elementi[i][j];
            std::cout << std::endl;
        }
        if(treba_brisati)
            for (int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
            delete[] mat.elementi;
            //mat.elementi = nullptr;
    }
template < typename TipElemenata >
  Matrica < TipElemenata > ZbirMatrica(const Matrica < TipElemenata > & m1,
    const Matrica < TipElemenata > & m2) {
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
      throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3 = StvoriMatricu < TipElemenata > (m1.br_redova, m1.br_kolona);
    for (int i = 0; i < m1.br_redova; i++)
      for (int j = 0; j < m1.br_kolona; j++)
        m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
  }

template<typename TipElemenata>
    Matrica<TipElemenata> Iskopiraj(const Matrica<TipElemenata> &m) {
        auto kopija = StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
        for(int i=0;i<m.br_redova;i++)
            for(int j=0;j<m.br_kolona;j++)
                kopija.elementi[i][j] = m.elementi[i][j];
        return kopija;
    }

template<typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
        if(m1.br_kolona != m2.br_redova)
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
            
        auto produkt = StvoriMatricu<TipElemenata>(m1.br_redova , m2.br_kolona);
        try {
            for(int i=0;i<m1.br_redova;i++) {
                for(int j=0;j<m2.br_kolona;j++) {
                    produkt.elementi[i][j] = 0;
                    for(int k=0;k<m1.br_kolona;k++)
                        produkt.elementi[i][j]+= m1.elementi[i][k] * m2.elementi[k][j];
                }
            }
        }
        catch(...) {
            UnistiMatricu(produkt);
            throw;
        }
        return produkt;
    }
double faktorijel(int n){
    double rez=1;
    for(int i=1;i<=n;i++)rez*=i;
    return rez;
}    
template<typename TipElemenata>
    Matrica<TipElemenata> pomnoziSkalarom(const Matrica<TipElemenata> &m,double n) {
        auto rez = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
        try {
            for(int i=0;i<rez.br_redova;i++)
                for(int j=0;j<rez.br_kolona;j++)
                    rez.elementi[i][j] = m.elementi[i][j] * n;
        }
        catch(...) {
            UnistiMatricu(rez);
            throw;
        }
        return rez;
    }

template<typename TipElemenata>
    Matrica<TipElemenata> MatricniEksponencijalniPolinom(const Matrica<TipElemenata> &A, int n) {
        if(n<0) throw std::domain_error("Neispravan red");
        if(A.br_kolona != A.br_redova) throw std::domain_error("Matrica nije kvadratna");
        
        auto rezultat = StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona); 

        try {  
            for(int i=0;i<rezultat.br_redova;i++) {
                for(int j=0;j<rezultat.br_kolona;j++)
                    if(i==j)
                        rezultat.elementi[i][j] = 1;  // Odmah mnozim jedinicnu matricu sa prvim koeficijentom
                    else
                        rezultat.elementi[i][j] = 0;
            }
        }
        catch(...) {
            UnistiMatricu(rezultat);
            throw;
        }
       
        // Tvrda kopija matrice A u pomocnu matricu
        
        Matrica<TipElemenata> pomocna;
        Matrica<TipElemenata> prethodnaPomocna;  // Nakon svake dodjele,moram izbrisati prethodnu verziju...
        Matrica<TipElemenata> prethodniRezultat;    //  ...da ne bi doslo do curenja memorije
        
        // Sabiranje clanova polinoma
        try {
            for(int k=1;k<=n;k++) {
                pomocna = Iskopiraj<TipElemenata>(A); 
                prethodnaPomocna = pomocna;
                for(int j=1;j<k;j++) {
                    pomocna = ProduktMatrica<TipElemenata>(pomocna,A); // A^
                    UnistiMatricu<TipElemenata>(prethodnaPomocna);
                    prethodnaPomocna = pomocna;
                }
                pomocna = pomnoziSkalarom<TipElemenata>(pomocna,1/faktorijel(k));  // Pk * A^k
                UnistiMatricu<TipElemenata>(prethodnaPomocna);
                prethodnaPomocna = pomocna;
                prethodniRezultat = rezultat;
                rezultat = ZbirMatrica<TipElemenata>(rezultat,pomocna);                  // Novi rezultat
                UnistiMatricu<TipElemenata>(prethodniRezultat); 
                UnistiMatricu<TipElemenata>(prethodnaPomocna); 
                
            }
        }
        catch(...) {
            UnistiMatricu(prethodnaPomocna);
            UnistiMatricu(prethodniRezultat);
            UnistiMatricu(rezultat);
            throw;
        }
        return rezultat;    // rezultat polinoma
    }

int main() {
    Matrica<int> m1(StvoriMatricu<int>(3,3));
m1.elementi[0][0] = -1;
m1.elementi[0][1] = 0;
m1.elementi[0][2] = 0;
m1.elementi[1][0] = 0;
m1.elementi[1][1] = -1;
m1.elementi[1][2] = 0;
m1.elementi[2][0] = 0;
m1.elementi[2][1] = 0;
m1.elementi[2][2] = -1;
IspisiMatricu(MatricniEksponencijalniPolinom(m1,1),2,7,true);
UnistiMatricu(m1);
    return 0;
}