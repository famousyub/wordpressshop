// ==============================================================================
//   COPYRIGHT (C) BMSC
//   ALL RIGHTS RESERVED.
//  
// 
// ==============================================================================
//   PROJET         : Banc Personnalisation
//   MODULE         : Traçabilité DLL SCProduction
//   PROCESSEUR     : INTEL Pentium
//   ENVIRONNEMENT  : Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION    : Interface avec la DLL SCProduction se connectant sur SAP ME
//                    
// ==============================================================================
//   REMARQUES      :
// ==============================================================================
//   MODIFICATIONS  :   
//
// Version Rev X
// Date / Author
//
// S13002AA00 
// 29-Janvier-2013  MPT
//      >>>  Création
// ==============================================================================
#ifndef __TRACASCPRODUCTION_H__
#define __TRACASCPRODUCTION_H__


// ==============================================================================
// DECLARATION DES CONSTANTES
// ==============================================================================
#define SCPROD_ERREUR_BRESULT							-2	  // Le -1 est réservé pour les autres cas
#define TCOM_ERREUR_CONFIG								-3
#define TCOM_ERREUR_RESEAU								-4
#define SCPROD_ERREUR_LONG_MSG							-5
#define SCPROD_ERREUR_DOT_NET							-6
#define SCPROD_ERREUR_SFC_DEJA_ASSEMBLE					-11
#define SCPROD_ERREUR_RECUP_SFC_COMPOSANT				-12
#define SCPROD_ERREUR_SFC_PAS_EN_STOCK					-13

#define TCOM_PARAM_TAILLE_MAX                   		64          // Taille max en octets des paramètres de la structure T_TCOM_BASE
#define TCOM_SN_PARAM_TAILLE_MAX                		64          // Taille max en octets des paramètres pour la création du Receiver SN

#define SCPROD_OBJET_LONG_MAX             				256        	// longueur maximum des noms d'objets SAP ME
#define SCPROD_MSG_LONG_MAX             				2048        // longueur message d'erreur   


// Nom du banc Perso en base
// -------------------------
#define TCOM_BDP_NOM                            		"ATR_BWC"
#define TCOM_FAMILLE_HDD_CIE							"DCHDDCIE"
#define TCOM_LONG_CODE_PRODUIT                         	9
#define SCPROD_GROUPE_MESURE_BTF             			"ATR_TEST_WIFI_CONDUIT"  

// Version appli paramétrage
// -------------------------
#define TCOM_VERSION_APPLI	                			"1" 		   			// Version de l'applciation Tracacom pour le parametrage en base.


// DONNEES SAP ME
// --------------
#define SCPROD_STR_VIDE									""						// Opération par défaut ==> celle du fichier SAPME.INI
// Code Non Conformité Générique
// -----------------------------
#define SCPROD_CODE_NON_CONF_BTF                   		"BWC_GEN_0001" 			// Code générique pour les Non conformités	

// Remontées temps de test
// -----------------------
#define SCPROD_DUREE_TEST_BTF	                  		"MES_TYPE_TEMPS_TEST" 			// Durée du test BPO
#define SCPROD_DUREE_MANIP_BTF	                  		"DUREE_MANIP_OPERATOR_BTF" 	// Durée de la manip opératuerBPO


// Opérations BPO
// --------------
//#define SCPROD_OPERATION_ASSEMBLAGE						"INTEG_ASSEMBLAGE"		// Opération d'entrée de Gamme où est effectué le StartByItem
//#define SCPROD_OPERATION_PERSO							"INTEG_PERSO"			// Opération de la perso
//#define SCPROD_OPERATION_IMPRESSION						"INTEG_IMPRESSION"		// Opération pour déclencher l'impression
#define SCPROD_OPERATION_DEFAUT							"ATR_TEST_WIFI_CONDUIT"						// Opération par défaut ==> celle du fichier SAPME.INI

// Ressources
// -----------																	//	Ressource par défaut ==> celle du fichier SAPME.INI
#define SCPROD_RESSOURCE_DEFAUT                   		"06_ASSEMBLAGE_01_01"

// Type OF
// -----------																	//	Ressource par défaut ==> celle du fichier SAPME.INI
#define SCPROD_TYPE_OF_PROTO                   			"ENGINEERING"

// Nombre Maximum d'OF CMS
// -----------------------																	//	Ressource par défaut ==> celle du fichier SAPME.INI
#define SCPROD_NBRE_MAX_OF_CMS                 			10


// Paramètres par Défaut SAP ME
// ----------------------------
#define SCPROD_INDICE_DEFAUT             				"A"        								// L'indice par défaut pour les éléments non versionnés dans BPO
#define SCPROD_LIBELLE_ASSEMBLAGE             			"Assemblé par BTF via DLL SCProd"   
#define SCPROD_LIBELLE_MESURE             				"Mesuré par BTF via DLL SCProd"     
#define SCPROD_GROUPE_MESURE_BTF             			"BTF"     
#define SCPROD_VALEUR_ZERO 								"0"										// Valeur 0 pour remontée du flag Provisioning
#define SCPROD_NOT_APPLICABLE							"NOT_APPLICABLE"						// Tag Non Applicable

// Accessoire HDD
// --------------
#define SCPROD_HDD_SUFFIXE	             				"_SERIAL"								// Suffixe du HDD Serial (CodeProduit+Suffixe) pour le SFC HDD à mettre en stock
#define SCPROD_HDD_PREFIXE_UNICITE         				"HDD_SERIAL="							// Prefixe du HDD Serial Number lorsque remonté dans SAP ME via u composant pour ne pas mélanger le contrôle d'unicité.
#define SCPROD_HDD_NOM_VARIABLE_PWD         			"HDD_PASSWORD"							// Nom de la variable utilisé en Collect SFC Data pour le Password HDD


// Accessoire GateWay EMTA 
// -----------------------
#define SCPROD_GTW_PREFIXE_UNICITE						"GTW_SERIAL="
//#define SCPROD_GTW_NOM_COMPOSANT_MAC_EMTA				"ETAT_DEC_GTW_SMACEMTA="
#define SCPROD_GTW_NOM_DONNEE_FIRMWARE					"ETAT_DEC_GTW_SFIRMWAREGATEWAY"
#define SCPROD_GTW_NOM_DONNEE_SSID						"ETAT_DEC_GTW_SSSIDWIFI"
#define SCPROD_GTW_NOM_DONNEE_MAC_DOCSIS				"ETAT_DEC_GTW_SMACDOCSISADRESSE"
#define SCPROD_GTW_NOM_DONNEE_MAC_EMTA					"ETAT_DEC_GTW_SMACADRESSEEMTA"
#define SCPROD_GTW_NOM_DONNEE_CLE_SECURITE				"ETAT_DEC_GTW_SCLESECURITEWIFI"
#define SCPROD_GTW_NOM_DONNEE_CLE_SECURITE_2G			"ETAT_DEC_GTW_SCLESECURITEWIFI_2GHZ"
#define SCPROD_GTW_NOM_DONNEE_CLE_SECURITE_5G			"ETAT_DEC_GTW_SCLESECURITEWIFI_5GHZ"
#define SCPROD_GTW_NOMBRE_VARIABLES						7
#define SCPROD_GTW_NET_NOMBRE_VARIABLES					3 



// Accessoire GateWay EMTF
// ------------------------------
#define SCPROD_GTW_NOM_DONNEE_SSNGPON					"ETAT_DEC_GTW_SSNGPON"
#define SCPROD_GTW_NOM_DONNEE_SMAC_EMTF					"ETAT_DEC_GTW_SMACADRESSEEMTF"
#define SCPROD_GTW_NOM_DONNEE_SN_EMTF					"ETAT_DEC_GTW_SSNEMTF"
#define SCPROD_GTW_NOM_DONNEE_PID_EMTF					"ETAT_DEC_GTW_SPIDEMTF"
#define SCPROD_GTW_NOM_DONNEE_WPA_EMTF					"ETAT_DEC_GTW_SWPAKEYEMTF"
#define SCPROD_GTW_NOM_DONNEE_AUTH_KEY_EMTF				"ETAT_DEC_GTW_SAUTHKEYEMTF"
#define SCPROD_GTW_NOM_DONNEE_PASSWORD_GPON				"ETAT_DEC_GTW_SGPONPASSWORD"





#define SCPROD_GTW_NOM_DONNEE_SSID_01					"ETAT_DEC_GTW_SSSID1"
#define SCPROD_GTW_NOM_DONNEE_SSID_02					"ETAT_DEC_GTW_SSSID2"

#define SCPROD_GTW_NOM_DONNEE_WIFI_01 					"ETAT_DEC_GTW_SWIFIKEY1"
#define SCPROD_GTW_NOM_DONNEE_WIFI_02 					"ETAT_DEC_GTW_SWIFIKEY2"


#define SCPROD_GTW_NOMBRE_VARIABLES_GW_EMTF				 6
#define SCPROD_GTW_NOMBRE_VARIABLES_GW_EMTF_PT			 8 




// Types d'assemblage
// ------------------
#define SCPROD_ASSEMBLAGE_SFC							"SFC"
#define SCPROD_ASSEMBLAGE_INVENTORY_ID					"INVENTORY_ID"


// Retour DLL SAP ME
// ------------------
#define SCPROD_RET_OK									"OK"
#define SCPROD_RET_NOK									"NOK"
#define SCPROD_RET_DEJA_ASSEMBLE						"ALREADY_ASSEMBLED"


// Définiton des types de SN client
// --------------------------------
#define TCOM_SN_CLIENT_BYT                      		"BYT"
#define TCOM_SN_CLIENT_CHILI                    		"CHILI"
#define TCOM_SN_CLIENT_VDF                    			"VDF"
#define TCOM_SN_CLIENT_DS87CYFRA						"DS87CYFRA"
#define TCOM_SN_CLIENT_DSI87HDSFR						"DSI87HDSFR"
#define TCOM_SN_CLIENT_IAD84HA						    "IAD84HA" 
#define TCOM_SN_CLIENT_DIGITURK						    "DIGITURK"
#define TCOM_SN_CLIENT_VIVACOM						    "VIVACOM"
#define TCOM_SN_CLIENT_ICADD82						    "ICADD82"
#define TCOM_SN_CLIENT_DSI83CYFRA						"DSI83CYFRA"
#define SCPROD_SN_CLIENT_BYT_RTI422						"CSN_BYT_RTI422"	//"BYT_RTI422" 
#define SCPROD_SN_CLIENT_VDF_383						"CSN_VDF_383"	
#define TCOM_SN_CLIENT_NDS16							"NDS16"
#define TCOM_SN_CLIENT_EMBRATEL1						"EMBRATEL1"
#define TCOM_SN_CLIENT_DSIW74_NCPLUS					"DSIW74_NCPLUS"

#define SCPROD_SN_CLIENT_DIGITURK_4K					"CSN_ESIW384_DGTK"
#define SCPROD_SN_CLIENT_DIGITURK_4K_V2					"CSN_DSIW362_DGTK"

#define SCPROD_SN_CLIENT_EIW384_UHD						"CSN_EIW384_UHD"
#define SCPROD_SN_CLIENT_EGCI_384_UHD_SFR				"CSN_EGCI384_UHD_SFR"


#define TCOM_SN_CLIENT_DIGITURK_4K						"DGTK" 
#define TCOM_SN_CLIENT_DIGITURK_4K_V2					"DGTKV2"


// a revoir impacte sur ME
//------------------------
#define TCOM_SN_CLIENT_VDF_383_NDS                 		"VDF_383_NDS"
#define TCOM_SN_CLIENT_VDF_383_SKY                 		"CSN_VDF_383_SKYD"
#define TCOM_SN_CLIENT_VDF_383_SKY_CAM_SNR             	"VDF_383_CAM_SNR"
#define TCOM_SN_CLIENT_TOTALPLAY_EIW384_UHD				"TOTALPLAY" 
#define TCOM_SN_CLIENT_VDF_ITALIE						"CSN_DTIW384_VI"
#define SCPROD_SN_CLIENT_VDF_362                   		"CSN_VDF_362"
#define SCPROD_SN_KD_VDF_362     						"KDSN_VDF_362" 

#define TCOM_SN_CLIENT_DTIW384_SFR						"DTIW384_SFR"
#define SCPROD_SN_CLIENT_DTIW384_SFR                 	"CSN_DTIW384_SFR"


#define TCOM_SN_CLIENT_EGFI184_SFR						"EGFI18400SFR"
#define SCPROD_SN_CLIENT_EGFI184_SFR                 	"CSN_EGFI184_SFR"   // pour faire l'asssemblage

#define TCOM_SN_CLIENT_ONE_BOX_NET						"NET"

#define SCPROD_SN_CLIENT_ONE_BOX_NET					"CSN_DGCI384_NET"


#define TCOM_SN_CLIENT_ONE_BOX_CLARO					"CLARO"

#define SCPROD_SN_CLIENT_ONE_BOX_CLARO					"CSN_DGCI384_CLARO"


// Définiton des paramètres de SN client DSI87HDSFR
// ------------------------------------------------
#define TCOM_SN_CLIENT_DSI87HDSFR_SOFT_REV      		"000"
#define TCOM_SN_CLIENT_DSI87HDSFR_HARDWARE_VERSION      "A" 

// URL pour récup logo et masque
// -----------------------------
#define URL 											"intranetTracacom/modules/production/etiquetage/etiquetageWebServicesCtl.php"



// ==============================================================================
// DECLARATION DES STRUCTURES ET ENUMERATIONS
// ==============================================================================

// Type instance TracaCom  et DotNet
// ----------------------------------
typedef SCProduction_GestionProductions hdleSCProd;   
typedef CDotNetHandle hdleExcept;

// Structure définissant une connexion à la base TracaCom
// ------------------------------------------------------
typedef struct
{
    char        nomServeur[TCOM_PARAM_TAILLE_MAX];          // Nom du serveur
    int         portServeur;                                // Port du serveur
    char        loginServeur[TCOM_PARAM_TAILLE_MAX];        // Login de connexion au serveur
    char        nomBase[TCOM_PARAM_TAILLE_MAX];             // Nom de la base de connexion
    hdleSCProd 	instSCProduction;                               // Instance sur la connexion à la base
	hdleExcept  ExceptHandle;
	char		adresseTracacom[TCOM_PARAM_TAILLE_MAX];		// Adresse Tracacom
	int 		iServeurDebug;								// 1 pour faire du Debug
}T_TCOM_BASE;

// Définition des informations d'un poste
// --------------------------------------
typedef struct
{
    char        chType[TCOM_PARAM_TAILLE_MAX];              // Type du poste
    char        chNom[TCOM_PARAM_TAILLE_MAX];               // Nom du poste
    __int64     id;                                         // Identifiant du poste
    int         numCentre;                                  // Numéro du centre
    int         numLigne;                                   // Numéro de la ligne
	//int 		numLangue;									// Numéro de la langue 0=FRANCAIS 1=ANGLAIS 2=PORTUGAIS
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
    char        chIndice[TCOM_PARAM_TAILLE_MAX];            // Indice du produit  exemple => A02
    char        chDesignation[TCOM_PARAM_TAILLE_MAX];       // Désignation du produit
    char        chFamille[TCOM_PARAM_TAILLE_MAX];           // Famille du produit
    char        chSousFamille[TCOM_PARAM_TAILLE_MAX];       // Sous famille du produit
	char        chLibelle[TCOM_PARAM_TAILLE_MAX];       	// Libelle du produit
//	char		chOrdreFabrication[SCPROD_OBJET_LONG_MAX];   // La référence d'OF est passé sur les variables de traça pour chaque décodeur.
	char		chTypeOrdreFabrication[SCPROD_OBJET_LONG_MAX];

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
    T_POSTE_PRODUIT *produits;          					// Liste de produits définis pour le poste
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

extern int SCPROD_Connexion ( T_TCOM_BASE *tcomBase , char *strErreurMessage );
extern int SCPROD_Deconnexion ( T_TCOM_BASE *tcomBase );
extern int SCPROD_PosteInformations ( T_TCOM_BASE *tcomBase, T_POSTE_INFOS *posteInfos, char *strErreurMessage );
extern int SCPROD_ProduitsPoste ( T_TCOM_BASE *tcomBase, T_POSTE_INFOS *posteInfos, T_POSTE_PRODUITS *posteProduits, char *strErreurMessage );
extern int TCOM_ProduitCopier ( T_POSTE_PRODUIT *posteProduitIn, T_POSTE_PRODUIT *posteProduitOut);
extern int TCOM_ProduitSupprimer ( T_POSTE_PRODUIT *posteProduit );
extern int SCPROD_GenerationSnClient (int nItfe, T_TCOM_BASE *tcomBase, char *strNumSerie, char *strFormatClient, char *strSnClient, char *strErreurMessage, int nbParam, ... );
extern int SCPROD_LiberationSnPFIN ( int nItfe, T_TCOM_BASE *tcomBase, char *OrdreFabrication, char *strErreurMessage );
extern int SCPROD_GenerationStartSnPFIN ( int nItfe, T_TCOM_BASE *tcomBase, char *codeProduit, char *indiceProduit, char *strErreurMessage );

// Cette fonction permet de faire des calcule via les ps en base de données tracacom
//-----------------------------------------------------------------------------------
extern int TCOM_V2_GenerationSnClient (int nItfe, T_TCOM_BASE *tcomBase, char *strFormatClient, char *strFormatClientSapme,char *strSnClient, char *strErreurMessage, int nbParam, ... );
extern int TCOM_GenerationSnClient (int nItfe, T_TCOM_BASE *tcomBase, char *strFormatClient, char *strSnClient, char *strErreurMessage, int nbParam, ... );

extern int SCPROD_StartSnPFIN ( int nItfe, T_TCOM_BASE *tcomBase, char *Operation, char *Ressource, char *strErreurMessage );
extern int SCPROD_SignoffSnPFIN ( int nItfe, T_TCOM_BASE *tcomBase, char *Operation, char *Ressource, char *strErreurMessage );
extern int SCPROD_RecuperationSFCDepuisComposant ( int nItfe, T_TCOM_BASE *tcomBase, char *Composant, char *SFC, int *iExistenceSFC, char *strErreurMessage );
extern int SCPROD_LogNC ( int nItfe, T_TCOM_BASE *tcomBase, char *Operation, char *Ressource, char *strErreurMessage );
extern int SCPROD_CollectSFCData ( int nItfe, T_TCOM_BASE *tcomBase, char *SFC, char *NomPropriete, char *ValeurPropriete, char *strErreurMessage );
extern int SCPROD_CollectSFCDataTableau ( int nItfe, T_TCOM_BASE *tcomBase, char *SFC, char **Tableau, int Lg1, int Lg2, char *strErreurMessage );
extern int SCPROD_LogParametricData ( int nItfe, int IndexMesure, char *strErreurMessage );
extern int SCPROD_LogParametricDataTableau ( int nItfe, char **Tableau, int Lg1, int Lg2, char *strErreurMessage );
extern int SCPROD_AjoutStockComposant ( int nItfe, T_TCOM_BASE *tcomBase, char *Composant, char *Indice, char *Valeur, int *iExistence, char *SFCParent, char *strErreurMessage );
extern int SCPROD_AssemblageComposant ( int nItfe, T_TCOM_BASE *tcomBase, char *ValeurComposant, char *CodeComposant, char *SFC, char *TypeAssemblage, char *Operation, char *Ressource, char *strErreurMessage );
extern int SCPROD_AssemblageComposantTableau ( int nItfe, T_TCOM_BASE *tcomBase, char *SFC, char *Operation, char *Ressource, char **Tableau, int Lg1, int Lg2, char *strErreurMessage );
extern int SCPROD_RecuperationComposant ( int nItfe, T_TCOM_BASE *tcomBase, char *SFC, char *TypeComposant, char *ValeurComposant, int *iExistence, char *strErreurMessage );
extern int SCPROD_RecuperationProprieteSFC ( int nItfe, T_TCOM_BASE *tcomBase, char *SFC, char *NomPropriete, char *ValeurPropriete, char *strErreurMessage);
extern int SCPROD_RecuperationProprietesSFCTableau ( int nItfe, T_TCOM_BASE *tcomBase, char *SFC, char ***TableauValeurs, int *Lg1, int *Lg2, char *strErreurMessage);
extern int SCPROD_CompleteSnPFIN ( int nItfe, T_TCOM_BASE *tcomBase, char *Operation, char *Ressource, char *strErreurMessage );
extern int SCPROD_EnregistrementLog ( int nItfe, T_TCOM_BASE *tcomBase, char *BufferTrace, char *strErreurMessage );
extern int SCPROD_InformationsOF ( int nItfe, T_TCOM_BASE *tcomBase, char *OrdreFabrication, char *RetourCodeProduit,char *RetourIndiceProduit, char *RetourTypeOF, char *strErreurMessage );
extern int SCPROD_InformationsSFC ( int nItfe, T_TCOM_BASE *tcomBase, char *SFC, char *RetourCodeProduit,char *RetourIndiceProduit, char *RetourOF, char *strErreurMessage );
extern int SCPROD_InformationsHDD ( int nItfe, T_TCOM_BASE *tcomBase, char *SFC, char *RetourCodeProduit,char *RetourIndiceProduit, char *strErreurMessage );
extern int TCOM_RecuperationProduitsParents ( T_TCOM_BASE *tcomBase, char *strCodeProduit, char *strIndiceProduit, T_PRODUIT **tabProduitsParents, int *nbProduitsParents, char *strErreurMessage );
extern int TCOM_RecuperationProduitsEnfants ( T_TCOM_BASE *tcomBase, char *strCodeProduit, char *strIndiceProduit, T_PRODUIT **tabProduitsEnfants, int *nbProduitsEnfants, char *strErreurMessage );
extern int SCPROD_RecuperationDateHeure ( T_TCOM_BASE *tcomBase, T_DATE_HEURE *dateheure, char *strErreurMessage );
extern int TCOM_EcritureCle (T_TCOM_BASE *tcomBase, char *strNomTableCle, char *strNumSerie, char *strCodeProduit, char *strIndiceProduit, char **tabParam, int iParamLength, char *strErreurMessage );
extern int TCOM_RecuperationCles (int nItfe, T_TCOM_BASE *tcomBase, char *strNomTableCle, char *strNumSerie, char *strCodeProduit, char *strIndiceProduit, char **tabParam, int iParamLength, char ***tabValeursCle, int *iQuantiteCle, int *iValeursCleLength, char *strErreurMessage );
extern int TCOM_LectureCle (int nItfe, T_TCOM_BASE *tcomBase, char *strNomTableCle, char *strNumSerie, char *strCodeProduit, char *strIndiceProduit, char **tabParam, int iParamLength, char ***tabValeursCle, int *iValeursCleLength, char *strErreurMessage );
extern int TCOM_RecuperationMasqueLogoEtiquette ( int nItfe, T_TCOM_BASE *tcomBase, char *strNumserie, char *strCodeProduit, char *strIndiceProduit, char *strServeurHttp, char *strUrlPage, char *strLogo, char *strErreurMessage );
extern int TCOM_RecuperationMasqueEtiquette ( int nItfe, T_TCOM_BASE *tcomBase, char *strNumserie, char *strCodeProduit, char *strIndiceProduit, char *strServeurHttp, char *strUrlPage, char *strMasque, char *strErreurMessage );
extern int TCOM_RecuperationSectionParametres ( T_TCOM_BASE *tcomBase, char *NomSectionParametre, 	char  ***TabParametresDetails, int *NombreLignesParametresDetails, int *NombreColonnesParametresDetails, char *strErreurMessage );
extern int SCPROD_ImprimerViaDll (int nItfe,  T_TCOM_BASE *tcomBase, char *SFC, char *chNumArticle, int QteEtiquettes, char  *chNomZebra, char *strErreurMessage );
extern int SCPROD_TraceAppels ( int nItfe, char *Message );
extern int SCPROD_StartSnCIE ( int nItfe, T_TCOM_BASE *tcomBase, char *Operation, char *Ressource, char *strErreurMessage );
#endif  // #ifndef __TRACASCPRODUCTION_H__			 
