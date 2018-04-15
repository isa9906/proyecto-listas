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
		int indiceindust,indicecatast,indicesist,indiceelec;//indices para manejar carreras
		int indicenat,indicebask,indicedan,indicebase;//indices para manejar hobbies
		int i;
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
		//se ordena la multilista por edad, se declara privado
		void ordenarByEdad (int edad,int anterior,int actual){
			anterior=-1;
			actual=cabecera[9];
			while(true){
				if(actual==0){ //insertar al final
					datos[anterior-1].sigedad=indice+1;
					break;
				}
				else if(edad<datos[actual-1].edad){
					anterior=actual;
					actual=datos[actual-1].sigedad;
				}
				else {
					if (anterior==-1){ //agregar a la cabeza
						datos[indice].sigedad = actual;
						cabecera[9] = indice+1;
					}
					else{ //agregar entre medio
						datos[anterior-1].sigedad= indice+1;
						datos[indice].sigedad = actual;
					}
					break;
				}
			}
		}
		//se coloca el hobbie a la cabeza
		void ordenarByHobbie(char *hobbie,int actual){
			int cab;
			if (strcoll(hobbie,"danza")==0){
				cab = 5;
			}
			else if (strcoll(hobbie,"natacion")==0){
				cab = 6;
			}
			else if (strcoll(hobbie,"basket")==0){
				cab = 7;
			}
			else {//beisbol
				cab = 8;
			}
			actual = cabecera[cab];
			datos[indice].sighobby = actual;
			cabecera[cab] = indice+1;
		}
		//se coloca la carrera al final
		void ordenarByCarrera(char *carrera, int actual, int anterior){
			int cab;
			if (strcoll(carrera,"electronica")==0){
				cab = 1;
			}
			else if (strcoll(carrera,"catastral")==0){
				cab = 2;
			}
			else if (strcoll(carrera,"industrial")==0){
				cab = 3;
			}
			else {//sistemas
				cab = 4;
			}
			anterior = -1;
			actual = cabecera[cab];
			while(actual!=0){
				anterior = actual;
				actual = datos[indice].sigcarrera;
			}
			if(anterior=-1){ //se agrega a la cabeza porque no hay ninguna persona con esa carrera
				cabecera[cab] = indice+1;
			}
			else{
				datos[anterior-1].sigcarrera = indice+1;
			}
			
		}
	public:	
		//Constructor
		multilista(int numPers){
				
			cabecera= new int [10];
			for(i=0;i<10;i++){
				cabecera[i] = 0;
			}
			datos = new Persona [numPers]; 
			indice=0;
		}
		void insertar(Persona persona){
			persona.signombre=0;
			persona.sigcarrera=0;
			persona.sighobby=0;
			persona.sigedad=0;
			datos[indice]=persona;	
			if (estaVacia()){
				//agregando nombre
				cabecera[0]=1;
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
				//agregando edad
				cabecera[9]=1;			
			}
			else{
				int anterior,actual;
				ordenarByNombre(persona.nombre,anterior,actual); //se ordena por nombre alfab�ticamente
				ordenarByEdad (persona.edad,anterior,actual); //se ordena por edad de mayor a menor
				ordenarByHobbie(persona.hobby,actual); //se pone a la cabeza
				ordenarByCarrera(persona.carrera,actual,anterior); //se pone al final 
			}
			indice++;
		}
		
		//retorna una lista de tipo char **
	Persona *listarByNombre(){
		int actual;
		Persona *lista;
		lista = new Persona [indice];
		actual = cabecera[0];
		i = 0;
		while(actual!=0){
			lista[i] = datos[actual-1];
			actual = datos[actual-1].signombre;
			i++;
		}
			return lista;
	}
//retorna una lista de tipo int *

	Persona  *listarByEdad(){
		int actual;
		Persona *lista;
		lista= new Persona[indice];
		actual=cabecera[1];
		while(actual!=0){
			lista[i]=datos[actual-1];
			actual=datos[actual-1].sigedad;
			i++;
		}
		return lista;
	}
	
	Persona  *listarByHobby(int hobby){
		int actual;
		Persona *lista;
		
	 //1 Se enlista por nataci�n
		// 2 se enlista por basket
	    // 3 Se enlista por danza
		// 4 Se enlista por baseball
			switch (hobby){
			case 1:
				actual=cabecera[2];
				lista= new Persona [indicenat];
			break;
			case 2:
				actual=cabecera[3];
				lista= new Persona [indicebask];
			break;
			case 3:
				actual=cabecera[4];
				lista= new Persona [indicedan];	
				break;
			case 4:
				actual=cabecera[5];
				lista= new Persona [indicebase];
			break;
		}
		while(actual!=0){
			lista[i]=datos[actual-1];
			actual=datos[actual-1].sighobby;
			i++;
		}
		return lista;
	}
	
	Persona  *listarByCarrera(int i, int carrera){
		int actual;
		Persona *lista;
		
 	 // 1 Se enlista por sistemas	
	 // 2 Se enlista por castral
	 // 3 Se enlista por electr�nica
	 // 4 Se enlista por industrial
		switch (carrera){
			case 1:
				actual=cabecera[6];
				lista= new Persona [indicesist];
			break;
			case 2:
				actual=cabecera[7];
				lista= new Persona [indicecatast];
			break;
			case 3:
				actual=cabecera[8];
				lista= new Persona [indiceelec];	
				break;
			case 4:
				actual=cabecera[9];
				lista= new Persona [indiceindust];
			break;
		}	
		while(actual!=0){
			lista[i]=datos[actual-1];
			actual=datos[actual-1].sigcarrera;
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
			if(indice==(tam-1)){
				return true;
			}
			return false;
		}
		int getindicesist(){
			return indicesist;
		}
		int getindicecatast(){
			return indicecatast;
		}
		int getindiceindus(){
			return indiceindust;
		}
		int getindiceelec(){
			return indiceelec;
		}
		int getindicenat(){
			return indicenat;
		}
		int getindicebask(){
			return indicebask;
		}
		int getindicedan(){
			return indicedan;
		}
		int getindicebase(){
			return indicebase;
		}
		int getindice(){
			return indice;
		}
		int getTam(){
			return tam;
		}
};




