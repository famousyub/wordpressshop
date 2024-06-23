// CVI wrapper header file for .NET assembly: QteTestDLL, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null
//
// This is specified by the '__assemblyName' constant in the generated source file.
// If there are multiple versions of this assembly, and you want .NET to determine 
// the appropriate one to load, then you can remove the version, culture, and public 
// key token information from the constant and just specify the name of the assembly.
//
// If any assembly, including the target assembly, is not installed in the
// Global Assembly Cache (GAC) or in the application directory, and the wrapper
// code needs to load the assembly to convert types like arrays and enums, then
// you must register the path of the assembly with the CVI .NET library by
// calling CDotNetRegisterAssemblyPath before calling the wrapper code.

#include <cvidotnet.h>

#ifdef __cplusplus
extern "C" {
#endif

// Type definitions
typedef struct __QteTestDLL_QteTest * QteTestDLL_QteTest;




// Global Functions
int CVIFUNC Initialize_QteTestDLL(void);
int CVIFUNC Close_QteTestDLL(void);

// Type: QteTestDLL.QteTest
int CVIFUNC QteTestDLL_QteTest__Create(
	QteTestDLL_QteTest * __instance,
	CDotNetHandle * __exception);
int CVIFUNC QteTestDLL_QteTest_openCnxAQLM(
	QteTestDLL_QteTest __instance,
	char ** outputText,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC QteTestDLL_QteTest_closeCnxAQLM(
	QteTestDLL_QteTest __instance,
	char ** outputText,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC QteTestDLL_QteTest_insert(
	QteTestDLL_QteTest __instance,
	char * refProduit,
	char * Op_rationTest,
	int etat,
	char ** outputText,
	int * __returnValue,
	CDotNetHandle * __exception);


#ifdef __cplusplus
}
#endif
