// Práctica 3-2.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include "ArbolBinarioBusqueda.h"

int main()
{
	struct TArbolBinarioBusqueda *R = new TArbolBinarioBusqueda;

	cout << "Arbol R:" << endl << endl;

	inicializa(R);
	inserta(R->raiz, 8);
	inserta(R->raiz, 6);
	inserta(R->raiz, 4);
	inserta(R->raiz, 7);
	inserta(R->raiz, 5);
	inserta(R->raiz, 10);
	inserta(R->raiz, 9);
	inserta(R->raiz, 15);
	imprimeArbol(R);
	cout << "Nodos" << nodos(R->raiz);
	cout << "\nElimina min: " << eliminaMinimo(R->raiz) << endl;
	imprimeArbol(R);
	cout << "\nMinimo Recursivo: " << minimoRecursivo(R->raiz)->dato << " Minimo Iterativo: " << minimoIterativo(R->raiz)->dato << endl;
	cout << "Maximo Recursivo: " << maximoRecursivo(R->raiz)->dato << " Maximo Iterativo: " << maximoIterativo(R->raiz)->dato << endl;
	cout << "Busca 10: " << busca(R->raiz, 10)->dato << endl;


	struct TArbolBinarioBusqueda *T = new TArbolBinarioBusqueda;

	cout << "\nArbol T:" << endl << endl;

	inicializa(T);
	inserta(T->raiz, 10);
	inserta(T->raiz, 5);
	inserta(T->raiz, 14);
	inserta(T->raiz, 7);
	inserta(T->raiz, 18);
	inserta(T->raiz, 12);
	inserta(T->raiz, 15);
	imprimeArbol(T);

	cout << "\nElimina 10: \n";
	elimina(T->raiz, 10);
	imprimeArbol(T);
	
    return 0;
}