/*
*
@author: Victor Aznar Echevarria - victor.aznar
*
*/

#include "llista.h"

void main() {
    int opcio;
    Element e;
    LlistaBid l = LLISTABID_crea();
    afegeixElement(l);
    afegeixElement(l);
    afegeixElement(l);
    afegeixElement(l);
    afegeixElement(l);
    afegeixElement(l);
    afegeixElement(l);
    llista_inici(l);
    llista_final(l);
    destrueixLlista(l);
}

void afegeixElement(LlistaBid l) {
    Element e;
    printf("Afegiu un numero: \n");
    scanf("%d", &e);
    LLISTABID_insereixOrdenat(&l, e);
    printf("S\'ha afegit un numero\n");
}

void destrueixLlista(LlistaBid l) {
    LLISTABID_destrueix(&l);
    printf("\nLlista suprimida.\n");
}

void llista_inici(LlistaBid l) {
    Element e;
    printf("\nElements de la llista sencera del dret:\n");
    printf("\n");
    LLISTABID_vesInici(&l);
    while (!LLISTABID_fi(l)) {
        e = LLISTABID_consulta(l);
        printf("\t%d\n", e);
        LLISTABID_avanca(&l);
    }
}

void llista_final(LlistaBid l) {
    Element e;
    printf("\nElements de la llista sencera a l'inreves:\n");
    printf("\n");
    LLISTABID_vesFinal(&l);
	
    while (!LLISTABID_inici(l)) {
        e = LLISTABID_consulta(l);
        printf("\t%d\n", e);
        LLISTABID_retrocedeix(&l);
    }
}