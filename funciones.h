#define id_Len 9
#define modelo_Len 15
#define combustible_Len 10
#define estado_Len 3

typedef struct{
    char id[id_Len];
    char modelo[modelo_Len];
    char combustible[combustible_Len];
    char estado[estado_Len];
}STR_avion;


int conex(STR_avion *info, char *Palabra);
void sendMSJ(int cliente, char *sendMsj);
void recevMSJ(int cliente);

typedef enum Opciones{CREAR_AVION, REISTRAR_AVION }Opciones;

int getOption();




STR_avion parsear2(char *palabra);
void printear(STR_avion *info);
void esperar(int segundos);
void strCAT (STR_avion *info, char *dest);
STR_avion *cargarDatos();
