// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//  
// 
// ==============================================================================
//   PROJET         : Banc Personnalisation
//   MODULE         : TracaCom
//   PROCESSEUR     : INTEL Pentium
//   ENVIRONNEMENT  : Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION    : Gestion de la base TracaCom.
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
// 13-Octobre-2009  NCR (DT2E)
//      >>>  Création
// ==============================================================================
#ifndef __TRACACOM_H__
#define __TRACACOM_H__


// ==============================================================================
// DECLARATION DES CONSTANTES
// ==============================================================================

#define TCOM_PARAM_TAILLE_MAX                   64          // Taille max en octets des paramètres de la structure T_TCOM_BASE
#define TCOM_PRODUIT_NB_MAX                     64          // Nombre max de produits
#define TCOM_SN_PARAM_TAILLE_MAX                64          // Taille max en octets des paramètres pour la création du Receiver SN

// Nom du banc Perso en base
// -------------------------
#define TCOM_BHD_NOM							"BHD"

// Définiton des types de SN client
// --------------------------------
#define TCOM_SN_CLIENT_ICADD                    "ICADD"
#define TCOM_SN_CLIENT_BYT                      "BYT"
#define TCOM_SN_CLIENT_CHILI                    "CHILI"
#define TCOM_SN_CLIENT_SFR	                    "SFR"


// Code d'autorisation de passage
// ------------------------------
#define TCOM_AUTORISATION_KO_DPNO_RMTP           0          // Code  d'autorisation  0 : Dernier Passage du Numserie Ok, Repasse sur le Meme Type de Poste
#define TCOM_AUTORISATION_KO_PPNMP_APP          -1          // Code  d'autorisation -1 : Premier Passage du Numserie sur le Mauvais Poste. Allez au Premier Poste
#define TCOM_AUTORISATION_KO_DPNK_RMTP_TRO      -2          // Code  d'autorisation -2 : Dernier Passage du Numserie Ko, Repasse sur le Mauvais Type de Poste et Temps de Repasse Ok
#define TCOM_AUTORISATION_KO_DPNO_PNTP          -3          // Code  d'autorisation -3 : Dernier Passage du Numserie Ok, Passage sur le Mauvais Type de Poste
#define TCOM_AUTORISATION_KO_DPNK_RMTP_TRK_APD  -4          // Code  d'autorisation -4 : Dernier Passage du Numserie Ko, Repasse sur le Mauvais Type de Poste et Temps de Repasse Ko. Allez au Poste de Dépannage
#define TCOM_AUTORISATION_KO_DPNK_RETP_TRK_APD  -5          // Code  d'autorisation -5 : Dernier Passage du Numserie Ko, Repasse sur le mEme Type de Poste et Temps de Repasse Ko. Allez au Poste de Dépannage
#define TCOM_AUTORISATION_KO_AUTRE              -6          // Code  d'autorisation -6 : Autre cas ???
#define TCOM_AUTORISATION_OK_PPNPP               1          // Code  d'autorisation  1 : Premier Passage du Numserie sur le Premier Poste
#define TCOM_AUTORISATION_OK_DPNK_RMTP_TRO       2          // Code  d'autorisation  2 : Dernier Passage du Numserie Ko, Repasse sur le Meme Type de Poste et Temps de Repasse Ok
#define TCOM_AUTORISATION_OK_DPNO_PPS            3          // Code  d'autorisation  3 : Dernier Passage du Numserie Ok et Passage sur le Poste Suivant
#define TCOM_AUTORISATION_OK_DPL                 4          // Code  d'autorisation  4 : Dernier Poste de la Ligne
#define TCOM_AUTORISATION_OK_RNPP                5          // Code  d'autorisation  5 : Repassage du Numserie sur le Premier Poste (RESTART_PROCESS)
#define TCOM_AUTORISATION_OK_CR                  6          // Code  d'autorisation  6 : Carte de Référence

// Codes d'erreur
//----------------
#define	TCOM_ERREUR_RESEAU						-5

// ==============================================================================
// DECLARATION DES STRUCTURES ET ENUMERATIONS
// ==============================================================================

// Type instance TracaCom 
// ----------------------
typedef TracaCom_FonctionsMDT_FonctionsMDT hdleTCom;  

// Structure définissant une connexion à la base TracaCom
// ------------------------------------------------------
typedef struct
{
    char        nomServeur[TCOM_PARAM_TAILLE_MAX];          // Nom du serveur
    int         portServeur;                                // Port du serveur
    char        loginServeur[TCOM_PARAM_TAILLE_MAX];        // Login de connexion au serveur
    char        passServeur[TCOM_PARAM_TAILLE_MAX];         // Password de connexion au serveur
    char        nomBase[TCOM_PARAM_TAILLE_MAX];             // Nom de la base de connexion
    hdleTCom    instTracaCom;        // Instance sur la connexion à la base
}T_TCOM_BASE;

/*
// Type instance SCProduction_GestionProductions SAPME
//typedef SCProduction_GestionProductions_ConfigurationBase SCProduction_GestionProductions;
// Structure définissant une connexion à la base TracaCom
// ------------------------------------------------------
typedef struct
{
    char        nomServeur[TCOM_PARAM_TAILLE_MAX];          // Nom du serveur
    int         portServeur;                                // Port du serveur
    char        loginServeur[TCOM_PARAM_TAILLE_MAX];        // Login de connexion au serveur
    char        passServeur[TCOM_PARAM_TAILLE_MAX];         // Password de connexion au serveur
    char        nomBase[TCOM_PARAM_TAILLE_MAX];             // Nom de la base de connexion
    SCProduction_GestionProductions    instTracaCom;        // Instance sur la connexion à la base
}T_TCOM_BASE;
*/
// Définition des informations d'un poste
// --------------------------------------
typedef struct
{
    char        chType[TCOM_PARAM_TAILLE_MAX];              // Type du poste
    char        chNom[TCOM_PARAM_TAILLE_MAX];               // Nom du poste
    __int64     id;                                         // Identifiant du poste
    int         numCentre;                                  // Numéro du centre
    int         numLigne;                                   // Numéro de la ligne
    char        chLibelleLigne[TCOM_PARAM_TAILLE_MAX];      // Nom de la ligne
    char        chDescriptionLigne[TCOM_PARAM_TAILLE_MAX];  // Description de la ligne
    char        idType[TCOM_PARAM_TAILLE_MAX];              // Identifiant du type du poste
    int         idConfNumSerie;                             // Identifiant de la configuration du numéro de série
    char        chMatricule[TCOM_PARAM_TAILLE_MAX];         // Matricule de l'opérateur
}T_POSTE_INFOS;

// Définition d'un niveau de nomenclature
// --------------------------------------
typedef struct
{
    char        chVersion[TCOM_PARAM_TAILLE_MAX];           // Code du produit
    char        chIndice[TCOM_PARAM_TAILLE_MAX];            // Indice du produit
    char        chDesignation[TCOM_PARAM_TAILLE_MAX];       // Désignation du produit
    char        chFamille[TCOM_PARAM_TAILLE_MAX];           // Famille du produit
    char        chSousFamille[TCOM_PARAM_TAILLE_MAX];       // Sous famille du produit
}T_PRODUIT;

// Définition d'un produit
// -----------------------
typedef struct
{
    T_PRODUIT   sfin;                                       // Info produit Nomenclature SFIN
    T_PRODUIT   cie;                                        // Info produit Nomenclature CIE
    T_PRODUIT   pfin;                                       // Info produit Nomenclature PFIN
    T_PRODUIT   *enfant;                                    // Info produits Nomenclature enfant (CIE, HDD...)
    int         nbEnfant;                                   // Nombre de produit enfant
    T_PRODUIT   *parent;                                    // Info produits Nomenclature parent (PFIN)
    int         nbParent;                                   // Nombre de produit parent
    int         lot;                                        // Numéro de Lot utilisé pour le produit
    int         palette;                                    // Numéro de Palette utilisé pour le produit
}T_POSTE_PRODUIT;

// Liste des produits pour le poste
// --------------------------------
typedef struct
{
    T_POSTE_PRODUIT produits[TCOM_PRODUIT_NB_MAX];          // Liste de produits définis pour le poste
    int             nbProduit;                              // Nombre de produits définis pour le poste
}T_POSTE_PRODUITS;


// Structure Date Heure
// --------------------
typedef struct
{
    short year;
	short year2digits;
    short month;
	short week;
    short dayweek;
	short daymonth;
	short dayyear;
    short hour;
    short minute;
    short second;
    short millisecond;
} T_DATE_HEURE;

// ==============================================================================
// DECLARATION DES PROTOTYPES
// ==============================================================================

extern int TCOM_Connexion ( T_TCOM_BASE *tcomBase );
extern int TCOM_Deconnexion ( T_TCOM_BASE *tcomBase );
extern int TCOM_PosteInformations ( T_TCOM_BASE *tcomBase, T_POSTE_INFOS *posteInfos, char *strErreurMessage );
extern int TCOM_ProduitsPoste ( T_TCOM_BASE *tcomBase, T_POSTE_INFOS *posteInfos, T_POSTE_PRODUITS *posteProduits, char *strErreurMessage );
extern int TCOM_ProduitCopier ( T_POSTE_PRODUIT *posteProduitIn, T_POSTE_PRODUIT *posteProduitOut);
extern int TCOM_ProduitSupprimer ( T_POSTE_PRODUIT *posteProduit );
extern int TCOM_ProduitIndexParent ( T_POSTE_PRODUIT *posteProduit, char *chCode, char *chIndice );
extern int TCOM_ProduitIndexEnfant ( T_POSTE_PRODUIT *posteProduit, char *chCode, char *chIndice, char *chFamille, char *chSousFamille );
extern int TCOM_ReceiverSN ( T_TCOM_BASE *tcomBase, T_VARIABLES_TRACA *varTraca, T_POSTE_PRODUITS *posteProduits, char *strReceiverSN, char *strErreurMessage, int nbParam, ... );
extern int TCOM_GenerationSnClient ( T_TCOM_BASE *tcomBase, char *strFormatClient, char *strSnClient, char *strErreurMessage, int nbParam, ... );
extern int TCOM_AutorisationPassage ( int nItfe, T_TCOM_BASE *tcomBase, char *codeProduitEntree, char *indiceProduitEntree, char *codeProduitSortie, char *indiceProduitSortie, char *nomPoste, char *strReceiverSN, char *strErreurMessage );
extern int TCOM_VerificationDoublon ( int nItfe, T_TCOM_BASE *tcomBase, char *chNomPropriete, char *chValeurPropriete, char *strErreurMessage );
extern int TCOM_EnregistrementMvtTest ( T_TCOM_BASE *tcomBase, char *strReceiverSN, char *codeProduit, char *indiceProduit, char *codeTransaction, int status, int vraiDefaut, float duree, float quantite, char *nomPoste, char *matriculePersonne, char *nomApplication, char *versionApplication, char *observation, __int64 *idMvtTest, char *strErreurMessage );
extern int TCOM_EnregistrementErreurMvtTest ( T_TCOM_BASE *tcomBase, char *libelleErreur, __int64 idMvtTest, char *strCodeErreur, char *strErreurMessage );
extern int TCOM_EnregistrementLienSn ( T_TCOM_BASE *tcomBase, char *strNumSerieEnfant, char *strCodeProduitEnfant, char *strIndiceProduitEnfant, char *strNumSerieParent, char *strCodeProduitParent, char *strIndiceProduitParent, char * strObservation, char * strTypeLien, __int64 lngOrdre, __int64 * lngId_LienNumSerie, char *strErreurMessage );
extern int TCOM_EnregistrementSn ( T_TCOM_BASE *tcomBase, char *strNumSerie, char *strIndiceNumSerie, char *strCodeProduit, char *strIndiceProduit, char *strCodeStatutNumserie, char * strObservation, __int64 * lngId_NumSerie, char *strErreurMessage );
extern int TCOM_RecuperationNumSeriesParents ( T_TCOM_BASE *tcomBase, char *strNumSerie, char *strCodeProduit, char *strIndiceProduit, T_NUM_SERIE **tabNumSeriesParents, int *nbNumSeriesParents, char *strErreurMessage );
extern int TCOM_RecuperationProduitsParents ( T_TCOM_BASE *tcomBase, char *strCodeProduit, char *strIndiceProduit, T_PRODUIT **tabProduitsParents, int *nbProduitsParents, char *strErreurMessage );
extern int TCOM_RecuperationProduitsEnfants ( T_TCOM_BASE *tcomBase, char *strCodeProduit, char *strIndiceProduit, T_PRODUIT **tabProduitsEnfants, int *nbProduitsEnfants, char *strErreurMessage );
extern int TCOM_RecuperationNumSerie ( T_TCOM_BASE *tcomBase, char *strNumSerie, char *strCodeProduit, char *strIndiceProduit, __int64 * lngId_NumSerie, char *strErreurMessage );
extern int TCOM_RecuperationNumSeriesParNumSerie ( T_TCOM_BASE *tcomBase, char *strNumSerie, char ***tabNumSeries, int *NumSeriesLenght1, int *NumSeriesLenght2, char *strErreurMessage );
extern int TCOM_RecuperationProduitNumSerie ( T_TCOM_BASE *tcomBase, char *strNumSerie, char *strCodeTypeProduit, char *strCodeLigneProduit, char *strCodeProduit, char *strIndiceProduit, char *strLibelleProduit, char *strErreurMessage );
extern int TCOM_RecuperationDateHeure ( T_TCOM_BASE *tcomBase, T_DATE_HEURE *dateheure, char *strErreurMessage );
extern int TCOM_RecuperationProprieteNumSerie ( int nItfe, T_TCOM_BASE *tcomBase, char *numserie, char *propriete, char *valpropriete, char *strErreurMessage);
extern int TCOM_EnregistrementTrace ( T_TCOM_BASE *tcomBase, __int64 iIdMvtTestCie, char *strTrace, __int64 *iIdTrace, char *strErreurMessage );
#endif  // #ifndef __TRACACOM_H__
