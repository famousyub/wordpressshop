// CVI wrapper source file for .NET assembly: QteTestDLL, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null

#include "dllQteTest.h"

// Macros
#ifndef __errChk
#define __errChk(f) if (__error = (f), __error < 0) goto __Error; else
#endif
#ifndef __nullChk
#define __nullChk(p) if (!(p)) { __error = CDotNetOutOfMemoryError; goto __Error; } else
#endif

// Constants
static const char * __assemblyName = "QteTestDLL, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null";

// Static Variables
static CDotNetAssemblyHandle __assemblyHandle = 0;

// Forward declarations
static void _CDotNetGenDisposeScalar(void * scalar, unsigned int typeId);

// Global Functions
int CVIFUNC Initialize_QteTestDLL(void)
{
	int __error = 0;


	if (__assemblyHandle == 0)
		__errChk(CDotNetLoadAssembly(
			__assemblyName, 
			&__assemblyHandle));



__Error:
	return __error;
}

int CVIFUNC Close_QteTestDLL(void)
{
	int __error = 0;


	if (__assemblyHandle) {
		__errChk(CDotNetDiscardAssemblyHandle(__assemblyHandle));
		__assemblyHandle = 0;
	}



__Error:
	return __error;
}


// Type: QteTestDLL.QteTest
int CVIFUNC QteTestDLL_QteTest__Create(
	QteTestDLL_QteTest * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"QteTestDLL.QteTest", 
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

int CVIFUNC QteTestDLL_QteTest_openCnxAQLM(
	QteTestDLL_QteTest __instance,
	char ** outputText,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*outputText = 0;


	// Pre-process parameter: outputText
	__parameterTypeNames[0] = "System.String&";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[0] = outputText;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"QteTestDLL.QteTest", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"openCnxAQLM", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			outputText, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC QteTestDLL_QteTest_closeCnxAQLM(
	QteTestDLL_QteTest __instance,
	char ** outputText,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*outputText = 0;


	// Pre-process parameter: outputText
	__parameterTypeNames[0] = "System.String&";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[0] = outputText;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"QteTestDLL.QteTest", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"closeCnxAQLM", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			outputText, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC QteTestDLL_QteTest_insert(
	QteTestDLL_QteTest __instance,
	char * refProduit,
	char * Op_rationTest,
	int etat,
	char ** outputText,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*outputText = 0;


	// Pre-process parameter: refProduit
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &refProduit;

	// Pre-process parameter: Op_rationTest
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &Op_rationTest;

	// Pre-process parameter: etat
	__parameterTypeNames[2] = "System.Boolean";
	__parameterTypes[2] = (CDOTNET_BOOLEAN);
	__parameters[2] = &etat;

	// Pre-process parameter: outputText
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = outputText;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"QteTestDLL.QteTest", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"insert", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			outputText, 
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

