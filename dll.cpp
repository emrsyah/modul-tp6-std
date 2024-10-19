#include "dll.h"

void createList_103012300339(List &L){
    first(L) = NULL;
    last(L) = NULL;
};

bool isEmpty_103012300339(List L){
  return (first(L) == NULL && last(L) == NULL);
}
void createNewElmt_103012300339(infotype X, address &P){
  P = new elmlist;
  info(P) = X;
  next(P) = NULL;
  prev(P) = NULL;
}
void insertFirst_103012300339(List &L, address P){
  if (isEmpty_103012300339(L)){
    first(L) = P;
    last(L) = P;
  } else {
    next(P) = first(L);
    prev(first(L)) = P;
    first(L) = P;
    prev(first(L)) = NULL;
  }
}

void insertAfter_103012300339(List &L, address &Prec, address &P){
  if (Prec == last(L)){
    prev(P) = Prec;
    next(Prec) = P;
    last(L) = P;
  } else {
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
    prev(next(P)) = P;
  }
}

void insertLast_103012300339(List &L, address P){
  if (first(L) == NULL){
    first(L) = P;
    last(L) = P;
  } else {
    next(last(L)) = P;
    prev(P) = last(L);
    last(L) = P;
  }
}

void deleteFirst_103012300339(List &L, address &P){
  if (next(first(L)) == NULL){
    P = first(L);
    first(L) = NULL;
    last(L) = NULL;
  } else {
    P = first(L);
    prev(next(P)) = NULL;
    first(L) = next(P);
    next(P) = NULL;
  }
}
void deleteAfter_103012300339(List &L, address &Prec, address &P){
  if (next(Prec) == last(L)){
    P = last(L);
    last(L) = Prec;
    next(Prec) = NULL;
    prev(P) = NULL;
  } else {
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
  }
}

void deleteLast_103012300339(List &L, address &P){
  P = last(L);
  if (first(L) == last(L)){
    first(L) = NULL;
    last(L) = NULL;
  } else{
  last(L) = prev(P);
  next(prev(P)) = NULL;
  prev(P) = NULL;
  }
}

void concat_103012300339(List L1, List L2, List &L3) {
    createList_103012300339(L3);
    address P = first(L1);
    while (P != NULL) {
        address newP;
        createNewElmt_103012300339(info(P), newP);
        insertLast_103012300339(L3, newP);
        P = next(P);
    }
    P = first(L2);
    while (P != NULL) {
        address newP;
        createNewElmt_103012300339(info(P), newP);
        insertLast_103012300339(L3, newP);
        P = next(P);
    }
}

address findLagu_103012300339(string Judul, List L){
  address q = first(L);
  while (q != NULL){
    if (info(q).lagu == Judul){
        return q;
    }
    q = next(q);
  }
  return NULL;
}
void removeLagu_103012300339(string Judul, List &L){
  address adrLagu = findLagu_103012300339(Judul, L);
  address tmp;
  if (adrLagu == first(L)){
    deleteFirst_103012300339(L, tmp);
  } else if (adrLagu == last(L)){
  deleteLast_103012300339(L, tmp);
} else {
  deleteAfter_103012300339(L, prev(adrLagu), tmp);
}
}
