#include <iostream>
#include "arbolBinario.h"
#include <windows.h>

template <class T>
void imprimir(Lista<T> *lista);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	int c=1,max,opcion;
	cout<<"Digite el numero maximo de elementos que poseera el arbol: ";
	cin>>max;
	arbolBinario <int> arbol (max);
	while(c!=0){
		system("cls");
		//menu
		cout<<endl<<"1. Insertar un elemento"<<endl<<"2. Eliminar un elemento"<<endl<<"3. Recorrido in orden"<<endl<<"4. Recorrido pre orden"<<endl<<"5. Recorrido pos orden"<<endl<<"Opcion: ";
		cin>>opcion;
		switch(opcion){
			case 1: //insertar un elemento
				if(arbol.arbolLleno()){
					cout<<"No se pueden insertar mas elementos, el arbol esta lleno"<<endl;
				}
				else{
					int elemento;
					cout<<"Digite el elemento que desea insertar: ";
					cin>>elemento;
					arbol.agregar(elemento);
				}
			break;
			case 2: //eliminar un elemento
				if(arbol.arbolVacio()){
					cout<<"No se pueden eliminar mas elementos, el arbol esta vacio"<<endl;
				}
				else{
					int elemento;
					cout<<"Digite el elemento que desea eliminar: ";
					cin>>elemento;
					arbol.eliminar(elemento);
				}
			break;
			case 3: //recorrido in orden
				if(arbol.arbolVacio()){
					cout<<"El arbol esta vacio"<<endl;
				}
				else{
					Lista<int> *lista;
					lista = arbol.recorridoInOrden();
					imprimir(lista);
					delete lista;
				}
			break;
			case 4: //recorrido pre orden
				if(arbol.arbolVacio()){
					cout<<"El arbol esta vacio"<<endl;
				}
				else{
					Lista<int> *lista;
					lista = arbol.recorridoPreOrden();
					imprimir(lista);
					delete lista;
				}
			break;
			case 5: //recorrido pos orden
				if(arbol.arbolVacio()){
					cout<<"El arbol esta vacio"<<endl;
				}
				else{
					Lista<int> *lista;
					lista = arbol.recorridoPosOrden();
					imprimir(lista);
					delete lista;
				}
			break;
			default: cout<<"Dato erroneo"<<endl;
			
		}
		cout<<"Para repetir el menu digite cualquier numero diferente de cero: ";
		cin>>c;
	}
	return 0;
}
template <class T>
void imprimir(Lista<T> *lista){
	for(int i=0;i<lista->getTam();i++){
		cout<<lista->devolverDato(i)<<" ";
	}
	cout<<endl;
}
