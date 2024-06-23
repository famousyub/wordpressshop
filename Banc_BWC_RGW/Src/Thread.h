
// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//  
// 
// ==============================================================================
//   PROJET			: Banc Personnalisation
//   MODULE			: Thread
//   PROCESSEUR		: INTEL Pentium
//   ENVIRONNEMENT	: Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION	: D�finition des t�ches de gestion des test fonctionnel
//					  et acc�s aux bases de donn�es.
//            		  
// ==============================================================================
//   REMARQUES		:
// ==============================================================================
//   MODIFICATIONS	:   
//
// Version Rev X
// Date / Author
//
// V 1.3.9 
// 16-Septembre-2009	NCR (DT2E)
//		>>>	 Cr�ation
// ==============================================================================
#ifndef __THREAD_H__
#define __THREAD_H__


// ==============================================================================
// DECLARATION DES CONSTANTES
// ==============================================================================


// ==============================================================================
// DECLARATION DES STRUCTURES ET ENUMERATIONS
// ==============================================================================


// ==============================================================================
// DECLARATION DES VARIABLES GLOBALES
// ==============================================================================

// Gestion Multitache
extern int IdLockCle;											// Verrou pour acc�s au serveur BDD en multithreads
extern int IdLockNvm;											// Verrou pour acc�s au serveur BlackBox en multithreads
extern int IdSnClient;											// Verrou pour acc�s au serveur BDD en multithreads
extern int IdPrinter;											// Verrou pour acc�s � l'imprimante en multithreads


// ==============================================================================
// DECLARATION DES PROTOTYPES
// ==============================================================================

extern int __stdcall ThreadSlot (void * data);
extern int __stdcall ThreadTestFonc (void * data);
extern int __stdcall ThreadLectureBdd (void * data);
int THREADS_TrouverTag(int, char * , char * );  

#endif	// #ifndef __THREAD_H__
