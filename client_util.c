
#include "client_util.h"
#include "phone_book.h"


char* getLine() {
	int length = 10;
	int count = 0;
	char* buffer = (char*)malloc(sizeof(char) * length);
	char* buf_ptr = &buffer[0];
	char c;

	*buf_ptr = '\0';
	
	while((c = getchar()) != '\n') {
		if(count >= (length - 1)) {
			length += 10;
			buffer = (char*)realloc(buffer, length);
		}

		++count;
		*buf_ptr = c;
		*(++buf_ptr) = '\0';
	}

	return buffer;
}

