#include <string>
#include <iostream>
using namespace std;
struct nodo {
	string info;
	int prioridad;
};
class colaPrioritaria {
	
	private:
		int tam;
		int indice;
		
		nodo inser;
		nodo *arreglo;
	public:
		//inicializando 
		colaPrioritaria (int tama){
			tam=tama;
			arreglo = new nodo [tam];
			indice=1; //indice en 1 ya que posicion 0 no se usa
			arreglo[0].info="";
			arreglo[0].prioridad=0;
		}
		bool colavacia (){
		
			if (indice==1){
				return true;
			}
			else {
			return false;
			}
		}
		bool colallena(){
			if (indice>=tam){
				return true;
			}
			else{
				return false;
			}
		}
		
		void insertar (string datoinfo, int datoprior){
			//creando un nodo con la info dada
			nodo actual;
			actual.info= datoinfo;
			actual.prioridad=datoprior;
			
			int i= indice;
			//caso lista vacia 
			if(colavacia()){
				arreglo[i]=actual;
			}
			//va revisando si tiene padre
			while (i/2!=0){
				
				int j = i/2;// se ubica en el padre
				nodo aux = arreglo [j];//guarda la informacion del padre
								
				if(aux.prioridad<actual.prioridad){//compara prioridad
					//intercambio posiciones
					arreglo[i]=aux;
					arreglo[j]=actual;						
				}
				//si ya no tiene mayor prioridad, posiciona y se detiene
				else {
					arreglo[i]=actual;
					break;
				}
				i=j;
			}
			indice++;	
		}
		
		
		//funcion unicamente para revisar como se encuentra el arreglo hasta el momento
		void revisar () {
			for(int i=0; i<indice; i++){
				cout<< arreglo[i].info<<" ";
				cout<<arreglo[i].prioridad<<endl;	 
			}
		}	
};

