#include <userint.h>
//#include "interface_test.h"

// ==============================================================================
//   COPYRIGHT (C) BMSC
//   ALL RIGHTS RESERVED.
//  
// 
// ==============================================================================
//   PROJET         : Banc Personnalisation
//   MODULE         : TracaCom
//   PROCESSEUR     : INTEL Pentium
//   ENVIRONNEMENT  : Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION    : Gestion de la DLL SCProduction interfacée avec SAP ME
//                    
// ==============================================================================
//   REMARQUES      :
// ==============================================================================
//   MODIFICATIONS  :   
//
// Version Rev X
// Date / Author
//
// S13002AA00 
// 29-Janvier-2013  MPT
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
// FONCTION :     SCPROD_Connexion
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_Connexion (  T_TCOM_BASE *tcomBase, char *strErreurMessage ) 
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base.
//                - char *strErreurMessage      : Message d'erreur/de retour.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Connexion et Configuration de la Base de données + Init DLL SAP ME. 
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        29/01/2013
//  AUTEUR :      NCR (DT2E)  / MPT pour SAP ME
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_Connexion ( T_TCOM_BASE *tcomBase, char *strErreurMessage )
{
   // Variable appel fonction SAP ME
    int     bResultSCProd = FALSE;
	int 	status;
    char    *chMsgSCProd = NULL;
    char    chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	
    // Variable appel fonction Tracacom
	int     errorOccured = 0;
    int     errorCode = 0;
    int     error = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;

 
	// ==========================================
    // = Initialisation du controlleur CVI .NET =
    // ==========================================
    
	status = Initialize_SCProduction ();
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);

    
    // ===================================================
    // = Création du handle pour communiquer avec la DLL =
    // ===================================================
    
	status = SCProduction_GestionProductions__Create (&tcomBase->instSCProduction, NULL);
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
    
	// ==========================================
    // = Connexion à la base de donnée Tracacom =
    // ==========================================

	status = SCProduction_GestionProductions_ConfigurationBase (
		tcomBase->instSCProduction,
		tcomBase->nomServeur, 
		tcomBase->portServeur, 
		tcomBase->nomBase, 
		tcomBase->loginServeur, 
		gPosteInfos.chNom,
		tcomBase->iServeurDebug, 
		&errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);

	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (errorMsg) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (errorMsg != NULL)
	{
		strcpy(chMsgTemp,errorMsg);
        CDotNetFreeMemory(errorMsg);
	}
	
	// On libère la mémoire .NET
	// -------------------------
	if (errorRequete != NULL)
	{
        CDotNetFreeMemory(errorRequete);
	}

	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (errorOccured != 0)
		errChk(SCPROD_ERREUR_BRESULT);
	
	
	// ================================================================
    // = Chargement paramètres INI + test Connexion au Serveur SAP ME =
    // ================================================================

	status = SCProduction_GestionProductions_InitialisationParametresGestMES (
		tcomBase->instSCProduction,
		FIC_CONFIG_SAP_ME_NOM,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);
	
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	
	
	
	// ===============================
    // = APPEL DE TEST !!  =
    // ===============================  
	
		//	SCPROD_LogNC(	2, &gTcomBase, SCPROD_OPERATION_PERSO, "06_PERSO_01_03", chMsgSCProd ) ;
		//FCT_TEST_EnregistrementAffichageTempsTest (&gTcomBase);
		
							
Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
	}
     
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;			   

    return 0;
}



// ==============================================================================
// FONCTION :     SCPROD_Deconnexion
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_Deconnexion ( T_TCOM_BASE *tcomBase )
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
int SCPROD_Deconnexion ( T_TCOM_BASE *tcomBase )
{
    int     errorOccured = FALSE;
    int     errorCode = FALSE;
    char    *errorMsg = NULL;
	
	// =====================================
    // = Fermeture du controlleur CVI .NET =
	// =====================================
 
	SCProduction_GestionProductions_DeconnexionBase 
		(tcomBase->instSCProduction, 
		&errorOccured, 
		&errorCode, 
		&errorMsg, NULL); 
	
 	Close_SCProduction();
	
	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( errorMsg == NULL )
		errorOccured = TRUE;
	
	if (errorOccured == TRUE)
    {
        // Libération des ressources
        // -------------------------
        if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        return -1;
    }
    else
		return 0;

}

// ==============================================================================
// FONCTION :     SCPROD_PosteInformations
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_PosteInformations (  T_TCOM_BASE *tcomBase, 
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
int SCPROD_PosteInformations ( T_TCOM_BASE *tcomBase, T_POSTE_INFOS *posteInfos, char *strErreurMessage )
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    int     error = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;				
    char    *chLibelleLigne = NULL;
    char    *chDescriptionLigne = NULL;
	
    // ===============================
    // = Extraction du type du poste =
    // ===============================
		

    SCProduction_GestionProductions_RecuperationLigneProductionParPoste(
        tcomBase->instSCProduction,
        posteInfos->chNom,
        &chLibelleLigne,
        &chDescriptionLigne,
        &posteInfos->numLigne,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);	   
	


	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( chLibelleLigne == NULL || chDescriptionLigne == NULL || errorMsg == NULL || errorRequete == NULL)
		errChk(TCOM_ERREUR_RESEAU);
	
    if (errorOccured || posteInfos->numLigne == -1)
        errChk(-1);
	
    if (chLibelleLigne != NULL)
	{
        strcpy ( posteInfos->chLibelleLigne, chLibelleLigne);
		
		// Libération des ressources
    	// -------------------------
		CDotNetFreeMemory(chLibelleLigne);
	}

    if (chDescriptionLigne != NULL)
	{
		strcpy ( posteInfos->chDescriptionLigne, chDescriptionLigne); 
		
	    // Libération des ressources
    	// -------------------------
		CDotNetFreeMemory(chDescriptionLigne);
	}

Error:
	
    // =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
		else if ( errorMsg != NULL )
            strcpy (strErreurMessage, errorMsg);
        else
            sprintf (strErreurMessage, GET_MESSAGE(TRC_MSG_ERR_INCONNU)); 
    }   
	
    // Libération des ressources
    // -------------------------
    if (errorMsg != NULL)
        CDotNetFreeMemory(errorMsg);
    if (errorRequete != NULL)
        CDotNetFreeMemory(errorRequete);
        
    if(error)
        return -1;
	
    
    return 0;
}

// ==============================================================================
// FONCTION :     SCPROD_ProduitsPoste
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_ProduitsPoste (  T_TCOM_BASE *tcomBase, 
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
int SCPROD_ProduitsPoste ( T_TCOM_BASE *tcomBase, T_POSTE_INFOS *posteInfos, T_POSTE_PRODUITS *posteProduits, char *strErreurMessage )
{
    int         errorOccured = FALSE;
    int         errorCode = 0;
    int         nLongueur2;
    int         error = 0;
    int         ii;
	char		chMsg[TAILLE_MAX_CHAINE];
    char        *errorMsg = NULL;
    char        *errorRequete = NULL;
    char        **tabProduit = NULL;

    // ====================================
    // = Extraction des produits du poste =
    // ====================================
	
	// Lock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);

	
   SCProduction_GestionProductions_RecuperationProduitsParPoste(
        tcomBase->instSCProduction,
        posteInfos->chNom,
        &tabProduit,
        &posteProduits->nbProduit,
        &nLongueur2,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);
	
	// Unlock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);
	
	
	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( tabProduit == NULL || errorMsg == NULL || errorRequete == NULL)
		errChk(TCOM_ERREUR_RESEAU);
	
    if (errorOccured)
        errChk(-1);
    
	// Allocation dynamique du Nbre de produit
	// ---------------------------------------
	posteProduits->produits = (T_POSTE_PRODUIT*) malloc (sizeof(T_POSTE_PRODUIT) * (posteProduits->nbProduit)); 
	
    

	
	// =================================
    // = Extraction des infos produits =
    // =================================
    for ( ii=0 ; ii<posteProduits->nbProduit ; ii++ )
    {
		
		if (gNPAbort == TRUE)
			errChk (-1);
			
		// Mise à jour Message IHM 
		// -----------------------
		ProcessDrawEvents ();
  		ProcessSystemEvents ();		
		sprintf (chMsg,GET_MESSAGE(PNL_INTIT_SLIDE_TEXT_PRODUCT),ii+1, posteProduits->nbProduit);
		SetCtrlAttribute (PnlProduitId, PNL_INTIT_TXT_SLIDE, ATTR_CTRL_VAL, chMsg);
		SetCtrlVal (PnlProduitId, PNL_INTIT_SLIDE, (100  * (ii+1) ) / (posteProduits->nbProduit));
		

		// On sette les parents à NULL
		// ---------------------------
		posteProduits->produits[ii].parent = NULL;	
		
		
		// On ne tient compte que des produits dont le code est différent de 0
        // -------------------------------------------------------------------
        if ( atoi (tabProduit[(ii*nLongueur2)]) > 0 )
        {
            // Code CIE
            // --------
            strcpy (posteProduits->produits[ii].cie.chVersion, tabProduit[(ii*nLongueur2)+0]);

            // Indice CIE
            // ----------
            strcpy (posteProduits->produits[ii].cie.chIndice, tabProduit[(ii*nLongueur2)+1]);
        
            // Désignation CIE
            // ---------------
            strcpy (posteProduits->produits[ii].cie.chDesignation, tabProduit[(ii*nLongueur2)+2]);
			
			// Famille CIE
            // -----------
			strcpy (posteProduits->produits[ii].cie.chFamille, "");
			
			// Sous Famille CIE
            // ----------------
			strcpy (posteProduits->produits[ii].cie.chSousFamille, "");	
            
            // Code SFIN
            // ---------
            strcpy (posteProduits->produits[ii].sfin.chVersion, tabProduit[(ii*nLongueur2)+3]);
            
            // Indice SFIN
            // -----------
            strcpy (posteProduits->produits[ii].sfin.chIndice, tabProduit[(ii*nLongueur2)+4]);
        
            // Désignation SFIN
            // ----------------
            strcpy (posteProduits->produits[ii].sfin.chDesignation, tabProduit[(ii*nLongueur2)+5]);
			
			// Famille SFIN
            // ------------
			strcpy (posteProduits->produits[ii].sfin.chFamille, "");
			
			// Sous Famille SFIN
            // -----------------
			strcpy (posteProduits->produits[ii].sfin.chSousFamille, "");
			
			// RAZ valeur de Lot
            // -----------------
            posteProduits->produits[ii].lot = 0;
        
            // RAZ valeur de Palette
            // ---------------------
            posteProduits->produits[ii].palette = 0;
        
            // =======================================
            // = Récupération Infos Produits parents =
            // =======================================
            errChk ( TCOM_RecuperationProduitsParents ( 
                            tcomBase,
                            posteProduits->produits[ii].sfin.chVersion,
                            posteProduits->produits[ii].sfin.chIndice,
                            &posteProduits->produits[ii].parent,
                            &posteProduits->produits[ii].nbParent,
                            strErreurMessage ));  
            
            if ( posteProduits->produits[ii].nbParent > 0 )
            {
                // Code PFIN
                // ---------
                strcpy (posteProduits->produits[ii].pfin.chVersion, posteProduits->produits[ii].parent[0].chVersion);

                // Indice PFIN
                // -----------
                strcpy (posteProduits->produits[ii].pfin.chIndice, posteProduits->produits[ii].parent[0].chIndice);

                // Désignation PFIN
                // ----------------
                strcpy (posteProduits->produits[ii].pfin.chDesignation, posteProduits->produits[ii].parent[0].chDesignation);
            }
            else
            {
				// Code PFIN
                // ---------
                strcpy (posteProduits->produits[ii].pfin.chVersion, "");

                // Indice PFIN
                // -----------
                strcpy (posteProduits->produits[ii].pfin.chIndice, "");

                // Désignation PFIN
                // ----------------
                strcpy (posteProduits->produits[ii].pfin.chDesignation, "");

            }
			
			// Famille PFIN
        	// ------------
			strcpy (posteProduits->produits[ii].pfin.chFamille, "");
		
			// Sous Famille PFIN
        	// -----------------
			strcpy (posteProduits->produits[ii].pfin.chSousFamille, "");
            
            // =======================================
            // = Récupération Infos Produits enfants =
            // =======================================
            
            errChk ( TCOM_RecuperationProduitsEnfants (
                            tcomBase,
                            posteProduits->produits[ii].sfin.chVersion,
                            posteProduits->produits[ii].sfin.chIndice,
                            &posteProduits->produits[ii].enfant,
                            &posteProduits->produits[ii].nbEnfant,
                            strErreurMessage ) 
                    );  
        }
		else
		{
			// Code CIE
            // --------
            strcpy (posteProduits->produits[ii].cie.chVersion, "");

            // Indice CIE
            // ----------
            strcpy (posteProduits->produits[ii].cie.chIndice, "");
        
            // Désignation CIE
            // ---------------
            strcpy (posteProduits->produits[ii].cie.chDesignation, "");
			
			// Famille CIE
            // -----------
			strcpy (posteProduits->produits[ii].cie.chFamille, "");
			
			// Sous Famille CIE
            // ----------------
			strcpy (posteProduits->produits[ii].cie.chSousFamille, "");	
            
            // Code SFIN
            // ---------
            strcpy (posteProduits->produits[ii].sfin.chVersion, "");
            
            // Indice SFIN
            // -----------
            strcpy (posteProduits->produits[ii].sfin.chIndice, "");
        
            // Désignation SFIN
            // ----------------
            strcpy (posteProduits->produits[ii].sfin.chDesignation, "");
			
			// Famille SFIN
            // ------------
			strcpy (posteProduits->produits[ii].sfin.chFamille, "");
			
			// Sous Famille SFIN
            // -----------------
			strcpy (posteProduits->produits[ii].sfin.chSousFamille, "");
			
			// Code PFIN
            // ---------
            strcpy (posteProduits->produits[ii].pfin.chVersion, "");

            // Indice PFIN
            // -----------
            strcpy (posteProduits->produits[ii].pfin.chIndice, "");

            // Désignation PFIN
            // ----------------
            strcpy (posteProduits->produits[ii].pfin.chDesignation, "");

			// Famille PFIN
        	// ------------
			strcpy (posteProduits->produits[ii].pfin.chFamille, "");
		
			// Sous Famille PFIN
        	// -----------------
			strcpy (posteProduits->produits[ii].pfin.chSousFamille, "");
		}
    }

Error:
    // Libération des ressources
    // -------------------------
    if (tabProduit != NULL)
		CDotNetFreeMemory(tabProduit);
        
    // =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
		else if ( errorMsg != NULL )
            strcpy (strErreurMessage, errorMsg);
        else
            sprintf (strErreurMessage, GET_MESSAGE(TRC_MSG_POPUP_1));
    }   
    
    // Libération des ressources
    // -------------------------
    if (errorMsg != NULL)
        CDotNetFreeMemory(errorMsg);
    if (errorRequete != NULL)
        CDotNetFreeMemory(errorRequete);
        
    if(error)
        return -1;
    
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
// FONCTION :     SCPROD_GenerationSnClient
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_GenerationSnClient ( T_TCOM_BASE *tcomBase, 
//                                              char *strFormatClient,
//												char *strNumSerie,
//                                              char *strSnClient,
//                                              char *strErreurMessage,
//                                              int nbParam,
//                                              ... )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase   : Paramètres de la base.
//				  - char *strNumSerie		: SN auquel on associe le Sn Client
//                - char *strFormatClient   : Format du SN à générer, (== Code Article sur SAP ME)
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
//  VERSION :     S13002AA00
//  DATE :        18/02/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Modifiée pour SAP ME - REnommée en SCPROD_GenerationSnClient
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_GenerationSnClient (int nItfe, T_TCOM_BASE *tcomBase, char *strNumSerie, char *strFormatClient, char *strSnClient, char *strErreurMessage, int nbParam, ... )
{
 	// Variables fonction
	int     			error = 0;
	int					iExistenceSnClient = -1;
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);

  	// Variables pour appel à fonction DLL SAP ME
    int 				bResultSCProd = FALSE;
	int 				status = - 1;
    char   			 	*chMsgSCProd = NULL;
	char 				*NumSerieClient = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
 
	
    // Variables pour la gestion des paramètres
	char    			**tabParametres = NULL;
    int     			idxParam;
    va_list 			list;
	
	
	// Affichage Dans le log du Sn Client
	// ----------------------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Génération du Sn Client : %s en cours...", strFormatClient);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	
	
	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strSnClient,"");
	strcpy(strErreurMessage,"");
	
	
    // ===========================================
    // = Vérification si Sn Client déjà assemblé =
    // ===========================================
	
	errChk ( SCPROD_RecuperationComposant ( 	nItfe,
    			                            	&gTcomBase,
                                    			ptrVariablesTraca->PfinSfcSAPME,
												strFormatClient,
												strSnClient,
												&iExistenceSnClient,
                                    			strErreurMessage )); 

	
    // ========================================
    // = Génération du numéro de série du STB =
    // ========================================
	if (iExistenceSnClient == 0)
	{
	
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

		
    // =================================================================================
    // = Appel Fonction génération de la DLL qui génére avec mise en stock directement =
    // =================================================================================

		SCPROD_TraceAppels	(nItfe,"Génération SnClient : Debut");
		
		status = SCProduction_GestionProductions_GenerationSFC(
	    	tcomBase->instSCProduction,
			strFormatClient,
			SCPROD_INDICE_DEFAUT,
	        &NumSerieClient,
	        &bResultSCProd,
			&chMsgSCProd,
			NULL);
		
  		SCPROD_TraceAppels	(nItfe,"Génération SnClient : Fin  ");


	/*	// AVEC CETTE FONCTION, ON A EGALEMENT L'ASSEMBLAGE QUI EST EFFECTUE  ==> Non Fonctionnelle à un moment donc abandonnée
		status = SCProduction_GestionProductions_GenerationNSClient(
	    	tcomBase->instSCProduction,
			ptrVariablesTraca->PfinSfcSAPME,
			strFormatClient,
	        &NumSerieClient,
	        &bResultSCProd,
			&chMsgSCProd,
			NULL);*/
		
		
	    // Libération mémoire des paramètres
	    // ---------------------------------
	    for ( idxParam=0 ; idxParam<nbParam ; idxParam++ )
	    {
	        free (tabParametres[idxParam]);
	    }
	    free (tabParametres);
	

		// On vérifie la longueur du message retourné
		// ------------------------------------------
		if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
			errChk(SCPROD_ERREUR_LONG_MSG);

		// On recopie le message puis on libère la mémoire .NET
		// ----------------------------------------------------
		if (chMsgSCProd != NULL)
		{
			strcpy(chMsgTemp,chMsgSCProd);
	        CDotNetFreeMemory(chMsgSCProd);
		}
	
		// Si le status est mal passé ==> erreur .NET
		// ------------------------------------------
		if (status != 0)
			errChk(SCPROD_ERREUR_DOT_NET);
	
		// Si le bResult est mal passé ==> erreur fonction DLL
		// ---------------------------------------------------
	 	if (bResultSCProd != TRUE)
			errChk(SCPROD_ERREUR_BRESULT);
	
		// On récupère le SnClient puis on libère la mémoire .NET 
		// ------------------------------------------------------
		if (NumSerieClient != NULL)
		{
			
			strcpy(strSnClient ,NumSerieClient);
	        CDotNetFreeMemory(NumSerieClient);
		
			// Si jamais le Sn Client n'a pas été complété
			// ----------------------------------------
			if (strlen(strSnClient) == 0)
			{
				strcpy( chMsgTemp, "le numéro de série retourné est vide");
				errChk(-1);
			}
		}
		else
		{
			strcpy( chMsgTemp, "le numéro de série retourné est vide");
			errChk(-1);
		}
	
		
	    // ==================================================================
	    // = Si génération bien effectué, on assemble le SnClient au SnPFIN =   (sauf si déjà effectué avec l'autre fonction)
	    // ==================================================================
	
		errChk ( SCPROD_AssemblageComposant ( 	nItfe,
        			                            &gTcomBase,
                                        		strSnClient,
                                        		NULL,
												ptrVariablesTraca->PfinSfcSAPME,
												SCPROD_ASSEMBLAGE_INVENTORY_ID,
												NOM_OPERATION,
												ptrVariablesTraca->NomRessourceSAPME,
                                        		strErreurMessage )); 
	}
	
    // =========================================================
    // = S'il existe déjà on l'a déjà récupèré et on le loggue =
    // =========================================================
	else
	{  
		// Affichage Dans le log du Sn Client
		// ----------------------------------
		if (gFlagLogSAPME == TRUE )
		{
			sprintf (chMsgInfo, "Sn client :%s est déjà assemblé sur le SFC : %s", strSnClient,ptrVariablesTraca->PfinSfcSAPME);
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}

	}	
	
	

	
Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
	
   
	

	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
	{ 
		return -1;
	}
	
	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	sprintf(strErreurMessage, "Retour DLL : %s", chMsgTemp);  
	
	// Affichage Dans le log du Sn Client
	// ----------------------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Génération/Récupération Sn client : %s OK.\n", strSnClient);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	return 0;
}



// ==============================================================================
// FONCTION :     SCPROD_LiberationSnPFIN
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_LiberationSnPFIN ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//                                              char *OrdreFabrication,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *OrdreFabrication	    : OF sur lequel on libère le SnPFIN
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Appel à la fonction effectuant Une libération unitaire de SnPFIN
//
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA04
//  DATE :        11/07/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_LiberationSnPFIN ( int nItfe, T_TCOM_BASE *tcomBase, char *OrdreFabrication, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status = -1;
    char    			*chMsgSCProd = NULL;
	char 				*NumSerie = NULL;
    //char    			chNumSerieLocal [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	

	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strErreurMessage,"");

	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Libération Sn PFIN En cours.");
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Libération SNPFIN : Début");
	
	status =  SCProduction_GestionProductions_GenerationSFCdepuisOF(
		tcomBase->instSCProduction,
		OrdreFabrication,
		&NumSerie,
		&chMsgSCProd,
		&bResultSCProd,
		NULL);

	SCPROD_TraceAppels	(nItfe,"Libération SNPFIN : Fin  ");

	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	
	
	// On récupère le SnPFIN / SnSFIN puis on libère la mémoire .NET 
	// -------------------------------------------------------------
	
	if (NumSerie != NULL)
	{
			
		strcpy(ptrVariablesTraca->PfinSfcSAPME ,NumSerie);
      	CDotNetFreeMemory(NumSerie);
		
		// Si jamais le SnPFIN n'a pas été complété
		// ----------------------------------------
		if (strlen(ptrVariablesTraca->PfinSfcSAPME) == 0)
		{
			strcpy( chMsgTemp, "le numéro de série retourné est vide");
			errChk(-1);
		}
	}
	else
	{
		strcpy( chMsgTemp, "le numéro de série retourné est vide");
		errChk(-1);
	}
	
	
Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       	else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       	else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    

	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Libération Pfin effectuée sur SFC %s. Retour DLL: %s ", ptrVariablesTraca->PfinSfcSAPME, chMsgTemp );
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

    return 0;
}




// ==============================================================================
// FONCTION :     SCPROD_GenerationStartSnPFIN
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_GenerationStartSnPFIN ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//                                              char *codeProduit,
//                                              char *indiceProduit,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *codeProduit		    : Code produit sur lequel on demande de génèrer le PFIN,
//                - char *indiceProduit   		: Indice produit sur lequel on demande de génèrer le PFIN,
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Appel à la fonction effectuant le Start By Item.
//
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        31/01/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_GenerationStartSnPFIN ( int nItfe, T_TCOM_BASE *tcomBase, char *codeProduit, char *indiceProduit, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status = -1;
    char    			*chMsgSCProd = NULL;
	char 				*NumSerie = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	

	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strErreurMessage,"");

	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Génération (Start By Item) Pfin En cours. Ressource par défaut - Opération par défaut.");
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	// Prise Sémaphore
    // ---------------
    //CmtGetLock (IdStartSfc);
 
	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Génération SNCIE - Start By ITEM : Début");
	
	status = SCProduction_GestionProductions_DebutOperationAvecGenerationSFC (
		tcomBase->instSCProduction,
		codeProduit,
		SCPROD_OPERATION_DEFAUT,
		SCPROD_RESSOURCE_DEFAUT,    // On fait le Start By Item avec la ressource par défaut
		indiceProduit,
		&NumSerie,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);

	SCPROD_TraceAppels	(nItfe,"Génération SNCIE - Start By ITEM : Fin  ");

    // Libération Sémaphore
    // --------------------
    //CmtReleaseLock (IdStartSfc);

	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	
	
	// On récupère le SnPFIN / SnSFIN puis on libère la mémoire .NET 
	// -------------------------------------------------------------
	
	if (NumSerie != NULL)
	{
			
		strcpy(ptrVariablesTraca->PfinSfcSAPME ,NumSerie);
        CDotNetFreeMemory(NumSerie);
		
		// Si jamais le SnPFIN n'a pas été complété
		// ----------------------------------------
		if (strlen(ptrVariablesTraca->PfinSfcSAPME) == 0)
		{
			strcpy( chMsgTemp, "le numéro de série retourné est vide");
			errChk(-1);
		}
	}
	else
	{
		strcpy( chMsgTemp, "le numéro de série retourné est vide");
		errChk(-1);
	}
	
	
Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       	else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       	else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    

	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Génération Pfin effectuée sur SFC %s. Retour DLL: %s ", ptrVariablesTraca->PfinSfcSAPME,chMsgTemp );
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

    return 0;
}


// ==============================================================================
// FONCTION :     SCPROD_StartSnPFIN
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_StartSnPFIN ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//                                              char *Operation,
//                                              char *Ressource,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *Operation     		: Opération Utilisée pour le Start
//                - char *Ressource   			: Ressource Utilisée pour le Start,
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Start sur SFC Pfin - correspondant à une autorisation de passage.
//				  Plusieurs opérations et ressources dans la gamme SAP ME 
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        04/02/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_StartSnPFIN ( int nItfe, T_TCOM_BASE *tcomBase,char *Operation, char *Ressource, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
    char    			*chMsgSCProd = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);

	
	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strErreurMessage,"");
	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Start en cours sur SFC %s. Ressource: %s. Opération: %s ", ptrVariablesTraca->PfinSfcSAPME,Ressource,Operation ); 
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	

	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"SNPFIN - Start : Début");
	
	status = SCProduction_GestionProductions_DebutOperation (
		tcomBase->instSCProduction,
		ptrVariablesTraca->PfinSfcSAPME,
		Ressource, 
		Operation,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);

	SCPROD_TraceAppels	(nItfe,"SNPFIN - Start : Fin  ");
	
	
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       	else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       	else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;
	
	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Start effectué sur SFC %s. Retour DLL: %s.\n", ptrVariablesTraca->PfinSfcSAPME,chMsgTemp );
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}


    return 0;
}
	
// ==============================================================================
// FONCTION :     SCPROD_StartSnPFIN
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_StartSnPFIN ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//                                              char *Operation,
//                                              char *Ressource,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *Operation     		: Opération Utilisée pour le Start
//                - char *Ressource   			: Ressource Utilisée pour le Start,
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Start sur SFC Pfin - correspondant à une autorisation de passage.
//				  Plusieurs opérations et ressources dans la gamme SAP ME 
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        04/02/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_StartSnCIE ( int nItfe, T_TCOM_BASE *tcomBase,char *Operation, char *Ressource, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
    char    			*chMsgSCProd = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);

	
	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strErreurMessage,"");
	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Start en cours sur SFC %s. Ressource: %s. Opération: %s ", ptrVariablesTraca->CiuSfcSAPME,Ressource,Operation ); 
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	

	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"SNCIE - Start : Début");
	
	status = SCProduction_GestionProductions_DebutOperation (
		tcomBase->instSCProduction,
		ptrVariablesTraca->CiuSfcSAPME,
		Ressource, 
		Operation,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);

	SCPROD_TraceAppels	(nItfe,"SNCIE - Start : Fin  ");
	
	
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       	else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       	else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;
	
	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Start effectué sur SFC %s. Retour DLL: %s.\n", ptrVariablesTraca->CiuSfcSAPME,chMsgTemp );
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}


    return 0;
}


// ==============================================================================
// FONCTION :     SCPROD_SignoffSnPFIN
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_SignoffSnPFIN ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//                                              char *Operation,
//                                              char *Ressource,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *Operation     		: Opération Utilisée pour le Start
//                - char *Ressource   			: Ressource Utilisée pour le Start,
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   SignOff sur SnPFin - Correspond à une remise en attente de l'opération en cours
//				  
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA01
//  DATE :        04/06/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_SignoffSnPFIN ( int nItfe, T_TCOM_BASE *tcomBase,char *Operation, char *Ressource, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
    char    			*chMsgSCProd = NULL;
    char    			*chCodeRetour = NULL;
    char    			*chStepRetour = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);

	
	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strErreurMessage,"");
	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "SignOff en cours sur SFC %s. Ressource: %s. Opération: %s ", ptrVariablesTraca->PfinSfcSAPME,Ressource,Operation ); 
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	

	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"SNPFIN - SignOff : Début");
	
	status = SCProduction_GestionProductions_Signoff (
		tcomBase->instSCProduction,
		ptrVariablesTraca->PfinSfcSAPME,
		Ressource, 
		Operation,
		"",  						// ==> C'est l'indice de l'opération. Laisser Vide pour prendre l'indice de l'opération par défaut
		&chCodeRetour,
		&chStepRetour,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);

	SCPROD_TraceAppels	(nItfe,"SNPFIN - SignOff : Fin  ");
	
	
	// On libère la mémoire .NET
	// -------------------------
	if (chCodeRetour != NULL)
        CDotNetFreeMemory(chCodeRetour);

	if (chStepRetour != NULL)
        CDotNetFreeMemory(chStepRetour);

	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       	else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       	else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;
	
	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "SignOff effectué sur SFC %s. Retour DLL: %s.\n", ptrVariablesTraca->PfinSfcSAPME,chMsgTemp );
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}


    return 0;
}


// ==============================================================================
// FONCTION :     SCPROD_RecuperationSFCDepuisComposant
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_RecuperationSFCDepuisComposant ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//                                              char *Composant,
//                                              char *SFC,
//                                              int *iExistenceSFC ,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *Composant	     		: Composant recherché
//                - char *SFC					: Le SFC Retourné
//				  - int  *iExistenceSFC			: Indicateur sur l'existence du SFC parent/composant
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Récupération du SFC sur lequel est rattaché un composant
//
//					Codes Retour :
//					1. 	SFC n'existe pas
//					2.	SFC existe mais pas de parent
//					4.	SFC existe et parent trouvé
//
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        06/03/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_RecuperationSFCDepuisComposant ( int nItfe, T_TCOM_BASE *tcomBase, char *Composant, char *SFC, int *iExistenceSFC, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
    char    			*chMsgSCProd = NULL;
    char    			*chCodeRetour = NULL;  
    char    			*chSFCRetour = NULL;  
	char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
 	char    			chCodeRetourTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 

	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(SFC,"");
	strcpy(strErreurMessage,"");
	*iExistenceSFC = -1;
	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Récupération SFC pour le Composant : %s en cours. ", Composant ); 
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Récupération SFC Depuis Composant : Début");
	
	// Lock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);	
	
	status = SCProduction_GestionProductions_RecuperationSFCdepuisComposantV2(
		tcomBase->instSCProduction,
		"",		  // Ce paramètre doit être égal à "" pour pouvoir utiliser l'autre paramètre de la fonction
		Composant,
		&chSFCRetour,
		&chCodeRetour,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);
	
	
	// Unlock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);		
	
	SCPROD_TraceAppels	(nItfe,"Récupération SFC Depuis Composant : Fin  ");
			 
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}

	// On recopie le Code Retour puis on libère la mémoire .NET
	// --------------------------------------------------------
	if (chCodeRetour != NULL)
	{
		strcpy(chCodeRetourTemp,chCodeRetour);
        CDotNetFreeMemory(chCodeRetour);
	}

	// On récupère le SFC puis on libère la mémoire .NET 
	// --------------------------------------------------
	
	if (chSFCRetour != NULL)
	{
		strcpy(SFC,chSFCRetour);
        CDotNetFreeMemory(chSFCRetour);
	}
	
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	//if (bResultSCProd != TRUE)
	//	errChk(SCPROD_ERREUR_BRESULT);
	
	// On regarde si le SFC Parent existe avec retour -1 si le Composant n'existe pas
	// -----------------------------------------------------------------------------
	if (FindPattern (chCodeRetourTemp,0,strlen(chCodeRetourTemp),"4",0,0) != -1)
		*iExistenceSFC = 1;
	else if (FindPattern (chCodeRetourTemp,0,strlen(chCodeRetourTemp),"2",0,0) != -1)
		*iExistenceSFC = 0;
	else if (FindPattern (chCodeRetourTemp,0,strlen(chCodeRetourTemp),"1",0,0) != -1)
		*iExistenceSFC = -1;
	else
		errChk(SCPROD_ERREUR_BRESULT); 



	
Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       	else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       	else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;
	
	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Récupération SFC terminée. Code Retour DLL : %s. SFC récupéré : %s. Retour DLL : %s", chCodeRetourTemp, SFC,chMsgTemp); 
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);


    return 0;
	
}



// ==============================================================================
// FONCTION :     SCPROD_LogNC
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_LogNC ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//												char *Operation,	
//												char *Ressource,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *Operation     		: Opération Utilisée 
//                - char *Ressource   			: Ressource Utilisée 
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Enregistrement d'une non conformité
//				  Correspond à un mouvement de test KO 
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        18/02/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_LogNC ( int nItfe, T_TCOM_BASE *tcomBase, char *Operation, char *Ressource, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
    char    			*chMsgSCProd = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	char                res [SCPROD_MSG_LONG_MAX] = ""; 
	char                *operationout= NULL;  
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	

	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strErreurMessage,"");

	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Enregistrement non conformité en cours. Opération : %s - Ressource : %s ", Operation, Ressource ); 
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Enregistrement Non Conformité : Début");
	
	
	status = SCProduction_GestionProductions_EnregistrementNonConformite (
		tcomBase->instSCProduction,
		ptrVariablesTraca->CiuSfcSAPME,
		Operation,
		Ressource, 
		SCPROD_CODE_NON_CONF_BTF,
		ptrVariablesTraca->chLibelleErreur,
		Code_Erreur,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);      

/* status = SCProduction_GestionProductions_EnregistrementNonConformiteV2 (
				 tcomBase->instSCProduction,
				 ptrVariablesTraca->CiuSfcSAPME,
				 Operation,
				 Ressource,
				 SCPROD_CODE_NON_CONF_BTF,
				 ptrVariablesTraca->chLibelleErreur,
				 SCPROD_STR_VIDE,
				 &bResultSCProd,
				 &operationout,
				 &chMsgSCProd,
				 NULL); */

	//strcpy (res,operationout);
	if ((FindPattern (res,0,strlen(res),"depannage",0,0) != -1))
    {
		SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_LABEL_TEXT, "ALLEZ AU POSTE DEPANNAGE");
		SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_BLUE);
		SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE); 
		SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_DEPANNAGE, ATTR_VISIBLE, 1);
		SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_RETEST, ATTR_VISIBLE, 0);

	}				  
	else
    {
		SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_LABEL_TEXT, "TEST KO");
		SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, ATTR_ON_COLOR, VAL_RED);
		SetCtrlVal (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_LED, TRUE); 
		SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_DEPANNAGE, ATTR_VISIBLE, 0);
		SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_RETEST, ATTR_VISIBLE, 1);

	}			
	
	SCPROD_TraceAppels	(nItfe,"Enregistrement Non Conformité : Fin  ");
			 
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	
	
Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);	
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Enregistrement non conformité effectué. Retour DLL: %s",chMsgTemp); 
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);
	
    return 0;
}


// ==============================================================================
// FONCTION :     SCPROD_CollectSFCData
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_CollectSFCData ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//                                              char *SFC, 
//                                              char *NomPropriete,
//                                              char *ValeurPropriete,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *SFC      				: SFC sur lequel on veut enregistrer,
//                - char *NomPropriete      	: Nom de la propriété à collecter,
//                - char *ValeurPropriete      	: Valeur de le propriété,
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Enregistrement d'une propriété
//				  
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        07/03/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_CollectSFCData ( int nItfe, T_TCOM_BASE *tcomBase, char *SFC, char *NomPropriete, char *ValeurPropriete, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
    char    			*chMsgSCProd = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	

	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strErreurMessage,"");

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Collecte de la donnée : %s avec la valeur %s pour le SFC %s en cours.", NomPropriete,ValeurPropriete,SFC );
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Collect SFC Data : Début");
	
	status = SCProduction_GestionProductions_EnregistrementProprieteNumSerie(
		tcomBase->instSCProduction,
		SFC,
		NomPropriete,
		ValeurPropriete,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);

	SCPROD_TraceAppels	(nItfe,"Collect SFC Data : Fin  ");
	
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Collecte de la donnée : %s OK.\n", NomPropriete );
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	
	
    return 0;
}

// ==============================================================================
// FONCTION :     SCPROD_CollectSFCDataTableau
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_CollectSFCDataTableau ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//                                              char *SFC, 
//                                              char **Tableau,
//                                              char * Lg1,
//                                              char * Lg2,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *SFC      				: SFC sur lequel on veut enregistrer,
//                - char **Tableau      		: Le tableau à enregistrer,
//                - char *Lg1			      	: Longueur 1 du tableau,
//                - char *Lg2			      	: Longueur 2 du tableau,
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Enregistrement d'un tableau de propriétés
//				  
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA05
//  DATE :        15/07/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_CollectSFCDataTableau ( int nItfe, T_TCOM_BASE *tcomBase, char *SFC, char **Tableau, int Lg1, int Lg2, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
    char    			*chMsgSCProd = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	

	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strErreurMessage,"");


	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Collect SFC Data Tableau: Début");
	
	
	status = SCProduction_GestionProductions_EnregistrementProprietesNumSerie(
		tcomBase->instSCProduction,
		SFC,
		Tableau,
		Lg1,
		Lg2,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);
	

	SCPROD_TraceAppels	(nItfe,"Collect SFC Data Tableau: Fin  ");
	
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Collecte des données OK.\n");
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	
	
    return 0;
}


// ==============================================================================
// FONCTION :     SCPROD_LogParametricData
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_LogParametricData ( int nItfe,
//                                              int IndexMesure, 
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - int IndexMesure             : Identifiant de la mesure
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Enregistrement d'une mesure vers SAP ME
//				  
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        07/03/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_LogParametricData ( int nItfe, int IndexMesure, char *strErreurMessage )   
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
    char    			*chMsgSCProd = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chComment [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char 				chValeur[32] = {'\0'};
    char 				chLimiteInferieure[32] = {'\0'};
    char 				chLimiteSuperieure[32] = {'\0'};
	T_MESURES           *ptrMesures = &(gSlot[nItfe].mesures);
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	

	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strErreurMessage,"");
	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Enregistrement de la mesure : %s en cours. (Statut : %s)", ptrMesures->mesures[IndexMesure].nom,ptrMesures->mesures[IndexMesure].status );
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	// Mise en forme des paramètres d'enregistrement
    // ---------------------------------------------
    sprintf (chValeur, "%f", ptrMesures->mesures[IndexMesure].mesure);
    sprintf (chLimiteInferieure, "%f", ptrMesures->mesures[IndexMesure].limiteInferieure);
    sprintf (chLimiteSuperieure, "%f", ptrMesures->mesures[IndexMesure].limiteSuperieure);
	
	
	// Mise en forme du commentaire (champ supplémentaire pour SAP ME)
	// ---------------------------------------------------------------
	sprintf (chComment,"Nom de la mesure: %s, Limite minimimale: %s, Valeur de la mesure: %s, Limite maximale: %s, Unité: %s, Statut: %s",ptrMesures->mesures[IndexMesure].nom, chLimiteInferieure, chValeur , chLimiteSuperieure,ptrMesures->mesures[IndexMesure].unite,ptrMesures->mesures[IndexMesure].status);
        

	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Log Parametric Data : Début");
	
	// Lock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);		
 
	status = SCProduction_GestionProductions_EnregistrementTestMesure(
        ptrMesures->instSCProduction,
		ptrVariablesTraca->PfinSfcSAPME,
		NOM_OPERATION,
		ptrVariablesTraca->NomRessourceSAPME,
		ptrVariablesTraca->chOrdreFabINTEG, 
		ptrMesures->mesures[IndexMesure].nom,
		ptrMesures->mesures[IndexMesure].status,
		(double)ptrMesures->mesures[IndexMesure].duree,
		SCPROD_LIBELLE_MESURE,
		chValeur,
		chLimiteInferieure,
		chLimiteSuperieure,
		ptrMesures->mesures[IndexMesure].unite,
		SCPROD_GROUPE_MESURE_BTF,
		chComment,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);
	
	// Unlock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);			
	
	SCPROD_TraceAppels	(nItfe,"Log Parametric Data : Fin  ");

	// ON inverse le bResult car il est à l'envers
	// -------------------------------------------		    ==> TEMPO, A REMPLACER !!
	if  (bResultSCProd == 0)
		bResultSCProd = 1;
	else if (bResultSCProd == 1)
		bResultSCProd = 0;
			 
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);
	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Enregistrement Mesure OK\n");
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
    return 0;
}


// ==============================================================================
// FONCTION :     SCPROD_LogParametricDataTableau
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_LogParametricDataTableau ( int nItfe,
//                                              int IndexMesure, 
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - int IndexMesure             : Identifiant de la mesure
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Enregistrement d'une mesure vers SAP ME
//				  
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA04
//  DATE :        14/07/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_LogParametricDataTableau ( int nItfe, char **Tableau, int Lg1, int Lg2, char *strErreurMessage )   
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
    char    			*chMsgSCProd = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	T_MESURES           *ptrMesures = &(gSlot[nItfe].mesures);
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	

	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strErreurMessage,"");
	

	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Log Parametric Data Tableau: Début");
 
	
	// Lock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);	

	status = SCProduction_GestionProductions_EnregistrementTableauTestsMesures(
        ptrMesures->instSCProduction,
		ptrVariablesTraca->CiuSfcSAPME,
		NOM_OPERATION,
		ptrVariablesTraca->NomRessourceSAPME,
		ptrVariablesTraca->chOrdreFabINTEG,		
		Tableau,
		Lg1,
		Lg2,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);

	
	// Unlock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);			
	
	SCPROD_TraceAppels	(nItfe,"Log Parametric Data Tableau: Fin  ");

	// ON inverse le bResult car il est à l'envers
	// -------------------------------------------		    ==> TEMPO, A REMPLACER !!
	if  (bResultSCProd == 0)
		bResultSCProd = 1;
	else if (bResultSCProd == 1)
		bResultSCProd = 0;
			 
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);
	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Enregistrement Tableau Mesure OK\n");
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
    return 0;
}


// ==============================================================================
// FONCTION :     SCPROD_AjoutStockComposant
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_AjoutStockComposant ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//                                              char *Composant,
//                                              char *Valeur,
//												int *iExistence,
//												char *SFCParent,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *Composant			    : Type de Composant ,
//                - char *Valeur			    : Valeur du composant à entrer en stock
//				  - int  *iExistence			: Indicateur sur l'état du composant : déjà en stock ou non, déjà assemblé...
//				  - char *SFCParent				: C'est le SFC sur lequel on devra assembler ==> permet de vérifier le parent si composant déjà assemblé.
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Permet d'ajouter un composant en stock
//				  
//				  
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        06/03/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_AjoutStockComposant ( int nItfe, T_TCOM_BASE *tcomBase, char *Composant, char *Indice, char *Valeur, int *iExistence, char *SFCParent, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
	int 				iSFCRetourOk = -1;
    char    			*chMsgSCProd = NULL;
	char				*chCodeRetour = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	char    			chCodeRetourTemp [SCPROD_MSG_LONG_MAX] = {'\0'};   
	char    			chSFCRetour [SCPROD_MSG_LONG_MAX] = {'\0'};   
	

	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strErreurMessage,"");
	
	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Mise en stock de l'article composant : %s avec la valeur : %s en cours...", Composant, Valeur);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Ajout Stock Composant : Début");

			
	// Lock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);			
	
	status = SCProduction_GestionProductions_AjoutStockOuRecuperationEtatComposant(
		tcomBase->instSCProduction,
		Valeur,
		Composant,
		Indice,
		TRUE,
		&chCodeRetour,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);

	// Unlock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);		
	
	SCPROD_TraceAppels	(nItfe,"Ajout Stock Composant : Fin  ");
		

	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}

	// On récupère le Code Retour puis on libère la mémoire .NET 
	// ------------------------------------------------------
	if (chCodeRetour != NULL)
	{	   
		strcpy(chCodeRetourTemp ,chCodeRetour);
        CDotNetFreeMemory(chCodeRetour);
	}   
																   
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL  On désactive car renvoie 0 Si n'existe PAS !!
	// ---------------------------------------------------
 //	if (bResultSCProd != TRUE)
//		errChk(SCPROD_ERREUR_BRESULT);
	
	
	// On regarde si le composant a bien été ajouté ou s'il existe  déjà  (et non assemblé) ou s'il est déjà assemblé (et dans ce cas, contrôles)
	// -------------------------------------------------------------------------------------------------------------------------------------------
	if (FindPattern (chCodeRetourTemp,0,strlen(chCodeRetourTemp),"3",0,0) != -1)
		*iExistence = 0; 
	else if (FindPattern (chCodeRetourTemp,0,strlen(chCodeRetourTemp),"2",0,0) != -1)
		*iExistence = 1; 
	else if (FindPattern (chCodeRetourTemp,0,strlen(chCodeRetourTemp),"4",0,0) != -1)
	{
		*iExistence = -1; 
		
		// Affichage si le composant est déjà assemblé
		// -------------------------------------------
		if (gFlagLogSAPME == TRUE )
		{
			sprintf (chMsgInfo, "Un composant de type: %s est déjà assemblé. Vérification SFC parent en cours.", Composant);
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}

		// On vérifie si le composant est assemblé sur le SFC PFIN
		// -------------------------------------------------------
		status = SCPROD_RecuperationSFCDepuisComposant(nItfe, tcomBase, Valeur, chSFCRetour, &iSFCRetourOk ,chMsgTemp);
			
		if ((status != 0) || (iSFCRetourOk != 1) )
			errChk(SCPROD_ERREUR_RECUP_SFC_COMPOSANT); 
		
		if ( strcmp(chSFCRetour,SFCParent) !=0)
			errChk(SCPROD_ERREUR_SFC_DEJA_ASSEMBLE); 
			
		
	}
	else 
		errChk(SCPROD_ERREUR_BRESULT); 
	
	

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (error == SCPROD_ERREUR_SFC_DEJA_ASSEMBLE)
            sprintf (strErreurMessage, "Erreur : Le Composant: %s est déjà assemblé sur le SFC : %s avec la valeur : %s.",Composant, chSFCRetour, Valeur);
		else if (error == SCPROD_ERREUR_RECUP_SFC_COMPOSANT)
            sprintf (strErreurMessage, "Erreur : Problème de récupération du SFC pour ce Composant: %s. Retour DLL SCProduction : %s",Composant, chMsgTemp);
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Code retour = %s. Retour DLL: %s ", chCodeRetourTemp, chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    

	
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);


	// Affichage Ajout stock OK
	// ------------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Mise en stock de l'article composant : %s OK. Code retour DLL = %s.\n", Composant,chCodeRetourTemp );
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	

    return 0;
}	



// ==============================================================================
// FONCTION :     SCPROD_AssemblageComposant
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_AssemblageComposant ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//												char *ValeurComposant,
//                                              char *CodeComposant,
//                                              char *SFC,
//												char *TypeAssemblage,
//												char *Operation,
//												char *Ressource,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *ValeurComposant       : Valeur du composant à assembler
//                - char *CodeComposant		    : Code article (nécessaire dans certains cas comme pour le HDD : Composant Trackable qui devient un SFC)
//                - char *SFC			        : SFC sur lequel on doit assembler
//				  - char *TypeAssemblage		: Si on assemble un SFC ou un INVENTORY_ID (composant)
//                - char *Operation     		: Opération Utilisée 
//                - char *Ressource   			: Ressource Utilisée 
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Permet d'assembler un composant sur un SFC.
//				  
//				  
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        06/03/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_AssemblageComposant ( int nItfe, T_TCOM_BASE *tcomBase, char *ValeurComposant, char *CodeComposant, char *SFC, char *TypeAssemblage, char *Operation, char *Ressource, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
	int 				iSFCRetourOk = -1;
    char    			*chStatut = NULL;
    char    			*chMsgSCProd = NULL;
	char				*ptrCodeComposant = NULL;
    char    			chSatutTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
 	char    			chSFCRetour [SCPROD_MSG_LONG_MAX] = {'\0'};   

	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strErreurMessage,"");

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Assemblage du composant : %s sur le SFC : %s en cours...(Type assemblage = %s - Operation : %s - Ressource : %s)", ValeurComposant,SFC, TypeAssemblage, Operation, Ressource);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	
    // Choix du Pointeur Composant : La Valeur si on assemble un INVENTORY_ID Déjà en Stock, ou le Code Produit pour les cas particulier des Composants Trackable
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------
	if (CodeComposant == NULL)
		ptrCodeComposant = ValeurComposant;
	else 
		ptrCodeComposant = CodeComposant;
	
	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Assemblage Composant : Début");
	
		
	// Lock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);	

		status = SCProduction_GestionProductions_AssembleComposant (
		tcomBase->instSCProduction,
		SFC,
		Operation,
		Ressource,
		ValeurComposant,
		ptrCodeComposant,
		TypeAssemblage,
		SCPROD_LIBELLE_ASSEMBLAGE,
		&bResultSCProd,
		&chStatut,
		&chMsgSCProd,
		NULL);
	
	// Unlock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);			

	SCPROD_TraceAppels	(nItfe,"Assemblage Composant : Fin  ");
	
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chStatut) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chSatutTemp,chStatut);
        CDotNetFreeMemory(chStatut);
	}	  
	
	// On Vérifie le statut : si OK ou ALREADY_ASSEMBLED ==> le composant est bien assemblé sur le SFC
	// ------------------------------------------------------------------------------------------------
	if ( strcmp(chSatutTemp,SCPROD_RET_OK) != 0 && strcmp(chSatutTemp,SCPROD_RET_DEJA_ASSEMBLE) != 0)
		errChk(-1);

			 
	// Si déjà assemblé, on vérifie que c'est sur le bon SFC
	// -----------------------------------------------------
	if ( strcmp(chSatutTemp,SCPROD_RET_DEJA_ASSEMBLE) == 0 )
	{	 
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{
			sprintf (chMsgInfo, "Un composant de ce type est déjà assemblé sur le SFC : %s. Vérification SFC parent en cours.", SFC );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
		
		// On vérifie si le composant est assemblé sur le SFC PFIN
		// -------------------------------------------------------
		status = SCPROD_RecuperationSFCDepuisComposant(nItfe, tcomBase, ValeurComposant, chSFCRetour, &iSFCRetourOk ,chMsgTemp);
			
		if ((status != 0) || (iSFCRetourOk != 1) )
			errChk(SCPROD_ERREUR_RECUP_SFC_COMPOSANT); 
		
		if ( strcmp(chSFCRetour,SFC) !=0)
			errChk(SCPROD_ERREUR_SFC_DEJA_ASSEMBLE); 
	}		 
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	
	// Si le statut est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	
	

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == -1)
			sprintf (strErreurMessage, "Erreur Assemblage KO. Retour DLL : %s",chMsgTemp);
        else if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       	else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       	else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (error == SCPROD_ERREUR_SFC_DEJA_ASSEMBLE)
            sprintf (strErreurMessage, "Erreur : Le Composant: %s est déjà assemblé sur le SFC : %s",ValeurComposant, chSFCRetour);
		else if (error == SCPROD_ERREUR_RECUP_SFC_COMPOSANT)
            sprintf (strErreurMessage, "Erreur : Problème de récupération du SFC pour ce Composant: %s. Retour DLL SCProduction : %s",ValeurComposant, chMsgTemp);
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================   
    if(error)
		return -1;

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);
	

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Assemblage du composant : %s sur le SFC : %s OK.\n", ValeurComposant,SFC );
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	
    return 0;
}	

// ==============================================================================
// FONCTION :     SCPROD_AssemblageComposantTableau
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_AssemblageComposantTableau ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//												char *ValeurComposant,
//                                              char *CodeComposant,
//                                              char *SFC,
//												char *TypeAssemblage,
//												char *Operation,
//												char *Ressource,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *ValeurComposant       : Valeur du composant à assembler
//                - char *CodeComposant		    : Code article (nécessaire dans certains cas comme pour le HDD : Composant Trackable qui devient un SFC)
//                - char *SFC			        : SFC sur lequel on doit assembler
//				  - char *TypeAssemblage		: Si on assemble un SFC ou un INVENTORY_ID (composant)
//                - char *Operation     		: Opération Utilisée 
//                - char *Ressource   			: Ressource Utilisée 
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Permet d'assembler un composant sur un SFC.
//				  
//				  
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002BA02
//  DATE :        10/01/2014
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_AssemblageComposantTableau ( int nItfe, T_TCOM_BASE *tcomBase, char *SFC, char *Operation, char *Ressource, char **Tableau, int Lg1, int Lg2, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
	//int 				iSFCRetourOk = -1;
    char    			*chStatut = NULL;
    char    			*chMsgSCProd = NULL;
	//char				*ptrCodeComposant = NULL;
    char    			chSatutTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
 	//char    			chSFCRetour [SCPROD_MSG_LONG_MAX] = {'\0'};   

	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strErreurMessage,"");



	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Assemblage Tableau Composant : Début");  
	
		
	// Lock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);			
	

	status = SCProduction_GestionProductions_AssembleTableauComposants (
		tcomBase->instSCProduction,
		SFC,
		Operation,
		Ressource,
		Tableau,
		Lg1,
		Lg2,
		&bResultSCProd,
		&chStatut,
		&chMsgSCProd,
		NULL);

	// Unlock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);			
	

	SCPROD_TraceAppels	(nItfe,"Assemblage Tableau Composant : Fin  ");
	
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chStatut) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chSatutTemp,chStatut);
        CDotNetFreeMemory(chStatut);
	}	  
	
	// On Vérifie le statut : si différent de OK , erreur
	// --------------------------------------------------
	if ( strcmp(chSatutTemp,SCPROD_RET_OK) != 0)
		errChk(-1);

			 
	// Si le statut est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);

	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	
	
	

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == -1)
			sprintf (strErreurMessage,"Erreur Assemblage (Retour DLL SCProduction : %s)", chMsgTemp);
		else if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       	else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       	else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================   
    if(error)
		return -1;

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);
	

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Assemblage OK.\n");
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	
    return 0;
}	

// ==============================================================================
// FONCTION :     SCPROD_RecuperationComposant
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_RecuperationComposant ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//                                              char *SFC,
//                                              char *TypeComposant,
//                                              char *ValeurComposant,
//                                              int  *iExistenceComposant,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *SFC			        : SFC sur lequel on doit récupérer le composant
//                - char *TypeComposant			: Article (Type de Composant) à récupérer,
//                - char *ValeurComposant		: Retour : Composant récupéré,
//				  - int  *iExistenceComposant	: Indicateur sur l'existence du composant
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Permet de récupérer la valeur d'un composant assemblé sur un SFC (si existe)
//				  
//				  
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        13/03/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_RecuperationComposant ( int nItfe, T_TCOM_BASE *tcomBase,  char *SFC, char *TypeComposant, char *ValeurComposant,int *iExistenceComposant, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status = -1;
    char    			*ValeurComposantDLL = NULL;
    char    			*chMsgSCProd = NULL;
	char 				*chCodeRetour = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chCodeRetourTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	

	
	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(ValeurComposant,"");
	strcpy(strErreurMessage,"");
	
	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Récupération de l'article composant : %s sur le SFC : %s en cours...", TypeComposant, SFC);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Récupération Composant Depuis SFC : Début");

	status = SCProduction_GestionProductions_RecuperationComposantdepuisSFC (
		tcomBase->instSCProduction,
		SFC, 
		TypeComposant,
		SCPROD_INDICE_DEFAUT,
		&chCodeRetour,
		&ValeurComposantDLL,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);  
	
	SCPROD_TraceAppels	(nItfe,"Récupération Composant Depuis SFC : Fin  ");

			 
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (ValeurComposantDLL) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);
	

	// On récupère le Composant puis on libère la mémoire .NET 
	// ------------------------------------------------------
	if (ValeurComposantDLL != NULL)
	{	   
		strcpy(ValeurComposant ,ValeurComposantDLL);
        CDotNetFreeMemory(ValeurComposantDLL);
	}   
	
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chCodeRetour) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);
	

	// On récupère le Code Retour puis on libère la mémoire .NET 
	// ------------------------------------------------------
	if (chCodeRetour != NULL)
	{	   
		strcpy(chCodeRetourTemp ,chCodeRetour);
        CDotNetFreeMemory(chCodeRetour);
	}   
																   
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL  On désactive car renvoie 0 Si n'existe PAS !!
	// ---------------------------------------------------
 //	if (bResultSCProd != TRUE)
//		errChk(SCPROD_ERREUR_BRESULT);
	
	
	// On regarde si le composant existe 
	// ----------------------------------
	if (FindPattern (chCodeRetourTemp,0,strlen(chCodeRetourTemp),"4",0,0) != -1)
		*iExistenceComposant = 1;
	else if (FindPattern (chCodeRetourTemp,0,strlen(chCodeRetourTemp),"3",0,0) != -1)
		*iExistenceComposant = 0;
	else
		errChk(-1); 
	

	// Si jamais le Composant n'a pas été complété
	// --------------------------------------------
	if (strlen(ValeurComposant) == 0 && *iExistenceComposant == 1)
	{
		strcpy( chMsgTemp, "le composant retourné est vide");
		errChk(-1);
	}

	
	
	
Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == -1)
			sprintf (strErreurMessage,"Erreur Récupération Composant : %s", chMsgTemp);
       	else if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       	else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       	else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Récupération effectuée. Code de retour DLL : %s. Composant récupéré : %s.", chCodeRetourTemp, ValeurComposant);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	
    return 0;
}	








// ==============================================================================
// FONCTION :     SCPROD_RecuperationProprieteSFC
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_RecuperationProprieteSFC ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//                                              char *SFC,
//                                              char *NomPropriete,
//                                              char *ValeurPropriete,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *SFC			        : SFC sur lequel on doit récupérer le composant
//                - char *NomPropriete			: Nom de la propriété à récupérer
//                - char *ValeurPropriete		: Valeur de la propriété à récupérer
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Permet de récupérer une propriété (donnée collectée) d'un SFC
//
//				  
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002BA01
//  DATE :        13/11/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_RecuperationProprieteSFC ( int nItfe, T_TCOM_BASE *tcomBase, char *SFC, char *NomPropriete, char *ValeurPropriete, char *strErreurMessage){
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status = -1;
    char    			*chMsgSCProd = NULL;
	char				*chValeurProprieteTMP = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	

	
	// ==================
    // = Init Variables =
    // ==================	 
	strcpy(strErreurMessage,"");

	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Récupération de la donnée collectée : % s sur le SFC : %s en cours...", NomPropriete, SFC);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Récupération Donnée Collectée du SFC : Début");

		
	// Lock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);			
	
	
	status = 		SCProduction_GestionProductions_RecuperationProprieteSFC(
		tcomBase->instSCProduction,
		SFC,
		NomPropriete,
		&bResultSCProd,
		&chValeurProprieteTMP, 		
		&chMsgSCProd,
		NULL);
	
	// Unlock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);			


	SCPROD_TraceAppels	(nItfe,"Récupération Donnée Collectée du SFC : Fin  ");

			 
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// On récupère la valeur puis on libère la mémoire .NET 
	// ------------------------------------------------------
	if (chValeurProprieteTMP != NULL)
	{	   
		strcpy(ValeurPropriete ,chValeurProprieteTMP);
        CDotNetFreeMemory(chValeurProprieteTMP);
	}   
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	


Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == -1)
			sprintf (strErreurMessage,"Erreur Récupération Donnée : %s", chMsgTemp);
       	else if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Aucune Donnée Récupérée (Retour DLL SCProduction : %s).", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       	else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       	else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Récupération Donnée sur SFC : %s réussie",SFC);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	
    return 0;
}	



// ==============================================================================
// FONCTION :     SCPROD_RecuperationProprietesSFCTableau
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_RecuperationProprietesSFCTableau ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//                                              char *SFC,
//                                              char *TableauValeurs,
//                                              int  *Lg1,
//                                              int  *Lg2,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *SFC			        : SFC sur lequel on doit récupérer le composant
//                - char *TableauValeurs		: Tableau des valeurs récupérées
//				  - int  *Lg1					: Nombre de propriétés
//				  - int  *Lg2					: Nombre de champs par propriétés
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Permet de récupérer par tableau les propriétés (données collectées) d'un SFC
//				  Attention, la mémoire .NET du tableau doit être libérée par la fonction appelante
//				  
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002BA01
//  DATE :        13/11/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_RecuperationProprietesSFCTableau ( int nItfe, T_TCOM_BASE *tcomBase, char *SFC, char ***TableauValeurs, int *Lg1, int *Lg2, char *strErreurMessage)
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status = -1;
    char    			*chMsgSCProd = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	

	
	// ==================
    // = Init Variables =
    // ==================	 
	strcpy(strErreurMessage,"");
	*Lg1 = 0;
	*Lg2 = 0;
	
	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Récupération du tableau de données collectées sur le SFC : %s en cours...", SFC);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Récupération Tableau Données Collectée du SFC : Début");

	// Lock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);			
	
	status = SCProduction_GestionProductions_RecuperationProprietesSFC(	
		tcomBase->instSCProduction,
		SFC,
        TableauValeurs,
        Lg1,
        Lg2,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);

	// Unlock BDD
	// --------
	if (SUR_LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);			

	SCPROD_TraceAppels	(nItfe,"Récupération Tableau Données Collectée du SFC : Fin  ");

			 
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	

	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	


Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == -1)
			sprintf (strErreurMessage,"Erreur Récupération Tableau Données : %s", chMsgTemp);
       	else if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       	else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       	else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Récupération Tableau Données sur SFC : %s réussie",SFC);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	
    return 0;
}	


// ==============================================================================
// FONCTION :     SCPROD_Complete
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_Complete ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//												char *Operation,
//												char *Ressource,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *Operation     		: Opération Utilisée 
//                - char *Ressource   			: Ressource Utilisée 
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Complete sur SFC Pfin - correspondant à un mvt de test.
//				  KO si une non conformité à été logguée auparavant
//				  OK sinon
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        18/02/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_CompleteSnPFIN ( int nItfe, T_TCOM_BASE *tcomBase, char *Operation, char *Ressource, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			*chMsgSCProd = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	

	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strErreurMessage,"");

	
	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Complete En cours sur SFC %s. Opération: %s - Ressource: %s.", ptrVariablesTraca->PfinSfcSAPME, Operation, Ressource);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	
	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Complete : Début");

	status = SCProduction_GestionProductions_FinOperation (
		tcomBase->instSCProduction,
		ptrVariablesTraca->CiuSfcSAPME,
		Ressource, 
		Operation, 
		&bResultSCProd,
		&chMsgSCProd,
		NULL);
			 
	SCPROD_TraceAppels	(nItfe,"Complete : Fin  ");

	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}	 
	
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Complete effectué sur SFC %s. Retour DLL: %s.\n", ptrVariablesTraca->PfinSfcSAPME,chMsgTemp );
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

	
	return 0;
}


// ==============================================================================
// FONCTION :     SCPROD_EnregistrementLog
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_EnregistrementLog ( int nItfe,
//                                              T_TCOM_BASE *tcomBase, 
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - T_TCOM_BASE *tcomBase       : Paramètres de la base,
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Complete sur SFC Pfin - correspondant à un mvt de test.
//				  KO si une non conformité à été logguée auparavant
//				  OK sinon
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        13/05/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_EnregistrementLog ( int nItfe, T_TCOM_BASE *tcomBase, char *BufferTrace, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
    int     			iErreurCode = 0;
	int     			error = 0;
	int 				status;
    char    			*chErreurMsgSCProd = NULL;
    char    			*chErreurRequeteSCProd = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	

	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strErreurMessage,"");

	
	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Enregistrement Log : Début");

	
	// =======================================
    // = On enregistre le LOG sur le SFC CIU =
    // =======================================

	// Lock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);
	
	
	status =   SCProduction_GestionProductions_EnregistrementTrace(
		tcomBase->instSCProduction,
		ptrVariablesTraca->CiuSfcSAPME,
		BufferTrace,
		NOM_OPERATION, // ==> On loggue sur l'opération de perso
		&bResultSCProd,
		&iErreurCode,
		&chErreurMsgSCProd,
		&chErreurRequeteSCProd,
		NULL);
		
	// Unlock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);		
			 
	SCPROD_TraceAppels	(nItfe,"Enregistrement Log : Fin  ");

	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chErreurMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chErreurMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chErreurMsgSCProd);
        CDotNetFreeMemory(chErreurMsgSCProd);
	}
	
	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chErreurRequeteSCProd != NULL)
	{
		if ((strlen (chMsgTemp)+strlen (chErreurRequeteSCProd)) >= SCPROD_MSG_LONG_MAX)
			errChk(SCPROD_ERREUR_LONG_MSG);
		else
			strcat(chMsgTemp, chErreurRequeteSCProd);
        CDotNetFreeMemory(chErreurRequeteSCProd);  
	}

	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// ON inverse le bResult car il est à l'envers
	// -------------------------------------------		    ==> TEMPO, A REMPLACER !!
	
	if  (bResultSCProd == 0)
		bResultSCProd = 1;
	else if (bResultSCProd == 1)
		bResultSCProd = 0;

	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE )
		errChk(SCPROD_ERREUR_BRESULT);
	

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    

	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// Affichage Dans le log 
	// ----------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Log enregistré sur SFC %s. Retour DLL: %s ", ptrVariablesTraca->CiuSfcSAPME,chMsgTemp );
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	
	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

    return 0;
}


// ==============================================================================
// FONCTION :     SCPROD_InformationsOF
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_InformationsOF ( int nItfe,
//                                              char *OrdreFabrication,
//                                              char *RetourCodeProduit,
//                                              char *RetourIndiceProduit,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - char *OrdreFabrication      : OF à récupérer,
//                - char *RetourCodeProduit     : Code produit associé à l'OF
//                - char *RetourIndiceProduit  	: Indice produit associé à l'OF
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Renvoie des informations sur un OF donné.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        18/02/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_InformationsOF ( int nItfe, T_TCOM_BASE *tcomBase, char *OrdreFabrication, char *RetourCodeProduit,char *RetourIndiceProduit, char *RetourTypeOF, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
	char				*chCodeProduitOF = NULL;
	char				*chIndiceProduitOF = NULL;
	char				*chTypeOF = NULL;
    char    			*chMsgSCProd = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	
	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(RetourCodeProduit,"");
	strcpy(RetourIndiceProduit,"");
	strcpy(RetourTypeOF,"");
	strcpy(strErreurMessage,"");


	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	status = SCProduction_GestionProductions_RecuperationDetailsOFV2 (
		tcomBase->instSCProduction,
		OrdreFabrication,
		&chCodeProduitOF,
		&chIndiceProduitOF,
		&chTypeOF,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);
			 
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// On recopie le Code produit puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chCodeProduitOF != NULL)
	{
		strcpy(RetourCodeProduit,chCodeProduitOF);
        CDotNetFreeMemory(chCodeProduitOF);
	}

	// On recopie l'indice produit puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chIndiceProduitOF != NULL)
	{
		strcpy(RetourIndiceProduit,chIndiceProduitOF);
        CDotNetFreeMemory(chIndiceProduitOF);
	}

	// On recopie le type OF puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chTypeOF != NULL)
	{
		strcpy(RetourTypeOF,chTypeOF);
        CDotNetFreeMemory(chTypeOF);
	}

	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
	}
    
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

    return 0;
}



// ==============================================================================
// FONCTION :     SCPROD_InformationsSFC
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_InformationsSFC ( int nItfe,
//                                              char *SFC,
//                                              char *RetourCodeProduit,
//                                              char *RetourIndiceProduit,
//                                              char *RetourOF,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - char *SFC			        : SFC dont on veut les infos,
//                - char *RetourCodeProduit     : Code produit associé au SFC
//                - char *RetourIndiceProduit  	: Indice produit associé au SFC
//                - char *RetourOF  			: OF associé au SFC
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Renvoie des informations sur un SFC donné.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        06/03/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_InformationsSFC ( int nItfe, T_TCOM_BASE *tcomBase, char *SFC, char *RetourCodeProduit,char *RetourIndiceProduit, char *RetourOF, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
	char				*chCodeProduitSFC = NULL;
	char				*chIndiceProduitSFC = NULL;
	char				*chRetourOFSFC = NULL;
    char    			*chMsgSCProd = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	
	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(RetourCodeProduit,"");
	strcpy(RetourIndiceProduit,"");
	strcpy(RetourOF,"");
	strcpy(strErreurMessage,"");

	
	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Informations SFC : Début");
	
	status = SCProduction_GestionProductions_RecuperationInformationSFC (
		tcomBase->instSCProduction,
		SFC,
		&chRetourOFSFC,
		&chCodeProduitSFC,
		&chIndiceProduitSFC,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);
			 
	SCPROD_TraceAppels	(nItfe,"Informations SFC : Fin  ");

	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// On recopie le Code produit puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chCodeProduitSFC != NULL)
	{
		strcpy(RetourCodeProduit,chCodeProduitSFC);
        CDotNetFreeMemory(chCodeProduitSFC);
	}

	// On recopie l'indice produit puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chIndiceProduitSFC != NULL)
	{
		strcpy(RetourIndiceProduit,chIndiceProduitSFC);
        CDotNetFreeMemory(chIndiceProduitSFC);
	}

	// On recopie le type OF puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chRetourOFSFC != NULL)
	{
		strcpy(RetourOF,chRetourOFSFC);
        CDotNetFreeMemory(chRetourOFSFC);
	}

	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);

	
Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       	else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       	else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	// Affichage Dans le log de la donnée en cours de collecte
	// -------------------------------------------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Informations sur SFC %s - Code Produit : %s/%s - OF : %s . Retour DLL: %s ", SFC,RetourCodeProduit,RetourIndiceProduit,RetourOF ,chMsgTemp );
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

    return 0;
}


// ==============================================================================
// FONCTION :     SCPROD_InformationsSFC
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_InformationsSFC ( int nItfe,
//                                              char *SFC,
//                                              char *RetourCodeProduit,
//                                              char *RetourIndiceProduit,
//                                              char *RetourOF,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - char *SFC			        : SFC dont on veut les infos,
//                - char *RetourCodeProduit     : Code produit associé au SFC
//                - char *RetourIndiceProduit  	: Indice produit associé au SFC
//                - char *RetourOF  			: OF associé au SFC
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Renvoie des informations sur un SFC donné.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        06/03/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_InformationsHDD ( int nItfe, T_TCOM_BASE *tcomBase, char *SFC, char *RetourCodeProduit,char *RetourIndiceProduit, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
	char				*chCodeProduitSFC = NULL;
	char				*chIndiceProduitSFC = NULL;
    char    			*chMsgSCProd = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	
	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(RetourCodeProduit,"");
	strcpy(RetourIndiceProduit,"");
	strcpy(strErreurMessage,"");

	
	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	SCPROD_TraceAppels	(nItfe,"Informations SFC : Début");
	
	status = SCProduction_GestionProductions_RecuperationInformationSFC_HDD (
		tcomBase->instSCProduction,
		SFC,
		&chCodeProduitSFC,
		&chIndiceProduitSFC,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);
			 
	SCPROD_TraceAppels	(nItfe,"Informations SFC : Fin  ");

	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// On recopie le Code produit puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chCodeProduitSFC != NULL)
	{
		strcpy(RetourCodeProduit,chCodeProduitSFC);
        CDotNetFreeMemory(chCodeProduitSFC);
	}

	// On recopie l'indice produit puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chIndiceProduitSFC != NULL)
	{
		strcpy(RetourIndiceProduit,chIndiceProduitSFC);
        CDotNetFreeMemory(chIndiceProduitSFC);
	}


	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);

	
Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       	else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       	else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	// Affichage Dans le log de la donnée en cours de collecte
	// -------------------------------------------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Informations sur SFC %s - Code Produit : %s/%s. Retour DLL: %s ", SFC,RetourCodeProduit,RetourIndiceProduit,chMsgTemp );
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

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
	int     error = 0;

    // ==============================
    // = Enregistrement de l'erreur =
    // ==============================
	
	// Lock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);
	
	
	SCProduction_GestionProductions_RecuperationProduitsParents(
        tcomBase->instSCProduction,
        strCodeProduit,
        strIndiceProduit,
        &tabProduitsParentsTmp,
        &tabProduitsParentsLength1,
        &tabProduitsParentsLength2,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL); 
	
	// Unlock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);
	
	
	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( errorMsg == NULL || errorRequete == NULL )
		errChk(TCOM_ERREUR_RESEAU);
	
	if (errorOccured)
        errChk(-1);
	
	if (( *nbProduitsParents = tabProduitsParentsLength1 ))
    {
        *tabProduitsParents = (T_PRODUIT*) malloc (sizeof(T_PRODUIT) * (*nbProduitsParents));
        if ( *tabProduitsParents == NULL )
			errChk(-2); 

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

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
		else if (error == -2)
			sprintf (strErreurMessage, GET_MESSAGE(TRC_MSG_ERR_ALLOCATION_MEMOIRE));
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
	int     error = 0;

    // =================================
    // = Récupération produits enfants =
    // =================================
			
	// Lock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);
	
	SCProduction_GestionProductions_RecuperationProduitsEnfants(
        tcomBase->instSCProduction,
        strCodeProduit,
        strIndiceProduit,
        &tabProduitsEnfantsTmp,
        &tabProduitsEnfantsLength1,
        &tabProduitsEnfantsLength2,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL); 	   
			
	// Unlock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);
	
	
	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( errorMsg == NULL || errorRequete == NULL )
		errChk(TCOM_ERREUR_RESEAU);

	if (errorOccured)
        errChk(-1);
	
	if (( *nbProduitsEnfants = tabProduitsEnfantsLength1 ))
    {
        *tabProduitsEnfants = (T_PRODUIT*) malloc (sizeof(T_PRODUIT) * (*nbProduitsEnfants));
        if ( *tabProduitsEnfants == NULL )
   			errChk(-2);
		
        for ( ii=0 ; ii<*nbProduitsEnfants ; ii++ )
        {
            strcpy ( (*tabProduitsEnfants)[ii].chVersion, tabProduitsEnfantsTmp[(ii*tabProduitsEnfantsLength2)]);
            strcpy ( (*tabProduitsEnfants)[ii].chIndice, tabProduitsEnfantsTmp[(ii*tabProduitsEnfantsLength2)+1]);
            strcpy ( (*tabProduitsEnfants)[ii].chDesignation, tabProduitsEnfantsTmp[(ii*tabProduitsEnfantsLength2)+2]);
            
            // Récupération des infos du produit enfant
            // ----------------------------------------
			
			// Lock BDD
			// --------
			if (LOCK_BDD == 1)
				CmtGetLock (IdLockBDD);
	

			SCProduction_GestionProductions_RecuperationProduitInformations(
                    tcomBase->instSCProduction,
                    (*tabProduitsEnfants)[ii].chVersion,
                    (*tabProduitsEnfants)[ii].chIndice,
                    &strCodeOperateur,
                    &strCodeSousFamille,
                    &strCodeFamille,
                    &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);
			
			// Unlock BDD
			// --------
			if (LOCK_BDD == 1)
				CmtReleaseLock (IdLockBDD);
	
			// Verification pointeurs non nuls => en cas de sortie de la fct en time out
			// -------------------------------------------------------------------------
			if ( strCodeOperateur == NULL || strCodeSousFamille == NULL || strCodeFamille == NULL || errorMsg == NULL || errorRequete == NULL )
				errChk(TCOM_ERREUR_RESEAU);

			if (errorOccured)
        		errChk(-1);
           
            // Enregistrement des infos
            // ------------------------
            strcpy ( (*tabProduitsEnfants)[ii].chFamille, strCodeFamille);
            strcpy ( (*tabProduitsEnfants)[ii].chSousFamille, strCodeSousFamille);
            
            // Libération mémoire
            // ------------------
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

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
		else if (error == -2)
			sprintf (strErreurMessage, GET_MESSAGE(TRC_MSG_ERR_ALLOCATION_MEMOIRE));
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
// FONCTION :     SCPROD_RecuperationDateHeure
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_RecuperationDateHeure ( T_TCOM_BASE *tcomBase, 
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
int SCPROD_RecuperationDateHeure ( T_TCOM_BASE *tcomBase, T_DATE_HEURE *dateheure, char *strErreurMessage )
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
	int     error = 0;
	
    // ===========================
    // = Recuperation Date Heure =
    // ===========================

	// Lock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);
	
	SCProduction_GestionProductions_RecuperationDateHeure (tcomBase->instSCProduction, 
															&dateheure->year, &dateheure->year2digits, &dateheure->month, &dateheure->week, &dateheure->dayweek, &dateheure->daymonth, &dateheure->dayyear, 
															&dateheure->hour, &dateheure->minute, &dateheure->second, &dateheure->millisecond, 
															&errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);  

	// Unlock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);
	
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
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
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
// FONCTION :     EcritureCle
// ------------------------------------------------------------------------------
// PROTOTYPE :    int EcritureCle ( T_TCOM_BASE *tcomBase, 
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
//  VERSION :     S08012CA21
//  DATE :        10/12/2010
//  AUTEUR :      GCX (APSIDE)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_EcritureCle (T_TCOM_BASE *tcomBase, char *strNomTableCle, char *strNumSerie, char *strCodeProduit, char *strIndiceProduit, char **tabParam, int iParamLength, char *strErreurMessage )
{
    int     error = 0;                     
	int     errorOccured = FALSE;
    int     errorCode = 0;
	int 	iValeursCleLength = 0;
	int		iBcleFree;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
	char 	**tabValeursCle = NULL;

	// =============================
    // = Ecriture d'une clé en BDD =
    // =============================

	// Lock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);
	
	SCProduction_GestionProductions_EcritureCle_sapme (
		tcomBase->instSCProduction, 
		strNomTableCle, 
		strNumSerie, 
		strCodeProduit, 
		strIndiceProduit, 
		tabParam, 
		iParamLength, 
		&tabValeursCle,
		&iValeursCleLength, 
		&errorOccured, &errorCode, &errorMsg, &errorRequete, NULL); 
	
	// Unlock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);
	

	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( tabValeursCle == NULL || errorMsg == NULL || errorRequete == NULL )
		errChk(TCOM_ERREUR_RESEAU);
	
	if (errorOccured)
        errChk(-1);
	
	// Vérification clé bien écrite en BDD
    // -----------------------------------
	if ( tabParam != NULL )
		if (strcmp(tabParam[0], tabValeursCle[2]))
			errChk(-2);
	
	// Libération mémoire
    // ------------------
	//if (tabValeursCle != NULL)
     //   CDotNetFreeMemory(tabValeursCle);
	
	// Liberation du pointeur de clés
	// ------------------------------
	for (iBcleFree = (iValeursCleLength -1); iBcleFree>=0 ; iBcleFree--)
	{
		if (tabValeursCle[iBcleFree] != NULL) 
        	CDotNetFreeMemory(tabValeursCle[iBcleFree]);
	}
	if (tabValeursCle != NULL)
		CDotNetFreeMemory(tabValeursCle); 
		
Error:	
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
		else if (error == -2)
			strcpy (strErreurMessage, GET_MESSAGE(TRC_MSG_ERR_ECRITURE_CLE));
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
// FONCTION :     RecuperationCles
// ------------------------------------------------------------------------------
// PROTOTYPE :    int RecuperationCles ( T_TCOM_BASE *tcomBase, 
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
//  VERSION :     S08012CA21
//  DATE :        10/12/2010
//  AUTEUR :      GCX (APSIDE)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_RecuperationCles (int nItfe, T_TCOM_BASE *tcomBase, char *strNomTableCle, char *strNumSerie, char *strCodeProduit, char *strIndiceProduit, char **tabParam, int iParamLength, char ***tabValeursCle, int *iQuantiteCle, int *iValeursCleLength, char *strErreurMessage )
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
	int     error = 0;
	
	// ========================================
    // = Lecture et Ecriture d'une clé en BDD =
    // ========================================
	
	// Lock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);
	
	SCProduction_GestionProductions_RecuperationCles_sapme (
		tcomBase->instSCProduction, 
		strNomTableCle, 
		strNumSerie, 
		strCodeProduit, 
		strIndiceProduit, 
		tabParam, 
		iParamLength, 
		tabValeursCle,
		iQuantiteCle,
		iValeursCleLength, 
		&errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);
	
	// Unlock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);
	
	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( tabValeursCle == NULL || errorMsg == NULL || errorRequete == NULL )
		errChk(TCOM_ERREUR_RESEAU);

	if (errorOccured)
        errChk(-1);
	
	// Libération mémoire
    // ------------------
	//if (tabValeursCle != NULL) ==> ne pas le libérer ici car il est appelé par la fonction parente !!!
        //CDotNetFreeMemory(tabValeursCle);
	
Error:	
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
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
// FONCTION :     LectureCle
// ------------------------------------------------------------------------------
// PROTOTYPE :    int LectureCle ( T_TCOM_BASE *tcomBase, 
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
//  VERSION :     S08012CA90
//  DATE :        18/07/2011
//  AUTEUR :      GCX (APSIDE)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_LectureCle (int nItfe, T_TCOM_BASE *tcomBase, char *strNomTableCle, char *strNumSerie, char *strCodeProduit, char *strIndiceProduit, char **tabParam, int iParamLength, char ***tabValeursCle, int *iValeursCleLength, char *strErreurMessage )
{
    int     errorOccured = FALSE;
    //int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
	int     error = 0;
	
	// ========================================
    // = Lecture et Ecriture d'une clé en BDD =
    // ========================================
	
	// [SUPPRESSION TEMPORAIRE TRACACOM]
	
	errChk(-1);  // pour ne pas sortir OK par inadvertance
	
	
	/*TracaCom_FonctionsMDT_FonctionsMDT_LectureCle (
		tcomBase->instTracaCom, 
		strNomTableCle, 
		strNumSerie, 
		strCodeProduit, 
		strIndiceProduit, 
		tabParam, 
		iParamLength, 
		tabValeursCle,
		iValeursCleLength, 
		&errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);  */
	
	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( tabValeursCle == NULL || errorMsg == NULL || errorRequete == NULL )
		errChk(TCOM_ERREUR_RESEAU);

	if (errorOccured)
        errChk(-1);
	
	// Libération mémoire
    // ------------------
	if (tabValeursCle != NULL)
        CDotNetFreeMemory(tabValeursCle);
	
Error:	
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
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
// FONCTION :     TCOM_RecuperationMasqueLogoEtiquette
// ------------------------------------------------------------------------------
// PROTOTYPE :    TCOM_RecuperationMasqueLogoEtiquette ( T_TCOM_BASE *tcomBase, 
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
//  VERSION :     S08012CA51
//  DATE :        03/02/2011
//  AUTEUR :      GCX (APSIDE)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_RecuperationMasqueLogoEtiquette (int nItfe, T_TCOM_BASE *tcomBase, char *strNumserie, char *strCodeProduit, char *strIndiceProduit, char *strServeurHttp, char *strUrlPage, char *strLogo, char *strErreurMessage )
{
    int     errorOccured = FALSE;
    //int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
	int     error = 0;
	char 	*LogoTemp = {"\0"};
	
	// =================================
    // = Recuperation Logo Etiquette   =
	// =	IP STC => 10.154.249.76    =
	// =	IP BYO => 10.25.249.20     =
	// =    IP BRA => 135.25.11.210"   =
	// =	IP UKR => 10.254.73.45	   =
    // =================================
	// [SUPPRESSION TEMPORAIRE TRACACOM]
	
	errChk(-1);  // pour ne pas sortir OK par inadvertance
	

	/*TracaCom_FonctionsMDT_FonctionsMDT_RecuperationMasqueLogoEtiquette (
		tcomBase->instTracaCom, 
		strNumserie, 
		strCodeProduit, 
		strIndiceProduit, 
		tcomBase->adresseTracacom,
		URL, 
		&LogoTemp,
		&errorOccured,&errorCode, &errorMsg, &errorRequete, NULL);  */
	
	strcpy (strLogo, LogoTemp);
	
	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( errorMsg == NULL || errorRequete == NULL )
		errChk(TCOM_ERREUR_RESEAU);
	
	if (errorOccured)
        errChk(-1);
	
	if (LogoTemp != NULL)
		// Libération des ressources
    	// -------------------------
		CDotNetFreeMemory(LogoTemp);

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
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


// ==============================================================================
// FONCTION :     TCOM_RecuperationMasqueEtiquette
// ------------------------------------------------------------------------------
// PROTOTYPE :    TCOM_RecuperationMasqueEtiquette ( T_TCOM_BASE *tcomBase, 
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
//  VERSION :     S08012CA46
//  DATE :        14/01/2011
//  AUTEUR :      GCX (APSIDE)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_RecuperationMasqueEtiquette ( int nItfe, T_TCOM_BASE *tcomBase, char *strNumserie, char *strCodeProduit, char *strIndiceProduit, char *strServeurHttp, char *strUrlPage, char *strMasque, char *strErreurMessage )
{
    int     errorOccured = FALSE;
    //int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
	int     error = 0;
	char 	*MasqueTemp = {"0"};   

    // =================================
    // = Recuperation Masque Etiquette =
    // =	IP STC => 10.154.249.76    =
	// =	IP BYO => 10.25.249.20	   =
	// =    IP BRA => 135.25.11.210"   =
    // =================================
	// [SUPPRESSION TEMPORAIRE TRACACOM]
	
	errChk(-1);  // pour ne pas sortir OK par inadvertance
	
	
	
	/*TracaCom_FonctionsMDT_FonctionsMDT_RecuperationMasqueEtiquette (
		tcomBase->instTracaCom, 
		strNumserie, 
		strCodeProduit, 
		strIndiceProduit, 
		tcomBase->adresseTracacom,
		URL, 
		&MasqueTemp, 
		&errorOccured,&errorCode, &errorMsg, &errorRequete, NULL);  */
	
	strcpy (strMasque, MasqueTemp);
	
	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( errorMsg == NULL || errorRequete == NULL )
		errChk(TCOM_ERREUR_RESEAU);
	
	if (errorOccured)
        errChk(-1);
	
	if (strMasque != NULL)
		// Libération des ressources
    	// -------------------------
		CDotNetFreeMemory(MasqueTemp);

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
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






// ==============================================================================
// FONCTION :     TCOM_RecuperationSectionParamètres
// ------------------------------------------------------------------------------
// PROTOTYPE :    TCOM_RecuperationSectionParamètres ( T_TCOM_BASE *tcomBase, 
//													char *NomSectionParametre, 
//													char **TabParametresDetails, 
//													int	 *NombreParametresDetails, 
//													char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase           : Paramètres de la base.
//                - char *NomSectionParamètre		: Nom de la section à récupérer
//                - char **TabParametresDetails		: Tableau de retour des paramètres de la section
//                - int	 *NombreParametresDetails	: Calcul du nombre de paramètres
//                - char *strErreurMessage          : Message d'erreur.
/// ------------------------------------------------------------------------------
// RETOUR :
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Récupération des paramètresdétaillés d'une section de paramètre 
//				  d'un paramètrage d'application !!
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S08012DA56
//  DATE :        19/09/2012
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_RecuperationSectionParametres ( T_TCOM_BASE *tcomBase, char *NomSectionParametre, 	char  ***TabParametresDetails, int *NombreLignesParametresDetails, int *NombreColonnesParametresDetails, char *strErreurMessage )
{
    int     errorOccured = FALSE;
    int     errorCode = 0;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
	int     error = 0;
	char	*CheminApplication = NULL;	  	// Non utilisé mais nécessaire pour appel fonction traça
	char	*Observation = NULL;			// Non utilisé mais nécessaire pour appel fonction traça
	char    *Valeur = NULL;					// Non utilisé mais nécessaire pour appel fonction traça
	//char 	VERSIONTCOM[2] = "1";			// Nom de version pour l'appli paramétrée en Base

	__int64 id_Parametrage ;
 	__int64 id_Parametre ;
 	__int64 index ;
	

    // =======================================
    // = Récupération de l'ID du paramètrage =
    // =======================================
	// [SUPPRESSION TEMPORAIRE TRACACOM]

	//errChk(-1);  // pour ne pas sortir OK par inadvertance

	
	SCProduction_GestionProductions_RecuperationParametrage ( tcomBase->instSCProduction, 
																gPosteInfos.chNom,
																TCOM_BDP_NOM, 
																TCOM_VERSION_APPLI, 
																&id_Parametrage, 
																&CheminApplication,
																&Observation, 
																&errorOccured,&errorCode, &errorMsg, &errorRequete, NULL);	   
	
	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( errorMsg == NULL || errorRequete == NULL )
		errChk(TCOM_ERREUR_RESEAU);
	
	if (errorOccured)
        errChk(-1);

    // =====================================
    // = Récupération de l'ID du paramètre =
    // =====================================
	
	// [SUPPRESSION TEMPORAIRE TRACACOM]

	//errChk(-1);  // pour ne pas sortir OK par inadvertance

	
	SCProduction_GestionProductions_RecuperationParametre (
		tcomBase->instSCProduction, 
		NomSectionParametre, 
		id_Parametrage, 
		&id_Parametre, 
		&index, 
		&Valeur,
		&Observation, 
		&errorOccured,&errorCode, &errorMsg, &errorRequete, NULL); 
	
		
	
	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( errorMsg == NULL || errorRequete == NULL )
		errChk(TCOM_ERREUR_RESEAU);
	
	if (errorOccured)
        errChk(-1);

	
    // ====================================================
    // = Récupération du tableau des paramètres détaillés =
    // ====================================================
	
	// [SUPPRESSION TEMPORAIRE TRACACOM]

	//errChk(-1);  // pour ne pas sortir OK par inadvertance


	SCProduction_GestionProductions_RecuperationParametresDetails (tcomBase->instSCProduction, 
																	id_Parametre, 
																	TabParametresDetails, 
																	NombreLignesParametresDetails, 
																	NombreColonnesParametresDetails, 
																	&errorOccured,&errorCode, &errorMsg, &errorRequete, NULL); 
	
	if (errorOccured)
        errChk(-1);


Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
		else if (errorMsg != NULL)
            sprintf (strErreurMessage, "%s", errorMsg);
	}
	
	// =============================
	// = Libération des ressources =
	// =============================
	if (CheminApplication != NULL)
	   	CDotNetFreeMemory(CheminApplication);
	if (Observation != NULL)
		CDotNetFreeMemory(Observation);
	if (Valeur != NULL)
		CDotNetFreeMemory(Valeur);

	if (errorMsg != NULL)
        CDotNetFreeMemory(errorMsg);
    if (errorRequete != NULL)
        CDotNetFreeMemory(errorRequete);
	
    if(error)
    {  
        return -1;
    }

    return 0;
	
}




// ==============================================================================
// FONCTION :     TCOM_V2_GenerationSnClient
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_V2_GenerationSnClient ( T_TCOM_BASE *tcomBase, 
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
//  DESCRIPTION :strFormatClientSapme pour besoin assemblage
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_V2_GenerationSnClient (int nItfe, T_TCOM_BASE *tcomBase, char *strFormatClient, char *strFormatClientSapme,char *strSnClient, char *strErreurMessage, int nbParam, ... )
{
	int     error = 0;
    int     errorOccured = FALSE;
    int     errorCode = 0;
    int     idxParam;
    char    *errorMsg = NULL;
    char    *errorRequete = NULL;
    char    *strNumSerie = NULL;
    char    **tabParametres = NULL;
	int					iExistenceSnClient = -1;
	int					iExistenceVar = -1;
    T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	
	char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	
    va_list list;
	
	
	
	// Affichage Dans le log du Sn Client
	// ----------------------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Génération du Sn Client : %s en cours...", strFormatClient);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}

	
	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(strSnClient,"");
	strcpy(strErreurMessage,"");
	
	
    // ===========================================
    // = Vérification si Sn Client déjà assemblé =
    // ===========================================
	
	errChk ( SCPROD_RecuperationComposant ( 	nItfe,
    			                            	&gTcomBase,
                                    			ptrVariablesTraca->PfinSfcSAPME,
												strFormatClientSapme,
												strSnClient,
												&iExistenceSnClient,
                                    			strErreurMessage )); 

	
    // ========================================
    // = Génération du numéro de série du STB =
    // ========================================
	if (iExistenceSnClient == 0)
	{
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

	
		// Lock BDD
		// --------
		if (LOCK_BDD == 1)
			CmtGetLock (IdLockBDD);
	
		SCPROD_TraceAppels	(nItfe,"Generating Customer SN : Begin");

		// ========================================
	    // = Génération du numéro de série du STB =
	    // ========================================
	    SCProduction_GestionProductions_GenerationNumSerieClient_tcm(
	        tcomBase->instSCProduction,
	        strFormatClient,
	        tabParametres,
	        nbParam,
	        &strNumSerie,
	        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);

		SCPROD_TraceAppels	(nItfe,"Generating Customer SN : End  ");

		// Unlock BDD
		// --------
		if (LOCK_BDD == 1)
			CmtReleaseLock (IdLockBDD);

	
		// Verification pointeurs non nuls => en cas de sortie de la fct en time out
		// -------------------------------------------------------------------------
		if ( strNumSerie == NULL || errorMsg == NULL || errorRequete == NULL)
			errChk(TCOM_ERREUR_RESEAU);
	
		if (errorOccured)
	        errChk(-1);

	    // Vérification de la génération du numéro de série
	    // ------------------------------------------------
	    if ( strNumSerie == NULL )
	    	errChk(-2);

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
	
	
		
		// ==================================================================
		// = Mise en stock du composant						    		    =
		// ==================================================================
		
		errChk ( SCPROD_AjoutStockComposant (nItfe, 
											 &gTcomBase, 
											 strFormatClientSapme, 
											 SCPROD_INDICE_DEFAUT, 
											 strSnClient, 
											 &iExistenceVar, 
											 ptrVariablesTraca->PfinSfcSAPME, 
											 strErreurMessage));
		
	
		 // ==================================================================
		 // = Si génération bien effectué, on assemble le SnClient au SnPFIN =
		 // ==================================================================
	
			errChk ( SCPROD_AssemblageComposant ( 	nItfe,
	        			                            &gTcomBase,
	                                        		strSnClient,
	                                        		strFormatClientSapme,
													ptrVariablesTraca->PfinSfcSAPME,
													SCPROD_ASSEMBLAGE_INVENTORY_ID,
													NOM_OPERATION,							 
													ptrVariablesTraca->NomRessourceSAPME,
	                                        		strErreurMessage )); 
	}
	
	
	// =========================================================
    // = S'il existe déjà on l'a déjà récupèré et on le loggue =
    // =========================================================
	else
	{  
		// Affichage Dans le log du Sn Client
		// ----------------------------------
		if (gFlagLogSAPME == TRUE )
		{
			sprintf (chMsgInfo, "Sn client :%s est déjà assemblé sur le SFC : %s", strSnClient,ptrVariablesTraca->PfinSfcSAPME);
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}

	}	
	
	

Error:	
    // =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        
		if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
		else if ( error == -2)
		    sprintf (strErreurMessage, GET_MESSAGE(TRC_MSG_ERR_SN_NON_GENERE));
		else if (errorMsg != NULL)
            sprintf (strErreurMessage, "%s", errorMsg);
		

        
		// Libération des ressources
    	// -------------------------
		if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        return -1;
    }   
        
	// Libération des ressources
	// -------------------------
	if (errorMsg != NULL)
        CDotNetFreeMemory(errorMsg);
    if (errorRequete != NULL)
        CDotNetFreeMemory(errorRequete);
	
	
	
	// Affichage Dans le log du Sn Client
	// ----------------------------------
	if (gFlagLogSAPME == TRUE )
	{
		sprintf (chMsgInfo, "Génération/Récupération Sn client : %s OK.\n", strSnClient);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
	}
	

    return 0;
}



// ==============================================================================
// FONCTION :     TCOM_V2_GenerationSnClient
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TCOM_V2_GenerationSnClient ( T_TCOM_BASE *tcomBase, 
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
//  DESCRIPTION :strFormatClientSapme pour besoin assemblage
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TCOM_GenerationSnClient (int nItfe, T_TCOM_BASE *tcomBase, char *strFormatClient, char *strSnClient, char *strErreurMessage, int nbParam, ... )
{
	int     error = 0;
    int     errorOccured = FALSE;
    int     errorCode = 0;
    int     idxParam;
	int		iExistenceSnClient = -1;
	
    T_VARIABLES_TRACA   *ptrVariablesTraca = &gSlot[nItfe].variablesTraca;
	
	char *errorMsg = NULL;       
	char *strNumSerie = NULL;    
	char *errorRequete = NULL;   
	char **tabParametres = NULL; 
	char chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	
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

	
	// Lock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtGetLock (IdLockBDD);
	
	SCPROD_TraceAppels	(nItfe,"Generating Customer SN : Begin");

	// ========================================
    // = Génération du numéro de série du STB =
    // ========================================
    SCProduction_GestionProductions_GenerationNumSerieClient_tcm(
        tcomBase->instSCProduction,
        strFormatClient,
        tabParametres,
        nbParam,
        &strNumSerie,
        &errorOccured, &errorCode, &errorMsg, &errorRequete, NULL);

	SCPROD_TraceAppels	(nItfe,"Generating Customer SN : End  ");

	// Unlock BDD
	// --------
	if (LOCK_BDD == 1)
		CmtReleaseLock (IdLockBDD);

	
	// Verification pointeurs non nuls => en cas de sortie de la fct en time out
	// -------------------------------------------------------------------------
	if ( strNumSerie == NULL || errorMsg == NULL || errorRequete == NULL)
		errChk(TCOM_ERREUR_RESEAU);
	
	if (errorOccured)
        errChk(-1);

    // Vérification de la génération du numéro de série
    // ------------------------------------------------
    if ( strNumSerie == NULL )
    	errChk(-2);

    // Enregistrement du numéro de série généré
    // ----------------------------------------
    strcpy (strSnClient, strNumSerie);
	
	
	// Verif taille SN genéré par TracaCom, si = 0 on sort en erreur
	//--------------------------------------------------------------
	if(strlen (strSnClient) == 0)
	{
    	errChk (-1);
	} 
	


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

Error:	
    // =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
		else if ( error == -2)
		    sprintf (strErreurMessage, GET_MESSAGE(TRC_MSG_ERR_SN_NON_GENERE));
		else if (errorMsg != NULL)
            sprintf (strErreurMessage, "%s", errorMsg);
        
		// Libération des ressources
    	// -------------------------
		if (errorMsg != NULL)
            CDotNetFreeMemory(errorMsg);
        if (errorRequete != NULL)
            CDotNetFreeMemory(errorRequete);
        return -1;
    }   
        
	// Libération des ressources
	// -------------------------
	if (errorMsg != NULL)
        CDotNetFreeMemory(errorMsg);
    if (errorRequete != NULL)
        CDotNetFreeMemory(errorRequete);

    return 0;
}






// ==============================================================================
// FONCTION :     SCPROD_ImprimerViaDll
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_ImprimerViaDll ( T_TCOM_BASE *tcomBase, 
//                                                       
//                                                       
//                                                       
//                                                       
//                                                       
//                                                       
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_TCOM_BASE *tcomBase           : Paramètres de la base.
//                - 
//                - 
//                - 
//                - 
//                - 
//                - 
/// ------------------------------------------------------------------------------
// RETOUR :
//                - 
//                - 
//                - 
// ------------------------------------------------------------------------------
// DESRIPTION :   Impression via une fonction de la dll plutôt que par Start/Complete
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     BPO_V2.00.07
//  DATE :        2015-07-28
//  AUTEUR :      MPI
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_ImprimerViaDll (int nItfe,  T_TCOM_BASE *tcomBase, char *SFC, char *chNumArticle, int QteEtiquettes, char  *chNomZebra , char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
    char    			*chMsgSCProd = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
    char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	
	// ========================================
    // = Lecture et Ecriture d'une clé en BDD =
    // ========================================
	
	// Attention lock pause problème
	//----------------------------------
    status = SCProduction_GestionProductions_PrintDocument(
		tcomBase->instSCProduction,
		SFC,
		chNumArticle, 
		QteEtiquettes,
		chNomZebra,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);
	
	
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	
	
	
	
Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       	else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       	else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
		// Affichage Dans le log 
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{   
			sprintf (chMsgInfo, "Erreur. Retour DLL: %s ", chMsgTemp );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
	}
    
	
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;  
	
	
	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);


    return 0;
}



// ==============================================================================
// FONCTION :     SCPROD_Trace_Appels
// ------------------------------------------------------------------------------
// PROTOTYPE :    SCPROD_Trace_Appels ( int nItfe, 
//										char *Message)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe 						: Numéro d'interface
//                - char *Message					: Message à tracer
//
// ------------------------------------------------------------------------------
// RETOUR :
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Tracer les appels aux fonctions de la DLL SCPRODUCTION
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        29/01/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================


int SCPROD_TraceAppels ( int nItfe, char *Message )
{

	T_VARIABLES 		*ptrVariablesConf = &(gSlot[nItfe].variablesConf);
				
    FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_SOUS_ETAPE_TRACA, Message);

	return 0;
}







// ==============================================================================
// FONCTION :     SCPROD_InformationsOF
// ------------------------------------------------------------------------------
// PROTOTYPE :    int SCPROD_InformationsOF ( int nItfe,
//                                              char *OrdreFabrication,
//                                              char *RetourCodeProduit,
//                                              char *RetourIndiceProduit,
//                                              char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe                   : Numéro interface,
//                - char *OrdreFabrication      : OF à récupérer,
//                - char *RetourCodeProduit     : Code produit associé à l'OF
//                - char *RetourIndiceProduit  	: Indice produit associé à l'OF
//                - char *strErreurMessage      : Message d'erreur,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Renvoie des informations sur un OF donné.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        16/11/2015
//  AUTEUR :      TNI
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     
//  DATE :        
//  AUTEUR :      
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int SCPROD_InformationsBom ( int nItfe, T_TCOM_BASE *tcomBase, char *OrdreFabrication, char *RetourCodeProduit,char *RetourIndiceProduit, char *RetourTypeOF, char *strErreurMessage )
{
    int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
	char				*chCodeProduitOF = NULL;
	char				*chIndiceProduitOF = NULL;
	char				*chTypeOF = NULL;
    char    			*chMsgSCProd = NULL;
    char    			chMsgTemp [SCPROD_MSG_LONG_MAX] = {'\0'}; 
	
	// ==================
    // = Init Variables =
    // ==================	 
	
	strcpy(RetourCodeProduit,"");
	strcpy(RetourIndiceProduit,"");
	strcpy(RetourTypeOF,"");
	strcpy(strErreurMessage,"");


	// ======================
    // = Appel Fonction DLL =
    // ======================
	
	status = SCProduction_GestionProductions_RecuperationDetailsOFV2 (
		tcomBase->instSCProduction,
		OrdreFabrication,
		&chCodeProduitOF,
		&chIndiceProduitOF,
		&chTypeOF,
		&bResultSCProd,
		&chMsgSCProd,
		NULL);
			 
	// On vérifie la longueur du message retourné
	// ------------------------------------------
	if (strlen (chMsgSCProd) >= SCPROD_MSG_LONG_MAX)
		errChk(SCPROD_ERREUR_LONG_MSG);

	// On recopie le message puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chMsgSCProd != NULL)
	{
		strcpy(chMsgTemp,chMsgSCProd);
        CDotNetFreeMemory(chMsgSCProd);
	}
	
	// On recopie le Code produit puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chCodeProduitOF != NULL)
	{
		strcpy(RetourCodeProduit,chCodeProduitOF);
        CDotNetFreeMemory(chCodeProduitOF);
	}

	// On recopie l'indice produit puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chIndiceProduitOF != NULL)
	{
		strcpy(RetourIndiceProduit,chIndiceProduitOF);
        CDotNetFreeMemory(chIndiceProduitOF);
	}

	// On recopie le type OF puis on libère la mémoire .NET
	// ----------------------------------------------------
	if (chTypeOF != NULL)
	{
		strcpy(RetourTypeOF,chTypeOF);
        CDotNetFreeMemory(chTypeOF);
	}

	// Si le status est mal passé ==> erreur .NET
	// ------------------------------------------
	if (status != 0)
		errChk(SCPROD_ERREUR_DOT_NET);
	
	// Si le bResult est mal passé ==> erreur fonction DLL
	// ---------------------------------------------------
 	if (bResultSCProd != TRUE)
		errChk(SCPROD_ERREUR_BRESULT);
	

Error:    
	// =======================
    // = gestion des erreurs =
    // =======================
    if(error)
    {
        if (error == SCPROD_ERREUR_BRESULT)
			sprintf (strErreurMessage,"Erreur Retour DLL SCProduction : %s", chMsgTemp);
        else if (error == TCOM_ERREUR_RESEAU)
			strcpy (strErreurMessage, GET_MESSAGE(TCOM_MESSAGE_ERREUR_RESEAU));
       else if (error == SCPROD_ERREUR_LONG_MSG)
			strcpy (strErreurMessage, "Erreur sur longueur Message Retour DLL");
       else if (error == SCPROD_ERREUR_DOT_NET)
			strcpy (strErreurMessage, "Erreur contrôleur .NET DLL");
		else if (chMsgTemp != NULL)
            sprintf (strErreurMessage, "Erreur Inconnue sur Fonction Dll SCProduction : %s",chMsgTemp);
		
	}
    
	// ==========================================================
	// = Libération des ressources ==> Directement dans le code =
	// ==========================================================
 
    if(error)
		return -1;

	// On recopie aussi le message quand tout va bien
	// ----------------------------------------------
	strcpy(strErreurMessage,chMsgTemp);

    return 0;
}



