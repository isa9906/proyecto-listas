




#include <iostream>
#include "arbolBinario.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int tam=10;
	arbolBinario arbol (tam);
	int variable;
	variable=100;
	arbol.agregar(variable);
	cout<<"agregado"<<endl;
	variable=50;
	arbol.agregar(variable);
	cout<<"agregado"<<endl;
	return 0;
}
