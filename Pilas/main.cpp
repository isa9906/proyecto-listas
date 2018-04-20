#include <iostream>
#include "pilas.h"

void notacionPolaca();
void solucion();

using namespace std;

int main(){
	notacionPolaca();
	solucion();
}

void notacionPolaca(){
	//Notación polaca
	char c;
	Pila<char> guardar(50);
	while(cin.get(c) && c!='\n'){
		while(c>='0' && c<='9'){
			cout.put(c);
			cin.get(c);
		}
		if(c==')') {
			cout<<" ";
			cout.put(guardar.sacar());
		}
		if(c=='+') guardar.meter(c);
		if(c=='*') guardar.meter(c);
		if(c!='(') cout<<" ";
	}
	cout<<endl<<endl;
}

void solucion(){
	//Solución
	char c;
	Pila<int> acc(50);
	int x;

	while(cin.get(c) && c!='\n'){
		x = 0;
		while(c==' ') cin.get(c);
		while(c>='0' && c<='9'){
			x = 10*x + (c-'0');
			cin.get(c);
		}
		if(c=='+') x = acc.sacar() + acc.sacar();
		if(c=='*') x = acc.sacar() * acc.sacar();
		acc.meter(x);		
	}
	cout<<acc.sacar()<<endl;
}
