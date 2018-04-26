#include <iostream>
#include "arbol.h"

using namespace std;
void imprimirArbol(arbol tree, int i);
void recursiva(arbol tree, int padre,int i, x *hojas);

const size_t BUFFER_SIZE = 1024;

int main(){
	char *descripcion;
	int tam1,tam2,i,sig,rais;
	cout<<"ARBOLES"<<endl;
	cout<<"Digite el tamaño de la primera tabla: ";
	cin>>tam1;
	cout<<"Digite el tamaño de la segundo tabla: ";
	cin>>tam2;
	cout<<"Digite la posición en donde se encuentra la raíz (las posiciones se cuentan desde 1): ";
	cin>>rais;
	arbol arboles(tam1,tam2,rais-1);
	//Tabla 1
	cout<<"TABLA 1:"<<endl;
	for(i=0;i<tam1;i++){
		cout<<"Digite el dato "<<i+1<<" para la tabla 1"<<endl;
		descripcion = new char[BUFFER_SIZE];
		cout<<"Descripcion: ";
		cin>>descripcion;
		cout<<"Siguiente; ";
		cin>>sig;
		x hoja;
		hoja.descripcion = descripcion;
		hoja.sig = sig-1;
		arboles.agregarTablaHojas(hoja);
	}
	//Tabla 2
	cout<<"TABLA 2:"<<endl;
	for(i=0;i<tam2;i++){
		cout<<"Digite el dato "<<i+1<<" para la tabla 2"<<endl;
		descripcion = new char[BUFFER_SIZE];
		cout<<"Descripcion: ";
		cin>>descripcion;
		cout<<"Siguiente; ";
		cin>>sig;
		x hoja;
		hoja.descripcion = descripcion;
		hoja.sig = sig-1;
		arboles.agregarTablaSiguientes(hoja);
	}
	imprimirArbol(arboles,i);
}

void imprimirArbol(arbol tree, int i){
	int padre = tree.getRaiz();
	x *hojas = tree.getHojas();
	cout<<hojas[tree.getRaiz()].descripcion; //Se imprime la raíz
	recursiva(tree,padre,i,hojas);
}

void recursiva(arbol tree, int padre,int i, x *hojas){
	Lista<int> lista = tree.getHijos(padre);
	while(!lista.lista_vacia()){
		for(i=0;i<lista.getTam();i++){
			cout<<hojas[lista.devolverDato(i)].descripcion<<" ";
		}
		cout<<"endl";
		for(i=0;i<lista.getTam();i++){
			recursiva(tree,lista.devolverDato(i),i,hojas);
		}
	}
}
