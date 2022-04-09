#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Function prototype
void registration(); //registration function
void shopping(); //shopping function
void output(); //output function
void clear(); //clear function

//Constants
#define _TOT_PEOPLE 100 //Max number of people
#define _NUM_CABINE 10 // Max number of cabines


//Main input vars
int numFamily[_TOT_PEOPLE]; //Number of people in each family
int numPeople = 0; //Total number of people
char names[_TOT_PEOPLE]; //Names of people
char surnames[_TOT_PEOPLE]; //Surnames of people
int birthdayDay[_TOT_PEOPLE]; //Birthday day of people
int birthdayMonth[_TOT_PEOPLE]; //Birthday month of people
int birthdayYear[_TOT_PEOPLE]; //Birthday year of people

//Work vars
int occupiedCabins1[_NUM_CABINE]; //Number of occupied 1 person cabines
int occupiedCabins2[_NUM_CABINE]; //Number of occupied 2 people cabines
int occupiedCabins3[_NUM_CABINE]; //Number of occupied 3 people cabines
int occupiedCabins4[_NUM_CABINE]; //Number of occupied 4 people cabines
int state = 0; //0 = registration 1 = shopping 2 = output
bool isRunning = true; //Is the program running?
bool isFull = false; //Is the ship full?

int main()
{
	printf("Benvenuto al programma di registrazione\n");
	Sleep(2000L);
	clear();
	do
	{
		switch (state) {
		case 0:
			//Registration
			registration();
			break;
		case 1:
			//Shopping
			shopping();
			break;
		case 2:
			//Travelling
			output();
			break;
		default:
			return EXIT_FAILURE;
			break;
		}
	} while (isRunning);
	return EXIT_SUCCESS;
}

void registration()
{
	int choice, familyMemb;
	bool _isRunning = true;
	do
	{
		if (numPeople != 100)
		{
			printf("[0]Registra una famiglia\n");
		}
		printf("[1]Parti\n");
		scanf("%d", &choice);
		clear();
		if (numPeople != 100 && choice == 0)
		{
			do
			{
				printf("Quanti membri ci sono?(Posti occupati = %d)\n", numPeople);
				scanf("%d", &familyMemb);
			} while (familyMemb < 0);
			numPeople += familyMemb;
			if (_TOT_PEOPLE - numPeople > 0)
			{
				for (int i = 0; i < familyMemb; i++)
				{
					printf("Membro della famiglia(%d)\nInserisci il nome\n", i + 1);
					scanf("%s", &names[i]);
					printf("Inserisci il cognome\n");
					scanf("%s", &surnames[i]);
					printf("Inserisci il giorno di nascita\n");
					scanf("%d", &birthdayDay[i]);
					while (birthdayDay[i] > 31 || birthdayDay[i] < 1)
					{
						printf("Non valido, riinserisci\n");
						scanf("%d", &birthdayDay[i]);
					}
					printf("Inserisci il mese di nascita\n");
					scanf("%d", &birthdayMonth[i]);
					while (birthdayMonth[i] > 12 || birthdayMonth[i] < 1)
					{
						printf("Non valido, riinserisci\n");
						scanf("%d", &birthdayMonth[i]);
					}
					printf("Inserisci l'anno di nascita\n");
					scanf("%d", &birthdayYear[i]);
					while (birthdayYear[i] > 2022 || birthdayYear[i] < 1900)
					{
						printf("Non valido, riinserisci\n");
						scanf("%d", &birthdayYear[i]);
					}
				}

				//cabin logic

				clear();
			}
			else
			{
				numPeople -= familyMemb;
				printf("Non ci sono abbastanza posti\n");
				Sleep(1000);
				clear();
			}
		}
		else if (choice == 1)
		{
			printf("Buon viaggio!\n");
			Sleep(1000);
			clear();
			state = 1;
			_isRunning = false;
		}
		else
		{
			printf("Inserisci una scelta valida\n");
			Sleep(1000);
			clear();
		}
	} while (_isRunning);
}

void shopping()
{
	printf("giglo");
}

void output()
{
	//print cabins
	isRunning = false;
}

void clear()
{
	system("cls");
}