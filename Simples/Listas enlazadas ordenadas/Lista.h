#include <stddef.h>


struct nodo {
	char clave;
	char *info;
	nodo *sig;
};



class Lista {
	//estructura de datos donde x es el dato a guardar y sig es la posicion a la que apunta despues
	nodo *cab;
	nodo *fin;
	nodo *auxinicio;
	nodo *auxfin;
	int tam;
	
	public:
		//constructor
		Lista(){
			cab=auxinicio;
			auxinicio->sig=auxfin;
			fin=auxfin;
			tam=0;
		}
		bool lista_vacia(){
			if(tam==0){
				return true;
			}
			else {
				return false;
			}
		}
		void anadir(char clave,char *info){
			nodo *b,*actual,*anterior;//creando un nodo 
			b= new nodo;//separando memoria
			b->clave=clave;//llenando la info con el dato dado
			b->info= info;//la info
			b->sig=NULL;
			if (lista_vacia()){
				auxinicio->sig=b;
				b->sig=auxfin;
			}
			else{
				actual = auxinicio->sig;
				anterior = auxinicio;
				int i;
				for (i=0;i<tam; i++){
					if(clave<actual->clave||actual->sig==auxfin){
						b->sig=actual;
						anterior->sig=b;
						break;
					}
					else{
						anterior = actual;
						actual = actual->sig;
					}			
				}	
			}
			tam++;
		}
		
		
		
		//añade un dato al final de la lista
		
		int eliminarInicio(){
			if(lista_vacia()) 
				return 0;
			else{
				nodo *b;
				
				b = auxinicio->sig;
				auxinicio->sig = b->sig;
				delete b;
			}
			tam--;
			return 1;
		}
		
		//si la lista está vacía, retornará 0, sino retorna 1
		int modificar(char clave, char *nuevo){
			if(lista_vacia()) return 0;
			else{					
				nodo *b;
				int i;
				b = new nodo;
				b = auxinicio->sig;
				for (i=0;i<tam; i++){
					if(clave==b->clave){
						break;
					}
					b=b->sig;
				}
				b->info=nuevo;
			}
			return 1;
		}
	
	int eliminar_final(){
		nodo *actual,*anterior;//creando un nodo
		if (lista_vacia()) return 0;
		else{
			anterior = auxinicio;
			actual = auxinicio->sig;
			
			int i;
			for (i=1;i<tam; i++){
					anterior = actual;
					actual = actual->sig;
			}
				anterior->sig=actual->sig;
									
			}
			tam--;
		return 1;			
		}
	int eliminar_clave(char clave){
		nodo *actual,*anterior;//creando un nodo
		if (lista_vacia()) return 0;
		else{
			anterior = auxinicio;
			actual = auxinicio->sig;
			
			int i;
			for (i=0;i<tam; i++){
				if(clave==actual->clave){
					
					anterior->sig=actual->sig;		
					break;
				}
				else{
					anterior = actual;
					actual = actual->sig;
				}
								
			}
			tam--;
		return 1;			
		}
				
	}
		


	char *buscar(char clave){
			//if(lista_vacia()) return 0;
				nodo *b;
				int contador;
				b = new nodo;
				b = auxinicio->sig;
				contador = 0;
				while(true){
					if(b->clave==clave){
						break;
					}
					else{
						contador++;
						b = b -> sig;
					}
				}
				return b->info;
				//delete b;
	}
	char *devolverDato(int posicion){	
			//if(lista_vacia()) return 0;
				nodo *b;
				int contador;
				b = new nodo;
				b = auxinicio->sig;
				contador = 0;
				while(true){
					if(contador==posicion){
						break;
					}
					else{
						contador++;
						b = b -> sig;
					}
				}
				return b->info;
				//delete b;
	}
	
		
	int getTam(){
		return tam;
	}	
};
