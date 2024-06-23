#include <userint.h>
#include "IhmNFT.h"

/************************************************************************
*                     SAGEM TUNISIE     					        	*
*************************************************************************
*																		*
*	 Module	 : Main														*
*                                                                       *
*    Objet   : Logiciel Template_CVI pour les projets avec la TracaCom	*
*                                                                       *
************************************************************************/


// ==============================================================================
// INCLUDE
// ==============================================================================

#include "Include.h"

// ==============================================================================
// DECLARATION DES FONCTIONS
// ==============================================================================

// fonctions de config et de gestion du test
// -----------------------------------------
static int ChargeConfigTesteur (void);
static int ChargeInitTesteur (void);
static int ChargeConfigPosteTracaCom (void);
int ChargeMessage (void);

int main (int argc, char *argv[])
{
	int					ii;
	int					status = 0;
	int					wasOtherInstance;
	char				chMess[1024];
	__int64 			errorCode;
	T_POSTE_PRODUITS    *ptrProduits = &gPosteProduits;
	char    			chErr[1024] = {'\0'};
	// ================
	// = Init système =
	// ================
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;

	EnableBreakOnLibraryErrors ();
	SetSleepPolicy (VAL_SLEEP_MORE);

	GetProjectDir (gChCurrentDir);
	// =======================================
	// = Une seule instance de l'application =
	// =======================================
	if (CheckForDuplicateAppInstance (DO_NOT_ACTIVATE_OTHER_INSTANCE, &wasOtherInstance) < -1)
	{
		MessagePopup ("Erreur initialisation testeur", "Allocation des ressources systèmes impossibles");
		return -1;
	}
	if (wasOtherInstance)
	{
		MessagePopup ("Erreur initialisation testeur", "Cette application est déjà ouverte");
		return -1;
	}

	// Chargement des messages => On prend le Messages.txt à la racine
	// ---------------------------------------------------------------
	if ( ChargeMessage() < 0)
	{
		MessagePopup ("ERROR","ERROR LOADING MESSAGES");
		return -1;
	}

	int Ping=-1;


	//status = InetPing ("192.168.5.1" , &Ping, 1000);



	// =========================================================
	// = Recherche de l'argument -> Chemin pour le fichier INI =
	// =========================================================
	GetProjectDir (gChCurrentDir);
	if (argc > 1)
	{
		MakePathname (argv[1], FIC_CONFIG_NOM, gChIniFile);
	}
	else
	{
		// Le fichier INI doit se trouver dans le répertoire de l'EXE
		// ----------------------------------------------------------
		MakePathname (gChCurrentDir, FIC_CONFIG_NOM, gChIniFile);
	}

	// ===================================
	// = Chargement des configs testeurs =
	// ===================================

	// Chargement de la config du testeur depuis le fichier .ini
	// ---------------------------------------------------------
	if (ChargeConfigTesteur() < 0)
		return -1;


	// Configuration du testeur
	// ------------------------

	if( ChargeInitTesteur ()<0)
		return -1;

	// ======================
	// = Connexion à la BDD =
	// ======================
	if (!status)
	{
		if ( SCPROD_Connexion ( &gTcomBase, chErr ) != 0 )
		{
			sprintf (chMess, GET_MESSAGE(MAI_MSG_POPUP_3), chErr);
			MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
			return -1;
		}
	}

	// ==============================================
	// = Récupération des informations sur ce poste =
	// ==============================================
	if (!status)
		errorCode = SCPROD_PosteInformations ( &gTcomBase, &gPosteInfos, chMess );
	if (errorCode)
	{
		sprintf (chMess, "Erreur récupération infos poste : %s\n", chMess);
		MessagePopup ("Erreur", chMess);
		return -1;
	}

	//===========================================================
	// = Chargement de la config du testeur en BDD SAPME  =
	//===========================================================
	if (ChargeConfigPosteTracaCom() < 0)
		return -1;
	// =======================
	// = Création de verrous =
	// =======================
	CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &IdLockBDD);
	//CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &IdSnClient);
	CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &IdLockCle);

	// ==================================================
	// = Chargement et affichage du panel choix produit =
	// ==================================================
	if (!status)
	{
		PnlProduitId = LoadPanel (0, gChUirFile, PNL_INTIT);

		// Gestion IHM
		// -----------
		SetCtrlAttribute (PnlProduitId, PNL_INTIT_INTIT, ATTR_VISIBLE, FALSE);
		SetCtrlAttribute (PnlProduitId, PNL_INTIT_VALIDER, ATTR_VISIBLE, FALSE);
		SetCtrlAttribute (PnlProduitId, PNL_INTIT_ANNULER, ATTR_VISIBLE, FALSE);
		SetCtrlAttribute (PnlProduitId, PNL_INTIT_SLIDE, ATTR_VISIBLE, TRUE);
		SetCtrlAttribute (PnlProduitId, PNL_INTIT_TXT_SLIDE, ATTR_VISIBLE, TRUE);
		SetCtrlVal (PnlProduitId, PNL_INTIT_SLIDE, 0);
		ProcessDrawEvents ();
		DisplayPanel (PnlProduitId);
	}
	if (!status)
	{
		FCT_AfficheVersionAppli (NOM_SOFT, PnlProduitId);
	}

	// ============================
	// = Chargement liste produit =
	// ============================
	if (!status)
		status = ChargeListeProduits ();

	// ===============
	// = Gestion IHM =
	// ===============
	if (!status)
	{
		SetCtrlAttribute (PnlProduitId, PNL_INTIT_SLIDE, ATTR_VISIBLE, FALSE);
		SetCtrlAttribute (PnlProduitId, PNL_INTIT_TXT_SLIDE, ATTR_VISIBLE, FALSE);
		SetCtrlAttribute (PnlProduitId, PNL_INTIT_INTIT, ATTR_VISIBLE, TRUE);
		SetCtrlAttribute (PnlProduitId, PNL_INTIT_VALIDER, ATTR_VISIBLE, TRUE);
		SetCtrlAttribute (PnlProduitId, PNL_INTIT_ANNULER, ATTR_VISIBLE, TRUE);
	}

	// =============================================
	// = Init de l'IHM et lancement de l'interface =
	// =============================================
	if (!status)

		RunUserInterface ();

	// =================================
	// = Attente de fin du thread slot =
	// =================================
	for (ii = 0; ii < NBRE_INTERFACE; ii++)
	{
		do
		{
			Sleep (100);
			ProcessSystemEvents ();
		}
		while (gSlot[ii].idThread > 0);

		gSlot[ii].ihmSlot.nEtat = ETAT_FERMETURE;
		IHM_GestCtrlPnl (ii);
	}

	//libération du lock pour le partitionnement avec diskpart
	//CmtDiscardLock (gLockDiskpart);
	//CmtDiscardLock (gLockUsbTree);
	//CmtDiscardLock (gLockOpenVerin);

	// ============================================================
	// = Fermeture des ports numériques E/S interface et de l'IHM =
	// ============================================================
	for (ii = 0; ii < NBRE_INTERFACE; ii++)
	{
		// Fermeture des IHM SLOT
		// ----------------------
		//if ( gSlot[ii].ihmSlot.nActif && (status == 0) )
		if ( status == 0 )
			IHM_SlotRemove (ii, chMess );

		// Fermeture ports numériques
		// --------------------------

	}

	// ====================
	// = RAZ des produits =
	// ====================
	FCT_ProduitsRaz (ptrProduits);

	// =========================
	// = Déconnexion de la BDD =
	// =========================
	if ( SCPROD_Deconnexion ( &gTcomBase ) != 0 )
		return -1;



	// =====================================
	// = Destruction des verrous acces BDD =
	// =====================================
	//CmtDiscardLock (IdPrinter);
	//CmtDiscardLock (IdSnClient);
	CmtDiscardLock (IdLockCle);

	// ===================
	// = Fin Main Thread =
	// ===================
	EnableBreakOnLibraryErrors ();
	CloseCVIRTE ();

	return 0;
}

// ==============================================================================
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :	Chargement des données du fichier INI
// ==============================================================================
int ChargeMessage (void)
{
	IniText 	ficIni;
	int 		status;
	int		   	ii=0;
	char 		gChLangueFile[MAX_PATHNAME_LEN];
	int 		error;

	// Le fichier TXT doit se trouver dans le répertoire de l'EXE
	// ----------------------------------------------------------
	errChk( MakePathname (gChCurrentDir, FIC_MESSAGES, gChLangueFile));

	// selon la langue du fichier ini => On ouvre le bon fichier langue
	// ---------------------------------
	ficIni = Ini_New (0);
	errChk( Ini_ReadFromFile (ficIni, gChLangueFile));

	// On rempli la structure
	// ----------------------------------
	for (ii = 0; ii < gNbMessage; ii++)
	{
		status = Ini_ItemExists (ficIni, SECTION_NAME, gLangues[ii].chTag);
		if (status == FALSE)
			errChk( -1);
		status = Ini_GetStringIntoBuffer (ficIni, SECTION_NAME, gLangues[ii].chTag, gLangues[ii].chMessage , TAILLE_MESSAGE_MAX);
		if (status != TRUE)
			errChk( -1);
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
//  FONCTION     : ChargeConfigTesteu
//  VERSION      : S12001AA01
//  DATE         : 02/04/2012
//  AUTEUR       : TNI
//  DESCRIPTION  : Chargement des données du fichier INI
//  MODIFICATION :
// ==============================================================================
static int ChargeConfigTesteur (void)
{
	int		status;
	char	chMess[1024];
	char	chParam[1024];
	char	chValeur[1024];
	char	*pMess;
	int		ii;
	int		idxSlot;
	IniText ficIni;

	//////////////////////////////////////////////////
	//	Lire fichier Config
	//////////////////////////////////////////////////
	ficIni = Ini_New (0);

	if ((status = Ini_ReadFromFile (ficIni, gChIniFile)))
	{
		pMess = GetGeneralErrorString (status);
		Fmt (chMess, "Code d'erreur %i : %s.\n\n", status, pMess);
		Fmt (chMess, "%sFichier de config %s non trouvé.\n\n", chMess, gChIniFile);
		ClipboardPutText (chMess);
		Fmt (chMess, "%s(Message copié vers le presse-papier)", chMess);
		MessagePopup ("Erreur initialisation", chMess);
		Ini_Dispose (ficIni);
		return -1;
	}

	//////////////////////////////////////////////////
	// Options de connexion Dinan
	//////////////////////////////////////////////////
	if (Ini_ItemExists (ficIni, ETIQ_INIT, "ConnexionDinan"))
	{
		Ini_GetInt (ficIni, ETIQ_INIT, "ConnexionDinan", &gConnexionDinan);
	}

	//////////////////////////////////////////////////
	// charger le nom des bases de données
	//////////////////////////////////////////////////
	if (!Ini_ItemExists (ficIni, ETIQ_INIT, INI_VAL_SERVEUR_ADRESSE))
	{
		Fmt (chMess, "Nom du serveur \"%s\" non trouvé dans section [%s] du fichier %s\n\n", INI_VAL_SERVEUR_ADRESSE, gChNomPc, gChIniFile);
		ClipboardPutText (chMess);
		Fmt (chMess, "%s(Message copié vers le presse-papier)", chMess);
		MessagePopup ("Erreur initialisation", chMess);
		Ini_Dispose (ficIni);
		return -1;
	}
	Ini_GetStringIntoBuffer (ficIni, ETIQ_INIT, INI_VAL_SERVEUR_ADRESSE, gTcomBase.nomServeur, TCOM_PARAM_TAILLE_MAX);

	if (!Ini_ItemExists (ficIni, ETIQ_INIT, INI_VAL_SERVEUR_PORT))
	{
		Fmt (chMess, "Nom du serveur \"%s\" non trouvé dans section [%s] du fichier %s\n\n", INI_VAL_SERVEUR_PORT, gChNomPc, gChIniFile);
		ClipboardPutText (chMess);
		Fmt (chMess, "%s(Message copié vers le presse-papier)", chMess);
		MessagePopup ("Erreur initialisation", chMess);
		Ini_Dispose (ficIni);
		return -1;
	}
	Ini_GetInt (ficIni, ETIQ_INIT, INI_VAL_SERVEUR_PORT, &gTcomBase.portServeur);

	if (!Ini_ItemExists (ficIni, ETIQ_INIT, INI_VAL_SERVEUR_LOGIN))
	{
		Fmt (chMess, "Nom du serveur \"%s\" non trouvé dans section [%s] du fichier %s\n\n", INI_VAL_SERVEUR_LOGIN, gChNomPc, gChIniFile);
		ClipboardPutText (chMess);
		Fmt (chMess, "%s(Message copié vers le presse-papier)", chMess);
		MessagePopup ("Erreur initialisation", chMess);
		Ini_Dispose (ficIni);
		return -1;
	}
	Ini_GetStringIntoBuffer (ficIni, ETIQ_INIT, INI_VAL_SERVEUR_LOGIN, gTcomBase.loginServeur, TCOM_PARAM_TAILLE_MAX);

	/*if (!Ini_ItemExists (ficIni, ETIQ_INIT, INI_VAL_SERVEUR_PASSWORD))
	{
		Fmt (chMess, "Nom du serveur \"%s\" non trouvé dans section [%s] du fichier %s\n\n", INI_VAL_SERVEUR_PASSWORD, gChNomPc, gChIniFile);
		ClipboardPutText (chMess);
		Fmt (chMess, "%s(Message copié vers le presse-papier)", chMess);
		MessagePopup ("Erreur initialisation", chMess);
		Ini_Dispose (ficIni);
		return -1;
	}
	Ini_GetStringIntoBuffer (ficIni, ETIQ_INIT, INI_VAL_SERVEUR_PASSWORD, gTcomBase.passServeur, TCOM_PARAM_TAILLE_MAX);
	 */
	if (!Ini_ItemExists (ficIni, ETIQ_INIT, INI_VAL_SERVEUR_NOM_BASE))
	{
		Fmt (chMess, "Nom du serveur \"%s\" non trouvé dans section [%s] du fichier %s\n\n", INI_VAL_SERVEUR_NOM_BASE, gChNomPc, gChIniFile);
		ClipboardPutText (chMess);
		Fmt (chMess, "%s(Message copié vers le presse-papier)", chMess);
		MessagePopup ("Erreur initialisation", chMess);
		Ini_Dispose (ficIni);
		return -1;
	}
	Ini_GetStringIntoBuffer (ficIni, ETIQ_INIT, INI_VAL_SERVEUR_NOM_BASE, gTcomBase.nomBase, TCOM_PARAM_TAILLE_MAX);

	//////////////////////////////////////////////////
	// charger flag INI_VAL_ACTIVE_LOG
	//////////////////////////////////////////////////
	if (!Ini_ItemExists (ficIni, ETIQ_INIT, INI_VAL_ACTIVE_LOG))
	{
		Fmt (chMess, "Clef \"%s\" non trouvée dans section [%s] du fichier %s\n\n", INI_VAL_ACTIVE_LOG, gChNomPc, gChIniFile);
		ClipboardPutText (chMess);
		Fmt (chMess, "%s(Message copié vers le presse-papier)", chMess);
		MessagePopup ("Erreur initialisation", chMess);
		Ini_Dispose (ficIni);
		return -1;
	}
	Ini_GetInt (ficIni, ETIQ_INIT, INI_VAL_ACTIVE_LOG, &gActiveLog);

	//////////////////////////////////////////////////
	// Récupération du nom du PC dans système
	//////////////////////////////////////////////////
	if (status =  GetCompName(gChNomPc))
	{
		pMess = GetGeneralErrorString (status);
		Fmt (chMess, "Code d'erreur %i : %s.\n\n", status, pMess);
		Fmt (chMess, "%sNom du Pc non récupérable dans système.\n\n", pMess);
		ClipboardPutText (chMess);
		Fmt (chMess, "%s(Message copié vers le presse-papier)", chMess);
		MessagePopup ("Erreur initialisation", chMess);
		Ini_Dispose (ficIni);
		return -1;
	}

	//////////////////////////////////////////////////
	//vérifier section Pc_nom existante ds fic Config
	//////////////////////////////////////////////////
	if (!Ini_SectionExists (ficIni, gChNomPc))
	{
		Fmt (chMess, "Section [%s] non trouvée dans fichier %s\n\n", gChNomPc, gChIniFile);
		ClipboardPutText (chMess);
		Fmt (chMess, "%s(Message copié vers le presse-papier)", chMess);
		MessagePopup ("Erreur initialisation", chMess);
		Ini_Dispose (ficIni);
		return -1;
	}

	//////////////////////////////////////////////////
	//charger le nom du testeur (char [])
	//////////////////////////////////////////////////
	if (!Ini_ItemExists (ficIni, gChNomPc, INI_VAL_NOM_TESTEUR))
	{
		Fmt (chMess, "Clef \"%s\" non trouvée dans section [%s] du fichier %s\n\n", INI_VAL_NOM_TESTEUR, gChNomPc, gChIniFile);
		ClipboardPutText (chMess);
		Fmt ( chMess, "%s(Message copié vers le presse-papier)", chMess);
		MessagePopup ("Erreur initialisation", chMess);
		Ini_Dispose (ficIni);
		return -1;
	}
	Ini_GetStringIntoBuffer (ficIni, gChNomPc, INI_VAL_NOM_TESTEUR, gPosteInfos.chNom, TCOM_PARAM_TAILLE_MAX);
//	sprintf (gPosteInfos.chNom, TCOM_BHD_NOM);

	//////////////////////////////////////////////////
	//charger le nom du testeur (char [])
	//////////////////////////////////////////////////
	if (!Ini_ItemExists (ficIni, gChNomPc, INI_VAL_NUMERO_USINE))
	{
		Fmt (chMess, "Clef \"%s\" non trouvée dans section [%s] du fichier %s\n\n", INI_VAL_NUMERO_USINE, gChNomPc, gChIniFile);
		ClipboardPutText (chMess);
		Fmt ( chMess, "%s(Message copié vers le presse-papier)", chMess);
		MessagePopup ("Erreur initialisation", chMess);
		Ini_Dispose (ficIni);
		return -1;
	}
	Ini_GetInt (ficIni, gChNomPc, INI_VAL_NUMERO_USINE, &gPosteInfos.numCentre);

	////////////////////////////////////////////////////////////////////////////////
	// charger le chemin du répertoire contenant les fichiers LOG (char [])
	////////////////////////////////////////////////////////////////////////////////
	if (!Ini_ItemExists (ficIni, gChNomPc, INI_VAL_CHEMIN_LOG))
	{
		Fmt (chMess, "Clef \"%s\" non trouvée dans section [%s] du fichier %s\n\n", INI_VAL_CHEMIN_LOG, gChNomPc, gChIniFile);
		ClipboardPutText (chMess);
		Fmt ( chMess, "%s(Message copié vers le presse-papier)", chMess);
		MessagePopup ("Erreur initialisation", chMess);
		Ini_Dispose (ficIni);
		return -1;
	}
	Ini_GetStringIntoBuffer (ficIni, gChNomPc, INI_VAL_CHEMIN_LOG, chValeur, TAILLE_MIN);
	for ( ii=0 ; ii<NBRE_INTERFACE ; ii++ )
		strcpy ( gSlot[ii].chCheminLog, chValeur);



	// =========================================
	// = Chargement des configuration des SLOT =
	// =========================================
	for (idxSlot = 0; idxSlot < NBRE_INTERFACE; idxSlot++)
	{
		//////////////////////////////////////////////////
		// Charger validité des slots
		//////////////////////////////////////////////////
		sprintf (chParam, INI_VAL_SLOT, idxSlot);
		if (!Ini_ItemExists (ficIni, gChNomPc, chParam))
		{
			Fmt (chMess, "Clef \"%s\" non trouvée dans section [%s] du fichier %s\n\n", chParam, gChNomPc, gChIniFile);
			ClipboardPutText (chMess);
			Fmt (chMess, "%s(Message copié vers le presse-papier)", chMess);
			MessagePopup ("Erreur initialisation", chMess);
			Ini_Dispose (ficIni);
			return -1;
		}
		Ini_GetInt (ficIni, gChNomPc, chParam, &gSlot[idxSlot].ihmSlot.nActif);

		////////////////////////////////
		// Charger la position left IHM
		////////////////////////////////
		sprintf (chParam, INI_VAL_IHM_POSITION_LEFT, idxSlot);
		if (!Ini_ItemExists (ficIni, gChNomPc, chParam))
		{
			Fmt (chMess, "Clef \"%s\" non trouvée dans section [%s] du fichier %s\n\n", chParam, gChNomPc, gChIniFile);
			ClipboardPutText (chMess);
			Fmt (chMess, "%s(Message copié vers le presse-papier)", chMess);
			MessagePopup ("Erreur initialisation", chMess);
			Ini_Dispose (ficIni);
			return -1;
		}
		Ini_GetInt (ficIni, gChNomPc, chParam, &gSlot[idxSlot].ihmSlot.panelMainLeft);

		////////////////////////////////
		// Charger la position top IHM
		////////////////////////////////
		sprintf (chParam, INI_VAL_IHM_POSITION_TOP, idxSlot);
		if (!Ini_ItemExists (ficIni, gChNomPc, chParam))
		{
			Fmt (chMess, "Clef \"%s\" non trouvée dans section [%s] du fichier %s\n\n", chParam, gChNomPc, gChIniFile);
			ClipboardPutText (chMess);
			Fmt (chMess, "%s(Message copié vers le presse-papier)", chMess);
			MessagePopup ("Erreur initialisation", chMess);
			Ini_Dispose (ficIni);
			return -1;
		}
		Ini_GetInt (ficIni, gChNomPc, chParam, &gSlot[idxSlot].ihmSlot.panelMainTop);

		// Si le SLOT n'est pas activé on passe au suivant
		// -----------------------------------------------
		if ( !gSlot[idxSlot].ihmSlot.nActif )
			continue;

		////////////////////////////////
		// Charger Port COM Decodeur
		////////////////////////////////
		sprintf (chParam, INI_VAL_PORT_DECODEUR, idxSlot);
		if (!Ini_ItemExists (ficIni, gChNomPc, chParam))
		{
			Fmt (chMess, "Clef \"%s\" non trouvée dans section [%s] du fichier %s\n\n", chParam, gChNomPc, gChIniFile);
			ClipboardPutText (chMess);
			Fmt (chMess, "%s(Message copié vers le presse-papier)", chMess);
			MessagePopup ("Erreur initialisation", chMess);
			Ini_Dispose (ficIni);
			return -1;
		}
		Ini_GetInt (ficIni, gChNomPc, chParam, &gSlot[idxSlot].comDecodeur.tConfig.numPort);

		////////////////////////////////
		// Charger Baud COM Decodeur
		////////////////////////////////
		sprintf (chParam, INI_VAL_BAUD_DECODEUR, idxSlot);
		if (!Ini_ItemExists (ficIni, gChNomPc, chParam))
		{
			Fmt (chMess, "Clef \"%s\" non trouvée dans section [%s] du fichier %s\n\n", chParam, gChNomPc, gChIniFile);
			ClipboardPutText (chMess);
			Fmt (chMess, "%s(Message copié vers le presse-papier)", chMess);
			MessagePopup ("Erreur initialisation", chMess);
			Ini_Dispose (ficIni);
			return -1;
		}
		Ini_GetInt (ficIni, gChNomPc, chParam, &gSlot[idxSlot].comDecodeur.tConfig.baud);



		////////////////////////////////
		// Charger RESSOURCE
		////////////////////////////////
		/*sprintf (chParam, NOM_RESSOURCE, idxSlot);
		if (!Ini_ItemExists (ficIni, gChNomPc, chParam))
		{
			Fmt (chMess, "Clef \"%s\" non trouvée dans section [%s] du fichier %s\n\n", chParam, gChNomPc, gChIniFile);
			ClipboardPutText (chMess);
			Fmt (chMess, "%s(Message copié vers le presse-papier)", chMess);
			MessagePopup ("Erreur initialisation", chMess);
			Ini_Dispose (ficIni);
			return -1;
		}
		Ini_GetInt (ficIni, gChNomPc, chParam, &gSlot[idxSlot].sRessource);
		 */

	}



	Ini_Dispose (ficIni);
	return 0;
}

// ==============================================================================
//  FONCTION     : ChargeInitTesteur
//  VERSION      : S12001AA01
//  DATE         : 02/04/2012
//  AUTEUR       : TNI
//  DESCRIPTION  : Fonction de configuration des ports COM
//  MODIFICATION :
// ==============================================================================
static int ChargeInitTesteur (void)
{
	int ii;

	//////////////////////////////////////////////////////////////////////////
	//	Attribution paramètres port COM ( sauf Numport et Baud en fichier INI)
	//////////////////////////////////////////////////////////////////////////
	for (ii = 0; ii < NBRE_INTERFACE; ii++)
	{
		// paramètres port COM decodeur
		gSlot[ii].comDecodeur.tConfig.syncAssync	=  RS232_ASSYNC;
		gSlot[ii].comDecodeur.tConfig.bitDonnee		=  8;
		gSlot[ii].comDecodeur.tConfig.parite		=  0;
		gSlot[ii].comDecodeur.tConfig.bitStop		=  0;
		gSlot[ii].comDecodeur.tConfig.testParite	=  RS232_OUI;

		// paramètres port COM Caisson
		gSlot[ii].comCaisson.tConfig.syncAssync   =  RS232_ASSYNC;
		gSlot[ii].comCaisson.tConfig.bitDonnee    =  8;
		gSlot[ii].comCaisson.tConfig.parite       =  0;
		gSlot[ii].comCaisson.tConfig.bitStop      =  0;
		gSlot[ii].comCaisson.tConfig.testParite   =  RS232_OUI;

		// paramètres port COM Générique
		gSlot[ii].comGenerique_A.tConfig.syncAssync   =  RS232_ASSYNC;
		gSlot[ii].comGenerique_A.tConfig.bitDonnee    =  8;
		gSlot[ii].comGenerique_A.tConfig.parite       =  0;
		gSlot[ii].comGenerique_A.tConfig.bitStop      =  0;
		gSlot[ii].comGenerique_A.tConfig.testParite   =  RS232_OUI;


#ifndef PRES_RS232
		// paramètres port COM imprimante
		gSlot[ii].comImprimante.tConfig.syncAssync	=  RS232_ASSYNC;
		gSlot[ii].comImprimante.tConfig.bitDonnee	=  8;
		gSlot[ii].comImprimante.tConfig.parite		=  0;
		gSlot[ii].comImprimante.tConfig.bitStop 	=  0;
		gSlot[ii].comImprimante.tConfig.testParite	=  RS232_OUI;
#endif
	}

	return 0;
}

int CVICALLBACK Quiiter (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DiscardPanel (PnlProduitId);
			gNPAbort = TRUE;
			QuitUserInterface (1);
			//HidePanel(panel) ;
			return 0;
			break;
	}
	return 0;
}

/********************************************************************/
/*	Chargement des données du ConfigPosteTracaCom					*/
/********************************************************************/
static int ChargeConfigPosteTracaCom (void)
{
	//char	chValeur[1024];
	int		status;
	char	chMess[1024];
	//char	*pMess;
	//int		idxSlot = 0;
	char    NomTesteur[100];
	char    cSectionPos[200]= {"\0"};
	char    chNomSousSection [200]= {"\0"};

	// Récupératuion des variables depuis la base de données
	//-------------------------------------------------------
	char     **TableauParametres = NULL;
	int      NombreLignesTab = 0;
	int		 iIndexValeur = 3;
	int		 NombreColonnes = 0;
	int		 iIndexNom = 1;
	int      iCpt = 0;
	int      idxPos = 0;
	int		iCompteurBoucle = 0;


	// Récupération du nom du PC
	//--------------------------
	if (status =  GetCompName(NomTesteur))
	{
		MessagePopup(GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR),GET_MESSAGE(MAI_MSG_POPUP_9));
		return -1;
	}

	// Récupération paramètres Généraux du testeur
	//---------------------------------------------
	if(TCOM_RecuperationSectionParametres (&gTcomBase, INI_VAL_GENERAL , &TableauParametres, &NombreLignesTab, &NombreColonnes, chMess) != 0)
	{
		sprintf(chMess,GET_MESSAGE(MAI_MSG_POPUP_10),chMess,INI_VAL_GENERAL);
		MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
		return -1;
	}

	// On teste si la chaine est bien trouvé
	// --------------------------------------
	if ( iCpt == NombreLignesTab )
	{
		sprintf (chMess, GET_MESSAGE(MAI_MSG_POPUP_11), NomTesteur,INI_VAL_GENERAL,gPosteInfos.chNom);
		MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
		return -1;
	}


	////////////////////////////////////////////////////////////////////////////////
	// Charger la valeur du canal 2G
	////////////////////////////////////////////////////////////////////////////////

	// On boucle sur le tableau de la section
	// --------------------------------------
	for ( iCpt = 0 ; iCpt < NombreLignesTab ;  iCpt++ )
	{
		// On Regarde si on trouve le champ recherché
		// ------------------------------------------
		if (strcmp(TableauParametres[iCpt*NombreColonnes+iIndexNom],INI_VAL_CANAL_2G) == 0)
		{
			// C'est un entier, On assigne donc la valeur définie en base au paramètre
			// ------------------------------------------------------------------------
			sscanf(TableauParametres[iCpt*NombreColonnes+iIndexValeur],"%d", &gnCanal2G);

			// Si paramètre trouvé, on sort de la boucle
			// -----------------------------------------
			break;
		}
	}
	// Si paramètre non trouvé, on aura parcouru toute la boucle - on assigne alors la valeur par défaut
	// -------------------------------------------------------------------------------------------------
	// Si paramètre non trouvé, on aura parcouru toute la boucle et donc on sort en erreur
	// -----------------------------------------------------------------------------------
	if ( iCompteurBoucle == NombreLignesTab )
	{
		Fmt (chMess, GET_MESSAGE(MAI_MSG_POPUP_12), INI_VAL_CANAL_2G, S_GENERAL, gPosteInfos.chNom);
		ClipboardPutText (chMess);
		Fmt ( chMess, GET_MESSAGE(GENERIQUE_MSG_POPUP_PRESSE_PAPIER), chMess);
		MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP), chMess);
		return -1;
	}

	////////////////////////////////////////////////////////////////////////////////
	// Charger la valeur du canal 5G
	////////////////////////////////////////////////////////////////////////////////

	// On boucle sur le tableau de la section
	// --------------------------------------
	for ( iCpt = 0 ; iCpt < NombreLignesTab ;  iCpt++ )
	{
		// On Regarde si on trouve le champ recherché
		// ------------------------------------------
		if (strcmp(TableauParametres[iCpt*NombreColonnes+iIndexNom],INI_VAL_CANAL_5G) == 0)
		{
			// C'est un entier, On assigne donc la valeur définie en base au paramètre
			// ------------------------------------------------------------------------
			sscanf(TableauParametres[iCpt*NombreColonnes+iIndexValeur],"%d", &gnCanal5G);

			// Si paramètre trouvé, on sort de la boucle
			// -----------------------------------------
			break;
		}
	}
	// Si paramètre non trouvé, on aura parcouru toute la boucle - on assigne alors la valeur par défaut
	// -------------------------------------------------------------------------------------------------
	// Si paramètre non trouvé, on aura parcouru toute la boucle et donc on sort en erreur
	// -----------------------------------------------------------------------------------
	if ( iCompteurBoucle == NombreLignesTab )
	{
		Fmt (chMess, GET_MESSAGE(MAI_MSG_POPUP_12), INI_VAL_CANAL_2G, S_GENERAL, gPosteInfos.chNom);
		ClipboardPutText (chMess);
		Fmt ( chMess, GET_MESSAGE(GENERIQUE_MSG_POPUP_PRESSE_PAPIER), chMess);
		MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP), chMess);
		return -1;
	}

	// =========================================
	// = Chargement des configuration des SLOT =
	// =========================================
	for ( idxPos=0 ; idxPos<NBRE_INTERFACE ; ++idxPos )
	{
		// Récupération de l'ensemble des paramètres liée à un slot X
		//-----------------------------------------------------------
		sprintf(cSectionPos,INI_VAL_SLOT_BDD,idxPos);
		if(TCOM_RecuperationSectionParametres (&gTcomBase, cSectionPos , &TableauParametres, &NombreLignesTab, &NombreColonnes, chMess) != 0)
		{
			sprintf(chMess,GET_MESSAGE(MAI_MSG_POPUP_14),cSectionPos,gPosteInfos.chNom);
			MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
			return -1;
		}

		// On teste si la chaine est bien trouvé
		// --------------------------------------
		if ( iCpt == NombreLignesTab )
		{
			sprintf (chMess, GET_MESSAGE(MAI_MSG_POPUP_12), chNomSousSection,cSectionPos,gPosteInfos.chNom);
			MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
			return -1;
		}

		//-------------------------------------------------------
		// Récupération nom de la ressource SAPME
		//-------------------------------------------------------
		sprintf (chNomSousSection, INI_VAL_RESSOURCE_SAPME, idxPos);

		for ( iCpt= 0 ; iCpt < NombreLignesTab ; ++iCpt )
		{
			if (strcmp (chNomSousSection,TableauParametres[iCpt*NombreColonnes+iIndexNom]) == 0)
			{
				// Cas ou le paramètre est dans le dernier ligne
				//----------------------------------------------
				if(iCpt == NombreLignesTab) iCpt = iCpt -1;

				// C'est un char [], On assigne donc la valeur définie en base au paramètre
				// ------------------------------------------------------------------------
				strncpy(gSlot[idxPos].variablesTraca.NomRessourceSAPME,TableauParametres[iCpt*NombreColonnes+iIndexValeur],TAILLE_MAX);

				// Si paramètre trouvé, on sort de la boucle
				// -----------------------------------------
				break;
			}
		}

		// On teste si la chaine est bien trouvé
		// --------------------------------------
		if ( iCpt == NombreLignesTab )
		{
			sprintf (chMess, GET_MESSAGE(MAI_MSG_POPUP_12), chNomSousSection,cSectionPos,gPosteInfos.chNom);
			MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
			return -1;
		}



		//-------------------------------------------------------
		// Récupération Instrument ID des slots
		//-------------------------------------------------------
		sprintf (chNomSousSection, INI_VAL_INSTR_SLOT,idxPos);
		for ( iCpt= 0 ; iCpt < NombreLignesTab ; ++iCpt )
		{
			if (strcmp(chNomSousSection,TableauParametres[iCpt*NombreColonnes+iIndexNom]) == 0)
			{
				// Cas ou le paramètre est dans le dernier ligne
				//----------------------------------------------
				if(iCpt == NombreLignesTab) iCpt = iCpt -1;
				strcpy ( gSlot[idxPos].BNFTnteg.gInstrumentID, TableauParametres[iCpt*NombreColonnes+iIndexValeur]);
				break;
			}
		}

		// On teste si la chaine est bien trouvé
		// --------------------------------------
		if ( iCpt == NombreLignesTab )
		{
			sprintf (chMess, GET_MESSAGE(MAI_MSG_POPUP_12), chNomSousSection,cSectionPos,gPosteInfos.chNom);
			MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
			return -1;
		}


		//-------------------------------------------------------
		// Récupération Type powermetter
		//-------------------------------------------------------
		sprintf (chNomSousSection, INI_VAL_PWR_TYPE,idxPos);
		for ( iCpt= 0 ; iCpt < NombreLignesTab ; ++iCpt )
		{
			if (strcmp(chNomSousSection,TableauParametres[iCpt*NombreColonnes+iIndexNom]) == 0)
			{
				// Cas ou le paramètre est dans le dernier ligne
				//----------------------------------------------
				if(iCpt == NombreLignesTab) iCpt = iCpt -1;
				strcpy ( gSlot[idxPos].BNFTnteg.gPwrmetterType, TableauParametres[iCpt*NombreColonnes+iIndexValeur]);
				break;
			}
		}

		// On teste si la chaine est bien trouvé
		// --------------------------------------
		if ( iCpt == NombreLignesTab )
		{
			sprintf (chMess, GET_MESSAGE(MAI_MSG_POPUP_12), chNomSousSection,cSectionPos,gPosteInfos.chNom);
			MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
			return -1;
		}

		////////////////////////////////////////////////////////////////////////////////
		// Charger Port COM Générique
		////////////////////////////////////////////////////////////////////////////////
		/*
		sprintf (chNomSousSection, INI_VAL_PORT_GEN_A,idxPos);
		for ( iCpt= 0 ; iCpt < NombreLignesTab ; ++iCpt )
		{
			if (strcmp(chNomSousSection,TableauParametres[iCpt*NombreColonnes+iIndexNom]) == 0)
			{
				// Cas ou le paramètre est dans le dernier ligne
				//----------------------------------------------
				if(iCpt == NombreLignesTab) iCpt = iCpt -1;
				sscanf(TableauParametres[iCpt*NombreColonnes+iIndexValeur],"%d", &gSlot[idxPos].comGenerique_A.tConfig.numPort);
				break;
			}
		}

		// On teste si la chaine est bien trouvé
		// --------------------------------------
		if ( iCpt == NombreLignesTab )
		{
			sprintf (chMess, GET_MESSAGE(MAI_MSG_POPUP_12), chNomSousSection,cSectionPos,gPosteInfos.chNom);
			MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
			return -1;
		}
			 */
		////////////////////////////////////////////////////////////////////////////////
		// Charger Port COM Caisson
		////////////////////////////////////////////////////////////////////////////////

		sprintf (chNomSousSection, INI_VAL_PORT_CAISSON,idxPos);
		for ( iCpt= 0 ; iCpt < NombreLignesTab ; ++iCpt )
		{
			if (strcmp(chNomSousSection,TableauParametres[iCpt*NombreColonnes+iIndexNom]) == 0)
			{
				// Cas ou le paramètre est dans le dernier ligne
				//----------------------------------------------
				if(iCpt == NombreLignesTab) iCpt = iCpt -1;
				sscanf(TableauParametres[iCpt*NombreColonnes+iIndexValeur],"%d", &gSlot[idxPos].comCaisson.tConfig.numPort);
				break;
			}
		}

		// On teste si la chaine est bien trouvé
		// --------------------------------------
		if ( iCpt == NombreLignesTab )
		{
			sprintf (chMess, GET_MESSAGE(MAI_MSG_POPUP_12), chNomSousSection,cSectionPos,gPosteInfos.chNom);
			MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
			return -1;
		}


		////////////////////////////////////////////////////////////////////////////////
		// Charger Port COM Générique
		////////////////////////////////////////////////////////////////////////////////

		sprintf (chNomSousSection, INI_VAL_BAUD_GEN_A,idxPos);
		for ( iCpt= 0 ; iCpt < NombreLignesTab ; ++iCpt )
		{
			if (strcmp(chNomSousSection,TableauParametres[iCpt*NombreColonnes+iIndexNom]) == 0)
			{
				// Cas ou le paramètre est dans le dernier ligne
				//----------------------------------------------
				if(iCpt == NombreLignesTab) iCpt = iCpt -1;
				sscanf(TableauParametres[iCpt*NombreColonnes+iIndexValeur],"%d",&gSlot[idxPos].comGenerique_A.tConfig.baud);
				break;
			}
		}

		// On teste si la chaine est bien trouvé
		// --------------------------------------
		if ( iCpt == NombreLignesTab )
		{
			sprintf (chMess, GET_MESSAGE(MAI_MSG_POPUP_12), chNomSousSection,cSectionPos,gPosteInfos.chNom);
			MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
			return -1;
		}

		//-------------------------------------------------------
		// Récupération adresse IP Switch RF SP8T
		//-------------------------------------------------------
		sprintf (chNomSousSection, INI_VAL_IP_SWITCH_RF_SP8T,idxPos);
		for ( iCpt= 0 ; iCpt < NombreLignesTab ; ++iCpt )
		{
			if (strcmp(chNomSousSection,TableauParametres[iCpt*NombreColonnes+iIndexNom]) == 0)
			{
				// Cas ou le paramètre est dans le dernier ligne
				//----------------------------------------------
				if(iCpt == NombreLignesTab) iCpt = iCpt -1;
				strcpy ( gSlot[idxPos].BNFTnteg.gchAdressIPSwitchRFSP8T, TableauParametres[iCpt*NombreColonnes+iIndexValeur]);
				break;
			}
		}

		// On teste si la chaine est bien trouvé
		// --------------------------------------
		if ( iCpt == NombreLignesTab )
		{
			sprintf (chMess, GET_MESSAGE(MAI_MSG_POPUP_12), chNomSousSection,cSectionPos,gPosteInfos.chNom);
			MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
			return -1;
		}

		//-------------------------------------------------------
		// Récupération FLAG SP8T 2G
		//-------------------------------------------------------
		sprintf (chNomSousSection, INI_VAL_FLAG_SP8T,idxPos);
		for ( iCpt= 0 ; iCpt < NombreLignesTab ; ++iCpt )
		{
			if (strcmp(chNomSousSection,TableauParametres[iCpt*NombreColonnes+iIndexNom]) == 0)
			{
				// Cas ou le paramètre est dans le dernier ligne
				//----------------------------------------------
				if(iCpt == NombreLignesTab) iCpt = iCpt -1;
				sscanf(TableauParametres[iCpt*NombreColonnes+iIndexValeur],"%d", &gSlot[idxPos].BNFTnteg.gFlagSP8T);
				break;
			}
		}

		// On teste si la chaine est bien trouvé
		// --------------------------------------
		if ( iCpt == NombreLignesTab )
		{
			sprintf (chMess, GET_MESSAGE(MAI_MSG_POPUP_12), chNomSousSection,cSectionPos,gPosteInfos.chNom);
			MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
			return -1;
		}

		//-------------------------------------------------------
		// Récupération adresse bloc Switch RF SP8T
		//-------------------------------------------------------

		sprintf (chNomSousSection, INI_VAL_BLOC_SWITCH_RF_SP8T,idxPos);
		for ( iCpt= 0 ; iCpt < NombreLignesTab ; ++iCpt )
		{
			if (strcmp(chNomSousSection,TableauParametres[iCpt*NombreColonnes+iIndexNom]) == 0)
			{
				// Cas ou le paramètre est dans le dernier ligne
				//----------------------------------------------
				if(iCpt == NombreLignesTab) iCpt = iCpt -1;
				strcpy ( gSlot[idxPos].BNFTnteg.gchAdressBlocSwitchRFSP8T, TableauParametres[iCpt*NombreColonnes+iIndexValeur]);
				break;
			}
		}

		// On teste si la chaine est bien trouvé
		// --------------------------------------
		if ( iCpt == NombreLignesTab )
		{
			sprintf (chMess, GET_MESSAGE(MAI_MSG_POPUP_12), chNomSousSection,cSectionPos,gPosteInfos.chNom);
			MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
			return -1;
		}

		//-------------------------------------------------------
		// Récupération adresse TimeOut Switch RF
		//-------------------------------------------------------

		sprintf (chNomSousSection, INI_VAL_TIMEOUT_SWITCH_RF,idxPos);
		for ( iCpt= 0 ; iCpt < NombreLignesTab ; ++iCpt )
		{
			if (strcmp(chNomSousSection,TableauParametres[iCpt*NombreColonnes+iIndexNom]) == 0)
			{
				// Cas ou le paramètre est dans le dernier ligne
				//----------------------------------------------
				if(iCpt == NombreLignesTab) iCpt = iCpt -1;
				sscanf(TableauParametres[iCpt*NombreColonnes+iIndexValeur],"%f", &gSlot[idxPos].BNFTnteg.gchTimeOutSwitchRF);
				break;
			}
		}

		// On teste si la chaine est bien trouvé
		// --------------------------------------
		if ( iCpt == NombreLignesTab )
		{
			sprintf (chMess, GET_MESSAGE(MAI_MSG_POPUP_12), chNomSousSection,cSectionPos,gPosteInfos.chNom);
			MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
			return -1;
		}

		//-------------------------------------------------------
		// Récupération Flag Traca
		//-------------------------------------------------------

		sprintf (chNomSousSection, INI_VAL_FLAG_TRACA,idxPos);
		for ( iCpt= 0 ; iCpt < NombreLignesTab ; ++iCpt )
		{
			if (strcmp(chNomSousSection,TableauParametres[iCpt*NombreColonnes+iIndexNom]) == 0)
			{
				// Cas ou le paramètre est dans le dernier ligne
				//----------------------------------------------
				if(iCpt == NombreLignesTab) iCpt = iCpt -1;
				sscanf(TableauParametres[iCpt*NombreColonnes+iIndexValeur],"%d", &gSlot[idxPos].BNFTnteg.gchFlagTraca);
				break;
			}
		}

		// On teste si la chaine est bien trouvé
		// --------------------------------------
		if ( iCpt == NombreLignesTab )
		{
			sprintf (chMess, GET_MESSAGE(MAI_MSG_POPUP_12), chNomSousSection,cSectionPos,gPosteInfos.chNom);
			MessagePopup (GET_MESSAGE(GENERIQUE_TTR_POPUP_ERR), chMess);
			return -1;
		}

	}


// fin boucle for pour le nombre des slotes

	return 0;
}


