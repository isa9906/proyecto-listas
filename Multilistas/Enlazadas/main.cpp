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
ingrediente ing;
receta rec;
Lista<receta> comida;
int i;

int menu(int opcion);
void agregarReceta(char *nombrereceta, char *preparacion, char *nombreing, float cantidad, char *medida,int opcion);
void agregarIngrediente(char *nombreing, float cantidad, char *medida);
void buscarRecetaByNombre(char *nombreReceta);

using namespace std;

int main(int argc, char** argv) {
	//Variables
	char *nombrereceta, *preparacion, *nombreing, *medida;
	float cantidad;
	int c=1,opcion=-1,i,numPers=0;
	//inicializando arreglos de char
	nombrereceta = new char[BUFFER_SIZE];
	preparacion = new char[BUFFER_SIZE];
	nombreing = new char[BUFFER_SIZE];
	medida = new char[BUFFER_SIZE];

	while(c!=0){
		switch(menu(opcion)){
				case 1: //Agregar receta
					agregarReceta(nombrereceta,preparacion,nombreing,cantidad,medida, opcion);
				break;
				case 2: // Eliminar
				
				break;
				case 3: //Listar por edad
				
				break;
				case 4: //Buscar receta por nombre
					buscarRecetaByNombre(nombrereceta);
				break;
				case 5: //Listar por hobbie
					
				break;
				default: cout<<"Dato erroneo";
		}
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
void agregarReceta(char *nombrereceta, char *preparacion, char *nombreing, float cantidad, char *medida,int opcion){
	cout<<endl<<"Ingrese nombre de la receta: ";
	cin>>nombrereceta;
	rec.nombre=nombrereceta;
	cout<< "Ingrese la preparacion: ";
	cin>>preparacion;
	rec.preparacion=preparacion;
	opcion=-1;
	do{
		cout<<"Ingrese los datos del ingrediente: "<<endl;	
		agregarIngrediente(nombreing,cantidad,medida);
		cout<<endl<<"Si desea agregar otro ingrediente ingrese un numero distinto a 0: ";
		cin>>opcion;	
	}while (opcion!=0);
	comida.anadir_inicio(rec);
		
}
void agregarIngrediente(char *nombreing, float cantidad, char *medida){
	cout<<"\tIngrese nombre del ingrediente: ";
	cin>>nombreing;
	ing.nombre=nombreing;
	cout<< "\tIngrese la cantidad: ";
	cin>>cantidad;
	ing.cant=cantidad;
	cout<< "\tIngrese la medida: ";
	cin>>medida;
	ing.medida=medida;
	rec.ing.anadir_inicio(ing);
}

void buscarRecetaByNombre(char *nombreReceta){
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
		ingrediente ing_ = rec.ing.devolverDato(i);
		cout<<endl<<"\t\tNombre ingrediente: "<<ing_.nombre<<endl;
		cout<<"\t\tCantidad: "<<ing_.cant<<endl;
		cout<<"\t\tMedida: "<<ing.medida<<endl<<endl;
	}
}

