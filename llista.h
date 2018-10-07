#ifndef _LLISTAH_
#define _LLISTAH_

#include <stdlib.h>
#include <stdio.h>

#define ELEMENT_indef -1

typedef int Element;

typedef struct n {
    Element e;
    struct n *seg;
    struct n *ant;
}Node;

typedef struct {
    Node *cap;
    Node *ult;
    Node *pdi;
}LlistaBid;

LlistaBid LLISTABID_crea();
void LLISTABID_insereixOrdenat(LlistaBid *l, Element e);
Element LLISTABID_consulta(LlistaBid l);
void LLISTABID_esborra(LlistaBid *l);
void LLISTABID_avanca(LlistaBid *l);
void LLISTABID_retrocedeix(LlistaBid *l);
void LLISTABID_vesInici(LlistaBid *l);
void LLISTABID_vesFinal(LlistaBid *l);
int LLISTABID_fi(LlistaBid l);
int LLISTABID_inici(LlistaBid l);
int LLISTABID_buida(LlistaBid l);
void LLISTABID_destrueix(LlistaBid *l);
void afegeixElement(LlistaBid l);
void destrueixLlista(LlistaBid l);
void llista_inici(LlistaBid l);
void llista_final(LlistaBid l);

#endif
