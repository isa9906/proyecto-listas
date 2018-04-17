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

int menu(int opcion);
void agregarReceta(char *nombrereceta, char *preparacion, char *nombreing, float cantidad, char *medida,int opcion);
void agregarIngrediente(char *nombreing, float cantidad, char *medida);
using namespace std;
int main(int argc, char** argv) {
	//Variables
	Lista<receta> comida;
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
				case 3: //Listar por edad
				
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




	
// LO NUEVO	
	ingrediente ing1;
	ing1.nombre= "cebolla";
	ing1.cant= 5;
	ing1.medida= "unidades";
	
	receta rec;
	rec.nombre="arroz al ajillo";
	rec.preparacion="bla bla bla ";
	
	rec.ing.anadir_inicio(ing1);
	rec.ing.anadir_inicio(ing1);
	
	comida.anadir_inicio(rec);
	
	//buscar receta segun nombre

	i=0;
	receta temp;
	while (i!=comida.getTam()){
		
		 temp = comida.devolverDato(i);
		
		if(strcoll(temp.nombre,"arroz al ajillo")==0){
			break;
		}
		i++;
	}
	
	cout<<temp.nombre<<endl;
		ingrediente temp1;
	for(i=0;i<temp.ing.getTam();i++){
		temp1=temp.ing.devolverDato(i);
		cout<<temp1.nombre<<endl;
		cout<<temp1.cant<<endl;
		cout<<temp1.medida<<endl;
	}
	
	// buscar recetas desde ingrediente
	
	int j;
	for (i=0;i<comida.getTam();i++){
		 temp = comida.devolverDato(i);
		 temp1=temp.ing.devolverDato(i);
		for (j=0;j<temp.ing.getTam();j++){
			if(strcoll(temp1.nombre,"cebolla")==0){
				cout<<temp.nombre<<endl;
			}
		}
	}		
//seccion de uso de listas de estructuras
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
		cout<<"Ingrese los datos del ingrediente: ";	
		agregarIngrediente(nombreing,cantidad,medida);
		cout<<"Si desea agregar otro ingrediente ingrese un numero distinto a 0";
		cin>>opcion;	
	}while (opcion!=0);
		
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

