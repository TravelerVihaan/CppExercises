#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <math.h>

using std::endl;
using std::cout;

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

		friend std::ostream & operator <<(std::ostream &strumien, const Fraction &ul);

};

		std::ostream & operator <<(std::ostream &strumien, const Fraction &ul){
			return strumien << "\n" << ul.licz << "\n" << "---\n" << ul.mian;
		}


int main(int, char**){


    Fraction a=Fraction(1, 2)+Fraction(1, 4);
    Fraction b=a-Fraction(1, 8);
    Fraction c=b*Fraction(1, 2);
    Fraction d=c/Fraction(10, 2);

    std::cout << a << "\n" << b << "\n" << c << "\n" << d << "\n";
    std::cout << -d << "\n";
    std::cout << !d << "\n";
    std::cout << !-d << "\n";
    std::cout << !-!++---!-!-Fraction(1, 10) << "\n";

    Fraction e(3, 4);
    std::cout << "wartosc poczatkowa: " << e << "\n";
    std::cout << "preinkrementacja: " << ++e << "\n";
    std::cout << "po operacji: " << e << "\n";
    std::cout << "predekrementacja: " << --e << "\n";
    std::cout << "po operacji: " << e << "\n";
    std::cout << "postinkrementacja: " << e++ << "\n";
    std::cout << "po operacji: " << e << "\n";
    std::cout << "postdekrementacja: " << e-- << "\n";
    std::cout << "po operacji: " << e << "\n";
    // Zadzia³a?
    //std::cout << a+2 << "\n";

	return 0;
};
