#include <iostream>
#include <string>
#include "Lista.h"

struct estud{
	long long cod;
	char *nombre;
};

using namespace std;

//plantilla para imprimir la lista
template <class T>
void imprimir (Lista <T> var){
	int i;
	for(i=0;i<var.getTam();i++)
		cout<<var.devolverDato(i).cod<<" "<<var.devolverDato(i).nombre<<endl;
			cout<<endl<<endl;
}
template <class T>
void imprimir2 (Lista <T> var){
	int i;
		for(i=0;i<var.getTam();i++)
		cout<<var.devolverDato(i)<<" ";
			cout<<endl<<endl;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//Variables
	int  i;
	Lista<estud> var;
	Lista<int> varInt;
	Lista<float> varFloat;
  
//seccion de uso de listas de estructuras
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

	//añadiendo datos
	var.anadir_inicio(estud4);
	var.anadir_final(estud1);
	var.anadir_posicion(estud6,2);

	//miremos como esta la lista
	imprimir (var);
	//eliminando inicio
	var.eliminarInicio();
	//miremos como esta la lista
	imprimir (var);
	//añadiendo	
	var.anadir_inicio(estud3);
	var.anadir_final(estud2);
	var.anadir_posicion(estud5,2);
	//miremos como esta la lista
	imprimir (var);	
	//eliminando
	var.eliminar_posicion(2);
	//miremos como esta la lista
	imprimir (var);	
	//añadiendo
	var.anadir_inicio(estud6);
	var.anadir_final(estud1);
	var.anadir_posicion(estud4,3);
	//miremos como esta la lista
	imprimir(var);
	//eliminando
	var.eliminar_final();
	//miremos como esta la lista
	imprimir(var);
	//eliminando	

	var.eliminarInicio();
	//miremos como esta la lista
	imprimir(var);	
	var.eliminar_final();
	//miremos como esta la lista
	imprimir(var);	
	var.eliminar_posicion(3);
  //miremos como esta la lista
	imprimir(var);	
	
	//Lista de enteros
	cout<<endl<<endl;
	cout<<"LISTA DE ENTEROS";
	cout<<endl<<endl;
	varInt.anadir_inicio(90);
	varInt.anadir_final(78);
	varInt.anadir_posicion(80,2);
	imprimir2(varInt);
	varInt.eliminar_posicion(varInt.getTam()/2); //Nueva
	imprimir2(varInt);
	varInt.anadir_inicio(0);
	varInt.anadir_posicion(14,4);
	varInt.anadir_posicion(35,6);
	imprimir2(varInt);
	varInt.eliminar_final();  //Nueva
	imprimir2(varInt);
	varInt.anadir_final(87);  //Nueva
	imprimir2(varInt);
	varInt.eliminarInicio();
	varInt.eliminar_final();
	varInt.eliminar_posicion(3);
	imprimir2(varInt);
	
	//Imprimiendo lista
	
  	imprimir2(varInt);
	cout<<endl<<endl;
	
	//Lista de flotantes
	cout<<endl<<endl;
	cout<<"LISTA DE FLOTANTES";
	cout<<endl<<endl;
	varFloat.anadir_inicio(90.8);
	varFloat.anadir_final(78.06);
	varFloat.anadir_posicion(80.7,2);
	imprimir2(varFloat);
	varFloat.eliminar_posicion(varFloat.getTam()/2); //Nueva
	imprimir2(varFloat);
	varFloat.anadir_inicio(0.08);
	varFloat.anadir_posicion(14.32,4);
	varFloat.anadir_posicion(35.097,6);
	imprimir2(varFloat);
	varFloat.eliminar_final(); //Nueva
	imprimir2(varFloat);
	varFloat.anadir_final(87.123); //Nueva
	imprimir2(varFloat);
	varFloat.eliminarInicio();
	varFloat.eliminar_final();
	varFloat.eliminar_posicion(3);
	imprimir2(varFloat);
	
	//Imprimiendo lista
	imprimir2(varFloat);
	cout<<endl<<endl;


// seccion de uso de listas de estructuras
	Lista<char> chars;
	char char1 = 'I';
	char char2=  'S';
	char char3= 'A';
	char char4= 'B';
	char char5= 'E';
	char char6= 'L';

	//añadiendo datos
	chars.anadir_inicio(char4);
	chars.anadir_final(char1);
	chars.anadir_posicion(char6,2);
	//miremos como esta la lista
	imprimir2 (chars);
	//eliminando inicio
	chars.eliminarInicio();
	//miremos como esta la lista
	imprimir2 (chars);
	//añadiendo	
	chars.anadir_inicio(char3);
	chars.anadir_final(char2);
	chars.anadir_posicion(char5,2);
	//miremos como esta la lista
	imprimir2 (chars);	
	//eliminando
	chars.eliminar_posicion(2);
	//miremos como esta la lista
	imprimir2 (chars);	
	//añadiendo
	chars.anadir_inicio(char6);
	chars.anadir_final(char1);
	chars.anadir_posicion(char4,3);
	//miremos como esta la lista
	imprimir2(chars);
	//eliminando
	chars.eliminar_final();
	//miremos como esta la lista
	imprimir2(chars);
	//eliminando	
	chars.eliminarInicio();
	//miremos como esta la lista
	imprimir2(chars);	
	chars.eliminar_final();
	//miremos como esta la lista
	imprimir2(chars);	
	chars.eliminar_posicion(3);
	//miremos como esta la lista
	imprimir2(chars);	
}

