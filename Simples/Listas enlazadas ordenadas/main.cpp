#include <iostream>
#include "Lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
void imprimir (Lista var){
	int i;
		for(i=0;i<var.getTam();i++)
		cout<<var.devolverDato(i)->clave<<" ";
			cout<<endl<<endl;
}
int main(int argc, char** argv) {
	Lista prueba;
	prueba.anadir('b',"esto");
	prueba.anadir('a',"si");
	prueba.anadir('c',"funciona");
	//prueba.eliminarInicio();
	//cout<<prueba.getTam()<<endl;
	//prueba.eliminar_final();
	imprimir(prueba);
	return 0;
}
