#include "llista.h"
#include <stdio.h>

LlistaBid LLISTABID_crea() {
    LlistaBid l;
    Node aux1, aux2;

    l.cap = (Node*)malloc(sizeof(Node));
    if (l.cap == NULL) {
        printf("Error!\n");
    }
    else {
        l.ult = (Node*)malloc(sizeof(Node));
        if (l.ult == NULL) {
            printf("Error\n");
            free(l.cap);
        }

        else {
            l.cap->seg = l.ult;
            l.ult->ant = l.cap;
            l.ult->seg = NULL;
            l.cap->ant = NULL;
            l.pdi = l.ult;
        }
    }

    return l;
}

void LLISTABID_esborra(LlistaBid *l) {
    Node *aux;
    if (l->pdi == l->cap || l->pdi == l->ult) {
        printf("Error!\n");
    }

    else {
        aux = l->pdi;
        l->pdi = l->pdi->seg;
        aux->ant->seg = aux->seg;
        aux->seg->ant = aux->ant;
        free(aux);
    }
}

void LLISTABID_insereixOrdenat(LlistaBid *l, Element e) {
    Node *aux, *pdi;
    int trobat = 0;
    aux = (Node*)malloc(sizeof(Node));

    if (aux == NULL) {
        printf("ERROR! No es pot inserir l'element.\n");
    }

    else {
        aux->e = e;
        pdi = l->pdi;
        l->pdi = l->cap->seg;

        if (l->cap->seg == l->ult){
            aux->seg = l->pdi;
            aux->ant = l->pdi->ant;
            aux->ant->seg = aux;
            l->pdi->ant = aux;

        }
        else{
            l->pdi = l->cap->seg;
            while (!trobat && l->pdi!=NULL) {
                if (l->pdi->e <= e){
                    l->pdi = l->pdi->seg;
                }

                else{
                    trobat = 1;
                    aux->seg = l->pdi;
                    aux->ant = l->pdi->ant;
                    aux->ant->seg = aux;
                    l->pdi->ant = aux;
                }
            }

            if (!trobat){
                l->pdi = l->ult;
                aux->seg = l->pdi;
                aux->ant = l->pdi->ant;
                aux->ant->seg = aux;
                l->pdi->ant = aux;
            }

            l->pdi= pdi;
        }
    }
}

Element LLISTABID_consulta(LlistaBid l) {
    Element e;
    e = ELEMENT_indef;

    if (l.pdi == l.cap || l.pdi == l.ult) {
        printf("No es pot consultar aquest element.\n");
    }

    else {
        e = l.pdi->e;
    }

    return e;
}

void LLISTABID_avanca(LlistaBid *l) {
    if (l->pdi->seg != NULL) {
        l->pdi = l->pdi->seg;
    }
    else {
        printf("Error!\n");
    }
}

void LLISTABID_retrocedeix(LlistaBid *l) {
    if (l->pdi== l->cap) {
        printf("Error!\n");
    }
    else {
        l->pdi = l->pdi->ant;
    }
}

void LLISTABID_vesInici(LlistaBid *l) {
    l->pdi = l->cap->seg;
}

void LLISTABID_vesFinal(LlistaBid *l) {
    l->pdi = l->ult->ant;
}

int LLISTABID_fi(LlistaBid l) {
    return l.pdi == l.ult;
}

int LLISTABID_inici(LlistaBid l) {
    return l.pdi == l.cap;
}

int LLISTABID_buida(LlistaBid l) {
    return l.cap->seg == l.ult;
}

void LLISTABID_destrueix(LlistaBid *l) {
    Node *aux;
    aux = l->cap;

    while (l->cap == NULL)
    {
        l->cap = l->cap->seg;
        free(aux);
        aux = l->cap;
    }

    l->ult = NULL;
    l->pdi = NULL;
}

