#include <stddef.h>
#include <string>

struct nodo {
	char clave;
	char *info;
	nodo *sig;
};



class Lista {
	//estructura de datos donde clave es el dato a guardar y sig es la posicion a la que apunta despues
	nodo *cab;
	nodo *fin;
	int tam;
	
	public:
		//constructor
		Lista(){
			cab=NULL;
			fin=NULL;
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
		void insertar(char dato){
			nodo *b;
			b = new nodo;
			b -> clave = dato;
			b -> info = "--";
			b -> sig = 	NULL;
			if(lista_vacia()){
				cab=fin=b;
			}
			else{
				nodo *actual;
				nodo *anterior;
				actual = cab;
				anterior = NULL;
				while(true){
					if(actual->sig == NULL){
						//agregar a la cola
						fin->sig=b;
						fin=b;
						break;
					}
					if(dato<actual->clave){
						if(anterior==NULL){
							//agregar a la cabeza
							b->sig = cab;
							cab = b;
							break;
						}
						else{
							b->sig = actual;
							anterior->sig = b;
							break;
						}
					}
					else{
						anterior->sig = actual;
						actual = actual->sig;
						break;
					}
				}	
			}
			tam++;
		}
		void eliminarInicio(){
			nodo *b;
			b = cab;
			cab = cab -> sig;
			delete b;
			tam--;
		}

		void modificar(char valorNuevo, int posicion){
			if(posicion==0){
				cab->clave = valorNuevo;
			}
			else if(posicion>=(tam-1)){
				fin->clave = valorNuevo;
			}
			else{
				nodo *b;
				int contador;
				b = new nodo;
				b = cab->sig;
				contador = 1;
				while(true){
					if(contador==posicion){
						break;
					}
					else{
						contador++;
						b = b -> sig;
					}
				}
				b->clave = valorNuevo;
			}
		}
	
	void eliminar_final(){
		nodo *b;//creando un nodo 
		//b= new nodo <T>;//separando memoria
		if(!lista_vacia()){
			b=cab;
			int i;
			for (i=1;i<tam-1; i++){
				b=b->sig;
		}
		delete fin;
		fin=b;
		tam--;	
		}
	}
	void eliminar_posicion(int posicion){
		if (posicion>=tam-1){
			eliminar_final();
		}
		else if(posicion==0){
			eliminarInicio();
		}
		else{
			nodo *b;//creando un nodo 
			nodo *c;//creando un nodo 
			//b= new nodo <T>;//separando memoria
							
			if(!lista_vacia()){
				b=cab;
				c=cab;
				int i;
				for (i=0;i<posicion; i++){
					b=b->sig;
				}
				for (i=1;i<posicion; i++){
					c=c->sig;
				}
				//b->sig=c->sig;
				c->sig = b->sig;
				delete b;
				//delete c;
				tam--;
			}
		}
		
	}

	char devolverDato(int posicion){
			//if(lista_vacia()) return 0;
			if(posicion==0){
				return cab->clave;
			}
			else if(posicion>=(tam-1)){
				return fin->clave;
			}
			else{
				nodo *b;
				int contador;
				b = new nodo;
				b = cab->sig;
				contador = 1;
				while(true){
					if(contador==posicion){
						break;
					}
					else{
						contador++;
						b = b -> sig;
					}
				}
				return b->clave;
				//delete b;
			}
		}
		
	int getTam(){
		return tam;
	}	
};
