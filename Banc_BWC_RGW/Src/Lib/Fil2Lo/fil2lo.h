#ifndef __FIL2LO_H__
#define __FIL2LO_H__

#include <time.h> 



#define NBRE_CAR_FIL2LO			32768		// Taille maxi du fichier LOG : 32 Koctets

#define FICHIER_TAILLE_MAX		2097152		// Taille maxi du fichier LOG debug : 2 Moctets

#define FIL2LO_LIGNE_MAX		1024		// Taille max d'une ligne dans le fichier LOG

#define FIL2LO_CONF_MAX			8192		// Taille max d'un champ config dans le fichier LOG

#define FIL2LO_TRACE_MAX		4096		// Taille max d'un champ config dans le fichier LOG




#define FIL2LO_STR_ETAPE			"===================> %s <==================================================================="
#define FIL2LO_STR_SOUS_ETAPE		"===================> %s \n"
#define FIL2LO_STR_CONF_STB			"######## CONFIGURATION BDT #######################"
#define FIL2LO_STR_TRACE_STB		"######## TRACE STB ###############################"
#define FIL2LO_STR_RES_OK			"############ PASSAGE OK ###########\n"
#define FIL2LO_STR_RES_KO			"############ PASSAGE KO ###########"
#define FIL2LO_STR_PARAM_BLANK		"                                  "
#define FIL2LO_STR_COM_BLANK		"\n                           "
#define FIL2LO_STR_RESULT_BLANK		"\n               "
#define FIL2LO_STR_RX_STB			"[PC > GTW]  "
#define FIL2LO_STR_TX_STB			"[PC < GTW]  "
#define FIL2LO_STR_RX_WATT			"[PC > WATT] "
#define FIL2LO_STR_TX_WATT			"[PC < WATT] "

#define FIL2LO_STR_ETAPE_SIZE	90

#define FIL2LO_PRINT_ETAPE(s, e)		{sprintf ((s), FIL2LO_STR_ETAPE, (e));(s)[FIL2LO_STR_ETAPE_SIZE]='\n';(s)[FIL2LO_STR_ETAPE_SIZE+1]='\0';}

#define FIL2LO_PRINT_SOUS_ETAPE(s, e)	{sprintf ((s), FIL2LO_STR_SOUS_ETAPE, (e));}

#define FIL2LO_COM_GTW_RX		0
#define FIL2LO_COM_GTW_TX		1
#define FIL2LO_COM_WATT_RX		2
#define FIL2LO_COM_WATT_TX		3
#define FIL2LO_COM_GAT_RX		0
#define FIL2LO_COM_GAT_TX		1
#define FIL2LO_COM_WATT_RX		2
#define FIL2LO_COM_WATT_TX		3
#define FIL2LO_COM_FEASA_LEDS_RX	12
#define	FIL2LO_COM_FEASA_LEDS_TX	13
#define FIL2LO_COM_INFORMATION	6  

//********************************************************************
//********************Prototypes**************************************
//********************************************************************

void FIL2LO_EcritTrace (int flagFil2Lo, int itfe, char *trace);
void FIL2LO_EcritTraceV2 (int flagFil2Lo, int itfe, char *trace);
void FIL2LO_Heure (char ch[80+1], char chmilli[80+1]);
void FIL2LO_Date (char ch [80+1]);
void FIL2LO_HeureV2 (char ch[80+1], char chmilli[80+1]);
void FIL2LO_DateV2 (char ch [80+1]);
void FIL2LO_EcrireFichier (char *chNomfichier, char *chaine);
void FIL2LO_PrintDebut (int nItfe);
void FIL2LO_PrintEtape (int nItfe, char *etape);
void FIL2LO_PrintSousEtape (int nItfe, char *etape);
void FIL2LO_PrintTraceStb (int nItfe);
void FIL2LO_PrintCom (int nItfe, int com, char *donnees);
void FIL2LO_PrintResultat (int nItfe, int res, char *msgErr, float dTest);
void FIL2LO_VerifDateChemin (int nItfe); 

#endif	// #ifndef __FIL2LO_H__ 
