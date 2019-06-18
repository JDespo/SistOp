#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int getOption()
 {
     int option;
     scanf("%i",&option);
     return option;

 }

/*
#include <unistd.h>  es para Slepp en LInux
*/

STR_avion parsear2(char *palabra)
{
    STR_avion info;
    char *token = strtok(palabra, ";");
    memset(info.id, '\0', id_Len);
    strncpy(info.id, token, id_Len);

    memset(info.modelo, '\0', modelo_Len);
    strncpy(info.modelo, token = strtok(NULL, ";"), modelo_Len);

    memset(info.combustible, '\0', combustible_Len);
    //info.combustible = atoi(strtok(NULL, ";"));
    strncpy(info.combustible, token = strtok(NULL, ";"), combustible_Len);

    memset(info.estado, '\0', estado_Len);
    strncpy(info.estado, token = strtok(NULL, ";"), estado_Len);

    return info;
}

void printear(STR_avion *info)
{
     printf("ID: %s\n", info->id);
     printf("MODELO: %s\n", info->modelo);
     printf("COMBUSTIBLE: %s\n", info->combustible);
     printf("ESTADO: %s\n", info->estado);
}

void strCAT (STR_avion *info, char *palabra)
{
    //printf("\n\n COMIENZA CAT string : \n");
    char src[2]=";";
    char *dest =malloc(sizeof(STR_avion));
    memset(dest,'\0',sizeof(STR_avion));

    
    strcat(dest, info->id);
    strcat(dest, src);
    strcat(dest, info->modelo);
    strcat(dest, src);
    strcat(dest, info->combustible);
    strcat(dest, src);
    strcat(dest, info->estado);
    strcat(dest, src);
    strcpy(palabra,dest);

   
    //printf("Final string : %s\n\n", dest);
}

STR_avion *cargarDatos()
{
    char id[id_Len],modelo[modelo_Len],combustible[combustible_Len];
    printf("\nIngrese el ID: ");
   //memset(info->id, '\0', id_Len);
    //fgets(info->id, id_Len, stdin);
    scanf("%s",id);
    printf("\nIngrese MODELO: ");
    //memset(info->modelo, '\0', modelo_Len);
    //fgets(info->modelo, modelo_Len, stdin);
    scanf("%s",modelo);

    printf("\nIngrese el COMBUSTIBLE: ");
    //memset(info->combustible, '\0', combustible_Len);
    //fgets(info->combustible, combustible_Len, stdin);
    scanf("%s",combustible);

    STR_avion *info=(STR_avion*)malloc(sizeof(STR_avion));
    strcpy(info->id, id);
    strcpy(info->modelo, modelo);
    strcpy(info->combustible, combustible);
    strcpy(info->estado, "01");
    printf("FUE CREADO ",info->id);
    return info;
}