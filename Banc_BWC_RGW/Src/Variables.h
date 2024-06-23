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
//   DESCRIPTION	: Gestion des variables de configuration du décodeur.
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
#ifndef __VARIABLES_H__
#define __VARIABLES_H__


// ==============================================================================
// DECLARATION DES CONSTANTES
// ==============================================================================

#define VAR_NOM_TAILLE_MAX		100				// Taille max du champ nom en octets
#define VAR_DESC_TAILLE_MAX		128				// Taille max du champ description en octets
#define VAR_STRING_TAILLE_MAX	1000				// Taille max du champ valeur de type STRING en octets
#define VAR_NB_PARENT_MAX		3				// Nombre max de variable parent pour une variable
#define VAR_STR_PARAM_BLANK		"                                          "
#define VAR_TAB_SEPARATOR		"|" 			// Chaine de séparation pour les tableaux de valeurs
#define VAR_PASS_OR_SEPARATOR   "+"             // Chaine de séparation pour les Pass en OU     

// Définition des types de variables
// ---------------------------------
#define VAR_BOOL				char			// Type de variable : Booléen
#define VAR_STRING				char*			// Type de variable : Chaine de caratère
#define VAR_SINT8				char			// Type de variable : entier signé 8bits
#define VAR_UINT8				unsigned char	// Type de variable : entier non signé 8bits
#define VAR_SINT16				short			// Type de variable : entier signé 16bits
#define VAR_UINT16				unsigned short	// Type de variable : entier non signé 16bits
#define VAR_SINT32				int				// Type de variable : entier signé 32bits
#define VAR_UINT32				unsigned int	// Type de variable : entier non signé 32bits
#define VAR_FLOAT				float			// Type de variable : nombre à virgule

#define VAR_BOOL_DEFAULT_VAL	FALSE			// Valeur par défaut pour le type : Booléen
#define VAR_STRING_DEFAULT_VAL	""				// Valeur par défaut pour le type : Chaine de caratère
#define VAR_SINT8_DEFAULT_VAL	-1				// Valeur par défaut pour le type : entier signé 8bits
#define VAR_UINT8_DEFAULT_VAL	0				// Valeur par défaut pour le type : entier non signé 8bits
#define VAR_SINT16_DEFAULT_VAL	-1				// Valeur par défaut pour le type : entier signé 16bits
#define VAR_UINT16_DEFAULT_VAL	0				// Valeur par défaut pour le type : entier non signé 16bits
#define VAR_SINT32_DEFAULT_VAL	-1				// Valeur par défaut pour le type : entier signé 32bits
#define VAR_UINT32_DEFAULT_VAL	0				// Valeur par défaut pour le type : entier non signé 32bits
#define VAR_FLOAT_DEFAULT_VAL	0.0				// Valeur par défaut pour le type : nombre à virgule

#define PROP_CIE_NON_DEFINIE	20
#define TAILLE_CHIPSET_SN		16

// -------------------------------------------------------------------------------------
// Définition des accès aux types de variables
// -------------------------------------------------------------------------------------
//  v : Tableau de variable
//  x : Index de la variable dans le Tableau
//  i : Index de la valeur si la variable est un tableau de valeur
// -------------------------------------------------------------------------------------
//  Exemples :
//
//   'conf_Loader' = "LG9DTR03"
//   VAR_GET_STRING(gVariablesConf,VAR_ID_LOADER,0) retourne "LG9DTR03" 			
//
//   'conf_MasqueSnCie' = "'2'##'26'########0|'22'#'24'########0|'28'#'26'########0"
//   VAR_GET_STRING(gVariablesConf,VAR_ID_MASQUE_SN_CIE,0) retourne "'2'##'26'########0"
//   VAR_GET_STRING(gVariablesConf,VAR_ID_MASQUE_SN_CIE,1) retourne "'22'#'24'########0" 
//   VAR_GET_STRING(gVariablesConf,VAR_ID_MASQUE_SN_CIE,2) retourne "'28'#'26'########0" 
//
// -------------------------------------------------------------------------------------
#define VAR_GET_BOOL(v,x,i)     ( (v)->variables[(x)].valeur == NULL ? (VAR_BOOL_DEFAULT_VAL)   : ( (VAR_BOOL)      ( (VAR_BOOL*)   ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_GET_STRING(v,x,i)   ( (v)->variables[(x)].valeur == NULL ? (VAR_STRING_DEFAULT_VAL) : ( (VAR_STRING)    ( (VAR_STRING*) ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_GET_SINT8(v,x,i)    ( (v)->variables[(x)].valeur == NULL ? (VAR_SINT8_DEFAULT_VAL)  : ( (VAR_SINT8)     ( (VAR_SINT8*)  ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_GET_UINT8(v,x,i)    ( (v)->variables[(x)].valeur == NULL ? (VAR_UINT8_DEFAULT_VAL)  : ( (VAR_UINT8)     ( (VAR_UINT8*)  ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_GET_SINT16(v,x,i)   ( (v)->variables[(x)].valeur == NULL ? (VAR_SINT16_DEFAULT_VAL) : ( (VAR_SINT16)    ( (VAR_SINT16*) ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_GET_UINT16(v,x,i)   ( (v)->variables[(x)].valeur == NULL ? (VAR_UINT16_DEFAULT_VAL) : ( (VAR_UINT16)    ( (VAR_UINT16*) ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_GET_SINT32(v,x,i)   ( (v)->variables[(x)].valeur == NULL ? (VAR_SINT32_DEFAULT_VAL) : ( (VAR_SINT32)    ( (VAR_SINT32*) ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_GET_UINT32(v,x,i)   ( (v)->variables[(x)].valeur == NULL ? (VAR_UINT32_DEFAULT_VAL) : ( (VAR_UINT32)    ( (VAR_UINT32*) ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_GET_FLOAT(v,x,i)    ( (v)->variables[(x)].valeur == NULL ? (VAR_FLOAT_DEFAULT_VAL)  : ( (VAR_FLOAT)     ( (VAR_FLOAT*)  ( (v)->variables[(x)].valeur) )[i] )    )

#define VAR_SET_BOOL(v,x,i)     ( ( /*(VAR_BOOL)*/      ( (VAR_BOOL*)   ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_SET_STRING(v,x,i)   ( ( /*(VAR_STRING)*/    ( (VAR_STRING*) ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_SET_SINT8(v,x,i)    ( ( /*(VAR_SINT8)*/     ( (VAR_SINT8*)  ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_SET_UINT8(v,x,i)    ( ( /*(VAR_UINT8)*/     ( (VAR_UINT8*)  ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_SET_SINT16(v,x,i)   ( ( /*(VAR_SINT16)*/    ( (VAR_SINT16*) ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_SET_UINT16(v,x,i)   ( ( /*(VAR_UINT16)*/    ( (VAR_UINT16*) ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_SET_SINT32(v,x,i)   ( ( /*(VAR_SINT32)*/    ( (VAR_SINT32*) ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_SET_UINT32(v,x,i)   ( ( /*(VAR_UINT32)*/    ( (VAR_UINT32*) ( (v)->variables[(x)].valeur) )[i] )    )
#define VAR_SET_FLOAT(v,x,i)    ( ( /*(VAR_FLOAT)*/     ( (VAR_FLOAT*)  ( (v)->variables[(x)].valeur) )[i] )    )





// Définition de la variable en base ?
// -----------------------------------
#define VAR_DEFINED(v,x)		( (v)->variables[(x)].valeur == NULL ? FALSE : TRUE )

// Nombre de valeur de la variable
// -------------------------------
#define VAR_NB_VAL(v,x)			( (v)->variables[(x)].nbValeur )

// Nom de la variable
// ------------------
#define VAR_NAME(v,x)           ( (v)->variables[(x)].nom )
// Définition des actions sur les remontées de variables
// -----------------------------------------------------
#define VAR_SAPME_STOCK					0				// Ajout un stock du composant (pour variables uniques)
#define VAR_SAPME_ASSEMBLE				1				// Assemblage du composant (pour variables uniques)
#define VAR_SAPME_COLLECT				2 				// Enregistrment des variables non uniques (CollectSFCData)


// ==============================================================================
// DECLARATION DES STRUCTURES ET ENUMERATIONS
// ==============================================================================

// Définition des types de variables
// ---------------------------------
typedef enum
{
	VAR_TBOOL,									// Type de variable : Booléen
	VAR_TSTRING,								// Type de variable : Chaine de caratère
	VAR_TSINT8,									// Type de variable : entier signé 8bits
	VAR_TUINT8,									// Type de variable : entier non signé 8bits
	VAR_TSINT16,								// Type de variable : entier signé 16bits
	VAR_TUINT16,								// Type de variable : entier non signé 16bits
	VAR_TSINT32,								// Type de variable : entier signé 32bits
	VAR_TUINT32,								// Type de variable : entier non signé 32bits
	VAR_TFLOAT,									// Type de variable : nombre à virgule
} T_VAR_TYPE;

// Définition des index des variables de configuration
// ---------------------------------------------------
typedef enum
{
	VAR_CONF_GTW_BWC_login,			 	
	
	VAR_CONF_GTW_BWC_FLAG_Eth,
	
	VAR_CONF_GTW_BWC_FLAG_LOGIN,
	
	VAR_CONF_GTW_BWC_Version,
	
	VAR_CONF_GTW_BWC_FLAG_DFA_MERE,
	
	VAR_CONF_GTW_BWC_Lecture_DFA_MERE,    
	
	VAR_CONF_GTW_BWC_Nombre_Char_DFA_MERE,
	
	VAR_CONF_GTW_BWC_TAG_DFA_MERE,  
	
	VAR_CONF_GTW_BWC_Nom_Produit,
	
	VAR_CONF_DEC_BWC_PROMPT_DUT,

	VAR_CONF_DEC_BWC_CMD_LECTURE_SN,

	VAR_CONF_DEC_BWC_CMD_LECTURE_VERSION,
	
	VAR_CONF_DEC_BWC_CMD_INITIALISATION,
	
	VAR_CONF_DEC_BWC_CMD_FINALISATION,
	
	VAR_CONF_DEC_BWC_CMD_RECUP_SN,
	
	VAR_CONF_DEC_BWC_CMD_RECUP_TT,
	
	VAR_CONF_DEC_BWC_CMD_Interface_Eth_DUT,
	
	VAR_CONF_DEC_BWC_CMD_Interface_IP_DUT,
	
	VAR_CONF_DEC_BWC_CMD_Check_Driver_2Ghz,
	
	VAR_CONF_DEC_BWC_CMD_Check_Driver_5Ghz,
	
	VAR_CONF_DEC_BWC_CMD_Check_Driver_6Ghz,
	
	VAR_CONF_DEC_BWC_CMD_Check_Driver_BT,
	
	VAR_CONF_DEC_BWC_CMD_Update_Driver_2Ghz,
	
	VAR_CONF_DEC_BWC_CMD_Update_Driver_5Ghz,
	
	VAR_CONF_DEC_BWC_CMD_Update_Driver_6Ghz,
	
	VAR_CONF_DEC_BWC_CMD_Update_Driver_BT,
	
	VAR_CONF_DEC_BWC_CMD_Check_Update_Driver_2Ghz ,
	
	VAR_CONF_DEC_BWC_CMD_Check_Update_Driver_5Ghz ,
	
	VAR_CONF_DEC_BWC_CMD_Check_Update_Driver_6Ghz ,
	
	VAR_CONF_DEC_BWC_CMD_Check_Update_Driver_BT ,
	
	VAR_CONF_DEC_BWC_CMD_ChipID,
	
	VAR_CONF_GTW_BWC_CMD_TEST_2Ghz,
	
	VAR_CONF_GTW_BWC_CMD_TEST_5Ghz,
	
	VAR_CONF_DEC_BWC_CMD_EXIT_2Ghz,
	
	VAR_CONF_GTW_BWC_CMD_TEST_BT,
	
	VAR_CONF_GTW_BWC_PATH_SCRIPT_2GHZ,
	
	VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,
	
	VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,
	
	VAR_CONF_GTW_BWC_PATH_SCRIPT_BT,
	
	VAR_CONF_DEC_BWC_CMD_PING_DUT,
	
	VAR_CONF_GTW_BWC_CMD_TEST_6Ghz,
	
    VAR_CONF_DEC_BWC_FLAG_Initialisation,	

	VAR_CONF_DEC_BWC_FLAG_Finalisation,
	
	VAR_CONF_DEC_BWC_FLAG_Update_Driver_2Ghz,
	
	VAR_CONF_DEC_BWC_FLAG_Update_Driver_5Ghz,
	
	VAR_CONF_DEC_BWC_FLAG_Update_Driver_6Ghz,
	
	VAR_CONF_DEC_BWC_FLAG_Update_Driver_BT,
	
	VAR_CONF_DEC_BWC_FLAG_ChipID,
	
	VAR_CONF_GTW_BWC_Flag_test_2Ghz,
	
	VAR_CONF_DEC_BWC_FLAG_PING,
	
	VAR_CONF_GTW_BWC_Flag_test_5Ghz ,
	
	VAR_CONF_GTW_BWC_FLAG_TEST_BT,
	
	VAR_CONF_DEC_BWC_FLAG_EXIT_2Ghz,
	
	VAR_CONF_GTW_BWC_Flag_test_6Ghz ,
	
	VAR_CONF_DEC_BWC_FLAG_TEST_check_driver_BT,
	
	VAR_CONF_DEC_BWC_FLAG_Check_Driver_5Ghz,
	
	VAR_CONF_DEC_BWC_FLAG_Check_Driver_2Ghz,
	
	VAR_CONF_DEC_BWC_Test_tampon,
	
	VAR_CONF_GTW_BWC_FLAG_sfc ,
	
	VAR_CONF_GTW_BWC_Gravage_DFA ,
	
	VAR_CONF_GTW_BWC_CMD_Activation_DHCP,
	
	VAR_CONF_GTW_BWC_CMD_Desactivation_DHCP,
	
	VAR_CONF_GTW_BWC_CMD_Rmonte_SFTP,
	
	VAR_CONF_GTW_BWC_FLAG_DHCP,
	
	VAR_CONF_GTW_BWC_FLAG_REMONTE_SFTP,
	

} T_VAR_CONF_INDEX;


// Définition des index des variables de configuration spécifiques à un POSTE
// ---------------------------------------------------------------------------
typedef enum
{
	
	VAR_POSTE_DEC_BNFT_Offset_Antennes_2G_S0,
	
	VAR_POSTE_DEC_BNFT_Offset_Antennes_5G_S0,
	
    VAR_POSTE_DEC_BNFT_Offset_Antennes_BT_S0,	
	
	
	
	VAR_CONF_POSTE_ID_OFFSET_2G_S0,
	                               
	VAR_CONF_POSTE_ID_OFFSET_2G_S1,
									
	VAR_CONF_POSTE_ID_OFFSET_5G_S0,
	                               
	VAR_CONF_POSTE_ID_OFFSET_5G_S1,
	
	VAR_CONF_POSTE_ID_OFFSET_DECT_S0,
	                               
	VAR_CONF_POSTE_ID_OFFSET_DECT_S1,
	

 
} T_VAR_CONF_POSTE_INDEX;



// Définition des index des variables de configuration spécifiques à un SN
// -----------------------------------------------------------------------
typedef enum
{
	VAR_CONF_ID_REFERENCE,
} T_VAR_CONF_SN_INDEX;

// Définition des index des variables d'état
// -----------------------------------------
typedef enum
{
	VAR_ETAT_ID_NUM_CENTRE,
	/*VAR_ETAT_ID_HDD_MODEL,
	VAR_ETAT_ID_HDD_HVN,
	VAR_ETAT_ID_HDD_SIZE,
	VAR_ETAT_ID_FIRMWARE,
    VAR_ETAT_ID_CLIENT_SN,
	VAR_ETAT_ID_CODE_CONSTRUCTEUR,
	VAR_ETAT_ID_HIBUS_SERIAL,
	VAR_ETAT_ID_HDD_SERIAL,
	VAR_ETAT_ID_HIBUS_FWVERSION  */
} T_VAR_ETAT_INDEX;

// Définition des accès aux types de variables
// -------------------------------------------
/*typedef struct
{
    int     index;                              // Index de la variable
    char    nom[VAR_NOM_TAILLE_MAX];            // Nom de la variable
    char    description[VAR_DESC_TAILLE_MAX];   // Description de la variable
    int     type;                               // Type de la variable
    int     optionnelle;                        // Indique si la valeur de la variables est optionnelle (0=>Définition de la variable obligatoire, 1=>Définition de la variable optionnelle)
    int     parent[VAR_NB_PARENT_MAX];          // Index de la propriété parente (-1 si aucune)
    void    *valeur;                            // Valeur de la variable
    int     nbValeur;                           // Nombre de valeur définis pour la variable (pour les tableaux)
    __int64 id;                                 // Identifiant de la variable
    int     unique;                        		// Indique si la valeur de la variables est unique (0=>Non unique, 1=>Unique)
} T_VARIABLE;
 */


// Définition de la structure variable
// -----------------------------------
typedef struct
{
    int     index;                              // Index de la variable
    char    nom[VAR_NOM_TAILLE_MAX];            // Nom de la variable
    char    nomtest[VAR_NOM_TAILLE_MAX];   		// Nom du test
	char    description[VAR_DESC_TAILLE_MAX];   // Description de la variable
	char    chValeur[VAR_STRING_TAILLE_MAX];   	// Valeur de la variable
    int     type;                               // Type de la variable
    int     optionnelle;                        // Indique si la valeur de la variables est optionnelle (0=>Définition de la variable obligatoire, 1=>Définition de la variable optionnelle)
    int     parent[VAR_NB_PARENT_MAX];          // Index de la propriété parente (-1 si aucune)
    void    *valeur;                            // Valeur de la variable
    int     nbValeur;                           // Nombre de valeur définis pour la variable (pour les tableaux)
    __int64 id;                                 // Identifiant de la variable
    int     unique;                        		// Indique si la valeur de la variables est unique (0=>Non unique, 1=>Unique)
}T_VARIABLE;




// Définition d'un tableau de variables
// ------------------------------------
typedef struct
{
	T_VARIABLE	*variables;						// Tableau de variables pour le produit
	int 		nbVariables;					// Nombre de variables pour le produit
} T_VARIABLES;


// ==============================================================================
// DECLARATION DES VARIABLES GLOBALES
// ==============================================================================

// Définition des variables de configuration pour le banc Perso
// ------------------------------------------------------------
extern T_VARIABLE gVariablesConf[];
// Nombre de variable de configuration
// -----------------------------------
extern const int gNbVariablesConf;
// Définition des variables de configuration pour le banc Perso
// ------------------------------------------------------------
extern T_VARIABLE gVariablesConfPoste[];
// Nombre de variable de configuration
// -----------------------------------
extern const int gNbVariablesConfPoste;


// Définition des variables d'état pour le banc Perso
// --------------------------------------------------
extern T_VARIABLE gVariablesEtat[];
// Nombre de variable d'état
// -------------------------
extern const int gNbVariablesEtat;

// Définition des variables de configuration pour le banc Perso liées à un SN
// --------------------------------------------------------------------------
extern T_VARIABLE gVariablesConfSn[];
// Nombre de variable de configuration liées à un SN
// -------------------------------------------------
extern const int gNbVariablesConfSn;


// ==============================================================================
// DECLARATION DES PROTOTYPES
// ==============================================================================

extern int VAR_Get		( T_VARIABLE *tVariablesModele, int nbVariablesModele, T_VARIABLES *tVariables, hdleSCProd 	instSCProduction, char *numSerie, char *codeProduit, char *indiceProduit, char *nomPoste, char *strErreurMessage );
extern int VAR_Set		( T_VARIABLES *tVariables, hdleSCProd 	instSCProduction, char *codeProduit, char *indiceProduit, char *numSerie, char *strErreurMessage );
extern int VAR_Raz		( T_VARIABLES *tVariables );
extern int VAR_Delete	( T_VARIABLES *tVariables );
extern int VAR_Print	( T_VARIABLES *tVariables, char *strPrint, char *strErreurMessage );
extern int VAR_SetString ( T_VARIABLES *tVariables, int idxVariable, char *valeur );
extern int VAR_GetString ( T_VARIABLES *tVariables, int index, char *valeur );
extern int VAR_GestionTableau ( int nItfe, T_TCOM_BASE *tcomBase, T_VARIABLES *tVariables, char *numSerie, char *Ressource, char *Operation, int iAction, char *strErreurMessage);


// Définition des variables de configuration pour le banc Perso liées à un SN
// --------------------------------------------------------------------------
extern T_VARIABLE gVariablesProprietesSFCCie[];
extern T_VARIABLE gVariablesProprietesSFCPfin[]; 

#endif	// #ifndef __VARIABLES_H__
