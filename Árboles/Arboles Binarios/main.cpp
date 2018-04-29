#include <iostream>
#include "arbolBinario.h"

using namespace std;

int main(){
	arbolBinario<int> arbol(5);
	arbol.insertar(100);
	arbol.insertar(50);
	arbol.insertar(25);
	arbol.insertar(70);
	arbol.insertar(200);
}
