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
void eliminarIngrediente();
void eliminarReceta();
int menuModificarReceta(int opcion);
int menuModificarIngrediente(int opcion);
void modificarrect(int opcion);

using namespace std;

int main(int argc, char** argv) {
	int c=1,opcion=-1;
	while(c!=0){
		cout<<"NOTA: ESTE PROGRAMA NO ADMITE ESPACIOS EN CADENAS DE CARACTERES; SE DEBE ESCRIBIR POR EJEMPLO: Huevos-pericos";
		switch(menu(opcion)){
				case 1: //Agregar receta
					agregarReceta(opcion);
				break;
				case 2: // Eliminar un receta
					eliminarReceta();
				break;
				case 3: //modificar receta
					modificarrect(opcion);
				break;
				case 4: //Buscar receta por nombre
					buscarRecetaByNombre();
				break;
				case 5: //Buscar recetas por ingredientes
					buscarRecetasByIngrediente();
				break;
				case 6: //Eliminar un ingrediente de una receta
					eliminarIngrediente();
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
	cout<<endl<<"4. Buscar receta dado el nombre"<<endl<<"5. Buscar receta dado el ingrediente"<<endl<<"6. Eliminar un ingrediente de una receta"<<endl;
	cout<<endl<<"Opcion: ";
	cin>>opcion;
	return opcion;
}

void modificarrect(int opcion){
	char *nombrec;
	nombrec= new char [BUFFER_SIZE];
	cout<<"Ingrese el nombre de la receta que desea modificar: "<<endl;
	cin>>nombrec;
	int i;
	i=0;
	while(true){
		if(strcoll(comida.devolverDato(i).nombre,nombrec)==0){
			cout<<"RECETA ENCONTRADA"<<endl;
			break;
		}
		else if (i==comida.getTam()){
			cout<<"No hay una receta con estas especificaciones"<<endl;
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
			nombrenuevo= new char [BUFFER_SIZE];
			cout<<"Ingrese nuevo nombre";
			cin>>nombrenuevo;
			temprec.nombre=nombrenuevo;
			comida.modificar(temprec,i);
			break;
		case 2://modifica la preparacion de la receta
			char *preparacionnuevo;
			preparacionnuevo= new char [BUFFER_SIZE];
			cout<<"Ingrese nueva preparaci�n: ";
			cin>>preparacionnuevo;
			temprec.preparacion=preparacionnuevo;
			
			break;
		case 3://modifica los ingredientes de la receta
		
			char *nombreing;
			nombreing = new char[BUFFER_SIZE];
			cout<<"Ingrese el nombre del ingrediente que desea modificar: ";
			cin>>nombreing;
			int j=0;
			while(true){
				if(strcoll(temprec.ing.devolverDato(j).nombre,nombreing)==0){
					break;
				}
				else if (j==temprec.ing.getTam()){
					cout<<"No hay un ingrediente con estas especificaciones"<<endl;
					return;		
				}
				else {
					j++;
				}
			}
			ingrediente temping= temprec.ing.devolverDato(j);
			switch(menuModificarIngrediente(opcion)){
				case 1:
					char *nombreingnuevo;
					nombreingnuevo=new char [BUFFER_SIZE];
					cout<<"Ingrese el nuevo nombre del ingrediente: ";
					cin>>nombreingnuevo;
					
					temping.nombre=nombreingnuevo;
					temprec.ing.modificar(temping,j);
					break;
				case 2:
					float cantidad;
					cout<<"Ingrese la nueva cantidad del ingrediente: ";
					cin>>cantidad;
					temping.cant=cantidad;
					temprec.ing.modificar(temping,j);
					break;
				case 3:
					char *medidanueva;
					medidanueva=new char [BUFFER_SIZE];
					cout<<"Ingrese la nueva medida del ingrediente: ";
					cin>>medidanueva;
					temping.medida=medidanueva;
					temprec.ing.modificar(temping,j);
					break;
			}
			comida.modificar(temprec,i);
		break;		
	}
	cout<<"RECETA MODIFICADA CON EXITO";
}

int menuModificarReceta(int opcion){
	cout<<"�Que desea modificar?"<<endl;
	cout<<"1. nombre de la receta"<<endl;
	cout<<"2. preparacion de la receta"<<endl;
	cout<<"3. algo relacionado a los ingredientes"<<endl;
	cin>>opcion;
	return opcion;	
}

int menuModificarIngrediente(int opcion){
	cout<<"�Que desea modificar?"<<endl;
	cout<<"1. nombre del ingrediente"<<endl;
	cout<<"2. cantidad"<<endl;
	cout<<"3. medida"<<endl;
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
	if(comida.getTam()>0){
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
					cout<<"El nombre de receta no coincide con ninguna receta"<<endl;
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
	else{
		cout<<endl<<"No hay recetas"<<endl;
	}
	
}

void buscarRecetasByIngrediente(){
	if(comida.getTam()>0){
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
			cout<<endl<<"No exite ninguna receta con ese ingrediente"<<endl;
			return;
		}
		else{
			imprimirRecetas(arrayRecetas);
		}
		
	}
	else{
		cout<<"No hay recetas"<<endl;
	}
	
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

void eliminarReceta(){
	if(comida.getTam()>0){
		char *nombreReceta;
		nombreReceta = new char[BUFFER_SIZE];
		cout<<"Digite el nombre de la receta: ";
		cin>>nombreReceta;
		//se busca la receta
		i=0;
		receta rec_;
		for(i=0;i<comida.getTam();i++){
			rec_ = comida.devolverDato(i);
			if(strcoll(rec_.nombre,nombreReceta)==0){
				break;
			}
			else{
				if(i+1==comida.getTam()){
					cout<<"El nombre de receta no coincide con ninguna receta"<<endl;
					return;
				}
			}
		}
		comida.eliminar_posicion(i);
		cout<<endl<<"Receta eliminada"<<endl;
	}
	else{
		cout<<"No hay recetas"<<endl;
	}
	
}

void eliminarIngrediente(){
	if(comida.getTam()>0){
		int j;
		char *nombreReceta, *nombreIngrediente;
		nombreReceta = new char[BUFFER_SIZE];
		nombreIngrediente = new char[BUFFER_SIZE];
		cout<<"Digite el nombre de la receta: ";
		cin>>nombreReceta;
		//se busca la receta
		i=0;
		receta rec_;
		for(i=0;i<comida.getTam();i++){
			rec_ = comida.devolverDato(i);
			if(strcoll(rec_.nombre,nombreReceta)==0){
				break;
			}
			else{
				if(i+1==comida.getTam()){
					cout<<"El nombre de receta no coincide con ninguna receta"<<endl;
					return;
				}
			}
		}
		if(rec_.ing.getTam()>0){
			cout<<"Digite el nombre del ingrediente: ";
			cin>>nombreIngrediente;
			//se busca el ingrediente dentro de la receta
			j=0;
			ingrediente ing_;
			for(j=0;j<rec_.ing.getTam();j++){
				ing_ = rec_.ing.devolverDato(j);
				if(strcoll(ing_.nombre,nombreIngrediente)==0){
					break;
				}
				else{
					if(j+1==rec_.ing.getTam()){
						cout<<"El nombre del ingrediente no coincide con ninguna receta"<<endl;
						return;
					}
				}
			}
			rec_.ing.eliminar_posicion(j);
			comida.eliminar_posicion(i);
			comida.anadir_posicion(rec_,i);
			cout<<endl<<"Ingrediente eliminado"<<endl;
		}
		else{
			cout<<"No hay ingredientes en esta receta"<<endl;
		}
		
	}
	else{
		cout<<"No hay recetas"<<endl;
	}
	
}
