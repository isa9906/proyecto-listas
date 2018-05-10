#ifndef COLA_P
#define COLA_P
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
		int i;
		
		nodo inser;
		nodo *arreglo;
	public:
		//inicializando 
		colaPrioritaria (int tama){
			tam=tama;
			arreglo = new nodo [tam];
			indice=1; //indice en 1 ya que posicion 0 no se usa
			//se inicializa todo el arreglo
			for(i=0;i<tam;i++){
				arreglo[i].info = "";
				arreglo[i].prioridad = 0;
			}
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
			
			i = indice;
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
		
		nodo atender(){
			nodo derecho,izquierdo,aux = arreglo[--indice],atendido = arreglo[1];
			arreglo[indice].info = "";
			arreglo[indice].prioridad = 0;
			i = 1;
			while(2*i<=(indice-1)){ //mientras el nodo tenga al menos un hijo
				izquierdo = arreglo[2*i];
				derecho = arreglo[2*i+1];
				if(izquierdo.prioridad>derecho.prioridad){
					arreglo[i].info = izquierdo.info;
					arreglo[i].prioridad = izquierdo.prioridad;
					i = i*2;
				}
				else{
					arreglo[i].info = derecho.info;
					arreglo[i].prioridad = derecho.prioridad;
					i = i*2+1;
				}
			}
			arreglo[i].info = aux.info;
			arreglo[i].prioridad = aux.prioridad;
			return atendido;
		}
		
		//funcion unicamente para revisar como se encuentra el arreglo hasta el momento
		void revisar () {
			cout<<"INFORMACI0N\tPRIORIDAD"<<endl;
			for(i=1; i<indice; i++){
				cout<< arreglo[i].info<<"\t";
				cout<<arreglo[i].prioridad<<endl;	 
			}
		}	
};
#endif
