#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>

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

//KLASA STOSU
class Stos{
    protected:
        int tab_size;
        static const Fraction statyczny;
    public:
        Fraction *tab;
        void Push(Fraction nowy);
        Fraction Pop();
        int Size();
        Stos();
        Stos(Stos & stosik);
        ~Stos(){
            delete [] tab;
            cout << "Destruktor \n";
        };
        // OPERATOR PRZYPISANIA ELEMENTOW STOSU
        Stos & operator = (Stos &stos2){
            if(this==&stos2){
                return *this;
            }else{
                tab = new Fraction[stos2.Size()];
                tab_size = stos2.tab_size;
                for(int i=0;i<stos2.Size();i++){
                    tab[i] = stos2.tab[i];
                }
                cout <<"Operator dziala \n";
            }
        };

        // OPERATOR INDEKSOWANIA
        Fraction & operator [] (int element){
            return tab[element];
        }
        const Fraction & operator [] (int element)
            const {return tab[element];
        }

        // OPERATOR BOOL
        operator bool() const {
            return (tab_size!=0);
        }

};

// WSTAWIANIE NOWEGO ELEMENTU NA STOS
void Stos::Push(Fraction nowy){
    if(tab==NULL){
        tab = new Fraction[tab_size+1];
        tab[0] = nowy;
        tab_size = 1;
        tab[1] = NULL;
    }else{
        Fraction *tab_nowa = new Fraction[tab_size+1];
        for(int i=0;i<tab_size+1;i++){
            tab_nowa[i] = tab[i];
        }
        tab_nowa[tab_size] = nowy;
        tab = tab_nowa;
        tab_size++;
    }
}

// FUNKCJA ZWRACAJACA ROZMIAR
int Stos::Size(){
    return tab_size;
};

// STATYCZNY STALY WEKTOR
const Fraction Stos::statyczny(1,2);

// KONSTRUKTOR STOSU
Stos::Stos(){
    tab = NULL;
    tab_size = 0;
};

// KONSTRUKTOR KOPIUJACY
Stos::Stos(Stos & stosik){
    tab = new Fraction[stosik.Size()];
    tab_size = stosik.Size();

    for(int i=0;i<stosik.Size();i++){
        tab[i]=stosik.tab[i];
    }
    cout << "Konstruktor kopiujacy \n";
};

//
Fraction Stos::Pop(){
    if(tab==NULL){
        return statyczny;
    }else{
        Fraction zwracany;
        zwracany = tab[tab_size-1];
        Fraction *tab_nowa = new Fraction[tab_size];
        for(int i=0;i<tab_size-1;i++){
            tab_nowa[i] = tab[i];
        }
        tab = tab_nowa;
        tab_size = tab_size-1;
        return zwracany;
    }
}

int main(int, char**){

    srand(time(NULL));

    Stos s;

    for(int i=0; i<20; ++i)
        s.Push(Fraction((rand()%7)-3));

    std::map<Fraction, int> histogram;

    while(s)
        ++histogram[s.Pop()];

    int map_size = histogram.size();

    for(int i=0;i<map_size;i++){
        std::cout << bbbbbbbb  << ": " << bbbbbbbb  << "\n";
    };

    return 0;
};

