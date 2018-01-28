#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

enum Kolor {czerwony, bialy, czarny, pomaranczowy, fioletowy, szary};
enum Komfort {niewygodna, wygodna, najwygodniejsza};

// KLASA WEKTOR
class Wektor{
	protected:
		double x,y,z;
	public:
		Wektor();
        Wektor(double a, double b, double c);
		double GetX(){return x;}
		double GetY(){return y;}
		double GetZ(){return z;}
		void ChangeX(double new_x){
			x=new_x;
		};
		void ChangeY(double new_y){
			y=new_y;
		};
		void ChangeZ(double new_z){
			z=new_z;
		};
};

//Wektor - konstruktor bezparametryczny
Wektor::Wektor(){
    x=0;
    y=0;
    z=0;
};

//Wektor - konstruktor parametryczny
Wektor::Wektor(double a, double b, double c){
    x=a;
    y=b;
    z=c;
};

// KLASA OBIEKT MATERIALNY
class ObiektMat{
	protected:
		Wektor pozycja;
		Wektor speed;
	public:
		Wektor GetPozycja(){
			return pozycja;
		};
		Wektor GetSpeed(){
			return speed;
		};
		void ChangePozycja(Wektor n_pozycja);
		void ChangeSpeed(Wektor n_speed);
		// wirtualna metoda Wypisz
		virtual void Write(){
        	cout << "to jest obiekt materialny \n";
        };
        ObiektMat();
        virtual ~ObiektMat(){
        	cout << "Obiekt materialny zostal usuniety \n";
		};
};

// Obiekt Materialny - funkcja zmiany pozycji
void ObiektMat::ChangePozycja(Wektor n_pozycja){
	pozycja.ChangeX(n_pozycja.GetX());
	pozycja.ChangeY(n_pozycja.GetY());
	pozycja.ChangeZ(n_pozycja.GetZ());
};

// Obiekt Materialny - funkcja zmiany predkosci
void ObiektMat::ChangeSpeed(Wektor n_speed){
	speed.ChangeX(n_speed.GetX());
	speed.ChangeY(n_speed.GetY());
	speed.ChangeZ(n_speed.GetZ());
};

// ObiektMat: konstruktor bezparametryczny
ObiektMat::ObiektMat(){
	pozycja.ChangeX(0);
	pozycja.ChangeY(0);
	pozycja.ChangeZ(0);
	speed.ChangeX(0);
	speed.ChangeY(0);
	speed.ChangeZ(0);
};

// KLASA LAWKA - DZIEDZICZY OBIEKT MATERIALNY
class Lawka : public ObiektMat{
	protected:
		Kolor l_kolor;
		Komfort l_komfort;
	public:
		Kolor GetKolor(){
			return l_kolor;
		};
		Komfort GetKomfort(){
			return l_komfort;
		}
		//nadpisana metoda Wypisz
		void Write(){
			cout << "To jest lawka w kolorze " << GetKolor() << " oraz o wygodzie " << GetKomfort() << endl;
		};
		Lawka(Wektor n_pozycja, Kolor n_kolor, Komfort n_komfort);
		~Lawka(){
			cout << "Lawka zostala usunieta \n";
		};
};


//Lawka - konstruktor
Lawka::Lawka(Wektor n_pozycja, enum Kolor n_kolor, enum Komfort n_komfort){
	ChangePozycja(n_pozycja);
	l_kolor=n_kolor;
	l_komfort=n_komfort;
};

// KLASA TACZKA - DZIEDZICZY OBIEKT MATERIALNY
class Taczka : public ObiektMat{
	protected:
		double t_capacity;
	public:
		double GetCapacity(){
			return t_capacity;
		};
		Taczka(double n_capacity);
		void Write(){
			cout << "To sa taczki o nosnosci: " << GetCapacity() << endl;
		};
		~Taczka(){
			cout << "Taczka zostala usunieta...\n";
		};
};

//konstruktor Taczki
Taczka::Taczka(double n_capacity){
	t_capacity=n_capacity;
};

// PROGRAM GLOWNY
int main(int argc, char *argv[]){

	Wektor w_pomocniczy(2,4,5);
	ObiektMat *obiekt_lawki = new Lawka(w_pomocniczy, czerwony, wygodna);
	obiekt_lawki->Write();
	ObiektMat *obiekt_taczki = new Taczka(6);
	obiekt_taczki->Write();
	delete obiekt_lawki;
	delete obiekt_taczki;
	return 0;
};
