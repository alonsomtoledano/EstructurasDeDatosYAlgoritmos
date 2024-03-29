// Práctica 2.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include "Lista.h"

int main()
{
	TLista *lista1 = new TLista;
	TLista *lista2 = new TLista;
	TLista *lista3 = new TLista;

	inicializa(lista1);
	inicializa(lista2);
	inicializa(lista3);

	insertaInicio(lista1, 2);
	insertaOrdenado(lista1, 1);

	insertaInicio(lista2, 3);
	insertaOrdenado(lista2, 4);

	cout << "Lista 1: " << endl;
	imprime(lista1);

	cout << "Lista 2: " << endl;
	imprime(lista2);

	concatena(lista1, lista2, lista3);

	cout << "Lista 3: " << endl;
	imprime(lista3);

    return 0;
}

