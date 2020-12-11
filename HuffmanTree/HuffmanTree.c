#include <stdio.h>
#include <stdlib.h>
#include "HuffmanTree.h"


void affichageListe(maillon *maillonCurseur)
{
    if(maillonCurseur==NULL)
        return;
    printf("%c",maillonCurseur->lettre);
    printf("%d\n",maillonCurseur->poids);
    affichageListe(maillonCurseur->next);
}

void affichageListeNoeud(noeudModif *noeudCurseur)
{
    while(noeudCurseur!=NULL)
    {
        printf("%c",noeudCurseur->lettre);
        printf("%d\n",noeudCurseur->poids);
        noeudCurseur=noeudCurseur->next;
    }

}

maillon* creationMaillonOccurrence(maillon *maillonListe,maillon *maillonCurseur)
{
    FILE* texte=NULL;
    texte=fopen("texte.txt","r");
    if (texte==NULL)
    {
        printf("erreur\n");
    }
    if (texte!=NULL)
    {


        char caractere;
        caractere=fgetc(texte);///we create the 1st link which is at the base of the list, which does not need any verification
        maillonCurseur->lettre=caractere;
        maillonCurseur->poids=1;
        maillonCurseur->next=NULL;
        maillonListe->next=maillonCurseur;
        int jamaisTraite;
        while(caractere!=EOF)///loop play file
        {
            caractere=fgetc(texte);
            jamaisTraite=1;
            maillonCurseur=maillonListe->next;
            int possibiliteAvancement=1;
            while(possibiliteAvancement==1)
            {
                if(caractere==maillonCurseur->lettre)
                {
                    maillonCurseur->poids++;
                    jamaisTraite=0;
                }
                if(maillonCurseur->next==NULL)
                    possibiliteAvancement=0;
                if(maillonCurseur->next!=NULL)
                    maillonCurseur=maillonCurseur->next;
            }
            if (jamaisTraite==1 && caractere!=EOF)
            {
                maillon *newMaillon;          ///it creates a new link
                newMaillon=malloc(sizeof(maillon));

                newMaillon->poids=1;
                newMaillon->lettre=caractere;
                newMaillon->next=NULL;
                maillonCurseur->next=newMaillon;
            }
        }
        maillonCurseur=maillonListe->next;
    }


    return maillonListe;
}

noeudModif* convertisseur(maillon *maillonCurseur,noeudModif* noeudCurseur,noeudModif* noeudListe)
{
    noeudListe->next=noeudCurseur;///to transfer a linked list to a node list, we will consider that sad will be next


    int possibiliteAvancement=1;
    while(possibiliteAvancement==1)
            {

                noeudCurseur->lettre=maillonCurseur->lettre;
                noeudCurseur->poids=maillonCurseur->poids;

                if(maillonCurseur->next==NULL)
                    possibiliteAvancement=0;
                if(maillonCurseur->next!=NULL)
                {

                    noeudModif *newNoeud;          ///we create a new node as long as there is a link to match
                    newNoeud=malloc(sizeof(noeudModif));
                    newNoeud->next=NULL;
                    newNoeud->sad=NULL;
                    newNoeud->sag=NULL;
                    noeudCurseur->next=newNoeud;

                    noeudCurseur=noeudCurseur->next;
                    maillonCurseur=maillonCurseur->next;

                }

            }
            noeudCurseur=noeudListe->next;///we reset noeudCurseur
    return noeudListe;
}

noeudModif* indice_min(noeudModif* noeudCurseur,noeudModif* noeudListe)
{
    noeudCurseur=noeudListe->next;
    int occurenceMin;
    while(noeudCurseur!=NULL)
    {

        if(noeudCurseur==noeudListe->next)
            occurenceMin=noeudCurseur->poids;

        if(noeudCurseur->poids<=occurenceMin)
            occurenceMin=noeudCurseur->poids;///we now have the minimum possible occurrence


        noeudCurseur=noeudCurseur->next;

    }
    noeudCurseur=noeudListe->next;///we reinitiate to go through the loop a second time and to stop where we see the occurrence

    while(noeudCurseur->poids!=occurenceMin)
        noeudCurseur=noeudCurseur->next;

    return noeudCurseur;

}

noeudModif* list_remove(noeudModif *noeudListe,noeudModif *noeudCurseur)
{
    int lettreSuppr;
    lettreSuppr=noeudCurseur->lettre;///we will do the comparisons with this letter
    noeudCurseur=noeudListe->next;
    int pasPremiereLettre=1;
    noeudModif **pointeurNoeudSuppr;
    if (noeudCurseur->lettre==lettreSuppr)///if we enter here it is because it is the 1st letter that must be changed so we do not have the same connections to make
    {
        pasPremiereLettre=0;
        pointeurNoeudSuppr=&noeudCurseur;///this pointer allows you to not lose what you want to delete
        noeudListe->next=noeudListe->next->next;

    }
    if(pasPremiereLettre==1)
    {
        while(lettreSuppr!=noeudCurseur->next->lettre)///we arrive at the node before the deletion and we can change the connections
        {
            noeudCurseur=noeudCurseur->next;
        }
        pointeurNoeudSuppr=&noeudCurseur->next;///this pointer allows you to not lose what you want to delete
        noeudCurseur->next=noeudCurseur->next->next;///we go over the next link
    }

    free(pointeurNoeudSuppr);
    pointeurNoeudSuppr=NULL;


    noeudCurseur=noeudListe->next;
    return noeudListe;
}

noeudModif* fusion(noeudModif* temp1, noeudModif* temp2,noeudModif* tempFinal)
{

    tempFinal->lettre = '$';///is just used to identify the nodes to work us
    tempFinal->poids = temp1->poids + temp2->poids;
    tempFinal->sad = temp1;
    tempFinal->sag = temp2;

    return tempFinal;

}

noeudModif* creationArbreHuffman(noeudModif *noeudCurseur, noeudModif *noeudListe)
{
    noeudModif *temp1;///we create the 2 temporary links
    temp1=malloc(sizeof(noeudModif));

    noeudModif *temp2;
    temp2=malloc(sizeof(noeudModif));

    while(noeudListe->next->next!=NULL)///as long as there is no more than one node left in the node list, which will match the tree
    {
        affichageListeNoeud(noeudCurseur);
        printf("\n\n");

        noeudCurseur=noeudListe->next;
        noeudCurseur=indice_min(noeudCurseur,noeudListe);
        temp1=noeudCurseur;
        noeudListe=list_remove(noeudListe,noeudCurseur);

        noeudCurseur=indice_min(noeudCurseur,noeudListe);
        temp2=noeudCurseur;
        noeudListe=list_remove(noeudListe,noeudCurseur);

        noeudCurseur=noeudListe->next;
        while (noeudCurseur && noeudCurseur->next)
            noeudCurseur=noeudCurseur->next;


        noeudModif *tempFinal;///we add the final temp
        tempFinal=malloc(sizeof(noeudModif));
        tempFinal->next=NULL;
        tempFinal->sad=NULL;
        tempFinal->sag=NULL;

        if (noeudCurseur)
            noeudCurseur->next=tempFinal;

        if (!noeudCurseur)///at the last operation there is no longer a cursor node so we add the time directly to the list node
            noeudListe->next=tempFinal;

        tempFinal=fusion(temp1,temp2,tempFinal);///we modify the final temp

        noeudCurseur=noeudListe->next;

    }

    return noeudListe;
}



///additional function

/// -------------------------------------------------------------------------- ancillary function
int profondeur_tree(noeudModif *noeudCurseur)
{
    if (noeudCurseur==NULL) return 0;
    else{

        int cote_gauche;
        int cote_droite;
        cote_gauche = profondeur_tree(noeudCurseur->sag);
        cote_droite = profondeur_tree(noeudCurseur->sad);
        if(cote_gauche > cote_droite){
            return cote_gauche + 1;
        }
        else{
            return cote_droite + 1;
        }
    }
}

int nb_feuille(noeudModif *noeudCurseur){
    if (noeudCurseur==NULL) return 0;
    else {
            if ((noeudCurseur->sad==NULL)&&(noeudCurseur->sag==NULL)){
                return 1;
            }
            return (nb_feuille(noeudCurseur->sad)+nb_feuille(noeudCurseur->sag));
        }
}

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void print_tree(noeudModif* noeudCurseur)
{
    if(noeudCurseur != NULL){

        printf("%d-%c\n", noeudCurseur->poids,noeudCurseur->lettre);
        print_tree(noeudCurseur->sag);
        print_tree(noeudCurseur->sad);
    }
}
