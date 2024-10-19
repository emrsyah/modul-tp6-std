#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define next(p) p->next
#define prev(p) p->prev
#define info(P) P->info

using namespace std;
struct laguBand {
  string band;
  string lagu;
};
typedef laguBand infotype;
typedef struct elmlist *address;

struct elmlist {
  infotype info;
  address next;
  address prev;
};

struct List {
  address first;
  address last;
};

bool isEmpty_103012300339(List L);
void createNewElmt_103012300339(infotype X, address &P);
void insertFirst_103012300339(List &L, address P);
void insertAfter_103012300339(List &L, address &Prec, address &P);
void insertLast_103012300339(List &L, address P);
void deleteFirst_103012300339(List &L, address &P);
void deleteAfter_103012300339(List &L, address &Prec, address &P);
void deleteLast_103012300339(List &L, address &P);
void concat_103012300339(List L1, List L2, List &L3);
address findLagu_103012300339(string Judul, List L);
void removeLagu_103012300339(string Judul, List &L);
void createList_103012300339(List &L);

#endif // DLL_H_INCLUDED



