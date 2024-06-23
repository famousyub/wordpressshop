
//   ********************************************    									 
//   *				INCLUDE				        *	 									 
//   ******************************************** 

#include <windows.h>
#include <cvirte.h> 
#include <utility.h>
#include <ansi_c.h>
#include <userint.h>
#include <stdio.h>
#include <stdlib.h>
#include <formatio.h>
//#include "toolbox.h"
#include "cvidef.h"
#include "cvirte.h"
#include "RS232_SDK.h"
//#include "InterfacePrincipale.h"
#include "inifile.h"
//#include "fil2loN.h"
//#include "IrRs232.h" 
//#include "NiPciDio96.h"
//#include <NIDAQmx.h>
//#include "AutotestDIO.h"

#define version_sw "Banc Telecommande Multi-Protocole rf4ce"
#define TitleSelectSTB "STB Référence"
#define TitleProcessTest "Process Test Télécommande"
//   ********************************************    									 
//   *				DEFINE				        *	 									 
//   ********************************************

		   




// Taille des chaines
#define COMMANDE_LONG_MAX			2048				// taille max de la commande envoyée au décodeur
#define REPONSE_LONG_MAX			2048	
#define RS232_MSG_LEN				4096				// Taille max d'un message d'erreur 
#define MSG_ERROR_LEN				2048				// longueur message d'erreur   
		
// Fichier .INI


#define MAX_PATHNAME_LEN  260    /* includes nul byte */
#define MAX_DRIVENAME_LEN   3    /* includes nul byte */
#define MAX_DIRNAME_LEN   256    /* includes nul byte */
#define MAX_FILENAME_LEN  256    /* includes nul byte */

//DLL PCDIO

//#define STATUS_OK			"S_OK"		//	statue renvoyé par NIPCIDIO96_MAIN_AjouterSignal:  Statut (pas d'erreur = S_OK, erreur = S_FALSE).

//   ********************************************    									 
//   *				CALLBACKS				    *	 									 
//   ********************************************

#define  PANEL_QUIT                       2       /* callback function: CB_QUIT */
#define  PANEL_START                      3       /* callback function: CB_START */		


//   ********************************************    									 
//   *				MESSAGE UTILISATEUR		    *	 									 
//   ********************************************


#ifdef LANGUE_FRANCAIS

	
		

	
 
				
	
// Autre langue
#else

#endif

// COMMANDES et buffers attendus


#define COMMANDE_DEC2				"blast_test\r"
#define COMMANDE_DEC3				"BLAST_Read\r"
#define BUFFER_DEC3					"NEC"


 
//type d'affichage avec AfficheInfo



#define AFFICHAGE_TRACE				TRUE

//#define S_OK						1				//status renvoyé par la DLL dio quand il n'y a pas d'erreur
//#define S_FALSE						0				//status renvoyé par la DLL dio quand il y a une erreur

 
// valeur booleen
#define FALSE							0						// faux
#define TRUE							1						// vrai




//   ********************************************    									 
//   *				STRUCTURE				    *	 									 
//   ********************************************

//structure des proprietes de config
typedef struct {
char NameKey[50];	
char CodeKey[50];
int numKey;

} T_PROPRIETES_CONFIG;

//structure des ihm led
typedef struct {

int  id_ihm_led;//l'id de l'ihm de LED ....
}

T_PROPRIETES_IHM_LED;




/****************************** == PROTOTYPES INTERNES == *******************************/ 

int  ChargeConfigTelecommande (void);
int  CreationIhmLed (int nb_led,int StartTop,int Start_Left);
int  GetCfgTlcFiles (char *patch);
int  creationlog (void);
int repetertest (void);
