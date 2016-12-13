
struct entry {
	string name<128>;
	string number<16>;

	struct entry *next;
};

struct linked_list {
  struct entry *head;
};

struct r_val {
	int num;
	string message<256>;
  linked_list *entries;
};

program PHONE_BOOK_PROG {
  version PHONE_BOOK_VERS {
    r_val ADD_TO_DATABASE(entry) = 1;
    r_val REMOVE_FROM_DATABASE(string) = 2;
    r_val LOOKUP_NAME(string) = 3;
    r_val LIST(void) = 4;
    int QUIT(void) = 5;
    int TERMINATE(void) = 6;
  } = 1;
} = 0x55550011;