// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//  
// 
// ==============================================================================
//   PROJET         : Banc Personnalisation
//   MODULE         : Cles
//   PROCESSEUR     : INTEL Pentium
//   ENVIRONNEMENT  : Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION    : Gestion des cl�s du d�codeur.
//                    
// ==============================================================================
//   REMARQUES      :
// ==============================================================================
//   MODIFICATIONS  :   
//
// Version Rev X
// Date / Author
//
// V 1.4.0 
// 12-Octobre-2009  NCR (DT2E)
//      >>>  Cr�ation
// ==============================================================================

// ==============================================================================
// INCLUDE
// ==============================================================================

#include "Include.h"


// ==============================================================================
// PROTOTYPES DES FONCTIONS LOCALES
// ==============================================================================

// Prototypes des fonctions de lecture des cl�s
// --------------------------------------------
int LectureCle ( void *cle, int indexCle, char *strMessageErreur, int nbParam, ...);
int LectureCleHddPass ( void *cle, int indexCle, char *strMessageErreur);

// Prototypes des fonctions d'�criture des cl�s
// --------------------------------------------
int EcritureCleHddPass ( void *cle, int indexCle, char *strMessageErreur);

// Prototypes des fonctions d'affichage des valeurs des cl�s
// ---------------------------------------------------------
int AffichageCleHddPass         ( void *cle, int indexCle, char *strPrint);

// Prototypes des fonctions d'extraction des valeurs des cl�s
// ----------------------------------------------------------
int ValeurCleHddPass            ( void *cle, int indexCle, char **strValeur);

// ==============================================================================
// DECLARATION DES VARIABLES GLOBALES
// ==============================================================================

// D�finition des cl�s perso pour le banc Perso
// --------------------------------------------
T_CLE gTCles[] =

//  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// |        NOM         | NOM TABLE | DESCRIPTION | QUANTITE | PARAMETRES | NB PARAMETRES | VALEURS 	| NB VALEURS | ID |   NAGRA |  		FCT LECTURE         |       FCT ECRITURE        |       FCT AFFICHAGE       |       	FCT VALEUR     	|
//  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{
 {    "stbpasswords16",         "",         "",         1,      NULL,			0,          NULL, 				0,      0,  	0,	 	LectureCleHddPass,			EcritureCleHddPass,		                       AffichageCleHddPass,            ValeurCleHddPass	},
};

// --------------
// Nombre de cl�s
// --------------
const int gNbCles = (int)(sizeof(gTCles) / sizeof(T_CLE));


// ==============================================================================
// DECLARATION DES FONCTIONS
// ==============================================================================

// ==============================================================================
// FONCTION :     CLE_Get
// ------------------------------------------------------------------------------
// PROTOTYPE :    int CLE_Get(  T_CLES *tCles,
//                              hdleTCom instTracaCom,
//                              char *codeProduit,
//                              char *indiceProduit,
//                              int nItfe,
//                              int idPort,
//                              char *strMessageErreur)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_CLES *tCles           : Tableau de cl� pour le Slot,
//                - hdleTCom instTracaCom   : Handle sur la base TracaCom,
//                - char *codeProduit       : Code produit,
//                - char *indiceProduit     : Indice produit,
//                - int nItfe               : Index Slot,
//                - int idPort              : Index COM STB,
//                - char *strErreurMessage  : Message de l'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontr� durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Extraction de la Base de donn�es des cl�s perso utilis�es 
//                pour le produit courant 
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        14/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int CLE_Get( T_CLES *tCles, hdleTCom instTracaCom, char *codeProduit, char *indiceProduit, int nItfe, int idPort, char *strMessageErreur)
{
    char    **tabCles = NULL;
    char    *tcomErreur = NULL;
    char    *strErreurRequete = NULL;
    int     erreurSurvenue;
    int     erreurCode;
    int     tabClesLen1;
    int     tabClesLen2;
    int     error = 0;
    int     idxCleIn;
    int     idxCleOut;
    

    // ===============================================
    // = RAZ des param�tres de sortie de la fonction =
    // ===============================================
    strMessageErreur[0] = '\0'; 
    
    // ==========================
    // = RAZ du tableau de cl�s =
    // ==========================
    tCles->cles = NULL;
    tCles->nbCle = 0;
    // MAJ de l'index du Slot
    // ----------------------
    tCles->nItfe = nItfe;
    // MAJ de l'index du port COM
    // --------------------------
    tCles->idPort = idPort;
    // MAJ de l'handle de la base TracaCom
    // -----------------------------------
    tCles->instTracaCom = instTracaCom;
    // MAJ du code produit
    // -------------------
    strcpy ( tCles->codeProduit, codeProduit);
    // MAJ de l'indice produit
    // -----------------------
    strcpy ( tCles->indiceProduit, indiceProduit);
    
    // =======================================================
    // = Extraction des cl�s perso utilis�es pour le produit =
    // =======================================================
    TracaCom_FonctionsMDT_FonctionsMDT_RecuperationClesParProduit(
            tCles->instTracaCom,
            tCles->codeProduit,
            tCles->indiceProduit,
            &tabCles,
            &tabClesLen1,
            &tabClesLen2,
            &erreurSurvenue,
            &erreurCode,
            &tcomErreur,
            &strErreurRequete,
            NULL);
    
    // V�rification des erreurs de la fonction
    // ---------------------------------------
    if(erreurSurvenue)
    {
        errChk(erreurCode);
    }

    // ==========================================
    // = Extraction des cl�s pour le banc Perso =
    // ==========================================
    for ( idxCleOut=0 ; idxCleOut<gNbCles ; idxCleOut++ )
    {
        for ( idxCleIn=0 ; idxCleIn<tabClesLen1 ; idxCleIn++ )
        {
            if ( strcmp (gTCles[idxCleOut].nom, tabCles[idxCleIn*tabClesLen2]) == 0 )
            {
                // On incr�mente le nombre de cl�s utilis�es
                // -----------------------------------------
                tCles->nbCle++;
            
                // Allocation m�moire pour la nouvelle cl�
                // ---------------------------------------
                tCles->cles = (T_CLE *) realloc (tCles->cles, sizeof(T_CLE) * tCles->nbCle);
            
                // Extraction du nom de la table o� est d�fini la cl�
                // --------------------------------------------------
                strcpy ( tCles->cles[tCles->nbCle-1].nomTable, tabCles[(idxCleIn*tabClesLen2)+1] );
            
                // Extraction de la d�signation de la cl�
                // --------------------------------------
                strcpy ( tCles->cles[tCles->nbCle-1].designation, tabCles[(idxCleIn*tabClesLen2)+2] );

                // Extraction de la quantit� des valeurs de la cl�
                // -----------------------------------------------
                tCles->cles[tCles->nbCle-1].quantite = atoi (tabCles[(idxCleIn*tabClesLen2)+3]);
                
                // MAJ du nom de la cl�
                // --------------------
                strcpy ( tCles->cles[tCles->nbCle-1].nom, gTCles[idxCleOut].nom );
                
                // RAZ parametres
                // --------------
                tCles->cles[tCles->nbCle-1].parametres = NULL;
                
                // RAZ nombre de parametres
                // ------------------------
                tCles->cles[tCles->nbCle-1].nbParametres = 0;

                // RAZ valeurs
                // -----------
                tCles->cles[tCles->nbCle-1].valeurs = NULL;
                
                // RAZ nombre de valeurs
                // ---------------------
                tCles->cles[tCles->nbCle-1].nbValeurs = 0;
                
                // RAZ id
                // ------
                tCles->cles[tCles->nbCle-1].id = 0;
				
				// MAJ du param�tre Nagra
                // ----------------------
                tCles->cles[tCles->nbCle-1].iNagra = gTCles[idxCleOut].iNagra;

                // MAJ de la fonction d'�criture
                // -----------------------------
                tCles->cles[tCles->nbCle-1].Ecriture = gTCles[idxCleOut].Ecriture;

                // MAJ de la fonction de lecture
                // -----------------------------
                tCles->cles[tCles->nbCle-1].Lecture = gTCles[idxCleOut].Lecture;

                // MAJ de la fonction d'affichage
                // ------------------------------
                tCles->cles[tCles->nbCle-1].Affichage = gTCles[idxCleOut].Affichage;
                
                // MAJ de la fonction d'extraction de la valeur de la cl�
                // ------------------------------------------------------
                tCles->cles[tCles->nbCle-1].Valeur = gTCles[idxCleOut].Valeur;

                break;
            }
        }
    }
    
Error:
    // Lib�ration des ressources
    // -------------------------
    CDotNetFreeMemory(tabCles);

    // =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if ( tcomErreur != NULL )
        {   
            if ( strErreurRequete != NULL )
                sprintf (strMessageErreur, "%s", tcomErreur);
            else
                strcpy (strMessageErreur, tcomErreur);
        }

        // Lib�ration des ressources
        // -------------------------
        if (strErreurRequete!=NULL)
            CDotNetFreeMemory(strErreurRequete);
        if (tcomErreur!=NULL)
            CDotNetFreeMemory(tcomErreur);

        return -1;
    }   
    
    return 0;
}

// ==============================================================================
// FONCTION :     CLE_GetIndex
// ------------------------------------------------------------------------------
// PROTOTYPE :    int CLE_GetIndex( T_CLES *tCles, char *chNomCle )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_CLES *tCles           : Tableau de cl� pour le Slot,
//                - char *chNomCle          : Nom de la cl� recherch�,
// ------------------------------------------------------------------------------
// RETOUR :
//                - >=0 = Sortie de fonction normale
//                - < 0 = La cl� n'existe pas.
// ------------------------------------------------------------------------------
// DESRIPTION :   Recherche de l'index d'une cl�. 
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        04/01/2010
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int CLE_GetIndex( T_CLES *tCles, char *chNomCle )
{
    int i;
     
     
    for ( i=0 ; i<tCles->nbCle ; i++ )
    {
        if ( strcmp (tCles->cles[i].nom, chNomCle) == 0 )
            return i;
    }
    
    return -1;
}

// ==============================================================================
// FONCTION :     CLE_Valeur
// ------------------------------------------------------------------------------
// PROTOTYPE :    int CLE_Valeur( T_CLES *tCles, char *chNomCle, char *chValeur )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_CLES *tCles           : Tableau de cl� pour le Slot,
//                - char *chNomCle          : Nom de la cl� recherch�,
//                - char *chValeur          : Valeur de la cl�.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = La cl� n'existe pas.
// ------------------------------------------------------------------------------
// DESRIPTION :   Retourne la valeur d'une cl�. 
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        04/01/2010
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int CLE_Valeur( T_CLES *tCles, char *chNomCle, char **chValeur )
{
    int                 idxCle;
    int                 error = 0;
    char                chMsg[1024];
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[tCles->nItfe].variablesTraca);
    

    // R�cup�ration de l'index de la cl� si elle existe
    // ------------------------------------------------
    if ( (idxCle = CLE_GetIndex (tCles, chNomCle)) == -1 )
        errChk (-2);
    
    // Lecture de la cl� en BDD
    // ------------------------
    if ( tCles->cles[idxCle].Valeur != NULL )
        errChk ( tCles->cles[idxCle].Valeur ( (void*)tCles, idxCle, chValeur) );

Error:
    // =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        // G�n�ration du message d'erreur
        // ------------------------------
        if (error == -2)
            sprintf (chMsg, "Extraction valeur cle <%s> : la cle n'existe pas", chNomCle);
        else
            sprintf (chMsg, "Extraction valeur cle <%s> : aucune valeur extraite", chNomCle);
        FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_ERREUR, chMsg);
        sprintf (ptrVariablesTraca->chLibelleErreur, "Extraction valeur cle <%s> impossible", chNomCle);
        return -1;
    }
    
    return 0;
}

// ==============================================================================
// FONCTION :     CLE_Nettoyage
// ------------------------------------------------------------------------------
// PROTOTYPE :    int CLE_Nettoyage (   T_CLES *tCles,
//                                      char *chNomCle,
//                                      char *strMessageErreur )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_CLES *tCles           : Tableau de cl� pour le Slot,
//                - char *chNomCle          : Nom de la cl� recherch�,
//                - char *strMessageErreur  : Message de l'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = La cl� n'existe pas.
// ------------------------------------------------------------------------------
// DESRIPTION :   Nettoyage d'une cl�. 
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        04/01/2010
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int CLE_Nettoyage ( T_CLES *tCles, char *chNomCle, char *strMessageErreur )
{
    int     idxCle;
    int     error = 0;
    char    chMsg[1024];
    char    *tcomErreur = NULL;
    char    *strErreurRequete = NULL;
    int     erreurSurvenue;
    int     erreurCode;


    // R�cup�ration de l'index de la cl� si elle existe
    // ------------------------------------------------
    if ( (idxCle = CLE_GetIndex (tCles, chNomCle)) == -1 )
        errChk (-2);


    // Affichage dans les traces de la lib�ration de la cl�
    // ----------------------------------------------------
    sprintf (chMsg, "Nettoyage de la cle %s [Table:%s] [ID:%d]", tCles->cles[idxCle].nom, tCles->cles[idxCle].nomTable, (int)tCles->cles[idxCle].id);
    FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMsg);

    // Nettoyage de la cl�
    // -------------------
    TracaCom_FonctionsMDT_FonctionsMDT_NettoyageCle(
        tCles->instTracaCom,
        tCles->cles[idxCle].nomTable,
        tCles->sn,
        tCles->codeProduit,
        tCles->indiceProduit,
        &tCles->cles[idxCle].id,
        &erreurSurvenue, &erreurCode, &tcomErreur, &strErreurRequete, NULL);
    if (erreurSurvenue)
        errChk (-1);

    
Error:
    // =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        // G�n�ration du message d'erreur
        // ------------------------------
        if (error == -2)
            sprintf (strMessageErreur, "Nettoyage cle <%s> : la cle n'existe pas", chNomCle);
        else
        {
            if (tcomErreur!=NULL)
            {
                if ( FCT_STRING_IS_EMPTY(tcomErreur) == FALSE )
                    sprintf (strMessageErreur, "Nettoyage cle <%s> KO : %s", tcomErreur);
                else
                    sprintf (strMessageErreur, "Nettoyage cle <%s> KO", chNomCle);
            }
            else
                sprintf (strMessageErreur, "Nettoyage cle <%s> KO", chNomCle);
        }
        
        // Lib�ration des ressources
        // -------------------------
        if (strErreurRequete!=NULL)
            CDotNetFreeMemory(strErreurRequete);
        if (tcomErreur!=NULL)
            CDotNetFreeMemory(tcomErreur);
        
        return -1;
    }
    
    return 0;
}

// ==============================================================================
// FONCTION :     CLE_Lecture
// ------------------------------------------------------------------------------
// PROTOTYPE :    int CLE_Lecture(  T_CLES *tCles,
//                                  char *chSn,
//                                  char *strMessageErreur  )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_CLES *tCles               : Tableau de cl�s,
//                - char *chSn                  : Num�ro de s�rie du produit,
//                - char *strErreurMessage      : Message de l'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontr� durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Extraction des cl�s perso de la Base de donn�es. 
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        14/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int CLE_Lecture( T_CLES *tCles, char *strMessageErreur)
{
    int                 error = 0;
    int                 idxCle;
    char                chMsg[1024];
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[tCles->nItfe].variablesTraca);

    // ===============================================
    // = RAZ des param�tres de sortie de la fonction =
    // ===============================================
    strMessageErreur[0] = '\0'; 

    // =======================================================
    // = Lecture de toutes les cl�s utilis�es par le produit =
    // =======================================================
    for ( idxCle=0 ; idxCle<tCles->nbCle ; idxCle++ )
    {
        if ( tCles->cles[idxCle].Lecture != NULL )
        {
            // Affichage de la trace du d�but de lecture de la cl�
            // ---------------------------------------------------
            sprintf (chMsg, "Lecture cle %s", tCles->cles[idxCle].nom);
            FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMsg);
            
            // Lecture de la cl� en BDD
            // ------------------------
            errChk ( tCles->cles[idxCle].Lecture ( (void*)tCles, idxCle, strMessageErreur) );
        
            // Affichage de la trace de fin de lecture de la cl�
            // -------------------------------------------------
    
            sprintf (chMsg, "Fin lecture cle %s : OK (ID = %d)", tCles->cles[idxCle].nom, (int)tCles->cles[idxCle].id);
            FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMsg);

            // Rend la main au syst�me entre la lecture de chaque cl�
            // ------------------------------------------------------
            Sleep (50);
        }
    }
    
Error:

    // =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        // Affichage de la trace de fin de lecture de la cl�
        // -------------------------------------------------
        sprintf (chMsg, "Fin lecture cle %s : KO \"%s\"", tCles->cles[idxCle].nom, strMessageErreur);
        FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_ERREUR, chMsg);
        sprintf (ptrVariablesTraca->chLibelleErreur, "Lecture cle %s impossible", tCles->cles[idxCle].nom);
        return -1;
    }
    
    return 0;
}

// ==============================================================================
// FONCTION :     CLE_Ecriture
// ------------------------------------------------------------------------------
// PROTOTYPE :    int CLE_Ecriture( T_CLES *tCles,
//                                  char *strMessageErreur)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_CLES *tCles           : Tableau de cl�s,
//                - char *strErreurMessage  : Message de l'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontr� durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Ecriture des cl�s perso dans la FLASH du d�codeur. 
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        14/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int CLE_Ecriture( T_CLES *tCles, char *strMessageErreur)
{
    int                 error = 0;
    int                 idxCle;
    char                chMsg[1024];
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[tCles->nItfe].variablesTraca);

	// ===============================================
    // = RAZ des param�tres de sortie de la fonction =
    // ===============================================
    strMessageErreur[0] = '\0'; 
    
    // ========================================================
    // = Ecriture de toutes les cl�s utilis�es par le produit =
    // ========================================================
    for ( idxCle=0 ; idxCle<tCles->nbCle ; idxCle++ )
    {
        if (tCles->cles[idxCle].Ecriture != NULL)
        {
            // Affichage de la trace du d�but de l'�criture de la cl�
            // ------------------------------------------------------
            sprintf (chMsg, "Traitement cle %s", tCles->cles[idxCle].nom);
            FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMsg);

            // Ecriture de la cl� dans le produit
            // ----------------------------------
            errChk ( tCles->cles[idxCle].Ecriture ((void*)tCles, idxCle, strMessageErreur) );
        
            // Affichage de la trace de fin de l'�criture de la cl�
            // ----------------------------------------------------
            sprintf (chMsg, "Fin traitement %s : OK", tCles->cles[idxCle].nom);
            FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMsg);

            // Rend la main au syst�me entre l'�criture de chaque cl�
            // ------------------------------------------------------
            Sleep (50);
        }
    }
	
Error:
    // =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        // Affichage de la trace de fin de l'�criture de la cl�
        // ----------------------------------------------------
        sprintf (chMsg, "Fin �criture %s : KO", tCles->cles[idxCle].nom);
        FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_ERREUR, chMsg);
        sprintf (ptrVariablesTraca->chLibelleErreur, "Ecriture cle %s : %s", tCles->cles[idxCle].nom, strMessageErreur);
        return -1;
    }
    
    return 0;
}

// ==============================================================================
// FONCTION :     CLE_Liberation
// ------------------------------------------------------------------------------
// PROTOTYPE :    int CLE_Liberation(   T_CLES *tCles, 
//                                      char *strMessageErreur  )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_CLES *tCles               : Tableau de cl�s,
//                - T_VARIABLES_TRACA *varTraca : Variables de tra�abilit�,
//                - char *strErreurMessage      : Message de l'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontr� durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Lib�ration des cl�s r�serv�es. 
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        14/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int CLE_Liberation( T_CLES *tCles, char *strMessageErreur)
{
    char    *tcomErreur = NULL;
    char    *strErreurRequete = NULL;
    int     erreurSurvenue;
    int     erreurCode;
    int     error = 0;
    int     idxCle;
    char    chMsg[1024];
    

    // ===============================================
    // = RAZ des param�tres de sortie de la fonction =
    // ===============================================
    strMessageErreur[0] = '\0'; 
    
    // ==========================================
    // = Lib�ration des cl�s pour le banc Perso =
    // ==========================================
    for ( idxCle=0 ; idxCle<tCles->nbCle ; idxCle++ )
    {
        if (tCles->cles[idxCle].id > 0)
        {
            // Affichage dans les traces de la lib�ration de la cl�
            // ----------------------------------------------------
            sprintf (chMsg, "Lib�ration de la cle %s [Table:%s - ID:%d]", tCles->cles[idxCle].nom, tCles->cles[idxCle].nomTable, (int)tCles->cles[idxCle].id);
            FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMsg);

            // Lib�ration de la cl�
            // --------------------
            TracaCom_FonctionsMDT_FonctionsMDT_LiberationCle(
                tCles->instTracaCom,
                tCles->cles[idxCle].nomTable,
                tCles->sn,
                tCles->codeProduit,
                tCles->indiceProduit,
                &tCles->cles[idxCle].id,
                &erreurSurvenue, &erreurCode, &tcomErreur, &strErreurRequete, NULL);

            // V�rification des erreurs de la fonction
            // ---------------------------------------
            if(erreurSurvenue)
            {
                errChk(erreurCode);
            }
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
            if ( tcomErreur[0] != '\0' )
            {
                if ( strErreurRequete != NULL )
                {
                    CDotNetFreeMemory(strErreurRequete);
                }
                sprintf (strMessageErreur, "Liberation Cle %s impossible \"%s\"", tCles->cles[idxCle].nom, tcomErreur);
            }
            else
            {
                sprintf (strMessageErreur, "Liberation Cle %s impossible", tCles->cles[idxCle].nom);
            }
            CDotNetFreeMemory(tcomErreur);
        }
        else
        {
            sprintf (strMessageErreur, "Liberation Cle %s impossible", tCles->cles[idxCle].nom);
        }
        return -1;
    }
    
    return 0;
}

// ==============================================================================
// FONCTION :     CLE_Raz
// ------------------------------------------------------------------------------
// PROTOTYPE :    int CLE_Raz ( T_CLES *tCles )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_CLES *tCles       : Tableau de cl�s,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Suppression m�moire des param�tres et des valeurs des cl�s.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        14/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int CLE_Raz( T_CLES *tCles )
{
    int idxCle, idxVal;
    

    // ==========================================================
    // = Supression de toutes les cl�s utilis�es par le produit =
    // ==========================================================
    for ( idxCle=0 ; idxCle<tCles->nbCle ; idxCle++ )
    {
        // Suppression des param�tres (s'ils existent)
        // -------------------------------------------
        if ( tCles->cles[idxCle].parametres != NULL )
        {
            for ( idxVal=0 ; idxVal<tCles->cles[idxCle].nbParametres ; idxVal++ )
            {
                free (tCles->cles[idxCle].parametres[idxVal]);
            }
            free (tCles->cles[idxCle].parametres);
            tCles->cles[idxCle].parametres = NULL;
            tCles->cles[idxCle].nbParametres = 0;
        }
        
        // Suppression des valeurs (si elles existent)
        // -------------------------------------------
        if ( tCles->cles[idxCle].valeurs != NULL )
        {
            for ( idxVal=0 ; idxVal<tCles->cles[idxCle].nbValeurs ; idxVal++ )
            {
                free (tCles->cles[idxCle].valeurs[idxVal]);
            }
            free (tCles->cles[idxCle].valeurs);
            tCles->cles[idxCle].valeurs = NULL;
            tCles->cles[idxCle].nbValeurs = 0;
        }
        
        // RAZ id
        // ------
        tCles->cles[idxCle].id = 0;
    }
    
    return 0;
}

// ==============================================================================
// FONCTION :     CLE_Delete
// ------------------------------------------------------------------------------
// PROTOTYPE :    int CLE_Delete (  T_CLES *tCles )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_CLES *tCles       : Tableau de cl�s,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Suppression m�moire des cl�s.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        14/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int CLE_Delete( T_CLES *tCles )
{
    // ==========================================================
    // = Supression de toutes les cl�s utilis�es par le produit =
    // ==========================================================
    CLE_Raz ( tCles );
    free (tCles->cles);
    tCles->nbCle = 0;
    
    return 0;
}

// ==============================================================================
// FONCTION :     CLE_Print
// ------------------------------------------------------------------------------
// PROTOTYPE :    int CLE_Print( T_CLES *tCles, 
//                               char *strPrint,
//                               int nShowVal,
//                               char *strMessageErreur )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_CLES *tCles           : Tableau de cl�s,
//                - char *strPrint          : Chaine format� pour impression,
//                - int nShowVal            : Flag indiquant si les valeurs 
//                                            doivent �tre affich�s,
//                - char *strErreurMessage  : Message de l'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Formatage pour affichage des cl�s.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        16/11/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int CLE_Print( T_CLES *tCles, char *strPrint, int nShowVal, char *strMessageErreur)
{
    char    chMess[CLE_PRINT_TAILLE_MAX] = {'\0'};
    char    chVal[CLE_PRINT_VAL_TAILLE_MAX] = {'\0'};
    char    chNom[512] = {'\0'};
    int     idxCle;
    

    // ===============================================
    // = RAZ des param�tres de sortie de la fonction =
    // ===============================================
    strPrint[0] = '\0';
    strMessageErreur[0] = '\0'; 

    // =========================================================
    // = Formatage de toutes les cl�s utilis�es par le produit =
    // =========================================================
    for ( idxCle=0 ; idxCle<tCles->nbCle ; idxCle++ )
    {
        // Ajout de la description, l'ID et le nom de la table de la cl� dans la ligne
        // ---------------------------------------------------------------------------
        if ( tCles->cles[idxCle].id == 0 )
            sprintf ( chMess, "%s: %s (Table : %s)%s", CLE_STR_INFO_BLANK, tCles->cles[idxCle].designation, tCles->cles[idxCle].nomTable, CLE_STR_VAL_BLANK );
        else
            sprintf ( chMess, "%s: %s id=%d (Table : %s)%s", CLE_STR_INFO_BLANK, tCles->cles[idxCle].designation, (int)tCles->cles[idxCle].id, tCles->cles[idxCle].nomTable, CLE_STR_VAL_BLANK );

        // Affiche les valeurs de la cl�
        // -----------------------------
        if ( (nShowVal == TRUE) && (tCles->cles[idxCle].Affichage != NULL) )
        {
            tCles->cles[idxCle].Affichage ((void*)tCles, idxCle, chVal);
            FCT_RemplacerTag ( chVal, CLE_PRINT_VAL_TAILLE_MAX-1, "\n", CLE_STR_VAL_BLANK );
            strcat (chMess, chVal);
        }
        
        // Ajout du nom de la cl� dans la ligne
        // ------------------------------------
        sprintf (chNom, "Cl� <%s>", tCles->cles[idxCle].nom);
        strncpy ( chMess, chNom, strlen(chNom) );
		chMess[strlen(chNom)] = '\0';
					
        // Ajout de la ligne dans la chaine de cl�s
        // ----------------------------------------
        strcat ( strPrint, chMess);
    }

    return 0;
}

// ==============================================================================
// FONCTION :     LectureCle
// ------------------------------------------------------------------------------
// PROTOTYPE :    int LectureCle (  void *cle,
//                                  int indexCle,
//                                  char *strMessageErreur,
//                                  int nbParam, 
//                                  ...                     )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - void *cle                   : Cl� perso � lire,
//                - int indexCle                : Index de la cl�,
//                - char *strErreurMessage      : Message de l'erreur,
//                - int nbParam                 : Nombre de param�tre,
//                - ...                         : Param�tres format 'char*'.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontr� durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Lecture des valeurs d'une cl� depuis la base.
//
//                Param�tres Cl� : 
//                  Aucun.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        14/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int LectureCle ( void *cle, int indexCle, char *strMessageErreur, int nbParam, ...)
{
    T_CLES  *ptrCles = (T_CLES*)cle;
    char    *tcomErreur = NULL;
    char    *strErreurRequete = NULL;
    char    *paramsNull[] = {{""}};
    char    **ptrParams = paramsNull;
    int     erreurSurvenue;
    int     erreurCode;
    int     error = 0;
    char    **tabValeursCle;
    int     idxValeur, idxParam;
    va_list list;


    // =======================================================
    // = D�finition des param�tres pour la lecture de la cl� =
    // =======================================================
    
    // Allocation m�moire pour le tableau de param�tres
    // ------------------------------------------------
    ptrCles->cles[indexCle].parametres = (char**) malloc( sizeof(char*) * nbParam);
    ptrCles->cles[indexCle].nbParametres = nbParam; 
    
    // Extraction et enregistrement des param�tres
    // -------------------------------------------
    va_start (list, nbParam);
    for ( idxParam=0 ; idxParam<nbParam ; idxParam++ )
    {
        // Allocation m�moire du param�tre
        // -------------------------------
        ptrCles->cles[indexCle].parametres[idxParam] = (char*) malloc( sizeof(char) * CLE_PARAM_TAILLE_MAX );
        strcpy (ptrCles->cles[indexCle].parametres[idxParam], va_arg (list, char*));
        ptrParams = ptrCles->cles[indexCle].parametres;
    }                        
    va_end (list);
    
    // Prise cl�s en BDD avec lock
    // ---------------------------
    CmtGetLock (IdLockCle);
    
    // ========================================================
    // = Extraction des valeurs des cl�s perso depuis la base =
    // ========================================================
    TracaCom_FonctionsMDT_FonctionsMDT_RecuperationCle(
        ptrCles->instTracaCom,
        ptrCles->cles[indexCle].nomTable,
        ptrCles->sn,
        ptrCles->codeProduit,
        ptrCles->indiceProduit,
        ptrParams,
        ptrCles->cles[indexCle].nbParametres,
        &tabValeursCle,
        &ptrCles->cles[indexCle].nbValeurs,
        &erreurSurvenue, &erreurCode, &tcomErreur, &strErreurRequete, NULL);
    
    // Lib�ration S�maphore
    // --------------------
    CmtReleaseLock (IdLockCle);

    // V�rification des erreurs de la fonction
    // ---------------------------------------
    if(erreurSurvenue)
    {
        errChk(erreurCode);
    }

    // ========================================
    // = Enregistrement des valeurs de la cl� =
    // ========================================
    
    // Allocation m�moire des valeurs
    // ------------------------------
    ptrCles->cles[indexCle].valeurs = (char**) malloc( sizeof(char*) * ptrCles->cles[indexCle].nbValeurs);
    
    for ( idxValeur=0 ; idxValeur<ptrCles->cles[indexCle].nbValeurs ; idxValeur++ )
    {
        // Allocation m�moire de la valeur
        // -------------------------------
        ptrCles->cles[indexCle].valeurs[idxValeur] = (char*) malloc( sizeof(char) * (strlen(tabValeursCle[idxValeur]) + 1) );
        
        // Copie de la valeur
        // ------------------
        strcpy (ptrCles->cles[indexCle].valeurs[idxValeur], tabValeursCle[idxValeur]);
    }
    
    // Enregistrement de l'ID de la cl�
    // --------------------------------
    ptrCles->cles[indexCle].id = (__int64)atoi(ptrCles->cles[indexCle].valeurs[CLE_IDX_VAL_ID_CLE]);
    
    // V�rification de la validit� de l'ID de la cl�
    // ---------------------------------------------
    if (ptrCles->cles[indexCle].id == 0)
    {
        sprintf ( strMessageErreur, "Plus de cle disponible." );
        errChk (-1);
    }
    
Error:
    
    // Lib�ration des ressources
    // -------------------------
    CDotNetFreeMemory(tabValeursCle);
    
    // =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if ( tcomErreur != NULL )
        {   
            if ( tcomErreur[0] != '\0' )
            {
                if ( strErreurRequete != NULL )
                {
                    if ( strErreurRequete[0] != '\0' )
                        sprintf (strMessageErreur, "%s\n%s", tcomErreur, strErreurRequete);
                    else
                        strcpy (strMessageErreur, tcomErreur);
                }
                else
                    strcpy (strMessageErreur, tcomErreur);
            }
            CDotNetFreeMemory(tcomErreur);
            if ( strErreurRequete != NULL )
                CDotNetFreeMemory(strErreurRequete);
        }
        return -1;
    }   
    
    return 0;
}

// ==============================================================================
// FONCTION :     CLE_RechercherIndiceCle
// ------------------------------------------------------------------------------
// PROTOTYPE :    int CLE_RechercherIndiceCle( T_CLES *tCles,
//                                  char *strMessageErreur)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_CLES *tCles           : Tableau de cl�s,
//				  - char *strNomCle       	: Nom de la cl�
//                - char *strErreurMessage  : Message de l'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//				  - int idxCle            	: Index de la cl� dans le tableau,
// ------------------------------------------------------------------------------
// DESRIPTION :   Recherche de l'indice d'une cl� � partir du nom de la table 
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     VS08012BA15
//  DATE :        26/04/2010
//  AUTEUR :      MBH
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int CLE_RechercherIndiceCle( T_CLES *tCles, char *strNomCle, char *strMessageErreur)
{
    int                 error = 0;
    char                chMsg[1024];
    int 				idxCle; 
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[tCles->nItfe].variablesTraca);  
	//T_CLES      		*ptrCles = (T_CLES*)tCles;

    // ===============================================
    // = RAZ des param�tres de sortie de la fonction =
    // ===============================================
    strMessageErreur[0] = '\0'; 
    
    // ========================================================
    // = Ecriture de toutes les cl�s utilis�es par le produit =
    // ========================================================
    idxCle = 0;
	while ( idxCle < tCles->nbCle )
    {
		if ( strcmp(tCles->cles[idxCle].nom, strNomCle) == 0 )
		{
			// ===================================
			// = On trouve bien des cl�s qui correspondent � ce nom = 
			// ===================================
			break;
		}
		else
			idxCle++;
    }
	if (idxCle == tCles->nbCle)
	{
        sprintf ( strMessageErreur, "Pas de cl� configur�e corresponant � ce nom de table" );
        errChk (-1);
	}
	
Error:
    // =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        // Affichage de la trace de fin de l'�criture de la cl�
        // ----------------------------------------------------
        sprintf (chMsg, "Recherche de l'indice d'une cl� : KO");
        FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_ERREUR, chMsg);
        sprintf (ptrVariablesTraca->chLibelleErreur, "Recherche de l'indice d'une cl� : KO : %s", strMessageErreur);
        return -1;
    }
    
    return idxCle;
}


// ==============================================================================
// FONCTION :     CLE_TxtFileCle
// ------------------------------------------------------------------------------
// PROTOTYPE :    int CLE_TxtFileCle(char *chNomFichierTxt, 
//                                  char *chbuffer) 
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - char *chNomFichierTxt  	: Nom du fichier TXT,
//                - char *chbuffer   		: Chaine de caract�re � �crire,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontr� durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :  Ecriture du fichier TXT
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S08012BA27
//  DATE :        11/10/2010
//  AUTEUR :      GCX (APSIDE)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int CLE_TxtFileCle ( void *cle, int indexCle, char *CharCmdTT, char *charBufferLu)
{
	
#ifdef	DEBUGTRACE 	
	FILE	*file_handle; 
	char    chBuff[TAILLE_MAX] = {"\0"};
	char    chNomFichierCleTxt[12] = {"\0"};
	T_CLES  *ptrCles = (T_CLES*)cle; 

	
	sprintf(chNomFichierCleTxt,"%s_%d.txt","Cles",ptrCles->nItfe);   

	file_handle = fopen (chNomFichierCleTxt, "a");
	
	// Ecriture du Nom de la Cl�
	// -------------------------
	sprintf(chBuff, "==========%s==========\n\n", ptrCles->cles[indexCle].nom);
    fwrite(chBuff, 1,strlen(chBuff) , file_handle);	
		
	// Ecriture de la CmdTT
	// --------------------
	sprintf(chBuff, "%s\n\n", CharCmdTT);
    fwrite(chBuff, 1,strlen(chBuff) , file_handle);
	
	// Ecriture de la R�ponse
	// ----------------------
	sprintf(chBuff, "%s\n\n", charBufferLu);
	fwrite(chBuff, 1,strlen(chBuff) , file_handle);

    fclose (file_handle);
#endif	
	
	return 0;
}

// ------------------------------------------------------------------------------
// FONCTIONS SPECIFIQUES DE LECTURE DE CLE
// ------------------------------------------------------------------------------

// ==============================================================================
// FONCTION : 	  LectureCleHddPass
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int LectureCleHddPass(void *cle,
//										int indexCle, 
//										char *strMessageErreur		)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - void *cle					: Tableau des cl�s perso � lire,
//				  - int indexCle				: Index de la cl� dans le tableau,
//				  - char *strErreurMessage		: Message de l'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontr� durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Lecture des valeurs d'une cl� depuis la base.
//
//				  Param�tres Cl� HDD : 
//					AUCUN
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  14/09/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  
//  DATE :		  
//  AUTEUR :	  
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int LectureCleHddPass( void *cle, int indexCle, char *strMessageErreur)
{
	// =====================
	// = Lecture de la cl� =
	// =====================
	return LectureCle ( cle, indexCle, strMessageErreur, 0 );
}

// ==============================================================================
// FONCTION :     AffichageCleHddPass
// ------------------------------------------------------------------------------
// PROTOTYPE :    int AffichageCleHddPass(  void *cle,
//                                          int indexCle, 
//                                          char *strPrint  )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - void *cle       : Tableau des cl�s perso � lire,
//                - int indexCle    : Index de la cl� dans le tableau,
//                - char *strPrint  : Valeur � afficher.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontr� durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :
//
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        15/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int AffichageCleHddPass ( void *cle, int indexCle, char *strPrint)
{
    sprintf (strPrint, "");
    return 0;
}

// ==============================================================================
// FONCTION :     ValeurCleHddPass
// ------------------------------------------------------------------------------
// PROTOTYPE :    int ValeurCleHddPass( void *cle,
//                                      int indexCle, 
//                                      char *strValeur )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - void *cle       : Tableau des cl�s perso � lire,
//                - int indexCle    : Index de la cl� dans le tableau,
//                - char *strValeur : Valeur de la cl�.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontr� durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Extraction de la Cl� Hdd Password.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        15/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int ValeurCleHddPass( void *cle, int indexCle, char **strValeur)
{
    T_CLES  *ptrCles = (T_CLES*)cle;

    if (ptrCles->cles[indexCle].valeurs != NULL)
    {
        if (ptrCles->cles[indexCle].nbValeurs > CLE_PASSWORD_IDX_VAL_VAL)
            *strValeur = ptrCles->cles[indexCle].valeurs[CLE_PASSWORD_IDX_VAL_VAL];
        else
            *strValeur = NULL;
    }
    else
    {
        *strValeur = NULL;
    }
        
    return 0;
}

// ------------------------------------------------------------------------------
// FONCTIONS SPECIFIQUES D'ECRITURE DE CLE
// ------------------------------------------------------------------------------

// ==============================================================================
// FONCTION : 	  EcritureHddPass
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int EcritureHddPass(	void *cle,
//										int indexCle, 
//										char *strMessageErreur	)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - void *cle				: Tableau des cl�s perso � lire,
//				  - int indexCle			: Index de la cl� dans le tableau,
//				  - char *strErreurMessage	: Message de l'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontr� durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Ecriture du password HDD.
//
//				  Valeurs Cl� HDCP : 
//					indice[0] -> champ id_stbpassword.
//					indice[1] -> champ id_numserie.
//					indice[2] -> champ stbpassword.
//					indice[3] -> champ utilisee.
//					indice[4] -> champ utilisateur.
//					indice[5] -> champ datecreation.
//					indice[6] -> champ datemaj.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  15/09/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Cr�ation.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  
//  DATE :		  
//  AUTEUR :	  
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int EcritureCleHddPass (void *cle, int indexCle, char *strMessageErreur)
{
	T_CLES				*ptrCles = (T_CLES*)cle;
	T_VARIABLES_TRACA	*ptrVariablesTraca = &(gSlot[ptrCles->nItfe].variablesTraca);
	int					nPassLen;
	int					ii;

	
	ptrVariablesTraca->bPwd[0] = '\0';
	nPassLen = strlen (ptrCles->cles[indexCle].valeurs[CLE_PASSWORD_IDX_VAL_VAL]);
	for (ii = 0; ii <nPassLen; ii++)
	{
		Fmt (ptrVariablesTraca->bPwd, "%s[a]<%x", ptrCles->cles[indexCle].valeurs[CLE_PASSWORD_IDX_VAL_VAL][ii]);
	}
	
	return 0;
}
