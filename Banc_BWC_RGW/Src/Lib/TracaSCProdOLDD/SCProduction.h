// CVI wrapper header file for .NET assembly: SCProduction, Version=2.0.0.7, Culture=neutral, PublicKeyToken=null
//
// This is specified by the '__assemblyName' constant in the generated source file.
// If there are multiple versions of this assembly, and you want .NET to determine 
// the appropriate one to load, then you can remove the version, culture, and public 
// key token information from the constant and just specify the name of the assembly.
//
// Other assemblies referenced by the target assembly:
// Name:+ mscorlib, Location: C:\Windows\Microsoft.NET\Framework\v4.0.30319\mscorlib.dll
//
// If any assembly, including the target assembly, is not installed in the
// Global Assembly Cache (GAC) or in the application directory, and the wrapper
// code needs to load the assembly to convert types like arrays and enums, then
// you must register the path of the assembly with the CVI .NET library by
// calling CDotNetRegisterAssemblyPath before calling the wrapper code.
//
// Types exposed by the target assembly but defined in other assemblies:
// CVI name: System_Collections_Generic_List_T1, .NET name: System.Collections.Generic.List`1[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Collections_Generic_Dictionary_T2, .NET name: System.Collections.Generic.Dictionary`2[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089],[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Collections_Hashtable, .NET name: System.Collections.Hashtable, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Collections_Generic_Dictionary_T2, .NET name: System.Collections.Generic.Dictionary`2[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089],[System.Collections.Generic.Dictionary`2[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089],[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], Assembly: mscorlib, Module: Global Assembly Cache

#include <cvidotnet.h>

#ifdef __cplusplus
extern "C" {
#endif

// Type definitions
typedef struct __SCProduction_GestionProductions * SCProduction_GestionProductions;
typedef struct __System_Collections_Generic_Dictionary_T2 * System_Collections_Generic_Dictionary_T2;
typedef struct __System_Collections_Generic_List_T1 * System_Collections_Generic_List_T1;
typedef struct __System_Collections_Generic_Dictionary_T2 * System_Collections_Generic_Dictionary_T2;
typedef struct __System_Collections_Hashtable * System_Collections_Hashtable;




// Global Functions
int CVIFUNC Initialize_SCProduction(void);
int CVIFUNC Close_SCProduction(void);

// Type: SCProduction.GestionProductions
int CVIFUNC SCProduction_GestionProductions__Create(
	SCProduction_GestionProductions * __instance,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_UpdateOrInsertPropertyPKT(
	SCProduction_GestionProductions __instance,
	char * SerialNumber,
	char * PropertyName,
	char * PropertyValue,
	int * STATUS,
	char ** Response,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_GenerationSFCdepuisOFV2(
	SCProduction_GestionProductions __instance,
	char * strOrdreFab,
	char ** strsfcRef,
	char ** sMessageRetour,
	int * blnResultat,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationConfigueProduit(
	SCProduction_GestionProductions __instance,
	char * Article,
	char * Version,
	char *** dcParameterList,
	ssize_t * __dcParameterListLength1,
	ssize_t * __dcParameterListLength2,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationSequenceFromBOM(
	SCProduction_GestionProductions __instance,
	char * Bom,
	char * indice,
	char * componentContext,
	double * sequence,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationComposantdepuisSFC(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * composant,
	char * indice,
	char ** ResultCode,
	char ** InventoryId,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementNonConformites(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char * operation,
	char * Ressource,
	char ** stabNonconformit_s,
	ssize_t __stabNonconformit_sLength1,
	ssize_t __stabNonconformit_sLength2,
	int * bResultat,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementNonConformitesSansRoutage(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char * operation,
	char * Ressource,
	char ** stabNonconformit_s,
	ssize_t __stabNonconformit_sLength1,
	ssize_t __stabNonconformit_sLength2,
	int * bResultat,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_removeSlotGroup(
	SCProduction_GestionProductions __instance,
	char * Resource,
	char * SlotGroup,
	char * indiceSlot,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementProprieteNumSerie(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char * strNomPropriete,
	char * strValeurPropriete,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementProprietesNumSerie(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char ** TabPropriete,
	ssize_t __TabProprieteLength1,
	ssize_t __TabProprieteLength2,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementProprietesNumSeries(
	SCProduction_GestionProductions __instance,
	char ** strNumSerie,
	ssize_t __strNumSerieLength,
	char ** TabPropriete,
	ssize_t __TabProprieteLength1,
	ssize_t __TabProprieteLength2,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecupererStatProduitAvecFiltre(
	SCProduction_GestionProductions __instance,
	char * startDate,
	char * endDate,
	char * Operation,
	char * Line,
	char *** listOfProductsWithStats,
	ssize_t * __listOfProductsWithStatsLength1,
	ssize_t * __listOfProductsWithStatsLength2,
	int * blnResultat,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecupererStatProduitAvecFiltreRessource(
	SCProduction_GestionProductions __instance,
	char * startDate,
	char * endDate,
	char * Operation,
	char * ressource,
	char *** listOfProductsWithStats,
	ssize_t * __listOfProductsWithStatsLength1,
	ssize_t * __listOfProductsWithStatsLength2,
	int * blnResultat,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_AjoutStockComposantAvecQuantite(
	SCProduction_GestionProductions __instance,
	char * strCodeComposant,
	char * strValeur,
	double quantite,
	char * Fournisseur,
	char * Lot_fournisseur,
	char * Magasin_de_stockage_ERP,
	char * Ref_fabricant,
	char * VENDOR_DATA_CODE,
	char * Fabricant,
	char * Materiel_Document,
	char * Date_Recep_ERP,
	char * Code_particulier,
	char * Emplacement,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_UpdateStockComposant(
	SCProduction_GestionProductions __instance,
	char * strCodeComposant,
	char * strValeur,
	double quantite,
	char * Fournisseur,
	char * Lot_fournisseur,
	char * Magasin_de_stockage_ERP,
	char * Ref_fabricant,
	char * VENDOR_DATA_CODE,
	char * Fabricant,
	char * Materiel_Document,
	char * Date_Recep_ERP,
	char * Code_particulier,
	char * Emplacement,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_AssembleComposant(
	SCProduction_GestionProductions __instance,
	char * strSFC,
	char * operation,
	char * Ressource,
	char * strComposant,
	char * identifiant,
	char * NomAttribute,
	char * strLibelle,
	int * blnResultat,
	char ** EtatAssemblage,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_AssemblageComposant_v2(
	SCProduction_GestionProductions __instance,
	char * sfc,
	char * operation,
	char * NomAttribute,
	char * value,
	char * bom,
	char * indicebom,
	char * sequebcebom,
	char * codecomposant,
	char * indicecomposant,
	char ** EtatAssemblage,
	int * blnResultat,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_AssemblageComponetV3(
	SCProduction_GestionProductions __instance,
	char * sfc,
	char * operation,
	char * NomAttribute,
	char * value,
	char * codecomposant,
	char * indicecomposant,
	char ** EtatAssemblage,
	int * blnResultat,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_recuperationdetailleBomfromOF(
	SCProduction_GestionProductions __instance,
	char * strOrdreFab,
	char ** plannedBomRef,
	char ** indiceBomRef,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationDetailsBOMwithOF(
	SCProduction_GestionProductions __instance,
	char * strOrdreFab,
	char ** plannedBomRef,
	char ** indiceBomRef,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_PrintPlanCarton(
	SCProduction_GestionProductions __instance,
	char ** TabSFC,
	ssize_t __TabSFCLength,
	char * CodeArticle,
	char * disignation,
	char * indice,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_AssembleTableauComposants(
	SCProduction_GestionProductions __instance,
	char * strSFC,
	char * operation,
	char * Ressource,
	char ** tabAssemblages,
	ssize_t __tabAssemblagesLength1,
	ssize_t __tabAssemblagesLength2,
	int * blnResultat,
	char ** EtatAssemblage,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationDetailsOF(
	SCProduction_GestionProductions __instance,
	char * strOrdreFab,
	char ** strItemRef,
	char ** strItemRevision,
	char ** strTypeOrdreFab,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_GenerationNSClient(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char * operation,
	char * Ressource,
	char * strFormatNSClient,
	char * indice,
	char ** strNSClient,
	char ** EtatAssemblage,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationInformationSFC(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char ** strOrdreFab,
	char ** strCodeProduit,
	char ** strIndiceProduit,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationInformationSFC_HDD(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char ** strCodeProduit,
	char ** strIndiceProduit,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationInformationSFC_SYNCHRO(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * operation,
	char ** strOrdreFab,
	char ** strCodeProduit,
	char ** strIndiceProduit,
	char ** strGamme,
	char ** strGammeIndice,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationSFCdepuisComposantV2(
	SCProduction_GestionProductions __instance,
	char * SFC_ENF,
	char * inventoryId,
	char ** SFCParent,
	char ** strCodeRetour,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_updateProvisionningStatus(
	SCProduction_GestionProductions __instance,
	char ** sfcPfin,
	ssize_t __sfcPfinLength,
	char * mode,
	char ** infoPfin,
	ssize_t __infoPfinLength1,
	ssize_t __infoPfinLength2,
	char ** infoCie,
	ssize_t __infoCieLength1,
	ssize_t __infoCieLength2,
	int * bresult,
	char ** statut,
	char ** ficherName,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_CreationSFC_Transfertsite(
	SCProduction_GestionProductions __instance,
	char * resourceRef,
	char * itemRef,
	char * indiceRef,
	char * operationRef,
	char * indiceOperation,
	char * sfc,
	char ** sfcRef,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationProprietesSFC(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char *** TabValeur,
	ssize_t * __TabValeurLength1,
	ssize_t * __TabValeurLength2,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationProprieteSFC(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * NomPropriete,
	int * bResultat,
	char ** ValeurPropriete,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_AjoutStockOuRecuperationEtatComposant(
	SCProduction_GestionProductions __instance,
	char * inventoryId,
	char * item,
	char * revision,
	int insertion,
	char ** ResultCode,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_Signoff(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * Ressource,
	char * Operation,
	char * Revision,
	char ** strCodeProduit,
	char ** StepId,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_CreationShopOrder(
	SCProduction_GestionProductions __instance,
	char * strOrdreFab,
	char * strItem,
	char * indice,
	char ** ShopOrder,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_changerOF(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char * OF,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_get_printing_datas(
	SCProduction_GestionProductions __instance,
	char * PRODUCT_CODE,
	char * PRODUCT_SERIAL,
	char * DATA,
	char * DATA_FORMAT,
	char ** STATUS,
	char ** DATA_VALUE,
	char ** strMessageRetour,
	int * bresult,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementNonConformite(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char * operation,
	char * Ressource,
	char * strCodeErreur,
	char * strLibelleErreur,
	char * REF_DES,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationCle(
	SCProduction_GestionProductions __instance,
	char * strNomTableCle,
	char * strNumSerie,
	char * strCodeProduit,
	char *** tabValeursCle,
	ssize_t * __tabValeursCleLength,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementTrace(
	SCProduction_GestionProductions __instance,
	char * numserie_sapme,
	char * trace,
	char * op_ration,
	int * blnErreurSurvenue,
	int * intErreurCode,
	char ** strErreurMessage,
	char ** strErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationParametreDetail(
	SCProduction_GestionProductions __instance,
	char * nomParametreDetail,
	__int64 id_parametre,
	__int64 * id_parametreDetail,
	__int64 * index,
	char ** valeur,
	char ** observation,
	int * erreurSurvenue,
	int * erreurCode,
	char ** erreurMessage,
	char ** erreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationParametrage(
	SCProduction_GestionProductions __instance,
	char * nomPoste,
	char * nomApplication,
	char * versionApplication,
	__int64 * id_parametrage,
	char ** cheminApplicationPoste,
	char ** observation,
	int * erreurSurvenue,
	int * erreurCode,
	char ** erreurMessage,
	char ** erreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_ActivationModeProto(
	SCProduction_GestionProductions __instance,
	char * nomPoste,
	char * nomApplication,
	char * versionApplication,
	int modeProto,
	int * erreurSurvenue,
	int * erreurCode,
	char ** erreurMessage,
	char ** erreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementParametre(
	SCProduction_GestionProductions __instance,
	__int64 id_parametrage,
	char * nom,
	__int64 index,
	char * valeur,
	char * observation,
	__int64 * id_parametre,
	int * erreurSurvenue,
	int * erreurCode,
	char ** erreurMessage,
	char ** erreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementParametreDetail(
	SCProduction_GestionProductions __instance,
	__int64 id_parametre,
	char * nom,
	__int64 index,
	char * valeur,
	char * observation,
	__int64 * id_parametreDetail,
	int * erreurSurvenue,
	int * erreurCode,
	char ** erreurMessage,
	char ** erreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_ModificationParametre(
	SCProduction_GestionProductions __instance,
	__int64 id_parametre,
	char * nom,
	__int64 index,
	char * valeur,
	char * observation,
	int * erreurSurvenue,
	int * erreurCode,
	char ** erreurMessage,
	char ** erreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_ModificationParametreDetail(
	SCProduction_GestionProductions __instance,
	__int64 id_parametreDetail,
	char * nom,
	__int64 index,
	char * valeur,
	char * observation,
	int * erreurSurvenue,
	int * erreurCode,
	char ** erreurMessage,
	char ** erreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationApplication(
	SCProduction_GestionProductions __instance,
	char * nomApplication,
	char * versionApplication,
	__int64 * id_application,
	char ** cheminApplication,
	char ** cheminSetup,
	int * actif,
	char ** observation,
	int * erreurSurvenue,
	int * erreurCode,
	char ** erreurMessage,
	char ** erreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationLocalisations(
	SCProduction_GestionProductions __instance,
	char *** tabLocalisations,
	ssize_t * __tabLocalisationsLength1,
	ssize_t * __tabLocalisationsLength2,
	int * erreurSurvenue,
	int * erreurCode,
	char ** erreurMessage,
	char ** erreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationParametre(
	SCProduction_GestionProductions __instance,
	char * nomParametre,
	__int64 id_parametrage,
	__int64 * id_parametre,
	__int64 * index,
	char ** valeur,
	char ** observation,
	int * erreurSurvenue,
	int * erreurCode,
	char ** erreurMessage,
	char ** erreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_ModificationPosteVariable(
	SCProduction_GestionProductions __instance,
	char * strCodePoste,
	char * strNomVariable,
	char * strValeur,
	__int64 * lngId_Variable_Poste,
	int * blnErreurSurvenue,
	int * intErreurCode,
	char ** strErreurMessage,
	char ** strErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationParametres(
	SCProduction_GestionProductions __instance,
	__int64 id_parametrage,
	char *** tabParametres,
	ssize_t * __tabParametresLength1,
	ssize_t * __tabParametresLength2,
	int * erreurSurvenue,
	int * erreurCode,
	char ** erreurMessage,
	char ** erreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationParametresDetails(
	SCProduction_GestionProductions __instance,
	__int64 id_parametre,
	char *** tabParametresDetails,
	ssize_t * __tabParametresDetailsLength1,
	ssize_t * __tabParametresDetailsLength2,
	int * erreurSurvenue,
	int * erreurCode,
	char ** erreurMessage,
	char ** erreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationTraductions(
	SCProduction_GestionProductions __instance,
	char * nomApplication,
	char * versionApplication,
	__int64 id_localisation,
	char *** tabTraductions,
	ssize_t * __tabTraductionsLength1,
	ssize_t * __tabTraductionsLength2,
	int * erreurSurvenue,
	int * erreurCode,
	char ** erreurMessage,
	char ** erreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationTestPlan(
	SCProduction_GestionProductions __instance,
	char * resource,
	char * itemRef,
	char * indice,
	char *** testPlan,
	ssize_t * __testPlanLength,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationParametrageTestPlan(
	SCProduction_GestionProductions __instance,
	char * testPlanId,
	char * measurementDescription,
	char ** description,
	System_Collections_Generic_Dictionary_T2 * testPlanMeasurementList,
	System_Collections_Generic_Dictionary_T2 * testPlanParamList,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationListeArticle(
	SCProduction_GestionProductions __instance,
	char * strGroupe,
	char ** description,
	char *** itemGroupMembers,
	ssize_t * __itemGroupMembersLength,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationListeGammeReprise(
	SCProduction_GestionProductions __instance,
	System_Collections_Generic_List_T1 * router,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationDonneesArticle(
	SCProduction_GestionProductions __instance,
	char * Attribute,
	char * ProductCode,
	char * Indice,
	char *** CustomField,
	ssize_t * __CustomFieldLength1,
	ssize_t * __CustomFieldLength2,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_GetCustoStatus(
	SCProduction_GestionProductions __instance,
	char * strIPAdress,
	char ** custoRequestDataArray,
	ssize_t __custoRequestDataArrayLength1,
	ssize_t __custoRequestDataArrayLength2,
	char *** custoStatusArray,
	ssize_t * __custoStatusArrayLength1,
	ssize_t * __custoStatusArrayLength2,
	int * bResult,
	char ** strMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_GenerationSNcarton(
	SCProduction_GestionProductions __instance,
	char * codeproduit,
	char * indice,
	char * UF,
	char * ligne,
	char * usine,
	char * Format,
	int * bresult,
	char ** SNcarton,
	char ** strmassage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_unloadSlotGroup(
	SCProduction_GestionProductions __instance,
	char * Resource,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_SetupSlotConfiguration(
	SCProduction_GestionProductions __instance,
	char * Resource,
	char * State,
	char * SlotConfigId,
	char * Revision,
	char *** SetupSlotConfiguration,
	ssize_t * __SetupSlotConfigurationLength1,
	ssize_t * __SetupSlotConfigurationLength2,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_Recuperation_Historique_NC(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char *** ncCodeRef,
	ssize_t * __ncCodeRefLength1,
	ssize_t * __ncCodeRefLength2,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_CHECK_OR_INSERT_SN_IN_PACKOUT_v2(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * ITEM,
	char * indice,
	char * Code_SSCC,
	char * ressorce,
	int * bresult,
	char ** strmessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_CHECK_OR_INSERT_SN_IN_PACKOUT(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * ITEM,
	char * indice,
	int * bresult,
	char ** strmessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_findSlotGroupByResourceAndState(
	SCProduction_GestionProductions __instance,
	char * Resource,
	char * slotGroupState,
	char *** slotGroupConfiguration,
	ssize_t * __slotGroupConfigurationLength1,
	ssize_t * __slotGroupConfigurationLength2,
	char ** slotGroupRef,
	char ** resourceSetupState,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_getCurrentAndPendingComponentTimeLogRecords(
	SCProduction_GestionProductions __instance,
	char * Resource,
	char *** CurrentAndPendingComponent,
	ssize_t * __CurrentAndPendingComponentLength1,
	ssize_t * __CurrentAndPendingComponentLength2,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_GET_COMP_TIME_LOG_STAGING(
	SCProduction_GestionProductions __instance,
	char * Resource,
	System_Collections_Generic_List_T1 * tabinfo,
	int * bresult,
	char ** strmassage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_ConfigurationBase(
	SCProduction_GestionProductions __instance,
	char * strServeur,
	int intPort,
	char * strBaseDeDonnees,
	char * strUtilisateur,
	char * strPoste,
	int blnDebug,
	int * blnErreurSurvenue,
	int * intErreurCode,
	char ** strErreurMessage,
	char ** strErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_markSfcAsDone(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char * codeproduit,
	char * indice,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_FindSFCByCollectData(
	SCProduction_GestionProductions __instance,
	char * value,
	char * dataField,
	char *** listSFCWithParam,
	ssize_t * __listSFCWithParamLength,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationListeCodeProduit(
	SCProduction_GestionProductions __instance,
	char * ligne,
	char *** listCodeProduits,
	ssize_t * __listCodeProduitsLength,
	int * bresult,
	char ** strMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationInfoLotMetrologie(
	SCProduction_GestionProductions __instance,
	char * ligne,
	char * CodeProduits,
	char * indice,
	char ** information,
	int * bresult,
	char ** strMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationlisteNSlots(
	SCProduction_GestionProductions __instance,
	char * lots,
	char * variable,
	System_Collections_Generic_Dictionary_T2 * information,
	int * bresult,
	char ** strMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationCodeSNclientLinky(
	SCProduction_GestionProductions __instance,
	char * CODE_PRODUIT_METRO,
	char * INDICE_PRODUIT_METRO,
	int * bresult,
	char ** VariableLot,
	char ** strmassage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationCodeSNclientLinky_V2(
	SCProduction_GestionProductions __instance,
	char * CODE_PRODUIT_METRO,
	char * INDICE_PRODUIT_METRO,
	char * var,
	int * bresult,
	char ** VariableLot,
	char ** strmassage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_ConfigurationBase_nrj(
	SCProduction_GestionProductions __instance,
	char * strServeur,
	int intPort,
	char * strBaseDeDonnees,
	char * strUtilisateur,
	char * strPoste,
	int blnDebug,
	int * blnErreurSurvenue,
	int * intErreurCode,
	char ** strErreurMessage,
	char ** strErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_findResourcesByWorkCenter(
	SCProduction_GestionProductions __instance,
	char * WorkCenter,
	int * blnResultat,
	System_Collections_Generic_List_T1 * ressources,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_TchekOperation(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * operation,
	char * indiceOp,
	int * state,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_ArchiveEnMasse(
	SCProduction_GestionProductions __instance,
	char ** strNumSerie,
	ssize_t __strNumSerieLength,
	int bArchiving,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_ChangeProduction(
	SCProduction_GestionProductions __instance,
	char ** sfcList,
	ssize_t __sfcListLength,
	char * newItem,
	char * newItemRevision,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_PASS_EN_MASSE(
	SCProduction_GestionProductions __instance,
	char ** Sfc,
	ssize_t __SfcLength,
	char * Ressource,
	char * Operation,
	char * indice,
	char * next_step,
	int * Statut,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationNCattachee(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char *** ncCodeRef,
	ssize_t * __ncCodeRefLength1,
	ssize_t * __ncCodeRefLength2,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationInformationSFC_Specifique(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char ** strCodeProduit,
	char ** strIndiceProduit,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_Recuperation_DetailsSFC(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char ** strOrdreFab,
	char ** strCodeProduit,
	char ** strIndiceProduit,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationOFdepuisArticle(
	SCProduction_GestionProductions __instance,
	char * itemMask,
	char * itemRevisionMask,
	System_Collections_Hashtable * shopOrder_status,
	int * blnResultat,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_PrintDocument(
	SCProduction_GestionProductions __instance,
	char * sfcRef,
	char * documentName,
	int printQty,
	char * printer,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_PreparationEtatConfigRessource(
	SCProduction_GestionProductions __instance,
	char * ShopOrderBO,
	char * description,
	char * resourceRef,
	int * blnResultat,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_GET_CUSTO(
	SCProduction_GestionProductions __instance,
	char * CIPHERING_KEY_NAME,
	char * PRODUCT_CODE,
	char * PRODUCT_SERIAL,
	char * SESSION_ID,
	char ** CUSTO_PAYLOAD,
	char ** STATUS,
	char ** strMessageRetour,
	int * bresult,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_Pass_assemblage(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * operation,
	char * ressource,
	char * OF,
	int * bresult,
	char ** SFCPARENT,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_INSERT_NS_Lot_Metro_v2(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * ressource,
	int * bresult,
	char ** snlot,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_ControleLotMetrologieDisponible(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * ressource,
	int * bresult,
	char ** snlot,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_COMMIT_CUSTO(
	SCProduction_GestionProductions __instance,
	char * PRODUCT_CODE,
	char * PRODUCT_SERIAL,
	char * SESSION_ID,
	char * FEEDBACK_PAYLOAD,
	char * CIPHERING_KEY_NAME,
	char ** STATUS,
	char ** strMessageRetour,
	int * bresult,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecupererPremierNSClient(
	SCProduction_GestionProductions __instance,
	char * strCodeComposant,
	char * indice,
	char ** firstSfc,
	char ** resultStatus,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_DeconnexionBase(
	SCProduction_GestionProductions __instance,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_InitialisationParametresGestMES(
	SCProduction_GestionProductions __instance,
	char * sCheminFichier,
	int * bRetour,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationParametrageMesuresMES(
	SCProduction_GestionProductions __instance,
	char * dcGroup,
	char * revision,
	char *** dcGroupList,
	ssize_t * __dcGroupListLength1,
	ssize_t * __dcGroupListLength2,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationLigneProductionParPoste(
	SCProduction_GestionProductions __instance,
	char * sNomPoste,
	char ** sLibelleLigne,
	char ** sDescriptionLigne,
	int * iNumeroLigne,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationProduitsParPoste(
	SCProduction_GestionProductions __instance,
	char * sNomPoste,
	char *** stabProduits,
	ssize_t * __stabProduitsLength1,
	ssize_t * __stabProduitsLength2,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationProduitInformations(
	SCProduction_GestionProductions __instance,
	char * sCodeProduit,
	char * sIndiceProduit,
	char ** sCodeOperateur,
	char ** sCodeSousFamille,
	char ** sCodeFamille,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationProduitsParents(
	SCProduction_GestionProductions __instance,
	char * sCodeProduitEnfant,
	char * sIndiceProduitEnfant,
	char *** stabProduitsParents,
	ssize_t * __stabProduitsParentsLength1,
	ssize_t * __stabProduitsParentsLength2,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationProduitsEnfants(
	SCProduction_GestionProductions __instance,
	char * sCodeProduitParent,
	char * sIndiceProduitParent,
	char *** stabProduitsEnfants,
	ssize_t * __stabProduitsEnfantsLength1,
	ssize_t * __stabProduitsEnfantsLength2,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationTypeTestsParProduitParPoste(
	SCProduction_GestionProductions __instance,
	char * sCodeProduit,
	char * sIndiceProduit,
	char * sNomPoste,
	char *** stabTypeTests,
	ssize_t * __stabTypeTestsLength1,
	ssize_t * __stabTypeTestsLength2,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationProprietes(
	SCProduction_GestionProductions __instance,
	char * sCodeProduit,
	char * sIndiceProduit,
	char *** stabProprietes,
	ssize_t * __stabProprietesLength1,
	ssize_t * __stabProprietesLength2,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationProprietesParPoste(
	SCProduction_GestionProductions __instance,
	char * sCodeProduit,
	char * sIndiceProduit,
	char * sNomPoste,
	char *** stabProprietes,
	ssize_t * __stabProprietesLength1,
	ssize_t * __stabProprietesLength2,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationTypePosteVariable(
	SCProduction_GestionProductions __instance,
	char * sCodeTypePoste,
	char * sNomVariable,
	char ** sValeur,
	__int64 * lId_Variable_TypePoste,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationPosteVariables(
	SCProduction_GestionProductions __instance,
	char * sNomPoste,
	char *** stabVariables,
	ssize_t * __stabVariablesLength1,
	ssize_t * __stabVariablesLength2,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationPosteVariable(
	SCProduction_GestionProductions __instance,
	char * sNomPoste,
	char * sNomVariable,
	char ** sValeur,
	__int64 * lId_Variable_Poste,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementLog(
	SCProduction_GestionProductions __instance,
	__int64 lId_NumSerie,
	char * sLibelle,
	char * sDateDebut,
	char * sDateFin,
	__int64 * lId_Log,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationDateHeure(
	SCProduction_GestionProductions __instance,
	short * shYear,
	short * shYear2Digits,
	short * shMonth,
	short * shWeek,
	short * shDayOfWeek,
	short * shDayOfMonth,
	short * shDayOfYear,
	short * shHour,
	short * shMinute,
	short * shSecond,
	short * shMillisecond,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_GenerationNumSerieClient_tcm(
	SCProduction_GestionProductions __instance,
	char * sFormatClient,
	char ** stabParametres,
	ssize_t __stabParametresLength,
	char ** sNumSerieClient,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationClesParProduit(
	SCProduction_GestionProductions __instance,
	char * sCodeProduit,
	char * sIndiceProduit,
	char *** stabCles,
	ssize_t * __stabClesLength1,
	ssize_t * __stabClesLength2,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationCle_sapme(
	SCProduction_GestionProductions __instance,
	char * sNomTableCle,
	char * sNumSerie,
	char * sCodeProduit,
	char * sIndiceProduit,
	char ** stabParametres,
	ssize_t __stabParametresLength,
	char *** stabValeursCle,
	ssize_t * __stabValeursCleLength,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationCles_sapme(
	SCProduction_GestionProductions __instance,
	char * sNomTableCle,
	char * sNumSerie,
	char * sCodeProduit,
	char * sIndiceProduit,
	char ** stabParametres,
	ssize_t __stabParametresLength,
	char *** stabValeursCles,
	ssize_t * __stabValeursClesLength1,
	ssize_t * __stabValeursClesLength2,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_LiberationCle_sapme(
	SCProduction_GestionProductions __instance,
	char * sNomTableCle,
	char * sNumSerie,
	char * sCodeProduit,
	char * sIndiceProduit,
	__int64 * lId_Cle,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_LiberationCles_sapme(
	SCProduction_GestionProductions __instance,
	char * sNomTableCle,
	char * sNumSerie,
	char * sCodeProduit,
	char * sIndiceProduit,
	__int64 ** stabId_Cle,
	ssize_t * __stabId_CleLength1,
	ssize_t * __stabId_CleLength2,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_NettoyageCle_sapme(
	SCProduction_GestionProductions __instance,
	char * sNomTableCle,
	char * sNumSerie,
	char * sCodeProduit,
	char * sIndiceProduit,
	__int64 * lId_Cle,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EcritureCle_sapme(
	SCProduction_GestionProductions __instance,
	char * sNomTableCle,
	char * sNumSerie,
	char * sCodeProduit,
	char * sIndiceProduit,
	char ** stabParametres,
	ssize_t __stabParametresLength,
	char *** stabValeursCle,
	ssize_t * __stabValeursCleLength,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_LectureCle_sapme(
	SCProduction_GestionProductions __instance,
	char * sNomTableCle,
	char * sNumSerie,
	char * sCodeProduit,
	char * sIndiceProduit,
	char ** stabParametres,
	ssize_t __stabParametresLength,
	char *** stabValeursCle,
	ssize_t * __stabValeursCleLength,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	char ** sErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_DebutOperationAvecGenerationSFC(
	SCProduction_GestionProductions __instance,
	char * strCodeProduit,
	char * operation,
	char * Ressource,
	char * indice,
	char ** strNumeroSerie,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_FinOperation(
	SCProduction_GestionProductions __instance,
	char * sNumSerie,
	char * Ressource,
	char * Operation,
	int * bResult,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_FinOperation_V2(
	SCProduction_GestionProductions __instance,
	char * sNumSerie,
	char * Ressource,
	char * Operation,
	char * Revision,
	int * bResult,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_FinOperationEnMasse(
	SCProduction_GestionProductions __instance,
	char ** sNumSerie,
	ssize_t __sNumSerieLength,
	char * Ressource,
	char * Operation,
	char * indice,
	int * bResult,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_DebutOperation(
	SCProduction_GestionProductions __instance,
	char * sNumSerie,
	char * Ressource,
	char * Operation,
	int * bResult,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_DebutOperation_V2(
	SCProduction_GestionProductions __instance,
	char * sNumSerie,
	char * Ressource,
	char * Operation,
	char * Revision,
	int * bResult,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_DebutOperationEnMasse(
	SCProduction_GestionProductions __instance,
	char ** sNumSerie,
	ssize_t __sNumSerieLength,
	char * Ressource,
	char * Operation,
	char * indice,
	int * bResult,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationInformationRessource(
	SCProduction_GestionProductions __instance,
	char * Ressource,
	char ** shopOrder,
	char ** orderType,
	char ** item,
	char ** revision,
	char ** router,
	char ** indice,
	char ** bom,
	char ** indicebom,
	char ** workCenter,
	int * Result,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationDetailsNC(
	SCProduction_GestionProductions __instance,
	char * ncGroupName,
	char *** NCCode,
	ssize_t * __NCCodeLength1,
	ssize_t * __NCCodeLength2,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationLastNC(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char ** ncCodeRef,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationStatusSfc(
	SCProduction_GestionProductions __instance,
	char ** strNumSerie,
	ssize_t __strNumSerieLength,
	char *** StatusSfc,
	ssize_t * __StatusSfcLength1,
	ssize_t * __StatusSfcLength2,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationDetailsOFV2(
	SCProduction_GestionProductions __instance,
	char * strOrdreFab,
	char ** strItemRef,
	char ** strItemRevision,
	char ** strTypeOrdreFab,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementNonConformiteSansRoutage(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char * operation,
	char * Ressource,
	char * strCodeErreur,
	char * strLibelleErreur,
	char * refdes,
	char ** IncidentDateTime1,
	double * Seque,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementTestMesure(
	SCProduction_GestionProductions __instance,
	char * sNumSerie,
	char * operation,
	char * ressource,
	char * OF,
	char * sCodeTypeTest,
	char * sCodeStatutTest,
	double dDuree,
	char * sDescription,
	char * sValeur,
	char * sToleranceMinimum,
	char * sToleranceMaximum,
	char * sUniteMesusre,
	char * sgroupe,
	char * sComment,
	int * bErreurSurvenue,
	char ** sErreurMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementTestMesureParCodeProduit(
	SCProduction_GestionProductions __instance,
	char * sNumSerie,
	char * operation,
	char * ressource,
	char * OF,
	char * sCodeTypeTest,
	char * sCodeStatutTest,
	double dDuree,
	char * sDescription,
	char * sValeur,
	char * sToleranceMinimum,
	char * sToleranceMaximum,
	char * sUniteMesusre,
	char * sgroupe,
	char * sComment,
	char * strProductCode,
	char * strRevisionProductCode,
	char * TestPlan,
	int * bErreurSurvenue,
	char ** sErreurMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_insertion_chip_id(
	SCProduction_GestionProductions __instance,
	char * SN_CIE,
	char * Chip_id,
	char * code_produit_CIE,
	char * indice_CIE,
	char ** statuts,
	char *** tabValeurschip,
	ssize_t * __tabValeurschipLength,
	int * blnErreurSurvenue,
	int * intErreurCode,
	char ** strErreurMessage,
	char ** strErreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_ReplenishComponent(
	SCProduction_GestionProductions __instance,
	char * Resource,
	char * SlotConfigId,
	char * Revision,
	char * Slot,
	char * Item,
	char ** AssyDataValues,
	ssize_t __AssyDataValuesLength1,
	ssize_t __AssyDataValuesLength2,
	char *** ReplenishComponentResponse,
	ssize_t * __ReplenishComponentResponseLength1,
	ssize_t * __ReplenishComponentResponseLength2,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationPropriete(
	SCProduction_GestionProductions __instance,
	char * codeProduit,
	char * indiceProduit,
	char * nomVariable,
	char ** valeur,
	__int64 * id_propriete,
	int * erreurSurvenue,
	int * erreurCode,
	char ** erreurMessage,
	char ** erreurRequete,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementTableauTestsMesuresDepuisValor(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char * operation,
	char * ressource,
	char * ligne,
	char * listeDeMachine,
	char * VariableDonneeCollecte,
	char * chaineDeconnexionSQL,
	char * chaineDeConnexionOracle,
	char * chaineDeConnexionPostgres,
	char * RefCodeProduit,
	char * indice,
	char * OrdreFabr,
	System_Collections_Generic_List_T1 * tabsansNum_Lot,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_INSERT_PROPERITE_IN_PACKOUT(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * variable,
	char * value,
	int * bresult,
	char ** strmessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementTableauTestsMesuresDepuisValor_1(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char * operation,
	char * ressource,
	char * ligne,
	char * listeDeMachine,
	char * VariableDonneeCollecte,
	char * chaineDeconnexionSQL,
	char * chaineDeConnexionOracle,
	System_Collections_Generic_List_T1 * tabsansNum_Lot,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationDonneesCollecteesSFC(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char *** TabValeur,
	ssize_t * __TabValeurLength1,
	ssize_t * __TabValeurLength2,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_Recuperation_Historique_Mouvement_SFC(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char *** tabValue,
	ssize_t * __tabValueLength1,
	ssize_t * __tabValueLength2,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationCodeCloture(
	SCProduction_GestionProductions __instance,
	char * CodeNC,
	char *** secondaryNcCodes,
	ssize_t * __secondaryNcCodesLength1,
	ssize_t * __secondaryNcCodesLength2,
	int * Result,
	char ** sMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementNonConformiteCloture(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char * operation,
	char * indiceOp,
	char * Ressource,
	char * strCodeErreur,
	char * strLibelleErreur,
	char * datetime,
	double sequence,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_EnregistrementTableauTestsMesures(
	SCProduction_GestionProductions __instance,
	char * sNumSerie,
	char * operation,
	char * ressource,
	char * OF,
	char ** stabMesures,
	ssize_t __stabMesuresLength1,
	ssize_t __stabMesuresLength2,
	int * bErreurSurvenue,
	char ** sErreurMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_RecuperationDetailleBom(
	SCProduction_GestionProductions __instance,
	char * Bom,
	char * indice,
	char *** TabbomComponentList,
	ssize_t * __TabbomComponentListLength,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_findInventory(
	SCProduction_GestionProductions __instance,
	char * inventoryId,
	char ** itemRef,
	char ** originalQty,
	char ** qtyOnHand,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_AjoutStockComposant(
	SCProduction_GestionProductions __instance,
	char * strCodeComposant,
	char * strValeur,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_PASSE_WITH_NEXT_OPERATION(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char * Ressource,
	char * Operation,
	char * indiceOp,
	char * next_step,
	char ** TapProperty,
	ssize_t __TapPropertyLength,
	int * bResult,
	char ** next_operation,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_AjoutStockComposant_Tableau(
	SCProduction_GestionProductions __instance,
	char ** tabAddInventory,
	ssize_t __tabAddInventoryLength1,
	ssize_t __tabAddInventoryLength2,
	int * blnResultat,
	char ** strMessageRetour,
	char ** codeDeRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_GenerationSFC(
	SCProduction_GestionProductions __instance,
	char * strCodeComposant,
	char * indice,
	char ** SFC,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception);
int CVIFUNC SCProduction_GestionProductions_GenerationSFCdepuisOF(
	SCProduction_GestionProductions __instance,
	char * strOrdreFab,
	char ** strsfcRef,
	char ** sMessageRetour,
	int * blnResultat,
	CDotNetHandle * __exception);


#ifdef __cplusplus
}
#endif
