
// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//
//
// ==============================================================================
//   PROJET			: Banc HDD
//   MODULE			: Ihm
//   PROCESSEUR		: INTEL Pentium
//   ENVIRONNEMENT	: Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION	: Définition des fonctions de gestion de l'IHM.
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

// ==============================================================================
// INCLUDE
// ==============================================================================
#include "Include.h"

// ==============================================================================
// DECLARATION DES VARIABLES LOCALES
// ==============================================================================

// variables pour charger les panels
int PnlProduitId;										// handle de panel choix produit
int PnlPere;											// handle de panel parent contenant les slots
int PnlChoixPalette;									// handle de panel choix lot + palette



static ViString  gs_sResourceName = "TCPIP0::169.254.44.189::INSTR";//"USB::0xAAD::*?";
static ViBoolean gs_hIDQuery = VI_TRUE;
static ViBoolean gs_hResetDevice = VI_TRUE;

// ==============================================================================
// DECLARATION DES FONCTIONS
// ==============================================================================

// ==============================================================================
// FONCTION : 	  IHM_GestCtrlPnl
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int IHM_GestCtrlPnl (char nItfe)
// ------------------------------------------------------------------------------
// ARGUMENTS :
// ------------------------------------------------------------------------------
// RETOUR :
// ------------------------------------------------------------------------------
// DESRIPTION :   Gestion de l'apparence de l'interface.
//				  Traitement en fonction du mode en cours.
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
int IHM_GestCtrlPnl (int nItfe)
{
	switch (gSlot[nItfe].ihmSlot.nEtat)
	{
			// Ouverture du logiciel
		case ETAT_INIT_IHM :
		{
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "");
			ResetTextBox (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TRACE, "");
			SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_LT_GRAY);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			break;
		}

		// Presence GATEWAY
		case ETAT_DECODEUR_PRESENT:
		{
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "");
			ResetTextBox (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TRACE, "");
			//FIL2LO_PrintEtape (nItfe, "Attente Demarrage Gateway ");
			SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, ATTR_TEXT_COLOR, VAL_BLUE);
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, " =====> Attente Demarrage Decodeur ");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "ATTENTE DECODEUR");
			SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);


			break;
		}
		//Fermeture caisoon
		
		

		case ETAT_ATTENTE_FERMETURE_CAISSON:
		{
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "");
			//ResetTextBox (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TRACE, "");
			//FIL2LO_PrintEtape (nItfe, "Attente Demarrage Gateway ");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, ATTR_TEXT_COLOR, VAL_BLUE);
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, " =====> Attente Fermeture Caisson ");
			//*********here!!!i skip next LINE
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Attente Fermerture caisson");
			
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, message_TXT_info);
		//	SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
		//	SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			
			
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "ATTENTE RETRAIT GTW");
			

			break;
		}
		
		 //
		
		 case ETAT_LECTURE_DFA_GATEWAY :
		{
 
			FIL2LO_PrintEtape (nItfe, "Lecture DFA");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Lecture DFA");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> Lecture DFA");
			break;
 
		}
		
		
		
		//
		
		// Verifier l'autorisation de passage
		case ETAT_AUTORISATION_PASSAGE:
		{
			FIL2LO_PrintEtape (nItfe, "TEST AUTHORIZATION");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "TEST AUTHORIZATION");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "====> TEST AUTHORIZATION");
			break;
		}

		case ETAT_LECTURE_SN :
		{

			FIL2LO_PrintEtape (nItfe, "SN reading");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "SN reading");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> SN reading");
			break;

		}
		case ETAT_VERIF_VERSION_FIRMWARE :
		{

			FIL2LO_PrintEtape (nItfe, "Check Firmware version");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Check Firmware version");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> Check Firmware version");
			break;

		}		
			
		case ETAT_Check_Driver_2Ghz :
		{

			FIL2LO_PrintEtape (nItfe, "Check Driver wifi 2Ghz");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Check Driver wifi 2Ghz");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> Check Driver wifi 2Ghz");
			break;

		}
		case ETAT_Check_Driver_5Ghz :
		{

			FIL2LO_PrintEtape (nItfe, "Check Driver wifi 5Ghz");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Check Driver wifi 5Ghz");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> Check Driver wifi 5Ghz");
			break;

		}
		case ETAT_Check_Driver_BT :
		{

			FIL2LO_PrintEtape (nItfe, "Check Driver BT");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Check Driver BT");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> Check Driver BT");
			break;

		}
		
		case ETAT_Update_Driver_2Ghz : 
		{

			FIL2LO_PrintEtape (nItfe, "Update wifi 2Ghz");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Update wifi 2Ghz");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> Update wifi 2Ghz");
			break;

		}
		case ETAT_Update_Driver_5Ghz : 
		{

			FIL2LO_PrintEtape (nItfe, "Update wifi 5Ghz");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Update wifi 5Ghz");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> Update wifi 5Ghz");
			break;

		}
		case ETAT_Update_Driver_BT :
		{

			FIL2LO_PrintEtape (nItfe, "Update BT");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Update BT");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> Update BT");
			break;

		}
		
		
		case ETAT_Update_IP_DUT :
		{

			FIL2LO_PrintEtape (nItfe, "Update Adress IP DUT");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Update Adress IP DUT");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> Update Adress IP DUT");
			break;

		}
		case ETAT_TEST_WIFI_2Ghz :
		{

			FIL2LO_PrintEtape (nItfe, "TEST wifi 2Ghz ");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "TEST wifi 2Ghz");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> TEST wifi 2Ghz");
			break;

		}
		case ETAT_TEST_WIFI_5Ghz :
		{

			FIL2LO_PrintEtape (nItfe, "TEST wifi 5Ghz ");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "TEST wifi 5Ghz");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> TEST wifi 5Ghz");
			break;
		}
		
			
			case ETAT_TEST_WIFI_6Ghz :
		{

			FIL2LO_PrintEtape (nItfe, "TEST wifi 6Ghz ");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "TEST wifi 6Ghz");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> TEST wifi 6Ghz");
			break;
			
				
		}
		
		case ETAT_TEST_BT :
		{

			FIL2LO_PrintEtape (nItfe, "TEST BT ");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "TEST BT");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> TEST BT");
			break;

		}
		case ETAT_Ping_DUT :
		{

			FIL2LO_PrintEtape (nItfe, "Wait Ping DUT");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Wait Ping DUT");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> Wait Ping DUT");
			break;

		}
		
		case ETAT_LECTURE_VERSION :
		{

			FIL2LO_PrintEtape (nItfe, "TT Version");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "TT Version");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999,"====> TT Version");
			break;

		}
		
		case ETAT_RECUP :
		{
			FIL2LO_PrintEtape (nItfe, "Recuperation");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Recuperation");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "====> Recuperation");
			break;
		}
		case ETAT_INIT :
		{
			FIL2LO_PrintEtape (nItfe, "Initialization");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "INITIALIZATION");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "====> Initialization");
			break;
		}
		
		case ETAT_FINALISATION :
		{
			FIL2LO_PrintEtape (nItfe, "Finalization");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Finalization");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "====> Finalization");
			break;
		}		
		
		case ETAT_INIT_WIFI_5G :
		{
			FIL2LO_PrintEtape (nItfe, "Wifi 5G initialization");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Wifi 5G initialization");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "====> Wifi 5G initialization");
			break;
		}

		case ETAT_CONFIG_WIFI_2G :
		{

			FIL2LO_PrintEtape (nItfe, "2.4 GHz WiFi configuration");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "2.4 GHz WiFi configuration");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "=====> 2.4 GHz WiFi configuration");
			break;
		}

		case ETAT_CONFIG_IR :
		{

			FIL2LO_PrintEtape (nItfe, "Wifi IR configuration");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Wifi IR configuration");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "=====> Wifi IR configuration");
			break;
		}
		case ETAT_CONFIG_WIFI_5G :
		{

			FIL2LO_PrintEtape (nItfe, "5GHz WiFi configuration");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "5GHz WiFi configuration");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "=====> 5GHz WiFi configuration");
			break;
		}
		
		case ETAT_CONFIG_BT :
		{

			FIL2LO_PrintEtape (nItfe, " BT Configuration");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "BT Configuration");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "=====> BT Configuration");
			break;
		}		
		
		
		case ETAT_TEST_Bouton :
		{

			FIL2LO_PrintEtape (nItfe, "TEST Button");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "TEST Button");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "=====> TEST Button");
			break;
		}
		
		case ETAT_TEST_IR :
		{

			FIL2LO_PrintEtape (nItfe, "TEST IR");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "TEST IR");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "=====> TEST IR");
			break;
		}
		
		case ETAT_TEST_LED :
		{

			FIL2LO_PrintEtape (nItfe, "TEST LED");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "TEST LED");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "=====> TEST LED");
			break;
		}		
		
		case ETAT_MESURE_2G :
		{

			FIL2LO_PrintEtape (nItfe, "2G WiFi measurements");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "2G WiFi measurements");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "=====> 2G WiFi measurements");
			break;
		}
		

		
		case ETAT_MESURE_5G :
		{

			FIL2LO_PrintEtape (nItfe, "5G WiFi measurements");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "5G WiFi measurements");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "=====> 5G WiFi measurements");
			break;
		}
		
		case ETAT_MESURE_BT :
		{

			FIL2LO_PrintEtape (nItfe, "BT measurements");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "BT measurements");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "=====> BT measurements");
			break;
		}		

		case ETAT_PERTE_PING:
		{

			FIL2LO_PrintEtape (nItfe, "Waiting for decoder removal");

			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "ATTENTE RETRAIT GTW");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "====> Waiting for decoder removal");
			break;
		}
		case ETAT_OPEN_CAISSON:
		{

			FIL2LO_PrintEtape (nItfe, "opening caisson");

			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "ATTENTE RETRAIT GTW");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "====> opening caisson");
			break;
		}

		// Tracabilité dans la BDD
		case ETAT_TRACA_BDD :
		{
			FIL2LO_PrintEtape (nItfe, "TRACA BDD");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "Traca en cours");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "TRACA BDD");
			// SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_GREEN);
	
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);  
			break;
		}

		// Test a échoué
		case ETAT_KO :
		{
			FIL2LO_PrintEtape (nItfe, "TEST KO");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "!!! Passage Ko !!!");
			SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_RED);
			SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, ATTR_TEXT_COLOR, VAL_RED);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			break;
		}

		// Test a réussi  ( test entier )
		case ETAT_OK :
		{
			FIL2LO_PrintEtape (nItfe, "TEST WIFI CONDUIT OK ");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "*** Passage OK ***");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "TEST WIFI CONDUIT OK");
			SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_GREEN);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_LABEL_TEXT, "TEST OK");
			SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_DEPANNAGE, ATTR_VISIBLE, 0);
			SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_RETEST, ATTR_VISIBLE, 0);
			break;
		}

		// Arrêt opérateur demandé
		case ETAT_STOP :
		{
			FIL2LO_PrintEtape (nItfe, "Operator stop");
			//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "*** Arret operateur ***");
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Arrêt opérateur");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_OFF_COLOR, VAL_LT_GRAY);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, FALSE);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_SLIDE, 0);
			break;
		}
		
		case ETAT_SWITCH :
		{

			FIL2LO_PrintEtape (nItfe, "Switch Initialization");
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_YELLOW);
			//SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE);
			//SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, TRUE);
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "Switch Initialization");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "=====>Switch Initialization");
			break;
		}
			case ETAT_ACTIVATION_DHCP:
		{
			FIL2LO_PrintEtape (nItfe, "ACTIVATION DHCP");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "ACTIVATION DHCP");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "====> ACTIVATION DHCP");
			break;
		}
			case ETAT_DESACTIVATION_DHCP:
		{
			FIL2LO_PrintEtape (nItfe, "DESACTIVATION DHCP");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "DESACTIVATION DHCP");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "====> DESACTIVATION DHCP");
			break;
		}
			case ETAT_REMONTE_SFTP:
		{
			FIL2LO_PrintEtape (nItfe, "REMONTE SFTP");
			SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TXT_INFO, "REMONTE SFTP");
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "====> REMONTE SFTP");
			break;
		}
		
		case ETAT_SLOT_INACTIF :
		case ETAT_FERMETURE :
		default:
			break;
	}

	//Sleep (1);
	return 0;
}

// ==============================================================================
// FONCTION : 	  Cb_Liberation
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int CVICALLBACK Cb_Liberation (int panel, int control,
//												 int event, void *callbackData,
//												 int eventData1, int eventData2)
// ------------------------------------------------------------------------------
// ARGUMENTS :
// ------------------------------------------------------------------------------
// RETOUR :
// ------------------------------------------------------------------------------
// DESRIPTION :   Fonction de lilbération des décodeurs.
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
//  DESCRIPTION :
//  DATE :
//  AUTEUR :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int CVICALLBACK Cb_Liberation (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int nItfe = -1;

	switch (event)
	{
		case EVENT_COMMIT:
		{
			nItfe = IHM_GetSlotIndexFromPanel (panel);
			if (nItfe >= 0)
				// DeverrouillageBandeau (nItfe);
				break;
		}
	}
	return 0;
}

// ==============================================================================
// FONCTION : 	  CB_ActiveLog
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int CVICALLBACK CB_ActiveLog ( int panel, int control,
//												 int event, void *callbackData,
//												 int eventData1, int eventData2)
// ------------------------------------------------------------------------------
// ARGUMENTS :
// ------------------------------------------------------------------------------
// RETOUR :
// ------------------------------------------------------------------------------
// DESRIPTION :   Gestion du Flag pour l'écriture dans le fichier de LOG.
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
int CVICALLBACK CB_ActiveLog (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	/*int nVal;
	int nItfe; */

	switch (event)
	{
		case EVENT_COMMIT:
			/*GetCtrlVal (panel, PNL_PERE_ACTIVE_LOG, &nVal);
			for (nItfe = 0; nItfe < NBRE_INTERFACE; nItfe++)
				gSlot[nItfe].ihmSlot.nActiveLog = nVal; */
			break;
	}
	return 0;
}

// ==============================================================================
// FONCTION : 	  CB_Panel
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int CVICALLBACK CB_Panel ( int panel, int control,
//											 int event, void *callbackData,
//											 int eventData1, int eventData2)
// ------------------------------------------------------------------------------
// ARGUMENTS :
// ------------------------------------------------------------------------------
// RETOUR :
// ------------------------------------------------------------------------------
// DESRIPTION :   Fonction qui permet de quitter le programme si on ferme
//				  le panel principal.
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
int CVICALLBACK CB_PanelPere (int panel, int event, void *callbackData, int eventData1, int eventData2)
{
	int nItfe;

	switch (event)
	{
		case EVENT_GOT_FOCUS:
			break;
		case EVENT_LOST_FOCUS:
			break;
		case EVENT_CLOSE:
			gNPAbort = TRUE;
			for (nItfe = 0; nItfe < NBRE_INTERFACE; nItfe++)
				gSlot[nItfe].ihmSlot.nEtat = ETAT_FERMETURE;
			QuitUserInterface (0);
			break;
	}
	return 0;
}

// ==============================================================================
// FONCTION : 	  CB_IntitPalette
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int CVICALLBACK CB_IntitPalette ( int panel, int control,
//											 	   int event, void *callbackData,
//											 	   int eventData1, int eventData2)
// ------------------------------------------------------------------------------
// ARGUMENTS :
// ------------------------------------------------------------------------------
// RETOUR :
// ------------------------------------------------------------------------------
// DESRIPTION :   Fonction de sélection d'un produit,
//				  Initialisation des variables,
//				  Prise de palette.
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
int CVICALLBACK CB_IntitPalette (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int 		 idxSel, idxStruct;
	int			 idxSlot;
	int 		 index;
	int 		 iNbProduit;
	char 		 Produit_NomProduit[TAILLE_MOY];
	char 	 	 msgErr[TAILLE_MAX] = {'\0'};
	char		 chVal[TAILLE_MOY] = {'\0'};
	char 	   	 strMessageErreur[TAILLE_MOY] = {"\0"};
	char		 chMess[TAILLE_MAX] = {'\0'};
	char 		 chFiltre[TAILLE_MOY] = {'\0'};
	


	// ===========================
	// = Affichage panel produit =
	// ===========================
	if (  (event == EVENT_LEFT_CLICK)  && (control == PNL_INTIT_INTIT) )
	{
		// Lecture du Filtre
		// -----------------
		GetCtrlVal( PnlProduitId, PNL_INTIT_FILTRE_PRODUIT, chFiltre );
		if (strlen(chFiltre))
		{
			// Chargement nom produit dans panel produit
			// -----------------------------------------
			GetNumListItems(PnlProduitId, PNL_INTIT_INTIT, &iNbProduit);
			for (int ii = 1; ii < (iNbProduit + 1); ii++)
			{
				// Supression de la liste des produits qui ne correcpondent pas au filtre
				// ----------------------------------------------------------------------
				GetLabelFromIndex(PnlProduitId, PNL_INTIT_INTIT, (iNbProduit-ii), Produit_NomProduit);
				index = FindPattern (Produit_NomProduit, 0, strlen(Produit_NomProduit), chFiltre, 0, 0);
				if ( index < 0)
					DeleteListItem(PnlProduitId, PNL_INTIT_INTIT, (iNbProduit-ii), 1);
			}
		}
	}   
	// Récupération du produit selectionné
	// -----------------------------------
	if (    ( (eventData1 == VAL_ENTER_VKEY) && (control == PNL_INTIT_INTIT)    )   ||
			( (event == EVENT_LEFT_CLICK)    && (control == PNL_INTIT_VALIDER)  )       )
	{
		
		GetCtrlIndex (PnlProduitId, PNL_INTIT_INTIT, &idxSel);
		GetLabelFromIndex (PnlProduitId, PNL_INTIT_INTIT, idxSel, Produit_NomProduit);
		GetValueFromIndex (PnlProduitId, PNL_INTIT_INTIT, idxSel, &idxStruct);


		// Fermer le panel de sélection
		// ----------------------------
		DiscardPanel (PnlProduitId);

		// =========================================
		// = Initialisation des variables globales =
		// =========================================
		gNPAbort = FALSE;

		// ======================================================
		// = Création du panel pere pouvant recevoir les slots  =
		// ======================================================
		PnlPere = LoadPanel (0, gChUirFile, PNL_PERE);
		FCT_AfficheVersionAppli (NOM_SOFT, PnlPere);

		//forcage du log à 1
		SetCtrlVal (PnlProduitId, PNL_PERE_ACTIVE_LOG, TRUE);
		//désactivation de la check box "activation LOG file"
		SetCtrlAttribute (PnlProduitId, PNL_PERE_ACTIVE_LOG, ATTR_DIMMED, TRUE);

		// ======================================================
		// = Lancement des threads pour chaque port acquisition =
		// ======================================================
		LaunchExecutable("C:\\TFTPD32\\tftpd32.exe");
		for (idxSlot = 0; idxSlot < NBRE_INTERFACE; idxSlot++)
		{
			// On vérifie si le SLOT est activé
			// --------------------------------
			if ( gSlot[idxSlot].ihmSlot.nActif )
			{
				// Initialisation des variables de traça
				// -------------------------------------
				FCT_TracaInit (&gSlot[idxSlot].variablesTraca);

				// MAJ des variables du SLOT
				// -------------------------
				gSlot[idxSlot].variablesTraca.idxProduit = idxStruct;	// Enregistrement de l'index du produit
				gSlot[idxSlot].id = idxSlot;							// MAJ index du SLOT
				gSlot[idxSlot].ihmSlot.nEtat = ETAT_SLOT_ACTIF;
				gSlot[idxSlot].ihmSlot.nActiveLog = gActiveLog;
				
				
				strcpy(gChNomProduit,"");
				// Extraction des variables de configuration de la BDD
				// ---------------------------------------------------
				if ( VAR_Get (	gVariablesConf,
								gNbVariablesConf,
								&gSlot[idxSlot].variablesConf,
								gTcomBase.instSCProduction,
								"1",
								gPosteProduits.produits[gSlot[idxSlot].variablesTraca.idxProduit].sfin.chVersion,
								gPosteProduits.produits[gSlot[idxSlot].variablesTraca.idxProduit].sfin.chIndice,
								gPosteInfos.chNom,
								msgErr) != 0 )
				{
					MessagePopup ("Erreur", "Erreur extraction variables de configuration produit.");
					gNPAbort = TRUE;
					QuitUserInterface (0);
					return -1;
				}

				/*********************************************************************/
				// Modification pour récupération des variables rattachées à un poste
				/*********************************************************************/
				// Extraction des variables de configuration de la BDD
				// ---------------------------------------------------
				strcpy(gChNomProduit,VAR_GET_STRING(&gSlot[idxSlot].variablesConf,VAR_CONF_GTW_BWC_Nom_Produit,0));
				if ( VAR_Get (	gVariablesConfPoste,
								gNbVariablesConfPoste,
								&gSlot[idxSlot].variablesConfPoste,
								gTcomBase.instSCProduction,
								NULL,
								gPosteProduits.produits[gSlot[idxSlot].variablesTraca.idxProduit].sfin.chVersion,
								gPosteProduits.produits[gSlot[idxSlot].variablesTraca.idxProduit].sfin.chIndice,
								gPosteInfos.chNom,
								msgErr) != 0 )
				{
					MessagePopup ("Erreur", "Erreur extraction variables de configuration Poste.");
					gNPAbort = TRUE;
					QuitUserInterface (0);
					return -1;
				}

				/*********************************************************************/
				// Fin modif
				/*********************************************************************/



				// ===================================================================================
				// = Maj du chemin des fichiers LOG et création du répertoire s'il n'existe pas déjà =
				// = ------------------------------------------------------------------------------- =
				// = Format du répertoire LOG :														 =
				// = 	[RACINE]\[Code Produit] - [Référence]\MM-JJ-AAAA 							 =
				// =																				 =
				// = Exemple :																		 =
				// = 	.\Log\253195340 - DS86 HD MT\10-25-2009										 =
				// = ------------------------------------------------------------------------------- =
				// ===================================================================================
				if ( !FileExists (gSlot[idxSlot].chCheminLog, NULL) )
				{
					MakeDir (gSlot[idxSlot].chCheminLog);
				}
				sprintf ( gSlot[idxSlot].chCheminLog, "%s%s\\", gSlot[idxSlot].chCheminLog, Produit_NomProduit);
				//sprintf ( gSlot[idxSlot].chCheminLog, "%s%s - %s\\", gSlot[idxSlot].chCheminLog, gPosteProduits.produits[idxStruct].sfin.chVersion, gPosteProduits.produits[idxStruct].sfin.chDesignation);
				if ( !FileExists (gSlot[idxSlot].chCheminLog, NULL) )
				{
					MakeDir (gSlot[idxSlot].chCheminLog);
				}
				// Récup de la date de la BDD
				// ---------------------------
				if(SCPROD_RecuperationDateHeure ( &gTcomBase, &gDateHeure, strMessageErreur))
					return -1;
				sprintf(gSlot[idxSlot].chMoisJourAnnee, "%02d-%02d-%04d", gDateHeure.month, gDateHeure.daymonth, gDateHeure.year);
				sprintf ( gSlot[idxSlot].chCheminLog, "%s%s\\", gSlot[idxSlot].chCheminLog, gSlot[idxSlot].chMoisJourAnnee);
				if ( !FileExists (gSlot[idxSlot].chCheminLog, NULL) )
					MakeDir (gSlot[idxSlot].chCheminLog);
				//sprintf ( gSlot[idxSlot].chCheminLog, "%s%s\\", gSlot[idxSlot].chCheminLog, DateStr());
				//if ( !FileExists (gSlot[idxSlot].chCheminLog, NULL) )
				//	MakeDir (gSlot[idxSlot].chCheminLog);


				// Déverrouillage de la tête
				// -------------------------
				//FCT_DeverrouillageBandeau (idxSlot);



				// Création de l'IHM du SLOT
				// -------------------------
				if ( IHM_SlotCreate ( &gSlot[idxSlot], msgErr ) != 0 )
				{
					MessagePopup ("Erreur",GET_MESSAGE(IHM_MSG_POPUP_7));
					gNPAbort = TRUE;
					QuitUserInterface (0);
					return -1;
				}



				//Initialisation Instrument Powermetter  ==> provisoire a regrouper les init dans une fonction séparé apres qualif instrument
				//============================================================================================================================

				  
			/*	if (strcmp(gSlot[idxSlot].BNFTnteg.gPwrmetterType,"USB") ==0)
				{
					if (rsnrpz_init(gSlot[idxSlot].BNFTnteg.gInstrumentID,gs_hIDQuery, gs_hResetDevice, &gSlot[idxSlot].g_Session) !=0)

					{

						sprintf(chMess,GET_MESSAGE(TFC_MSG_ERREUR_BRANCHEMENT_POWERMETER),chVal);
						MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
						gNPAbort = TRUE;
						QuitUserInterface (0);
						return 0;
					}

				}
				else
				{

				    	sprintf(chMess,GET_MESSAGE(TFC_MSG_ERREUR_TYPE_POWERMETER),chVal);
					    MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
						gNPAbort = TRUE;
						QuitUserInterface (0);
						return 0;
				}	  */ 

				EnableBreakOnLibraryErrors ();

				// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
				// Connexion Switch SP8T
				// ----------------------------------------------------------------------------------------------------------------------------------------------------------------

			/*	if ((VAR_GET_UINT8(&gSlot[idxSlot].variablesConf,VAR_CONF_DEC_BNFT_FLAG_SWITCH,0)))
				{
					if (Connect_Switch_SP8T (idxSlot, chMess)==-1)

					{
						MessagePopup ("Error Switch SP8T", chMess);
						DiscardPanel (PnlProduitId);
						gNPAbort = TRUE;
						QuitUserInterface (0);
						return 0;
					}
				}*/

				// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
				// Controle version de l'appli
				// ----------------------------------------------------------------------------------------------------------------------------------------------------------------

				if (VAR_DEFINED(&gSlot[idxSlot].variablesConf,VAR_CONF_GTW_BWC_Version) == TRUE) 
				{
				if (FCT_ControleVersion ()==-1)
				{
					sprintf (chMess, "App version:% s does not match.Eexpected version:% s",VERSION_SOFT,sVersionSoft);
					MessagePopup ("Erreur Version", chMess);

						gNPAbort = TRUE;
						QuitUserInterface (0);
						return 0;
				}
				}
				else
			    {
					strncpy(chMess,"conf_DEC_BWC_Version does not exist in TRACACOM",TAILLE_MAX_CHAINE-1);
					MessagePopup ("Error Version", chMess);

						gNPAbort = TRUE;
						QuitUserInterface (0);
						return 0;
				}

				
				
				
				// ============================
                // = Ouverture des Ports COM  =
                // ============================
			//	if ((VAR_GET_UINT8(&gSlot[idxSlot].variablesConf,VAR_CONF_DEC_BWC_FLAG_eth,0) )==0)
			//	{
					
				if ( FCT_OuverturePortsCOM ( idxSlot ) != 0)//&&(VAR_GET_UINT8(&gSlot[idxSlot].variablesConf,VAR_CONF_DEC_BWC_FLAG_eth,0) )
				{
					MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), GET_MESSAGE(IHM_MSG_POPUP_7));
					gNPAbort = TRUE;
					QuitUserInterface (0);
						gNPAbort = TRUE;
						QuitUserInterface (0);
						return 0;
				}
			//	}

				// Création du thread SLOT
				// -----------------------
				gSlot[idxSlot].hdleThread = CreateThread (	NULL,
											0,
											(LPTHREAD_START_ROUTINE) ThreadSlot,
											(LPVOID)(&gSlot[idxSlot]),
											0,
											&gSlot[idxSlot].idThread	);

				// Vérification de la création du thread, on sort si le thread n'est pas créé
				// --------------------------------------------------------------------------
				if (gSlot[idxSlot].hdleThread == NULL)
				{
					MessagePopup ("Error", "Thread Slot Launch Error");
					gNPAbort = TRUE;
					QuitUserInterface (0);
					return -1;
				}

				// il est possible de vérifier si le client TCP est bien lancé *
			}
			else
			{
				// MAJ des variables du SLOT
				// -------------------------
				gSlot[idxSlot].variablesTraca.idxProduit = idxStruct;	// Enregistrement de l'index du produit
				gSlot[idxSlot].id = idxSlot;							// MAJ index du SLOT
				gSlot[idxSlot].ihmSlot.nEtat = ETAT_SLOT_INACTIF;
				gSlot[idxSlot].ihmSlot.nActiveLog = gActiveLog;

				// Création de l'IHM du SLOT
				// -------------------------
				if ( IHM_SlotCreate ( &gSlot[idxSlot], msgErr ) != 0 )
				{
					MessagePopup ("Erreur", "Erreur création IHM Slot");
					gNPAbort = TRUE;
					QuitUserInterface (0);
					return -1;
				}

				// Désactivation de l'IHM SLOT
				// ---------------------------
				SetPanelAttribute (gSlot[idxSlot].ihmSlot.panelMain, ATTR_DIMMED , 1);
			}
		}


	   	// Maj nom produit testé
		// ---------------------
		sprintf (chVal, "%s - %s", gPosteProduits.produits[idxStruct].cie.chVersion, gPosteProduits.produits[idxStruct].sfin.chDesignation);
		SetCtrlVal (PnlPere, PNL_PERE_ACTIVE_LOG, gActiveLog);
		SetCtrlVal (PnlPere, PNL_PERE_DEFINITION, Produit_NomProduit);

	
		// ======================================
		// = Affichage de la fenêtre principale =
		// ======================================
		DisplayPanel (PnlPere);
		// Mettre curseur sur le num slot
		//SetActiveCtrl(PnlPere,PNL_PERE_TXT_SLOT);

		return 0;
	}

	// ===================================================
	// = Quitte le programme si on clique sur annuler ou =
	// = si on ferme le panel choix produits 			 =
	// ===================================================
	if ( ((event == EVENT_LEFT_CLICK) && (control == PNL_INTIT_ANNULER)) ||
			((event == EVENT_COMMIT) && (control == PNL_INTIT_ANNULER)) )
	{
		DiscardPanel (PnlProduitId);
		gNPAbort = TRUE;
		QuitUserInterface (0);
		return 0;
	}

	return 0;
}

/********************************************************************************************************************************************/
/*											Chargement de la liste des produits																*/
/********************************************************************************************************************************************/
int ChargeListeProduits (void)
{
	int ii=0;
	int error=0;
	int errorOccured=0;

	char chTemp[512]="";
	char errorMsg[1024]= {'\0'};

	// Récupération de la liste des produits
	errorOccured = SCPROD_ProduitsPoste (&gTcomBase, &gPosteInfos, &gPosteProduits, errorMsg);
	if (errorOccured)	errChk (-1);

	// Tri des produits par PrimaryKey
	ClasseListeProduits (&gPosteProduits, 1);

	// Chargement nom produit dans panel produit
	ClearListCtrl (PnlProduitId, PNL_INTIT_INTIT);
	for (ii=0; ii<gPosteProduits.nbProduit; ii++)
	{
		if (strlen (gPosteProduits.produits[ii].sfin.chIndice))
			sprintf (chTemp, "%s-%s %s - %s(CIE)", gPosteProduits.produits[ii].sfin.chVersion,
					 gPosteProduits.produits[ii].sfin.chIndice,
					 gPosteProduits.produits[ii].sfin.chDesignation,
					 gPosteProduits.produits[ii].cie.chIndice);
		else
			sprintf (chTemp, "%s %s - %s(CIE)", gPosteProduits.produits[ii].sfin.chVersion,
					 gPosteProduits.produits[ii].sfin.chDesignation,
					 gPosteProduits.produits[ii].cie.chIndice);

		InsertListItem (PnlProduitId, PNL_INTIT_INTIT, -1, chTemp, ii);
	}

Error:
	if (errorOccured)
	{
		MessagePopup ("Erreur Chargement Liste Produit", errorMsg);
		return -1;
	}

	return 0;
}

/********************************************************************************************************************************************/
/*									Classement de la liste des produits	(Par PrimaryKey ou nom)												*/
/********************************************************************************************************************************************/
void ClasseListeProduits (T_POSTE_PRODUITS *posteProduits, int type)
{
	int ii=0;
	int idxMax=0;

	T_POSTE_PRODUIT posteProduit;

	if (posteProduits!=NULL)
	{
		for (ii=1; ii<posteProduits->nbProduit; ii++)
		{
			idxMax=ii;
			switch (type)
			{
					// Tri sur les désignations produit
				case 0:
					while ( (strcmp (posteProduits->produits[idxMax].sfin.chDesignation, posteProduits->produits[idxMax-1].sfin.chDesignation)<0) && (idxMax>0) )
					{
						TCOM_ProduitCopier (&posteProduits->produits[idxMax-1], &posteProduit);

						TCOM_ProduitSupprimer (&posteProduits->produits[idxMax-1]);
						TCOM_ProduitCopier (&posteProduits->produits[idxMax], &posteProduits->produits[idxMax-1]);

						TCOM_ProduitSupprimer (&posteProduits->produits[idxMax]);
						TCOM_ProduitCopier (&posteProduit, &posteProduits->produits[idxMax]);

						TCOM_ProduitSupprimer (&posteProduit);

						idxMax--;
						if (idxMax<=0)
							break;
					}
					break;

					// Tri sur les CODE SFIN
				default:
				case 1:
					while ( (strcmp (posteProduits->produits[idxMax].sfin.chVersion, posteProduits->produits[idxMax-1].sfin.chVersion)<0) && (idxMax>0))
					{
						TCOM_ProduitCopier (&posteProduits->produits[idxMax-1], &posteProduit);

						TCOM_ProduitSupprimer (&posteProduits->produits[idxMax-1]);
						TCOM_ProduitCopier (&posteProduits->produits[idxMax], &posteProduits->produits[idxMax-1]);

						TCOM_ProduitSupprimer (&posteProduits->produits[idxMax]);
						TCOM_ProduitCopier (&posteProduit, &posteProduits->produits[idxMax]);

						TCOM_ProduitSupprimer (&posteProduit);

						idxMax--;
						if (idxMax<=0)
							break;
					}
					break;
			}
		}
	}
}

// ==============================================================================
// FONCTION : 	  IHM_SlotCreate
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int IHM_SlotCreate ( 	T_SLOT *tSlot,
//										char *strErreurMessage 	)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_SLOT *tSlot			: Définition du SLOT,
//				  - char *strErreurMessage	: Message d'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Création IHM SLOT.
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
int IHM_SlotCreate ( T_SLOT *tSlot, char *strErreurMessage )
{
	char			chMess[8192] = {'\0'};
	char			chVal[256] = {'\0'};

	// ======================
	// = Création des panel =
	// ======================

	// Création de la panel principale
	// -------------------------------
	tSlot->ihmSlot.panelMain = LoadPanel (PnlPere, gChUirFile, PNL_MAIN);
	if ( tSlot->ihmSlot.panelMain <= 0 )
		return -1;

	// Création de la panel popup
	// --------------------------
	//tSlot->ihmSlot.panelSn = LoadPanel (tSlot->ihmSlot.panelMain, gChUirFile, PNL_SN);
	//if ( tSlot->ihmSlot.panelSn <= 0 )
	//	return -1;
	/*tSlot->ihmSlot.panelPopup = LoadPanel (tSlot->ihmSlot.panelMain, gChUirFile, PNL_POPUP);
	if ( tSlot->ihmSlot.panelPopup <= 0 )
		return -1;  */

	// Création de la panel traca
	// --------------------------
	/*tSlot->ihmSlot.panelTraca = LoadPanel (tSlot->ihmSlot.panelMain, gChUirFile, PNL_TRACA);
	if ( tSlot->ihmSlot.panelTraca <= 0 )
		return -1; */

	// Création de la panel Info
	// -------------------------
	/*	tSlot->ihmSlot.panelInfo = LoadPanel (tSlot->ihmSlot.panelMain, gChUirFile, PNL_INFO);
	if ( tSlot->ihmSlot.panelInfo <= 0 )
		return -1;  */



	// Création de la panel gestion des variables de configuration
	// -----------------------------------------------------------
	/*tSlot->ihmSlot.panelVariables = LoadPanel (tSlot->ihmSlot.panelMain, gChUirFile, PNL_VAR);
	if ( tSlot->ihmSlot.panelVariables <= 0 )
		return -1; */

	// =====================
	// = RAZ variables IHM =
	// =====================
	tSlot->ihmSlot.nPopupActif = FALSE;
	//SetCtrlAttribute (tSlot->ihmSlot.panelMain, PNL_MAIN_BT_CONFIG, ATTR_DIMMED, !gnFonctionConfiguration);
	//SetCtrlAttribute (tSlot->ihmSlot.panelMain, PNL_MAIN_TEST_PRINT_SLOT, ATTR_DIMMED, !gnFonctionImprimante);
	//SetCtrlAttribute (tSlot->ihmSlot.panelMain, PNL_MAIN_LANCE_TEST, ATTR_DIMMED, !gnFonctionSansDio);
	//SetCtrlAttribute (tSlot->ihmSlot.panelMain, PNL_MAIN_LIB_SLOT, ATTR_DIMMED, !gnFonctionVerrou);
	//SetCtrlAttribute (tSlot->ihmSlot.panelMain, PNL_MAIN_BT_TRACA_SLOT, ATTR_DIMMED, !gnFonctionTraca);

	// Nettoyage du fichier LOG
	// ------------------------
	memset (tSlot->stbLog, 0, TAILLE_MAX);

	// Maj numéro SLOT
	// ---------------
	sprintf (chVal, "Slot %d", tSlot->id+1);
	SetCtrlVal (tSlot->ihmSlot.panelMain, PNL_MAIN_SLOT, chVal);

	// Maj nom application
	// -------------------
	FCT_AfficheVersionAppli ("", tSlot->ihmSlot.panelMain);

	// ====================================
	// = Affichage de la panel principale =
	// ====================================

	// MAJ de la position de la panel
	// ------------------------------
	SetPanelAttribute (tSlot->ihmSlot.panelMain, ATTR_LEFT, tSlot->ihmSlot.panelMainLeft);
	SetPanelAttribute (tSlot->ihmSlot.panelMain, ATTR_TOP, tSlot->ihmSlot.panelMainTop);




	// Affichage de la panel
	// ---------------------
	if ( DisplayPanel (tSlot->ihmSlot.panelMain) < 0 )
		return -1;


	return 0;
}

// ==============================================================================
// FONCTION : 	  IHM_SlotRemove
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int IHM_SlotRemove ( 	T_SLOT *tSlot,
//										char *strErreurMessage 	)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_SLOT *tSlot			: Définition du SLOT,
//				  - char *strErreurMessage	: Message d'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Destruction IHM SLOT.
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
int IHM_SlotRemove ( int nItfe, char *strErreurMessage )
{
    T_SLOT  *ptrSlot = &(gSlot[nItfe]);
    int status = 0;
    
	// ===================================
    // = Destruction de toutes les panel =
    // ===================================

    // Destruction de la panel popup
    // -----------------------------
    if (ptrSlot->ihmSlot.panelPopup != 0) 
	{
		if ( DiscardPanel (ptrSlot->ihmSlot.panelPopup) != 0 )
        	return -1;
	}
    ptrSlot->ihmSlot.panelPopup = -1;
    
    // Destruction de la panel popup
    // -----------------------------
    if (ptrSlot->ihmSlot.panelSuperPop != 0) 
	{
		if ( DiscardPanel (ptrSlot->ihmSlot.panelSuperPop) != 0 )
        	return -1;
	}
    ptrSlot->ihmSlot.panelSuperPop = -1;

	// Destruction de la panel traca
    // -----------------------------
    if (ptrSlot->ihmSlot.panelTraca != 0)
	{
		if ( DiscardPanel (ptrSlot->ihmSlot.panelTraca) != 0 )
    	    return -1;
    }
	ptrSlot->ihmSlot.panelTraca = -1;
    
    // Destruction de la panel Bouton
    // ------------------------------
    if (ptrSlot->ihmSlot.panelbouton != 0)
    {
        if ( DiscardPanel (ptrSlot->ihmSlot.panelbouton) != 0 )
            return -1;
    }
    ptrSlot->ihmSlot.panelbouton = -1;
	
	// Destruction de la panel Configuration
    // -------------------------------------
    if (ptrSlot->ihmSlot.panelConfiguration != 0) 
	{
		if ( DiscardPanel (ptrSlot->ihmSlot.panelConfiguration) != 0 )
        	return -1;
	}
    ptrSlot->ihmSlot.panelConfiguration = -1;
	
	// Destruction de la panel Variables
    // ---------------------------------
    if (ptrSlot->ihmSlot.panelVariables != 0) 
	{
		if ( DiscardPanel (ptrSlot->ihmSlot.panelVariables) != 0 )
        	return -1;
	}
    ptrSlot->ihmSlot.panelVariables = -1;

	// Destruction de la panel principale
    // ----------------------------------
    if (ptrSlot->ihmSlot.panelMain != 0)  
	{
		if ( DiscardPanel (ptrSlot->ihmSlot.panelMain) != 0 )
    	    return -1;
	}
    ptrSlot->ihmSlot.panelMain = -1;
    

	// ===================================
    // = Fermeture de tous les ports COM =
    // ===================================
	FCT_FermeturePortsCOM ( nItfe, strErreurMessage ); 	


	// Fermeture interface powermeter
	// ------------------------------
	/*if(ptrSlot->g_Session > 0)
	{
		rspwrmeter_close (ptrSlot->g_Session);//fermer la session du powermetter
		rsnrpz_close(ptrSlot->g_Session);
	}*/


	return 0;
}

// ==============================================================================
// FONCTION : 	  IHM_ShowPopup
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int IHM_SlotCreate ( 	T_IHM_SLOT *tIhmSlot,
//										int type,
//										char *titre,
//										char *message 	)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_IHM_SLOT *tIhmSlot	: IHM SLOT,
//				  - int type				: Type de la fenêtre popup.
//				  - char *titre				: Titre de la fenêtre popup.
//				  - char *message			: Message de la fenêtre popup.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Affichage d'une fenêtre popup.
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
int IHM_ShowPopup ( T_IHM_SLOT *tIhmSlot, int type, char *titre, char *message )
{
	int panelWidth, labelWidth, labelLeft;
	int grilleTop, labelTop, grilleHeight, labelHeight;


	// Si la fenêtre est déjà ouverte on ne fait rien
	// ----------------------------------------------
	if ( tIhmSlot->nPopupActif == TRUE )
		return -1;

	// On prend le controle de la fenêtre
	// ----------------------------------
	tIhmSlot->nPopupActif = TRUE;

	// La fenêtre principale est désactivée
	// ------------------------------------
	SetPanelAttribute (tIhmSlot->panelMain, ATTR_DIMMED , 1);

	// Configuration de la fenêtre en fonction du type choisi
	// ------------------------------------------------------
	switch (type)
	{
			// Affichage d'une fenêtre de type information
			// -------------------------------------------
		case IHM_POPUP_TYPE_INFO:
			SetCtrlAttribute (tIhmSlot->panelPopup, PNL_POPUP_CB_OK, ATTR_VISIBLE, 1);
			SetCtrlAttribute (tIhmSlot->panelPopup, PNL_POPUP_CB_OUI, ATTR_VISIBLE, 0);
			SetCtrlAttribute (tIhmSlot->panelPopup, PNL_POPUP_CB_NON, ATTR_VISIBLE, 0);
			SetPanelAttribute (tIhmSlot->panelPopup, ATTR_BACKCOLOR, VAL_WHITE);
			break;

			// Affichage d'une fenêtre de type question
			// ----------------------------------------
		case IHM_POPUP_TYPE_QUESTION:
			SetCtrlAttribute (tIhmSlot->panelPopup, PNL_POPUP_CB_OK, ATTR_VISIBLE, 0);
			SetCtrlAttribute (tIhmSlot->panelPopup, PNL_POPUP_CB_OUI, ATTR_VISIBLE, 1);
			SetCtrlAttribute (tIhmSlot->panelPopup, PNL_POPUP_CB_NON, ATTR_VISIBLE, 1);
			SetPanelAttribute (tIhmSlot->panelPopup, ATTR_BACKCOLOR, VAL_WHITE);
			break;

			// Affichage d'une fenêtre de type erreur
			// --------------------------------------
		case IHM_POPUP_TYPE_ERREUR:
			SetCtrlAttribute (tIhmSlot->panelPopup, PNL_POPUP_CB_OK, ATTR_VISIBLE, 1);
			SetCtrlAttribute (tIhmSlot->panelPopup, PNL_POPUP_CB_OUI, ATTR_VISIBLE, 0);
			SetCtrlAttribute (tIhmSlot->panelPopup, PNL_POPUP_CB_NON, ATTR_VISIBLE, 0);
			SetPanelAttribute (tIhmSlot->panelPopup, ATTR_BACKCOLOR, VAL_RED);
			break;

		default:
			return -1;
	}

	// MAJ du titre et du message de la fenêtre
	// ----------------------------------------
	SetPanelAttribute (tIhmSlot->panelPopup, ATTR_TITLE, titre);
	SetCtrlVal ( tIhmSlot->panelPopup, PNL_POPUP_TXT_MSG, message);

	// Le message est centré sur la fenêtre
	// ------------------------------------
	GetCtrlAttribute (tIhmSlot->panelPopup, PNL_POPUP_TXT_MSG, ATTR_WIDTH, &labelWidth);
	GetPanelAttribute (tIhmSlot->panelPopup, ATTR_WIDTH, &panelWidth);
	labelLeft = (int)(panelWidth-labelWidth)/2;
	SetCtrlAttribute (tIhmSlot->panelPopup, PNL_POPUP_TXT_MSG, ATTR_LEFT, labelLeft);
	GetCtrlAttribute (tIhmSlot->panelPopup, PNL_POPUP_TXT_MSG, ATTR_HEIGHT, &labelHeight);
	GetCtrlAttribute (tIhmSlot->panelPopup, PNL_POPUP_DECO_GRILLE, ATTR_HEIGHT, &grilleHeight);
	GetCtrlAttribute (tIhmSlot->panelPopup, PNL_POPUP_DECO_GRILLE, ATTR_TOP, &grilleTop);
	labelTop = ((int)(grilleHeight-labelHeight)/2) + grilleTop;
	SetCtrlAttribute (tIhmSlot->panelPopup, PNL_POPUP_TXT_MSG, ATTR_TOP, labelTop);


	// Affichage de la panel popup
	// ---------------------------
	DisplayPanel (tIhmSlot->panelPopup);

	// Attente la fermeture de la fenêtre popup
	// ----------------------------------------
	while ( tIhmSlot->nPopupActif == TRUE )
	{
		Sleep (10);
		ProcessDrawEvents();
		ProcessSystemEvents();
	}

	// Fermeture de la panel popup
	// ---------------------------
	HidePanel (tIhmSlot->panelPopup);

	// La fenêtre principale est réactivée
	// -----------------------------------
	SetPanelAttribute (tIhmSlot->panelMain, ATTR_DIMMED , 0);

	return tIhmSlot->nPopupRetour;
}

// ==============================================================================
// FONCTION : 	  IHM_ShowLot
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int IHM_ShowLot ( T_IHM_SLOT *tIhmSlot, int *lot, int *palette )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_IHM_SLOT *tIhmSlot	: IHM SLOT,
//				  - int *lot				: Valeur du lot.
//				  - int *palette			: Valeur de la palette.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Affichage d'une fenêtre sélection lot/palette.
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
int IHM_ShowLot ( T_IHM_SLOT *tIhmSlot, int *lot, int *palette )
{
	// Si la fenêtre est déjà ouverte on ne fait rien
	// ----------------------------------------------
	if ( tIhmSlot->nLotActif == TRUE )
		return -1;

	// On prend le controle de la fenêtre
	// ----------------------------------
	tIhmSlot->nLotActif = TRUE;

	// La fenêtre principale est désactivée
	// ------------------------------------
	SetPanelAttribute (tIhmSlot->panelMain, ATTR_DIMMED , 1);

	// RAZ des valeurs des lot et palette
	// ----------------------------------
	/*SetCtrlVal ( tIhmSlot->panelLot, PNL_LOT_STR_PALETTE, *palette);
	SetCtrlVal ( tIhmSlot->panelLot, PNL_LOT_STR_LOT, *lot);*/

	// Affichage de la panel Lot
	// -------------------------
	DisplayPanel (tIhmSlot->panelLot);

	// Attente la fermeture de la fenêtre Lot
	// --------------------------------------
	while ( tIhmSlot->nLotActif == TRUE )
	{
		Sleep (10);
		ProcessDrawEvents();
		ProcessSystemEvents();
	}

	// Enregistrement des valeurs Lot et Palette
	// -----------------------------------------
	//GetCtrlVal ( tIhmSlot->panelLot, PNL_LOT_STR_PALETTE, palette);
	//GetCtrlVal ( tIhmSlot->panelLot, PNL_LOT_STR_LOT, lot);

	// Fermeture de la panel Lot
	// -------------------------
	HidePanel (tIhmSlot->panelLot);

	// La fenêtre principale est réactivée
	// -----------------------------------
	SetPanelAttribute (tIhmSlot->panelMain, ATTR_DIMMED , 0);

	return 0;
}

// ==============================================================================
// FONCTION : 	  IHM_GetSlotIndexFromPanel
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int IHM_GetSlotIndexFromPanel ( int panel )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - int panel	: Handle de la panel recherchée.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - >= 0 = Index du SLOT trouvé
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Récupération de l'index du SLOT à partir de l'Handle d'une panel.
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
int IHM_GetSlotIndexFromPanel ( int panel )
{
	int idxSlot;

	// On recherche le SLOT correspondant à la panel
	// ---------------------------------------------
	for ( idxSlot=0 ; idxSlot<NBRE_INTERFACE ; idxSlot++ )
	{
		// Vérifie si la panel est celle du SLOT courant
		// ---------------------------------------------
		if ( (gSlot[idxSlot].ihmSlot.panelMain == panel)  ||
				(gSlot[idxSlot].ihmSlot.panelPopup == panel) ||
				(gSlot[idxSlot].ihmSlot.panelTraca == panel) ||
				(gSlot[idxSlot].ihmSlot.panelInfo == panel)  ||
				(gSlot[idxSlot].ihmSlot.panelLot == panel)   ||
				(gSlot[idxSlot].ihmSlot.panelVariables == panel) )
			return idxSlot;
	}

	return -1;
}

// ==============================================================================
// FONCTION : 	  IHM_CentrerObjet
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int IHM_CentrerObjet ( int panel, int objet1, int objet2, int type)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_SLOT *tSlot	: SLOT à afficher,
//				  - char *chInfo	: Message à afficher.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0
// ------------------------------------------------------------------------------
// DESRIPTION :   Alignement de deux objets graphique.
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
int IHM_CentrerObjet ( int panel, int objet1, int objet2, int type)
{
	int		objet1Top=0, objet1Left=0, objet1Height=0, objet1Width=0;
	int		objet2Top=0, objet2Left=0, objet2Height=0, objet2Width=0;


	if (objet1 > 0)
	{
		GetCtrlBoundingRect (panel, objet1, &objet1Top, &objet1Left, &objet1Height, &objet1Width);
	}
	else
	{
		SetPanelAttribute (panel, ATTR_HEIGHT, objet1Height);
		SetPanelAttribute (panel, ATTR_WIDTH, objet1Width);
	}
	GetCtrlBoundingRect (panel, objet2, &objet2Top, &objet2Left, &objet2Height, &objet2Width);

	if (type == 0)
	{
		objet2Left = objet1Left + ( (objet1Width - objet2Width) / 2 );
		SetCtrlAttribute (panel, objet2, ATTR_LEFT, objet2Left);
	}
	else if (type == 1)
	{
		objet2Top = objet1Top + ( (objet1Height - objet2Height) / 2 );
		SetCtrlAttribute (panel, objet2, ATTR_TOP, objet2Top);
	}

	return 0;
}

// ==============================================================================
// FONCTION : 	  IHM_SN
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int IHM_SlotCreate ( 	T_IHM_SLOT *tIhmSlot,
//										int type,
//										char *titre,
//										char *message 	)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_IHM_SLOT *tIhmSlot	: IHM SLOT,
//				  - int type				: Type de la fenêtre popup.
//				  - char *titre				: Titre de la fenêtre popup.
//				  - char *message			: Message de la fenêtre popup.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Affichage d'une fenêtre SN.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :		1.1.0
//  DATE :			20/11/2013
//  AUTEUR :		NW
//  DESCRIPTION :	Création issue de la personnalisation STB
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int IHM_ShowSn ( T_IHM_SLOT *tIhmSlot, char *titre )
{
	int panelWidth, labelWidth, labelLeft;
	int grilleTop, labelTop, grilleHeight, labelHeight;


	// Si la fenêtre est déjà ouverte on ne fait rien
	// ----------------------------------------------
	if ( tIhmSlot->nPopupActif == TRUE )
		return -1;

	// On prend le controle de la fenêtre
	// ----------------------------------
	tIhmSlot->nPopupActif = TRUE;

	// La fenêtre principale est désactivée
	// ------------------------------------
	//SetPanelAttribute (tIhmSlot->panelMain, ATTR_DIMMED , 1);

	// MAJ du titre et du message de la fenêtre
	// ----------------------------------------
	SetPanelAttribute (tIhmSlot->panelSn, ATTR_TITLE, titre);

	// Affichage de la panel Sn
	// ---------------------------
	DisplayPanel (tIhmSlot->panelSn);

	// La fenêtre principale est réactivée
	// -----------------------------------
	//SetPanelAttribute (tIhmSlot->panelMain, ATTR_DIMMED , 0);

	return tIhmSlot->nPopupRetour;
}


