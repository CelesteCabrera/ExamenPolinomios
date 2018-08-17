#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <iostream>
#include <stdio.h>

using namespace std;

class Polinomio
{
    friend std::ostream &operator<< (std::ostream &, const Polinomio &);
    friend std::istream &operator<< (std::istream &, Polinomio &);
    friend Polinomio &operator- (Polinomio &, Polinomio &);
    friend Polinomio &operator+ (Polinomio &, Polinomio &);
    friend Polinomio &operator* (Polinomio &, Polinomio &);

public:
    int num;
    int n, m, i;
    int arrayCoeficiente[30];
    int arrayExponente[30];
    int getPolinomio();
    void setPolinomio(int, int);
    Polinomio();;
    Polinomio(int, int);
    ~Polinomio();
    void ordenar_polinomio();
    void ingresarTerminos();
    void imprimir_polinomio();
    string toString();
};

#endif // POLINOMIO_H
