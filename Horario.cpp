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
};

struct Evento
{
	int semana;
};

int seleccion_ramo(int cant_ramos, Ramo Ramos[8]);

int main()
{
	/*
	Definicion de variables, se usaran en todo el programa. Es una mezcla de estructura de datos y matrices ya que no supe muy bien como implementar
	completamente las estructuras de datos.
    */

	Clase Clases_semanales[7][12];
	Ramo Ramos[8];
	Evento Eventos_diarios[16];
	char semana[20][22] = {{"Semanas/Semana#1.txt"}, {"Semanas/Semana#2.txt"}, {"Semanas/Semana#3.txt"}, {"Semanas/Semana#4.txt"}, {"Semanas/Semana#5.txt"}, {"Semanas/Semana#6.txt"}, {"Semanas/Semana#7.txt"}, {"Semanas/Semana#8.txt"}, {"Semanas/Semana#9.txt"}, {"Semanas/Semana#10.txt"}, {"Semanas/Semana#11.txt"}, {"Semanas/Semana#12.txt"}, {"Semanas/Semana#13.txt"}, {"Semanas/Semana#14.txt"}, {"Semanas/Semana#15.txt"}, {"Semanas/Semana#16.txt"}, {"Semanas/Semana#17.txt"}, {"Semanas/Semana#18.txt"}, {"Semanas/Semana#19.txt"}, {"Semanas/Semana#20.txt"}};
	int cant_clases[7];
	char dia_semana[7][12] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
	char posicion[12][10] = {"primera", "segunda", "tercera", "cuarta", "quinta", "sexta", "septima", "octava", "novena", "decima", "undecima", "duodecima"};
	bool horario_creado = 0;
	int opcion_selec;
	int ramo_seleccionado[7][8];
	int cant_semanas;
	int cant_ramos;

	while (opcion_selec != 3)                                                                           //Se realiza un while en caso de ingresar una entrada incorrecta
	{
		printf("Que desea realizar?\n");
		printf("1. Crear un horario fijo de estudio\n");
		printf("2. Agendar evento o recordatorio\n");
		printf("3. Salir del programa\n");
		scanf("%d", &opcion_selec);
		system("cls");

		switch (opcion_selec)                                                                           //Switch para la opcion seleccionada
		{
		case 1:                                                                                         //Caso 1 Crear un horario Fijo de estudios el cual se mantendrá
			printf("Cuantas semanas estara impartiendo esta rutina de estudios?\n");                    //segun la cantidad de semanas que ingrese el usuario
			scanf("%d", &cant_semanas);
			system("cls");
			printf("A continuacion ingrese los datos solicitados:\n");
			printf("ingrese la cantidad de ramos a rendir en este periodo (maximo 8 ramos)\n");
			scanf("%d", &cant_ramos);
			system("cls");

			for (int i = 0; i < cant_ramos; i++)                                                        //Solicitud de los datos de cada ramo para guardarlos y posterormente
			{                                                                                           //usarlos en el codigo
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

			for (int i = 0; i <= 6; i++)                                                                //Este for repite el ingreso de datos diarios la cantidad de dias de la semana
			{
				do
				{
					a = 0;
					printf("Cuantas clases debe asistir el dia %s?\n", dia_semana[i]);
					scanf("%d", &cant_clases[i]);
					system("cls");

					for (int j = 0; j < cant_clases[i]; j++)                                            //Este for repite el ingreso de datos de cada calse asistida segun la cantidad
					{                                                                                   //de clases diarias que tenga el usuario
						int b;

						printf("Ingrese la %s clase del dia %s:\n", posicion[j], dia_semana[i]);        //Aqui especifica el orden de entrada para no hacer tan complejo el ingreso de datos al txt
						ramo_seleccionado[i][j] = seleccion_ramo(cant_ramos, Ramos);

						do
						{
							b = 0;

							printf("Ingrese la hora de inicio y termino de '%s' a continuacion (use formato 24Hrs):\n", Ramos[ramo_seleccionado[i][j]].nombre_ramo);

							printf("Ingrese Hora de inicio en formato 'HH:MM':\n");
							scanf("%d:%d", &Clases_semanales[i][j].hora_inicio, &Clases_semanales[i][j].minuto_inicio);

							printf("Ingrese Hora de termino en formato 'HH:MM':\n");
							scanf("%d:%d", &Clases_semanales[i][j].hora_termino, &Clases_semanales[i][j].minuto_termino);

							if (j != 0)                                                                //Aqui se realiza el testeo de el topon de horas, igual es bien limitado (falta depurar)
							{
								if (((Clases_semanales[i][j - 1].hora_inicio < Clases_semanales[i][j].hora_inicio) && (Clases_semanales[i][j].hora_inicio < Clases_semanales[i][j - 1].hora_termino)))  //creo que este if sobra
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

						} while (b == 2);                                                               //Este do while es en el caso de querer editar el horario ingresado de la ultima clase
					}
					printf("El Horario del dia %s quedara de la siguiente manera:\n", dia_semana[i]);   //Se muestra la vista previa del ingreso de horarios diarios
					for (int j = 0; j < cant_clases[i]; j++)
					{
						printf("[%d] %s (%d:%d) - (%d:%d)\n", j + 1, Ramos[ramo_seleccionado[i][j]].nombre_ramo, Clases_semanales[i][j].hora_inicio, Clases_semanales[i][j].minuto_inicio, Clases_semanales[i][j].hora_termino, Clases_semanales[i][j].minuto_termino);
					}
					printf("Es correcta la informacion?\n");
					printf("1. Si\n");
					printf("2. No (se realizara nuevamente)\n");
					scanf("%d", &a);
					system("cls");

				} while (a == 2);                                                                        //Este do while es en el caso de que el usuario quiera ingresar desde 0 los horarios diarios
			}

			for (int i = 0; i < cant_semanas; i++)                                                       //Pega los datos en los txt creados con el for
			{

				FILE *arch = fopen(semana[i], "w");
				fprintf(arch, "Ramos:\n\n");
				for (int j = 0; j < cant_ramos; j++)
				{
					fprintf(arch, "(%d) %s / %s\n", j + 1, Ramos[j].nombre_ramo, Ramos[j].nombre_profe);
				}
				fprintf(arch, "\n*Horario Fijo*\n\n");
				for (int k = 0; k < 7; k++)
				{
					if (cant_clases[k] == 0)
					{
						continue;
					}
					fprintf(arch, "%s:\n", dia_semana[k]);
					for (int j = 0; j < cant_clases[k]; j++)
					{

						fprintf(arch, "[%d] (%d:%d)~(%d:%d) - %s - %s\n", j + 1, Clases_semanales[k][j].hora_inicio, Clases_semanales[k][j].minuto_inicio, Clases_semanales[k][j].hora_termino, Clases_semanales[k][j].minuto_termino, Ramos[ramo_seleccionado[k][j]].nombre_ramo, Ramos[ramo_seleccionado[k][j]].link_clase);
					}
				}
				fclose(arch);
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
