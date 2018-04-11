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
	prueba.anadir('b',"esto");
	prueba.anadir('a',"si");
	prueba.anadir('c',"funciona");
	imprimir(prueba);
	prueba.eliminar_clave('b'); //Eliminando por clave
	imprimir(prueba);
	cout<<prueba.buscar('a')->info<<endl<<endl; //Buscando por clave
	prueba.modificar('a',"Primer elemento"); //Modificando por clave
	imprimir(prueba);
	
	return 0;
}
