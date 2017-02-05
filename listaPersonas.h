//lista de personas
#if !defined(NULL)
    #define NULL ((void*)0)
#endif
typedef enum{FALSE,TRUE} boolean;

typedef struct{
	unsigned int id;
	char nombre[20];
	unsigned int edad;
}Persona;

typedef struct node{
	Persona dato;
	struct node* siguiente;
}Nodo;

Nodo* buscar(Nodo*,int);
boolean agregar(Nodo**);
boolean eliminar(Nodo**);
