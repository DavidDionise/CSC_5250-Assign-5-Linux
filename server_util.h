
#ifndef SERVER_UTIL_H
#define SERVER_UTIL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "phone_book.h"

extern int COUNT;

void push(entry **head, entry *e);

int removeNode(entry **head, entry **e);

int buildList(entry **head);

#endif