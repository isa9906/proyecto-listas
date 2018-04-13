#include <iostream>
#include "Lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
//Imprime clave e info
void imprimir (Lista var){
	int i;
	nodo *b;
		for(i=0;i<var.getTam();i++){
			b = var.devolverDato(i);
			cout<<b->clave<<" "<<b->info<<endl;
		}
		cout<<endl<<endl;
}
int main(int argc, char** argv) {
	Lista prueba;
	cout<<"INSERTANDO"<<endl;
	prueba.anadir('b',"Isabel Perez");
	prueba.anadir('a',"Sebastian Mora");
	prueba.anadir('c',"Felipe Renteria");
	imprimir(prueba);
	cout<<"ELIMINANDO"<<endl;
	prueba.eliminar_clave('b'); //Eliminando por clave
	imprimir(prueba);
	prueba.anadir('f',"David Romero");
	prueba.anadir('d',"Estefania Garcia");
	imprimir(prueba);
	cout<<"BUSCANDO POR CLAVE"<<endl;
	cout<<prueba.buscar('a')->info<<endl<<endl; //Buscando por clave
	cout<<"MODIFICANDO<<"<<endl;
	prueba.modificar('a',"Primer elemento"); //Modificando por clave
	imprimir(prueba);
	
	return 0;
}
