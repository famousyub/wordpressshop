// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//
//
// ==============================================================================
//   PROJET			: Banc HDD
//   MODULE			: Include
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
// V 1.1.0
// 15-Décembre-2009			EAH
//		>>>	 Création issue du banc de personnalisation
// ==============================================================================

// ==============================================================================
// INCLUDE
// ==============================================================================

#include "Include.h"

//**********************************************************************
//*************************** Traca ************************************
//**********************************************************************
void FIL2LO_EcritTrace (int flagFil2Lo, int nItfe, char *trace)
{
	int					nTaille;
	char				chDate[80+1];
	char				chHeure[80+1];
	char				chHeureMili[80+1];
	char				chTemp[NBRE_CAR_FIL2LO+80+1] = {'\0'};
	char				chNomficTrace[MAX_PATHNAME_LEN+1] = {'\0'};
	char				chNomFichier[MAX_PATHNAME_LEN+1] = {'\0'};
	FILE				*fic = NULL;
	T_VARIABLES_TRACA	*ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	int					nActiveLog = gSlot[nItfe].ihmSlot.nActiveLog;

	__int64 			iIdTrace;
	char                strErreurMessage[1024] = {'\0'};
	char                CheminLog[1024]="";


	if (nActiveLog == FALSE)
	{
		memset (trace, 0, sizeof(trace));
		return;
	}

	if (flagFil2Lo)
	{
		// ======================================
		// = Concaténation de toutes les traces =
		// ======================================
		FIL2LO_Heure (chHeure, chHeureMili);
		sprintf (chTemp, "%s%s\n", chHeureMili, trace);

#ifdef DEBUG_TRACE
		printf (chTemp);
#endif	// #ifdef DEBUG_TRACE

		// Avoir les traces au fil de l'eau
		// --------------------------------
		sprintf (chNomFichier, "%sLocalDebugS%d.txt", gSlot[nItfe].chCheminLog, nItfe);

		// Nettoyage du fichier s'il est trop gros
		// ----------------------------------------
		DisableBreakOnLibraryErrors ();
		GetFileSize (chNomFichier, &nTaille);
		EnableBreakOnLibraryErrors ();

		// Ouverture et écriture dans le fichier
		// -------------------------------------
		if (nTaille < FICHIER_TAILLE_MAX)
			fic = fopen (chNomFichier, "a");
		else
			fic = fopen (chNomFichier, "w");
		if (fic != NULL)
		{
			fwrite (chTemp, sizeof(char), strlen(chTemp), fic);	   // Ecrire le contenu de chaine dans un fichier
			fclose (fic);
		}

		// Nettoyage mémoire
		// -----------------
		strcat (gSlot[nItfe].stbLog, chTemp);
		memset (trace, 0, sizeof(trace));
	}
	else
	{
		// ==========================================================
		// = Création du fichier pass                               =
		// ==========================================================
		if(FindPattern (trace, 0, -1, "OK", 0, 0)==-1)
		{
			sprintf (CheminLog, "%s\%s", gSlot[nItfe].chCheminLog,"FAIL");
		}
		else sprintf (CheminLog, "%s\%s", gSlot[nItfe].chCheminLog,"PASS");

		if ( !FileExists (CheminLog, NULL) )
			MakeDir (CheminLog);

		// ==========================================================
		// = Création du fichier de trace et remplisage de celui-ci =
		// ==========================================================

		// Constitution
		// ------------
		FIL2LO_Date (chDate);
		FIL2LO_Heure (chHeure, chHeureMili);

		sprintf (chNomficTrace, "%s\\SN_%s_L%d_SLOT%d_%s_%s.log",CheminLog, ptrVariablesTraca->CiuSfcSAPME, gPosteInfos.numLigne, nItfe+1, chDate, chHeure);

		// Ecriture
		// --------
		FIL2LO_EcrireFichier (chNomficTrace, gSlot[nItfe].stbLog);


		// Ecriture en Bdd
		//-----------------
		//if ( ptrVariablesTraca->idMvtTestCie )
		//	TCOM_EnregistrementTrace ( &gTcomBase, ptrVariablesTraca->idMvtTestCie, gSlot[nItfe].stbLog, &iIdTrace, strErreurMessage );

		// Nettoyage
		// ---------
		memset (gSlot[nItfe].stbLog, 0, TAILLE_MAX);
	}
	return;
}
void FIL2LO_EcritTraceV2 (int flagFil2Lo, int nItfe, char *trace)
{
	int					nTaille;
	char				chDate[80+1];
	char				chHeure[80+1];
	char				chHeureMili[80+1];
	char				chTemp[2097152+80+1] = {'\0'};
	char				chNomficTrace[MAX_PATHNAME_LEN+1] = {'\0'};
	char				chNomFichier[MAX_PATHNAME_LEN+1] = {'\0'};
	FILE				*fic = NULL;
	T_VARIABLES_TRACA	*ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	int					nActiveLog = gSlot[nItfe].ihmSlot.nActiveLog;

	__int64 			iIdTrace;
	char                strErreurMessage[1024] = {'\0'};
	char                CheminLog[1024]="";


	if (nActiveLog == FALSE)
	{
		memset (trace, 0, sizeof(trace));
		return;
	}

	if (flagFil2Lo)
	{
		// ======================================
		// = Concaténation de toutes les traces =
		// ======================================
		FIL2LO_Heure (chHeure, chHeureMili);
		sprintf (chTemp, "%s%s\n", chHeureMili, trace);

#ifdef DEBUG_TRACE
		printf (chTemp);
#endif	// #ifdef DEBUG_TRACE

		// Avoir les traces au fil de l'eau
		// --------------------------------
		sprintf (chNomFichier, "%sLocalDebugS%d.txt", gSlot[nItfe].chCheminLog, nItfe);

		// Nettoyage du fichier s'il est trop gros
		// ----------------------------------------
		DisableBreakOnLibraryErrors ();
		GetFileSize (chNomFichier, &nTaille);
		EnableBreakOnLibraryErrors ();

		// Ouverture et écriture dans le fichier
		// -------------------------------------
		if (nTaille < FICHIER_TAILLE_MAX)
			fic = fopen (chNomFichier, "a");
		else
			fic = fopen (chNomFichier, "w");
		if (fic != NULL)
		{
			fwrite (chTemp, sizeof(char), strlen(chTemp), fic);	   // Ecrire le contenu de chaine dans un fichier
			fclose (fic);
		}

		// Nettoyage mémoire
		// -----------------
		strcat (gSlot[nItfe].stbLog, chTemp);
		memset (trace, 0, sizeof(trace));
	}
	else
	{
		// ==========================================================
		// = Création du fichier pass                               =
		// ==========================================================
		if(FindPattern (trace, 0, -1, "OK", 0, 0)==-1)
		{
			sprintf (CheminLog, "%s\%s", gSlot[nItfe].chCheminLog,"FAIL");
		}
		else sprintf (CheminLog, "%s\%s", gSlot[nItfe].chCheminLog,"PASS");

		if ( !FileExists (CheminLog, NULL) )
			MakeDir (CheminLog);

		// ==========================================================
		// = Création du fichier de trace et remplisage de celui-ci =
		// ==========================================================

		// Constitution
		// ------------
		FIL2LO_Date (chDate);
		FIL2LO_Heure (chHeure, chHeureMili);

		sprintf (chNomficTrace, "%s\\SN_%s_L%d_SLOT%d_%s_%s.log",CheminLog, ptrVariablesTraca->CieSn, gPosteInfos.numLigne, nItfe+1, chDate, chHeure);

		// Ecriture
		// --------
		FIL2LO_EcrireFichier (chNomficTrace, gSlot[nItfe].stbLog);


		// Ecriture en Bdd
		//-----------------
		//if ( ptrVariablesTraca->idMvtTestCie )
		//	TCOM_EnregistrementTrace ( &gTcomBase, ptrVariablesTraca->idMvtTestCie, gSlot[nItfe].stbLog, &iIdTrace, strErreurMessage );

		// Nettoyage
		// ---------
		memset (gSlot[nItfe].stbLog, 0, TAILLE_MAX);
	}
	return;
}
/*
//**********************************************************************
//*************************** Traca ************************************
//**********************************************************************
void FIL2LO_EcritTrace (int flagFil2Lo, int nItfe, char *trace)
{
	int					nTaille;
	char				chDate[80+1];
	char				chHeure[80+1];
	char				chHeureMili[80+1];
	char				chTemp[NBRE_CAR_FIL2LO+80+1] = {'\0'};
	char				chNomficTrace[MAX_PATHNAME_LEN+1] = {'\0'};
	char				chNomFichier[MAX_PATHNAME_LEN+1] = {'\0'};
	FILE				*fic = NULL;
	T_VARIABLES_TRACA	*ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	int					nActiveLog = gSlot[nItfe].ihmSlot.nActiveLog;

	__int64 			iIdTrace;
	char                strErreurMessage[1024] = {'\0'};



	if (nActiveLog == FALSE)
	{
		memset (trace, 0, sizeof(trace));
		return;
	}

	if (flagFil2Lo)
	{
		// ======================================
		// = Concaténation de toutes les traces =
		// ======================================
		FIL2LO_Heure (chHeure, chHeureMili);
		sprintf (chTemp, "%s%s\n", chHeureMili, trace);

#ifdef DEBUG_TRACE
		printf (chTemp);
#endif	// #ifdef DEBUG_TRACE

		// Avoir les traces au fil de l'eau
		// --------------------------------
		sprintf (chNomFichier, "%sLocalDebugS%d.txt", gSlot[nItfe].chCheminLog, nItfe);

		// Nettoyage du fichier s'il est trop gros
		// ----------------------------------------
		DisableBreakOnLibraryErrors ();
		GetFileSize (chNomFichier, &nTaille);
		EnableBreakOnLibraryErrors ();

		// Ouverture et écriture dans le fichier
		// -------------------------------------
		if (nTaille < FICHIER_TAILLE_MAX)
			fic = fopen (chNomFichier, "a");
		else
			fic = fopen (chNomFichier, "w");
		if (fic != NULL)
		{
			fwrite (chTemp, sizeof(char), strlen(chTemp), fic);	   // Ecrire le contenu de chaine dans un fichier
			fclose (fic);
		}

		// Nettoyage mémoire
		// -----------------
		strcat (gSlot[nItfe].stbLog, chTemp);
		memset (trace, 0, sizeof(trace));
	}
	else
	{
		// ==========================================================
		// = Création du fichier pass                               =
		// ==========================================================

		sprintf (gSlot[nItfe].chCheminLog, "%s\\%s\\", gSlot[nItfe].chCheminLog,"FAIL");
		if ( !FileExists (gSlot[nItfe].chCheminLog, NULL) )
			MakeDir (gSlot[nItfe].chCheminLog);

		// ==========================================================
		// = Création du fichier de trace et remplisage de celui-ci =
		// ==========================================================

		// Constitution
		// ------------
		FIL2LO_Date (chDate);
		FIL2LO_Heure (chHeure, chHeureMili);

		sprintf (chNomficTrace, "%sSN_%s_L%d_SLOT%d_%s_%s.log", gSlot[nItfe].chCheminLog, ptrVariablesTraca->PfinSfcSAPME, gPosteInfos.numLigne, nItfe+1, chDate, chHeure);

		// Ecriture
		// --------
		FIL2LO_EcrireFichier (chNomficTrace, gSlot[nItfe].stbLog);


		// Ecriture en Bdd
		//-----------------
		//if ( ptrVariablesTraca->idMvtTestCie )
		//	TCOM_EnregistrementTrace ( &gTcomBase, ptrVariablesTraca->idMvtTestCie, gSlot[nItfe].stbLog, &iIdTrace, strErreurMessage );

		// Nettoyage
		// ---------
		memset (gSlot[nItfe].stbLog, 0, TAILLE_MAX);
	}
	return;
}
 */
//********************************************************************
//********************Ecriture dans le fichier************************
//********************************************************************

void FIL2LO_EcrireFichier (char *chNomFichier, char *chaine)
{
	int		ii;
	char	fichier[TAILLE_MAX_CHAINE] = {'\0'};
	FILE	*fic = NULL;

	// Supression des caractères inutiles
	// ----------------------------------
	strncpy (fichier, chNomFichier,TAILLE_MAX_CHAINE-1);
	for (ii = 2; ii < strlen (chNomFichier); ii++)
	{
		if ( (chNomFichier[ii] == '/') || (chNomFichier[ii] == ':') )
			fichier[ii] = '_';
		else
			fichier[ii] = chNomFichier[ii];
	}

	// Ouverture et écriture dans le fichier
	// -------------------------------------
	fic = fopen (fichier, "a");
	if (fic != NULL)
	{
		// Ecrire le contenu de chaine dans un fichier
		// -------------------------------------------
		fwrite (chaine, sizeof(char), strlen(chaine), fic);
		fclose (fic);
	}

	return;
}

//**********************************************************************
//****************************HEURE**************************************
//**********************************************************************
void FIL2LO_Heure (char ch[80+1], char chmilli[80+1])
{
	SYSTEMTIME pstructtime;

	GetLocalTime (&pstructtime);

	sprintf (ch, "%02d:%02d:%02d:", pstructtime.wHour,  pstructtime.wMinute, pstructtime.wSecond);
	sprintf (chmilli, "[%02d:%02d:%02d:%03d] ", pstructtime.wHour,  pstructtime.wMinute, pstructtime.wSecond, pstructtime.wMilliseconds);

	return;
}
//****************************HEURE V2**************************************
void FIL2LO_HeureV2 (char ch[80+1], char chmilli[80+1])
{
	SYSTEMTIME pstructtime;

	GetLocalTime (&pstructtime);

	sprintf (ch, "%02d-%02d-%02d", pstructtime.wHour,  pstructtime.wMinute, pstructtime.wSecond);
	sprintf (chmilli, "%02d-%02d-%02d-%03d ", pstructtime.wHour,  pstructtime.wMinute, pstructtime.wSecond, pstructtime.wMilliseconds);

	return;
}

//**********************************************************************
//****************************DATE**************************************
//**********************************************************************

void FIL2LO_Date (char ch[80+1])
{
	struct tm * pdh;
	time_t intps;
	int nbc;

	intps = time (NULL);
	pdh = localtime (&intps);
	nbc = strftime (ch, 81,"%d/%m/%y:", pdh);

	return;
}
//****************************DATE V2**************************************
void FIL2LO_DateV2 (char ch[80+1])
{
	struct tm * pdh;
	time_t intps;
	int nbc;

	intps = time (NULL);
	pdh = localtime (&intps);
	nbc = strftime (ch, 81,"%d-%m-%y", pdh);

	return;
}

// ==============================================================================
// FONCTION : 	  FIL2LO_PrintDebut
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  void FIL2LO_PrintDebut (int nItfe)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//  			  - int nItfe		: Index du SLOT en test (0 ou 1).
// ------------------------------------------------------------------------------
// DESRIPTION :   Affichage du début de test.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.3.14
//  DATE :		  30/09/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
void FIL2LO_PrintDebut (int nItfe)
{
	char 		ligne[FIL2LO_LIGNE_MAX];
	char		chPrint[8192];
	char		chMsgErr[1024];
	T_VARIABLES	*ptrVariablesConf = &(gSlot[nItfe].variablesConf);
	T_VARIABLES	*ptrVariablesConfPoste = &(gSlot[nItfe].variablesConfPoste);
	char path2lo2G[10000]="";
	char path2lo5G[10000]="";
	char path2loDECT[10000]="";
	char path2loBT[10000]="";

	
	// ===========================
	// = Affichage Début de test =
	// ===========================
	FIL2LO_PrintEtape (nItfe, "DEBUT DE TEST");

	FIL2LO_PrintEtape (nItfe, gChNomPc);
	
	// =============================================
	// = Affichage des paramètres de configuration =
	// =============================================
	strncpy ( ligne, FIL2LO_STR_CONF_STB,FIL2LO_LIGNE_MAX-1);
	FIL2LO_EcritTrace (TRUE, nItfe, ligne);
	// Mise en forme des variables de traca
	// ------------------------------------
	VAR_Print ( ptrVariablesConf, chPrint, chMsgErr);
	FCT_RemplacerTag ( chPrint, 8192, "\n", FIL2LO_STR_RESULT_BLANK );

	// Affichage des variables
	// -----------------------
	FIL2LO_EcritTrace (TRUE, nItfe, chPrint);
	// Mise en forme des variables de traca
	// ------------------------------------
	VAR_Print ( ptrVariablesConfPoste, chPrint, chMsgErr);
	FCT_RemplacerTag ( chPrint, 8192, "\n", FIL2LO_STR_RESULT_BLANK );

	// Affichage des variables
	// -----------------------
	FIL2LO_EcritTrace (TRUE, nItfe, chPrint);
	/*
	sprintf(path2lo2G,"Pathloss 2GHz : %s",fichpathloss_2G);
	FIL2LO_EcritTrace (TRUE, nItfe, path2lo2G);
	sprintf(path2lo5G,"Pathloss 5GHz : %s",fichpathloss_5G);
	FIL2LO_EcritTrace (TRUE, nItfe, path2lo5G);
	sprintf(path2loBT,"Pathloss BT : %s",fichpathloss_BT);
	FIL2LO_EcritTrace (TRUE, nItfe, path2loBT);*/


	return;
}

// ==============================================================================
// FONCTION : 	  FIL2LO_PrintTraceStb
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  void FIL2LO_PrintResultat (	int nItfe,
//												int res,
//											 	char *msgErr,
//												char *dTest)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//  			  - int nItfe				: Index du SLOT en test (0 ou 1).
//  			  - int res					: Résultat du test,
//											  TRUE -> OK / FALSE -> KO
//  			  - char *msgErr			: Message d'erreur en cas de KO.
//  			  - char *dTest				: Durée du test.
// ------------------------------------------------------------------------------
// DESRIPTION :   Affichage du résultat de test du STB.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.3.14
//  DATE :		  30/09/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
void FIL2LO_PrintResultat (int nItfe, int res, char *msgErr, float dTest)
{
	char				ligne[FIL2LO_LIGNE_MAX];
	char				chPrint[8192];
	char				chMsgErr[1024];
	char                chVersionSoft[16] = {'\0'};
	T_VARIABLES			*ptrVariablesEtat = &(gSlot[nItfe].variablesEtat);
	T_VARIABLES_TRACA	*ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	T_MESURES           *ptrMesures = &(gSlot[nItfe].mesures);
	//T_CLES              *ptrClesSfin = &(gSlot[nItfe].clesSfin);

	// ===============
	// = Fin de test =
	// ===============
	FIL2LO_PRINT_ETAPE (ligne, "FIN DE TEST");
	FIL2LO_EcritTrace (TRUE, nItfe, ligne);

	// =================================
	// = Affichage du résultat du test =
	// =================================
	if ( res == TRUE )
	{
		strncpy ( ligne, FIL2LO_STR_RES_OK,FIL2LO_LIGNE_MAX-1);
		FIL2LO_EcritTrace (TRUE, nItfe, ligne);
	}
	else
	{
		strncpy ( ligne, FIL2LO_STR_RES_KO,FIL2LO_LIGNE_MAX-1);
		FIL2LO_EcritTrace (TRUE, nItfe, ligne);
		// Affichage de l'erreur en cas de KO
		//sprintf (ligne, "ERREUR : %s\n", msgErr);
		//FIL2LO_EcritTrace (TRUE, nItfe, ligne);
	}

	// =================================
	// = Affichage de la durée du test =
	// =================================
	sprintf (ligne, "DUREE DU TEST : %d secondes\n", (int)dTest);
	FIL2LO_EcritTrace (TRUE, nItfe, ligne);

	// ===================================
	// = Affichage de la version du soft =
	// ===================================
	Fmt(chVersionSoft, "%s %s_%i",gChNomPc, VERSION_SOFT, nItfe);
	sprintf (ligne, "SOFT VERSION : %s\n", chVersionSoft);
	FIL2LO_EcritTrace (TRUE, nItfe, ligne);

	// ===========================================
	// = Affichage des variables de traça du STB =
	// ===========================================

	// Mise en forme et affichage des infos produit
	// --------------------------------------------
	FCT_ProduitPrint ( &gPosteProduits.produits[ptrVariablesTraca->idxProduit], chPrint, chMsgErr);
	FCT_RemplacerTag ( chPrint, PRINT_INFO_TAILLE_MAX, "\n", FIL2LO_STR_RESULT_BLANK );
	FIL2LO_EcritTrace (TRUE, nItfe, chPrint);

	// Mise en forme et affichage des variables de traca
	// -------------------------------------------------
	FCT_TracaPrint ( ptrVariablesTraca, chPrint, chMsgErr);
	FCT_RemplacerTag ( chPrint, PRINT_INFO_TAILLE_MAX, "\n", FIL2LO_STR_RESULT_BLANK );
	FIL2LO_EcritTrace (TRUE, nItfe, chPrint);

	// Mise en forme et affichage des variables état en BDD
	// ----------------------------------------------------
	VAR_Print ( ptrVariablesEtat, chPrint, chMsgErr);
	FCT_RemplacerTag ( chPrint, PRINT_INFO_TAILLE_MAX, "\n", FIL2LO_STR_RESULT_BLANK );
	FIL2LO_EcritTrace (TRUE, nItfe, chPrint);

	// Mise en forme et affichage des mesures
	// --------------------------------------
	MES_PrintTab ( ptrMesures, chPrint );
	FCT_RemplacerTag ( chPrint, PRINT_INFO_TAILLE_MAX, "\n", FIL2LO_STR_RESULT_BLANK );
	FIL2LO_EcritTrace (TRUE, nItfe, chPrint);

	// Mise en forme et affichage des clés
	// -----------------------------------
	//CLE_Print ( ptrClesSfin, chPrint, FALSE, chMsgErr);
	FCT_RemplacerTag ( chPrint, PRINT_INFO_TAILLE_MAX, "\n", FIL2LO_STR_RESULT_BLANK );
	FIL2LO_EcritTrace (TRUE, nItfe, chPrint);

	return;
}

// ==============================================================================
// FONCTION : 	  FIL2LO_PrintEtape
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  void FIL2LO_PrintEtape (int nItfe, char *etape)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//  			  - int nItfe		: Index du SLOT en test (0 ou 1).
//  			  - char *etape		: Nom de l'étape à afficher.
// ------------------------------------------------------------------------------
// DESRIPTION :   Affichage d'une ligne étape dans le fichier LOG.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.3.14
//  DATE :		  30/09/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
void FIL2LO_PrintEtape (int nItfe, char *etape)
{
	char ligne[FIL2LO_LIGNE_MAX];

	FIL2LO_PRINT_ETAPE (ligne, etape);
	FIL2LO_EcritTrace (TRUE, nItfe, ligne);
}

// ==============================================================================
// FONCTION : 	  FIL2LO_PrintEtape
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  void FIL2LO_PrintSousEtape (int nItfe, char *etape)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//  			  - int nItfe		: Index du SLOT en test (0 ou 1).
//  			  - char *etape		: Nom de l'étape à afficher.
// ------------------------------------------------------------------------------
// DESRIPTION :   Affichage d'une ligne sous étape dans le fichier LOG.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.3.14
//  DATE :		  30/09/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
void FIL2LO_PrintSousEtape (int nItfe, char *etape)
{
	char ligne[FIL2LO_LIGNE_MAX];

	FIL2LO_PRINT_SOUS_ETAPE (ligne, etape);
	FIL2LO_EcritTrace (TRUE, nItfe, ligne);
}

// ==============================================================================
// FONCTION : 	  FIL2LO_PrintTraceStb
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  void FIL2LO_PrintTraceStb (int nItfe)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//  			  - int nItfe				: Index du SLOT en test (0 ou 1).
// ------------------------------------------------------------------------------
// DESRIPTION :   Affichage des traces de démarrage du STB.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.3.14
//  DATE :		  30/09/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
void FIL2LO_PrintTraceStb (int nItfe)
{
	char				ligne[FIL2LO_LIGNE_MAX];
	char				traceTmp[FIL2LO_CONF_MAX] = {'\0'};
	T_VARIABLES_TRACA	*ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);


	// Titre trace STB
	// ---------------
	strncpy ( ligne, FIL2LO_STR_TRACE_STB,FIL2LO_LIGNE_MAX-1);
	FIL2LO_EcritTrace (TRUE, nItfe, ligne);

	// Trace de démarrage du STB
	// -------------------------

	// Core Board SN ==> SN du CIE (DFAB)
	sprintf (traceTmp, "SN du CIE         : %s\n", ptrVariablesTraca->CieSn);

	// Indice SFIN
	sprintf (ligne, "               SFIN indice       : %s\n", gPosteProduits.produits[gSlot[nItfe].variablesTraca.idxProduit].sfin.chIndice);
	strcat (traceTmp, ligne);

	FIL2LO_EcritTrace (TRUE, nItfe, traceTmp);
}

// ==============================================================================
// FONCTION : 	  FIL2LO_PrintEtape
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  void FIL2LO_PrintEtape (int nItfe, char *etape)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//  			  - int nItfe		: Index du SLOT en test (0 ou 1).
//  			  - char *etape		: Nom de l'étape à afficher.
// ------------------------------------------------------------------------------
// DESRIPTION :   Affichage d'une ligne étape dans le fichier LOG.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.3.14
//  DATE :		  30/09/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
void FIL2LO_PrintCom (int nItfe, int com, char *donnees)
{
	char traceTmp[FIL2LO_TRACE_MAX] = {'\0'};


	// ======================================
	// = Sélection du type de communication =
	// ======================================
	switch (com)
	{
			// COM PC vers GTW
			// ---------------
		case FIL2LO_COM_GTW_RX:
			strncpy (traceTmp, FIL2LO_STR_RX_STB,FIL2LO_TRACE_MAX-1);
			break;

			// COM GTW vers PC
			// ---------------
		case FIL2LO_COM_GTW_TX:
			strncpy (traceTmp, FIL2LO_STR_TX_STB,FIL2LO_TRACE_MAX-1);
			break;

			// COM PC vers WATTMETRE
			// ---------------------
		case FIL2LO_COM_WATT_RX:
			strncpy (traceTmp, FIL2LO_STR_RX_WATT,FIL2LO_TRACE_MAX-1);
			break;

			// COM WATTMETRE vers PC
			// ---------------------
		case FIL2LO_COM_WATT_TX:
			strncpy (traceTmp, FIL2LO_STR_TX_WATT,FIL2LO_TRACE_MAX-1);
			break;

		default:
			break;
	}

	// =============================
	// = Mise en forme de la trace =
	// =============================
	strcat ( traceTmp, donnees );
	FCT_RemplacerTag ( traceTmp, FIL2LO_TRACE_MAX, "\r", "" );
	FCT_RemplacerTag ( traceTmp, FIL2LO_TRACE_MAX, "\n", FIL2LO_STR_COM_BLANK );

	// ============================================
	// = Affichage des traces dans le fichier LOG =
	// ============================================
	FIL2LO_EcritTrace (TRUE, nItfe, traceTmp);
}

// ==============================================================================
// FONCTION :     FIL2LO_VerifDateChemin
// ------------------------------------------------------------------------------
// PROTOTYPE :    void FIL2LO_VerifDateChemin (int nItfe)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe       : Index du SLOT en test (0 ou 1).
// ------------------------------------------------------------------------------
// DESRIPTION :   Vérification que la date n'a pas changé depuis l'ouverture de l'appli
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S08012CA85
//  DATE :        14/06/2011
//  AUTEUR :      GCX (APSIDE)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
void FIL2LO_VerifDateChemin (int nItfe )
{
	char 	chMoisJourAnnee[12] = {"\0"};
	int 	iLenChemin;
	int 	iLenDate;
	char	strMessageErreur[1024] = {"\0"};


	// Récupération de la date actuelle
	// --------------------------------
	SCPROD_RecuperationDateHeure ( &gTcomBase, &gDateHeure, strMessageErreur);
	sprintf(chMoisJourAnnee, "%02d-%02d-%04d", gDateHeure.month, gDateHeure.daymonth, gDateHeure.year);


	// Comparaison Date Actuelle et Date ouverture de l'appli
	// ------------------------------------------------------
	if (strcmp ( chMoisJourAnnee, gSlot[nItfe].chMoisJourAnnee ) )
	{
		// Mise à jour de la date à l'intérieur du chemin
		// ----------------------------------------------
		sprintf ( gSlot[nItfe].chMoisJourAnnee, "%s\\", chMoisJourAnnee);
		iLenChemin = strlen( gSlot[nItfe].chCheminLog);
		iLenDate = strlen( gSlot[nItfe].chMoisJourAnnee);
		CopyString (gSlot[nItfe].chCheminLog, (iLenChemin - (iLenDate)), gSlot[nItfe].chMoisJourAnnee, 0, (iLenDate));
	}

	if ( !FileExists (gSlot[nItfe].chCheminLog, NULL) )
		MakeDir (gSlot[nItfe].chCheminLog);
}
