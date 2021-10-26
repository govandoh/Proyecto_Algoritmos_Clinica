#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

int opcion;

class Proyecto {
public:
	void crearFichero(FILE* fichero_Paciente);
	void registrar();
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
	char nombre[50];
	char dpi[13];
	char sexo[13];
	int edad;
	char direccion[25];
	bool seguro_medico;
}registro;


int salida = 0;
FILE* fichero_Paciente;

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

void Proyecto::registrar() {
	system("cls");
	cout << verde << ("NUEVO REGISTRO DE PACIENTE \n") << blanco;
	cout << "Ingrese Nombre del paciente: ";

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
		case 2: p.registrar();
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