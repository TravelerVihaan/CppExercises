#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

#define N 10

using std::endl;
using std::cout;

// KLASA REPREZENTUJACA ULAMEK ZWYKLY - SZABLON NA LICZNIK I MIANOWNIK
template <typename T1>
class Fraction{
	private:
		T1 licz;
		T1 mian;
	public:
		T1 GetLicz(){
			return licz;
		};
		T1 GetMian(){
			return mian;
		}
		//konstruktory
		Fraction(){
			licz=0;
			mian=1;
		}

		Fraction(T1 k_licznik){
			licz=k_licznik;
			mian=1;
		}

		Fraction(T1 k_licznik, T1 k_mianownik){
			licz=k_licznik;
			mian=k_mianownik;
		}


		//operator dodawania
		Fraction operator +(const Fraction &u2){
			return Fraction(this->licz*u2.mian+u2.licz*this->mian , this->mian*u2.mian);
		}

		//operator odejmowania
		Fraction operator -(const Fraction &u2){
			return Fraction(this->licz*u2.mian-u2.licz*this->mian , this->mian*u2.mian);
		}

		//operator mnozenia
		Fraction operator *(const Fraction &u2){
			return Fraction(this->licz*u2.licz , this->mian*u2.mian);
		}
		//operator dzielenia
		Fraction operator /(const Fraction &u2){
			return Fraction(this->licz*u2.mian , this->mian*u2.licz);
		}

		//operator preinkrementacji
		Fraction & operator ++(){
			this->licz=licz+mian;
			this->mian=mian;
			return *this;
		}

        //operator postinkrementacji
		Fraction operator ++(int){
            Fraction Old = (*this);
            this->licz=licz+mian;
            this->mian=mian;
            return Old;
		}

		//operator predekrementacji
		Fraction & operator --(){
			this->licz=licz-mian;
			this->mian=mian;
			return *this;
		}

		//operator postdekrementacji
		Fraction operator --(int){
            Fraction Old = (*this);
            this->licz=licz-mian;
            this->mian=mian;
            return Old;
		}

		//operator zamiany znaku na przeciwny
		Fraction & operator -(){
			this->licz= - licz;
			this->mian= mian;
			return *this;
		}

		//operator zamieniajacy licznik z mianownikiem
		Fraction & operator !(){
			this->licz=mian;
			this->mian=licz;
			return *this;
		}

		bool operator < (Fraction const &u2) const {
		    int u1_licznik, u2_licznik;
		    u1_licznik=this->licz*u2.mian;
		    u2_licznik=u2.licz*this->mian;
            if(u1_licznik>u2_licznik){
                return false;
            }else{
                return true;
            }
		}

		bool operator > ( const Fraction &u2) const {
            int u1_licznik, u2_licznik;
		    u1_licznik=this->licz*u2.mian;
		    u2_licznik=u2.licz*this->mian;
            if(u1_licznik>u2_licznik){
                return true;
            }else{
                return false;
            }
		}

		bool operator == (const Fraction & u2){
            Fraction f1 = *this;
            Fraction f2 = u2;
            f1.licz = this->licz*u2.mian;
            f1.mian = this->mian*u2.licz;
            f2.licz = u2.licz*this->mian;
            f2.mian = u2.mian*this->licz;
            if((f1.licz == f2.licz) && (f1.mian == f2.mian)){
                return true;
            }else{
                return false;
            }
		}


        template <typename T2>
		friend std::ostream & operator <<(std::ostream &strumien, const Fraction<T2> &ul);

};
        template <typename T2>
		std::ostream & operator <<(std::ostream &strumien, const Fraction <T2> &ul){
			return strumien << "\n" << ul.licz << "\n" << "---\n" << ul.mian;
		}

//KLASA STOSU - SZABLON
template < typename TT>
class Stos{
    protected:
        int tab_size;
    public:
        TT *tab;
        // KONSTRUKTOR STOSU
        Stos(){
            tab = NULL;
            tab_size = 0;
        };
        //ZRZUCANIE ELEMENTU ZE STOSU
        TT Pop(){
            if(tab==NULL){
                return 0;
            }else{
                TT zwracany;
                zwracany = tab[tab_size-1];
                TT *tab_nowa = new TT[tab_size];
                for(int i=0;i<tab_size-1;i++){
                    tab_nowa[i] = tab[i];
                }
                tab = tab_nowa;
                tab_size = tab_size-1;
                return zwracany;
                }
        }
        // FUNKCJA ZWRACAJACA ROZMIAR
        int Size(){
            return tab_size;
        };
        // WSTAWIANIE NOWEGO ELEMENTU NA STOS
        void Push(TT nowy){
            if(tab==NULL){
                tab = new TT [tab_size+1];
                tab[0] = nowy;
                tab_size = 1;
                tab[1] = NULL;
            }else{
                TT *tab_nowa = new TT[tab_size+1];
                for(int i=0;i<tab_size+1;i++){
                    tab_nowa[i] = tab[i];
                }
            tab_nowa[tab_size] = nowy;
            tab = tab_nowa;
            tab_size++;
            }
        }
        ~Stos(){
            delete [] tab;
            cout << "Destruktor \n";
        };
        // OPERATOR PRZYPISANIA ELEMENTOW STOSU
        Stos & operator = (Stos &stos2){
            if(this==&stos2){
                return *this;
            }else{
                tab = new TT[stos2.Size()];
                tab_size = stos2.tab_size;
                for(int i=0;i<stos2.Size();i++){
                    tab[i] = stos2.tab[i];
                }
                cout <<"Operator dziala \n";
            }
        }
        // OPERATOR INDEKSOWANIA
        TT & operator [] (int element){
            return tab[element];
        }
        const TT & operator [] (int element)
            const {return tab[element];
        }

        // OPERATOR BOOL
        operator bool() const {
            return (tab_size!=0);
        }
        // KONSTRUKTOR KOPIUJACY
        Stos(Stos & stosik){
            tab = new TT[stosik.Size()];
            tab_size = stosik.Size();
            for(int i=0;i<stosik.Size();i++){
                tab[i]=stosik.tab[i];
            }
            cout << "Konstruktor kopiujacy \n";
        }
    };


// SZABLON FUNKCJI CLAMP - DLA POJEDYNCZYCH ARGUMENTOW
template < typename T1>
T1 Clamp(T1 a_min, T1 bb, T1 c_max){

    if(bb < a_min){
        return a_min;
    }else if(bb > c_max){
        return c_max;
    }else{
        return bb;
    };
}

// SZABLON FUNKCJI CLAMP - DLA TABLIC
template < typename T1>
void Clamp(T1 tab[], T1 a_min, T1 c_max, int tab_size){

    for(int i=0;i<tab_size;i++){
        if(tab[i] < a_min){
            tab[i]=a_min;
        }else if(tab[i] > c_max){
            tab[i]=c_max;
        }else{
            tab[i] = tab[i];
        }
    };
};

//SZABLON FUNKCJI LICZACEJ SREDNIA WARTOSC ELEMENTOW TABLICY
template <typename T1>
T1 Avg(T1 tab[], int tab_size){
    T1 suma=NULL;
    for(int i=0;i<tab_size;i++){
        suma=suma+tab[i];
    };
    T1 average;
    average=suma/tab_size;
    return average;
};

//FUNKCJA SORTUJACA ALGORYTMEM BABELKOWYM
template <typename T1>
void Bubblesort(T1 tab[], int tab_size){
    for(int i=0;i<tab_size;i++){
        for(int j=0;j<tab_size-1;j++){
            if(tab[j]>tab[j+1]){
                swap(tab[j],tab[j+1]);
            }
        }
    }
};

// PROGRAM GLOWNY
int main(int, char**){

    std::srand(time(NULL));

    Stos <int> Stos_int;
    int los_int;

    for(int i=0;i<N;i++){
        los_int = std::rand()%50;
        Stos_int.Push(los_int);
    };

    Stos <Fraction <int> > Stos_f;
    Fraction<int> los_frac;

    for(int i=0;i<N;i++){
        los_frac = std::rand()%6;
        Stos_f.Push(los_frac);
    }

    Stos <Fraction <char> > Stos_c;
    Fraction<char> los_fc;
    int los_licz;
    int los_mian;
    char *f_licz;
    char *f_mian;

    for(int i=0;i<N;i++){
        los_int = std::rand()%9;
        sprintf(f_licz, "%d", los_int);
        los_mian = std::rand()%9;
        sprintf(f_mian, "%d", los_mian);
    }

};

