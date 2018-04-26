#include "Lista.h"

struct x{
	char* descripcion;
	int sig;
};

class arbol{
	private:
		int raiz;
		x *hojas;
		x *siguientes;
		int indiceHojas;
		int indiceSiguientes;
	public:
		arbol(int tam1, int tam2, int rais){
			indiceHojas = 0;
			indiceSiguientes = 0;
			raiz = rais;
			hojas = new x[tam1];
			siguientes = new x[tam2];
		}
		
		void agregarTablaHojas(x hoja){
			hojas[indiceHojas++] = hoja;
		}
		
		void agregarTablaSiguientes(x hoja){
			siguientes[indiceSiguientes++] = hoja;
		}
		
		x *getHojas(){
			return hojas;
		}
		
		x *getSiguientes(){
			return siguientes;
		}
		
		int getRaiz(){
			return raiz;
		}
		
		Lista<int> getHijos(int padre){
			Lista<int> lista;
			int sig;
			sig = hojas[padre].sig;
			while(sig!=0){
				lista.anadir_inicio(sig);
				sig = hojas[sig].sig;
			}
			return lista;
		}
};
