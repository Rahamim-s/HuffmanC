/*****************************************************************//**
 * \file   D_Compress.h
 * \brief  header used to compress files and create a new file
 * 
 * \author VincentEung and Ralys Lallali
 * \date   11 December 2020
 *********************************************************************/

#ifndef D_COMPRESS_H_INCLUDED
#define D_COMPRESS_H_INCLUDED

/**
 * \brief Function to create a new text file in which we put the caracters we find 
 */
void creationFichierCodage();

/**
 * \brief Function text translated in binary
 * \get back the code in the files
 * \pointeurDicoCode is the pointer which scroll the dico until it finds the right value 
 */
void decodage();

#endif // D_COMPRESS_H_INCLUDED
