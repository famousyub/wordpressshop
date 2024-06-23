// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//  
// 
// ==============================================================================
//   PROJET			: Banc HDD
//   MODULE			: Globale
//   PROCESSEUR		: INTEL Pentium
//   ENVIRONNEMENT	: Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION	: D�finition des variables et constantes globales.
//            		  
// ==============================================================================
//   REMARQUES		:
// ==============================================================================
//   MODIFICATIONS	:   
//
// Version Rev X
// Date / Author
//
// V 1.1.0 
// 15-D�cembre-2009			EAH
//		>>>	 Cr�ation issue du banc de personnalisation
// ==============================================================================
#ifndef __GLOBALE_H__
#define __GLOBALE_H__
//#include <rsnrpz.h>

// ==============================================================================
// DECLARATION DES STRUCTURES ET ENUMERATIONS
// ==============================================================================

// D�finition d'un SLOT
// --------------------
typedef struct
{
	int					id;										// Index du SLOT
	int					idThread;								// ID thread du SLOT
	int 				nCompteurPassages;												// Compteur de passage par Slots
	HANDLE				hdleThread;								// Handle thread du SLOT
	T_VARIABLES			variablesConf;							// D�finition des variables de configuration utilis�es par le produit
	T_VARIABLES			variablesConfPoste;					   // D�finition des variables de configuration utilis�es par poste    
	T_VARIABLES			variablesConfSn;						// D�finition des variables de configuration utilis�es pour le SN
	T_VARIABLES			variablesEtat;							// D�finition des variables d'�tat utilis�es par le produit
	T_VARIABLES_TRACA	variablesTraca;							// D�finition des variables de traca
	T_MESURES			mesures;								// D�finition des mesures utilis�es par le produit
	T_MESURES1			mesures1;								// D�finition des mesures utilis�es par le produit
	T_IHM_SLOT			ihmSlot;								// IHM du SLOT
	T_PORT_COM 			comDecodeur;				   			// Port COM decodeur
	T_PORT_COM 			comImprimante;			   				// Port COM imprimante
	T_PORT_COM 			comGenerique_A;
	T_PORT_COM 			comCaisson ;						// Port COM caisson
	// Port COM Generique A
	//T_PORT_USB			comUsb;									// Port USB du HDD
    //T_PC_CLIENT         pcclient;                               // PC Client
	//T_PC_SERVEUR        pcserveur;                              // PC Serveur
	char 				chCheminLog[TAILLE_MIN];				// Chemin complet du r�pertoire contenant les fichiers LOG
	char 				chCheminMasqueEtiquette[TAILLE_MIN];	// Chemin complet du fichier masque �tiquette
	char 				chCheminLogoEtiquette[TAILLE_MIN];	// Chemin complet du fichier logo �tiquette
	long				nTempsDebutTest;						// Valeur du compteur de tick (ms) en d�but de test
	long				nTempsFinTest;							// Valeur du compteur de tick (ms) en fin de test
	char 				stbTraceDemarrage[TAILLE_MOY];	// Trace de d�marrage du d�codeur
	char 				stbLog[580000];				// Trace LOG du test du d�codeur
	char				chMoisJourAnnee[TAILLE_MIN];			// MM-JJ-AAAA au d�marrage du banc
	// Les liens de com en telnet
	//-------------------------------------------------------------------------------------
	int                 igHandleConnexion;                      	// Handle de connexion 
	//ressource ME
	char 				sRessource[TAILLE_MAX];				//ressource ME
	T_BNFT            	BNFTnteg;										// D�finition des variables bouton
	ViSession           g_Session; 
	int                 HandleTelnetSwitch_SP8T;
	int                 HandleTelnetSwitch_SP12T;
	char                Bufflu[TAILLE_MAX];

}T_SLOT;



// ==============================================================================
// DECLARATION DES VARIABLES GLOBALES
// ==============================================================================

// Param�tre de connexion � la base TracaCom
// -----------------------------------------
extern T_TCOM_BASE gTcomBase;

// Informations sur le poste d'ex�cution
// -------------------------------------
extern T_POSTE_INFOS gPosteInfos;

// Liste des produits disponible pour le poste
// -------------------------------------------
extern T_POSTE_PRODUITS gPosteProduits;

// D�finition des slots
// --------------------
extern T_SLOT gSlot[NBRE_INTERFACE]; 

// Fichiers ou r�pertoires
// -----------------------
extern char gChCurrentDir[MAX_PATHNAME_LEN];				// R�pertoire courant
extern char gChIniFile[MAX_PATHNAME_LEN];					// Fichier INI complet
extern char gChUirFile[MAX_PATHNAME_LEN];					// Fichier UIR
extern char gChNomPc[MAX_PATHNAME_LEN];						// Nom du PC
extern char gChCheminEtiquette[TAILLE_MIN];				// Chemin complet du r�pertoire contenant les masques d'�tiquettes

// Flag d'activation des fonctions SLOT
// ------------------------------------
extern int gnFonctionConfiguration;							// Flag d'activation de la fonction de configuration
extern int gnFonctionImprimante;							// Flag d'activation de la fonction de test imprimante
extern int gnFonctionVerrou;								// Flag d'activation des fonctions de pilotage verrou
extern int gnFonctionTraca;									// Flag d'activation des fonctions de traca
extern int gnFonctionModeUsb;								// D�finition du mode USB � deux ou trois param�tres
// Flag indiquant que l'application doit se terminer
// -------------------------------------------------
extern volatile int gNPAbort;								// Flag appuie de quitter ( fermeture panel principal )
extern volatile int gFlagLancementTest[NBRE_INTERFACE];		// Flag de lancement manuel du test

// Flag indiquant si le fichier LOG doit �tre cr��
// -----------------------------------------------
extern int gActiveLog;
extern int gnPresenceDio;										// Flag de desactivation de la Dio 
extern int gnCanal2G;
extern int gnCanal5G;
// Date Heure
// ----------
extern T_DATE_HEURE gDateHeure;


// Variables pour Dinan
// ----------------------
extern int gConnexionDinan;
// Gestion Lock Multitache
// -----------------------
extern int IdLockBDD;                                          // Verrou pour acc�s au serveur BDD en multithreads
extern int IdLockNvm;                                          // Verrou pour acc�s au serveur BlackBox en multithreads
extern int IdSnClient;                                         // Verrou pour acc�s au serveur BDD en multithreads
extern int IdStartSfc;                                         // Verrou pour acc�s au serveur BDD en multithreads
extern int IdLockDongleTexasInstrument;                        	// Verrou pour acc�s au DongleTexasInstrument en multithreads
extern int IdLockIR;                        					// Verrou pour �mission trame IR (�viter les perturbations interslots)
extern int IdLockNetwork;                        				// Verrou pour les requete r�seau comme Ping ou transfert FTP
extern int IdLockFollows;                        				// Verrou pour les appels � la DLL de Follow
extern int IdLockFichierLog[NBRE_INTERFACE];					// Verrou pour acc�s au fichier de Log de chaque Slot
extern int IdLockTextBox[NBRE_INTERFACE];						// Verrou pour acc�s � la Text Box (IHM) de chaque Slot
// Variables Globales Log infos TRaca SAP ME
// ----------------------------------------- 
extern int  gFlagLogSAPME; 									// Flag pour savoir si on Log les infos SAP ME ou non..
extern int  gFlagTelnetDect; 
extern int Handlescript;

extern int  gnPresenceCartePicIr;                                                                                                                      // 0 Absent 1 Pr�sent  
extern char gChNomProduit[TAILLE_MIN];
extern char message_TXT_info[TAILLE_MAX];
extern char Code_Erreur[TAILLE_MAX];
extern int Temps_Test_intermediaire;
extern char msg_erreur_persiste[TAILLE_MAX];

#endif	// #ifndef __GLOBALE_H__
