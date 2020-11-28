#include <stdio.h>
#include <windows.h>
#include <string.h>

struct Ramo
{
	char nombre_ramo[30];
	char nombre_profe[30];
	char link_clase[120];
} Ramos[8];

int main()
{
	bool horario_creado = 0;
	int opcion_selec;
	int cant_semanas;
	int cant_ramos;

	while (opcion_selec != 3)
	{
		printf("Que desea realizar?\n");
		printf("1. Crear un horario fijo de estudio\n");
		printf("2. Agendar evento o recordatorio\n");
		printf("3. Salir del programa\n");
		scanf("%d", &opcion_selec);
		system("cls");

		switch (opcion_selec)
		{
		case 1:
			printf("Cuantas semanas estara impartiendo esta rutina de estudios?\n");
			scanf("%d", &cant_semanas);
			printf("A continuacion ingrese los datos solicitados:\n");
			printf("ingrese la cantidad de ramos a rendir en este periodo (maximo 8 ramos)\n");
			scanf("%d", &cant_ramos);

			for (int i = 0; i < cant_ramos; i++)
			{
				fflush(stdin);
				printf("ingrese el nombre del ramo %d:\n", i + 1);
				scanf("%[^\n]", Ramos[i].nombre_ramo);
				fflush(stdin);
				printf("ingrese el nombre del profesor que rinde el ramo %d:\n", i + 1);
				scanf("%[^\n]", Ramos[i].nombre_profe);
				fflush(stdin);
				printf("pegue el link de ingreso a la clase del ramo %d:\n", i + 1);
				scanf("%[^\n]", Ramos[i].link_clase);
			}

			break;
		case 2:
			if (horario_creado == 0)
			{
				printf("Todavia no ha creado un horario fijo, desea continuar?\n");
				break;
			}

			break;
		case 3:

			return 0;
			break;

		default:
			if ((opcion_selec < 1) || (opcion_selec > 3))
			{
				printf("Error!!, Ingrese una opcion valida\n");
			}
			break;
		}
	}

	return 0;
}
