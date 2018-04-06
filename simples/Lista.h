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
				return True;
			}
			else {
				return False;
			}
		}
		//a�ade un dato al final de la lista
		void a�adir_final(T dato){
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
		}
		void a�adir_inicio(T dato){
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
	}
	void a�adir_posicion (T dato, int posicion){
		int i;
		if (posicion>tam){
			a�adir_fin(dato);
		}
		else if( posicion==0){
			a�adir_inicio(dato);
		}
		else{		
			for (i=0;i<posicion; i++){
			}
		
		}
	}
	void eliminar_final(T dato){
		nodo <T> *b;//creando un nodo 
		//b= new nodo <T>;//separando memoria
		
		if(!lista_vacia){
			b=cabeza;
			for (i=1;i<tam-1; i++){
				b=b->sig;
		}
		delete fin;
		fin=b;
		tam--;	
		}
	}
	void eliminar_posicion(T dato,int posicion){
		if (posicion>=tam){
			eliminar_fin(dato);
		}
		else if( posicion==0){
			eliminar_inicio(dato);
		}
		else{
			nodo <T> *b;//creando un nodo 
			nodo <T> *c;//creando un nodo 
			//b= new nodo <T>;//separando memoria
							
			if(!lista_vacia){
				b=cabeza;
				c=cabeza;
				for (i=0;i<posicion-1; i++){
					b=b->sig;
				}
				for (i=1;i<posicion-1; i++){
					c=c->sig;
				}
				b->sig=c->sig;
				delete c;
			}
		}
		tam--;
	}
};
