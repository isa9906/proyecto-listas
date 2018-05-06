#include <iostream>
#include "colaPrioritaria.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void menu (colaPrioritaria *cola);
void menuinsertar(colaPrioritaria *cola);
void menuatender(colaPrioritaria *cola);
using namespace std;
int main(int argc, char** argv) {
	int tam;
	cout<< "Ingrese el tamaño del arreglo: ";
	cin>> tam;
	colaPrioritaria *cola; // se hizo apuntador para que cambien los valores
	cola = new colaPrioritaria (tam);
	int mas;
	do{
		cout<<"ESTE PROGRAMA NO ADMITE ESPACIOS PARA CADENAS DE TEXTO"<<endl;
		menu(cola);
		cout<<endl<<"Revisando la cola: "<<endl<<endl;
		cola->revisar();
		cout<<endl<<"Revisada"<<endl;
		cout<<"Si desea algo mas digite un numero distinto a 0, sino digite 0: ";
		cin>>mas;
		system("cls");
	}while (mas!=0);
	return 0;
}


void menu (colaPrioritaria *cola){
	int eleccion=0;		
			cout<< "1. Para ingresar dato"<<endl;
			cout<< "2. Para atender"<<endl<<"Opcion: ";
			cin>>eleccion;
			switch(eleccion){
				case 1:
					if (cola->colallena()){
						cout<<"La cola se encuentra llena";
					}
					else{
						menuinsertar(cola);
					}
					
				break;
				case 2:
					if(cola->colavacia()){
						cout<<"La cola se encuentra vacia";
					}
					else{
						menuatender(cola);
					}
				break;
			}		
}

void menuinsertar(colaPrioritaria *cola){
	int prioridad;
	string info;
	cout<< "Ingrese informacion: ";
	cin>>info;
	cout<<"Ingrese prioridad: ";
	cin>>prioridad;
	cola->insertar(info,prioridad);
	cout<<"Elemento ingresado con exito"<<endl;	
}
void menuatender(colaPrioritaria *cola){
	//Aqui llama a atender
	nodo atendido = cola->atender();
	cout<<"COLA ATENDIDA: "<<endl<<"Informacion: "<<atendido.info<<endl<<"Prioridad: "<<atendido.prioridad<<endl;	
}


