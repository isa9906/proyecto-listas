#include <iostream>
#include <string>
#include "Lista.h"

struct estud{
	long long cod;
	char *nombre;
};

using namespace std;



void imprimir(Lista var){
	int i;
		for(i=0;i<var.getTam();i++)
		cout<<var.devolverDato(i)<<" ";
			cout<<endl<<endl;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//Variables
	int  i;
	Lista var;
	var.insertar('b');
	imprimir(var);
	var.insertar('z');
	imprimir(var);
	var.insertar('a');
	imprimir(var);
	return 0;	
}

