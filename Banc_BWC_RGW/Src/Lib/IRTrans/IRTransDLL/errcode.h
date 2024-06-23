#define ERR_OPEN			1
#define ERR_RESET			2
#define ERR_VERSION			3
#define ERR_TIMEOUT			4
#define	ERR_READVERSION		5

#define ERR_DBOPENINPUT		11
#define ERR_REMOTENOTFOUND	12
#define ERR_COMMANDNOTFOUND	13
#define ERR_TIMINGNOTFOUND	14
#define ERR_OPENASCII		15
#define ERR_NODATABASE		16
#define ERR_OPENUSB			17
#define ERR_RESEND			18
#define ERR_TOGGLE_DUP		19
#define ERR_DBOPENINCLUDE	20
#define ERR_NOFILEOPEN		21
#define	ERR_FLOCK			22
#define ERR_STTY			23
#define ERR_HOTCODE			24
#define ERR_NOTIMING		25
#define ERR_TEMPCOMMAND		26
#define ERR_OPENTRANS		27
#define ERR_TESTCOM			28
#define ERR_SHUTDOWN		29
#define ERR_ISMACRO			30
#define ERR_LONGRAW			31
#define ERR_LONGDATA		32
#define ERR_WRONGBUS		33
#define ERR_COMMANDSTRING	34
#define	ERR_OVERWRITE		35
#define	ERR_CCF				36

#define ERR_OPENSOCKET		100
#define ERR_BINDSOCKET		101
#define ERR_FINDHOST		103
#define ERR_CONNECT			104
#define ERR_SEND			105
#define ERR_RECV			106
#define ERR_BINDWEB			107
#define ERR_DEVICEUNKNOWN	108


#define FATAL				1
#define IR					2
#define	IRTIMEOUT			3

void GetError (int res,char st[]);
