#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include <unistd.h>


int main()
 {
	 printf("Ingrese la Opcion: ");
	 printf("\n");

	 //int  Op = getOption();
	 
    STR_avion info=*cargarDatos();
		char *Palabra2=malloc(sizeof(STR_avion));
		strCAT(&info,Palabra2);
		int cliente = conex(&info,Palabra2);
		sendMSJ(cliente,Palabra2);
		recevMSJ(cliente);
		sendMSJ(cliente,Palabra2);
		//printear(&info);
		//printf("\nINFO ID : %s\n\n", Palabra2);
    /* char palabra[]="AABCN123;Boeing / 767;180000;01";

    STR_avion info2 = parsear2(palabra);

    char *Palabra=malloc(sizeof(STR_avion));


    printf("ESPERAMOS 10 segundos\n");
    sleep(5);
    
		if(strcmp(info2.estado,"01")==0)
		{
        printf("LLego el mensaje correcto\n\n");
        printear(&info2);
				strCAT(&info2,Palabra);
				parsear2(Palabra);
				printear(&info2);
    }
    else
    {
        printf("LLego otro estado");
    } */

}
