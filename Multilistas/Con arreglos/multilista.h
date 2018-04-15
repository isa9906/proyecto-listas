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
		int tam;        //determina el tamaño limite de personas
		int indice;		//determinar la posición en la que va el arreglo de personas
		
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
		void eliminar(int lista, int pos){
			if(lista==0){
				
				eliminarByNombre(lista, pos);
				
			}else if(lista>=1&&lista<=4){
				
				eliminarByCarrera(lista, pos);
				
			}else if(lista>=5&&lista<=8){
				
				eliminarByHobbie(lista, pos);
				
			}else if(lista==9){
				
				eliminarByEdad(lista, pos);
				
			}
			
		}
		
		void eliminarByNombre(int nombre, int pos){
			int auxiliar = cabecera[nombre];
			int retardAuxiliar=0;
			int moreRetardAuxiliar;
			int i=1;
			//recorre hasta llegar a la posicion que se desea eliminar
			//si la posicion que se desea eliminar es mas grande que el tama;o del arreglo se sale
			while(i<pos&&(auxiliar!=0)){
				moreRetardAuxiliar=retardAuxiliar;
				retardAuxiliar = auxiliar;
				auxiliar = datos[auxiliar-1].signombre;
				i++;
			}
			//si pos es mas grande que el arreglo se toma la ultima posicion del arreglo para eliminar
			if(auxiliar==0){
				auxiliar=retardAuxiliar;
				retardAuxiliar=moreRetardAuxiliar;
			}
			//si el arreglo solo tiene una posicion se pasa a eliminar sin problemas
			if(retardAuxiliar==0){
				
			}else{
				//se remplaza el sig del anterior del que se quiere eliminar por el sig del que se va a eliminar
				datos[retardAuxiliar-1].signombre=datos[auxiliar-1].signombre;
				//se busca la carrera que tiene esa persona y dependiendo se selecciona la cabecera
				if (strcoll(datos[auxiliar-1].carrera,"electronica")==0){
					retardAuxiliar=cabecera[1];
					i=1;
				}
				else if (strcoll(datos[auxiliar-1].carrera,"catastral")==0){
					retardAuxiliar=cabecera[2];
					i=2;
				}
				else if (strcoll(datos[auxiliar-1].carrera,"industrial")==0){
					retardAuxiliar=cabecera[3];
					i=3;
				}
				else {//sistemas
					retardAuxiliar=cabecera[4];
					i=4;
				}
				//si el que se desea eliminar esta en la cabecera se remplaza por su siguiente
				if(auxiliar==retardAuxiliar){
					cabecera[i]=datos[auxiliar-1].sigcarrera;
				}else{
					//se busca el que tiene como siguiente el que se va a eliminar
					while(auxiliar!=retardAuxiliar){
						moreRetardAuxiliar=retardAuxiliar;
						retardAuxiliar=datos[retardAuxiliar].sigcarrera;	
					}
					//se remplaza el siguiente por el siguiente del que se va a eliminar
					datos[moreRetardAuxiliar-1].sigcarrera=datos[retardAuxiliar-1].sigcarrera;
				}
				//se busca el hobby que tiene esa persona y dependiendo se selecciona la cabecera
				if (strcoll(datos[auxiliar-1].hobby,"danza")==0){
					retardAuxiliar=cabecera[5];
					i=5;
				}
				else if (strcoll(datos[auxiliar-1].hobby,"natacion")==0){
					retardAuxiliar=cabecera[6];
					i=6;
				}
				else if (strcoll(datos[auxiliar-1].hobby,"basket")==0){
					retardAuxiliar=cabecera[7];
					i=7;
				}
				else {//beisbol
					retardAuxiliar=cabecera[8];
					i=8;
				}
				//si el que se desea eliminar esta en la cabecera se remplaza por su siguiente
				if(auxiliar==retardAuxiliar){
					cabecera[i]=datos[auxiliar-1].sighobby;
				}else{
					//se busca el que tiene como siguiente el que se va a eliminar
					while(auxiliar!=retardAuxiliar){
						moreRetardAuxiliar=retardAuxiliar;
						retardAuxiliar=datos[retardAuxiliar].sighobby;	
					}
					//se remplaza el siguiente por el siguiente del que se va a eliminar
					datos[moreRetardAuxiliar-1].sighobby=datos[retardAuxiliar-1].sighobby;
				}
				//se selecciona la cabecera de la edad
				retardAuxiliar=cabecera[9];
				//si el que se desea eliminar esta en la cabecera se remplaza por su siguiente
				if(auxiliar==retardAuxiliar){
					cabecera[9]=datos[auxiliar-1].sighobby;
				}else{
					//se busca el que tiene como siguiente el que se va a eliminar
					while(auxiliar!=retardAuxiliar){
						moreRetardAuxiliar=retardAuxiliar;
						retardAuxiliar=datos[retardAuxiliar].sigedad;	
					}
					//se remplaza el siguiente por el siguiente del que se va a eliminar
					datos[moreRetardAuxiliar-1].sigedad=datos[retardAuxiliar-1].sigedad;
				}
				
			}//fin del else
			//se corren las personas
			for(i=auxiliar;i<=indice;i++){
				datos[i-1]=datos[i];
			}
			indice--;
			//si el dato no tiene nombre es porque en la lista no hay personas
			if(datos[auxiliar-1].nombre==NULL){
				for(i=0;i<10;i++){
				    cabecera[i]=0;
				}
			}else{
				//todos los que como siguiente tienen un numero mayor al del que se elimino, se resta 1
				//para evitar problemas con el indice
				for(i=1;i<=indice;i++){
					if(auxiliar<datos[i-1].sigcarrera){
						datos[i-1].sigcarrera=(datos[i-1].sigcarrera)-1;
					}
					if(auxiliar<datos[i-1].sigedad){
						datos[i-1].sigedad=(datos[i-1].sigedad)-1;
					}
					if(auxiliar<datos[i-1].sighobby){
						datos[i-1].sighobby=(datos[i-1].sighobby)-1;
					}
					if(auxiliar<datos[i-1].signombre){
						datos[i-1].signombre=(datos[i-1].signombre)-1;
					}
				}
				//se hace lo mismo con las cabeceras
				for(i=0;i<10;i++){
					if(auxiliar<cabecera[i]){
						cabecera[i]=cabecera[i]-1;
					}
				}
			}
		}
		void eliminarByCarrera(int carrera, int pos){
		
		}
		void eliminarByHobbie(int hobbie, int pos){
		
		}
		void eliminarByEdad(int edad, int pos){
		
		}
		
	
		//verifica si la lista está vacía
		bool estaVacia(){
			if(indice==0){
				return true;
			}
			return false;
		}
		//verifica si la lista está llena
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




