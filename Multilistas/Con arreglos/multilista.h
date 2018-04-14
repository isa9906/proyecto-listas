#include <string.h>
#include <iostream>

using namespace std;

struct Persona {
	char* nombre;
	char* carrera;
	char* hobby;
	int edad;
	int signombre,sigcarrera,sighobby,sigedad;
};

//edad de mayor a menor
	//nombre de menor a mayor
	//hobby insertar al comienzo
	//carrera insertar al final
	
	/*
	cabecera[0] -> nombre
	cabecera[1] -> electronica
	cabecera[2] -> catastral
	cabecera[3] -> industrial
	cabecera[4] -> sistemas
	cabecera[5] -> danza
	cabecera[6] -> natacion
	cabecera[7] -> basket
	cabecera[8] -> baseball
	cabecera[9] -> edad
	*/
	
class multilista {
	private:
		int *cabecera;
		Persona *datos;
		int tam;        //determina el tama�o limite de personas
		int indice;		//determinar la posici�n en la que va el arreglo de personas
		
		//se ordena la multilista por nombre, se declara privado
		void ordenarByNombre (char *nombre,int anterior,int actual){
			anterior=-1;
			actual=cabecera[0];
			while(true){
				if(actual==0){ //insertar al final
					datos[anterior-1].signombre=indice+1;
					break;
				}
				else if(strcoll(nombre,datos[actual-1].nombre)==1){
					anterior=actual;
					actual=datos[actual-1].signombre;
				}
				else {
					if (anterior==-1){ //agregar a la cabeza
						datos[indice].signombre = actual;
						cabecera[0] = indice+1;
					}
					else{ //agregar entre medio
						datos[anterior-1].signombre = indice+1;
						datos[indice].signombre = actual;
					}
					break;
				}
			}
		}
	public:	
		//Constructor
		multilista(int numPers,int i){	
			cabecera= new int [10];
			for(i=0;i<10;i++){
				cabecera[i] = 0;
			}
			datos = new Persona [numPers]; 
			indice=0;
		}
		void insertar(Persona persona){
			datos[indice]=persona;	
			if (estaVacia()){
				//agregando nombre
				cabecera[0]=1;
				persona.signombre=0;
				//agregando carrera
				if (strcoll(persona.carrera,"electronica")==0){
					cabecera[1]=1;
				}
				else if (strcoll(persona.carrera,"catastral")==0){
					cabecera[2]=1;
				}
				else if (strcoll(persona.carrera,"industrial")==0){
					cabecera[3]=1;
				}
				else {//sistemas
					cabecera[4]=1;
				}
				persona.sigcarrera=0;
				//agregando hobbie
				if (strcoll(persona.hobby,"danza")==0){
					cabecera[5]=1;
				}
				else if (strcoll(persona.hobby,"natacion")==0){
					cabecera[6]=1;
				}
				else if (strcoll(persona.hobby,"basket")==0){
					cabecera[7]=1;
				}
				else {//beisbol
					cabecera[8]=1;
				}
				persona.sighobby=0;
				//agregando edad
				cabecera[9]=1;
				persona.sigedad=0;						
			}
			else{
				int anterior,actual;
				ordenarByNombre(persona.nombre,anterior,actual);
			}
			indice++;
		}
		
		//retorna una lista de tipo char **
		char **listarByNombre(int i){
			int actual;
			char **lista;
			lista = new char*[indice];
			actual = cabecera[0];
			i = 0;
			while(actual!=0){
				lista[i] = datos[actual-1].nombre;
				actual = datos[actual-1].signombre;
				i++;
			}
			return lista;
		}
		void eliminar(string nombre, int pos){
		
		}
		//verifica si la lista est� vac�a
		bool estaVacia(){
			if(indice==0){
				return true;
			}
			return false;
		}
		//verifica si la lista est� llena
		bool estaLlena(){
			if(indice=(tam-1)){
				return true;
			}
			return false;
		}
		int getindice(){
			return indice;
		}
		int getTam(){
			return tam;
		}
};




