#include <iostream>
#include <string>
#include "multilista.h"


using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	switch(menu()){
		case 1: //Agregar persona
		break;
		case 2: // Eliminar
			menuEliminar();
		break;
		case 3: //Listar por edad
		break;
		case 4: //Listar por nombre
		break;
		case 5: //Listar por hobbie
		break;
		case 6: //Listar por carrera
		break;
		default: cout<<"Dato erróneo";
}

int menu(){
	cout<<"Digite una opción"<<endl;
	cout<<"1. Agregar persona"<<endl<<"2. Eliminar"<<"3. Listar por edad"
	<<endl<<"4. Listar por nombre"<<endl<<"5. Listar por hobbie"<<endl<<"6. Listar por carrera"
	<<endl<<"Opción: ";
	cin>>opcion;
	return opcion
}

void menuEliminar(){
	int posicion=0;
	int opcion=0;
	while(!(posicion>=1 && posicion<=tam)){
		cout<<endl<<endl<<"Digite el número de lista del elemento que desea eliminar";
		cin>>posicion;
		if(!(posicion>=1 && posicion<=tam)) cout<<"Dato erróneo. Inténtelo de nuevo";
	}
	cout<<endl<<"Seleccione la lista de la cual desea eliminar el elemento:"<<endl<<"1. Nombre"<<endl<<"2. Carrera"
	<<endl<<"3. Hobbie"<<"4. Edad"<<endl<<"Opción: ";
	cin>>opcion;
	switch(opcion){
		case 1: //Eliminar de la lista nombre
		break;
		case 2: // Eliminar de la lista carrea
		break;
		case 3: //Eliminar de la lista hobbie
		break;
		case 4: //Eliminar de la lista edad
		break;
		default: cout<<"Dato erróneo";
	}
	
}

