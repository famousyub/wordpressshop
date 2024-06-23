#include <userint.h>

#include <tcpsupp.h>
#include "toolbox.h"
#include <formatio.h>
#include <utility.h>
#include <cvintwrk.h>
#include <ansi_c.h>
#include "Define.h"
int	BasePortParallele ;
int totPorts = 0 ;
int gEvent=0;
int gConnected=0;
char sReadBuferAdsl[50000]="";

#define DataReg	BasePortParallele



/*****************************************************************************************/
/*																						 */
/*																						 */
/*																						 */
/*****************************************************************************************/
void AfficheInfo (int mode, int codeErr, ...)
{
	char buffer[TAILLE_MAX_CHAINE] = "";
	va_list list;   
	// Récupération du message d'erreur complet
	va_start (list, codeErr);
	switch (codeErr)
	{
		case ERREUR_ALLOC_RESOURCE :strncpy (buffer, "Erreur 001 : Allocation des ressources systèmes impossibles",TAILLE_MAX_CHAINE-1);break;
		case ERREUR_OTHER_INSTANCE :strncpy (buffer, "Erreur 002 : Cette application est déjà ouverte",TAILLE_MAX_CHAINE-1);break;
		case ERREUR_INI :strncpy (buffer, "Erreur 100 : Lecture du fichier INI impossible. Le logiciel ne peut pas démarrer",TAILLE_MAX_CHAINE-1);break;
		case ERREUR_GEST_SEQ_OPEN :vsprintf (buffer, "Erreur 200 : Connexion à la base de paramétrage impossible (séquence %s). Le logiciel ne peut pas démarrer\n[%s]", list);break;
		case ERREUR_GEST_SEQ_READ :vsprintf (buffer, "Erreur 201 : Impossible de lire le paramètre [%s] dans la base de paramétrage. Le logiciel ne peut pas démarrer\n[%s]", list);break;
		case ERREUR_BASE_DE_REGISTRE :vsprintf (buffer, "Erreur 300 : Configuration du serveur Tftp dans la base de registre impossible. Le logiciel ne peut pas démarrer\n[%s]", list);break;
		case ERREUR_BASE_DE_TRACA :vsprintf (buffer, "Erreur 400 : Problème de connexion à la base de tracabilité. Le logiciel ne peut pas démarrer\n[%s]", list);break;
		case ERREUR_SEQ_APPAIRAGE_OPEN :vsprintf (buffer, "Erreur 500 : Connexion à la base de paramétrage impossible. Il est impossible d'acceder à la séquence d'appairage\n[%s]", list);break;
		case ERREUR_SEQ_APPAIRAGE_RAZ :vsprintf (buffer, "Erreur 501 : Impossible d'effacer le poste dans la séquence d'appairage\n[%s]", list);break;
		case ERREUR_CONFIG_IP_CARTE_ETH :vsprintf (buffer, "Erreur 600 : Configuration de l'adresse de la carte réseau impossible. Mettre l'adresse manuellement\n[%s]", list);break;
		default :vsprintf (buffer, "%s", list);break;
	}
	// Affichage suivant le mode défini
	if (mode == MODE_POPUP_INFO)
		MessagePopup ("Information", buffer);
	else if (mode == MODE_POPUP_ERREUR)
		MessagePopup ("Erreur", buffer);
	return;
}

/*****************************************************************************************/
/*																						 */
/*																						 */
/*																						 */
/*****************************************************************************************/

 int Telnet_Query_thread (int handletelnet,char *Question,char *Tag,char *reponse,int TimeOutms)
{
    int erreur=0;
    char response[TAILLE_MAX_CHAINE]="";
    int iNumBytWritten=0;
    
    int debCLK,bytesread,PosTag=-1;
    
    
    ClearBufferTelnet(handletelnet);
    SetBreakOnLibraryErrors (0);
    erreur = InetTelnetWrite (handletelnet, Question, "\r\n", -1, &iNumBytWritten, 3000);
    ProcessDrawEvents() ;
    if ( !erreur)
        {
           
            debCLK=clock();
        //erreur = InetTelnetReadUntil (handletelnet, response, sizeof (response) - 1, Tag, TimeOutms);
           do
           {
            InetTelnetRead (handletelnet, response, sizeof (response) - 1, &bytesread, 3000);
             PosTag = FindPattern (response, 0, -1, Tag, 0, 0); 
			 
			 	
			 
           }while (PosTag==-1  &&  (clock()-debCLK<TimeOutms));
       
        ProcessDrawEvents() ;
        }
	
	//ligneDansHisto (response,1);
	
    strncpy(reponse,response,TAILLE_MAX_CHAINE-1);
	
    SetBreakOnLibraryErrors (1);         
    return (PosTag >=0 ? 0 : 1);// 0 si Bon 
}
/*****************************************************************************************/
/*																						 */
/*																						 */
/*																						 */
/*****************************************************************************************/
 
 int DisconnectTelnetThread(int handle)
{
	int result=0; 
	
	result=InetTelnetClose (handle);
	ProcessDrawEvents();
	
	return result;
	
}

/*****************************************************************************************/
/*																						 */
/*																						 */
/*																						 */
/*****************************************************************************************/
 int ConnectTelnetThread(char * Ip,int *handleTelnet)
{
	 
	*handleTelnet = InetTelnetOpen (Ip, 23, 0);
	ProcessDrawEvents();
    return *handleTelnet;
	
}
/*****************************************************************************************/
/*																						 */
/*																						 */
/*																						 */
/*****************************************************************************************/
 
 
 /*int Telnet_Query(int handleTelnet, char *Question,char *Tag,char *reponse,char *signal,int TimeOutms)
{
	int erreur=0;
	char response[1000]="";
	int iNumBytWritten=0;
	int iLog=0;
	//int	nItfe = tSlot->id;
	//T_TAB_CMD tabCmdTelnet;


    // ==========================================
    // = Extraction des commandes TT à exécuter =
    // ==========================================
    //errChk (FCT_CmdComExtract (Question, &tabCmdTelnet));
    
	
	ClearBufferTelnet(handleTelnet); 
	SetBreakOnLibraryErrors (0);
	erreur = InetTelnetWrite (handleTelnet , Question, "\n", -1, &iNumBytWritten, 3000); 
	ProcessDrawEvents() ;
	if ( !erreur)
		{
		Delay(0.5);
		erreur = InetTelnetReadUntil (handleTelnet, response, sizeof (response) - 1, Tag, TimeOutms);
		ProcessDrawEvents() ;
		}
	strcpy(reponse,response);
	SetBreakOnLibraryErrors (1);
	if (erreur ==0)
		return 1;
	else
		return erreur;
		   //? 0 : 1);// 0 si Bon	
}//Fin de int Telnet_Query (char *Question,char *Tag,char reponse,int TimeOutms) */




/*****************************************************************************************/
/*																						 */
/*																						 */
/*																						 */
/*****************************************************************************************/

  int Telnet_QueryThread_2G (int handleTelnet, char *Question,char *Tag,char *reponse,int TimeOutms)
{
	int erreur=0;
	char response[TAILLE_MAX_CHAINE]="";
	int iNumBytWritten=0;
	int iLog=0;
	 
	ClearBufferTelnet_2G(handleTelnet); 
	SetBreakOnLibraryErrors (0);
	erreur = InetTelnetWrite (handleTelnet , Question, "\n", -1, &iNumBytWritten, 3000); 		 
	ProcessDrawEvents() ;
	if ( !erreur)
		{
		//Delay(1);
		erreur = InetTelnetReadUntil (handleTelnet, response, sizeof (response) - 1, Tag, TimeOutms);
		ProcessDrawEvents() ;
		}
	strncpy(reponse,response,TAILLE_MAX_CHAINE-1);
	SetBreakOnLibraryErrors (1);		 
	return (erreur >=0 ? 0 : 1);// 0 si Bon	
}//Fin de int Telnet_Query (char *Question,char *Tag,char reponse,int TimeOutms)
  
/*****************************************************************************************/
/*																						 */
/*																						 */
/*																						 */
/*****************************************************************************************/

 int ClearBufferTelnet_2G(int iFlagTelnet)
{
int Octetslus=0;
char buffer[20000];
int erreur=0;

	do
	{	
	 erreur=InetTelnetRead (iFlagTelnet,buffer,sizeof(buffer)-1, &Octetslus, 500);
	} while (Octetslus >0); 
return ( erreur);	
}


/*****************************************************************************************/
/*																						 */
/*																						 */
/*																						 */
/*****************************************************************************************/

 int ClearBufferTelnet(int iFlagTelnet)
{
int Octetslus=0;
char buffer[500];
int erreur=0;

	do
	{	
	 erreur=InetTelnetRead (iFlagTelnet,buffer,sizeof(buffer)-1, &Octetslus, 50);
	} while (Octetslus >0); 
return ( erreur);	
}


/*****************************************************************************************/
/*																						 */
/*																						 */
/*																						 */
/*****************************************************************************************/

int UpdateIHM (void)
{
	ProcessDrawEvents();
	ProcessSystemEvents();
	return 0;
}


/*****************************************************************************************/
/*																						 */
/*																						 */
/*																						 */
/*****************************************************************************************/

int ClearBufferTelnet_5G(int iFlagTelnet)
{
int Octetslus=0;
char buffer[20000];
int erreur=0;

	do
	{	
	 erreur=InetTelnetRead (iFlagTelnet,buffer,sizeof(buffer)-1, &Octetslus, 500);
	} while (Octetslus >0); 
return ( erreur);	
}



 
/*****************************************************************************************/
/*																						 */
/*																						 */
/*																						 */
/*****************************************************************************************/
int Telnet_Query_TME(int handleTelnet,char *reponse,int TimeOutms)
{
	int erreur=0;
	char response[TAILLE_MAX_CHAINE]="";
	int iNumBytWritten=0;
	int iLog=0;
	 
		SetBreakOnLibraryErrors (0);
		ProcessDrawEvents() ;
		if ( !erreur)
		{
			//Delay(1);
			erreur = InetTelnetRead(handleTelnet, response, sizeof (response) - 1, NULL, TimeOutms);
			ProcessDrawEvents() ;
		}
		strncpy(reponse,response,TAILLE_MAX_CHAINE-1);
		SetBreakOnLibraryErrors (1);		 
	return (erreur >=0 ? 0 : 1);// 0 si Bon	
}

/*****************************************************************************************/
/*																						 */
/*****************************************************************************************/

  int Telnet_Query_TBR6_FP(int handleTelnet, char *Question,char *Tag,char *reponse,int TimeOutms)
{
	int erreur=0;
	char response[TAILLE_MAX_CHAINE]="";
	int iNumBytWritten=0;
	int iLog=0;
	 
	ClearBufferTelnet_5G(handleTelnet); 
	SetBreakOnLibraryErrors (0);
	erreur = InetTelnetWrite (handleTelnet , Question, "\0", -1, &iNumBytWritten, 3000); 		 
	ProcessDrawEvents() ;
	if ( !erreur)
		{
		//Delay(1);
		erreur = InetTelnetReadUntil (handleTelnet, response, sizeof (response) - 1, Tag, TimeOutms);
		ProcessDrawEvents() ;
		}
	strncpy(reponse,response,TAILLE_MAX_CHAINE-1);
	SetBreakOnLibraryErrors (1);		 
	return (erreur >=0 ? 0 : 1);// 0 si Bon	
}
  
/*****************************************************************************************/
/*																						 */
/*****************************************************************************************/
int Telnet_Query_GPIO(int handleTelnet, char *Question,char *Tag,char *reponse,int TimeOutms)
{
	int erreur=0;
	char response[TAILLE_MAX_CHAINE]="";
	int iNumBytWritten=0;
	int iLog=0;
	 
	ClearBufferTelnet_5G(handleTelnet); 
	SetBreakOnLibraryErrors (0);
	erreur = InetTelnetWrite (handleTelnet , Question, "\n", -1, &iNumBytWritten, 3000); 		 
	ProcessDrawEvents() ;
	if ( !erreur)
		{
		//Delay(1);
		erreur = InetTelnetReadUntil (handleTelnet, response, sizeof (response) - 1, Tag, TimeOutms);
		ProcessDrawEvents() ;
		}
	strncpy(reponse,response,TAILLE_MAX_CHAINE-1);
	SetBreakOnLibraryErrors (1);		 
	return (erreur >=0 ? 0 : 1);// 0 si Bon	
}
  
/*****************************************************************************************/
/*																						 */
/*****************************************************************************************/
 int Telnet_Query_Festo (int handleTelnet, char *Question,char *Tag,char *reponse,char *signal,int IndiceCMMO,int TimeOutms)
{
	int erreur=0;
	char response[TAILLE_MAX_CHAINE]="";
	int iNumBytWritten=0;
	int iLog=0;
	double Position;
	double ValVelocity =120.000;
	double ValAcceleration=330.400;
	//int	nItfe = tSlot->id;
	//T_TAB_CMD tabCmdTelnet;


    // ==========================================
    // = Extraction des commandes TT à exécuter =
    // ==========================================
    //errChk (FCT_CmdComExtract (Question, &tabCmdTelnet));
    
	
	ClearBufferTelnet(handleTelnet); 
	SetBreakOnLibraryErrors (0);
	erreur = InetTelnetWrite (handleTelnet , Question, "\n", -1, &iNumBytWritten, 3000); 
	ProcessDrawEvents() ;

		if (strcmp (signal,"RCD") == 0)
		Position=Position-100;
		
		if (strcmp (signal,"RCG") == 0)
		Position=Position+100;
	
	if ( !erreur)
		{
		Delay(0.5);
		erreur = InetTelnetReadUntil (handleTelnet, response, sizeof (response) - 1, Tag, TimeOutms);
		ProcessDrawEvents() ;
		}
	strncpy(reponse,response,TAILLE_MAX_CHAINE-1);
	SetBreakOnLibraryErrors (1);
	if (erreur ==0)
		return 1;
	else
		return erreur;
		   //? 0 : 1);// 0 si Bon	
}//Fin de int Telnet_Query (char *Question,char *Tag,char reponse,int TimeOutms)


int Telnet_Query (int HandleTelnet,char *Question,char *Tag,char *Response,char *signal,int TimeOutms)
{
	int iErreur=1;// Mauvais par defaut
	int Done=0;
	int iNumBytWritten=0;
	int iLog=0;
	char sMessage[TAILLE_MAX_CHAINE]="";
	
	SetBreakOnLibraryErrors (0);
	
	ClearBufferTelnet(HandleTelnet);
	
	Done = InetTelnetWrite (HandleTelnet , Question, "\n", -1, &iNumBytWritten, 1000); 		 
	//Sleep(150);
	if ( !Done)
		{
			Done = InetTelnetReadUntil (HandleTelnet, sMessage, sizeof (sMessage) - 1, Tag, TimeOutms); 
		 	if (Done)
			iErreur = ERREUR_TELNET_LECTURE; 
		}
	
	else 
		iErreur = ERREUR_TELNET_ECRITURE;   
			 
		SetBreakOnLibraryErrors (1);
		strncpy(Response,sMessage,TAILLE_MAX_CHAINE-1);
		
	return (iErreur);	// 1 si Bon	
}
