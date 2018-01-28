#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::endl;
using std::cout;

// KLASA REPREZENTUJACA ULAMEK ZWYKLY
class Fraction{
	private:
		int licz;
		int mian;
	public:
		int GetLicz(){
			return licz;
		};
		int GetMian(){
			return mian;
		}
		//konstruktory
		Fraction(){
			licz=0;
			mian=1;
		}

		Fraction(int k_licznik){
			licz=k_licznik;
			mian=1;
		}

		Fraction(int k_licznik, int k_mianownik){
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

		bool operator > (Fraction const &u2) const {
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



		friend std::ostream & operator <<(std::ostream &strumien, const Fraction &ul);

};

		std::ostream & operator <<(std::ostream &strumien, const Fraction &ul){
			return strumien << "\n" << ul.licz << "\n" << "---\n" << ul.mian;
		}

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

const int tsize = 3;

// PROGRAM GLOWNY
int main(int, char**){

    srand(time(NULL));

    int minim = Clamp<int> (2,1,5);
    cout << minim << endl;

    Fraction f_min(1,5);
    Fraction ff(2,5);
    Fraction f_max(3,5);
    Fraction normal  =  Clamp<Fraction> (f_min,ff,f_max);

    cout << normal << endl;

    int tab[tsize];
    tab[0]=3;
    tab[1]=6;
    tab[2]=9;
    int tmin = 4;
    int tmax = 7;

    Clamp<int> (tab,tmin,tmax,tsize);

    for(int i=0;i<tsize;i++)
        cout << tab[i] << endl;


};

