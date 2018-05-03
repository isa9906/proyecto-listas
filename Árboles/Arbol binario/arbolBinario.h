#include <iostream>
#include "Pila.h"
#include "Lista.h"

template <class T>
struct x{
	T clave;
	int izq;
	int der;
};

using namespace std;
template <class T>

class arbolBinario {
	int tama;
	int i;
	int indice;
	x <T> *arreglo;
	int auxactual=0;
	int auxrevisado=0;
	public:
	arbolBinario (int tam){
		tama=tam;
		arreglo= new x <T> [tama+1];
		indice=0;
		for(i=0;i<tama;i++){
			arreglo[i].der=i+1;
		}
		arreglo[tam].der=0;				
	}
	void agregar(T valor){
		
		
		auxactual=arreglo[0].der;
		arreglo[auxactual].clave=valor;
		arreglo[0].der=arreglo[auxactual].der;
		arreglo[auxactual].izq=0;
		arreglo[auxactual].der=0;
		if (indice==0){
			arreglo[0].izq=auxactual;
			indice++;
		}
		else{
			auxrevisado=arreglo[0].izq;
			while(auxrevisado!=0){
				if(arreglo[auxactual].clave>arreglo[auxrevisado].clave){
					if(arreglo[auxrevisado].der==0){
						arreglo[auxrevisado].der=auxactual;
						auxrevisado=0;
					}
					else
					{
						auxrevisado=arreglo[auxrevisado].der;
					}		
				
				}
				else{
					if(arreglo[auxrevisado].izq==0){
						arreglo[auxrevisado].izq=auxactual;
						auxrevisado=0;
					}
					else{
						auxrevisado=arreglo[auxrevisado].izq;
					}
					
				}	
			}
			indice++;		
		}		
	}
	void eliminar(T valor){
		int padre=0;
		int hijo=arreglo[0].izq;
		
		while(arreglo[hijo].clave!=valor){
			if(valor>arreglo[hijo].clave){
				padre=hijo;
				hijo=arreglo[hijo].der;
			}
			else{
				padre=hijo;
				hijo=arreglo[hijo].izq;
			}
		}
		//elimina una hoja
		if(arreglo[hijo].der==0&&arreglo[hijo].izq==0){
			if(arreglo[padre].der==hijo){
				arreglo[padre].der=0;
			}
			else{
				arreglo[padre].izq=0;
			}			
		}
		//eliminar x con un solo hijo
		else if(arreglo[hijo].der==0||arreglo[hijo].izq==0){
			int hijoaux;
			if(arreglo[hijo].der!=0){
				hijoaux=arreglo[hijo].der;
			}
			else{
				hijoaux=arreglo[hijo].izq;
			}
			if(arreglo[padre].der==hijo){
				arreglo[padre].der=hijoaux;
			}
			else{
				arreglo[padre].izq=hijoaux;
			}
		}
	// comienza lo bueno
	
		else if(arreglo[hijo].der!=0&&arreglo[hijo].izq!=0){
			int padrerep;
			int hijorep;
			
			padrerep=hijo;
			hijorep=arreglo[padrerep].der;
			
			while(arreglo[hijorep].izq!=0){
				padrerep=hijorep;
				hijorep=arreglo[hijorep].izq;
			}
			if(arreglo[hijorep].der==0&&arreglo[hijorep].izq==0){
				if(arreglo[padrerep].der==hijorep){
					arreglo[padrerep].der=0;
				}
				else{
					arreglo[padrerep].izq=0;
				}				
			}
			else if(arreglo[hijorep].der==0||arreglo[hijorep].izq==0){
				int hijoaux;
				if(arreglo[hijorep].der!=0){
				hijoaux=arreglo[hijorep].der;
				}
				else{
					hijoaux=arreglo[hijorep].izq;
				}
				if(arreglo[padrerep].der==hijorep){
					arreglo[padrerep].der=hijoaux;
				}
				else{
					arreglo[padrerep].izq=hijoaux;
				}	
			}
			arreglo[hijorep].der=arreglo[hijo].der;
			arreglo[hijorep].izq=arreglo[hijo].izq;
			if(padre==0){
				arreglo[0].izq=hijorep;
			}
			else{
				if(arreglo[padre].der==hijo){
					arreglo[padre].der=hijorep;
				}
				else{
					arreglo[padre].izq=hijorep;
				}		
			}	
		}	
		//liberando espacio
		arreglo[hijo].der=arreglo[0].der;
		arreglo[0].der=hijo;
		arreglo[hijo].clave=0;
		arreglo[hijo].izq=0;	
	}
	
	Lista<T> *recorridoInOrden(){
		int node = arreglo[0].izq;
		Lista<T> *lista = new Lista<T>();
		inOrden(node,lista);
		return lista;
	}
	
	void inOrden(int node,Lista<T> *lista){
		Pila<int> pila;
		int actual = node;
		//se meten los nodos en la pila
		while(actual!=0){
			pila.meter(actual);
			actual = arreglo[actual].izq;
		}
		//se imprimen todos los nodoss según como esté dada la pila
		int current;
		while(!pila.vacia()){
			current = pila.sacar();
			lista->anadir_final(arreglo[current].clave);
			if(arreglo[current].der!=0)
				inOrden(arreglo[current].der,lista);
		}
	}
	
	
	void revisar(){
		for(int i; i<=tama;i++){
			cout<<arreglo[i].clave<<" ";
			cout<<arreglo[i].izq<<" ";
			cout<<arreglo[i].der<<endl;
		}
		
	}	
};
