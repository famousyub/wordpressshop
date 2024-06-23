// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//
//
// ==============================================================================
//   PROJET			: Banc Personnalisation
//   MODULE			: Variables
//   PROCESSEUR		: INTEL Pentium
//   ENVIRONNEMENT	: Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION	: Gestion des mesures du décodeur.
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
// 12-Octobre-2009	NCR (DT2E)
//		>>>	 Création
// ==============================================================================


// ==============================================================================
// INCLUDE
// ==============================================================================

#include "Include.h"


// ==============================================================================
// DECLARATION DES VARIABLES GLOBALES
// ==============================================================================

// Définition des mesures pour le banc DisquesDurs
// -----------------------------------------------
T_MESURE gMesuresBNFT[] =
//  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// |		TYPE			|			NOM	 				|	DESCRIPTION	|	LIM INF	|	LIM SUP	  |	UNITE	  |	AVEC MES  |		STATUS		|	DUREE	|	MESURE	|	ID	|
//  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{
	{	MES_TYPE_TEMPS_TEST,		"MES_BWC_TEMPS_TEST",				"",				0.0,			0.0,		"",			1,		MES_STATUS_NOGO,		0,		0.0,		0	},

};

// Nombre de mesure dans le tableau
// --------------------------------
const int gNbMesuresHdd = (int)(sizeof(gMesuresBNFT) / sizeof(T_MESURE));


// ==============================================================================
// DECLARATION DES FONCTIONS
// ==============================================================================

// ==============================================================================
// FONCTION : 	  MES_Get
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int MES_Get ( T_MESURES *tTabMesure,
//								hdleTCom instTracaCom,
//								char *codeProduit,
//								char *indiceProduit,
//								char *nomPoste,
//								int nItfe,
//								int idPort,
//								char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_MESURES *tTabMesure 	: Tabelau de mesures pour le Slot,
//				  - hdleTCom instTracaCom	: Handle sur la base TracaCom,
//				  - char *codeProduit		: Code produit,
//				  - char *indiceProduit		: Indice produit,
//				  - char *nomPoste			: Nom poste,
//				  - int nItfe				: Index Slot,
//				  - int idPort				: Index COM STB,
//				  - char *strErreurMessage	: Message d'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Extraction des mesures de la Base de données.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  12/09/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int MES_Get ( T_MESURES *tTabMesure, hdleSCProd instSCProduction, char *codeProduit, char *indiceProduit, char *nomPoste, int nItfe, int idPort, char *strErreurMessage )
{
	char **tabMesure = NULL;
	char *tcomErreur = NULL;
	char *strErreurRequete = NULL;
	int erreurSurvenue;
	int erreurCode;
	int tabMesLen1;
	int tabMesLen2;
	int error = 0;
	int idxMesIn;
	int idxMesOut;



	// ===============================================
	// = RAZ des paramètres de sortie de la fonction =
	// ===============================================
	strErreurMessage[0] = '\0';

	// ================================
	// = RAZ du le tableau de mesures =
	// ================================
	tTabMesure->nbMesure = 0;
	tTabMesure->mesures = NULL;
	// MAJ de l'index du Slot
	tTabMesure->nItfe = nItfe;
	// MAJ de l'index du port COM
	tTabMesure->idPort = idPort;
	// MAJ de l'handle de la base TracaCom
	tTabMesure->instSCProduction = instSCProduction;
	// MAJ du code produit
	strcpy ( tTabMesure->codeProduit, codeProduit);
	// MAJ de l'indice produit
	strcpy ( tTabMesure->indiceProduit, indiceProduit);
	// MAJ du nom du poste
	strcpy ( tTabMesure->nomPoste, nomPoste);

	// =======================================================
	// = Extraction des clés perso utilisées pour le produit =
	// =======================================================
	SCProduction_GestionProductions_RecuperationTypeTestsParProduitParPoste(
		tTabMesure->instSCProduction,
		tTabMesure->codeProduit,
		tTabMesure->indiceProduit,
		tTabMesure->nomPoste,
		&tabMesure,
		&tabMesLen1,
		&tabMesLen2,
		&erreurSurvenue,
		&erreurCode,
		&tcomErreur,
		&strErreurRequete,
		NULL);

	// Vérification des erreurs de la fonction
	if(erreurSurvenue)
	{
		errChk(erreurCode);
	}

	// =========================================================
	// = Extraction des variables de mesure pour le banc Perso =
	// =========================================================
	for ( idxMesOut=0 ; idxMesOut<gNbMesuresHdd ; idxMesOut++ )
	{
		for ( idxMesIn=0 ; idxMesIn<tabMesLen1 ; idxMesIn++ )
		{
			if ( strcmp (gMesuresBNFT[idxMesOut].nom, tabMesure[idxMesIn*tabMesLen2]) == 0 )
			{
				// Allocation mémoire pour la nouvelle mesure
				tTabMesure->mesures = (T_MESURE *) realloc (tTabMesure->mesures, sizeof(T_MESURE) * (tTabMesure->nbMesure+1));

				// MAJ du type de la mesure
				tTabMesure->mesures[tTabMesure->nbMesure].type = gMesuresBNFT[idxMesOut].type;

				// MAJ du nom de la mesure
				strcpy ( tTabMesure->mesures[tTabMesure->nbMesure].nom, gMesuresBNFT[idxMesOut].nom );

				// Extraction de la description de la mesure
				strcpy ( tTabMesure->mesures[tTabMesure->nbMesure].libelle, tabMesure[(idxMesIn*tabMesLen2)+1] );

				// Extraction de la limite inférieure de la mesure
				tTabMesure->mesures[tTabMesure->nbMesure].limiteInferieure = atof (tabMesure[(idxMesIn*tabMesLen2)+2]);

				// Extraction de la limite supérieure de la mesure
				tTabMesure->mesures[tTabMesure->nbMesure].limiteSuperieure = atof (tabMesure[(idxMesIn*tabMesLen2)+3]);

				// Extraction de l'unité de la mesure
				strcpy ( tTabMesure->mesures[tTabMesure->nbMesure].unite, tabMesure[(idxMesIn*tabMesLen2)+4] );

				// Extraction de l'info avec ou sans mesure
				StringLowerCase (tabMesure[(idxMesIn*tabMesLen2)+5]);
				if ( strstr (tabMesure[(idxMesIn*tabMesLen2)+5], MES_STR_TRUE) != NULL )
					tTabMesure->mesures[tTabMesure->nbMesure].avecMesure = TRUE;
				else if ( strstr (tabMesure[(idxMesIn*tabMesLen2)+5], MES_STR_FALSE) != NULL )
					tTabMesure->mesures[tTabMesure->nbMesure].avecMesure = FALSE;
				else
				{
					sprintf (strErreurMessage, "Mesure \"%s\" : Info avec mesure non reconnu (%s)", gMesuresBNFT[idxMesOut].nom, tabMesure[(idxMesIn*tabMesLen2)+5]);
					errChk(-1);
				}

				// On incrémente le nombre de mesures utilisées
				tTabMesure->nbMesure++;

				break;
			}
		}
	}

Error:
	// Libération des ressources
	CDotNetFreeMemory(tabMesure);

	// =======================
	// = gestion des erreurs =
	// =======================
	if(error)
	{
		if ( tcomErreur != NULL )
		{
			if ( strErreurRequete != NULL )
				sprintf (strErreurMessage, "%s", tcomErreur);
			else
				strcpy (strErreurMessage, tcomErreur);
		}

		// Libération des ressources
		CDotNetFreeMemory(strErreurRequete);
		CDotNetFreeMemory(tcomErreur);

		return -1;
	}

	return 0;
}

// ==============================================================================
// FONCTION : 	  MES_DeleteAll
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int MES_DeleteAll ( T_TAB_MESURE *tTabMesure )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_TAB_MESURE *tTabMesure	: Tableau de mesure.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Suppression du tableau de mesures.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  12/09/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int MES_Delete ( T_MESURES *tTabMesure )
{
	// =====================================
	// = Suppression du tableau de mesures =
	// =====================================
	free (tTabMesure->mesures);

	return 0;
}

// ==============================================================================
// FONCTION : 	  MES_Reset
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int MES_Reset ( T_MESURES *tTabMesure )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_MESURES 	*tTabMesure	: Tableau de mesure,
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Remise à zéro des valeurs du tableau de mesures.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  12/09/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int MES_Reset ( T_MESURES *tTabMesure )
{
	int idxMesure;


	// ================================================
	// = Reset des mesures pour l'interface spécifiée =
	// ================================================
	for ( idxMesure=0 ; idxMesure<tTabMesure->nbMesure ; idxMesure++ )
	{
		// RAZ de la durée de la mesure
		tTabMesure->mesures[idxMesure].duree = 0.0;
		// RAZ de la durée de la mesure
		tTabMesure->mesures[idxMesure].mesure = 0.0;
		// RAZ de l'Identifiant de la mesure
		tTabMesure->mesures[idxMesure].id = 0;
		// RAZ de la durée de la mesure
		strcpy (tTabMesure->mesures[idxMesure].status, MES_STATUS_NOGO);
	}

	return 0;
}

// ==============================================================================
// FONCTION : 	  MES_Index
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int MES_Index (	T_MESURES *tTabMesure,
//									T_MES_TYPE type )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_MESURES 	*tTabMesure	: Tableau de mesure,
//				  - T_MES_TYPE 	type		: Type de mesure recherchée.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - >= 0 = Index de la mesure trouvé
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Recherche l'index d'une mesure dans le tableau de mesures.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  12/09/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int MES_Index ( T_MESURES *tTabMesure, T_MES_TYPE type )
{
	int idxMesure;


	// ==========================================
	// = recherche de l'index du type de mesure =
	// ==========================================
	for ( idxMesure=0 ; idxMesure<tTabMesure->nbMesure ; idxMesure++ )
	{
		// Vérification du type avec la mesure courante
		if ( tTabMesure->mesures[idxMesure].type == type )
			return idxMesure;
	}

	// Type de mesure inconnu
	return -1;
}

// FONCTION :     MES_GetName
// ------------------------------------------------------------------------------
// PROTOTYPE :    int MES_GetName ( T_MES_TYPE type,
//                                  char *chName    )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_MES_TYPE  type        : Type de mesure recherchée,
//                - char        *chName     : Nom de la mesure.
// ------------------------------------------------------------------------------
// RETOUR :
//                - >= 0 = Index de la mesure trouvé
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Recherche du nom d'une mesure dans le tableau de mesures.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        12/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int MES_GetName ( T_MES_TYPE type, char *chName )
{
	int idxMesure;


	// ==========================================
	// = recherche de l'index du type de mesure =
	// ==========================================
	for ( idxMesure=0 ; idxMesure<gNbMesuresHdd ; idxMesure++ )
	{
		// Vérification du type avec la mesure courante
		// --------------------------------------------
		if ( gMesuresBNFT[idxMesure].type == type )
		{
			strcpy (chName, gMesuresBNFT[idxMesure].nom);
			return idxMesure;
		}
	}

	// Type de mesure inconnu
	// ----------------------
	return -1;
}



// ==============================================================================
// FONCTION : 	  MES_Capturer
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int MES_Capturer (	T_MESURES *tTabMesure,
//										T_MES_TYPE type,
//										char *status,
//										float valeur,
//										float duree )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_MESURES	*tTabMesure	: Tableau de mesure,
//				  - T_MES_TYPE 	type		: Type de mesure recherchée,
//				  - char 		*status		: Status de la mesure (avecMesure=0),
//				  - float 		valeur		: Valeur de la mesure (avecMesure=1),
//				  - int 		duree		: Duree de la mesure.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Mise à jour du résultat de la mesure dans le tableau de mesure.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  12/09/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int MES_Capturer ( T_MESURES *tTabMesure, T_MES_TYPE type, char *status, float valeur, int duree )
{
	int idxMesure;

	// ==========================================
	// = recherche de l'index du type de mesure =
	// ==========================================
	idxMesure = MES_Index ( tTabMesure, type );
	if (idxMesure <= -1)
		return -1;

	// =========================================
	// = Enregistrement du status de la mesure =
	// =========================================
	if ( tTabMesure->mesures[idxMesure].avecMesure == 1 )
	{
		//Mettre la valeur dans la struct
		//-------------------------------
		tTabMesure->mesures[idxMesure].mesure = valeur;

		// Vérification du résultat de la mesure
		// -------------------------------------
		if ( (valeur >= tTabMesure->mesures[idxMesure].limiteInferieure) && (valeur <= tTabMesure->mesures[idxMesure].limiteSuperieure) )
			strcpy (tTabMesure->mesures[idxMesure].status, MES_STATUS_OK);
		else
		{
			strcpy (tTabMesure->mesures[idxMesure].status, MES_STATUS_KO);
		}
		strcpy (status, tTabMesure->mesures[idxMesure].status);

	}

	else
	{
		// Mesure sans valeur => on enregistre le status
		// ---------------------------------------------
		strcpy (tTabMesure->mesures[idxMesure].status, status);
	}

	// ===========================================
	// = Enregistrement de la durée de la mesure =
	// ===========================================
	tTabMesure->mesures[idxMesure].duree = duree;

	return 0;
}

// ==============================================================================
// FONCTION : 	  MES_Enregistrer
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int MES_Enregistrer ( T_MESURES *tTabMesure,
//										__int64 idMvtTest,
//										char *strMessageErreur )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_MESURES	*tTabMesure			: Tableau de mesure,
//				  - __int64		idMvtTest			: ID du mouvement de test,
//				  - char		*strMessageErreur	: Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Enregistrement des mesures en bases.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  12/09/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int MES_Enregistrer ( T_MESURES *tTabMesure, __int64 idMvtTest, char *strMessageErreur )
{
	int idxMesure;
	char *tcomErreur = NULL;
	char *strErreurRequete = NULL;
	int erreurSurvenue;
	int erreurCode;
	int error = 0;
	char chValeur[32] = {'\0'};
	char chLimiteInferieure[32] = {'\0'};
	char chLimiteSuperieure[32] = {'\0'};


	// =========================================
	// = Enregistrement du status de la mesure =
	// =========================================
	for ( idxMesure=0 ; idxMesure<tTabMesure->nbMesure ; idxMesure++ )
	{
		// Mise en forme des paramètres d'enregistrement
		sprintf (chValeur, "%f", tTabMesure->mesures[idxMesure].mesure);
		sprintf (chLimiteInferieure, "%f", tTabMesure->mesures[idxMesure].limiteInferieure);
		sprintf (chLimiteSuperieure, "%f", tTabMesure->mesures[idxMesure].limiteSuperieure);

		// Enregistrement de la mesure en base
		TracaCom_FonctionsMDT_FonctionsMDT_EnregistrementTestMesure(tTabMesure->instSCProduction,
				idMvtTest,
				tTabMesure->mesures[idxMesure].nom,
				tTabMesure->mesures[idxMesure].status,
				(int)tTabMesure->mesures[idxMesure].duree,
				chValeur,
				chLimiteInferieure,
				chLimiteSuperieure,
				&(tTabMesure->mesures[idxMesure].id),
				&erreurSurvenue,
				&erreurCode,
				&tcomErreur,
				&strErreurRequete,
				NULL);

		// Vérification des erreurs de la fonction
		if(erreurSurvenue)
		{
			errChk(erreurCode);
		}
	}

Error:
	// =======================
	// = gestion des erreurs =
	// =======================
	if(error)
	{
		if ( tcomErreur != NULL )
		{
			if ( strErreurRequete != NULL )
				sprintf (strMessageErreur, "[Enregitrement mesure %s] %s", tTabMesure->mesures[idxMesure].nom, tcomErreur);
		}

		// Libération des ressources
		CDotNetFreeMemory(strErreurRequete);
		CDotNetFreeMemory(tcomErreur);

		return -1;
	}

	return 0;
}

// ==============================================================================
// FONCTION : 	  MES_PrintTab
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int MES_PrintTab ( T_MESURES *tMesures, char *strPrint )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_MESURES *tMesures	: Tableau mesure à formater pour impression,
//				  - char *strPrint		: Chaine formaté pour impression.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Formatage pour impression d'un tableau de mesure.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  25/11/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int MES_PrintTab ( T_MESURES *tMesures, char *strPrint )
{
	int		idxMesure;
	char	chMess[1024] = {'\0'};


	strcpy (strPrint, "");
	for ( idxMesure=0 ; idxMesure<tMesures->nbMesure ; idxMesure++ )
	{
		MES_Print ( &tMesures->mesures[idxMesure], chMess );
		strcat (strPrint, chMess);
	}

	return 0;
}

// ==============================================================================
// FONCTION : 	  MES_Print
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int MES_Print ( T_MESURE *tMesure, char *strPrint )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_MESURE *tMesure	: Mesure à formater pour impression,
//				  - char *strPrint		: Chaine formaté pour impression.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Formatage pour impression d'une mesure.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  18/11/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int MES_Print ( T_MESURE *tMesure, char *strPrint )
{
	char chMess[128] = {'\0'};


	// ==========================
	// = Formatage de la mesure =
	// ==========================

	// RAZ de la chaine de retour
	// --------------------------
	strcpy (strPrint, "");

	// Ajout de la description et du status de test
	// --------------------------------------------
	sprintf ( chMess, "%s: %s - Status %s\n", MES_STR_PARAM_BLANK, tMesure->libelle, tMesure->status );
	strcat (strPrint, chMess);

	// Si avec mesure
	// --------------
	if (tMesure->avecMesure)
	{
		// Ajout des limites
		// -----------------
		sprintf ( chMess, "%s  %f %s < ... < %f %s\n", MES_STR_PARAM_BLANK, tMesure->limiteInferieure, tMesure->unite, tMesure->limiteSuperieure, tMesure->unite );
		strcat (strPrint, chMess);

		// Si la mesure a été réalisée on affiche le résultat
		// --------------------------------------------------
		if ( tMesure->mesure != 0.0 )
		{
			// Ajout de la valeur mesurées
			// ---------------------------
			sprintf ( chMess, "%s  %f %s\n", MES_STR_PARAM_BLANK, tMesure->mesure, tMesure->unite );
			strcat (strPrint, chMess);
		}
	}

	// Ajout du résultat de la mesure
	// ------------------------------
	//sprintf ( chMess, "%s  Status %s\n", MES_STR_PARAM_BLANK, tMesure->status );
	//strcat (strPrint, chMess);

	if ( tMesure->duree > 0 )
	{
		// Ajout de la durée du test
		// -------------------------
		sprintf ( chMess, "%s  Duree %d ms\n", MES_STR_PARAM_BLANK, tMesure->duree );
		strcat (strPrint, chMess);
	}

	// Ajout du nom de la variable dans la ligne
	// -----------------------------------------
	sprintf ( chMess, "Mesure <%s>", tMesure->nom);
	strncpy ( strPrint, chMess, strlen(chMess) );
	strPrint[strlen(strPrint)] = '\0';
	return 0;
}

// ==============================================================================
// FONCTION :     MES_EnregistrerTableau
// ------------------------------------------------------------------------------
// PROTOTYPE :    int MES_EnregistrerTableau ( 	T_MESURES *tTabMesure,
//                                    	  		int nItfe,
//                                      		char *strMessageErreur )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_MESURES   *tTabMesure         : Tableau de mesure,
//                - int     	nItfe				: Slot,
//                - char        *strMessageErreur   : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Enregistrement des mesures en bases.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA04
//  DATE :        12/072013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int MES_EnregistrerTableau (T_MESURES *tTabMesure, int nItfe, char *strMessageErreur )
{
	int 				error = 0;
	int 				idxMesure,i;
	int 				CHAMPS_TAB = 10;
	char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'};
	char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'};
	char    			chComment [SCPROD_MSG_LONG_MAX] = {'\0'};
	char				**TableauMesures = NULL;



	// =================
	// = Affichage Log =
	// =================
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_SOUS_ETAPE, GET_MESSAGE(FCT_MSG_TRACABILITE_MESURE));

	// Affichage Dans le log
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Enregistrement du tableau de mesure en cours");
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	// ========================================================
	// = Enregistrement des données dans le tableau de mesure =
	// ========================================================

	// Liste des Champs du Tableau :
	// ---------------------------
	/*
	0	code du type de test
	1	code du statut de test
	2	durée de la mesure
	3	valeur de mesure
	4	tolérance minimum de la mesure
	5	tolérance maximum de la mesure
	6	Description
	7	unité de mesure
	8	operation choisie
	9	commenteur
	*/


	// On créee le tableau de mesures
	// ------------------------------
	TableauMesures = (char**) malloc( sizeof(char*) * tTabMesure->nbMesure * CHAMPS_TAB);

	// On Boucle sur le nombre de mesures
	// ----------------------------------

	for ( idxMesure=0 ; idxMesure<tTabMesure->nbMesure ; idxMesure++ )
	{
		// On alloue la mémoire sur le tableau pour chaque Champ
		// -----------------------------------------------------
		TableauMesures[(idxMesure * CHAMPS_TAB) + 0] = (char*) malloc( sizeof(char) * MES_NOM_TAILLE_MAX );
		TableauMesures[(idxMesure * CHAMPS_TAB) + 1] = (char*) malloc( sizeof(char) * MES_STATUS_TAILLE_MAX );
		TableauMesures[(idxMesure * CHAMPS_TAB) + 2] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
		TableauMesures[(idxMesure * CHAMPS_TAB) + 3] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
		TableauMesures[(idxMesure * CHAMPS_TAB) + 4] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
		TableauMesures[(idxMesure * CHAMPS_TAB) + 5] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
		TableauMesures[(idxMesure * CHAMPS_TAB) + 6] = (char*) malloc( sizeof(char) * MES_DESC_TAILLE_MAX );
		TableauMesures[(idxMesure * CHAMPS_TAB) + 7] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
		TableauMesures[(idxMesure * CHAMPS_TAB) + 8] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
		TableauMesures[(idxMesure * CHAMPS_TAB) + 9] = (char*) malloc( sizeof(char) * SCPROD_MSG_LONG_MAX );

		// Mise en forme du commentaire (champ supplémentaire pour SAP ME)
		// ---------------------------------------------------------------
		sprintf (chComment,"Nom de la mesure: %s, Limite minimimale: %f, Valeur de la mesure: %f, Limite maximale: %f, Unité: %s, Statut: %s",tTabMesure->mesures[idxMesure].nom, tTabMesure->mesures[idxMesure].limiteInferieure, tTabMesure->mesures[idxMesure].mesure , tTabMesure->mesures[idxMesure].limiteSuperieure,tTabMesure->mesures[idxMesure].unite,tTabMesure->mesures[idxMesure].status);

		// On renseigne les différents champs de la mesure
		// -----------------------------------------------
		strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 0],tTabMesure->mesures[idxMesure].nom) ;
		strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 1],tTabMesure->mesures[idxMesure].status) ;
		sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 2],"%d", tTabMesure->mesures[idxMesure].duree) ;
		sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 3],"%f", tTabMesure->mesures[idxMesure].mesure) ;
		sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 4],"%f", tTabMesure->mesures[idxMesure].limiteInferieure) ;
		sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 5],"%f", tTabMesure->mesures[idxMesure].limiteSuperieure) ;
		strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 6],tTabMesure->mesures[idxMesure].libelle) ;
		strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 7],tTabMesure->mesures[idxMesure].unite) ;
		strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 8],SCPROD_GROUPE_MESURE_BTF) ;
		strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 9],chComment) ;
	}


	// On appelle ici la fonction d'enregistrement du tableau
	// ------------------------------------------------------
	errChk ( SCPROD_LogParametricDataTableau (nItfe, TableauMesures, tTabMesure->nbMesure, CHAMPS_TAB, chMsgTemp));

Error:


	// ===========================
	// = Libération des mémoires =
	// ===========================
	for (i =  (tTabMesure->nbMesure * CHAMPS_TAB - 1) ; i >= 0 ; i--)
		free ( TableauMesures [i]);

	free ( TableauMesures);

	// =======================
	// = gestion des erreurs =
	// =======================
	if(error)
	{
		sprintf (strMessageErreur, GET_MESSAGE(MES_MSG_MES_ENREGISTREMENT), tTabMesure->mesures[idxMesure].nom,chMsgTemp);
		return -1;
	}

	return 0;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
// FONCTION :		MES_EnregistrerTableauV2 2GHZ/5GHZ
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			08/09/2022
//  AUTEUR :		IHEB
//  DESCRIPTION :   MES_EnregistrerTableauV2
// ==============================================================================
// ==============================================================================
int MES_EnregistrerTableauV2 (T_MESURES1 *tTabMesure, int nItfe,FILE* fichier, char *strMessageErreur )
{
	int 				error = 0;
	int 				idxMesure=0,i=0;
	int 				CHAMPS_TAB = 10;
	char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'};
	char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'};
	char    			chComment [SCPROD_MSG_LONG_MAX] = {'\0'};
	char				**TableauMesures = NULL;
	char chLine[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char chMesure[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char chCode[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char Msg_Erreur[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char ligne_fail[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char tag[TAILLE_MAX] = "";
	char chcode2[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char chcodenum[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	int lenchLine=0;
	int len_tag=0;
	int a=0;
	int P=0;
	int Status=0;
	int Status1=0;
	int Status2=0;
	int status2=0;
	int status3=0;
	int Status_Failed=0;
	int Status_code_erreur=0;
	int k=0;
	int j=0;
	int S=0;
	int N=0;
	int nb_occurence=0;
	char find_1 = '(';
	char find_2 = ')';
	char find_3 = ',';
	int index_1;
	int index_2;
	int index_3;
	int len_erreur_code=0;
	char space[32]="";
	char libelle[32]="";
	char limiteInferieure[32]="";
	char limiteSuperieure[32]="";
	char res[TAILLE_MAX] = "";
	char Msg_Erreur_attache[TAILLE_MAX] = "";
	char unite[32]="";
	char mesure[32]="";
	char nom[32]="";
	float dlimiteInferieure=0;
	float dlimiteSuperieure=0;
	float dmesure=0;
	char status[32]="";
	char chTAG1[TAILLE_MAX] = ".TEST_VERIFY EVM MASK POWER SPECTRUM";
	char chTAG2[TAILLE_MAX] = ".TEST_VERIFY PER";
	char *ret;



	// =================
	// = Affichage Log =
	// =================
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_SOUS_ETAPE, GET_MESSAGE(FCT_MSG_TRACABILITE_MESURE));

	// Affichage Dans le log
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Enregistrement du tableau de mesure en cours");
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
//TableauMesures = (char**) malloc( sizeof(char*) * 400 * CHAMPS_TAB);
//	TableauMesures = (char**) malloc( sizeof(char*) * tTabMesure->nbMesure * CHAMPS_TAB);
	// ========================================================
	// = Enregistrement des données dans le tableau de mesure =
	// ========================================================

	// Liste des Champs du Tableau :
	// ---------------------------
	/*
	0	code du type de test
	1	code du statut de test
	2	durée de la mesure
	3	valeur de mesure
	4	tolérance minimum de la mesure
	5	tolérance maximum de la mesure
	6	Description
	7	unité de mesure
	8	operation choisie
	9	commenteur
	*/


	// On créee le tableau de mesures
	// ------------------------------
	//TableauMesures = (char**) malloc( sizeof(char*) * tTabMesure->nbMesure * CHAMPS_TAB);

	// On Boucle sur le nombre de mesures
	// ----------------------------------
	TableauMesures = (char**) malloc( sizeof(char*) * 400 * CHAMPS_TAB);
	/* for (int ich = 0; ich < 399; ich++)
		{
	TableauMesures[(ich * CHAMPS_TAB) + 0] = (char*) malloc( sizeof(char) * MES_NOM_TAILLE_MAX );
		TableauMesures[(ich * CHAMPS_TAB) + 1] = (char*) malloc( sizeof(char) * MES_STATUS_TAILLE_MAX );
		TableauMesures[(ich * CHAMPS_TAB) + 2] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
		TableauMesures[(ich * CHAMPS_TAB) + 3] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
		TableauMesures[(ich * CHAMPS_TAB) + 4] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
		TableauMesures[(ich * CHAMPS_TAB) + 5] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
		TableauMesures[(ich * CHAMPS_TAB) + 6] = (char*) malloc( sizeof(char) * MES_DESC_TAILLE_MAX );
		TableauMesures[(ich * CHAMPS_TAB) + 7] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
		TableauMesures[(ich * CHAMPS_TAB) + 8] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
		TableauMesures[(ich * CHAMPS_TAB) + 9] = (char*) malloc( sizeof(char) * SCPROD_MSG_LONG_MAX );
		//////////////////////////////////////////////////////////////////////////////////////////////
		sprintf(TableauMesures[(ich * CHAMPS_TAB) + 0],"%d",ich) ;
		strcpy(TableauMesures[(ich * CHAMPS_TAB) + 1],"2") ;
		sprintf(TableauMesures[(ich * CHAMPS_TAB) + 2],"%d", 0) ;
		sprintf(TableauMesures[(ich * CHAMPS_TAB) + 3],"%f", 0.0) ;
		sprintf(TableauMesures[(ich * CHAMPS_TAB) + 4],"%f",0.0) ;
		sprintf(TableauMesures[(ich * CHAMPS_TAB) + 5],"%f", 0.0) ;
		strcpy(TableauMesures[(ich * CHAMPS_TAB) + 6],"a") ;
		strcpy(TableauMesures[(ich * CHAMPS_TAB) + 7],"b") ;
		strcpy(TableauMesures[(ich * CHAMPS_TAB) + 8],"BWC") ;
		strcpy(TableauMesures[(ich * CHAMPS_TAB) + 9],"c") ;

		}*/



	if(fichier != NULL)
	{
		//	TableauMesures = (char**) malloc( sizeof(char*) * tTabMesure->nbMesure * CHAMPS_TAB);
		//tTabMesure->mesures = (T_MESURE *) realloc (tTabMesure->mesures, sizeof(T_MESURE) * (tTabMesure->nbMesure+1)


		while(fgets(chLine, TAILLE_MAX, fichier) != NULL)
		{
			lenchLine=strlen(chLine);
			if((lenchLine>3) )
			{
				Status=0;
				status2=0;
				Status1=0;
				Status2=0;
				status3=0;
				Status=FindPattern (chLine, 0,sizeof(chLine), "_____", 0, 0) ;
				if (Status>0)
				{

					CopyString (chCode,0 ,chLine,0 ,Status);
					memset (chLine, '\0', sizeof( chLine));
					Status1=FindPattern (chCode, 0,sizeof(chCode), chTAG1, 0, 0) ;
					if (Status1>0)
					{
						CopyString (chcode2,0 ,chCode,38,Status);
						CopyString (chcodenum,0 ,chCode,0 ,Status1);
						sprintf (nom,"%s_TX_%s",chcodenum,chcode2);
						if ((status2=    FindPattern (nom, 0,sizeof(nom), "HT_", 0, 0)) >0)
						{
							CopyString (nom,0 ,nom,0,status2-1);
							status3=    FindPattern (chCode, 0,sizeof(chCode), "HT_", 0, 0)	;
							if (status3>0)
							{
								CopyString (chcode2,0 ,chCode,status3+6,Status);
								sprintf (nom,"%s_%s",nom,chcode2);

							}
						}
						else if ((status2=    FindPattern (nom, 0,sizeof(nom), "HE_", 0, 0)) >0)
						{
							CopyString (nom,0 ,nom,0,status2-1);
							status3=    FindPattern (chCode, 0,sizeof(chCode), "HE_", 0, 0)	;
							if (status3>0)
							{
								CopyString (chcode2,0 ,chCode,status3+6,Status);
								sprintf (nom,"%s_%s",nom,chcode2);
							}
						}
						else if ((status2=    FindPattern (nom, 0,sizeof(nom), "VHT", 0, 0)) >0)
						{
							CopyString (nom,0 ,nom,0,status2-1);
							status3=    FindPattern (chCode, 0,sizeof(chCode), "VHT", 0, 0)	;
							if (status3>0)
							{
								CopyString (chcode2,0 ,chCode,status3+4,Status);
								sprintf (nom,"%s_%s",nom,chcode2);
							}
						}
					}
					Status2=FindPattern (chCode, 0,sizeof(chCode), chTAG2, 0, 0) ;
					if (Status2>0)
					{
						CopyString (chcode2,0 ,chCode,19,Status);
						CopyString (chcodenum,0 ,chCode,0 ,Status2);
						sprintf (nom,"%s_RX_%s",chcodenum,chcode2);
						if ((status2=    FindPattern (nom, 0,sizeof(nom), "HT_", 0, 0)) >0)
						{
							CopyString (nom,0 ,nom,0,status2-1);
							status3=    FindPattern (chCode, 0,sizeof(chCode), "HT_", 0, 0)	;
							if (status3>0)
							{
								CopyString (chcode2,0 ,chCode,status3+6,Status);
								sprintf (nom,"%s_%s",nom,chcode2);
							}
						}
						else if ((status2=    FindPattern (nom, 0,sizeof(nom), "HE_", 0, 0)) >0)
						{
							CopyString (nom,0 ,nom,0,status2-1);
							status3=    FindPattern (chCode, 0,sizeof(chCode), "HE_", 0, 0)	;
							if (status3>0)
							{
								CopyString (chcode2,0 ,chCode,status3+6,Status);
								sprintf (nom,"%s_%s",nom,chcode2);
							}
						}
						else if ((status2=    FindPattern (nom, 0,sizeof(nom), "VHT", 0, 0)) >0)
						{
							CopyString (nom,0 ,nom,0,status2-1);
							status3=    FindPattern (chCode, 0,sizeof(chCode), "VHT", 0, 0)	;
							if (status3>0)
							{
								CopyString (chcode2,0 ,chCode,status3+4,Status);
								sprintf (nom,"%s_%s",nom,chcode2);
							}
						}
					}

				}

				if (chCode!="")
				{
					const char *ptr_1 = strchr(chLine, find_1);
					const char *ptr_2 = strchr(chLine, find_2);
					const char *ptr_3 = strchr(chLine, find_3);

					if((ptr_1)&&(ptr_2)&&(ptr_3))
					{
						int index_1 = ptr_1 - chLine;
						int index_2 = ptr_2 - chLine;
						int index_3 = ptr_3 - chLine;
						int index_4 = index_2 -index_1;
						int index_5 = index_2 -index_3;


						for( k = index_1-7, j = 0; k <= (index_1-1); k++, j++)
							tag[j] = chLine[k];
						len_tag=strlen(tag);
						a=strlen("       ");


						ret = strstr(tag,"       ");
						if ( ret==NULL)
						{

							if (index_4>=5 && index_4<13 && index_5<8 )
							{

								// sprintf (nom ,"%s %d", "TEST_WIFI",idxMesure);

								//memset (tag, '\0', sizeof( tag));

								sscanf (chLine, "%s",libelle);
								sscanf (chLine, "%*s %*s %s",mesure);
								dmesure=atof(mesure);
								//  tTabMesure->mesures[idxMesure].mesure=dmesure;
								sscanf (chLine, "%*s %*s %*s %s",unite);
								sscanf (chLine, "%*s %*s%*s %*s %s",space) ;
								if ( strcmp ( space, "(,") == 0)
								{
									sprintf( limiteInferieure,"%s" ,"0");
									dlimiteInferieure=atof(limiteInferieure);
									//	tTabMesure->mesures[idxMesure].limiteInferieure=dlimiteInferieure ;
									sscanf (chLine, "%*s %*s %*s %*s %*s %s",limiteSuperieure);
									Status=    FindPattern (limiteSuperieure, 0,sizeof(limiteSuperieure), ")", 0, 0) ;
									CopyString (limiteSuperieure,0 ,limiteSuperieure,0 ,Status);
									dlimiteSuperieure=atof(limiteSuperieure);
									//	tTabMesure->mesures[idxMesure].limiteSuperieure=dlimiteSuperieure;

								}

								else
								{
									sscanf (chLine, "%*s %*s %*s %*s %*s %s",limiteInferieure);
									Status=    FindPattern (limiteInferieure, 0,sizeof(limiteInferieure), ",", 0, 0) ;
									CopyString (limiteInferieure,0 ,limiteInferieure,0 ,Status);
									dlimiteInferieure=atof(limiteInferieure);
									//	tTabMesure->mesures[idxMesure].limiteInferieure=dlimiteInferieure ;
									sscanf (chLine, "%*s %*s%*s %*s %*s %*s %s",limiteSuperieure);
									Status=    FindPattern (limiteSuperieure, 0,sizeof(limiteSuperieure), ")", 0, 0) ;
									CopyString (limiteSuperieure,0 ,limiteSuperieure,0 ,Status);
									dlimiteSuperieure=atof(limiteSuperieure);
									//	tTabMesure->mesures[idxMesure].limiteSuperieure=dlimiteSuperieure;

								}
								if (dlimiteInferieure<dmesure<dlimiteSuperieure )
								{
									sprintf (status, "%s", "0");
								}
								else
									sprintf (status, "%s", "1");




								//   tTabMesure->mesures[idxMesure].nom= ;

								// On alloue la mémoire sur le tableau pour chaque Champ
								// -----------------------------------------------------
								TableauMesures[(idxMesure * CHAMPS_TAB) + 0] = (char*) malloc( sizeof(char) * MES_NOM_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 1] = (char*) malloc( sizeof(char) * MES_STATUS_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 2] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 3] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 4] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 5] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 6] = (char*) malloc( sizeof(char) * MES_DESC_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 7] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 8] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 9] = (char*) malloc( sizeof(char) * SCPROD_MSG_LONG_MAX );

								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 0],"%d",idxMesure) ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 1],"2") ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 2],"%d", 0) ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 3],"%f", 0.0) ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 4],"%f",0.0) ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 5],"%f", 0.0) ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 6],"a") ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 7],"b") ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 8],"BWC") ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 9],"c") ;

								// Mise en forme du commentaire (champ supplémentaire pour SAP ME)
								// ---------------------------------------------------------------
								sprintf (chComment,"Nom de la mesure: %s, Limite minimimale: %f, Valeur de la mesure: %f, Limite maximale: %f, Unité: %s, Statut: %s",nom, dlimiteInferieure, dmesure , dlimiteSuperieure,unite,status);

								// On renseigne les différents champs de la mesure
								// -----------------------------------------------
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 0],nom) ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 1],status) ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 2],"%d", 0) ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 3],"%f", dmesure) ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 4],"%f", dlimiteInferieure) ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 5],"%f", dlimiteSuperieure) ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 6],libelle) ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 7],unite) ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 8],"BWC") ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 9],chComment) ;
								idxMesure++ ;
								//TableauMesures =(char**) realloc (TableauMesures, sizeof(char*) * (idxMesure + 1));
							}
						}
					}

				}

			}

			Status_Failed=FindPattern (chLine, 0,sizeof(chLine), "--- [Failed]", 0, 0) ;
			if (Status_Failed>0)
			{
				nb_occurence++;
				if   (nb_occurence==1)
				{
					//CopyString (Msg_Erreur,0 ,chLine,0 ,lenchLine);

					CopyString (Msg_Erreur,0 ,chLine,0 ,Status_Failed);
					// Status_code_erreur=FindPattern (Msg_Erreur, 0,sizeof(Msg_Erreur), ":", 0, 0) ;

					//if (Status_code_erreur>0)
					// {


					while (Msg_Erreur[N] != '\0')
					{
						if ((Msg_Erreur[N] == ' ' && Msg_Erreur[N+1] == ' ') != 1)
						{
							Msg_Erreur_attache[S] = Msg_Erreur[N];
							S++;
						}
						N++;
					}
					len_erreur_code=strlen(Msg_Erreur_attache);
					CopyString (Code_Erreur,0 ,Msg_Erreur_attache,0,len_erreur_code);
					// CopyString (Code_Erreur,0 ,Msg_Erreur,Status_code_erreur+2,len_erreur_code);
					FCT_RemplacerTag(Code_Erreur,FCT_PRINT_TAILLE_MAX," : " ,"");
					FCT_RemplacerTag(Code_Erreur,FCT_PRINT_TAILLE_MAX,"_" ,"");
					FCT_RemplacerTag(Code_Erreur,FCT_PRINT_TAILLE_MAX,"," ," ");
					FCT_RemplacerTag(Code_Erreur,FCT_PRINT_TAILLE_MAX,"%" ,"");
					//}
					// sprintf (strMessageErreur,"%s_%s","wifi_ko",res);


					//ligne_fail=strcat(chCode,Msg_Erreur);
					//sprintf (ligne_fail,"%s_%s",chCode,Msg_Erreur);
					sprintf (ligne_fail,"%s",chCode);
					//hethouma zedethom
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TX_MULTI_VERIFICATION_","TX");
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"RX_VERIFY_PER_","RX_");
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TEST_VERIFY_EVM_MASK_POWER_SPECTRUM_","TX_EVM_");
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TX_VERIFICATION_EVM_MASK_POWER_SPECTRUM_","TXTX_EVM_");
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TEST_VERIFY_PER_","RX_");
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TEST_VERIFY PER","RX_");
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TEST_VERIFY PER_","RX_");
					FCT_RemplacerTag ( ligne_fail,FCT_PRINT_TAILLE_MAX,"_HT_MF","");
					FCT_RemplacerTag ( ligne_fail,FCT_PRINT_TAILLE_MAX,"_HE_SU_","");
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TEST_VERIFY PER","RX_");
					FCT_RemplacerTag ( ligne_fail,FCT_PRINT_TAILLE_MAX,"VHT_","");
					FCT_RemplacerTag ( ligne_fail,FCT_PRINT_TAILLE_MAX,"NON_HT_","");
					FCT_RemplacerTag ( ligne_fail,FCT_PRINT_TAILLE_MAX,"TEST_VERIFY EVM MASK POWER SPECTRUM","EVM");
					//FCT_RemplacerTag ( ligne_fail, int nTaille,"_HT_MF","");
					//FCT_RemplacerTag ( ligne_fail, int nTaille,"_HT_MF","");

					//pour supprimer les espaces:


					while (ligne_fail[i] != '\0')
					{
						if ((ligne_fail[i] == ' ' && ligne_fail[i+1] == ' ') != 1)
						{
							res[P] = ligne_fail[i];
							P++;
						}
						i++;
					}
					// sprintf (strMessageErreur,"%s",res);
					sprintf (strMessageErreur,"%s_%s","wifi_ko",res);
					//Ajout Partie code erreur



					//FCT_RemplacerTag ( ligne_fail, int nTaille,"_HT_MF","");
					//FCT_RemplacerTag ( ligne_fail, int nTaille,"_HT_MF","");

					// sprintf (strMessageErreur,"%s",ligne_fail);
					//strMessageErreur=ligne_fail;

					//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,res);
				}

			}

			//sprintf (strMessageErreur,"%s",ligne_fail);

		}

		//	FIL2LO_EcritTraceV2 (TRUE, nItfe,chMesure);
		// getchar();
		//sprintf (strMessageErreur,"%s",ligne_fail);

	}


	// On appelle ici la fonction d'enregistrement du tableau
	// ------------------------------------------------------
	if (idxMesure >= 1 ) // Pour ne pas planter ME
		errChk ( SCPROD_LogParametricDataTableau (nItfe, TableauMesures, (idxMesure-1) , CHAMPS_TAB, chMsgTemp));

Error:


	// ===========================
	// = Libération des mémoires =
	// ===========================
	/*for (i =  (idxMesure * CHAMPS_TAB - 1) ; i >= 0 ; i--)
		free ( TableauMesures [i]);
	*/
	free ( TableauMesures);

	// =======================
	// = gestion des erreurs =
	// =======================
	if(error)
	{
		sprintf (strMessageErreur, GET_MESSAGE(MES_MSG_MES_ENREGISTREMENT), tTabMesure->mesures[idxMesure].nom,chMsgTemp);
		return -1;
	}

	return 0;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
// FONCTION :		MES_EnregistrerTableauV3 2GHZ/5GHZ
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			21/09/2022
//  AUTEUR :		IHEB
//  DESCRIPTION :   MES_EnregistrerTableauV3
// ==============================================================================
// ==============================================================================
int MES_EnregistrerTableauV3 (T_MESURES1 *tTabMesure, int nItfe,FILE* fichier, char *strMessageErreur )
{
	int 				error = 0;
	int 				idxMesure=0,i=0;
	int 				CHAMPS_TAB = 10;
	char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'};
	char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'};
	char    			chComment [SCPROD_MSG_LONG_MAX] = {'\0'};
	char				**TableauMesures = NULL;
	char chLine[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char chMesure[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char chCode[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char chcode2[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char chcodenum[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char Msg_Erreur[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char ligne_fail[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char tag[TAILLE_MAX] = "";
	int lenchLine=0;
	int len_tag=0;
	int a=0;
	int k=0;
	int P=0;
	int j=0;
	int Status_Failed=0;
	int Status=0;
	int Status1=0;
	int Status2=0;
	int status2=0;
	int status3=0;
	int Status_code_erreur=0;
	int nb_occurence=0;
	char find_1 = '(';
	char find_2 = ')';
	char find_3 = ',';
	int index_1;
	int index_2;
	int index_3;
	int N=0;
	int S=0;
	char Msg_Erreur_attache[TAILLE_MAX] = "";
	int len_erreur_code=0;
	char space[32]="";
	char libelle[32]="";
	char limiteInferieure[32]="";
	char res[TAILLE_MAX] = "";
	char limiteSuperieure[32]="";
	char unite[32]="";
	char mesure[32]="";
	char nom[32]="";
	float dlimiteInferieure=0;
	float dlimiteSuperieure=0;
	float dmesure=0;
	char status[32]="";
	char chTAG1[TAILLE_MAX] = ".TEST_VERIFY EVM MASK POWER SPECTRUM";
	char chTAG2[TAILLE_MAX] = ".TEST_VERIFY PER";
	char *ret;



	// =================
	// = Affichage Log =
	// =================
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_SOUS_ETAPE, GET_MESSAGE(FCT_MSG_TRACABILITE_MESURE));

	// Affichage Dans le log
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Enregistrement du tableau de mesure en cours");
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	// ========================================================
	// = Enregistrement des données dans le tableau de mesure =
	// ========================================================

	// Liste des Champs du Tableau :
	// ---------------------------
	/*
	0	code du type de test
	1	code du statut de test
	2	durée de la mesure
	3	valeur de mesure
	4	tolérance minimum de la mesure
	5	tolérance maximum de la mesure
	6	Description
	7	unité de mesure
	8	operation choisie
	9	commenteur
	*/


	// On créee le tableau de mesures
	// ------------------------------

	// On Boucle sur le nombre de mesures
	// ----------------------------------
	TableauMesures = (char**) malloc( sizeof(char*) * 400 * CHAMPS_TAB);

	if(fichier != NULL)
	{
		while(fgets(chLine, TAILLE_MAX, fichier) != NULL)
		{
			lenchLine=strlen(chLine);
			if((lenchLine>3) )
			{
				Status=0;
				status2=0;
				Status1=0;
				Status2=0;
				status3=0;
				Status=    FindPattern (chLine, 0,sizeof(chLine), "_____", 0, 0) ;
				if (Status>0)
				{
					CopyString (nom,0 ,chLine,0 ,Status);
					//memset (chLine, '\0', sizeof( chLine));
					CopyString (chCode,0 ,chLine,0 ,Status);
					memset (chLine, '\0', sizeof( chLine));

				}

				if (chCode!="")
				{
					const char *ptr_1 = strchr(chLine, find_1);
					const char *ptr_2 = strchr(chLine, find_2);
					const char *ptr_3 = strchr(chLine, find_3);

					if((ptr_1)&&(ptr_2)&&(ptr_3))
					{
						int index_1 = ptr_1 - chLine;
						int index_2 = ptr_2 - chLine;
						int index_3 = ptr_3 - chLine;
						int index_4 = index_2 -index_1;
						int index_5 = index_2 -index_3;




						for( k = index_1-7, j = 0; k <= (index_1-1); k++, j++)
							tag[j] = chLine[k];
						len_tag=strlen(tag);
						a=strlen("       ");


						ret = strstr(tag,"       ");
						if ( ret==NULL)
						{
							if (index_4>=5 && index_4<13 && index_5<8)
							{
								// sprintf (nom ,"%s %d", "TEST_WIFI",idxMesure);



								sscanf (chLine, "%s",libelle);
								sscanf (chLine, "%*s %*s %s",mesure);
								dmesure=atof(mesure);
								//  tTabMesure->mesures[idxMesure].mesure=dmesure;
								sscanf (chLine, "%*s %*s %*s %s",unite);
								sscanf (chLine, "%*s %*s%*s %*s %s",space) ;
								if ( strcmp ( space, "(,") == 0)
								{
									sprintf( limiteInferieure,"%s" ,"0");
									dlimiteInferieure=atof(limiteInferieure);
									//	tTabMesure->mesures[idxMesure].limiteInferieure=dlimiteInferieure ;
									sscanf (chLine, "%*s %*s %*s %*s %*s %s",limiteSuperieure);
									Status=    FindPattern (limiteSuperieure, 0,sizeof(limiteSuperieure), ")", 0, 0) ;
									CopyString (limiteSuperieure,0 ,limiteSuperieure,0 ,Status);
									dlimiteSuperieure=atof(limiteSuperieure);
									//	tTabMesure->mesures[idxMesure].limiteSuperieure=dlimiteSuperieure;

								}
								else
								{
									sscanf (chLine, "%*s %*s %*s %*s %*s %s",limiteInferieure);
									Status=    FindPattern (limiteInferieure, 0,sizeof(limiteInferieure), ",", 0, 0) ;
									CopyString (limiteInferieure,0 ,limiteInferieure,0 ,Status);
									dlimiteInferieure=atof(limiteInferieure);
									//	tTabMesure->mesures[idxMesure].limiteInferieure=dlimiteInferieure ;
									sscanf (chLine, "%*s %*s%*s %*s %*s %*s %s",limiteSuperieure);
									Status=    FindPattern (limiteSuperieure, 0,sizeof(limiteSuperieure), ")", 0, 0) ;
									CopyString (limiteSuperieure,0 ,limiteSuperieure,0 ,Status);
									dlimiteSuperieure=atof(limiteSuperieure);
									//	tTabMesure->mesures[idxMesure].limiteSuperieure=dlimiteSuperieure;

								}
								if (dlimiteInferieure<dmesure<dlimiteSuperieure )
								{
									sprintf (status, "%s", "0");
								}
								else
									sprintf (status, "%s", "1");





								//   tTabMesure->mesures[idxMesure].nom= ;

								// On alloue la mémoire sur le tableau pour chaque Champ
								// -----------------------------------------------------
								TableauMesures[(idxMesure * CHAMPS_TAB) + 0] = (char*) malloc( sizeof(char) * MES_NOM_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 1] = (char*) malloc( sizeof(char) * MES_STATUS_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 2] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 3] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 4] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 5] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 6] = (char*) malloc( sizeof(char) * MES_DESC_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 7] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 8] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
								TableauMesures[(idxMesure * CHAMPS_TAB) + 9] = (char*) malloc( sizeof(char) * SCPROD_MSG_LONG_MAX );

								/*sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 0],"%d",idxMesure) ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 1],"2") ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 2],"%d", 0) ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 3],"%f", 0.0) ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 4],"%f",0.0) ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 5],"%f", 0.0) ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 6],"a") ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 7],"b") ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 8],"BWC") ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 9],"c") ; */

								// Mise en forme du commentaire (champ supplémentaire pour SAP ME)
								// ---------------------------------------------------------------
								sprintf (chComment,"Nom de la mesure: %s, Limite minimimale: %f, Valeur de la mesure: %f, Limite maximale: %f, Unité: %s, Statut: %s",nom, dlimiteInferieure, dmesure , dlimiteSuperieure,unite,status);

								// On renseigne les différents champs de la mesure
								// -----------------------------------------------
								//strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 0],nom) ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 0],nom) ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 1],status) ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 2],"%d", 0) ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 3],"%f", dmesure) ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 4],"%f", dlimiteInferieure) ;
								sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 5],"%f", dlimiteSuperieure) ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 6],libelle) ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 7],unite) ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 8],"BWC") ;
								strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 9],chComment) ;
								idxMesure++ ;
								//TableauMesures =(char**) realloc (TableauMesures, sizeof(char*) * (idxMesure + 1));
							}
						}
					}
				}
			}

			Status_Failed=FindPattern (chLine, 0,sizeof(chLine), "--- [Failed]", 0, 0) ;
			if (Status_Failed>0)
			{
				nb_occurence++;
				if   (nb_occurence==1)
				{
					CopyString (Msg_Erreur,0 ,chLine,0 ,Status_Failed);


					while (Msg_Erreur[N] != '\0')
					{
						if ((Msg_Erreur[N] == ' ' && Msg_Erreur[N+1] == ' ') != 1)
						{
							Msg_Erreur_attache[S] = Msg_Erreur[N];
							S++;
						}
						N++;
					}

					//Status_code_erreur=FindPattern (Msg_Erreur, 0,sizeof(Msg_Erreur), ":", 0, 0) ;
					len_erreur_code=strlen(Msg_Erreur_attache);
					// if (Status_code_erreur>0)
					// {

					CopyString (Code_Erreur,0 ,Msg_Erreur_attache,0,len_erreur_code);
					FCT_RemplacerTag(Code_Erreur,FCT_PRINT_TAILLE_MAX," : " ,"");
					FCT_RemplacerTag(Code_Erreur,FCT_PRINT_TAILLE_MAX,"_" ,"");
					FCT_RemplacerTag(Code_Erreur,FCT_PRINT_TAILLE_MAX,"," ," ");
					FCT_RemplacerTag(Code_Erreur,FCT_PRINT_TAILLE_MAX,"%" ,"");
					//  FCT_RemplacerTag(Code_Erreur,FCT_PRINT_TAILLE_MAX," : " ,"_");
					//  FCT_RemplacerTag(Code_Erreur,FCT_PRINT_TAILLE_MAX," ( " ,"(");
					//  FCT_RemplacerTag(Code_Erreur,FCT_PRINT_TAILLE_MAX," )" ,")");
					//  FCT_RemplacerTag(Code_Erreur,FCT_PRINT_TAILLE_MAX,"%" ,"");
					// }
					//  sprintf (strMessageErreur,"%s_%s","BT_ko",res);

					//ligne_fail=strcat(chCode,Msg_Erreur);
					//sprintf (ligne_fail,"%s_%s",chCode,Msg_Erreur);
					sprintf (ligne_fail,"%s",chCode);
					//ligne_fail=strcat(chCode,Msg_Erreur);
					//sprintf (ligne_fail,"%s_%s",chCode,Msg_Erreur);
					//hethouma zedethom
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TX_MULTI_VERIFICATION_","TX");
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"RX_VERIFY_PER_","RX_");
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TEST_VERIFY_EVM_MASK_POWER_SPECTRUM_","TX_EVM_");
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TX_VERIFICATION_EVM_MASK_POWER_SPECTRUM_","TXTX_EVM_");
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TEST_VERIFY_PER_","RX_");
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TEST_VERIFY PER","RX_");
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TEST_VERIFY PER_","RX_");
					FCT_RemplacerTag ( ligne_fail,FCT_PRINT_TAILLE_MAX,"_HT_MF","");
					FCT_RemplacerTag ( ligne_fail,FCT_PRINT_TAILLE_MAX,"_HE_SU_","");
					FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TEST_VERIFY PER","RX_");
					FCT_RemplacerTag ( ligne_fail,FCT_PRINT_TAILLE_MAX,"VHT_","");
					FCT_RemplacerTag ( ligne_fail,FCT_PRINT_TAILLE_MAX,"NON_HT_","");
					FCT_RemplacerTag ( ligne_fail,FCT_PRINT_TAILLE_MAX,"TEST_VERIFY EVM MASK POWER SPECTRUM","EVM");
					//FCT_RemplacerTag ( ligne_fail, int nTaille,"_HT_MF","");
					//FCT_RemplacerTag ( ligne_fail, int nTaille,"_HT_MF","");

					//pour supprimer les espaces:


					while (ligne_fail[i] != '\0')
					{
						if ((ligne_fail[i] == ' ' && ligne_fail[i+1] == ' ') != 1)
						{
							res[P] = ligne_fail[i];
							P++;
						}
						i++;
					}


					sprintf (strMessageErreur,"%s_%s","BT_ko",res);

					//FCT_RemplacerTag ( ligne_fail, int nTaille,"_HT_MF","");
					//FCT_RemplacerTag ( ligne_fail, int nTaille,"_HT_MF","");
					//sprintf (strMessageErreur,"%s",res);
					//sprintf (strMessageErreur,"%s",ligne_fail);
					//strMessageErreur=ligne_fail;

					//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,ligne_fail);

					//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,ligne_fail);
				}

			}
		}


		//sprintf (strMessageErreur,"%s",ligne_fail);



//	FIL2LO_EcritTraceV2 (TRUE, nItfe,chMesure);
		// getchar();
	}


	// On appelle ici la fonction d'enregistrement du tableau
	// ------------------------------------------------------
	if (idxMesure >= 1 ) // Pour ne pas planter ME
		errChk ( SCPROD_LogParametricDataTableau (nItfe, TableauMesures, (idxMesure-1) , CHAMPS_TAB, chMsgTemp));

Error:


	// ===========================
	// = Libération des mémoires =
	// ===========================
	/*for (i =  (idxMesure * CHAMPS_TAB - 1) ; i >= 0 ; i--)
		free ( TableauMesures [i]);
	*/
	free ( TableauMesures);

	// =======================
	// = gestion des erreurs =
	// =======================
	if(error)
	{
		sprintf (strMessageErreur, GET_MESSAGE(MES_MSG_MES_ENREGISTREMENT), tTabMesure->mesures[idxMesure].nom,chMsgTemp);
		return -1;
	}

	return 0;
}





int MES_EnregistrerTableauV2Log (T_MESURES *tTabMesure,const  char *filename ,  int nItfe,FILE* fichier, char *strMessageErreur )

{
	int 				error = 0;
	int 				idxMesure=0,i=0;
	int 				CHAMPS_TAB = 30;
	char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'};
	char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'};
	char    			chComment [SCPROD_MSG_LONG_MAX] = {'\0'};
	char				**TableauMesures = NULL;
	char chLine[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char chMesure[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char chCode[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char Msg_Erreur[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char ligne_fail[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char tag[TAILLE_MAX] = "";
	char chcode2[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char chcodenum[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	int lenchLine=0;
	int len_tag=0;
	int a=0;
	int P=0;
	int Status=0;
	int Status1=0;
	int Status2=0;
	int status2=0;
	int status3=0;
	int Status_Failed=0;
	int Status_code_erreur=0;
	int k=0;
	int j=0;
	int S=0;
	int N=0;
	int nb_occurence=0;
	char find_1 = '(';
	char find_2 = ')';
	char find_3 = ',';
	int index_1;
	int index_2;
	int index_3;
	int len_erreur_code=0;
	char space[32]="";
	char libelle[32]="";
	char limiteInferieure[32]="";
	char limiteSuperieure[32]="";
	char res[TAILLE_MAX] = "";
	char Msg_Erreur_attache[TAILLE_MAX] = "";
	char unite[32]="";
	char mesure[32]="";
	char nom[32]="";
	float dlimiteInferieure=0;
	float dlimiteSuperieure=0;
	float dmesure=0;
	char status[32]="";
	char chTAG1[TAILLE_MAX] = ".TEST_VERIFY EVM MASK POWER SPECTRUM";
	char chTAG2[TAILLE_MAX] = ".TEST_VERIFY PER";
	char *ret;


	FILE  * f  ;
	f = fopen(filename ,"r") ;

	// =================
	// = Affichage Log =
	// =================
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_SOUS_ETAPE, GET_MESSAGE(FCT_MSG_TRACABILITE_MESURE));

	// Affichage Dans le log
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Enregistrement du tableau de mesure en cours");
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	// ========================================================
	// = Enregistrement des données dans le tableau de mesure =
	// ========================================================

	// Liste des Champs du Tableau :
	// ---------------------------
	/*
	0	code du type de test
	1	code du statut de test
	2	durée de la mesure
	3	valeur de mesure
	4	tolérance minimum de la mesure
	5	tolérance maximum de la mesure
	6	Description
	7	unité de mesure
	8	operation choisie
	9	commenteur
	*/


	// On créee le tableau de mesures
	// ------------------------------
	//TableauMesures = (char**) malloc( sizeof(char*) * tTabMesure->nbMesure * CHAMPS_TAB);

	// On Boucle sur le nombre de mesures
	// ----------------------------------
	//TableauMesures = (char**) malloc( sizeof(char*) * 400 * CHAMPS_TAB);


	const int tabmes = 1;
	if(f != NULL)
	{
		//TableauMesures = (char**) malloc( sizeof(char*) * tTabMesure->nbMesure * CHAMPS_TAB);
		//tTabMesure->mesures = (T_MESURE *) realloc (tTabMesure->mesures, sizeof(T_MESURE) * (tTabMesure->nbMesure+1)


		//TableauMesures = (char**) malloc( sizeof(char*) *  tabmes * CHAMPS_TAB);
TableauMesures = (char**) malloc( sizeof(char*) *  400 * CHAMPS_TAB);
		Status=0;
		status2=0;
		Status1=0;
		Status2=0;
		status3=0;


		lenchLine=strlen(chLine);
		// nouveau  code
		/* code lire log python */

		char *filenameinput=  ( char *)  malloc(sizeof(char )  *  1024  );



		char result[8024]  ;







		char message [4084 ] ;

		//sprintf(message,"opened file %s" ,   filenameinput );
		//PromptPopup("ok" , "reading file ok" ,message , MAX_FILE_DATA_LENGTH);



		char   result2[2048];

		char nom [1024] ;
		char minb[20] = {'\0'} ;
		char maxc[20] = "10000000" ;
		char a[20];
		float  m=0;
		char _date[1024];
		char nomRX[1024]={'\0'} ;
		char step[1024]={'\0'} ; 
		char _com;

		float  min = 0, max = 0  ,  valeur=0;


		char readeruni [1024] ;



		while(fgets(chLine, TAILLE_MAX, f) != NULL)
		{

		   sscanf(chLine  , "nom  : %s  mesure  : %f  unite  : %s  val1  : %s  val2  : %s" ,nom , &m, readeruni, minb, maxc );

		   
		   //char  *nomRX,  *nomTX;

		   
		   
		   if( (  strstr(nom, "_TX_")) ||  (strstr(nom, "_RX_")) ) 
		   
		   {
			   
			 strncpy (nomRX, &nom[5], strlen(nom)-5);
			 strcpy(nom,nomRX);
			     
		   }
		   

			if (strcmp(maxc , " ") == 0 ||  strcmp(maxc , "\0") == 0   )
			{
				strcpy(maxc , "infinity" ) ;
				
				
			}
			if(strcmp(minb, " ") ==0  || strcmp(minb , "\0") == 0 ) strcpy(minb , "inifinty") ;
			//sprintf(result , "Nom %s; status : %f;date:  %s; mesure : %s ;min : %s; max :%s;step :%s;uni : %s", nom , m ,_date, a, minb, maxc , step ,readeruni) ;

             //FILE *o ;
			 //o = fopen("testy.txt","w+"); 
			//fprintf(o , "testwfig.conduit %s" , filename);


		
			int _status  = 1;
				
		     char  statsm [1024];
			 sprintf(statsm, "%f",m);
				
				float v1 =  atof(maxc ) ; 
				float  v2 =   atof(minb  ) ;
				
				
			  if (statsm <=maxc  && statsm >= minb)
				   _status = 0 ;
			





			// On alloue la mémoire sur le tableau pour chaque Champ
			// -----------------------------------------------------

			//TableauMesures =(char**) realloc (TableauMesures, sizeof(char*) * (idxMesure + 1));



			TableauMesures[(idxMesure * CHAMPS_TAB) + 0] = (char*) malloc( sizeof(char) * MES_NOM_TAILLE_MAX );
			TableauMesures[(idxMesure * CHAMPS_TAB) + 1] = (char*) malloc( sizeof(char) * MES_STATUS_TAILLE_MAX );
			TableauMesures[(idxMesure * CHAMPS_TAB) + 2] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
			TableauMesures[(idxMesure * CHAMPS_TAB) + 3] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
			TableauMesures[(idxMesure * CHAMPS_TAB) + 4] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
			TableauMesures[(idxMesure * CHAMPS_TAB) + 5] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
			TableauMesures[(idxMesure * CHAMPS_TAB) + 6] = (char*) malloc( sizeof(char) * MES_DESC_TAILLE_MAX );
			TableauMesures[(idxMesure * CHAMPS_TAB) + 7] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
			TableauMesures[(idxMesure * CHAMPS_TAB) + 8] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
			TableauMesures[(idxMesure * CHAMPS_TAB) + 9] = (char*) malloc( sizeof(char) * SCPROD_MSG_LONG_MAX );

			/*sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 0],"%d",idxMesure) ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 1],"2") ;
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 2],"%d", 0) ;
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 3],"%f", 0.0) ;
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 4],"%f",0.0) ;
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 5],"%f", 0.0) ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 6],"a") ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 7],"b") ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 8],"BWC") ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 9],"c") ; */

			// Mise en forme du commentaire (champ supplémentaire pour SAP ME)
			// ---------------------------------------------------------------
			sprintf (chComment,"Nom de la mesure: %s, Limite minimimale: %f, Valeur de la mesure: %f, Limite maximale: %f, Unité: %s, Statut: %s",nom, dlimiteInferieure, dmesure , dlimiteSuperieure,unite,status);

			// On renseigne les différents champs de la mesure
			// -----------------------------------------------


            
			sprintf(result , "Nom %s; status : %f;date:  %s; mesure : %s ;min : %s; max :%s;step :%s;uni : %s", nom , m ,_date, a, minb, maxc , step ,readeruni) ;
			/*char  statsm [1024];
			sprintf(statsm, "%f",m);
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 0],nom) ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 1],statsm) ;
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 2],"%d", 0) ;
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 3],"%s", a) ;
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 4],"%s", minb) ;
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 5],"%s", maxc) ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 6],"libelle") ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 7],readeruni) ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 8],"BWC") ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 9],"") ;
			*/
          
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 0],nom) ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 1],statsm) ;
			
		 
			
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 2],"%d", _status) ;
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 3],"%s", "ok") ;
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 4],"%s", minb) ;
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 5],"%s", maxc) ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 6],"STEP") ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 7],readeruni) ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 8],"BWC") ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 9],"C") ;


			/*

			old - old

			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 0],nom) ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 1],status) ;
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 2],"%d", 0) ;
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 3],"%f", dmesure) ;
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 4],"%f", dlimiteInferieure) ;
			sprintf(TableauMesures[(idxMesure * CHAMPS_TAB) + 5],"%f", dlimiteSuperieure) ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 6],libelle) ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 7],unite) ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 8],"BWC") ;
			strcpy(TableauMesures[(idxMesure * CHAMPS_TAB) + 9],chComment) ;


			*/
			
			if(strcmp(nom,"" )){
				
						idxMesure++ ;  
			}
			
	
			






			//ligne_fail=strcat(chCode,Msg_Erreur);
			//sprintf (ligne_fail,"%s_%s",chCode,Msg_Erreur);
			//  sprintf (ligne_fail,"%s",chCode);
			//
			FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TX_MULTI_VERIFICATION_","TX");
			FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"RX_VERIFY_PER_","RX_");
			FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TEST_VERIFY_EVM_MASK_POWER_SPECTRUM_","TX_EVM_");
			FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TX_VERIFICATION_EVM_MASK_POWER_SPECTRUM_","TXTX_EVM_");
			FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TEST_VERIFY_PER_","RX_");
			FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TEST_VERIFY PER","RX_");
			FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TEST_VERIFY PER_","RX_");
			FCT_RemplacerTag ( ligne_fail,FCT_PRINT_TAILLE_MAX,"_HT_MF","");
			FCT_RemplacerTag ( ligne_fail,FCT_PRINT_TAILLE_MAX,"_HE_SU_","");
			FCT_RemplacerTag ( ligne_fail, FCT_PRINT_TAILLE_MAX,"TEST_VERIFY PER","RX_");
			FCT_RemplacerTag ( ligne_fail,FCT_PRINT_TAILLE_MAX,"VHT_","");
			FCT_RemplacerTag ( ligne_fail,FCT_PRINT_TAILLE_MAX,"NON_HT_","");
			FCT_RemplacerTag ( ligne_fail,FCT_PRINT_TAILLE_MAX,"TEST_VERIFY EVM MASK POWER SPECTRUM","EVM");
			//FCT_RemplacerTag ( ligne_fail, int nTaille,"_HT_MF","");
			//FCT_RemplacerTag ( ligne_fail, int nTaille,"_HT_MF","");

			//pour supprimer les espaces:





			//SetCtrlAttribute();
			// C:\Users\g702306\Desktop\testy000\extractorparser\resultfinale2G.txt
			
		}
		SCPROD_LogParametricDataTableau (nItfe, TableauMesures, (idxMesure-1), CHAMPS_TAB,chMsgTemp);




		//FCT_EnregistrementMesureLog(nItfe,(char **) TableauMesures);
		//sprintf (strMessageErreur,"%s",ligne_fail);

	}

	//	FIL2LO_EcritTraceV2 (TRUE, nItfe,chMesure);
	// getchar();
	//sprintf (strMessageErreur,"%s",ligne_fail);




	// On appelle ici la fonction d'enregistrement du tableau
	// ------------------------------------------------------
//	if (idxMesure >= 1 ) // Pour ne pas planter ME
	//	errChk ( SCPROD_LogParametricDataTableau (nItfe, TableauMesures, (idxMesure-1) , CHAMPS_TAB, chMsgTemp));

Error:

	// ===========================
	// = Libération des mémoires =
	// ===========================
/*	for (i =  (((idxMesure-1) * CHAMPS_TAB) +9) ; i >= 0 ; i--)
		free ( TableauMesures [i]);			*/









	free ( TableauMesures);

	// =======================
	// = gestion des erreurs =
	// =======================
	if(error)
	{
		sprintf (strMessageErreur, GET_MESSAGE(MES_MSG_MES_ENREGISTREMENT), tTabMesure->mesures[idxMesure].nom,chMsgTemp);
		return -1;
	}

	return 0;
}

