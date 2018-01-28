#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>

using namespace std;

class Ulamek{
private:
    int licznik;
    int mianownik;
public:
    int PobierzLicznik();
    int PobierzMianownik();
    Ulamek Dodawanie(Ulamek *ulamek2);
    Ulamek Odejmowanie(Ulamek *ulamek2);
    Ulamek Mnozenie(Ulamek *ulamek2);
    Ulamek();
    Ulamek(int licznikk);
    Ulamek(int licznikk, int mianownikk);
};

int Ulamek::PobierzLicznik(){
	return licznik;
};

int Ulamek::PobierzMianownik(){
	return mianownik;
};

Ulamek::Ulamek(){
	licznik=0;
	mianownik=1;
};

Ulamek::Ulamek(int licznikk){
	licznik=licznikk;
	mianownik=1;
};

Ulamek::Ulamek(int licznikk, int mianownikk){
	licznik=licznikk;
	mianownik=mianownikk;
};

Ulamek Ulamek::Mnozenie(Ulamek *ulamek2){
	int wyn_licznik;
	int wyn_mianownik;
	wyn_licznik=this->licznik*ulamek2->PobierzLicznik();
	wyn_mianownik=this->mianownik*ulamek2->PobierzMianownik();
	Ulamek wynik(wyn_licznik,wyn_mianownik);
	return wynik;
};

Ulamek Ulamek::Dodawanie(Ulamek *ulamek2){
	int nww;
	int m1, m2;
	int iloczyn;
	int wyn_licznik, wyn_mianownik;
	m1=this->mianownik;
	m2=ulamek2->PobierzMianownik();
	iloczyn=m1*m2;
	do{
		if(m1>m2){
			m1=m1-m2;
		}else{
			m2=m2-m1;
		}
	}while(m1!=m2);
	nww=iloczyn/m1;
	wyn_mianownik=nww;
	wyn_licznik=this->licznik*(nww/this->mianownik)+ulamek2->PobierzLicznik()*(nww/ulamek2->PobierzMianownik());
	Ulamek wynik(wyn_licznik,wyn_mianownik);
	return wynik;
};

Ulamek Ulamek::Odejmowanie(Ulamek *ulamek2){
	int nww;
	int m1, m2;
	int iloczyn;
	int wyn_licznik, wyn_mianownik;
	m1=this->mianownik;
	m2=ulamek2->PobierzMianownik();
	iloczyn=m1*m2;
	do{
		if(m1>m2){
			m1=m1-m2;
		}else{
			m2=m2-m1;
		}
	}while(m1!=m2);
	nww=iloczyn/m1;
	wyn_mianownik=nww;
	wyn_licznik=this->licznik*(nww/this->mianownik)-ulamek2->PobierzLicznik()*(nww/ulamek2->PobierzMianownik());
	Ulamek wynik(wyn_licznik,wyn_mianownik);
	return wynik;
};


int main(){
    Ulamek *Ulamek_1 = new Ulamek();
    Ulamek *Ulamek_2 = new Ulamek(3);
    Ulamek *Ulamek_3 = new Ulamek(4,7);

    cout << "Licznik ulamka 2-go to: " << Ulamek_2->PobierzLicznik() << endl;
    cout << "Mianownik ulamka 2-go to: " << Ulamek_2->PobierzMianownik() << endl;

    Ulamek Wynik_dod = Ulamek_2->Dodawanie(Ulamek_3);
    cout << "Wynik dodawania ulamka 2 i 3 to: " << Wynik_dod.PobierzLicznik() << "/" << Wynik_dod.PobierzMianownik() << endl;
    Ulamek Wynik_odej = Ulamek_2->Odejmowanie(Ulamek_3);
    cout << "Wynik odejmowania ulamka 2 i 3 to: " << Wynik_odej.PobierzLicznik() << "/" << Wynik_odej.PobierzMianownik() << endl;
    Ulamek Wynik_mn = Ulamek_2->Mnozenie(Ulamek_3);
    cout << "Wynik mnozenia ulamka 2 i 3 to: " << Wynik_mn.PobierzLicznik() << "/" << Wynik_mn.PobierzMianownik() << endl;
return 0;
};
