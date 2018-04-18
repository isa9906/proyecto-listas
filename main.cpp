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
ingrediente ing;
receta rec;
Lista<receta> comida;
int menu(int opcion);
void agregarReceta(char *nombrereceta, char *preparacion, char *nombreing, float cantidad, char *medida,int opcion);
void agregarIngrediente(char *nombreing, float cantidad, char *medida);
int menuModificarReceta(int opcion);
int menuModificarIngrediente(int opcion);
void modificarrect(int opcion);
using namespace std;
int main(int argc, char** argv) {
	//Variables
	
	char *nombrereceta, *preparacion, *nombreing, *medida;
	float cantidad;
	int c=1,opcion=-1,i,numPers=0;

	while(c!=0){
		switch(menu(opcion)){
				case 1: //Agregar receta
					agregarReceta(nombrereceta,preparacion,nombreing,cantidad,medida, opcion);
				break;
				case 2: // Eliminar
				
				break;
				case 3: //modificar receta
					modificarrect(opcion);
					break;
				case 4: //Listar por nombre
					
				
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
	cout<<"1.Agregar receta"<<endl<<"2. Eliminar receta"<<endl<<"3. Modificar receta";
	cout<<endl<<"4. Buscar receta dado el nombre"<<endl<<"5. Buscar receta dado el ingrediente"<<endl;
	cout<<endl<<"Opcion: ";
	cin>>opcion;
	return opcion;
}
void agregarReceta(char *nombrereceta, char *preparacion, char *nombreing, float cantidad, char *medida,int opcion){
	cout<< "Ingrese nombre de la receta: ";
	cin>>nombrereceta;
	rec.nombre=nombrereceta;
	cout<< "Ingrese la preparacion: ";
	cin>>preparacion;
	rec.preparacion=preparacion;
	opcion=-1;
	
	do{
		cout<<"Ingrese los datos del ingrediente: "<<endl;	
		agregarIngrediente(nombreing,cantidad,medida);
		cout<<"Si desea agregar otro ingrediente ingrese un numero distinto a 0";
		cin>>opcion;	
	}while (opcion!=0);
	comida.anadir_inicio(rec);

}
void agregarIngrediente(char *nombreing, float cantidad, char *medida){
	cout<< "Ingrese nombre del ingrediente: ";
	cin>>nombreing;
	ing.nombre=nombreing;
	cout<< "Ingrese la cantidad: ";
	cin>>cantidad;
	ing.cant=cantidad;
	cout<< "Ingrese la medida: ";
	cin>>medida;
	ing.medida=medida;
	rec.ing.anadir_inicio(ing);
}
void modificarrect(int opcion){
	char *nombrec;
	cout<<"Ingrese el nombre de la receta que desea modificar: "<<endl;
	cin>>nombrec;
	int i;
	i=0;
	while(true){
		if(strcoll(comida.devolverDato(i).nombre,nombrec)==0){
			break;
		}
		else if (i==comida.getTam()){
			cout<<"No hay una receta con estas especificaciones";
			return;		
		}
		else {
			i++;
		}
	}
	receta temprec= comida.devolverDato(i);
	switch(menuModificarReceta(opcion)){
		case 1://modifica nombre de la receta
			char *nombrenuevo;
			cin>>nombrenuevo;
			temprec.nombre=nombrenuevo;
			comida.modificar(temprec,i);
			break;
		case 2://modifica la preparacion de la receta
			char *preparacionnuevo;
			cin>>preparacionnuevo;
			temprec.preparacion=preparacionnuevo;
			
			break;
		case 3://modifica los ingredientes de la receta
		
			char *nombreing;
			cout<<"Ingrese el nombre del ingrediente que desea modificar: "<<endl;
			cin>>nombreing;
			int j=0;
			while(true){
				if(strcoll(temprec.ing.devolverDato(j).nombre,nombrec)==0){
					break;
				}
				else if (j==temprec.ing.getTam()){
					cout<<"No hay un ingrediente con estas especificaciones";
					return;		
				}
				else {
					j++;
				}
			}
			ingrediente temping= temprec.ing.devolverDato(j);
			switch(menuModificarIngrediente(opcion)){
				case 1:
					char *nombreing;
					cin>>nombreing;
					temping.nombre=nombreing;
					temprec.ing.modificar(temping,j);
					break;
				case 2:
					float cantidad;
					cin>>cantidad;
					temping.cant=cantidad;
					temprec.ing.modificar(temping,j);
					break;
				case 3:
					char *medida;
					cin>>medida;
					temping.medida=medida;
					temprec.ing.modificar(temping,j);
					break;
			}
			comida.modificar(temprec,i);
		break;		
	}
}
int menuModificarReceta(int opcion){
	cout<<"¿Que desea modificar?"<<endl;
	cout<<"1. nombre de la receta"<<endl;
	cout<<"2. preparacion de la receta"<<endl;
	cout<<"3. algo relacionado a los ingredientes"<<endl;
	cin>>opcion;
	return opcion;	
}
int menuModificarIngrediente(int opcion){
	cout<<"¿Que desea modificar?"<<endl;
	cout<<"1. nombre del ingrediente"<<endl;
	cout<<"2. cantidad"<<endl;
	cout<<"3. medida"<<endl;
	cin>>opcion;
	return opcion;	
}










