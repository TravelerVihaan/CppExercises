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
	public:
		double x,y,z;
		Wektor();
        Wektor(double a, double b, double c);
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
	pozycja.x=n_pozycja.x;
	pozycja.y=n_pozycja.y;
	pozycja.z=n_pozycja.z;
};

// Obiekt Materialny - funkcja zmiany predkosci
void ObiektMat::ChangeSpeed(Wektor n_speed){
	speed.x=n_speed.x;
	speed.y=n_speed.y;
	speed.z=n_speed.z;
};

// ObiektMat: konstruktor bezparametryczny
ObiektMat::ObiektMat(){
	pozycja.x=0;
	pozycja.y=0;
	pozycja.z=0;
	speed.x=0;
	speed.y=0;
	speed.z=0;
};

// KLASA LAWKA - DZIEDZICZY OBIEKT MATERIALNY
class Lawka : public virtual ObiektMat{
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
class Taczka : public virtual ObiektMat{
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


// KLASA TACZKOLAWKI
class TaczkoLawka : public Taczka, public Lawka{
	protected:
		Dzialo *c_single;
		Dzialo *c_seria;
	public:
		TaczkoLawka(Dzialo *can1, Dzialo *can2) : Taczka(5), Lawka(/* ZAPYTAC SIE O TO!!!!! */can1->GetPozycja() , czerwony, wygodna){
			c_single = can1;
			c_seria = can2;
		}
		void Write(){
			cout << "To jest £awko-Tacz-- Taczko-£awka!\n";
		}
		void DoubleCann();
		~TaczkoLawka(){
			cout << "Udalo sie zwolnic pamiec \n";
		}
};

void TaczkoLawka::DoubleCann(){
	c_single->Wystrzel();
	c_seria->Wystrzel();
}

// PROGRAM GLOWNY
int main(int argc, char *argv[]){

	TaczkoLawka tl1(new DzialoSingle(3), new DzialoSeria(6));
	Wektor w1(9,9,9);
	tl1.ChangePozycja(w1);
	tl1.ChangePozycja(w1);
	tl1.DoubleCann();
	cout << "Pozycja taczkolawki: \n";
	cout << "x: " << tl1.GetPozycja().x << endl;
	cout << "y: " << tl1.GetPozycja().y << endl;
	cout << "z: " << tl1.GetPozycja().z << endl;

	ObiektMat *tl2 = new ObiektMat;

	delete tl2;
	return 0;
};
