#include <iostream>
#include "arbolAVL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	arbolAVL <int> arbol(10);
	arbol.agregar(50);
	arbol.agregar(80);
	arbol.agregar(90);
	arbol.agregar(100);
	arbol.agregar(110);
	arbol.agregar(150);
	arbol.revisar();
	return 0;
}
