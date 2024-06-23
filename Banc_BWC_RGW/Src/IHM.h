// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//  
// 
// ==============================================================================
//   PROJET			: Banc HDD
//   MODULE			: Ihm
//   PROCESSEUR		: INTEL Pentium
//   ENVIRONNEMENT	: Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION	: Définition des fonctions de gestion de l'IHM.
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
#ifndef __IHM_H__
#define __IHM_H__

// ==============================================================================
// DECLARATION DES CONSTANTES
// ==============================================================================

// Taille max de la chaine de retour de la fenêtre promptPopup
// -----------------------------------------------------------
#define PROMPT_REP_TAILLE_MAX			128

// Titre de la fenêtre promptPopup
// -------------------------------
#define PROMPT_TITRE					"Saisie SN STB"

// Message de la fenêtre promptPopup
// ---------------------------------
#define PROMPT_MESSAGE					"Nouveau numéro de série du "

// Type de fenêtre popup
// ---------------------
#define IHM_POPUP_TYPE_INFO				0
#define IHM_POPUP_TYPE_QUESTION			1
#define IHM_POPUP_TYPE_ERREUR			2

// Valeur de retour de la fenêtre popup
// ------------------------------------
#define IHM_POPUP_RETOUR_OK				0
#define IHM_POPUP_RETOUR_OUI			1
#define IHM_POPUP_RETOUR_NON			2

// Mode de gestion d'affichage des messages
// ----------------------------------------
#define IHM_MODE_POPUP_INFO				0x01			// Affichage d'une popup d'information
#define IHM_MODE_POPUP_ERREUR			0x02			// Affichage d'une popup d'erreur
#define IHM_MODE_TRACE_TXTBOX			0x04			// Affichage d'une trace sur l'IHM
#define IHM_MODE_TRACE_LOG				0x08			// Affichage d'une trace dans le fichier LOG

// Type de l'état resultat
// -----------------------
#define IHM_RESULT_OK                   0
#define IHM_RESULT_KO                   1
#define IHM_RESULT_TEST                 2
#define IHM_RESULT_ATTENTE              3

// Gestion de l'impression des étapes et sous-étapes
// -------------------------------------------------
#define IHM_STR_ETAPE                   "==============> %s <======================================================================"
#define IHM_STR_SOUS_ETAPE              "==============> %s\n"
//#define IHM_STR_ERREUR                  ">>ERREUR>> %s\n"
#define IHM_STR_INFO                    "%s"
#define IHM_STR_ETAPE_SIZE              90
#define IHM_PRINT_ETAPE(s, e)           {sprintf ((s), IHM_STR_ETAPE, (e));(s)[IHM_STR_ETAPE_SIZE]='\0';}
#define IHM_PRINT_SOUS_ETAPE(s, e)      {sprintf ((s), IHM_STR_SOUS_ETAPE, (e));}

// Gestion de l'impression des étapes et sous-étapes	  
// -------------------------------------------------
#define IHM_STR_ETAPE                   "==============> %s <======================================================================"
#define IHM_STR_SOUS_ETAPE              "==============> %s\n"
#define IHM_STR_SOUS_ETAPE_TRACA        "--------> Appel Traça  : %s <--------"
#define IHM_STR_INFO_TRACA              "%s"
#define IHM_STR_INFO                    "%s\n"
#define IHM_STR_ETAPE_SIZE              90
#define IHM_PRINT_ETAPE(s, e)           {sprintf ((s), IHM_STR_ETAPE, (e));(s)[IHM_STR_ETAPE_SIZE]='\n';(s)[IHM_STR_ETAPE_SIZE+1]='\0';}
#define IHM_PRINT_SOUS_ETAPE(s, e)      {sprintf ((s), IHM_STR_SOUS_ETAPE, (e));}

// ==============================================================================
// DECLARATION DES VARIABLES GLOBALES
// ==============================================================================
// variables pour charger les panels
extern int PnlProduitId;									// handle de panel choix produit 
extern int PnlPere;											// handle de panel parent contenant les slots
extern int PnlChoixPalette;									// handle de panel choix lot + palette


// ==============================================================================
// DECLARATION DES FONCTIONS
// ==============================================================================

extern int IHM_GestCtrlPnl (int nItfe);
extern int IHM_ChoixPalette (int *nPackageKey);												// Fonction de sélection de la palette pour SN consécutifs
extern int IHM_SlotCreate ( T_SLOT *tSlot, char *strErreurMessage );						// Fonction de création de l'IHM d'un SLOT
extern int IHM_SlotRemove ( int nItfe, char *strErreurMessage );						// Fonction de destruction de l'IHM d'un SLOT
extern int IHM_ShowPopup ( T_IHM_SLOT *tIhmSlot, int type, char *titre, char *message );	// Fonction d'affichage de la panel message Popup
extern int IHM_ShowLot ( T_IHM_SLOT *tIhmSlot, int *lot, int *palette );					// Fonction d'affichage de la panel Lot/Palette
extern int IHM_GetSlotIndexFromPanel ( int panel );											// Fonction de recherche d'un SLOT à partir d'une panel
extern int IHM_DisplayPanelTraca ( T_SLOT *tSlot );											// Fonction d'affichage de la fenêtre traca
extern int IHM_DisplayPanelVariables ( T_SLOT *tSlot );										// Fonction d'affichage de la fenêtre de gestion des variables de configuration
extern int IHM_CentrerObjet ( int panel, int objet1, int objet2, int type);
extern int IHM_ShowSn ( T_IHM_SLOT *tIhmSlot, char *titre);								// Fonction d'affichage de la panel Sn Sfin


extern int ChargeListeProduits (void);
extern void ClasseListeProduits (T_POSTE_PRODUITS *posteProduits, int type);

#endif	// #ifndef __IHM_H__
