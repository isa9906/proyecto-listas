#include <iostream>
#include "arbol.h"
#include <windows.h>

using namespace std;
void imprimirArbol(arbol tree, int i);
void recursiva(arbol tree, int padre,int i, x<char*> *hojas);
void gotoxy(int x,int y);
int getCurrentX();
int getCurrentY();

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
		cout<<"Siguiente: ";
		cin>>sig;
		x<char*> hoja;
		hoja.descripcion = descripcion;
		hoja.sig = sig-1;
		arboles.agregarTablaHojas(hoja);
	}
	//Tabla 2
	cout<<"TABLA 2:"<<endl;
	for(i=0;i<tam2;i++){
		int descrip;
		cout<<"Digite el dato "<<i+1<<" para la tabla 2"<<endl;
		cout<<"Descripcion: ";
		cin>>descrip;
		cout<<"Siguiente: ";
		cin>>sig;
		x <int>hoja;
		hoja.descripcion = descrip-1;
		hoja.sig = sig-1;
		arboles.agregarTablaSiguientes(hoja);
	}
	//gotoxy(0,2*tam1+2*tam2+10); //jugando con las posiciones del cursor
	imprimirArbol(arboles,i);
}

void imprimirArbol(arbol tree, int i){
	int padre = tree.getRaiz();
	x<char*> *hojas = tree.getHojas();
	cout<<hojas[tree.getRaiz()].descripcion<<endl; //Se imprime la raíz
	recursiva(tree,padre,i,hojas);
}

void recursiva(arbol tree, int padre,int i, x<char*> *hojas){
	if(hojas[padre].sig!=-1){
		Lista<int> lista = tree.getHijos(padre);
		for(i=0;i<lista.getTam();i++){
			cout<<hojas[lista.devolverDato(i)].descripcion<<" ";
		}
		//cout<<endl;
		for(i=0;i<lista.getTam();i++){
			recursiva(tree,lista.devolverDato(i),i,hojas);
		}
	}
}

void gotoxy(int x,int y){
	COORD p = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

int getCurrentX(){
	POINT pt;
	GetCursorPos(&pt);
	return pt.x;
}

int getCurrentY(){
	POINT pt;
	GetCursorPos(&pt);
	return pt.y;
}
