/*****************************************************************//**
 * \file   HuffmanTree.h
 * \brief  header where the link and node structs are located, as well as the functions handling the Huffman tree
 * 
 * \author JULIEN MABECQUE/SITBON RAHAMIM julien.mabecque@efrei.net
 * \date   December 2020
 *********************************************************************/

#ifndef HUFFMANTREE_H_INCLUDED
#define HUFFMANTREE_H_INCLUDED


/**
 * \typedef struct maillon
 * \brief struct for using chain list
 * \poids -> the number of the same letter in the text
 * \lettre -> the letter of the text
 * \maillon* next -> use for create a chain list
 */
typedef struct maillon
{
    int poids;
    char lettre;
    struct maillon* next;

}maillon;

/**
 * \typedef struct noeudModif
 * \brief sturct for the node, we also use next in the node for allow us to have a node list in the same struct
 * \poids -> the number of the same letter in the text
 * \lettre -> the letter of the text
 * \noeudModif* next -> use for create a node list in a easier way than put a node in a real chain list
 * \noeudModif* sag -> the left child of the node
 * \noeudModif* next -> the right chil of the node
 */
typedef struct noeudModif
{
    int poids;
    char lettre;
    struct noeudModif* next;
    struct noeudModif* sag;
    struct noeudModif* sad;

}noeudModif;

/**
 * \brief : function that displays a link structure list ( used for unit tests)
 * \param : maillonCurseur-> List of occurrences and letters
 */
void affichageListe(maillon *maillonCurseur);
/**
 * \param noeudListe -> used for reset noeudCurseur (used for unit tests)
 * \param noeudCurseur -> our list of node.
 */
void affichageListeNoeud(noeudModif *noeudCurseur);
/**
 * param: maillonListe allows to reset the link cursor, 
 * param: maillionCurseur: cursor that allows to move in the list
 * return creates a list with the occurrence of his letter from a file
 */
maillon* creationMaillonOccurrence(maillon *maillonListe,maillon *maillonCurseur);
/**
* \brief convert a chain list into a node list
 * param: maillionCurseur: cursor that allows to move in the list
 * param: noeudListe -> used for reset noeudCurseur
 * param: noeudCurseur -> our list of node
 * return -> noeudList
 */
noeudModif* convertisseur(maillon *maillonCurseur,noeudModif* noeudCurseur,noeudModif* noeudListe);
/**
 * \brief function for remove a node from the list of node
 * \param noeudListe -> used for reset noeudCurseur
 * \param noeudCurseur -> our list of node
 * \return noeudListe -> return the list once modified
 */
noeudModif* list_remove(noeudModif *noeudListe,noeudModif *noeudCurseur);
/**
 * \brief search of the lowest weight's position of the list
 * \param noeudListe -> used for reset noeudCurseur
 * \param noeudCurseur -> our list of node
 * \return NoeudCurseur -> return the node at the position of the lowest weight of the list
 */
noeudModif* indice_min(noeudModif* noeudCurseur,noeudModif* noeudListe);
/**
 * \brief create the new node with the two node who were deleted
 * \param temp1 -> one of the two lowest weight's node
 * \param temp2 -> one of the two lowest weight's node
 * \param tempFinal -> the node who is create
 * \return tempFinal -> the node who is create
 */
noeudModif* fusion(noeudModif* temp1, noeudModif* temp2, noeudModif* tempFinal);
/**
 * \brief function who create the Huffman tree by using list_remove, indice_min and fusion
 * \param noeudListe -> used for reset noeudCurseur
 * \param noeudCurseur -> our list of node
 * \return noeudCurseur -> noeudCurseur is now a tree wich contain every node and the list of node doesn't exist anymore
 */
noeudModif* creationArbreHuffman(noeudModif *noeudCurseur, noeudModif *noeudListe);


/// <summary>
/// some usefull function who may be important for working
/// </summary>
/// <param name="noeudCurseur"></param>
void print_tree(noeudModif* noeudCurseur);
void viderBuffer();




#endif // HUFFMANTREE_H_INCLUDED
