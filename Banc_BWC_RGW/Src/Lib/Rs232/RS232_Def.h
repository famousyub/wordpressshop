#ifndef __RS232_H
#define __RS232_H
																			
/* -------------------------------------------------------------------------*
 *	.FICHIERS INCLUS				                                        *
 * -------------------------------------------------------------------------*/

#include "windows.h"

/* -------------------------------------------------------------------------*
 *	.DEFINITIONS DE CONSTANTES					                            *
 * -------------------------------------------------------------------------*/

// Constantes d'erreur
#define RS232_ERREUR				-100
#define RS232_PB_ALLOC_DYNAMIQUE	(RS232_ERREUR - 1)
#define RS232_PORT_DEJA_OUVERT		(RS232_ERREUR - 2)
#define RS232_PB_OUVERTURE_PORT		(RS232_ERREUR - 3)
#define RS232_PB_RECUP_INFO_PORT	(RS232_ERREUR - 4)
#define RS232_PB_PARAMETRAGE_PORT	(RS232_ERREUR - 5)
#define RS232_PB_FERMETURE_PORT		(RS232_ERREUR - 6)
#define RS232_PB_ID					(RS232_ERREUR - 7)		 
#define RS232_PB_LIBERATION_MEM		(RS232_ERREUR - 8)
#define RS232_PB_ECRITURE_PORT		(RS232_ERREUR - 9)
#define RS232_PB_ENVOI_CHAINE		(RS232_ERREUR - 10)
#define RS232_PB_RAZ_BUFFER_TX_RX	(RS232_ERREUR - 11)
#define RS232_PB_RAZ_BUFFER_TX		(RS232_ERREUR - 12)
#define RS232_PB_RAZ_BUFFER_RX		(RS232_ERREUR - 13)
#define RS232_PB_CONF_BUF_HARD		(RS232_ERREUR - 14)
#define RS232_GESTION_ASSYNCHRONE	(RS232_ERREUR - 15)
#define RS232_PB_ALLOC_BUF_CYCL		(RS232_ERREUR - 16)
#define RS232_PB_EVEN_PORT_RX_CAR	(RS232_ERREUR - 17)
#define RS232_PB_TACHE_RECEPTION	(RS232_ERREUR - 18)
#define RS232_PB_CREATION_MUTEX		(RS232_ERREUR - 19)
#define RS232_PB_SUPPRESSION_MUTEX	(RS232_ERREUR - 20)
#define RS232_PB_SUPRESSION_TACHE	(RS232_ERREUR - 21)
#define RS232_PB_ALLOC_BUF_INTER	(RS232_ERREUR - 22)
#define RS232_PB_LECTURE_PORT		(RS232_ERREUR - 23)
#define RS232_TAG_NON_TROUVE		(RS232_ERREUR - 24)
#define RS232_PB_ALLOC_BUF_TEMP		(RS232_ERREUR - 25)
#define RS232_TAG_SUITE_TROPS_GRAND	(RS232_ERREUR - 26)
#define RS232_BUF_CIBLE_TROPS_PETIT	(RS232_ERREUR - 27)
#define RS232_PB_THREAD_RX			(RS232_ERREUR - 28)

// Autres
#define RS232_COM_TIME_OUT			1.0			// Définition du TimeOut en lecture et écriture en seconde
#define RS232_MINI_CHAINE			10			// Taille max buffer pour mise en formes de petites chaines de caractères	
#define RS232_MSG_LEN				4096		// Taille max d'un message d'erreur
#define RS232_BUF_SOFT_RX_DEFAUT	4096		// Taille par défaut du buffer cyclique logiciel de réception 
#define RS232_BUF_HARD_RX_DEFAUT	4096		// Taille buffer matériel de réception
#define RS232_BUF_HARD_TX_DEFAUT	4096		// Taille buffer matériel d'émission
#define RS232_SYNC					0			// Mode de gestion synchrone à l'ouverture du port
#define RS232_ASSYNC				1			// Mode de gestion assynchrone à l'ouverture du port
#define RS232_DEL_MIN				1			// Delai intercaractère minimum (ms)
#define RS232_DEL_MAX				250			// Delai intercaractère maximum (ms)
#define RS232_TAILLE_BUF_CYCL_RX	4096		// Taille par defaut du buffer logiciel cyclique de réception (doit être >= à RS232_BUF_HARD_RX_DEFAUT)  
#define RS232_TITRE_ERREUR_DLL   	"Erreur DLL sur tache de réception"
#define RS232_TROUV_OUI				1			// Tag trouvé
#define RS232_TROUV_NON				0			// Tag introuvable
#define RS232_PARITE_NO				0			// Pas de parite
#define RS232_PARITE_ODD			1			// Parite de type "odd" (anglais)
#define RS232_PARITE_EVEN			2			// Parite de type "even" (anglais)
#define RS232_PARITE_MARK			3			// Parite de type "mark" (anglais)
#define RS232_PARITE_SPACE			4			// Parite de type "Space" (anglais)
#define RS232_BITSTOP_UN			0			// 1 bit de stop
#define RS232_BITSTOP_UNDEMI		1			// 1.5 bit de stop
#define RS232_BITSTOP_DEUX			2			// 2 bit de stop
#define RS232_NON					0			// Flag non universel (RS232)
#define RS232_OUI					1			// Flag oui universel (RS232)
#define RS232_HANDSHAKE				2			// Contrôle de flux de type "handshake" (anglais)
#define RS232_TOGGLE				3			// Contrôle de flux de type "toggle" (anglais)
#define RS232_EXEC					0			// Flag d'exécution des taches
#define RS232_STOP					1			// Flag d'arret des taches


// Etat de la tâche de réception
#define RS232_STATE_SYNC			0			// Etat Réception : Mode Synchrone
#define RS232_STATE_ASYNC_INIT		1			// Etat Réception : Mode Asynchrone initialisation
#define RS232_STATE_ASYNC_WAIT		2			// Etat Réception : Mode Asynchrone attente de réception de données
#define RS232_STATE_ASYNC_RCV		3			// Etat Réception : Mode Asynchrone réception de donnée


/* -------------------------------------------------------------------------*
 *	.DEFINITIONS DE TYPES						                            *
 * -------------------------------------------------------------------------*/

// Structure contenant les paramètres demandés à l'ouverture d'un port en mode EXPERT
typedef struct T_RS232_CFG_EXPERT
{
	int				numPort;					// Numéro du port : 1, 2...
	int				syncAssync;					// Mode de gestion synchrone/assynchrone defini à l'ouverture du port (synchrone = RS232_SYNC = 0, assynchrone = RS232_ASSYNC = 1)   
	unsigned long 	baud;						// Vitesse du port : de 110, 300, 600, 1200, 4800, 9600, 14400, 19200, 38400, 56000, 57600, 115200, 128000, 256000.
	unsigned char	bitDonnee;					// Nombre de bit de données : de 4 à 8
	unsigned char	parite;						// Parité ("no" = RS232_PARITE_NO = 0, "odd" = RS232_PARITE_ODD = 1, "even" = RS232_PARITE_EVEN = 2, "mark" = RS232_PARITE_MARK = 3, "space" = RS232_PARITE_SPACE = 4)
	unsigned char	bitStop;					// Nombre de bit de stop ("1" = RS232_BITSTOP_UN = 0, "1.5" = RS232_BITSTOP_UNDEMI = 1, "2" = RS232_BITSTOP_DEUX = 2)  
	unsigned long   testParite: 1;				// Test de parité actif (non = RS232_NON = 0, oui = RS232_OUI = 1)  
	unsigned long   ctrlFluxCTS: 1;				// Contrôle de flux CTS (non = RS232_NON = 0, oui = RS232_OUI = 1)
	unsigned long   ctrlFluxDSR: 1;				// Contrôle de flux DSR (non = RS232_NON = 0, oui = RS232_OUI = 1)
	unsigned long   ctrlFluxDTR: 2;				// Contrôle de flux DTR (non = RS232_NON = 0, oui = RS232_OUI = 1, "handshake" = RS232_HANDSHAKE = 2)
	unsigned long   sensitiviteDSR: 1;			// Sensitivité DSR (non = RS232_NON = 0, oui = RS232_OUI = 1)
	unsigned long   xoffTXcontinue:	1;			// XOFF, TX continue (non = RS232_NON = 0, oui = RS232_OUI = 1)
	unsigned long   xonxoffCtrlFluxTX: 1;		// XON/XOFF contrôle de flux TX (non = RS232_NON = 0, oui = RS232_OUI = 1)
	unsigned long   xonxoffCtrlFluxRX: 1;		// XON/XOFF contrôle de flux RX (non = RS232_NON = 0, oui = RS232_OUI = 1)
	unsigned long   remplacErreur: 1;			// Remplacement d'erreur actif (non = RS232_NON = 0, oui = RS232_OUI = 1)
	unsigned long   sautOctetNul: 1;			// Saut des octets nuls actif (non = RS232_NON = 0, oui = RS232_OUI = 1)
	unsigned long   ctrlFluxRTS: 2;				// Contrôle de flux RTS (non = RS232_NON = 0, oui = RS232_OUI = 1, "handshake" = RS232_HANDSHAKE = 2, "toggle" = RS232_TOGGLE = 3) 
	unsigned long   genErrTxInterompu: 1;		// Générer une erreur lors d'un transfert interrompu (non = RS232_NON = 0, oui = RS232_OUI = 1)
	unsigned short	seuilXonTx;					// Seuil XON TX (nombre d'octet)
	unsigned short	seuilXoffRx;				// Seuil XOFF TX (nombre d'octet)
	char 			carXonTxRx;					// Charactère XON TX et RX
	char 			carXoffTxRx;				// Charactère XOFF TX et RX
	char   			carRemplacErrPar;			// Charactère de remplacement lors d'une erreur de parité
	char   			carEOF;						// Charactère de fin de transfert (EOF)
	char   			carEVT;						// Charactère signalant un evènement reçu
}	T_RS232_CFG_EXPERT;

// Structure contenant les paramètres demandés à l'ouverture d'un port en mode non EXPERT
typedef struct T_RS232_CFG
{

	int				numPort;					// Numéro du port : 1, 2...  
	int				syncAssync;					// Mode de gestion synchrone/assynchrone defini à l'ouverture du port (synchrone = RS232_SYNC = 0, assynchrone = RS232_ASSYNC = 1)   
	unsigned long 	baud;						// Vitesse du port : de 110, 300, 600, 1200, 4800, 9600, 14400, 19200, 38400, 56000, 57600, 115200, 128000, 256000.
	unsigned char	bitDonnee;					// Nombre de bit de données : de 4 à 8
	unsigned char	parite;						// Parité ("no" = RS232_PARITE_NO = 0, "odd" = RS232_PARITE_ODD = 1, "even" = RS232_PARITE_EVEN = 2, "mark" = RS232_PARITE_MARK = 3, "space" = RS232_PARITE_SPACE = 4)
	unsigned char	bitStop;					// Nombre de bit de stop ("1" = RS232_BITSTOP_UN = 0, "1.5" = RS232_BITSTOP_UNDEMI = 1, "2" = RS232_BITSTOP_DEUX = 2)  
	unsigned long   testParite;					// Test de parité actif (non = RS232_NON = 0, oui = RS232_OUI = 1)   
}	T_RS232_CFG;	

// Structure contenant l'ensemble des paramétres d'un port série
typedef struct T_RS232_COM
{
	HANDLE 			idCom;						// Identifiant d'un port (Windows SDK) 
	DCB 			dcbCom;						// Structure de parametres d'un port (Windows SDK)
	int				numCom;						// Numero du port com
	char			nomCom[RS232_MINI_CHAINE];		// Nom du port com (exemple COM2)
	int				syncAssync;					// Mode de gestion synchrone/assynchrone defini à l'ouverture du port (synchrone = RS232_SYNC = 0, assynchrone = RS232_ASSYNC = 1)
	unsigned char	*bufRxCycl;					// Buffer logiciel cyclique pour réception
	unsigned long	taillBufRxCycl;				// Taille du buffer logiciel cyclique pour réception
	unsigned long	ptFin;						// Index de fin du buffer (équivalent pointeur d'écriture = les données directement derrières ce pointeur sont les plus récentes) ; (compté à partir de 0)
	unsigned long	ptDeb;						// Index de début du buffer (les données directement dessous ce pointeur sont les moins récentes) ; (compté à partir de 0)
	unsigned long	ptCop;						// Index de copie du buffer (les données directement dessous ce pointeur sont copiées jusqu'au données précédant l'index ptFin)
	int				bufRxCyclEstVide;			// Flag indiquant si le buffer de réception est vide ou non
	int				ghpool;						// Identifiant du pouleur de tache
	int				tacheReceptionID;			// Identifiant de la tache de réception
	volatile int	tacheExist;					// Flag permettant l'execution de la tache (stop = RS232_STOP = 1, execute = RS232_EXEC = 0)  
}	T_RS232_COM;

// Structure contenant tous les paramètres globaux
typedef struct T_RS232_PORT
{
	T_RS232_COM		*com;						// Pointeur sur structure de type T_COM pour parametrage de plusieurs ports	
	int				nbPort;						// Nombre de port ouverts
	int				*mutex;						// Pointeur sur table de sémaphores type Mutex pour sécuriser l'accés aux paramètres d'un port (évite plantage dans le cas d'une réallocation mémoire lors de la suppression d'un port)
	int				numPortMax;					// Contient le numéro du port com le plus élevé
}   T_RS232_PORT;
					
/* -------------------------------------------------------------------------*
 *	.DEFINITIONS DE MACROS						                            *
 * -------------------------------------------------------------------------*/

#endif //__RS232_H 

/* -------------------------------------------------------------------------*
 *	.DECLARATIONS DE PROTOTYPES (PROCEDURES / FONCTIONS)					*
 * -------------------------------------------------------------------------*/

#ifdef RS232_C
#define GLOBAL 
#else
#define GLOBAL extern
#endif //RS232_C 

// RS232_Main (contient tout ce qui est : ouverture, fermeture, action sur la partie RS232 interne au PC)
GLOBAL int __declspec(dllexport) __stdcall RS232_MAIN_OpenPort(int *hdlSession, T_RS232_CFG paramPort, short *errorOccurred, long *errorCode, char errorMsg[1024]); 

GLOBAL int __declspec(dllexport) __stdcall RS232_MAIN_ClosePort(int hdlSession, short *errorOccurred, long *errorCode, char errorMsg[1024]); 

GLOBAL int __declspec(dllexport) __stdcall RS232_MAIN_PurgeTxPort(int hdlSession, short *errorOccurred, long *errorCode, char errorMsg[1024]);

GLOBAL int __declspec(dllexport) __stdcall RS232_MAIN_PurgeRxPort(int hdlSession, short *errorOccurred, long *errorCode, char errorMsg[1024]);

GLOBAL int __declspec(dllexport) __stdcall RS232_MAIN_Nettoyage(void);

GLOBAL int __declspec(dllexport) __stdcall RS232_MAIN_ErrorManager(int device, long errorCode, char errorMessage[]);

// RS232_Conf (contient tout ce qui est : ecriture, configuration pour l'appareil connecté sur RS232 du PC)
GLOBAL int __declspec(dllexport) __stdcall RS232_CONF_EcrirePort(int hdlSession, unsigned char *ecrire, unsigned long lngEcrire, short *errorOccurred, long *errorCode, char errorMsg[1024]); 

GLOBAL int __declspec(dllexport) __stdcall RS232_CONF_EcrirePortTestStand(int hdlSession, char *ecrire, unsigned long lngEcrire, short *errorOccurred, long *errorCode, char errorMsg[1024]); 

// RS232_Meas (contient tout ce qui est : lecture, measure pour l'appareil connecté sur RS232 du PC)
GLOBAL int __declspec(dllexport) __stdcall RS232_MEAS_LectureBuffer(int hdlSession, unsigned char *buffer, unsigned long *tailleCopie, unsigned long dimMaxBuf, unsigned long *dimBuf, short *errorOccurred, long *errorCode, char errorMsg[1024]);

GLOBAL int __declspec(dllexport) __stdcall RS232_MEAS_LectureBufPattern(int hdlSession, char *sBuffer, unsigned long ulTailleBuffer, unsigned long *ulBufInfo, char sPatternCherche[100], double dTimeout, short *errorOccurred, long *errorCode, char errorMsg[1024]);

// RS232_Meas (contient tout ce qui est : lecture, measure pour l'appareil connecté sur RS232 du PC)
GLOBAL int __declspec(dllexport) __stdcall RS232_MEAS_RechercheTag(int hdlSession, unsigned char *tag, unsigned long lngTag, unsigned char carFinTag, unsigned char *tagSuite, unsigned long *lngTagSuite, unsigned long dimMaxTagSuite, unsigned long *posTag, unsigned long *dimBuf, int *tagTrouv, short *errorOccurred, long *errorCode, char errorMsg[1024]);

#undef RS232_C
