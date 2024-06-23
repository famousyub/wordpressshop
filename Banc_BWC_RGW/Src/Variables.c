// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//
//
// ==============================================================================
//   PROJET			: Banc HDD
//   MODULE			: Variables
//   PROCESSEUR		: INTEL Pentium
//   ENVIRONNEMENT	: Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION	: Gestion des variables de configuration du décodeur.
//
// ==============================================================================
//   REMARQUES		:
//					  NOM VARIABLE : ttt_BBB_fNn...n
//
//						ttt = Type (minuscule)
//						    conf : variable de configuration
//						    etat : variable d'état
//						    inst : variable d'instrument
//
//						  BBB = Banc (majuscule)
//						    BFE : Banc Front End
//						    BAV : Banc Audio Video
//						    BPO : Banc Personnalisation
//						    GEN : Variable générique
//						    PAL : Poste palettisation
//
//						  f =   Format (minuscule)
//						    b : Booléen
//						    i : entier 32 bits signé
//						    f : flottant 32 bits
//						    s : chaine de caractères
//
//						  Nn...n = Nom de la variable (minuscule sauf 1ere letre)
//
//						  Exemples :
//						   conf_DEC_BPO_sTermTech
//						   conf_DEC_BPO_bFlagLockCryptocore
//						   conf_DEC_BPO_iNombreBoutons
//						   conf_DEC_BPO_sAdrHdcp
//						   conf_DEC_BPO_bFlagCleNvm
//						   conf_DEC_BPO_sCdeTTTestUsb
//
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

// ------------------------------------------------------------
// DEFINITION DES VARIABLES DE CONFIGURATION POUR LE BANC HDD
// ------------------------------------------------------------
// /!\ LES VARIABLES DOIVENT ETRE DEFINIS DANS LE TABLEAU
// 	   DANS LE MEME ORDRE DE DEFINITION DES INDEX (T_VAR_INDEX)
// ------------------------------------------------------------
// /!\ LES VARIABLES PARENTES DOIVENT ETRE DEFINIS DANS LE
//	   TABLEAU AVANT LES VARIABLES FILLES
// ------------------------------------------------------------
//
// AJOUT D'UNE VARIABLE :
// --------------------
//
//	1. Recopier la ligne entière de la dernière variable en
//	   fin de tableau,
//
//	2. Modifier les champs suivants :
//
//		a. 'INDEX' : Définir le nom de l'index de la variable
//					 (commençant par 'VAR_CONF_ID_').
//
//		b. 'NOM' : Renseigner le nom de la variable tel que
//				   définit dans TracaCom.
//
//		c. 'TYPE' : Définir le type de la variable.
//
//		d. 'OPTIONNELLE' : Définir si la définition de la
//						   variable en BDD est obligatoire.
//
//		e. 'PARENTS' : Définir les variables parentes pour
//					   lesquelles la définition de la variable
//					   peut être utile.
//
//	3. Ajouter l'index de la variable à la fin de l'énumération
//	   'T_VAR_CONF_INDEX'.
//
//
// UTILISATION D'UNE VARIABLE :
// --------------------------
//
//	1. LECTURE :
//	   ~~~~~~~
//		VAR_GET_<TYPE> (v,x,i)
//		(avec <TYPE> = BOOL ou STRING ou SINT8 ou UINT8 ou
//		 SINT16 ou UINT16 ou SINT32 ou UINT32 ou FLOAT)
//
//		Exemples :
//		strcpy ( chaine, VAR_GET_STRING(gVariablesConf,VAR_ID_LOADER,0)  )
//		if ( VAR_GET_BOOL(gVariablesConf,VAR_CONF_ID_LOT_PALETTE,0) == TRUE )
//
//	1. ECRITURE :
//	   ~~~~~~~~
//		VAR_SET_<TYPE> (v,x,i)
//		(avec <TYPE> = BOOL ou STRING ou SINT8 ou UINT8 ou
//		 SINT16 ou UINT16 ou SINT32 ou UINT32 ou FLOAT)
//
//		Exemples :
//		strcpy ( VAR_SET_STRING(gVariablesConf,VAR_ID_LOADER,0), chaine )
//		VAR_SET_BOOL(gVariablesConf,VAR_CONF_ID_LOT_PALETTE,0) = TRUE
//
// ------------------------------------------------------------
T_VARIABLE gVariablesConf[] =
//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ --------
// |            INDEX               			|           NOM                         |    DESCRIPTION    |    TYPE     |OPTIONNELLE|  PARENTS  | VALEUR | NB VALEUR | IDENTIFIANT | UNIQUE |
//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ --------
{
	{  VAR_CONF_GTW_BWC_login,                    "conf_GTW_BWC_login",                  "",	"",	"",		  VAR_TSTRING,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_FLAG_Eth,                 "flag_GTW_BWC_Eth",                    "",	"",	"",		  VAR_TUINT8,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_FLAG_LOGIN,               "flag_GTW_BWC_login",                  "",	"",	"",		  VAR_TUINT8,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_Version,                  "conf_GTW_BWC_Version_Application",    "",	"",	"",		  VAR_TSTRING,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_FLAG_DFA_MERE,       	  "flag_GTW_BWC_Flag_Lecture_DFA_MERE",  "",	"",	"",		  VAR_TUINT8,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_Lecture_DFA_MERE,         "conf_GTW_BWC_Lecture_DFA_MERE",       "",	"",	"",		  VAR_TSTRING,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_Nombre_Char_DFA_MERE,     "conf_GTW_BWC_Nombre_Char_DFA_MERE",   "",	"",	"",		  VAR_TUINT8,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_TAG_DFA_MERE,          	  "conf_GTW_BWC_Tag_DFA_MERE",           "",	"",	"",		  VAR_TSTRING,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_Nom_Produit,              "conf_GTW_BWC_Nom_Produit",            "",	"",	"",		  VAR_TSTRING,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_PROMPT_DUT,               "conf_DEC_BWC_sPromptDetection",       "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_LECTURE_SN,           "conf_DEC_GEN_sCdesTT.DisplaySnCIE",   "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_LECTURE_VERSION,      "conf_DEC_BWC_sCdesTT.Version_TT",     "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_INITIALISATION,       "conf_DEC_BWC_CMD_INITIALISATION",     "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_FINALISATION,         "conf_DEC_BWC_CMD_FINALISATION",       "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_RECUP_SN,         	  "conf_DEC_BWC_CMD_RECUPERATION_SN",    "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_RECUP_TT,         	  "conf_DEC_BWC_CMD_RECUPERATION_TT",    "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_Interface_Eth_DUT,    "conf_DEC_BWC_CMD_Interface_Eth_DUT",  "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_Interface_IP_DUT,     "conf_DEC_BWC_CMD_Interface_IP_DUT",   "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_Check_Driver_2Ghz,    "conf_DEC_BWC_CMD_Check_Driver_2Ghz",  "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_Check_Driver_5Ghz,    "conf_DEC_BWC_CMD_Check_Driver_5Ghz",  "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_Check_Driver_6Ghz,    "conf_DEC_BWC_CMD_Check_Driver_6Ghz",  "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_Check_Driver_BT,      "conf_DEC_BWC_CMD_Check_Driver_BT",    "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_Update_Driver_2Ghz,   "conf_DEC_BWC_CMD_Update_Driver_2Ghz", "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_Update_Driver_5Ghz,   "conf_DEC_BWC_CMD_Update_Driver_5Ghz", "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_Update_Driver_6Ghz,   "conf_DEC_BWC_CMD_Update_Driver_6Ghz", "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_Update_Driver_BT,     "conf_DEC_BWC_CMD_Update_Driver_BT",   "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_Check_Update_Driver_2Ghz,  "conf_DEC_BWC_CMD_Check_Update_Driver_2Ghz",                   "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_Check_Update_Driver_5Ghz,  "conf_DEC_BWC_CMD_Check_Update_Driver_5Ghz",                   "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_Check_Update_Driver_6Ghz, "conf_DEC_BWC_CMD_Check_Update_Driver_6Ghz",                   "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_Check_Update_Driver_BT,"conf_DEC_BWC_CMD_Check_Update_Driver_BT",                   "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_ChipID,               "conf_DEC_BWC_CMD_CHIPSET_ID",         "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_CMD_TEST_2Ghz,            "conf_GTW_BWC_Cmd_test_2Ghz",          "",	"",	"",		  VAR_TSTRING,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_CMD_TEST_5Ghz,            "conf_GTW_BWC_Cmd_test_5Ghz",          "",	"",	"",		  VAR_TSTRING,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_EXIT_2Ghz,            "conf_DEC_BWC_CMD_EXIT_2Ghz",          "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_CMD_TEST_BT,              "conf_GTW_BWC_Cmd_test_BT",            "",	"",	"",		  VAR_TSTRING,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_PATH_SCRIPT_2GHZ,         "conf_GTW_BWC_Path_script_2GHZ",       "",	"",	"",		  VAR_TSTRING,	  0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,         "conf_GTW_BWC_Path_script_5GHZ",       "",	"",	"",		  VAR_TSTRING,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,         "conf_GTW_BWC_Path_script_6GHZ",       "",	"",	"",		  VAR_TSTRING,	  0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_PATH_SCRIPT_BT,           "conf_GTW_BWC_Path_script_BT",         "",	"",	"",		  VAR_TSTRING,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_CMD_PING_DUT,             "conf_DEC_BWC_CMD_PING_DUT",           "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_CMD_TEST_6Ghz,            "conf_GTW_BWC_Cmd_test_6Ghz",          "",	"",	"",		  VAR_TSTRING,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_FLAG_Initialisation,      "conf_DEC_BWC_FLAG_INITIALISATION",    "",	"",	"",		  VAR_TUINT8,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_FLAG_Finalisation,        "conf_DEC_BWC_FLAG_FINALISATION",      "",	"",	"",		  VAR_TUINT8,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_FLAG_Update_Driver_2Ghz,  "conf_DEC_BWC_FLAG_Update_Driver_2Ghz","",	"",	"",		  VAR_TUINT8,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_FLAG_Update_Driver_5Ghz,  "conf_DEC_BWC_FLAG_Update_Driver_5Ghz","",	"",	"",		  VAR_TUINT8,	  1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_FLAG_Update_Driver_6Ghz,  "conf_DEC_BWC_FLAG_Update_Driver_6Ghz","",	"",	"",		  VAR_TUINT8,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_FLAG_Update_Driver_BT,    "conf_DEC_BWC_FLAG_Update_Driver_BT",  "",	"",	"",		  VAR_TUINT8,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_FLAG_ChipID,     	      "conf_DEC_BWC_FLAG_CHECK_CHIPSET_ID",  "",	"",	"",		  VAR_TUINT8,	  1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_Flag_test_2Ghz,     	  "flag_GTW_BWC_Flag_test_2Ghz",         "",	"",	"",		  VAR_TUINT8,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_FLAG_PING,     	          "flag_conf_DEC_BWC_FLAG_PING",         "",	"",	"",		  VAR_TUINT8,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_Flag_test_5Ghz,     	  "flag_GTW_BWC_Flag_test_5Ghz",         "",	"",	"",		  VAR_TUINT8,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_FLAG_TEST_BT,     	      "flag_GTW_BWC_Flag_test_BT",           "",	"",	"",		  VAR_TUINT8,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_FLAG_EXIT_2Ghz,     	  "conf_DEC_BWC_FLAG_EXIT_2Ghz",         "",	"",	"",		  VAR_TUINT8,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_GTW_BWC_Flag_test_6Ghz,     	  "flag_GTW_BWC_Flag_test_6Ghz",         "",	"",	"",		  VAR_TUINT8,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_FLAG_TEST_check_driver_BT,"flag_DEC_BWC_FLAG_TEST_check_driver_BT",                        "",	"",	"",		  VAR_TUINT8,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_DEC_BWC_FLAG_Check_Driver_5Ghz,   "flag_conf_DEC_BWC_FLAG_Check_Driver_5Ghz",                        "",	"",	"",		  VAR_TUINT8,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{ VAR_CONF_DEC_BWC_FLAG_Check_Driver_2Ghz,    "flag_conf_DEC_BWC_FLAG_Check_Driver_2Ghz",                        "",	"",	"",		  VAR_TUINT8,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{ VAR_CONF_DEC_BWC_Test_tampon,       	      "conf_DEC_BWC_Test_tampon",            "",	"",	"",		  VAR_TUINT8,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},
	
	{  VAR_CONF_GTW_BWC_FLAG_sfc,                          "conf_GTW_BWC_FLAG_sfc",          "",	"",	"",		  VAR_TUINT8,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	}, 
	
	{  VAR_CONF_GTW_BWC_Gravage_DFA,              	"conf__GTW_BWC_InsertCIE",            	         "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	}, 
	
	{  VAR_CONF_GTW_BWC_CMD_Activation_DHCP,      "conf_GTW_BWC_CMD_Activation_DHCP",            	         "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	}, 
	
	{  VAR_CONF_GTW_BWC_CMD_Desactivation_DHCP,    "conf_GTW_BWC_CMD_Desactivation_DHCP",            	         "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	}, 
	
	{  VAR_CONF_GTW_BWC_CMD_Rmonte_SFTP,           "conf_GTW_BWC_CMD_Rmonte_SFTP",            	         "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	}, 

	{  VAR_CONF_GTW_BWC_FLAG_DHCP,     	      "flag_GTW_BWC_Flag_DHCP",           "",	"",	"",		  VAR_TUINT8,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},
	
	{  VAR_CONF_GTW_BWC_FLAG_REMONTE_SFTP,     	      "flag_GTW_BWC_Flag_REMONTE_SFTP",           "",	"",	"",		  VAR_TUINT8,	   0, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},
};


// Nombre de variable dans le tableau
// ----------------------------------
const int gNbVariablesConf = (int)(sizeof(gVariablesConf) / sizeof(T_VARIABLE));

// ------------------------------------------------------------
T_VARIABLE gVariablesConfPoste[] =
//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ --------
// |            INDEX               			|           NOM                         |    DESCRIPTION    |    TYPE     |OPTIONNELLE|  PARENTS  | VALEUR | NB VALEUR | IDENTIFIANT | UNIQUE |
//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ --------
{

	{  VAR_POSTE_DEC_BNFT_Offset_Antennes_2G_S0,       		"poste_DEC_BNFT_Offset_Antennes_2G_S0",    "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_POSTE_DEC_BNFT_Offset_Antennes_5G_S0,       		"poste_DEC_BNFT_Offset_Antennes_5G_S0",    "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_POSTE_DEC_BNFT_Offset_Antennes_BT_S0,       		"poste_DEC_BNFT_Offset_Antennes_BT_S0",    "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},


	{  VAR_CONF_POSTE_ID_OFFSET_2G_S0,       		        "conf_poste_GTW_BNFT_Offset_Antennes_2G_S0",    "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_POSTE_ID_OFFSET_2G_S1,       		        "conf_poste_GTW_BNFT_Offset_Antennes_2G_S1",    "",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_POSTE_ID_OFFSET_5G_S0,       		        "conf_poste_GTW_BNFT_Offset_Antennes_5G_S0",   	"",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_POSTE_ID_OFFSET_5G_S1,       		        "conf_poste_GTW_BNFT_Offset_Antennes_5G_S1",   	"",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_POSTE_ID_OFFSET_DECT_S0,       		        "conf_poste_GTW_BNFT_Offset_Antennes_DECT_S0",   	"",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},

	{  VAR_CONF_POSTE_ID_OFFSET_DECT_S1,       		        "conf_poste_GTW_BNFT_Offset_Antennes_DECT_S1",   	"",	"",	"",		  VAR_TSTRING,	   1, 		{-1,-1,-1},  NULL,  	0,			 0,			  0	},


};


// Nombre de variable dans le tableau
// ----------------------------------
const int gNbVariablesConfPoste = (int)(sizeof(gVariablesConfPoste) / sizeof(T_VARIABLE));



// Définition des variables de configuration pour le banc Perso liées à un SN
// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
// DEFINITION DES VARIABLES DE CONFIGURATION POUR LE BANC PERSO LIEES A UN SN
// --------------------------------------------------------------------------
// /!\ LES VARIABLES DOIVENT ETRE DEFINIS DANS LE TABLEAU
//     DANS LE MEME ORDRE DE DEFINITION DES INDEX (T_VAR_CONF_SN_INDEX)
// --------------------------------------------------------------------------
// /!\ LES VARIABLES PARENTES DOIVENT ETRE DEFINIS DANS LE
//     TABLEAU AVANT LES VARIABLES FILLES
// --------------------------------------------------------------------------
//
// AJOUT D'UNE VARIABLE :
// --------------------
//
//  1. Recopier la ligne entière de la dernière variable en
//     fin de tableau,
//
//  2. Modifier les champs suivants :
//
//      a. 'INDEX' : Définir le nom de l'index de la variable
//                   (commençant par 'VAR_ETAT_ID_').
//
//      b. 'NOM' : Renseigner le nom de la variable tel que
//                 définit dans TracaCom.
//
//      c. 'TYPE' : Définir le type de la variable.
//
//      d. 'OPTIONNELLE' : Définir si la définition de la
//                         variable en BDD est obligatoire.
//
//      e. 'PARENTS' : Définir les variables parentes pour
//                     lesquelles la définition de la variable
//                     peut être utile.
//
//  3. Ajouter l'index de la variable à la fin de l'énumération
//     'T_VAR_ETAT_IN_INDEX_CIU'.
//
// --------------------------------------------------------------------------
/*T_VARIABLE gVariablesProprietesSFCCie[] =
//  --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// |            INDEX               |           NOM                 |   DESCRIPTION |       TYPE        |   OPTIONNELLE   |     PARENTS         |               VALEUR                | NB VALEUR   | IDENTIFIANT |
//  --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{
 {  VAR_ETAT_ID_REFERENCE,              "etat_DEC_GEN_bFlagReference",          "",     "",        "", VAR_TBOOL,              1,      {-1,-1,-1},                                         NULL,           0,      0       },
 //{  VAR_ETAT_ID_SNNIM,              	"etat_DEC_GEN_sSnNIM",          		"",     "",        "", VAR_TSTRING,            1,      {-1,-1,-1},                                         NULL,           0,      0       },
 //{  VAR_ETAT_ID_BAV_SMI_CHIPSET_ID,    	"etat_DEC_BAV_sSmiChipsetId",      		"",     "",        "", VAR_TSTRING,            1,      {-1,-1,-1},                                         NULL,           0,      0       },
};*/

// Nombre de variable dans le tableau
// ----------------------------------
//const int gNbVariablesProprietesSFCCie = (int)(sizeof(gVariablesProprietesSFCCie) / sizeof(T_VARIABLE));



/*T_VARIABLE gVariablesProprietesSFCPfin[] =
//  --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// |            INDEX               |           NOM                 |   DESCRIPTION |       TYPE        |   OPTIONNELLE   |     PARENTS         |               VALEUR                | NB VALEUR   | IDENTIFIANT |
//  --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{
 {  VAR_ETAT_ID_BWI_NB_BAD_BLOCKS,    	"etat_DEC_BWI_iNbreBadBlocks",      	"",     "",        "", VAR_TUINT32,            1,      {-1,-1,-1},                                         NULL,           0,      0       },
 //{  VAR_ETAT_ID_BWI_NB_SPARE_BLOCKS,   	"etat_DEC_BWI_iNbreSpareBlocks",      	"",     "",        "", VAR_TUINT32,            1,      {-1,-1,-1},                                         NULL,           0,      0       },
};
*/
// Nombre de variable dans le tableau
// ----------------------------------
//const int gNbVariablesProprietesSFCPfin = (int)(sizeof(gVariablesProprietesSFCPfin) / sizeof(T_VARIABLE));


// -----------------------------------------------------------------
// DEFINITION DES VARIABLES D'ETAT POUR LE BANC PERSO
// -----------------------------------------------------------------
// /!\ LES VARIABLES DOIVENT ETRE DEFINIS DANS LE TABLEAU
// 	   DANS LE MEME ORDRE DE DEFINITION DES INDEX (T_VAR_ETAT_INDEX)
// -----------------------------------------------------------------
// /!\ LES VARIABLES PARENTES DOIVENT ETRE DEFINIS DANS LE
//	   TABLEAU AVANT LES VARIABLES FILLES
// -----------------------------------------------------------------
//
// AJOUT D'UNE VARIABLE :
// --------------------
//
//	1. Recopier la ligne entière de la dernière variable en
//	   fin de tableau,
//
//	2. Modifier les champs suivants :
//
//		a. 'INDEX' : Définir le nom de l'index de la variable
//					 (commençant par 'VAR_ETAT_ID_').
//
//		b. 'NOM' : Renseigner le nom de la variable tel que
//				   définit dans TracaCom.
//
//		c. 'TYPE' : Définir le type de la variable.
//
//		d. 'OPTIONNELLE' : Définir si la définition de la
//						   variable en BDD est obligatoire.
//
//		e. 'PARENTS' : Définir les variables parentes pour
//					   lesquelles la définition de la variable
//					   peut être utile.
//
//	3. Ajouter l'index de la variable à la fin de l'énumération
//	   'T_VAR_ETAT_INDEX'.
//
// -----------------------------------------------------------------
T_VARIABLE gVariablesEtat[] =
//  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// |            INDEX               |           NOM                 |       DESCRIPTION     |       TYPE        |   OPTIONNELLE   |     PARENTS         |               VALEUR                | NB VALEUR   | IDENTIFIANT | UNIQUE |
//  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{
	{  VAR_ETAT_ID_NUM_CENTRE,				"etat_DEC_BHD_iNumCentre",			"","","",   		VAR_TUINT32,			1, 					{-1,-1,-1}, 							NULL,  			0,				0,				0	},
	/*
	{  VAR_ETAT_ID_HDD_MODEL,				"etat_DEC_BHD_sHddModel",			"",				VAR_TSTRING,			0, 					{-1,-1,-1}, 							NULL,  			0,				0,				0	},
	{  VAR_ETAT_ID_HDD_HVN,				"etat_DEC_BHD_sHddHvn",				"",				VAR_TSTRING,			0, 					{-1,-1,-1}, 							NULL,  			0,				0,				0	},
	{  VAR_ETAT_ID_HDD_SIZE,				"etat_DEC_BHD_iHddSize",			"",				VAR_TUINT32,			0, 					{-1,-1,-1}, 							NULL,  			0,				0,				0	},
	{  VAR_ETAT_ID_FIRMWARE,				"etat_DEC_BHD_sFirmwareHdd",		"",				VAR_TSTRING,			0, 					{-1,-1,-1}, 							NULL,  			0,				0,				0	},
	{  VAR_ETAT_ID_CLIENT_SN,              "etat_DEC_BPO_sClientSn",           "",             VAR_TSTRING,            1,     				{-1,-1,-1},								NULL,           0,      		0,				0	},
	{  VAR_ETAT_ID_CODE_CONSTRUCTEUR,      "etat_DEC_BHD_sCodeConstructeur",   "",             VAR_TSTRING,            1,      			{-1,-1,-1},								NULL,           0,      		0,				0	},
	{  VAR_ETAT_ID_HIBUS_SERIAL,      		"etat_DEC_BHD_sHibusSerial",  		"",             VAR_TSTRING,            0,      			{-1,-1,-1},								NULL,           0,      		0,				0	},
	{  VAR_ETAT_ID_HDD_SERIAL,      		"etat_DEC_BHD_sHddSerial",  		"",             VAR_TSTRING,            0,      			{-1,-1,-1},								NULL,           0,      		0,				0	},
	{  VAR_ETAT_ID_HIBUS_FWVERSION,   		"etat_DEC_BHD_Hibus_FWVersion",		"",             VAR_TSTRING,            0,      			{-1,-1,-1},								NULL,           0,      		0,				0	},
	*/
};

// Nombre de variable dans le tableau
// ----------------------------------
const int gNbVariablesEtat = (int)(sizeof(gVariablesEtat) / sizeof(T_VARIABLE));


// --------------------------------------------------------------------------
// DEFINITION DES VARIABLES DE CONFIGURATION POUR LE BANC PERSO LIEES A UN SN
// --------------------------------------------------------------------------
// /!\ LES VARIABLES DOIVENT ETRE DEFINIS DANS LE TABLEAU
// 	   DANS LE MEME ORDRE DE DEFINITION DES INDEX (T_VAR_CONF_SN_INDEX)
// --------------------------------------------------------------------------
// /!\ LES VARIABLES PARENTES DOIVENT ETRE DEFINIS DANS LE
//	   TABLEAU AVANT LES VARIABLES FILLES
// --------------------------------------------------------------------------
//
// AJOUT D'UNE VARIABLE :
// --------------------
//
//	1. Recopier la ligne entière de la dernière variable en
//	   fin de tableau,
//
//	2. Modifier les champs suivants :
//
//		a. 'INDEX' : Définir le nom de l'index de la variable
//					 (commençant par 'VAR_CONF_ID_').
//
//		b. 'NOM' : Renseigner le nom de la variable tel que
//				   définit dans TracaCom.
//
//		c. 'TYPE' : Définir le type de la variable.
//
//		d. 'OPTIONNELLE' : Définir si la définition de la
//						   variable en BDD est obligatoire.
//
//		e. 'PARENTS' : Définir les variables parentes pour
//					   lesquelles la définition de la variable
//					   peut être utile.
//
//	3. Ajouter l'index de la variable à la fin de l'énumération
//	   'T_VAR_CONF_SN_INDEX'.
//
// --------------------------------------------------------------------------
T_VARIABLE gVariablesConfSn[] =
//  --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// |			INDEX	 			|			NOM	 				|	DESCRIPTION	|		TYPE		|	OPTIONNELLE	  |		PARENTS	  		|				VALEUR				  |	NB VALEUR	| IDENTIFIANT |
//  --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{

	{  VAR_CONF_ID_REFERENCE,			"etat_DEC_GEN_bReference",		"", "", "",				VAR_TBOOL,				1, 				{-1,-1,-1}, 						NULL,  					0,				0		},


};

// Nombre de variable dans le tableau
// ----------------------------------
const int gNbVariablesConfSn = (int)(sizeof(gVariablesConfSn) / sizeof(T_VARIABLE));


// ==============================================================================
// DECLARATION DES FONCTIONS
// ==============================================================================

// ==============================================================================
// FONCTION : 	  VAR_Get
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int VAR_Get ( 	T_VARIABLE *tVariablesModele,
//									int nbVariablesModele,
//									T_VARIABLES *tVariables,
//									hdleTCom instTracaCom,
//									char *numSerie,
//									char *codeProduit,
//									char *indiceProduit,
//									char *nomPoste,
//									char *strErreurMessage)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_VARIABLES *tVariablesModele	: Tableau de variables modele,
//				  - int 		nbVariablesModele	: Taille du tableau modele,s
//				  - T_VARIABLES *tVariables 		: Tableau de variables,
//				  - hdleTCom 	instTracaCom		: Handle sur la base TracaCom,
//				  - char 		*numSerie			: Numéro de série du STB,
//				  - char 		*codeProduit		: Code produit,
//				  - char 		*indiceProduit		: Indice produit,
//				  - char 		*nomPoste			: Nom poste,
//				  - char 		*strErreurMessage	: Message d'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Extraction des variables de configuration de la Base de données.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :		1.1.0
//  DATE :			15/12/2009
//  AUTEUR :		EAH
//  DESCRIPTION :	Création issue de la personnalisation STB
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	   S09014AC15
//  DATE :		   23/12/2010
//  AUTEUR :	   MBH
//  DESCRIPTION :  Allocation mémoire apres la requete en BDD
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int VAR_Get ( T_VARIABLE *tVariablesModele, int nbVariablesModele, T_VARIABLES *tVariables, hdleSCProd 	instSCProduction, char *numSerie, char *codeProduit, char *indiceProduit, char *nomPoste, char *strErreurMessage )
{
	char    **tabVariables = NULL;
	char    *tcomErreur = NULL;
	char    *tcomErreurRequete = NULL;
	int     blnErreurSurvenue = -1;
	int     intErreurCode;
	int     tabVariablesLength1 = 0;
	int     tabVariablesLength2 = 0;
	int     error = 0;
	char    chMess[512] = {'\0'};
	int     idxVariableIn;
	int     idxVariableOut = 0;
	int     idxParent;
	int     varFound = 0;
	int     parentFound = 0;            // Flag infdiquant que la variable parente est définie
	int     parentPresent = 0;          // Flag indiquant qu la variable posséde une variable parente
	int 	ii;
	int 	iBcleFree;

	// ==========================================
	// = Initialisation des variables de retour =
	// ==========================================
	strErreurMessage[0] = '\0';

	// ========================================================
	// = Extraction des variables de configuration de la base =
	// ========================================================
	if ( numSerie != NULL && nomPoste != NULL )
	{
		// On extrait les variables liées à tous les STB du produit
		// --------------------------------------------------------

		// Lock BDD
		// --------
		if (LOCK_BDD == 1)
			CmtGetLock (IdLockBDD);

		SCProduction_GestionProductions_RecuperationProprietesParPoste(
			instSCProduction,
			codeProduit,
			indiceProduit,
			nomPoste,
			&tabVariables,
			&tabVariablesLength1,
			&tabVariablesLength2,
			&blnErreurSurvenue,
			&intErreurCode,
			&tcomErreur,
			&tcomErreurRequete,
			NULL);

		// Unlock BDD
		// --------
		if (LOCK_BDD == 1)
			CmtReleaseLock (IdLockBDD);

		// Verification pointeurs non nuls => en cas de sortie de la fct en time out
		// -------------------------------------------------------------------------
		if ( tcomErreur == NULL || tcomErreurRequete == NULL )
			errChk(TCOM_ERREUR_RESEAU);
	}
	else  if (numSerie == NULL && nomPoste != NULL)
	{
		// On extrait les variables liées à un nom de poste
		// ------------------------------------------------
		SCProduction_GestionProductions_RecuperationPosteVariables(
			instSCProduction,
			nomPoste,
			&tabVariables,
			&tabVariablesLength1,
			&tabVariablesLength2,
			&blnErreurSurvenue,
			&intErreurCode,
			&tcomErreur,
			&tcomErreurRequete,
			NULL);

	}

	else
	{
		MessagePopup ("Erreur initialisation", "On ne peut faire un appel à VAR_Get avec à la fois un nom de poste et un numserie");
		errChk(-1);
	}

	// Vérification des erreurs de la fonction
	// ---------------------------------------
	if (blnErreurSurvenue)
		errChk (-1);


	// =====================================
	// = Allocation du tableau de valeurs  =
	// = Si un modèle est défini en entrée =
	// =====================================
	if (tVariablesModele != NULL)
	{
		tVariables->variables = (T_VARIABLE*)malloc ( sizeof(T_VARIABLE) * nbVariablesModele );
		tVariables->nbVariables = nbVariablesModele;
	}

	// ================================================================
	// = Extraction des variables de configuration pour le banc Perso =
	// ================================================================
	for ( idxVariableOut=0 ; idxVariableOut<tVariables->nbVariables ; idxVariableOut++ )
	{
		// RAZ du flag indiquant que la variable est trouvée
		// -------------------------------------------------
		varFound = 0;

		// Recopie des paramètres de la variable
		// Si un modèle est défini en entrée
		// -------------------------------------
		if (tVariablesModele != NULL)
		{
			tVariables->variables[idxVariableOut].index = idxVariableOut;
			strcpy ( tVariables->variables[idxVariableOut].nom, tVariablesModele[idxVariableOut].nom);
			if (strcmp (gChNomProduit,"")!=0)
			{
				sprintf(tVariables->variables[idxVariableOut].nom,"%s_%s",tVariablesModele[idxVariableOut].nom,gChNomProduit);
			}


			strcpy ( tVariables->variables[idxVariableOut].nomtest, tVariablesModele[idxVariableOut].nomtest);
			strcpy ( tVariables->variables[idxVariableOut].description, "");
			strcpy ( tVariables->variables[idxVariableOut].chValeur, "");
			tVariables->variables[idxVariableOut].type = tVariablesModele[idxVariableOut].type;
			tVariables->variables[idxVariableOut].optionnelle = tVariablesModele[idxVariableOut].optionnelle;
			for ( idxParent=0 ; idxParent<VAR_NB_PARENT_MAX ; idxParent++ )
				tVariables->variables[idxVariableOut].parent[idxParent] = tVariablesModele[idxVariableOut].parent[idxParent];
			tVariables->variables[idxVariableOut].valeur = NULL;
			tVariables->variables[idxVariableOut].nbValeur = tVariablesModele[idxVariableOut].nbValeur;
			tVariables->variables[idxVariableOut].id = 0;
			tVariables->variables[idxVariableOut].unique = 0;

		}

		for ( idxVariableIn=0 ; idxVariableIn<tabVariablesLength1 ; idxVariableIn++ )
		{
			// On vérifie si la propriété parente existe, si non on ne charge pas la propriété
			// -------------------------------------------------------------------------------
			parentFound = 0;
			parentPresent = 0;
			for ( idxParent=0 ; idxParent<VAR_NB_PARENT_MAX ; idxParent++ )
			{
				if ( tVariables->variables[idxVariableOut].parent[idxParent] != -1 )
				{
					parentPresent = 1;
					if ( tVariables->variables[tVariables->variables[idxVariableOut].parent[idxParent]].valeur != NULL )

					{
						parentFound = 1;
						break;
					}
				}
			}
			//if ( (parentPresent == 1) && (parentFound == 0) )
			//    break;

			// Vérif pour ne pas planter sur le strcmp
			// ---------------------------------------
			if ( tabVariables[idxVariableIn*tabVariablesLength2] == NULL )
			{
				sprintf (tcomErreur, GET_MESSAGE(VAR_MSG_POPUP_2), idxVariableIn*tabVariablesLength2, tVariables->variables[idxVariableOut].nom);
				errChk(-1);
			}

			if ( strcmp (tVariables->variables[idxVariableOut].nom, tabVariables[idxVariableIn*tabVariablesLength2]) == 0 )
			{

				// La variable est trouvée
				// -----------------------
				varFound = 1;

				// Extraction de la description de la variable
				// -------------------------------------------
				strcpy ( tVariables->variables[idxVariableOut].description, tabVariables[(idxVariableIn*tabVariablesLength2)+1] );

				// Extraction de la description de la variable
				// -------------------------------------------
				//strcpy ( tVariables->variables[idxVariableOut].chValeur, tabVariables[(idxVariableIn*tabVariablesLength2)+2] );

				// Vérifie si on extrait une variable d'état ou une variable de configuration
				// --------------------------------------------------------------------------
				if ( tVariables->variables[idxVariableOut].nbValeur == 0 )
				{
					if (VAR_SetString ( tVariables, idxVariableOut, tabVariables[(idxVariableIn*tabVariablesLength2)+2] ))
						errChk (-1);
				}

				// Extraction de la l'information d'unicité de la variable
				// -------------------------------------------------------
				if ( tabVariablesLength2 == 4)
					if ( strcmp ( "True", tabVariables[(idxVariableIn*tabVariablesLength2)+3] ) == 0 )
						tVariables->variables[idxVariableOut].unique = 1;

				// Variable trouvé on passe à la nouvelle variable
				// -----------------------------------------------
				break;
			}
		}

		// Si la variable n'est pas définie alors on met à zéro le nombre de valeur
		// ------------------------------------------------------------------------
		if ( (varFound == 0) && (tVariables->variables[idxVariableOut].valeur == NULL) )
			tVariables->variables[idxVariableOut].nbValeur = 0;

		// On vérifie si la variable est optionnelle ou pas
		// ------------------------------------------------
		// Conditions d'arrêt :
		//  - La variable n'est pas trouvée
		//  ET
		//  - La variable n'est pas optionnelle
		//  ET
		//      - La variable posséde un parent défini
		//      OU
		//      - La variable ne possède pas de parent
		// ------------------------------------------------
		if ( (varFound == 0) && (tVariables->variables[idxVariableOut].optionnelle == 0) && ( ( (parentPresent == 1) && (parentFound == 1) ) || (parentPresent == 0) ) && (tVariables->variables[idxVariableOut].valeur == NULL) )
		{
			// La variable n'est pas optionnelle et elle n'a pas été trouvée -> on génère une erreur
			// -------------------------------------------------------------------------------------
			Fmt (chMess, GET_MESSAGE(VAR_MSG_POPUP_3), tVariables->variables[idxVariableOut].nom);
			ClipboardPutText (chMess);
			Fmt (chMess, GET_MESSAGE(GENERIQUE_MSG_POPUP_PRESSE_PAPIER), chMess);
			MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP), chMess);

			// On affiche le pop up pour toutes les variables non optionelle non configurées
			// -----------------------------------------------------------------------------
			error = -1;
		}
	}

Error:

	// Libération des ressources
	// -------------------------
	for (iBcleFree = (tabVariablesLength1*tabVariablesLength2 -1); iBcleFree>=0 ; iBcleFree--)
	{
		if (tabVariables[iBcleFree] != NULL)
			CDotNetFreeMemory(tabVariables[iBcleFree]);
	}
	if (tabVariables != NULL)
		CDotNetFreeMemory(tabVariables);

	// =======================
	// = gestion des erreurs =
	// =======================
	if(error)
	{
		if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
		else if ( error == TCOM_ERREUR_CONFIG )
			strcpy (strErreurMessage, chMess);
		else if ( tcomErreur != NULL )
			strcpy (strErreurMessage, tcomErreur);
		else
			sprintf (strErreurMessage, GET_MESSAGE(VAR_MSG_POPUP_4), VAR_NAME(tVariables,idxVariableOut));

	}

	// Libération des ressources   - Suite
	// --------------------------------------------
	if ( tcomErreur != NULL )
		CDotNetFreeMemory (tcomErreur);
	if ( tcomErreurRequete != NULL )
		CDotNetFreeMemory (tcomErreurRequete);


	if(error)
		return -1;

	return 0;

	return 0;
}

// ==============================================================================
// FONCTION : 	  VAR_Set
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int VAR_Set ( T_VARIABLE *tVariablesModele,
//								T_VARIABLES *tVariables,
//								hdleTCom instTracaCom,
//								char *codeProduit,
//								char *indiceProduit,
//								char *numSerie,
//								char *strErreurMessage)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_VARIABLES *tVariablesModele	: Tableau de variables modele,
//				  - T_VARIABLES *tVariables 		: Tableau de variables,
//				  - hdleTCom 	instTracaCom		: Handle sur la base TracaCom,
//				  - char 		*codeProduit		: Code produit,
//				  - char 		*indiceProduit		: Indice produit,
//				  - char 		*numSerie			: Numéro de série du STB,
//				  - char 		*strErreurMessage	: Message d'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Enregistrement des variables d'état de la Base de données.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :		1.1.0
//  DATE :			15/12/2009
//  AUTEUR :		EAH
//  DESCRIPTION :	Création issue de la personnalisation STB
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int VAR_Set ( T_VARIABLES *tVariables, hdleSCProd instSCProduction, char *codeProduit, char *indiceProduit, char *numSerie, char *strErreurMessage )
{
	char	*tcomErreur = NULL;
	char	*tcomErreurRequete = NULL;
	int		blnErreurSurvenue=0;
	int		intErreurCode=0;
	int		error = 0;
	char	chMess[512] = {'\0'};
	char	*chValeur = NULL;
	int		idxVariable;
	int		idxValeur;


	// ================================================================
	// = Extraction des variables de configuration pour le banc Perso =
	// ================================================================
	for ( idxVariable=0 ; idxVariable<tVariables->nbVariables ; idxVariable++ )
	{
		if ( tVariables->variables[idxVariable].valeur != NULL )
		{
			// Formatage de la valeur de la variable
			// -------------------------------------
			switch (tVariables->variables[idxVariable].type)
			{
					// Formatage d'une variable de type Booléen
					// ----------------------------------------
				case VAR_TBOOL:
					for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
					{
						if (idxValeur == 0)
							sprintf ( chMess, "%d", (VAR_BOOL)((VAR_BOOL*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						else
							sprintf ( chMess, "%s|%d", chMess, (VAR_BOOL)((VAR_BOOL*)tVariables->variables[idxVariable].valeur)[idxValeur] );
					}
					break;

					// Formatage d'une variable de type entier signé 8bits
					// ---------------------------------------------------
				case VAR_TSINT8:
					for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
					{
						if (idxValeur == 0)
							sprintf ( chMess, "%d", (VAR_SINT8)((VAR_SINT8*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						else
							sprintf ( chMess, "%s|%d", chMess, (VAR_SINT8)((VAR_SINT8*)tVariables->variables[idxVariable].valeur)[idxValeur] );
					}
					break;

					// Formatage d'une variable de type entier non signé 8bits
					// -------------------------------------------------------
				case VAR_TUINT8:
					for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
					{
						if (idxValeur == 0)
							sprintf ( chMess, "%d", (VAR_UINT8)((VAR_UINT8*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						else
							sprintf ( chMess, "%s|%d", chMess, (VAR_UINT8)((VAR_UINT8*)tVariables->variables[idxVariable].valeur)[idxValeur] );
					}
					break;

					// Formatage d'une variable de type entier signé 16bits
					// ----------------------------------------------------
				case VAR_TSINT16:
					for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
					{
						if (idxValeur == 0)
							sprintf ( chMess, "%d", (VAR_SINT16)((VAR_SINT16*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						else
							sprintf ( chMess, "%s|%d", chMess, (VAR_SINT16)((VAR_SINT16*)tVariables->variables[idxVariable].valeur)[idxValeur] );
					}
					break;

					// Formatage d'une variable de type entier non signé 16bits
					// --------------------------------------------------------
				case VAR_TUINT16:
					for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
					{
						if (idxValeur == 0)
							sprintf ( chMess, "%d", (VAR_UINT16)((VAR_UINT16*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						else
							sprintf ( chMess, "%s|%d", chMess, (VAR_UINT16)((VAR_UINT16*)tVariables->variables[idxVariable].valeur)[idxValeur] );
					}
					break;

					// Formatage d'une variable de type entier signé 32bits
					// ----------------------------------------------------
				case VAR_TSINT32:
					for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
					{
						if (idxValeur == 0)
							sprintf ( chMess, "%d", (VAR_SINT32)((VAR_SINT32*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						else
							sprintf ( chMess, "%s|%d", chMess, (VAR_SINT32)((VAR_SINT32*)tVariables->variables[idxVariable].valeur)[idxValeur] );
					}
					break;

					// Formatage d'une variable de type entier non signé 32bits
					// --------------------------------------------------------
				case VAR_TUINT32:
					for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
					{
						if (idxValeur == 0)
							sprintf ( chMess, "%d", (VAR_UINT32)((VAR_UINT32*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						else
							sprintf ( chMess, "%s|%d", chMess, (VAR_UINT32)((VAR_UINT32*)tVariables->variables[idxVariable].valeur)[idxValeur] );
					}
					break;

					// Formatage d'une variable de type String
					// ---------------------------------------
				case VAR_TSTRING:
					for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
					{
						if (idxValeur == 0)
							sprintf ( chMess, "%s", (VAR_STRING)((VAR_STRING*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						else
							sprintf ( chMess, "%s|%s", chMess, (VAR_STRING)((VAR_STRING*)tVariables->variables[idxVariable].valeur)[idxValeur] );
					}
					break;

					// Formatage d'une variable de type Booléen
					// ----------------------------------------
				case VAR_TFLOAT:
					for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
					{
						if (idxValeur == 0)
							sprintf ( chMess, "%f", (VAR_FLOAT)((VAR_FLOAT*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						else
							sprintf ( chMess, "%s|%f", chMess, (VAR_FLOAT)((VAR_FLOAT*)tVariables->variables[idxVariable].valeur)[idxValeur] );
					}
					break;

					// Type de variable non reconnu
					// ----------------------------
				default:
					sprintf (strErreurMessage, "Type de variable inconnu (%d).", tVariables->variables[idxVariable].type);
					return -1;
			}






			// Vérification des erreurs de la fonction
			// ---------------------------------------
			if(blnErreurSurvenue)
			{
				errChk(intErreurCode);
			}
		}
	}

Error:
	// =======================
	// = gestion des erreurs =
	// =======================
	if (error)
	{
		if ( tcomErreur != NULL )
			strcpy (strErreurMessage, tcomErreur);
		sprintf (strErreurMessage, "Enregistrement variables etat [%s] : %s\n", tVariables->variables[idxVariable].nom, strErreurMessage);
		return -1;
	}

	return 0;
}

// ==============================================================================
// FONCTION : 	  VAR_Raz
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int VAR_Raz ( T_VARIABLES *tVariables )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_VARIABLES *tVariables : Tableau de variables,
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Raz des valeurs des variables d'état.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :		1.1.0
//  DATE :			15/12/2009
//  AUTEUR :		EAH
//  DESCRIPTION :	Création issue de la personnalisation STB
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int VAR_Raz ( T_VARIABLES *tVariables )
{
	int idxVariable;
	int idxValeur;


	// =================================
	// = RAZ des valeurs des variables =
	// =================================
	for ( idxVariable=0 ; idxVariable<tVariables->nbVariables ; idxVariable++ )
	{
		// RAZ de la valeur de la variable
		// -------------------------------
		switch (tVariables->variables[idxVariable].type)
		{
				// ======================================================================
				// = RAZ d'une variable de type Booléen									=
				// ======================================================================
			case VAR_TBOOL:
				// Allocation mémoire si la mémoire est vide
				// -----------------------------------------
				if ( (tVariables->variables[idxVariable].valeur == NULL) && (tVariables->variables[idxVariable].nbValeur > 0) )
					tVariables->variables[idxVariable].valeur = malloc ( sizeof(VAR_BOOL) * (tVariables->variables[idxVariable].nbValeur) );
				// Raz des valeurs de la variable
				// ------------------------------
				for ( idxValeur=0 ; (idxValeur<tVariables->variables[idxVariable].nbValeur) && (tVariables->variables[idxVariable].valeur != NULL) ; idxValeur++ )
					((VAR_BOOL*)tVariables->variables[idxVariable].valeur)[idxValeur] = VAR_BOOL_DEFAULT_VAL;
				break;

				// ======================================================================
				// = RAZ d'une variable de type String									=
				// ======================================================================
			case VAR_TSTRING:
				// Allocation mémoire si la mémoire est vide
				// -----------------------------------------
				if ( (tVariables->variables[idxVariable].valeur == NULL) && (tVariables->variables[idxVariable].nbValeur > 0) )
				{
					tVariables->variables[idxVariable].valeur = malloc ( sizeof(VAR_STRING) * (tVariables->variables[idxVariable].nbValeur) );
					for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
						((VAR_STRING*)tVariables->variables[idxVariable].valeur)[idxValeur] = (VAR_STRING)malloc ( sizeof(char) * VAR_STRING_TAILLE_MAX );
				}
				// Raz des valeurs de la variable
				// ------------------------------
				for ( idxValeur=0 ; (idxValeur<tVariables->variables[idxVariable].nbValeur) && (tVariables->variables[idxVariable].valeur != NULL) ; idxValeur++ )
					strcpy ( ((VAR_STRING*)tVariables->variables[idxVariable].valeur)[idxValeur], VAR_STRING_DEFAULT_VAL );
				break;

				// ======================================================================
				// = RAZ d'une variable de type entier signé 8bits 						=
				// ======================================================================
			case VAR_TSINT8:
				// Allocation mémoire si la mémoire est vide
				// -----------------------------------------
				if ( (tVariables->variables[idxVariable].valeur == NULL) && (tVariables->variables[idxVariable].nbValeur > 0) )
					tVariables->variables[idxVariable].valeur = malloc ( sizeof(VAR_SINT8) * (tVariables->variables[idxVariable].nbValeur) );
				// Raz des valeurs de la variable
				// ------------------------------
				for ( idxValeur=0 ; (idxValeur<tVariables->variables[idxVariable].nbValeur) && (tVariables->variables[idxVariable].valeur != NULL) ; idxValeur++ )
					((VAR_SINT8*)tVariables->variables[idxVariable].valeur)[idxValeur] = VAR_SINT8_DEFAULT_VAL;
				break;

				// ======================================================================
				// = RAZ d'une variable de type entier non signé 8bits					=
				// ======================================================================
			case VAR_TUINT8:
				// Allocation mémoire si la mémoire est vide
				// -----------------------------------------
				if ( (tVariables->variables[idxVariable].valeur == NULL) && (tVariables->variables[idxVariable].nbValeur > 0) )
					tVariables->variables[idxVariable].valeur = malloc ( sizeof(VAR_UINT8) * (tVariables->variables[idxVariable].nbValeur) );
				// Raz des valeurs de la variable
				// ------------------------------
				for ( idxValeur=0 ; (idxValeur<tVariables->variables[idxVariable].nbValeur) && (tVariables->variables[idxVariable].valeur != NULL) ; idxValeur++ )
					((VAR_UINT8*)tVariables->variables[idxVariable].valeur)[idxValeur] = VAR_UINT8_DEFAULT_VAL;
				break;

				// ======================================================================
				// = RAZ d'une variable de type entier signé 16bits						=
				// ======================================================================
			case VAR_TSINT16:
				// Allocation mémoire si la mémoire est vide
				// -----------------------------------------
				if ( (tVariables->variables[idxVariable].valeur == NULL) && (tVariables->variables[idxVariable].nbValeur > 0) )
					tVariables->variables[idxVariable].valeur = malloc ( sizeof(VAR_SINT16) * (tVariables->variables[idxVariable].nbValeur) );
				// Raz des valeurs de la variable
				// ------------------------------
				for ( idxValeur=0 ; (idxValeur<tVariables->variables[idxVariable].nbValeur) && (tVariables->variables[idxVariable].valeur != NULL) ; idxValeur++ )
					((VAR_SINT16*)tVariables->variables[idxVariable].valeur)[idxValeur] = VAR_SINT16_DEFAULT_VAL;
				break;

				// ======================================================================
				// = RAZ d'une variable de type entier non signé 16bits					=
				// ======================================================================
			case VAR_TUINT16:
				// Allocation mémoire si la mémoire est vide
				// -----------------------------------------
				if ( (tVariables->variables[idxVariable].valeur == NULL) && (tVariables->variables[idxVariable].nbValeur > 0) )
					tVariables->variables[idxVariable].valeur = malloc ( sizeof(VAR_UINT16) * (tVariables->variables[idxVariable].nbValeur) );
				// Raz des valeurs de la variable
				// ------------------------------
				for ( idxValeur=0 ; (idxValeur<tVariables->variables[idxVariable].nbValeur) && (tVariables->variables[idxVariable].valeur != NULL) ; idxValeur++ )
					((VAR_UINT16*)tVariables->variables[idxVariable].valeur)[idxValeur] = VAR_UINT16_DEFAULT_VAL;
				break;

				// ======================================================================
				// = RAZ d'une variable de type entier signé 32bits						=
				// ======================================================================
			case VAR_TSINT32:
				// Allocation mémoire si la mémoire est vide
				// -----------------------------------------
				if ( (tVariables->variables[idxVariable].valeur == NULL) && (tVariables->variables[idxVariable].nbValeur > 0) )
					tVariables->variables[idxVariable].valeur = malloc ( sizeof(VAR_SINT32) * (tVariables->variables[idxVariable].nbValeur) );
				// Raz des valeurs de la variable
				// ------------------------------
				for ( idxValeur=0 ; (idxValeur<tVariables->variables[idxVariable].nbValeur) && (tVariables->variables[idxVariable].valeur != NULL) ; idxValeur++ )
					((VAR_SINT32*)tVariables->variables[idxVariable].valeur)[idxValeur] = VAR_SINT32_DEFAULT_VAL;
				break;

				// ======================================================================
				// = RAZ d'une variable de type entier non signé 32bits					=
				// ======================================================================
			case VAR_TUINT32:
				// Allocation mémoire si la mémoire est vide
				// -----------------------------------------
				if ( (tVariables->variables[idxVariable].valeur == NULL) && (tVariables->variables[idxVariable].nbValeur > 0) )
					tVariables->variables[idxVariable].valeur = malloc ( sizeof(VAR_UINT32) * (tVariables->variables[idxVariable].nbValeur) );
				// Raz des valeurs de la variable
				// ------------------------------
				for ( idxValeur=0 ; (idxValeur<tVariables->variables[idxVariable].nbValeur) && (tVariables->variables[idxVariable].valeur != NULL) ; idxValeur++ )
					((VAR_UINT32*)tVariables->variables[idxVariable].valeur)[idxValeur] = VAR_UINT32_DEFAULT_VAL;
				break;

				// ======================================================================
				// = RAZ d'une variable de type Booléen									=
				// ======================================================================
			case VAR_TFLOAT:
				// Allocation mémoire si la mémoire est vide
				// -----------------------------------------
				if ( (tVariables->variables[idxVariable].valeur == NULL) && (tVariables->variables[idxVariable].nbValeur > 0) )
					tVariables->variables[idxVariable].valeur = malloc ( sizeof(VAR_FLOAT) * (tVariables->variables[idxVariable].nbValeur) );
				// Raz des valeurs de la variable
				// ------------------------------
				for ( idxValeur=0 ; (idxValeur<tVariables->variables[idxVariable].nbValeur) && (tVariables->variables[idxVariable].valeur != NULL) ; idxValeur++ )
					((VAR_FLOAT*)tVariables->variables[idxVariable].valeur)[idxValeur] = VAR_FLOAT_DEFAULT_VAL;
				break;

				// ======================================================================
				// = Type de variable non reconnu										=
				// ======================================================================
			default:
				return -1;
		}

	}

	return 0;
}

// ==============================================================================
// FONCTION : 	  VAR_Delete
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int VAR_Delete ( T_VARIABLES *tVariables )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_VARIABLES *tVariables : Tableau de variables,
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Suppression des valeurs des variables.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :		1.1.0
//  DATE :			15/12/2009
//  AUTEUR :		EAH
//  DESCRIPTION :	Création issue de la personnalisation STB
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int VAR_Delete ( T_VARIABLES *tVariables )
{
	int idxVariable;
	int idxValeur;


	// ===================================
	// = Suppression des valeurs alloués =
	// ===================================
	for ( idxVariable=0 ; idxVariable<tVariables->nbVariables ; idxVariable++ )
	{
		// Libération mémoire seulement si allouée
		// ---------------------------------------
		if (tVariables->variables[idxVariable].valeur != NULL)
		{
			// Si la variable et de type STRING alors on libère la mémoire pour toutes les chaines
			// -----------------------------------------------------------------------------------
			if (tVariables->variables[idxVariable].type == VAR_TSTRING)
			{
				for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
				{
					// Libération de la mémoire allouée pour la chaine
					// -----------------------------------------------
					free ( ((VAR_STRING*)tVariables->variables[idxVariable].valeur)[idxValeur] );
				}
			}
			// Libération de la mémoire allouée pour la variable
			// -------------------------------------------------
			free (tVariables->variables[idxVariable].valeur);
			tVariables->variables[idxVariable].valeur = NULL;
			tVariables->variables[idxVariable].nbValeur = 0;
		}
	}

	// =============================================
	// = Suppression du tableau de valeurs alloués =
	// =============================================
	free (tVariables->variables);
	tVariables->variables = NULL;
	tVariables->nbVariables = 0;

	return 0;
}

// ==============================================================================
// FONCTION : 	  VAR_Print
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int VAR_Print ( 	T_VARIABLES *tVariables,
//									char *strPrint,
//									char *strErreurMessage)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - char *strPrint			: Chaine formaté pour impression,
//				  - T_VARIABLES *tVariables : Tableau de variables,
//				  - char *strErreurMessage	: Message d'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Formatage des variables pour impression.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :		1.1.0
//  DATE :			15/12/2009
//  AUTEUR :		EAH
//  DESCRIPTION :	Création issue de la personnalisation STB
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int VAR_Print ( T_VARIABLES *tVariables, char *strPrint, char *strErreurMessage)
{
	char    chMess[1024] = {'\0'};
	char    chValeur[1024] = {'\0'};
	int     idxVariable;


	// ==========================================
	// = Initialisation des variables de retour =
	// ==========================================
	strPrint[0] = '\0';
	strErreurMessage[0] = '\0';

	// ===========================================================
	// = Print des variables de configuration pour le banc Perso =
	// ===========================================================
	for ( idxVariable=0 ; idxVariable<tVariables->nbVariables ; idxVariable++ )
	{
		if ( tVariables->variables[idxVariable].valeur != NULL )
		{
			// Formatage de la valeur à afficher
			// ---------------------------------
			if ( VAR_GetString ( tVariables, idxVariable, chValeur ) != 0 )
				return -1;

			// Si la chaine est vide on n'affiche pas la variable
			// --------------------------------------------------
			if ( chValeur[0] == '\0' )
				continue;

			// Si la variable est un entier non signé et que sa valeur vaut 0 :
			//      => On n'affiche pas la valeur
			// ----------------------------------------------------------------
			if (
				(!( (tVariables->variables[idxVariable].type == VAR_TUINT8 ) && (chValeur[0] == '0') )) &&
				(!( (tVariables->variables[idxVariable].type == VAR_TUINT16) && (chValeur[0] == '0') )) &&
				(!( (tVariables->variables[idxVariable].type == VAR_TUINT32) && (chValeur[0] == '0') ))
			)
			{
				sprintf ( chMess, "%s: %s\n", VAR_STR_PARAM_BLANK, chValeur );

				// Ajout du nom de la variable dans la ligne
				// -----------------------------------------
				strncpy ( chMess, tVariables->variables[idxVariable].nom, strlen(tVariables->variables[idxVariable].nom) );
				chMess[strlen(chMess)] = '\0';

				// Ajout de la ligne dans la chaine de variable
				// --------------------------------------------
				strcat ( strPrint, chMess);
			}
		}
	}

	return 0;
}

// ==============================================================================
// FONCTION : 	  VAR_SetString
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int VAR_SetString (	T_VARIABLES *tVariables,
//										int index,
//										char *valeur )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - char *strPrint			: Chaine formaté pour impression,
//				  - T_VARIABLES *tVariables : Tableau de variables,
//				  - char *strErreurMessage	: Message d'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Enregistrement d'une variable à partir d'une chaine.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :		1.1.0
//  DATE :			15/12/2009
//  AUTEUR :		EAH
//  DESCRIPTION :	Création issue de la personnalisation STB
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int VAR_SetString ( T_VARIABLES *tVariables, int idxVariable, char *valeur )
{
	char			*ptrVariable = NULL;
	void			*ptrValeurSave = NULL;
	int				nbValeurSave;
	int				error = 0;
	char			chMess[512] = {'\0'};
	char			chValeurDefaut[16] = "";
	int				idxValeur;
	int 			integerValue;
	int				flagVariablesEtat;
	unsigned int	unsignedIntegerValue;


	// Mise en mémoire de la valeur courante avant modification
	// --------------------------------------------------------
	ptrValeurSave = tVariables->variables[idxVariable].valeur;
	nbValeurSave = tVariables->variables[idxVariable].nbValeur;
	tVariables->variables[idxVariable].valeur = NULL;
	tVariables->variables[idxVariable].nbValeur = 0;

	// Vérifie si on doit extraire un tableau de valeur (les valeurs du tableau sont séparés par '|')
	// ----------------------------------------------------------------------------------------------
	flagVariablesEtat = (strlen (valeur) == 0);
	if (flagVariablesEtat)
		ptrVariable = chValeurDefaut;
	else
		ptrVariable = strtok (valeur, VAR_TAB_SEPARATOR);
	while ( (ptrVariable != NULL) || (flagVariablesEtat) )
	{
		// On passe une fois pour allouer de la mémoire pour variable état
		// Les variables n'ont pas de valeurs définis en BDD
		// ---------------------------------------------------------------
		flagVariablesEtat = 0;

		// Extraction de la valeur de la variable
		// --------------------------------------
		switch (tVariables->variables[idxVariable].type)
		{
				// Extraction d'une variable de type Booléen
				// -----------------------------------------
			case VAR_TBOOL:
				tVariables->variables[idxVariable].valeur = realloc ( tVariables->variables[idxVariable].valeur, sizeof(VAR_BOOL) * (tVariables->variables[idxVariable].nbValeur+1) );
				if ( ptrVariable[0] == '1' )
					VAR_SET_BOOL(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = TRUE;
				else if ( ptrVariable[0] == '0' )
					VAR_SET_BOOL(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = FALSE;
				else if ( ptrVariable[0] == '\0' )
					VAR_SET_BOOL(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = VAR_BOOL_DEFAULT_VAL;
				else
				{
					free (tVariables->variables[idxVariable].valeur);
					tVariables->variables[idxVariable].valeur = ptrValeurSave;
					tVariables->variables[idxVariable].nbValeur = nbValeurSave;
					errChk(-1);
				}
				break;

				// Extraction d'une variable de type String
				// ----------------------------------------
			case VAR_TSTRING:
				tVariables->variables[idxVariable].valeur = realloc ( tVariables->variables[idxVariable].valeur, sizeof(char*) * (tVariables->variables[idxVariable].nbValeur+1) );
				((VAR_STRING*)tVariables->variables[idxVariable].valeur)[tVariables->variables[idxVariable].nbValeur] = malloc ( sizeof(char) * VAR_STRING_TAILLE_MAX );
				strcpy ( VAR_SET_STRING(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur), ptrVariable);
				break;

				// Extraction d'une variable de type entier signé 8bits
				// ----------------------------------------------------
			case VAR_TSINT8:
				tVariables->variables[idxVariable].valeur = realloc ( tVariables->variables[idxVariable].valeur, sizeof(VAR_SINT8) * (tVariables->variables[idxVariable].nbValeur+1) );
				if ( StrToInt (ptrVariable, &integerValue) )
					VAR_SET_SINT8(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = (VAR_SINT8)integerValue;
				else if ( ptrVariable[0] == '\0' )
					VAR_SET_SINT8(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = (VAR_SINT8)VAR_SINT8_DEFAULT_VAL;
				else
				{
					free (tVariables->variables[idxVariable].valeur);
					tVariables->variables[idxVariable].valeur = ptrValeurSave;
					tVariables->variables[idxVariable].nbValeur = nbValeurSave;
					errChk(-1);
				}
				break;

				// Extraction d'une variable de type entier non signé 8bits
				// --------------------------------------------------------
			case VAR_TUINT8:
				tVariables->variables[idxVariable].valeur = realloc ( tVariables->variables[idxVariable].valeur, sizeof(VAR_UINT8) * (tVariables->variables[idxVariable].nbValeur+1) );
				if ( StrToUInt (ptrVariable, &unsignedIntegerValue) )
					VAR_SET_UINT8(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = (VAR_UINT8)unsignedIntegerValue;
				else if ( ptrVariable[0] == '\0' )
					VAR_SET_UINT8(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = (VAR_UINT8)VAR_UINT8_DEFAULT_VAL;
				else
				{
					free (tVariables->variables[idxVariable].valeur);
					tVariables->variables[idxVariable].valeur = ptrValeurSave;
					tVariables->variables[idxVariable].nbValeur = nbValeurSave;
					errChk(-1);
				}
				break;

				// Extraction d'une variable de type entier signé 16bits
				// -----------------------------------------------------
			case VAR_TSINT16:
				tVariables->variables[idxVariable].valeur = realloc ( tVariables->variables[idxVariable].valeur, sizeof(VAR_SINT16) * (tVariables->variables[idxVariable].nbValeur+1) );
				if ( StrToInt (ptrVariable, &integerValue) )
					VAR_SET_SINT16(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = (VAR_SINT16)integerValue;
				else if ( ptrVariable[0] == '\0' )
					VAR_SET_SINT16(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = (VAR_SINT16)VAR_SINT16_DEFAULT_VAL;
				else
				{
					free (tVariables->variables[idxVariable].valeur);
					tVariables->variables[idxVariable].valeur = ptrValeurSave;
					tVariables->variables[idxVariable].nbValeur = nbValeurSave;
					errChk(-1);
				}
				break;

				// Extraction d'une variable de type entier non signé 16bits
				// ---------------------------------------------------------
			case VAR_TUINT16:
				tVariables->variables[idxVariable].valeur = realloc ( tVariables->variables[idxVariable].valeur, sizeof(VAR_UINT16) * (tVariables->variables[idxVariable].nbValeur+1) );
				if ( StrToUInt (ptrVariable, &unsignedIntegerValue) )
					VAR_SET_UINT16(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = (VAR_UINT16)unsignedIntegerValue;
				else if ( ptrVariable[0] == '\0' )
					VAR_SET_UINT16(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = (VAR_UINT16)VAR_UINT16_DEFAULT_VAL;
				else
				{
					free (tVariables->variables[idxVariable].valeur);
					tVariables->variables[idxVariable].valeur = ptrValeurSave;
					tVariables->variables[idxVariable].nbValeur = nbValeurSave;
					errChk(-1);
				}
				break;

				// Extraction d'une variable de type entier signé 32bits
				// -----------------------------------------------------
			case VAR_TSINT32:
				tVariables->variables[idxVariable].valeur = realloc ( tVariables->variables[idxVariable].valeur, sizeof(VAR_SINT32) * (tVariables->variables[idxVariable].nbValeur+1) );
				if ( StrToInt (ptrVariable, &integerValue) )
					VAR_SET_SINT32(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = (VAR_SINT32)integerValue;
				else if ( ptrVariable[0] == '\0' )
					VAR_SET_SINT32(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = (VAR_SINT32)VAR_SINT32_DEFAULT_VAL;
				else
				{
					free (tVariables->variables[idxVariable].valeur);
					tVariables->variables[idxVariable].valeur = ptrValeurSave;
					tVariables->variables[idxVariable].nbValeur = nbValeurSave;
					errChk(-1);
				}
				break;

				// Extraction d'une variable de type entier non signé 32bits
				// ---------------------------------------------------------
			case VAR_TUINT32:
				tVariables->variables[idxVariable].valeur = realloc ( tVariables->variables[idxVariable].valeur, sizeof(VAR_UINT32) * (tVariables->variables[idxVariable].nbValeur+1) );
				if ( StrToUInt (ptrVariable, &unsignedIntegerValue) )
					VAR_SET_UINT32(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = (VAR_UINT32)unsignedIntegerValue;
				else if ( ptrVariable[0] == '\0' )
					VAR_SET_UINT32(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = (VAR_UINT32)VAR_UINT32_DEFAULT_VAL;
				else
				{
					free (tVariables->variables[idxVariable].valeur);
					tVariables->variables[idxVariable].valeur = ptrValeurSave;
					tVariables->variables[idxVariable].nbValeur = nbValeurSave;
					errChk(-1);
				}
				break;

				// Extraction d'une variable de type Booléen
				// -----------------------------------------
			case VAR_TFLOAT:
				tVariables->variables[idxVariable].valeur = realloc ( tVariables->variables[idxVariable].valeur, sizeof(VAR_FLOAT) * (tVariables->variables[idxVariable].nbValeur+1) );
				VAR_SET_FLOAT(tVariables,idxVariable,tVariables->variables[idxVariable].nbValeur) = (VAR_FLOAT)atof (ptrVariable);
				break;

				// Type de variable non reconnu
				// ----------------------------
			default:
				sprintf (chMess, "Type de variable inconnu (%d).", tVariables->variables[idxVariable].type);
				tVariables->variables[idxVariable].valeur = ptrValeurSave;
				tVariables->variables[idxVariable].nbValeur = nbValeurSave;
				errChk(-1);
				break;
		}

		// Récupération de la valeur suivante du tableau
		// ---------------------------------------------
		ptrVariable = strtok(NULL, VAR_TAB_SEPARATOR);

		// Incrémente le nombre de valeur
		// ------------------------------
		tVariables->variables[idxVariable].nbValeur++;
	}

	// Libération mémoire seulement si allouée
	// ---------------------------------------
	if (ptrValeurSave != NULL)
	{
		// Si la variable et de type STRING alors on libère la mémoire pour toutes les chaines
		// -----------------------------------------------------------------------------------
		if (tVariables->variables[idxVariable].type == VAR_TSTRING)
		{
			for ( idxValeur=0 ; idxValeur<nbValeurSave ; idxValeur++ )
			{
				// Libération de la mémoire allouée pour la chaine
				// -----------------------------------------------
				free ( ((VAR_STRING*)ptrValeurSave)[idxValeur] );
			}
		}
		// Libération de la mémoire allouée pour la variable
		// -------------------------------------------------
		free (ptrValeurSave);
	}

Error:
	// =======================
	// = gestion des erreurs =
	// =======================
	if(error)
	{
		return -1;
	}

	return 0;
}

// ==============================================================================
// FONCTION : 	  VAR_GetString
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int VAR_GetString (	T_VARIABLES *tVariables,
//										int index,
//										char *valeur )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - char *strPrint			: Chaine formaté pour impression,
//				  - T_VARIABLES *tVariables : Tableau de variables,
//				  - char *strErreurMessage	: Message d'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Formatage d'une valeur de variable sous forme de chaine.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :		1.1.0
//  DATE :			15/12/2009
//  AUTEUR :		EAH
//  DESCRIPTION :	Création issue de la personnalisation STB
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int VAR_GetString ( T_VARIABLES *tVariables, int index, char *valeur )
{
	int idxValeur;


	// ==========================================
	// = Initialisation des variables de retour =
	// ==========================================
	valeur[0] = '\0';

	// ===========================================================
	// = Print des variables de configuration pour le banc Perso =
	// ===========================================================
	if ( tVariables->variables[index].valeur != NULL )
	{
		// Formatage de la valeur de la variable
		// -------------------------------------
		switch (tVariables->variables[index].type)
		{
				// Formatage d'une variable de type Booléen
				// ----------------------------------------
			case VAR_TBOOL:
				for ( idxValeur=0 ; idxValeur<tVariables->variables[index].nbValeur ; idxValeur++ )
				{
					if (idxValeur == 0)
						sprintf ( valeur, "%d", (VAR_BOOL)((VAR_BOOL*)tVariables->variables[index].valeur)[idxValeur] );
					else
						sprintf ( valeur, "%s|%d", valeur, (VAR_BOOL)((VAR_BOOL*)tVariables->variables[index].valeur)[idxValeur] );
				}
				break;

				// Formatage d'une variable de type entier signé 8bits
				// ---------------------------------------------------
			case VAR_TSINT8:
				for ( idxValeur=0 ; idxValeur<tVariables->variables[index].nbValeur ; idxValeur++ )
				{
					if (idxValeur == 0)
						sprintf ( valeur, "%d", (VAR_SINT8)((VAR_SINT8*)tVariables->variables[index].valeur)[idxValeur] );
					else
						sprintf ( valeur, "%s|%d", valeur, (VAR_SINT8)((VAR_SINT8*)tVariables->variables[index].valeur)[idxValeur] );
				}
				break;

				// Formatage d'une variable de type entier non signé 8bits
				// -------------------------------------------------------
			case VAR_TUINT8:
				for ( idxValeur=0 ; idxValeur<tVariables->variables[index].nbValeur ; idxValeur++ )
				{
					if (idxValeur == 0)
						sprintf ( valeur, "%d", (VAR_UINT8)((VAR_UINT8*)tVariables->variables[index].valeur)[idxValeur] );
					else
						sprintf ( valeur, "%s|%d", valeur, (VAR_UINT8)((VAR_UINT8*)tVariables->variables[index].valeur)[idxValeur] );
				}
				break;

				// Formatage d'une variable de type entier signé 16bits
				// ----------------------------------------------------
			case VAR_TSINT16:
				for ( idxValeur=0 ; idxValeur<tVariables->variables[index].nbValeur ; idxValeur++ )
				{
					if (idxValeur == 0)
						sprintf ( valeur, "%d", (VAR_SINT16)((VAR_SINT16*)tVariables->variables[index].valeur)[idxValeur] );
					else
						sprintf ( valeur, "%s|%d", valeur, (VAR_SINT16)((VAR_SINT16*)tVariables->variables[index].valeur)[idxValeur] );
				}
				break;

				// Formatage d'une variable de type entier non signé 16bits
				// --------------------------------------------------------
			case VAR_TUINT16:
				for ( idxValeur=0 ; idxValeur<tVariables->variables[index].nbValeur ; idxValeur++ )
				{
					if (idxValeur == 0)
						sprintf ( valeur, "%d", (VAR_UINT16)((VAR_UINT16*)tVariables->variables[index].valeur)[idxValeur] );
					else
						sprintf ( valeur, "%s|%d", valeur, (VAR_UINT16)((VAR_UINT16*)tVariables->variables[index].valeur)[idxValeur] );
				}
				break;

				// Formatage d'une variable de type entier signé 32bits
				// ----------------------------------------------------
			case VAR_TSINT32:
				for ( idxValeur=0 ; idxValeur<tVariables->variables[index].nbValeur ; idxValeur++ )
				{
					if (idxValeur == 0)
						sprintf ( valeur, "%d", (VAR_SINT32)((VAR_SINT32*)tVariables->variables[index].valeur)[idxValeur] );
					else
						sprintf ( valeur, "%s|%d", valeur, (VAR_SINT32)((VAR_SINT32*)tVariables->variables[index].valeur)[idxValeur] );
				}
				break;

				// Formatage d'une variable de type entier non signé 32bits
				// --------------------------------------------------------
			case VAR_TUINT32:
				for ( idxValeur=0 ; idxValeur<tVariables->variables[index].nbValeur ; idxValeur++ )
				{
					if (idxValeur == 0)
						sprintf ( valeur, "%d", (VAR_UINT32)((VAR_UINT32*)tVariables->variables[index].valeur)[idxValeur] );
					else
						sprintf ( valeur, "%s|%d", valeur, (VAR_UINT32)((VAR_UINT32*)tVariables->variables[index].valeur)[idxValeur] );
				}
				break;

				// Formatage d'une variable de type String
				// ---------------------------------------
			case VAR_TSTRING:
				for ( idxValeur=0 ; idxValeur<tVariables->variables[index].nbValeur ; idxValeur++ )
				{
					if (idxValeur == 0)
						sprintf ( valeur, "%s", (VAR_STRING)((VAR_STRING*)tVariables->variables[index].valeur)[idxValeur] );
					else
						sprintf ( valeur, "%s|%s", valeur, (VAR_STRING)((VAR_STRING*)tVariables->variables[index].valeur)[idxValeur] );
				}
				break;

				// Formatage d'une variable de type Booléen
				// ----------------------------------------
			case VAR_TFLOAT:
				for ( idxValeur=0 ; idxValeur<tVariables->variables[index].nbValeur ; idxValeur++ )
				{
					if (idxValeur == 0)
						sprintf ( valeur, "%f", (VAR_FLOAT)((VAR_FLOAT*)tVariables->variables[index].valeur)[idxValeur] );
					else
						sprintf ( valeur, "%s|%f", valeur, (VAR_FLOAT)((VAR_FLOAT*)tVariables->variables[index].valeur)[idxValeur] );
				}
				break;

				// Type de variable non reconnu
				// ----------------------------
			default:
				return -1;
		}
	}
	else
		strcpy (valeur, "NULL");


	return 0;
}
// ==============================================================================
// FONCTION :     VAR_GestionTableau
// ------------------------------------------------------------------------------
// PROTOTYPE :    int VAR_GestionTableau ( T_VARIABLE *tVariablesModele,
//                              T_VARIABLES *tVariables,
//                              hdleTCom instTracaCom,
//                              char *codeProduit,
//                              char *indiceProduit,
//                              char *numSerie,
//								int iGestionUnicite
//                              char *strErreurMessage)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_VARIABLES *tVariablesModele   : Tableau de variables modele,
//                - T_VARIABLES *tVariables         : Tableau de variables,
//                - hdleTCom    instTracaCom        : Handle sur la base TracaCom,
//                - char        *codeProduit        : Code produit,
//                - char        *indiceProduit      : Indice produit,
//                - char        *numSerie           : Numéro de série du STB,
//				  - int 		iGestionUnicite		: Gestion de l'unicité
//                - char        *strErreurMessage   : Message d'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Enregistrement des variables d'état dans la Base de données
//				  sous forme de tableau pour SAP ME
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA05
//  DATE :        17/07/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int VAR_GestionTableau (int nItfe, T_TCOM_BASE *tcomBase, T_VARIABLES *tVariables, char *numSerie, char *Ressource, char *Operation, int iAction, char *strErreurMessage)
{
	int     			error = 0;
	int     			idxVariable = 0;
	int     			idxValeur;
	int					iFlagVariablesUniques = 0;
	int					iCompteurMemoire = 0;
	int 				i, CHAMPS_TAB = 0 ;
	char    			*tcomErreur = NULL;
	char    			*tcomErreurRequete = NULL;
	char    			chMess[VAR_STRING_TAILLE_MAX] = {'\0'};
	char    			chErr[512] = {'\0'};
	char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'};

	// Variables temporaires pour la mise en majuscules
	char    			chMessTMP[VAR_STRING_TAILLE_MAX] = {'\0'};
	char				chNomTMP[VAR_NOM_TAILLE_MAX] = {'\0'};

	char				**TableauVariables = NULL;


	// ==================
	// = Init Variables =
	// ==================

	strcpy(strErreurMessage,"");

	// ====================================================================================
	// = Selon l'action demandée - on va traiter les variables uniques ou les non uniques =
	// ====================================================================================

	switch (iAction)
	{
			// =================================
			// = CAS DES DONNEES MISE EN STOCK =
			// =================================
		case VAR_SAPME_STOCK:

			// On donne les paramètres
			// -----------------------
			iFlagVariablesUniques=1;
			CHAMPS_TAB=0;

			// On sort du case
			// ---------------
			break;

			// ==============================
			// = CAS DES DONNEES ASSEMBLEES =
			// ==============================
		case VAR_SAPME_ASSEMBLE:

			// On donne les paramètres
			// -----------------------
			iFlagVariablesUniques=1;
			CHAMPS_TAB=4;

			// Affichage LOG sous-étape fait à l'appel à cette fonction..
			// ----------------------------------------------------------

			// Affichage info SAP ME
			// ----------------------
			if (gFlagLogSAPME == TRUE )
			{
				sprintf (chMsgInfo, "Assemblage du tableau de composants en cours");
				FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
			}

			// On sort du case
			// ---------------
			break;

			// ==============================
			// = CAS DES DONNEES COLLECTEES =
			// ==============================
		case VAR_SAPME_COLLECT:

			// On donne les paramètres
			// -----------------------
			iFlagVariablesUniques=0;
			CHAMPS_TAB = 2;

			// Affichage LOG sous-étape
			// ------------------------
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_SOUS_ETAPE, GET_MESSAGE(FCT_MSG_TRACABILITE_COLLECT));

			// Affichage info SAP ME
			// ----------------------
			if (gFlagLogSAPME == TRUE )
			{
				sprintf (chMsgInfo, "Enregistrement du tableau de données collectées en cours");
				FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
			}

			// On sort du case
			// ---------------
			break;

			// ==================
			// = CAS PAR DEFAUT =
			// ==================
		default:

			// On sort en erreur
			// -----------------
			sprintf (strErreurMessage,"Erreur Remontée variables, action demandée non reconnue");
			errChk (-1);

			// On sort du case
			// ---------------
			break;
	}




	// ================================================================
	// = Extraction des variables de configuration pour le banc Perso =
	// ================================================================
	for ( idxVariable=0 ; idxVariable<tVariables->nbVariables ; idxVariable++ )
	{

		if ( tVariables->variables[idxVariable].valeur != NULL )
		{

			// on traite soit les variables uniques soit les autres selon l'action
			// --------------------------------------------------------------------
			if ( tVariables->variables[idxVariable].unique == iFlagVariablesUniques )
			{
				// Formatage de la valeur de la variable
				// -------------------------------------
				switch (tVariables->variables[idxVariable].type)
				{
						// Formatage d'une variable de type Booléen
						// ----------------------------------------
					case VAR_TBOOL:
						for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
						{
							if (idxValeur == 0)
								sprintf ( chMess, "%d", (VAR_BOOL)((VAR_BOOL*)tVariables->variables[idxVariable].valeur)[idxValeur] );
							else
								sprintf ( chMess, "%s|%d", chMess, (VAR_BOOL)((VAR_BOOL*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						}
						break;

						// Formatage d'une variable de type entier signé 8bits
						// ---------------------------------------------------
					case VAR_TSINT8:
						for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
						{
							if (idxValeur == 0)
								sprintf ( chMess, "%d", (VAR_SINT8)((VAR_SINT8*)tVariables->variables[idxVariable].valeur)[idxValeur] );
							else
								sprintf ( chMess, "%s|%d", chMess, (VAR_SINT8)((VAR_SINT8*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						}
						break;

						// Formatage d'une variable de type entier non signé 8bits
						// -------------------------------------------------------
					case VAR_TUINT8:
						for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
						{
							if (idxValeur == 0)
								sprintf ( chMess, "%d", (VAR_UINT8)((VAR_UINT8*)tVariables->variables[idxVariable].valeur)[idxValeur] );
							else
								sprintf ( chMess, "%s|%d", chMess, (VAR_UINT8)((VAR_UINT8*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						}
						break;

						// Formatage d'une variable de type entier signé 16bits
						// ----------------------------------------------------
					case VAR_TSINT16:
						for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
						{
							if (idxValeur == 0)
								sprintf ( chMess, "%d", (VAR_SINT16)((VAR_SINT16*)tVariables->variables[idxVariable].valeur)[idxValeur] );
							else
								sprintf ( chMess, "%s|%d", chMess, (VAR_SINT16)((VAR_SINT16*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						}
						break;

						// Formatage d'une variable de type entier non signé 16bits
						// --------------------------------------------------------
					case VAR_TUINT16:
						for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
						{
							if (idxValeur == 0)
								sprintf ( chMess, "%d", (VAR_UINT16)((VAR_UINT16*)tVariables->variables[idxVariable].valeur)[idxValeur] );
							else
								sprintf ( chMess, "%s|%d", chMess, (VAR_UINT16)((VAR_UINT16*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						}
						break;

						// Formatage d'une variable de type entier signé 32bits
						// ----------------------------------------------------
					case VAR_TSINT32:
						for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
						{
							if (idxValeur == 0)
								sprintf ( chMess, "%d", (VAR_SINT32)((VAR_SINT32*)tVariables->variables[idxVariable].valeur)[idxValeur] );
							else
								sprintf ( chMess, "%s|%d", chMess, (VAR_SINT32)((VAR_SINT32*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						}
						break;

						// Formatage d'une variable de type entier non signé 32bits
						// --------------------------------------------------------
					case VAR_TUINT32:
						for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
						{
							if (idxValeur == 0)
								sprintf ( chMess, "%d", (VAR_UINT32)((VAR_UINT32*)tVariables->variables[idxVariable].valeur)[idxValeur] );
							else
								sprintf ( chMess, "%s|%d", chMess, (VAR_UINT32)((VAR_UINT32*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						}
						break;

						// Formatage d'une variable de type String
						// ---------------------------------------
					case VAR_TSTRING:
						for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
						{
							if (idxValeur == 0)
								sprintf ( chMess, "%s", (VAR_STRING)((VAR_STRING*)tVariables->variables[idxVariable].valeur)[idxValeur] );
							else
								sprintf ( chMess, "%s|%s", chMess, (VAR_STRING)((VAR_STRING*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						}
						break;

						// Formatage d'une variable de type Booléen
						// ----------------------------------------
					case VAR_TFLOAT:
						for ( idxValeur=0 ; idxValeur<tVariables->variables[idxVariable].nbValeur ; idxValeur++ )
						{
							if (idxValeur == 0)
								sprintf ( chMess, "%f", (VAR_FLOAT)((VAR_FLOAT*)tVariables->variables[idxVariable].valeur)[idxValeur] );
							else
								sprintf ( chMess, "%s|%f", chMess, (VAR_FLOAT)((VAR_FLOAT*)tVariables->variables[idxVariable].valeur)[idxValeur] );
						}
						break;

						// Type de variable non reconnu
						// ----------------------------
					default:
						sprintf (chErr, GET_MESSAGE(VAR_MSG_ERR_VAR_INCONNU), tVariables->variables[idxVariable].type);
						errChk(-1);
				}



				// Si la variable est unique ==> On concatene avec "CodeArticle=" pour gestion de l'unicité. ==> Mise en Stock ou assemblage  + On met en Majuscules (car composants en MAJ côté ME)
				// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				if (iFlagVariablesUniques  == 1)
				{
					sprintf(chMessTMP,"%s=%s",tVariables->variables[idxVariable].nom,chMess);
					StringUpperCase (chMessTMP);
				}

				// Sinon, on recopie la valeur pour passage à la fonction sans modifier (respect de la casse)
				// ------------------------------------------------------------------------------------------
				else
					strcpy(chMessTMP, chMess);

				// On remonte le nom de la variable en majuscules (articles déclarés en majuscules dans ME, que ce soit des composants ou des CollectSFCData
				// -----------------------------------------------------------------------------------------------------------------------------------------
				strcpy(chNomTMP,tVariables->variables[idxVariable].nom);
				StringUpperCase(chNomTMP);


				// ======================================================
				// = Allocation Mémoire pour chaque variable du tableau =
				// ======================================================

				// On créee le tableau de variables
				// ------------------------------
				if (iCompteurMemoire == 0)
					TableauVariables = (char**) malloc( sizeof(char*) * (iCompteurMemoire + 1) * CHAMPS_TAB);
				else
					TableauVariables = (char**) realloc( TableauVariables, sizeof(char*) * (iCompteurMemoire + 1) * CHAMPS_TAB);


				// ======================================================================================================
				// = Allocation Mémoire pour chaque Champ en fonction du type d'action et enregistrement de la variable =
				// ======================================================================================================

				switch (iAction)
				{

					case VAR_SAPME_STOCK:

						// A completer selon les champs qui seront définis pour la fonction de mise en stock par tableau
						// ---------------------------------------------------------------------------------------------

						break;

					case VAR_SAPME_COLLECT:

						// On alloue la mémoire sur le tableau pour chaque Champ
						// -----------------------------------------------------
						TableauVariables[(iCompteurMemoire  * CHAMPS_TAB)  + 0] = (char*) malloc( sizeof(char) * SCPROD_OBJET_LONG_MAX );
						TableauVariables[(iCompteurMemoire  * CHAMPS_TAB)  + 1] = (char*) malloc( sizeof(char) * SCPROD_OBJET_LONG_MAX );

						// On alloue la mémoire sur le tableau pour chaque Champ
						// -----------------------------------------------------
						strcpy(TableauVariables[(iCompteurMemoire  * CHAMPS_TAB)  + 0],chNomTMP);
						strcpy(TableauVariables[(iCompteurMemoire  * CHAMPS_TAB)  + 1],chMessTMP);
						break;

					case VAR_SAPME_ASSEMBLE:

						// On alloue la mémoire sur le tableau pour chaque Champ
						// -----------------------------------------------------
						TableauVariables[(iCompteurMemoire  * CHAMPS_TAB)  + 0] = (char*) malloc( sizeof(char) * SCPROD_OBJET_LONG_MAX );
						TableauVariables[(iCompteurMemoire  * CHAMPS_TAB)  + 1] = (char*) malloc( sizeof(char) * SCPROD_OBJET_LONG_MAX );
						TableauVariables[(iCompteurMemoire  * CHAMPS_TAB)  + 2] = (char*) malloc( sizeof(char) * SCPROD_OBJET_LONG_MAX );
						TableauVariables[(iCompteurMemoire  * CHAMPS_TAB)  + 3] = (char*) malloc( sizeof(char) * SCPROD_OBJET_LONG_MAX );

						// On alloue la mémoire sur le tableau pour chaque Champ
						// -----------------------------------------------------
						strcpy(TableauVariables[(iCompteurMemoire  * CHAMPS_TAB)  + 0],chMessTMP);
						strcpy(TableauVariables[(iCompteurMemoire  * CHAMPS_TAB)  + 1],chNomTMP);
						strcpy(TableauVariables[(iCompteurMemoire  * CHAMPS_TAB)  + 2],SCPROD_ASSEMBLAGE_INVENTORY_ID);
						strcpy(TableauVariables[(iCompteurMemoire  * CHAMPS_TAB)  + 3],SCPROD_LIBELLE_ASSEMBLAGE);

						break;

					default:
						sprintf (strErreurMessage,"Erreur Remontée variables, action demandée non reconnue");
						errChk (-1);
						break;

				}

				// On incrémente le compteur
				// -------------------------
				iCompteurMemoire ++;


				// On réinitialise les valeurs tempos après l'appel
				// ------------------------------------------------
				strcpy(chMessTMP,"");
				strcpy(chNomTMP,"");


			}
		}
	}


	// ====================================================
	// = Appel à la fonction d'enregistrement par tableau =
	// ====================================================

	switch (iAction)
	{
		case VAR_SAPME_STOCK:
			// A completer
			break;

		case VAR_SAPME_COLLECT:
			errChk ( SCPROD_CollectSFCDataTableau (nItfe, tcomBase, numSerie, TableauVariables, iCompteurMemoire, CHAMPS_TAB, strErreurMessage));
			break;

		case VAR_SAPME_ASSEMBLE:
			errChk ( SCPROD_AssemblageComposantTableau (nItfe, tcomBase, numSerie, Operation, Ressource, TableauVariables, iCompteurMemoire, CHAMPS_TAB, strErreurMessage));
			break;

		default:
			sprintf (strErreurMessage,"Erreur Remontée variables, action demandée non reconnue");
			errChk (-1);
			break;
	}


Error:

	// ===========================
	// = Libération des mémoires =
	// ===========================
	for (i =  (iCompteurMemoire * CHAMPS_TAB - 1) ; i >= 0 ; i--)
		free ( TableauVariables [i]);

	free ( TableauVariables);

	// =======================
	// = gestion des erreurs =
	// =======================
	if (error)
	{
		if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
		else if ( strcmp(strErreurMessage,"") == 0 )
			sprintf (strErreurMessage, GET_MESSAGE(VAR_MSG_ERR_VAR_ENREGISTREMENT2),  "Enregistrement par Tableau");

		// Libération des ressources
		// -------------------------
		if ( tcomErreur != NULL )
			CDotNetFreeMemory (tcomErreur);
		if ( tcomErreurRequete != NULL )
			CDotNetFreeMemory (tcomErreurRequete);

		return -1;
	}

	return 0;
}

