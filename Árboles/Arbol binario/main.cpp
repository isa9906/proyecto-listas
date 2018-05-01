




#include <iostream>
#include "arbolBinario.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	arbolBinario <int> arbol (10);
	arbol.agregar(100);
	arbol.agregar(50);
	arbol.agregar(25);
	arbol.agregar(150);
	arbol.agregar(30);
	arbol.revisar();
	arbol.eliminar(100);
	cout<<endl;
	arbol.revisar();
	return 0;
}
