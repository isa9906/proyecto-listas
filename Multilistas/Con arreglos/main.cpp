#include <iostream>
#include <string>
#include "multilista.h"

int menu(int opcion);
void menuEliminar(int opcion,int indice);
void menuListarCarrera(int opcion);
void menuListarHobbie(int opcion);

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int c=1,opcion=0,i,numPers=0;
	while(c!=0){
		while(!(numPers>0)){ //se valida que el número de personas sea mayor a cero
			cout<<"Digite el numero de elementos de la lista: ";
			cin>>numPers;
			if(!(numPers>0)) cout<<"Dato erróneo, digítelo de nuevo";
		}
		multilista lista (numPers,i); //Creación de multilista
		switch(menu(opcion)){
				case 1: //Agregar persona
					if(lista.estaLlena()){
						cout<<"La lista esta llena, no se pueden agregar nuevos elementos"<<endl;
					}
					else{
						//se agrega una nueva persona
					}
				break;
				case 2: // Eliminar
					if(lista.estaVacia()){
						cout<<"La lista esta vacia, no se puede eliminar ningun elemento"<<endl;
					}
					else{
						//se elimina un elemento
						menuEliminar(opcion,lista.getindice());
					}
				break;
				case 3: //Listar por edad
					if(lista.estaVacia()){
						cout<<"La lista esta vacia, no se puede enlistar ningun elemento"<<endl;
					}
					else{
						//se enlista por edad
					}
				break;
				case 4: //Listar por nombre
					if(lista.estaVacia()){
						cout<<"La lista esta vacia, no se puede enlistar ningun elemento"<<endl;
					}
					else{
						//se lista por nombre
						char **cadena = lista.listarByNombre(i);
						for(i=0;i<lista.getindice();i++){
							cout<<cadena[i]<<endl;
						}
					}
				break;
				case 5: //Listar por hobbie
					if(lista.estaVacia()){
						cout<<"La lista esta vacia, no se puede enlistar ningun elemento"<<endl;
					}
					else{
						//se enlista por hobbie
						menuListarHobbie(opcion);
					}
				break;
				case 6: //Listar por carrera
					if(lista.estaVacia()){
						cout<<"La lista esta vacia, no se puede enlistar ningun elemento"<<endl;
					}
					else{
						//se enlista por carrera
						menuListarCarrera(opcion);
					}
				break;
				default: cout<<"Dato erróneo";
		}
		cout<<"Para repetir el menu digite cualquier tecla diferente de 0: ";
		cin>>c;	
	}
	
}

int menu(int opcion){
	cout<<endl<<"Digite una opcion"<<endl;
	cout<<"1. Agregar persona"<<endl<<"2. Eliminar"<<endl<<"3. Listar por edad"
	<<endl<<"4. Listar por nombre"<<endl<<"5. Listar por hobbie"<<endl<<"6. Listar por carrera"
	<<endl<<"Opcion: ";
	cin>>opcion;
	return opcion;
}

void menuEliminar(int opcion,int indice){
	int posicion=0;
	while(!(posicion>=1 && posicion<=indice)){
		cout<<endl<<endl<<"Digite el número de lista del elemento que desea eliminar";
		cin>>posicion; //Posición que se quiere borrar
		if(!(posicion>=1 && posicion<=indice)) cout<<"Dato erróneo, la lista tiene "<<indice<<" elementos. Inténtelo de nuevo";
	}
	cout<<endl<<"Seleccione la lista de la cual desea eliminar el elemento:"<<endl<<"1. Nombre"<<endl<<"2. Carrera"
	<<endl<<"3. Hobbie"<<"4. Edad"<<endl<<"Opcion: ";
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

void menuListarCarrera(int opcion){
	cout<<endl<<"Seleccione la carrera de la cual desea enlistar las personas:"<<endl<<"1. Sistemas"<<endl<<"2. Catastral"
	<<endl<<"3. Electrónica"<<"4. Industrial"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //Se enlista por sistemas
		break;
		case 2: // Se enlista por castral
		break;
		case 3: //Se enlista por electrónica
		break;
		case 4: //Se enlista por industrial
		break;
		default: cout<<"Dato erróneo";
	}
}

void menuListarHobbie(int opcion){
	cout<<endl<<"Seleccione el hobbie del cual desea enlistar las personas:"<<endl<<"1. Natacion"<<endl<<"2. Basket"
	<<endl<<"3. Danza"<<"4. Baseball"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //Se enlista por natación
		break;
		case 2: // Se enlista por basket
		break;
		case 3: //Se enlista por danza
		break;
		case 4: //Se enlista por baseball
		break;
		default: cout<<"Dato erróneo";
	}
}


