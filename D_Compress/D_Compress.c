#include <stdio.h>
#include <stdlib.h>
#include "../D_compress/D_Compress.h"


void decodage()
{
    FILE* texteFinal=NULL;
    texteFinal=fopen("texteFinal.txt","r");///Text written in binary
    if (texteFinal==NULL)
    {
        printf("erreur\n");
    }
    if (texteFinal!=NULL)
    {

        FILE* dico=NULL;
            dico=fopen("dico.txt","r");
            if (dico==NULL)
            {
                printf("erreur\n");
            }
            if (dico!=NULL)
            {

                FILE* texteFinal2=NULL;
                texteFinal2=fopen("texteFinal2.txt","w");///The text that is translated from the binary
                if (texteFinal2==NULL)
                {
                    printf("erreur\n");
                }
                if (texteFinal2!=NULL)
                {
                    char pointeurTexteCode[9];

                    while(fgets(pointeurTexteCode,9,texteFinal)!=NULL)///we get the code in the text
                    {
                        char pointeurDicoCode[9];
                        char lettreCorrespondante;
                        while(strcmp(pointeurDicoCode,pointeurTexteCode))
                        {
                            fscanf(dico,"%c%*[\n]",&lettreCorrespondante);
                            fgets(pointeurDicoCode,9,dico);///it works through the dico until he finds the right value
                            printf("%s-%s\n",pointeurDicoCode,pointeurTexteCode);
                            printf("lettre:%c\n",lettreCorrespondante);
                        }
                        fprintf(texteFinal2,"%c",lettreCorrespondante);
                        rewind(dico);
                        //fgets(pointeurTexteCode,9,texteFinal);///we get the code in the text
                        printf("chaine recup dans texte: %s\n",pointeurTexteCode);
                        printf("ecriture\n");
                    }

                }
                fclose(dico);
                fclose(texteFinal);
                fclose(texteFinal2);
            }
    }


}

void creationFichierCodage()
{

    FILE* texte=NULL;
    texte=fopen("texte.txt","r");
    if (texte==NULL)
    {
        printf("erreur\n");
    }
    if (texte!=NULL)
    {

        FILE* dico=NULL;
            dico=fopen("dico.txt","r");
            if (dico==NULL)
            {
                printf("erreur\n");
            }
            if (dico!=NULL)
            {

                FILE* texteFinal=NULL;
                texteFinal=fopen("texteFinal.txt","w");
                if (texteFinal==NULL)
                {
                    printf("erreur\n");
                }
                if (texteFinal!=NULL)
                {
                    char caractere;
                    caractere=fgetc(texte);///we create the cursor that reads the text to translate

                    while (caractere!=EOF)
                    {
                        char pointeurDicoLettre;///we create the cursor which reads and searches for the code
                        char pointeurDicoCode[9];
                        //pointeurDicoLettre=fgetc(dico);
                        fscanf(dico,"%c%*[\n]",&pointeurDicoLettre);
                        while (caractere!=pointeurDicoLettre)
                        {
                            fgets(pointeurDicoCode,9,dico);
                            //fscanf(dico,"%s%*[\n]",&pointeurDicoCode);
                            //pointeurDicoLettre=fgetc(dico);
                            fscanf(dico,"%c%*[\n]",&pointeurDicoLettre);
                        }
                        fgets(pointeurDicoCode,9,dico);
                        fprintf(texteFinal,"%s",pointeurDicoCode);
                        rewind(dico);
                        caractere=fgetc(texte);
                    }
                }
                fclose(dico);
                fclose(texte);
                fclose(texteFinal);
            }
    }

}




