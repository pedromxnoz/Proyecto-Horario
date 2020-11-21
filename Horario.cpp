#include <stdio.h>
#include <windows.h>

int main(){
	bool horario_creado = 0;
	int opcion_selec;
	int opcion_selec1;
	int cant_semanas;
	int cant_ramos;
	char nombre_ramo[8][30];
	char nombre_profe[8][30];
	char link_clase[8][120];
	
	do{
	printf("Que desea realizar?\n");
	printf("1. Crear un horario fijo de estudio\n");
	printf("2. Agendar evento o recordatorio\n");
	printf("3. Salir del programa\n");
	scanf("%d", &opcion_selec);
	system("cls");
	
	while ((opcion_selec <= 0) || (opcion_selec > 3))
				{
					printf("Error!!, Ingrese una opcion valida\n");
					printf("Que desea realizar?\n");
	                printf("1. Crear un horario fijo de estudio o trabajo\n");
	                printf("2. Agendar evento o recordatorio\n");
	                printf("3. Salir del programa\n");
					scanf("%d", &opcion_selec);
					system("cls");
				}	
				
	switch(opcion_selec){
		case 1:
		printf("Cuantas semanas estara impartiendo esta rutina de estudios?\n");
		scanf("%d", &cant_semanas);
		printf("A continuacion ingrese los datos solicitados:\n");
		printf("ingrese la cantidad de ramos a rendir en este periodo (maximo 8 ramos)\n");
		scanf("%d", &cant_ramos);
		
		for(int i = 0 ; i < cant_ramos ; i++){
		fflush(stdin);
		printf("ingrese el nombre del ramo %d:\n", i+1);
		scanf("%[^\n]", nombre_ramo[i]);
		fflush(stdin);
		printf("ingrese el nombre del profesor que rinde el ramo %d:\n", i+1);
		scanf("%[^\n]", nombre_profe[i]);
		fflush(stdin);
		printf("pegue el link de ingreso a la clase del ramo %d:\n", i+1);
		scanf("%[^\n]", link_clase[i]);	
	}
		
		printf("Tiene clases los dias lunes?\n");
		printf("1. Si\n");
	    printf("2. No\n");
		scanf("%d", &opcion_selec1);
		while ((opcion_selec1 <= 0) || (opcion_selec1 > 2))
				{
					printf("Error!!, Ingrese una opcion valida\n");
					printf("Tiene clases los dias lunes?\n");
		            printf("1. Si\n");
	                printf("2. No\n");
	                scanf("%d", &opcion_selec1);
					system("cls");
				}
				
		break;
		case 2:
		if(horario_creado == 0){
			printf("Debe crear un horario fijo antes de poder agreagar eventos a su horario\n");
			break;
		}
		
		break;
		case 3:
		
		return 0;
		break;
	}
}while(!horario_creado);
	
	return 0;
}
