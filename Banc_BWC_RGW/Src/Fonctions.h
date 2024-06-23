// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//  
// 
// ==============================================================================
//   PROJET			: Banc Personnalisation
//   MODULE			: Fonctions
//   PROCESSEUR		: INTEL Pentium
//   ENVIRONNEMENT	: Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION	: Définition des fonctions utiles à l'application Perso.
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
// 17-Novembre-2009	NCR (DT2E)
//		>>>	 Création
// ==============================================================================
#ifndef __FONCTIONS_H__
#define __FONCTIONS_H__


// ==============================================================================
// DEFINITION DES CONSTANTES
// ==============================================================================

#define FCT_PRINT_TAILLE_MAX			50000
#define TIME_OUT_COMMUNICATION			"Time out"		       
// ==============================================================================
// DECLARATION DES PROTOTYPES
// ==============================================================================

// Fonction de vérification de chaine vide
// ---------------------------------------
#define FCT_STRING_IS_EMPTY(x)		((x)[0] == '\0' ? TRUE : FALSE)


// Nombre de tentative de connexion aux Ports Com WATT - STB - autres
// -----------------------------------------------------------------
#define WATT_NB_TENTATIVE_CONNEXION                2
#define STB_NB_TENTATIVE_CONNEXION                 3
#define COM_NB_TENTATIVE_CONNEXION                 2
#define TST_NB_MAX_LEDS_FEASA				5							// Nombre maximum de leds testables via Module Feasa


// ------------------------------------------------------------------------------
// FONCTIONS D'ACCES A LA BASE TRACACOM
// ------------------------------------------------------------------------------
//extern int FCT_GenerationSn ( int nItfe, char *strErreurMessage );
extern int FCT_TracaBddKo ( int nItfe );
extern int FCT_TracaBdd ( int nItfe );
extern int FCT_AutorisationPassage (int nItfe, char *strErreurMessage ) ;
extern int FCT_PropietesEtatInit ( int nItfe );

// ------------------------------------------------------------------------------
// FONCTIONS D'INTERFACE AVEC L'IHM
// ------------------------------------------------------------------------------
extern void FCT_AfficheInfo ( int nItfe, int mode, int codeErr, ... );
extern void FCT_GetIdPoste ( char *sIDPoste, int maxIdSize ) ;
extern void FCT_GetVersionInfo (char *filePath, char *strVersion);
extern void FCT_AfficheVersionAppli ( char *appName, int panelHnd );

// ------------------------------------------------------------------------------
// FONCTIONS DE GESTION MEMOIRE
// ------------------------------------------------------------------------------
extern void FCT_InfoMemoire(int nItfe, char *step); 

// ------------------------------------------------------------------------------
// FONCTIONS D'INTERFACE AVEC LE DECODEUR
// ------------------------------------------------------------------------------
extern int FCT_RecupCommandeTT ( int nItfe, int idPort, char *BufferAttendu, char *chBufferLu, unsigned long *taille_recu, int TimeOut, short *erreur, long *codeErreur, char *messagErreur );
extern int FCT_EnvoiCommandeTT ( int nItfe, int idPort, char *BufferCommande, int AffichageTrace, short *erreur, long *codeErreur, char *messagErreur );
extern int FCT_EnvoiCommandeTTAvecVerifRetour ( int nItfe, int idPort, char *BufferCommande, char *BufferAttendu, char *chBufferLu, unsigned long *taille_recu, int TimeOut, int AffichageTrace, short *erreur, long *codeErreur, char *messagErreur );

extern int FCT_CmdTTExtract (char *cmdIn, T_TAB_CMD *cmdOut );
extern int FCT_CmdExecution (int nItfe, int iHandleTelnet, T_CMD *cmdTT, char ***info, int *nbInfo, int timeout); 
extern int FCT_CmdComExecutionV3 (int nItfe, int AffichageTrace, char *chCmdTT, char ***info, int *nbInfo, char *chTrace, int timeout);
extern int FCT_CmdComExecutionV5 (int nItfe, int AffichageTrace, char *chCmdTT, char ***info, int *nbInfo, char *chTrace, int timeout);
extern int FCT_CmdComExtract (char *cmdIn, T_TAB_CMD *cmdOut);
extern void FCT_RemplacerEscapeSequence ( char *chValeur ); 

extern int FCT_TestHdd (int nItfe, char *strErreurMessage);
extern int FCT_AppairageLockageHDD (int nItfe, char *strErreurMessage);

extern int FCT_clean_atapi(int nItfe, int AffichageTrace, char *messagErreur);
extern int FCT_ecoute_com(int nItfe, int AffichageTrace, char *messagErreur); 

// ------------------------------------------------------------------------------
// FONCTIONS DIVERS
// ------------------------------------------------------------------------------
extern int	FCT_RechercheTag ( char *chBuffer, char *chTag, char *chRetour );
extern int  FCT_Comm_Attente_Fermeture_Caisson (int nItfe) ;
//extern int  FCT_CMD_PingGateWay (int nItfe, char *messagErreur);
extern int  FCT_AttenteDemarrageGateWay_telnet (int nItfe, char *messagErreur);
extern int  FCT_RecuperationVariableTraca (int nItfe, char *strErreurMessage) ;
extern int	FCT_MasqueValidation ( char *chMasque, char *chValeur );
extern void FCT_SupprimerTag ( char *chValeur, char *chTag );
extern void FCT_RemplacerTag ( char *chValeur, int nTaille, char *chTagOld, char *chTagNew );
extern int	FCT_ProduitPrint( T_POSTE_PRODUIT *tPosteProduit, char *strPrint, char *strMessageErreur);

// ------------------------------------------------------------------------------
// FONCTIONS DE GESTION DE LA STRUCTURE DE TRACA
// ------------------------------------------------------------------------------
extern int	FCT_TracaInit( T_VARIABLES_TRACA *tVariablesTraca );
extern int	FCT_TracaRaz( T_VARIABLES_TRACA *tVariablesTraca );
extern int	FCT_TracaPrint( T_VARIABLES_TRACA *tVariablesTraca, char *strPrint, char *strMessageErreur);
extern int  FCT_ProduitsRaz ( T_POSTE_PRODUITS *posteProduits );

extern int COM_RechercheTag(int, unsigned char *, unsigned long, unsigned char, unsigned char *, unsigned long *, unsigned long *, int *);

extern int  FCT_ChercherTag(int nItfe,char *Tag,int iTimeOut);  
extern int  FCT_RecupSnSfin(int nItfe,char *Tag,char *Sn);

extern int FCT_VerificationVariables( int nItfe, char *strMessage);

extern int  FCT_VerificationSFC (int nItfe, char *SFC, char *CodeProduit, char *IndiceProduit, char *ReferenceOF, char *OF_SAPME, char *strMessage );
extern int  FCT_VerificationSFC_MultiOF_CMS (int nItfe, char *SFC, char *CodeProduit, char *IndiceProduit, char *strMessage ); 
 
// Fonctions ping GateWay
extern int FCT_CMD_PingGateWay (int nItfe, char *messagErreur);
extern int FCT_LectureNumserieGateWay(int nItfe, char *chMessageErreur);  

extern int FCT_AutorisationPassageSAPME (int nItfe,char *strErreurMessage, char *dfa) ;   
extern int Test_button(int HandleTelnet,char cmd [1024], int TimeOut,char Tag [1024],char SignalDio[64], char sMessage [50001])    ;
extern int OuvertureTelnet(char sIPDUT[255],char sLogin[255],char sPreFixLogin[255],char sSuFixLogin[255],char sPassword[255],char sSuFixPassword[255], int TimeOut) ;  
extern int Test_button_RC(int HandleTelnet,char cmd [1024], int TimeOut,char Tag [1024],char SignalDio[64],int IndiceCMMO, char sMessage [50001])    ;

extern int LectureDFAviaTelnet (int HandleTelnet, char *SendCmd,int LengthDFA,int TimeOutms,  char *sDFALue ,char *sMessage); 
extern int AFficheMsgErreur(int iErreur, char * sMessage ) ;
extern int TelnetOpenSession (int *HandleTelnet, char *IPFAST, int NumPort, char *Login, char *TagLogin, char *Psw,char * TagPassword , char *Response ) ;
extern int FCT_CloseConnexionTelnet (int nItfe, char	*chMessageErreur, int HandleTelnet );
extern int  TelnetCloseSession_slot2(int HandleTelnet,char *Response) ;
//extern int  FCT_CloseConnexionTelnet (int nItfe, char    *chMessageErreur, int HandleTelnet );

extern int FCT_Initialisation(int nItfe, char *messagErreur); 
extern int FCT_Config_Wifi_2G (int nItfe, char	*chMessageErreur ); 
extern int FCT_Config_Wifi_5G (int nItfe, char	*chMessageErreur );
extern int FCT_EnvoieLogBdd( int nItfe); 
extern int FCT_Assemblage_fille_mere (int nItfe, char	*strErreurMessage );
extern int FCT_ControleVersion (void);
extern int FCT_OuverturePortsCOM ( int nItfe );  
extern int FCT_Lecture_Version (int nItfe, char	*chMessageErreur );
extern int FCT_Config_BT (int nItfe, char	*chMessageErreur );
extern int FCT_Mesure_BT (int nItfe, char	*chMessageErreur );
extern int FCT_reboot (int nItfe, char	*chMessageErreur );
extern int FCT_FermeturePortsCOM ( int nItfe, char *strErreurMessage );
extern int FCT_VerificationVariables( int nItfe, char *chMessErreur);
extern int FCT_Finalisation (int nItfe, char	*chMessageErreur );
extern int FCT_Config_IR (int nItfe, char	*chMessageErreur );
extern int FCT_Send_IR (int nItfe, char	*chMessageErreur );
extern int FCT_VerifChipsetId (int nItfe, char	*chMessageErreur );
extern int TST_Leds_Feasa (int nItfe, char	*chMessageErreur );
extern int FCT_CmdComExecutionInstSansRetour (int nItfe, int idPort, int ParamRX, int ParamTX, int AffichageTrace, char *chCmdTT, char ***info, int *nbInfo, char *chTrace, int timeout);
extern int FCT_Verification_version_Firmware(int nItfe, char *chMessageErreur);
extern int Connect_Switch_SP8T (int nItfe, char	*chMessageErreur );
extern int FCT_Switch (int nItfe, char	*chMessageErreur );
extern int FCT_CmdComExecutionV4 (int nItfe,int HandleTelnet ,int AffichageTrace, char *chCmdTT, char ***info, int *nbInfo, char *chTrace, int timeout);
extern int FCT_Switch_SP8T (int nItfe, char	*chMessageErreur, char *PortSwitch );
extern int FCT_AttenteDemarrageGateWay (int nItfe, char *messagErreur);
extern int FCT_Test_Bouton (int nItfe, char	*chMessageErreur );
extern int FCT_Test_IR (int nItfe, char	*chMessageErreur );
extern int FCT_Mesure_Wifi_2G (int nItfe, char	*chMessageErreur );
extern int FCT_Mesure_Wifi_5G (int nItfe, char	*chMessageErreur );
extern int FCT_AttentePertePingGateWay (int nItfe, char *messagErreur);
extern int FCT_Comm_Attente_Fermeture_Caisson(int nItfe);
extern int FCT_Comm_Caisson_Open (int nItfe) ;
extern int FCT_Comm_Init_Caisson(int nItfe) ;
extern int FCT_Check_Driver_wifi_2Ghz(int nItfe, char	*chMessageErreur );
extern int FCT_Update_Driver_wifi_2Ghz(int nItfe, char	*chMessageErreur );
extern int FCT_Check_Driver_wifi_5Ghz(int nItfe, char	*chMessageErreur );
extern int FCT_TEST_wifi_6Ghz(int nItfe, char	*chMessageErreur );
extern int FCT_Update_Driver_wifi_5Ghz(int nItfe, char	*chMessageErreur );
extern int FCT_Update_Driver_wifi_5_2Ghz(int nItfe, char	*chMessageErreur );
extern int FCT_Check_Driver_BT(int nItfe, char	*chMessageErreur );
extern int FCT_Update_Driver_BT(int nItfe, char	*chMessageErreur );
extern int FCT_UPDATE_IP_DUT(int nItfe, char	*chMessageErreur ) ;
extern int FCT_TEST_wifi_2Ghz(int nItfe, char	*chMessageErreur ) ;
extern int FCT_TEST_wifi_5Ghz(int nItfe, char	*chMessageErreur ) ;
extern int FCT_TEST_BT(int nItfe, char	*chMessageErreur ) ;
extern int FCT_PingSTB (int nItfe, char *messagErreur) ;
extern int FCT_Rcup_Mesure_log(int nItfe, FILE* fichier ,char*tabMesure,char*chMessageErreur  );
extern int FCT_EnregistrementMesure (int nItfe) ;
extern int FCT_EnregistrementMesureLog (int nItfe,char ** tab) ;
extern int FCT_TAMPON (int nItfe ) ;
extern int FCT_OpenConnexionTelnet(int nItfe, char *messagErreur) ;




extern  int FCT_GenerationDFA (int nItfe, char *strErreurMessage );
extern int FCT_Flachage (int nItfe, char	*chMessageErreur, char *SFC_Flache  )  ;
extern int SAPME_GenerationDFA ( int nItfe, T_TCOM_BASE *tcomBase, char *REF, int *iExistenceSFC, char *strErreurMessage );



extern  int  FCT_EcritureDFA (int nItfe, char	*chMessageErreur );


extern int FCT_Activation_DHCP(int nItfe, char	*chMessageErreur );
extern int FCT_Desactivation_DHCP(int nItfe, char	*chMessageErreur );
extern int FCT_Remonte_SFTP(int nItfe, char	*chMessageErreur );
extern int  IHM_GestCtrlPnl_V2(int nItfe, char NomTest [200] );
extern int FCT_LanceTFTP (void);
#endif	// #ifndef __FONCTIONS_H__





