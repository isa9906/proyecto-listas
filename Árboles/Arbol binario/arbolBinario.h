
struct nodo {
	int clave;
	int izq;
	int der;
};
using namespace std;
class arbolBinario {
	int tam;
	int i;
	int indice;
	nodo *arreglo;
	int auxactual=0;
	int auxrevisado=0;
	public:
	arbolBinario (int tam){
		arreglo= new nodo [tam+1];
		indice=0;
		for(i=0;i<tam;i++){
			arreglo[i].der=i+1;
		}
		arreglo[tam].der=0;				
	}
	void agregar(int valor){
		
		
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
	void inorden(){
		
		
	}	
};
