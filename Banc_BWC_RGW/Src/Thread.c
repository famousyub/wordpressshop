// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
// ==============================================================================
//   PROJET			: Banc BNFT
//   MODULE			: Thread
//   PROCESSEUR		: INTEL Pentium
//   ENVIRONNEMENT	: Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION	: Définition des tâches de gestion des test fonctionnel
//					  et accés aux bases de données.
// 		V 1.1.0
// 		15-Décembre-2009			EAH
//		>>>	 Création issue du banc de personnalisation
// ==============================================================================
// INCLUDE
// ==============================================================================
#include "IhmNFT.h"
#include <userint.h>
#include "Include.h"

// ==============================================================================
// DECLARATION DES VARIABLES GLOBALES
// ================================!==============================================

// Gestion Multitache
// ------------------
int IdPrinter;					   // Verrou pour accès à l'imprimante en multithreads
int IdSnClient;					   // Verrou pour accès au serveur BDD en multithreads
int IdLockCle;					   // Verrou pour accès au serveur BDD en multithreads
int iTIME_OUT_MAX = 300000 ;	   // TimeOut Max
int iTIME_OUT_IP_MAX = 10000;	   // TimeOut Max IP
static int g_exeHandle;
// ==============================================================================
// DECLARATION DES VARIABLES LOCALES
// ==============================================================================

// Multitache pour le test
// -----------------------
HANDLE HdleThreadTestFonc;
HANDLE HdleThreadLectureBdd;
DWORD IdThreadTestFonc;
DWORD IdThreadLectureBdd;

// variables pour la gestion du timer HDD : 10s mini repositionnement tête de lecture
// ----------------------------------------------------------------------------------
time_t tDepartTimer;									// départ du timer
time_t tFinTimer;										// fin du timer
double difference;										// temps calculé
// Pour la gestion de test de concoordance etiquette
int  iQuit;
int  iNumSlot;
int  iListeSnScannee[20];
char strNumserie[16][20];

clock_t startTestGlobal=0;

// ==============================================================================
// DECLARATION DES FONCTIONS
// ==============================================================================
//int __stdcall ThreadChargerLogoZebra (void * data);

// ==============================================================================
// FONCTION : 	  ThreadSlot
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int __stdcall ThreadSlot (void * data)
// ------------------------------------------------------------------------------
// DESRIPTION :   Thread principale.
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :		1.1.0
//  DATE :			15/12/2009
//  AUTEUR :		EAH
//  DESCRIPTION :	Création issue de la personnalisation STB
// ==============================================================================
int __stdcall ThreadSlot (void * data)
{
	T_SLOT				*tSlot = (T_SLOT*)data;
	T_VARIABLES			*ptrVariablesConf 	= &tSlot->variablesConf;
	T_VARIABLES			*ptrVariablesEtat 	= &tSlot->variablesEtat;
	T_VARIABLES			*ptrVariablesConfSn = &tSlot->variablesConfSn;
	T_VARIABLES_TRACA	*ptrVariablesTraca 	= &tSlot->variablesTraca;
	T_MESURES			*ptrMesures = &tSlot->mesures;
	T_POSTE_PRODUIT		*ptrProduit = &gPosteProduits.produits[ptrVariablesTraca->idxProduit];

	int	nItfe=tSlot->id;
	int	error=0;
	int	status=0;
	int	resultatTest=0;

	char Message[50001]="";
	char trace[9600] = {'\0'};
	char strErreurMessage[TAILLE_MAX] = {'\0'};

	int    Temps_Test = 0;
	char   Temps_Test_char[TAILLE_MIN] = "";
	clock_t startTimer=0;
	int iNumBytWritten=0;
	char  chBufferLuTmp[TAILLE_MAX] = {"\0"};
	char Response [300]="";
	//status = TelnetOpenSession (&gSlot[nItfe].igHandleConnexion, "192.168.5.1", 23, "", "", "", "", Response);
	//status = InetTelnetWrite (&gSlot[nItfe].igHandleConnexion , "telnet 192.168.5.1",  "\r\n", -1, &iNumBytWritten, 1000);
	//status = InetTelnetReadUntil(gSlot[nItfe].igHandleConnexion, chBufferLuTmp, sizeof (chBufferLuTmp) - 1, "f5359p login:", 1000);


	// =========================================
	// = Gestion des propriétes et des mesures =
	// =========================================

	// Extraction des variables d'état de la BDD
	// -----------------------------------------
	if ( VAR_Get ( gVariablesEtat, gNbVariablesEtat,
				   ptrVariablesEtat,
				   gTcomBase.instSCProduction,
				   NULL,
				   gPosteProduits.produits[ptrVariablesTraca->idxProduit].cie.chVersion,
				   gPosteProduits.produits[ptrVariablesTraca->idxProduit].cie.chIndice,
				   gPosteInfos.chNom,
				   strErreurMessage) )
		errChk(-1);

	// Extraction des variables de mesure de la BDD
	// --------------------------------------------
	if ( MES_Get ( ptrMesures, gTcomBase.instSCProduction,
				   gPosteProduits.produits[ptrVariablesTraca->idxProduit].cie.chVersion,
				   gPosteProduits.produits[ptrVariablesTraca->idxProduit].cie.chIndice,
				   gPosteInfos.chNom,
				   nItfe,
				   gSlot[nItfe].comDecodeur.iHandle,
				   strErreurMessage) )
		errChk(-1);

	SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
	SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
	// ==============================================================================
	// = Boucle qui permet le test de N hdd tant que l'on ne ferme pas le programme =
	// ==============================================================================
	while (gNPAbort == FALSE)
	{

		FIL2LO_VerifDateChemin (gSlot[nItfe].id);

#ifdef CONTROLEMEMOIRE  // Analyse fuite mémoire
		FCT_InfoMemoire( nItfe, "0" );
#endif

#ifdef NO_AUTORISATION
		FIL2LO_PrintEtape (nItfe, "!! PAS DE VERIFICATION D'AUTORISATION DE PASSAGE !!");
#endif

		// RAZ des variables / mesures / clés...
		// -------------------------------------
		FCT_TracaRaz (ptrVariablesTraca);
		MES_Reset (ptrMesures);
		//CLE_Raz (ptrCles);
		VAR_Raz (ptrVariablesEtat);
		VAR_Delete (ptrVariablesConfSn);


		// Affichage dans le LOG des paramètres de configuration du disque
		FIL2LO_PrintDebut (nItfe);
		gSlot[nItfe].ihmSlot.nEtat = ETAT_INIT_IHM;

		IHM_GestCtrlPnl (nItfe);
		gSlot[nItfe].ihmSlot.nEtat = ETAT_FLACHAGE_SFC;
		//	IHM_GestCtrlPnl (nItfe);
		if(gSlot[nItfe].BNFTnteg.gchFlagTraca)
		{
			SetCtrlVal (PnlPere, PNL_PERE_LED_TRACA, TRUE);
			SetCtrlAttribute ( PnlPere, PNL_PERE_LED_TRACA, ATTR_ON_COLOR, VAL_GREEN);
		}
		else
		{
			SetCtrlVal (PnlPere, PNL_PERE_LED_TRACA, TRUE);
			SetCtrlAttribute ( PnlPere, PNL_PERE_LED_TRACA, ATTR_ON_COLOR, VAL_RED);
		}

		SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_DEPANNAGE, ATTR_VISIBLE, 0);
		SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_RETEST, ATTR_VISIBLE, 0);
		SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_LABEL_TEXT, "");


		/////******

		// ======================================================================================
		// = Flachage SFC          												=
		// =====================================================================================

		if ((gSlot[nItfe].ihmSlot.nEtat == ETAT_FLACHAGE_SFC) && (gNPAbort == FALSE))
		{
			if (VAR_GET_BOOL(ptrVariablesConf, VAR_CONF_GTW_BWC_FLAG_sfc, 0) == 1)
			{
				IHM_GestCtrlPnl(nItfe);
				FCT_AfficheInfo(nItfe, IHM_MODE_TRACE_TXTBOX | IHM_MODE_TRACE_LOG, 999, "Flachage ");
				status = FCT_Flachage(nItfe, strErreurMessage, ptrVariablesTraca->OxNumSerie);
				strcpy(ptrVariablesTraca->CiuSfcSAPME,ptrVariablesTraca->OxNumSerie);
				FCT_AfficheInfo(nItfe, IHM_MODE_TRACE_TXTBOX | IHM_MODE_TRACE_LOG, 999, ptrVariablesTraca->OxNumSerie);

				if (status == 0)
				{
					FCT_AfficheInfo(nItfe, IHM_MODE_TRACE_TXTBOX | IHM_MODE_TRACE_LOG, 999, "Flachage SFC OK");
					gSlot[nItfe].ihmSlot.nEtat = ETAT_AUTORISATION_PASSAGE;
				}
				else
				{
					// !!! On ne crée pas un passage KO en cas de non autorisation de passage !!!
					FCT_AfficheInfo(nItfe, IHM_MODE_TRACE_TXTBOX | IHM_MODE_TRACE_LOG, 999, strErreurMessage);
					strcpy(ptrVariablesTraca->chLibelleErreur, strErreurMessage);
					SetCtrlVal(gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, ptrVariablesTraca->chLibelleErreur);
					resultatTest = FALSE;
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl(nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

				}
			}
			else
			{
				gSlot[nItfe].ihmSlot.nEtat = ETAT_AUTORISATION_PASSAGE;
			}

			if (gNPAbort == TRUE)
			{
				gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
			}
		}

		// ======================================================================================
		// = Attente Fermeture Caisson	           												=
		// ======================================================================================

		if ( (gSlot[nItfe].ihmSlot.nEtat != ETAT_STOP) && (gNPAbort == FALSE) )
		{
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "Attente Fermeture Caisson");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Attente Fermerture caisson");

			FCT_Comm_Attente_Fermeture_Caisson (nItfe) ;
		}
		// ======================================================================================
		// = Autorisation de Passage	           												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_AUTORISATION_PASSAGE) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_BOOL(ptrVariablesConf, VAR_CONF_GTW_BWC_FLAG_sfc, 0) == 1)
			{
				if(gSlot[nItfe].BNFTnteg.gchFlagTraca)
				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_AutorisationPassage (nItfe, strErreurMessage);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(THR_MSG_AUTORISATION_PASSAGE));
						//gSlot[nItfe].ihmSlot.nEtat = ETAT_Update_IP_DUT;
						gSlot[nItfe].ihmSlot.nEtat = ETAT_DECODEUR_PRESENT;
					}
					else
					{
						SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_LABEL_TEXT,strErreurMessage );
						// // 	// !!! On ne crée pas un passage KO en cas de non autorisation de passage !!!
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, strErreurMessage);
						strncpy (strErreurMessage, "",TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_PERTE_PING;


					}
				}
				else
					gSlot[nItfe].ihmSlot.nEtat = ETAT_DECODEUR_PRESENT;
			}
			else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_DECODEUR_PRESENT;

		}

		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

		// ======================================================================================
		// = Attente Demarrage GateWay                                                          =
		// ======================================================================================
		while (	(gSlot[nItfe].ihmSlot.nEtat == ETAT_DECODEUR_PRESENT) && (gNPAbort == FALSE) )
		{
			IHM_GestCtrlPnl (nItfe);

			//
			if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_GTW_BWC_FLAG_Eth,0))
			{
				//	status = FCT_AttenteDemarrageGateWay (nItfe, strErreurMessage);
				status = FCT_AttenteDemarrageGateWay_telnet (nItfe, strErreurMessage);
				//	status = FCT_AttenteDemarrageGateWay_telnet;
			}
			if (status==0)
			{
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(IHM_DEPART_TEST));
				//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Demarrage produit OK");
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Demarrage Carte OK");
				Sleep(200);
				gSlot[nItfe].ihmSlot.nEtat = ETAT_CONNEXION_TELNET;
				strcpy (strErreurMessage, "");
				gSlot[nItfe].nTempsDebutTest = GetTickCount ();	// Mise à jour du Chrono de temps de test
			}
			else
			{
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "Demarrage Carte KO");
				strcpy (ptrVariablesTraca->chLibelleErreur, "Carte pas démarré");
				Sleep(3000);
				resultatTest = FALSE;
				gSlot[nItfe].ihmSlot.nEtat = ETAT_DECODEUR_PRESENT;
				strcpy (strErreurMessage, "");
			}

			if (gNPAbort==TRUE)
				gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
		}


		//Delay (1);

		// ======================================================================================
		// = Connexion Telnet                   												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_CONNEXION_TELNET) && (gNPAbort == FALSE) )
		{
			IHM_GestCtrlPnl (nItfe);
			Sleep(200);
			status = FCT_OpenConnexionTelnet (nItfe, strErreurMessage);
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
			if (status==0)
			{
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Connexion Telnet OK");
				gSlot[nItfe].ihmSlot.nEtat = ETAT_ACTIVATION_DHCP;
			}
			else
			{
				// !!! On ne crée pas un passage KO en cas de non autorisation de passage !!!
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
				strcpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage);
				resultatTest = FALSE;
				gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
				IHM_GestCtrlPnl (nItfe);
				gSlot[nItfe].ihmSlot.nEtat = ETAT_PERTE_PING;
				strcpy (strErreurMessage, "");

			}
		}

		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

		Delay (1);

		// ======================================================================================
		// = Activation DHCP                 												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_ACTIVATION_DHCP) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_BOOL(ptrVariablesConf, VAR_CONF_GTW_BWC_FLAG_DHCP, 0) == 1)
			{
				IHM_GestCtrlPnl (nItfe);
				Sleep(200);
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Activation DHCP");
				status = FCT_Activation_DHCP (nItfe, strErreurMessage);
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
				if (status==0)
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Activation DHCP OK");
					gSlot[nItfe].ihmSlot.nEtat = ETAT_ECRITURE_DFA;
				}
				else
				{
					// !!! On ne crée pas un passage KO en cas de non autorisation de passage !!!
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
					strcpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage);
					resultatTest = FALSE;
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_PERTE_PING;
					strcpy (strErreurMessage, "");

				}
			}
			else
			{
				gSlot[nItfe].ihmSlot.nEtat = ETAT_ECRITURE_DFA;
			}

		}


		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

		Delay (1);






		/*
		// ======================================================================================
		// = Déactivation DHCP                  												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_DESACTIVATION_DHCP) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_BOOL(ptrVariablesConf, VAR_CONF_GTW_BWC_FLAG_DHCP, 0) == 1)
			{

				IHM_GestCtrlPnl (nItfe);
				Sleep(200);
				status = FCT_Desactivation_DHCP (nItfe, strErreurMessage);
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
				if (status==0)
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Connexion Telnet OK");
					gSlot[nItfe].ihmSlot.nEtat = ETAT_ECRITURE_DFA;
				}
				else
				{
					// !!! On ne crée pas un passage KO en cas de non autorisation de passage !!!
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
					strcpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage);
					resultatTest = FALSE;
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_PERTE_PING;
					strcpy (strErreurMessage, "");

				}
			}
		}
		{
			gSlot[nItfe].ihmSlot.nEtat = ETAT_LECTURE_DFA_GATEWAY;
		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

		Delay (1);


		*/
		// ======================================================================================
		// = Ecriture DFA          												=
		// =====================================================================================

		if ((gSlot[nItfe].ihmSlot.nEtat == ETAT_ECRITURE_DFA) && (gNPAbort == FALSE))
		{
			if (VAR_GET_BOOL(ptrVariablesConf, VAR_CONF_GTW_BWC_FLAG_sfc, 0) == 1)
			{
				IHM_GestCtrlPnl(nItfe);
				FCT_AfficheInfo(nItfe, IHM_MODE_TRACE_TXTBOX | IHM_MODE_TRACE_LOG, 999, "Ecriture DFA ");
				status =FCT_EcritureDFA (nItfe, strErreurMessage);
				FCT_AfficheInfo(nItfe, IHM_MODE_TRACE_TXTBOX | IHM_MODE_TRACE_LOG, 999, ptrVariablesTraca->OxNumSerie);

				if (status == 0)
				{
					FCT_AfficheInfo(nItfe, IHM_MODE_TRACE_TXTBOX | IHM_MODE_TRACE_LOG, 999, "Ecriture DFA OK");
					gSlot[nItfe].ihmSlot.nEtat = ETAT_LECTURE_DFA_GATEWAY;
				}
				else
				{
					// !!! On ne crée pas un passage KO en cas de non autorisation de passage !!!
					FCT_AfficheInfo(nItfe, IHM_MODE_TRACE_TXTBOX | IHM_MODE_TRACE_LOG, 999, strErreurMessage);
					strcpy(ptrVariablesTraca->chLibelleErreur, strErreurMessage);
					SetCtrlVal(gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, ptrVariablesTraca->chLibelleErreur);
					resultatTest = FALSE;
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
				}
			}
			else
			{
				gSlot[nItfe].ihmSlot.nEtat = ETAT_LECTURE_DFA_GATEWAY;
			}

			if (gNPAbort == TRUE)
			{
				gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
			}
		}



		// ======================================================================================
		// = Lecture DFA mére                       											=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_LECTURE_DFA_GATEWAY) && (gNPAbort == FALSE) )
		{
			if(VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_GTW_BWC_FLAG_DFA_MERE,0))
			{
				if((VAR_DEFINED(ptrVariablesConf,VAR_CONF_GTW_BWC_Lecture_DFA_MERE) == TRUE) && (VAR_DEFINED(ptrVariablesConf,VAR_CONF_GTW_BWC_Nombre_Char_DFA_MERE) == TRUE) && (VAR_DEFINED(ptrVariablesConf,VAR_CONF_GTW_BWC_TAG_DFA_MERE) == TRUE))
				{
					IHM_GestCtrlPnl (nItfe);

					status = FCT_LectureNumserieGateWay(nItfe,strErreurMessage);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Lecture DFA carte OK");
						gSlot[nItfe].ihmSlot.nEtat =ETAT_AUTORISATION_PASSAGE;
					}
					else
					{
						// !!! On ne crée pas un passage KO en cas de non autorisation de passage !!!
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						strcpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage);
						SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, ptrVariablesTraca->chLibelleErreur);
						resultatTest = FALSE;
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_PERTE_PING;
						strcpy (strErreurMessage, "");

					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "CONF DFA MERE n'existe pas");
					strcpy (ptrVariablesTraca->chLibelleErreur, "CONF DFA MERE n'existe pas");
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO,"CONF DFA MERE n'existe pas");
					resultatTest = FALSE;
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_PERTE_PING;
				}

			}
			else
				gSlot[nItfe].ihmSlot.nEtat =ETAT_AUTORISATION_PASSAGE;
			//	gSlot[nItfe].ihmSlot.nEtat = ETAT_FLACHAGE_DFA;

		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

		// ======================================================================================

		/*
			// ======================================================================================
			// = Attente Demarrage Decodeur                                                         =
			// ======================================================================================
			while ((gSlot[nItfe].ihmSlot.nEtat == ETAT_DECODEUR_PRESENT) && (gNPAbort == FALSE) )
			{   strncpy (msg_erreur_persiste, "",TAILLE_MAX-1);
				IHM_GestCtrlPnl (nItfe);

				if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_eth,0))
				{

				status = FCT_AttenteDemarrageGateWay_telnet (nItfe, strErreurMessage);

				}
				else
				{
				status = FCT_AttenteDemarrageGateWay (nItfe, strErreurMessage);
				}
				if (status==0)
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(IHM_DEPART_TEST));
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Demarrage produit OK");
					gSlot[nItfe].ihmSlot.nEtat = ETAT_CONNEXION_TELNET;
					strncpy (strErreurMessage, "",TAILLE_MAX-1);
					gSlot[nItfe].nTempsDebutTest = GetTickCount ();	// Mise à jour du Chrono de temps de test
				}
				else
				{
					Sleep(2000);
					strncpy (strErreurMessage, "",TAILLE_MAX-1);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_DECODEUR_PRESENT;
				}

				if (gNPAbort==TRUE)
					gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
			}

			// ======================================================================================
			// = Connexion Telnet                   												=
			// ======================================================================================
			if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_CONNEXION_TELNET) && (gNPAbort == FALSE) )
			{
				if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_eth,0))
				{
				   IHM_GestCtrlPnl (nItfe);

				   status = FCT_OpenConnexionTelnet (nItfe, strErreurMessage);
				   FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
				   if (status==0)
				   {
					 FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Connexion Telnet OK");
					 gSlot[nItfe].ihmSlot.nEtat = ETAT_INIT;
				   }
				   else
				   {
					// !!! On ne crée pas un passage KO en cas de non autorisation de passage !!!
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
					strcpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage);

					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_PERTE_PING;
					strcpy (strErreurMessage, "");

					}
				}
				else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_INIT;
			}

			if (gNPAbort==TRUE)
				gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

			Delay (1);

				*/
		// ======================================================================================
		// = Initialisation 			                                                =
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_INIT) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_Initialisation,0))
			{
				if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_INITIALISATION) == TRUE)
				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_Initialisation(nItfe, strErreurMessage);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,GET_MESSAGE(TFC_MSG_INITIALISATION_OK) );
						gSlot[nItfe].ihmSlot.nEtat = ETAT_RECUP;
					}
					else
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);

						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "conf_DEC_BWC_INITIALISATION n'existe pas");
					strncpy (strErreurMessage, "",TAILLE_MAX-1);
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO,"conf_DEC_BWC_INITIALISATION n'existe pas");
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
			}
			else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_RECUP;
		}

		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
		// ======================================================================================
		// = RECUPERATION des info 			                                                =
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_RECUP) && (gNPAbort == FALSE) )
		{

			if((VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_RECUP_SN) == TRUE)&&(VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_RECUP_TT) == TRUE))
			{
				IHM_GestCtrlPnl (nItfe);
				status = FCT_RecuperationVariableTraca(nItfe, strErreurMessage);
				if (status==0)
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,GET_MESSAGE(TFC_MSG_INITIALISATION_OK) );
					gSlot[nItfe].ihmSlot.nEtat = ETAT_AUTORISATION_PASSAGE;
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
					strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
				}
			}
			else
			{
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "conf_DEC_BWC_INITIALISATION n'existe pas");
				strncpy (strErreurMessage, "",TAILLE_MAX-1);
				SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO,"conf_DEC_BWC_INITIALISATION n'existe pas");
				gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
				IHM_GestCtrlPnl (nItfe);
				gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
			}
		}


		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

		// ======================================================================================
		// = Autorisation de Passage	           												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_AUTORISATION_PASSAGE) && (gNPAbort == FALSE) )
		{
			if (!VAR_GET_BOOL(ptrVariablesConf, VAR_CONF_GTW_BWC_FLAG_sfc, 0) == 1)
			{
				if(gSlot[nItfe].BNFTnteg.gchFlagTraca)
				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_AutorisationPassage (nItfe, strErreurMessage);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(THR_MSG_AUTORISATION_PASSAGE));
						gSlot[nItfe].ihmSlot.nEtat = ETAT_Check_Driver_2Ghz;

					}
					else
					{
						SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_LABEL_TEXT,strErreurMessage );
						// // 	// !!! On ne crée pas un passage KO en cas de non autorisation de passage !!!
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, strErreurMessage);
						strncpy (strErreurMessage, "",TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;


					}
				}
				else
					gSlot[nItfe].ihmSlot.nEtat = ETAT_Check_Driver_2Ghz;
			}
			else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_Check_Driver_2Ghz;

		}

		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

		// ======================================================================================
		// = Update IP DUT         												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_Update_IP_DUT) && (gNPAbort == FALSE) )
		{

			if((VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Interface_Eth_DUT) == TRUE)&&(VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Interface_IP_DUT) == TRUE))
			{
				IHM_GestCtrlPnl (nItfe);
				status = FCT_UPDATE_IP_DUT(nItfe, strErreurMessage);
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
				if (status==0)
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"Update adress IP OK" );
					gSlot[nItfe].ihmSlot.nEtat = ETAT_Check_Driver_2Ghz;
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
					strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
				}
			}
			else
			{
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
				//strncpy (ptrVariablesTraca->chLibelleErreur,  "CONF_DEC_BWC_CMD_Interface_Eth_DUT ou CONF_DEC_BWC_CMD_Interface_IP_DUT",TAILLE_MAX-1);
				//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
				gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
				IHM_GestCtrlPnl (nItfe);
				gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
			}
		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
		// ======================================================================================
		// = Check_Driver_2Ghz         												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_Check_Driver_2Ghz) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_Check_Driver_2Ghz,0))
			{
				if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Check_Driver_2Ghz) == TRUE)
				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_Check_Driver_wifi_2Ghz(nItfe, strErreurMessage);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"Check Driver WIFI 2Ghz OK" );
						gSlot[nItfe].ihmSlot.nEtat = ETAT_Update_Driver_2Ghz;
					}
					else
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					strncpy (ptrVariablesTraca->chLibelleErreur,  "CONF_DEC_BWC_CMD_Check_Driver_2Ghz",TAILLE_MAX-1);
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
			}

			else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_Update_Driver_2Ghz;
		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
		// ======================================================================================
		// = Update Driver wifi 2Ghz        												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_Update_Driver_2Ghz) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_Update_Driver_2Ghz,0))
			{
				if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Update_Driver_2Ghz) == TRUE)
				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_Update_Driver_wifi_2Ghz(nItfe, strErreurMessage);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"Update et check update Driver WIFI 2Ghz OK" );
						gSlot[nItfe].ihmSlot.nEtat = ETAT_Ping_DUT;
					}
					else
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					strncpy (ptrVariablesTraca->chLibelleErreur,  "CONF_DEC_BWC_CMD_Update_Driver_2Ghz",TAILLE_MAX-1);
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
			}

			else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_Ping_DUT;
		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
		// ======================================================================================
		// = Ping DUT       												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_Ping_DUT) && (gNPAbort == FALSE) )
		{
			if ((VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_PING,0)) && ((VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_GTW_BWC_FLAG_Eth,0)==0)))
			{
				if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_PING_DUT) == TRUE)
				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_PingSTB(nItfe, strErreurMessage);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"Ping DUT OK" );
						gSlot[nItfe].ihmSlot.nEtat = ETAT_TEST_WIFI_2Ghz;
					}
					else
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					strncpy (ptrVariablesTraca->chLibelleErreur,  "CONF_DEC_BWC_CMD_PING_DUT",TAILLE_MAX-1);
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
			}

			else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_TEST_WIFI_2Ghz;
		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;


		// ======================================================================================
		// = TEST wifi 2Ghz        												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_TEST_WIFI_2Ghz) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_GTW_BWC_Flag_test_2Ghz,0))
			{
				if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_GTW_BWC_CMD_TEST_2Ghz) == TRUE)
					//if(TRUE == TRUE)
				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_TEST_wifi_2Ghz(nItfe, strErreurMessage);


					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"TEST wifi 2Ghz OK" );
						//gSlot[nItfe].ihmSlot.nEtat = ETAT_cmd_exit_2Ghz;




						gSlot[nItfe].ihmSlot.nEtat = ETAT_TEST_WIFI_5Ghz;
					}
					else
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					strncpy (ptrVariablesTraca->chLibelleErreur,  "CONF_DEC_BWC_CMD_Check_Driver_2Ghz",TAILLE_MAX-1);
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_PERTE_PING;
				}
			}

			else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_TEST_WIFI_5Ghz;
		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
		// ======================================================================================
		// =  cmd exit  2ghz      												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_cmd_exit_2Ghz) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_EXIT_2Ghz,0))
			{
				if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_EXIT_2Ghz) == TRUE)
				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_EXIT_2Ghz,0), NULL,NULL ,NULL, 8);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"Exit OK " );
						gSlot[nItfe].ihmSlot.nEtat = ETAT_Check_Driver_5Ghz;
					}
					else
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Exit KO ");
						//	strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					strncpy (ptrVariablesTraca->chLibelleErreur,  "CONF_DEC_BWC_CMD_EXIT_2Ghz",TAILLE_MAX-1);
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
			}

			else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_Check_Driver_5Ghz;

		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
		// ======================================================================================
		// = Check_Driver_5Ghz         												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_Check_Driver_5Ghz) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_Check_Driver_5Ghz,0))
			{
				if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Check_Driver_5Ghz) == TRUE)
				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_Check_Driver_wifi_5Ghz(nItfe, strErreurMessage);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"Check Driver WIFI 5Ghz OK" );
						gSlot[nItfe].ihmSlot.nEtat = ETAT_Update_Driver_5Ghz;
					}
					else
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					strncpy (ptrVariablesTraca->chLibelleErreur,  "CONF_DEC_BWC_CMD_Check_Driver_5Ghz",TAILLE_MAX-1);
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
			}

			else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_Update_Driver_5Ghz;
		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
		// ======================================================================================
		// = Update Driver wifi 5Ghz        												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_Update_Driver_5Ghz) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_Update_Driver_5Ghz,0))
			{
				if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Update_Driver_5Ghz) == TRUE)
				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_Update_Driver_wifi_5Ghz(nItfe, strErreurMessage);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"Update Driver WIFI 5Ghz OK" );
						gSlot[nItfe].ihmSlot.nEtat = ETAT_TEST_WIFI_5Ghz;
					}
					else
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					strncpy (ptrVariablesTraca->chLibelleErreur,  "CONF_DEC_BWC_CMD_Update_Driver_5Ghz",TAILLE_MAX-1);
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
			}

			else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_TEST_WIFI_5Ghz;
		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
		// ======================================================================================
		// = TEST wifi 5Ghz        												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_TEST_WIFI_5Ghz) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_GTW_BWC_Flag_test_5Ghz,0))
			{
				if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_GTW_BWC_CMD_TEST_5Ghz) == TRUE)

					//if(TRUE == TRUE)
				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_TEST_wifi_5Ghz(nItfe, strErreurMessage);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"TEST wifi 5Ghz OK" );
						//gSlot[nItfe].ihmSlot.nEtat = ETAT_cmd_exit_5Ghz;
						gSlot[nItfe].ihmSlot.nEtat = ETAT_TEST_WIFI_6Ghz;

					}
					else
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					strncpy (ptrVariablesTraca->chLibelleErreur,  "CONF_DEC_BWC_CMD_Check_Driver_5Ghz",TAILLE_MAX-1);
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
			}

			else
				//gSlot[nItfe].ihmSlot.nEtat = ETAT_cmd_exit_5Ghz;
				gSlot[nItfe].ihmSlot.nEtat = ETAT_TEST_WIFI_6Ghz;
		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
		// ======================================================================================
		// =  cmd exit  5ghz      												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_cmd_exit_5Ghz) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_EXIT_2Ghz,0))
			{
				if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_EXIT_2Ghz) == TRUE)
				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_EXIT_2Ghz,0), NULL,NULL ,NULL, 8);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"Exit OK " );
						gSlot[nItfe].ihmSlot.nEtat = ETAT_TEST_WIFI_6Ghz;
					}
					else
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Exit KO ");
						//	strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					strncpy (ptrVariablesTraca->chLibelleErreur,  "CONF_DEC_BWC_CMD_EXIT_2Ghz",TAILLE_MAX-1);
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
			}
			else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_TEST_WIFI_6Ghz;

		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

		// ======================================================================================
		// = TEST wifi 5Ghz ET 2GHZ   les deux en meme temps    												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_TEST_WIFI_6Ghz) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_GTW_BWC_Flag_test_6Ghz,0))
			{
				if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_GTW_BWC_CMD_TEST_6Ghz) == TRUE)
					//if(TRUE == TRUE)
				{
					IHM_GestCtrlPnl (nItfe);
					status =FCT_TEST_wifi_6Ghz(nItfe, strErreurMessage);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"TEST wifi 6Ghz OK" );
						//gSlot[nItfe].ihmSlot.nEtat = ETAT_Check_Driver_BT;
						//gSlot[nItfe].ihmSlot.nEtat = ETAT_FINALISATION;
						gSlot[nItfe].ihmSlot.nEtat = ETAT_TEST_BT;
					}
					else
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					strncpy (ptrVariablesTraca->chLibelleErreur,  "CONF_DEC_BWC_CMD_Check_Driver_5Ghz",TAILLE_MAX-1);
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
			}

			else
				//gSlot[nItfe].ihmSlot.nEtat = ETAT_Check_Driver_BT;
				//gSlot[nItfe].ihmSlot.nEtat = ETAT_FINALISATION;
				gSlot[nItfe].ihmSlot.nEtat = ETAT_TEST_BT;
		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

		// ======================================================================================
		// = Check_Driver_BT       												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_Check_Driver_BT) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_TEST_check_driver_BT,0))
			{
				if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Check_Driver_BT) == TRUE)
				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_Check_Driver_BT(nItfe, strErreurMessage);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"Check Driver BT OK" );
						gSlot[nItfe].ihmSlot.nEtat = ETAT_Update_Driver_BT;
					}
					else
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					strncpy (ptrVariablesTraca->chLibelleErreur,  "CONF_DEC_BWC_CMD_Check_Driver_BTCMD_Check_Driver_BT",TAILLE_MAX-1);
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
			}

			else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_Update_Driver_BT;
		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
		// ======================================================================================
		// = Update Driver BT        												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_Update_Driver_BT) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_Update_Driver_BT,0))
			{
				if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Update_Driver_BT) == TRUE)
				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_Update_Driver_BT(nItfe, strErreurMessage);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"Update Driver BT OK" );
						gSlot[nItfe].ihmSlot.nEtat = ETAT_TEST_BT;
					}
					else
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					strncpy (ptrVariablesTraca->chLibelleErreur,  "CONF_DEC_BWC_CMD_Update_Driver_BT",TAILLE_MAX-1);
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
			}

			else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_TEST_BT;
		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

		// ======================================================================================
		// = TEST BT        												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_TEST_BT) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_GTW_BWC_FLAG_TEST_BT,0))
			{
				if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_GTW_BWC_CMD_TEST_BT) == TRUE)
					//if(TRUE == TRUE)

				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_TEST_BT(nItfe, strErreurMessage);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"TEST BT OK" );
						gSlot[nItfe].ihmSlot.nEtat = ETAT_REMONTE_SFTP;
					}
					else
					{

						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					strncpy (ptrVariablesTraca->chLibelleErreur,  "CONF_DEC_BWC_CMD_Check_Driver_BT",TAILLE_MAX-1);
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
			}

			else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_REMONTE_SFTP;
		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;



		// ======================================================================================
		// = FINALISATION 			                                                =
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_FINALISATION) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_Finalisation,0))
			{
				if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_FINALISATION) == TRUE)
				{
					IHM_GestCtrlPnl (nItfe);
					status = FCT_Finalisation(nItfe, strErreurMessage);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
					if (status==0)
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,GET_MESSAGE(TFC_MSG_FINALISATION_OK) );
						gSlot[nItfe].ihmSlot.nEtat = ETAT_REMONTE_SFTP;
					}
					else
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
						strncpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage,TAILLE_MAX-1);
						gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
						IHM_GestCtrlPnl (nItfe);
					}
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					strncpy (ptrVariablesTraca->chLibelleErreur,  GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST),TAILLE_MAX-1);
					SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, GET_MESSAGE(TFC_MSG_ERREUR_CONF_Finalisation_NON_EXIST));
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
			}

			else
				gSlot[nItfe].ihmSlot.nEtat = ETAT_TRACA_BDD;
		}
		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

		//Delay(2);

		// ------------------------------
		// Remonter temps de test
		// ------------------------------

		/*if (gSlot[nItfe].ihmSlot.nEtat == ETAT_KO)
		{
			Temps_Test =  (int)(GetTickCount() - gSlot[nItfe].nTempsDebutTest)/1000 ;*/

		/*if ( MES_Capturer ( ptrMesures, MES_TYPE_TEMPS_TEST, MES_STATUS_KO, Temps_Test, 0) != 0 )
		{
			FCT_AfficheInfo (nItfe, IHM_MODE_POPUP_ERREUR|IHM_MODE_TRACE_TXTBOX, MES_NON_DEFINIE, gMesuresBNFT[MES_TYPE_TEMPS_TEST].nom);
			return -1;
		}*/
		/*Temps_Test_intermediaire=Temps_Test;
			   if(gSlot[nItfe].BNFTnteg.gchFlagTraca)
				{
				   FCT_EnregistrementMesure ( nItfe );
				}
		}*/
		/*	else
			{
				Temps_Test =  (int)(GetTickCount() - gSlot[nItfe].nTempsDebutTest)/1000 ;*/

		/*if ( MES_Capturer ( ptrMesures, MES_TYPE_TEMPS_TEST, MES_STATUS_OK, Temps_Test, 0) != 0 )
		{
			FCT_AfficheInfo (nItfe, IHM_MODE_POPUP_ERREUR|IHM_MODE_TRACE_TXTBOX, MES_NON_DEFINIE, gMesuresBNFT[MES_TYPE_TEMPS_TEST].nom);
			return -1;
		}*/
		/*Temps_Test_intermediaire=Temps_Test;
		if(gSlot[nItfe].BNFTnteg.gchFlagTraca)
		{
			  FCT_EnregistrementMesure ( nItfe);
		}
		}

		sprintf (Temps_Test_char,"%d s",Temps_Test);
		SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_Temps_Test, Temps_Test_char);*/

		// ======================================================================================
		// = REMONTE SFTP                  												=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_REMONTE_SFTP) && (gNPAbort == FALSE) )
		{
			if (VAR_GET_BOOL(ptrVariablesConf, VAR_CONF_GTW_BWC_FLAG_REMONTE_SFTP, 0) == 1)
			{
				IHM_GestCtrlPnl (nItfe);
				Sleep(200);
				status = FCT_Remonte_SFTP (nItfe, strErreurMessage);
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
				if (status==0)
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Remonte fichier Calibration OK");
					gSlot[nItfe].ihmSlot.nEtat = ETAT_TRACA_BDD;
				}
				else
				{
					// !!! On ne crée pas un passage KO en cas de non autorisation de passage !!!
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
					strcpy (ptrVariablesTraca->chLibelleErreur, strErreurMessage);
					resultatTest = FALSE;
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_PERTE_PING;
					strcpy (strErreurMessage, "");

				}
			} 
			else
			 gSlot[nItfe].ihmSlot.nEtat = ETAT_TRACA_BDD; 
		}
		

		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

		Delay (1);

		// ======================================================================================
		// = Traçabilité en base																=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_TRACA_BDD) && (gNPAbort == FALSE)  )
		{
			if(gSlot[nItfe].BNFTnteg.gchFlagTraca)
			{
				IHM_GestCtrlPnl (nItfe);

				status = FCT_TracaBdd (nItfe);
				//ajout remonter temps de test
				Temps_Test =  (int)(GetTickCount() - gSlot[nItfe].nTempsDebutTest)/1000 ;
				Temps_Test_intermediaire=Temps_Test;

				//FCT_EnregistrementMesure(nItfe);

				//FCT_EnregistrementMesureLog(nItfe , NULL) ;


				sprintf (Temps_Test_char,"%d s",Temps_Test);
				SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_Temps_Test, Temps_Test_char);



				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
				if (status==0)
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG|IHM_MODE_TRACE_TXTBOX, 999, GET_MESSAGE(TFC_MSG_TRACABILITE_OK));

					resultatTest = 1;
					SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_CTRL_VAL, 1);
					SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_DIMMED, 0);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OK;
					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG|IHM_MODE_TRACE_TXTBOX, 999, GET_MESSAGE(TFC_MSG_TRACABILITE_KO));
					strncpy (ptrVariablesTraca->chLibelleErreur, "Erreur tracabilité",TAILLE_MAX-1);
					resultatTest = 0;
					gSlot[nItfe].ihmSlot.nEtat = ETAT_KO;

					IHM_GestCtrlPnl (nItfe);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;

				}
			}

		}
		//else
		//gSlot[nItfe].ihmSlot.nEtat = ETAT_KO; // Dans les 2 cas l'etat suivant est la perte Ping

		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

		IHM_GestCtrlPnl (nItfe);




		// ======================================================================================
		// = Traitement si le test est KO														=
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_KO) && (gNPAbort == FALSE) )
		{
			strcpy(msg_erreur_persiste,ptrVariablesTraca->chLibelleErreur);
			if(gSlot[nItfe].BNFTnteg.gchFlagTraca)
			{
				IHM_GestCtrlPnl (nItfe);
				//c'est ici affiche msg erreur dans txt_info en rouge
				//ajout remonter temps de test
				status = FCT_TracaBddKo (nItfe);
				Temps_Test =  (int)(GetTickCount() - gSlot[nItfe].nTempsDebutTest)/1000 ;
				Temps_Test_intermediaire=Temps_Test;
				//FCT_EnregistrementMesure ( nItfe);
				//FCT_EnregistrementMesureLog(nItfe , NULL) ;
				sprintf (Temps_Test_char,"%d s",Temps_Test);
				SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_Temps_Test, Temps_Test_char);




				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Message);
				// 	SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_LABEL_TEXT,strErreurMessage );
				SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, ptrVariablesTraca->chLibelleErreur);
				resultatTest = 0;//
				if (status==0)
				{
					SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_CTRL_VAL, 1);
					SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_DIMMED, 0);
					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;

				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG|IHM_MODE_TRACE_TXTBOX, 999, "Enregistrement KO Traçabilite NON FAIT");
					strncpy (ptrVariablesTraca->chLibelleErreur, "Erreur tracabilité",TAILLE_MAX-1);

					gSlot[nItfe].ihmSlot.nEtat = ETAT_OPEN_CAISSON;
				}
			}
		}

		if (gNPAbort==TRUE)
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

		IHM_GestCtrlPnl (nItfe);










		// ======================================================================================
		// = Reboot de la carte en cas repetabilite						                                            =
		// ======================================================================================
		/*	if(VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_FLAG_Repetabilite,0))
			{
				FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,"[export PS1=#{Pass:#}][killall telnetd{Pass:#}][telnetd -l /bin/sh  killall udhcpc{Pass:#}][reboot{Pass:#}]", NULL,NULL ,NULL, 3);
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG|IHM_MODE_TRACE_TXTBOX, 999, "reboot");

				Delay(30);
			}*/

		// ======================================================================================
		// = OPEN caisson  =FCT_Comm_Caisson_Open(nItfe);
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_OPEN_CAISSON) && (gNPAbort == FALSE) )
		{
			status = FCT_Comm_Caisson_Open(nItfe);
			IHM_GestCtrlPnl (nItfe);
			if (status==0)
			{
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Open Caisson");
				gSlot[nItfe].ihmSlot.nEtat = ETAT_PERTE_PING;
				//strncpy (strErreurMessage, "",TAILLE_MAX-1);
			}
			else
			{
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"Opening Caisson KO");

				//resultatTest = FALSE;
				gSlot[nItfe].ihmSlot.nEtat = ETAT_PERTE_PING;
				//***
				strncpy (message_TXT_info, strErreurMessage,TAILLE_MAX-1);
				//strncpy (strErreurMessage, "",TAILLE_MAX-1);
				IHM_GestCtrlPnl (nItfe);

			}
			if (gNPAbort==TRUE)
				gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

			IHM_GestCtrlPnl (nItfe);
			if ((VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_GTW_BWC_FLAG_Eth,0)==1))
			{
				//status = InetTelnetWrite (gSlot[nItfe].igHandleConnexion , "taskkill /F /tftpd64.exe",  "\r\n", -1, &iNumBytWritten, 1000);
				//TerminateProcess("C:\\Users\\G558412\\Desktop\\Tftpd64\\tftpd64.exe",0);
				TerminateExecutable (g_exeHandle);
			}

			if (resultatTest == 1)
			{
				// Ecriture fichier log
				FIL2LO_PrintResultat (nItfe, TRUE, NULL, (float)(GetTickCount() - gSlot[nItfe].nTempsDebutTest)/1000);
				// Ecriture trace
				// ---------------    ;
				FCT_EnvoieLogBdd( nItfe);
				FIL2LO_EcritTrace (FALSE, nItfe, "OK");

			}
			else
			{
				FIL2LO_PrintResultat (nItfe, FALSE, NULL, (float)(GetTickCount() - gSlot[nItfe].nTempsDebutTest)/1000);
				// Ecriture trace
				// ---------------
				FCT_EnvoieLogBdd( nItfe);
				FIL2LO_EcritTrace (FALSE, nItfe, "KO");
			}



		}

		// ======================================================================================
		// =ATTENTE_FERMETURE_CAISSON                                                      =
		// ======================================================================================

		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_ATTENTE_FERMETURE_CAISSON) && (gNPAbort == FALSE))
		{
			//status = FCT_Comm_Attente_Fermeture_Caisson(nItfe);
			IHM_GestCtrlPnl (nItfe);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, msg_erreur_persiste);
			//if (status==0)

			if (FCT_Comm_Attente_Fermeture_Caisson(nItfe) == 0)  /*FCT_Comm_Attente_Retrait_Decoduer*/
			{
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, " Caisson Fermée  ");
				gSlot[nItfe].ihmSlot.nEtat = ETAT_DECODEUR_PRESENT;
			}
			else
			{

				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, " Erreur fermeture caisson  ");
				//resultatTest = 0;
				gSlot[nItfe].ihmSlot.nEtat = ETAT_PERTE_PING;
				//strncpy (strErreurMessage, "",TAILLE_MAX-1);
				IHM_GestCtrlPnl (nItfe);
			}
			if (gNPAbort==TRUE)
				gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
			IHM_GestCtrlPnl (nItfe);

		}

		// = Attente Perte Ping						                                            =
		// ======================================================================================
		if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_PERTE_PING) && (gNPAbort == FALSE) )
		{
			status = FCT_AttentePertePingGateWay (nItfe, strErreurMessage);
			IHM_GestCtrlPnl (nItfe);
			if (status==0)
			{
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Perte Ping OK");
				gSlot[nItfe].ihmSlot.nEtat = ETAT_DECODEUR_PRESENT;
				//strcpy (strErreurMessage, "");
			}
			else
			{
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Perte Ping KO");

				//resultatTest = 0;
				gSlot[nItfe].ihmSlot.nEtat = ETAT_PERTE_PING;
				//strcpy (strErreurMessage, "");
				IHM_GestCtrlPnl (nItfe);
			}
			
			/*
			if (resultatTest == 1)
			{
				// Ecriture fichier log
				FIL2LO_PrintResultat (nItfe, TRUE, NULL, (float)(GetTickCount() - gSlot[nItfe].nTempsDebutTest)/1000);
				// Ecriture trace
				// ---------------    ;
				FCT_EnvoieLogBdd( nItfe);
				FIL2LO_EcritTrace (FALSE, nItfe, "OK");

			}
			else
			{
				FIL2LO_PrintResultat (nItfe, FALSE, NULL, (float)(GetTickCount() - gSlot[nItfe].nTempsDebutTest)/1000);
				// Ecriture trace
				// ---------------
				FCT_EnvoieLogBdd( nItfe);
				FIL2LO_EcritTrace (FALSE, nItfe, "KO");
			}
			
			*/
			if (gNPAbort==TRUE)
				gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

			IHM_GestCtrlPnl (nItfe);
		}

		// Fermeture de la connexion Telnet si handl valide
		//----------------------------------
		if (gSlot[nItfe].igHandleConnexion!=-1)
		{
			FCT_CloseConnexionTelnet (nItfe,strErreurMessage,gSlot[nItfe].igHandleConnexion);
		}

		if (gSlot[nItfe].HandleTelnetSwitch_SP8T!=-1)
		{
			FCT_CloseConnexionTelnet (nItfe,strErreurMessage,gSlot[nItfe].HandleTelnetSwitch_SP8T);
		}

		if (gSlot[nItfe].HandleTelnetSwitch_SP12T!=-1)
		{
			FCT_CloseConnexionTelnet (nItfe,strErreurMessage,gSlot[nItfe].HandleTelnetSwitch_SP12T);
		}

		if (gNPAbort == TRUE)
		{
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
			IHM_GestCtrlPnl (nItfe);
		}

		Sleep(100);


		// ======================================================================================
		// = Attente Perte Ping						                                            =FCT_Comm_Caisson_Open(nItfe);
		// ======================================================================================
		/*	if ( (gSlot[nItfe].ihmSlot.nEtat == ETAT_PERTE_PING) && (gNPAbort == FALSE) )
			{
				status = FCT_AttentePertePingGateWay (nItfe, strErreurMessage);
				IHM_GestCtrlPnl (nItfe);
				if (status==0)
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_PERTE_PROMPT_OK));
					gSlot[nItfe].ihmSlot.nEtat = ETAT_DECODEUR_PRESENT;
					strncpy (strErreurMessage, "",TAILLE_MAX-1);
				}
				else
				{
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,GET_MESSAGE(TFC_MSG_PERTE_PROMPT_KO));

					resultatTest = 0;
					gSlot[nItfe].ihmSlot.nEtat = ETAT_PERTE_PING;
					strncpy (strErreurMessage, "",TAILLE_MAX-1);
					IHM_GestCtrlPnl (nItfe);
				}
				if (gNPAbort==TRUE)
					gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;

				IHM_GestCtrlPnl (nItfe);
			}*/


		if (gNPAbort == TRUE)
		{
			gSlot[nItfe].ihmSlot.nEtat = ETAT_STOP;
			IHM_GestCtrlPnl (nItfe);
		}

		/*	if (gSlot[nItfe].HandleTelnetSwitch_SP8T!=-1)
			{
				FCT_CloseConnexionTelnet (nItfe,strErreurMessage,gSlot[nItfe].HandleTelnetSwitch_SP8T);
			}*/
		Sleep(100);

#ifdef CONTROLEMEMOIRE // Analyse fuite mémoire
		FCT_InfoMemoire( nItfe, "1" );
#endif

#ifdef CONTROLEMEMOIRE // Analyse fuite mémoire
		FCT_InfoMemoire( nItfe, "2" );
#endif

#ifdef CONTROLEMEMOIRE // Analyse fuite mémoire
		FCT_InfoMemoire( nItfe, "3" );
#endif

#ifdef CONTROLEMEMOIRE // Analyse fuite mémoire
		FCT_InfoMemoire( nItfe, "4" );
#endif

#ifdef CONTROLEMEMOIRE // Analyse fuite mémoire
		FCT_InfoMemoire( nItfe, "5" );
#endif

	}	// FIN DU THREAD

Error:

	IHM_GestCtrlPnl (nItfe);


	// RAZ de l'identifiant du thread
	tSlot->idThread = 0;

	// Libération mémoire allouée

	// Libération mémoire des variables de configuration produit
	VAR_Delete ( ptrVariablesConf );

	// Libération mémoire des variables de configuration liées à un SN
	VAR_Delete ( ptrVariablesConfSn );

	// Libération mémoire des variables d'état
	VAR_Delete ( ptrVariablesEtat );

	// Libération mémoire des mesures
	MES_Delete ( ptrMesures );

	// RAZ des clés
	//CLE_Delete ( ptrCles );

	// RAZ des variables de traça avant exécution du test
	FCT_TracaRaz (ptrVariablesTraca);

	// Suppression des fichiers temporaires
	DeleteFile (tSlot->chCheminMasqueEtiquette);
	DeleteFile (tSlot->chCheminLogoEtiquette);
	if (error)
	{
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);
		return -1;
	}

	return 0;
}
