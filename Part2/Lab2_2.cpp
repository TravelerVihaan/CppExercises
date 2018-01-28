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

// KLASA OBIEKT STRZELAJACY
class ObiektStrzel{
	public:
		virtual void Wystrzel()=0;
};

// KLASA DZIALO - DZIEDZICZY OBIEKT STRZELAJACY I OBIEKT MATERIALNY
class Dzialo : public ObiektStrzel, public ObiektMat{
	protected:
		double moc;
	public:
		void Write(){
			cout << "To jest dzialo strzelajace z moca: " << moc << endl;
		};
		Dzialo(double n_moc);
		Dzialo();
		~Dzialo(){
			cout << "Dzialo zostalo usuniete...\n";
		};
};

//Dzialo - konstruktor
Dzialo::Dzialo(double n_moc){
	moc=n_moc;
};


// KLASA DZIALA STRZELAJACEGO POJEDYNCZO
class DzialoSingle : public Dzialo{
	public:
		DzialoSingle(double n_moc) : Dzialo(n_moc){}
		void Write(){
			Dzialo::Write();
			cout << "To jest dzialo strzelajace pojedynczym pociskiem.\n";
		};
		void Wystrzel(){
			cout <<"Bzzzt!\n";
		}
		~DzialoSingle(){
			cout << "Udalo sie usunac dzialo strzelajace pojedynczo\n";
		}
};


// KLASA DZIALA STRZELAJACEGO SERIA
class DzialoSeria : public Dzialo{
	public:
		DzialoSeria(double n_moc) : Dzialo(n_moc){}
		void Write(){
			Dzialo::Write();
			cout << "To jest dzialo strzelajace seriami.\n";
		};
		void Wystrzel(){
			int ilosc;
			cout << "Ile pociskow ma wystrzelic to dzialo? \n";
			cin >> ilosc;
			for(int i=0;i<ilosc;i++)
				cout << "Bzzzt!\n";
		};
		~DzialoSeria(){
			cout << "Udalo sie usunac dzialo strzelajace seriami\n";
		}
};

// PROGRAM GLOWNY
int main(int argc, char *argv[]){

	DzialoSeria *dzialko = new DzialoSeria(5.23);
	dzialko->Wystrzel();
	dzialko->Write();
	DzialoSingle *dzialko2 = new DzialoSingle(6.12);
	dzialko2->Wystrzel();
	dzialko2->Write();

	delete dzialko;
	delete dzialko2;

	return 0;
};
