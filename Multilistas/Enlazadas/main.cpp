#include <iostream>
#include "Lista.h"
#include <string.h>

struct ingrediente{
		char *nombre;
		float cant;
		char *medida;
	};

struct receta {
	char *nombre;
	char *preparacion;
	Lista <ingrediente> ing;
};

const size_t BUFFER_SIZE = 1024;
Lista<receta> comida;
int i;

int menu(int opcion);
void agregarReceta(int opcion);
ingrediente agregarIngrediente();
void buscarRecetaByNombre();
void buscarRecetasByIngrediente();
void imprimirRecetas(Lista<receta> rec_);

using namespace std;

int main(int argc, char** argv) {

	int c=1,opcion=-1,i,numPers=0;
	

	while(c!=0){
		switch(menu(opcion)){
				case 1: //Agregar receta
					agregarReceta(opcion);
				break;
				case 2: // Eliminar
				
				break;
				case 3: //Listar por edad
				
				break;
				case 4: //Buscar receta por nombre
					buscarRecetaByNombre();
				break;
				case 5: //Buscar recetas por ingredientes
					buscarRecetasByIngrediente();
				break;
				default: cout<<"Dato erroneo";
		}
		cout<<endl<<"RECETAS"<<endl;
		cout<<"Para repetir el menu digite cualquier tecla diferente de 0: ";
		cin>>c;	
		system("CLS");
	}
}		

int menu(int opcion){
	//system("CLS");
	cout<<endl<<"Digite una opcion"<<endl;
	cout<<"1. Agregar receta"<<endl<<"2. Eliminar receta"<<endl<<"3. Modificar receta";
	cout<<endl<<"4. Buscar receta dado el nombre"<<endl<<"5. Buscar receta dado el ingrediente"<<endl;
	cout<<endl<<"Opcion: ";
	cin>>opcion;
	return opcion;
}
void agregarReceta(int opcion){
	float cantidad;
	//Variables
	char *nombrereceta, *preparacion;
	//inicializando arreglos de char
	nombrereceta = new char[BUFFER_SIZE];
	preparacion = new char[BUFFER_SIZE];
	receta rec;
	cout<<endl<<"Ingrese nombre de la receta: ";
	cin>>nombrereceta;
	rec.nombre=nombrereceta;
	cout<< "Ingrese la preparacion: ";
	cin>>preparacion;
	rec.preparacion=preparacion;
	opcion=-1;
	do{
		cout<<"Ingrese los datos del ingrediente: "<<endl;
		rec.ing.anadir_inicio(agregarIngrediente());	
		cout<<endl<<"Si desea agregar otro ingrediente ingrese un numero distinto a 0: ";
		cin>>opcion;	
	}while (opcion!=0);
	comida.anadir_inicio(rec);
}
ingrediente agregarIngrediente(){
	float cantidad;
	char *nombreing, *medida;
	nombreing = new char[BUFFER_SIZE];
	medida = new char[BUFFER_SIZE];
	ingrediente ingrediente_;
	cout<<"\tIngrese nombre del ingrediente: ";
	cin>>nombreing;
	ingrediente_.nombre=nombreing;
	cout<< "\tIngrese la cantidad: ";
	cin>>cantidad;
	ingrediente_.cant=cantidad;
	cout<< "\tIngrese la medida: ";
	cin>>medida;
	ingrediente_.medida=medida;
	return ingrediente_;
}

void buscarRecetaByNombre(){
	char *nombreReceta;
	nombreReceta = new char[BUFFER_SIZE];
	cout<<"Digite el nombre de la receta: ";
	cin>>nombreReceta;
	i=0;
	receta rec_;
	for(i=0;i<comida.getTam();i++){
		rec_ = comida.devolverDato(i);
		if(strcoll(rec_.nombre,nombreReceta)==0){
			break;
		}
		else{
			if(i+1==comida.getTam()){
				cout<<"El nombre de receta no coincide con ninguna receta";
				return;
			}
		}
	}
	cout<<endl<<"RECETA ENCONTRADA:"<<endl<<"\tNombre de la receta: "<<rec_.nombre<<endl<<"\tPreparacion: "<<rec_.preparacion<<endl;
	cout<<endl<<"\tINGREDIENTES:"<<endl;
	for(i=0;i<rec_.ing.getTam();i++){
		ingrediente ing_ = rec_.ing.devolverDato(i);
		cout<<endl<<"\t\tNombre ingrediente: "<<ing_.nombre<<endl;
		cout<<"\t\tCantidad: "<<ing_.cant<<endl;
		cout<<"\t\tMedida: "<<ing_.medida<<endl<<endl;
	}
}

void buscarRecetasByIngrediente(){
	char *nomIngrediente;
	nomIngrediente = new char[BUFFER_SIZE];
	Lista<receta> arrayRecetas;
	receta rec_;
	ingrediente ing_;
	cout<<endl<<"Digite el nombre del ingrediente: ";
	cin>>nomIngrediente;
	for(i=0;i<comida.getTam();i++){ //se recorren las recetas
		rec_ = comida.devolverDato(i);
		for(int j=0;j<rec_.ing.getTam();j++){ //se recorren los ingredientes de cada receta
			ing_ = rec_.ing.devolverDato(j);
			if(strcoll(nomIngrediente,ing_.nombre)==0){ //se verifica si coincide el nombre
				arrayRecetas.anadir_inicio(rec_);
			}
		}
	}
	if(arrayRecetas.getTam()==0){
		cout<<endl<<"No exite ninguna receta con ese ingrediente";
		return;
	}
	imprimirRecetas(arrayRecetas);
}

void imprimirRecetas(Lista<receta> rec_){
	int j;
	receta a;
	for(i=0;i<rec_.getTam();i++){
		a = rec_.devolverDato(i);
		cout<<endl<<"\tNombre de la receta: "<<a.nombre<<endl<<"\tPreparacion: "<<a.preparacion<<endl;
		cout<<endl<<"\tINGREDIENTES:"<<endl;
		for(j=0;j<a.ing.getTam();j++){
			ingrediente ing_ = a.ing.devolverDato(j);
			cout<<endl<<"\t\tNombre ingrediente: "<<ing_.nombre<<endl;
			cout<<"\t\tCantidad: "<<ing_.cant<<endl;
			cout<<"\t\tMedida: "<<ing_.medida<<endl<<endl;
		}
	}
	
}

