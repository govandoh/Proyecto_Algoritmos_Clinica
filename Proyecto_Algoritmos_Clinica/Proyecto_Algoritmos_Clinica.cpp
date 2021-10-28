#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <cstring>    

using namespace std;

int opcion;

class Proyecto {
public:
	void crearFichero(FILE* fichero_Paciente);
	void registrarPaciete(FILE* fichero_Paciente);
	void eliminar();
	void consultar();
	void caratula();
	void menu();
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
	char dpi[13];
	char nombre[25];
	char apellido[25];
	char sexo[13];
	int  edad;
	char seguro_medico[50];
	char estado_Clinico[50];
	char direccion[50];
}registroPa;

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

void Proyecto::menu() {
	cout << amarillo << "\n------- MENU PRINCIPAL --------";
	cout << amarillo << "\n1 - Crear un Fichero de Pacientes \n";
	cout << amarillo << "2 - Insert un Paciente nuevo \n";
	cout << amarillo << "3 - Ver Historial de Paciente \n";
	cout << amarillo << "4 - Salir \n";
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
	cin>>registroPa.codigo_Paciente;
	printf("NO. DPI: ");
	cin>>registroPa.dpi;
	printf("NOMBRE: ");
	cin>>registroPa.nombre;
	printf("APELLIDO: ");
	cin>>registroPa.apellido;
	printf("SEXO: ");
	cin>>registroPa.sexo;
	printf("EDAD: ");
	cin>>registroPa.edad;
	cout<<("SEGURO MEDICO: ");
	cin>>registroPa.seguro_medico;
	printf("ESTADO CLINICO: ");
	cin>>registroPa.estado_Clinico;
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
}


//Agregue un switch y while para el menu
int main() {
	Proyecto p = Proyecto();
	p.caratula();
	while (!salida) {
		p.menu();
		printf("Opcion: ");
		scanf("%d", &opcion);
		switch (opcion) {
		case 1: p.crearFichero(fichero_Paciente);
			break;
		case 2: p.registrarPaciete(fichero_Paciente);
			break;
		case 3: p.caratula();
			break;
		case 4: salida = 1;
			exit(1);
			break;
		default: printf("\n Opcion no valida");
		}
	}
	return 0;
}
