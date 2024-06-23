// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//  
// 
// ==============================================================================
//   PROJET			: Banc HDD
//   MODULE			: Define
//   PROCESSEUR		: INTEL Pentium
//   ENVIRONNEMENT	: Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION	: Définition du projet
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


#ifndef DEFINE_H_
	#define DEFINE_H_

	// Général
	#define NBRE_INTERFACE		1					// nombre des slots

	#define SLOT_1				1					// Slot 1
	#define SLOT_2				2					// Slot 2
	#define SLOT_3				3					// Slot 3
	#define SLOT_4				4					// Slot 4
	#define SLOT_5				5					// Slot 5
	#define SLOT_6				6					// Slot 6
	#define SLOT_7				7					// Slot 7
	#define SLOT_8				8					// Slot 8
	#define SLOT_9				9					// Slot 9
	#define SLOT_10				10					// Slot 10
	#define SLOT_11				11					// Slot 11
	#define SLOT_12				12					// Slot 12
	#define SLOT_13				13					// Slot 13
	#define SLOT_14				14					// Slot 14
	#define SLOT_15				15					// Slot 15
	#define SLOT_16				16					// Slot 16
	
    #define OK					1					// OK
	#define KO					0					// KO
	#define OUI					1					// OUI
	#define NON					0					// NON
	
	// Chaines de caractères
	#define TAILLE_MAX_CHAINE   20000				// Taille maxi d'une chaine de caractere
	#define TAILLE_MSG_ERR_MAX	2048				// Taille maxi d'une chaine de caractere

	// Pour analyse fichier ".ini"
	#define S_GENERAL			"[GENERAL]"			// Section général
	#define S_SIGNAUX			"[SIGNAUX]"			// Section signaux
	#define SERVEUR_SQL			"serveur_SQL"		// Nom du serveur SQL
	
	// Noms des signaux
	#define NOM_SIGNAL			"ITFE%1d_%s"

	// Déclaration dans le fichier INI
	#define L_PRESENCE			"L_PRESENCE"			// Nom du signal de présence du HDD sur le slot
	#define LED_ROUGE			"L_ROUGE"				// Nom du signal de commande de la led rouge
	#define LED_VERTE			"L_VERTE"				// Nom du signal de commande de la led verte
	#define L_VERROU_OUT		"L_VERROU"				// Nom du signal de commande du bloquage du verrou
	#define L_PATIN1			"L_PATIN1"				// Nom du signal de présence du patin 1
	#define L_PATIN2			"L_PATIN2"				// Nom du signal de présence du patin 2
	#define L_PATIN3			"L_PATIN3"				// Nom du signal de présence du patin 3
	#define L_PATIN4			"L_PATIN4"				// Nom du signal de présence du patin 4

	// RS232
	#define TAILLE_BUFF_RS232	4096					// Taille buffer RS232

	// Tests HDD
	#define CLES_HDD_LONG_MAX				16
	#define CLES_TRAITE_HDD_LONG_MAX		8 
	#define PWD_HDD_LONG_MAX				32
	#define PWD_TRAITE_HDD_LONG_MAX 		8
	#define COPIE_DU_PWD_3					16
	#define COPIE_DU_PWD_4					24
	#define TIMEOUT							10.0
	#define LOCKE							"OUI" 
	#define VIDE							""
	#define STR_OK							"OK"
	#define TAILLE_PRODUIT_REFSAGEM			20
	#define TAILLE_BUFFER					4096
	#define TAILLE_TRACE					50
	#define TAILLE_SNHDD					20

	#define	DUREE_TEST_HDD					125
	#define TIMEOUT_TEST_HDD				180
	#define TAUX_TRANSFERT_ECRITURE			40
	#define TAUX_TRANSFERT_LECTURE			40
	#define PERFORMANCE_FILENAME			"testpattern.tst"
    #define TCP_PARAM_BLANK		            "                                 "

	// Taille max des chaines infos traca
	#define PRINT_INFO_TAILLE_MAX           16384

	// Définition des type de transactions pour le banc
	#define MVT_TEST_TRANS_BANC				"TELECHARGE"
	#define MVT_TEST_RESTART_PROCESS		"RESTART_PROCESS" 

	// Code autorisation de passage
	#define ALLER_AU_DEPANNAGE				-5
	#define ALLER_A_EMBALLAGE				0

	// Définition des status NUM SERIE
	// -------------------------------
	#define SN_STATUS_VALIDE                "VALIDE"


	// Définiton des types de liens entre SN SIE et SFIN
	// -------------------------------------------------
	#define SN_TYPE_LIEN                    "ENCOURS"

	#define ERR					0					// Message d'erreur 
	// Noms des signaux
	#define NOM_SIGNAL                      "ITFE%1d_%s"
	#define ALIM              				"ALIM"    					// Nom du signal de commande de l'alim             
	#define PISTON              			"PISTON"    				// Nom du signal de commande du piston
	#define VERROU_FLASH_ALIM               "VERROU_FLASH_ALIM"			// Nom du signal de commande pour vérouillage flash par application 5V grace aux aiguilles montées sur le piston
	#define L_PATIN_1                       "L_PATIN_1"             	// Nom du signal de présence du patin 1
	#define L_PATIN_2                       "L_PATIN_2"             	// Nom du signal de présence du patin 2 
	#define L_PATIN_3                       "L_PATIN_3"             	// Nom du signal de présence du patin 3 
	#define L_PATIN_4                       "L_PATIN_4"             	// Nom du signal de présence du patin 4
	#define L_PATIN_5                       "L_PATIN_5"             	// Nom du signal de présence du patin 5
	#define L_VIS_1                         "L_VIS_1"               	// Nom du signal de présence de la vis 1
	#define L_VIS_2                         "L_VIS_2"               	// Nom du signal de présence de la vis 2
	#define L_VIS_3                         "L_VIS_3"               	// Nom du signal de présence de la vis 3
	#define L_VIS_4                         "L_VIS_4"               	// Nom du signal de présence de la vis 4
	#define L_VENTILO_ALENDROIT				"L_VENTILO_ALENDROIT"		// Nom du signal de présence du ventilo
	#define L_VENTILO_ALENVERS				"L_VENTILO_ALENVERS"		// Nom du signal de sens du ventilo
	#define L_VERROU_IN                     "L_VERROU_IN"           	// Nom du signal de présence du verrou
	#define L_PRESENCE                       "L_PRESENCE"             	// Nom du signal de présence du décodeur
	#define L_VERROU_OUT                    "L_VERROU_OUT"          	// Nom du signal de commande du bloquage du verrou
	#define L_COULEUR_1                     "L_COULEUR_1"          		// Nom du signal de présence du capteur de couleur 1
	#define PRES_DECO                       "L_PRESENCE"             	// Nom du signal de présence du décodeur

	#define L_VReset                        "L_VReset"               	// Nom du signal de présence de la verrin 1
	#define L_VOK                           "L_VOK"               	// Nom du signal de présence de la verrin 2
	#define L_VWifi                         "L_L_VWifi"               	// Nom du signal de présence de la verrin 3
	#define L_VPairing                      "L_VPairing"               	// Nom du signal de présence de la verrin 4
	#define L_VSConnectique                 "L_VSConnectique"               	// Nom du signal de présence de la verrin 5
	#define L_VEConnectique                 "L_VEConnectique"               	// Nom du signal de présence de la verrin 5
	
	#define L_VOFF                          "L_VOFF"               	// Nom du signal de présence de la verrin 6
	#define L_VERIN_7                       "L_VERIN_7"               	// Nom du signal de présence de la verrin 7
	#define L_VMembrane                     "L_VMembrane"               	// Nom du signal de présence de la verrin 8

	#define L_VERIN_9                       "L_VERIN_9"               	// Nom du signal de présence de la verrin 9
	#define L_VEMoteur                      "L_VEMoteur"               	// Nom du signal de présence de la verrin 10
	#define L_VSMoteur                      "L_VSMoteur"               	// Nom du signal de présence de la verrin 11



    #define L_PRESENCE2 					"L_PRESENCE2"				// Nom du signal de présence2 du décodeur




	//#define L_MEMBRANE_1                    "L_MEMBRANE_1"              // Nom du signal de présence de la MEMBRANE 1


	#define L_ROUGE                       	"L_ROUGE"               	// Nom du signal de présence de la ROUGE
	#define L_VERTE                       	"L_VERTE"               	// Nom du signal de présence de la VERTE
	#define L_JAUNE                       	"L_JAUNE"               	// Nom du signal de présence de la JAUNE

	// Boutons
	#define NB_MAX_BOUTON                   14                      	// Définition du nombre de bouton max en face avant du décodeur
	#define LG_MAX_TAG_BOUTON				16							// Longueur max du tag de retour bouton


  	#define MODE_POPUP_INFO				0
	#define MODE_POPUP_ERREUR			1
	#define MODE_POPUP_TRACE			2
	#define ERREUR_ALLOC_RESOURCE 		0
	#define ERREUR_OTHER_INSTANCE 		1
	#define ERREUR_INI					2
	#define ERREUR_GEST_SEQ_OPEN		3
	#define ERREUR_GEST_SEQ_READ		4
	#define ERREUR_BASE_DE_REGISTRE		5
	#define ERREUR_BASE_DE_TRACA		6
	#define ERREUR_SEQ_APPAIRAGE_OPEN	7
	#define ERREUR_CONFIG_IP_CARTE_ETH	8
	#define ERREUR_SEQ_APPAIRAGE_RAZ	9


	#define PROD_PROV3					0
	#define PROD_DTAG					1 
	#define PROD_LVB3					3



	#define NOM_PROCESS                 "tftpd32.exe"
	# define MaxTimeDownloadTftp		300


	//erreur Telnet

	#define ERREUR_TELNET_OUVERTURE 			-100
	#define ERREUR_TELNET_FERMETURE 			-101
	#define ERREUR_TELNET_LOGIN 				-102
	#define ERREUR_TELNET_PASSWORD 				-103
	#define ERREUR_TELNET_ECRITURE 				-104
	#define ERREUR_TELNET_LECTURE 				-105
	#define ERREUR_TELNET_LECTURE_DFA 			-106 


	#define TAILLE_MOY           	2048                        // taille max de la commande envoyée au décodeur
	#define TAILLE_MAX            	50000
	#define CMD_LONG_MAX                 	50000
	#define FCT_RECUP_INFO_TAILLE_MAX	4096        

#endif /*DEFINE_H_*/   
