// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//  
// 
// ==============================================================================
//   PROJET         : Banc Personnalisation
//   MODULE         : TracaCom
//   PROCESSEUR     : INTEL Pentium
//   ENVIRONNEMENT  : Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION    : Gestion de la base TracaCom.
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
// 13-Octobre-2009  NCR (DT2E)
//      >>>  Création
// ==============================================================================


// ==============================================================================
// INCLUDE
// ==============================================================================

#include "Include.h"


// ==============================================================================
// DECLARATION DES VARIABLES GLOBALES
// ==============================================================================


// ==============================================================================
// DECLARATION DES FONCTIONS
// ==============================================================================

// ==============================================================================
// FONCTION :     TCOM_Connexion
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_Connexion (  T_TCOM_BASE *tcomBase ) 
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Connexion et Configuration de la Base de données. 
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
int TCOM_Connexion ( T_TCOM_BASE *tcomBase )
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
    
    
    // ==========================================
    // = Initialisation du controlleur CVI .NET =
    // ==========================================
    Initialize_TracaCom ();
    
    // =======================
    // = Création de l'objet =
    // =======================
    TracaCom_FonctionsMDT_FonctionsMDT__Create(&tcomBase->instTracaCom, 0);
    
    // =================================
    // = Connexion à la base de donnée =   (Dinan)
    // =================================

	if ( gConnexionDinan )
	{
		TracaCom_FonctionsMDT_FonctionsMDT_ConfigurationBaseDyn(
        tcomBase->instTracaCom,
        tcomBase->nomServeur,
        tcomBase->portServeur,
        tcomBase->loginServeur,
        tcomBase->passServeur,
        tcomBase->nomBase,
		gPosteInfos.chNom,
		0,
		&errorOccured, 
		&errorCode, 
		&errorMsg, 
		NULL);
	}
	else
	{
    // =================================
    // = Connexion à la base de donnée =   (BYO et STC)
    // =================================
	TracaCom_FonctionsMDT_FonctionsMDT_ConfigurationBase(
        tcomBase->instTracaCom,
        tcomBase->nomServeur,
        tcomBase->portServeur,
        tcomBase->nomBase,
        tcomBase->loginServeur,
        gPosteInfos.chNom,		 //nom du poste
		0,						 //active debug
        &errorOccured, 
		&errorCode, 
		&errorMsg, 
		&errorRequete,
		NULL); 
	/*
	SCProduction_GestionProductions_ConfigurationBase(
        tcomBase->instTracaCom,
        "configbase.txt",
		&errorCode, 
		&errorMsg, 
		NULL);   */
	}
    
    if (errorOccured == TRUE)
    {
        // Libération des ressources
        // -------------------------
        if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        return errorCode;
    }
    else
        return 0;
}

// ==============================================================================
// FONCTION :     TCOM_Deconnexion
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_Deconnexion ( T_TCOM_BASE *tcomBase )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Deconnexion de la Base de données.
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
int TCOM_Deconnexion ( T_TCOM_BASE *tcomBase )
{
    // =====================================
    // = Fermeture du controlleur CVI .NET =
    // =====================================
    Close_TracaCom ();
    
    return 0;
}

// ==============================================================================
// FONCTION :     TCOM_PosteInformations
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_PosteInformations (  T_TCOM_BASE *tcomBase, 
//                                              T_POSTE_INFOS *posteInfos, 
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base.
//                - T_POSTE_INFOS *posteInfos   : Informations sur le poste.
//                - char *strErreurMessage      : Message d'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Extractions des informations sur le poste.
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
int TCOM_PosteInformations ( T_TCOM_BASE *tcomBase, T_POSTE_INFOS *posteInfos, char *strErreurMessage )
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
    char    *typePoste = NULL;
    char    *chLibelleLigne = NULL;
    char    *chDescriptionLigne = NULL;
    int     error = 0;

    
    // ===============================
    // = Extraction du type du poste =
    // ===============================
    TracaCom_FonctionsMDT_FonctionsMDT_RecuperationLigneProductionParPoste(
        tcomBase->instTracaCom,
        posteInfos->chNom,
        &chLibelleLigne,
        &chDescriptionLigne,
        &posteInfos->numLigne,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);
    if (errorOccured)
        errChk(-1);
    if (chLibelleLigne != NULL)
        strcpy ( posteInfos->chLibelleLigne, chLibelleLigne); 
    if (chDescriptionLigne != NULL)
        strcpy ( posteInfos->chDescriptionLigne, chDescriptionLigne); 
	if ( posteInfos->numLigne == 0 )
		errChk(-1);	

Error:
    // Libération des ressources
    // -------------------------
    CDotNetFreeMemory(typePoste);
    CDotNetFreeMemory(chLibelleLigne);
    CDotNetFreeMemory(chDescriptionLigne);

    // =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if ( errorMsg != NULL )
            strcpy (strErreurMessage, errorMsg);
        else
            sprintf (strErreurMessage, "Erreur inconnu lors de l'extraction des informations du poste\n");
        
        // Libération des ressources
        // -------------------------
        if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        
        return -1;
    }   
    
    return 0;
}

// ==============================================================================
// FONCTION :     TCOM_ProduitsPoste
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_ProduitsPoste (  T_TCOM_BASE *tcomBase, 
//                                          T_POSTE_INFOS *posteInfos, 
//                                          T_POSTE_PRODUITS *posteProduits,
//                                          char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase           : Paramètres de la base.
//                - T_POSTE_INFOS *posteInfos       : Informations sur le poste.
//                - T_POSTE_PRODUITS *posteProduits : Produits du poste.
//                - char *strErreurMessage          : Message d'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Extractions des produits du poste.
//
//                indice[0] -> champ codeproduit : 
//                             code du produit configuré en entrée du poste.
//                indice[1] -> champ indice :
//                             indice du produit configuré en entrée du poste.
//                indice[2] -> champ libelle :
//                             libelle du produit configuré en entrée du poste.
//                indice[3] -> champ codeproduit :
//                             code du produit configuré en sortie du poste.
//                indice[4] -> champ indice :
//                             indice du produit configuré en sortie du poste.
//                indice[5] -> champ libelle :
//                             libelle du produit configuré en sortie du poste.
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
int TCOM_ProduitsPoste ( T_TCOM_BASE *tcomBase, T_POSTE_INFOS *posteInfos, T_POSTE_PRODUITS *posteProduits, char *strErreurMessage )
{
    int         errorOccured = FALSE;
    int         errorCode = 0;
    char        *errorMsg = NULL;
    char        *errorRequete = NULL;
    char        **tabProduit = NULL;
    int         nLongueur1;
    int         nLongueur2;
    int         error = 0;
    int         ii;

    
    // ====================================
    // = Extraction des produits du poste =
    // ====================================
    TracaCom_FonctionsMDT_FonctionsMDT_RecuperationProduitsParPoste(
        tcomBase->instTracaCom,
        posteInfos->chNom,
        &tabProduit,
        &nLongueur1,
        &nLongueur2,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);
    if (errorOccured)
        errChk(-1);
    
    // =================================
    // = Extraction des infos produits =
    // =================================
    posteProduits->nbProduit = 0;
    for ( ii=0 ; ii<nLongueur1 ; ii++ )
    {
        // On ne tient compte que des produits dont le code est différent de 0
        // -------------------------------------------------------------------
        if ( atoi (tabProduit[(ii*nLongueur2)]) > 0)
        {
            // Code CIE
            // --------
            strcpy (posteProduits->produits[posteProduits->nbProduit].cie.chVersion, tabProduit[(ii*nLongueur2)+0]);

            // Indice CIE
            // ----------
            strcpy (posteProduits->produits[posteProduits->nbProduit].cie.chIndice, tabProduit[(ii*nLongueur2)+1]);
        
            // Désignation CIE
            // ---------------
            strcpy (posteProduits->produits[posteProduits->nbProduit].cie.chDesignation, tabProduit[(ii*nLongueur2)+2]);
            
            // Code SFIN
            // ---------
            strcpy (posteProduits->produits[posteProduits->nbProduit].sfin.chVersion, tabProduit[(ii*nLongueur2)+3]);
            
            // Indice SFIN
            // -----------
            strcpy (posteProduits->produits[posteProduits->nbProduit].sfin.chIndice, tabProduit[(ii*nLongueur2)+4]);
        
            // Désignation SFIN
            // ----------------
            strcpy (posteProduits->produits[posteProduits->nbProduit].sfin.chDesignation, tabProduit[(ii*nLongueur2)+5]);
        
            // RAZ valeur de Lot
            // -----------------
            posteProduits->produits[posteProduits->nbProduit].lot = 0;
        
            // RAZ valeur de Palette
            // ---------------------
            posteProduits->produits[posteProduits->nbProduit].palette = 0;
        
            // =======================================
            // = Récupération Infos Produits parents =
            // =======================================
            
            errChk ( TCOM_RecuperationProduitsParents ( 
                            tcomBase,
                            posteProduits->produits[posteProduits->nbProduit].sfin.chVersion,
                            posteProduits->produits[posteProduits->nbProduit].sfin.chIndice,
                            &posteProduits->produits[posteProduits->nbProduit].parent,
                            &posteProduits->produits[posteProduits->nbProduit].nbParent,
                            strErreurMessage )
                    );
            
            if ( posteProduits->produits[posteProduits->nbProduit].nbParent > 0 )
            {
                // Code PFIN
                // ---------
                strcpy (posteProduits->produits[posteProduits->nbProduit].pfin.chVersion, posteProduits->produits[posteProduits->nbProduit].parent[0].chVersion);

                // Indice PFIN
                // -----------
                strcpy (posteProduits->produits[posteProduits->nbProduit].pfin.chIndice, posteProduits->produits[posteProduits->nbProduit].parent[0].chIndice);

                // Désignation PFIN
                // ----------------
                strcpy (posteProduits->produits[posteProduits->nbProduit].pfin.chDesignation, posteProduits->produits[posteProduits->nbProduit].parent[0].chDesignation);
            }
            else
            {
                // Code PFIN
                // ---------
                strcpy (posteProduits->produits[posteProduits->nbProduit].pfin.chVersion, "");

                // Indice PFIN
                // -----------
                strcpy (posteProduits->produits[posteProduits->nbProduit].pfin.chIndice, "");

                // Désignation PFIN
                // ----------------
                strcpy (posteProduits->produits[posteProduits->nbProduit].pfin.chDesignation, "");

            }
            
            // =======================================
            // = Récupération Infos Produits enfants =
            // =======================================
            
            errChk ( TCOM_RecuperationProduitsEnfants (
                            tcomBase,
                            posteProduits->produits[posteProduits->nbProduit].sfin.chVersion,
                            posteProduits->produits[posteProduits->nbProduit].sfin.chIndice,
                            &posteProduits->produits[posteProduits->nbProduit].enfant,
                            &posteProduits->produits[posteProduits->nbProduit].nbEnfant,
                            strErreurMessage )
                    );

            // On incrémente le nombre de produit
            // ----------------------------------
            posteProduits->nbProduit++;
        }
    }

Error:
    // Libération des ressources
    // -------------------------
    CDotNetFreeMemory(tabProduit);
        
    // =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if ( errorMsg != NULL )
            strcpy (strErreurMessage, errorMsg);
        else
            sprintf (strErreurMessage, "Erreur inconnu lors de l'extraction des informations du produit\n");
        
        // Libération des ressources
        // -------------------------
        if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        
        return -1;
    }   
    
    return 0;
}

// ==============================================================================
// FONCTION :     TCOM_ProduitCopier
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_ProduitCopier (  T_POSTE_PRODUIT *posteProduitIn, 
//                                          T_POSTE_PRODUIT *posteProduitOut )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_POSTE_PRODUIT *posteProduitIn     : Produit à copier,
//                - T_POSTE_PRODUIT *posteProduitOut    : Produit copié.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Copie des infos d'un produit vers un autre.
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
int TCOM_ProduitCopier ( T_POSTE_PRODUIT *posteProduitIn, T_POSTE_PRODUIT *posteProduitOut)
{
    int ii;


    // Copie SFIN
    // ----------
    strcpy (posteProduitOut->sfin.chVersion, posteProduitIn->sfin.chVersion);
    strcpy (posteProduitOut->sfin.chIndice, posteProduitIn->sfin.chIndice);
    strcpy (posteProduitOut->sfin.chDesignation, posteProduitIn->sfin.chDesignation);
    strcpy (posteProduitOut->sfin.chFamille, posteProduitIn->sfin.chFamille);
    strcpy (posteProduitOut->sfin.chSousFamille, posteProduitIn->sfin.chSousFamille);

    // Copie CIE
    // ---------
    strcpy (posteProduitOut->cie.chVersion, posteProduitIn->cie.chVersion);
    strcpy (posteProduitOut->cie.chIndice, posteProduitIn->cie.chIndice);
    strcpy (posteProduitOut->cie.chDesignation, posteProduitIn->cie.chDesignation);
    strcpy (posteProduitOut->cie.chFamille, posteProduitIn->cie.chFamille);
    strcpy (posteProduitOut->cie.chSousFamille, posteProduitIn->cie.chSousFamille);

    // Copie PFIN
    // ----------
    strcpy (posteProduitOut->pfin.chVersion, posteProduitIn->pfin.chVersion);
    strcpy (posteProduitOut->pfin.chIndice, posteProduitIn->pfin.chIndice);
    strcpy (posteProduitOut->pfin.chDesignation, posteProduitIn->pfin.chDesignation);
    strcpy (posteProduitOut->pfin.chFamille, posteProduitIn->pfin.chFamille);
    strcpy (posteProduitOut->pfin.chSousFamille, posteProduitIn->pfin.chSousFamille);

    // Copie ENFANT
    // ------------
    if ( posteProduitIn->nbEnfant > 0 )
    {
        posteProduitOut->nbEnfant = posteProduitIn->nbEnfant;
        posteProduitOut->enfant = (T_PRODUIT*) malloc (sizeof(T_PRODUIT) * (posteProduitOut->nbEnfant));
        if ( posteProduitOut->enfant == NULL )
        {
            return -1;
        }
        for ( ii=0 ; ii<posteProduitOut->nbEnfant ; ii++ )
        {
            strcpy (posteProduitOut->enfant[ii].chVersion, posteProduitIn->enfant[ii].chVersion);
            strcpy (posteProduitOut->enfant[ii].chIndice, posteProduitIn->enfant[ii].chIndice);
            strcpy (posteProduitOut->enfant[ii].chDesignation, posteProduitIn->enfant[ii].chDesignation);
            strcpy (posteProduitOut->enfant[ii].chFamille, posteProduitIn->enfant[ii].chFamille);
            strcpy (posteProduitOut->enfant[ii].chSousFamille, posteProduitIn->enfant[ii].chSousFamille);
        }
    }
    else
    {
        posteProduitOut->nbEnfant = 0;
        posteProduitOut->enfant = NULL;
    }

    // Copie PARENT
    // ------------
    if ( posteProduitIn->nbParent > 0 )
    {
        posteProduitOut->nbParent = posteProduitIn->nbParent;
        posteProduitOut->parent = (T_PRODUIT*) malloc (sizeof(T_PRODUIT) * (posteProduitOut->nbParent));
        if ( posteProduitOut->parent == NULL )
        {
            return -1;
        }
        for ( ii=0 ; ii<posteProduitOut->nbParent ; ii++ )
        {
            strcpy (posteProduitOut->parent[ii].chVersion, posteProduitIn->parent[ii].chVersion);
            strcpy (posteProduitOut->parent[ii].chIndice, posteProduitIn->parent[ii].chIndice);
            strcpy (posteProduitOut->parent[ii].chDesignation, posteProduitIn->parent[ii].chDesignation);
            strcpy (posteProduitOut->parent[ii].chFamille, posteProduitIn->parent[ii].chFamille);
            strcpy (posteProduitOut->parent[ii].chSousFamille, posteProduitIn->parent[ii].chSousFamille);
        }
    }
    else
    {
        posteProduitOut->nbParent = 0;
        posteProduitOut->parent = NULL;
    }

    // Copie LOT/PALETTE
    // -----------------
    posteProduitOut->lot = posteProduitIn->lot;
    posteProduitOut->palette = posteProduitIn->palette;
    
    return 0;
}

// ==============================================================================
// FONCTION :     TCOM_ProduitSupprimer
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_ProduitSupprimer ( T_POSTE_PRODUIT *posteProduit )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_POSTE_PRODUIT *posteProduit   : Produit à supprimer.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Suppression de la mémoire alloué pour le produit et RAZ 
//                des valeurs.
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
int TCOM_ProduitSupprimer ( T_POSTE_PRODUIT *posteProduit )
{
    // RAZ SFIN
    // --------
    strcpy (posteProduit->sfin.chVersion, "");
    strcpy (posteProduit->sfin.chIndice, "");
    strcpy (posteProduit->sfin.chDesignation, "");
    strcpy (posteProduit->sfin.chFamille, "");
    strcpy (posteProduit->sfin.chSousFamille, "");

    // RAZ CIE
    // -------
    strcpy (posteProduit->cie.chVersion, "");
    strcpy (posteProduit->cie.chIndice, "");
    strcpy (posteProduit->cie.chDesignation, "");
    strcpy (posteProduit->cie.chFamille, "");
    strcpy (posteProduit->cie.chSousFamille, "");

    // RAZ PFIN
    // --------
    strcpy (posteProduit->pfin.chVersion, "");
    strcpy (posteProduit->pfin.chIndice, "");
    strcpy (posteProduit->pfin.chDesignation, "");
    strcpy (posteProduit->pfin.chFamille, "");
    strcpy (posteProduit->pfin.chSousFamille, "");

    // RAZ ENFANT
    // ----------
    if ( posteProduit->nbEnfant > 0 )
    {
        free (posteProduit->enfant);
    }
    posteProduit->nbEnfant = 0;
    posteProduit->enfant = NULL;

    // RAZ PARENT
    // ----------
    if ( posteProduit->nbParent > 0 )
    {
        free (posteProduit->parent);
    }
    posteProduit->nbParent = 0;
    posteProduit->parent = NULL;
    
    // RAZ LOT/PALETTE
    // ---------------
    posteProduit->lot = 0;
    posteProduit->palette = 0;
    
    return 0;
}

// ==============================================================================
// FONCTION :     TCOM_ProduitIndexParent
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_ProduitIndexParent ( T_POSTE_PRODUIT *posteProduit, 
//                                              char *chCode,
//                                              char *chIndice )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_POSTE_PRODUIT *posteProduit   : Produit source,
//                - char *chCode                    : Code produit cherché,
//                - char *chIndice                  : Indice produit cherché.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Recherche de l'index d'un produit dans le tableau de produit
//                Parent.
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
int TCOM_ProduitIndexParent ( T_POSTE_PRODUIT *posteProduit, char *chCode, char *chIndice )
{
    int ii;
    
    
    for ( ii=0 ; ii<posteProduit->nbParent ; ii++ )
    {
        if ( (strcmp (posteProduit->parent[ii].chVersion,chCode) == 0) && (strcmp (posteProduit->parent[ii].chIndice,chIndice) == 0) )  
            return ii;      
    }
    
    return -1;
}

// ==============================================================================
// FONCTION :     TCOM_ProduitIndexEnfant
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_ProduitIndexEnfant ( T_POSTE_PRODUIT *posteProduit, 
//                                              char *chCode,
//                                              char *chIndice,
//                                              char *chFamille,
//                                              char *chSousFamille)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_POSTE_PRODUIT *posteProduit   : Produit source,
//                - char *chCode                    : Code produit cherché,
//                - char *chIndice                  : Indice produit cherché,
//                - char *chFamille                 : Famille du produit recherché,
//                - char *chSousFamille             : Sous famille du produit recherché,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Recherche de l'index d'un produit dans le tableau de produit
//                Enfant.
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
int TCOM_ProduitIndexEnfant ( T_POSTE_PRODUIT *posteProduit, char *chCode, char *chIndice, char *chFamille, char *chSousFamille )
{
    int ii;
    
    
    for ( ii=0 ; ii<posteProduit->nbEnfant ; ii++ )
    {
        if (chCode != NULL)
        {
            if ( (strcmp (posteProduit->enfant[ii].chVersion,chCode) == 0) && (strcmp (posteProduit->enfant[ii].chIndice,chIndice) == 0) )  
                return ii;      
        }
        else if (chFamille != NULL)
        {
            if ( strcmp (posteProduit->enfant[ii].chFamille,chFamille) == 0 )  
                return ii;      
        }
        else if (chSousFamille != NULL)
        {
            if ( strcmp (posteProduit->enfant[ii].chSousFamille,chSousFamille) == 0 )  
                return ii;      
        }
    }
    
    return -1;
}

// ==============================================================================
// FONCTION :     TCOM_ReceiverSN
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_ReceiverSN ( T_TCOM_BASE *tcomBase, 
//                                      T_VARIABLES_TRACA *varTraca,
//                                      T_POSTE_PRODUITS *posteProduits,
//                                      char *strReceiverSN, 
//                                      char *strErreurMessage, 
//                                      int nbParam, 
//                                      ... )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase           : Paramètres de la base.
//                - T_VARIABLES_TRACA *varTraca     : Variables de traçabilité,
//                - T_POSTE_PRODUITS *posteProduits : Produits du poste,
//                - char *strReceiverSN             : Numéro de série généré,
//                - char *strErreurMessage          : Message d'erreur,
//                - int nbParam                     : Nombre de paramètres,
//                - ...                             : Paramètres.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Génération du numéro de série pour le décodeur.
//
//                Numéro de série CIE :
//                  paramètre1 -> indice[0] -> usine
//                  paramètre2 -> indice[1] -> ligne
//
//                Numéro de série SFIN :
//                  paramètre1 -> indice[0] -> usine
//                  paramètre2 -> indice[1] -> ligne
//
//                Numéro de série PFIN :
//                  paramètre1 -> indice[0] -> usine
//                  paramètre2 -> indice[1] -> ligne
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        20/11/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_ReceiverSN ( T_TCOM_BASE *tcomBase, T_VARIABLES_TRACA *varTraca, T_POSTE_PRODUITS *posteProduits, char *strReceiverSN, char *strErreurMessage, int nbParam, ... )
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
    char    *strNumSerie;
    char    **tabParametres = NULL;
    int     idxParam;
    va_list list;
    
    
    // Allocation mémoire pour le tableau de paramètres
    // ------------------------------------------------
    tabParametres = (char**)malloc ( sizeof(char*) * nbParam);

    // Récupération des paramètres
    // ---------------------------
    va_start (list, nbParam);
    for ( idxParam=0 ; idxParam<nbParam ; idxParam++ )
    {
        // Allocation mémoire du paramètre
        // -------------------------------
        tabParametres[idxParam] = (char*) malloc( sizeof(char) * TCOM_SN_PARAM_TAILLE_MAX );
        strcpy (tabParametres[idxParam], va_arg (list, char*));
    }                        
    va_end (list);
    
    // ========================================
    // = Génération du numéro de série du STB =
    // ========================================
    TracaCom_FonctionsMDT_FonctionsMDT_GenerationNumSerie(
        tcomBase->instTracaCom,
        posteProduits->produits[varTraca->idxProduit].sfin.chVersion,
        posteProduits->produits[varTraca->idxProduit].sfin.chIndice,
        tabParametres,
        nbParam,
        &strNumSerie,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);

    // Vérification de la génération du numéro de série
    // ------------------------------------------------
    if ( strNumSerie == NULL )
    {
        sprintf (strErreurMessage, "SN non généré");
        return -1;
    }

    // Enregistrement du numéro de série généré
    // ----------------------------------------
    strcpy (strReceiverSN, strNumSerie);

    // Libération des ressources
    // -------------------------
    CDotNetFreeMemory(strNumSerie);
    
    // Libération mémoire des paramètres
    // ---------------------------------
    for ( idxParam=0 ; idxParam<nbParam ; idxParam++ )
    {
        free (tabParametres[idxParam]);
    }
    free (tabParametres);

    // =======================
    // = gestion des erreurs =
    // =======================
    if(errorOccured)
    {
        if ( (errorMsg != NULL) && (errorRequete != NULL) )
            sprintf (strErreurMessage, "%s", errorMsg);
        if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        return -1;
    }   
    
    return 0;
}

// ==============================================================================
// FONCTION :     TCOM_GenerationSnClient
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_GenerationSnClient ( T_TCOM_BASE *tcomBase, 
//                                              char *strFormatClient,
//                                              char *strSnClient,
//                                              char *strErreurMessage,
//                                              int nbParam,
//                                              ... )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase   : Paramètres de la base.
//                - char *strFormatClient   : Format du SN à générer,
//                - char *strSnClient       : Numéro de série généré,
//                - char *strErreurMessage  : Message d'erreur,
//                - int nbParam             : Nombre de paramètres,
//                - ...                     : Paramètres.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Génération du numéro de série client pour le décodeur.
//
//                Numéro de série ICADD : 
//                  paramètre1 -> indice[0] -> usine.
//                  paramètre2 -> indice[1] -> ligne.
//                 
//                Numéro de série BYT : 
//                  paramètre1 -> indice[0] -> usine.
//                  paramètre2 -> indice[1] -> ligne.
//                  paramètre2 -> indice[2] -> model.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S08012BA00
//  DATE :        05/02/2010
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_GenerationSnClient ( T_TCOM_BASE *tcomBase, char *strFormatClient, char *strSnClient, char *strErreurMessage, int nbParam, ... )
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
    char    *strNumSerie;
    char    **tabParametres = NULL;
    int     idxParam;
    va_list list;
    
    // Allocation mémoire pour le tableau de paramètres
    // ------------------------------------------------
    tabParametres = (char**)malloc ( sizeof(char*) * nbParam);

    // Récupération des paramètres
    // ---------------------------
    va_start (list, nbParam);
    for ( idxParam=0 ; idxParam<nbParam ; idxParam++ )
    {
        // Allocation mémoire du paramètre
        // -------------------------------
        tabParametres[idxParam] = (char*) malloc( sizeof(char) * TCOM_SN_PARAM_TAILLE_MAX );
        strcpy (tabParametres[idxParam], va_arg (list, char*));
    }
    va_end (list);

    // ========================================
    // = Génération du numéro de série du STB =
    // ========================================
    TracaCom_FonctionsMDT_FonctionsMDT_GenerationNumSerieClient(
        tcomBase->instTracaCom,
        strFormatClient,
        tabParametres,
        nbParam,
        &strNumSerie,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);

    // Vérification de la génération du numéro de série
    // ------------------------------------------------
    if ( strNumSerie == NULL )
    {
        sprintf (strErreurMessage, "SN non généré");
        return -1;
    }

    // Enregistrement du numéro de série généré
    // ----------------------------------------
    strcpy (strSnClient, strNumSerie);

    // Libération des ressources
    // -------------------------
    CDotNetFreeMemory(strNumSerie);
    
    // Libération mémoire des paramètres
    // ---------------------------------
    for ( idxParam=0 ; idxParam<nbParam ; idxParam++ )
    {
        free (tabParametres[idxParam]);
    }
    free (tabParametres);

    // =======================
    // = gestion des erreurs =
    // =======================
    if(errorOccured)
    {
        if ( (errorMsg != NULL) && (errorRequete != NULL) )
            sprintf (strErreurMessage, "%s", errorMsg);
        if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        return -1;
    }   
    
    return 0;
}

// ==============================================================================
// FONCTION :     TCOM_AutorisationPassage
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_AutorisationPassage (int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//                                              char *codeProduitEntree,
//                                              char *indiceProduitEntree,
//                                              char *codeProduitSortie,
//                                              char *indiceProduitSortie,
//                                              char *nomPoste,
//                                              char *strReceiverSN,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *codeProduitEntree     : Code produit en entrée,
//                - char *indiceProduitEntree   : Indice produit en entrée,
//                - char *codeProduitSortie     : Code produit en sortie,
//                - char *indiceProduitSortie   : Indice produit en sortie,
//                - char *nomPoste              : Nom poste,
//                - char *strReceiverSN         : Numéro de série du STB,
//                - char *strErreurMessage      : Message d'erreur,
/// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Passage autorisé
//                - 1 = Passage non autorisé
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Vérification de l'autorisation de passage pour le décodeur.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        20/11/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_AutorisationPassage ( int nItfe, T_TCOM_BASE *tcomBase, char *codeProduitEntree, char *indiceProduitEntree, char *codeProduitSortie, char *indiceProduitSortie, char *nomPoste, char *strReceiverSN, char *strErreurMessage )
{
    __int64             lngId_NumSerie;
    int                 errorOccured = FALSE;
    int                 errorCode = 0;
    char                *errorMsg = NULL;
    char                *errorRequete = NULL;
    char                *strMessage = NULL;
    int                 autorisation;
    char                chMsg[1024];
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	T_VARIABLES 		*ptrVariablesConf = &(gSlot[nItfe].variablesConf);
 	int 				error = 0;


    // ================================================
    // = Vérification de l'existance en BDD du SN CIE =
    // = Si il n'existe pas on le crée                =
    // ================================================
    TracaCom_FonctionsMDT_FonctionsMDT_RecuperationNumSerie (tcomBase->instTracaCom, strReceiverSN,
                                                             codeProduitEntree, indiceProduitEntree,
                                                             &lngId_NumSerie, 
                                                             &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);

/*	if ( strMessage == NULL || errorMsg == NULL || errorRequete == NULL )
		errChk(-2);  */
	
	if (errorOccured)
        errChk(-1);
 
    if ( lngId_NumSerie == 0 )
    {
    
        TracaCom_FonctionsMDT_FonctionsMDT_EnregistrementNumSerie ( tcomBase->instTracaCom, strReceiverSN, "",
                                                                    codeProduitEntree, indiceProduitEntree, "", "",
                                                                    &lngId_NumSerie,
                                                                    &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);
    	
		if ( strMessage == NULL || errorMsg == NULL || errorRequete == NULL )
			errChk(-2);
	
		if (errorOccured)
	        errChk(-1);
 
	}
    
    
    // ===============================================
    // = Lecture de l'autorisation de passage du STB =
    // ===============================================
   if ( VAR_GET_BOOL(ptrVariablesConf,VAR_CONF_ID_CONTROL_FLUX,0) )
		// =================================================
	    //  Nouvelle gestion de l'autorisation de passage 
		// 	4 : Carte de référence.
		//	3 : Flux de retour dépannage.
		//	2 : Flux de production normal en retest.
		//	1 : Flux de production normal.
		//	0 : Flux de production en retest.
		//	-1 : Le poste renseigné n'existe pas en base de données ou mal configuré.
		//	-2 : Le couple code produit et indice produit renseignés n'existent pas en base de données.
		//	-3 : Le couple code produit et indice produit renseignés n'existent pas en base de données.
		//	-4 : Le triplet numéro de série, code produit et indice produit renseignés n'existent pas en base de données.
		//	-5 : Le flux de production n'est pas configuré pour les produits et le poste renseignés.
		//	-6 : Le numserie renseigné n'est pas valide, il ne possède aucun mouvement en base de données.
		//	-7 : Flux de production normal mais passage sur le mauvais poste.
		//	-8 : Flux de production normal en retest mais passage sur le mauvais poste.
		//	-9 : Flux de production normal en retest mais temps de repasse écoulé.
		//	-10 : Flux de production normal en retest mais quantité de repasse épuisée.
		//	-11 : Problème avec la base de données (Postgres).
		//	-12 : Problème avec la base de données (DLL). 
	    // =================================================
		TracaCom_FonctionsMDT_FonctionsMDT_ControlFlux (
			tcomBase->instTracaCom,
	        strReceiverSN,
	        nomPoste,
			codeProduitEntree,
	        indiceProduitEntree,
	        codeProduitSortie,
	        indiceProduitSortie, 
			&ptrVariablesTraca->nCodePassage, 
	        &strMessage,
	        &autorisation,
			&errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);
	else	
	    TracaCom_FonctionsMDT_FonctionsMDT_AutorisationPassage(
	        tcomBase->instTracaCom,
	        strReceiverSN,
	        nomPoste,
	        codeProduitEntree,
	        indiceProduitEntree,
	        codeProduitSortie,
	        indiceProduitSortie,
	        &ptrVariablesTraca->nCodePassage,
	        &strMessage,
	        &autorisation,
	        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);
	
	if ( strMessage == NULL || errorMsg == NULL || errorRequete == NULL )
		errChk(-2);
	
	if (errorOccured)
        errChk(-1);
 
	// =============================================
    // = Vérification de l'autorisation de passage =
    // =============================================
    if ( autorisation == 0 )
    {
		/*Autorisation de passage KO : 
		code 0 : dernier passage du numserie OK, repasse sur le meme type de poste.
		code -1 : premier passage du numserie sur le mauvais poste. Allez au premier poste.
		code -2 : dernier passage du numserie KO, repasse sur le mauvais type de poste et temps de repasse OK.
		code -3 : dernier passage du numserie OK, passage sur le mauvais type de poste.
		code -4 : dernier passage du numserie KO, repasse sur le mauvais type de poste et temps de repasse KO. Allez au poste de dépannage.
		code -5 : dernier passage du numserie KO, repasse sur le meme type de poste et temps de repasse KO. Allez au poste de dépannage.
		code -6 : autre cas ??? */
        autorisation = 1;
    }
    else
	{	
		/*Autorisation de passage OK : 
		code 1 : premier passage du numserie sur le premier poste..
		code 2 : dernier passage du numserie KO, repasse sur le meme type de poste et temps de repasse OK.
		code 3 : dernier passage du numserie OK et passage sur le poste suivant.
		code 4 : dernier poste de la ligne.
		code 5 : repassage du numserie sur le premier poste (RESTART_PROCESS).
		code 6 : carte de référence.*/
        autorisation = 0;
	}
	
    if (strMessage != NULL)
    {
        if (FCT_STRING_IS_EMPTY(strMessage) == FALSE)
            sprintf ( strErreurMessage, "Code Passage = %d \"%s\"", ptrVariablesTraca->nCodePassage, strMessage);
    }
    else
        sprintf ( strErreurMessage, "Code Passage = %d", ptrVariablesTraca->nCodePassage);
    
    // =============================
    // = Libération des ressources =
    // =============================
    if ( strMessage != NULL )
        CDotNetFreeMemory(strMessage);
    
    // =======================
    // = gestion des erreurs =
    // =======================
Error:
	if(error)
    {
		if (error == -2)
			strcpy (strErreurMessage, "Erreur Réseau");
        else if ( errorMsg != NULL )
        {
            if (errorMsg[0] != '\0')
            {
                sprintf (chMsg, "%s (Erreur:\"%s\")", strErreurMessage, errorMsg);
                strcpy (strErreurMessage, chMsg);
            }
        }
		
		// =============================
    	// = Libération des ressources =
    	// =============================

        if ( errorMsg != NULL ) 
            CDotNetFreeMemory(errorMsg);
        if ( errorRequete != NULL ) 
            CDotNetFreeMemory(errorRequete);
        return -1;
    }   
    
    return autorisation;
}

// ==============================================================================
// FONCTION :     TCOM_VerificationDoublon
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_VerificationDoublon ( int nItfe, 
//                                               T_TCOM_BASE *tcomBase,
//                                               char *chNomPropriete,
//                                               char *chValeurPropriete,
//                                               char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *chNomPropriete        : Nom de la propriété à vérifier,
//                - char *chValeurPropriete     : Valeur de la propriété à vérifier,
//                - char *strErreurMessage      : Message d'erreur,
/// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Propriété sans doublon
//                - < 0 = Erreur rencontré durant la fonction
//                  -1 : Doublon présent et supprimé (numserie non palettisé)
//                  -2 : Doublon présent et non supprimé (numserie palettisé)
//                  -3 : Présence de plusieurs doublons
//                  -4 : Erreur
// ------------------------------------------------------------------------------
// DESRIPTION :   Vérification de la presence de doublon sous TracaCom pour une 
//                propriété donnée.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        02/02/2010
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_VerificationDoublon ( int nItfe, T_TCOM_BASE *tcomBase, char *chNomPropriete, char *chValeurPropriete, char *strErreurMessage )
{
    int                 errorOccured = FALSE;
    int                 errorCode = 0;
    char                *errorMsg = NULL;
    char                *errorRequete = NULL;
    char                *strMessage = NULL;
    int                 intCodeDoublon;
    char                chMsg[1024];

    
    // =================================================
    // = Vérification de la présence de doublon en BDD =
    // =================================================
    TracaCom_FonctionsMDT_FonctionsMDT_VerificationProprieteNumSerieDoublon(
        tcomBase->instTracaCom,
        chNomPropriete,
        chValeurPropriete,
        &intCodeDoublon,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);

    // =============================================
    // = Vérification de l'autorisation de passage =
    // =============================================
    if (strMessage != NULL)
    {
        if (FCT_STRING_IS_EMPTY(strMessage) == FALSE)
            sprintf ( strErreurMessage, "Code doublon = %d \"%s\"", intCodeDoublon, strMessage);
    }
    else
        sprintf ( strErreurMessage, "Code doublon = %d", intCodeDoublon);
    
    // =============================
    // = Libération des ressources =
    // =============================
    if ( strMessage != NULL )
        CDotNetFreeMemory(strMessage);
    
    // =======================
    // = gestion des erreurs =
    // =======================
    if(errorOccured)
    {
        if ( (errorMsg != NULL) && (errorRequete != NULL) )
        {
            if (errorMsg[0] != '\0')
            {
                sprintf (chMsg, "%s (Erreur:\"%s\")", strErreurMessage, errorMsg);
                strcpy (strErreurMessage, chMsg);
            }
        }
        
        if ( errorMsg != NULL ) 
            CDotNetFreeMemory(errorMsg);
        if ( errorRequete != NULL ) 
            CDotNetFreeMemory(errorRequete);
        
        if (intCodeDoublon >= 0)
            intCodeDoublon = -4;
        
        return intCodeDoublon;
    }   
    
    // code -1 -> Doublon présent et supprimé (numserie non palettisé).
    if (intCodeDoublon == -1)
        intCodeDoublon = 0;
    
    return intCodeDoublon;
}

// ==============================================================================
// FONCTION :     TCOM_EnregistrementMvtTest
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_EnregistrementMvtTest ( T_TCOM_BASE *tcomBase, 
//                                                 char *strReceiverSN, 
//                                                 char *codeProduit,
//                                                 char *indiceProduit,
//                                                 char *codeTransaction,
//                                                 int status,
//                                                 int vraiDefaut,
//                                                 float duree,
//                                                 float quantite,
//                                                 char *nomPoste,
//                                                 char *matriculePersonne,
//                                                 char *nomApplication,
//                                                 char *versionApplication,
//                                                 char *observation,
//                                                 long *idMvtTest,
//                                                 char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase   : Paramètres de la base.
//                - char *strReceiverSN     : Numéro de série du STB,
//                - char *codeProduit       : Code produit,
//                - char *indiceProduit     : Indice produit,
//                - char *codeTransaction   : Code transaction,
//                - int status              : Status du test (OK ou KO),
//                - int vraiDefaut          : Vrai défaut,
//                - float duree             : duree du test,
//                - float quantite          : quantité (facultatif),
//                - char *nomPoste          : Nom poste,
//                - char *matriculePersonne : MAtricule operateur,
//                - char *nomApplication    : Nom application,
//                - char *versionApplication: Version application,
//                - char *observation       : Observation,
//                - long *idMvtTest         : Id du mouvement de test,
//                - char *strErreurMessage  : Message d'erreur.
/// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Passage autorisé
//                - 1 = Passage non autorisé
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Enregistrement d'un mouvement de test en BDD.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        30/11/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_EnregistrementMvtTest ( T_TCOM_BASE *tcomBase, char *strReceiverSN, char *codeProduit, char *indiceProduit, char *codeTransaction, int status, int vraiDefaut, float duree, float quantite, char *nomPoste, char *matriculePersonne, char *nomApplication, char *versionApplication, char *observation, __int64 *idMvtTest, char *strErreurMessage )
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;

    
    // =======================================
    // = Enregistrement du mouvement de test =
    // =======================================
    TracaCom_FonctionsMDT_FonctionsMDT_EnregistrementMvtTest(
        tcomBase->instTracaCom,
        strReceiverSN,
        codeProduit,
        indiceProduit,
        codeTransaction,
        status,
        vraiDefaut,
        duree,
        quantite,
        nomPoste,
        matriculePersonne,
        nomApplication,
        versionApplication,
        observation,
        idMvtTest,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);

    // =======================
    // = gestion des erreurs =
    // =======================
    if(errorOccured)
    {
        if ( (errorMsg != NULL) && (errorRequete != NULL) )
            sprintf (strErreurMessage, "%s", errorMsg);
        if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        return -1;
    }   
    
    return 0;
}

// ==============================================================================
// FONCTION :     TCOM_EnregistrementErreurMvtTest
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_EnregistrementErreurMvtTest ( T_TCOM_BASE *tcomBase,
//                                                       char *libelleErreur,
//                                                       __int64 idMvtTest,
//                                                       char *strCodeErreur,
//                                                       char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase   : Paramètres de la base.
//                - char *libelleErreur     : Libellé de l'erreur,
//                - long idMvtTest          : Id du mouvement de test,
//                - char *strCodeErreur     : Code de l'erreur,
//                - char *strErreurMessage  : Message d'erreur.
/// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Passage autorisé
//                - 1 = Passage non autorisé
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Enregistrement d'une erreur pour associée à un mouvement de 
//                test en BDD.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        30/11/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_EnregistrementErreurMvtTest ( T_TCOM_BASE *tcomBase, char *libelleErreur, __int64 idMvtTest, char *strCodeErreur, char *strErreurMessage )
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *codeErreur = NULL;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;

    
    // ==============================
    // = Enregistrement de l'erreur =
    // ==============================
    TracaCom_FonctionsMDT_FonctionsMDT_EnregistrementErreur(
        tcomBase->instTracaCom,
        libelleErreur,
        idMvtTest,
        &codeErreur,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);

    // =======================
    // = gestion des erreurs =
    // =======================
    if(errorOccured)
    {
        if ( (errorMsg != NULL) && (errorRequete != NULL) )
            sprintf (strErreurMessage, "%s", errorMsg);
        if (codeErreur != NULL)
            CDotNetFreeMemory(codeErreur);
        if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        return -1;
    }
    
    if ( codeErreur != NULL )
    {
        strcpy (strCodeErreur, codeErreur);
        CDotNetFreeMemory(codeErreur);
    }
    
    return 0;
}

// ==============================================================================
// FONCTION :     TCOM_EnregistrementLienSn
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_EnregistrementLienSn ( T_TCOM_BASE *tcomBase,
//                                                char *strNumSerieEnfant,
//                                                char *strCodeProduitEnfant,
//                                                char *strIndiceProduitEnfant,
//                                                char *strNumSerieParent,
//                                                char *strCodeProduitParent,
//                                                char *strIndiceProduitParent,
//                                                char * strObservation,
//                                                char * strTypeLien,
//                                                __int64 lngOrdre,
//                                                __int64 * lngId_LienNumSerie,
//                                                char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base.
//                - char *strNumSerieEnfant     : Numero de série enfant,
//                - char *strCodeProduitEnfant  : Code produit enfant,
//                - char *strIndiceProduitEnfant: Indice produit enfant,
//                - char *strNumSerieParent     : Numero de série parent,
//                - char *strCodeProduitParent  : Code produit parent,
//                - char *strIndiceProduitParent: Indice produit parent,
//                - char *strObservation        : Observation sur la liaison (facultatif),
//                - char *strTypeLien           : Type de liaison (facultatif),
//                - __int64 lngOrdre            : Ordre de la liaison(facultatif),
//                - __int64 *lngId_LienNumSerie : Clé primaire de la liaison qui 
//                                                vient d'être ajouté (paramètre de retour),
//                - char *strErreurMessage      : Message d'erreur.
/// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Passage autorisé
//                - 1 = Passage non autorisé
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Enregistrement d'une liaison entre deux numéros de série.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        30/11/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_EnregistrementLienSn ( T_TCOM_BASE *tcomBase, char *strNumSerieEnfant, char *strCodeProduitEnfant, char *strIndiceProduitEnfant, char *strNumSerieParent, char *strCodeProduitParent, char *strIndiceProduitParent, char * strObservation, char * strTypeLien, __int64 lngOrdre, __int64 * lngId_LienNumSerie, char *strErreurMessage )
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;


    // ==============================
    // = Enregistrement de l'erreur =
    // ==============================
    TracaCom_FonctionsMDT_FonctionsMDT_EnregistrementLienNumSerie(
        tcomBase->instTracaCom,
        strNumSerieEnfant,
        strCodeProduitEnfant,
        strIndiceProduitEnfant,
        strNumSerieParent,
        strCodeProduitParent,
        strIndiceProduitParent,
        strObservation,
        strTypeLien,
        lngOrdre,
        lngId_LienNumSerie,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);

    // =======================
    // = gestion des erreurs =
    // =======================
    if(errorOccured)
    {
        if ( (errorMsg != NULL) && (errorRequete != NULL) )
            sprintf (strErreurMessage, "%s", errorMsg);
        if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        return -1;
    }

    return 0;
}

// ==============================================================================
// FONCTION :     TCOM_EnregistrementSn
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_EnregistrementSn ( T_TCOM_BASE *tcomBase, 
//                                            char *strNumSerie,
//                                            char *strIndiceNumSerie,
//                                            char *strCodeProduit,
//                                            char *strIndiceProduit,
//                                            char *strCodeStatutNumserie,
//                                            char * strObservation,
//                                            __int64 * lngId_NumSerie,
//                                            char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base.
//                - char *strNumSerie           : Numero de série,
//                - char *strIndiceNumSerie     : Indice du numéro de série,
//                - char *strCodeProduit        : Code produit,
//                - char *strCodeStatutNumserie : Code du statut du numserie 
//                                                correspondant (obligatoire),
//                - char * strObservation       : Observation sur la liaison (facultatif),
//                - __int64 * lngId_NumSerie    : Clé primaire du numéro de série,
//                - char *strErreurMessage      : Message d'erreur.
/// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Passage autorisé
//                - 1 = Passage non autorisé
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Enregistrement d'une liaison entre deux numéros de série.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        30/11/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_EnregistrementSn ( T_TCOM_BASE *tcomBase, char *strNumSerie, char *strIndiceNumSerie, char *strCodeProduit, char *strIndiceProduit, char *strCodeStatutNumserie, char * strObservation, __int64 * lngId_NumSerie, char *strErreurMessage )
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;


    // ==============================
    // = Enregistrement de l'erreur =
    // ==============================
    TracaCom_FonctionsMDT_FonctionsMDT_EnregistrementNumSerie(
        tcomBase->instTracaCom,
        strNumSerie,
        strIndiceNumSerie,
        strCodeProduit,
        strIndiceProduit,
        strCodeStatutNumserie,
        strObservation,
        lngId_NumSerie,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);

    // =======================
    // = gestion des erreurs =
    // =======================
    if(errorOccured)
    {
        if ( (errorMsg != NULL) && (errorRequete != NULL) )
            sprintf (strErreurMessage, "%s", errorMsg);
        if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        return -1;
    }

    return 0;
}

// ==============================================================================
// FONCTION :     TCOM_RecuperationNumSeriesParents
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_RecuperationNumSeriesParents ( T_TCOM_BASE *tcomBase, 
//                                                        char *strNumSerie,
//                                                        char *strCodeProduit,
//                                                        char *strIndiceProduit,
//                                                        T_NUM_SERIE *tabNumSeriesParents,
//                                                        int *nbNumSeriesParents,
//                                                        char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase           : Paramètres de la base.
//                - char *strNumSerie               : Numero de série,
//                - char *strIndiceNumSerie         : Indice du numéro de série,
//                - char *strCodeProduit            : Code produit,
//                - T_NUM_SERIE *tabNumSeriesParents: Tableau des SN parents,
//                - int *nbNumSeriesParents         : Nombre de SN parents,
//                - char *strErreurMessage          : Message d'erreur.
/// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Passage autorisé
//                - 1 = Passage non autorisé
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Récupération des numéro de série parents d'un SN.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        30/11/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_RecuperationNumSeriesParents ( T_TCOM_BASE *tcomBase, char *strNumSerie, char *strCodeProduit, char *strIndiceProduit, T_NUM_SERIE **tabNumSeriesParents, int *nbNumSeriesParents, char *strErreurMessage )
{
    int     ii;
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
    char    **tabNumSeriesParentsTmp = NULL;
    int     tabNumSeriesParentsLength1;
    int     tabNumSeriesParentsLength2;


    // ==============================
    // = Enregistrement de l'erreur =
    // ==============================
    TracaCom_FonctionsMDT_FonctionsMDT_RecuperationNumSeriesParents(
        tcomBase->instTracaCom,
        strNumSerie,
        strCodeProduit,
        strIndiceProduit,
        &tabNumSeriesParentsTmp,
        &tabNumSeriesParentsLength1,
        &tabNumSeriesParentsLength2,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);

    // =======================
    // = gestion des erreurs =
    // =======================
    if(errorOccured)
    {
        if ( (errorMsg != NULL) && (errorRequete != NULL) )
            sprintf (strErreurMessage, "%s", errorMsg);
        if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        return -1;
    }
    
    if ( *nbNumSeriesParents = tabNumSeriesParentsLength1 )
    {
        *tabNumSeriesParents = (T_NUM_SERIE*) malloc (sizeof(T_NUM_SERIE) * (*nbNumSeriesParents));
        if ( *tabNumSeriesParents == NULL )
        {
            sprintf (strErreurMessage, "Problème d'allocation mémoire");
            return -1;
        }
        for ( ii=0 ; ii<*nbNumSeriesParents ; ii++ )
        {
            strcpy ( (*tabNumSeriesParents)[ii].chNumSerie, tabNumSeriesParentsTmp[(ii*tabNumSeriesParentsLength2)]);
            strcpy ( (*tabNumSeriesParents)[ii].chCodeProduit, tabNumSeriesParentsTmp[(ii*tabNumSeriesParentsLength2)+1]);
            strcpy ( (*tabNumSeriesParents)[ii].chIndiceProduit, tabNumSeriesParentsTmp[(ii*tabNumSeriesParentsLength2)+2]);
        }
    }
    
    if (tabNumSeriesParentsTmp != NULL)
        CDotNetFreeMemory(tabNumSeriesParentsTmp);

    return 0;
}

// ==============================================================================
// FONCTION :     TCOM_RecuperationProduitsParents
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_RecuperationProduitsParents ( T_TCOM_BASE *tcomBase, 
//                                                       char *strCodeProduit, 
//                                                       char *strIndiceProduit,
//                                                       T_PRODUIT **tabProduitsParents,
//                                                       int *nbProduitsParents,
//                                                       char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase           : Paramètres de la base.
//                - char *strCodeProduit            : Code produit,
//                - char *strIndiceProduit          : Indice produit,
//                - T_PRODUIT **tabProduitsParents  : Tableau des Produits parents,
//                - int *nbProduitsParents          : Nombre de Produit parents,
//                - char *strErreurMessage          : Message d'erreur.
/// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Passage autorisé
//                - 1 = Passage non autorisé
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Récupération des numéro de série parents d'un SN.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        30/11/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_RecuperationProduitsParents ( T_TCOM_BASE *tcomBase, char *strCodeProduit, char *strIndiceProduit, T_PRODUIT **tabProduitsParents, int *nbProduitsParents, char *strErreurMessage )
{
    int     ii;
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
    char    **tabProduitsParentsTmp = NULL;
    int     tabProduitsParentsLength1;
    int     tabProduitsParentsLength2;


    // ==============================
    // = Enregistrement de l'erreur =
    // ==============================
    TracaCom_FonctionsMDT_FonctionsMDT_RecuperationProduitsParents(
        tcomBase->instTracaCom,
        strCodeProduit,
        strIndiceProduit,
        &tabProduitsParentsTmp,
        &tabProduitsParentsLength1,
        &tabProduitsParentsLength2,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);

    // =======================
    // = gestion des erreurs =
    // =======================
    if(errorOccured)
    {
        if ( (errorMsg != NULL) && (errorRequete != NULL) )
            sprintf (strErreurMessage, "%s", errorMsg);
        if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        return -1;
    }
    
    if ( *nbProduitsParents = tabProduitsParentsLength1 )
    {
        *tabProduitsParents = (T_PRODUIT*) malloc (sizeof(T_PRODUIT) * (*nbProduitsParents));
        if ( *tabProduitsParents == NULL )
        {
            sprintf (strErreurMessage, "Problème d'allocation mémoire");
            return -1;
        }
        for ( ii=0 ; ii<*nbProduitsParents ; ii++ )
        {
            strcpy ( (*tabProduitsParents)[ii].chVersion, tabProduitsParentsTmp[(ii*tabProduitsParentsLength2)]);
            strcpy ( (*tabProduitsParents)[ii].chIndice, tabProduitsParentsTmp[(ii*tabProduitsParentsLength2)+1]);
            strcpy ( (*tabProduitsParents)[ii].chDesignation, tabProduitsParentsTmp[(ii*tabProduitsParentsLength2)+2]);
            strcpy ( (*tabProduitsParents)[ii].chFamille, "");
            strcpy ( (*tabProduitsParents)[ii].chSousFamille, "");
        }
    }
    
    if (tabProduitsParentsTmp != NULL)
        CDotNetFreeMemory(tabProduitsParentsTmp);

    return 0;   
}

// ==============================================================================
// FONCTION :     TCOM_RecuperationProduitsEnfants
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_RecuperationProduitsEnfants ( T_TCOM_BASE *tcomBase, 
//                                                       char *strCodeProduit, 
//                                                       char *strIndiceProduit,
//                                                       T_PRODUIT **tabProduitsEnfants,
//                                                       int *nbProduitsEnfants,
//                                                       char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase           : Paramètres de la base.
//                - char *strCodeProduit            : Code produit,
//                - char *strIndiceProduit          : Indice produit,
//                - T_PRODUIT **tabProduitsEnfants  : Tableau des Produits enfants,
//                - int *nbProduitsEnfants          : Nombre de Produit enfants,
//                - char *strErreurMessage          : Message d'erreur.
/// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Passage autorisé
//                - 1 = Passage non autorisé
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Récupération des produits enfants d'un produit spécifié.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        30/11/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_RecuperationProduitsEnfants ( T_TCOM_BASE *tcomBase, char *strCodeProduit, char *strIndiceProduit, T_PRODUIT **tabProduitsEnfants, int *nbProduitsEnfants, char *strErreurMessage )
{
    int     ii;
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
    char    *strCodeOperateur = NULL;
    char    *strCodeSousFamille = NULL;
    char    *strCodeFamille = NULL;
    char    **tabProduitsEnfantsTmp = NULL;
    int     tabProduitsEnfantsLength1;
    int     tabProduitsEnfantsLength2;


    // =================================
    // = Récupération produits enfants =
    // =================================
    TracaCom_FonctionsMDT_FonctionsMDT_RecuperationProduitsEnfants(
        tcomBase->instTracaCom,
        strCodeProduit,
        strIndiceProduit,
        &tabProduitsEnfantsTmp,
        &tabProduitsEnfantsLength1,
        &tabProduitsEnfantsLength2,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);

    // =======================
    // = gestion des erreurs =
    // =======================
    if(errorOccured)
    {
        if ( (errorMsg != NULL) && (errorRequete != NULL) )
            sprintf (strErreurMessage, "%s", errorMsg);
        if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        return -1;
    }
    
    // Libération mémoire
    // ------------------
    if (errorMsg != NULL)
        CDotNetFreeMemory(errorMsg);
    if (errorRequete != NULL)
        CDotNetFreeMemory(errorRequete);

    if ( *nbProduitsEnfants = tabProduitsEnfantsLength1 )
    {
        *tabProduitsEnfants = (T_PRODUIT*) malloc (sizeof(T_PRODUIT) * (*nbProduitsEnfants));
        if ( *tabProduitsEnfants == NULL )
        {
            sprintf (strErreurMessage, "Problème d'allocation mémoire");
            return -1;
        }
        for ( ii=0 ; ii<*nbProduitsEnfants ; ii++ )
        {
            strcpy ( (*tabProduitsEnfants)[ii].chVersion, tabProduitsEnfantsTmp[(ii*tabProduitsEnfantsLength2)]);
            strcpy ( (*tabProduitsEnfants)[ii].chIndice, tabProduitsEnfantsTmp[(ii*tabProduitsEnfantsLength2)+1]);
            strcpy ( (*tabProduitsEnfants)[ii].chDesignation, tabProduitsEnfantsTmp[(ii*tabProduitsEnfantsLength2)+2]);
            
            // Récupération des infos du produit enfant
            // ----------------------------------------
            TracaCom_FonctionsMDT_FonctionsMDT_RecuperationProduitInformations(
                    tcomBase->instTracaCom,
                    (*tabProduitsEnfants)[ii].chVersion,
                    (*tabProduitsEnfants)[ii].chIndice,
                    &strCodeOperateur,
                    &strCodeSousFamille,
                    &strCodeFamille,
                    &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);
            
            // Gestion des erreurs
            // -------------------
            if(errorOccured)
            {
                if ( (errorMsg != NULL) && (errorRequete != NULL) )
                    sprintf (strErreurMessage, "%s", errorMsg);
                if (errorMsg != NULL)
                    CDotNetFreeMemory(errorMsg);
                if (errorRequete != NULL)
                    CDotNetFreeMemory(errorRequete);
                if (strCodeFamille != NULL)
                    CDotNetFreeMemory(strCodeFamille);
                if (strCodeSousFamille != NULL)
                    CDotNetFreeMemory(strCodeSousFamille);
                if (strCodeOperateur != NULL)
                    CDotNetFreeMemory(strCodeOperateur);
               return -1;
            }
            
            // Enregistrement des infos
            // ------------------------
            strcpy ( (*tabProduitsEnfants)[ii].chFamille, strCodeFamille);
            strcpy ( (*tabProduitsEnfants)[ii].chSousFamille, strCodeSousFamille);
            
            // Libération mémoire
            // ------------------
            if (errorMsg != NULL)
                CDotNetFreeMemory(errorMsg);
            if (errorRequete != NULL)
                CDotNetFreeMemory(errorRequete);
            if (strCodeFamille != NULL)
                CDotNetFreeMemory(strCodeFamille);
            if (strCodeSousFamille != NULL)
                CDotNetFreeMemory(strCodeSousFamille);
            if (strCodeOperateur != NULL)
                CDotNetFreeMemory(strCodeOperateur);
        }
    }
    else
    {
        *tabProduitsEnfants = NULL;
        *nbProduitsEnfants = 0;
    }
    
    if (tabProduitsEnfantsTmp != NULL)
        CDotNetFreeMemory(tabProduitsEnfantsTmp);

    return 0;   
}

// ==============================================================================
// FONCTION : 	  TCOM_RecuperationNumSerie
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int TCOM_RecuperationNumSerie ( T_TCOM_BASE *tcomBase, 
//												  char *strNumSerie,
//												  char *strCodeProduit,
//												  char *strIndiceProduit,
//												  __int64 *lngId_NumSerie,
//												  char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_TCOM_BASE *tcomBase			: Paramètres de la base.
//				  - char *strNumSerie				: Numero de série,
//				  - char *strIndiceNumSerie			: Indice du numéro de série,
//				  - char *strCodeProduit			: Code produit,
//				  - __int64 *lngId_NumSerie			: Index en BDD du SN
//				  - char *strErreurMessage			: Message d'erreur.
/// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0   = NumSérie présent ou non présent en BDD. Fonction correctement exécutée
//				  - -1  = Erreur de fonction
// ------------------------------------------------------------------------------
// DESRIPTION :		Vérification de l'existance d'un numéro de série
//					Renvoie de l'index de la BDD si présent
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.1.0
//  DATE :		  23/12/2009
//  AUTEUR :	  EAH
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  
//  DATE :		  
//  AUTEUR :	  
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_RecuperationNumSerie ( T_TCOM_BASE *tcomBase, char *strNumSerie, char *strCodeProduit, char *strIndiceProduit, __int64 * lngId_NumSerie, char *strErreurMessage )
{
	int		errorOccured = FALSE;
	int		errorCode = 0;
	char	*errorMsg = NULL;
	char	*errorRequete = NULL;
	
	// ==============================
	// = Lancement fonction			=
	// ==============================
	TracaCom_FonctionsMDT_FonctionsMDT_RecuperationNumSerie (tcomBase->instTracaCom,
															strNumSerie,
															strCodeProduit,
															strIndiceProduit,
															lngId_NumSerie,
															&errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);

	// =======================
	// = gestion des erreurs =
	// =======================
	if (errorOccured)
	{
		if ( (errorMsg != NULL) && (errorRequete != NULL) )
			sprintf (strErreurMessage, "%s", errorMsg);
		return -1;
	}

	// ======================
	// = Libération mémoire	=
	// ======================
	if (errorMsg != NULL)
		CDotNetFreeMemory(errorMsg);
	if (errorRequete != NULL)
		CDotNetFreeMemory(errorRequete);

	return 0;
}

// ==============================================================================
// FONCTION : 	  TCOM_RecuperationNumSeriesParNumSerie
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int TCOM_RecuperationNumSeriesParNumSerie ( T_TCOM_BASE *tcomBase, 
//												  char *strNumSerie,
//												  char *strCodeProduit,
//												  char *strIndiceProduit,
//												  __int64 *lngId_NumSerie,
//												  char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_TCOM_BASE *tcomBase			: Paramètres de la base.
//				  - char *strNumSerie				: Numero de série,
//				  - char *tabNumSeries				: Tableau des Sn parents
//				  - int *NumSeriesLenght1			: Nombre  de Sn parents
//				  - int *NumSeriesLenght2			: ...
//				  - char *strErreurMessage			: Message d'erreur.
/// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0   = NumSérie présent ou non présent en BDD. Fonction correctement exécutée
//				  - -1  = Erreur de fonction
// ------------------------------------------------------------------------------
// DESRIPTION :		
//					
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  S09014AC16
//  DATE :		  14/01/2011
//  AUTEUR :	  MBH
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  
//  DATE :		  
//  AUTEUR :	  
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_RecuperationNumSeriesParNumSerie ( T_TCOM_BASE *tcomBase, char *strNumSerie, char ***tabNumSeries, int *NumSeriesLenght1, int *NumSeriesLenght2, char *strErreurMessage )
{
	int		errorOccured = FALSE;
	int		errorCode = 0;
	char	*errorMsg = NULL;
	char	*errorRequete = NULL;

	
	// ==============================
	// = Lancement fonction			=
	// ==============================
	TracaCom_FonctionsMDT_FonctionsMDT_RecuperationNumSeriesParNumSerie (tcomBase->instTracaCom,
																			 strNumSerie, "", tabNumSeries,
																			 NumSeriesLenght1,
																			 NumSeriesLenght2, &errorOccured,
																			 &errorCode, &errorMsg,
																			 &errorRequete, NULL);

	// =======================
	// = gestion des erreurs =
	// =======================
	if (errorOccured)
	{
		if ( (errorMsg != NULL) && (errorRequete != NULL) )
			sprintf (strErreurMessage, "%s", errorMsg);
		return -1;
	}

	// ======================
	// = Libération mémoire	=
	// ======================
	if (errorMsg != NULL)
		CDotNetFreeMemory(errorMsg);
	if (errorRequete != NULL)
		CDotNetFreeMemory(errorRequete);

	return 0;
}

// ==============================================================================
// FONCTION :     TCOM_RecuperationProduitNumSerie
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_RecuperationProduitNumSerie ( T_TCOM_BASE *tcomBase, 
//                                                        char *strNumSerie,
//                                                        char *strCodeProduit,
//                                                        char *strIndiceProduit,
//                                                        T_NUM_SERIE *tabNumSeriesParents,
//                                                        int *nbNumSeriesParents,
//                                                        char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase           : Paramètres de la base.
//                - char *strNumSerie               : Numero de série,
//                - char *strIndiceNumSerie         : Indice du numéro de série,
//                - char *strCodeProduit            : Code produit,
//                - T_NUM_SERIE *tabNumSeriesParents: Tableau des SN parents,
//                - int *nbNumSeriesParents         : Nombre de SN parents,
//                - char *strErreurMessage          : Message d'erreur.
/// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Passage autorisé
//                - 1 = Passage non autorisé
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Récupération des numéro de série parents d'un SN.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        30/11/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_RecuperationProduitNumSerie ( T_TCOM_BASE *tcomBase, char *strNumSerie, char *strCodeTypeProduit, char *strCodeLigneProduit, char *strCodeProduit, char *strIndiceProduit, char *strLibelleProduit, char *strErreurMessage )
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
	char    *chCodeTmp = NULL;
	char    *chIndiceTmp = NULL;
	char    *chLibelleTmp = NULL;
	int     error = 0;

    // Recuperation du Code de l'Indice et du Libelle Produit
    // ------------------------------------------------------
	TracaCom_FonctionsMDT_FonctionsMDT_RecuperationProduitNumSerie (
		tcomBase->instTracaCom,
        strNumSerie, 
		strCodeTypeProduit,
		strCodeLigneProduit, 
		&chCodeTmp,
        &chIndiceTmp, 
		&chLibelleTmp, 
		&errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);
	
	if (errorOccured)
        errChk(-1);

	// Libération mémoire + Enregistrement des infos
    // ---------------------------------------------
	if (chCodeTmp != NULL && strCodeProduit != NULL)
	{
        sprintf (strCodeProduit, "%s", chCodeTmp);
		CDotNetFreeMemory(chCodeTmp);
	}
	if (chIndiceTmp != NULL && strIndiceProduit != NULL)
	{
        sprintf (strIndiceProduit, "%s", chIndiceTmp);
		CDotNetFreeMemory(chIndiceTmp);
	}
	if (chLibelleTmp != NULL && strLibelleProduit != NULL)
	{
        sprintf (strLibelleProduit, "%s", chLibelleTmp);
		CDotNetFreeMemory(chLibelleTmp);
	}

Error: 
	
	// =======================
	// = gestion des erreurs =
	// =======================
	if (errorOccured)
	{
		if ( (errorMsg != NULL) && (errorRequete != NULL) )
			sprintf (strErreurMessage, "%s", errorMsg);
		return -1;
	}

	// ======================
	// = Libération mémoire	=
	// ======================
	if (errorMsg != NULL)
		CDotNetFreeMemory(errorMsg);
	if (errorRequete != NULL)
		CDotNetFreeMemory(errorRequete);

	return 0;
}

// ==============================================================================
// FONCTION :     TCOM_RecuperationDateHeure
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_RecuperationDateHeure ( T_TCOM_BASE *tcomBase, 
//                                                        const time_t *
//                                                        char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase           : Paramètres de la base.
//                -	const time_t *					: Date et Heure
//                - char *strErreurMessage          : Message d'erreur.
/// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Passage autorisé
//                - 1 = Passage non autorisé
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Récupération des numéro de série parents d'un SN.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S08012CA01
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
int TCOM_RecuperationDateHeure ( T_TCOM_BASE *tcomBase, T_DATE_HEURE *dateheure, char *strErreurMessage )
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
	int     error = 0;
	
    // ===========================
    // = Recuperation Date Heure =
    // ===========================
	TracaCom_FonctionsMDT_FonctionsMDT_RecuperationDateHeure (tcomBase->instTracaCom, 
															&dateheure->year, &dateheure->year2digits, &dateheure->month, &dateheure->week, &dateheure->dayweek, &dateheure->daymonth, &dateheure->dayyear, 
															&dateheure->hour, &dateheure->minute, &dateheure->second, &dateheure->millisecond, 
															&errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);
	
	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( errorMsg == NULL || errorRequete == NULL )
		errChk(TCOM_ERREUR_RESEAU);

	if (errorOccured)
        errChk(-1);
	
Error:	
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, "Impossible d'accéder au serveur tracacom");
		else if (errorMsg != NULL)
            sprintf (strErreurMessage, "%s", errorMsg);
        
		// Libération mémoire
    	// ------------------
		if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        return -1;
    }
    
    return 0;
}

int TCOM_RecuperationProprieteNumSerie ( int nItfe, T_TCOM_BASE *tcomBase, char *numserie, char *propriete, char *valpropriete, char *strErreurMessage)
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
	int     error = 0;
	char	*valeurrecup;
	__int64	idpropriete;
	T_VARIABLES_TRACA	*ptrVariablesTraca = &gSlot[nItfe].variablesTraca;
	
	// ===========================
    // = Recuperation Propriété  =
    // ===========================
		TracaCom_FonctionsMDT_FonctionsMDT_RecuperationProprieteNumSerie (tcomBase->instTracaCom, 
										numserie, 
										gPosteProduits.produits[ptrVariablesTraca->idxProduit].cie.chVersion, 
										gPosteProduits.produits[ptrVariablesTraca->idxProduit].cie.chIndice,
									  	propriete, 
									 	&valeurrecup, 
									  	&idpropriete,
									 	&errorOccured, 
									 	&errorCode,&errorMsg, &errorRequete, NULL);
	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( errorMsg == NULL || errorRequete == NULL )
		errChk(TCOM_ERREUR_RESEAU);

	if (errorOccured)
        errChk(-1);
	
	strcpy(valpropriete, valeurrecup);
	
Error:	
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, "Impossible d'accéder au serveur tracacom");
		else if (errorMsg != NULL)
            sprintf (strErreurMessage, "%s", errorMsg);
        
		// Libération mémoire
    	// ------------------
		if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        return -1;
    }
    
    return 0;
}
// ==============================================================================
// FONCTION :     TCOM_EnregistrementTrace
// ------------------------------------------------------------------------------
// PROTOTYPE :    TCOM_EnregistrementTrace ( T_TCOM_BASE *tcomBase, 
//													char *strNumserie, 
//													char *strServeur, 
//													char *strMasque, 
//													char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase           : Paramètres de la base.
//                - char *strNumserie				:
//                - char *strServeur				:
//                - char *strMasque 				:
//                - char *strErreurMessage          : Message d'erreur.
/// ------------------------------------------------------------------------------
// RETOUR :
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Récupération du masque étiquette
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S08012CA95
//  DATE :        22/08/2011
//  AUTEUR :      GCX (APSIDE)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_EnregistrementTrace ( T_TCOM_BASE *tcomBase, __int64 iIdMvtTestCie, char *strTrace, __int64 *iIdTrace, char *strErreurMessage )
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
	int     error = 0;

    // =====================================
    // = Enregistrement de la trace en Bdd =
    // =====================================
	TracaCom_FonctionsMDT_FonctionsMDT_EnregistrementTrace (
			tcomBase->instTracaCom,
			iIdMvtTestCie, 
			strTrace,
			iIdTrace, 
			&errorOccured,&errorCode, &errorMsg, &errorRequete, NULL);
	
	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( errorMsg == NULL || errorRequete == NULL )
		errChk(TCOM_ERREUR_RESEAU);
	
	if (errorOccured)
        errChk(-1);

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, "TimeOut : pb réseaux lors de la sauvgarde du log en BDD");
		else if (errorMsg != NULL)
            sprintf (strErreurMessage, "%s", errorMsg);
        
		// =============================
    	// = Libération des ressources =
    	// =============================
		if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        return -1;
    }

    return 0;
}
