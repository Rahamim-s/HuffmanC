/*****************************************************************//**
 * \file   Dico.h
 * \brief  
 * 
 * \author Florian ALEXANDRE et Menkem HUET
 * \date   11/12/2020
 *********************************************************************/
#ifndef DICO_H_INCLUDED
#define DICO_H_INCLUDED
#include "../Stack/Stack.h"
 /**
  * \typedef struct LSC
  * \brief a LSC is a temporary simply chained list.
  */
typedef struct LSC
{
    int numero;
    char lettre;
    struct LSC* succ;
}LSC;

typedef LSC* List_lettre;
/**
 * \brief Function to create a simply chained list.
 * \n Example :
 * \code{.c}
 * List_lettre *test = List_lettre create_LSC(10);
 * \endcode
 * \param size of the simply chained list.
 * \return an LSC's pointer, if the simply chained list is created.
 * \return \c NULL, if the simply chained list could not be created.
 */
List_lettre create_LSC(int n);

/**
 * \brief Function to initialize a simply chained list.
 * \n Example :
 * \code{.c}
 * modif(test);
 * \endcode
 * \param the simply chained list who is going to be changed.
 */
void modif(LSC *l);

/**
 * \brief Function to create a file.
 * \n Example :
 * \code{.c}
 *  conversion_bin ("start.txt");
 * \endcode
 * \param file who is going to be translated.
 */
void conversion_bin (char* path); 

/**
 * \brief Function to count the number of binary element of a file.
 * \n Example :
 * \code{.c}
 *  nb_char();
 * \endcode
 * \param nothing.
 */
void nb_char(); 

/**
 * \brief Function to reverse a simply chained list.
 * \n Example :
 * \code{.c}
 * l = reverse_LSC(l, tree);
 * \endcode
 * \param the simply chained list who is going to be reversed and the tree to know the size of the simply chained list.
 * \return an LSC's pointer, if the simply chained list is reversed.
 */
LSC* reverse_LSC (LSC *l, noeudModif* noeudCurseur);

/**
 * \brief Function to create and fill a file.
 * \n Example :
 * \code{.c}
 * add_fichier(l, tree);
 * \endcode
 * \param the simply chained list who is going to be written in the file and the tree to know the size of the simply chained list.
 */
void add_fichier(LSC *l, noeudModif* noeudCurseur);

/**
 * \brief Function to create and fill a file.
 * \n Example :
 * \code{.c}
 * add_fichier(l, tree);
 * \endcode
 * \param the simply chained list who is going to be written in the file and the tree to know the size of the simply chained list.
 */
void afficher_LSC(LSC *l, noeudModif* noeudCurseur);

/**
 * \brief Function to fill a simply chained list with a tree.
 * \n Example :
 * \code{.c}
 * Afficher(tree,stack,n,ref_stack,l,pi);
 * \endcode
 * \param the tree who is going to be analysed, two stacks, a integer variable, a integer pointer and a simply chained list.
 */
void Afficher(noeudCurseur, ps, n, refps, l, pi);

/**
 * \brief Function know the depth of a tree.
 * \n Example :
 * \code{.c}
 * int depth = profondeur_tree(tree);
 * \endcode
 * \param the tree who is going to be analysed.
 * \return the depth of the tree.
 */
int profondeur_tree(noeudModif* noeudCurseur);

/**
 * \brief Function know number of leave of a tree.
 * \n Example :
 * \code{.c}
 * int number_of_leave = nb_feuille(tree);
 * \endcode
 * \param the tree who is going to be analysed.
 * \return the number of leave of the tree.
 */
int nb_feuille(noeudModif* noeudCurseur);

#endif // DICO_H_INCLUDED
