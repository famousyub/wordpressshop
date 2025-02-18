#ifndef __MULTILANGUE_H__
#define __MULTILANGUE_H__

#define GET_MESSAGE(iIndexMessage) (  gLangues[iIndexMessage].chMessage )

#define TAILLE_MESSAGE_MAX         256
#define TAILLE_MESSAGE_TAG         64
#define SECTION_NAME				"MESSAGES"

typedef struct
{
	char chTag[TAILLE_MESSAGE_TAG];
	char chMessage[TAILLE_MESSAGE_MAX];
}T_LANGUES;

extern T_LANGUES gLangues[]; 

// Nombre de message
// -----------------
extern const int gNbMessage;

typedef enum
{
	IHM_STR_ERREUR,
	TCOM_MESSAGE_ERREUR_RESEAU,
	PNL_INTIT_TEXT,
	PNL_INTIT_ANNULER_TEXT,
	PNL_INTIT_VALIDER_TEXT,
	PNL_INTIT_SLIDE_TEXT,
	PNL_INTIT_SLIDE_TEXT_PRODUCT,
	PNL_INTIT_FILTRE,
	PNL_MAIN_TEXT,
	PNL_MAIN_LIB_SLOT_TEXT,
	PNL_MAIN_FERME_SLOT_TEXT,
	PNL_MAIN_TEST_PRINT_SLOT_TEXT,
	PNL_MAIN_BT_TRACA_SLOT_TEXT,
	PNL_MAIN_BT_CONFIG_TEXT,
	PNL_MAIN_TOP_PROD_TEXT,
	//PNL_MAIN_ACTIVE_LOG_TEXT,
	PNL_MAIN_TXT_INFO2_TEXT,
	PNL_MAIN_TXT_RESULT_TEXT,
	PNL_MAIN_SLOT_TEXT,
	PNL_VAR_TXT_TRACA_TEXT,
	PNL_VAR_STR_FILTRE_TEXT,
	PNL_VAR_CHK_FILTRE_TEXT,
	PNL_VAR_BTN_DEFAUT_TEXT,
	PNL_VAR_BTN_SAVE_TEXT,
	PNL_VAR_BTN_QUIT_TEXT,  
	PNL_BOUTON_TXT_INFO_ECRAN_OK_TEXT,
	PNL_BOUTON_TXT_INFO_ECRAN_KO_TEXT,
	//PNL_BOUTON_TXT_INFO_TEXT_DETAILS,
	PNL_BOUTON_TXT_INFO_TEXT,
	PNL_BOUTON_TXT_INFO_TEXT_HDD,
	PNL_BOUTON_TXT_INFO_TEXT_ECRAN,
	//PNL_INFO_TXT_MSG_CARD_RETIREZ,
	PNL_POPUP_CB_OUI_TEXT,
	PNL_POPUP_CB_NON_TEXT,
	PNL_POPUP_CB_OK_TEXT,
	PNL_POPUP_TEXT,
	PNL_POPUP_TXT_MSG_TEXT,
	PNL_PWD_ID,
	PNL_PWD_PWD,
	PNL_TRACA_TEXT,
	PNL_TRACA_TXT_TRACA_TEXT,
	PNL_TRACA_BTN_ENRG_TEXT,
	PNL_TRACA_BTN_QUIT_TEXT,
	IHM_ATTENTE_DECODEUR,
	IHM_DECODEUR_DETECTE,
	IHM_ATTENTE_DEMARRAGE_DECODEUR,
	IHM_DEPART_TEST,
	IHM_VERIFICATION_AUTORISATION_PASSAGE,
	IHM_LANCEMENT_SERVEUR_FTP,
	IHM_LECTURE_CHIPSET_ID,
	IHM_GENERATION_NUMSERIE,
	IHM_TEST_HDD,
	IHM_RETRAIT_HDD,
	IHM_TEST_PATINS_VIS,
	IHM_TEST_COULEUR,
	IHM_TEST_BOUTONS,
	IHM_TEST_LAME_MASSE,
	IHM_TEST_INFRAROUGE,
	IHM_TEST_RF,
	IHM_TEST_RF4CE,
	IHM_TEST_VENTILATEUR,
	IHM_TEST_VENTI_TACHY,
	IHM_TEST_CONSOMMATION,
	IHM_TEST_LED_PSOC,
	IHM_TEST_SMARTCARD,
	IHM_TEST_USB,
	IHM_TEST_SD_CARD,
	IHM_TEST_E_SATA,
	IHM_TEST_BR_HDMI,
	IHM_TEST_ECRAN,
	IHM_TEST_VISION_7_SEG,
	IHM_TEST_DOCSIS,
	IHM_TEST_FLASH_NAND,
	IHM_TEST_FLASH_NOR,
	IHM_TEST_NIM,
	IHM_TEST_VIDEO,
	IHM_TEST_CHECK_APPLI_TT,
	IHM_TEST_GET_STB_INFO,
	IHM_TEST_CHIPSET_TEMPERATURE,
	IHM_ECRITURE_FLASH,
	IHM_SECURISATION_TRACA,
	IHM_TEST_TT_CLIENT,
	IHM_TRACA_BDD,
	IHM_IMPRESSION_ETIQUETTE,
	IHM_PASSAGE_KO,
	IHM_TEST_FONCTIONNEL_TERMINE,
	IHM_PASSAGE_OK,
	IHM_TEST_TERMINE,
	IHM_ATTENTE_RETRAIT_DECODEUR,
	IHM_DECODEUR_VALIDE,
	IHM_DECODEUR_NON_VALIDE,
	IHM_SLOT_NUM,
	IHM_MODE_PROTO_SANS_DIO_WATT,
	IHM_MODE_PROTO_SANS_WATT,
	IHM_MODE_PROTO_SANS_DIO,
	IHM_MODE_PROTO,
	TFC_TTR_POPUP_QST_BOUTON,
	TFC_TTR_POPUP_QST_IR,
	TFC_TTR_POPUP_QST_ECRAN,
	TFC_TTR_POPUP_QST_VIDEO,
	HDD_TTR_POPUP_QST_HDD,
	FCT_TTR_POPUP_INF,
	FCT_TTR_POPUP_ERR,
	TFC_MSG_POPUP_QST_BOUTON,
	TFC_MSG_POPUP_QST_IR,
	TFC_MSG_POPUP_QST_ECRAN,
	TFC_MSG_POPUP_QST_VIDEO,
	HDD_MSG_POPUP_QST_HDD,
	FCT_MSG_POPUP_ERR_PROP_SFIN_NON_DEFINIE,
	FCT_MSG_POPUP_ERR_PROP_CIE_NON_DEFINIE,
	FCT_MSG_POPUP_ERR_MES_NON_DEFINIE,
	CLE_MSG_POPUP_ERR_MAC_CONSECUTIVES,
	CLE_MSG_POPUP_ERR_BSK,
	SMI_MSG_POPUP_ERR_1,
	SMI_MSG_POPUP_ERR_2,
	SMI_MSG_POPUP_ERR_3,
	SMI_MSG_POPUP_ERR_4,
	SMI_MSG_POPUP_ERR_5,
	GENERIQUE_MSG_POPUP_CODE,
	GENERIQUE_MSG_POPUP_PRESSE_PAPIER,
	GENERIQUE_TTR_POPUP,
	GENERIQUE_TTR_POPUP_ERR,
	DIO_TTR_POPUP,
	DIO_MSG_POPUP_1,
	DIO_MSG_POPUP_2,
	DIO_MSG_POPUP_3,
	DIO_MSG_POPUP_4,
//	DIO_MSG_POPUP_5,
//	DIO_MSG_POPUP_6,
//	DIO_MSG_POPUP_7,
	DIO_MSG_POPUP_8,
	DIO_MSG_POPUP_9,
	ZEB_TTR_POPUP,
	ZEB_MSG_POPUP_5,
	ZEB_MSG_POPUP_6,
	IHM_WATT_TTR_POPUP,
	IHM_WATT_MSG_POPUP_1,
	IHM_WATT_MSG_POPUP_2,
	IHM_WATT_MSG_POPUP_3,
	IHM_WATT_MSG_POPUP_4,
	IHM_WATT_MSG_POPUP_5,
	IHM_WATT_MSG_POPUP_6,
	IHM_QUANTUM_TTR_POPUP,
	IHM_QUANTUM_MSG_POPUP_1,
	IHM_COM_TTR_POPUP,
	IHM_COM_MSG_POPUP_1,
	IHM_COM_MSG_POPUP_2,
	IHM_BTN_TTR_POPUP,
	IHM_BTN_MSG_POPUP_1,
	IHM_BTN_MSG_POPUP_2,
	IHM_BTN_MSG_POPUP_3,
	IHM_TTR_POPUP_2,
	IHM_TTR_POPUP_3,
	IHM_MSG_POPUP_4,
	IHM_MSG_POPUP_5,
	//IHM_MSG_POPUP_6,
	IHM_MSG_POPUP_7,
	IHM_MSG_POPUP_8,
	VAR_MSG_POPUP_2,
	VAR_MSG_POPUP_3,
	VAR_MSG_POPUP_4,
	TRC_MSG_POPUP_1,
	MAI_TTR_POPUP,
	MAI_MSG_POPUP_1,
	MAI_MSG_POPUP_2,
	MAI_MSG_POPUP_3,
	MAI_MSG_POPUP_4,
	MAI_MSG_POPUP_6,
	MAI_MSG_POPUP_7,
	MAI_MSG_POPUP_8,
	MAI_MSG_POPUP_9,
	MAI_MSG_POPUP_10,
	MAI_MSG_POPUP_11,
	MAI_MSG_POPUP_12,
	MAI_MSG_POPUP_COPY_FONT,
	CAL_TTR_POPUP,
	FCT_TTR_POPUP_EMAIL_VAL,
	FCT_TTR_POPUP_EMAIL_ACT,
	FCT_MSG_ERR_VERSION_BPO_TOPPROD,
	IHM_TTR_LIB_SLOT,
	//IHM_TTR_ESS_IMP,
	IHM_MSG_LIB_SLOT,
	//IHM_MSG_ESS_IMP,
	IHM_BTN_OUI,
	IHM_BTN_NON,
	THR_TTR_EMAIL,
	THR_MSG_EMAIL,
	THR_LIBELLE_ERREUR_PATINS_VIS,
	THR_LIBELLE_ERREUR_COULEUR,
	THR_LIBELLE_ERREUR_LAME_MASSE,
	THR_LIBELLE_ERREUR_DEMARRAGE,
	THR_LIBELLE_ERREUR_AUTORISATION,
	THR_LIBELLE_ERREUR_LECTURE_NUID,
	THR_LIBELLE_ERREUR_PRISE_SN_CLIENT,
	THR_LIBELLE_ERREUR_ECRITURE_FLASH,
	THR_LIBELLE_ERREUR_TT_CLIENT,
	THR_LIBELLE_ERREUR_TRACA_PARA,
	THR_LIBELLE_ERREUR_TRACA,
	THR_LIBELLE_ERREUR_IMPRESSION,
	THR_LIBELLE_ERREUR_LOGO,
	THR_LIBELLE_ERREUR_LIBERATION_SLOT,
	THR_LIBELLE_ERREUR_FERMETURE_APPLI,
	THR_LIBELLE_ERREUR_LED,
	THR_LIBELLE_ERREUR_SMC_PRESENCE,
	THR_LIBELLE_ERREUR_USB,
	THR_LIBELLE_ERREUR_ESATA,
	THR_LIBELLE_ERREUR_SD_CARD,
	THR_LIBELLE_ERREUR_IR,
	THR_LIBELLE_ERREUR_RF,
	THR_LIBELLE_ERREUR_FLASH_NOR,
	THR_LIBELLE_ERREUR_FLASH_NAND,
	THR_LIBELLE_ERREUR_ECRAN,
	THR_LIBELLE_ERREUR_VISION_7_SEG,
	THR_LIBELLE_ERREUR_HDD,
	THR_LIBELLE_ERREUR_BOUTON,
	THR_LIBELLE_ERREUR_SMC_ABSENCE,
	THR_LIBELLE_ERREUR_EXTRACTION_HDD,
	THR_LIBELLE_ERREUR_CONSO_VENTILO,
	THR_LIBELLE_ERREUR_VENTI_TACHY,
	THR_LIBELLE_ERREUR_VENTILO,
	THR_LIBELLE_ERREUR_DOCSIS,
	THR_LIBELLE_ERREUR_NIM,
	THR_LIBELLE_ERREUR_VIDEO,
	THR_LIBELLE_ERREUR_HDMI,
	THR_LIBELLE_ERREUR_CHECK_APLLI_TT,
	THR_LIBELLE_ERREUR_TEST_GET_STB_INFO,
	THR_LIBELLE_ERREUR_TEST_CHIPSET_TEMPERATURE,
	THR_LIBELLE_ERREUR_LECTURE_CLE,
	FCT_LIBELLE_ERREUR_SN,
	FCT_LIBELLE_ERREUR_SN_NC,
	FCT_LIBELLE_ERREUR_SN_BYT,
	FCT_LIBELLE_ERREUR_SN_CHIL,
	FCT_LIBELLE_ERREUR_CODE_MATERIEL,
	FCT_LIBELLE_ERREUR_SN_VODA,
	FCT_LIBELLE_ERREUR_SN_CYFRA,
	FCT_LIBELLE_ERREUR_SN_DSI87SFR,
	FCT_LIBELLE_ERREUR_SN_M45,
	FCT_LIBELLE_ERREUR_SN_IAD84HA,
	FCT_LIBELLE_ERREUR_SN_DIGITURK,
	FCT_LIBELLE_ERREUR_SN_DCI85KDG,
	FCT_LIBELLE_ERREUR_SN_CLIENT,
	FCT_LIBELLE_ERREUR_VERIF_LOCK_FLASH,
	FCT_LIBELLE_ERREUR_CRYPT_HDD,
	FCT_LIBELLE_ERREUR_WRT_SN,
	FCT_LIBELLE_ERREUR_WRT_CERTIFICAT_SSL,
	FCT_LIBELLE_ERREUR_WRT_SN_NC,
	FCT_LIBELLE_ERREUR_WRT_SN_BYT,
	FCT_LIBELLE_ERREUR_WRT_SN_VODA,
	FCT_LIBELLE_ERREUR_WRT_SN_DSI87_SFR,
	FCT_LIBELLE_ERREUR_WRT_SN_DIGITURK,
	FCT_LIBELLE_ERREUR_WRT_SN_CLIENT,
	FCT_LIBELLE_ERREUR_ECRITURE_BADBLOCKS,
	FCT_LIBELLE_ERREUR_DESACTIV_ETHERNET,
	FCT_LIBELLE_ERREUR_WRT_CLES,
	FCT_LIBELLE_ERREUR_WRT_RECUP_NAGRA,
	FCT_LIBELLE_ERREUR_WRT_DOCSIS,
	FCT_LIBELLE_ERREUR_WOL,
	FCT_LIBELLE_ERREUR_UNICITE,
	FCT_LIBELLE_ERREUR_WRTTRACKING,
	FCT_LIBELLE_ERREUR_WRT_FLASH,
	FCT_LIBELLE_ERREUR_CONFIGURATION,
	FCT_LIBELLE_ERREUR_PARAMETRAGE,
	FCT_LIBELLE_ERREUR_CNX_TELNET_SWITCH,
	FCT_LIBELLE_ERREUR_PASSWORD_SWITCH,
	FCT_LIBELLE_ERREUR_VERSION_TT,
	FCT_LIBELLE_ERREUR_LECTURE_SN,
	FCT_LIBELLE_ERREUR_SFC_PARENT,
	FCT_LIBELLE_ERREUR_SFC_TROUVE,
	FCT_LIBELLE_ERREUR_RECUPERATION_SFC_PARENT,
	
	
	WRT_LIBELLE_ERREUR_WRT_HARDWARE_ID,
	WRT_LIBELLE_ERREUR_WRT_MANU_ID,
	WRT_LIBELLE_ERREUR_WRT_HARD_VERSION,
	WRT_LIBELLE_ERREUR_WRT_DWL_ID,
	WRT_LIBELLE_ERREUR_WRT_IP,
	WRT_LIBELLE_ERREUR_WRT_PATH,
	WRT_LIBELLE_ERREUR_WRT_CRYPT_FLUX,
	WRT_LIBELLE_ERREUR_WRT_CMD_FIN,
	WRT_LIBELLE_ERREUR_WRT_PRERECETTE,
	WRT_LIBELLE_ERREUR_WRT_SWITCH_TT_PANA,
	WRT_LIBELLE_ERREUR_WRT_CHECK_APPLI_PANA,
	WRT_LIBELLE_ERREUR_WRT_SWITCH_TO,
	WRT_LIBELLE_ERREUR_WRT_FORC_TEL,
	WRT_LIBELLE_ERREUR_WRT_EFFACEMENT_TT,
	WRT_LIBELLE_ERREUR_WRT_LOCK_FLASH,
	WRT_LIBELLE_ERREUR_WRT_REVERIF_LOCK_FLASH,
	WRT_LIBELLE_ERREUR_WRT_RECUP_PWD_JTAG,
	WRT_LIBELLE_ERREUR_WRT_LOCK_JTAG,
	WRT_LIBELLE_ERREUR_WRT_CHIP_PAIRING,
	WRT_LIBELLE_ERREUR_WRT_CRYPTOCORE,
	WRT_LIBELLE_ERREUR_WRT_FUSE_STATUS,
	WRT_LIBELLE_ERREUR_WRT_DRM_FUSE,
	WRT_LIBELLE_ERREUR_WRT_MES_FUSE,
	HDD_LIBELLE_ERREUR,
	HDD_LIBELLE_ERREUR_SN_HDD,
	HDD_LIBELLE_ERREUR_LEC_MODEL_HDD,
	HDD_LIBELLE_ERREUR_MODEL_HDD,
	HDD_LIBELLE_ERREUR_SIZE_HDD,
	HDD_LIBELLE_ERREUR_FIRMWARE_HDD,
	HDD_LIBELLE_ERREUR_RETRAIT1_HDD,
	HDD_LIBELLE_ERREUR_RETRAIT2_HDD,
	HDD_LIBELLE_ERREUR_SUP_DOUBLON,
	HDD_LIBELLE_ERREUR_HDD_EMBALLE,
	HDD_LIBELLE_ERREUR_VERIF_HDD_EMBALLE,
	HDD_LIBELLE_ERREUR_HDD_LOCK,
	HDD_LIBELLE_ERREUR_HDD_NON_LOCK,
	HDD_LIBELLE_ERREUR_PASSAGE_BHD,
	HDD_LIBELLE_ERREUR_PASSAGE_KO_BHD,
	HDD_LIBELLE_ERREUR_PARENTS_HDD,
	HDD_LIBELLE_ERREUR_VERIF_PASSAGE_BHD,
	HDD_LIBELLE_ERREUR_NOMENCLATURE_HDD,
	HDD_LIBELLE_ERREUR_CREATION_CIE_HDD,
	HDD_LIBELLE_ERREUR_FORMATAGE_SSD,
	HDD_LIBELLE_ERREUR_NON_LIEN_HDD,
	HDD_LIBELLE_ERREUR_PWD_UNIQUE,
	HDD_LIBELLE_ERREUR_TEST_PARTITIONS,
	HDD_LIBELLE_ERREUR_RECUP_PARTITIONS,
	CLE_LIBELLE_ERREUR_LECTURE,
	CLE_LIBELLE_ERREUR_ECRITURE,
	LIE_LIBELLE_ERREUR_LIEN,
	CLE_MSG_FIL2LO,
	FCT_MSG_FIL2LO,
	THR_MSG_FIL2LO,
	FIL2LO_STR_WARNING_LOCK_NDS,
	FIL2LO_STR_CONF_STB,
	FIL2LO_STR_TRACE_STB,
	FIL2LO_STR_RES_OK,
	FIL2LO_STR_RES_KO,
	FIL2LO_STR_DEBUT_TEST,
	FIL2LO_STR_FIN_TEST,
	FIL2LO_STR_ERREUR,
	FIL2LO_STR_DUREE_TEST,
	FIL2LO_STR_SOFT_VERSION,
	FIL2LO_STR_SN_CIE,
	FIL2LO_STR_CODE_PRODUIT,
	FIL2LO_STR_INDICE,
	FIL2LO_STR_SFIN_INDICE,
	FIL2LO_STR_LOADER,
	FIL2LO_STR_APPLISOFT,
	FIL2LO_STR_TT,
	FIL2LO_STR_NOMENCLATURE_HW,
	FIL2LO_STR_NOMENCLATURE_BOOT,
	//DIO_MSG_FIL2LO,
/*	THR_MSG_CONTEXT_LED_PSOC,
	THR_MSG_CONTEXT_SMARTCARD,
	THR_MSG_CONTEXT_USB,
	THR_MSG_CONTEXT_ESATA,
	THR_MSG_CONTEXT_SDCARD,
	THR_MSG_CONTEXT_IR,
	THR_MSG_CONTEXT_RF,
	THR_MSG_CONTEXT_FLASHNOR,
	THR_MSG_CONTEXT_FLASHNAND,
	THR_MSG_CONTEXT_ECRAN,
	THR_MSG_CONTEXT_HDD,
	THR_MSG_CONTEXT_BOUTONS,
	THR_MSG_CONTEXT_CONSO,
	THR_MSG_CONTEXT_VENTI_TACHY,
	THR_MSG_CONTEXT_VENTILO,
	THR_MSG_CONTEXT_DOCSIS,
	THR_MSG_CONTEXT_NIM,
	THR_MSG_CONTEXT_VIDEO,
	THR_MSG_CONTEXT_HDMI,
	THR_MSG_CONTEXT_CHECK_APPLI_TT,
	THR_MSG_CONTEXT_TEST_GET_STB_INFO,
	THR_MSG_CONTEXT_TEST_CHIPSET_TEMPERATURE,  */
	CLE_MSG_CONTEXT_LECTURE_CLE,
	//MAI_TTR_EMAIL_FERMETURE1,
	//MAI_TTR_EMAIL_FERMETURE2,
	CLE_TTR_EMAIL_CHECK_NUMBER,
	CLE_MSG_EMAIL_CHECK_NUMBER,
	CLE_TXT_DATE,
	CLE_TXT_HEURE,
	CLE_TXT_CODE_PRODUIT,
	CLE_TXT_INDICE,
	CLE_TXT_SN,
	ZEB_MSG_LOG_CAS_ID,
	ZEB_MSG_LOG_DATE,
	LIE_MSG_ACC_DEJA_LIE_AUTRE_DEC,
	LIE_MSG_ACC_DEJA_LIE,
	LIE_MSG_SUP_LIEN,
	LIE_MSG_DEC_DEJA_LIE,
	MES_MSG_MES_NON_RECONNU,
	MES_MSG_MES_ENREGISTREMENT,
	THR_MSG_ERR_DETECTION_VIS,
	THR_MSG_ERR_DETECTION_PATINS,
	THR_MSG_ERR_DETECTION_COULEUR,
	THR_MSG_DEMMARAGE,
	THR_MSG_AUTORISATION_PASSAGE,
	THR_MSG_ERR_THREAD_LOGO,
	THR_MSG_ERR_THREAD_TESTFONC,
	THR_MSG_ERR_THREAD_LECTUREBDD,
	THR_MSG_ERR_THREAD_SECURE,
	THR_MSG_ERR_THREAD_TRACA_PARA,
	THR_MSG_ECRITURE_FLASH,
	THR_MSG_SECURISATION_TRACA,
	THR_MSG_TEST_TT_CLIENT,
	THR_MSG_TRACA,
	THR_MSG_LIBERATION_SLOT,
	THR_MSG_ERR,
	THR_MSG_RETRAIT_STB,
	THR_MSG_ERR_DEVEROUILLAGE,
	THR_MSG_FIN_THREAD_LOGO,
	THR_MSG_FIN_THREAD_TESTFONC,
	THR_MSG_FIN_THREAD_LECTUREBDD,
	THR_MSG_FIN_THREAD_SECURISATION,
	THR_MSG_FIN_THREAD_TRACA_PARA,
	THR_MSG_ERR_NVM,
	THR_MSGL_DUREE_LOGO,
	WOL_MSG_SLEEP,
	WOL_MSG_ERR_ENVOIE,
	WOL_MSG_TIMEOUT,
	WOL_MSG_ERR_WOL1,
	WOL_MSG_ERR_WOL2,
	WOL_MSG_WOL_OK,
	VAR_MSG_ERR_VAR_INCONNU,
	VAR_MSG_ERR_VAR_ENREGISTREMENT1,
	VAR_MSG_ERR_VAR_ENREGISTREMENT2,
	VAR_MSG_ERR_PROP_SUP,
	VAR_MSG_ERR_VAR_UNIQUE_SUP1,
	VAR_MSG_ERR_VAR_UNIQUE_SUP2,
	//IHM_MSG_APPUYER_BTN,
	TRC_MSG_ERR_INCONNU,
	TRC_MSG_ERR_SN_NON_GENERE,
	TRC_MSG_ERR_CODE_PASSAGE,
	TRC_MSG_CODE_PASSAGE,
	TRC_MSG_ERR_CODE_DOUBLON,
	TRC_MSG_CODE_DOUBLON,
	TRC_MSG_SUP_DOUBLON,
	TRC_MSG_ERR_ALLOCATION_MEMOIRE,
	TRC_MSG_ERR_ECRITURE_CLE,
	CLE_MSG_VALEUR1,
	CLE_MSG_VALEUR2,
	CLE_MSG_NETTOYAGE1,
	CLE_MSG_NETTOYAGE2,
	CLE_MSG_NETTOYAGE3,
	CLE_MSG_NETTOYAGE4,
	CLE_MSG_LECTURE1,
	CLE_MSG_LECTURE2,
	CLE_MSG_LECTURE3,
	CLE_MSG_ECRITURE1,
	CLE_MSG_ECRITURE2,
	CLE_MSG_ECRITURE3,
	CLE_MSG_LIBERATION1,
	CLE_MSG_LIBERATION2,
	CLE_MSG_LIBERATION3,
	CLE_MSG_INFO_NAGRA1,
	CLE_MSG_INFO_NAGRA2,
	CLE_MSG_INFO_NAGRA3,
	CLE_MSG_INFO_NAGRA4,
	CLE_MSG_INDICE_CLES1,
	CLE_MSG_INDICE_CLES2,
	CLE_MSG_LECTURE_STBPWD,
	CLE_MSG_MISE_EN_FORME_HDCP,
	CLE_MSG_ECRITURE_NDS_DCI85KDG,
	CLE_MSG_ERREUR_VERIF_SMI1,
	CLE_MSG_ERREUR_VERIF_SMI2,
	CLE_MSG_ERREUR_NUM_CENTRE,  
	HDD_MSG_MODELE,
	HDD_MSG_SN,
	HDD_MSG_RESA_CLE_SN,
	HDD_MSG_LOCKAGE,
	HDD_MSG_TAILLE,
	HDD_MSG_FIRMWARE,
	HDD_MSG_PAIRING_OK,
	HDD_MSG_ERR_PAIRING_KO,
	HDD_MSG_PAIRING_SANS_LOCK_OK,
	HDD_MSG_ERR_PAIRING_SANS_LOCK_KO,
	HDD_MSG_PAIRING_PLUS_LOCK_OK,
	HDD_MSG_ERR_PAIRING_PLUS_LOCK_KO,
	HDD_MSG_DEJA_LOCKE,
	HDD_MSG_DELOCKAGE_KO,
	HDD_MSG_RELOCKAGE_KO,
	HDD_MSG_GENERATION_PWD_LOCK,
	HDD_MSG_PWD_DEJA_PRESENT,
	HDD_MSG_ERR_GENERATION_CLES_PAIRING,
	HDD_MSG_DEJA_EMBALLE,
	HDD_MSG_LOCKE_OK,
	HDD_MSG_NBR_SFIN_HDD,
	HDD_MSG_SN_SFIN_HDD,
	HDD_MSG_PASSAGE_KO_BHD,
	HDD_MSG_PASSAGE_OK_BHD,
	HDD_MSG_CREATION_SN_CIE_HDD,
	HDD_MSG_HDD_ABSENT_NOMENCLATURE,
	HDD_MSG_SN_CIE_HDD_DEJA_PRESENT,
	HDD_MSG_CODE_PRODUIT_CIE_HDD,
	HDD_MSG_ERR_CODE_PRODUIT_HDD,
	HDD_MSG_TEST_PARTITIONS,
	HDD_MSG_TEST_PARTITIONS_OK,
	HDD_MSG_PRES_PARTITION,
	HDD_MSG_ABS_PARTITION,
	HDD_MSG_BLOCS_PARTITION_OK,
	HDD_MSG_BLOCS_PARTITION_NOK,
	HDD_MSG_TYPE_PARTITION_OK,
	HDD_MSG_TYPE_PARTITION_NOK,
	TFC_MSG_PAT1_DETECTE,
	TFC_MSG_PAT2_DETECTE,
	TFC_MSG_PAT3_DETECTE,
	TFC_MSG_PAT4_DETECTE,
	TFC_MSG_PAT5_DETECTE,
	TFC_MSG_VIS1_DETECTEE,
	TFC_MSG_VIS2_DETECTEE,
	TFC_MSG_VIS3_DETECTEE,
	TFC_MSG_VIS4_DETECTEE,
	TFC_MSG_COUL1_DETECTE,	
	TFC_MSG_DEMSTB_ERR_COM,
	TFC_MSG_DEMSTB_DEM_CHRONO,
	TFC_MSG_DEMSTB_ERR_PREALIMENTATION,
	TFC_MSG_DEMSTB_ERR_CMD_TT_INIT,
	TFC_MSG_VTL_OFF,
	TFC_MSG_CONSO_PW,
	TFC_MSG_VTL_ON,
	TFC_MSG_VTL_OK,
	TFC_MSG_VTL_ERR_KO,
	TFC_MSG_CONSO_VTL,
	TFC_MSG_VTL_ERR_CONSO,
	TFC_MSG_CONSO_ERR_LECTURE,
	TFC_MSG_BTN_ERR_ACTIVATION,
	TFC_MSG_BTN_ERR_DESACTIVATION,
	TFC_MSG_BTN_CONF_NB_APPUIS,
	TFC_MSG_BTN_CONF_ORDRE,
	TFC_MSG_BTN_CONF_SIMULTANE,
	TFC_MSG_BTN_OK,
	TFC_MSG_BTN_OUVERTURE_POP_UP,
	TFC_MSG_BTN_FERMETURE_POP_UP,
	TFC_MSG_BTN_ERR_DATE,
	TFC_MSG_BTN_ERR_TIMEOUT,
	TFC_MSG_BTN_ERR_SIMULTANE,
	TFC_MSG_BTN_ERR_DESORDRE,
	TFC_MSG_BTN_ERR_KO, 
	TFC_MSG_IR_TOUCHE_OK,
	TFC_MSG_IR_RF_TOUCHE_ROUGE,
	TFC_MSG_IR_CODE_RECU,
	TFC_MSG_IR_RF_CODE_RECU_SFR,
	TFC_MSG_IR_ERR, 
	TFC_MSG_IR_OUVERTURE_POP_UP,
	TFC_MSG_IR_FERMETURE_POP_UP,
	TFC_MSG_RF_ERR_PW,
	TFC_MSG_RF_ERR_PASSAGE_PROTOCOLE_RF,
	TFC_MSG_RF_ERR_PASSAGE_RF,
	TFC_MSG_RF_ERR_SYNCWORD,
	TFC_MSG_RF_ERR_MODULE,
	TFC_MSG_RF_ERR,
	TFC_MSG_USB_INSERTION,
	TFC_MSG_USB_DETECTION,
	TFC_MSG_USB_ERR,
	TFC_MSG_SD_INSERTION,
	TFC_MSG_SD_DETECTION,
	TFC_MSG_SD_ERR_CMDTT,
	TFC_MSG_SD_ERR,
	TFC_MSG_NAND_ID,
	TFC_MSG_NAND_ERR_ID_NONCONFORME,
	TFC_MSG_NAND_ERR_ID,
	TFC_MSG_NAND_TAILLE,
	TFC_MSG_NAND_ERR_TAILLE_NONCONFORME,
	TFC_MSG_NAND_ERR_TAILLE,
	TFC_MSG_NAND_ERR,
	TFC_MSG_CARD_INSERTION,
	TFC_MSG_CARD_ERR_DETECTION,
	TFC_MSG_CARD_DETECTION,
	TFC_MSG_CARD_RETIREZ,
	TFC_MSG_CARD_ERR_RETRAIT,
	TFC_MSG_CARD_RETRAIT,
	TFC_MSG_DOCSIS_ERR_VERSION_NONLUE,
	TFC_MSG_DOCSIS_ERR_VERSION_DIFF,
	TFC_MSG_DOCSIS_ERR_VERSION_SOFT,
	TFC_MSG_DOCSIS_ERR_ADRESSE_NONLUE,
	TFC_MSG_DOCSIS_ERR_ADRESSE,		
	TFC_MSG_DOCSIS_ERR_ADRESSE_BDD,	
	TFC_MSG_EMTA_ERR_ADRESSE_BDD,	
	TFC_MSG_SSID_ERR_LECTURE,		
	TFC_MSG_SSID_ERR_BDD,			
	TFC_MSG_SSID_ERR_MASQUE,
	TFC_MSG_ECRAN_ERR,
	TFC_MSG_VISION_FRONTS_ERR,
	TFC_MSG_NIM_ERR_SN,
	TFC_MSG_NIM_ERR_VAR_SN,
	TFC_MSG_NIM_ERR_SN_INCONNU,
	TFC_MSG_NIM_CIE,
	TFC_MSG_NIM_ERR,
	TFC_MSG_INFO_VERSION_APPLI,
	TFC_MSG_INFO_HARDWARE,
	TFC_MSG_VIDEO_FLUX_ERR,
	TFC_MSG_VENTILO_CAPTEUR_OK,
	TFC_MSG_VENTILO_CAPTEUR_KO,
	TFC_MSG_VENTILO_CAPTEUR_ERREUR,
	TFC_MSG_VENTILO_OK,
	TFC_MSG_VENTILO_SENS_KO,
	TFC_MSG_VENTILO_PRESENCE_KO,
	TFC_MSG_GET_STB_INFO_VERSION_APPLI,
	TFC_MSG_GET_STB_INFO_VERSION_HARDWAREID,
	TFC_MSG_INITIALISATION_SWITCH_OK,
	TFC_MSG_LECTURE_VERSION_OK,
	TFC_MSG_LECTURE_SN_OK,
	TFC_MSG_VERIF_VERSION_FIRMWARE_OK,
	TFC_MSG_VERIF_VERSION_FIRMWARE_KO,
	TFC_MSG_INITIALISATION_OK,
	TFC_MSG_DRIVER_2G_KO,
	TFC_MSG_DRIVER_5G_KO,
	TFC_MSG_TEST_BOUTON_OK,
	TFC_MSG_Configuration_IR_OK,
	TFC_MSG_Configuration_IR_KO,
	TFC_MSG_TEST_IR_OK,
	TFC_MSG_TEST_IR_KO,
	TFC_MSG_TEST_LED_OK,
	TFC_MSG_Configuration_2G_OK,
	TFC_MSG_Configuration_2G_KO,
	TFC_MSG_Mesures_2G_OK,
	TFC_MSG_ERREUR_Nbre_NUM_SWITCH_2G,
	TFC_MSG_ERREUR_SWITCH_PORT_SP8T,
	TFC_MSG_ERREUR_ACTIVATION_2G,
	TFC_MSG_ERREUR_CONFIGURATION_POWERMETER,
	TFC_MSG_ERREUR_CONFIGURATION_BDD,
	TFC_MSG_ERREUR_MESURE_2G,
	TFC_MSG_ERREUR_NBRE_ANTENNES_2G,
	TFC_MSG_ERREUR_CONF_2G_NON_EXIST,
	TFC_MSG_Configuration_5G_OK,
	TFC_MSG_Configuration_5G_KO,
	TFC_MSG_Mesures_5G_OK,
	TFC_MSG_ERREUR_Nbre_NUM_SWITCH_5G,
	TFC_MSG_ERREUR_ACTIVATION_5G,
	TFC_MSG_ERREUR_MESURE_5G,
	TFC_MSG_ERREUR_NBRE_ANTENNES_5G,
	TFC_MSG_ERREUR_CONF_5G_NON_EXIST,	
	TFC_MSG_Configuration_BT_OK,
	TFC_MSG_Configuration_BT_KO,
	TFC_MSG_Mesures_BT_OK,
	TFC_MSG_ERREUR_Nbre_NUM_SWITCH_BT,
	TFC_MSG_ERREUR_ACTIVATION_BT,
	TFC_MSG_ERREUR_MESURE_BT,
	TFC_MSG_ERREUR_NBRE_ANTENNES_BT,
	TFC_MSG_ERREUR_CONF_BT_NON_EXIST,
	TFC_MSG_FINALISATION_OK,
	TFC_MSG_FINALISATION_KO,
	TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST,
	TFC_MSG_TRACABILITE_OK,
	TFC_MSG_TRACABILITE_KO,
	TFC_MSG_PERTE_PROMPT_OK,
	TFC_MSG_PERTE_PROMPT_KO,
	TFC_MSG_ERREUR_BRANCHEMENT_POWERMETER,
	TFC_MSG_ERREUR_TYPE_POWERMETER,
	TFC_MSG_ATTENTE_PING,
	
	
	
	FCT_MSG_CODE_PRODUIT_EXISTE_DIFFERENT,
	FCT_MSG_GENE_SN_VIDE_NOGENE,
	FCT_MSG_GENE_SN_UNDEF_BYT,
	FCT_MSG_GENE_SN_UNDEF_CHILI,
	FCT_MSG_GENE_CODEMATERIEL_UNDEF,
	FCT_MSG_GENE_SN_UNDEF_VODA,
	FCT_MSG_GENE_SN_UNDEF_CYFRA,
	FCT_MSG_GENE_SN_UNDEF_DSI87,
	FCT_MSG_GENE_SN_UNDEF_M45,
	FCT_MSG_GENE_SN_UNDEF_IAD84HA,
	FCT_MSG_GENE_SN_UNDEF_DIGITURK,
	FCT_MSG_GENE_SN_CLIENT,
	FCT_MSG_TRACABDD_STRING,
	FCT_MSG_PASS_KO_BDD_SNCIE,
	FCT_MSG_NO_START,
	FCT_MSG_TRACABDD_KO_STRING,
	FCT_MSG_SN_TESTENCOURS,
	FCT_MSG_MAUVAISE_VERSION_CIE,
	FCT_MSG_VERSION_CIE_PASENFLASH,
	FCT_MSG_MAUVAIS_INDICE_CIE,
	FCT_MSG_INDICE_CIE_PASENFLASH,
	FCT_MSG_MAUVAIS_MASQUE_CIE,
	FCT_MSG_SERIAL_CIE_PASENFLASH,
	FCT_MSG_MAUVAIS_LOADER,
	FCT_MSG_MAUVAISE_NOMENCLATURE_HARD,
	FCT_MSG_MAUVAISE_NOMENCLATURE_BOOT,
	FCT_MSG_MAUVAISE_FULL_SALES_TYPE,
	FCT_MSG_SN_CIE_STRING,
	FCT_MSG_TEST_AUTORISATION,
	FCT_MSG_PASSAGE_NON_AUTORISE,
	FCT_MSG_VERIF_FLASH_LOCKE,
	FCT_MSG_CRYPTAGE_DONNEES_HDD,
	FCT_MSG_CRYPTAGE_DONNEES_HDD_INHIBE,
	FCT_MSG_ECRITURE_SN_SAGEM,
	FCT_MSG_ECRITURE_SN_SSL,
	FCT_MSG_PASDECRITURE_SNCLIENT,
	FCT_MSG_ECRITURE_SN_BYT,
	FCT_MSG_ECRITURE_SN_VODA,
	FCT_MSG_PASDECRITURE_SN_CYFRA,
	FCT_MSG_PASDECRITURE_SN_CHILI,
	FCT_MSG_ECRITURE_SN_DSI87,
	FCT_MSG_ECRITURE_SN_DIGITURK,
	FCT_MSG_ECRITURE_SN_CLIENT,
	FCT_MSG_ECRITURE_BADBLOCKS,
	FCT_MSG_DESACTIVATION_ETHERNET,
	FCT_MSG_ECRITURE_DES_CLES,
	FCT_MSG_ECRITURE_SETMAC_DOCSIS,
	FCT_MSG_TEST_WAKEONLAN,
	FCT_MSG_MAJ_PROPRIETES_DEBUT,
	FCT_MSG_MAJ_PROPRIETES_FIN,
	FCT_MSG_FILTRE_UNICITE,
	FCT_MSG_ECRITURE_WRITETRACKING, 
	FCT_MSG_SECURISATION,
	FCT_MSG_TRACABILITE_MESURE,
	FCT_MSG_TRACABILITE_HDD,
	FCT_MSG_TRACABILITE_COLLECT,
	FCT_MSG_TRACABILITE_ASSEMBLE,	  
	FCT_MSG_ECRITURE_WRITETRACKING_INHIBE,
	//FCT_MSG_ECRITURE_FLASH_SKIPPE,
	FCT_MSG_CIE_SN_NON_REMONTE,
	FCT_MSG_CIE_INDICE_NON_REMONTE,
	FCT_MSG_CIE_CODE_PRODUIT_NON_REMONTE,
	FCT_MSG_LOADER_NON_REMONTE,
	FCT_MSG_TT_NON_REMONTE,
	FCT_MSG_NOMENCLATURE_HW_NON_REMONTE,
	FCT_MSG_NOMENCLATURE_BOOT_NON_REMONTE,
	FCT_MSG_FULL_SALES_TYPE_NON_REMONTE,
	FCT_MSG_VARIABLE_STRING_NON_DEFINIE,
	FCT_MSG_ERR_RECUP_VAR_TRACA,
	FCT_MSG_ERR_CMDTT_TIMEOUT,
	FCT_MSG_ERR_CMDTT_FAIL,
	FCT_MSG_ERR_CMDTT_NON_TROUVE_STRING,
	FCT_MSG_ERR_CMDTT_STRING,
	FCT_MSG_ERR_CMDTT_ECHO1,
	FCT_MSG_ERR_CMDTT_ECHO2,
	FCT_MSG_ERR_CMDTT_ECHO3,
	FCT_MSG_CMDTT_ECHO_NO_AFF,
	FCT_MSG_CMDTT_ECHO_OK,	
	FCT_MSG_CHECK_NUMBER_STRING,
	FCT_MSG_ERREUR_DE_COM,
	FCT_MSG_DIFF_CHIPSETID_MASQUE,
	FCT_MSG_ERR_LECT_UNIQUEID_STRING,
	FCT_MSG_ERR_LECT_FLASH_ID_STRING,
	FCT_MSG_ERR_LECT_CHIP_IDENT_STRING,
	FCT_MSG_LIST_CIE_NOM,
	FCT_MSG_LIST_CIE_REF,
	FCT_MSG_LIST_CIE_IND,
	FCT_MSG_LIST_SFIN_NOM,
	FCT_MSG_LIST_SFIN_REF,
	FCT_MSG_LIST_SFIN_IND,
	FCT_MSG_LIST_PFIN_NOM,
	FCT_MSG_LIST_PFIN_REF,
	FCT_MSG_LIST_PFIN_IND,   
	//FCT_MSG_OUVRIR_FICHIER_IMPOSSIBLE,
	//FCT_MSG_CREER_FICHIER_IMPOSSIBLE,
	FCT_MSG_RESULT_SFC_PFIN,
	FCT_MSG_RESULT_SFC_CIU,
	FCT_MSG_SAPME_REF_CMS,
	FCT_MSG_SAPME_TYPE_CMS,
	FCT_MSG_SAPME_REF_INTEG,
	FCT_MSG_SAPME_TYPE_INTEG,
	FCT_MSG_RESULT_SN_CIE,
	FCT_MSG_RESULT_VERSION_CIE,
	FCT_MSG_RESULT_INDICE_CIE,		
	FCT_MSG_RESULT_POSTE_TRACACOM,
	FCT_MSG_RESULT_OPR_POSTE_SAP_ME,
	FCT_MSG_RESULT_RSC_POSTE_SAP_ME,
	FCT_MSG_RESULT_OPR_PRINT_SAP_ME,
	FCT_MSG_RESULT_RSC_PRINT_SAP_ME,
	FCT_MSG_RESULT_CHIPSET_ID,
	FCT_MSG_RESULT_CODE_AUTORISATION,
	FCT_MSG_RESULT_LIBELLE_ERREUR,
	FCT_MSG_ERR_CREATION_CMDTT,
	FCT_MSG_ERR_DYNMEMINFO,
	FCT_MSG_ERR_POSTE_SLOT,
	FCT_MSG_ERR_MESSAGE,
	FCT_MSG_ERR_ENVOI_EMAIL,
	FCT_MSG_TT_CLIENT_NON_REMONTE,
	FCT_MSG_ADR_BASE_TRACA_NON_REMONTE,
	FCT_MSG_HARDWARE_ID_NON_REMONTE,
	FCT_MSG_USAGE_ID_NON_REMONTE,
	FCT_MSG_SFIN_SN_NON_REMONTE,
	FCT_MSG_ERR_PROVIS_C_PLUS,
	WRT_MSG_NAGRA_UNIQUE_ID_PB_LEN,
	WRT_MSG_NAGRA_UNIQUE_ID_PB_FMT,
	WRT_MSG_NAGRA_UNIQUE_ID_PB_SN,
	WRT_MSG_NAGRA_STB_CA_SN_PB_FMT,
	WRT_MSG_NAGRA_CRC_PB_FMT,
	WRT_MSG_CHECK_NUMBER_PB_FMT,
	WRT_MSG_CSCDATA_CHECK_NUMBER_PB_FMT,
	WRT_MSG_ERR_WRITENAGRALOG,
	WRT_MSG_ERR_WTR_SN,
	WRT_MSG_ECRITURE_SN_FIN,
	WRT_MSG_ERR_DOCSIS,
	WRT_MSG_DOCSIS,
	WRT_MSG_ECRITURE_DOCSIS_SETMAC_ERR,
	WRT_MSG_ECRITURE_DOCSIS_SETMAC_FIN,
	WRT_MSG_FLASH_VERIF_LOCK,
	WRT_MSG_FLASH_PAS_LOCKEE,
	WRT_MSG_FLASH_BIEN_LOCKEE,
	WRT_MSG_FLASH_LOCK_PWD_GENERIC,
	WRT_MSG_FLASH_PASSER_PWD,
	WRT_MSG_FLASH_DELOCK_OK_FIN,
	WRT_MSG_FLASH_PASSAGE_PWD,
	WRT_MSG_FLASH_LOCKAGE_OK,
	WRT_MSG_FLASH_LOCKAGE,
	WRT_MSG_FLASH_VERIF_AFTER_STD,
	WRT_MSG_ERREUR_CLE_STB,
	WRT_MSG_CHIPSET_NON_SECURSIE,
	WRT_MSG_CHIPSET_EST_SECURISE,
	WRT_MSG_CRYPTAGE_HDD,
	WRT_MSG_ETH_FERMETURE_PORT,
	WRT_MSG_ETH_DESACTIVER,
	WRT_MSG_ECRITURE_HW_ID,
	WRT_MSG_ECRITURE_MAN_ID,
	WRT_MSG_ECRITURE_HW_VERSION,
	WRT_MSG_ECRITURE_DWNLD_ID,
	WRT_MSG_ECRITURE_IP_SERVEUR_DL,
	WRT_MSG_ECRITURE_FICHIER_DL,
	WRT_MSG_CRYPTAGE_FLUX_DL,
	WRT_MSG_ERREUR_TT_FINALISATION,
	WRT_MSG_ACTIVE_CUSTOM_PRERECETTE,
	WRT_MSG_ACTIVE_CUSTOM_UNDEF,
	WRT_MSG_SWITCH_TT_PANA,
	WRT_MSG_FORCAGE_TT_TO_APPLI,
	WRT_MSG_FORCAGE_TELECHARGEMENT,
	WRT_MSG_EFFACE_ZONE_TT,
	WRT_MSG_CHIPSET_PAIRING,
	WRT_MSG_LOCKAGE_JTAG,
	WRT_MSG_ACTIVE_CRYPTOCORE,
	WRT_MSG_FUSIBLE_DRM,
	WRT_MSG_ERREUR_WRITETRACKING,
	WRT_MSG_ERREUR_SECURISATION,
	WRT_MSG_ERREUR_WTR_SSLSN,
	WRT_MSG_ECRITURE_SSLSN_FIN,
	WRT_MSG_FUSES_ERREUR_VERIF,
	WRT_MSG_FUSES_CONFIRM_VERIF,
	WRT_MSG_FUSES_ACTIV_OK,
	WRT_MSG_FUSES_ACTIV_SKIPPE,
	WRT_MSG_FUSES_DESACTIV_OK,
	WRT_MSG_FUSES_DESACTIV_SKIPPE,
	WRT_MSG_STATUS_JTAG,
	WRT_MSG_STATUS_DSC,
	WRT_MSG_STATUS_CW,
	WRT_MSG_FUSIBLE_MES,
	WRT_MSG_PWD_FLASH_KO,
	WRT_MSG_PWD_FLASH_OK,
	WRT_MSG_NOVERIF_PWD_FLASH,
	WRT_MSG_SECTEUR_FLASH_LOCK_KO,
	WRT_MSG_SECTEUR_FLASH_LOCK_OK,
	WRT_MSG_PROP_SFIN,
	TNT_BBX_MSG_INIT,
	TNT_BBX_MSG_WARNING,
	TNT_BBX_MSG_ERREUR,
	TNT_BBX_MSG_TERMINATE,
	TNT_BBX_MSG_NEW_STB,
	TNT_BBX_MSG_CONNECT_ID,
	TNT_BBX_MSG_DIAGNOSTIC,
	TNT_BBX_MSG_NVM_PREPARE,
	TNT_BBX_MSG_NVM_GET,
	TNT_BBX_MSG_DISCONNECT,
	TNT_BBX_MSG_TEMPS,
	TNT_BBX_MSG_NVM_LIT_CLE,
	TNT_BBX_MSG_DIAGNOSTIC_TITRE,
	TNT_BBX_MSG_DIAGNOSTIC_CMD,
	TNT_BBX_MSG_NVM_ANNULE_TITRE,
	TNT_BBX_MSG_NVM_CANCEL,
	TNT_BBX_MSG_STRING_TO_BCD,
	TNT_BBX_MSG_PREPARE_CHIPSET_ID,
	TNT_BBX_MSG_NO_ERR_MSG,
	TNT_BBX_MSG_WARNING_NO_FCT_CALL,
	TNT_BBX_MSG_WARNING_CHIPSET_UNKNOWN,
	TNT_BBX_MSG_WARNING_NO_COMPUTATION,
	TNT_BBX_MSG_WARNING_PROJECTID_UNKNOWN,
	TNT_BBX_MSG_WARNING_COMPUTATION_DONE,
	TNT_BBX_MSG_WARNING_WAIT_RESPONSE,
	TNT_BBX_MSG_WARNING_COMPUTATION_LOST,
	TNT_BBX_MSG_WARNING_WRONG_NVM_SIZE,
	TNT_BBX_MSG_ERROR_INIT_LIBRARY,
	TNT_BBX_MSG_ERROR_CLIENT_CANT_LOAD,
	TNT_BBX_MSG_ERROR_NO_CONFIG_FILE,
	TNT_BBX_MSG_ERROR_CANT_READ_CONFIG,
	TNT_BBX_MSG_ERROR_CANT_CONNECT,
	TNT_BBX_MSG_ERROR_CONNECTION_LOST,
	TNT_BBX_MSG_ERROR_MAX_CONNECTIONS,
	TNT_BBX_MSG_ERROR_BAD_PROTOCOL,
	TNT_BBX_MSG_ERROR_UNKNOWN_SESSION_ID,
	TNT_BBX_MSG_ERROR_INTERNAL,
	TNT_BBX_MSG_ERROR_CANT_TERMINATE,
	TNT_BBX_MSG_ERROR_INVALID_PARAMETER,
	TNT_BBX_MSG_ERROR_NO_ERROR,
	TNT_BBX_MSG_GETBBXERRORSTRING,
	TNT_BBX_MSG_DISK_STATUS_OK,
	TNT_BBX_MSG_DISK_STATUS_LOW,
	TNT_BBX_MSG_DISK_STATUS_FULL,
	TNT_BBX_MSG_DISK_STATUS_UNKNOWN,
	TNT_BBX_MSG_RAID_STATUS_OK,
	TNT_BBX_MSG_RAID_STATUS_NOREDUNDANT,
	TNT_BBX_MSG_RAID_STATUS_UNKNOWN,
	TNT_BBX_MSG_POWER_STATUS_OK,
	TNT_BBX_MSG_POWER_STATUS_NOREDUDANT,
	TNT_BBX_MSG_POWER_STATUS_UNKNOWN,
	TNT_BBX_MSG_FAIL_STATUS_OK,
	TNT_BBX_MSG_FAIL_STATUS_DOWN,
	TNT_BBX_MSG_FAIL_STATUS_UNKNOWN,
	TNT_BBX_MSG_GETBBXDIAGSTRING,
	TNT_BBX_MSG_NVM_TRACE,
	MAI_MSG_POPUP_14,
}T_LANGUES_INDEX; 

#endif  // #ifndef __MULTILANGUE_H__  
