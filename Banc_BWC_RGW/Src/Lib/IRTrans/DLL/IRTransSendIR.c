// CVI wrapper source file for .NET assembly: IRTrans.SendIR, Version=1.0.7.29762, Culture=neutral, PublicKeyToken=null

#include "IRTransSendIR.h"

// Macros
#ifndef __errChk
#define __errChk(f) if (__error = (f), __error < 0) goto __Error; else
#endif
#ifndef __nullChk
#define __nullChk(p) if (!(p)) { __error = CDotNetOutOfMemoryError; goto __Error; } else
#endif

// Constants
static const char * __assemblyName = "IRTrans.SendIR, Version=1.0.7.29762, Culture=neutral, PublicKeyToken=null";

// Static Variables
static CDotNetAssemblyHandle __assemblyHandle = 0;

// Global Functions
int CVIFUNC Initialize_IRTrans_SendIR(void)
{
	int __error = 0;


	if (__assemblyHandle == 0)
		__errChk(CDotNetLoadAssembly(
			__assemblyName, 
			&__assemblyHandle));



__Error:
	return __error;
}

int CVIFUNC Close_IRTrans_SendIR(void)
{
	int __error = 0;


	if (__assemblyHandle) {
		__errChk(CDotNetDiscardAssemblyHandle(__assemblyHandle));
		__assemblyHandle = 0;
	}



__Error:
	return __error;
}


// Type: IRTrans.SendIR.SendIR
int CVIFUNC IRTrans_SendIR_SendIR_SendIRVisible(
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"IRTrans.SendIR.SendIR", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"SendIRVisible", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC IRTrans_SendIR_SendIR_ShowSendIR(
	IRTrans_NET_IRTransServer ir,
	System_Windows_Forms_Form parent,
	int xsize,
	int ysize,
	int resize,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: ir
	__parameterTypeNames[0] = "IRTrans.NET.IRTransServer,IRTrans.NET, Version=4.0.53.30768, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &ir;

	// Pre-process parameter: parent
	__parameterTypeNames[1] = "System.Windows.Forms.Form,System.Windows.Forms, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089";
	__parameterTypes[1] = (CDOTNET_OBJECT);
	__parameters[1] = &parent;

	// Pre-process parameter: xsize
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &xsize;

	// Pre-process parameter: ysize
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &ysize;

	// Pre-process parameter: resize
	__parameterTypeNames[4] = "System.Boolean";
	__parameterTypes[4] = (CDOTNET_BOOLEAN);
	__parameters[4] = &resize;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"IRTrans.SendIR.SendIR", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"ShowSendIR", 
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
	return __error;
}

int CVIFUNC IRTrans_SendIR_SendIR_SendIRDispose(
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"IRTrans.SendIR.SendIR", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"SendIRDispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}



