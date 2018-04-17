#include <iostream>
#include <string.h>
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
		int tam;        //determina el tama√±o limite de personas
		int indice;		//determinar la posici√≥n en la que va el arreglo de personas
		int indiceindust,indicecatast,indicesist,indiceelec;//indices para manejar carreras
		int indicenat,indicebask,indicedan,indicebase;//indices para manejar hobbies
		int i;
		int numPers;
		
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
		//se elimina segun la lista de nombre
		void eliminarByNombre(int pos){
			int j;
			Persona *lista;
			lista = listarByNombre();
			backEliminar(lista,pos);
		}
	
		//se elimina segun la lista de edad
		void eliminarByEdad(int pos){
			int j;
			Persona *lista;
			lista = listarByEdad();
			backEliminar(lista,pos);
		}
		//se elimina segun la lista de carreras
		void eliminarByCarrera(int lista,int pos){
			Persona *list;
			switch(lista){
				case 1: //Sistemas
					list = listarByCarrera(1);
				break;
				case 2: //Catastral
					list = listarByCarrera(2);
				break;
				case 3: //ElectrÛnica
					list = listarByCarrera(3);
				break;
				case 4: //Industrial
					list = listarByCarrera(4);
				break;
			}
			backEliminar(list,pos);
		}
		//Se elimina seg˙n lista de hobbie
		void eliminarByHobby(int lista,int pos){
			Persona *list;
			switch(lista){
				case 5: //Natacion
					list = listarByHobby(1);
				break;
				case 6: //Basket
					list = listarByHobby(2);
				break;
				case 7: //Danza
					list = listarByHobby(3);
				break;
				case 8: //Baseball
					list = listarByHobby(4);
				break;
			}
			backEliminar(list,pos);
		}
		//funciÛn para comparar estructuras
		bool compareE(Persona per1,Persona per2){
			if(strcoll(per1.nombre,per2.nombre)==0 && strcoll(per1.carrera,per2.carrera)==0 && strcoll(per1.hobby,per2.hobby)==0 &&
			per1.edad == per2.edad && per1.signombre == per2.signombre && per1.sigedad == per2.sigedad && per1.sigcarrera == per2.sigcarrera &&
			per1.sighobby == per2.sighobby){
				return true;
			}
			return false;
		}
	
		//para ver quÈ hace exactamente esta funcion ver cada una de las funciones de eliminar
		void backEliminar(Persona *lista,int pos){
			int j;
			Persona persona = lista[pos-1]; //persona a la que se quiere eliminar
			i = 0;
			//el ciclo encuentra la posicion en donde se encuentra el elemento a eliminar
			while(true){
				if(compareE(persona,datos[i])){
					break;
				}
				i++;		
			}
			datos[i].edad = 0; //centinela que indica que esta persona se va a eliminar, lo hago porque no me deja hacer datos[i] = NULL
			//en el arreglo person se copian todos los elementos de datos pero sin el elemento que se elimina
			Persona *person;
			person = new Persona[numPers];
			int k=0;
			for(j=0;j<indice;j++){
				if(datos[j].edad!=0){
					person[k] = datos[j];
					k++;
				}
			}
			//se hace de cuenta que la lista esta vacia
			indice = 0;
			//indices de carreras
			indicecatast = 0;
			indiceindust = 0;
			indicesist = 0;
			indiceelec = 0;
			//indices de hobbie
			indicebase = 0;
			indicenat = 0;
			indicebask = 0;
			indicenat = 0;
			
			//e insertamos todos los elementos que quedaron, asÌ la funcion insertar
			//se encargara de la cuestion de los siguientes
			for(i=0;i<k;i++){
				insertar(person[i]);
			}
		}
		
		
	public:	
		//Constructor
		multilista(int numPersonas){
			numPers = numPersonas;
			cabecera= new int [10];
			for(i=0;i<10;i++){
				cabecera[i] = 0;
			}
			datos = new Persona [numPers]; 
			indice=0;
			indiceindust=0;
			indicecatast=0;
			indicesist=0;
			indiceelec=0;//indices para manejar carreras
			indicenat=0;
			indicebask=0;
			indicedan=0;
			indicebase=0;//indices para manejar hobbies
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
				ordenarByNombre(persona.nombre,anterior,actual); //se ordena por nombre alfab√©ticamente
				ordenarByEdad (persona.edad,anterior,actual); //se ordena por edad de mayor a menor
				ordenarByHobbie(persona.hobby,actual); //se pone a la cabeza
				ordenarByCarrera(persona.carrera,actual,anterior); //se pone al final 
			}
			indice++;
			//indices de las carreras
			if (strcoll(persona.carrera,"electronica")==0){
					indiceelec++;;
			}
			else if (strcoll(persona.carrera,"catastral")==0){
				indicecatast++;
			}
			else if (strcoll(persona.carrera,"industrial")==0){
				indiceindust++;
			}
			else {//sistemas
				indicesist++;
			}
			//indices de los hobbies
			if (strcoll(persona.hobby,"danza")==0){
					indicedan++;
				}
				else if (strcoll(persona.hobby,"natacion")==0){
					indicenat++;
				}
				else if (strcoll(persona.hobby,"basket")==0){
					indicebask++;
				}
				else {//beisbol
					indicebase++;
				}
		}
		
		//funciona 
		Persona *listarByNombre(){
			int i;
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

		//funciona
		Persona  *listarByEdad(){
			int i = 0;
			int actual;
			Persona *lista;
			lista= new Persona[indice];
			actual=cabecera[9];
			i=0;
			while(actual!=0){
				lista[i]=datos[actual-1];
				actual=datos[actual-1].sigedad;
				i++;
			}
			return lista;
		}

		//eliminar
		void eliminar(int lista, int pos){
			lista=lista-1;
			if(lista==0){
				eliminarByNombre(pos);	
			}
			else if(lista>=1&&lista<=4){
				eliminarByCarrera(lista, pos);
			}
			else if(lista>=5&&lista<=8){	
				eliminarByHobby(lista, pos);
			}
			else if(lista==9){
				eliminarByEdad(pos);
			}
		}
		Persona  *listarByHobby(int hobby){
			int actual;
			Persona *lista;
		    //1 Se enlista por nataci√≥n
			  // 2 se enlista por basket
		    // 3 Se enlista por danza
			  // 4 Se enlista por baseball
				switch (hobby){
				case 1:
					actual=cabecera[6];
					lista= new Persona [indicenat];
				break;
				case 2:
					actual=cabecera[7];
					lista= new Persona [indicebask];
				break;
				case 3:
					actual=cabecera[5];
					lista= new Persona [indicedan];	
					break;
				case 4:
					actual=cabecera[8];
					lista= new Persona [indicebase];
				break;
			}
			i=0;
			while(actual!=0){
				lista[i]=datos[actual-1];
				actual=datos[actual-1].sighobby;
				i++;
			}
			return lista;
		}
	
		Persona  *listarByCarrera(int carrera){
			int actual;
			Persona *lista;
			// 1 Se enlista por sistemas	
		  // 2 Se enlista por castral
		  // 3 Se enlista por electr√≥nica
		  // 4 Se enlista por industrial
			switch (carrera){
				case 1:
					actual=cabecera[4];
					lista= new Persona [indicesist];
				break;
				case 2:
					actual=cabecera[2];
					lista= new Persona [indicecatast];
				break;
				case 3:
					actual=cabecera[1];
					lista= new Persona [indiceelec];	
					break;
				case 4:
					actual=cabecera[3];
					lista= new Persona [indiceindust];
				break;
			}
			i=0;	
			while(actual!=0){
				lista[i]=datos[actual-1];
				actual=datos[actual-1].sigcarrera;
				i++;
			}
			return lista;
		}

		//verifica si la lista est√° vac√≠a
		bool estaVacia(){
			if(indice==0){
				return true;
			}
			return false;
		}
		//verifica si la lista est√° llena
		bool estaLlena(){
			if(indice==(tam-1)){
				return true;
			}
			return false;
		}
		void decreaseIndice(){
			indice = indice - 1;
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




