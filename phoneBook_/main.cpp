#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include <string>

typedef struct {
	int day;
	int month;
	int year;
}dob;

typedef struct {
	char city[20];
	char state[20];
	long code;
}address;

typedef struct {
	char name[40];
	char lastname[40];
	char phone[15];
	address location;
	dob birthdate;
} contact;

int main() {
	int op = 0, totalCont = 0, opDel = 0, total = 0;
	contact contacts[100];

	printf("Welcome to Phonebook\n");
	do {
		printf("1.- View contacts\n");
		printf("2.- Add contact\n");
		printf("3.- Delete contact\n");
		printf("4.- Exit\n");
		scanf_s("%d", &op);

		switch (op) {
			// Ver contactos
		case 1:
			printf("\n*********************************************\n");
			printf("View contacts\n");
			if (totalCont <= 0) {
				printf("No contacts available\n");
			}
			else {
				for (int i = 0; i < totalCont; i++) {
					printf("Contact %d\n", i + 1);
					printf("Name: %s\n", contacts[i].name);
					printf("Lastname: %s\n", contacts[i].lastname);
					printf("City: %s\n", contacts[i].location.city);
					printf("State: %s\n", contacts[i].location.state);
					printf("Postal Code: %ld\n", contacts[i].location.code);
					printf("Phone: %s\n", contacts[i].phone);
					printf("Birthdate: %d/%d/%d\n", contacts[i].birthdate.day, contacts[i].birthdate.month, contacts[i].birthdate.year);
				}
			}
			printf("\n*********************************************\n");
			printf("\n\nPress any key to continue...\n");
			_getch();
			system("cls");
			break;

			// Agregar contacto
		case 2:
			printf("\n*********************************************\n");
			printf("Add contact\n");
			fflush(stdin);
			printf("Contact %d\n", totalCont + 1);
			printf("\nName: ");
			scanf_s("%s", contacts[totalCont].name, 40);
			printf("\nLastname: ");
			scanf_s("%s", contacts[totalCont].lastname, 40);
			printf("\nPhone: ");
			scanf_s("%s", contacts[totalCont].phone, 15);
			fflush(stdin);
			// Date of birth
			printf("\nBirthdate (dd/mm/yyyy): ");
			scanf_s("%d/%d/%d", &contacts[totalCont].birthdate.day, &contacts[totalCont].birthdate.month, &contacts[totalCont].birthdate.year);
			fflush(stdin);
			// Address
			printf("\nCity: ");
			scanf_s("%s", contacts[totalCont].location.city, 20);
			printf("\nState: ");
			scanf_s("%s", contacts[totalCont].location.state, 20);
			printf("\nPostal code: ");
			scanf_s("%ld", &contacts[totalCont].location.code);

			totalCont++;
			printf("\n\nPress any key to continue\n");
			_getch();
			system("cls");
			break;


			// Delete contact
		case 3:
			printf("\n**********************************\n");
			printf("Delete contact\n");
			printf("\n**********************************\n");
			if (totalCont == 0) {
				printf("No contacts available\n");
			}
			else {

				printf("Contact list:\n");
				for (int i = 0; i < totalCont; i++) {
					printf("Contact %d", i + 1);
					printf(" %s\n", contacts[i].name);
				}
				printf("\n**********************************\n");
				printf("\nEnter the contact number to delete: ");
				scanf_s("%d", &opDel);

				if (opDel <= totalCont) {
					while (opDel <= totalCont) {
						errno_t strcpy_s(char* strDestination, size_t numberOfElements, const char* strSource);
						opDel++;
					}
					totalCont--;
					printf("\nContact deleted\n");
				}
				else {
					printf("\nContact not found\n");
				}

			}
			printf("\n\nPress any key to continue\n");
			_getch();
			system("cls");
			break;


		case 4:
			printf("Exiting...\n");
			break;
		default:
			printf("Invalid option\n");

		}

	} while (op != 4);
	return 0;
}