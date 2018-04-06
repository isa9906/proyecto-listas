template <class T>

class Lista {
	//estructura de datos donde x es el dato a guardar y sig es la posicion a la que apunta despues
	struct nodo {
		T x;
		nodo <T> *sig;
	};
	
	T *cab;
	T *fin;
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
		//añade un dato al final de la lista
		void añadir_final(T dato){
			nodo <T> *b;//creando un nodo 
			b= new nodo <T>;//separando memoria
			b->x=dato;//llenando la info con el dato dado
			b->sig= NULL;//no apunta a nada
			//mueve el apuntador de la cabeza y del fin
			if(lista_vacia){
				cabeza=fin=b;
			}
			else{
				fin->sig=b;
				fin=b;
			}
			tam++;
			delete b;
		}
		void añadir_inicio(T dato){
			nodo <T> *b;//creando un nodo 
			b= new nodo <T>;//separando memoria
			b->x=dato;//llenando la info con el dato dado
			b->sig= NULL;//no apunta a nada
			//mueve el apuntador de la cabeza y del fin
			if(lista_vacia){
				cabeza=fin=b;
			}
			else{
				b->sig=cabeza;
				cabeza=b;
			}
			tam++;
			delete b;
		}
		void añadir_posicion (T dato, int posicion){
			if(posicion==0){
				añadir_inicio(dato);
			}
			else if(posicion>=(tam-1)){
				añadir_final(dato);
			}
			else{
				nodo<T> *anterior, *actual;
				int contador = 1;
				actual = cabeza->sig;
				anterior = cabeza;
				while(true){
					if(contador==posicion){
						break;
					}
					else{
						contador++;
						anterior = actual;
						actual = actual->sig;
					}
				}
				nodo<T> *b;
				b = new nodo<T>;
				b->x = dato;
				b->sig = actual;
				anterior-> sig = b;
				delete anterior;
				delete actual;
				delete b;
			}
		}
	
		int eliminarInicio(){
			if(listaVacia()) return 0;
			else{
				nodo<T> *b;
				b = cabeza;
				cabeza = cabeza -> sig;
				delete *b; //Dudas
			}
			return 1;
		}
		//si la lista está vacía, retornará 0, sino retorna 1
		int modificar(T valorNuevo, int posicion){
			if(listaVacia()) return 0;
			else if(posicion==0){
				cabeza->x = valorNuevo;
			}
			else if(posicion>=(tam-1)){
				fin->x = valorNuevo
			}
			else{
				nodo<T> *b;
				int contador;
				b = new nodo<T>;
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
				b->x = valorNuevo;
				delete b;
			}
			return 1;
		}
		
		/*void imprimir(){
			nodo<T> *b;
			b = cab;
			while(true){
				cout<<b->x<<" ";
				if(b->sig == NULL) break;
				else{
					b = b -> sig;
				}
				
			}
		}*/
};
