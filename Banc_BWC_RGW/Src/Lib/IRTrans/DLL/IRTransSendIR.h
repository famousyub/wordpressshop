// CVI wrapper header file for .NET assembly: IRTrans.SendIR, Version=1.0.7.29762, Culture=neutral, PublicKeyToken=null
//
// This is specified by the '__assemblyName' constant in the generated source file.
// If there are multiple versions of this assembly, and you want .NET to determine 
// the appropriate one to load, then you can remove the version, culture, and public 
// key token information from the constant and just specify the name of the assembly.
//
// Other assemblies referenced by the target assembly:
// Name: IRTrans.NET, Location: g:\CVI_Project\BTF\IRTrans\IRTRANS\DLL\IRTrans.NET.dll
// Name: System.Windows.Forms, Location: C:\Windows\Microsoft.Net\assembly\GAC_MSIL\System.Windows.Forms\v4.0_4.0.0.0__b77a5c561934e089\System.Windows.Forms.dll
//
// If any assembly, including the target assembly, is not installed in the
// Global Assembly Cache (GAC) or in the application directory, and the wrapper
// code needs to load the assembly to convert types like arrays and enums, then
// you must register the path of the assembly with the CVI .NET library by
// calling CDotNetRegisterAssemblyPath before calling the wrapper code.
//
// Types exposed by the target assembly but defined in other assemblies:
// CVI name: IRTrans_NET_IRTransServer, .NET name: IRTrans.NET.IRTransServer, Assembly: IRTrans.NET, Module: g:\CVI_Project\BTF\IRTrans\IRTRANS\DLL\IRTrans.NET.dll
// CVI name: System_Windows_Forms_Form, .NET name: System.Windows.Forms.Form, Assembly: System.Windows.Forms, Module: Global Assembly Cache

#include <cvidotnet.h>

#ifdef __cplusplus
extern "C" {
#endif

// Type definitions
typedef struct __IRTrans_SendIR_SendIR * IRTrans_SendIR_SendIR;
typedef struct __IRTrans_NET_IRTransServer * IRTrans_NET_IRTransServer;
typedef struct __System_Windows_Forms_Form * System_Windows_Forms_Form;




// Global Functions
int CVIFUNC Initialize_IRTrans_SendIR(void);
int CVIFUNC Close_IRTrans_SendIR(void);

// Type: IRTrans.SendIR.SendIR
int CVIFUNC IRTrans_SendIR_SendIR_SendIRVisible(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_SendIR_SendIR_ShowSendIR(
	IRTrans_NET_IRTransServer ir,
	System_Windows_Forms_Form parent,
	int xsize,
	int ysize,
	int resize,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_SendIR_SendIR_SendIRDispose(
	CDotNetHandle * __exception);


#ifdef __cplusplus
}
#endif
