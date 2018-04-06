#include <iostream>
#include "Lista.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	Lista<int> var;
	int i;
	var.anadir_inicio(10);
	var.anadir_final(20);
	var.anadir_posicion(15,2);
	var.anadir_inicio(5);
	var.anadir_posicion(18,4);
	var.anadir_posicion(25,6);
	for(i=0;i<var.getTam();i++)
		cout<<var.devolverDato(i)<<" ";
	return 0;
}
