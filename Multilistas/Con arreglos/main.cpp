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
		break;
		case 3: //Listar por edad
		break;
		case 4: //Listar por nombre
		break;
		case 5: //Listar por hobbie
		break;
		case 6: //Listar por carrera
		break;
	}
}

void menu(){
	cout<<"Digite una opción"<<endl;
	cout<<"1. Agregar persona"<<endl<<"2. Eliminar"<<"3. Listar por edad"
	<<endl<<"4. Listar por nombre"<<endl<<"5. Listar por hobbie"<<endl<<"6. Listar por carrera"
	<<endl<<"Opción: ";
	cin>>opcion;
	return opcion
}

