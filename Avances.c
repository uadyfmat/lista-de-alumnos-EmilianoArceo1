#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *nombre;
	int creditos;
	int semestre;
} alumno;
typedef alumno *Alumno;
	
Alumno crearAlumno(Alumno *actual, char *nombre, int creditos, int semestre);
int main(int argc, char *argv[]) {
	Alumno inicioPtr= NULL;
	char *nombre;
	int creditos, semestre;
	crearAlumno(&inicioPtr, nombre, creditos, semestre);
	return 0;
}

Alumno crearAlumno(Alumno *actual, char *nombre, int creditos, int semestre){
	int i = 0;
	while(nombre!= "FIN"){
		printf("Alumno %i.\n",i+1);
		printf("Nombre completo: ");
		gets(actual->nombre);
		printf("Créditos: ");
		scanf("%i",actual->creditos);
		i++;
	}
}
