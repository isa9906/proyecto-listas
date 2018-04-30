#include <iostream>
#include "arbolBinario.h"

template <class T>
void imprimir(Lista<T> lista);

using namespace std;

int main(){
	arbolBinario<int> arbol(10);
	arbol.insertar(100);
	arbol.insertar(50);
	arbol.insertar(25);
	arbol.insertar(70);
	arbol.insertar(200);
	arbol.insertar(150);
	arbol.insertar(250);
	Lista<int> lista = arbol.recorridoInOrden();
	imprimir(lista);
}

template <class T>
void imprimir(Lista<T> lista){
	for(int i=0;i<lista.getTam();i++){
		cout<<lista.devolverDato(i)<<" ";
	}
	cout<<endl;
}
