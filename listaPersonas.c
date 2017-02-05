//lista de personas
#include "listaPersonas.h"
Nodo* buscarById(Nodo* inicio,int id){
	Nodo* actual=inicio;
	while(actual!=NULL){
		if(actual->dato.id == id){
			return actual;
		}else{
			actual= actual->siguiente;
		}
	}
	return NULL;
}

boolean agregar(Nodo** inicio){
	return TRUE;
}

boolean eliminar(Nodo** inicio){
	return TRUE;
}
