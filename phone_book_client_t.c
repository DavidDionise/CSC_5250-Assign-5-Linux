/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "phone_book.h"
#include "client_util.h"


void
phone_book_prog_1(char *host, char *command)
{
	char *name, *number;
	
	CLIENT *clnt;
	r_val  *result_1;
	entry  add_to_database_1_arg;
	r_val  *result_2;
	char * remove_from_database_1_arg;
	r_val  *result_3;
	char * lookup_name_1_arg;
	r_val  *result_4;
	char *list_1_arg;
	int  *result_5;
	char *quit_1_arg;
	int  *result_6;
	char *terminate_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, PHONE_BOOK_PROG, PHONE_BOOK_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	// **************************** //
	// ********* ADD ************** //
	// **************************** //

	if(strcmp(command, "add") == 0) {
		puts("Enter the name : ");
		name = getLine();

		puts("Enter the number : ");
		number = getLine();

		add_to_database_1_arg.name = malloc(sizeof(char) * 64);
		add_to_database_1_arg.number = malloc(sizeof(char) * 64);

		strcpy(add_to_database_1_arg.name, name);
		strcpy(add_to_database_1_arg.number, number);

		add_to_database_1_arg.next = NULL;

		result_1 = add_to_database_1(&add_to_database_1_arg, clnt);
		if (result_1 == NULL) {
			clnt_perror(clnt, "call failed:");
		}
		else if(result_1->num < 0){
			printf("%s\n", result_1->message);
		}
		else {
			printf("Entries in phone book : %i\n", result_1->num);
		}
		free(name);
		free(number);
		free(add_to_database_1_arg.name);
		free(add_to_database_1_arg.number);

		printf("\n");
	}

	// **************************** //
	// ********* DELETE *********** //
	// **************************** //

	else if(strcmp(command, "delete") == 0) {
		remove_from_database_1_arg = malloc(sizeof(char) * 64);

		puts("Enter a name to delete : ");
		name = getLine();

		strcpy(remove_from_database_1_arg, name);

		result_2 = remove_from_database_1(&remove_from_database_1_arg, clnt);
		if (result_2 == (r_val *) NULL) {
			clnt_perror (clnt, "call failed");
			printf("\n");
		}
		else if(result_2->num < 0){
			printf("%s\n", result_2->message);
		}
		else {
			printf("Entries in phone book : %i\n", result_2->num);
		}
		free(name);
		free(remove_from_database_1_arg);

		printf("\n");
	}

	// **************************** //
	// *********** QUERY ********** //
	// **************************** //

	else if(strcmp(command, "query") == 0) {
		puts("Enter a name to search for :");

		name = getLine();
		lookup_name_1_arg = malloc(sizeof(char) * 128);

		strcpy(lookup_name_1_arg, name);

		result_3 = lookup_name_1(&lookup_name_1_arg, clnt);
		if (result_3 == (r_val *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		else if(result_3->num < 0) {
			printf("%s\n", result_3->message);
		}
		else {
			entry *current = result_3->head;
			while(current) {
				printf("%s, %s\n", current->name, current->number);
				current = current->next;
			}
		}
	}

	// **************************** //
	// *********** LIST *********** //
	// **************************** //
	
	result_4 = list_1((void*)&list_1_arg, clnt);
	if (result_4 == (r_val *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else if(result_4->num < 0) {
		printf("%s\n", result_4->message);
	}
	else {
		entry *current = result_4->head;
		while(current) {
			printf("%s, %s\n", current->name, current->number);
			current = current->next;
		}
	}
	// result_5 = quit_1((void*)&quit_1_arg, clnt);
	// if (result_5 == (int *) NULL) {
	// 	clnt_perror (clnt, "call failed");
	// }
	// result_6 = terminate_1((void*)&terminate_1_arg, clnt);
	// if (result_6 == (int *) NULL) {
	// 	clnt_perror (clnt, "call failed");
	// }
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;
	char *command;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];

	while(1) {
		puts("Enter a command to operate the phone book : ");
		command = getLine();

		phone_book_prog_1( host, command );
	}
exit (0);
}
