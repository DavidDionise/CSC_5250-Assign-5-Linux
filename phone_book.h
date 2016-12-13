/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _PHONE_BOOK_H_RPCGEN
#define _PHONE_BOOK_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct entry {
	char *name;
	char *number;
	struct entry *next;
};
typedef struct entry entry;

struct r_val {
	int num;
	char *message;
};
typedef struct r_val r_val;

struct linked_list {
	struct entry *head;
};
typedef struct linked_list linked_list;

#define PHONE_BOOK_PROG 0x55550011
#define PHONE_BOOK_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define ADD_TO_DATABASE 1
extern  r_val * add_to_database_1(entry *, CLIENT *);
extern  r_val * add_to_database_1_svc(entry *, struct svc_req *);
#define REMOVE_FROM_DATABASE 2
extern  r_val * remove_from_database_1(char **, CLIENT *);
extern  r_val * remove_from_database_1_svc(char **, struct svc_req *);
#define LOOKUP_NAME 3
extern  r_val * lookup_name_1(char **, CLIENT *);
extern  r_val * lookup_name_1_svc(char **, struct svc_req *);
#define LIST 4
extern  r_val * list_1(void *, CLIENT *);
extern  r_val * list_1_svc(void *, struct svc_req *);
#define QUIT 5
extern  int * quit_1(void *, CLIENT *);
extern  int * quit_1_svc(void *, struct svc_req *);
#define TERMINATE 6
extern  int * terminate_1(void *, CLIENT *);
extern  int * terminate_1_svc(void *, struct svc_req *);
extern int phone_book_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define ADD_TO_DATABASE 1
extern  r_val * add_to_database_1();
extern  r_val * add_to_database_1_svc();
#define REMOVE_FROM_DATABASE 2
extern  r_val * remove_from_database_1();
extern  r_val * remove_from_database_1_svc();
#define LOOKUP_NAME 3
extern  r_val * lookup_name_1();
extern  r_val * lookup_name_1_svc();
#define LIST 4
extern  r_val * list_1();
extern  r_val * list_1_svc();
#define QUIT 5
extern  int * quit_1();
extern  int * quit_1_svc();
#define TERMINATE 6
extern  int * terminate_1();
extern  int * terminate_1_svc();
extern int phone_book_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_entry (XDR *, entry*);
extern  bool_t xdr_r_val (XDR *, r_val*);
extern  bool_t xdr_linked_list (XDR *, linked_list*);

#else /* K&R C */
extern bool_t xdr_entry ();
extern bool_t xdr_r_val ();
extern bool_t xdr_linked_list ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_PHONE_BOOK_H_RPCGEN */
