#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <math.h>

using namespace std;

class Vector{
    private:
        double x,y,z;
    public:
        double How_long();
        Vector();
        Vector(double a, double b, double c);
        double GetX();
        double GetY();
        double GetZ();
        Vector Add(Vector *wektor2);
        Vector Minus(Vector *wektor2);
};

double Vector::GetX(){
        return x;
};

double Vector::GetY(){
        return y;
};

double Vector::GetZ(){
        return z;
};

Vector::Vector(){
    x=0;
    y=0;
    z=0;
};

double Vector::How_long(){
    double wynik;
    wynik=sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
    return wynik;
    }

Vector::Vector(double a, double b, double c){
    x=a;
    y=b;
    z=c;
}

Vector Vector::Add(Vector * wektor2){
    double xx,yy,zz;
    xx=this->x+wektor2->x;
    yy=this->y+wektor2->y;
    zz=this->z+wektor2->z;
    Vector wynik(xx,yy,zz);
    return wynik;
}

Vector Vector::Minus(Vector * wektor2){
    double xx,yy,zz;
    xx=this->x+wektor2->x;
    yy=this->y+wektor2->y;
    zz=this->z+wektor2->z;
    Vector wynik(xx,yy,zz);
    return wynik;
}

double a, b, c;
double x1,x2, dlugosc1, dlugosc2;

int main(){
    Vector *Vector_no1 = new Vector();
    Vector *Vector_no2 = new Vector(3.5 , 6.84 , 4.22);

    Vector Add_Result = Vector_no1->Add(Vector_no2);
    x1=Add_Result.GetX();
    cout << x1;
    Vector Minus_Result = Vector_no2->Minus(Vector_no1);
    x2=Minus_Result.GetX();

    dlugosc1=Vector_no2->How_long();
    dlugosc2=Minus_Result.How_long();

    cout << "Dlugosc wektora nr 2 to: " << dlugosc1 << endl;
    cout << "Dlugosc wektora powstalego z odejmowania wektorow nr 2 i 1 to:" << dlugosc2 << endl;

return 0;
};
