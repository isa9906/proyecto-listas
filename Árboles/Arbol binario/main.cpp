#include <iostream>
#include "arbolBinario.h"

template <class T>
void imprimir(Lista<T> *lista);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	Lista<int> *lista;
	arbolBinario <int> arbol (10);
	arbol.agregar(100);
	arbol.agregar(50);
	arbol.agregar(25);
	arbol.agregar(150);
	arbol.agregar(30);
	//arbol.revisar();
	arbol.eliminar(100);
	cout<<endl;
	//arbol.revisar();
	//recorrido in orden
	cout<<"RECORRIDO IN ORDEN"<<endl;
	lista = arbol.recorridoInOrden();
	imprimir(lista);
	//recorrido pre orden
	cout<<"RECORRIDO PRE ORDEN"<<endl;
	lista = arbol.recorridoPreOrden();
	imprimir(lista);
	return 0;
}

template <class T>
void imprimir(Lista<T> *lista){
	for(int i=0;i<lista->getTam();i++){
		cout<<lista->devolverDato(i)<<" ";
	}
	cout<<endl;
}
