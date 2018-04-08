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
	Lista<estud> var;
	//Creando estudiantes
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
	
	int  i;
	for(i=0;i<var.getTam();i++)
		cout<<var.devolverDato(i).cod<<" "<<var.devolverDato(i).nombre<<endl;
		
	var.eliminarInicio();
	var.eliminar_final();
	var.eliminar_posicion(3);
	
	cout<<endl<<endl;
	for(i=0;i<var.getTam();i++)
		cout<<var.devolverDato(i).cod<<" "<<var.devolverDato(i).nombre<<endl;
}


