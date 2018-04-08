#include <iostream>
#include <string>
#include "Lista.h"

struct estud{
	long long cod;
	char *nombre;
};


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	//Variables
	int  i;
	Lista<estud> var;
	Lista<int> varInt;
	Lista<float> varFloat;
	//Lista de estudiantes
	cout<<"Lista de estudiantes";
	estud estud1;
	estud1.cod = 20161020029;
	estud1.nombre = "Andres Arias";
	estud estud2;
	estud2.cod = 20161020014;
	estud2.nombre = "Isabel Perez";
	estud estud3;
	estud3.cod = 20161020031;
	estud3.nombre = "Sebatian Mora";
	estud estud4;
	estud4.cod = 20161020058;
	estud4.nombre = "Felipe Renteria";
	estud estud5;
	estud5.cod = 20161020017;
	estud5.nombre = "Estefania Garcia";
	estud estud6;
	estud6.cod = 20161020067;
	estud6.nombre = "Cristian Mora";

	var.anadir_inicio(estud4);
	var.anadir_final(estud1);
	var.anadir_posicion(estud6,2);
	var.anadir_inicio(estud2);
	var.anadir_posicion(estud3,4);
	var.anadir_posicion(estud5,6);
	var.eliminarInicio();
	var.eliminar_final();
	var.eliminar_posicion(3);
	
	cout<<endl<<endl;
	for(i=0;i<var.getTam();i++)
		cout<<var.devolverDato(i).cod<<" "<<var.devolverDato(i).nombre<<endl;
	
	//Lista de enteros
	cout<<endl<<endl;
	cout<<"LISTA DE ENTEROS";
	cout<<endl<<endl;
	varInt.anadir_inicio(90);
	varInt.anadir_final(78);
	varInt.anadir_posicion(80,2);
	varInt.eliminar_posicion(varInt.getTam()/2); //Nueva
	varInt.anadir_inicio(0);
	varInt.anadir_posicion(14,4);
	varInt.anadir_posicion(35,6);
	varInt.eliminar_final();  //Nueva
	varInt.anadir_final(87);  //Nueva
	varInt.eliminarInicio();
	varInt.eliminar_final();
	varInt.eliminar_posicion(3);
	
	//Imprimiendo lista
	for(i=0;i<varInt.getTam();i++)
		cout<<varInt.devolverDato(i)<<endl;
	cout<<endl<<endl;
	
	//Lista de flotantes
	cout<<endl<<endl;
	cout<<"LISTA DE FLOTANTES";
	cout<<endl<<endl;
	varFloat.anadir_inicio(90.8);
	varFloat.anadir_final(78.06);
	varFloat.anadir_posicion(80.7,2);
	varFloat.eliminar_posicion(varFloat.getTam()/2); //Nueva
	varFloat.anadir_inicio(0.08);
	varFloat.anadir_posicion(14.32,4);
	varFloat.anadir_posicion(35.097,6);
	varFloat.eliminar_final(); //Nueva
	varFloat.anadir_final(87.123); //Nueva
	varFloat.eliminarInicio();
	varFloat.eliminar_final();
	varFloat.eliminar_posicion(3);
	
	//Imprimiendo lista
	for(i=0;i<varFloat.getTam();i++)
		cout<<varFloat.devolverDato(i)<<endl;
	cout<<endl<<endl;
}



