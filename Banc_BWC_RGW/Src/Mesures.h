// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//  
// 
// ==============================================================================
//   PROJET			: Banc Personnalisation
//   MODULE			: Variables
//   PROCESSEUR		: INTEL Pentium
//   ENVIRONNEMENT	: Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION	: Gestion des mesures du décodeur.
//            		  
// ==============================================================================
//   REMARQUES		:
// ==============================================================================
//   MODIFICATIONS	:   
//
// Version Rev X
// Date / Author
//
// V 1.4.0 
// 12-Octobre-2009	NCR (DT2E)
//		>>>	 Création
// ==============================================================================
#ifndef __MESURES_H__
#define __MESURES_H__


// ==============================================================================
// DECLARATION DES CONSTANTES
// ==============================================================================

#define MES_NOM_TAILLE_MAX		100				// Taille max du champ nom en octets
#define MES_DESC_TAILLE_MAX		128				// Taille max du champ description en octets
#define MES_UNITE_TAILLE_MAX	100				// Taille max du champ unité en octets
#define MES_STATUS_TAILLE_MAX	100				// Taille max du champ status
#define MES_STR_PARAM_BLANK		"                                          "
#define MES_STR_TRUE			"true"
#define MES_STR_FALSE			"false"
#define MES_NON_DEFINIE			10 






#define  MESURE_NOM 	     256 
#define MESURE_VALEUR 			  100 

#define MESURE_UNITE 		 8 
#define MESURE_VAL_MAX 			  16
#define MESURE_VAL_MIN			   16



#define MESURE_GAME     16   
					   
#define MESURE_C  		16




#define FILENAMEPYTHON "resultfinallog.txt"
#define FILEPATHLOG "c://logbwc"


#define MAX_FILE_DATA_LENGTH 1024









	
// Définition des status des mesures
// ---------------------------------
#define MES_STATUS_OK			"0"			// Status de mesure : resultat valide
#define MES_STATUS_KO			"1"			// Status de mesure : resultat non valide
#define MES_STATUS_NOGO			"2"			// Status de mesure : mesure non faite


// ==============================================================================
// DECLARATION DES STRUCTURES ET ENUMERATIONS
// ==============================================================================

// Définition des types de mesure
// ------------------------------
typedef enum
{
	//MES_TYPE_WIFI_2G,
	MES_TYPE_TEMPS_TEST,
	/*MES_TYPE_ANTENNE1_2G,
	MES_TYPE_ANTENNE2_2G,
	MES_TYPE_ANTENNE3_2G,
	MES_TYPE_ANTENNE0_5G,
	MES_TYPE_ANTENNE1_5G,
	MES_TYPE_ANTENNE2_5G,
	MES_TYPE_ANTENNE3_5G,
	MES_TYPE_ANTENNE4_5G,
	MES_TYPE_ANTENNE5_5G,
	MES_TYPE_ANTENNE6_5G,
	MES_TYPE_ANTENNE7_5G,
	MES_TYPE_ANTENNE0_DECT,
	MES_TYPE_ANTENNE1_DECT,
	MES_TYPE_ANTENNE0_BT,
	
	MES_TYPE_TEST_LED_1,
	MES_TYPE_TEST_LED_2,
	MES_TYPE_TEST_LED_3,
	MES_TYPE_TEST_LED_4,
	MES_TYPE_TEST_LED_5,*/
	
}T_MES_TYPE;

// Définition des accès aux types de mesure
// ----------------------------------------
typedef struct
{
	T_MES_TYPE	type;										// Type de la mesure
	char 		nom[MES_NOM_TAILLE_MAX];					// Nom de la mesure
	char 		libelle[MES_DESC_TAILLE_MAX];				// Description de la mesure
	float		limiteInferieure;							// Valeur de la limite inférieure de la mesure
	float		limiteSuperieure;							// Valeur de la limite supérieure de la mesure
	char		unite[MES_UNITE_TAILLE_MAX];				// Unité de la mesure
	int			avecMesure;									// Indique si mesure doit être réalisée (0 = sans mesure, 1 = avec mesure)
	char 		status[MES_STATUS_TAILLE_MAX];				// Status de la mesure
	int		    duree;										// Durée de la mesure
	float		mesure;										// Valeur de la mesure
	__int64		id;											// Identifiant de la mesure
		
}T_MESURE;
typedef struct
{
	char 		type[MES_NOM_TAILLE_MAX] ;										// Type de la mesure
	char 		nom[MES_NOM_TAILLE_MAX];					// Nom de la mesure
	char 		libelle[MES_DESC_TAILLE_MAX];				// Description de la mesure
	float		limiteInferieure;							// Valeur de la limite inférieure de la mesure
	float		limiteSuperieure;							// Valeur de la limite supérieure de la mesure
	char		unite[MES_UNITE_TAILLE_MAX];				// Unité de la mesure
	int			avecMesure;									// Indique si mesure doit être réalisée (0 = sans mesure, 1 = avec mesure)
	char 		status[MES_STATUS_TAILLE_MAX];				// Status de la mesure
	int		    duree;										// Durée de la mesure
	float		mesure;										// Valeur de la mesure
	__int64		id;											// Identifiant de la mesure
}T_MESURE1;


// Définition des accès aux types de mesure
// ----------------------------------------
typedef struct
{
	T_MESURE 	*mesures;									// Tableau des mesures pour le produit
	int 		nbMesure;									// Nombre de mesures
	int 		nItfe;										// Index de l'interface
	int			idPort;										// Identifiant du port de communication STB
	hdleSCProd  instSCProduction;                               // Handle de la base TracaCom
	char 		codeProduit[MES_NOM_TAILLE_MAX];			// Code produit
	char 		indiceProduit[MES_NOM_TAILLE_MAX];			// Indice produit
	char 		nomPoste[MES_NOM_TAILLE_MAX];				// Nom poste
	
}T_MESURES;

typedef struct
{
	T_MESURE1 	*mesures;									// Tableau des mesures pour le produit
	int 		nbMesure;									// Nombre de mesures
	int 		nItfe;										// Index de l'interface
	int			idPort;										// Identifiant du port de communication STB
	hdleSCProd  instSCProduction;                               // Handle de la base TracaCom
	char 		codeProduit[MES_NOM_TAILLE_MAX];			// Code produit
	char 		indiceProduit[MES_NOM_TAILLE_MAX];			// Indice produit
	char 		nomPoste[MES_NOM_TAILLE_MAX];				// Nom poste
}T_MESURES1;


// ==============================================================================
// DECLARATION DES VARIABLES GLOBALES
// ==============================================================================

// Définition des variables de configuration pour le banc Disques Durs
extern T_MESURE gMesuresBNFT[];

// Nombre de variable dans le tableau
extern const int gNbMesuresHdd;


// ==============================================================================
// DECLARATION DES PROTOTYPES
// ==============================================================================
extern int MES_Get			( T_MESURES *tTabMesure, hdleSCProd instSCProductio, char *codeProduit, char *indiceProduit, char *nomPoste, int nItfe, int idPort, char *strErreurMessage );
extern int MES_Delete		( T_MESURES *tTabMesure );
extern int MES_Reset		( T_MESURES *tTabMesure );
extern int MES_Index		( T_MESURES *tTabMesure, T_MES_TYPE type );
extern int MES_GetName      ( T_MES_TYPE type, char *chName );
extern int MES_Capturer ( T_MESURES *tTabMesure, T_MES_TYPE type, char *status, float valeur, int duree );
extern int MES_Enregistrer	( T_MESURES *tTabMesure, __int64 idMvtTest, char *strMessageErreur );
extern int MES_PrintTab		( T_MESURES *tMesures, char *strPrint );
extern int MES_Print		( T_MESURE *tMesure, char *strPrint );
extern int MES_EnregistrerTableau 	( T_MESURES *tTabMesure, int nItfe, char *strMessageErreur );
extern int MES_EnregistrerTableauV2 (T_MESURES1 *tTabMesure, int nItfe,FILE* fichier, char *strMessageErreur ) ;
extern int MES_EnregistrerTableauV3 (T_MESURES1 *tTabMesure, int nItfe,FILE* fichier, char *strMessageErreur ) ;





extern int MES_EnregistrerTableauV2Log (T_MESURES *tTabMesure,const char *filename,  int nItfe,FILE* fichier, char *strMessageErreur ) ;

extern int MES_EnregistrerTableauV3Log (T_MESURES *tTabMesure, int nItfe,FILE* fichier, char *strMessageErreur ) ;


#endif	// #ifndef __MESURES_H__
