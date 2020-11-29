#include <stdio.h>
#include <windows.h>
#include <string.h>

struct Ramo
{
	char nombre_ramo[30];
	char nombre_profe[30];
	char link_clase[120];
};

struct Clase
{
	int hora_inicio;
	int minuto_inicio;
	int hora_termino;
	int minuto_termino;
} Clases_semanales[7][12];

struct Evento
{
	int semana;
};

int seleccion_ramo(int cant_ramos, Ramo Ramos[8]);

int main()
{
	Ramo Ramos[8];
	Evento Eventos_diarios[16];
	int cant_clases[7];
	char dia_semana[7][12] = {"lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo"};
	char posicion[12][10] = {"primera", "segunda", "tercera", "cuarta", "quinta", "sexta", "septima", "octava", "novena", "decima", "undecima", "duodecima"};
	bool horario_creado = 0;
	int opcion_selec;
	int ramo_seleccionado[7][8];
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
			system("cls");
			printf("A continuacion ingrese los datos solicitados:\n");
			printf("ingrese la cantidad de ramos a rendir en este periodo (maximo 8 ramos)\n");
			scanf("%d", &cant_ramos);
			system("cls");

			for (int i = 0; i < cant_ramos; i++)
			{
				fflush(stdin);
				printf("ingrese el nombre del ramo %d:\n", i + 1);
				scanf("%[^\n]", Ramos[i].nombre_ramo);
				system("cls");
				fflush(stdin);
				printf("ingrese el nombre del profesor que rinde el ramo %d:\n", i + 1);
				scanf("%[^\n]", Ramos[i].nombre_profe);
				system("cls");
				fflush(stdin);
				printf("pegue el link de ingreso a la clase del ramo %d:\n", i + 1);
				scanf("%[^\n]", Ramos[i].link_clase);
				system("cls");
			}

			int a;

			for (int i = 0; i <= 7; i++)
			{
				do
				{
					printf("Cuantas clases debe asistir el dia %s?\n", dia_semana[i]);
					scanf("%d", &cant_clases[i]);
					system("cls");

					for (int j = 0; j < cant_clases[i]; j++)
					{
						int b;

						printf("Ingrese la %s clase del dia %s:\n", posicion[j], dia_semana[i]);
						ramo_seleccionado[i][j] = seleccion_ramo(cant_ramos, Ramos);

						do
						{

							printf("Ingrese la hora de inicio y termino de '%s' a continuacion (use formato 24Hrs):\n", Ramos[ramo_seleccionado[i][j]].nombre_ramo);

							printf("Ingrese Hora de inicio en formato 'HH:MM':\n");
							scanf("%d:%d", &Clases_semanales[i][j].hora_inicio, &Clases_semanales[i][j].minuto_inicio);

							printf("Ingrese Hora de termino en formato 'HH:MM':\n");
							scanf("%d:%d", &Clases_semanales[i][j].hora_termino, &Clases_semanales[i][j].minuto_termino);

							if (j != 0)
							{
								if (((Clases_semanales[i][j - 1].hora_inicio < Clases_semanales[i][j].hora_inicio) && (Clases_semanales[i][j].hora_inicio < Clases_semanales[i][j - 1].hora_termino)))
								{

									printf("Este horario ingresado irrumpe dentro de otro horario ingresado anteriormente\n");
									printf("Desea continuar?\n");
									printf("1. Si\n");
									printf("2. No (ingresar un nuevo horario)\n");
									scanf("%d", &b);
									system("cls");
								}
								else if (((Clases_semanales[i][j - 1].hora_inicio <= Clases_semanales[i][j].hora_inicio) && (Clases_semanales[i][j].hora_inicio <= Clases_semanales[i][j - 1].hora_termino)) && ((Clases_semanales[i][j].minuto_inicio < Clases_semanales[i][j - 1].minuto_termino)))
								{

									printf("Este horario ingresado irrumpe dentro de otro horario ingresado anteriormente\n");
									printf("Desea continuar?\n");
									printf("1. Si\n");
									printf("2. No (ingresar un nuevo horario)\n");
									scanf("%d", &b);
									system("cls");
								}
							}

						} while (b == 2);
					}
					printf("El Horario del dia %s quedara de la siguiente manera:\n", dia_semana[i]);
					for (int j = 0; j < cant_clases[i]; j++)
					{
						printf("[%d] %s (%d:%d) - (%d:%d)\n", j + 1, Ramos[ramo_seleccionado[i][j]].nombre_ramo, Clases_semanales[i][j].hora_inicio, Clases_semanales[i][j].minuto_inicio, Clases_semanales[i][j].hora_termino, Clases_semanales[i][j].minuto_termino);
					}
					printf("Es correcta la informacion?\n");
					printf("1. Si\n");
					printf("2. No (se realizara nuevamente)\n");
					scanf("%d", &a);
					system("cls");

				} while (a == 2);
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

int seleccion_ramo(int cant_ramos, Ramo Ramos[8])
{
	int a;
	printf("Seleccione un ramo:\n");
	for (int i = 0; i < cant_ramos; i++)
	{
		printf("%d.%s\n", i + 1, Ramos[i].nombre_ramo);
	}
	scanf("%d", &a);

	while ((a <= 0) || (a > (cant_ramos + 1)))
	{
		printf("Error, Ingrese una opcion valida\n");
		scanf("%d", &a);
	}
	a = a - 1;
	return a;
}
