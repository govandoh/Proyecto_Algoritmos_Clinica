#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <cstring>    
#include <bits/stdc++.h>

using namespace std;

int opcion;

class Proyecto {
public:
	void crearFichero(FILE* fichero_Paciente);
	void registrarPaciete(FILE* fichero_Paciente);
	void eliminar();
	void consultarTodos();
	void generarVisita();
	void consultaVisita();
	void caratula();
	void menu();
	void enca();
	//Colores para pintar letras de consola
	string negro = "\u001B[30m";
	string rojo = "\u001B[31m";
	string verde = "\u001B[32m";
	string amarillo = "\u001B[33m";
	string azul = "\u001B[34m";
	string purpura = "\u001B[35m";
	string cielo = "\u001B[36m";
	string blanco = "\u001B[37m";
	string salto = "\n";
};


struct Paciente {
	float codigo_Paciente;
	char dpi[14];
	char nombre[25];
	char apellido[25];
	char sexo[13];
	int  edad;
	char seguro_medico[50];
	char estado_Clinico[50];
	char direccion[50];
}registroPa;

struct Consulta{
	int id;
	char fecha[10];
	char nombre[15];
	char tipo[10];
	int habitacion;
	int cama;
}visitaReg;

int salida = 0;
FILE *fichero_Paciente;
int i;

//Agregue funcion para generar un archivo de paciente
void Proyecto::crearFichero(FILE* fichero_Paciente) {
	fichero_Paciente = fopen("Paciente.txt", "r");
	if (!fichero_Paciente) {
		fichero_Paciente = fopen("Paciente.txt", "w");
		printf("\nArchivo creado! \n");
	}
	else {
		cout << rojo << ("\nEl fichero ya existe! \n") << rojo;
	}
	fclose(fichero_Paciente);
}


//28/10/21 - 12:00 :  Agregue funcion para buscar a todos los pacientes o solo a uno

void Proyecto::consultarTodos(){
	system("cls");
	string linea;
	ifstream fichero("Paciente.txt");
	
	Proyecto p = Proyecto();
	
	p.enca();
	int contador = 1;
	while(getline(fichero,linea)){
		cout<<contador<<")  "<<linea << "\n";
		contador++;
	}
	
	cout<<salto<<salto;
	getchar();
}



void Proyecto::generarVisita(){
	system("cls");
	
	
	// Leemos el archivo del contador para generar el ID
	ifstream contador("contador.txt");
	int id = 0;
	contador>>id;
	contador.close();
	remove("contador.txt");
	//Incrementamos para volver a guardar
	id++;
	ofstream nuevoContador("contador.txt", ios::out | ios::app);
	nuevoContador<<id;
	nuevoContador.close();
	
	//Creamos el archivo para la consulta
	string nombre = "consultas//Consulta"+ std::to_string(id) + ".txt";
	ofstream consulta(nombre, ios::out | ios::app);
		
	cout<<"Su Numero de visita es "<<id<<endl;
	cout<<"Ingrese la fecha de visita: ";
	cin>>visitaReg.fecha; cout<<"---------------------------------- \n";
	cout<<"Ingrese el nombre del paciente: ";
	fflush(stdin);
	scanf("%[^\n]15s",visitaReg.nombre); cout<<"---------------------------------- \n";//scanf("%[^\n]15s",visitaReg.nombre); cout<<"---------------------------------- \n";
	cout<<"Ingrese tipo de consulta: ";
	cin>>visitaReg.tipo; cout<<"---------------------------------- \n"; //scanf("%[^\n]10s", visitaReg.tipo); cout<<"---------------------------------- \n";
	cout<<"Ingrese habitacion asignada: ";
	cin>>visitaReg.habitacion; cout<<"---------------------------------- \n";
	cout<<"Ingrese cama asignada: ";
	cin>>visitaReg.cama; cout<<"---------------------------------- \n";
	cout<<"\nSe genero su visita correctamente ";
	
	
	
	consulta<<id << " - " << visitaReg.fecha << " - " << visitaReg.nombre << " - " << visitaReg.tipo << " - " << visitaReg.habitacion << " - " <<visitaReg.cama;
	consulta.close();

}

void Proyecto::consultaVisita(){
	system("cls");
	
	string visitaNo, datoRecuperado;
	
	cout<<"Ingrese el numero de visita: ";
	cin>>visitaNo;
	
	ifstream visita("consultas//Consulta"+visitaNo + ".txt");

	cout<< " \n\n----- Resultados de la visita numero " <<visitaNo << "  ----- \n\n";
	
	cout<<"\nID - Fecha -   Paciente   -  Tipo Cita  - Habitacion  -  Cama\n";
	
	
		
	while(getline(visita,datoRecuperado)){
		cout<< datoRecuperado;
	}
	
	cout<<salto<<salto;
}

void Proyecto::enca() { 
	printf("********************************************\n");
	printf("No.Cama: 	   No.DPI:		 Nombre:       Apellido:	  Genero:      Edad:	 Seguro Medico:     Estado Clinico:	    Dirección\n"); 
} 


void Proyecto::menu() {
	cout << amarillo << "\n------- MENU PRINCIPAL --------";
	cout << amarillo << "\n1 - Crear un Fichero de Pacientes \n";
	cout << amarillo << "2 - Insert un Paciente nuevo \n";
	cout << amarillo << "3 - Ver Pasientes \n";
	cout << amarillo << "4 - Generar Visita\n";
	cout << amarillo << "5 - Ver Visita \n";
	cout << amarillo << "6 - Salir \n";
}

void Proyecto::registrarPaciete(FILE *fichero_Paciente) {
	system("cls");
	fichero_Paciente = fopen("Paciente.txt", "a+");
	if(fichero_Paciente == NULL){
		printf("\nFichero no existe! \nPor favor 	creelo"); 
  		return; 
	}
	cout<<("\nREGISTRO DE PACIENTE! \n");
	printf("******************************\n");
	printf("Codigo de Paciente: ");
	cin>>registroPa.codigo_Paciente; cout<<"---------------------------------- \n";
	printf("NO. DPI: ");
	cin>>registroPa.dpi; cout<<"---------------------------------- \n";
	printf("NOMBRE: ");
	cin>>registroPa.nombre; cout<<"---------------------------------- \n";
	printf("APELLIDO: ");
	cin>>registroPa.apellido;cout<<"---------------------------------- \n";
	printf("SEXO: ");
	cin>>registroPa.sexo;cout<<"---------------------------------- \n";
	printf("EDAD: ");
	cin>>registroPa.edad;cout<<"---------------------------------- \n";
	cout<<("SEGURO MEDICO: ");
	cin>>registroPa.seguro_medico;cout<<"---------------------------------- \n";
	printf("ESTADO CLINICO: ");
	cin>>registroPa.estado_Clinico;cout<<"---------------------------------- \n";
	printf("DIRECCION: ");
	//
	fflush(stdin);
	scanf("%[^\n]25s",registroPa.direccion);
	
	ofstream fpaciente("Paciente.txt", ios::out | ios::app);
	fpaciente<<"\n";
	fpaciente<<registroPa.codigo_Paciente<<"  ";
	fpaciente<<registroPa.dpi<<"   ";
	fpaciente<<registroPa.nombre<<"   ";
	fpaciente<<registroPa.apellido<<"   " ;
	fpaciente<<registroPa.sexo<<"   ";
	fpaciente<<registroPa.edad<<"   ";
	fpaciente<<registroPa.seguro_medico<<"  ";
	fpaciente<<registroPa.estado_Clinico<<"  ";
	fpaciente<<registroPa.direccion<<"  ";
	fpaciente<<"\n";
	fpaciente.close();
}
void Proyecto::caratula() {
	system("cls");


	cout << verde << "*********************************************" << salto;
	cout << verde << "**" << amarillo << " UNIVERSIDAD MARIANO GALVEZ DE GUATEMALA " << verde << "**" << salto;
	cout << verde << "**" << amarillo << "         ING SAUL DONAZETTI ARBIZU       " << verde << "**" << salto;
	cout << verde << "**" << amarillo << "               ALGORITMOS                " << verde << "**" << salto;
	cout << verde << "**" << amarillo << "                                         " << verde << "**" << salto;
	cout << verde << "**" << amarillo << "                                         " << verde << "**" << salto;
	cout << verde << "**" << amarillo << "              Proyecto Final             " << verde << "**" << salto;
	cout << verde << "**" << amarillo << "                                         " << verde << "**" << salto;
	cout << verde << "**" << amarillo << "                                         " << verde << "**" << salto;
	cout << verde << "**" << amarillo << "ABNER NOE RAMIREZ ALVAREZ                " << verde << "**" << salto;
	cout << verde << "**" << amarillo << "CARNE: 9490-21-3265                      " << verde << "**" << salto;
	cout << verde << "**" << amarillo << "OSCAR ORLANDO LIMA                       " << verde << "**" << salto;
	cout << verde << "**" << amarillo << "CARNE: 9490-21-75                        " << verde << "**" << salto;
	cout << verde << "**" << amarillo << "GERARDO OVANDO                           " << verde << "**" << salto;
	cout << verde << "**" << amarillo << "CARNE: 9490-21-7                         " << verde << "**" << salto;
	cout << verde << "**" << amarillo << "30/10/21                                 " << verde << "**" << salto;
	cout << verde << "*********************************************" << salto;
	cout << salto << salto;
	cout << blanco << "-------[Precione cualquier tecla para continuar]-------";
	getchar();
	system("cls");
}


//Agregue un switch y while para el menu
int main() {
	Proyecto p = Proyecto();
	p.caratula();
	while (!salida) {
		p.menu();
		printf("Opcion: ");
		scanf("%d", &opcion);
		system("cls");
		switch (opcion) {
		case 1: p.crearFichero(fichero_Paciente);
			break;
		case 2: p.registrarPaciete(fichero_Paciente);
			break;
		case 3: p.consultarTodos();
			break;
		case 4: char d; p.generarVisita();
			break;
		case 5: p.consultaVisita();
			break;
		case 6: salida = 1;
			exit(1);
		default: printf("\n Opcion no valida");
		}
	}
	return 0;
}
