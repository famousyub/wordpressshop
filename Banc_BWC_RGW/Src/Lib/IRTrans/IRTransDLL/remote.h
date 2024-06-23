#ifdef WIN32
//typedef unsigned char uint8_t;
//typedef unsigned int uint32_t;
//typedef unsigned short uint16_t;

//typedef char int8_t;
//typedef short int16_t;
//typedef int int32_t;
//typedef unsigned int uint32_t;
#endif

#ifdef _HCS12

typedef INT8 int8_t;
typedef UINT8 uint8_t;

typedef UINT16 uint16_t;
typedef INT16 int16_t;

typedef UINT32 uint32_t;

#endif

typedef uint8_t byte;
typedef uint16_t word;

#ifdef _HCS12
#define CODE_LEN	174

#else
#ifndef AVR
#pragma pack(1)
#define CODE_LEN	176							// 2 Byte mehr für String-Ende 0
#else
#ifdef REMOTECONTROL
#define CODE_LEN	20
#else
#define CODE_LEN	174
#endif
#endif
#endif


#define VCC_THRESHOLD	210



#define TIME_LEN	8
#define RAW_EXTRA	TIME_LEN * 4 + 2
#define CODE_LENRAW	(CODE_LEN + RAW_EXTRA - 2)
#define OLD_LENRAW	(CODE_LEN + (6 * 4 + 2) - 2)
#define MAXLCDLEN 170



typedef struct {
	byte len;
	byte checksumme;
	byte command;

	byte address;
	word target_mask;

	byte ir_length;
	byte transmit_freq;
	byte mode;

	short pause_len[TIME_LEN];
	short pulse_len[TIME_LEN];
	byte time_cnt;
	byte ir_repeat;
	byte repeat_pause;

	byte data[CODE_LEN];
} IRDATA;

#define FLASH_TYPE_LAN			0xff01
#define FLASH_TYPE_IRDB			0xff02

#define SENDMASK_LEN  16

#define COMMAND_LAN             200
#define COMMAND_FLASH_START     201
#define COMMAND_FLASH_DATA      202
#define COMMAND_FLASH_END		203
#define COMMAND_FLASH_ACK       204
#define COMMAND_FLASH_CANCEL    205
#define COMMAND_LAN_SENDSTRING	's' // 115



#define RESULT_IR_BROADCAST		230
#define RESULT_GETVERSION		231
#define RESULT_DEVSTATUS		232
#define RESULT_EEPROM			233
#define RESULT_RESET			234
#define RESULT_IRDBSTATUS		235
#define RESULT_REMOTELIST		236
#define RESULT_COMMANDLIST		237
#define RESULT_IR_RECEIVE		238
#define	RESULT_UDP_FORMAT		239
#define RESULT_FLASH			240
#define RESULT_ALIVE			241
#define RESULT_LEARN			242

typedef struct {
	uint8_t len;
	uint8_t checksumme;
	uint8_t command;

	uint8_t cmd_str[80 + 20 + 10];
} IRCOMMAND_STRING;


typedef struct {
	uint8_t len;
	uint8_t checksumme;
	uint8_t command;

	uint8_t remote[81];
	uint8_t ircommand[21];
	uint8_t ledselect;
} IRCOMMAND_BUF;

typedef struct {
	uint8_t len;
	uint8_t checksumme;
	uint8_t command;

  uint16_t start;
	uint8_t remote[81];
} IRDBLIST_BUF;


typedef struct {
	word adr;
	word len;
	word flash_adr;
	word page;
	word crc;
} FLASH_BLOCK;

typedef struct {
	word crc;
	word type;
	FLASH_BLOCK dir[12];
} FLASH_TABLE;

#define FLASH_TABLE_LEN ((sizeof (FLASH_TABLE) + 1) / 2)


typedef struct {
	uint8_t netcommand;
	uint8_t mode;
	uint16_t timeout;
	uint32_t sendmask[SENDMASK_LEN];
	IRDATA ir_data;
} IRDATA_LAN;

typedef struct {
	uint8_t netcommand;
	uint8_t mode;
	uint16_t timeout;
	uint32_t sendmask[SENDMASK_LEN];
	IRDATA ir_data;
	byte buffer[256];
} IRDATA_LAN_LARGE;

typedef struct {
	uint8_t netcommand;
	IRDATA ir_data;
} IRDATA_LAN_SHORT;

typedef struct {
	byte len;
	byte checksumme;
	byte command;
	word adr;
	byte data[200];
} IRDATA_EEPROM;

typedef struct {
	uint8_t		netcommand;
	uint8_t		len;
	uint8_t		ir_version[8];
	uint32_t	ir_capabilities;
	uint32_t	ir_serno;
	uint8_t		lan_version[8];
	uint8_t		mac_adr[6];
} GETVERSION_LAN;

typedef struct {
	uint32_t	access_ip[8];			// Erlaubte Input IPs
	uint32_t	access_mask[8];			// Netmask dazu
	uint32_t	ir_relay_from[16];		// IR Relay von diesen Adressen erlaubt
	uint32_t	ir_relay_to[8];  		// Output wird zusätzlich zum Broadcast an diese IPs gesendet
	uint32_t	udp_str_adr;
	uint8_t		wakeonlan_mac[6];		// Zielhost für WakeOnLAN Pakete (PowerOn)
	int8_t		password[12];
	uint8_t		broadcast_relay;
	uint8_t		udp_format_len;
	uint16_t	udp_port;
} SYS_PARAMETER;

typedef struct {
	uint8_t			len;
	SYS_PARAMETER	sysparm;
} SYS_PARAMETER_GET;

typedef struct {
	uint8_t		len;
	byte      checksumme;
	byte      command;
	SYS_PARAMETER	sysparm;
} SYS_PARAMETER_STORE;

typedef struct {
	uint8_t		len;
	byte      checksumme;
	byte      command;
	byte      udplen;
	byte      str[100];
} UDP_FORMAT_STORE;

typedef struct {
	uint8_t		len;
	uint8_t		dhcp_flag;
	uint8_t		fallback_flag;
	uint8_t		mac_adr[6];
	uint32_t	ip_adr;
	uint32_t	ip_netmask;
	uint32_t	ip_gateway;
} LAN_PARAMETER;

typedef struct {
	uint8_t		len;
	byte      checksumme;
	byte      command;
	uint8_t		dhcp_flag;
	uint8_t		fallback_flag;
	uint8_t		mac_adr[6];
	uint32_t	ip_adr;
	uint32_t	ip_netmask;
	uint32_t	ip_gateway;
} LAN_PARAMETER_STORE;

typedef struct {
	byte len;
	byte checksumme;
	byte command;

	byte address;
	word target_mask;

	byte ir_length;
	byte transmit_freq;
	byte mode;

	word pause_len[6];
	word pulse_len[6];
	byte time_cnt;
	byte ir_repeat;
	byte repeat_pause;

	byte data[CODE_LEN];
} IRDATA3;

typedef struct {
	byte len;
	byte checksumme;
	byte command;

	byte address;
	word target_mask;

	byte ir_length;
	byte transmit_freq;
	byte mode;

	byte data[CODE_LENRAW];
} IRRAW;

typedef struct {
	byte len;
	byte checksumme;
	byte command;

	byte address;
	word target_mask;

	byte ir_length;
	byte transmit_freq;
	byte mode;

	byte data[MAXLCDLEN];
} IRRAWLCD;

typedef struct {
	int16_t statuslen;
	int16_t statustype;
  int16_t offset;
  int16_t count_buffer;
	int16_t count_total;
	int16_t count_remaining;
	int8_t remotes[3][80];
} REMOTEBUFFER_INT;


typedef struct {
	uint32_t target_mask;
	uint32_t source_mask;
	int8_t name[80];
} REMOTELINE;

typedef struct {
	int16_t statuslen;
	int16_t statustype;
    int16_t offset;
    int16_t count_buffer;
	int16_t count_total;
	int16_t count_remaining;
	REMOTELINE remotes[3];
} REMOTEBUFFER_SHORT;

typedef struct {
	uint8_t	len;
	uint16_t action_adr;
	uint8_t remote[80];
	uint8_t command[20];
	uint8_t ircommand[150];
} IRRECEIVE;

typedef struct {
	int16_t statuslen;
	int16_t statustype;
	int16_t adress;
    uint16_t command_num;
	int8_t remote[80];
	int8_t command[20];
	int8_t data[150];
} NETWORKRECV_SHORT;


// Mode Flags
#define DEVMODE_PC			0
#define DEVMODE_SEND		1
#define DEVMODE_IR			2
#define DEVMODE_SBUS		4
#define DEVMODE_IRCODE		8
#define DEVMODE_SBUSCODE	16
#define DEVMODE_RAW			32
#define DEVMODE_RAWFAST		64
#define DEVMODE_REPEAT		128

// Extended Mode Flags
#define INTERNAL_LEDS		1
#define EXTERNAL_LEDS		2
#define STANDARD_RCV		4
#define BO_RCV				8
#define BO_MODE				16
#define SELF_REPEAT			32
#define	INTERNAL_REPEAT		64
#define SBUS_UART			128			// Set: SBUS läuft über UART

// Extended Mode2 Flags
#define LRN_TIMEOUT_MASK	7			// Bit 0-2
#define SBUS_BAUD_MASK		24			// Bit 3-4
#define RS232_BAUD_MASK		96			// Bit 5-6			


#define LOCAL_MODE			16
#define	RECEIVE_ALL			17
#define	QUICK_MODE			32
#define RAW_MODE			64
#define REPEAT_MODE			128
#define IR_MODE				256
#define SBUS_MODE			512
#define	INSTANT_MODE		1024



#define SBUS_REPEAT			1
#define HOST_VERSION		2
#define HOST_NETWORK_STATUS	3

#define SBUS_SEND			4
#define SBUS_RESEND			5
#define HOST_SEND			6
#define HOST_RESEND			7


#define SBUS_LEARN			16
#define HOST_LEARNIR		18

#define SBUS_QUICKPARM		48
#define HOST_LEARNIRQUICK	50

#define SBUS_RAWMODE		80
#define HOST_LEARNIRRAW		82

#define SBUS_REPEATMODE		144
#define HOST_LEARNIRREPEAT	146
#define SBUS_RAWREPEATMODE		208
#define HOST_LEARNIRRAWREPEAT	210

#define SBUS_RESET			192
#define SBUS_PING			193
#define SBUS_PONG			194
#define SBUS_PARAMETER		196
#define HOST_SETMODE		197
#define SET_ID				199

#define SET_TRANSLATE_DATA	200
#define SBUS_TRANSLATE_DATA	201
#define READ_TRANSLATE_DATA	202
#define START_FLASH_MODE	203
#define	TRANSFER_FLASH		204
#define	SBUS_SET_MODE2		206
#define	HOST_SET_MODE2		207

#define	HOST_STORE_LANPARM	224
#define	HOST_READ_LANPARM	225
#define	HOST_STORE_FLASH	226
#define	HOST_READ_FLASH		227
#define SEND_IRDB_STRING	228
#define	SEND_IRDB_BLOCK		229
#define	RESEND_IRDB_BLOCK	230
#define IRDB_REMLIST		231
#define IRDB_COMLIST		232
#define HOST_STORE_UDPSTR	233
#define PING_IR_CONTROLLER	234
#define SET_POWER_LED		235

// Ab 240 wieder geblockt


#define	SEND				SBUS_SEND
#define LEARN				SBUS_LEARN
#define	SETMODE				SBUS_PARAMETER

#define ADRESS_MASK			15
#define ADRESS_LOCAL		16
#define ADRESS_ALL			32


#define	START_BIT			1
#define REPEAT_START		2
#define START_MASK			3
#define RC5_DATA			4
#define	RC6_DATA			8
#define IRDA_DATA			12
#define	RAW_DATA			16
#define NO_TOGGLE			2
#define NO_TOGGLE_H			64
#define MACRO_DATA			32


#define LCD_BACKLIGHT		1
#define LCD_TEXT			2


#define LCD_INIT			4
#define LCD_SETTIME			8
#define LCD_DISPLAYTIME		16
#define LCD_DEFINECHAR		12
#define LCD_BRIGHTNESS		20
#define LCD_REFRESHDATE		24

#define	LCD_DATA			32

#define	TEMP_GET			1
#define TEMP_RESET			2
#define TEMP_DATA			64
#define NON_IRMODE			224

#define SWITCH_DATA			96

#define IR_CORRECT_455		1				// Entspricht 8 µs Korrektur

#ifdef B_O
#ifdef IR_CORRECT
#undef IR_CORRECT
#endif
#define IR_CORRECT			IR_CORRECT_455
#else
#ifndef IR_CORRECT
#define IR_CORRECT			8				// Entspricht 64 µs Korrektur
#endif
#endif

#define IR_TOLERANCE_BO		50				// Entspricht 280 µs Toleranz
#define IR_TOLERANCE		15				// Entspricht 120 µs Toleranz
#define RCX_TOLERANCE		19				// Entspricht 152 µs Toleranz
#define MAX_IR_REPEAT		5
#define RAW_TOLERANCE		20

#ifndef AVR

#define FN_IR			1
#define	FN_SBUS			2
#define FN_SER			4
#define FN_USB			8
#define FN_POWERON		16
#define FN_B_O			32
#define FN_TEMP			64
#define FN_SOFTID		128
#define FN_EEPROM		256
#define FN_TRANSL		512
#define FN_HWCARR		1024
#define FN_DUALRCV		2048
#define FN_SBUS_UART	4096
#define FN_FLASH128		8192
#define FN_DUALSND		16384
#define FN_DISP1		32768
#define FN_DISP2		0x10000
#define FN_DISP3		0x20000
#define FN_CLOCK		0x40000
#define FN_DEBOUNCE		0x80000
#define FN_BOOTLOADER	0x100000
#define FN_DUALPOWERON	0x200000
#define FN_USBWAKEUP	0x400000
#define FN_NOSCROLL		0x800000
#define FN_LAN			0x1000000
#define FN_IRDB			0x2000000


#define FUNCTION_FLASH_MASK  ~(FN_SBUS_UART | FN_CLOCK | FN_DEBOUNCE | FN_DUALPOWERON | FN_USBWAKEUP | FN_NOSCROLL)

#endif

#define START			1
#define REPEAT			2


typedef struct {
	byte sbus_len;
	byte sbus_checksumme;
	byte sbus_command;
	byte sbus_address;
	byte mode;
	word target_mask;
	byte hotcode_len;
	byte hotcode[CODE_LENRAW];
} MODE_BUFFER;


typedef struct {
	byte sbus_len;
	byte sbus_checksumme;
	byte sbus_command;
	byte sbus_address;
	byte device_mode;
	word send_mask;
	byte version[10];
	byte extended_mode;
	unsigned long capabilities;
	byte extended_mode2;
} STATUS_LINE;

typedef struct {
	byte sbus_len;
	byte sbus_checksumme;
	byte sbus_command;
	byte sbus_address;
	byte device_mode;
	word send_mask;
	byte version[10];
	byte extended_mode;
	word capabilities;
} STATUS_LINE_3;

typedef struct {
	byte sbus_len;
	byte sbus_checksumme;
	byte sbus_command;
	byte sbus_address;
	byte device_mode;
	word send_mask;
	byte version[10];
	byte extended_mode;
} STATUS_LINE_2;

typedef struct {
	byte sbus_len;
	byte sbus_checksumme;
	byte sbus_command;
	byte sbus_address;
	byte device_mode;
	word send_mask;
	byte version[10];
} STATUS_LINE_1;

typedef struct {
	byte my_adress;
	STATUS_LINE stat[16];
} STATUS_BUFFER;

typedef struct {
	byte my_adress;
	STATUS_LINE_1 stat[16];
} STATUS_BUFFER_1;

typedef struct {
	byte my_adress;
	STATUS_LINE_2 stat[16];
} STATUS_BUFFER_2;

typedef struct {
	byte my_adress;
	STATUS_LINE_3 stat[16];
} STATUS_BUFFER_3;

typedef struct {
	uint8_t netcommand;
	STATUS_LINE stat;
} STATUS_LINE_LAN;


#define IRTRANS_PORT	21000

