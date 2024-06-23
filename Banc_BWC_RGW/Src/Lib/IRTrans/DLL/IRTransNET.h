// CVI wrapper header file for .NET assembly: IRTrans.NET, Version=4.0.53.30768, Culture=neutral, PublicKeyToken=null
//
// This is specified by the '__assemblyName' constant in the generated source file.
// If there are multiple versions of this assembly, and you want .NET to determine 
// the appropriate one to load, then you can remove the version, culture, and public 
// key token information from the constant and just specify the name of the assembly.
//
// Other assemblies referenced by the target assembly:
// Name: System, Location: C:\Windows\Microsoft.Net\assembly\GAC_MSIL\System\v4.0_4.0.0.0__b77a5c561934e089\System.dll
// Name: mscorlib, Location: C:\Windows\Microsoft.NET\Framework\v4.0.30319\mscorlib.dll
//
// If any assembly, including the target assembly, is not installed in the
// Global Assembly Cache (GAC) or in the application directory, and the wrapper
// code needs to load the assembly to convert types like arrays and enums, then
// you must register the path of the assembly with the CVI .NET library by
// calling CDotNetRegisterAssemblyPath before calling the wrapper code.
//
// Types exposed by the target assembly but defined in other assemblies:
// CVI name: System_Reflection_MethodInfo, .NET name: System.Reflection.MethodInfo, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_IAsyncResult, .NET name: System.IAsyncResult, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_AsyncCallback, .NET name: System.AsyncCallback, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Type, .NET name: System.Type, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_EventArgs, .NET name: System.EventArgs, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Exception, .NET name: System.Exception, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Runtime_Serialization_SerializationInfo, .NET name: System.Runtime.Serialization.SerializationInfo, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Net_Sockets_Socket, .NET name: System.Net.Sockets.Socket, Assembly: System, Module: Global Assembly Cache
// CVI name: System_Reflection_MethodBase, .NET name: System.Reflection.MethodBase, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Delegate, .NET name: System.Delegate, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Runtime_Serialization_StreamingContext, .NET name: System.Runtime.Serialization.StreamingContext, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Collections_IDictionary, .NET name: System.Collections.IDictionary, Assembly: mscorlib, Module: Global Assembly Cache

#include <cvidotnet.h>

#ifdef __cplusplus
extern "C" {
#endif

// Type definitions
typedef struct __IRTrans_NET_IRTransCommand * IRTrans_NET_IRTransCommand;
typedef struct __IRTrans_NET_CCFCommand * IRTrans_NET_CCFCommand;
typedef struct __IRTrans_NET_CCFLEARNCommand * IRTrans_NET_CCFLEARNCommand;
typedef struct __IRTrans_NET_CCFBinCommand * IRTrans_NET_CCFBinCommand;
typedef struct __IRTrans_NET_StatCommand * IRTrans_NET_StatCommand;
typedef struct __IRTrans_NET_NetworkCommand * IRTrans_NET_NetworkCommand;
typedef struct __IRTrans_NET_MacroCommand * IRTrans_NET_MacroCommand;
typedef struct __IRTrans_NET_RS232Command * IRTrans_NET_RS232Command;
typedef struct __IRTrans_NET_IRTransServer * IRTrans_NET_IRTransServer;
typedef struct __System_Net_Sockets_Socket * System_Net_Sockets_Socket;
typedef struct __IRTrans_NET_IRTransServer_IRReceiveEventHandler * IRTrans_NET_IRTransServer_IRReceiveEventHandler;
typedef struct __System_EventArgs * System_EventArgs;
typedef struct __System_Reflection_MethodInfo * System_Reflection_MethodInfo;
typedef struct __System_AsyncCallback * System_AsyncCallback;
typedef struct __System_IAsyncResult * System_IAsyncResult;
typedef struct __System_Runtime_Serialization_SerializationInfo * System_Runtime_Serialization_SerializationInfo;
typedef struct __System_Runtime_Serialization_StreamingContext * System_Runtime_Serialization_StreamingContext;
typedef struct __System_Delegate * System_Delegate;
typedef struct __IRTrans_NET_IRTransServer_ConnectionLostEventHandler * IRTrans_NET_IRTransServer_ConnectionLostEventHandler;
typedef struct __IRTrans_NET_BUSLINE * IRTrans_NET_BUSLINE;
typedef struct __IRTrans_NET_BUSBUFFER * IRTrans_NET_BUSBUFFER;
typedef struct __IRTrans_NET_HARDWAREINFO * IRTrans_NET_HARDWAREINFO;
typedef struct __IRTrans_NET_MODELINEEX * IRTrans_NET_MODELINEEX;
typedef struct __IRTrans_NET_MODEINFO * IRTrans_NET_MODEINFO;
typedef struct __IRTrans_NET_NETWORKMODEEX2 * IRTrans_NET_NETWORKMODEEX2;
typedef struct __IRTrans_NET_NETWORKMODEEX3 * IRTrans_NET_NETWORKMODEEX3;
typedef struct __IRTrans_NET_SYSPARMSTATUSBUFFER * IRTrans_NET_SYSPARMSTATUSBUFFER;
typedef struct __IRTrans_NET_MODELINE * IRTrans_NET_MODELINE;
typedef struct __IRTrans_NET_LANSTATUSBUFFER * IRTrans_NET_LANSTATUSBUFFER;
typedef struct __IRTrans_NET_WLANSTATUSBUFFER * IRTrans_NET_WLANSTATUSBUFFER;
typedef struct __IRTrans_NET_WLANBUFFER * IRTrans_NET_WLANBUFFER;
typedef struct __IRTrans_NET_FUNCTIONSTATUSEX * IRTrans_NET_FUNCTIONSTATUSEX;
typedef struct __IRTrans_NET_Capabilities * IRTrans_NET_Capabilities;
typedef struct __IRTrans_NET_IRDBModes * IRTrans_NET_IRDBModes;
typedef struct __IRTrans_NET_FileModes * IRTrans_NET_FileModes;
typedef struct __IRTrans_NET_RS232Modes * IRTrans_NET_RS232Modes;
typedef struct __IRTrans_NET_RS232ParameterValues * IRTrans_NET_RS232ParameterValues;
typedef struct __IRTrans_NET_DeviceModes * IRTrans_NET_DeviceModes;
typedef struct __IRTrans_NET_NETWORKLCDSTAT * IRTrans_NET_NETWORKLCDSTAT;
typedef struct __IRTrans_NET_NETWORKLEARN * IRTrans_NET_NETWORKLEARN;
typedef struct __IRTrans_NET_NETWORKSTATUS * IRTrans_NET_NETWORKSTATUS;
typedef struct __IRTrans_NET_FLASHSTATUS * IRTrans_NET_FLASHSTATUS;
typedef struct __IRTrans_NET_NETWORKRECV * IRTrans_NET_NETWORKRECV;
typedef struct __IRTrans_NET_REMOTELINE * IRTrans_NET_REMOTELINE;
typedef struct __IRTrans_NET_REMOTEBUFFER * IRTrans_NET_REMOTEBUFFER;
typedef struct __IRTrans_NET_FIRMWARELINE * IRTrans_NET_FIRMWARELINE;
typedef struct __IRTrans_NET_FIRMWAREBUFFER * IRTrans_NET_FIRMWAREBUFFER;
typedef struct __IRTrans_NET_COMMANDBUFFER * IRTrans_NET_COMMANDBUFFER;
typedef struct __IRTrans_NET_STATUSTYPE * IRTrans_NET_STATUSTYPE;
typedef struct __IRTrans_NET_STATUSINFO * IRTrans_NET_STATUSINFO;
typedef struct __IRTrans_NET_ANALOG_CONFIG_COMMAND * IRTrans_NET_ANALOG_CONFIG_COMMAND;
typedef struct __IRTrans_NET_ANALOGSTATUS * IRTrans_NET_ANALOGSTATUS;
typedef struct __IRTrans_NET_DEVICEINFO * IRTrans_NET_DEVICEINFO;
typedef struct __IRTrans_NET_DEVICELISTEX * IRTrans_NET_DEVICELISTEX;
typedef struct __IRTrans_NET_NETWORKLEARNSTAT * IRTrans_NET_NETWORKLEARNSTAT;
typedef struct __IRTrans_NET_TRANSLATECOMMAND * IRTrans_NET_TRANSLATECOMMAND;
typedef struct __IRTrans_NET_TRANSLATEBUFFER * IRTrans_NET_TRANSLATEBUFFER;
typedef struct __IRTrans_NET_MODECOMMANDEX3 * IRTrans_NET_MODECOMMANDEX3;
typedef struct __IRTrans_NET_MODECOMMANDEX * IRTrans_NET_MODECOMMANDEX;
typedef struct __IRTrans_NET_WLANCONFIGCOMMAND * IRTrans_NET_WLANCONFIGCOMMAND;
typedef struct __IRTrans_NET_SYSPARAMCOMMAND * IRTrans_NET_SYSPARAMCOMMAND;
typedef struct __IRTrans_NET_LcdCommand * IRTrans_NET_LcdCommand;
typedef struct __IRTrans_NET_IRTransConnectionException * IRTrans_NET_IRTransConnectionException;
typedef struct __System_Exception * System_Exception;
typedef struct __System_Collections_IDictionary * System_Collections_IDictionary;
typedef struct __System_Reflection_MethodBase * System_Reflection_MethodBase;
typedef struct __System_Type * System_Type;
typedef struct __IRTrans_NET_IRDBHEADER * IRTrans_NET_IRDBHEADER;
typedef struct __IRTrans_NET_IRDBCOMMAND * IRTrans_NET_IRDBCOMMAND;
typedef struct __IRTrans_NET_IRDBSTATUS * IRTrans_NET_IRDBSTATUS;
typedef struct __IRTrans_NET_IRDBBUFFER * IRTrans_NET_IRDBBUFFER;
typedef struct __IRTrans_NET_IRDBHEADERBUFFER * IRTrans_NET_IRDBHEADERBUFFER;


typedef int (CVICALLBACK * IRTrans_NET_IRTransServer_IRReceiveEventHandler__Callback_t)(void * callbackData,
		CDotNetHandle sender,
		System_EventArgs e,
		IRTrans_NET_NETWORKRECV recv);
typedef int (CVICALLBACK * IRTrans_NET_IRTransServer_ConnectionLostEventHandler__Callback_t)(void * callbackData,
		CDotNetHandle sender,
		System_EventArgs e);


// Global Functions
int CVIFUNC Initialize_IRTrans_NET(void);
int CVIFUNC Close_IRTrans_NET(void);

// Type: IRTrans.NET.IRTransCommand
int CVIFUNC IRTrans_NET_IRTransCommand__Create(
	IRTrans_NET_IRTransCommand * __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Create_1(
	IRTrans_NET_IRTransCommand * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand_Get_Size(
	IRTrans_NET_IRTransCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand_toByte(
	IRTrans_NET_IRTransCommand __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__netcommand(
	IRTrans_NET_IRTransCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Set__netcommand(
	IRTrans_NET_IRTransCommand __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__mode(
	IRTrans_NET_IRTransCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Set__mode(
	IRTrans_NET_IRTransCommand __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__timeout(
	IRTrans_NET_IRTransCommand __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Set__timeout(
	IRTrans_NET_IRTransCommand __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__adress(
	IRTrans_NET_IRTransCommand __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Set__adress(
	IRTrans_NET_IRTransCommand __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__protocol_version(
	IRTrans_NET_IRTransCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Set__protocol_version(
	IRTrans_NET_IRTransCommand __instance,
	int protocol_version,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SEND(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LRNREM(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LRNTIM(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LRNCOM(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__CLOSE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__RESEND(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LRNRAW(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LRNRPT(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LRNTOG(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SETSTAT(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LRNLONG(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LRNRAWRPT(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__RELOAD(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LCD(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LEARNSTAT(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__TEMP(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__GETREMOTES(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__GETCOMMANDS(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STORETRANS(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LOADTRANS(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SAVETRANS(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__FLASHTRANS(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__FUNCTIONS(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__TESTCOM(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LONGSEND(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SHUTDOWN(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SENDCCF(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LCDINIT(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SETSWITCH(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUSEX(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__RESET(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__DEVICEDATA(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STARTCLOCK(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LCDSTATUS(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__FUNCTIONEX(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__MCE_CHARS(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__DELETECOM(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SETSTAT2(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUSEXN(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STOREIRDB(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__FLASHIRDB(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SAVEIRDB(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LOADIRDB(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__TRANSFILE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__IRDBFILE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LISTBUS(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SENDCCFSTR(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LEARNDIRECT(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__TESTCOMEX(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SETSTATEX(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__DELETEREM(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__READ_ANALOG(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SEND_RS232(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LEARNCCF(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUSEX2(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SETSTATEX2(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LEARNRS232(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SEND_MASK(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SSIDLIST(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__WLANPARAM(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STOREWLAN(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__READ_SYSPARAM(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__WRITE_SYSPARAM(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LANPARAM(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LOGLEVEL(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LEARNLINK(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SEND_MACRO(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__READ_ANALOG_EX(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__MODE_NO_RECEIVE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__CLEARFLASH(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUSEX3(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SETSTATEX3(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SET_ANALOGLEVEL(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__GET_IRCODE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__SET_IRCODE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUSEX3_SHORT(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__LISTFIRMWARE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__FLASHFIRMWARE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_MESSAGE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_TIMING(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_DEVICEMODE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_RECEIVE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_LEARN(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_REMOTELIST(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_COMMANDLIST(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_TRANSLATE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_FUNCTION(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_DEVICEMODEEX(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_DEVICEDATA(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_FUNCTIONEX(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_DEVICEMODEEXN(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_IRDB(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_TRANSLATIONFILE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_IRDBFILE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_BUSLIST(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_LEARNDIRECT(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_IRDBFLASH(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_ANALOGINPUT(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_DEVICEMODEEX2(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_SSIDLIST(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_WLANPARAMETER(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_SYSPARAMETER(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_LANPARAMETER(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_ANALOGINPUT_EX(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_DEVICEMODEEX3(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_FIRMWARELIST(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_FIRMWAREFLASH(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransCommand__Get__STATUS_TIMEOUT(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.CCFCommand
int CVIFUNC IRTrans_NET_CCFCommand__Create(
	IRTrans_NET_CCFCommand * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand_Get_Size(
	IRTrans_NET_CCFCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand_toByte(
	IRTrans_NET_CCFCommand __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand__Get__ccf_data(
	IRTrans_NET_CCFCommand __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand__Set__ccf_data(
	IRTrans_NET_CCFCommand __instance,
	char * ccf_data,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand__Get__repeatcommand(
	IRTrans_NET_CCFCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand__Set__repeatcommand(
	IRTrans_NET_CCFCommand __instance,
	unsigned char repeatcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand__Get__netcommand(
	IRTrans_NET_CCFCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand__Set__netcommand(
	IRTrans_NET_CCFCommand __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand__Get__mode(
	IRTrans_NET_CCFCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand__Set__mode(
	IRTrans_NET_CCFCommand __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand__Get__timeout(
	IRTrans_NET_CCFCommand __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand__Set__timeout(
	IRTrans_NET_CCFCommand __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand__Get__adress(
	IRTrans_NET_CCFCommand __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand__Set__adress(
	IRTrans_NET_CCFCommand __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand__Get__protocol_version(
	IRTrans_NET_CCFCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFCommand__Set__protocol_version(
	IRTrans_NET_CCFCommand __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.CCFLEARNCommand
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Create(
	IRTrans_NET_CCFLEARNCommand * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand_Get_Size(
	IRTrans_NET_CCFLEARNCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand_toByte(
	IRTrans_NET_CCFLEARNCommand __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Get__remote(
	IRTrans_NET_CCFLEARNCommand __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Set__remote(
	IRTrans_NET_CCFLEARNCommand __instance,
	char * remote,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Get__command(
	IRTrans_NET_CCFLEARNCommand __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Set__command(
	IRTrans_NET_CCFLEARNCommand __instance,
	char * command,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Get__ccf(
	IRTrans_NET_CCFLEARNCommand __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Set__ccf(
	IRTrans_NET_CCFLEARNCommand __instance,
	char * ccf,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Get__netcommand(
	IRTrans_NET_CCFLEARNCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Set__netcommand(
	IRTrans_NET_CCFLEARNCommand __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Get__mode(
	IRTrans_NET_CCFLEARNCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Set__mode(
	IRTrans_NET_CCFLEARNCommand __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Get__timeout(
	IRTrans_NET_CCFLEARNCommand __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Set__timeout(
	IRTrans_NET_CCFLEARNCommand __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Get__adress(
	IRTrans_NET_CCFLEARNCommand __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Set__adress(
	IRTrans_NET_CCFLEARNCommand __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Get__protocol_version(
	IRTrans_NET_CCFLEARNCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFLEARNCommand__Set__protocol_version(
	IRTrans_NET_CCFLEARNCommand __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.CCFBinCommand
int CVIFUNC IRTrans_NET_CCFBinCommand__Create(
	IRTrans_NET_CCFBinCommand * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFBinCommand_Get_Size(
	IRTrans_NET_CCFBinCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFBinCommand_toByte(
	IRTrans_NET_CCFBinCommand __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFBinCommand__Get__ccf_data(
	IRTrans_NET_CCFBinCommand __instance,
	unsigned short ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFBinCommand__Set__ccf_data(
	IRTrans_NET_CCFBinCommand __instance,
	unsigned short * ccf_data,
	ssize_t __ccf_dataLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFBinCommand__Get__netcommand(
	IRTrans_NET_CCFBinCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFBinCommand__Set__netcommand(
	IRTrans_NET_CCFBinCommand __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFBinCommand__Get__mode(
	IRTrans_NET_CCFBinCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFBinCommand__Set__mode(
	IRTrans_NET_CCFBinCommand __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFBinCommand__Get__timeout(
	IRTrans_NET_CCFBinCommand __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFBinCommand__Set__timeout(
	IRTrans_NET_CCFBinCommand __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFBinCommand__Get__adress(
	IRTrans_NET_CCFBinCommand __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFBinCommand__Set__adress(
	IRTrans_NET_CCFBinCommand __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFBinCommand__Get__protocol_version(
	IRTrans_NET_CCFBinCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_CCFBinCommand__Set__protocol_version(
	IRTrans_NET_CCFBinCommand __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.StatCommand
int CVIFUNC IRTrans_NET_StatCommand__Create(
	IRTrans_NET_StatCommand * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_StatCommand_Get_Size(
	IRTrans_NET_StatCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_StatCommand_toByte(
	IRTrans_NET_StatCommand __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_StatCommand__Get__netcommand(
	IRTrans_NET_StatCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_StatCommand__Set__netcommand(
	IRTrans_NET_StatCommand __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_StatCommand__Get__mode(
	IRTrans_NET_StatCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_StatCommand__Set__mode(
	IRTrans_NET_StatCommand __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_StatCommand__Get__timeout(
	IRTrans_NET_StatCommand __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_StatCommand__Set__timeout(
	IRTrans_NET_StatCommand __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_StatCommand__Get__adress(
	IRTrans_NET_StatCommand __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_StatCommand__Set__adress(
	IRTrans_NET_StatCommand __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_StatCommand__Get__protocol_version(
	IRTrans_NET_StatCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_StatCommand__Set__protocol_version(
	IRTrans_NET_StatCommand __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.NetworkCommand
int CVIFUNC IRTrans_NET_NetworkCommand__Create(
	IRTrans_NET_NetworkCommand * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Create_1(
	IRTrans_NET_NetworkCommand * __instance,
	unsigned char netcommand,
	int bin,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand_Get_Size(
	IRTrans_NET_NetworkCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand_toByte(
	IRTrans_NET_NetworkCommand __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Get__transmit_freq(
	IRTrans_NET_NetworkCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Set__transmit_freq(
	IRTrans_NET_NetworkCommand __instance,
	unsigned char transmit_freq,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Get__remote_binary(
	IRTrans_NET_NetworkCommand __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Set__remote_binary(
	IRTrans_NET_NetworkCommand __instance,
	unsigned char * remote_binary,
	ssize_t __remote_binaryLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Get__remote(
	IRTrans_NET_NetworkCommand __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Set__remote(
	IRTrans_NET_NetworkCommand __instance,
	char * remote,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Get__command(
	IRTrans_NET_NetworkCommand __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Set__command(
	IRTrans_NET_NetworkCommand __instance,
	char * command,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Get__netcommand(
	IRTrans_NET_NetworkCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Set__netcommand(
	IRTrans_NET_NetworkCommand __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Get__mode(
	IRTrans_NET_NetworkCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Set__mode(
	IRTrans_NET_NetworkCommand __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Get__timeout(
	IRTrans_NET_NetworkCommand __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Set__timeout(
	IRTrans_NET_NetworkCommand __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Get__adress(
	IRTrans_NET_NetworkCommand __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Set__adress(
	IRTrans_NET_NetworkCommand __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Get__protocol_version(
	IRTrans_NET_NetworkCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NetworkCommand__Set__protocol_version(
	IRTrans_NET_NetworkCommand __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.MacroCommand
int CVIFUNC IRTrans_NET_MacroCommand__Create(
	IRTrans_NET_MacroCommand * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand_Get_Size(
	IRTrans_NET_MacroCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand_toByte(
	IRTrans_NET_MacroCommand __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Get__remote(
	IRTrans_NET_MacroCommand __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Set__remote(
	IRTrans_NET_MacroCommand __instance,
	char * remote,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Get__command(
	IRTrans_NET_MacroCommand __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Set__command(
	IRTrans_NET_MacroCommand __instance,
	char * command,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Get__pause(
	IRTrans_NET_MacroCommand __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Set__pause(
	IRTrans_NET_MacroCommand __instance,
	unsigned short pause,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Get__netcommand(
	IRTrans_NET_MacroCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Set__netcommand(
	IRTrans_NET_MacroCommand __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Get__mode(
	IRTrans_NET_MacroCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Set__mode(
	IRTrans_NET_MacroCommand __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Get__timeout(
	IRTrans_NET_MacroCommand __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Set__timeout(
	IRTrans_NET_MacroCommand __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Get__adress(
	IRTrans_NET_MacroCommand __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Set__adress(
	IRTrans_NET_MacroCommand __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Get__protocol_version(
	IRTrans_NET_MacroCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MacroCommand__Set__protocol_version(
	IRTrans_NET_MacroCommand __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.RS232Command
int CVIFUNC IRTrans_NET_RS232Command__Create(
	IRTrans_NET_RS232Command * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command_Get_Size(
	IRTrans_NET_RS232Command __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command_toByte(
	IRTrans_NET_RS232Command __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Get__len(
	IRTrans_NET_RS232Command __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Set__len(
	IRTrans_NET_RS232Command __instance,
	unsigned char len,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Get__adr(
	IRTrans_NET_RS232Command __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Set__adr(
	IRTrans_NET_RS232Command __instance,
	unsigned char adr,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Get__parameter(
	IRTrans_NET_RS232Command __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Set__parameter(
	IRTrans_NET_RS232Command __instance,
	unsigned char parameter,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Get__data(
	IRTrans_NET_RS232Command __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Set__data(
	IRTrans_NET_RS232Command __instance,
	unsigned char * data,
	ssize_t __dataLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Get__netcommand(
	IRTrans_NET_RS232Command __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Set__netcommand(
	IRTrans_NET_RS232Command __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Get__mode(
	IRTrans_NET_RS232Command __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Set__mode(
	IRTrans_NET_RS232Command __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Get__timeout(
	IRTrans_NET_RS232Command __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Set__timeout(
	IRTrans_NET_RS232Command __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Get__adress(
	IRTrans_NET_RS232Command __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Set__adress(
	IRTrans_NET_RS232Command __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Get__protocol_version(
	IRTrans_NET_RS232Command __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Command__Set__protocol_version(
	IRTrans_NET_RS232Command __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.IRTransServer
int CVIFUNC IRTrans_NET_IRTransServer__Create(
	IRTrans_NET_IRTransServer * __instance,
	char * server,
	int port,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer__Create_1(
	IRTrans_NET_IRTransServer * __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer__Create_2(
	IRTrans_NET_IRTransServer * __instance,
	char * server,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getSocket(
	IRTrans_NET_IRTransServer __instance,
	System_Net_Sockets_Socket * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_add_IRReceive(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_IRTransServer_IRReceiveEventHandler value,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_remove_IRReceive(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_IRTransServer_IRReceiveEventHandler value,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_add_ConnectionLost(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_IRTransServer_ConnectionLostEventHandler value,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_remove_ConnectionLost(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_IRTransServer_ConnectionLostEventHandler value,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ReceiveIRCode(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_NETWORKRECV * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_StopAsyncReceiver(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_StartAsnycReceiver(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_Close(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ReadStatusType(
	IRTrans_NET_IRTransServer __instance,
	unsigned char stype,
	int timeout,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_DeleteRemote(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendNetworkCommand(
	IRTrans_NET_IRTransServer __instance,
	unsigned char netcommand,
	char * remote,
	char * command,
	unsigned int adrval,
	unsigned short timeout,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_Dispose(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SaveIRDB(
	IRTrans_NET_IRTransServer __instance,
	char * name,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_FlashIRDB(
	IRTrans_NET_IRTransServer __instance,
	unsigned short bus,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ClearFlash(
	IRTrans_NET_IRTransServer __instance,
	unsigned short bus,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ReadFlashStatus(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_readIRDBHeader(
	IRTrans_NET_IRTransServer __instance,
	char * nm,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_readIRDBCommands(
	IRTrans_NET_IRTransServer __instance,
	unsigned int offset,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendIRDBHeader(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_IRDBHEADER irh,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendIRDBCommand(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_IRDBCOMMAND irdb,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getIRDBFiles(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_flashHTMLPages(
	IRTrans_NET_IRTransServer __instance,
	char * filenames,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getHTMLFilenames(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getSYSParameter(
	IRTrans_NET_IRTransServer __instance,
	unsigned char bus,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getSSIDInfo(
	IRTrans_NET_IRTransServer __instance,
	unsigned char bus,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getLANParameter(
	IRTrans_NET_IRTransServer __instance,
	unsigned char bus,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getWLANParameter(
	IRTrans_NET_IRTransServer __instance,
	unsigned char bus,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getDeviceStatus(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_GetDeviceModeEx(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_GetDeviceModeEx3(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_GetDeviceModeEx3Short(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getBusinfo(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSendCCF(
	IRTrans_NET_IRTransServer __instance,
	char * ccfdata,
	int repeatcommand,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSendCCF_1(
	IRTrans_NET_IRTransServer __instance,
	char * ccfdata,
	int repeatcommand,
	unsigned int addressmask,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSendCCF_2(
	IRTrans_NET_IRTransServer __instance,
	char * ccfdata,
	int repeatcommand,
	unsigned int addressmask,
	unsigned char ledSel,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSendCCFBin(
	IRTrans_NET_IRTransServer __instance,
	unsigned short * ccfdata,
	ssize_t __ccfdataLength,
	int repeatcommand,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSendCCFBin_1(
	IRTrans_NET_IRTransServer __instance,
	unsigned short * ccfdata,
	ssize_t __ccfdataLength,
	int repeatcommand,
	unsigned int addressmask,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSendCCFBin_2(
	IRTrans_NET_IRTransServer __instance,
	unsigned short * ccfdata,
	ssize_t __ccfdataLength,
	int repeatcommand,
	unsigned int addressmask,
	unsigned char ledSel,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSend(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSend_1(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	unsigned int addressmask,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSend_2(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	unsigned int addressmask,
	unsigned char ledSel,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSendCCF_3(
	IRTrans_NET_IRTransServer __instance,
	char * ccfdata,
	int repeatcommand,
	unsigned int addressmask,
	unsigned char ledSel,
	unsigned char bus,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSendCCFBin_3(
	IRTrans_NET_IRTransServer __instance,
	unsigned short * ccfdata,
	ssize_t __ccfdataLength,
	int repeatcommand,
	unsigned int addressmask,
	unsigned char ledSel,
	unsigned char bus,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSendMacroLED(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	unsigned char bus,
	unsigned char ledSel,
	unsigned short macro_pause,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSendMacro(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	unsigned int busmask,
	unsigned int ledmask,
	unsigned short macro_pause,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSendMask(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	unsigned int busmask,
	unsigned int ledmask,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSendMask_1(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	unsigned __int64 busmask,
	unsigned int ledmask,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRSend_3(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	unsigned int addressmask,
	unsigned char ledSel,
	unsigned char bus,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRRepeat(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendRS232(
	IRTrans_NET_IRTransServer __instance,
	char * data,
	unsigned char port,
	unsigned char bus,
	unsigned char mask,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendRS232_1(
	IRTrans_NET_IRTransServer __instance,
	char * data,
	unsigned char port,
	unsigned char bus,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendRS232_2(
	IRTrans_NET_IRTransServer __instance,
	char * data,
	unsigned char bus,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendRS232_3(
	IRTrans_NET_IRTransServer __instance,
	unsigned char * data,
	ssize_t __dataLength,
	unsigned char bus,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendRS232_4(
	IRTrans_NET_IRTransServer __instance,
	unsigned char * data,
	ssize_t __dataLength,
	unsigned char port,
	unsigned char bus,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendRS232_5(
	IRTrans_NET_IRTransServer __instance,
	unsigned char * data,
	ssize_t __dataLength,
	unsigned char port,
	unsigned char bus,
	unsigned char mask,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_LearnIRRaw(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_LearnIRRaw_1(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	unsigned short timeout,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_LearnIRRaw_2(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	unsigned short timeout,
	int bus,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_LearnIR(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_LearnIR_1(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	unsigned short timeout,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_LearnIR_2(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	unsigned short timeout,
	int bus,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_LearnRS232(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	char * data,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendCCFLearnCommand(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_CCFLEARNCommand lc,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_LearnIRData(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_LearnIRData_1(
	IRTrans_NET_IRTransServer __instance,
	int bus,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getIRData(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_LearnIRData_2(
	IRTrans_NET_IRTransServer __instance,
	unsigned short timeout,
	int bus,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getLearnStatus(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendNetworkLearnCommand(
	IRTrans_NET_IRTransServer __instance,
	unsigned char netcommand,
	char * remote,
	char * command,
	unsigned int adrval,
	unsigned short timeout,
	unsigned char freq,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_FlashFirmware(
	IRTrans_NET_IRTransServer __instance,
	char * fw_file,
	char * upgrade_key,
	unsigned char bus,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ReloadDatabase(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ResetDevice(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SetLoglevel(
	IRTrans_NET_IRTransServer __instance,
	unsigned char loglevel,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_GetDevicelist(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_GetCommandlist(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_GetFirmwareFiles(
	IRTrans_NET_IRTransServer __instance,
	unsigned char bus,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_GetRemotelist(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getAnalogInput(
	IRTrans_NET_IRTransServer __instance,
	unsigned char bus,
	unsigned short cnt,
	unsigned char mode,
	CDotNetHandle id,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getAnalogInput_1(
	IRTrans_NET_IRTransServer __instance,
	unsigned char bus,
	unsigned short cnt,
	CDotNetHandle id,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getAnalogSensorIDs(
	IRTrans_NET_IRTransServer __instance,
	unsigned char bus,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendAnalogLevelCommand(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_ANALOG_CONFIG_COMMAND ac,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getAnalogInput_2(
	IRTrans_NET_IRTransServer __instance,
	unsigned char bus,
	unsigned short mask,
	unsigned char mode,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_GetDeviceData(
	IRTrans_NET_IRTransServer __instance,
	char * remote,
	char * command,
	unsigned char * data,
	ssize_t __dataLength,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SaveTranslation(
	IRTrans_NET_IRTransServer __instance,
	char * name,
	unsigned int savemode,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_FlashTranslation(
	IRTrans_NET_IRTransServer __instance,
	unsigned short bus,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ReadTranslationStatus(
	IRTrans_NET_IRTransServer __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendTranslation(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_TRANSLATECOMMAND tr,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_readTranslations(
	IRTrans_NET_IRTransServer __instance,
	char * name,
	unsigned int offset,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_getTranslatorFiles(
	IRTrans_NET_IRTransServer __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendModeCommand(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_MODECOMMANDEX mc,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendModeCommand_1(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_MODECOMMANDEX3 mc,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendSysConfig(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_SYSPARAMCOMMAND sysp,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SendWIFIMode(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_WLANCONFIGCOMMAND wlan,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SetMCESpecialChars(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_StartClock(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_setDisplayText(
	IRTrans_NET_IRTransServer __instance,
	char * text,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_setDisplayText_1(
	IRTrans_NET_IRTransServer __instance,
	unsigned char * text,
	ssize_t __textLength,
	IRTrans_NET_NETWORKSTATUS * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_InitLCDBuffer(
	IRTrans_NET_IRTransServer __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SetLCDBuffer(
	IRTrans_NET_IRTransServer __instance,
	unsigned char * dest,
	ssize_t __destLength,
	int row,
	int col,
	char * sourc,
	int len,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SetLCDBuffer_1(
	IRTrans_NET_IRTransServer __instance,
	unsigned char * dest,
	ssize_t __destLength,
	int row,
	int col,
	char * sourc,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SetLCDBuffer_2(
	IRTrans_NET_IRTransServer __instance,
	unsigned char * dest,
	ssize_t __destLength,
	int off,
	char * sourc,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_SetLCDBuffer_3(
	IRTrans_NET_IRTransServer __instance,
	unsigned char * dest,
	ssize_t __destLength,
	int off,
	char * sourc,
	int len,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_GetLCDInfo(
	IRTrans_NET_IRTransServer __instance,
	IRTrans_NET_NETWORKLCDSTAT * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.IRTransServer+IRReceiveEventHandler
int CVIFUNC IRTrans_NET_IRTransServer_IRReceiveEventHandler__Create(
	IRTrans_NET_IRTransServer_IRReceiveEventHandler * __instance,
	IRTrans_NET_IRTransServer_IRReceiveEventHandler__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRReceiveEventHandler_Get_Method(
	IRTrans_NET_IRTransServer_IRReceiveEventHandler __instance,
	System_Reflection_MethodInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRReceiveEventHandler_Get_Target(
	IRTrans_NET_IRTransServer_IRReceiveEventHandler __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRReceiveEventHandler_Invoke(
	IRTrans_NET_IRTransServer_IRReceiveEventHandler __instance,
	CDotNetHandle sender,
	System_EventArgs e,
	IRTrans_NET_NETWORKRECV recv,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRReceiveEventHandler_BeginInvoke(
	IRTrans_NET_IRTransServer_IRReceiveEventHandler __instance,
	CDotNetHandle sender,
	System_EventArgs e,
	IRTrans_NET_NETWORKRECV recv,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRReceiveEventHandler_EndInvoke(
	IRTrans_NET_IRTransServer_IRReceiveEventHandler __instance,
	System_IAsyncResult result,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRReceiveEventHandler_GetObjectData(
	IRTrans_NET_IRTransServer_IRReceiveEventHandler __instance,
	System_Runtime_Serialization_SerializationInfo info,
	System_Runtime_Serialization_StreamingContext context,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRReceiveEventHandler_Equals(
	IRTrans_NET_IRTransServer_IRReceiveEventHandler __instance,
	CDotNetHandle obj,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRReceiveEventHandler_GetInvocationList(
	IRTrans_NET_IRTransServer_IRReceiveEventHandler __instance,
	System_Delegate ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRReceiveEventHandler_GetHashCode(
	IRTrans_NET_IRTransServer_IRReceiveEventHandler __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRReceiveEventHandler_DynamicInvoke(
	IRTrans_NET_IRTransServer_IRReceiveEventHandler __instance,
	CDotNetHandle * args,
	ssize_t __argsLength,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_IRReceiveEventHandler_Clone(
	IRTrans_NET_IRTransServer_IRReceiveEventHandler __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.IRTransServer+ConnectionLostEventHandler
int CVIFUNC IRTrans_NET_IRTransServer_ConnectionLostEventHandler__Create(
	IRTrans_NET_IRTransServer_ConnectionLostEventHandler * __instance,
	IRTrans_NET_IRTransServer_ConnectionLostEventHandler__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ConnectionLostEventHandler_Get_Method(
	IRTrans_NET_IRTransServer_ConnectionLostEventHandler __instance,
	System_Reflection_MethodInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ConnectionLostEventHandler_Get_Target(
	IRTrans_NET_IRTransServer_ConnectionLostEventHandler __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ConnectionLostEventHandler_Invoke(
	IRTrans_NET_IRTransServer_ConnectionLostEventHandler __instance,
	CDotNetHandle sender,
	System_EventArgs e,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ConnectionLostEventHandler_BeginInvoke(
	IRTrans_NET_IRTransServer_ConnectionLostEventHandler __instance,
	CDotNetHandle sender,
	System_EventArgs e,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ConnectionLostEventHandler_EndInvoke(
	IRTrans_NET_IRTransServer_ConnectionLostEventHandler __instance,
	System_IAsyncResult result,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ConnectionLostEventHandler_GetObjectData(
	IRTrans_NET_IRTransServer_ConnectionLostEventHandler __instance,
	System_Runtime_Serialization_SerializationInfo info,
	System_Runtime_Serialization_StreamingContext context,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ConnectionLostEventHandler_Equals(
	IRTrans_NET_IRTransServer_ConnectionLostEventHandler __instance,
	CDotNetHandle obj,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ConnectionLostEventHandler_GetInvocationList(
	IRTrans_NET_IRTransServer_ConnectionLostEventHandler __instance,
	System_Delegate ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ConnectionLostEventHandler_GetHashCode(
	IRTrans_NET_IRTransServer_ConnectionLostEventHandler __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ConnectionLostEventHandler_DynamicInvoke(
	IRTrans_NET_IRTransServer_ConnectionLostEventHandler __instance,
	CDotNetHandle * args,
	ssize_t __argsLength,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransServer_ConnectionLostEventHandler_Clone(
	IRTrans_NET_IRTransServer_ConnectionLostEventHandler __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.BUSLINE
int CVIFUNC IRTrans_NET_BUSLINE__Create(
	IRTrans_NET_BUSLINE * __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Get__capabilities(
	IRTrans_NET_BUSLINE __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Set__capabilities(
	IRTrans_NET_BUSLINE __instance,
	unsigned int capabilities,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Get__capabilities2(
	IRTrans_NET_BUSLINE __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Set__capabilities2(
	IRTrans_NET_BUSLINE __instance,
	unsigned int capabilities2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Get__capabilities3(
	IRTrans_NET_BUSLINE __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Set__capabilities3(
	IRTrans_NET_BUSLINE __instance,
	unsigned int capabilities3,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Get__capabilities4(
	IRTrans_NET_BUSLINE __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Set__capabilities4(
	IRTrans_NET_BUSLINE __instance,
	unsigned int capabilities4,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Get__name(
	IRTrans_NET_BUSLINE __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Set__name(
	IRTrans_NET_BUSLINE __instance,
	char * name,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Get__version(
	IRTrans_NET_BUSLINE __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Set__version(
	IRTrans_NET_BUSLINE __instance,
	char * version,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Get__extended_mode(
	IRTrans_NET_BUSLINE __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Set__extended_mode(
	IRTrans_NET_BUSLINE __instance,
	unsigned char extended_mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Get__extended_mode2(
	IRTrans_NET_BUSLINE __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Set__extended_mode2(
	IRTrans_NET_BUSLINE __instance,
	unsigned char extended_mode2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Get__extended_mode_ex(
	IRTrans_NET_BUSLINE __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSLINE__Set__extended_mode_ex(
	IRTrans_NET_BUSLINE __instance,
	unsigned char * extended_mode_ex,
	ssize_t __extended_mode_exLength,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.BUSBUFFER
int CVIFUNC IRTrans_NET_BUSBUFFER__Create(
	IRTrans_NET_BUSBUFFER * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSBUFFER__Get__offset(
	IRTrans_NET_BUSBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSBUFFER__Set__offset(
	IRTrans_NET_BUSBUFFER __instance,
	short offset,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSBUFFER__Get__count_buffer(
	IRTrans_NET_BUSBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSBUFFER__Set__count_buffer(
	IRTrans_NET_BUSBUFFER __instance,
	short count_buffer,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSBUFFER__Get__count_total(
	IRTrans_NET_BUSBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSBUFFER__Set__count_total(
	IRTrans_NET_BUSBUFFER __instance,
	short count_total,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSBUFFER__Get__count_remaining(
	IRTrans_NET_BUSBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSBUFFER__Set__count_remaining(
	IRTrans_NET_BUSBUFFER __instance,
	short count_remaining,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSBUFFER__Get__bus(
	IRTrans_NET_BUSBUFFER __instance,
	IRTrans_NET_BUSLINE ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_BUSBUFFER__Set__bus(
	IRTrans_NET_BUSBUFFER __instance,
	IRTrans_NET_BUSLINE * bus,
	ssize_t __busLength,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.HARDWAREINFO
int CVIFUNC IRTrans_NET_HARDWAREINFO__Create(
	IRTrans_NET_HARDWAREINFO * __instance,
	IRTrans_NET_MODELINEEX source,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Get__BaseDevice(
	IRTrans_NET_HARDWAREINFO __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Set__BaseDevice(
	IRTrans_NET_HARDWAREINFO __instance,
	char * BaseDevice,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Get__DeviceVersion(
	IRTrans_NET_HARDWAREINFO __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Set__DeviceVersion(
	IRTrans_NET_HARDWAREINFO __instance,
	char * DeviceVersion,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Get__InternalReceivers(
	IRTrans_NET_HARDWAREINFO __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Set__InternalReceivers(
	IRTrans_NET_HARDWAREINFO __instance,
	char ** InternalReceivers,
	ssize_t __InternalReceiversLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Get__IP(
	IRTrans_NET_HARDWAREINFO __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Set__IP(
	IRTrans_NET_HARDWAREINFO __instance,
	char * IP,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Get__MAC(
	IRTrans_NET_HARDWAREINFO __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Set__MAC(
	IRTrans_NET_HARDWAREINFO __instance,
	char * MAC,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Get__Outputs(
	IRTrans_NET_HARDWAREINFO __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Set__Outputs(
	IRTrans_NET_HARDWAREINFO __instance,
	char * Outputs,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Get__Features(
	IRTrans_NET_HARDWAREINFO __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Set__Features(
	IRTrans_NET_HARDWAREINFO __instance,
	char * Features,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Get__LANVersion(
	IRTrans_NET_HARDWAREINFO __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Set__LANVersion(
	IRTrans_NET_HARDWAREINFO __instance,
	char * LANVersion,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Get__IRVersion(
	IRTrans_NET_HARDWAREINFO __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_HARDWAREINFO__Set__IRVersion(
	IRTrans_NET_HARDWAREINFO __instance,
	char * IRVersion,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.MODELINEEX
int CVIFUNC IRTrans_NET_MODELINEEX__Create(
	IRTrans_NET_MODELINEEX * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Create_1(
	IRTrans_NET_MODELINEEX * __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__send_mask(
	IRTrans_NET_MODELINEEX __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__send_mask(
	IRTrans_NET_MODELINEEX __instance,
	unsigned int send_mask,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__device_mode(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__device_mode(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char device_mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__extended_mode(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__extended_mode(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char extended_mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__extended_mode2(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__extended_mode2(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char extended_mode2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__switch_mode(
	IRTrans_NET_MODELINEEX __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__switch_mode(
	IRTrans_NET_MODELINEEX __instance,
	unsigned short switch_mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__switch_mode2(
	IRTrans_NET_MODELINEEX __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__switch_mode2(
	IRTrans_NET_MODELINEEX __instance,
	unsigned short switch_mode2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__features(
	IRTrans_NET_MODELINEEX __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__features(
	IRTrans_NET_MODELINEEX __instance,
	unsigned int features,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__features2(
	IRTrans_NET_MODELINEEX __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__features2(
	IRTrans_NET_MODELINEEX __instance,
	unsigned int features2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__features3(
	IRTrans_NET_MODELINEEX __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__features3(
	IRTrans_NET_MODELINEEX __instance,
	unsigned int features3,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__features4(
	IRTrans_NET_MODELINEEX __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__features4(
	IRTrans_NET_MODELINEEX __instance,
	unsigned int features4,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__extended_mode_ex(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__extended_mode_ex(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char * extended_mode_ex,
	ssize_t __extended_mode_exLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__extended_mode_ex2(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__extended_mode_ex2(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char * extended_mode_ex2,
	ssize_t __extended_mode_ex2Length,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__rs232_mode(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__rs232_mode(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char * rs232_mode,
	ssize_t __rs232_modeLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__status_mode(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__status_mode(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char * status_mode,
	ssize_t __status_modeLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__status_value(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__status_value(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char * status_value,
	ssize_t __status_valueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__status_flags(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__status_flags(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char * status_flags,
	ssize_t __status_flagsLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__extended_mode3(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__extended_mode3(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char extended_mode3,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__extended_mode4(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__extended_mode4(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char extended_mode4,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__version(
	IRTrans_NET_MODELINEEX __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__version(
	IRTrans_NET_MODELINEEX __instance,
	char * version,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__remote(
	IRTrans_NET_MODELINEEX __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__remote(
	IRTrans_NET_MODELINEEX __instance,
	char * remote,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__command(
	IRTrans_NET_MODELINEEX __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__command(
	IRTrans_NET_MODELINEEX __instance,
	char * command,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__remote2(
	IRTrans_NET_MODELINEEX __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__remote2(
	IRTrans_NET_MODELINEEX __instance,
	char * remote2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__command2(
	IRTrans_NET_MODELINEEX __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__command2(
	IRTrans_NET_MODELINEEX __instance,
	char * command2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__poweron_mac(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__poweron_mac(
	IRTrans_NET_MODELINEEX __instance,
	unsigned char * poweron_mac,
	ssize_t __poweron_macLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Get__lanversion(
	IRTrans_NET_MODELINEEX __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINEEX__Set__lanversion(
	IRTrans_NET_MODELINEEX __instance,
	char * lanversion,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.MODEINFO
int CVIFUNC IRTrans_NET_MODEINFO__Create(
	IRTrans_NET_MODEINFO * __instance,
	int count,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODEINFO__Get__stat(
	IRTrans_NET_MODEINFO __instance,
	IRTrans_NET_MODELINEEX ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODEINFO__Set__stat(
	IRTrans_NET_MODEINFO __instance,
	IRTrans_NET_MODELINEEX * stat,
	ssize_t __statLength1,
	ssize_t __statLength2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODEINFO__Get__devadr(
	IRTrans_NET_MODEINFO __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODEINFO__Set__devadr(
	IRTrans_NET_MODEINFO __instance,
	unsigned char * devadr,
	ssize_t __devadrLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODEINFO__Get__count(
	IRTrans_NET_MODEINFO __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODEINFO__Set__count(
	IRTrans_NET_MODEINFO __instance,
	unsigned short count,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.NETWORKMODEEX2
int CVIFUNC IRTrans_NET_NETWORKMODEEX2__Create(
	IRTrans_NET_NETWORKMODEEX2 * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX2__Get__adress(
	IRTrans_NET_NETWORKMODEEX2 __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX2__Set__adress(
	IRTrans_NET_NETWORKMODEEX2 __instance,
	unsigned short adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX2__Get__offset(
	IRTrans_NET_NETWORKMODEEX2 __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX2__Set__offset(
	IRTrans_NET_NETWORKMODEEX2 __instance,
	unsigned char offset,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX2__Get__count(
	IRTrans_NET_NETWORKMODEEX2 __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX2__Set__count(
	IRTrans_NET_NETWORKMODEEX2 __instance,
	unsigned char count,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX2__Get__dev_adr(
	IRTrans_NET_NETWORKMODEEX2 __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX2__Set__dev_adr(
	IRTrans_NET_NETWORKMODEEX2 __instance,
	unsigned char * dev_adr,
	ssize_t __dev_adrLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX2__Get__stat(
	IRTrans_NET_NETWORKMODEEX2 __instance,
	IRTrans_NET_MODELINEEX ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX2__Set__stat(
	IRTrans_NET_NETWORKMODEEX2 __instance,
	IRTrans_NET_MODELINEEX * stat,
	ssize_t __statLength1,
	ssize_t __statLength2,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.NETWORKMODEEX3
int CVIFUNC IRTrans_NET_NETWORKMODEEX3__Create(
	IRTrans_NET_NETWORKMODEEX3 * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	int len,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX3__Get__adress(
	IRTrans_NET_NETWORKMODEEX3 __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX3__Set__adress(
	IRTrans_NET_NETWORKMODEEX3 __instance,
	unsigned short adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX3__Get__offset(
	IRTrans_NET_NETWORKMODEEX3 __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX3__Set__offset(
	IRTrans_NET_NETWORKMODEEX3 __instance,
	unsigned char offset,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX3__Get__count(
	IRTrans_NET_NETWORKMODEEX3 __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX3__Set__count(
	IRTrans_NET_NETWORKMODEEX3 __instance,
	unsigned char count,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX3__Get__dev_adr(
	IRTrans_NET_NETWORKMODEEX3 __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX3__Set__dev_adr(
	IRTrans_NET_NETWORKMODEEX3 __instance,
	unsigned char * dev_adr,
	ssize_t __dev_adrLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX3__Get__stat(
	IRTrans_NET_NETWORKMODEEX3 __instance,
	IRTrans_NET_MODELINEEX ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKMODEEX3__Set__stat(
	IRTrans_NET_NETWORKMODEEX3 __instance,
	IRTrans_NET_MODELINEEX * stat,
	ssize_t __statLength1,
	ssize_t __statLength2,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.SYSPARMSTATUSBUFFER
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Create(
	IRTrans_NET_SYSPARMSTATUSBUFFER * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Get__access_ip(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Set__access_ip(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char ** access_ip,
	ssize_t __access_ipLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Get__access_mask(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Set__access_mask(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char ** access_mask,
	ssize_t __access_maskLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Get__ir_relay_from(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Set__ir_relay_from(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char ** ir_relay_from,
	ssize_t __ir_relay_fromLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Get__ir_relay_to(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Set__ir_relay_to(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char ** ir_relay_to,
	ssize_t __ir_relay_toLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Get__ir_relay_led(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Set__ir_relay_led(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	unsigned char * ir_relay_led,
	ssize_t __ir_relay_ledLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Get__udp_str_adr(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Set__udp_str_adr(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char * udp_str_adr,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Get__wakeonlan_mac(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Set__wakeonlan_mac(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char * wakeonlan_mac,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Get__password(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Set__password(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char * password,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Get__broadcast_relay(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Set__broadcast_relay(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	unsigned char broadcast_relay,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Get__udp_port(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Set__udp_port(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char * udp_port,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Get__tz(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Set__tz(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	unsigned char tz,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Get__ntp_ip(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARMSTATUSBUFFER__Set__ntp_ip(
	IRTrans_NET_SYSPARMSTATUSBUFFER __instance,
	char * ntp_ip,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.MODELINE
int CVIFUNC IRTrans_NET_MODELINE__Create(
	IRTrans_NET_MODELINE * __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Get__send_mask(
	IRTrans_NET_MODELINE __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Set__send_mask(
	IRTrans_NET_MODELINE __instance,
	unsigned int send_mask,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Get__device_mode(
	IRTrans_NET_MODELINE __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Set__device_mode(
	IRTrans_NET_MODELINE __instance,
	unsigned char device_mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Get__extended_mode(
	IRTrans_NET_MODELINE __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Set__extended_mode(
	IRTrans_NET_MODELINE __instance,
	unsigned char extended_mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Get__extended_mode2(
	IRTrans_NET_MODELINE __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Set__extended_mode2(
	IRTrans_NET_MODELINE __instance,
	unsigned char extended_mode2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Get__switch_mode(
	IRTrans_NET_MODELINE __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Set__switch_mode(
	IRTrans_NET_MODELINE __instance,
	unsigned short switch_mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Get__switch_mode2(
	IRTrans_NET_MODELINE __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Set__switch_mode2(
	IRTrans_NET_MODELINE __instance,
	unsigned short switch_mode2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Get__features(
	IRTrans_NET_MODELINE __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Set__features(
	IRTrans_NET_MODELINE __instance,
	unsigned int features,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Get__extended_mode3(
	IRTrans_NET_MODELINE __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Set__extended_mode3(
	IRTrans_NET_MODELINE __instance,
	unsigned char extended_mode3,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Get__extended_mode4(
	IRTrans_NET_MODELINE __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Set__extended_mode4(
	IRTrans_NET_MODELINE __instance,
	unsigned char extended_mode4,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Get__version(
	IRTrans_NET_MODELINE __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Set__version(
	IRTrans_NET_MODELINE __instance,
	char * version,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Get__remote(
	IRTrans_NET_MODELINE __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Set__remote(
	IRTrans_NET_MODELINE __instance,
	char * remote,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Get__command(
	IRTrans_NET_MODELINE __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Set__command(
	IRTrans_NET_MODELINE __instance,
	char * command,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Get__remote2(
	IRTrans_NET_MODELINE __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Set__remote2(
	IRTrans_NET_MODELINE __instance,
	char * remote2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Get__command2(
	IRTrans_NET_MODELINE __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODELINE__Set__command2(
	IRTrans_NET_MODELINE __instance,
	char * command2,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.LANSTATUSBUFFER
int CVIFUNC IRTrans_NET_LANSTATUSBUFFER__Create(
	IRTrans_NET_LANSTATUSBUFFER * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LANSTATUSBUFFER__Get__ip_adr(
	IRTrans_NET_LANSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LANSTATUSBUFFER__Set__ip_adr(
	IRTrans_NET_LANSTATUSBUFFER __instance,
	char * ip_adr,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LANSTATUSBUFFER__Get__ip_netmask(
	IRTrans_NET_LANSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LANSTATUSBUFFER__Set__ip_netmask(
	IRTrans_NET_LANSTATUSBUFFER __instance,
	char * ip_netmask,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LANSTATUSBUFFER__Get__ip_gateway(
	IRTrans_NET_LANSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LANSTATUSBUFFER__Set__ip_gateway(
	IRTrans_NET_LANSTATUSBUFFER __instance,
	char * ip_gateway,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LANSTATUSBUFFER__Get__dhcp_flag(
	IRTrans_NET_LANSTATUSBUFFER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LANSTATUSBUFFER__Set__dhcp_flag(
	IRTrans_NET_LANSTATUSBUFFER __instance,
	unsigned char dhcp_flag,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LANSTATUSBUFFER__Get__speed_flag(
	IRTrans_NET_LANSTATUSBUFFER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LANSTATUSBUFFER__Set__speed_flag(
	IRTrans_NET_LANSTATUSBUFFER __instance,
	unsigned char speed_flag,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LANSTATUSBUFFER__Get__mac_adr(
	IRTrans_NET_LANSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LANSTATUSBUFFER__Set__mac_adr(
	IRTrans_NET_LANSTATUSBUFFER __instance,
	char * mac_adr,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.WLANSTATUSBUFFER
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Create(
	IRTrans_NET_WLANSTATUSBUFFER * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__ip_adr(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__ip_adr(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	char * ip_adr,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__ip_netmask(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__ip_netmask(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	char * ip_netmask,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__ip_gateway(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__ip_gateway(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	char * ip_gateway,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__ntp_server(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__ntp_server(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	char * ntp_server,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__dhcp_flag(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__dhcp_flag(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char dhcp_flag,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__wpa_key(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__wpa_key(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	char * wpa_key,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__wlan_ssid(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__wlan_ssid(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	char * wlan_ssid,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__wlan_channel(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__wlan_channel(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char wlan_channel,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__wlan_speed(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__wlan_speed(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char wlan_speed,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__wlan_power(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__wlan_power(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char wlan_power,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__wlan_mode(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__wlan_mode(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char wlan_mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__wlan_security(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__wlan_security(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char wlan_security,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__connected_mode(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__connected_mode(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char connected_mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__connected_rssi(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__connected_rssi(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char connected_rssi,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__connected_if(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__connected_if(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char connected_if,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__timezone(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__timezone(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	unsigned char timezone,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Get__mac_adr(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANSTATUSBUFFER__Set__mac_adr(
	IRTrans_NET_WLANSTATUSBUFFER __instance,
	char * mac_adr,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.WLANBUFFER
int CVIFUNC IRTrans_NET_WLANBUFFER__Create(
	IRTrans_NET_WLANBUFFER * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	unsigned char len,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANBUFFER__Create_1(
	IRTrans_NET_WLANBUFFER * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANBUFFER__Get__offset(
	IRTrans_NET_WLANBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANBUFFER__Set__offset(
	IRTrans_NET_WLANBUFFER __instance,
	short offset,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANBUFFER__Get__count_buffer(
	IRTrans_NET_WLANBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANBUFFER__Set__count_buffer(
	IRTrans_NET_WLANBUFFER __instance,
	short count_buffer,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANBUFFER__Get__count_total(
	IRTrans_NET_WLANBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANBUFFER__Set__count_total(
	IRTrans_NET_WLANBUFFER __instance,
	short count_total,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANBUFFER__Get__count_remaining(
	IRTrans_NET_WLANBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANBUFFER__Set__count_remaining(
	IRTrans_NET_WLANBUFFER __instance,
	short count_remaining,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANBUFFER__Get__WLAN_SSID(
	IRTrans_NET_WLANBUFFER __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANBUFFER__Set__WLAN_SSID(
	IRTrans_NET_WLANBUFFER __instance,
	char ** WLAN_SSID,
	ssize_t __WLAN_SSIDLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANBUFFER__Get__WLAN_type(
	IRTrans_NET_WLANBUFFER __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANBUFFER__Set__WLAN_type(
	IRTrans_NET_WLANBUFFER __instance,
	unsigned char * WLAN_type,
	ssize_t __WLAN_typeLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANBUFFER__Get__WLAN_rssi(
	IRTrans_NET_WLANBUFFER __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANBUFFER__Set__WLAN_rssi(
	IRTrans_NET_WLANBUFFER __instance,
	unsigned char * WLAN_rssi,
	ssize_t __WLAN_rssiLength,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.FUNCTIONSTATUSEX
int CVIFUNC IRTrans_NET_FUNCTIONSTATUSEX__Create(
	IRTrans_NET_FUNCTIONSTATUSEX * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FUNCTIONSTATUSEX__Get__serno(
	IRTrans_NET_FUNCTIONSTATUSEX __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FUNCTIONSTATUSEX__Set__serno(
	IRTrans_NET_FUNCTIONSTATUSEX __instance,
	unsigned int serno,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FUNCTIONSTATUSEX__Get__functions(
	IRTrans_NET_FUNCTIONSTATUSEX __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FUNCTIONSTATUSEX__Set__functions(
	IRTrans_NET_FUNCTIONSTATUSEX __instance,
	unsigned int functions,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FUNCTIONSTATUSEX__Get__version(
	IRTrans_NET_FUNCTIONSTATUSEX __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FUNCTIONSTATUSEX__Set__version(
	IRTrans_NET_FUNCTIONSTATUSEX __instance,
	char * version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.Capabilities
int CVIFUNC IRTrans_NET_Capabilities__Create(
	IRTrans_NET_Capabilities * __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_IR(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_SBUS(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_SER(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_USB(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_POWERON(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_SW_SEL_EXT(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_B_O(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_TEMP(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_SOFTID(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_EEPROM(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_TRANSL(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_HWCARR(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_DUALRCV(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_SBUS_UART(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_FLASH128(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_DUALSND(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_BOOTLOADER(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_DUALPOWERON(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_USBWAKEUP(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_NOSCROLL(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_LAN(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_IRDB(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_MULTIRELAY4(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_MULTISEND4(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_MULTISEND8(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_MULTISEND2(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN_HTML(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_FUNCTIONVAL2(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_EXT_RCV(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_ONEWIRE(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_PULSE200(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_V38(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_RECS80(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_PULSELEN_18(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_SW_RCV_SEL(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_RTS_CTS(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_MULTIRELAY2(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_DUTYCYCLE(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_SBUS_SEND(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_USB_WAKEUP(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_STATEIO_SBUS(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_STATEIO_ANALOG(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_RS232_IO_SBUS(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_RS232_OUT_IR(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_AUX_RS232(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_RS232_PARAMETER(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_EXTRS232_PARAMETER(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_MULTISEND16(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_STATEIO_IRIN(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_SW_SEL_EXT_LOW(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_IRIN_EXTRA_LINE(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_RELAY_SBUS(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_EXT_HI_LO_SINGLE(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_RC5_FREE_TIMING(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_INTERNAL_PLASMA(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_HF_BLASTER(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_RS232_IN_IR(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN2_RS232_UDP_RELAY(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_DUAL_RCV_EXTERNAL(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_WLAN(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_MULTISTREAM(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_VAR_SEND_POWER(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_NO_RECEIVE(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_ONE_WIRE_IR1(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_ONE_WIRE_IR2(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_ONE_WIRE_ANALOG1(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_ONE_WIRE_ANALOG2(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_IRIN_ANALOG(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_TRANSLATOR_IRDB(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_ANALOG_LEVEL(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_STATEIO_AUX(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_ONE_WIRE_AUX(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_RS232_OUT_IR2(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_RS232_OUT_IR4(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_RS232_ANALOG2(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_RS232_IRIN1(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_RS232_IRIN2(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN3_MULTI_RS232(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_MASK(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_OTHER(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_USB_3_6(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_USB_3_8(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_TRANS_2_0(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_TRANS_3_2(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_TRANS_XL(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_LAN_1_2(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_LAN_2_2(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_LAN_2_3(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_LAN_3(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_MICRO_WIFI(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_LANIO_1_5(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_LANIO_CTL_1_5(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_RS232_3_6(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_RS232_3_8(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_BUS_3_5(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_BUS_3_8(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_WIFI_1_5(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_LANC(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_LANC_XL(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_LANC_XXL(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_LANC_MS_16(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_OEM(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_LAN_2_64(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_LANC_XL_V2(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_LANCTRL_V2(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_Capabilities__Get__FN4_DEVICETYPE_LANC_MS_V2(
	unsigned int * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.IRDBModes
int CVIFUNC IRTrans_NET_IRDBModes__Create(
	IRTrans_NET_IRDBModes * __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBModes__Get__IRDB_REMOTE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBModes__Get__IRDB_HEADER(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBModes__Get__IRDB_ACTION(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBModes__Get__IRDB_ACTION_1(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBModes__Get__IRDB_ACTION_2(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBModes__Get__IRDB_ACTION_3(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBModes__Get__IRDB_ACTION_4(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBModes__Get__IRDB_ACTION_5(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBModes__Get__IRDB_ACTION_6(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBModes__Get__IRDB_ACTION_7(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBModes__Get__IRDB_HEADER_OVERWRITE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBModes__Get__IRDB_HEADER_32K(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBModes__Get__IRDB_HEADER_64K(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBModes__Get__IRDB_HEADER_96K(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.FileModes
int CVIFUNC IRTrans_NET_FileModes__Create(
	IRTrans_NET_FileModes * __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FileModes__Get__FILE_MODE_SAVE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FileModes__Get__FILE_MODE_SAVEAS(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FileModes__Get__FILE_MODE_OVERWRITE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.RS232Modes
int CVIFUNC IRTrans_NET_RS232Modes__Create(
	IRTrans_NET_RS232Modes * __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__INPUT(
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__OUTPUT(
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__IO(
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__OFF(
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__PARITY(
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__DATABITS(
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__STOPBITS(
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__RTS_CTS(
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__AUX(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__SBUS(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__IR_INPUT_1(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__IR_INPUT_2(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__ANALOG_1(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__ANALOG_2(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__IR_OUTPUT_1(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__IR_OUTPUT_2(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__IR_OUTPUT_3(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232Modes__Get__IR_OUTPUT_4(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.RS232ParameterValues
int CVIFUNC IRTrans_NET_RS232ParameterValues__Create(
	IRTrans_NET_RS232ParameterValues * __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__BAUDRATE_MASK_SMALL(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__BAUDRATE_MASK(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__BAUDRATE_OFF(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__BAUDRATE_4800(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__BAUDRATE_9600(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__BAUDRATE_19200(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__BAUDRATE_38400(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__BAUDRATE_57600(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__BAUDRATE_115200(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__STOPBITS(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__PARITY_MASK(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__PARITY_NONE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__PARITY_EVEN(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__PARITY_ODD(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__DATABITS(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_RS232ParameterValues__Get__INPUT(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.DeviceModes
int CVIFUNC IRTrans_NET_DeviceModes__Create(
	IRTrans_NET_DeviceModes * __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DeviceModes__Get__DEVMODE_SEND(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DeviceModes__Get__DEVMODE_IR(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DeviceModes__Get__DEVMODE_SBUS(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DeviceModes__Get__DEVMODE_IRCODE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DeviceModes__Get__DEVMODE_SBUSCODE(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DeviceModes__Get__DEVMODE_RAW(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DeviceModes__Get__DEVMODE_RAWFAST(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DeviceModes__Get__DEVMODE_REPEAT(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.NETWORKLCDSTAT
int CVIFUNC IRTrans_NET_NETWORKLCDSTAT__Create(
	IRTrans_NET_NETWORKLCDSTAT * __instance,
	unsigned char * content,
	ssize_t __contentLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLCDSTAT__Get__adress(
	IRTrans_NET_NETWORKLCDSTAT __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLCDSTAT__Set__adress(
	IRTrans_NET_NETWORKLCDSTAT __instance,
	short adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLCDSTAT__Get__netstatus(
	IRTrans_NET_NETWORKLCDSTAT __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLCDSTAT__Set__netstatus(
	IRTrans_NET_NETWORKLCDSTAT __instance,
	unsigned short netstatus,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLCDSTAT__Get__statuslevel(
	IRTrans_NET_NETWORKLCDSTAT __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLCDSTAT__Set__statuslevel(
	IRTrans_NET_NETWORKLCDSTAT __instance,
	unsigned short statuslevel,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLCDSTAT__Get__numcol(
	IRTrans_NET_NETWORKLCDSTAT __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLCDSTAT__Set__numcol(
	IRTrans_NET_NETWORKLCDSTAT __instance,
	unsigned char numcol,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLCDSTAT__Get__numrows(
	IRTrans_NET_NETWORKLCDSTAT __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLCDSTAT__Set__numrows(
	IRTrans_NET_NETWORKLCDSTAT __instance,
	unsigned char numrows,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLCDSTAT__Get__clockflag(
	IRTrans_NET_NETWORKLCDSTAT __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLCDSTAT__Set__clockflag(
	IRTrans_NET_NETWORKLCDSTAT __instance,
	int clockflag,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLCDSTAT__Get__advanced_lcd(
	IRTrans_NET_NETWORKLCDSTAT __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLCDSTAT__Set__advanced_lcd(
	IRTrans_NET_NETWORKLCDSTAT __instance,
	int advanced_lcd,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.NETWORKLEARN
int CVIFUNC IRTrans_NET_NETWORKLEARN__Create(
	IRTrans_NET_NETWORKLEARN * __instance,
	unsigned char * content,
	ssize_t __contentLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARN__Get__adress(
	IRTrans_NET_NETWORKLEARN __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARN__Set__adress(
	IRTrans_NET_NETWORKLEARN __instance,
	short adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARN__Get__commandlen(
	IRTrans_NET_NETWORKLEARN __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARN__Set__commandlen(
	IRTrans_NET_NETWORKLEARN __instance,
	short commandlen,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARN__Get__data(
	IRTrans_NET_NETWORKLEARN __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARN__Set__data(
	IRTrans_NET_NETWORKLEARN __instance,
	unsigned char * data,
	ssize_t __dataLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARN__Get__size(
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.NETWORKSTATUS
int CVIFUNC IRTrans_NET_NETWORKSTATUS__Create(
	IRTrans_NET_NETWORKSTATUS * __instance,
	unsigned char * content,
	ssize_t __contentLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKSTATUS__Create_1(
	IRTrans_NET_NETWORKSTATUS * __instance,
	unsigned short netstat,
	unsigned short stlevel,
	char * msg,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKSTATUS__Get__adress(
	IRTrans_NET_NETWORKSTATUS __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKSTATUS__Set__adress(
	IRTrans_NET_NETWORKSTATUS __instance,
	short adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKSTATUS__Get__netstatus(
	IRTrans_NET_NETWORKSTATUS __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKSTATUS__Set__netstatus(
	IRTrans_NET_NETWORKSTATUS __instance,
	unsigned short netstatus,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKSTATUS__Get__statuslevel(
	IRTrans_NET_NETWORKSTATUS __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKSTATUS__Set__statuslevel(
	IRTrans_NET_NETWORKSTATUS __instance,
	unsigned short statuslevel,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKSTATUS__Get__message(
	IRTrans_NET_NETWORKSTATUS __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKSTATUS__Set__message(
	IRTrans_NET_NETWORKSTATUS __instance,
	char * message,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKSTATUS__Get__size(
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.FLASHSTATUS
int CVIFUNC IRTrans_NET_FLASHSTATUS__Create(
	IRTrans_NET_FLASHSTATUS * __instance,
	unsigned char * content,
	ssize_t __contentLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FLASHSTATUS__Create_1(
	IRTrans_NET_FLASHSTATUS * __instance,
	unsigned short netstat,
	unsigned short stlevel,
	char * msg,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FLASHSTATUS__Get__adress(
	IRTrans_NET_FLASHSTATUS __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FLASHSTATUS__Set__adress(
	IRTrans_NET_FLASHSTATUS __instance,
	short adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FLASHSTATUS__Get__netstatus(
	IRTrans_NET_FLASHSTATUS __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FLASHSTATUS__Set__netstatus(
	IRTrans_NET_FLASHSTATUS __instance,
	unsigned short netstatus,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FLASHSTATUS__Get__statuslevel(
	IRTrans_NET_FLASHSTATUS __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FLASHSTATUS__Set__statuslevel(
	IRTrans_NET_FLASHSTATUS __instance,
	unsigned short statuslevel,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FLASHSTATUS__Get__message(
	IRTrans_NET_FLASHSTATUS __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FLASHSTATUS__Set__message(
	IRTrans_NET_FLASHSTATUS __instance,
	char * message,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FLASHSTATUS__Get__size(
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.NETWORKRECV
int CVIFUNC IRTrans_NET_NETWORKRECV__Create(
	IRTrans_NET_NETWORKRECV * __instance,
	unsigned char * content,
	ssize_t __contentLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKRECV__Get__adress(
	IRTrans_NET_NETWORKRECV __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKRECV__Set__adress(
	IRTrans_NET_NETWORKRECV __instance,
	short adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKRECV__Get__COMMAND_num(
	IRTrans_NET_NETWORKRECV __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKRECV__Set__COMMAND_num(
	IRTrans_NET_NETWORKRECV __instance,
	unsigned short COMMAND_num,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKRECV__Get__remote(
	IRTrans_NET_NETWORKRECV __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKRECV__Set__remote(
	IRTrans_NET_NETWORKRECV __instance,
	char * remote,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKRECV__Get__command(
	IRTrans_NET_NETWORKRECV __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKRECV__Set__command(
	IRTrans_NET_NETWORKRECV __instance,
	char * command,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKRECV__Get__data(
	IRTrans_NET_NETWORKRECV __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKRECV__Set__data(
	IRTrans_NET_NETWORKRECV __instance,
	char * data,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKRECV__Get__size(
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.REMOTELINE
int CVIFUNC IRTrans_NET_REMOTELINE__Create(
	IRTrans_NET_REMOTELINE * __instance,
	unsigned char * content,
	ssize_t __contentLength,
	int offset,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTELINE__Get__target_mask(
	IRTrans_NET_REMOTELINE __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTELINE__Set__target_mask(
	IRTrans_NET_REMOTELINE __instance,
	unsigned int target_mask,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTELINE__Get__source_mask(
	IRTrans_NET_REMOTELINE __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTELINE__Set__source_mask(
	IRTrans_NET_REMOTELINE __instance,
	unsigned int source_mask,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTELINE__Get__name(
	IRTrans_NET_REMOTELINE __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTELINE__Set__name(
	IRTrans_NET_REMOTELINE __instance,
	char * name,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTELINE__Get__size(
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.REMOTEBUFFER
int CVIFUNC IRTrans_NET_REMOTEBUFFER__Create(
	IRTrans_NET_REMOTEBUFFER * __instance,
	unsigned char * content,
	ssize_t __contentLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTEBUFFER_extend(
	IRTrans_NET_REMOTEBUFFER __instance,
	unsigned char * content,
	ssize_t __contentLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTEBUFFER__Get__count_remaining(
	IRTrans_NET_REMOTEBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTEBUFFER__Set__count_remaining(
	IRTrans_NET_REMOTEBUFFER __instance,
	short count_remaining,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTEBUFFER__Get__next_offset(
	IRTrans_NET_REMOTEBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTEBUFFER__Set__next_offset(
	IRTrans_NET_REMOTEBUFFER __instance,
	short next_offset,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTEBUFFER__Get__count(
	IRTrans_NET_REMOTEBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTEBUFFER__Set__count(
	IRTrans_NET_REMOTEBUFFER __instance,
	short count,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTEBUFFER__Get__remotes(
	IRTrans_NET_REMOTEBUFFER __instance,
	IRTrans_NET_REMOTELINE ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTEBUFFER__Set__remotes(
	IRTrans_NET_REMOTEBUFFER __instance,
	IRTrans_NET_REMOTELINE * remotes,
	ssize_t __remotesLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTEBUFFER__Get__count_buffer(
	IRTrans_NET_REMOTEBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTEBUFFER__Set__count_buffer(
	IRTrans_NET_REMOTEBUFFER __instance,
	short count_buffer,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTEBUFFER__Get__offset(
	IRTrans_NET_REMOTEBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTEBUFFER__Set__offset(
	IRTrans_NET_REMOTEBUFFER __instance,
	short offset,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTEBUFFER__Get__count_total(
	IRTrans_NET_REMOTEBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_REMOTEBUFFER__Set__count_total(
	IRTrans_NET_REMOTEBUFFER __instance,
	short count_total,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.FIRMWARELINE
int CVIFUNC IRTrans_NET_FIRMWARELINE__Create(
	IRTrans_NET_FIRMWARELINE * __instance,
	unsigned char * content,
	ssize_t __contentLength,
	int offset,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWARELINE__Get__firmware_flags(
	IRTrans_NET_FIRMWARELINE __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWARELINE__Set__firmware_flags(
	IRTrans_NET_FIRMWARELINE __instance,
	unsigned int firmware_flags,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWARELINE__Get__net_flag(
	IRTrans_NET_FIRMWARELINE __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWARELINE__Set__net_flag(
	IRTrans_NET_FIRMWARELINE __instance,
	unsigned short net_flag,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWARELINE__Get__filename(
	IRTrans_NET_FIRMWARELINE __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWARELINE__Set__filename(
	IRTrans_NET_FIRMWARELINE __instance,
	char * filename,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWARELINE__Get__devicetype(
	IRTrans_NET_FIRMWARELINE __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWARELINE__Set__devicetype(
	IRTrans_NET_FIRMWARELINE __instance,
	char * devicetype,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWARELINE__Get__ir_version(
	IRTrans_NET_FIRMWARELINE __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWARELINE__Set__ir_version(
	IRTrans_NET_FIRMWARELINE __instance,
	char * ir_version,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWARELINE__Get__lan_version(
	IRTrans_NET_FIRMWARELINE __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWARELINE__Set__lan_version(
	IRTrans_NET_FIRMWARELINE __instance,
	char * lan_version,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWARELINE__Get__size(
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.FIRMWAREBUFFER
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER__Create(
	IRTrans_NET_FIRMWAREBUFFER * __instance,
	unsigned char * content,
	ssize_t __contentLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER_extend(
	IRTrans_NET_FIRMWAREBUFFER __instance,
	unsigned char * content,
	ssize_t __contentLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER__Get__count_remaining(
	IRTrans_NET_FIRMWAREBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER__Set__count_remaining(
	IRTrans_NET_FIRMWAREBUFFER __instance,
	short count_remaining,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER__Get__next_offset(
	IRTrans_NET_FIRMWAREBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER__Set__next_offset(
	IRTrans_NET_FIRMWAREBUFFER __instance,
	short next_offset,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER__Get__count(
	IRTrans_NET_FIRMWAREBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER__Set__count(
	IRTrans_NET_FIRMWAREBUFFER __instance,
	short count,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER__Get__firmware(
	IRTrans_NET_FIRMWAREBUFFER __instance,
	IRTrans_NET_FIRMWARELINE ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER__Set__firmware(
	IRTrans_NET_FIRMWAREBUFFER __instance,
	IRTrans_NET_FIRMWARELINE * firmware,
	ssize_t __firmwareLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER__Get__count_buffer(
	IRTrans_NET_FIRMWAREBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER__Set__count_buffer(
	IRTrans_NET_FIRMWAREBUFFER __instance,
	short count_buffer,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER__Get__offset(
	IRTrans_NET_FIRMWAREBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER__Set__offset(
	IRTrans_NET_FIRMWAREBUFFER __instance,
	short offset,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER__Get__count_total(
	IRTrans_NET_FIRMWAREBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_FIRMWAREBUFFER__Set__count_total(
	IRTrans_NET_FIRMWAREBUFFER __instance,
	short count_total,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.COMMANDBUFFER
int CVIFUNC IRTrans_NET_COMMANDBUFFER__Create(
	IRTrans_NET_COMMANDBUFFER * __instance,
	unsigned char * content,
	ssize_t __contentLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_COMMANDBUFFER_extend(
	IRTrans_NET_COMMANDBUFFER __instance,
	unsigned char * content,
	ssize_t __contentLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_COMMANDBUFFER__Get__count_remaining(
	IRTrans_NET_COMMANDBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_COMMANDBUFFER__Set__count_remaining(
	IRTrans_NET_COMMANDBUFFER __instance,
	short count_remaining,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_COMMANDBUFFER__Get__next_offset(
	IRTrans_NET_COMMANDBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_COMMANDBUFFER__Set__next_offset(
	IRTrans_NET_COMMANDBUFFER __instance,
	short next_offset,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_COMMANDBUFFER__Get__count(
	IRTrans_NET_COMMANDBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_COMMANDBUFFER__Set__count(
	IRTrans_NET_COMMANDBUFFER __instance,
	short count,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_COMMANDBUFFER__Get__commands(
	IRTrans_NET_COMMANDBUFFER __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_COMMANDBUFFER__Set__commands(
	IRTrans_NET_COMMANDBUFFER __instance,
	char ** commands,
	ssize_t __commandsLength,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.STATUSTYPE
int CVIFUNC IRTrans_NET_STATUSTYPE__Create(
	IRTrans_NET_STATUSTYPE * __instance,
	unsigned char * content,
	ssize_t __contentLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_STATUSTYPE__Get__type(
	IRTrans_NET_STATUSTYPE __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_STATUSTYPE__Set__type(
	IRTrans_NET_STATUSTYPE __instance,
	short type,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_STATUSTYPE__Get__len(
	IRTrans_NET_STATUSTYPE __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_STATUSTYPE__Set__len(
	IRTrans_NET_STATUSTYPE __instance,
	unsigned short len,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_STATUSTYPE__Get__clientid(
	IRTrans_NET_STATUSTYPE __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_STATUSTYPE__Set__clientid(
	IRTrans_NET_STATUSTYPE __instance,
	unsigned int clientid,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.STATUSINFO
int CVIFUNC IRTrans_NET_STATUSINFO__Create(
	IRTrans_NET_STATUSINFO * __instance,
	IRTrans_NET_STATUSTYPE st,
	unsigned char * data,
	ssize_t __dataLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_STATUSINFO__Get__stype(
	IRTrans_NET_STATUSINFO __instance,
	IRTrans_NET_STATUSTYPE * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_STATUSINFO__Set__stype(
	IRTrans_NET_STATUSINFO __instance,
	IRTrans_NET_STATUSTYPE stype,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_STATUSINFO__Get__sdata(
	IRTrans_NET_STATUSINFO __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_STATUSINFO__Set__sdata(
	IRTrans_NET_STATUSINFO __instance,
	unsigned char * sdata,
	ssize_t __sdataLength,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.ANALOG_CONFIG_COMMAND
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Create(
	IRTrans_NET_ANALOG_CONFIG_COMMAND * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND_Get_Size(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND_toByte(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Get__level(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Set__level(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned short level,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Get__level_off_delay(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Set__level_off_delay(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned char level_off_delay,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Get__macro_on_delay(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Set__macro_on_delay(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned short macro_on_delay,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Get__macro_off_delay(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Set__macro_off_delay(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned short macro_off_delay,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Get__remotes(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Set__remotes(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	char ** remotes,
	ssize_t __remotesLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Get__commands(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Set__commands(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	char ** commands,
	ssize_t __commandsLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Get__netcommand(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Set__netcommand(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Get__mode(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Set__mode(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Get__timeout(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Set__timeout(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Get__adress(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Set__adress(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Get__protocol_version(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOG_CONFIG_COMMAND__Set__protocol_version(
	IRTrans_NET_ANALOG_CONFIG_COMMAND __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.ANALOGSTATUS
int CVIFUNC IRTrans_NET_ANALOGSTATUS__Create(
	IRTrans_NET_ANALOGSTATUS * __instance,
	unsigned char * content,
	ssize_t __contentLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOGSTATUS__Get__length(
	IRTrans_NET_ANALOGSTATUS __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOGSTATUS__Set__length(
	IRTrans_NET_ANALOGSTATUS __instance,
	unsigned char length,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOGSTATUS__Get__count(
	IRTrans_NET_ANALOGSTATUS __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOGSTATUS__Set__count(
	IRTrans_NET_ANALOGSTATUS __instance,
	unsigned char count,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOGSTATUS__Get__mode(
	IRTrans_NET_ANALOGSTATUS __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOGSTATUS__Set__mode(
	IRTrans_NET_ANALOGSTATUS __instance,
	unsigned char * mode,
	ssize_t __modeLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOGSTATUS__Get__value(
	IRTrans_NET_ANALOGSTATUS __instance,
	short ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOGSTATUS__Set__value(
	IRTrans_NET_ANALOGSTATUS __instance,
	short * value,
	ssize_t __valueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOGSTATUS__Get__id(
	IRTrans_NET_ANALOGSTATUS __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_ANALOGSTATUS__Set__id(
	IRTrans_NET_ANALOGSTATUS __instance,
	CDotNetHandle id,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.DEVICEINFO
int CVIFUNC IRTrans_NET_DEVICEINFO__Create(
	IRTrans_NET_DEVICEINFO * __instance,
	unsigned char * content,
	ssize_t __contentLength,
	int offset,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Get__send_mask(
	IRTrans_NET_DEVICEINFO __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Set__send_mask(
	IRTrans_NET_DEVICEINFO __instance,
	int send_mask,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Get__device_mode(
	IRTrans_NET_DEVICEINFO __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Set__device_mode(
	IRTrans_NET_DEVICEINFO __instance,
	unsigned short device_mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Get__extended_mode(
	IRTrans_NET_DEVICEINFO __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Set__extended_mode(
	IRTrans_NET_DEVICEINFO __instance,
	unsigned short extended_mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Get__extended_mode2(
	IRTrans_NET_DEVICEINFO __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Set__extended_mode2(
	IRTrans_NET_DEVICEINFO __instance,
	unsigned short extended_mode2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Get__switch_mode(
	IRTrans_NET_DEVICEINFO __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Set__switch_mode(
	IRTrans_NET_DEVICEINFO __instance,
	unsigned short switch_mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Get__features(
	IRTrans_NET_DEVICEINFO __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Set__features(
	IRTrans_NET_DEVICEINFO __instance,
	unsigned int features,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Get__version(
	IRTrans_NET_DEVICEINFO __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Set__version(
	IRTrans_NET_DEVICEINFO __instance,
	char * version,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Get__remote(
	IRTrans_NET_DEVICEINFO __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Set__remote(
	IRTrans_NET_DEVICEINFO __instance,
	char * remote,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Get__command(
	IRTrans_NET_DEVICEINFO __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICEINFO__Set__command(
	IRTrans_NET_DEVICEINFO __instance,
	char * command,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.DEVICELISTEX
int CVIFUNC IRTrans_NET_DEVICELISTEX__Create(
	IRTrans_NET_DEVICELISTEX * __instance,
	unsigned char * content,
	ssize_t __contentLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICELISTEX__Get__count(
	IRTrans_NET_DEVICELISTEX __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICELISTEX__Set__count(
	IRTrans_NET_DEVICELISTEX __instance,
	unsigned short count,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICELISTEX__Get__dev_adr(
	IRTrans_NET_DEVICELISTEX __instance,
	unsigned short ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICELISTEX__Set__dev_adr(
	IRTrans_NET_DEVICELISTEX __instance,
	unsigned short * dev_adr,
	ssize_t __dev_adrLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICELISTEX__Get__stat(
	IRTrans_NET_DEVICELISTEX __instance,
	IRTrans_NET_DEVICEINFO ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_DEVICELISTEX__Set__stat(
	IRTrans_NET_DEVICELISTEX __instance,
	IRTrans_NET_DEVICEINFO * stat,
	ssize_t __statLength1,
	ssize_t __statLength2,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.NETWORKLEARNSTAT
int CVIFUNC IRTrans_NET_NETWORKLEARNSTAT__Create(
	IRTrans_NET_NETWORKLEARNSTAT * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARNSTAT__Get__adress(
	IRTrans_NET_NETWORKLEARNSTAT __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARNSTAT__Set__adress(
	IRTrans_NET_NETWORKLEARNSTAT __instance,
	short adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARNSTAT__Get__learnok(
	IRTrans_NET_NETWORKLEARNSTAT __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARNSTAT__Set__learnok(
	IRTrans_NET_NETWORKLEARNSTAT __instance,
	unsigned char learnok,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARNSTAT__Get__carrier(
	IRTrans_NET_NETWORKLEARNSTAT __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARNSTAT__Set__carrier(
	IRTrans_NET_NETWORKLEARNSTAT __instance,
	unsigned char carrier,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARNSTAT__Get__remote(
	IRTrans_NET_NETWORKLEARNSTAT __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARNSTAT__Set__remote(
	IRTrans_NET_NETWORKLEARNSTAT __instance,
	char * remote,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARNSTAT__Get__num_timings(
	IRTrans_NET_NETWORKLEARNSTAT __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARNSTAT__Set__num_timings(
	IRTrans_NET_NETWORKLEARNSTAT __instance,
	short num_timings,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARNSTAT__Get__num_commands(
	IRTrans_NET_NETWORKLEARNSTAT __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARNSTAT__Set__num_commands(
	IRTrans_NET_NETWORKLEARNSTAT __instance,
	short num_commands,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARNSTAT__Get__received(
	IRTrans_NET_NETWORKLEARNSTAT __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_NETWORKLEARNSTAT__Set__received(
	IRTrans_NET_NETWORKLEARNSTAT __instance,
	char * received,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.TRANSLATECOMMAND
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Create(
	IRTrans_NET_TRANSLATECOMMAND * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Create_1(
	IRTrans_NET_TRANSLATECOMMAND * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	int pos,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND_Get_Size(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND_toByte(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__number(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__number(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned int number,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__setup(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__setup(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char setup,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__type(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__type(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char type,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__accelerator_timeout(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__accelerator_timeout(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char accelerator_timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__accelerator_repeat(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__accelerator_repeat(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char accelerator_repeat,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__wait_timeout(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__wait_timeout(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	short wait_timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__remote_num(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__remote_num(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char remote_num,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__group_num(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__group_num(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char group_num,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__remote(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__remote(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	char * remote,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__command(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__command(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	char * command,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__source_mask(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__source_mask(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	int source_mask,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__target_mask(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__target_mask(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	int target_mask,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__multi_num(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__multi_num(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char multi_num,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__include_names(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__include_names(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char include_names,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__io_input(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__io_input(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char io_input,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__io_value(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__io_value(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char io_value,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__netcommand(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__netcommand(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__mode(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__mode(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__timeout(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__timeout(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__adress(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__adress(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Get__protocol_version(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATECOMMAND__Set__protocol_version(
	IRTrans_NET_TRANSLATECOMMAND __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.TRANSLATEBUFFER
int CVIFUNC IRTrans_NET_TRANSLATEBUFFER__Create(
	IRTrans_NET_TRANSLATEBUFFER * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATEBUFFER__Get__offset(
	IRTrans_NET_TRANSLATEBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATEBUFFER__Set__offset(
	IRTrans_NET_TRANSLATEBUFFER __instance,
	short offset,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATEBUFFER__Get__count_buffer(
	IRTrans_NET_TRANSLATEBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATEBUFFER__Set__count_buffer(
	IRTrans_NET_TRANSLATEBUFFER __instance,
	short count_buffer,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATEBUFFER__Get__count_total(
	IRTrans_NET_TRANSLATEBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATEBUFFER__Set__count_total(
	IRTrans_NET_TRANSLATEBUFFER __instance,
	short count_total,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATEBUFFER__Get__count_remaining(
	IRTrans_NET_TRANSLATEBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATEBUFFER__Set__count_remaining(
	IRTrans_NET_TRANSLATEBUFFER __instance,
	short count_remaining,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATEBUFFER__Get__trans(
	IRTrans_NET_TRANSLATEBUFFER __instance,
	IRTrans_NET_TRANSLATECOMMAND ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_TRANSLATEBUFFER__Set__trans(
	IRTrans_NET_TRANSLATEBUFFER __instance,
	IRTrans_NET_TRANSLATECOMMAND * trans,
	ssize_t __transLength,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.MODECOMMANDEX3
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Create(
	IRTrans_NET_MODECOMMANDEX3 * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Create_1(
	IRTrans_NET_MODECOMMANDEX3 * __instance,
	unsigned char netcommand,
	unsigned int lngMask,
	unsigned char mode_v,
	unsigned char extmode_v,
	unsigned int address_v,
	unsigned char extmode2_v,
	unsigned char * extmode_ex_v,
	ssize_t __extmode_ex_vLength,
	char * hotrem,
	char * hotcom,
	char * hotrem2,
	char * hotcom2,
	char * wakemac,
	unsigned char * extmode_ex2_v,
	ssize_t __extmode_ex2_vLength,
	unsigned char * rs232_mode_v,
	ssize_t __rs232_mode_vLength,
	unsigned char * status_input_v,
	ssize_t __status_input_vLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3_Get_Size(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3_toByte(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__hotremote(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__hotremote(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	char * hotremote,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__hotcommand(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__hotcommand(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	char * hotcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__hotremote_2(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__hotremote_2(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	char * hotremote_2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__hotcommand_2(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__hotcommand_2(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	char * hotcommand_2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__targetmask(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__targetmask(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned int targetmask,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__extmode(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__extmode(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char extmode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__extmode_2(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__extmode_2(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char extmode_2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__wakeup_mac(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__wakeup_mac(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char * wakeup_mac,
	ssize_t __wakeup_macLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__extmode_ex(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__extmode_ex(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char * extmode_ex,
	ssize_t __extmode_exLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__extmode_ex2(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__extmode_ex2(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char * extmode_ex2,
	ssize_t __extmode_ex2Length,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__rs232_mode(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__rs232_mode(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char * rs232_mode,
	ssize_t __rs232_modeLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__status_input(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__status_input(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char * status_input,
	ssize_t __status_inputLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__netcommand(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__netcommand(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__mode(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__mode(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__timeout(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__timeout(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__adress(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__adress(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Get__protocol_version(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX3__Set__protocol_version(
	IRTrans_NET_MODECOMMANDEX3 __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.MODECOMMANDEX
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Create(
	IRTrans_NET_MODECOMMANDEX * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Create_1(
	IRTrans_NET_MODECOMMANDEX * __instance,
	unsigned char netcommand,
	unsigned int lngMask,
	unsigned char mode_v,
	unsigned char extmode_v,
	unsigned int address_v,
	unsigned char extmode2_v,
	unsigned char * extmode_ex_v,
	ssize_t __extmode_ex_vLength,
	char * hotrem,
	char * hotcom,
	char * hotrem2,
	char * hotcom2,
	char * wakemac,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX_Get_Size(
	IRTrans_NET_MODECOMMANDEX __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX_toByte(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Get__hotremote(
	IRTrans_NET_MODECOMMANDEX __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Set__hotremote(
	IRTrans_NET_MODECOMMANDEX __instance,
	char * hotremote,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Get__hotcommand(
	IRTrans_NET_MODECOMMANDEX __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Set__hotcommand(
	IRTrans_NET_MODECOMMANDEX __instance,
	char * hotcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Get__hotremote_2(
	IRTrans_NET_MODECOMMANDEX __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Set__hotremote_2(
	IRTrans_NET_MODECOMMANDEX __instance,
	char * hotremote_2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Get__hotcommand_2(
	IRTrans_NET_MODECOMMANDEX __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Set__hotcommand_2(
	IRTrans_NET_MODECOMMANDEX __instance,
	char * hotcommand_2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Get__targetmask(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Set__targetmask(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned int targetmask,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Get__extmode(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Set__extmode(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned char extmode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Get__extmode_2(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Set__extmode_2(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned char extmode_2,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Get__wakeup_mac(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Set__wakeup_mac(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned char * wakeup_mac,
	ssize_t __wakeup_macLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Get__extmode_ex(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Set__extmode_ex(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned char * extmode_ex,
	ssize_t __extmode_exLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Get__netcommand(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Set__netcommand(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Get__mode(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Set__mode(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Get__timeout(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Set__timeout(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Get__adress(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Set__adress(
	IRTrans_NET_MODECOMMANDEX __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Get__protocol_version(
	IRTrans_NET_MODECOMMANDEX __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_MODECOMMANDEX__Set__protocol_version(
	IRTrans_NET_MODECOMMANDEX __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.WLANCONFIGCOMMAND
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Create(
	IRTrans_NET_WLANCONFIGCOMMAND * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND_Get_Size(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND_checkValues(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND_toByte(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__ip_adr(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__ip_adr(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	char * ip_adr,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__ip_netmask(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__ip_netmask(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	char * ip_netmask,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__ip_gateway(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__ip_gateway(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	char * ip_gateway,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__ntp_server(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__ntp_server(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	char * ntp_server,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__dhcp_flag(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__dhcp_flag(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char dhcp_flag,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__wpa_key(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__wpa_key(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	char * wpa_key,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__wlan_ssid(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__wlan_ssid(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	char * wlan_ssid,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__wlan_channel(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__wlan_channel(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char wlan_channel,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__wlan_speed(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__wlan_speed(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char wlan_speed,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__wlan_power(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__wlan_power(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char wlan_power,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__wlan_mode(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__wlan_mode(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char wlan_mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__wlan_security(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__wlan_security(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char wlan_security,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__timezone(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__timezone(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char timezone,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__netcommand(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__netcommand(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__mode(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__mode(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__timeout(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__timeout(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__adress(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__adress(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Get__protocol_version(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_WLANCONFIGCOMMAND__Set__protocol_version(
	IRTrans_NET_WLANCONFIGCOMMAND __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.SYSPARAMCOMMAND
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Create(
	IRTrans_NET_SYSPARAMCOMMAND * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND_Get_Size(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND_checkValues(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND_toByte(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__access_ip(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__access_ip(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char ** access_ip,
	ssize_t __access_ipLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__access_mask(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__access_mask(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char ** access_mask,
	ssize_t __access_maskLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__ir_relay_from(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__ir_relay_from(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char ** ir_relay_from,
	ssize_t __ir_relay_fromLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__ir_relay_to(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__ir_relay_to(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char ** ir_relay_to,
	ssize_t __ir_relay_toLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__udp_str_adr(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__udp_str_adr(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char * udp_str_adr,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__wakeonlan_mac(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__wakeonlan_mac(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char * wakeonlan_mac,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__password(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__password(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char * password,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__broadcast_relay(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__broadcast_relay(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned char broadcast_relay,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__udp_port(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__udp_port(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned short udp_port,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__tz(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__tz(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned char tz,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__ntp_ip(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__ntp_ip(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	char * ntp_ip,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__ir_relay_led(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__ir_relay_led(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned char * ir_relay_led,
	ssize_t __ir_relay_ledLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__netcommand(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__netcommand(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__mode(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__mode(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__timeout(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__timeout(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__adress(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__adress(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Get__protocol_version(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_SYSPARAMCOMMAND__Set__protocol_version(
	IRTrans_NET_SYSPARAMCOMMAND __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.LcdCommand
int CVIFUNC IRTrans_NET_LcdCommand__Create(
	IRTrans_NET_LcdCommand * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand_Get_Size(
	IRTrans_NET_LcdCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand_toByte(
	IRTrans_NET_LcdCommand __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Get__lcdcommand(
	IRTrans_NET_LcdCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Set__lcdcommand(
	IRTrans_NET_LcdCommand __instance,
	unsigned char lcdcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Get__wid(
	IRTrans_NET_LcdCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Set__wid(
	IRTrans_NET_LcdCommand __instance,
	unsigned char wid,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Get__hgt(
	IRTrans_NET_LcdCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Set__hgt(
	IRTrans_NET_LcdCommand __instance,
	unsigned char hgt,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Get__framebuffer(
	IRTrans_NET_LcdCommand __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Set__framebuffer(
	IRTrans_NET_LcdCommand __instance,
	unsigned char * framebuffer,
	ssize_t __framebufferLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Get__BACKLIGHT(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Get__TEXT(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Get__INIT(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Get__DATA(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Get__netcommand(
	IRTrans_NET_LcdCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Set__netcommand(
	IRTrans_NET_LcdCommand __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Get__mode(
	IRTrans_NET_LcdCommand __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Set__mode(
	IRTrans_NET_LcdCommand __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Get__timeout(
	IRTrans_NET_LcdCommand __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Set__timeout(
	IRTrans_NET_LcdCommand __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Get__adress(
	IRTrans_NET_LcdCommand __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Set__adress(
	IRTrans_NET_LcdCommand __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Get__protocol_version(
	IRTrans_NET_LcdCommand __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_LcdCommand__Set__protocol_version(
	IRTrans_NET_LcdCommand __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.IRTransConnectionException
int CVIFUNC IRTrans_NET_IRTransConnectionException__Create(
	IRTrans_NET_IRTransConnectionException * __instance,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException__Create_1(
	IRTrans_NET_IRTransConnectionException * __instance,
	char * message,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException__Create_2(
	IRTrans_NET_IRTransConnectionException * __instance,
	char * message,
	System_Exception inner,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException_Get_Message(
	IRTrans_NET_IRTransConnectionException __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException_Get_Data(
	IRTrans_NET_IRTransConnectionException __instance,
	System_Collections_IDictionary * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException_Get_InnerException(
	IRTrans_NET_IRTransConnectionException __instance,
	System_Exception * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException_Get_TargetSite(
	IRTrans_NET_IRTransConnectionException __instance,
	System_Reflection_MethodBase * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException_Get_StackTrace(
	IRTrans_NET_IRTransConnectionException __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException_Get_HelpLink(
	IRTrans_NET_IRTransConnectionException __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException_Set_HelpLink(
	IRTrans_NET_IRTransConnectionException __instance,
	char * value,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException_Get_Source(
	IRTrans_NET_IRTransConnectionException __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException_Set_Source(
	IRTrans_NET_IRTransConnectionException __instance,
	char * value,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException_Get_HResult(
	IRTrans_NET_IRTransConnectionException __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException_GetBaseException(
	IRTrans_NET_IRTransConnectionException __instance,
	System_Exception * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException_ToString(
	IRTrans_NET_IRTransConnectionException __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException_GetObjectData(
	IRTrans_NET_IRTransConnectionException __instance,
	System_Runtime_Serialization_SerializationInfo info,
	System_Runtime_Serialization_StreamingContext context,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRTransConnectionException_GetType(
	IRTrans_NET_IRTransConnectionException __instance,
	System_Type * __returnValue,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.IRDBHEADER
int CVIFUNC IRTrans_NET_IRDBHEADER__Create(
	IRTrans_NET_IRDBHEADER * __instance,
	unsigned char netcommand,
	unsigned char typ,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Create_1(
	IRTrans_NET_IRDBHEADER * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	int pos,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER_Get_Size(
	IRTrans_NET_IRDBHEADER __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER_toByte(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__number(
	IRTrans_NET_IRDBHEADER __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__number(
	IRTrans_NET_IRDBHEADER __instance,
	int number,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__active(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__active(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char active,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__type(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__type(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char type,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__port(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__port(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned short port,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__default_action(
	IRTrans_NET_IRDBHEADER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__default_action(
	IRTrans_NET_IRDBHEADER __instance,
	char * default_action,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__err_status(
	IRTrans_NET_IRDBHEADER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__err_status(
	IRTrans_NET_IRDBHEADER __instance,
	char * err_status,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__ok_status(
	IRTrans_NET_IRDBHEADER __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__ok_status(
	IRTrans_NET_IRDBHEADER __instance,
	char * ok_status,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__inputmode(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__inputmode(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char * inputmode,
	ssize_t __inputmodeLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__min(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__min(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char * min,
	ssize_t __minLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__max(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__max(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char * max,
	ssize_t __maxLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__hyst(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__hyst(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char * hyst,
	ssize_t __hystLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__minledsel(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__minledsel(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char * minledsel,
	ssize_t __minledselLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__maxledsel(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__maxledsel(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char * maxledsel,
	ssize_t __maxledselLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__minmask(
	IRTrans_NET_IRDBHEADER __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__minmask(
	IRTrans_NET_IRDBHEADER __instance,
	int * minmask,
	ssize_t __minmaskLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__maxmask(
	IRTrans_NET_IRDBHEADER __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__maxmask(
	IRTrans_NET_IRDBHEADER __instance,
	int * maxmask,
	ssize_t __maxmaskLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__minremote(
	IRTrans_NET_IRDBHEADER __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__minremote(
	IRTrans_NET_IRDBHEADER __instance,
	char ** minremote,
	ssize_t __minremoteLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__mincommand(
	IRTrans_NET_IRDBHEADER __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__mincommand(
	IRTrans_NET_IRDBHEADER __instance,
	char ** mincommand,
	ssize_t __mincommandLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__maxremote(
	IRTrans_NET_IRDBHEADER __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__maxremote(
	IRTrans_NET_IRDBHEADER __instance,
	char ** maxremote,
	ssize_t __maxremoteLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__maxcommand(
	IRTrans_NET_IRDBHEADER __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__maxcommand(
	IRTrans_NET_IRDBHEADER __instance,
	char ** maxcommand,
	ssize_t __maxcommandLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__ip(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__ip(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned int ip,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__rs232_config(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__rs232_config(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char * rs232_config,
	ssize_t __rs232_configLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__netcommand(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__netcommand(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__mode(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__mode(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__timeout(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__timeout(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__adress(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__adress(
	IRTrans_NET_IRDBHEADER __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Get__protocol_version(
	IRTrans_NET_IRDBHEADER __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADER__Set__protocol_version(
	IRTrans_NET_IRDBHEADER __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.IRDBCOMMAND
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Create(
	IRTrans_NET_IRDBCOMMAND * __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Create_1(
	IRTrans_NET_IRDBCOMMAND * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	int pos,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND_Get_Size(
	IRTrans_NET_IRDBCOMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND_toByte(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__number(
	IRTrans_NET_IRDBCOMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__number(
	IRTrans_NET_IRDBCOMMAND __instance,
	int number,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__relais(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__relais(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned char relais,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__type(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__type(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned char type,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__action_type(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__action_type(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned char action_type,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__action_len(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__action_len(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned char action_len,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__remote_num(
	IRTrans_NET_IRDBCOMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__remote_num(
	IRTrans_NET_IRDBCOMMAND __instance,
	int remote_num,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__command_num(
	IRTrans_NET_IRDBCOMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__command_num(
	IRTrans_NET_IRDBCOMMAND __instance,
	int command_num,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__ip(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__ip(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned int ip,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__port(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__port(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned short port,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__remote(
	IRTrans_NET_IRDBCOMMAND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__remote(
	IRTrans_NET_IRDBCOMMAND __instance,
	char * remote,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__command(
	IRTrans_NET_IRDBCOMMAND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__command(
	IRTrans_NET_IRDBCOMMAND __instance,
	char * command,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__action(
	IRTrans_NET_IRDBCOMMAND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__action(
	IRTrans_NET_IRDBCOMMAND __instance,
	char * action,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__netcommand(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__netcommand(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned char netcommand,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__mode(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__mode(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned char mode,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__timeout(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__timeout(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned short timeout,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__adress(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__adress(
	IRTrans_NET_IRDBCOMMAND __instance,
	unsigned int adress,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Get__protocol_version(
	IRTrans_NET_IRDBCOMMAND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBCOMMAND__Set__protocol_version(
	IRTrans_NET_IRDBCOMMAND __instance,
	int protocol_version,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.IRDBSTATUS
int CVIFUNC IRTrans_NET_IRDBSTATUS__Create(
	IRTrans_NET_IRDBSTATUS * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBSTATUS__Get__memsize(
	IRTrans_NET_IRDBSTATUS __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBSTATUS__Set__memsize(
	IRTrans_NET_IRDBSTATUS __instance,
	char * memsize,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBSTATUS__Get__flashsize(
	IRTrans_NET_IRDBSTATUS __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBSTATUS__Set__flashsize(
	IRTrans_NET_IRDBSTATUS __instance,
	char * flashsize,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBSTATUS__Get__remotes(
	IRTrans_NET_IRDBSTATUS __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBSTATUS__Set__remotes(
	IRTrans_NET_IRDBSTATUS __instance,
	char * remotes,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBSTATUS__Get__commands(
	IRTrans_NET_IRDBSTATUS __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBSTATUS__Set__commands(
	IRTrans_NET_IRDBSTATUS __instance,
	char * commands,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBSTATUS__Get__actions(
	IRTrans_NET_IRDBSTATUS __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBSTATUS__Set__actions(
	IRTrans_NET_IRDBSTATUS __instance,
	char * actions,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.IRDBBUFFER
int CVIFUNC IRTrans_NET_IRDBBUFFER__Create(
	IRTrans_NET_IRDBBUFFER * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBBUFFER__Get__offset(
	IRTrans_NET_IRDBBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBBUFFER__Set__offset(
	IRTrans_NET_IRDBBUFFER __instance,
	short offset,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBBUFFER__Get__count_buffer(
	IRTrans_NET_IRDBBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBBUFFER__Set__count_buffer(
	IRTrans_NET_IRDBBUFFER __instance,
	short count_buffer,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBBUFFER__Get__count_total(
	IRTrans_NET_IRDBBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBBUFFER__Set__count_total(
	IRTrans_NET_IRDBBUFFER __instance,
	short count_total,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBBUFFER__Get__count_remaining(
	IRTrans_NET_IRDBBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBBUFFER__Set__count_remaining(
	IRTrans_NET_IRDBBUFFER __instance,
	short count_remaining,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBBUFFER__Get__irdb(
	IRTrans_NET_IRDBBUFFER __instance,
	IRTrans_NET_IRDBCOMMAND ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBBUFFER__Set__irdb(
	IRTrans_NET_IRDBBUFFER __instance,
	IRTrans_NET_IRDBCOMMAND * irdb,
	ssize_t __irdbLength,
	CDotNetHandle * __exception);

// Type: IRTrans.NET.IRDBHEADERBUFFER
int CVIFUNC IRTrans_NET_IRDBHEADERBUFFER__Create(
	IRTrans_NET_IRDBHEADERBUFFER * __instance,
	unsigned char * source,
	ssize_t __sourceLength,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADERBUFFER__Get__offset(
	IRTrans_NET_IRDBHEADERBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADERBUFFER__Set__offset(
	IRTrans_NET_IRDBHEADERBUFFER __instance,
	short offset,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADERBUFFER__Get__count_buffer(
	IRTrans_NET_IRDBHEADERBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADERBUFFER__Set__count_buffer(
	IRTrans_NET_IRDBHEADERBUFFER __instance,
	short count_buffer,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADERBUFFER__Get__count_total(
	IRTrans_NET_IRDBHEADERBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADERBUFFER__Set__count_total(
	IRTrans_NET_IRDBHEADERBUFFER __instance,
	short count_total,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADERBUFFER__Get__count_remaining(
	IRTrans_NET_IRDBHEADERBUFFER __instance,
	short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADERBUFFER__Set__count_remaining(
	IRTrans_NET_IRDBHEADERBUFFER __instance,
	short count_remaining,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADERBUFFER__Get__header(
	IRTrans_NET_IRDBHEADERBUFFER __instance,
	IRTrans_NET_IRDBHEADER * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC IRTrans_NET_IRDBHEADERBUFFER__Set__header(
	IRTrans_NET_IRDBHEADERBUFFER __instance,
	IRTrans_NET_IRDBHEADER header,
	CDotNetHandle * __exception);


#ifdef __cplusplus
}
#endif
