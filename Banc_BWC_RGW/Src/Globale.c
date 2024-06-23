// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//  
// 
// ==============================================================================
//   PROJET			: Banc HDD
//   MODULE			: TracaCom
//   PROCESSEUR		: INTEL Pentium
//   ENVIRONNEMENT	: Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION	: Gestion de la base TracaCom.
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
// 15-Décembre-2009			EAH
//		>>>	 Création issue du banc de personnalisation
// ==============================================================================


// ==============================================================================
// INCLUDE
// ==============================================================================

#include "Include.h"


// ==============================================================================
// DECLARATION DES VARIABLES GLOBALES
// ==============================================================================

// Paramètre de connexion à la base TracaCom
// -----------------------------------------
T_TCOM_BASE gTcomBase;

// Informations sur le poste d'exécution
// -------------------------------------
T_POSTE_INFOS gPosteInfos;

// Liste des produits disponible pour le poste
// -------------------------------------------
T_POSTE_PRODUITS gPosteProduits;

// Définition des slots
// --------------------
T_SLOT gSlot[NBRE_INTERFACE];

// Fichiers ou répertoires
// -----------------------
char gChCurrentDir[MAX_PATHNAME_LEN];							// Répertoire courant
char gChIniFile[MAX_PATHNAME_LEN];								// Fichier INI complet
char gChUirFile[MAX_PATHNAME_LEN] = "ihm\\IhmNFT.uir";			// Fichier UIR
char gChNomPc[MAX_PATHNAME_LEN];								// Nom du PC
char gChCheminEtiquette[TAILLE_MIN];							// Chemin complet du répertoire contenant les masques d'étiquettes

// Flag d'activation des fonctions SLOT
// ------------------------------------
int gnFonctionConfiguration = 0;								// Flag d'activation de la fonction de configuration
int gnFonctionImprimante = 0;									// Flag d'activation de la fonction de test imprimante
int gnFonctionVerrou = 0;										// Flag d'activation des fonctions de pilotage verrou
int gnFonctionTraca = 0;										// Flag d'activation des fonctions de pilotage verrou
int gnFonctionSansDio = 0;										// Flag d'activation du banc sans DIO (Bouton GO)

// Flag d'activation des fonctions SLOT
// ------------------------------------
int gnPresenceDio = 1;
int gnCanal2G = 0;
int gnCanal5G = 0;
// Flag de desactivation de la Dio

// Flag indiquant que l'application doit se terminer
// -------------------------------------------------
volatile int gNPAbort;											// Flag appuie de quitter ( fermeture panel principal )
volatile int gFlagLancementTest[NBRE_INTERFACE];				// Flag de lancement manuel du test

// Flag indiquant si le fichier LOG doit être créé
// -----------------------------------------------
int gActiveLog;

// Date Heure
// ----------
T_DATE_HEURE gDateHeure;

// Variables pour Dinan
// ----------------------
int gConnexionDinan;

// variable arbre usb
//--------------------
int gLockUsbTree;
int gLockDiskpart;
int gLockOpenVerin;
// Gestion Multitache
// ------------------
int IdLockBDD;											// Verrou pour accès au serveur BDD en multithreads
int IdLockNvm;											// Verrou pour accès au serveur BlackBox en multithreads
int IdSnClient;											// Verrou pour accès au serveur BDD en multithreads
int IdStartSfc;											// Verrou pour accès au serveur BDD en multithreads
int IdLockDongleTexasInstrument;                        // Verrou pour accès au DongleTexasInstrument en multithreads
int IdLockIR;                        					// Verrou pour émission trame IR (éviter les perturbations interslots)
int IdLockNetwork;                        				// Verrou pour les requete réseau comme Ping ou transfert FTP
int IdLockFollows;                        				// Verrou pour les appels à la DLL de Follow
int IdLockFichierLog[NBRE_INTERFACE];					// Verrou pour accès au fichier de Log de chaque Slot
int IdLockTextBox[NBRE_INTERFACE];						// Verrou pour accès à la Text Box (IHM) de chaque Slot
int	IdLockUnigraph;
// Variables Globales Log infos TRaca SAP ME
// ----------------------------------------- 
int  gFlagLogSAPME = TRUE; 									// Flag pour savoir si on Log les infos SAP ME ou non..
int  gFlagTelnetDect; 

int gnPresenceCartePicIr = 0;                                                                                                                            // 0 Absent 1 Présent  


int iQuit ; 
char gChNomProduit[TAILLE_MIN]="";
char message_TXT_info[TAILLE_MAX]="";
char Code_Erreur[TAILLE_MAX]="";
int Temps_Test_intermediaire;
char msg_erreur_persiste[TAILLE_MAX]="";

int Handlescript;
