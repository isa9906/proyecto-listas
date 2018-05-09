#include "Lista.h"
template <class T>
struct x{
	T descripcion;
	int sig;
};

class arbol{
	private:
		int raiz;
		x<char*> *hojas;
		x<int> *siguientes;
		int indiceHojas;
		int indiceSiguientes;
	public:
		arbol(int tam1, int tam2, int rais){
			int i;
			indiceHojas = 0;
			indiceSiguientes = 0;
			raiz = rais;
			hojas = new x<char*>[tam1];
			//inicializando la tabla de hojas
			for(i=0;i<tam1;i++){
				hojas[i].sig = 0;
			}
			siguientes = new x<int>[tam2];
			//inicializando la tabla de siguientes
			for(i=0;i<tam2;i++){
				siguientes[i].descripcion = -1;
				siguientes[i].sig = -1;
			}
		}
		
		void agregarTablaHojas(x<char*> hoja){
			hojas[indiceHojas++] = hoja;
		}
		
		void agregarTablaSiguientes(x<int> hoja){
			siguientes[indiceSiguientes++] = hoja;
		}
		
		x<char*> *getHojas(){
			return hojas;
		}
		
		x<int> *getSiguientes(){
			return siguientes;
		}
		
		int getRaiz(){
			return raiz;
		}
		
		Lista<int> getHijos(int padre){
			Lista<int> lista;
			int sig;
			sig = hojas[padre].sig;
			while(sig!=-1){
				lista.anadir_inicio(siguientes[sig].descripcion);
				sig = siguientes[sig].sig;
			}
			return lista;
		}
};
