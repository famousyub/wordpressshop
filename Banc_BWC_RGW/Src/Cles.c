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
//   DESCRIPTION    : Gestion des clés du décodeur.
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
//      >>>  Création
// ==============================================================================

// ==============================================================================
// INCLUDE
// ==============================================================================

#include "Include.h"


// ==============================================================================
// PROTOTYPES DES FONCTIONS LOCALES
// ==============================================================================

// Prototypes des fonctions de lecture des clés
// --------------------------------------------
int LectureCle ( void *cle, int indexCle, char *strMessageErreur, int nbParam, ...);
int LectureCleHddPass ( void *cle, int indexCle, char *strMessageErreur);

// Prototypes des fonctions d'écriture des clés
// --------------------------------------------
int EcritureCleHddPass ( void *cle, int indexCle, char *strMessageErreur);

// Prototypes des fonctions d'affichage des valeurs des clés
// ---------------------------------------------------------
int AffichageCleHddPass         ( void *cle, int indexCle, char *strPrint);

// Prototypes des fonctions d'extraction des valeurs des clés
// ----------------------------------------------------------
int ValeurCleHddPass            ( void *cle, int indexCle, char **strValeur);

// ==============================================================================
// DECLARATION DES VARIABLES GLOBALES
// ==============================================================================

// Définition des clés perso pour le banc Perso
// --------------------------------------------
T_CLE gTCles[] =

//  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// |        NOM         | NOM TABLE | DESCRIPTION | QUANTITE | PARAMETRES | NB PARAMETRES | VALEURS 	| NB VALEURS | ID |   NAGRA |  		FCT LECTURE         |       FCT ECRITURE        |       FCT AFFICHAGE       |       	FCT VALEUR     	|
//  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{
 {    "stbpasswords16",         "",         "",         1,      NULL,			0,          NULL, 				0,      0,  	0,	 	LectureCleHddPass,			EcritureCleHddPass,		                       AffichageCleHddPass,            ValeurCleHddPass	},
};

// --------------
// Nombre de clés
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
//                - T_CLES *tCles           : Tableau de clé pour le Slot,
//                - hdleTCom instTracaCom   : Handle sur la base TracaCom,
//                - char *codeProduit       : Code produit,
//                - char *indiceProduit     : Indice produit,
//                - int nItfe               : Index Slot,
//                - int idPort              : Index COM STB,
//                - char *strErreurMessage  : Message de l'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Extraction de la Base de données des clés perso utilisées 
//                pour le produit courant 
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        14/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
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
    // = RAZ des paramètres de sortie de la fonction =
    // ===============================================
    strMessageErreur[0] = '\0'; 
    
    // ==========================
    // = RAZ du tableau de clés =
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
    // = Extraction des clés perso utilisées pour le produit =
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
    
    // Vérification des erreurs de la fonction
    // ---------------------------------------
    if(erreurSurvenue)
    {
        errChk(erreurCode);
    }

    // ==========================================
    // = Extraction des clés pour le banc Perso =
    // ==========================================
    for ( idxCleOut=0 ; idxCleOut<gNbCles ; idxCleOut++ )
    {
        for ( idxCleIn=0 ; idxCleIn<tabClesLen1 ; idxCleIn++ )
        {
            if ( strcmp (gTCles[idxCleOut].nom, tabCles[idxCleIn*tabClesLen2]) == 0 )
            {
                // On incrémente le nombre de clés utilisées
                // -----------------------------------------
                tCles->nbCle++;
            
                // Allocation mémoire pour la nouvelle clé
                // ---------------------------------------
                tCles->cles = (T_CLE *) realloc (tCles->cles, sizeof(T_CLE) * tCles->nbCle);
            
                // Extraction du nom de la table où est défini la clé
                // --------------------------------------------------
                strcpy ( tCles->cles[tCles->nbCle-1].nomTable, tabCles[(idxCleIn*tabClesLen2)+1] );
            
                // Extraction de la désignation de la clé
                // --------------------------------------
                strcpy ( tCles->cles[tCles->nbCle-1].designation, tabCles[(idxCleIn*tabClesLen2)+2] );

                // Extraction de la quantité des valeurs de la clé
                // -----------------------------------------------
                tCles->cles[tCles->nbCle-1].quantite = atoi (tabCles[(idxCleIn*tabClesLen2)+3]);
                
                // MAJ du nom de la clé
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
				
				// MAJ du paramètre Nagra
                // ----------------------
                tCles->cles[tCles->nbCle-1].iNagra = gTCles[idxCleOut].iNagra;

                // MAJ de la fonction d'écriture
                // -----------------------------
                tCles->cles[tCles->nbCle-1].Ecriture = gTCles[idxCleOut].Ecriture;

                // MAJ de la fonction de lecture
                // -----------------------------
                tCles->cles[tCles->nbCle-1].Lecture = gTCles[idxCleOut].Lecture;

                // MAJ de la fonction d'affichage
                // ------------------------------
                tCles->cles[tCles->nbCle-1].Affichage = gTCles[idxCleOut].Affichage;
                
                // MAJ de la fonction d'extraction de la valeur de la clé
                // ------------------------------------------------------
                tCles->cles[tCles->nbCle-1].Valeur = gTCles[idxCleOut].Valeur;

                break;
            }
        }
    }
    
Error:
    // Libération des ressources
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

        // Libération des ressources
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
//                - T_CLES *tCles           : Tableau de clé pour le Slot,
//                - char *chNomCle          : Nom de la clé recherché,
// ------------------------------------------------------------------------------
// RETOUR :
//                - >=0 = Sortie de fonction normale
//                - < 0 = La clé n'existe pas.
// ------------------------------------------------------------------------------
// DESRIPTION :   Recherche de l'index d'une clé. 
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        04/01/2010
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
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
//                - T_CLES *tCles           : Tableau de clé pour le Slot,
//                - char *chNomCle          : Nom de la clé recherché,
//                - char *chValeur          : Valeur de la clé.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = La clé n'existe pas.
// ------------------------------------------------------------------------------
// DESRIPTION :   Retourne la valeur d'une clé. 
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        04/01/2010
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
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
    

    // Récupération de l'index de la clé si elle existe
    // ------------------------------------------------
    if ( (idxCle = CLE_GetIndex (tCles, chNomCle)) == -1 )
        errChk (-2);
    
    // Lecture de la clé en BDD
    // ------------------------
    if ( tCles->cles[idxCle].Valeur != NULL )
        errChk ( tCles->cles[idxCle].Valeur ( (void*)tCles, idxCle, chValeur) );

Error:
    // =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        // Génération du message d'erreur
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
//                - T_CLES *tCles           : Tableau de clé pour le Slot,
//                - char *chNomCle          : Nom de la clé recherché,
//                - char *strMessageErreur  : Message de l'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = La clé n'existe pas.
// ------------------------------------------------------------------------------
// DESRIPTION :   Nettoyage d'une clé. 
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        04/01/2010
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
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


    // Récupération de l'index de la clé si elle existe
    // ------------------------------------------------
    if ( (idxCle = CLE_GetIndex (tCles, chNomCle)) == -1 )
        errChk (-2);


    // Affichage dans les traces de la libération de la clé
    // ----------------------------------------------------
    sprintf (chMsg, "Nettoyage de la cle %s [Table:%s] [ID:%d]", tCles->cles[idxCle].nom, tCles->cles[idxCle].nomTable, (int)tCles->cles[idxCle].id);
    FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMsg);

    // Nettoyage de la clé
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
        // Génération du message d'erreur
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
        
        // Libération des ressources
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
//                - T_CLES *tCles               : Tableau de clés,
//                - char *chSn                  : Numéro de série du produit,
//                - char *strErreurMessage      : Message de l'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Extraction des clés perso de la Base de données. 
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        14/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
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
    // = RAZ des paramètres de sortie de la fonction =
    // ===============================================
    strMessageErreur[0] = '\0'; 

    // =======================================================
    // = Lecture de toutes les clés utilisées par le produit =
    // =======================================================
    for ( idxCle=0 ; idxCle<tCles->nbCle ; idxCle++ )
    {
        if ( tCles->cles[idxCle].Lecture != NULL )
        {
            // Affichage de la trace du début de lecture de la clé
            // ---------------------------------------------------
            sprintf (chMsg, "Lecture cle %s", tCles->cles[idxCle].nom);
            FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMsg);
            
            // Lecture de la clé en BDD
            // ------------------------
            errChk ( tCles->cles[idxCle].Lecture ( (void*)tCles, idxCle, strMessageErreur) );
        
            // Affichage de la trace de fin de lecture de la clé
            // -------------------------------------------------
    
            sprintf (chMsg, "Fin lecture cle %s : OK (ID = %d)", tCles->cles[idxCle].nom, (int)tCles->cles[idxCle].id);
            FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMsg);

            // Rend la main au système entre la lecture de chaque clé
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
        // Affichage de la trace de fin de lecture de la clé
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
//                - T_CLES *tCles           : Tableau de clés,
//                - char *strErreurMessage  : Message de l'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Ecriture des clés perso dans la FLASH du décodeur. 
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        14/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
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
    // = RAZ des paramètres de sortie de la fonction =
    // ===============================================
    strMessageErreur[0] = '\0'; 
    
    // ========================================================
    // = Ecriture de toutes les clés utilisées par le produit =
    // ========================================================
    for ( idxCle=0 ; idxCle<tCles->nbCle ; idxCle++ )
    {
        if (tCles->cles[idxCle].Ecriture != NULL)
        {
            // Affichage de la trace du début de l'écriture de la clé
            // ------------------------------------------------------
            sprintf (chMsg, "Traitement cle %s", tCles->cles[idxCle].nom);
            FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMsg);

            // Ecriture de la clé dans le produit
            // ----------------------------------
            errChk ( tCles->cles[idxCle].Ecriture ((void*)tCles, idxCle, strMessageErreur) );
        
            // Affichage de la trace de fin de l'écriture de la clé
            // ----------------------------------------------------
            sprintf (chMsg, "Fin traitement %s : OK", tCles->cles[idxCle].nom);
            FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMsg);

            // Rend la main au système entre l'écriture de chaque clé
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
        // Affichage de la trace de fin de l'écriture de la clé
        // ----------------------------------------------------
        sprintf (chMsg, "Fin écriture %s : KO", tCles->cles[idxCle].nom);
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
//                - T_CLES *tCles               : Tableau de clés,
//                - T_VARIABLES_TRACA *varTraca : Variables de traçabilité,
//                - char *strErreurMessage      : Message de l'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Libération des clés réservées. 
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        14/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
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
    // = RAZ des paramètres de sortie de la fonction =
    // ===============================================
    strMessageErreur[0] = '\0'; 
    
    // ==========================================
    // = Libération des clés pour le banc Perso =
    // ==========================================
    for ( idxCle=0 ; idxCle<tCles->nbCle ; idxCle++ )
    {
        if (tCles->cles[idxCle].id > 0)
        {
            // Affichage dans les traces de la libération de la clé
            // ----------------------------------------------------
            sprintf (chMsg, "Libération de la cle %s [Table:%s - ID:%d]", tCles->cles[idxCle].nom, tCles->cles[idxCle].nomTable, (int)tCles->cles[idxCle].id);
            FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMsg);

            // Libération de la clé
            // --------------------
            TracaCom_FonctionsMDT_FonctionsMDT_LiberationCle(
                tCles->instTracaCom,
                tCles->cles[idxCle].nomTable,
                tCles->sn,
                tCles->codeProduit,
                tCles->indiceProduit,
                &tCles->cles[idxCle].id,
                &erreurSurvenue, &erreurCode, &tcomErreur, &strErreurRequete, NULL);

            // Vérification des erreurs de la fonction
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
//                - T_CLES *tCles       : Tableau de clés,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Suppression mémoire des paramètres et des valeurs des clés.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        14/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
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
    // = Supression de toutes les clés utilisées par le produit =
    // ==========================================================
    for ( idxCle=0 ; idxCle<tCles->nbCle ; idxCle++ )
    {
        // Suppression des paramètres (s'ils existent)
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
//                - T_CLES *tCles       : Tableau de clés,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Suppression mémoire des clés.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        14/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
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
    // = Supression de toutes les clés utilisées par le produit =
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
//                - T_CLES *tCles           : Tableau de clés,
//                - char *strPrint          : Chaine formaté pour impression,
//                - int nShowVal            : Flag indiquant si les valeurs 
//                                            doivent être affichés,
//                - char *strErreurMessage  : Message de l'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Formatage pour affichage des clés.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        16/11/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
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
    // = RAZ des paramètres de sortie de la fonction =
    // ===============================================
    strPrint[0] = '\0';
    strMessageErreur[0] = '\0'; 

    // =========================================================
    // = Formatage de toutes les clés utilisées par le produit =
    // =========================================================
    for ( idxCle=0 ; idxCle<tCles->nbCle ; idxCle++ )
    {
        // Ajout de la description, l'ID et le nom de la table de la clé dans la ligne
        // ---------------------------------------------------------------------------
        if ( tCles->cles[idxCle].id == 0 )
            sprintf ( chMess, "%s: %s (Table : %s)%s", CLE_STR_INFO_BLANK, tCles->cles[idxCle].designation, tCles->cles[idxCle].nomTable, CLE_STR_VAL_BLANK );
        else
            sprintf ( chMess, "%s: %s id=%d (Table : %s)%s", CLE_STR_INFO_BLANK, tCles->cles[idxCle].designation, (int)tCles->cles[idxCle].id, tCles->cles[idxCle].nomTable, CLE_STR_VAL_BLANK );

        // Affiche les valeurs de la clé
        // -----------------------------
        if ( (nShowVal == TRUE) && (tCles->cles[idxCle].Affichage != NULL) )
        {
            tCles->cles[idxCle].Affichage ((void*)tCles, idxCle, chVal);
            FCT_RemplacerTag ( chVal, CLE_PRINT_VAL_TAILLE_MAX-1, "\n", CLE_STR_VAL_BLANK );
            strcat (chMess, chVal);
        }
        
        // Ajout du nom de la clé dans la ligne
        // ------------------------------------
        sprintf (chNom, "Clé <%s>", tCles->cles[idxCle].nom);
        strncpy ( chMess, chNom, strlen(chNom) );
		chMess[strlen(chNom)] = '\0';
					
        // Ajout de la ligne dans la chaine de clés
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
//                - void *cle                   : Clé perso à lire,
//                - int indexCle                : Index de la clé,
//                - char *strErreurMessage      : Message de l'erreur,
//                - int nbParam                 : Nombre de paramètre,
//                - ...                         : Paramètres format 'char*'.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Lecture des valeurs d'une clé depuis la base.
//
//                Paramètres Clé : 
//                  Aucun.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        14/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
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
    // = Définition des paramètres pour la lecture de la clé =
    // =======================================================
    
    // Allocation mémoire pour le tableau de paramètres
    // ------------------------------------------------
    ptrCles->cles[indexCle].parametres = (char**) malloc( sizeof(char*) * nbParam);
    ptrCles->cles[indexCle].nbParametres = nbParam; 
    
    // Extraction et enregistrement des paramètres
    // -------------------------------------------
    va_start (list, nbParam);
    for ( idxParam=0 ; idxParam<nbParam ; idxParam++ )
    {
        // Allocation mémoire du paramètre
        // -------------------------------
        ptrCles->cles[indexCle].parametres[idxParam] = (char*) malloc( sizeof(char) * CLE_PARAM_TAILLE_MAX );
        strcpy (ptrCles->cles[indexCle].parametres[idxParam], va_arg (list, char*));
        ptrParams = ptrCles->cles[indexCle].parametres;
    }                        
    va_end (list);
    
    // Prise clés en BDD avec lock
    // ---------------------------
    CmtGetLock (IdLockCle);
    
    // ========================================================
    // = Extraction des valeurs des clés perso depuis la base =
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
    
    // Libération Sémaphore
    // --------------------
    CmtReleaseLock (IdLockCle);

    // Vérification des erreurs de la fonction
    // ---------------------------------------
    if(erreurSurvenue)
    {
        errChk(erreurCode);
    }

    // ========================================
    // = Enregistrement des valeurs de la clé =
    // ========================================
    
    // Allocation mémoire des valeurs
    // ------------------------------
    ptrCles->cles[indexCle].valeurs = (char**) malloc( sizeof(char*) * ptrCles->cles[indexCle].nbValeurs);
    
    for ( idxValeur=0 ; idxValeur<ptrCles->cles[indexCle].nbValeurs ; idxValeur++ )
    {
        // Allocation mémoire de la valeur
        // -------------------------------
        ptrCles->cles[indexCle].valeurs[idxValeur] = (char*) malloc( sizeof(char) * (strlen(tabValeursCle[idxValeur]) + 1) );
        
        // Copie de la valeur
        // ------------------
        strcpy (ptrCles->cles[indexCle].valeurs[idxValeur], tabValeursCle[idxValeur]);
    }
    
    // Enregistrement de l'ID de la clé
    // --------------------------------
    ptrCles->cles[indexCle].id = (__int64)atoi(ptrCles->cles[indexCle].valeurs[CLE_IDX_VAL_ID_CLE]);
    
    // Vérification de la validité de l'ID de la clé
    // ---------------------------------------------
    if (ptrCles->cles[indexCle].id == 0)
    {
        sprintf ( strMessageErreur, "Plus de cle disponible." );
        errChk (-1);
    }
    
Error:
    
    // Libération des ressources
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
//                - T_CLES *tCles           : Tableau de clés,
//				  - char *strNomCle       	: Nom de la clé
//                - char *strErreurMessage  : Message de l'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//				  - int idxCle            	: Index de la clé dans le tableau,
// ------------------------------------------------------------------------------
// DESRIPTION :   Recherche de l'indice d'une clé à partir du nom de la table 
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     VS08012BA15
//  DATE :        26/04/2010
//  AUTEUR :      MBH
//  DESCRIPTION : Création.
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
    // = RAZ des paramètres de sortie de la fonction =
    // ===============================================
    strMessageErreur[0] = '\0'; 
    
    // ========================================================
    // = Ecriture de toutes les clés utilisées par le produit =
    // ========================================================
    idxCle = 0;
	while ( idxCle < tCles->nbCle )
    {
		if ( strcmp(tCles->cles[idxCle].nom, strNomCle) == 0 )
		{
			// ===================================
			// = On trouve bien des clés qui correspondent à ce nom = 
			// ===================================
			break;
		}
		else
			idxCle++;
    }
	if (idxCle == tCles->nbCle)
	{
        sprintf ( strMessageErreur, "Pas de clé configurée corresponant à ce nom de table" );
        errChk (-1);
	}
	
Error:
    // =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        // Affichage de la trace de fin de l'écriture de la clé
        // ----------------------------------------------------
        sprintf (chMsg, "Recherche de l'indice d'une clé : KO");
        FCT_AfficheInfo (tCles->nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_ERREUR, chMsg);
        sprintf (ptrVariablesTraca->chLibelleErreur, "Recherche de l'indice d'une clé : KO : %s", strMessageErreur);
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
//                - char *chbuffer   		: Chaine de caractère à écrire,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :  Ecriture du fichier TXT
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S08012BA27
//  DATE :        11/10/2010
//  AUTEUR :      GCX (APSIDE)
//  DESCRIPTION : Création.
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
	
	// Ecriture du Nom de la Clé
	// -------------------------
	sprintf(chBuff, "==========%s==========\n\n", ptrCles->cles[indexCle].nom);
    fwrite(chBuff, 1,strlen(chBuff) , file_handle);	
		
	// Ecriture de la CmdTT
	// --------------------
	sprintf(chBuff, "%s\n\n", CharCmdTT);
    fwrite(chBuff, 1,strlen(chBuff) , file_handle);
	
	// Ecriture de la Réponse
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
//				  - void *cle					: Tableau des clés perso à lire,
//				  - int indexCle				: Index de la clé dans le tableau,
//				  - char *strErreurMessage		: Message de l'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Lecture des valeurs d'une clé depuis la base.
//
//				  Paramètres Clé HDD : 
//					AUCUN
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  14/09/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
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
	// = Lecture de la clé =
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
//                - void *cle       : Tableau des clés perso à lire,
//                - int indexCle    : Index de la clé dans le tableau,
//                - char *strPrint  : Valeur à afficher.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
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
//  DESCRIPTION : Création.
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
//                - void *cle       : Tableau des clés perso à lire,
//                - int indexCle    : Index de la clé dans le tableau,
//                - char *strValeur : Valeur de la clé.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Extraction de la Clé Hdd Password.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        15/09/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
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
//				  - void *cle				: Tableau des clés perso à lire,
//				  - int indexCle			: Index de la clé dans le tableau,
//				  - char *strErreurMessage	: Message de l'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Ecriture du password HDD.
//
//				  Valeurs Clé HDCP : 
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
//  DESCRIPTION : Création.
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
