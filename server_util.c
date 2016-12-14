

#include <stdio.h>

#include "server_util.h"

int COUNT = 0;

void push(entry **head, entry *e) {
	if(*head == NULL) {
		*head = e;
	}
	else {
		entry *current = *head;
		while(current) {
			if(current->next == NULL) {
				current->next = e;
				break;
			}
			current = current->next;
		}
	}
}

int removeNode(entry **head, entry **e) {
	int found = 0;

	if(*e == *head) {
		*head = (*head)->next;

		found = 1;

		free((*e)->name);
		free((*e)->number);
		free(*e);
	}
	else {
		entry *current = *head;

		while(current) {
			if(current->next == *e) {
				found = 1;
				entry *temp = current->next;
				current->next = temp->next;

				found = 1;

				free(temp->name);
				free(temp->number);
				free(temp);

				break;
			}
			else {
				current = current->next;
			}
		}
	}

	if(found) 
		return 0;
	else
		return -1;
}

int buildList(entry **head) {
	FILE *fp;
	int finished_build = 0;
	int i;
	char c;

	if((fp = fopen("database.txt", "r")) < 0) {
		perror("Error opening file for read");
		return -1;
	}

	while(!finished_build) {
		i = 0;

		entry *e = malloc(sizeof(entry));
		e->name = malloc(sizeof(char) * 128);
		e->number = malloc(sizeof(char) * 16);
		e->next = NULL;

		e->name[0] = '\0';
		e->number[0] = '\0';

		while((c = fgetc(fp)) != '#') {
			if(c == EOF) {
				break;
			}

			e->name[i] = c;
			e->name[++i] = '\0';
		}

		// Read space
		c = fgetc(fp);
		i = 0;

		while((c = fgetc(fp)) != '\n') {
			if(c == EOF) {
				finished_build = 1;
				break;
			}

			e->number[i] = c;
			e->number[++i] = '\0';
		}

		if(!finished_build) {
			push(head, e);
		}
	}

	fclose(fp);
}


