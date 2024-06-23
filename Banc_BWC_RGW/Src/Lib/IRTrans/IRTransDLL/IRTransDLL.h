#include <winsock2.h>
//#include <windows.h>
//#include <stdio.h>

#include "remote.h"
#include "network.h"
#include "errcode.h"


#ifdef IRTRANSDLL_EXPORTS
#define IRTRANSDLL_API __declspec(dllexport)
#else
#ifdef  __cplusplus
#define IRTRANSDLL_API extern "C" __declspec(dllimport)
#else
#define IRTRANSDLL_API __declspec(dllimport)
#endif
#endif

#define TIMER_OFF               1	
#define TIMER_REPEAT            4
#define TIMER_ONCE 			    2

IRTRANSDLL_API int ConnectIRTransServer (char host[],SOCKET *sock);
IRTRANSDLL_API void DisconnectIRTransServer (SOCKET serv);
IRTRANSDLL_API NETWORKSTATUS *LearnIRCode (SOCKET serv, char rem[],char com[],unsigned short timeout);
IRTRANSDLL_API NETWORKSTATUS *LearnRepeatIRCode (SOCKET serv, char rem[],char com[],unsigned short timeout);
IRTRANSDLL_API NETWORKSTATUS *SendRemoteCommand (SOCKET serv, char rem[],char com[],int mask,int LEDSel,int bus);
IRTRANSDLL_API NETWORKRECV *ReceiveIR (SOCKET serv);
IRTRANSDLL_API NETWORKSTATUS *ReloadIRDatabase (SOCKET serv);
IRTRANSDLL_API int GetDeviceStatus (SOCKET serv, void *result);
