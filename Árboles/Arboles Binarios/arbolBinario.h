template <class T>
struct node{
	T clave;
	int izq;
	int der;
};
// la posición de control es -1
template <class T>
class arbolBinario{
	private:
		int raiz; //indica la posición en donde se encuentra la raiz
		int indice;
		node<T> *arbol;
		int i;
	public:
		arbolBinario(int tam){
			raiz = -1;
			indice = 0;
			arbol = new node<T>[tam];
			//todos los valores de izquieda y derecha quedan con la posición de control -1
			for(i=0;i<tam;i++){
				arbol[i].der = -1;
				arbol[i].izq = -1;
			}
		}
		
		bool arbolVacio(){
			if(indice==0){
				return true;
			}
			return false;
		}
		
		void insertar(T valor){
			if(arbolVacio()){ //si el arbol está vacío
				raiz = indice;
				arbol[indice++].clave = valor;
			}
			else{
				int actual,izquierda=0,derecha=0;
				actual = raiz;
				while(!(izquierda==-1 || derecha==-1)){
					if(valor<arbol[actual].clave){ //se va a la izquierda
						izquierda = arbol[actual].izq;
						if(izquierda!=-1){
							actual = arbol[actual].izq;
						}
					}
					else{ //se va por la derecha
						derecha = arbol[actual].der;
						if(derecha!=-1){
							actual = arbol[actual].der;
						}
					}
				}
				//se verifica cual de los dos, derecha o izquierda, quedó el con el valor -1
				//así se podra saber si el valor se inserta a izquierda o derecha
				arbol[indice].clave = valor;
				if(derecha==-1){
					arbol[actual].der = indice++;
				}
				else if(izquierda==-1){
					arbol[actual].izq = indice++;
				}
			}
		}
		
		Lista<T> recorridoInOrden(){
			
		}
};
