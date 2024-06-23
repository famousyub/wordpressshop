// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//  
// 
// ==============================================================================
//   PROJET         : Banc Personnalisation
//   MODULE         : Cles
//   PROCESSEUR     : INTEL Pentium
//   ENVIRONNEMENT  : Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION    : Gestion des clés du décodeur.
//                    
// ==============================================================================
//   REMARQUES      :
// ==============================================================================
//   MODIFICATIONS  :   
//
// Version Rev X
// Date / Author
//
// V 1.4.0 
// 14-Octobre-2009  NCR (DT2E)
//      >>>  Création
// ==============================================================================
#ifndef __CLES_H__
#define __CLES_H__


// ==============================================================================
// DECLARATION DES CONSTANTES
// ==============================================================================

// Commandes TT
// ------------
#define CMD_TT_FLA_W_CSCD_NAGRA_KEYS                "FLA_W_CSCD_NAGRA_KEYS"
#define CMD_TT_OPTION_CSCD_NON_CRYPTE               "#00"
//#define CMD_TT_OPTION_CSCD_CRYPTE                   "#01"
#define CMD_TT_NAGRA_CSCD_POC_START                 "NAGRA_CSCD_POC_START"
#define CMD_TT_NAGRA_CSCD_POC_STOP                  "NAGRA_CSCD_POC_STOP"
#define CMD_TT_FLA_W_NDS                            "FLA_W_KDG_PDB" 
#define CMD_TT_FLA_W_PK_NAGRA_KEYS                  "FLA_W_PK_NAGRA_KEYS"
#define CMD_TT_FLA_W_PDB                    		"FLA_W_PDB" 
#define CMD_TT_WMDRMV10_WRITE_CERT          		"[WMDRMV10_WRITE_CERT{Pass:OK}{Fail:ERROR}]"
#define CMD_TT_FLA_W_NDS                    		"FLA_W_KDG_PDB" 
#define CMD_TT_FLA_W_UNIQUE_PWD						"FLA_W_UNIQUE_PWD"
#define CMD_TT_FLA_WRITE_SFR_PDB					"FLA_WRITE_SFR_PDB"
#define CMD_TT_FLA_W_COMMON_RESCU_KEY          		"[FLA_W_COMMON_RESCU_KEY{Pass:OK}{Fail:ERROR}]"
#define CMD_TT_FLA_W_UNIQUE_SCRAMB_HDD				"FLA_W_UNIQUE_SCRAMB_HDD_KEY"   													 //FLA_W_Unique_SCRAMB_HDD_KEY #octet_1 .. #octet_32
#define CMD_TT_FLA_W_UNIQUE_RESCUE_KEY				"FLA_W_UNIQUE_RESCU_KEY"   															 //FLA_W_Unique_RESCU_KEY #octet_1 .. #octet_32
#define CMD_TT_FLA_W_RESCUE_KEYS					"[FLA_W_RESCUE_KEYS{Pass:OK}{Fail:ERROR}{Key 0: %}{Key 1: %}{Key 2: %}{Key 3: %}]"   //FLA_W_Unique_RESCU_KEY 



//#define CMD_TT_FLA_W_PDB                          "FLA_W_PDB_FT" 
//#define CMD_TT_ETH_INIT                           "ETH_INIT\n"
//#define CMD_TT_ETH_OPEN                           "ETH_OPEN 0 0 100\n"
//#define CMD_TT_ETH_CLOSE                          "ETH_CLOSE\n"

//Taille Clés
// ----------
#define CLE_TIME_OUT_CMD_TT                         10                          // Time out (s) pour une commande TT

#define CLE_NB_MAX                                  32                          // Taille max du champ description en octets

#define CLE_NOM_TAILLE_MAX                          32                          // Taille max du champ nom en octets
#define CLE_DESC_TAILLE_MAX                         128                         // Taille max du champ description en octets
#define CLE_PARAM_TAILLE_MAX                        128                         // Taille max d'un paramètres de lecture de clé
#define CLE_PRINT_TAILLE_MAX                        PRINT_INFO_TAILLE_MAX       // Taille max pour la chaine d'affichage de clé
#define CLE_PRINT_VAL_TAILLE_MAX                    (PRINT_INFO_TAILLE_MAX-256) // Taille max pour la chaine d'affichage des valeurs de la clé

#define CLE_TAILLE_HDCP                             324
#define CLE_TAILLE_HDCP_NUM_LIVR                    2
#define CLE_TAILLE_HDCP_NUM_LOT                     2
#define CLE_TAILLE_HDCP_INDEX_LOT                   4
#define CLE_TAILLE_HDCP_INDEX_SOURCE                4
#define CLE_TAILLE_HDCP_CHIP_SET                    4
#define CLE_TAILLE_HDCP_KSV                         8
#define CLE_TAILLE_HDCP_KEYS                        280
#define CLE_TAILLE_HDCP_SHA                         20

#define CLE_TAILLE_PAIRING_KEY                      536
#define CLE_TAILLE_PAIRING_KEY_LENGTH               4
#define CLE_TAILLE_PAIRING_KEY_CAS_ID               4
#define CLE_TAILLE_PAIRING_KEY_PAIRING_KEY_INFO     356 
#define CLE_TAILLE_PAIRING_KEY_SECURE_SIGNATURE     128
#define CLE_TAILLE_PAIRING_KEY_CRC                  2

#define CLE_TAILLE_PAIRING_HEADER                   32
#define CLE_TAILLE_PAIRING_PADDING                  10

#define CLE_TAILLE_CSCD                             151 // Composition clé CSCD :
                                                        //      - Taille    = 4 octets
                                                        //      - NUID      = 4 octets
                                                        //      - Version   = 2 octets
                                                        //      - Data      = 135 octets
                                                        //      - Controle  = 4 octets
                                                        //      - CRC       = 2 octets

#define CLE_TAILLE_CSCD_DATA                        135 // Taille en octets des données de la clé CSCD (135 octets)

#define CLE_TAILLE_PDB                              128

#define CLE_TAILLE_SFK                              16

#define CLE_STR_INFO_BLANK                          "                                          "
#define CLE_STR_VAL_BLANK                           "\n "
#define CLE_TAILLE_PWD_UNIQUE_STB                   16

// ========================================================
// Définition des index des paramètres pour toutes les clés
// ========================================================

// Clé HDCP
// --------
#define CLE_HDCP_IDX_PARAM_CHIPSET_ID               0


// Définition des index des valeurs pour toutes les clés
// =====================================================

// Index de la valeur de l'ID de la clé (pour toutes les clés)
// -----------------------------------------------------------
#define CLE_IDX_VAL_ID_CLE                          0

// Adresse MAC
// -----------
#define CLE_MAC_IDX_VAL_ID_CLE                      0
#define CLE_MAC_IDX_VAL_ID_NUMSERIE                 1
#define CLE_MAC_IDX_VAL_ADRESSE                     2
#define CLE_MAC_IDX_VAL_UTILISEE                    3
#define CLE_MAC_IDX_VAL_UTILISATEUR                 4
#define CLE_MAC_IDX_VAL_DATE_CREATION               5
#define CLE_MAC_IDX_VAL_DATE_MAJ                    6

// Clé HDCP
// --------
#define CLE_HDCP_IDX_VAL_ID_CLE                     0
#define CLE_HDCP_IDX_VAL_ID_NUM                     1
#define CLE_HDCP_IDX_VAL_ORDER                      2
#define CLE_HDCP_IDX_VAL_NUM_LIVR                   3
#define CLE_HDCP_IDX_VAL_NUM_LOT                    4
#define CLE_HDCP_IDX_VAL_LOT_SIZE                   5
#define CLE_HDCP_IDX_VAL_INDEX_DISPO                6
#define CLE_HDCP_IDX_VAL_INDEX_SOURCE               7
#define CLE_HDCP_IDX_VAL_KEY_SET_INDEX              8
#define CLE_HDCP_IDX_VAL_KSV                        9
#define CLE_HDCP_IDX_VAL_KEYS                       10
#define CLE_HDCP_IDX_VAL_SHA1                       11
#define CLE_HDCP_IDX_VAL_CHIPSET                    12
#define CLE_HDCP_IDX_VAL_UTILISEE                   13
#define CLE_HDCP_IDX_VAL_NOM_FICHIER                14
#define CLE_HDCP_IDX_VAL_UTILISATEUR                15
#define CLE_HDCP_IDX_VAL_DATE_CREATION              16
#define CLE_HDCP_IDX_VAL_DATE_MAJ                   17

// Clé PAIRING
// -----------
#define CLE_PAIRING_IDX_VAL_ID_CLE                	0
#define CLE_PAIRING_IDX_VAL_ID_NUM                	1
#define CLE_PAIRING_IDX_VAL_CAS_ID                	2
#define CLE_PAIRING_IDX_VAL_LENGTH                	3
#define CLE_PAIRING_IDX_VAL_KEY_INFO				4 
#define CLE_PAIRING_IDX_VAL_SECURE_SIGNATURE      	5
#define CLE_PAIRING_IDX_VAL_CRC                  	6
#define CLE_PAIRING_IDX_VAL_NOM_FICHIER           	7
#define CLE_PAIRING_IDX_VAL_UTILISEE              	8
#define CLE_PAIRING_IDX_VAL_UTILISATEUR           	9
#define CLE_PAIRING_IDX_VAL_DATE_CREATION         	10
#define CLE_PAIRING_IDX_VAL_DATE_MAJ              	11
#define CLE_PAIRING_IDX_VAL_CODE_PRODUIT          	12

// Clé STB Password
// ----------------
#define CLE_PASSWORD_IDX_VAL_ID_CLE                 0
#define CLE_PASSWORD_IDX_VAL_ID_NUM                 1
#define CLE_PASSWORD_IDX_VAL_VAL                    2
#define CLE_PASSWORD_IDX_VAL_UTILISEE               3
#define CLE_PASSWORD_IDX_VAL_UTILISATEUR            4
#define CLE_PASSWORD_IDX_VAL_DATE_CREATION          5
#define CLE_PASSWORD_IDX_VAL_DATE_MAJ               6

// Clé/Password HDD
// ----------------
#define CLE_HDD_IDX_VAL_ID_CLE                      0
#define CLE_HDD_IDX_VAL_ID_NUM                      1
#define CLE_HDD_IDX_VAL_CLE_1                       2
#define CLE_HDD_IDX_VAL_CLE_2                       3
#define CLE_HDD_IDX_VAL_CLE_3                       4
#define CLE_HDD_IDX_VAL_PWD                         5
#define CLE_HDD_IDX_VAL_UTILISEE                    6
#define CLE_HDD_IDX_VAL_UTILISATEUR                 7
#define CLE_HDD_IDX_VAL_DATE_CREATION               8
#define CLE_HDD_IDX_VAL_DATE_MAJ                    9

// Clé SFK Password
// ----------------
#define CLE_SFK_PWD_IDX_VAL_ID_CLE                  0
#define CLE_SFK_PWD_IDX_VAL_ID_NUM                  1
#define CLE_SFK_PWD_IDX_VAL_VAL                     2
#define CLE_SFK_PWD_IDX_VAL_UTILISEE                3
#define CLE_SFK_PWD_IDX_VAL_UTILISATEUR             4
#define CLE_SFK_PWD_IDX_VAL_DATE_CREATION           5
#define CLE_SFK_PWD_IDX_VAL_DATE_MAJ                6

// Clé NDS
// -------
#define CLE_NDS_IDX_VAL_ID_CLE                      0
#define CLE_NDS_IDX_VAL_ID_NUM                      1
#define CLE_NDS_IDX_VAL_LENGTH                      2
#define CLE_NDS_IDX_VAL_HEADER_LENGTH               3
#define CLE_NDS_IDX_VAL_PAYLOADID                   4
#define CLE_NDS_IDX_VAL_SRC_START                   5
#define CLE_NDS_IDX_VAL_SRC_LENGTH                  6
#define CLE_NDS_IDX_VAL_ORIGIN_FILE_NAME            7
#define CLE_NDS_IDX_VAL_KEY_IND                     8
#define CLE_NDS_IDX_VAL_PROJECT_IND                 9
#define CLE_NDS_IDX_VAL_FILE_REC_IND                10
#define CLE_NDS_IDX_VAL_VERSION                     11
#define CLE_NDS_IDX_VAL_CRC32                       12
#define CLE_NDS_IDX_VAL_NDS_SN                      13
#define CLE_NDS_IDX_VAL_NDS_DATA                    14
#define CLE_NDS_IDX_VAL_NDS_CRC                     15
#define CLE_NDS_IDX_VAL_PADDING                     16
#define CLE_NDS_IDX_VAL_RESERVED2                   17
#define CLE_NDS_IDX_VAL_SHA                         18
#define CLE_NDS_IDX_VAL_NOM_FICHIER                 19
#define CLE_NDS_IDX_VAL_UTILISEE                    20
#define CLE_NDS_IDX_VAL_UTILISATEUR                 21
#define CLE_NDS_IDX_VAL_DATE_CREATION               22
#define CLE_NDS_IDX_VAL_DATE_MAJ                    23

// Clé PDB
// -------
#define CLE_PDB_IDX_VAL_ID_CLE                      0
#define CLE_PDB_IDX_VAL_ID_NUM                      1
#define CLE_PDB_IDX_VAL_ORIGIN_FILE_NAME            2
#define CLE_PDB_IDX_VAL_KEY_IND                     3
#define CLE_PDB_IDX_VAL_PROJECT_IND                 4
#define CLE_PDB_IDX_VAL_FILE_REC_IND                5
#define CLE_PDB_IDX_VAL_RESERVED1                   6
#define CLE_PDB_IDX_VAL_CRC32                       7
#define CLE_PDB_IDX_VAL_PDB_PUB_ID                  8
#define CLE_PDB_IDX_VAL_PDB_DATA                    9
#define CLE_PDB_IDX_VAL_SHA1_FT                     10
#define CLE_PDB_IDX_VAL_PADDING                     11
#define CLE_PDB_IDX_VAL_SHA1_SAGEM                  12
#define CLE_PDB_IDX_VAL_RESERVED2                   13
#define CLE_PDB_IDX_VAL_NOM_FICHIER                 14
#define CLE_PDB_IDX_VAL_UTILISEE                    15
#define CLE_PDB_IDX_VAL_UTILISATEUR                 16
#define CLE_PDB_IDX_VAL_DATE_CREATION               17
#define CLE_PDB_IDX_VAL_DATE_MAJ                    18

// Clé CSCD
// --------
#define CLE_CSCD_IDX_VAL_ID_CLE                      0
#define CLE_CSCD_IDX_VAL_ID_NUM                      1
#define CLE_CSCD_IDX_VAL_LENGTH                      2
#define CLE_CSCD_IDX_VAL_HEADER_LENGTH               3
#define CLE_CSCD_IDX_VAL_PAYLOADID                   4
#define CLE_CSCD_IDX_VAL_SRC_START                   5
#define CLE_CSCD_IDX_VAL_SRC_LENGTH                  6
#define CLE_CSCD_IDX_VAL_ORIGIN_FILE_NAME            7
#define CLE_CSCD_IDX_VAL_KEY_IND                     8
#define CLE_CSCD_IDX_VAL_PROJECT_IND                 9
#define CLE_CSCD_IDX_VAL_FILE_REC_IND                10
#define CLE_CSCD_IDX_VAL_HEADER_VERSION              11
#define CLE_CSCD_IDX_VAL_CRC32                       12
#define CLE_CSCD_IDX_VAL_REC_LENGTH                  13
#define CLE_CSCD_IDX_VAL_NUID                        14
#define CLE_CSCD_IDX_VAL_VERSION                     15
#define CLE_CSCD_IDX_VAL_PROVID                      16
#define CLE_CSCD_IDX_VAL_SA                          17
#define CLE_CSCD_IDX_VAL_OFF                         18
#define CLE_CSCD_IDX_VAL_TAG                         19
#define CLE_CSCD_IDX_VAL_LEN                         20
#define CLE_CSCD_IDX_VAL_CSCD_DATA                   21
#define CLE_CSCD_IDX_VAL_CSCD_CN                     22
#define CLE_CSCD_IDX_VAL_CSCD_CRC16                  23
#define CLE_CSCD_IDX_VAL_PADDING                     24
#define CLE_CSCD_IDX_VAL_RESERVED2                   25
#define CLE_CSCD_IDX_VAL_SHA                         26
#define CLE_CSCD_IDX_VAL_NOM_FICHIER                 27
#define CLE_CSCD_IDX_VAL_VECTEUR_DATA                28
#define CLE_CSCD_IDX_VAL_VECTEUR_CRC                 29
#define CLE_CSCD_IDX_VAL_UTILISEE                    30
#define CLE_CSCD_IDX_VAL_UTILISATEUR                 31
#define CLE_CSCD_IDX_VAL_DATE_CREATION               32
#define CLE_CSCD_IDX_VAL_DATE_MAJ                    33

// Clé PAIRING CRYPTE V2
// ---------------------
#define CLE_PAIRINGCRP_IDX_VAL_ID_CLE                0
#define CLE_PAIRINGCRP_IDX_VAL_ID_NUM                1
#define CLE_PAIRINGCRP_IDX_VAL_LENGTH                2
#define CLE_PAIRINGCRP_IDX_VAL_HEADER_LENGTH         3
#define CLE_PAIRINGCRP_IDX_VAL_PAYLOADID             4
#define CLE_PAIRINGCRP_IDX_VAL_SRC_START             5
#define CLE_PAIRINGCRP_IDX_VAL_SRC_LENGTH            6
#define CLE_PAIRINGCRP_IDX_VAL_ORIGIN_FILE_NAME      7
#define CLE_PAIRINGCRP_IDX_VAL_KEY_IND               8
#define CLE_PAIRINGCRP_IDX_VAL_PROJECT_IND           9
#define CLE_PAIRINGCRP_IDX_VAL_FILE_REC_IND          10
#define CLE_PAIRINGCRP_IDX_VAL_HEADER_VERSION        11
#define CLE_PAIRINGCRP_IDX_VAL_CRC32                 12
#define CLE_PAIRINGCRP_IDX_VAL_REC_LENGTH            13
#define CLE_PAIRINGCRP_IDX_VAL_CAS_ID                14
#define CLE_PAIRINGCRP_IDX_VAL_DATA                  15
#define CLE_PAIRINGCRP_IDX_VAL_SECURE_SIGNATURE      16
#define CLE_PAIRINGCRP_IDX_VAL_CSCD_CRC16            17 
#define CLE_PAIRINGCRP_IDX_VAL_PADDING               18
#define CLE_PAIRINGCRP_IDX_VAL_RESERVED2             19
#define CLE_PAIRINGCRP_IDX_VAL_SHA                   20
#define CLE_PAIRINGCRP_IDX_VAL_HEADER                21
#define CLE_PAIRINGCRP_IDX_VAL_NOM_FICHIER           22
#define CLE_PAIRINGCRP_IDX_VAL_UTILISEE              23
#define CLE_PAIRINGCRP_IDX_VAL_CODE_PRODUIT          24
#define CLE_PAIRINGCRP_IDX_VAL_UTILISATEUR           25
#define CLE_PAIRINGCRP_IDX_VAL_DATE_CREATION         26
#define CLE_PAIRINGCRP_IDX_VAL_DATE_MAJ              27

// Password Unique Stb
// -----------
#define CLE_PWD_UNIQUE_IDX_VAL_DATA             	2

// Clé PDB SFR
// ---------------------
#define CLE_PDBSFR_IDX_VAL_ID_CLE					0 
#define CLE_PDBSFR_IDX_VAL_ID_NUM					1 
#define CLE_PDBSFR_IDX_VAL_KEY_IND					2 
#define CLE_PDBSFR_IDX_VAL_DATA						3 
#define CLE_PDBSFR_IDX_VAL_ORIGIN_FILE_NAME			4 
#define CLE_PDBSFR_IDX_VAL_UTILISEE 				5 
#define CLE_PDBSFR_IDX_VAL_UTILISATEUR				6 
#define CLE_PDBSFR_IDX_VAL_DATE_CREATION			7 
#define CLE_PDBSFR_IDX_VAL_DATE_MAJ  				8 

// Clé chiffrage Hdd
// -----------------
#define CLE_CHIFFRAGE_HDD_IDX_VAL_DATA          	2

// Clé secrète unique
// ------------------
#define CLE_SECRETE_UNIQUE_IDX_VAL_DATA         	2

// ==============================================================================
// DECLARATION DES STRUCTURES ET ENUMERATIONS
// ==============================================================================

// Définition d'une clé perso
// --------------------------
typedef struct
{
    char    nom[CLE_NOM_TAILLE_MAX];                                // Nom de la clé
    char    nomTable[CLE_NOM_TAILLE_MAX];                           // Nom de la table où chercher la clé
    char    designation[CLE_DESC_TAILLE_MAX];                       // Désignation de la clé
    int     quantite;                                               // Quantité de clé
    char    **parametres;                                           // Définition des paramètres utilisés pour récupérer la clé
    int     nbParametres;                                           // Nombre de paramètres
    char    **valeurs;                                              // Définition des valeurs renvoyé à la lecture de la clé
    int     nbValeurs;                                              // Nombre de valeurs
    __int64 id;                                                     // Identifiant de la clé
   	int     iNagra;                                              	// 0->clé non Nagra 1->clé Nagra
	int     (*Lecture)(void*,int,char*);                            // Fonction de lecture de la clé
    int     (*Ecriture)(void*,int,char*);                           // Fonction d'écriture de la clé
    int     (*Affichage)(void*,int,char*);                          // Fonction d'affichage de la valeur de la clé
    int     (*Valeur)(void*,int,char**);                            // Fonction d'extraction de la valeur de la clé
}T_CLE;

// Définition d'un tableau de clés
// -------------------------------
typedef struct
{
    T_CLE       *cles;                                              // Tableau de clés pour toutes les interfaces
    int         nbCle;                                              // Nombre de clés pour toutes les interfaces
    int         nItfe;                                              // Index de l'interface
    int         idPort;                                             // Identifiant du port de communication STB
    hdleTCom    instTracaCom;                                       // Handle de la base TracaCom
    char        codeProduit[CLE_PARAM_TAILLE_MAX];                  // Code produit
    char        indiceProduit[CLE_PARAM_TAILLE_MAX];                // Indice produit
    char        sn[CLE_PARAM_TAILLE_MAX];                           // Numéro de série
}T_CLES;


// ==============================================================================
// DECLARATION DES VARIABLES GLOBALES
// ==============================================================================

// Définition des clés perso pour le banc Perso
// --------------------------------------------
extern T_CLE gClesPerso[];

// Nombre de clés perso
// --------------------
extern const int gNbClesPerso;


// ==============================================================================
// DECLARATION DES PROTOTYPES
// ==============================================================================

extern int CLE_Get          ( T_CLES *tCles, hdleTCom instTracaCom, char *codeProduit, char *indiceProduit, int nItfe, int idPort, char *strMessageErreur );
extern int CLE_GetIndex     ( T_CLES *tCles, char *chNomCle );
extern int CLE_Valeur       ( T_CLES *tCles, char *chNomCle, char **chValeur );
extern int CLE_Nettoyage    ( T_CLES *tCles, char *chNomCle, char *strMessageErreur );
extern int CLE_Lecture      ( T_CLES *tCles, char *strMessageErreur );
extern int CLE_Ecriture     ( T_CLES *tClesPerso, char *strMessageErreur );
extern int CLE_Liberation   ( T_CLES *tCles, char *strMessageErreur );
extern int CLE_Raz          ( T_CLES *tClesPerso );
extern int CLE_Delete       ( T_CLES *tCles );
extern int CLE_Print        ( T_CLES *tCles, char *strPrint, int nShowVal, char *strMessageErreur );

#endif  // #ifndef __CLES_H__
