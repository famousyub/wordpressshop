// CVI wrapper source file for .NET assembly: SCProduction, Version=2.0.0.7, Culture=neutral, PublicKeyToken=null

#include "SCProduction.h"
#include <stdarg.h>

// Macros
#ifndef __errChk
#define __errChk(f) if (__error = (f), __error < 0) goto __Error; else
#endif
#ifndef __nullChk
#define __nullChk(p) if (!(p)) { __error = CDotNetOutOfMemoryError; goto __Error; } else
#endif

// Constants
static const char * __assemblyName = "SCProduction, Version=2.0.0.7, Culture=neutral, PublicKeyToken=null";

// Static Variables
static CDotNetAssemblyHandle __assemblyHandle = 0;

// Forward declarations
static void _CDotNetGenDisposeScalar(void * scalar, unsigned int typeId);
static void CVIFUNC_C _CDotNetGenDisposeArray(void * array, unsigned int typeId, size_t nDims, ...);

// Global Functions
int CVIFUNC Initialize_SCProduction(void)
{
	int __error = 0;


	if (__assemblyHandle == 0)
		__errChk(CDotNetLoadAssembly(
			__assemblyName, 
			&__assemblyHandle));



__Error:
	return __error;
}

int CVIFUNC Close_SCProduction(void)
{
	int __error = 0;


	if (__assemblyHandle) {
		__errChk(CDotNetDiscardAssemblyHandle(__assemblyHandle));
		__assemblyHandle = 0;
	}



__Error:
	return __error;
}


// Type: SCProduction.GestionProductions
int CVIFUNC SCProduction_GestionProductions__Create(
	SCProduction_GestionProductions * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_UpdateOrInsertPropertyPKT(
	SCProduction_GestionProductions __instance,
	char * SerialNumber,
	char * PropertyName,
	char * PropertyValue,
	int * STATUS,
	char ** Response,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*Response = 0;


	// Pre-process parameter: SerialNumber
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SerialNumber;

	// Pre-process parameter: PropertyName
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &PropertyName;

	// Pre-process parameter: PropertyValue
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &PropertyValue;

	// Pre-process parameter: STATUS
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = STATUS;

	// Pre-process parameter: Response
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = Response;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"UpdateOrInsertPropertyPKT", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			Response, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_GenerationSFCdepuisOFV2(
	SCProduction_GestionProductions __instance,
	char * strOrdreFab,
	char ** strsfcRef,
	char ** sMessageRetour,
	int * blnResultat,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;
	*strsfcRef = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: strOrdreFab
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strOrdreFab;

	// Pre-process parameter: strsfcRef
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = strsfcRef;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = sMessageRetour;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = blnResultat;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GenerationSFCdepuisOFV2", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strsfcRef, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationConfigueProduit(
	SCProduction_GestionProductions __instance,
	char * Article,
	char * Version,
	char *** dcParameterList,
	ssize_t * __dcParameterListLength1,
	ssize_t * __dcParameterListLength2,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle dcParameterList__ = 0;

	if (__exception)
		*__exception = 0;
	*dcParameterList = 0;
	*__dcParameterListLength1 = 0;
	*__dcParameterListLength2 = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: Article
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &Article;

	// Pre-process parameter: Version
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &Version;

	// Pre-process parameter: dcParameterList
	__parameterTypeNames[2] = "System.String[,]&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[2] = &dcParameterList__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationConfigueProduit", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: dcParameterList
	if (dcParameterList__) {
		__errChk(CDotNetGetArrayElements(
			dcParameterList__, 
			CDOTNET_STRING, 
			0, 
			dcParameterList));
		__errChk(CDotNetGetArrayLength(
			dcParameterList__, 
			0, 
			__dcParameterListLength1));
		__errChk(CDotNetGetArrayLength(
			dcParameterList__, 
			1, 
			__dcParameterListLength2));
	}


__Error:
	if (dcParameterList__)
		CDotNetDiscardHandle(dcParameterList__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			dcParameterList, 
			CDOTNET_STRING, 
			2, 
			__dcParameterListLength1, 
			__dcParameterListLength2);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationSequenceFromBOM(
	SCProduction_GestionProductions __instance,
	char * Bom,
	char * indice,
	char * componentContext,
	double * sequence,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;
	*strMessage = 0;


	// Pre-process parameter: Bom
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &Bom;

	// Pre-process parameter: indice
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &indice;

	// Pre-process parameter: componentContext
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &componentContext;

	// Pre-process parameter: sequence
	__parameterTypeNames[3] = "System.Decimal&";
	__parameterTypes[3] = (CDOTNET_DECIMAL | CDOTNET_OUT);
	__parameters[3] = sequence;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = blnResultat;

	// Pre-process parameter: strMessage
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationSequenceFromBOM", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationComposantdepuisSFC(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * composant,
	char * indice,
	char ** ResultCode,
	char ** InventoryId,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];

	if (__exception)
		*__exception = 0;
	*ResultCode = 0;
	*InventoryId = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: composant
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &composant;

	// Pre-process parameter: indice
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &indice;

	// Pre-process parameter: ResultCode
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = ResultCode;

	// Pre-process parameter: InventoryId
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = InventoryId;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationComposantdepuisSFC", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			ResultCode, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			InventoryId, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	CDotNetHandle stabNonconformit_s__ = 0;
	ssize_t __stabNonconformit_sLengths[2];

	if (__exception)
		*__exception = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: Ressource
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Ressource;

	// Pre-process parameter: stabNonconformit_s
	__stabNonconformit_sLengths[0] = __stabNonconformit_sLength1;
	__stabNonconformit_sLengths[1] = __stabNonconformit_sLength2;
	if (stabNonconformit_s)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			2, 
			0, 
			__stabNonconformit_sLengths, 
			stabNonconformit_s, 
			&stabNonconformit_s__));
	__parameterTypeNames[3] = "System.String[,]";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[3] = &stabNonconformit_s__;

	// Pre-process parameter: bResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bResultat;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementNonConformites", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (stabNonconformit_s__)
		CDotNetDiscardHandle(stabNonconformit_s__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	CDotNetHandle stabNonconformit_s__ = 0;
	ssize_t __stabNonconformit_sLengths[2];

	if (__exception)
		*__exception = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: Ressource
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Ressource;

	// Pre-process parameter: stabNonconformit_s
	__stabNonconformit_sLengths[0] = __stabNonconformit_sLength1;
	__stabNonconformit_sLengths[1] = __stabNonconformit_sLength2;
	if (stabNonconformit_s)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			2, 
			0, 
			__stabNonconformit_sLengths, 
			stabNonconformit_s, 
			&stabNonconformit_s__));
	__parameterTypeNames[3] = "System.String[,]";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[3] = &stabNonconformit_s__;

	// Pre-process parameter: bResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bResultat;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementNonConformitesSansRoutage", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (stabNonconformit_s__)
		CDotNetDiscardHandle(stabNonconformit_s__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_removeSlotGroup(
	SCProduction_GestionProductions __instance,
	char * Resource,
	char * SlotGroup,
	char * indiceSlot,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*strMessage = 0;


	// Pre-process parameter: Resource
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &Resource;

	// Pre-process parameter: SlotGroup
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &SlotGroup;

	// Pre-process parameter: indiceSlot
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &indiceSlot;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = blnResultat;

	// Pre-process parameter: strMessage
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"removeSlotGroup", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_EnregistrementProprieteNumSerie(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char * strNomPropriete,
	char * strValeurPropriete,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: strNomPropriete
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &strNomPropriete;

	// Pre-process parameter: strValeurPropriete
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &strValeurPropriete;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementProprieteNumSerie", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_EnregistrementProprietesNumSerie(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char ** TabPropriete,
	ssize_t __TabProprieteLength1,
	ssize_t __TabProprieteLength2,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle TabPropriete__ = 0;
	ssize_t __TabProprieteLengths[2];

	if (__exception)
		*__exception = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: TabPropriete
	__TabProprieteLengths[0] = __TabProprieteLength1;
	__TabProprieteLengths[1] = __TabProprieteLength2;
	if (TabPropriete)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			2, 
			0, 
			__TabProprieteLengths, 
			TabPropriete, 
			&TabPropriete__));
	__parameterTypeNames[1] = "System.String[,]";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[1] = &TabPropriete__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementProprietesNumSerie", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (TabPropriete__)
		CDotNetDiscardHandle(TabPropriete__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_EnregistrementProprietesNumSeries(
	SCProduction_GestionProductions __instance,
	char ** strNumSerie,
	ssize_t __strNumSerieLength,
	char ** TabPropriete,
	ssize_t __TabProprieteLength1,
	ssize_t __TabProprieteLength2,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle strNumSerie__ = 0;
	CDotNetHandle TabPropriete__ = 0;
	ssize_t __TabProprieteLengths[2];

	if (__exception)
		*__exception = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	if (strNumSerie)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__strNumSerieLength, 
			strNumSerie, 
			&strNumSerie__));
	__parameterTypeNames[0] = "System.String[]";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[0] = &strNumSerie__;

	// Pre-process parameter: TabPropriete
	__TabProprieteLengths[0] = __TabProprieteLength1;
	__TabProprieteLengths[1] = __TabProprieteLength2;
	if (TabPropriete)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			2, 
			0, 
			__TabProprieteLengths, 
			TabPropriete, 
			&TabPropriete__));
	__parameterTypeNames[1] = "System.String[,]";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[1] = &TabPropriete__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementProprietesNumSeries", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (strNumSerie__)
		CDotNetDiscardHandle(strNumSerie__);
	if (TabPropriete__)
		CDotNetDiscardHandle(TabPropriete__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];
	CDotNetHandle listOfProductsWithStats__ = 0;

	if (__exception)
		*__exception = 0;
	*listOfProductsWithStats = 0;
	*__listOfProductsWithStatsLength1 = 0;
	*__listOfProductsWithStatsLength2 = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: startDate
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &startDate;

	// Pre-process parameter: endDate
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &endDate;

	// Pre-process parameter: Operation
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Operation;

	// Pre-process parameter: Line
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &Line;

	// Pre-process parameter: listOfProductsWithStats
	__parameterTypeNames[4] = "System.String[,]&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[4] = &listOfProductsWithStats__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = blnResultat;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecupererStatProduitAvecFiltre", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: listOfProductsWithStats
	if (listOfProductsWithStats__) {
		__errChk(CDotNetGetArrayElements(
			listOfProductsWithStats__, 
			CDOTNET_STRING, 
			0, 
			listOfProductsWithStats));
		__errChk(CDotNetGetArrayLength(
			listOfProductsWithStats__, 
			0, 
			__listOfProductsWithStatsLength1));
		__errChk(CDotNetGetArrayLength(
			listOfProductsWithStats__, 
			1, 
			__listOfProductsWithStatsLength2));
	}


__Error:
	if (listOfProductsWithStats__)
		CDotNetDiscardHandle(listOfProductsWithStats__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			listOfProductsWithStats, 
			CDOTNET_STRING, 
			2, 
			__listOfProductsWithStatsLength1, 
			__listOfProductsWithStatsLength2);
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];
	CDotNetHandle listOfProductsWithStats__ = 0;

	if (__exception)
		*__exception = 0;
	*listOfProductsWithStats = 0;
	*__listOfProductsWithStatsLength1 = 0;
	*__listOfProductsWithStatsLength2 = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: startDate
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &startDate;

	// Pre-process parameter: endDate
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &endDate;

	// Pre-process parameter: Operation
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Operation;

	// Pre-process parameter: ressource
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &ressource;

	// Pre-process parameter: listOfProductsWithStats
	__parameterTypeNames[4] = "System.String[,]&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[4] = &listOfProductsWithStats__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = blnResultat;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecupererStatProduitAvecFiltreRessource", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: listOfProductsWithStats
	if (listOfProductsWithStats__) {
		__errChk(CDotNetGetArrayElements(
			listOfProductsWithStats__, 
			CDOTNET_STRING, 
			0, 
			listOfProductsWithStats));
		__errChk(CDotNetGetArrayLength(
			listOfProductsWithStats__, 
			0, 
			__listOfProductsWithStatsLength1));
		__errChk(CDotNetGetArrayLength(
			listOfProductsWithStats__, 
			1, 
			__listOfProductsWithStatsLength2));
	}


__Error:
	if (listOfProductsWithStats__)
		CDotNetDiscardHandle(listOfProductsWithStats__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			listOfProductsWithStats, 
			CDOTNET_STRING, 
			2, 
			__listOfProductsWithStatsLength1, 
			__listOfProductsWithStatsLength2);
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[15] = {0};
	unsigned int __parameterTypes[15];
	void * __parameters[15];

	if (__exception)
		*__exception = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strCodeComposant
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strCodeComposant;

	// Pre-process parameter: strValeur
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &strValeur;

	// Pre-process parameter: quantite
	__parameterTypeNames[2] = "System.Decimal";
	__parameterTypes[2] = (CDOTNET_DECIMAL);
	__parameters[2] = &quantite;

	// Pre-process parameter: Fournisseur
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &Fournisseur;

	// Pre-process parameter: Lot_fournisseur
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &Lot_fournisseur;

	// Pre-process parameter: Magasin_de_stockage_ERP
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &Magasin_de_stockage_ERP;

	// Pre-process parameter: Ref_fabricant
	__parameterTypeNames[6] = "System.String";
	__parameterTypes[6] = (CDOTNET_STRING);
	__parameters[6] = &Ref_fabricant;

	// Pre-process parameter: VENDOR_DATA_CODE
	__parameterTypeNames[7] = "System.String";
	__parameterTypes[7] = (CDOTNET_STRING);
	__parameters[7] = &VENDOR_DATA_CODE;

	// Pre-process parameter: Fabricant
	__parameterTypeNames[8] = "System.String";
	__parameterTypes[8] = (CDOTNET_STRING);
	__parameters[8] = &Fabricant;

	// Pre-process parameter: Materiel_Document
	__parameterTypeNames[9] = "System.String";
	__parameterTypes[9] = (CDOTNET_STRING);
	__parameters[9] = &Materiel_Document;

	// Pre-process parameter: Date_Recep_ERP
	__parameterTypeNames[10] = "System.String";
	__parameterTypes[10] = (CDOTNET_STRING);
	__parameters[10] = &Date_Recep_ERP;

	// Pre-process parameter: Code_particulier
	__parameterTypeNames[11] = "System.String";
	__parameterTypes[11] = (CDOTNET_STRING);
	__parameters[11] = &Code_particulier;

	// Pre-process parameter: Emplacement
	__parameterTypeNames[12] = "System.String";
	__parameterTypes[12] = (CDOTNET_STRING);
	__parameters[12] = &Emplacement;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[13] = "System.Boolean&";
	__parameterTypes[13] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[13] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[14] = "System.String&";
	__parameterTypes[14] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[14] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AjoutStockComposantAvecQuantite", 
		0, 
		0, 
		15, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[15] = {0};
	unsigned int __parameterTypes[15];
	void * __parameters[15];

	if (__exception)
		*__exception = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strCodeComposant
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strCodeComposant;

	// Pre-process parameter: strValeur
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &strValeur;

	// Pre-process parameter: quantite
	__parameterTypeNames[2] = "System.Decimal";
	__parameterTypes[2] = (CDOTNET_DECIMAL);
	__parameters[2] = &quantite;

	// Pre-process parameter: Fournisseur
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &Fournisseur;

	// Pre-process parameter: Lot_fournisseur
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &Lot_fournisseur;

	// Pre-process parameter: Magasin_de_stockage_ERP
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &Magasin_de_stockage_ERP;

	// Pre-process parameter: Ref_fabricant
	__parameterTypeNames[6] = "System.String";
	__parameterTypes[6] = (CDOTNET_STRING);
	__parameters[6] = &Ref_fabricant;

	// Pre-process parameter: VENDOR_DATA_CODE
	__parameterTypeNames[7] = "System.String";
	__parameterTypes[7] = (CDOTNET_STRING);
	__parameters[7] = &VENDOR_DATA_CODE;

	// Pre-process parameter: Fabricant
	__parameterTypeNames[8] = "System.String";
	__parameterTypes[8] = (CDOTNET_STRING);
	__parameters[8] = &Fabricant;

	// Pre-process parameter: Materiel_Document
	__parameterTypeNames[9] = "System.String";
	__parameterTypes[9] = (CDOTNET_STRING);
	__parameters[9] = &Materiel_Document;

	// Pre-process parameter: Date_Recep_ERP
	__parameterTypeNames[10] = "System.String";
	__parameterTypes[10] = (CDOTNET_STRING);
	__parameters[10] = &Date_Recep_ERP;

	// Pre-process parameter: Code_particulier
	__parameterTypeNames[11] = "System.String";
	__parameterTypes[11] = (CDOTNET_STRING);
	__parameters[11] = &Code_particulier;

	// Pre-process parameter: Emplacement
	__parameterTypeNames[12] = "System.String";
	__parameterTypes[12] = (CDOTNET_STRING);
	__parameters[12] = &Emplacement;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[13] = "System.Boolean&";
	__parameterTypes[13] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[13] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[14] = "System.String&";
	__parameterTypes[14] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[14] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"UpdateStockComposant", 
		0, 
		0, 
		15, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];

	if (__exception)
		*__exception = 0;
	*EtatAssemblage = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strSFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strSFC;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: Ressource
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Ressource;

	// Pre-process parameter: strComposant
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &strComposant;

	// Pre-process parameter: identifiant
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &identifiant;

	// Pre-process parameter: NomAttribute
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &NomAttribute;

	// Pre-process parameter: strLibelle
	__parameterTypeNames[6] = "System.String";
	__parameterTypes[6] = (CDOTNET_STRING);
	__parameters[6] = &strLibelle;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[7] = "System.Boolean&";
	__parameterTypes[7] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[7] = blnResultat;

	// Pre-process parameter: EtatAssemblage
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = EtatAssemblage;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AssembleComposant", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			EtatAssemblage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[12] = {0};
	unsigned int __parameterTypes[12];
	void * __parameters[12];

	if (__exception)
		*__exception = 0;
	*EtatAssemblage = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: sfc
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sfc;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: NomAttribute
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &NomAttribute;

	// Pre-process parameter: value
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &value;

	// Pre-process parameter: bom
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &bom;

	// Pre-process parameter: indicebom
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &indicebom;

	// Pre-process parameter: sequebcebom
	__parameterTypeNames[6] = "System.String";
	__parameterTypes[6] = (CDOTNET_STRING);
	__parameters[6] = &sequebcebom;

	// Pre-process parameter: codecomposant
	__parameterTypeNames[7] = "System.String";
	__parameterTypes[7] = (CDOTNET_STRING);
	__parameters[7] = &codecomposant;

	// Pre-process parameter: indicecomposant
	__parameterTypeNames[8] = "System.String";
	__parameterTypes[8] = (CDOTNET_STRING);
	__parameters[8] = &indicecomposant;

	// Pre-process parameter: EtatAssemblage
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = EtatAssemblage;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[10] = "System.Boolean&";
	__parameterTypes[10] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[10] = blnResultat;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[11] = "System.String&";
	__parameterTypes[11] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[11] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AssemblageComposant_v2", 
		0, 
		0, 
		12, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			EtatAssemblage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];

	if (__exception)
		*__exception = 0;
	*EtatAssemblage = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: sfc
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sfc;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: NomAttribute
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &NomAttribute;

	// Pre-process parameter: value
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &value;

	// Pre-process parameter: codecomposant
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &codecomposant;

	// Pre-process parameter: indicecomposant
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &indicecomposant;

	// Pre-process parameter: EtatAssemblage
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = EtatAssemblage;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[7] = "System.Boolean&";
	__parameterTypes[7] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[7] = blnResultat;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AssemblageComponetV3", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			EtatAssemblage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_recuperationdetailleBomfromOF(
	SCProduction_GestionProductions __instance,
	char * strOrdreFab,
	char ** plannedBomRef,
	char ** indiceBomRef,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*plannedBomRef = 0;
	*indiceBomRef = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strOrdreFab
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strOrdreFab;

	// Pre-process parameter: plannedBomRef
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = plannedBomRef;

	// Pre-process parameter: indiceBomRef
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = indiceBomRef;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"recuperationdetailleBomfromOF", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			plannedBomRef, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			indiceBomRef, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationDetailsBOMwithOF(
	SCProduction_GestionProductions __instance,
	char * strOrdreFab,
	char ** plannedBomRef,
	char ** indiceBomRef,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*plannedBomRef = 0;
	*indiceBomRef = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strOrdreFab
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strOrdreFab;

	// Pre-process parameter: plannedBomRef
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = plannedBomRef;

	// Pre-process parameter: indiceBomRef
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = indiceBomRef;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationDetailsBOMwithOF", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			plannedBomRef, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			indiceBomRef, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_PrintPlanCarton(
	SCProduction_GestionProductions __instance,
	char ** TabSFC,
	ssize_t __TabSFCLength,
	char * CodeArticle,
	char * disignation,
	char * indice,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	CDotNetHandle TabSFC__ = 0;

	if (__exception)
		*__exception = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: TabSFC
	if (TabSFC)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__TabSFCLength, 
			TabSFC, 
			&TabSFC__));
	__parameterTypeNames[0] = "System.String[]";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[0] = &TabSFC__;

	// Pre-process parameter: CodeArticle
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &CodeArticle;

	// Pre-process parameter: disignation
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &disignation;

	// Pre-process parameter: indice
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &indice;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PrintPlanCarton", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (TabSFC__)
		CDotNetDiscardHandle(TabSFC__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];
	CDotNetHandle tabAssemblages__ = 0;
	ssize_t __tabAssemblagesLengths[2];

	if (__exception)
		*__exception = 0;
	*EtatAssemblage = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strSFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strSFC;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: Ressource
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Ressource;

	// Pre-process parameter: tabAssemblages
	__tabAssemblagesLengths[0] = __tabAssemblagesLength1;
	__tabAssemblagesLengths[1] = __tabAssemblagesLength2;
	if (tabAssemblages)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			2, 
			0, 
			__tabAssemblagesLengths, 
			tabAssemblages, 
			&tabAssemblages__));
	__parameterTypeNames[3] = "System.String[,]";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[3] = &tabAssemblages__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = blnResultat;

	// Pre-process parameter: EtatAssemblage
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = EtatAssemblage;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AssembleTableauComposants", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (tabAssemblages__)
		CDotNetDiscardHandle(tabAssemblages__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			EtatAssemblage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationDetailsOF(
	SCProduction_GestionProductions __instance,
	char * strOrdreFab,
	char ** strItemRef,
	char ** strItemRevision,
	char ** strTypeOrdreFab,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;
	*strItemRef = 0;
	*strItemRevision = 0;
	*strTypeOrdreFab = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strOrdreFab
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strOrdreFab;

	// Pre-process parameter: strItemRef
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = strItemRef;

	// Pre-process parameter: strItemRevision
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = strItemRevision;

	// Pre-process parameter: strTypeOrdreFab
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strTypeOrdreFab;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationDetailsOF", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strItemRef, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strItemRevision, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strTypeOrdreFab, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];

	if (__exception)
		*__exception = 0;
	*strNSClient = 0;
	*EtatAssemblage = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: Ressource
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Ressource;

	// Pre-process parameter: strFormatNSClient
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &strFormatNSClient;

	// Pre-process parameter: indice
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &indice;

	// Pre-process parameter: strNSClient
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strNSClient;

	// Pre-process parameter: EtatAssemblage
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = EtatAssemblage;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[7] = "System.Boolean&";
	__parameterTypes[7] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[7] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GenerationNSClient", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strNSClient, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			EtatAssemblage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationInformationSFC(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char ** strOrdreFab,
	char ** strCodeProduit,
	char ** strIndiceProduit,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;
	*strOrdreFab = 0;
	*strCodeProduit = 0;
	*strIndiceProduit = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: strOrdreFab
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = strOrdreFab;

	// Pre-process parameter: strCodeProduit
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = strCodeProduit;

	// Pre-process parameter: strIndiceProduit
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strIndiceProduit;

	// Pre-process parameter: bResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationInformationSFC", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strOrdreFab, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strCodeProduit, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strIndiceProduit, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationInformationSFC_HDD(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char ** strCodeProduit,
	char ** strIndiceProduit,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*strCodeProduit = 0;
	*strIndiceProduit = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: strCodeProduit
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = strCodeProduit;

	// Pre-process parameter: strIndiceProduit
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = strIndiceProduit;

	// Pre-process parameter: bResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationInformationSFC_HDD", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strCodeProduit, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strIndiceProduit, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];

	if (__exception)
		*__exception = 0;
	*strOrdreFab = 0;
	*strCodeProduit = 0;
	*strIndiceProduit = 0;
	*strGamme = 0;
	*strGammeIndice = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: strOrdreFab
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = strOrdreFab;

	// Pre-process parameter: strCodeProduit
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strCodeProduit;

	// Pre-process parameter: strIndiceProduit
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strIndiceProduit;

	// Pre-process parameter: strGamme
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strGamme;

	// Pre-process parameter: strGammeIndice
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = strGammeIndice;

	// Pre-process parameter: bResultat
	__parameterTypeNames[7] = "System.Boolean&";
	__parameterTypes[7] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[7] = bResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationInformationSFC_SYNCHRO", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strOrdreFab, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strCodeProduit, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strIndiceProduit, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strGamme, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strGammeIndice, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationSFCdepuisComposantV2(
	SCProduction_GestionProductions __instance,
	char * SFC_ENF,
	char * inventoryId,
	char ** SFCParent,
	char ** strCodeRetour,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;
	*SFCParent = 0;
	*strCodeRetour = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC_ENF
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC_ENF;

	// Pre-process parameter: inventoryId
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &inventoryId;

	// Pre-process parameter: SFCParent
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = SFCParent;

	// Pre-process parameter: strCodeRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strCodeRetour;

	// Pre-process parameter: bResult
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bResult;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationSFCdepuisComposantV2", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			SFCParent, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strCodeRetour, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];
	CDotNetHandle sfcPfin__ = 0;
	CDotNetHandle infoPfin__ = 0;
	ssize_t __infoPfinLengths[2];
	CDotNetHandle infoCie__ = 0;
	ssize_t __infoCieLengths[2];

	if (__exception)
		*__exception = 0;
	*statut = 0;
	*ficherName = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: sfcPfin
	if (sfcPfin)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__sfcPfinLength, 
			sfcPfin, 
			&sfcPfin__));
	__parameterTypeNames[0] = "System.String[]";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[0] = &sfcPfin__;

	// Pre-process parameter: mode
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &mode;

	// Pre-process parameter: infoPfin
	__infoPfinLengths[0] = __infoPfinLength1;
	__infoPfinLengths[1] = __infoPfinLength2;
	if (infoPfin)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			2, 
			0, 
			__infoPfinLengths, 
			infoPfin, 
			&infoPfin__));
	__parameterTypeNames[2] = "System.String[,]";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[2] = &infoPfin__;

	// Pre-process parameter: infoCie
	__infoCieLengths[0] = __infoCieLength1;
	__infoCieLengths[1] = __infoCieLength2;
	if (infoCie)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			2, 
			0, 
			__infoCieLengths, 
			infoCie, 
			&infoCie__));
	__parameterTypeNames[3] = "System.String[,]";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[3] = &infoCie__;

	// Pre-process parameter: bresult
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bresult;

	// Pre-process parameter: statut
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = statut;

	// Pre-process parameter: ficherName
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = ficherName;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"updateProvisionningStatus", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (sfcPfin__)
		CDotNetDiscardHandle(sfcPfin__);
	if (infoPfin__)
		CDotNetDiscardHandle(infoPfin__);
	if (infoCie__)
		CDotNetDiscardHandle(infoCie__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			statut, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			ficherName, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];

	if (__exception)
		*__exception = 0;
	*sfcRef = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: resourceRef
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &resourceRef;

	// Pre-process parameter: itemRef
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &itemRef;

	// Pre-process parameter: indiceRef
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &indiceRef;

	// Pre-process parameter: operationRef
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &operationRef;

	// Pre-process parameter: indiceOperation
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &indiceOperation;

	// Pre-process parameter: sfc
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &sfc;

	// Pre-process parameter: sfcRef
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sfcRef;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[7] = "System.Boolean&";
	__parameterTypes[7] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[7] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CreationSFC_Transfertsite", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sfcRef, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationProprietesSFC(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char *** TabValeur,
	ssize_t * __TabValeurLength1,
	ssize_t * __TabValeurLength2,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle TabValeur__ = 0;

	if (__exception)
		*__exception = 0;
	*TabValeur = 0;
	*__TabValeurLength1 = 0;
	*__TabValeurLength2 = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: TabValeur
	__parameterTypeNames[1] = "System.String[,]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &TabValeur__;

	// Pre-process parameter: bResultat
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationProprietesSFC", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: TabValeur
	if (TabValeur__) {
		__errChk(CDotNetGetArrayElements(
			TabValeur__, 
			CDOTNET_STRING, 
			0, 
			TabValeur));
		__errChk(CDotNetGetArrayLength(
			TabValeur__, 
			0, 
			__TabValeurLength1));
		__errChk(CDotNetGetArrayLength(
			TabValeur__, 
			1, 
			__TabValeurLength2));
	}


__Error:
	if (TabValeur__)
		CDotNetDiscardHandle(TabValeur__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			TabValeur, 
			CDOTNET_STRING, 
			2, 
			__TabValeurLength1, 
			__TabValeurLength2);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationProprieteSFC(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * NomPropriete,
	int * bResultat,
	char ** ValeurPropriete,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*ValeurPropriete = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: NomPropriete
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &NomPropriete;

	// Pre-process parameter: bResultat
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bResultat;

	// Pre-process parameter: ValeurPropriete
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = ValeurPropriete;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationProprieteSFC", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			ValeurPropriete, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_AjoutStockOuRecuperationEtatComposant(
	SCProduction_GestionProductions __instance,
	char * inventoryId,
	char * item,
	char * revision,
	int insertion,
	char ** ResultCode,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];

	if (__exception)
		*__exception = 0;
	*ResultCode = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: inventoryId
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &inventoryId;

	// Pre-process parameter: item
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &item;

	// Pre-process parameter: revision
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &revision;

	// Pre-process parameter: insertion
	__parameterTypeNames[3] = "System.Boolean";
	__parameterTypes[3] = (CDOTNET_BOOLEAN);
	__parameters[3] = &insertion;

	// Pre-process parameter: ResultCode
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = ResultCode;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AjoutStockOuRecuperationEtatComposant", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			ResultCode, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];

	if (__exception)
		*__exception = 0;
	*strCodeProduit = 0;
	*StepId = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: Ressource
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &Ressource;

	// Pre-process parameter: Operation
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Operation;

	// Pre-process parameter: Revision
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &Revision;

	// Pre-process parameter: strCodeProduit
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strCodeProduit;

	// Pre-process parameter: StepId
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = StepId;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Signoff", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strCodeProduit, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			StepId, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_CreationShopOrder(
	SCProduction_GestionProductions __instance,
	char * strOrdreFab,
	char * strItem,
	char * indice,
	char ** ShopOrder,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;
	*ShopOrder = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strOrdreFab
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strOrdreFab;

	// Pre-process parameter: strItem
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &strItem;

	// Pre-process parameter: indice
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &indice;

	// Pre-process parameter: ShopOrder
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = ShopOrder;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CreationShopOrder", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			ShopOrder, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_changerOF(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char * OF,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: OF
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &OF;

	// Pre-process parameter: bResult
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bResult;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"changerOF", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];

	if (__exception)
		*__exception = 0;
	*STATUS = 0;
	*DATA_VALUE = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: PRODUCT_CODE
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &PRODUCT_CODE;

	// Pre-process parameter: PRODUCT_SERIAL
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &PRODUCT_SERIAL;

	// Pre-process parameter: DATA
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &DATA;

	// Pre-process parameter: DATA_FORMAT
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &DATA_FORMAT;

	// Pre-process parameter: STATUS
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = STATUS;

	// Pre-process parameter: DATA_VALUE
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = DATA_VALUE;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = strMessageRetour;

	// Pre-process parameter: bresult
	__parameterTypeNames[7] = "System.Boolean&";
	__parameterTypes[7] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[7] = bresult;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"get_printing_datas", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			STATUS, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			DATA_VALUE, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];

	if (__exception)
		*__exception = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: Ressource
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Ressource;

	// Pre-process parameter: strCodeErreur
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &strCodeErreur;

	// Pre-process parameter: strLibelleErreur
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &strLibelleErreur;

	// Pre-process parameter: REF_DES
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &REF_DES;

	// Pre-process parameter: bResultat
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = bResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementNonConformite", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationCle(
	SCProduction_GestionProductions __instance,
	char * strNomTableCle,
	char * strNumSerie,
	char * strCodeProduit,
	char *** tabValeursCle,
	ssize_t * __tabValeursCleLength,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	CDotNetHandle tabValeursCle__ = 0;

	if (__exception)
		*__exception = 0;
	*tabValeursCle = 0;
	*__tabValeursCleLength = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNomTableCle
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNomTableCle;

	// Pre-process parameter: strNumSerie
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &strNumSerie;

	// Pre-process parameter: strCodeProduit
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &strCodeProduit;

	// Pre-process parameter: tabValeursCle
	__parameterTypeNames[3] = "System.String[]&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[3] = &tabValeursCle__;

	// Pre-process parameter: bResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationCle", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: tabValeursCle
	if (tabValeursCle__) {
		__errChk(CDotNetGetArrayElements(
			tabValeursCle__, 
			CDOTNET_STRING, 
			0, 
			tabValeursCle));
		__errChk(CDotNetGetArrayLength(
			tabValeursCle__, 
			0, 
			__tabValeursCleLength));
	}


__Error:
	if (tabValeursCle__)
		CDotNetDiscardHandle(tabValeursCle__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			tabValeursCle, 
			CDOTNET_STRING, 
			1, 
			__tabValeursCleLength);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_EnregistrementTrace(
	SCProduction_GestionProductions __instance,
	char * numserie_sapme,
	char * trace,
	char * op_ration,
	int * blnErreurSurvenue,
	int * intErreurCode,
	char ** strErreurMessage,
	char ** strErreurRequete,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];

	if (__exception)
		*__exception = 0;
	*strErreurMessage = 0;
	*strErreurRequete = 0;


	// Pre-process parameter: numserie_sapme
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &numserie_sapme;

	// Pre-process parameter: trace
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &trace;

	// Pre-process parameter: op_ration
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &op_ration;

	// Pre-process parameter: blnErreurSurvenue
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = blnErreurSurvenue;

	// Pre-process parameter: intErreurCode
	__parameterTypeNames[4] = "System.Int32&";
	__parameterTypes[4] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[4] = intErreurCode;

	// Pre-process parameter: strErreurMessage
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strErreurMessage;

	// Pre-process parameter: strErreurRequete
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = strErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementTrace", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];

	if (__exception)
		*__exception = 0;
	*valeur = 0;
	*observation = 0;
	*erreurMessage = 0;
	*erreurRequete = 0;


	// Pre-process parameter: nomParametreDetail
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &nomParametreDetail;

	// Pre-process parameter: id_parametre
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &id_parametre;

	// Pre-process parameter: id_parametreDetail
	__parameterTypeNames[2] = "System.Int64&";
	__parameterTypes[2] = (CDOTNET_INT64 | CDOTNET_OUT);
	__parameters[2] = id_parametreDetail;

	// Pre-process parameter: index
	__parameterTypeNames[3] = "System.Int64&";
	__parameterTypes[3] = (CDOTNET_INT64 | CDOTNET_OUT);
	__parameters[3] = index;

	// Pre-process parameter: valeur
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = valeur;

	// Pre-process parameter: observation
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = observation;

	// Pre-process parameter: erreurSurvenue
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = erreurSurvenue;

	// Pre-process parameter: erreurCode
	__parameterTypeNames[7] = "System.Int32&";
	__parameterTypes[7] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[7] = erreurCode;

	// Pre-process parameter: erreurMessage
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = erreurMessage;

	// Pre-process parameter: erreurRequete
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = erreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationParametreDetail", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			valeur, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			observation, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];

	if (__exception)
		*__exception = 0;
	*cheminApplicationPoste = 0;
	*observation = 0;
	*erreurMessage = 0;
	*erreurRequete = 0;


	// Pre-process parameter: nomPoste
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &nomPoste;

	// Pre-process parameter: nomApplication
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &nomApplication;

	// Pre-process parameter: versionApplication
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &versionApplication;

	// Pre-process parameter: id_parametrage
	__parameterTypeNames[3] = "System.Int64&";
	__parameterTypes[3] = (CDOTNET_INT64 | CDOTNET_OUT);
	__parameters[3] = id_parametrage;

	// Pre-process parameter: cheminApplicationPoste
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = cheminApplicationPoste;

	// Pre-process parameter: observation
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = observation;

	// Pre-process parameter: erreurSurvenue
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = erreurSurvenue;

	// Pre-process parameter: erreurCode
	__parameterTypeNames[7] = "System.Int32&";
	__parameterTypes[7] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[7] = erreurCode;

	// Pre-process parameter: erreurMessage
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = erreurMessage;

	// Pre-process parameter: erreurRequete
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = erreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationParametrage", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			cheminApplicationPoste, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			observation, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];

	if (__exception)
		*__exception = 0;
	*erreurMessage = 0;
	*erreurRequete = 0;


	// Pre-process parameter: nomPoste
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &nomPoste;

	// Pre-process parameter: nomApplication
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &nomApplication;

	// Pre-process parameter: versionApplication
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &versionApplication;

	// Pre-process parameter: modeProto
	__parameterTypeNames[3] = "System.Boolean";
	__parameterTypes[3] = (CDOTNET_BOOLEAN);
	__parameters[3] = &modeProto;

	// Pre-process parameter: erreurSurvenue
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = erreurSurvenue;

	// Pre-process parameter: erreurCode
	__parameterTypeNames[5] = "System.Int32&";
	__parameterTypes[5] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[5] = erreurCode;

	// Pre-process parameter: erreurMessage
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = erreurMessage;

	// Pre-process parameter: erreurRequete
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = erreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ActivationModeProto", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			erreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];

	if (__exception)
		*__exception = 0;
	*erreurMessage = 0;
	*erreurRequete = 0;


	// Pre-process parameter: id_parametrage
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &id_parametrage;

	// Pre-process parameter: nom
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &nom;

	// Pre-process parameter: index
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &index;

	// Pre-process parameter: valeur
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &valeur;

	// Pre-process parameter: observation
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &observation;

	// Pre-process parameter: id_parametre
	__parameterTypeNames[5] = "System.Int64&";
	__parameterTypes[5] = (CDOTNET_INT64 | CDOTNET_OUT);
	__parameters[5] = id_parametre;

	// Pre-process parameter: erreurSurvenue
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = erreurSurvenue;

	// Pre-process parameter: erreurCode
	__parameterTypeNames[7] = "System.Int32&";
	__parameterTypes[7] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[7] = erreurCode;

	// Pre-process parameter: erreurMessage
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = erreurMessage;

	// Pre-process parameter: erreurRequete
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = erreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementParametre", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			erreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];

	if (__exception)
		*__exception = 0;
	*erreurMessage = 0;
	*erreurRequete = 0;


	// Pre-process parameter: id_parametre
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &id_parametre;

	// Pre-process parameter: nom
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &nom;

	// Pre-process parameter: index
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &index;

	// Pre-process parameter: valeur
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &valeur;

	// Pre-process parameter: observation
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &observation;

	// Pre-process parameter: id_parametreDetail
	__parameterTypeNames[5] = "System.Int64&";
	__parameterTypes[5] = (CDOTNET_INT64 | CDOTNET_OUT);
	__parameters[5] = id_parametreDetail;

	// Pre-process parameter: erreurSurvenue
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = erreurSurvenue;

	// Pre-process parameter: erreurCode
	__parameterTypeNames[7] = "System.Int32&";
	__parameterTypes[7] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[7] = erreurCode;

	// Pre-process parameter: erreurMessage
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = erreurMessage;

	// Pre-process parameter: erreurRequete
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = erreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementParametreDetail", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			erreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];

	if (__exception)
		*__exception = 0;
	*erreurMessage = 0;
	*erreurRequete = 0;


	// Pre-process parameter: id_parametre
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &id_parametre;

	// Pre-process parameter: nom
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &nom;

	// Pre-process parameter: index
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &index;

	// Pre-process parameter: valeur
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &valeur;

	// Pre-process parameter: observation
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &observation;

	// Pre-process parameter: erreurSurvenue
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = erreurSurvenue;

	// Pre-process parameter: erreurCode
	__parameterTypeNames[6] = "System.Int32&";
	__parameterTypes[6] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[6] = erreurCode;

	// Pre-process parameter: erreurMessage
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = erreurMessage;

	// Pre-process parameter: erreurRequete
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = erreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ModificationParametre", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			erreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];

	if (__exception)
		*__exception = 0;
	*erreurMessage = 0;
	*erreurRequete = 0;


	// Pre-process parameter: id_parametreDetail
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &id_parametreDetail;

	// Pre-process parameter: nom
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &nom;

	// Pre-process parameter: index
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &index;

	// Pre-process parameter: valeur
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &valeur;

	// Pre-process parameter: observation
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &observation;

	// Pre-process parameter: erreurSurvenue
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = erreurSurvenue;

	// Pre-process parameter: erreurCode
	__parameterTypeNames[6] = "System.Int32&";
	__parameterTypes[6] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[6] = erreurCode;

	// Pre-process parameter: erreurMessage
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = erreurMessage;

	// Pre-process parameter: erreurRequete
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = erreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ModificationParametreDetail", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			erreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[11] = {0};
	unsigned int __parameterTypes[11];
	void * __parameters[11];

	if (__exception)
		*__exception = 0;
	*cheminApplication = 0;
	*cheminSetup = 0;
	*observation = 0;
	*erreurMessage = 0;
	*erreurRequete = 0;


	// Pre-process parameter: nomApplication
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &nomApplication;

	// Pre-process parameter: versionApplication
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &versionApplication;

	// Pre-process parameter: id_application
	__parameterTypeNames[2] = "System.Int64&";
	__parameterTypes[2] = (CDOTNET_INT64 | CDOTNET_OUT);
	__parameters[2] = id_application;

	// Pre-process parameter: cheminApplication
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = cheminApplication;

	// Pre-process parameter: cheminSetup
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = cheminSetup;

	// Pre-process parameter: actif
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = actif;

	// Pre-process parameter: observation
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = observation;

	// Pre-process parameter: erreurSurvenue
	__parameterTypeNames[7] = "System.Boolean&";
	__parameterTypes[7] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[7] = erreurSurvenue;

	// Pre-process parameter: erreurCode
	__parameterTypeNames[8] = "System.Int32&";
	__parameterTypes[8] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[8] = erreurCode;

	// Pre-process parameter: erreurMessage
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = erreurMessage;

	// Pre-process parameter: erreurRequete
	__parameterTypeNames[10] = "System.String&";
	__parameterTypes[10] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[10] = erreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationApplication", 
		0, 
		0, 
		11, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			cheminApplication, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			cheminSetup, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			observation, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationLocalisations(
	SCProduction_GestionProductions __instance,
	char *** tabLocalisations,
	ssize_t * __tabLocalisationsLength1,
	ssize_t * __tabLocalisationsLength2,
	int * erreurSurvenue,
	int * erreurCode,
	char ** erreurMessage,
	char ** erreurRequete,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle tabLocalisations__ = 0;

	if (__exception)
		*__exception = 0;
	*tabLocalisations = 0;
	*__tabLocalisationsLength1 = 0;
	*__tabLocalisationsLength2 = 0;
	*erreurMessage = 0;
	*erreurRequete = 0;


	// Pre-process parameter: tabLocalisations
	__parameterTypeNames[0] = "System.String[,]&";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &tabLocalisations__;

	// Pre-process parameter: erreurSurvenue
	__parameterTypeNames[1] = "System.Boolean&";
	__parameterTypes[1] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[1] = erreurSurvenue;

	// Pre-process parameter: erreurCode
	__parameterTypeNames[2] = "System.Int32&";
	__parameterTypes[2] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[2] = erreurCode;

	// Pre-process parameter: erreurMessage
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = erreurMessage;

	// Pre-process parameter: erreurRequete
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = erreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationLocalisations", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: tabLocalisations
	if (tabLocalisations__) {
		__errChk(CDotNetGetArrayElements(
			tabLocalisations__, 
			CDOTNET_STRING, 
			0, 
			tabLocalisations));
		__errChk(CDotNetGetArrayLength(
			tabLocalisations__, 
			0, 
			__tabLocalisationsLength1));
		__errChk(CDotNetGetArrayLength(
			tabLocalisations__, 
			1, 
			__tabLocalisationsLength2));
	}


__Error:
	if (tabLocalisations__)
		CDotNetDiscardHandle(tabLocalisations__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			tabLocalisations, 
			CDOTNET_STRING, 
			2, 
			__tabLocalisationsLength1, 
			__tabLocalisationsLength2);
		_CDotNetGenDisposeScalar(
			erreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];

	if (__exception)
		*__exception = 0;
	*valeur = 0;
	*observation = 0;
	*erreurMessage = 0;
	*erreurRequete = 0;


	// Pre-process parameter: nomParametre
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &nomParametre;

	// Pre-process parameter: id_parametrage
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &id_parametrage;

	// Pre-process parameter: id_parametre
	__parameterTypeNames[2] = "System.Int64&";
	__parameterTypes[2] = (CDOTNET_INT64 | CDOTNET_OUT);
	__parameters[2] = id_parametre;

	// Pre-process parameter: index
	__parameterTypeNames[3] = "System.Int64&";
	__parameterTypes[3] = (CDOTNET_INT64 | CDOTNET_OUT);
	__parameters[3] = index;

	// Pre-process parameter: valeur
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = valeur;

	// Pre-process parameter: observation
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = observation;

	// Pre-process parameter: erreurSurvenue
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = erreurSurvenue;

	// Pre-process parameter: erreurCode
	__parameterTypeNames[7] = "System.Int32&";
	__parameterTypes[7] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[7] = erreurCode;

	// Pre-process parameter: erreurMessage
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = erreurMessage;

	// Pre-process parameter: erreurRequete
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = erreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationParametre", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			valeur, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			observation, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];

	if (__exception)
		*__exception = 0;
	*strErreurMessage = 0;
	*strErreurRequete = 0;


	// Pre-process parameter: strCodePoste
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strCodePoste;

	// Pre-process parameter: strNomVariable
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &strNomVariable;

	// Pre-process parameter: strValeur
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &strValeur;

	// Pre-process parameter: lngId_Variable_Poste
	__parameterTypeNames[3] = "System.Int64&";
	__parameterTypes[3] = (CDOTNET_INT64 | CDOTNET_OUT);
	__parameters[3] = lngId_Variable_Poste;

	// Pre-process parameter: blnErreurSurvenue
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = blnErreurSurvenue;

	// Pre-process parameter: intErreurCode
	__parameterTypeNames[5] = "System.Int32&";
	__parameterTypes[5] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[5] = intErreurCode;

	// Pre-process parameter: strErreurMessage
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = strErreurMessage;

	// Pre-process parameter: strErreurRequete
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = strErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ModificationPosteVariable", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	CDotNetHandle tabParametres__ = 0;

	if (__exception)
		*__exception = 0;
	*tabParametres = 0;
	*__tabParametresLength1 = 0;
	*__tabParametresLength2 = 0;
	*erreurMessage = 0;
	*erreurRequete = 0;


	// Pre-process parameter: id_parametrage
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &id_parametrage;

	// Pre-process parameter: tabParametres
	__parameterTypeNames[1] = "System.String[,]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &tabParametres__;

	// Pre-process parameter: erreurSurvenue
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = erreurSurvenue;

	// Pre-process parameter: erreurCode
	__parameterTypeNames[3] = "System.Int32&";
	__parameterTypes[3] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[3] = erreurCode;

	// Pre-process parameter: erreurMessage
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = erreurMessage;

	// Pre-process parameter: erreurRequete
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = erreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationParametres", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: tabParametres
	if (tabParametres__) {
		__errChk(CDotNetGetArrayElements(
			tabParametres__, 
			CDOTNET_STRING, 
			0, 
			tabParametres));
		__errChk(CDotNetGetArrayLength(
			tabParametres__, 
			0, 
			__tabParametresLength1));
		__errChk(CDotNetGetArrayLength(
			tabParametres__, 
			1, 
			__tabParametresLength2));
	}


__Error:
	if (tabParametres__)
		CDotNetDiscardHandle(tabParametres__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			tabParametres, 
			CDOTNET_STRING, 
			2, 
			__tabParametresLength1, 
			__tabParametresLength2);
		_CDotNetGenDisposeScalar(
			erreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	CDotNetHandle tabParametresDetails__ = 0;

	if (__exception)
		*__exception = 0;
	*tabParametresDetails = 0;
	*__tabParametresDetailsLength1 = 0;
	*__tabParametresDetailsLength2 = 0;
	*erreurMessage = 0;
	*erreurRequete = 0;


	// Pre-process parameter: id_parametre
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &id_parametre;

	// Pre-process parameter: tabParametresDetails
	__parameterTypeNames[1] = "System.String[,]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &tabParametresDetails__;

	// Pre-process parameter: erreurSurvenue
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = erreurSurvenue;

	// Pre-process parameter: erreurCode
	__parameterTypeNames[3] = "System.Int32&";
	__parameterTypes[3] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[3] = erreurCode;

	// Pre-process parameter: erreurMessage
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = erreurMessage;

	// Pre-process parameter: erreurRequete
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = erreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationParametresDetails", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: tabParametresDetails
	if (tabParametresDetails__) {
		__errChk(CDotNetGetArrayElements(
			tabParametresDetails__, 
			CDOTNET_STRING, 
			0, 
			tabParametresDetails));
		__errChk(CDotNetGetArrayLength(
			tabParametresDetails__, 
			0, 
			__tabParametresDetailsLength1));
		__errChk(CDotNetGetArrayLength(
			tabParametresDetails__, 
			1, 
			__tabParametresDetailsLength2));
	}


__Error:
	if (tabParametresDetails__)
		CDotNetDiscardHandle(tabParametresDetails__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			tabParametresDetails, 
			CDOTNET_STRING, 
			2, 
			__tabParametresDetailsLength1, 
			__tabParametresDetailsLength2);
		_CDotNetGenDisposeScalar(
			erreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];
	CDotNetHandle tabTraductions__ = 0;

	if (__exception)
		*__exception = 0;
	*tabTraductions = 0;
	*__tabTraductionsLength1 = 0;
	*__tabTraductionsLength2 = 0;
	*erreurMessage = 0;
	*erreurRequete = 0;


	// Pre-process parameter: nomApplication
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &nomApplication;

	// Pre-process parameter: versionApplication
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &versionApplication;

	// Pre-process parameter: id_localisation
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &id_localisation;

	// Pre-process parameter: tabTraductions
	__parameterTypeNames[3] = "System.String[,]&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[3] = &tabTraductions__;

	// Pre-process parameter: erreurSurvenue
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = erreurSurvenue;

	// Pre-process parameter: erreurCode
	__parameterTypeNames[5] = "System.Int32&";
	__parameterTypes[5] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[5] = erreurCode;

	// Pre-process parameter: erreurMessage
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = erreurMessage;

	// Pre-process parameter: erreurRequete
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = erreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationTraductions", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: tabTraductions
	if (tabTraductions__) {
		__errChk(CDotNetGetArrayElements(
			tabTraductions__, 
			CDOTNET_STRING, 
			0, 
			tabTraductions));
		__errChk(CDotNetGetArrayLength(
			tabTraductions__, 
			0, 
			__tabTraductionsLength1));
		__errChk(CDotNetGetArrayLength(
			tabTraductions__, 
			1, 
			__tabTraductionsLength2));
	}


__Error:
	if (tabTraductions__)
		CDotNetDiscardHandle(tabTraductions__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			tabTraductions, 
			CDOTNET_STRING, 
			2, 
			__tabTraductionsLength1, 
			__tabTraductionsLength2);
		_CDotNetGenDisposeScalar(
			erreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationTestPlan(
	SCProduction_GestionProductions __instance,
	char * resource,
	char * itemRef,
	char * indice,
	char *** testPlan,
	ssize_t * __testPlanLength,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	CDotNetHandle testPlan__ = 0;

	if (__exception)
		*__exception = 0;
	*testPlan = 0;
	*__testPlanLength = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: resource
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &resource;

	// Pre-process parameter: itemRef
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &itemRef;

	// Pre-process parameter: indice
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &indice;

	// Pre-process parameter: testPlan
	__parameterTypeNames[3] = "System.String[]&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[3] = &testPlan__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationTestPlan", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: testPlan
	if (testPlan__) {
		__errChk(CDotNetGetArrayElements(
			testPlan__, 
			CDOTNET_STRING, 
			0, 
			testPlan));
		__errChk(CDotNetGetArrayLength(
			testPlan__, 
			0, 
			__testPlanLength));
	}


__Error:
	if (testPlan__)
		CDotNetDiscardHandle(testPlan__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			testPlan, 
			CDOTNET_STRING, 
			1, 
			__testPlanLength);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationParametrageTestPlan(
	SCProduction_GestionProductions __instance,
	char * testPlanId,
	char * measurementDescription,
	char ** description,
	System_Collections_Generic_Dictionary_T2 * testPlanMeasurementList,
	System_Collections_Generic_Dictionary_T2 * testPlanParamList,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];

	if (__exception)
		*__exception = 0;
	*description = 0;
	*testPlanMeasurementList = 0;
	*testPlanParamList = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: testPlanId
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &testPlanId;

	// Pre-process parameter: measurementDescription
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &measurementDescription;

	// Pre-process parameter: description
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = description;

	// Pre-process parameter: testPlanMeasurementList
	__parameterTypeNames[3] = "System.Collections.Generic.Dictionary`2[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089],[System.Collections.Generic.Dictionary`2[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089],[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]&";
	__parameterTypes[3] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[3] = testPlanMeasurementList;

	// Pre-process parameter: testPlanParamList
	__parameterTypeNames[4] = "System.Collections.Generic.Dictionary`2[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089],[System.Collections.Generic.Dictionary`2[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089],[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]&";
	__parameterTypes[4] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[4] = testPlanParamList;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationParametrageTestPlan", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			description, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			testPlanMeasurementList, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			testPlanParamList, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationListeArticle(
	SCProduction_GestionProductions __instance,
	char * strGroupe,
	char ** description,
	char *** itemGroupMembers,
	ssize_t * __itemGroupMembersLength,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle itemGroupMembers__ = 0;

	if (__exception)
		*__exception = 0;
	*description = 0;
	*itemGroupMembers = 0;
	*__itemGroupMembersLength = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strGroupe
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strGroupe;

	// Pre-process parameter: description
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = description;

	// Pre-process parameter: itemGroupMembers
	__parameterTypeNames[2] = "System.String[]&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[2] = &itemGroupMembers__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationListeArticle", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: itemGroupMembers
	if (itemGroupMembers__) {
		__errChk(CDotNetGetArrayElements(
			itemGroupMembers__, 
			CDOTNET_STRING, 
			0, 
			itemGroupMembers));
		__errChk(CDotNetGetArrayLength(
			itemGroupMembers__, 
			0, 
			__itemGroupMembersLength));
	}


__Error:
	if (itemGroupMembers__)
		CDotNetDiscardHandle(itemGroupMembers__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			description, 
			CDOTNET_STRING);
		_CDotNetGenDisposeArray(
			itemGroupMembers, 
			CDOTNET_STRING, 
			1, 
			__itemGroupMembersLength);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationListeGammeReprise(
	SCProduction_GestionProductions __instance,
	System_Collections_Generic_List_T1 * router,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;
	*router = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: router
	__parameterTypeNames[0] = "System.Collections.Generic.List`1[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]&";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[0] = router;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[1] = "System.Boolean&";
	__parameterTypes[1] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[1] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationListeGammeReprise", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			router, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	CDotNetHandle CustomField__ = 0;

	if (__exception)
		*__exception = 0;
	*CustomField = 0;
	*__CustomFieldLength1 = 0;
	*__CustomFieldLength2 = 0;
	*strMessage = 0;


	// Pre-process parameter: Attribute
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &Attribute;

	// Pre-process parameter: ProductCode
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &ProductCode;

	// Pre-process parameter: Indice
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Indice;

	// Pre-process parameter: CustomField
	__parameterTypeNames[3] = "System.String[,]&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[3] = &CustomField__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = blnResultat;

	// Pre-process parameter: strMessage
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationDonneesArticle", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: CustomField
	if (CustomField__) {
		__errChk(CDotNetGetArrayElements(
			CustomField__, 
			CDOTNET_STRING, 
			0, 
			CustomField));
		__errChk(CDotNetGetArrayLength(
			CustomField__, 
			0, 
			__CustomFieldLength1));
		__errChk(CDotNetGetArrayLength(
			CustomField__, 
			1, 
			__CustomFieldLength2));
	}


__Error:
	if (CustomField__)
		CDotNetDiscardHandle(CustomField__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			CustomField, 
			CDOTNET_STRING, 
			2, 
			__CustomFieldLength1, 
			__CustomFieldLength2);
		_CDotNetGenDisposeScalar(
			strMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle custoRequestDataArray__ = 0;
	ssize_t __custoRequestDataArrayLengths[2];
	CDotNetHandle custoStatusArray__ = 0;

	if (__exception)
		*__exception = 0;
	*custoStatusArray = 0;
	*__custoStatusArrayLength1 = 0;
	*__custoStatusArrayLength2 = 0;
	*strMessage = 0;


	// Pre-process parameter: strIPAdress
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strIPAdress;

	// Pre-process parameter: custoRequestDataArray
	__custoRequestDataArrayLengths[0] = __custoRequestDataArrayLength1;
	__custoRequestDataArrayLengths[1] = __custoRequestDataArrayLength2;
	if (custoRequestDataArray)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			2, 
			0, 
			__custoRequestDataArrayLengths, 
			custoRequestDataArray, 
			&custoRequestDataArray__));
	__parameterTypeNames[1] = "System.String[,]";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[1] = &custoRequestDataArray__;

	// Pre-process parameter: custoStatusArray
	__parameterTypeNames[2] = "System.String[,]&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[2] = &custoStatusArray__;

	// Pre-process parameter: bResult
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bResult;

	// Pre-process parameter: strMessage
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetCustoStatus", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: custoStatusArray
	if (custoStatusArray__) {
		__errChk(CDotNetGetArrayElements(
			custoStatusArray__, 
			CDOTNET_STRING, 
			0, 
			custoStatusArray));
		__errChk(CDotNetGetArrayLength(
			custoStatusArray__, 
			0, 
			__custoStatusArrayLength1));
		__errChk(CDotNetGetArrayLength(
			custoStatusArray__, 
			1, 
			__custoStatusArrayLength2));
	}


__Error:
	if (custoRequestDataArray__)
		CDotNetDiscardHandle(custoRequestDataArray__);
	if (custoStatusArray__)
		CDotNetDiscardHandle(custoStatusArray__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			custoStatusArray, 
			CDOTNET_STRING, 
			2, 
			__custoStatusArrayLength1, 
			__custoStatusArrayLength2);
		_CDotNetGenDisposeScalar(
			strMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];

	if (__exception)
		*__exception = 0;
	*SNcarton = 0;
	*strmassage = 0;


	// Pre-process parameter: codeproduit
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &codeproduit;

	// Pre-process parameter: indice
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &indice;

	// Pre-process parameter: UF
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &UF;

	// Pre-process parameter: ligne
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &ligne;

	// Pre-process parameter: usine
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &usine;

	// Pre-process parameter: Format
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &Format;

	// Pre-process parameter: bresult
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = bresult;

	// Pre-process parameter: SNcarton
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = SNcarton;

	// Pre-process parameter: strmassage
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = strmassage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GenerationSNcarton", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			SNcarton, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strmassage, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_unloadSlotGroup(
	SCProduction_GestionProductions __instance,
	char * Resource,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;
	*strMessage = 0;


	// Pre-process parameter: Resource
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &Resource;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[1] = "System.Boolean&";
	__parameterTypes[1] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[1] = blnResultat;

	// Pre-process parameter: strMessage
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = strMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"unloadSlotGroup", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];
	CDotNetHandle SetupSlotConfiguration__ = 0;

	if (__exception)
		*__exception = 0;
	*SetupSlotConfiguration = 0;
	*__SetupSlotConfigurationLength1 = 0;
	*__SetupSlotConfigurationLength2 = 0;
	*strMessage = 0;


	// Pre-process parameter: Resource
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &Resource;

	// Pre-process parameter: State
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &State;

	// Pre-process parameter: SlotConfigId
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &SlotConfigId;

	// Pre-process parameter: Revision
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &Revision;

	// Pre-process parameter: SetupSlotConfiguration
	__parameterTypeNames[4] = "System.String[,]&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[4] = &SetupSlotConfiguration__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = blnResultat;

	// Pre-process parameter: strMessage
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = strMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetupSlotConfiguration", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: SetupSlotConfiguration
	if (SetupSlotConfiguration__) {
		__errChk(CDotNetGetArrayElements(
			SetupSlotConfiguration__, 
			CDOTNET_STRING, 
			0, 
			SetupSlotConfiguration));
		__errChk(CDotNetGetArrayLength(
			SetupSlotConfiguration__, 
			0, 
			__SetupSlotConfigurationLength1));
		__errChk(CDotNetGetArrayLength(
			SetupSlotConfiguration__, 
			1, 
			__SetupSlotConfigurationLength2));
	}


__Error:
	if (SetupSlotConfiguration__)
		CDotNetDiscardHandle(SetupSlotConfiguration__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			SetupSlotConfiguration, 
			CDOTNET_STRING, 
			2, 
			__SetupSlotConfigurationLength1, 
			__SetupSlotConfigurationLength2);
		_CDotNetGenDisposeScalar(
			strMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_Recuperation_Historique_NC(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char *** ncCodeRef,
	ssize_t * __ncCodeRefLength1,
	ssize_t * __ncCodeRefLength2,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle ncCodeRef__ = 0;

	if (__exception)
		*__exception = 0;
	*ncCodeRef = 0;
	*__ncCodeRefLength1 = 0;
	*__ncCodeRefLength2 = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: ncCodeRef
	__parameterTypeNames[1] = "System.String[,]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &ncCodeRef__;

	// Pre-process parameter: bResult
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bResult;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Recuperation_Historique_NC", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: ncCodeRef
	if (ncCodeRef__) {
		__errChk(CDotNetGetArrayElements(
			ncCodeRef__, 
			CDOTNET_STRING, 
			0, 
			ncCodeRef));
		__errChk(CDotNetGetArrayLength(
			ncCodeRef__, 
			0, 
			__ncCodeRefLength1));
		__errChk(CDotNetGetArrayLength(
			ncCodeRef__, 
			1, 
			__ncCodeRefLength2));
	}


__Error:
	if (ncCodeRef__)
		CDotNetDiscardHandle(ncCodeRef__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			ncCodeRef, 
			CDOTNET_STRING, 
			2, 
			__ncCodeRefLength1, 
			__ncCodeRefLength2);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_CHECK_OR_INSERT_SN_IN_PACKOUT_v2(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * ITEM,
	char * indice,
	char * Code_SSCC,
	char * ressorce,
	int * bresult,
	char ** strmessage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];

	if (__exception)
		*__exception = 0;
	*strmessage = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: ITEM
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &ITEM;

	// Pre-process parameter: indice
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &indice;

	// Pre-process parameter: Code_SSCC
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &Code_SSCC;

	// Pre-process parameter: ressorce
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &ressorce;

	// Pre-process parameter: bresult
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = bresult;

	// Pre-process parameter: strmessage
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = strmessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CHECK_OR_INSERT_SN_IN_PACKOUT_v2", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strmessage, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_CHECK_OR_INSERT_SN_IN_PACKOUT(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * ITEM,
	char * indice,
	int * bresult,
	char ** strmessage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*strmessage = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: ITEM
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &ITEM;

	// Pre-process parameter: indice
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &indice;

	// Pre-process parameter: bresult
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bresult;

	// Pre-process parameter: strmessage
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strmessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CHECK_OR_INSERT_SN_IN_PACKOUT", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strmessage, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];
	CDotNetHandle slotGroupConfiguration__ = 0;

	if (__exception)
		*__exception = 0;
	*slotGroupConfiguration = 0;
	*__slotGroupConfigurationLength1 = 0;
	*__slotGroupConfigurationLength2 = 0;
	*slotGroupRef = 0;
	*resourceSetupState = 0;
	*strMessage = 0;


	// Pre-process parameter: Resource
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &Resource;

	// Pre-process parameter: slotGroupState
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &slotGroupState;

	// Pre-process parameter: slotGroupConfiguration
	__parameterTypeNames[2] = "System.String[,]&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[2] = &slotGroupConfiguration__;

	// Pre-process parameter: slotGroupRef
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = slotGroupRef;

	// Pre-process parameter: resourceSetupState
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = resourceSetupState;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = blnResultat;

	// Pre-process parameter: strMessage
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = strMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"findSlotGroupByResourceAndState", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: slotGroupConfiguration
	if (slotGroupConfiguration__) {
		__errChk(CDotNetGetArrayElements(
			slotGroupConfiguration__, 
			CDOTNET_STRING, 
			0, 
			slotGroupConfiguration));
		__errChk(CDotNetGetArrayLength(
			slotGroupConfiguration__, 
			0, 
			__slotGroupConfigurationLength1));
		__errChk(CDotNetGetArrayLength(
			slotGroupConfiguration__, 
			1, 
			__slotGroupConfigurationLength2));
	}


__Error:
	if (slotGroupConfiguration__)
		CDotNetDiscardHandle(slotGroupConfiguration__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			slotGroupConfiguration, 
			CDOTNET_STRING, 
			2, 
			__slotGroupConfigurationLength1, 
			__slotGroupConfigurationLength2);
		_CDotNetGenDisposeScalar(
			slotGroupRef, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			resourceSetupState, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_getCurrentAndPendingComponentTimeLogRecords(
	SCProduction_GestionProductions __instance,
	char * Resource,
	char *** CurrentAndPendingComponent,
	ssize_t * __CurrentAndPendingComponentLength1,
	ssize_t * __CurrentAndPendingComponentLength2,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle CurrentAndPendingComponent__ = 0;

	if (__exception)
		*__exception = 0;
	*CurrentAndPendingComponent = 0;
	*__CurrentAndPendingComponentLength1 = 0;
	*__CurrentAndPendingComponentLength2 = 0;
	*strMessage = 0;


	// Pre-process parameter: Resource
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &Resource;

	// Pre-process parameter: CurrentAndPendingComponent
	__parameterTypeNames[1] = "System.String[,]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &CurrentAndPendingComponent__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = blnResultat;

	// Pre-process parameter: strMessage
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCurrentAndPendingComponentTimeLogRecords", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: CurrentAndPendingComponent
	if (CurrentAndPendingComponent__) {
		__errChk(CDotNetGetArrayElements(
			CurrentAndPendingComponent__, 
			CDOTNET_STRING, 
			0, 
			CurrentAndPendingComponent));
		__errChk(CDotNetGetArrayLength(
			CurrentAndPendingComponent__, 
			0, 
			__CurrentAndPendingComponentLength1));
		__errChk(CDotNetGetArrayLength(
			CurrentAndPendingComponent__, 
			1, 
			__CurrentAndPendingComponentLength2));
	}


__Error:
	if (CurrentAndPendingComponent__)
		CDotNetDiscardHandle(CurrentAndPendingComponent__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			CurrentAndPendingComponent, 
			CDOTNET_STRING, 
			2, 
			__CurrentAndPendingComponentLength1, 
			__CurrentAndPendingComponentLength2);
		_CDotNetGenDisposeScalar(
			strMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_GET_COMP_TIME_LOG_STAGING(
	SCProduction_GestionProductions __instance,
	char * Resource,
	System_Collections_Generic_List_T1 * tabinfo,
	int * bresult,
	char ** strmassage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;
	*tabinfo = 0;
	*strmassage = 0;


	// Pre-process parameter: Resource
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &Resource;

	// Pre-process parameter: tabinfo
	__parameterTypeNames[1] = "System.Collections.Generic.List`1[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]&";
	__parameterTypes[1] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[1] = tabinfo;

	// Pre-process parameter: bresult
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bresult;

	// Pre-process parameter: strmassage
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strmassage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GET_COMP_TIME_LOG_STAGING", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			tabinfo, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			strmassage, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];

	if (__exception)
		*__exception = 0;
	*strErreurMessage = 0;
	*strErreurRequete = 0;


	// Pre-process parameter: strServeur
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strServeur;

	// Pre-process parameter: intPort
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &intPort;

	// Pre-process parameter: strBaseDeDonnees
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &strBaseDeDonnees;

	// Pre-process parameter: strUtilisateur
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &strUtilisateur;

	// Pre-process parameter: strPoste
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &strPoste;

	// Pre-process parameter: blnDebug
	__parameterTypeNames[5] = "System.Boolean";
	__parameterTypes[5] = (CDOTNET_BOOLEAN);
	__parameters[5] = &blnDebug;

	// Pre-process parameter: blnErreurSurvenue
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = blnErreurSurvenue;

	// Pre-process parameter: intErreurCode
	__parameterTypeNames[7] = "System.Int32&";
	__parameterTypes[7] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[7] = intErreurCode;

	// Pre-process parameter: strErreurMessage
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = strErreurMessage;

	// Pre-process parameter: strErreurRequete
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = strErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ConfigurationBase", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_markSfcAsDone(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char * codeproduit,
	char * indice,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: codeproduit
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &codeproduit;

	// Pre-process parameter: indice
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &indice;

	// Pre-process parameter: bResult
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bResult;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"markSfcAsDone", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_FindSFCByCollectData(
	SCProduction_GestionProductions __instance,
	char * value,
	char * dataField,
	char *** listSFCWithParam,
	ssize_t * __listSFCWithParamLength,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle listSFCWithParam__ = 0;

	if (__exception)
		*__exception = 0;
	*listSFCWithParam = 0;
	*__listSFCWithParamLength = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &value;

	// Pre-process parameter: dataField
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &dataField;

	// Pre-process parameter: listSFCWithParam
	__parameterTypeNames[2] = "System.String[]&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[2] = &listSFCWithParam__;

	// Pre-process parameter: bResult
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bResult;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"FindSFCByCollectData", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: listSFCWithParam
	if (listSFCWithParam__) {
		__errChk(CDotNetGetArrayElements(
			listSFCWithParam__, 
			CDOTNET_STRING, 
			0, 
			listSFCWithParam));
		__errChk(CDotNetGetArrayLength(
			listSFCWithParam__, 
			0, 
			__listSFCWithParamLength));
	}


__Error:
	if (listSFCWithParam__)
		CDotNetDiscardHandle(listSFCWithParam__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			listSFCWithParam, 
			CDOTNET_STRING, 
			1, 
			__listSFCWithParamLength);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationListeCodeProduit(
	SCProduction_GestionProductions __instance,
	char * ligne,
	char *** listCodeProduits,
	ssize_t * __listCodeProduitsLength,
	int * bresult,
	char ** strMessage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle listCodeProduits__ = 0;

	if (__exception)
		*__exception = 0;
	*listCodeProduits = 0;
	*__listCodeProduitsLength = 0;
	*strMessage = 0;


	// Pre-process parameter: ligne
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &ligne;

	// Pre-process parameter: listCodeProduits
	__parameterTypeNames[1] = "System.String[]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &listCodeProduits__;

	// Pre-process parameter: bresult
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bresult;

	// Pre-process parameter: strMessage
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationListeCodeProduit", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: listCodeProduits
	if (listCodeProduits__) {
		__errChk(CDotNetGetArrayElements(
			listCodeProduits__, 
			CDOTNET_STRING, 
			0, 
			listCodeProduits));
		__errChk(CDotNetGetArrayLength(
			listCodeProduits__, 
			0, 
			__listCodeProduitsLength));
	}


__Error:
	if (listCodeProduits__)
		CDotNetDiscardHandle(listCodeProduits__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			listCodeProduits, 
			CDOTNET_STRING, 
			1, 
			__listCodeProduitsLength);
		_CDotNetGenDisposeScalar(
			strMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationInfoLotMetrologie(
	SCProduction_GestionProductions __instance,
	char * ligne,
	char * CodeProduits,
	char * indice,
	char ** information,
	int * bresult,
	char ** strMessage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;
	*information = 0;
	*strMessage = 0;


	// Pre-process parameter: ligne
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &ligne;

	// Pre-process parameter: CodeProduits
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &CodeProduits;

	// Pre-process parameter: indice
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &indice;

	// Pre-process parameter: information
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = information;

	// Pre-process parameter: bresult
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bresult;

	// Pre-process parameter: strMessage
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationInfoLotMetrologie", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			information, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationlisteNSlots(
	SCProduction_GestionProductions __instance,
	char * lots,
	char * variable,
	System_Collections_Generic_Dictionary_T2 * information,
	int * bresult,
	char ** strMessage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*information = 0;
	*strMessage = 0;


	// Pre-process parameter: lots
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &lots;

	// Pre-process parameter: variable
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &variable;

	// Pre-process parameter: information
	__parameterTypeNames[2] = "System.Collections.Generic.Dictionary`2[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089],[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]&";
	__parameterTypes[2] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[2] = information;

	// Pre-process parameter: bresult
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bresult;

	// Pre-process parameter: strMessage
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationlisteNSlots", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			information, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			strMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationCodeSNclientLinky(
	SCProduction_GestionProductions __instance,
	char * CODE_PRODUIT_METRO,
	char * INDICE_PRODUIT_METRO,
	int * bresult,
	char ** VariableLot,
	char ** strmassage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*VariableLot = 0;
	*strmassage = 0;


	// Pre-process parameter: CODE_PRODUIT_METRO
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &CODE_PRODUIT_METRO;

	// Pre-process parameter: INDICE_PRODUIT_METRO
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &INDICE_PRODUIT_METRO;

	// Pre-process parameter: bresult
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bresult;

	// Pre-process parameter: VariableLot
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = VariableLot;

	// Pre-process parameter: strmassage
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strmassage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationCodeSNclientLinky", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			VariableLot, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strmassage, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationCodeSNclientLinky_V2(
	SCProduction_GestionProductions __instance,
	char * CODE_PRODUIT_METRO,
	char * INDICE_PRODUIT_METRO,
	char * var,
	int * bresult,
	char ** VariableLot,
	char ** strmassage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;
	*VariableLot = 0;
	*strmassage = 0;


	// Pre-process parameter: CODE_PRODUIT_METRO
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &CODE_PRODUIT_METRO;

	// Pre-process parameter: INDICE_PRODUIT_METRO
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &INDICE_PRODUIT_METRO;

	// Pre-process parameter: var
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &var;

	// Pre-process parameter: bresult
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bresult;

	// Pre-process parameter: VariableLot
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = VariableLot;

	// Pre-process parameter: strmassage
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strmassage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationCodeSNclientLinky_V2", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			VariableLot, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strmassage, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];

	if (__exception)
		*__exception = 0;
	*strErreurMessage = 0;
	*strErreurRequete = 0;


	// Pre-process parameter: strServeur
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strServeur;

	// Pre-process parameter: intPort
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &intPort;

	// Pre-process parameter: strBaseDeDonnees
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &strBaseDeDonnees;

	// Pre-process parameter: strUtilisateur
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &strUtilisateur;

	// Pre-process parameter: strPoste
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &strPoste;

	// Pre-process parameter: blnDebug
	__parameterTypeNames[5] = "System.Boolean";
	__parameterTypes[5] = (CDOTNET_BOOLEAN);
	__parameters[5] = &blnDebug;

	// Pre-process parameter: blnErreurSurvenue
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = blnErreurSurvenue;

	// Pre-process parameter: intErreurCode
	__parameterTypeNames[7] = "System.Int32&";
	__parameterTypes[7] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[7] = intErreurCode;

	// Pre-process parameter: strErreurMessage
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = strErreurMessage;

	// Pre-process parameter: strErreurRequete
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = strErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ConfigurationBase_nrj", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_findResourcesByWorkCenter(
	SCProduction_GestionProductions __instance,
	char * WorkCenter,
	int * blnResultat,
	System_Collections_Generic_List_T1 * ressources,
	char ** sMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;
	*ressources = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: WorkCenter
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &WorkCenter;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[1] = "System.Boolean&";
	__parameterTypes[1] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[1] = blnResultat;

	// Pre-process parameter: ressources
	__parameterTypeNames[2] = "System.Collections.Generic.List`1[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]&";
	__parameterTypes[2] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[2] = ressources;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"findResourcesByWorkCenter", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			ressources, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_TchekOperation(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * operation,
	char * indiceOp,
	int * state,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: indiceOp
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &indiceOp;

	// Pre-process parameter: state
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = state;

	// Pre-process parameter: bResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TchekOperation", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_ArchiveEnMasse(
	SCProduction_GestionProductions __instance,
	char ** strNumSerie,
	ssize_t __strNumSerieLength,
	int bArchiving,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle strNumSerie__ = 0;

	if (__exception)
		*__exception = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	if (strNumSerie)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__strNumSerieLength, 
			strNumSerie, 
			&strNumSerie__));
	__parameterTypeNames[0] = "System.String[]";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[0] = &strNumSerie__;

	// Pre-process parameter: bArchiving
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &bArchiving;

	// Pre-process parameter: bResult
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bResult;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ArchiveEnMasse", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (strNumSerie__)
		CDotNetDiscardHandle(strNumSerie__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_ChangeProduction(
	SCProduction_GestionProductions __instance,
	char ** sfcList,
	ssize_t __sfcListLength,
	char * newItem,
	char * newItemRevision,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle sfcList__ = 0;

	if (__exception)
		*__exception = 0;
	*strMessage = 0;


	// Pre-process parameter: sfcList
	if (sfcList)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__sfcListLength, 
			sfcList, 
			&sfcList__));
	__parameterTypeNames[0] = "System.String[]";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[0] = &sfcList__;

	// Pre-process parameter: newItem
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &newItem;

	// Pre-process parameter: newItemRevision
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &newItemRevision;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = blnResultat;

	// Pre-process parameter: strMessage
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ChangeProduction", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (sfcList__)
		CDotNetDiscardHandle(sfcList__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];
	CDotNetHandle Sfc__ = 0;

	if (__exception)
		*__exception = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: Sfc
	if (Sfc)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__SfcLength, 
			Sfc, 
			&Sfc__));
	__parameterTypeNames[0] = "System.String[]";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[0] = &Sfc__;

	// Pre-process parameter: Ressource
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &Ressource;

	// Pre-process parameter: Operation
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Operation;

	// Pre-process parameter: indice
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &indice;

	// Pre-process parameter: next_step
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &next_step;

	// Pre-process parameter: Statut
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = Statut;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PASS_EN_MASSE", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (Sfc__)
		CDotNetDiscardHandle(Sfc__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationNCattachee(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char *** ncCodeRef,
	ssize_t * __ncCodeRefLength1,
	ssize_t * __ncCodeRefLength2,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle ncCodeRef__ = 0;

	if (__exception)
		*__exception = 0;
	*ncCodeRef = 0;
	*__ncCodeRefLength1 = 0;
	*__ncCodeRefLength2 = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: ncCodeRef
	__parameterTypeNames[1] = "System.String[,]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &ncCodeRef__;

	// Pre-process parameter: bResult
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bResult;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationNCattachee", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: ncCodeRef
	if (ncCodeRef__) {
		__errChk(CDotNetGetArrayElements(
			ncCodeRef__, 
			CDOTNET_STRING, 
			0, 
			ncCodeRef));
		__errChk(CDotNetGetArrayLength(
			ncCodeRef__, 
			0, 
			__ncCodeRefLength1));
		__errChk(CDotNetGetArrayLength(
			ncCodeRef__, 
			1, 
			__ncCodeRefLength2));
	}


__Error:
	if (ncCodeRef__)
		CDotNetDiscardHandle(ncCodeRef__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			ncCodeRef, 
			CDOTNET_STRING, 
			2, 
			__ncCodeRefLength1, 
			__ncCodeRefLength2);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationInformationSFC_Specifique(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char ** strCodeProduit,
	char ** strIndiceProduit,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*strCodeProduit = 0;
	*strIndiceProduit = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: strCodeProduit
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = strCodeProduit;

	// Pre-process parameter: strIndiceProduit
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = strIndiceProduit;

	// Pre-process parameter: bResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationInformationSFC_Specifique", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strCodeProduit, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strIndiceProduit, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_Recuperation_DetailsSFC(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char ** strOrdreFab,
	char ** strCodeProduit,
	char ** strIndiceProduit,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;
	*strOrdreFab = 0;
	*strCodeProduit = 0;
	*strIndiceProduit = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: strOrdreFab
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = strOrdreFab;

	// Pre-process parameter: strCodeProduit
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = strCodeProduit;

	// Pre-process parameter: strIndiceProduit
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strIndiceProduit;

	// Pre-process parameter: bResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Recuperation_DetailsSFC", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strOrdreFab, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strCodeProduit, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strIndiceProduit, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationOFdepuisArticle(
	SCProduction_GestionProductions __instance,
	char * itemMask,
	char * itemRevisionMask,
	System_Collections_Hashtable * shopOrder_status,
	int * blnResultat,
	char ** sMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*shopOrder_status = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: itemMask
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &itemMask;

	// Pre-process parameter: itemRevisionMask
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &itemRevisionMask;

	// Pre-process parameter: shopOrder_status
	__parameterTypeNames[2] = "System.Collections.Hashtable&";
	__parameterTypes[2] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[2] = shopOrder_status;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = blnResultat;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationOFdepuisArticle", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			shopOrder_status, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_PrintDocument(
	SCProduction_GestionProductions __instance,
	char * sfcRef,
	char * documentName,
	int printQty,
	char * printer,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: sfcRef
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sfcRef;

	// Pre-process parameter: documentName
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &documentName;

	// Pre-process parameter: printQty
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &printQty;

	// Pre-process parameter: printer
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &printer;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PrintDocument", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_PreparationEtatConfigRessource(
	SCProduction_GestionProductions __instance,
	char * ShopOrderBO,
	char * description,
	char * resourceRef,
	int * blnResultat,
	char ** sMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: ShopOrderBO
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &ShopOrderBO;

	// Pre-process parameter: description
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &description;

	// Pre-process parameter: resourceRef
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &resourceRef;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = blnResultat;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PreparationEtatConfigRessource", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];

	if (__exception)
		*__exception = 0;
	*CUSTO_PAYLOAD = 0;
	*STATUS = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: CIPHERING_KEY_NAME
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &CIPHERING_KEY_NAME;

	// Pre-process parameter: PRODUCT_CODE
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &PRODUCT_CODE;

	// Pre-process parameter: PRODUCT_SERIAL
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &PRODUCT_SERIAL;

	// Pre-process parameter: SESSION_ID
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &SESSION_ID;

	// Pre-process parameter: CUSTO_PAYLOAD
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = CUSTO_PAYLOAD;

	// Pre-process parameter: STATUS
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = STATUS;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = strMessageRetour;

	// Pre-process parameter: bresult
	__parameterTypeNames[7] = "System.Boolean&";
	__parameterTypes[7] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[7] = bresult;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GET_CUSTO", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			CUSTO_PAYLOAD, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			STATUS, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_Pass_assemblage(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * operation,
	char * ressource,
	char * OF,
	int * bresult,
	char ** SFCPARENT,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];

	if (__exception)
		*__exception = 0;
	*SFCPARENT = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: ressource
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &ressource;

	// Pre-process parameter: OF
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &OF;

	// Pre-process parameter: bresult
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bresult;

	// Pre-process parameter: SFCPARENT
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = SFCPARENT;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Pass_assemblage", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			SFCPARENT, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_INSERT_NS_Lot_Metro_v2(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * ressource,
	int * bresult,
	char ** snlot,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*snlot = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: ressource
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &ressource;

	// Pre-process parameter: bresult
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bresult;

	// Pre-process parameter: snlot
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = snlot;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"INSERT_NS_Lot_Metro_v2", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			snlot, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_ControleLotMetrologieDisponible(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * ressource,
	int * bresult,
	char ** snlot,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*snlot = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: ressource
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &ressource;

	// Pre-process parameter: bresult
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bresult;

	// Pre-process parameter: snlot
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = snlot;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControleLotMetrologieDisponible", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			snlot, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];

	if (__exception)
		*__exception = 0;
	*STATUS = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: PRODUCT_CODE
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &PRODUCT_CODE;

	// Pre-process parameter: PRODUCT_SERIAL
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &PRODUCT_SERIAL;

	// Pre-process parameter: SESSION_ID
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &SESSION_ID;

	// Pre-process parameter: FEEDBACK_PAYLOAD
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &FEEDBACK_PAYLOAD;

	// Pre-process parameter: CIPHERING_KEY_NAME
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &CIPHERING_KEY_NAME;

	// Pre-process parameter: STATUS
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = STATUS;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = strMessageRetour;

	// Pre-process parameter: bresult
	__parameterTypeNames[7] = "System.Boolean&";
	__parameterTypes[7] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[7] = bresult;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"COMMIT_CUSTO", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			STATUS, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecupererPremierNSClient(
	SCProduction_GestionProductions __instance,
	char * strCodeComposant,
	char * indice,
	char ** firstSfc,
	char ** resultStatus,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;
	*firstSfc = 0;
	*resultStatus = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strCodeComposant
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strCodeComposant;

	// Pre-process parameter: indice
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &indice;

	// Pre-process parameter: firstSfc
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = firstSfc;

	// Pre-process parameter: resultStatus
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = resultStatus;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecupererPremierNSClient", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			firstSfc, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			resultStatus, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_DeconnexionBase(
	SCProduction_GestionProductions __instance,
	int * bErreurSurvenue,
	int * iErreurCode,
	char ** sErreurMessage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;
	*sErreurMessage = 0;


	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[0] = "System.Boolean&";
	__parameterTypes[0] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[0] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[1] = "System.Int32&";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[1] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = sErreurMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"DeconnexionBase", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_InitialisationParametresGestMES(
	SCProduction_GestionProductions __instance,
	char * sCheminFichier,
	int * bRetour,
	char ** sMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: sCheminFichier
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sCheminFichier;

	// Pre-process parameter: bRetour
	__parameterTypeNames[1] = "System.Boolean&";
	__parameterTypes[1] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[1] = bRetour;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"InitialisationParametresGestMES", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationParametrageMesuresMES(
	SCProduction_GestionProductions __instance,
	char * dcGroup,
	char * revision,
	char *** dcGroupList,
	ssize_t * __dcGroupListLength1,
	ssize_t * __dcGroupListLength2,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle dcGroupList__ = 0;

	if (__exception)
		*__exception = 0;
	*dcGroupList = 0;
	*__dcGroupListLength1 = 0;
	*__dcGroupListLength2 = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: dcGroup
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &dcGroup;

	// Pre-process parameter: revision
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &revision;

	// Pre-process parameter: dcGroupList
	__parameterTypeNames[2] = "System.String[,]&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[2] = &dcGroupList__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationParametrageMesuresMES", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: dcGroupList
	if (dcGroupList__) {
		__errChk(CDotNetGetArrayElements(
			dcGroupList__, 
			CDOTNET_STRING, 
			0, 
			dcGroupList));
		__errChk(CDotNetGetArrayLength(
			dcGroupList__, 
			0, 
			__dcGroupListLength1));
		__errChk(CDotNetGetArrayLength(
			dcGroupList__, 
			1, 
			__dcGroupListLength2));
	}


__Error:
	if (dcGroupList__)
		CDotNetDiscardHandle(dcGroupList__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			dcGroupList, 
			CDOTNET_STRING, 
			2, 
			__dcGroupListLength1, 
			__dcGroupListLength2);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];

	if (__exception)
		*__exception = 0;
	*sLibelleLigne = 0;
	*sDescriptionLigne = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sNomPoste
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNomPoste;

	// Pre-process parameter: sLibelleLigne
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = sLibelleLigne;

	// Pre-process parameter: sDescriptionLigne
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = sDescriptionLigne;

	// Pre-process parameter: iNumeroLigne
	__parameterTypeNames[3] = "System.Int32&";
	__parameterTypes[3] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[3] = iNumeroLigne;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[5] = "System.Int32&";
	__parameterTypes[5] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[5] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationLigneProductionParPoste", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sLibelleLigne, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sDescriptionLigne, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	CDotNetHandle stabProduits__ = 0;

	if (__exception)
		*__exception = 0;
	*stabProduits = 0;
	*__stabProduitsLength1 = 0;
	*__stabProduitsLength2 = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sNomPoste
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNomPoste;

	// Pre-process parameter: stabProduits
	__parameterTypeNames[1] = "System.String[,]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &stabProduits__;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[3] = "System.Int32&";
	__parameterTypes[3] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[3] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationProduitsParPoste", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: stabProduits
	if (stabProduits__) {
		__errChk(CDotNetGetArrayElements(
			stabProduits__, 
			CDOTNET_STRING, 
			0, 
			stabProduits));
		__errChk(CDotNetGetArrayLength(
			stabProduits__, 
			0, 
			__stabProduitsLength1));
		__errChk(CDotNetGetArrayLength(
			stabProduits__, 
			1, 
			__stabProduitsLength2));
	}


__Error:
	if (stabProduits__)
		CDotNetDiscardHandle(stabProduits__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			stabProduits, 
			CDOTNET_STRING, 
			2, 
			__stabProduitsLength1, 
			__stabProduitsLength2);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];

	if (__exception)
		*__exception = 0;
	*sCodeOperateur = 0;
	*sCodeSousFamille = 0;
	*sCodeFamille = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sCodeProduit
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sCodeProduit;

	// Pre-process parameter: sIndiceProduit
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sIndiceProduit;

	// Pre-process parameter: sCodeOperateur
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = sCodeOperateur;

	// Pre-process parameter: sCodeSousFamille
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = sCodeSousFamille;

	// Pre-process parameter: sCodeFamille
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = sCodeFamille;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[6] = "System.Int32&";
	__parameterTypes[6] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[6] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationProduitInformations", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sCodeOperateur, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sCodeSousFamille, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sCodeFamille, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];
	CDotNetHandle stabProduitsParents__ = 0;

	if (__exception)
		*__exception = 0;
	*stabProduitsParents = 0;
	*__stabProduitsParentsLength1 = 0;
	*__stabProduitsParentsLength2 = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sCodeProduitEnfant
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sCodeProduitEnfant;

	// Pre-process parameter: sIndiceProduitEnfant
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sIndiceProduitEnfant;

	// Pre-process parameter: stabProduitsParents
	__parameterTypeNames[2] = "System.String[,]&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[2] = &stabProduitsParents__;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[4] = "System.Int32&";
	__parameterTypes[4] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[4] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationProduitsParents", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: stabProduitsParents
	if (stabProduitsParents__) {
		__errChk(CDotNetGetArrayElements(
			stabProduitsParents__, 
			CDOTNET_STRING, 
			0, 
			stabProduitsParents));
		__errChk(CDotNetGetArrayLength(
			stabProduitsParents__, 
			0, 
			__stabProduitsParentsLength1));
		__errChk(CDotNetGetArrayLength(
			stabProduitsParents__, 
			1, 
			__stabProduitsParentsLength2));
	}


__Error:
	if (stabProduitsParents__)
		CDotNetDiscardHandle(stabProduitsParents__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			stabProduitsParents, 
			CDOTNET_STRING, 
			2, 
			__stabProduitsParentsLength1, 
			__stabProduitsParentsLength2);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];
	CDotNetHandle stabProduitsEnfants__ = 0;

	if (__exception)
		*__exception = 0;
	*stabProduitsEnfants = 0;
	*__stabProduitsEnfantsLength1 = 0;
	*__stabProduitsEnfantsLength2 = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sCodeProduitParent
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sCodeProduitParent;

	// Pre-process parameter: sIndiceProduitParent
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sIndiceProduitParent;

	// Pre-process parameter: stabProduitsEnfants
	__parameterTypeNames[2] = "System.String[,]&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[2] = &stabProduitsEnfants__;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[4] = "System.Int32&";
	__parameterTypes[4] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[4] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationProduitsEnfants", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: stabProduitsEnfants
	if (stabProduitsEnfants__) {
		__errChk(CDotNetGetArrayElements(
			stabProduitsEnfants__, 
			CDOTNET_STRING, 
			0, 
			stabProduitsEnfants));
		__errChk(CDotNetGetArrayLength(
			stabProduitsEnfants__, 
			0, 
			__stabProduitsEnfantsLength1));
		__errChk(CDotNetGetArrayLength(
			stabProduitsEnfants__, 
			1, 
			__stabProduitsEnfantsLength2));
	}


__Error:
	if (stabProduitsEnfants__)
		CDotNetDiscardHandle(stabProduitsEnfants__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			stabProduitsEnfants, 
			CDOTNET_STRING, 
			2, 
			__stabProduitsEnfantsLength1, 
			__stabProduitsEnfantsLength2);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];
	CDotNetHandle stabTypeTests__ = 0;

	if (__exception)
		*__exception = 0;
	*stabTypeTests = 0;
	*__stabTypeTestsLength1 = 0;
	*__stabTypeTestsLength2 = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sCodeProduit
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sCodeProduit;

	// Pre-process parameter: sIndiceProduit
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sIndiceProduit;

	// Pre-process parameter: sNomPoste
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &sNomPoste;

	// Pre-process parameter: stabTypeTests
	__parameterTypeNames[3] = "System.String[,]&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[3] = &stabTypeTests__;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[5] = "System.Int32&";
	__parameterTypes[5] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[5] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationTypeTestsParProduitParPoste", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: stabTypeTests
	if (stabTypeTests__) {
		__errChk(CDotNetGetArrayElements(
			stabTypeTests__, 
			CDOTNET_STRING, 
			0, 
			stabTypeTests));
		__errChk(CDotNetGetArrayLength(
			stabTypeTests__, 
			0, 
			__stabTypeTestsLength1));
		__errChk(CDotNetGetArrayLength(
			stabTypeTests__, 
			1, 
			__stabTypeTestsLength2));
	}


__Error:
	if (stabTypeTests__)
		CDotNetDiscardHandle(stabTypeTests__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			stabTypeTests, 
			CDOTNET_STRING, 
			2, 
			__stabTypeTestsLength1, 
			__stabTypeTestsLength2);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];
	CDotNetHandle stabProprietes__ = 0;

	if (__exception)
		*__exception = 0;
	*stabProprietes = 0;
	*__stabProprietesLength1 = 0;
	*__stabProprietesLength2 = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sCodeProduit
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sCodeProduit;

	// Pre-process parameter: sIndiceProduit
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sIndiceProduit;

	// Pre-process parameter: stabProprietes
	__parameterTypeNames[2] = "System.String[,]&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[2] = &stabProprietes__;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[4] = "System.Int32&";
	__parameterTypes[4] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[4] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationProprietes", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: stabProprietes
	if (stabProprietes__) {
		__errChk(CDotNetGetArrayElements(
			stabProprietes__, 
			CDOTNET_STRING, 
			0, 
			stabProprietes));
		__errChk(CDotNetGetArrayLength(
			stabProprietes__, 
			0, 
			__stabProprietesLength1));
		__errChk(CDotNetGetArrayLength(
			stabProprietes__, 
			1, 
			__stabProprietesLength2));
	}


__Error:
	if (stabProprietes__)
		CDotNetDiscardHandle(stabProprietes__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			stabProprietes, 
			CDOTNET_STRING, 
			2, 
			__stabProprietesLength1, 
			__stabProprietesLength2);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];
	CDotNetHandle stabProprietes__ = 0;

	if (__exception)
		*__exception = 0;
	*stabProprietes = 0;
	*__stabProprietesLength1 = 0;
	*__stabProprietesLength2 = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sCodeProduit
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sCodeProduit;

	// Pre-process parameter: sIndiceProduit
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sIndiceProduit;

	// Pre-process parameter: sNomPoste
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &sNomPoste;

	// Pre-process parameter: stabProprietes
	__parameterTypeNames[3] = "System.String[,]&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[3] = &stabProprietes__;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[5] = "System.Int32&";
	__parameterTypes[5] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[5] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationProprietesParPoste", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: stabProprietes
	if (stabProprietes__) {
		__errChk(CDotNetGetArrayElements(
			stabProprietes__, 
			CDOTNET_STRING, 
			0, 
			stabProprietes));
		__errChk(CDotNetGetArrayLength(
			stabProprietes__, 
			0, 
			__stabProprietesLength1));
		__errChk(CDotNetGetArrayLength(
			stabProprietes__, 
			1, 
			__stabProprietesLength2));
	}


__Error:
	if (stabProprietes__)
		CDotNetDiscardHandle(stabProprietes__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			stabProprietes, 
			CDOTNET_STRING, 
			2, 
			__stabProprietesLength1, 
			__stabProprietesLength2);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];

	if (__exception)
		*__exception = 0;
	*sValeur = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sCodeTypePoste
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sCodeTypePoste;

	// Pre-process parameter: sNomVariable
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sNomVariable;

	// Pre-process parameter: sValeur
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = sValeur;

	// Pre-process parameter: lId_Variable_TypePoste
	__parameterTypeNames[3] = "System.Int64&";
	__parameterTypes[3] = (CDOTNET_INT64 | CDOTNET_OUT);
	__parameters[3] = lId_Variable_TypePoste;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[5] = "System.Int32&";
	__parameterTypes[5] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[5] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationTypePosteVariable", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sValeur, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	CDotNetHandle stabVariables__ = 0;

	if (__exception)
		*__exception = 0;
	*stabVariables = 0;
	*__stabVariablesLength1 = 0;
	*__stabVariablesLength2 = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sNomPoste
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNomPoste;

	// Pre-process parameter: stabVariables
	__parameterTypeNames[1] = "System.String[,]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &stabVariables__;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[3] = "System.Int32&";
	__parameterTypes[3] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[3] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationPosteVariables", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: stabVariables
	if (stabVariables__) {
		__errChk(CDotNetGetArrayElements(
			stabVariables__, 
			CDOTNET_STRING, 
			0, 
			stabVariables));
		__errChk(CDotNetGetArrayLength(
			stabVariables__, 
			0, 
			__stabVariablesLength1));
		__errChk(CDotNetGetArrayLength(
			stabVariables__, 
			1, 
			__stabVariablesLength2));
	}


__Error:
	if (stabVariables__)
		CDotNetDiscardHandle(stabVariables__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			stabVariables, 
			CDOTNET_STRING, 
			2, 
			__stabVariablesLength1, 
			__stabVariablesLength2);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];

	if (__exception)
		*__exception = 0;
	*sValeur = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sNomPoste
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNomPoste;

	// Pre-process parameter: sNomVariable
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sNomVariable;

	// Pre-process parameter: sValeur
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = sValeur;

	// Pre-process parameter: lId_Variable_Poste
	__parameterTypeNames[3] = "System.Int64&";
	__parameterTypes[3] = (CDOTNET_INT64 | CDOTNET_OUT);
	__parameters[3] = lId_Variable_Poste;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[5] = "System.Int32&";
	__parameterTypes[5] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[5] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationPosteVariable", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sValeur, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];

	if (__exception)
		*__exception = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: lId_NumSerie
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &lId_NumSerie;

	// Pre-process parameter: sLibelle
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sLibelle;

	// Pre-process parameter: sDateDebut
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &sDateDebut;

	// Pre-process parameter: sDateFin
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &sDateFin;

	// Pre-process parameter: lId_Log
	__parameterTypeNames[4] = "System.Int64&";
	__parameterTypes[4] = (CDOTNET_INT64 | CDOTNET_OUT);
	__parameters[4] = lId_Log;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[6] = "System.Int32&";
	__parameterTypes[6] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[6] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementLog", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[15] = {0};
	unsigned int __parameterTypes[15];
	void * __parameters[15];

	if (__exception)
		*__exception = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: shYear
	__parameterTypeNames[0] = "System.Int16&";
	__parameterTypes[0] = (CDOTNET_INT16 | CDOTNET_OUT);
	__parameters[0] = shYear;

	// Pre-process parameter: shYear2Digits
	__parameterTypeNames[1] = "System.Int16&";
	__parameterTypes[1] = (CDOTNET_INT16 | CDOTNET_OUT);
	__parameters[1] = shYear2Digits;

	// Pre-process parameter: shMonth
	__parameterTypeNames[2] = "System.Int16&";
	__parameterTypes[2] = (CDOTNET_INT16 | CDOTNET_OUT);
	__parameters[2] = shMonth;

	// Pre-process parameter: shWeek
	__parameterTypeNames[3] = "System.Int16&";
	__parameterTypes[3] = (CDOTNET_INT16 | CDOTNET_OUT);
	__parameters[3] = shWeek;

	// Pre-process parameter: shDayOfWeek
	__parameterTypeNames[4] = "System.Int16&";
	__parameterTypes[4] = (CDOTNET_INT16 | CDOTNET_OUT);
	__parameters[4] = shDayOfWeek;

	// Pre-process parameter: shDayOfMonth
	__parameterTypeNames[5] = "System.Int16&";
	__parameterTypes[5] = (CDOTNET_INT16 | CDOTNET_OUT);
	__parameters[5] = shDayOfMonth;

	// Pre-process parameter: shDayOfYear
	__parameterTypeNames[6] = "System.Int16&";
	__parameterTypes[6] = (CDOTNET_INT16 | CDOTNET_OUT);
	__parameters[6] = shDayOfYear;

	// Pre-process parameter: shHour
	__parameterTypeNames[7] = "System.Int16&";
	__parameterTypes[7] = (CDOTNET_INT16 | CDOTNET_OUT);
	__parameters[7] = shHour;

	// Pre-process parameter: shMinute
	__parameterTypeNames[8] = "System.Int16&";
	__parameterTypes[8] = (CDOTNET_INT16 | CDOTNET_OUT);
	__parameters[8] = shMinute;

	// Pre-process parameter: shSecond
	__parameterTypeNames[9] = "System.Int16&";
	__parameterTypes[9] = (CDOTNET_INT16 | CDOTNET_OUT);
	__parameters[9] = shSecond;

	// Pre-process parameter: shMillisecond
	__parameterTypeNames[10] = "System.Int16&";
	__parameterTypes[10] = (CDOTNET_INT16 | CDOTNET_OUT);
	__parameters[10] = shMillisecond;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[11] = "System.Boolean&";
	__parameterTypes[11] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[11] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[12] = "System.Int32&";
	__parameterTypes[12] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[12] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[13] = "System.String&";
	__parameterTypes[13] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[13] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[14] = "System.String&";
	__parameterTypes[14] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[14] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationDateHeure", 
		0, 
		0, 
		15, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];
	CDotNetHandle stabParametres__ = 0;

	if (__exception)
		*__exception = 0;
	*sNumSerieClient = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sFormatClient
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sFormatClient;

	// Pre-process parameter: stabParametres
	if (stabParametres)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__stabParametresLength, 
			stabParametres, 
			&stabParametres__));
	__parameterTypeNames[1] = "System.String[]";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[1] = &stabParametres__;

	// Pre-process parameter: sNumSerieClient
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = sNumSerieClient;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[4] = "System.Int32&";
	__parameterTypes[4] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[4] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GenerationNumSerieClient_tcm", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (stabParametres__)
		CDotNetDiscardHandle(stabParametres__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sNumSerieClient, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];
	CDotNetHandle stabCles__ = 0;

	if (__exception)
		*__exception = 0;
	*stabCles = 0;
	*__stabClesLength1 = 0;
	*__stabClesLength2 = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sCodeProduit
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sCodeProduit;

	// Pre-process parameter: sIndiceProduit
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sIndiceProduit;

	// Pre-process parameter: stabCles
	__parameterTypeNames[2] = "System.String[,]&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[2] = &stabCles__;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[4] = "System.Int32&";
	__parameterTypes[4] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[4] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationClesParProduit", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: stabCles
	if (stabCles__) {
		__errChk(CDotNetGetArrayElements(
			stabCles__, 
			CDOTNET_STRING, 
			0, 
			stabCles));
		__errChk(CDotNetGetArrayLength(
			stabCles__, 
			0, 
			__stabClesLength1));
		__errChk(CDotNetGetArrayLength(
			stabCles__, 
			1, 
			__stabClesLength2));
	}


__Error:
	if (stabCles__)
		CDotNetDiscardHandle(stabCles__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			stabCles, 
			CDOTNET_STRING, 
			2, 
			__stabClesLength1, 
			__stabClesLength2);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];
	CDotNetHandle stabParametres__ = 0;
	CDotNetHandle stabValeursCle__ = 0;

	if (__exception)
		*__exception = 0;
	*stabValeursCle = 0;
	*__stabValeursCleLength = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sNomTableCle
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNomTableCle;

	// Pre-process parameter: sNumSerie
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sNumSerie;

	// Pre-process parameter: sCodeProduit
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &sCodeProduit;

	// Pre-process parameter: sIndiceProduit
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &sIndiceProduit;

	// Pre-process parameter: stabParametres
	if (stabParametres)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__stabParametresLength, 
			stabParametres, 
			&stabParametres__));
	__parameterTypeNames[4] = "System.String[]";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[4] = &stabParametres__;

	// Pre-process parameter: stabValeursCle
	__parameterTypeNames[5] = "System.String[]&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[5] = &stabValeursCle__;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[7] = "System.Int32&";
	__parameterTypes[7] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[7] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationCle_sapme", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: stabValeursCle
	if (stabValeursCle__) {
		__errChk(CDotNetGetArrayElements(
			stabValeursCle__, 
			CDOTNET_STRING, 
			0, 
			stabValeursCle));
		__errChk(CDotNetGetArrayLength(
			stabValeursCle__, 
			0, 
			__stabValeursCleLength));
	}


__Error:
	if (stabParametres__)
		CDotNetDiscardHandle(stabParametres__);
	if (stabValeursCle__)
		CDotNetDiscardHandle(stabValeursCle__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			stabValeursCle, 
			CDOTNET_STRING, 
			1, 
			__stabValeursCleLength);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];
	CDotNetHandle stabParametres__ = 0;
	CDotNetHandle stabValeursCles__ = 0;

	if (__exception)
		*__exception = 0;
	*stabValeursCles = 0;
	*__stabValeursClesLength1 = 0;
	*__stabValeursClesLength2 = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sNomTableCle
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNomTableCle;

	// Pre-process parameter: sNumSerie
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sNumSerie;

	// Pre-process parameter: sCodeProduit
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &sCodeProduit;

	// Pre-process parameter: sIndiceProduit
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &sIndiceProduit;

	// Pre-process parameter: stabParametres
	if (stabParametres)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__stabParametresLength, 
			stabParametres, 
			&stabParametres__));
	__parameterTypeNames[4] = "System.String[]";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[4] = &stabParametres__;

	// Pre-process parameter: stabValeursCles
	__parameterTypeNames[5] = "System.String[,]&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[5] = &stabValeursCles__;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[7] = "System.Int32&";
	__parameterTypes[7] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[7] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationCles_sapme", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: stabValeursCles
	if (stabValeursCles__) {
		__errChk(CDotNetGetArrayElements(
			stabValeursCles__, 
			CDOTNET_STRING, 
			0, 
			stabValeursCles));
		__errChk(CDotNetGetArrayLength(
			stabValeursCles__, 
			0, 
			__stabValeursClesLength1));
		__errChk(CDotNetGetArrayLength(
			stabValeursCles__, 
			1, 
			__stabValeursClesLength2));
	}


__Error:
	if (stabParametres__)
		CDotNetDiscardHandle(stabParametres__);
	if (stabValeursCles__)
		CDotNetDiscardHandle(stabValeursCles__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			stabValeursCles, 
			CDOTNET_STRING, 
			2, 
			__stabValeursClesLength1, 
			__stabValeursClesLength2);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];

	if (__exception)
		*__exception = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sNomTableCle
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNomTableCle;

	// Pre-process parameter: sNumSerie
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sNumSerie;

	// Pre-process parameter: sCodeProduit
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &sCodeProduit;

	// Pre-process parameter: sIndiceProduit
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &sIndiceProduit;

	// Pre-process parameter: lId_Cle
	__parameterTypeNames[4] = "System.Int64&";
	__parameterTypes[4] = (CDOTNET_INT64 | CDOTNET_OUT);
	__parameters[4] = lId_Cle;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[6] = "System.Int32&";
	__parameterTypes[6] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[6] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"LiberationCle_sapme", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];
	CDotNetHandle stabId_Cle__ = 0;

	if (__exception)
		*__exception = 0;
	*stabId_Cle = 0;
	*__stabId_CleLength1 = 0;
	*__stabId_CleLength2 = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sNomTableCle
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNomTableCle;

	// Pre-process parameter: sNumSerie
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sNumSerie;

	// Pre-process parameter: sCodeProduit
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &sCodeProduit;

	// Pre-process parameter: sIndiceProduit
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &sIndiceProduit;

	// Pre-process parameter: stabId_Cle
	__parameterTypeNames[4] = "System.Int64[,]&";
	__parameterTypes[4] = (CDOTNET_INT64 | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[4] = &stabId_Cle__;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[6] = "System.Int32&";
	__parameterTypes[6] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[6] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"LiberationCles_sapme", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: stabId_Cle
	if (stabId_Cle__) {
		__errChk(CDotNetGetArrayElements(
			stabId_Cle__, 
			CDOTNET_INT64, 
			0, 
			stabId_Cle));
		__errChk(CDotNetGetArrayLength(
			stabId_Cle__, 
			0, 
			__stabId_CleLength1));
		__errChk(CDotNetGetArrayLength(
			stabId_Cle__, 
			1, 
			__stabId_CleLength2));
	}


__Error:
	if (stabId_Cle__)
		CDotNetDiscardHandle(stabId_Cle__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			stabId_Cle, 
			CDOTNET_INT64, 
			2, 
			__stabId_CleLength1, 
			__stabId_CleLength2);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];

	if (__exception)
		*__exception = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sNomTableCle
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNomTableCle;

	// Pre-process parameter: sNumSerie
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sNumSerie;

	// Pre-process parameter: sCodeProduit
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &sCodeProduit;

	// Pre-process parameter: sIndiceProduit
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &sIndiceProduit;

	// Pre-process parameter: lId_Cle
	__parameterTypeNames[4] = "System.Int64&";
	__parameterTypes[4] = (CDOTNET_INT64 | CDOTNET_OUT);
	__parameters[4] = lId_Cle;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[6] = "System.Int32&";
	__parameterTypes[6] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[6] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"NettoyageCle_sapme", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];
	CDotNetHandle stabParametres__ = 0;
	CDotNetHandle stabValeursCle__ = 0;

	if (__exception)
		*__exception = 0;
	*stabValeursCle = 0;
	*__stabValeursCleLength = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sNomTableCle
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNomTableCle;

	// Pre-process parameter: sNumSerie
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sNumSerie;

	// Pre-process parameter: sCodeProduit
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &sCodeProduit;

	// Pre-process parameter: sIndiceProduit
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &sIndiceProduit;

	// Pre-process parameter: stabParametres
	if (stabParametres)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__stabParametresLength, 
			stabParametres, 
			&stabParametres__));
	__parameterTypeNames[4] = "System.String[]";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[4] = &stabParametres__;

	// Pre-process parameter: stabValeursCle
	__parameterTypeNames[5] = "System.String[]&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[5] = &stabValeursCle__;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[7] = "System.Int32&";
	__parameterTypes[7] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[7] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EcritureCle_sapme", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: stabValeursCle
	if (stabValeursCle__) {
		__errChk(CDotNetGetArrayElements(
			stabValeursCle__, 
			CDOTNET_STRING, 
			0, 
			stabValeursCle));
		__errChk(CDotNetGetArrayLength(
			stabValeursCle__, 
			0, 
			__stabValeursCleLength));
	}


__Error:
	if (stabParametres__)
		CDotNetDiscardHandle(stabParametres__);
	if (stabValeursCle__)
		CDotNetDiscardHandle(stabValeursCle__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			stabValeursCle, 
			CDOTNET_STRING, 
			1, 
			__stabValeursCleLength);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];
	CDotNetHandle stabParametres__ = 0;
	CDotNetHandle stabValeursCle__ = 0;

	if (__exception)
		*__exception = 0;
	*stabValeursCle = 0;
	*__stabValeursCleLength = 0;
	*sErreurMessage = 0;
	*sErreurRequete = 0;


	// Pre-process parameter: sNomTableCle
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNomTableCle;

	// Pre-process parameter: sNumSerie
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &sNumSerie;

	// Pre-process parameter: sCodeProduit
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &sCodeProduit;

	// Pre-process parameter: sIndiceProduit
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &sIndiceProduit;

	// Pre-process parameter: stabParametres
	if (stabParametres)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__stabParametresLength, 
			stabParametres, 
			&stabParametres__));
	__parameterTypeNames[4] = "System.String[]";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[4] = &stabParametres__;

	// Pre-process parameter: stabValeursCle
	__parameterTypeNames[5] = "System.String[]&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[5] = &stabValeursCle__;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = bErreurSurvenue;

	// Pre-process parameter: iErreurCode
	__parameterTypeNames[7] = "System.Int32&";
	__parameterTypes[7] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[7] = iErreurCode;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = sErreurMessage;

	// Pre-process parameter: sErreurRequete
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = sErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"LectureCle_sapme", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: stabValeursCle
	if (stabValeursCle__) {
		__errChk(CDotNetGetArrayElements(
			stabValeursCle__, 
			CDOTNET_STRING, 
			0, 
			stabValeursCle));
		__errChk(CDotNetGetArrayLength(
			stabValeursCle__, 
			0, 
			__stabValeursCleLength));
	}


__Error:
	if (stabParametres__)
		CDotNetDiscardHandle(stabParametres__);
	if (stabValeursCle__)
		CDotNetDiscardHandle(stabValeursCle__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			stabValeursCle, 
			CDOTNET_STRING, 
			1, 
			__stabValeursCleLength);
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_DebutOperationAvecGenerationSFC(
	SCProduction_GestionProductions __instance,
	char * strCodeProduit,
	char * operation,
	char * Ressource,
	char * indice,
	char ** strNumeroSerie,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];

	if (__exception)
		*__exception = 0;
	*strNumeroSerie = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strCodeProduit
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strCodeProduit;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: Ressource
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Ressource;

	// Pre-process parameter: indice
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &indice;

	// Pre-process parameter: strNumeroSerie
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strNumeroSerie;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"DebutOperationAvecGenerationSFC", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strNumeroSerie, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_FinOperation(
	SCProduction_GestionProductions __instance,
	char * sNumSerie,
	char * Ressource,
	char * Operation,
	int * bResult,
	char ** sMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: sNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNumSerie;

	// Pre-process parameter: Ressource
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &Ressource;

	// Pre-process parameter: Operation
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Operation;

	// Pre-process parameter: bResult
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bResult;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"FinOperation", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_FinOperation_V2(
	SCProduction_GestionProductions __instance,
	char * sNumSerie,
	char * Ressource,
	char * Operation,
	char * Revision,
	int * bResult,
	char ** sMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: sNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNumSerie;

	// Pre-process parameter: Ressource
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &Ressource;

	// Pre-process parameter: Operation
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Operation;

	// Pre-process parameter: Revision
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &Revision;

	// Pre-process parameter: bResult
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bResult;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"FinOperation_V2", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_FinOperationEnMasse(
	SCProduction_GestionProductions __instance,
	char ** sNumSerie,
	ssize_t __sNumSerieLength,
	char * Ressource,
	char * Operation,
	char * indice,
	int * bResult,
	char ** sMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	CDotNetHandle sNumSerie__ = 0;

	if (__exception)
		*__exception = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: sNumSerie
	if (sNumSerie)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__sNumSerieLength, 
			sNumSerie, 
			&sNumSerie__));
	__parameterTypeNames[0] = "System.String[]";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[0] = &sNumSerie__;

	// Pre-process parameter: Ressource
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &Ressource;

	// Pre-process parameter: Operation
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Operation;

	// Pre-process parameter: indice
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &indice;

	// Pre-process parameter: bResult
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bResult;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"FinOperationEnMasse", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (sNumSerie__)
		CDotNetDiscardHandle(sNumSerie__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_DebutOperation(
	SCProduction_GestionProductions __instance,
	char * sNumSerie,
	char * Ressource,
	char * Operation,
	int * bResult,
	char ** sMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: sNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNumSerie;

	// Pre-process parameter: Ressource
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &Ressource;

	// Pre-process parameter: Operation
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Operation;

	// Pre-process parameter: bResult
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bResult;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"DebutOperation", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_DebutOperation_V2(
	SCProduction_GestionProductions __instance,
	char * sNumSerie,
	char * Ressource,
	char * Operation,
	char * Revision,
	int * bResult,
	char ** sMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: sNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNumSerie;

	// Pre-process parameter: Ressource
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &Ressource;

	// Pre-process parameter: Operation
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Operation;

	// Pre-process parameter: Revision
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &Revision;

	// Pre-process parameter: bResult
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bResult;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"DebutOperation_V2", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_DebutOperationEnMasse(
	SCProduction_GestionProductions __instance,
	char ** sNumSerie,
	ssize_t __sNumSerieLength,
	char * Ressource,
	char * Operation,
	char * indice,
	int * bResult,
	char ** sMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	CDotNetHandle sNumSerie__ = 0;

	if (__exception)
		*__exception = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: sNumSerie
	if (sNumSerie)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__sNumSerieLength, 
			sNumSerie, 
			&sNumSerie__));
	__parameterTypeNames[0] = "System.String[]";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[0] = &sNumSerie__;

	// Pre-process parameter: Ressource
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &Ressource;

	// Pre-process parameter: Operation
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Operation;

	// Pre-process parameter: indice
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &indice;

	// Pre-process parameter: bResult
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = bResult;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"DebutOperationEnMasse", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (sNumSerie__)
		CDotNetDiscardHandle(sNumSerie__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[12] = {0};
	unsigned int __parameterTypes[12];
	void * __parameters[12];

	if (__exception)
		*__exception = 0;
	*shopOrder = 0;
	*orderType = 0;
	*item = 0;
	*revision = 0;
	*router = 0;
	*indice = 0;
	*bom = 0;
	*indicebom = 0;
	*workCenter = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: Ressource
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &Ressource;

	// Pre-process parameter: shopOrder
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = shopOrder;

	// Pre-process parameter: orderType
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = orderType;

	// Pre-process parameter: item
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = item;

	// Pre-process parameter: revision
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = revision;

	// Pre-process parameter: router
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = router;

	// Pre-process parameter: indice
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = indice;

	// Pre-process parameter: bom
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = bom;

	// Pre-process parameter: indicebom
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = indicebom;

	// Pre-process parameter: workCenter
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = workCenter;

	// Pre-process parameter: Result
	__parameterTypeNames[10] = "System.Boolean&";
	__parameterTypes[10] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[10] = Result;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[11] = "System.String&";
	__parameterTypes[11] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[11] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationInformationRessource", 
		0, 
		0, 
		12, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			shopOrder, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			orderType, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			item, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			revision, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			router, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			indice, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			bom, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			indicebom, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			workCenter, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationDetailsNC(
	SCProduction_GestionProductions __instance,
	char * ncGroupName,
	char *** NCCode,
	ssize_t * __NCCodeLength1,
	ssize_t * __NCCodeLength2,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle NCCode__ = 0;

	if (__exception)
		*__exception = 0;
	*NCCode = 0;
	*__NCCodeLength1 = 0;
	*__NCCodeLength2 = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: ncGroupName
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &ncGroupName;

	// Pre-process parameter: NCCode
	__parameterTypeNames[1] = "System.String[,]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &NCCode__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationDetailsNC", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: NCCode
	if (NCCode__) {
		__errChk(CDotNetGetArrayElements(
			NCCode__, 
			CDOTNET_STRING, 
			0, 
			NCCode));
		__errChk(CDotNetGetArrayLength(
			NCCode__, 
			0, 
			__NCCodeLength1));
		__errChk(CDotNetGetArrayLength(
			NCCode__, 
			1, 
			__NCCodeLength2));
	}


__Error:
	if (NCCode__)
		CDotNetDiscardHandle(NCCode__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			NCCode, 
			CDOTNET_STRING, 
			2, 
			__NCCodeLength1, 
			__NCCodeLength2);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationLastNC(
	SCProduction_GestionProductions __instance,
	char * strNumSerie,
	char ** ncCodeRef,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;
	*ncCodeRef = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: ncCodeRef
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = ncCodeRef;

	// Pre-process parameter: bResult
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bResult;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationLastNC", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			ncCodeRef, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationStatusSfc(
	SCProduction_GestionProductions __instance,
	char ** strNumSerie,
	ssize_t __strNumSerieLength,
	char *** StatusSfc,
	ssize_t * __StatusSfcLength1,
	ssize_t * __StatusSfcLength2,
	int * bResult,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle strNumSerie__ = 0;
	CDotNetHandle StatusSfc__ = 0;

	if (__exception)
		*__exception = 0;
	*StatusSfc = 0;
	*__StatusSfcLength1 = 0;
	*__StatusSfcLength2 = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	if (strNumSerie)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__strNumSerieLength, 
			strNumSerie, 
			&strNumSerie__));
	__parameterTypeNames[0] = "System.String[]";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[0] = &strNumSerie__;

	// Pre-process parameter: StatusSfc
	__parameterTypeNames[1] = "System.String[,]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &StatusSfc__;

	// Pre-process parameter: bResult
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bResult;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationStatusSfc", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: StatusSfc
	if (StatusSfc__) {
		__errChk(CDotNetGetArrayElements(
			StatusSfc__, 
			CDOTNET_STRING, 
			0, 
			StatusSfc));
		__errChk(CDotNetGetArrayLength(
			StatusSfc__, 
			0, 
			__StatusSfcLength1));
		__errChk(CDotNetGetArrayLength(
			StatusSfc__, 
			1, 
			__StatusSfcLength2));
	}


__Error:
	if (strNumSerie__)
		CDotNetDiscardHandle(strNumSerie__);
	if (StatusSfc__)
		CDotNetDiscardHandle(StatusSfc__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			StatusSfc, 
			CDOTNET_STRING, 
			2, 
			__StatusSfcLength1, 
			__StatusSfcLength2);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationDetailsOFV2(
	SCProduction_GestionProductions __instance,
	char * strOrdreFab,
	char ** strItemRef,
	char ** strItemRevision,
	char ** strTypeOrdreFab,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;
	*strItemRef = 0;
	*strItemRevision = 0;
	*strTypeOrdreFab = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strOrdreFab
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strOrdreFab;

	// Pre-process parameter: strItemRef
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = strItemRef;

	// Pre-process parameter: strItemRevision
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = strItemRevision;

	// Pre-process parameter: strTypeOrdreFab
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strTypeOrdreFab;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationDetailsOFV2", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strItemRef, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strItemRevision, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strTypeOrdreFab, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];

	if (__exception)
		*__exception = 0;
	*IncidentDateTime1 = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: Ressource
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Ressource;

	// Pre-process parameter: strCodeErreur
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &strCodeErreur;

	// Pre-process parameter: strLibelleErreur
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &strLibelleErreur;

	// Pre-process parameter: refdes
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &refdes;

	// Pre-process parameter: IncidentDateTime1
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = IncidentDateTime1;

	// Pre-process parameter: Seque
	__parameterTypeNames[7] = "System.Decimal&";
	__parameterTypes[7] = (CDOTNET_DECIMAL | CDOTNET_OUT);
	__parameters[7] = Seque;

	// Pre-process parameter: bResultat
	__parameterTypeNames[8] = "System.Boolean&";
	__parameterTypes[8] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[8] = bResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementNonConformiteSansRoutage", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			IncidentDateTime1, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[16] = {0};
	unsigned int __parameterTypes[16];
	void * __parameters[16];

	if (__exception)
		*__exception = 0;
	*sErreurMessage = 0;


	// Pre-process parameter: sNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNumSerie;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: ressource
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &ressource;

	// Pre-process parameter: OF
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &OF;

	// Pre-process parameter: sCodeTypeTest
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &sCodeTypeTest;

	// Pre-process parameter: sCodeStatutTest
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &sCodeStatutTest;

	// Pre-process parameter: dDuree
	__parameterTypeNames[6] = "System.Decimal";
	__parameterTypes[6] = (CDOTNET_DECIMAL);
	__parameters[6] = &dDuree;

	// Pre-process parameter: sDescription
	__parameterTypeNames[7] = "System.String";
	__parameterTypes[7] = (CDOTNET_STRING);
	__parameters[7] = &sDescription;

	// Pre-process parameter: sValeur
	__parameterTypeNames[8] = "System.String";
	__parameterTypes[8] = (CDOTNET_STRING);
	__parameters[8] = &sValeur;

	// Pre-process parameter: sToleranceMinimum
	__parameterTypeNames[9] = "System.String";
	__parameterTypes[9] = (CDOTNET_STRING);
	__parameters[9] = &sToleranceMinimum;

	// Pre-process parameter: sToleranceMaximum
	__parameterTypeNames[10] = "System.String";
	__parameterTypes[10] = (CDOTNET_STRING);
	__parameters[10] = &sToleranceMaximum;

	// Pre-process parameter: sUniteMesusre
	__parameterTypeNames[11] = "System.String";
	__parameterTypes[11] = (CDOTNET_STRING);
	__parameters[11] = &sUniteMesusre;

	// Pre-process parameter: sgroupe
	__parameterTypeNames[12] = "System.String";
	__parameterTypes[12] = (CDOTNET_STRING);
	__parameters[12] = &sgroupe;

	// Pre-process parameter: sComment
	__parameterTypeNames[13] = "System.String";
	__parameterTypes[13] = (CDOTNET_STRING);
	__parameters[13] = &sComment;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[14] = "System.Boolean&";
	__parameterTypes[14] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[14] = bErreurSurvenue;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[15] = "System.String&";
	__parameterTypes[15] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[15] = sErreurMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementTestMesure", 
		0, 
		0, 
		16, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[19] = {0};
	unsigned int __parameterTypes[19];
	void * __parameters[19];

	if (__exception)
		*__exception = 0;
	*sErreurMessage = 0;


	// Pre-process parameter: sNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNumSerie;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: ressource
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &ressource;

	// Pre-process parameter: OF
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &OF;

	// Pre-process parameter: sCodeTypeTest
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &sCodeTypeTest;

	// Pre-process parameter: sCodeStatutTest
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &sCodeStatutTest;

	// Pre-process parameter: dDuree
	__parameterTypeNames[6] = "System.Decimal";
	__parameterTypes[6] = (CDOTNET_DECIMAL);
	__parameters[6] = &dDuree;

	// Pre-process parameter: sDescription
	__parameterTypeNames[7] = "System.String";
	__parameterTypes[7] = (CDOTNET_STRING);
	__parameters[7] = &sDescription;

	// Pre-process parameter: sValeur
	__parameterTypeNames[8] = "System.String";
	__parameterTypes[8] = (CDOTNET_STRING);
	__parameters[8] = &sValeur;

	// Pre-process parameter: sToleranceMinimum
	__parameterTypeNames[9] = "System.String";
	__parameterTypes[9] = (CDOTNET_STRING);
	__parameters[9] = &sToleranceMinimum;

	// Pre-process parameter: sToleranceMaximum
	__parameterTypeNames[10] = "System.String";
	__parameterTypes[10] = (CDOTNET_STRING);
	__parameters[10] = &sToleranceMaximum;

	// Pre-process parameter: sUniteMesusre
	__parameterTypeNames[11] = "System.String";
	__parameterTypes[11] = (CDOTNET_STRING);
	__parameters[11] = &sUniteMesusre;

	// Pre-process parameter: sgroupe
	__parameterTypeNames[12] = "System.String";
	__parameterTypes[12] = (CDOTNET_STRING);
	__parameters[12] = &sgroupe;

	// Pre-process parameter: sComment
	__parameterTypeNames[13] = "System.String";
	__parameterTypes[13] = (CDOTNET_STRING);
	__parameters[13] = &sComment;

	// Pre-process parameter: strProductCode
	__parameterTypeNames[14] = "System.String";
	__parameterTypes[14] = (CDOTNET_STRING);
	__parameters[14] = &strProductCode;

	// Pre-process parameter: strRevisionProductCode
	__parameterTypeNames[15] = "System.String";
	__parameterTypes[15] = (CDOTNET_STRING);
	__parameters[15] = &strRevisionProductCode;

	// Pre-process parameter: TestPlan
	__parameterTypeNames[16] = "System.String";
	__parameterTypes[16] = (CDOTNET_STRING);
	__parameters[16] = &TestPlan;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[17] = "System.Boolean&";
	__parameterTypes[17] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[17] = bErreurSurvenue;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[18] = "System.String&";
	__parameterTypes[18] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[18] = sErreurMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementTestMesureParCodeProduit", 
		0, 
		0, 
		19, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];
	CDotNetHandle tabValeurschip__ = 0;

	if (__exception)
		*__exception = 0;
	*statuts = 0;
	*tabValeurschip = 0;
	*__tabValeurschipLength = 0;
	*strErreurMessage = 0;
	*strErreurRequete = 0;


	// Pre-process parameter: SN_CIE
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SN_CIE;

	// Pre-process parameter: Chip_id
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &Chip_id;

	// Pre-process parameter: code_produit_CIE
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &code_produit_CIE;

	// Pre-process parameter: indice_CIE
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &indice_CIE;

	// Pre-process parameter: statuts
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = statuts;

	// Pre-process parameter: tabValeurschip
	__parameterTypeNames[5] = "System.String[]&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[5] = &tabValeurschip__;

	// Pre-process parameter: blnErreurSurvenue
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = blnErreurSurvenue;

	// Pre-process parameter: intErreurCode
	__parameterTypeNames[7] = "System.Int32&";
	__parameterTypes[7] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[7] = intErreurCode;

	// Pre-process parameter: strErreurMessage
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = strErreurMessage;

	// Pre-process parameter: strErreurRequete
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = strErreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"insertion_chip_id", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: tabValeurschip
	if (tabValeurschip__) {
		__errChk(CDotNetGetArrayElements(
			tabValeurschip__, 
			CDOTNET_STRING, 
			0, 
			tabValeurschip));
		__errChk(CDotNetGetArrayLength(
			tabValeurschip__, 
			0, 
			__tabValeurschipLength));
	}


__Error:
	if (tabValeurschip__)
		CDotNetDiscardHandle(tabValeurschip__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			statuts, 
			CDOTNET_STRING);
		_CDotNetGenDisposeArray(
			tabValeurschip, 
			CDOTNET_STRING, 
			1, 
			__tabValeurschipLength);
		_CDotNetGenDisposeScalar(
			strErreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strErreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];
	CDotNetHandle AssyDataValues__ = 0;
	ssize_t __AssyDataValuesLengths[2];
	CDotNetHandle ReplenishComponentResponse__ = 0;

	if (__exception)
		*__exception = 0;
	*ReplenishComponentResponse = 0;
	*__ReplenishComponentResponseLength1 = 0;
	*__ReplenishComponentResponseLength2 = 0;
	*strMessage = 0;


	// Pre-process parameter: Resource
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &Resource;

	// Pre-process parameter: SlotConfigId
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &SlotConfigId;

	// Pre-process parameter: Revision
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Revision;

	// Pre-process parameter: Slot
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &Slot;

	// Pre-process parameter: Item
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &Item;

	// Pre-process parameter: AssyDataValues
	__AssyDataValuesLengths[0] = __AssyDataValuesLength1;
	__AssyDataValuesLengths[1] = __AssyDataValuesLength2;
	if (AssyDataValues)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			2, 
			0, 
			__AssyDataValuesLengths, 
			AssyDataValues, 
			&AssyDataValues__));
	__parameterTypeNames[5] = "System.String[,]";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[5] = &AssyDataValues__;

	// Pre-process parameter: ReplenishComponentResponse
	__parameterTypeNames[6] = "System.String[,]&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[6] = &ReplenishComponentResponse__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[7] = "System.Boolean&";
	__parameterTypes[7] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[7] = blnResultat;

	// Pre-process parameter: strMessage
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = strMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReplenishComponent", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: ReplenishComponentResponse
	if (ReplenishComponentResponse__) {
		__errChk(CDotNetGetArrayElements(
			ReplenishComponentResponse__, 
			CDOTNET_STRING, 
			0, 
			ReplenishComponentResponse));
		__errChk(CDotNetGetArrayLength(
			ReplenishComponentResponse__, 
			0, 
			__ReplenishComponentResponseLength1));
		__errChk(CDotNetGetArrayLength(
			ReplenishComponentResponse__, 
			1, 
			__ReplenishComponentResponseLength2));
	}


__Error:
	if (AssyDataValues__)
		CDotNetDiscardHandle(AssyDataValues__);
	if (ReplenishComponentResponse__)
		CDotNetDiscardHandle(ReplenishComponentResponse__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			ReplenishComponentResponse, 
			CDOTNET_STRING, 
			2, 
			__ReplenishComponentResponseLength1, 
			__ReplenishComponentResponseLength2);
		_CDotNetGenDisposeScalar(
			strMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];

	if (__exception)
		*__exception = 0;
	*valeur = 0;
	*erreurMessage = 0;
	*erreurRequete = 0;


	// Pre-process parameter: codeProduit
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &codeProduit;

	// Pre-process parameter: indiceProduit
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &indiceProduit;

	// Pre-process parameter: nomVariable
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &nomVariable;

	// Pre-process parameter: valeur
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = valeur;

	// Pre-process parameter: id_propriete
	__parameterTypeNames[4] = "System.Int64&";
	__parameterTypes[4] = (CDOTNET_INT64 | CDOTNET_OUT);
	__parameters[4] = id_propriete;

	// Pre-process parameter: erreurSurvenue
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = erreurSurvenue;

	// Pre-process parameter: erreurCode
	__parameterTypeNames[6] = "System.Int32&";
	__parameterTypes[6] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[6] = erreurCode;

	// Pre-process parameter: erreurMessage
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = erreurMessage;

	// Pre-process parameter: erreurRequete
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = erreurRequete;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationPropriete", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			valeur, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurMessage, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			erreurRequete, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[15] = {0};
	unsigned int __parameterTypes[15];
	void * __parameters[15];

	if (__exception)
		*__exception = 0;
	*tabsansNum_Lot = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: ressource
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &ressource;

	// Pre-process parameter: ligne
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &ligne;

	// Pre-process parameter: listeDeMachine
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &listeDeMachine;

	// Pre-process parameter: VariableDonneeCollecte
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &VariableDonneeCollecte;

	// Pre-process parameter: chaineDeconnexionSQL
	__parameterTypeNames[6] = "System.String";
	__parameterTypes[6] = (CDOTNET_STRING);
	__parameters[6] = &chaineDeconnexionSQL;

	// Pre-process parameter: chaineDeConnexionOracle
	__parameterTypeNames[7] = "System.String";
	__parameterTypes[7] = (CDOTNET_STRING);
	__parameters[7] = &chaineDeConnexionOracle;

	// Pre-process parameter: chaineDeConnexionPostgres
	__parameterTypeNames[8] = "System.String";
	__parameterTypes[8] = (CDOTNET_STRING);
	__parameters[8] = &chaineDeConnexionPostgres;

	// Pre-process parameter: RefCodeProduit
	__parameterTypeNames[9] = "System.String";
	__parameterTypes[9] = (CDOTNET_STRING);
	__parameters[9] = &RefCodeProduit;

	// Pre-process parameter: indice
	__parameterTypeNames[10] = "System.String";
	__parameterTypes[10] = (CDOTNET_STRING);
	__parameters[10] = &indice;

	// Pre-process parameter: OrdreFabr
	__parameterTypeNames[11] = "System.String";
	__parameterTypes[11] = (CDOTNET_STRING);
	__parameters[11] = &OrdreFabr;

	// Pre-process parameter: tabsansNum_Lot
	__parameterTypeNames[12] = "System.Collections.Generic.List`1[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]&";
	__parameterTypes[12] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[12] = tabsansNum_Lot;

	// Pre-process parameter: bResult
	__parameterTypeNames[13] = "System.Boolean&";
	__parameterTypes[13] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[13] = bResult;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[14] = "System.String&";
	__parameterTypes[14] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[14] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementTableauTestsMesuresDepuisValor", 
		0, 
		0, 
		15, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			tabsansNum_Lot, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_INSERT_PROPERITE_IN_PACKOUT(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char * variable,
	char * value,
	int * bresult,
	char ** strmessage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*strmessage = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: variable
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &variable;

	// Pre-process parameter: value
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &value;

	// Pre-process parameter: bresult
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = bresult;

	// Pre-process parameter: strmessage
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strmessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"INSERT_PROPERITE_IN_PACKOUT", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strmessage, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[11] = {0};
	unsigned int __parameterTypes[11];
	void * __parameters[11];

	if (__exception)
		*__exception = 0;
	*tabsansNum_Lot = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: ressource
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &ressource;

	// Pre-process parameter: ligne
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &ligne;

	// Pre-process parameter: listeDeMachine
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &listeDeMachine;

	// Pre-process parameter: VariableDonneeCollecte
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &VariableDonneeCollecte;

	// Pre-process parameter: chaineDeconnexionSQL
	__parameterTypeNames[6] = "System.String";
	__parameterTypes[6] = (CDOTNET_STRING);
	__parameters[6] = &chaineDeconnexionSQL;

	// Pre-process parameter: chaineDeConnexionOracle
	__parameterTypeNames[7] = "System.String";
	__parameterTypes[7] = (CDOTNET_STRING);
	__parameters[7] = &chaineDeConnexionOracle;

	// Pre-process parameter: tabsansNum_Lot
	__parameterTypeNames[8] = "System.Collections.Generic.List`1[[System.String, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]&";
	__parameterTypes[8] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[8] = tabsansNum_Lot;

	// Pre-process parameter: bResult
	__parameterTypeNames[9] = "System.Boolean&";
	__parameterTypes[9] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[9] = bResult;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[10] = "System.String&";
	__parameterTypes[10] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[10] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementTableauTestsMesuresDepuisValor", 
		0, 
		0, 
		11, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			tabsansNum_Lot, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationDonneesCollecteesSFC(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char *** TabValeur,
	ssize_t * __TabValeurLength1,
	ssize_t * __TabValeurLength2,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle TabValeur__ = 0;

	if (__exception)
		*__exception = 0;
	*TabValeur = 0;
	*__TabValeurLength1 = 0;
	*__TabValeurLength2 = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: TabValeur
	__parameterTypeNames[1] = "System.String[,]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &TabValeur__;

	// Pre-process parameter: bResultat
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationDonneesCollecteesSFC", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: TabValeur
	if (TabValeur__) {
		__errChk(CDotNetGetArrayElements(
			TabValeur__, 
			CDOTNET_STRING, 
			0, 
			TabValeur));
		__errChk(CDotNetGetArrayLength(
			TabValeur__, 
			0, 
			__TabValeurLength1));
		__errChk(CDotNetGetArrayLength(
			TabValeur__, 
			1, 
			__TabValeurLength2));
	}


__Error:
	if (TabValeur__)
		CDotNetDiscardHandle(TabValeur__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			TabValeur, 
			CDOTNET_STRING, 
			2, 
			__TabValeurLength1, 
			__TabValeurLength2);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_Recuperation_Historique_Mouvement_SFC(
	SCProduction_GestionProductions __instance,
	char * SFC,
	char *** tabValue,
	ssize_t * __tabValueLength1,
	ssize_t * __tabValueLength2,
	int * bResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle tabValue__ = 0;

	if (__exception)
		*__exception = 0;
	*tabValue = 0;
	*__tabValueLength1 = 0;
	*__tabValueLength2 = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: SFC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &SFC;

	// Pre-process parameter: tabValue
	__parameterTypeNames[1] = "System.String[,]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &tabValue__;

	// Pre-process parameter: bResultat
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = bResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Recuperation_Historique_Mouvement_SFC", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: tabValue
	if (tabValue__) {
		__errChk(CDotNetGetArrayElements(
			tabValue__, 
			CDOTNET_STRING, 
			0, 
			tabValue));
		__errChk(CDotNetGetArrayLength(
			tabValue__, 
			0, 
			__tabValueLength1));
		__errChk(CDotNetGetArrayLength(
			tabValue__, 
			1, 
			__tabValueLength2));
	}


__Error:
	if (tabValue__)
		CDotNetDiscardHandle(tabValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			tabValue, 
			CDOTNET_STRING, 
			2, 
			__tabValueLength1, 
			__tabValueLength2);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationCodeCloture(
	SCProduction_GestionProductions __instance,
	char * CodeNC,
	char *** secondaryNcCodes,
	ssize_t * __secondaryNcCodesLength1,
	ssize_t * __secondaryNcCodesLength2,
	int * Result,
	char ** sMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle secondaryNcCodes__ = 0;

	if (__exception)
		*__exception = 0;
	*secondaryNcCodes = 0;
	*__secondaryNcCodesLength1 = 0;
	*__secondaryNcCodesLength2 = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: CodeNC
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &CodeNC;

	// Pre-process parameter: secondaryNcCodes
	__parameterTypeNames[1] = "System.String[,]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &secondaryNcCodes__;

	// Pre-process parameter: Result
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = Result;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = sMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationCodeCloture", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: secondaryNcCodes
	if (secondaryNcCodes__) {
		__errChk(CDotNetGetArrayElements(
			secondaryNcCodes__, 
			CDOTNET_STRING, 
			0, 
			secondaryNcCodes));
		__errChk(CDotNetGetArrayLength(
			secondaryNcCodes__, 
			0, 
			__secondaryNcCodesLength1));
		__errChk(CDotNetGetArrayLength(
			secondaryNcCodes__, 
			1, 
			__secondaryNcCodesLength2));
	}


__Error:
	if (secondaryNcCodes__)
		CDotNetDiscardHandle(secondaryNcCodes__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			secondaryNcCodes, 
			CDOTNET_STRING, 
			2, 
			__secondaryNcCodesLength1, 
			__secondaryNcCodesLength2);
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];

	if (__exception)
		*__exception = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: indiceOp
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &indiceOp;

	// Pre-process parameter: Ressource
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &Ressource;

	// Pre-process parameter: strCodeErreur
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &strCodeErreur;

	// Pre-process parameter: strLibelleErreur
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &strLibelleErreur;

	// Pre-process parameter: datetime
	__parameterTypeNames[6] = "System.String";
	__parameterTypes[6] = (CDOTNET_STRING);
	__parameters[6] = &datetime;

	// Pre-process parameter: sequence
	__parameterTypeNames[7] = "System.Decimal";
	__parameterTypes[7] = (CDOTNET_DECIMAL);
	__parameters[7] = &sequence;

	// Pre-process parameter: bResultat
	__parameterTypeNames[8] = "System.Boolean&";
	__parameterTypes[8] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[8] = bResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[9] = "System.String&";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[9] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementNonConformiteCloture", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];
	CDotNetHandle stabMesures__ = 0;
	ssize_t __stabMesuresLengths[2];

	if (__exception)
		*__exception = 0;
	*sErreurMessage = 0;


	// Pre-process parameter: sNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &sNumSerie;

	// Pre-process parameter: operation
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &operation;

	// Pre-process parameter: ressource
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &ressource;

	// Pre-process parameter: OF
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &OF;

	// Pre-process parameter: stabMesures
	__stabMesuresLengths[0] = __stabMesuresLength1;
	__stabMesuresLengths[1] = __stabMesuresLength2;
	if (stabMesures)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			2, 
			0, 
			__stabMesuresLengths, 
			stabMesures, 
			&stabMesures__));
	__parameterTypeNames[4] = "System.String[,]";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[4] = &stabMesures__;

	// Pre-process parameter: bErreurSurvenue
	__parameterTypeNames[5] = "System.Boolean&";
	__parameterTypes[5] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[5] = bErreurSurvenue;

	// Pre-process parameter: sErreurMessage
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sErreurMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnregistrementTableauTestsMesures", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (stabMesures__)
		CDotNetDiscardHandle(stabMesures__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sErreurMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_RecuperationDetailleBom(
	SCProduction_GestionProductions __instance,
	char * Bom,
	char * indice,
	char *** TabbomComponentList,
	ssize_t * __TabbomComponentListLength,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle TabbomComponentList__ = 0;

	if (__exception)
		*__exception = 0;
	*TabbomComponentList = 0;
	*__TabbomComponentListLength = 0;
	*strMessage = 0;


	// Pre-process parameter: Bom
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &Bom;

	// Pre-process parameter: indice
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &indice;

	// Pre-process parameter: TabbomComponentList
	__parameterTypeNames[2] = "System.String[]&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[2] = &TabbomComponentList__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = blnResultat;

	// Pre-process parameter: strMessage
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RecuperationDetailleBom", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: TabbomComponentList
	if (TabbomComponentList__) {
		__errChk(CDotNetGetArrayElements(
			TabbomComponentList__, 
			CDOTNET_STRING, 
			0, 
			TabbomComponentList));
		__errChk(CDotNetGetArrayLength(
			TabbomComponentList__, 
			0, 
			__TabbomComponentListLength));
	}


__Error:
	if (TabbomComponentList__)
		CDotNetDiscardHandle(TabbomComponentList__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			TabbomComponentList, 
			CDOTNET_STRING, 
			1, 
			__TabbomComponentListLength);
		_CDotNetGenDisposeScalar(
			strMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_findInventory(
	SCProduction_GestionProductions __instance,
	char * inventoryId,
	char ** itemRef,
	char ** originalQty,
	char ** qtyOnHand,
	int * blnResultat,
	char ** strMessage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;
	*itemRef = 0;
	*originalQty = 0;
	*qtyOnHand = 0;
	*strMessage = 0;


	// Pre-process parameter: inventoryId
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &inventoryId;

	// Pre-process parameter: itemRef
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = itemRef;

	// Pre-process parameter: originalQty
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = originalQty;

	// Pre-process parameter: qtyOnHand
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = qtyOnHand;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[4] = "System.Boolean&";
	__parameterTypes[4] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[4] = blnResultat;

	// Pre-process parameter: strMessage
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = strMessage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"findInventory", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			itemRef, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			originalQty, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			qtyOnHand, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessage, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_AjoutStockComposant(
	SCProduction_GestionProductions __instance,
	char * strCodeComposant,
	char * strValeur,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strCodeComposant
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strCodeComposant;

	// Pre-process parameter: strValeur
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &strValeur;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[2] = "System.Boolean&";
	__parameterTypes[2] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[2] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AjoutStockComposant", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];
	CDotNetHandle TapProperty__ = 0;

	if (__exception)
		*__exception = 0;
	*next_operation = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strNumSerie
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strNumSerie;

	// Pre-process parameter: Ressource
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &Ressource;

	// Pre-process parameter: Operation
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &Operation;

	// Pre-process parameter: indiceOp
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &indiceOp;

	// Pre-process parameter: next_step
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &next_step;

	// Pre-process parameter: TapProperty
	if (TapProperty)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__TapPropertyLength, 
			TapProperty, 
			&TapProperty__));
	__parameterTypeNames[5] = "System.String[]";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[5] = &TapProperty__;

	// Pre-process parameter: bResult
	__parameterTypeNames[6] = "System.Boolean&";
	__parameterTypes[6] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[6] = bResult;

	// Pre-process parameter: next_operation
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = next_operation;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PASSE_WITH_NEXT_OPERATION", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (TapProperty__)
		CDotNetDiscardHandle(TapProperty__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			next_operation, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_AjoutStockComposant_Tableau(
	SCProduction_GestionProductions __instance,
	char ** tabAddInventory,
	ssize_t __tabAddInventoryLength1,
	ssize_t __tabAddInventoryLength2,
	int * blnResultat,
	char ** strMessageRetour,
	char ** codeDeRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle tabAddInventory__ = 0;
	ssize_t __tabAddInventoryLengths[2];

	if (__exception)
		*__exception = 0;
	*strMessageRetour = 0;
	*codeDeRetour = 0;


	// Pre-process parameter: tabAddInventory
	__tabAddInventoryLengths[0] = __tabAddInventoryLength1;
	__tabAddInventoryLengths[1] = __tabAddInventoryLength2;
	if (tabAddInventory)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			2, 
			0, 
			__tabAddInventoryLengths, 
			tabAddInventory, 
			&tabAddInventory__));
	__parameterTypeNames[0] = "System.String[,]";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[0] = &tabAddInventory__;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[1] = "System.Boolean&";
	__parameterTypes[1] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[1] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = strMessageRetour;

	// Pre-process parameter: codeDeRetour
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = codeDeRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AjoutStockComposant_Tableau", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (tabAddInventory__)
		CDotNetDiscardHandle(tabAddInventory__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			codeDeRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_GenerationSFC(
	SCProduction_GestionProductions __instance,
	char * strCodeComposant,
	char * indice,
	char ** SFC,
	int * blnResultat,
	char ** strMessageRetour,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;
	*SFC = 0;
	*strMessageRetour = 0;


	// Pre-process parameter: strCodeComposant
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strCodeComposant;

	// Pre-process parameter: indice
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &indice;

	// Pre-process parameter: SFC
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = SFC;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = blnResultat;

	// Pre-process parameter: strMessageRetour
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = strMessageRetour;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GenerationSFC", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			SFC, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			strMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SCProduction_GestionProductions_GenerationSFCdepuisOF(
	SCProduction_GestionProductions __instance,
	char * strOrdreFab,
	char ** strsfcRef,
	char ** sMessageRetour,
	int * blnResultat,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;
	*strsfcRef = 0;
	*sMessageRetour = 0;


	// Pre-process parameter: strOrdreFab
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &strOrdreFab;

	// Pre-process parameter: strsfcRef
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = strsfcRef;

	// Pre-process parameter: sMessageRetour
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = sMessageRetour;

	// Pre-process parameter: blnResultat
	__parameterTypeNames[3] = "System.Boolean&";
	__parameterTypes[3] = (CDOTNET_BOOLEAN | CDOTNET_OUT);
	__parameters[3] = blnResultat;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SCProduction.GestionProductions", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GenerationSFCdepuisOF", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			strsfcRef, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sMessageRetour, 
			CDOTNET_STRING);
	}
	return __error;
}



// Internal functions
static void _CDotNetGenDisposeScalar(void * scalar, unsigned int typeId)
{
	if (!*(void **)scalar)
		return;

	typeId &= CDOTNET_BASIC_TYPE_MASK;
	if (typeId == CDOTNET_STRING) {
		CDotNetFreeMemory(*(char **)scalar);
		*(char **)scalar = 0;
	}
	else if (typeId == CDOTNET_OBJECT || typeId == CDOTNET_STRUCT) {
		CDotNetDiscardHandle(*(CDotNetHandle *)scalar);
		*(CDotNetHandle *)scalar = 0;
	}
}

static void CVIFUNC_C _CDotNetGenDisposeArray(void * array, unsigned int typeId, size_t nDims, ...)
{
	size_t i;
	ssize_t totalLength = 1;
	va_list list;

	if (!*(void **)array)
		return;

	va_start(list, nDims);
	for (i = 0; i < nDims; ++i) {
		ssize_t * lenPtr = va_arg(list, ssize_t*);

		totalLength *= *lenPtr;
		*lenPtr = 0;
	}
	va_end(list);

	typeId &= CDOTNET_BASIC_TYPE_MASK;
	if (typeId == CDOTNET_STRING)
		while (--totalLength >= 0)
			CDotNetFreeMemory((*(char ***)array)[totalLength]);
	else if (typeId > CDOTNET_ENUM)
		while (--totalLength >= 0)
			CDotNetDiscardHandle((*(CDotNetHandle **)array)[totalLength]);

	CDotNetFreeMemory(*(void**)array);
	*(void**)array = 0;
}

