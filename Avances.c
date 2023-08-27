#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodos{
	char *nombre;
	int creditos;
	int semestre;
	struct nodos *sig;
}Alumno;

/*Firmas*/
Alumno *listaAlumnos(Alumno *lista);
Alumno *crearAlumno(Alumno *lista, char *nombre, int creditos, int semestre);
void imprimirAlumno();
Alumno *insertarNodoOrdenadoCreditos(Alumno *lista);
void imprimirLista(Alumno *lista);

int main(int argc, char *argv[]) {
	Alumno *lista = listaAlumnos(lista);
	printf("			Lista de Alumnos.\n");
	lista = crearAlumno(lista,"Mateo Pizón",45,3);
	lista = crearAlumno(lista,"Eduardo Ortíz",38,3);
	lista = crearAlumno(lista,"Victor Hugo Rosado",45,5);
	lista = crearAlumno(lista,"Andry Rabanales",55,2);
	lista = crearAlumno(lista,"Carlos Ek",42,4);
	printf("\n");
	imprimirAlumno(lista);
	lista = insertarNodoOrdenadoCreditos(lista);
	imprimirLista(lista);
	return 0;
}

Alumno *listaAlumnos(Alumno *lista){
	lista = NULL;
	return lista;
}
	
Alumno *crearAlumno(Alumno *lista, char *nombre, int creditos, int semestre){
	Alumno *nvoAlumno, *actAlumno;
	nvoAlumno = malloc(sizeof(Alumno));
	printf("Se ha creado un nodo en la lista de alumnos en la dirección %p\n",(void*)nvoAlumno);
	nvoAlumno->nombre=strdup(nombre);
	nvoAlumno->creditos = creditos;
	nvoAlumno->semestre = semestre;
	nvoAlumno->sig = NULL;
	if(lista==NULL){
		lista=nvoAlumno;
	}
	else{
		actAlumno = lista;
		while(actAlumno->sig!=NULL){
			actAlumno = actAlumno->sig;
		}
		actAlumno->sig = nvoAlumno;
	}
	return lista;
}
	
void imprimirAlumno(Alumno *lista){
	while(lista !=NULL){
		printf("Se ha creado la estructura Alumno en la dirección %p\n",(void*)lista);
		lista = lista->sig;
	}
	printf("\n");
}
	
Alumno *insertarNodoOrdenadoCreditos(Alumno *lista) {
	Alumno *i, *j, *max;
	
	for (i = lista; i->sig != NULL; i = i->sig) {
		max = i;
		for (j = i->sig; j != NULL; j = j->sig) {
			if (j->creditos > max->creditos) {
				max = j;
			}
		}
		
		if (max != i) {
			char *tempNombre = i->nombre;
			int tempCreditos = i->creditos;
			int tempSemestre = i->semestre;
			
			i->nombre = max->nombre;
			i->creditos = max->creditos;
			i->semestre = max->semestre;
			
			max->nombre = tempNombre;
			max->creditos = tempCreditos;
			max->semestre = tempSemestre;
		}
	}
	
	return lista;
}
	
	

void imprimirLista(Alumno *lista){
	printf("			Lista ordenada por créditos.\n");
	printf("---------------------------------------------------------------------\n");
	printf("|		 Nombre		 	  | Créditos   | Semestre  |\n");
	printf("---------------------------------------------------------------------\n");
	while(lista!=NULL){
		printf("|%-40s | %10d | %10d|\n",lista->nombre, lista->creditos, lista->semestre);
		lista = lista->sig;
	}
	printf("---------------------------------------------------------------------\n");
}


