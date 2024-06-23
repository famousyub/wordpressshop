#include <winsock2.h>
#include <windows.h>

#include "IRTransDLL.h"
//#include "network.h"


SOCKET sock;


main ()
{
	int res;
	NETWORKSTATUS *stat;

	res = ConnectIRTransServer ("localhost",&sock);

	if (res) return (res);

	stat = SendRemoteCommand (sock,"sony-cd","play",0,0,0);

	if (stat) {
		// ... Error Handling
	}

	DisconnectIRTransServer (sock);
}
