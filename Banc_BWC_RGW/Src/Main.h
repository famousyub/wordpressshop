#ifndef __MAIN_H__
#define __MAIN_H__



/**********************************************/
/*** SECTION : INCLUDE et DEFINE			***/
/**********************************************/

// Paramètres de configuration de l'application
// --------------------------------------------
#define NOM_SOFT									"Banc Test Wifi conduit"
#define VERSION_SOFT								"BWC_V1.0.2"
//#define VERSION_SOFT								"BWC_V1.0.7" 
#define NOM_OPERATION		 						"ATR_TEST_WIFI_CONDUIT"   //   ATR_TEST_WIFI_CONDUIT  ///"TEST_WIFI_CONDUIT" 
#define INI_VAL_SAPME_RESSOURCE						"SAPMEBoutonRessource%d" 
#define INI_VAL_RESSOURCE_SAPME		        		"RessourceSlot%d" 
#define INI_VAL_ACTIVE_SLOT							"ActiveSlot%d"

#define INI_VAL_INSTR_SLOT                          "InstrumentID_S%d"
#define INI_VAL_PWR_TYPE                            "TypePwrmetterS%d" 

// =================================================================
// = Définition des commandes appli  (à définir en minuscule) =
// =================================================================

#define CMD_PERSO_TYPE_WAIT                         "cmd_wait"                              // Type Commande appli perso : WAIT - attente de x secondes
#define CMD_PERSO_FORMAT_WAIT                       "cmd_wait %d"                           // Format commande appli perso : WAIT - attente de x secondes ('cmd_wait x')
#define CMD_PERSO_TYPE_DISPLAY                      "cmd_display"                           // Type Commande appli perso : DISPLAY - affichage d'un message
#define CMD_PERSO_FORMAT_DISPLAY                    "cmd_display %d"                        // Format commande appli perso : DISPLAY - affichage d'un message
#define CMD_PERSO_TYPE_DISPLAY_T_IHM    0x01                                // Type Commande appli perso : DISPLAY - Type affichage IHM
#define CMD_PERSO_TYPE_DISPLAY_T_LOG    0x02                                // Type Commande appli perso : DISPLAY - Type affichage fichier LOG
#define CMD_PERSO_TYPE_DISPLAY_T_BOX    0x04                                // Type Commande appli perso : DISPLAY - Type affichage fenêtre


// valeur booleen
#define FALSE										0						// faux
#define TRUE										1						// vrai

// Affichage de traces
#define AUCUNE_TRACE								0
#define AFFICHAGE_TRACE								1  
#define AFFICHAGE_RETOUR_CLE                        0x10
#define AFFICHAGE_RETOUR_OK                        	0x20

// Define pour le fichier INI et cfg							  +
#define FIC_CONFIG_NOM								"fichier_INI.ini" 
#define FIC_CONFIG_SAP_ME_NOM						"Configuration_SAPME.ini"    
#define FIC_MESSAGES                              	"Messages.txt"

#define ETIQ_INIT									"Initialisation"
#define TAILLE_AFFICHAGE_CLE                        50  
// Définition du lock des appels DLL des fonctions tracacom (activation du multi-thread sur contrôleur .NET)
// -----------------------------------------------------------------------------------------------------------
#define	LOCK_BDD						     		1
#define	SUR_LOCK_BDD					    		1

// =========================================================
// = Définition des paramètres du fichier de configuration =
// =========================================================

// Champ [Initialisation]
// ----------------------
#define INI_VAL_ACTIVE_LOG							"ActiveLog"
#define INI_VAL_SERVEUR_ADRESSE						"ServeurAdresse"
#define INI_VAL_SERVEUR_PORT						"ServeurPort"
#define INI_VAL_SERVEUR_LOGIN						"ServeurLogin"
#define INI_VAL_SERVEUR_PASSWORD					"ServeurPassword"
#define INI_VAL_SERVEUR_NOM_BASE					"ServeurNomBase"
#define INI_VAL_GENERAL							    "[GENERAL]" 

// Champ ['Poste']
// ---------------
#define INI_VAL_NOM_TESTEUR							"NomTesteur"
#define INI_VAL_NUMERO_USINE						"NumUsine"
#define INI_VAL_CHEMIN_LOG							"CheminLog"
#define INI_VAL_SLOT								"Slot%d"
#define INI_VAL_IHM_POSITION_LEFT					"IhmPositionLeft%d"
#define INI_VAL_IHM_POSITION_TOP					"IhmPositionTop%d"
#define INI_VAL_PORT_GEN_A                          "NumPortGenerique%d"
#define INI_VAL_BAUD_GEN_A                          "BaudPortGen%d"
#define INI_VAL_IP_SWITCH_RF_SP8T                   "IPSwitchRFSP8T_S%d"
#define INI_VAL_FLAG_SP8T							"SP8T_S%d"
#define INI_VAL_BLOC_SWITCH_RF_SP8T                 "BlocSwitchRFSP8T_S%d"
#define INI_VAL_TIMEOUT_SWITCH_RF                   "TimeOutSwitchRF_S%d"
#define INI_VAL_FLAG_TRACA                          "Flag_Traca_S%d"
#define INI_VAL_PORT_CAISSON                        "NumPortCaisson%d"

// Section [GENERAL] du paramétrage en base
// -----------------------------------------
						
#define INI_VAL_CANAL_2G                		    "CANAL_2G"
#define INI_VAL_CANAL_5G                		    "CANAL_5G"


// Champ Slot
//-----------
#define INI_VAL_SLOT_BDD							"[SLOT_%d]" 

// Valeur des ports COM
#define INI_VAL_PORT_DECODEUR						"NumPortDecodeur%d"
// Valeur de la vitesse en baud de la COM
#define INI_VAL_BAUD_DECODEUR						"BaudPortDecodeur%d"

// Valeur SAPME


// Valeur des erreurs
#define ERROR_ALLOC_RESOURCE 		  0
#define OTHER_INSTANCE 				  1
#define LIB_NOT_FREE				  2
#define BAD_LOG_SQL					  3
#define MESS_VERIF_CODE__1			  4
#define MESS_VERIF_CODE__2			  5
#define MESS_VERIF_CODE__3			  6
#define MESS_VERIF_CODE__4			  7
#define TESTEUR_NON_TROUVE			  8

// Etats de l'IHM
#define ETAT_INIT_IHM				  10
#define ETAT_SLOT_INACTIF			  11
#define ETAT_SLOT_ACTIF				  12
#define ETAT_FERMETURE				  13
#define ETAT_AUTORISATION_PASSAGE	  14
#define ETAT_TRACA_BDD				  15
#define ETAT_KO						  16
#define ETAT_OK						  17
#define ETAT_STOP					  18
#define ETAT_PERTE_PING				  19

// TESTS
#define ETAT_CONFIG_WIFI_2G			  100
#define ETAT_CONFIG_WIFI_5G			  101
#define ETAT_MESURE_2G				  102
#define ETAT_MESURE_5G				  103
#define ETAT_INIT_WIFI_5G			  104
#define ETAT_TEST_USB_1				  105
#define ETAT_MSJ_NVRAM				  106
#define ETAT_ASSEMBLAGE_FILLE_MERE	  107
#define ETAT_TEST_USB_2				  108
#define ETAT_CHECK_NVRAM			  109  
#define ETAT_LECTURE_VERSION       	  110

#define ETAT_LECTURE_DFA_GATEWAY	  111
	

//#define ETAT_INIT       			  111
#define ETAT_CONFIG_BT   			  112
#define ETAT_MESURE_BT			      113
#define ETAT_LECTURE_SN			      114
#define	ETAT_DECODEUR_PRESENT		  115
#define	ETAT_FINALISATION			  116
#define	ETAT_CONFIG_IR				  117
#define	ETAT_TEST_IR				  118
#define ETAT_TEST_Bouton			  119
#define ETAT_TEST_LED	     		  120
#define ETAT_VERIF_VERSION_FIRMWARE   121
#define ETAT_SWITCH         		  122
#define ETAT_RECUP       			  123
#define ETAT_ATTENTE_FERMETURE_CAISSON 124
#define ETAT_Check_Driver_2Ghz		   125
#define ETAT_Update_Driver_2Ghz		   126
#define ETAT_Update_IP_DUT			   127
#define	ETAT_TEST_WIFI_2Ghz			   128	
#define ETAT_Ping_DUT					 129
#define	ETAT_TEST_BT					130
#define ETAT_OPEN_CAISSON				131
#define ETAT_Check_Driver_BT		   132
#define ETAT_Update_Driver_BT		   133
#define ETAT_Check_Driver_5Ghz			134
#define ETAT_Update_Driver_5Ghz			135
#define ETAT_TEST_WIFI_5Ghz				136
#define	ETAT_cmd_exit_2Ghz		        154
#define ETAT_cmd_exit_5Ghz              155 
#define ETAT_TEST_WIFI_5_2Ghz           170
#define ETAT_CONNEXION_TELNET           180
	//
#define ETAT_INIT       			    181

#define ETAT_TEST_WIFI_6Ghz				182
#define	ETAT_FLACHAGE_SFC			    183
#define	ETAT_ECRITURE_DFA			    184
#define	ETAT_ACTIVATION_DHCP			185
#define	ETAT_DESACTIVATION_DHCP			186
#define	ETAT_REMONTE_SFTP			    187



#define	TAILLE_MAX					  50000
#define	TAILLE_MOY					  3000
#define	TAILLE_MIN					  500
// Autre
#define CMD_TT_NB_MAX				  10								// Nombre maxi de commande TT
#define REP_TT_NB_MAX				  10								// Nombre maxi de réponse à une commande TT


#define MASQUE_ERR                    0x04  
#define TAG_NON_REMONTE               "Non Remonte"    


// Nombre de tentative pour la récupération du receiver SN
//#define RCVSN_NB_TENTATIVE			2

// Nombre de tentative pour la récupération de clé
//#define KEY_NB_TENTATIVE			2

/**********************************************/
/*** SECTION : STRUCTURES					***/
/**********************************************/

// Structure générale (slot, interface, ports)
// -------------------------------------------
typedef struct 
{
	int						nActif;										// Slot actif
	int						nEtat;   									// Etat du test ( attente,init,en cours, fermeture ... )
	int						nPopupActif;								// Etat panel Popup
	int						nLotActif;									// Etat panel Lot
	int						nVariablesActif;							// Etat panel de gesteino des variables de configuration
	int						nPopupRetour;								// Valeur de retour de la fenêtre Popup
	int						nActiveLog;									// Flag indiquant si le fichier Log doit être créé
	int						panelMain;									// Handle du panel principal
	int						panelPopup;									// Handle du panel Popup
	int						panelTraca;									// Handle du panel Traca
	int						panelbouton;								// Handle du panel Bouton
	int						panelInfo;									// Handle du panel Info
	int						panelLot;									// Handle du panel Lot/Palette
	int						panelVariables;								// Handle du panel de gestion des variables de configuration
	int						panelMainLeft;								// Position gauche initiale de la panel principale
	int						panelMainTop;								// Position haute initiale de la panel principale
	int						panelSn;									// Handle du panel Sn
    int                     panelSuperPop;                              // Handle du panel Popup
    int                     panelConfiguration;                         // Handle du panel de gestion des variables de configuration
} T_IHM_SLOT;

// Structure de gestion d'erreur
// -----------------------------
typedef struct 
{
	T_RS232_CFG	tConfig;									// Configuratino du port COM									
	int			iHandle;									// Handle du port. ATTENTION : handle différent du numéro du port réel
	short int	iErrorOccured;								// Indicateur d'erreur lors de l'ouverture d'un port (0 ou 1)						 			 						  
	long  int	iErrorCode;									// Code d'erreur lors de l'ouverture d'un port
	char		sErrorMsg[RS232_MSG_LEN];					// Message d'erreur lors de l'ouverture d'un port
	int			iStatus;									// valeur de retour
} T_PORT_COM;



// Structure 
// -------------------------------------
typedef struct 
{
	char	chNumSerie[64];									// Numéro de série
	char	chCodeProduit[64];								// Code produit du SN
	char	chIndiceProduit[64];							// Indice du code produit du SN
} T_NUM_SERIE;


// Structure tracabilité
// ---------------------
typedef struct
{
    int                 idxProduit;                             // Index du produit sélectionné
    int                 idxProduitHdd;                          // Index du produit HDD sélectionné dans la table de produits enfants du SFIN
   	int					nFlagProduitTrace;						// Flag indiquant si le produit a été tracé ou non (pour les Follows entre autre).
	int                 iStartOK;                          		// Flag indiquant si le start a été effectué avec succès (pour savoir si on fait un complete ou non après)
 	//char                PersoSAPMERessource[TAILLE_MAX];        	// Nom de la ressource utilisée par SAP ME pour effectuer la demande d'impression.
 	//char                PersoSAPMEOperation[TAILLE_MAX];        	// Nom de la ressource utilisée par SAP ME pour effectuer la demande d'impression.
	
	char                NomRessourceSAPME[TAILLE_MAX];      // Nom de la ressource utilisée par SAP ME pour effectuer les opérations start/complete etc.
	char                ImpressionSAPMERessource[TAILLE_MAX];        	// Nom de la ressource utilisée par SAP ME pour effectuer la demande d'impression.
 	
	char                ImpressionSAPMEOperation[TAILLE_MAX];        	// Nom de la ressource utilisée par SAP ME pour effectuer la demande d'impression.
	char                ImpressionSAPMEZebra[TAILLE_MAX];        	// Nom de la ressource utilisée par SAP ME pour effectuer la demande d'impression.
		
	//char                NomRscImpressionSAPME[TAILLE_MAX];        	// Nom de la ressource utilisée par SAP ME pour effectuer la demande d'impression.
	//char                NomOprImpressionSAPME[TAILLE_MAX];        	// Nom de la ressource utilisée par SAP ME pour effectuer la demande d'impression.
	char                PfinSfcSAPME[TAILLE_MAX];               // Numéro de série du Pfin SAPME (SFC)
	char                CieSn[TAILLE_MAX];                      // Numéro de série du CIE
	char                CiuSfcSAPME[TAILLE_MAX];                // Numéro de série du CIU SAPME (SFC sur gamme CMS/CIE) ==> rattaché au code produit CIE.
	char				chOrdreFabCMS[TAILLE_MAX*3];
	char				chOrdreFabINTEG[TAILLE_MAX*3];
//	char				chTypeOrdreFabCMS[TAILLE_MAX*3];		// Les types sont rattachés au produit
//	char				chTypeOrdreFabINTEG[TAILLE_MAX*3];
    char                AddrCieSn[TAILLE_MAX];                  // Adresse du Numéro de série du CIE
	char                CieVersion[TAILLE_MAX];                 // Code du CIE
    char                CieIndice[TAILLE_MAX];                  // Indice du CIE	exemple A2 et non A02!
	char                chChipsetSnDec[21];                    	// Valeur du Chipset ID en Décimale	   
	char                chChipsetSnHex[26];                    	// Valeur du Chipset ID en Héxadécimal
    char                chLibelleErreur[TAILLE_MAX];                  // Libellé de l'erreur remonté en BDD
	char            	chNumSerieNimCie[50];  					// Numero de série Cie du NIM
	char            	chCodeNimCie[50];  						// Code Produit Cie du NIM
	char            	chIndiceNimCie[50];  					// Indice Produit Cie du NIM
	char            	chLibelleNimCie[50];  					// Libelle Cie du NIM
	//char                NomRessourceSAPME[TAILLE_MAX];      // Nom de la ressource utilisée par SAP ME pour effectuer les opérations start/complete etc.
	char                DFAfille[TAILLE_MAX];					// DFA carte fille
	char                CiuSfcFilleSAPME[TAILLE_MAX];                // Numéro de série du CIU SAPME (SFC sur gamme CMS/CIE) ==> rattaché au code produit CIE.
	char                OxNumSerie[TAILLE_MIN];
	//	int                 idxProduit;                             // Index du produit sélectionné
//	int                 idxProduitHdd;                          // Index du produit HDD sélectionné dans la table de produits enfants du SFIN
//	int					nFlagProduitTrace;						// Flag indiquant si le produit a été tracé ou non (pour les Follows entre autre)
	//int                 iStartOK;                          		// Flag indiquant si le start a été effectué avec succès (pour savoir si on fait un complete ou non après)
	char                PersoSAPMERessource[TAILLE_MAX];        	// Nom de la ressource utilisée par SAP ME pour effectuer la demande d'impression.
	char                PersoSAPMEOperation[TAILLE_MAX];        	// Nom de la ressource utilisée par SAP ME pour effectuer la demande d'impression.

//	char                NomRessourceSAPME[TAILLE_MAX];      // Nom de la ressource utilisée par SAP ME pour effectuer les opérations start/complete etc.
//	char                ImpressionSAPMERessource[TAILLE_MAX];        	// Nom de la ressource utilisée par SAP ME pour effectuer la demande d'impression.

//	char                ImpressionSAPMEOperation[TAILLE_MAX];        	// Nom de la ressource utilisée par SAP ME pour effectuer la demande d'impression.
//	char                ImpressionSAPMEZebra[TAILLE_MAX];        	// Nom de la ressource utilisée par SAP ME pour effectuer la demande d'impression.

	//char                NomRscImpressionSAPME[TAILLE_MAX];        	// Nom de la ressource utilisée par SAP ME pour effectuer la demande d'impression.
	//char                NomOprImpressionSAPME[TAILLE_MAX];        	// Nom de la ressource utilisée par SAP ME pour effectuer la demande d'impression.
//	char                PfinSfcSAPME[TAILLE_MAX];               // Numéro de série du Pfin SAPME (SFC)
		char                SnEtiquette[128]; 						// Numéro de série du SFIN étiquette 
//	char                CieSn[TAILLE_MAX];                      // Numéro de série du CIE
//	char                CiuSfcSAPME[TAILLE_MAX];                // Numéro de série du CIU SAPME (SFC sur gamme CMS/CIE) ==> rattaché au code produit CIE.
//	char				chOrdreFabCMS[TAILLE_MAX*3];
//	char				chOrdreFabINTEG[TAILLE_MAX*3];
//	char				chTypeOrdreFabCMS[TAILLE_MAX*3];		// Les types sont rattachés au produit
//	char				chTypeOrdreFabINTEG[TAILLE_MAX*3];
//	char                AddrCieSn[TAILLE_MAX];                  // Adresse du Numéro de série du CIE
//	char                CieVersion[TAILLE_MAX];                 // Code du CIE
//	char                CieIndice[TAILLE_MAX];                  // Indice du CIE	exemple A2 et non A02!
//	char                chChipsetSnDec[21];                    	// Valeur du Chipset ID en Décimale
//	char                chChipsetSnHex[17];                    	// Valeur du Chipset ID en Héxadécimal
//	char                chLibelleErreur[1024];                  // Libellé de l'erreur remonté en BDD
//	char            	chNumSerieNimCie[50];  					// Numero de série Cie du NIM
//	char            	chCodeNimCie[50];  						// Code Produit Cie du NIM
//	char            	chIndiceNimCie[50];  					// Indice Produit Cie du NIM
///	char            	chLibelleNimCie[50];  					// Libelle Cie du NIM
	//char               NomRessourceSAPME[TAILLE_MAX];      // Nom de la ressource utilisée par SAP ME pour effectuer les opérations start/complete etc.
//	char                DFAfille[TAILLE_MIN];					// DFA carte fille
//	char                CiuSfcFilleSAPME[TAILLE_MIN];          	// Numéro de série de la carte fille (SFC sur gamme CMS/CIE) ==> rattaché au code produit CIE.
	char                OrdreFabFilleSAPME[TAILLE_MIN];         // Ordre de fabrication de la carte fille ==> rattaché au code produit CIE.
	char                CodePrdtFilleSAPME[TAILLE_MIN];         // Code produit de la carte fille ==> rattaché au code produit CIE.
	char                IndicePrdtFilleSAPME[TAILLE_MIN];       // Indice produit de la carte fille ==> rattaché au code produit CIE.
	char                chDFA[TAILLE_MIN];
//	char                OxNumSerie[TAILLE_MIN];
	char                Nom_Operation[TAILLE_MIN];
	char                Non_Confirmite[TAILLE_MIN];
	char	            chCodeProduit[64];
	char				NumeroSlot[64] ;
    

} T_VARIABLES_TRACA;

// Structure des commandes TT avec retour
// --------------------------------------
/*typedef struct 
{
	char	cmd[TAILLE_MIN];							// Commande TT à envoyer
	char	pass[REP_TT_NB_MAX][TAILLE_MIN];			// Réponses attendus OK
	int		nbPass;											// Nombre Réponses attendus OK
	char	fail[REP_TT_NB_MAX][TAILLE_MIN];			// Réponses attendus KO
	int		nbFail;											// Nombre Réponses attendus KO
	char	info[REP_TT_NB_MAX][TAILLE_MIN];			// Réponses attendus infos
	int		nbInfo;											// Nombre Réponses attendus infos
} T_CMD_TT;

// Structure des commandes TT avec retour
// --------------------------------------
typedef struct 
{
	T_CMD_TT	cmd[CMD_TT_NB_MAX];							// Tableau de commande TT à jouer
	int			nbCmd;										// Nombre de commande TT à jouer
} T_TAB_CMD_TT;
*/
// Structure d'une commande avec retour
typedef struct 
{
	int  nbPass;                   				   // Nombre Réponses attendus OK 
	int  nbFail;								   // Nombre Réponses attendus KO 
	int  nbTags;                   				   // Nombre Réponses attendus TAG 
	int  nbInfo;                   				   // Nombre Réponses attendus infos                                 
	int  nTimeOut;                 				   // Time de la réponse en secondes (vaut -1 si pas définis)        
	char cmd[500];                 				   // Commande TT à envoyer
    char pass[10][500];            				   // Réponses attendus OK
    char fail[10][256];            				   // Réponses attendus KO
    char Tags[10][256];            				   // Réponses attendus TAG
    char info[10][256];            				   // Réponses attendus infos
} T_CMD;

// Structure d'une chaine de commandes 
typedef struct 
{
    int     nbCmd;                     			  // Nombre de commande TT à jouer             
	T_CMD   cmd[20];                   			  // Tableau de commande TT à jouer
} T_TAB_CMD;



// Structure des commandes COM avec retour
// ---------------------------------------
/*typedef struct 
{
    int     nbPass;                                             // Nombre Réponses attendus OK
    int     nbFail;                                             // Nombre Réponses attendus KO
    int     nbInfo;                                             // Nombre Réponses attendus infos
    int     nTimeOut;                                           // Time de la réponse en secondes (vaut -1 si pas définis)
    char    cmd[TAILLE_MIN];                               // Commande TT à envoyer
    char    pass[REP_TT_NB_MAX][TAILLE_MIN];               // Réponses attendus OK
    char    fail[REP_TT_NB_MAX][TAILLE_MIN];               // Réponses attendus KO
    char    info[REP_TT_NB_MAX][TAILLE_MIN];               // Réponses attendus infos
} T_CMD;

*/
// Structure de Bouton
// ---------------------------------------
typedef struct 
{
	
	char   gchAdressIP[100];
    char   gInstrumentID[100];
    char   gPwrmetterType[100];
	char   gchAdressIPSwitchRFSP8T[100];
	char   gchAdressBlocSwitchRFSP8T[100];
	int    gFlagSP8T;
	float  gchTimeOutSwitchRF;
	int    gchFlagTraca;
	//int    gnumPortcaisson ;
	
} T_BNFT;

char Pathloss_2G[20][3]; 
char Pathloss_5G[20][3]; 
char Pathloss_DECT[20][3];
char Pathloss_BT[20][3];
char fichpathloss_2G[10000];
char fichpathloss_5G[10000];
char fichpathloss_BT[10000];
char fichpathloss_dect[10000];
char sVersionSoft[1024];

// Structure des commandes COM avec retour
// ---------------------------------------
/*typedef struct 
{
    int     nbCmd;                                              // Nombre de commande TT à jouer
    T_CMD   cmd[CMD_TT_NB_MAX];                                 // Tableau de commande TT à jouer
} T_TAB_CMD;
  */
#endif	// #ifndef __MAIN_H__
