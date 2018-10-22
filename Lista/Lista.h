#pragma once

struct NodoLista {
	int dato;
	NodoLista *siguiente;
};

struct TLista {
	NodoLista *inicio, *fin;
};

void inicializa(struct TLista *L) {
	L->inicio = NULL;
	L->fin = NULL;
}

bool vacia(struct TLista *L) {
	return (L->inicio == NULL);
}

NodoLista* inicio(struct TLista *L) {
	return L->inicio;
}

NodoLista* fin(struct TLista *L) {
	return L->fin;
}

NodoLista* busca(struct TLista *L, int v) {
	NodoLista *p = L->inicio;

	if (p != NULL)
		while (p != NULL){
			if (p->dato == v)
				break;
			else
				p = p->siguiente;
		}
	return p;
}

void insertaInicio(struct TLista *L, int v) {
	NodoLista *tmp = new NodoLista;
	tmp->dato = v;

	if (vacia(L)) {
		tmp->siguiente = NULL;
		L->inicio = tmp;
		L->fin = tmp;
	}
	else {
		tmp->siguiente = L->inicio;
		L->inicio = tmp;
	}
}

void insertaFin(struct TLista *L, int v) {
	NodoLista *tmp = new NodoLista;
	tmp->dato = v;

	if (vacia(L)) {
		tmp->siguiente = NULL;
		L->inicio = tmp;
		L->fin = tmp;
	}
	else {
		tmp->siguiente = NULL;
		L->fin->siguiente = tmp;
		L->fin = tmp;
	}
}

void insertaAntes(struct TLista *L, int v, NodoLista *p) {
	if (p != NULL) {
		if (p == L->inicio)
			insertaInicio(L, v);
		else {
			NodoLista *q = L->inicio;

			while (q->siguiente != p)
				q = q->siguiente;
			if (q->siguiente == p) {
				NodoLista *tmp = new NodoLista;
				tmp->dato = v;
				tmp->siguiente = p;
				q->siguiente = tmp;
			}
		}
	}
}

void insertaDespues(struct TLista *L, int v, NodoLista*p) {
	if (p != NULL) {
		if (p == L->fin)
			insertaFin(L, v);
		else {
			NodoLista *tmp = new NodoLista;
			tmp->dato = v;
			tmp->siguiente = p->siguiente;
			p->siguiente = tmp;
		}
	}
}

void eliminar(struct TLista *L, NodoLista *p) {
	if (p != NULL) {
		if (L->inicio == p)
			L->inicio = L->inicio->siguiente;
		else if (L->fin == p) {
			NodoLista *q = L->inicio;
			while (q->siguiente != p)
				q = q->siguiente;
			q->siguiente = NULL;
			L->fin = q;
		}
		else {
			NodoLista *q = L->inicio;
			while (q->siguiente != p)
				q = q->siguiente;
			q->siguiente = p->siguiente;
		}
		delete p;
	}
}

void elimina(struct TLista *L, int v) {
	NodoLista *p = L->inicio;
	if (p != NULL) {
		while (p != NULL) {
			if (p->dato == v)
				break;
			p = p->siguiente;
		}
		eliminar(L, p);
	}
}

void imprime(struct TLista *L) {
	NodoLista *p = L->inicio;
	if (p == NULL)
		cout << "Lista vacia" << endl;
	else {
		cout << "Lista: {";
		while (p != NULL) {
			cout << p->dato << ", ";
			p = p->siguiente;
		}
		cout << "}" << endl;
	}
}

void insertaOrdenado(struct TLista *L, int v) {
	NodoLista *p = L->inicio;
	if (vacia(L))
		insertaInicio(L, v);
	else {
		while (p != NULL) {
				if (p->dato < v)
					p = p->siguiente;
				else
					break;
		}
		if (p == NULL)
			insertaFin(L, v);
		else
			insertaAntes(L, v, p);
	}
}

void concatena(struct TLista *L1, struct TLista *L2, struct TLista *C) {
	if (vacia(L1)) {
		C->inicio = L2->inicio;
		C->fin = L2->fin;
	}
	else if (vacia(L2)) {
		C->inicio = L1->inicio;
		C->fin = L1->fin;
	}
	else {
		C->inicio = L1->inicio;
		L1->fin->siguiente = L2->inicio;
		C->fin = L2->fin;
	}
}