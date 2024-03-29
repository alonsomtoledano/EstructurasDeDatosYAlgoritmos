// Práctica 3.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "ArbolBinario.h"


int main()
{
	struct TArbolBinario *R = new TArbolBinario;
	struct NodoArbol *raiz, *izquierdo, *derecho;

	// Arbol construido de las hojas a la raíz

	cout << "Arbol R:" << endl << endl;

	inicializa(R);
	izquierdo = insertaNodo('*', insertaNodo('3', NULL, NULL), insertaNodo('2', NULL, NULL));
	derecho = insertaNodo('-', insertaNodo('5', NULL, NULL), insertaNodo('3', NULL, NULL));
	insertaRaiz(R->raiz, '+', izquierdo, derecho);
	imprimeArbol(R);
	
	cout << "\nAltura del arbol " << altura(R->raiz) << " con " << nodos(R->raiz) << " nodos" << endl;

	if (busca(R->raiz, '4') != NULL)
		cout << "El nodo 4 forma parte del arbol R " << endl;
	else
		cout << "El nodo 4 no forma parte del arbol R " << endl;
	
	if (busca(R->raiz, '2') != NULL)
		cout << "El nodo 2 forma parte del arbol R " << endl;
	else
		cout << "El nodo 2 no forma parte del arbol R " << endl;

	// Arbol construido de la raíz a las hojas
	
	cout << "\n\nArbol T:" << endl << endl;

	struct TArbolBinario *T = new TArbolBinario;
	inicializa(T);
	insertaRaiz(T->raiz, '*', NULL, NULL);
	izquierdo = insertaNodo('*', insertaNodo('4', NULL, NULL), insertaNodo('5', NULL, NULL));
	derecho = insertaNodo('+', insertaNodo('6', NULL, NULL), insertaNodo('7', NULL, NULL));
	insertaHijoIzquierdo(T->raiz, izquierdo);
	insertaHijoDerecho(T->raiz, derecho);
	imprimeArbol(T);
	
	cout << "\nAltura del arbol " << altura(T->raiz) << " con " << nodos(T->raiz) << " nodos" << endl;
	if (busca(T->raiz, '4') != NULL)
		cout << "El nodo 4 forma parte del arbol T " << endl;
	else
		cout << "El nodo 4 no forma parte del arbol T " << endl;
	if (busca(T->raiz, '8') != NULL)
		cout << "El nodo 8 forma parte del arbol T " << endl;
	else
		cout << "El nodo 8 no forma parte del arbol T " << endl;
		
    return 0;
}

