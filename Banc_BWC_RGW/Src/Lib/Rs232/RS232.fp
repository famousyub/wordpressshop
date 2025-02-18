s��        S�    HO  �        ����                                                               RS232                                                                                                 	p    Ce module comprend un ensemble de fonctions pour l'utilisation des ports COM au standard RS232.

Ces fonctions permettent d'ouvrir, fermer, param�trer un ou plusieurs ports, mais aussi lire, �crire, rechercher un tag ... sur un ou plusieurs ports.

La particularit� de cette biblioth�que est l'utilisation des fonctions Windows SDK pour la gestion des ports COM, au lieu des librairies conventionelles Labwindows RS-232.

L'ouverture et la fermeture d'un port est totalement dynamique.

La lecture sur un port est faite sur l'�v�nement  "caract�re 
re�u" et est g�r�e au sein d'une tache. Il y a autant de taches que de ports ouverts.

La tache de r�ception remplit un buffer cyclique de r�ception. Les fonctions de recherche de tag ou encore de lecture du buffer agissent � partir de ce buffer cyclique.

Une gestion par identifiant de port facilite l'utilisation des fonctions de la biblioth�que.

Pour l'utilisation de ce module :
  #include "RS232.h"

Pour exemple, consulter la fonction main du fichier RS232_Main.c.

Si des modifications sont apport�es � cette biblioth�que, merci de renseigner les ent�tes des fonctions et des fichiers. Il faudra penser aussi � mettre � jour l'aide.

Cette biblioth�que peut �tre utilis�e via TESTSTAND en utilisant son format DLL. Les fonctions non utilisable avec TESTSTAND (format non respect�) sont clairement identifi�es par un message l'indiquant.


Exemple d'utilisation :

#include "RS232.h"

int main (int argc, char *argv[])
{

T_RS232_CFG stParamPort;
int iIDPort;

short erreur = 0;
long codeErreur = 0;
char messagErreur[RS232_MSG_LEN] = {"\0"};
unsigned long lBufInfo =0;
char sBufRS232[4096]={"\0"};


stParamPort.numPort=1;
stParamPort.syncAssync=RS232_ASSYNC;
stParamPort.baud=38400;
stParamPort.bitDonnee=8;
stParamPort.parite=RS232_PARITE_NO;
stParamPort.bitStop=RS232_BITSTOP_UN;
stParamPort.testParite=RS232_NON;

RS232_MAIN_OpenPort(&iIDPort, stParamPort, &erreur, &codeErreur, messagErreur);
RS232_MAIN_RazBufferCycliqueRx (iIDPort, &erreur, &codeErreur, messagErreur);
//Envoi de "Machaine\r"
RS232_CONF_EcrirePort (iIDPort, "Machaine\r",strlen("Machaine\r"), &erreur, &codeErreur, messagErreur);
//Lecture avec recherche de la chaine "ST7100 >"
RS232_MEAS_LectureBufPattern(iIDPort, sBufRS232, 4096 ,&lBufInfo, "ST7100 >",2.0, &erreur, &codeErreur, messagErreur);
RS232_MAIN_ClosePort(iIDPort, &erreur, &codeErreur, messagErreur);

return 0;
}




     s    Ensemble de fonctions contenant tout ce qui est : ouverture, fermeture, action sur la partie RS232 interne au PC.     u    Ensemble de fonctions contenant tout ce qui est : �criture, configuration pour l'appareil connect� sur RS232 du PC.     m    Ensemble de fonctions contenant tout ce qui est : lecture, mesure pour l'appareil connect� sur RS232 du PC.    �    Effectue l'ouverture et la configuration d'un port s�rie.

Remarques :

- Le type "void *" doit �tre remplac� par le type T_RS232_CFG (voir RS232.h ou paramPort). Il s'agit d'une structure, pass�e en param�tre � la fonction, contenant les param�tres du port.
- Lors de cette op�ration un buffer cyclique de r�ception d�di� au port est cr��. Une tache sp�cifique avec gestion d'�v�nement sur r�ception de caract�res est d�marr�e afin de remplir ce buffer cyclique.     �    Identifiant du port s�rie toujours renvoy� par la fonction.

Remarque :

- Cet identifiant correspond au num�ro du port ouvert.     �    Indique si une erreur est apparue (pas d'erreur = FALSE = 0, erreur = TRUE = 1).

Remarque :

- Il s'agit d'un compl�ment au retour de la fonction (voir retour). Cette variable est pr�sente pour une utilisation de la biblioth�que via TESTSTAND.        Code d'erreur renvoy� par la fonction.

Remarque :

- La fonction RS232_MAIN_ErrorManager renvoie un message d'erreur en fonction du code d'erreur. Les codes d'erreurs sont les suivants :


RS232_BUF_CIBLE_TROPS_PETIT = -127 :
  "Le buffer cible est trops petit pour effectuer la r�cup�ration des informations du buffer cyclique de r�ception sur port COM%d.".


RS232_TAG_SUITE_TROPS_GRAND = -126 :
  "La taille du tag trouv�, lors de la recherche de tag sur port COM%d, d�passe la taille limite ; la chaine retourn�e est tronqu�e !".


RS232_PB_ALLOC_BUF_TEMP     = -125 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer temporaire pour la recherche de tag sur le port COM%d.".


RS232_TAG_NON_TROUVE        = -124 :
  "La recherche de tag n'a rien trouv�e dans le buffer cyclique de r�ception du port COM%d.".

       
RS232_PB_LECTURE_PORT       = -123 :
  "Probl�me de lecture sur port COM%d.".


RS232_PB_ALLOC_BUF_INTER    = -122 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer interm�diaire pour la r�ception sur le port COM%d.".


RS232_PB_SUPRESSION_TACHE   = -121 :
  "Probl�me lors de la suppression de la tache de r�ception du port COM%d.".


RS232_PB_SUPPRESSION_MUTEX  = -120 :
  "Probl�me lors de la suppression du mutex pour la fermeture du port COM%d.".

    
RS232_PB_CREATION_MUTEX     = -119 :
  "Probl�me lors de la cr�ation du mutex pour l'utilisation des param�tres du port COM%d.".

    
RS232_PB_TACHE_RECEPTION    = -118 :
  "Probl�me lors de la cr�ation de la tache de r�ception du port COM%d.".


RS232_PB_EVEN_PORT_RX_CAR   = -117 :
  "Probl�me lors du param�trage du masque d'�v�nements pour le port COM%d, la fonction \"SetCommMask\" (Windows SDK) a �chou�e.".


RS232_PB_ALLOC_BUF_CYCL     = -116 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer logiciel cyclique pour la r�ception sur le port COM%d.".


RS232_GESTION_ASSYNCHRONE   = -115 :
  "Fonction non utilisable avec un port ouvert en mode assynchrone.".


RS232_PB_CONF_BUF_HARD      = -114 :
  "La configuration de la taille des buffers mat�riels TX et RX du port COM%d a echou�e, probl�me avec la fonction \"SetupComm\" (Windows SDK).".


RS232_PB_RAZ_BUFFER_RX      = -113 :
  "La raz du buffer RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

      
RS232_PB_RAZ_BUFFER_TX      = -112 :
  "La raz du buffer TX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

        
RS232_PB_RAZ_BUFFER_TX_RX   = -111 :
  "La raz des buffers TX et RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

     
RS232_PB_ENVOI_CHAINE       = -110 :
  "Chaine non �crit ou tronqu�e sur port COM%d, la fonction \"WriteFile\" (Windows SDK) a �chou�e.".


RS232_PB_ECRITURE_PORT      = -109 :
  "Probl�me d'�criture sur port COM%d.".


RS232_PB_LIBERATION_MEM     = -108 :
  "Probl�me de lib�ration de la m�moire allou�e pour le COM%d lors de la fermeture de ce dernier.".


RS232_PB_ID                  = -107 :
  "Identifiant inconnu.".


RS232_PB_FERMETURE_PORT      = -106 :
  "Probl�me lors de la fermeture du port COM%d, la fonction \"CloseHandle\" (Windows SDK) a �chou�e.".


RS232_PB_PARAMETRAGE_PORT    = -105 :
  "Probl�me lors du param�trage du port COM%d, la fonction \"SetCommState\" (Windows SDK) a �chou�e. V�rifier les param�tres.".


RS232_PB_RECUP_INFO_PORT     = -104 :
"Probl�me lors de la r�cup�ration des param�tres du port COM%d, la fonction \"GetCommState\" (Windows SDK) a �chou�e.".


RS232_PB_OUVERTURE_PORT      = -103 :
  "Probl�me lors de l'ouverture du port COM%d, la fonction \"CreateFile\" (Windows SDK) a �chou�e.".


RS232_PORT_DEJA_OUVERT       = -102 :
  "Port COM%d d�ja ouvert.".


RS232_PB_ALLOC_DYNAMIQUE     = -101 :
  "Probl�me d'allocation m�moire lors de l'ouverture du port COM%d.".     �    Message d'erreur renvoy� par la fonction. La taille de ces messages n'ex�de pas 1024 caract�res.

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.     1    Statut (pas d'erreur = S_OK, erreur = S_FALSE).    6    Contient les param�tres du port s�rie (mode non EXPERT).

Remarques :

- Ce param�tre est du type T_RS232_CFG, et non "numeric array => void *", (voir RS232.h) ; il s'agit d'une structure contenant les param�tres du port. Cette structure est constitu�e de la fa�on suivante :

  typedef struct
  {
      int             numPort;
      int             syncAssync;                    
      unsigned long   baud;
      unsigned char   bitDonnee;
      unsigned char   parite;
      unsigned char   bitStop;  
      unsigned long   testParite;   
  }   T_RS232_CFG;

- D�finitions des champs de la structure pr�c�dente (dans l'ordre) :

    * Num�ro du port : 1, 2...

    * Mode de gestion synchrone/assynchrone d�fini � l'ouverture du port (synchrone = RS232_SYNC = 0, assynchrone = RS232_ASSYNC = 1).

    * Vitesse du port : de 110, 300, 600, 1200, 4800, 9600, 14400, 19200, 38400, 56000, 57600, 115200, 128000, 256000.

    * Nombre de bit de donn�es : de 4 � 8.

    * Parit� ("no" = RS232_PARITE_NO = 0, "odd" = RS232_PARITE_ODD = 1, "even" = RS232_PARITE_EVEN = 2, "mark" = RS232_PARITE_MARK = 3, "space" = RS232_PARITE_SPACE = 4).

    * Nombre de bit de stop ("1" = RS232_BITSTOP_UN = 0, "1.5" = RS232_BITSTOP_UNDEMI = 1, "2" = RS232_BITSTOP_DEUX = 2).

    * Test de parit� actif (non = RS232_NON = 0, oui = RS232_OUI = 1).
    �        d    hdlSession                         x    d    errorOccurred                      �    d    errorCode                         /R    d    errorMsg                          ���    d    retour                            ;  x    d    paramPort                          	            	            	            	            	                   Effectue la fermeture d'un port s�rie.

Remarque :

- Lors de cette op�ration le buffer cyclique de r�ception d�di� au port est supprim�. La tache sp�cifique avec gestion d'�v�nement sur r�ception de caract�res est stopp�e et supprim�e et la m�moire lib�r�e.         Identifiant du port s�rie.     �    Indique si une erreur est apparue (pas d'erreur = FALSE = 0, erreur = TRUE = 1).

Remarque :

- Il s'agit d'un compl�ment au retour de la fonction (voir retour). Cette variable est pr�sente pour une utilisation de la biblioth�que via TESTSTAND.        Code d'erreur renvoy� par la fonction.

Remarque :

- La fonction RS232_MAIN_ErrorManager renvoie un message d'erreur en fonction du code d'erreur. Les codes d'erreurs sont les suivants :


RS232_BUF_CIBLE_TROPS_PETIT = -127 :
  "Le buffer cible est trops petit pour effectuer la r�cup�ration des informations du buffer cyclique de r�ception sur port COM%d.".


RS232_TAG_SUITE_TROPS_GRAND = -126 :
  "La taille du tag trouv�, lors de la recherche de tag sur port COM%d, d�passe la taille limite ; la chaine retourn�e est tronqu�e !".


RS232_PB_ALLOC_BUF_TEMP     = -125 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer temporaire pour la recherche de tag sur le port COM%d.".


RS232_TAG_NON_TROUVE        = -124 :
  "La recherche de tag n'a rien trouv�e dans le buffer cyclique de r�ception du port COM%d.".

       
RS232_PB_LECTURE_PORT       = -123 :
  "Probl�me de lecture sur port COM%d.".


RS232_PB_ALLOC_BUF_INTER    = -122 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer interm�diaire pour la r�ception sur le port COM%d.".


RS232_PB_SUPRESSION_TACHE   = -121 :
  "Probl�me lors de la suppression de la tache de r�ception du port COM%d.".


RS232_PB_SUPPRESSION_MUTEX  = -120 :
  "Probl�me lors de la suppression du mutex pour la fermeture du port COM%d.".

    
RS232_PB_CREATION_MUTEX     = -119 :
  "Probl�me lors de la cr�ation du mutex pour l'utilisation des param�tres du port COM%d.".

    
RS232_PB_TACHE_RECEPTION    = -118 :
  "Probl�me lors de la cr�ation de la tache de r�ception du port COM%d.".


RS232_PB_EVEN_PORT_RX_CAR   = -117 :
  "Probl�me lors du param�trage du masque d'�v�nements pour le port COM%d, la fonction \"SetCommMask\" (Windows SDK) a �chou�e.".


RS232_PB_ALLOC_BUF_CYCL     = -116 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer logiciel cyclique pour la r�ception sur le port COM%d.".


RS232_GESTION_ASSYNCHRONE   = -115 :
  "Fonction non utilisable avec un port ouvert en mode assynchrone.".


RS232_PB_CONF_BUF_HARD      = -114 :
  "La configuration de la taille des buffers mat�riels TX et RX du port COM%d a echou�e, probl�me avec la fonction \"SetupComm\" (Windows SDK).".


RS232_PB_RAZ_BUFFER_RX      = -113 :
  "La raz du buffer RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

      
RS232_PB_RAZ_BUFFER_TX      = -112 :
  "La raz du buffer TX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

        
RS232_PB_RAZ_BUFFER_TX_RX   = -111 :
  "La raz des buffers TX et RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

     
RS232_PB_ENVOI_CHAINE       = -110 :
  "Chaine non �crit ou tronqu�e sur port COM%d, la fonction \"WriteFile\" (Windows SDK) a �chou�e.".


RS232_PB_ECRITURE_PORT      = -109 :
  "Probl�me d'�criture sur port COM%d.".


RS232_PB_LIBERATION_MEM     = -108 :
  "Probl�me de lib�ration de la m�moire allou�e pour le COM%d lors de la fermeture de ce dernier.".


RS232_PB_ID                  = -107 :
  "Identifiant inconnu.".


RS232_PB_FERMETURE_PORT      = -106 :
  "Probl�me lors de la fermeture du port COM%d, la fonction \"CloseHandle\" (Windows SDK) a �chou�e.".


RS232_PB_PARAMETRAGE_PORT    = -105 :
  "Probl�me lors du param�trage du port COM%d, la fonction \"SetCommState\" (Windows SDK) a �chou�e. V�rifier les param�tres.".


RS232_PB_RECUP_INFO_PORT     = -104 :
"Probl�me lors de la r�cup�ration des param�tres du port COM%d, la fonction \"GetCommState\" (Windows SDK) a �chou�e.".


RS232_PB_OUVERTURE_PORT      = -103 :
  "Probl�me lors de l'ouverture du port COM%d, la fonction \"CreateFile\" (Windows SDK) a �chou�e.".


RS232_PORT_DEJA_OUVERT       = -102 :
  "Port COM%d d�ja ouvert.".


RS232_PB_ALLOC_DYNAMIQUE     = -101 :
  "Probl�me d'allocation m�moire lors de l'ouverture du port COM%d.".     �    Message d'erreur renvoy� par la fonction. La taille de ces messages n'ex�de pas 1024 caract�res.

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.     1    Statut (pas d'erreur = S_OK, erreur = S_FALSE).    '        d    hdlSession                        '' x    d    errorOccurred                     (% �    d    errorCode                         7CR    d    errorMsg                          8���    d    retour                                 	            	            	            	            ,    RAZ buffer TX (buffer materiel) d'un port.         Identifiant du port s�rie.     �    Indique si une erreur est apparue (pas d'erreur = FALSE = 0, erreur = TRUE = 1).

Remarque :

- Il s'agit d'un compl�ment au retour de la fonction (voir retour). Cette variable est pr�sente pour une utilisation de la biblioth�que via TESTSTAND.        Code d'erreur renvoy� par la fonction.

Remarque :

- La fonction RS232_MAIN_ErrorManager renvoie un message d'erreur en fonction du code d'erreur. Les codes d'erreurs sont les suivants :


RS232_BUF_CIBLE_TROPS_PETIT = -127 :
  "Le buffer cible est trops petit pour effectuer la r�cup�ration des informations du buffer cyclique de r�ception sur port COM%d.".


RS232_TAG_SUITE_TROPS_GRAND = -126 :
  "La taille du tag trouv�, lors de la recherche de tag sur port COM%d, d�passe la taille limite ; la chaine retourn�e est tronqu�e !".


RS232_PB_ALLOC_BUF_TEMP     = -125 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer temporaire pour la recherche de tag sur le port COM%d.".


RS232_TAG_NON_TROUVE        = -124 :
  "La recherche de tag n'a rien trouv�e dans le buffer cyclique de r�ception du port COM%d.".

       
RS232_PB_LECTURE_PORT       = -123 :
  "Probl�me de lecture sur port COM%d.".


RS232_PB_ALLOC_BUF_INTER    = -122 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer interm�diaire pour la r�ception sur le port COM%d.".


RS232_PB_SUPRESSION_TACHE   = -121 :
  "Probl�me lors de la suppression de la tache de r�ception du port COM%d.".


RS232_PB_SUPPRESSION_MUTEX  = -120 :
  "Probl�me lors de la suppression du mutex pour la fermeture du port COM%d.".

    
RS232_PB_CREATION_MUTEX     = -119 :
  "Probl�me lors de la cr�ation du mutex pour l'utilisation des param�tres du port COM%d.".

    
RS232_PB_TACHE_RECEPTION    = -118 :
  "Probl�me lors de la cr�ation de la tache de r�ception du port COM%d.".


RS232_PB_EVEN_PORT_RX_CAR   = -117 :
  "Probl�me lors du param�trage du masque d'�v�nements pour le port COM%d, la fonction \"SetCommMask\" (Windows SDK) a �chou�e.".


RS232_PB_ALLOC_BUF_CYCL     = -116 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer logiciel cyclique pour la r�ception sur le port COM%d.".


RS232_GESTION_ASSYNCHRONE   = -115 :
  "Fonction non utilisable avec un port ouvert en mode assynchrone.".


RS232_PB_CONF_BUF_HARD      = -114 :
  "La configuration de la taille des buffers mat�riels TX et RX du port COM%d a echou�e, probl�me avec la fonction \"SetupComm\" (Windows SDK).".


RS232_PB_RAZ_BUFFER_RX      = -113 :
  "La raz du buffer RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

      
RS232_PB_RAZ_BUFFER_TX      = -112 :
  "La raz du buffer TX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

        
RS232_PB_RAZ_BUFFER_TX_RX   = -111 :
  "La raz des buffers TX et RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

     
RS232_PB_ENVOI_CHAINE       = -110 :
  "Chaine non �crit ou tronqu�e sur port COM%d, la fonction \"WriteFile\" (Windows SDK) a �chou�e.".


RS232_PB_ECRITURE_PORT      = -109 :
  "Probl�me d'�criture sur port COM%d.".


RS232_PB_LIBERATION_MEM     = -108 :
  "Probl�me de lib�ration de la m�moire allou�e pour le COM%d lors de la fermeture de ce dernier.".


RS232_PB_ID                  = -107 :
  "Identifiant inconnu.".


RS232_PB_FERMETURE_PORT      = -106 :
  "Probl�me lors de la fermeture du port COM%d, la fonction \"CloseHandle\" (Windows SDK) a �chou�e.".


RS232_PB_PARAMETRAGE_PORT    = -105 :
  "Probl�me lors du param�trage du port COM%d, la fonction \"SetCommState\" (Windows SDK) a �chou�e. V�rifier les param�tres.".


RS232_PB_RECUP_INFO_PORT     = -104 :
"Probl�me lors de la r�cup�ration des param�tres du port COM%d, la fonction \"GetCommState\" (Windows SDK) a �chou�e.".


RS232_PB_OUVERTURE_PORT      = -103 :
  "Probl�me lors de l'ouverture du port COM%d, la fonction \"CreateFile\" (Windows SDK) a �chou�e.".


RS232_PORT_DEJA_OUVERT       = -102 :
  "Port COM%d d�ja ouvert.".


RS232_PB_ALLOC_DYNAMIQUE     = -101 :
  "Probl�me d'allocation m�moire lors de l'ouverture du port COM%d.".     �    Message d'erreur renvoy� par la fonction. La taille de ces messages n'ex�de pas 1024 caract�res.

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.     1    Statut (pas d'erreur = S_OK, erreur = S_FALSE).    9�        d    hdlSession                        9� x    d    errorOccurred                     :� �    d    errorCode                         J R    d    errorMsg                          J����    d    retour                                 	            	            	            	            ,    RAZ buffer RX (buffer materiel) d'un port.         Identifiant du port s�rie.     �    Indique si une erreur est apparue (pas d'erreur = FALSE = 0, erreur = TRUE = 1).

Remarque :

- Il s'agit d'un compl�ment au retour de la fonction (voir retour). Cette variable est pr�sente pour une utilisation de la biblioth�que via TESTSTAND.        Code d'erreur renvoy� par la fonction.

Remarque :

- La fonction RS232_MAIN_ErrorManager renvoie un message d'erreur en fonction du code d'erreur. Les codes d'erreurs sont les suivants :


RS232_BUF_CIBLE_TROPS_PETIT = -127 :
  "Le buffer cible est trops petit pour effectuer la r�cup�ration des informations du buffer cyclique de r�ception sur port COM%d.".


RS232_TAG_SUITE_TROPS_GRAND = -126 :
  "La taille du tag trouv�, lors de la recherche de tag sur port COM%d, d�passe la taille limite ; la chaine retourn�e est tronqu�e !".


RS232_PB_ALLOC_BUF_TEMP     = -125 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer temporaire pour la recherche de tag sur le port COM%d.".


RS232_TAG_NON_TROUVE        = -124 :
  "La recherche de tag n'a rien trouv�e dans le buffer cyclique de r�ception du port COM%d.".

       
RS232_PB_LECTURE_PORT       = -123 :
  "Probl�me de lecture sur port COM%d.".


RS232_PB_ALLOC_BUF_INTER    = -122 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer interm�diaire pour la r�ception sur le port COM%d.".


RS232_PB_SUPRESSION_TACHE   = -121 :
  "Probl�me lors de la suppression de la tache de r�ception du port COM%d.".


RS232_PB_SUPPRESSION_MUTEX  = -120 :
  "Probl�me lors de la suppression du mutex pour la fermeture du port COM%d.".

    
RS232_PB_CREATION_MUTEX     = -119 :
  "Probl�me lors de la cr�ation du mutex pour l'utilisation des param�tres du port COM%d.".

    
RS232_PB_TACHE_RECEPTION    = -118 :
  "Probl�me lors de la cr�ation de la tache de r�ception du port COM%d.".


RS232_PB_EVEN_PORT_RX_CAR   = -117 :
  "Probl�me lors du param�trage du masque d'�v�nements pour le port COM%d, la fonction \"SetCommMask\" (Windows SDK) a �chou�e.".


RS232_PB_ALLOC_BUF_CYCL     = -116 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer logiciel cyclique pour la r�ception sur le port COM%d.".


RS232_GESTION_ASSYNCHRONE   = -115 :
  "Fonction non utilisable avec un port ouvert en mode assynchrone.".


RS232_PB_CONF_BUF_HARD      = -114 :
  "La configuration de la taille des buffers mat�riels TX et RX du port COM%d a echou�e, probl�me avec la fonction \"SetupComm\" (Windows SDK).".


RS232_PB_RAZ_BUFFER_RX      = -113 :
  "La raz du buffer RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

      
RS232_PB_RAZ_BUFFER_TX      = -112 :
  "La raz du buffer TX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

        
RS232_PB_RAZ_BUFFER_TX_RX   = -111 :
  "La raz des buffers TX et RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

     
RS232_PB_ENVOI_CHAINE       = -110 :
  "Chaine non �crit ou tronqu�e sur port COM%d, la fonction \"WriteFile\" (Windows SDK) a �chou�e.".


RS232_PB_ECRITURE_PORT      = -109 :
  "Probl�me d'�criture sur port COM%d.".


RS232_PB_LIBERATION_MEM     = -108 :
  "Probl�me de lib�ration de la m�moire allou�e pour le COM%d lors de la fermeture de ce dernier.".


RS232_PB_ID                  = -107 :
  "Identifiant inconnu.".


RS232_PB_FERMETURE_PORT      = -106 :
  "Probl�me lors de la fermeture du port COM%d, la fonction \"CloseHandle\" (Windows SDK) a �chou�e.".


RS232_PB_PARAMETRAGE_PORT    = -105 :
  "Probl�me lors du param�trage du port COM%d, la fonction \"SetCommState\" (Windows SDK) a �chou�e. V�rifier les param�tres.".


RS232_PB_RECUP_INFO_PORT     = -104 :
"Probl�me lors de la r�cup�ration des param�tres du port COM%d, la fonction \"GetCommState\" (Windows SDK) a �chou�e.".


RS232_PB_OUVERTURE_PORT      = -103 :
  "Probl�me lors de l'ouverture du port COM%d, la fonction \"CreateFile\" (Windows SDK) a �chou�e.".


RS232_PORT_DEJA_OUVERT       = -102 :
  "Port COM%d d�ja ouvert.".


RS232_PB_ALLOC_DYNAMIQUE     = -101 :
  "Probl�me d'allocation m�moire lors de l'ouverture du port COM%d.".     �    Message d'erreur renvoy� par la fonction. La taille de ces messages n'ex�de pas 1024 caract�res.

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.     1    Statut (pas d'erreur = S_OK, erreur = S_FALSE).    L}        d    hdlSession                        L� x    d    errorOccurred                     M� �    d    errorCode                         \�R    d    errorMsg                          ]����    d    retour                                 	            	            	            	            ?    RAZ buffer cyclique de r�ception (buffer logiciel) d'un port.         Identifiant du port s�rie.     �    Indique si une erreur est apparue (pas d'erreur = FALSE = 0, erreur = TRUE = 1).

Remarque :

- Il s'agit d'un compl�ment au retour de la fonction (voir retour). Cette variable est pr�sente pour une utilisation de la biblioth�que via TESTSTAND.        Code d'erreur renvoy� par la fonction.

Remarque :

- La fonction RS232_MAIN_ErrorManager renvoie un message d'erreur en fonction du code d'erreur. Les codes d'erreurs sont les suivants :


RS232_BUF_CIBLE_TROPS_PETIT = -127 :
  "Le buffer cible est trops petit pour effectuer la r�cup�ration des informations du buffer cyclique de r�ception sur port COM%d.".


RS232_TAG_SUITE_TROPS_GRAND = -126 :
  "La taille du tag trouv�, lors de la recherche de tag sur port COM%d, d�passe la taille limite ; la chaine retourn�e est tronqu�e !".


RS232_PB_ALLOC_BUF_TEMP     = -125 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer temporaire pour la recherche de tag sur le port COM%d.".


RS232_TAG_NON_TROUVE        = -124 :
  "La recherche de tag n'a rien trouv�e dans le buffer cyclique de r�ception du port COM%d.".

       
RS232_PB_LECTURE_PORT       = -123 :
  "Probl�me de lecture sur port COM%d.".


RS232_PB_ALLOC_BUF_INTER    = -122 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer interm�diaire pour la r�ception sur le port COM%d.".


RS232_PB_SUPRESSION_TACHE   = -121 :
  "Probl�me lors de la suppression de la tache de r�ception du port COM%d.".


RS232_PB_SUPPRESSION_MUTEX  = -120 :
  "Probl�me lors de la suppression du mutex pour la fermeture du port COM%d.".

    
RS232_PB_CREATION_MUTEX     = -119 :
  "Probl�me lors de la cr�ation du mutex pour l'utilisation des param�tres du port COM%d.".

    
RS232_PB_TACHE_RECEPTION    = -118 :
  "Probl�me lors de la cr�ation de la tache de r�ception du port COM%d.".


RS232_PB_EVEN_PORT_RX_CAR   = -117 :
  "Probl�me lors du param�trage du masque d'�v�nements pour le port COM%d, la fonction \"SetCommMask\" (Windows SDK) a �chou�e.".


RS232_PB_ALLOC_BUF_CYCL     = -116 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer logiciel cyclique pour la r�ception sur le port COM%d.".


RS232_GESTION_ASSYNCHRONE   = -115 :
  "Fonction non utilisable avec un port ouvert en mode assynchrone.".


RS232_PB_CONF_BUF_HARD      = -114 :
  "La configuration de la taille des buffers mat�riels TX et RX du port COM%d a echou�e, probl�me avec la fonction \"SetupComm\" (Windows SDK).".


RS232_PB_RAZ_BUFFER_RX      = -113 :
  "La raz du buffer RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

      
RS232_PB_RAZ_BUFFER_TX      = -112 :
  "La raz du buffer TX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

        
RS232_PB_RAZ_BUFFER_TX_RX   = -111 :
  "La raz des buffers TX et RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

     
RS232_PB_ENVOI_CHAINE       = -110 :
  "Chaine non �crit ou tronqu�e sur port COM%d, la fonction \"WriteFile\" (Windows SDK) a �chou�e.".


RS232_PB_ECRITURE_PORT      = -109 :
  "Probl�me d'�criture sur port COM%d.".


RS232_PB_LIBERATION_MEM     = -108 :
  "Probl�me de lib�ration de la m�moire allou�e pour le COM%d lors de la fermeture de ce dernier.".


RS232_PB_ID                  = -107 :
  "Identifiant inconnu.".


RS232_PB_FERMETURE_PORT      = -106 :
  "Probl�me lors de la fermeture du port COM%d, la fonction \"CloseHandle\" (Windows SDK) a �chou�e.".


RS232_PB_PARAMETRAGE_PORT    = -105 :
  "Probl�me lors du param�trage du port COM%d, la fonction \"SetCommState\" (Windows SDK) a �chou�e. V�rifier les param�tres.".


RS232_PB_RECUP_INFO_PORT     = -104 :
"Probl�me lors de la r�cup�ration des param�tres du port COM%d, la fonction \"GetCommState\" (Windows SDK) a �chou�e.".


RS232_PB_OUVERTURE_PORT      = -103 :
  "Probl�me lors de l'ouverture du port COM%d, la fonction \"CreateFile\" (Windows SDK) a �chou�e.".


RS232_PORT_DEJA_OUVERT       = -102 :
  "Port COM%d d�ja ouvert.".


RS232_PB_ALLOC_DYNAMIQUE     = -101 :
  "Probl�me d'allocation m�moire lors de l'ouverture du port COM%d.".     �    Message d'erreur renvoy� par la fonction. La taille de ces messages n'ex�de pas 1024 caract�res.

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.     1    Statut (pas d'erreur = S_OK, erreur = S_FALSE).    _M        d    hdlSession                        _q x    d    errorOccurred                     `o �    d    errorCode                         o�R    d    errorMsg                          p`���    d    retour                                 	            	            	            	            �    Fonction de Nettoyage (m�moire, ports demeur�s ouverts, buffers...).

Remarques :

- A utiliser en cas d'une erreur sur l'allocation m�moire par exemple.
- Pas format�e pour utilisation avec TESTSTAND.    {    G�re les codes d'erreurs pour l'ensemble de la biblioth�que. Cette fonction renvoie un message d'erreur en fonction d'un code d'erreur. (Il s'agit bien sur des codes d'erreurs de la biblioth�que et uniquement de celle-ci !).

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.
- Pas format�e pour utilisation avec TESTSTAND.     �    Message d'erreur renvoy� par la fonction. La taille de ces messages n'ex�de pas 1024 caract�res.

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.     1    Statut (pas d'erreur = S_OK, erreur = S_FALSE).     .    Contient num�ro de port si besoin (sinon 0).        Code d'erreur renvoy� par la fonction.

Remarque :

- La fonction RS232_MAIN_ErrorManager renvoie un message d'erreur en fonction du code d'erreur. Les codes d'erreurs sont les suivants :


RS232_BUF_CIBLE_TROPS_PETIT = -127 :
  "Le buffer cible est trops petit pour effectuer la r�cup�ration des informations du buffer cyclique de r�ception sur port COM%d.".


RS232_TAG_SUITE_TROPS_GRAND = -126 :
  "La taille du tag trouv�, lors de la recherche de tag sur port COM%d, d�passe la taille limite ; la chaine retourn�e est tronqu�e !".


RS232_PB_ALLOC_BUF_TEMP     = -125 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer temporaire pour la recherche de tag sur le port COM%d.".


RS232_TAG_NON_TROUVE        = -124 :
  "La recherche de tag n'a rien trouv�e dans le buffer cyclique de r�ception du port COM%d.".

       
RS232_PB_LECTURE_PORT       = -123 :
  "Probl�me de lecture sur port COM%d.".


RS232_PB_ALLOC_BUF_INTER    = -122 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer interm�diaire pour la r�ception sur le port COM%d.".


RS232_PB_SUPRESSION_TACHE   = -121 :
  "Probl�me lors de la suppression de la tache de r�ception du port COM%d.".


RS232_PB_SUPPRESSION_MUTEX  = -120 :
  "Probl�me lors de la suppression du mutex pour la fermeture du port COM%d.".

    
RS232_PB_CREATION_MUTEX     = -119 :
  "Probl�me lors de la cr�ation du mutex pour l'utilisation des param�tres du port COM%d.".

    
RS232_PB_TACHE_RECEPTION    = -118 :
  "Probl�me lors de la cr�ation de la tache de r�ception du port COM%d.".


RS232_PB_EVEN_PORT_RX_CAR   = -117 :
  "Probl�me lors du param�trage du masque d'�v�nements pour le port COM%d, la fonction \"SetCommMask\" (Windows SDK) a �chou�e.".


RS232_PB_ALLOC_BUF_CYCL     = -116 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer logiciel cyclique pour la r�ception sur le port COM%d.".


RS232_GESTION_ASSYNCHRONE   = -115 :
  "Fonction non utilisable avec un port ouvert en mode assynchrone.".


RS232_PB_CONF_BUF_HARD      = -114 :
  "La configuration de la taille des buffers mat�riels TX et RX du port COM%d a echou�e, probl�me avec la fonction \"SetupComm\" (Windows SDK).".


RS232_PB_RAZ_BUFFER_RX      = -113 :
  "La raz du buffer RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

      
RS232_PB_RAZ_BUFFER_TX      = -112 :
  "La raz du buffer TX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

        
RS232_PB_RAZ_BUFFER_TX_RX   = -111 :
  "La raz des buffers TX et RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

     
RS232_PB_ENVOI_CHAINE       = -110 :
  "Chaine non �crit ou tronqu�e sur port COM%d, la fonction \"WriteFile\" (Windows SDK) a �chou�e.".


RS232_PB_ECRITURE_PORT      = -109 :
  "Probl�me d'�criture sur port COM%d.".


RS232_PB_LIBERATION_MEM     = -108 :
  "Probl�me de lib�ration de la m�moire allou�e pour le COM%d lors de la fermeture de ce dernier.".


RS232_PB_ID                  = -107 :
  "Identifiant inconnu.".


RS232_PB_FERMETURE_PORT      = -106 :
  "Probl�me lors de la fermeture du port COM%d, la fonction \"CloseHandle\" (Windows SDK) a �chou�e.".


RS232_PB_PARAMETRAGE_PORT    = -105 :
  "Probl�me lors du param�trage du port COM%d, la fonction \"SetCommState\" (Windows SDK) a �chou�e. V�rifier les param�tres.".


RS232_PB_RECUP_INFO_PORT     = -104 :
"Probl�me lors de la r�cup�ration des param�tres du port COM%d, la fonction \"GetCommState\" (Windows SDK) a �chou�e.".


RS232_PB_OUVERTURE_PORT      = -103 :
  "Probl�me lors de l'ouverture du port COM%d, la fonction \"CreateFile\" (Windows SDK) a �chou�e.".


RS232_PORT_DEJA_OUVERT       = -102 :
  "Port COM%d d�ja ouvert.".


RS232_PB_ALLOC_DYNAMIQUE     = -101 :
  "Probl�me d'allocation m�moire lors de l'ouverture du port COM%d.".    t,R    d    errorMessage                      t����    d    retour                            u8 p      d    device                            un �    d    errorCode                          	            	                	            �    Ecriture d'une chaine sur un port s�rie (Synchrone et Assynchrone).

Remarque :

- Le mode Synchrone ou Assynchrone est d�fini au moment de l'ouverture du port.


Ne marche pas sous TestStand (il ne veut pas de unsigned char)         Identifiant du port s�rie.     �    Indique si une erreur est apparue (pas d'erreur = FALSE = 0, erreur = TRUE = 1).

Remarque :

- Il s'agit d'un compl�ment au retour de la fonction (voir retour). Cette variable est pr�sente pour une utilisation de la biblioth�que via TESTSTAND.        Code d'erreur renvoy� par la fonction.

Remarque :

- La fonction RS232_MAIN_ErrorManager renvoie un message d'erreur en fonction du code d'erreur. Les codes d'erreurs sont les suivants :


RS232_BUF_CIBLE_TROPS_PETIT = -127 :
  "Le buffer cible est trops petit pour effectuer la r�cup�ration des informations du buffer cyclique de r�ception sur port COM%d.".


RS232_TAG_SUITE_TROPS_GRAND = -126 :
  "La taille du tag trouv�, lors de la recherche de tag sur port COM%d, d�passe la taille limite ; la chaine retourn�e est tronqu�e !".


RS232_PB_ALLOC_BUF_TEMP     = -125 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer temporaire pour la recherche de tag sur le port COM%d.".


RS232_TAG_NON_TROUVE        = -124 :
  "La recherche de tag n'a rien trouv�e dans le buffer cyclique de r�ception du port COM%d.".

       
RS232_PB_LECTURE_PORT       = -123 :
  "Probl�me de lecture sur port COM%d.".


RS232_PB_ALLOC_BUF_INTER    = -122 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer interm�diaire pour la r�ception sur le port COM%d.".


RS232_PB_SUPRESSION_TACHE   = -121 :
  "Probl�me lors de la suppression de la tache de r�ception du port COM%d.".


RS232_PB_SUPPRESSION_MUTEX  = -120 :
  "Probl�me lors de la suppression du mutex pour la fermeture du port COM%d.".

    
RS232_PB_CREATION_MUTEX     = -119 :
  "Probl�me lors de la cr�ation du mutex pour l'utilisation des param�tres du port COM%d.".

    
RS232_PB_TACHE_RECEPTION    = -118 :
  "Probl�me lors de la cr�ation de la tache de r�ception du port COM%d.".


RS232_PB_EVEN_PORT_RX_CAR   = -117 :
  "Probl�me lors du param�trage du masque d'�v�nements pour le port COM%d, la fonction \"SetCommMask\" (Windows SDK) a �chou�e.".


RS232_PB_ALLOC_BUF_CYCL     = -116 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer logiciel cyclique pour la r�ception sur le port COM%d.".


RS232_GESTION_ASSYNCHRONE   = -115 :
  "Fonction non utilisable avec un port ouvert en mode assynchrone.".


RS232_PB_CONF_BUF_HARD      = -114 :
  "La configuration de la taille des buffers mat�riels TX et RX du port COM%d a echou�e, probl�me avec la fonction \"SetupComm\" (Windows SDK).".


RS232_PB_RAZ_BUFFER_RX      = -113 :
  "La raz du buffer RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

      
RS232_PB_RAZ_BUFFER_TX      = -112 :
  "La raz du buffer TX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

        
RS232_PB_RAZ_BUFFER_TX_RX   = -111 :
  "La raz des buffers TX et RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

     
RS232_PB_ENVOI_CHAINE       = -110 :
  "Chaine non �crit ou tronqu�e sur port COM%d, la fonction \"WriteFile\" (Windows SDK) a �chou�e.".


RS232_PB_ECRITURE_PORT      = -109 :
  "Probl�me d'�criture sur port COM%d.".


RS232_PB_LIBERATION_MEM     = -108 :
  "Probl�me de lib�ration de la m�moire allou�e pour le COM%d lors de la fermeture de ce dernier.".


RS232_PB_ID                  = -107 :
  "Identifiant inconnu.".


RS232_PB_FERMETURE_PORT      = -106 :
  "Probl�me lors de la fermeture du port COM%d, la fonction \"CloseHandle\" (Windows SDK) a �chou�e.".


RS232_PB_PARAMETRAGE_PORT    = -105 :
  "Probl�me lors du param�trage du port COM%d, la fonction \"SetCommState\" (Windows SDK) a �chou�e. V�rifier les param�tres.".


RS232_PB_RECUP_INFO_PORT     = -104 :
"Probl�me lors de la r�cup�ration des param�tres du port COM%d, la fonction \"GetCommState\" (Windows SDK) a �chou�e.".


RS232_PB_OUVERTURE_PORT      = -103 :
  "Probl�me lors de l'ouverture du port COM%d, la fonction \"CreateFile\" (Windows SDK) a �chou�e.".


RS232_PORT_DEJA_OUVERT       = -102 :
  "Port COM%d d�ja ouvert.".


RS232_PB_ALLOC_DYNAMIQUE     = -101 :
  "Probl�me d'allocation m�moire lors de l'ouverture du port COM%d.".     �    Message d'erreur renvoy� par la fonction. La taille de ces messages n'ex�de pas 1024 caract�res.

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.     1    Statut (pas d'erreur = S_OK, erreur = S_FALSE).          Chaine de caract�re � envoyer.     "    Longueur de la chaine � envoyer.    �s        d    hdlSession                        �� x    d    errorOccurred                     �� �    d    errorCode                         ��R    d    errorMsg                          �����    d    retour                            ��  x    d    ecrire                            ��  �    d    lngEcrire                              	            	            	            	                    �    Ecriture d'une chaine sur un port s�rie (Synchrone et Assynchrone).

Remarque :

- Le mode Synchrone ou Assynchrone est d�fini au moment de l'ouverture du port.


Cette fonction marche sous TestStand         Identifiant du port s�rie.     �    Indique si une erreur est apparue (pas d'erreur = FALSE = 0, erreur = TRUE = 1).

Remarque :

- Il s'agit d'un compl�ment au retour de la fonction (voir retour). Cette variable est pr�sente pour une utilisation de la biblioth�que via TESTSTAND.        Code d'erreur renvoy� par la fonction.

Remarque :

- La fonction RS232_MAIN_ErrorManager renvoie un message d'erreur en fonction du code d'erreur. Les codes d'erreurs sont les suivants :


RS232_BUF_CIBLE_TROPS_PETIT = -127 :
  "Le buffer cible est trops petit pour effectuer la r�cup�ration des informations du buffer cyclique de r�ception sur port COM%d.".


RS232_TAG_SUITE_TROPS_GRAND = -126 :
  "La taille du tag trouv�, lors de la recherche de tag sur port COM%d, d�passe la taille limite ; la chaine retourn�e est tronqu�e !".


RS232_PB_ALLOC_BUF_TEMP     = -125 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer temporaire pour la recherche de tag sur le port COM%d.".


RS232_TAG_NON_TROUVE        = -124 :
  "La recherche de tag n'a rien trouv�e dans le buffer cyclique de r�ception du port COM%d.".

       
RS232_PB_LECTURE_PORT       = -123 :
  "Probl�me de lecture sur port COM%d.".


RS232_PB_ALLOC_BUF_INTER    = -122 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer interm�diaire pour la r�ception sur le port COM%d.".


RS232_PB_SUPRESSION_TACHE   = -121 :
  "Probl�me lors de la suppression de la tache de r�ception du port COM%d.".


RS232_PB_SUPPRESSION_MUTEX  = -120 :
  "Probl�me lors de la suppression du mutex pour la fermeture du port COM%d.".

    
RS232_PB_CREATION_MUTEX     = -119 :
  "Probl�me lors de la cr�ation du mutex pour l'utilisation des param�tres du port COM%d.".

    
RS232_PB_TACHE_RECEPTION    = -118 :
  "Probl�me lors de la cr�ation de la tache de r�ception du port COM%d.".


RS232_PB_EVEN_PORT_RX_CAR   = -117 :
  "Probl�me lors du param�trage du masque d'�v�nements pour le port COM%d, la fonction \"SetCommMask\" (Windows SDK) a �chou�e.".


RS232_PB_ALLOC_BUF_CYCL     = -116 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer logiciel cyclique pour la r�ception sur le port COM%d.".


RS232_GESTION_ASSYNCHRONE   = -115 :
  "Fonction non utilisable avec un port ouvert en mode assynchrone.".


RS232_PB_CONF_BUF_HARD      = -114 :
  "La configuration de la taille des buffers mat�riels TX et RX du port COM%d a echou�e, probl�me avec la fonction \"SetupComm\" (Windows SDK).".


RS232_PB_RAZ_BUFFER_RX      = -113 :
  "La raz du buffer RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

      
RS232_PB_RAZ_BUFFER_TX      = -112 :
  "La raz du buffer TX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

        
RS232_PB_RAZ_BUFFER_TX_RX   = -111 :
  "La raz des buffers TX et RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

     
RS232_PB_ENVOI_CHAINE       = -110 :
  "Chaine non �crit ou tronqu�e sur port COM%d, la fonction \"WriteFile\" (Windows SDK) a �chou�e.".


RS232_PB_ECRITURE_PORT      = -109 :
  "Probl�me d'�criture sur port COM%d.".


RS232_PB_LIBERATION_MEM     = -108 :
  "Probl�me de lib�ration de la m�moire allou�e pour le COM%d lors de la fermeture de ce dernier.".


RS232_PB_ID                  = -107 :
  "Identifiant inconnu.".


RS232_PB_FERMETURE_PORT      = -106 :
  "Probl�me lors de la fermeture du port COM%d, la fonction \"CloseHandle\" (Windows SDK) a �chou�e.".


RS232_PB_PARAMETRAGE_PORT    = -105 :
  "Probl�me lors du param�trage du port COM%d, la fonction \"SetCommState\" (Windows SDK) a �chou�e. V�rifier les param�tres.".


RS232_PB_RECUP_INFO_PORT     = -104 :
"Probl�me lors de la r�cup�ration des param�tres du port COM%d, la fonction \"GetCommState\" (Windows SDK) a �chou�e.".


RS232_PB_OUVERTURE_PORT      = -103 :
  "Probl�me lors de l'ouverture du port COM%d, la fonction \"CreateFile\" (Windows SDK) a �chou�e.".


RS232_PORT_DEJA_OUVERT       = -102 :
  "Port COM%d d�ja ouvert.".


RS232_PB_ALLOC_DYNAMIQUE     = -101 :
  "Probl�me d'allocation m�moire lors de l'ouverture du port COM%d.".     �    Message d'erreur renvoy� par la fonction. La taille de ces messages n'ex�de pas 1024 caract�res.

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.     1    Statut (pas d'erreur = S_OK, erreur = S_FALSE).          Chaine de caract�re � envoyer.     "    Longueur de la chaine � envoyer.    ��        d    hdlSession                        �� x    d    errorOccurred                     �� �    d    errorCode                         ��R    d    errorMsg                          �����    d    retour                            ��  x    d    ecrire                            �  �    d    lngEcrire                              	            	            	            	                    �    Ecriture d'une chaine sur un port s�rie avec un d�lai inter caract�re (Synchrone uniquement).

Remarque :

- Fonction utilisable en mode Synchrone (d�fini � l'ouverture du port).         Identifiant du port s�rie.     �    Indique si une erreur est apparue (pas d'erreur = FALSE = 0, erreur = TRUE = 1).

Remarque :

- Il s'agit d'un compl�ment au retour de la fonction (voir retour). Cette variable est pr�sente pour une utilisation de la biblioth�que via TESTSTAND.        Code d'erreur renvoy� par la fonction.

Remarque :

- La fonction RS232_MAIN_ErrorManager renvoie un message d'erreur en fonction du code d'erreur. Les codes d'erreurs sont les suivants :


RS232_BUF_CIBLE_TROPS_PETIT = -127 :
  "Le buffer cible est trops petit pour effectuer la r�cup�ration des informations du buffer cyclique de r�ception sur port COM%d.".


RS232_TAG_SUITE_TROPS_GRAND = -126 :
  "La taille du tag trouv�, lors de la recherche de tag sur port COM%d, d�passe la taille limite ; la chaine retourn�e est tronqu�e !".


RS232_PB_ALLOC_BUF_TEMP     = -125 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer temporaire pour la recherche de tag sur le port COM%d.".


RS232_TAG_NON_TROUVE        = -124 :
  "La recherche de tag n'a rien trouv�e dans le buffer cyclique de r�ception du port COM%d.".

       
RS232_PB_LECTURE_PORT       = -123 :
  "Probl�me de lecture sur port COM%d.".


RS232_PB_ALLOC_BUF_INTER    = -122 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer interm�diaire pour la r�ception sur le port COM%d.".


RS232_PB_SUPRESSION_TACHE   = -121 :
  "Probl�me lors de la suppression de la tache de r�ception du port COM%d.".


RS232_PB_SUPPRESSION_MUTEX  = -120 :
  "Probl�me lors de la suppression du mutex pour la fermeture du port COM%d.".

    
RS232_PB_CREATION_MUTEX     = -119 :
  "Probl�me lors de la cr�ation du mutex pour l'utilisation des param�tres du port COM%d.".

    
RS232_PB_TACHE_RECEPTION    = -118 :
  "Probl�me lors de la cr�ation de la tache de r�ception du port COM%d.".


RS232_PB_EVEN_PORT_RX_CAR   = -117 :
  "Probl�me lors du param�trage du masque d'�v�nements pour le port COM%d, la fonction \"SetCommMask\" (Windows SDK) a �chou�e.".


RS232_PB_ALLOC_BUF_CYCL     = -116 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer logiciel cyclique pour la r�ception sur le port COM%d.".


RS232_GESTION_ASSYNCHRONE   = -115 :
  "Fonction non utilisable avec un port ouvert en mode assynchrone.".


RS232_PB_CONF_BUF_HARD      = -114 :
  "La configuration de la taille des buffers mat�riels TX et RX du port COM%d a echou�e, probl�me avec la fonction \"SetupComm\" (Windows SDK).".


RS232_PB_RAZ_BUFFER_RX      = -113 :
  "La raz du buffer RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

      
RS232_PB_RAZ_BUFFER_TX      = -112 :
  "La raz du buffer TX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

        
RS232_PB_RAZ_BUFFER_TX_RX   = -111 :
  "La raz des buffers TX et RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

     
RS232_PB_ENVOI_CHAINE       = -110 :
  "Chaine non �crit ou tronqu�e sur port COM%d, la fonction \"WriteFile\" (Windows SDK) a �chou�e.".


RS232_PB_ECRITURE_PORT      = -109 :
  "Probl�me d'�criture sur port COM%d.".


RS232_PB_LIBERATION_MEM     = -108 :
  "Probl�me de lib�ration de la m�moire allou�e pour le COM%d lors de la fermeture de ce dernier.".


RS232_PB_ID                  = -107 :
  "Identifiant inconnu.".


RS232_PB_FERMETURE_PORT      = -106 :
  "Probl�me lors de la fermeture du port COM%d, la fonction \"CloseHandle\" (Windows SDK) a �chou�e.".


RS232_PB_PARAMETRAGE_PORT    = -105 :
  "Probl�me lors du param�trage du port COM%d, la fonction \"SetCommState\" (Windows SDK) a �chou�e. V�rifier les param�tres.".


RS232_PB_RECUP_INFO_PORT     = -104 :
"Probl�me lors de la r�cup�ration des param�tres du port COM%d, la fonction \"GetCommState\" (Windows SDK) a �chou�e.".


RS232_PB_OUVERTURE_PORT      = -103 :
  "Probl�me lors de l'ouverture du port COM%d, la fonction \"CreateFile\" (Windows SDK) a �chou�e.".


RS232_PORT_DEJA_OUVERT       = -102 :
  "Port COM%d d�ja ouvert.".


RS232_PB_ALLOC_DYNAMIQUE     = -101 :
  "Probl�me d'allocation m�moire lors de l'ouverture du port COM%d.".     �    Message d'erreur renvoy� par la fonction. La taille de ces messages n'ex�de pas 1024 caract�res.

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.     1    Statut (pas d'erreur = S_OK, erreur = S_FALSE).          Chaine de caract�re � envoyer.     "    Longueur de la chaine � envoyer.     (    D�lai inter caract�re de 1 � 250 (ms).    ��        d    hdlSession                        �� x    d    errorOccurred                     �� �    d    errorCode                         ��R    d    errorMsg                          �����    d    retour                            ��  x    d    ecrire                            �  �    d    lngEcrire                         �8 R     d    delai                                  	            	            	            	                        P    Recherche d'une chaine dans le buffer cyclique de r�ception sur un port s�rie.         Identifiant du port s�rie.     �    Indique si une erreur est apparue (pas d'erreur = FALSE = 0, erreur = TRUE = 1).

Remarque :

- Il s'agit d'un compl�ment au retour de la fonction (voir retour). Cette variable est pr�sente pour une utilisation de la biblioth�que via TESTSTAND.        Code d'erreur renvoy� par la fonction.

Remarque :

- La fonction RS232_MAIN_ErrorManager renvoie un message d'erreur en fonction du code d'erreur. Les codes d'erreurs sont les suivants :


RS232_BUF_CIBLE_TROPS_PETIT = -127 :
  "Le buffer cible est trops petit pour effectuer la r�cup�ration des informations du buffer cyclique de r�ception sur port COM%d.".


RS232_TAG_SUITE_TROPS_GRAND = -126 :
  "La taille du tag trouv�, lors de la recherche de tag sur port COM%d, d�passe la taille limite ; la chaine retourn�e est tronqu�e !".


RS232_PB_ALLOC_BUF_TEMP     = -125 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer temporaire pour la recherche de tag sur le port COM%d.".


RS232_TAG_NON_TROUVE        = -124 :
  "La recherche de tag n'a rien trouv�e dans le buffer cyclique de r�ception du port COM%d.".

       
RS232_PB_LECTURE_PORT       = -123 :
  "Probl�me de lecture sur port COM%d.".


RS232_PB_ALLOC_BUF_INTER    = -122 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer interm�diaire pour la r�ception sur le port COM%d.".


RS232_PB_SUPRESSION_TACHE   = -121 :
  "Probl�me lors de la suppression de la tache de r�ception du port COM%d.".


RS232_PB_SUPPRESSION_MUTEX  = -120 :
  "Probl�me lors de la suppression du mutex pour la fermeture du port COM%d.".

    
RS232_PB_CREATION_MUTEX     = -119 :
  "Probl�me lors de la cr�ation du mutex pour l'utilisation des param�tres du port COM%d.".

    
RS232_PB_TACHE_RECEPTION    = -118 :
  "Probl�me lors de la cr�ation de la tache de r�ception du port COM%d.".


RS232_PB_EVEN_PORT_RX_CAR   = -117 :
  "Probl�me lors du param�trage du masque d'�v�nements pour le port COM%d, la fonction \"SetCommMask\" (Windows SDK) a �chou�e.".


RS232_PB_ALLOC_BUF_CYCL     = -116 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer logiciel cyclique pour la r�ception sur le port COM%d.".


RS232_GESTION_ASSYNCHRONE   = -115 :
  "Fonction non utilisable avec un port ouvert en mode assynchrone.".


RS232_PB_CONF_BUF_HARD      = -114 :
  "La configuration de la taille des buffers mat�riels TX et RX du port COM%d a echou�e, probl�me avec la fonction \"SetupComm\" (Windows SDK).".


RS232_PB_RAZ_BUFFER_RX      = -113 :
  "La raz du buffer RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

      
RS232_PB_RAZ_BUFFER_TX      = -112 :
  "La raz du buffer TX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

        
RS232_PB_RAZ_BUFFER_TX_RX   = -111 :
  "La raz des buffers TX et RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

     
RS232_PB_ENVOI_CHAINE       = -110 :
  "Chaine non �crit ou tronqu�e sur port COM%d, la fonction \"WriteFile\" (Windows SDK) a �chou�e.".


RS232_PB_ECRITURE_PORT      = -109 :
  "Probl�me d'�criture sur port COM%d.".


RS232_PB_LIBERATION_MEM     = -108 :
  "Probl�me de lib�ration de la m�moire allou�e pour le COM%d lors de la fermeture de ce dernier.".


RS232_PB_ID                  = -107 :
  "Identifiant inconnu.".


RS232_PB_FERMETURE_PORT      = -106 :
  "Probl�me lors de la fermeture du port COM%d, la fonction \"CloseHandle\" (Windows SDK) a �chou�e.".


RS232_PB_PARAMETRAGE_PORT    = -105 :
  "Probl�me lors du param�trage du port COM%d, la fonction \"SetCommState\" (Windows SDK) a �chou�e. V�rifier les param�tres.".


RS232_PB_RECUP_INFO_PORT     = -104 :
"Probl�me lors de la r�cup�ration des param�tres du port COM%d, la fonction \"GetCommState\" (Windows SDK) a �chou�e.".


RS232_PB_OUVERTURE_PORT      = -103 :
  "Probl�me lors de l'ouverture du port COM%d, la fonction \"CreateFile\" (Windows SDK) a �chou�e.".


RS232_PORT_DEJA_OUVERT       = -102 :
  "Port COM%d d�ja ouvert.".


RS232_PB_ALLOC_DYNAMIQUE     = -101 :
  "Probl�me d'allocation m�moire lors de l'ouverture du port COM%d.".     �    Message d'erreur renvoy� par la fonction. La taille de ces messages n'ex�de pas 1024 caract�res.

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.     1    Statut (pas d'erreur = S_OK, erreur = S_FALSE).         Tag � trouver.     L    Longueur du tag � trouver (caract�re fin de chaine carFinTag NON compris).     p    Caract�re de fin de chaine pour le tag et sa suite (exemple '\0', mais �a peut etre n'importe quoi d'autre !).     �    Chaine comportant le tag et sa suite (si tag trouv� : cette chaine va du tag au caractere carFinTag) renvoy�e par la fonction.     i    Longueur du tag et de sa suite (caract�re fin de chaine carFinTag NON compris) renvoy� par la fonction.     _    Dimension maximale admissible du tag et sa suite (caract�re fin de chaine carFinTag compris).     �    Position du d�but du tag dans le buffer de r�ception cyclique (compt� � partir de 0) renvoy� par la fonction.

Remarque :

- Permet de savoir si la suite du tag est sucseptible de contenir (au niveau taille) ce que l'on recherche par exemple.     F    Dimension totale du buffer cyclique examin� renvoy� par la fonction.     t    Indicateur de tag trouv� (non trouv� = RS232_TROUV_NON = 0, trouv� = RS232_TROUV_OUI = 1) renvoy� par la fonction.    ¨        d    hdlSession                        �� x 
   d    errorOccurred                     �� �    d    errorCode                         ��R    d    errorMsg                          ӻ���    d    retour                            �� R x    d    tag                               � R �    d    lngTag                            �` RR    d    carFinTag                         �� � x    d    tagSuite                          �` � �    d    lngTagSuite                       �� �R    d    dimMaxTagSuite                    �8 � x    d    posTag                            �4 � �    d    dimBuf                            ׂ �R 	    d    tagTrouv                               	            	            	            	                        	           	                	            	            	            P    Recherche d'une chaine dans le buffer cyclique de r�ception sur un port s�rie.         Identifiant du port s�rie.     �    Indique si une erreur est apparue (pas d'erreur = FALSE = 0, erreur = TRUE = 1).

Remarque :

- Il s'agit d'un compl�ment au retour de la fonction (voir retour). Cette variable est pr�sente pour une utilisation de la biblioth�que via TESTSTAND.        Code d'erreur renvoy� par la fonction.

Remarque :

- La fonction RS232_MAIN_ErrorManager renvoie un message d'erreur en fonction du code d'erreur. Les codes d'erreurs sont les suivants :


RS232_BUF_CIBLE_TROPS_PETIT = -127 :
  "Le buffer cible est trops petit pour effectuer la r�cup�ration des informations du buffer cyclique de r�ception sur port COM%d.".


RS232_TAG_SUITE_TROPS_GRAND = -126 :
  "La taille du tag trouv�, lors de la recherche de tag sur port COM%d, d�passe la taille limite ; la chaine retourn�e est tronqu�e !".


RS232_PB_ALLOC_BUF_TEMP     = -125 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer temporaire pour la recherche de tag sur le port COM%d.".


RS232_TAG_NON_TROUVE        = -124 :
  "La recherche de tag n'a rien trouv�e dans le buffer cyclique de r�ception du port COM%d.".

       
RS232_PB_LECTURE_PORT       = -123 :
  "Probl�me de lecture sur port COM%d.".


RS232_PB_ALLOC_BUF_INTER    = -122 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer interm�diaire pour la r�ception sur le port COM%d.".


RS232_PB_SUPRESSION_TACHE   = -121 :
  "Probl�me lors de la suppression de la tache de r�ception du port COM%d.".


RS232_PB_SUPPRESSION_MUTEX  = -120 :
  "Probl�me lors de la suppression du mutex pour la fermeture du port COM%d.".

    
RS232_PB_CREATION_MUTEX     = -119 :
  "Probl�me lors de la cr�ation du mutex pour l'utilisation des param�tres du port COM%d.".

    
RS232_PB_TACHE_RECEPTION    = -118 :
  "Probl�me lors de la cr�ation de la tache de r�ception du port COM%d.".


RS232_PB_EVEN_PORT_RX_CAR   = -117 :
  "Probl�me lors du param�trage du masque d'�v�nements pour le port COM%d, la fonction \"SetCommMask\" (Windows SDK) a �chou�e.".


RS232_PB_ALLOC_BUF_CYCL     = -116 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer logiciel cyclique pour la r�ception sur le port COM%d.".


RS232_GESTION_ASSYNCHRONE   = -115 :
  "Fonction non utilisable avec un port ouvert en mode assynchrone.".


RS232_PB_CONF_BUF_HARD      = -114 :
  "La configuration de la taille des buffers mat�riels TX et RX du port COM%d a echou�e, probl�me avec la fonction \"SetupComm\" (Windows SDK).".


RS232_PB_RAZ_BUFFER_RX      = -113 :
  "La raz du buffer RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

      
RS232_PB_RAZ_BUFFER_TX      = -112 :
  "La raz du buffer TX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

        
RS232_PB_RAZ_BUFFER_TX_RX   = -111 :
  "La raz des buffers TX et RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

     
RS232_PB_ENVOI_CHAINE       = -110 :
  "Chaine non �crit ou tronqu�e sur port COM%d, la fonction \"WriteFile\" (Windows SDK) a �chou�e.".


RS232_PB_ECRITURE_PORT      = -109 :
  "Probl�me d'�criture sur port COM%d.".


RS232_PB_LIBERATION_MEM     = -108 :
  "Probl�me de lib�ration de la m�moire allou�e pour le COM%d lors de la fermeture de ce dernier.".


RS232_PB_ID                  = -107 :
  "Identifiant inconnu.".


RS232_PB_FERMETURE_PORT      = -106 :
  "Probl�me lors de la fermeture du port COM%d, la fonction \"CloseHandle\" (Windows SDK) a �chou�e.".


RS232_PB_PARAMETRAGE_PORT    = -105 :
  "Probl�me lors du param�trage du port COM%d, la fonction \"SetCommState\" (Windows SDK) a �chou�e. V�rifier les param�tres.".


RS232_PB_RECUP_INFO_PORT     = -104 :
"Probl�me lors de la r�cup�ration des param�tres du port COM%d, la fonction \"GetCommState\" (Windows SDK) a �chou�e.".


RS232_PB_OUVERTURE_PORT      = -103 :
  "Probl�me lors de l'ouverture du port COM%d, la fonction \"CreateFile\" (Windows SDK) a �chou�e.".


RS232_PORT_DEJA_OUVERT       = -102 :
  "Port COM%d d�ja ouvert.".


RS232_PB_ALLOC_DYNAMIQUE     = -101 :
  "Probl�me d'allocation m�moire lors de l'ouverture du port COM%d.".     �    Message d'erreur renvoy� par la fonction. La taille de ces messages n'ex�de pas 1024 caract�res.

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.     1    Statut (pas d'erreur = S_OK, erreur = S_FALSE).         Tag � trouver.     L    Longueur du tag � trouver (caract�re fin de chaine carFinTag NON compris).     p    Caract�re de fin de chaine pour le tag et sa suite (exemple '\0', mais �a peut etre n'importe quoi d'autre !).     �    Chaine comportant le tag et sa suite (si tag trouv� : cette chaine va du tag au caractere carFinTag) renvoy�e par la fonction.     i    Longueur du tag et de sa suite (caract�re fin de chaine carFinTag NON compris) renvoy� par la fonction.     _    Dimension maximale admissible du tag et sa suite (caract�re fin de chaine carFinTag compris).     �    Position du d�but du tag dans le buffer de r�ception cyclique (compt� � partir de 0) renvoy� par la fonction.

Remarque :

- Permet de savoir si la suite du tag est sucseptible de contenir (au niveau taille) ce que l'on recherche par exemple.     F    Dimension totale du buffer cyclique examin� renvoy� par la fonction.     t    Indicateur de tag trouv� (non trouv� = RS232_TROUV_NON = 0, trouv� = RS232_TROUV_OUI = 1) renvoy� par la fonction.    ۼ        d    hdlSession                        �� x 
   d    errorOccurred                     �� �    d    errorCode                         ��R    d    errorMsg                          �����    d    retour                            � R x    d    tag                               �  R �    d    lngTag                            �t RR    d    carFinTag                         �� � x    d    tagSuite                          �t � �    d    lngTagSuite                       �� �R    d    dimMaxTagSuite                    �L � x    d    posTag                            �H � �    d    dimBuf                            � �R 	    d    tagTrouv                               	            	            	            	                        	           	                	            	            	           �    Lecture du buffer cyclique de r�ception du port concern� � un moment donn� (lecture sans effacement) et copie dans un buffer � une adresse donn�e.

Remarque :

- Il s'agit d'une copie du buffer cyclique de r�ception dans un autre buffer a un instant donn�.


Attention cette fonction remplace les '\0' au milieu des chaines par des '\n'. Donc des sauts de ligne en plus


Pr�f�rer la fonction RS232_MEAS_LectureBufPattern()
         Identifiant du port s�rie.     �    Indique si une erreur est apparue (pas d'erreur = FALSE = 0, erreur = TRUE = 1).

Remarque :

- Il s'agit d'un compl�ment au retour de la fonction (voir retour). Cette variable est pr�sente pour une utilisation de la biblioth�que via TESTSTAND.        Code d'erreur renvoy� par la fonction.

Remarque :

- La fonction RS232_MAIN_ErrorManager renvoie un message d'erreur en fonction du code d'erreur. Les codes d'erreurs sont les suivants :


RS232_BUF_CIBLE_TROPS_PETIT = -127 :
  "Le buffer cible est trops petit pour effectuer la r�cup�ration des informations du buffer cyclique de r�ception sur port COM%d.".


RS232_TAG_SUITE_TROPS_GRAND = -126 :
  "La taille du tag trouv�, lors de la recherche de tag sur port COM%d, d�passe la taille limite ; la chaine retourn�e est tronqu�e !".


RS232_PB_ALLOC_BUF_TEMP     = -125 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer temporaire pour la recherche de tag sur le port COM%d.".


RS232_TAG_NON_TROUVE        = -124 :
  "La recherche de tag n'a rien trouv�e dans le buffer cyclique de r�ception du port COM%d.".

       
RS232_PB_LECTURE_PORT       = -123 :
  "Probl�me de lecture sur port COM%d.".


RS232_PB_ALLOC_BUF_INTER    = -122 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer interm�diaire pour la r�ception sur le port COM%d.".


RS232_PB_SUPRESSION_TACHE   = -121 :
  "Probl�me lors de la suppression de la tache de r�ception du port COM%d.".


RS232_PB_SUPPRESSION_MUTEX  = -120 :
  "Probl�me lors de la suppression du mutex pour la fermeture du port COM%d.".

    
RS232_PB_CREATION_MUTEX     = -119 :
  "Probl�me lors de la cr�ation du mutex pour l'utilisation des param�tres du port COM%d.".

    
RS232_PB_TACHE_RECEPTION    = -118 :
  "Probl�me lors de la cr�ation de la tache de r�ception du port COM%d.".


RS232_PB_EVEN_PORT_RX_CAR   = -117 :
  "Probl�me lors du param�trage du masque d'�v�nements pour le port COM%d, la fonction \"SetCommMask\" (Windows SDK) a �chou�e.".


RS232_PB_ALLOC_BUF_CYCL     = -116 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer logiciel cyclique pour la r�ception sur le port COM%d.".


RS232_GESTION_ASSYNCHRONE   = -115 :
  "Fonction non utilisable avec un port ouvert en mode assynchrone.".


RS232_PB_CONF_BUF_HARD      = -114 :
  "La configuration de la taille des buffers mat�riels TX et RX du port COM%d a echou�e, probl�me avec la fonction \"SetupComm\" (Windows SDK).".


RS232_PB_RAZ_BUFFER_RX      = -113 :
  "La raz du buffer RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

      
RS232_PB_RAZ_BUFFER_TX      = -112 :
  "La raz du buffer TX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

        
RS232_PB_RAZ_BUFFER_TX_RX   = -111 :
  "La raz des buffers TX et RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

     
RS232_PB_ENVOI_CHAINE       = -110 :
  "Chaine non �crit ou tronqu�e sur port COM%d, la fonction \"WriteFile\" (Windows SDK) a �chou�e.".


RS232_PB_ECRITURE_PORT      = -109 :
  "Probl�me d'�criture sur port COM%d.".


RS232_PB_LIBERATION_MEM     = -108 :
  "Probl�me de lib�ration de la m�moire allou�e pour le COM%d lors de la fermeture de ce dernier.".


RS232_PB_ID                  = -107 :
  "Identifiant inconnu.".


RS232_PB_FERMETURE_PORT      = -106 :
  "Probl�me lors de la fermeture du port COM%d, la fonction \"CloseHandle\" (Windows SDK) a �chou�e.".


RS232_PB_PARAMETRAGE_PORT    = -105 :
  "Probl�me lors du param�trage du port COM%d, la fonction \"SetCommState\" (Windows SDK) a �chou�e. V�rifier les param�tres.".


RS232_PB_RECUP_INFO_PORT     = -104 :
"Probl�me lors de la r�cup�ration des param�tres du port COM%d, la fonction \"GetCommState\" (Windows SDK) a �chou�e.".


RS232_PB_OUVERTURE_PORT      = -103 :
  "Probl�me lors de l'ouverture du port COM%d, la fonction \"CreateFile\" (Windows SDK) a �chou�e.".


RS232_PORT_DEJA_OUVERT       = -102 :
  "Port COM%d d�ja ouvert.".


RS232_PB_ALLOC_DYNAMIQUE     = -101 :
  "Probl�me d'allocation m�moire lors de l'ouverture du port COM%d.".     �    Message d'erreur renvoy� par la fonction. La taille de ces messages n'ex�de pas 1024 caract�res.

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.     1    Statut (pas d'erreur = S_OK, erreur = S_FALSE).     D    Dimension totale du buffer cyclique copi� renvoy� par la fonction.     o    Taille maximale admissible pour la copie (correspond � la taille du buffer dans lequel on effectue la copie).     Q    Taille des donn�es copi�es (toutes donn�es confondues) renvoy� par la fonction.     7    Adresse du buffer dans lequel on effectue la recopie.    �*        d    hdlSession                        �N x    d    errorOccurred                     �L �    d    errorCode                        jR    d    errorMsg                         =���    d    retour                           v � �    d    dimBuf                           � � x    d    dimMaxBuffer                     9 _ �    d    tailleCopie                      � _ x    d    buffer                                 	            	            	            	            	                	            	          �    Lecture du buffer cyclique de r�ception du port concern� � un moment donn� (lecture sans effacement) et copie dans un buffer � une adresse donn�e (sBuffer).

Remarque :

- Cette fonction copie dans sBuffer le contenu du buffer cyclique jusqu'� avoir trouver la pattern. 
Cette fonction comporte un Timeout si la pattern n'est pas trouv�e


Compatible TestStand

Cette fonction supprime � la lecture les '\0' au milieu des chaine.         Identifiant du port s�rie.     �    Indique si une erreur est apparue (pas d'erreur = FALSE = 0, erreur = TRUE = 1).

Remarque :

- Il s'agit d'un compl�ment au retour de la fonction (voir retour). Cette variable est pr�sente pour une utilisation de la biblioth�que via TESTSTAND.        Code d'erreur renvoy� par la fonction.

Remarque :

- La fonction RS232_MAIN_ErrorManager renvoie un message d'erreur en fonction du code d'erreur. Les codes d'erreurs sont les suivants :


RS232_BUF_CIBLE_TROPS_PETIT = -127 :
  "Le buffer cible est trops petit pour effectuer la r�cup�ration des informations du buffer cyclique de r�ception sur port COM%d.".


RS232_TAG_SUITE_TROPS_GRAND = -126 :
  "La taille du tag trouv�, lors de la recherche de tag sur port COM%d, d�passe la taille limite ; la chaine retourn�e est tronqu�e !".


RS232_PB_ALLOC_BUF_TEMP     = -125 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer temporaire pour la recherche de tag sur le port COM%d.".


RS232_TAG_NON_TROUVE        = -124 :
  "La recherche de tag n'a rien trouv�e dans le buffer cyclique de r�ception du port COM%d.".

       
RS232_PB_LECTURE_PORT       = -123 :
  "Probl�me de lecture sur port COM%d.".


RS232_PB_ALLOC_BUF_INTER    = -122 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer interm�diaire pour la r�ception sur le port COM%d.".


RS232_PB_SUPRESSION_TACHE   = -121 :
  "Probl�me lors de la suppression de la tache de r�ception du port COM%d.".


RS232_PB_SUPPRESSION_MUTEX  = -120 :
  "Probl�me lors de la suppression du mutex pour la fermeture du port COM%d.".

    
RS232_PB_CREATION_MUTEX     = -119 :
  "Probl�me lors de la cr�ation du mutex pour l'utilisation des param�tres du port COM%d.".

    
RS232_PB_TACHE_RECEPTION    = -118 :
  "Probl�me lors de la cr�ation de la tache de r�ception du port COM%d.".


RS232_PB_EVEN_PORT_RX_CAR   = -117 :
  "Probl�me lors du param�trage du masque d'�v�nements pour le port COM%d, la fonction \"SetCommMask\" (Windows SDK) a �chou�e.".


RS232_PB_ALLOC_BUF_CYCL     = -116 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer logiciel cyclique pour la r�ception sur le port COM%d.".


RS232_GESTION_ASSYNCHRONE   = -115 :
  "Fonction non utilisable avec un port ouvert en mode assynchrone.".


RS232_PB_CONF_BUF_HARD      = -114 :
  "La configuration de la taille des buffers mat�riels TX et RX du port COM%d a echou�e, probl�me avec la fonction \"SetupComm\" (Windows SDK).".


RS232_PB_RAZ_BUFFER_RX      = -113 :
  "La raz du buffer RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

      
RS232_PB_RAZ_BUFFER_TX      = -112 :
  "La raz du buffer TX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

        
RS232_PB_RAZ_BUFFER_TX_RX   = -111 :
  "La raz des buffers TX et RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

     
RS232_PB_ENVOI_CHAINE       = -110 :
  "Chaine non �crit ou tronqu�e sur port COM%d, la fonction \"WriteFile\" (Windows SDK) a �chou�e.".


RS232_PB_ECRITURE_PORT      = -109 :
  "Probl�me d'�criture sur port COM%d.".


RS232_PB_LIBERATION_MEM     = -108 :
  "Probl�me de lib�ration de la m�moire allou�e pour le COM%d lors de la fermeture de ce dernier.".


RS232_PB_ID                  = -107 :
  "Identifiant inconnu.".


RS232_PB_FERMETURE_PORT      = -106 :
  "Probl�me lors de la fermeture du port COM%d, la fonction \"CloseHandle\" (Windows SDK) a �chou�e.".


RS232_PB_PARAMETRAGE_PORT    = -105 :
  "Probl�me lors du param�trage du port COM%d, la fonction \"SetCommState\" (Windows SDK) a �chou�e. V�rifier les param�tres.".


RS232_PB_RECUP_INFO_PORT     = -104 :
"Probl�me lors de la r�cup�ration des param�tres du port COM%d, la fonction \"GetCommState\" (Windows SDK) a �chou�e.".


RS232_PB_OUVERTURE_PORT      = -103 :
  "Probl�me lors de l'ouverture du port COM%d, la fonction \"CreateFile\" (Windows SDK) a �chou�e.".


RS232_PORT_DEJA_OUVERT       = -102 :
  "Port COM%d d�ja ouvert.".


RS232_PB_ALLOC_DYNAMIQUE     = -101 :
  "Probl�me d'allocation m�moire lors de l'ouverture du port COM%d.".     �    Message d'erreur renvoy� par la fonction. La taille de ces messages n'ex�de pas 1024 caract�res.

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.     1    Statut (pas d'erreur = S_OK, erreur = S_FALSE).     -    C'est le TimeOut de recherche de la pattern         Taille du Buffer.     7    Adresse du buffer dans lequel on effectue la recopie.     �    Info sur sBuffer retourn� par la fonction.

Retourne la taille de la chaine retourn� si la sChaineCherche a �t� trouv�.
Sinon retourne 0, cela ne veut pas dire que sBuffer est vide mais seulement que la pattern n'a pas �t� trouv�.
     s    C'est la pattern que l'on cherche dans le buffer cyclique.

Attention � la d�claration  : char sChaineCherche[30]   �        d    hdlSession                       � x    d    errorOccurred                    � �    d    errorCode                        R    d    errorMsg                         ����    d    retour                            � x    d    dTimeout                         B _ �    d    ulTailleBuffer                   ] _ x    d    sBuffer                          � ^U    d    ulBufInfo                        � �(    �    sPatternCherche                        	            	            	            	            2.5        	           	           "ST7100 >"    �    Temporisation en seconde.

Utilise la fonction de windows.h : Sleep()

Parametres : dSleep en seconde

Les retours d'erreurs sont conformes au format TestStand.     �    Indique si une erreur est apparue (pas d'erreur = FALSE = 0, erreur = TRUE = 1).

Remarque :

- Il s'agit d'un compl�ment au retour de la fonction (voir retour). Cette variable est pr�sente pour une utilisation de la biblioth�que via TESTSTAND.        Code d'erreur renvoy� par la fonction.

Remarque :

- La fonction RS232_MAIN_ErrorManager renvoie un message d'erreur en fonction du code d'erreur. Les codes d'erreurs sont les suivants :


RS232_BUF_CIBLE_TROPS_PETIT = -127 :
  "Le buffer cible est trops petit pour effectuer la r�cup�ration des informations du buffer cyclique de r�ception sur port COM%d.".


RS232_TAG_SUITE_TROPS_GRAND = -126 :
  "La taille du tag trouv�, lors de la recherche de tag sur port COM%d, d�passe la taille limite ; la chaine retourn�e est tronqu�e !".


RS232_PB_ALLOC_BUF_TEMP     = -125 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer temporaire pour la recherche de tag sur le port COM%d.".


RS232_TAG_NON_TROUVE        = -124 :
  "La recherche de tag n'a rien trouv�e dans le buffer cyclique de r�ception du port COM%d.".

       
RS232_PB_LECTURE_PORT       = -123 :
  "Probl�me de lecture sur port COM%d.".


RS232_PB_ALLOC_BUF_INTER    = -122 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer interm�diaire pour la r�ception sur le port COM%d.".


RS232_PB_SUPRESSION_TACHE   = -121 :
  "Probl�me lors de la suppression de la tache de r�ception du port COM%d.".


RS232_PB_SUPPRESSION_MUTEX  = -120 :
  "Probl�me lors de la suppression du mutex pour la fermeture du port COM%d.".

    
RS232_PB_CREATION_MUTEX     = -119 :
  "Probl�me lors de la cr�ation du mutex pour l'utilisation des param�tres du port COM%d.".

    
RS232_PB_TACHE_RECEPTION    = -118 :
  "Probl�me lors de la cr�ation de la tache de r�ception du port COM%d.".


RS232_PB_EVEN_PORT_RX_CAR   = -117 :
  "Probl�me lors du param�trage du masque d'�v�nements pour le port COM%d, la fonction \"SetCommMask\" (Windows SDK) a �chou�e.".


RS232_PB_ALLOC_BUF_CYCL     = -116 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer logiciel cyclique pour la r�ception sur le port COM%d.".


RS232_GESTION_ASSYNCHRONE   = -115 :
  "Fonction non utilisable avec un port ouvert en mode assynchrone.".


RS232_PB_CONF_BUF_HARD      = -114 :
  "La configuration de la taille des buffers mat�riels TX et RX du port COM%d a echou�e, probl�me avec la fonction \"SetupComm\" (Windows SDK).".


RS232_PB_RAZ_BUFFER_RX      = -113 :
  "La raz du buffer RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

      
RS232_PB_RAZ_BUFFER_TX      = -112 :
  "La raz du buffer TX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

        
RS232_PB_RAZ_BUFFER_TX_RX   = -111 :
  "La raz des buffers TX et RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

     
RS232_PB_ENVOI_CHAINE       = -110 :
  "Chaine non �crit ou tronqu�e sur port COM%d, la fonction \"WriteFile\" (Windows SDK) a �chou�e.".


RS232_PB_ECRITURE_PORT      = -109 :
  "Probl�me d'�criture sur port COM%d.".


RS232_PB_LIBERATION_MEM     = -108 :
  "Probl�me de lib�ration de la m�moire allou�e pour le COM%d lors de la fermeture de ce dernier.".


RS232_PB_ID                  = -107 :
  "Identifiant inconnu.".


RS232_PB_FERMETURE_PORT      = -106 :
  "Probl�me lors de la fermeture du port COM%d, la fonction \"CloseHandle\" (Windows SDK) a �chou�e.".


RS232_PB_PARAMETRAGE_PORT    = -105 :
  "Probl�me lors du param�trage du port COM%d, la fonction \"SetCommState\" (Windows SDK) a �chou�e. V�rifier les param�tres.".


RS232_PB_RECUP_INFO_PORT     = -104 :
"Probl�me lors de la r�cup�ration des param�tres du port COM%d, la fonction \"GetCommState\" (Windows SDK) a �chou�e.".


RS232_PB_OUVERTURE_PORT      = -103 :
  "Probl�me lors de l'ouverture du port COM%d, la fonction \"CreateFile\" (Windows SDK) a �chou�e.".


RS232_PORT_DEJA_OUVERT       = -102 :
  "Port COM%d d�ja ouvert.".


RS232_PB_ALLOC_DYNAMIQUE     = -101 :
  "Probl�me d'allocation m�moire lors de l'ouverture du port COM%d.".     �    Message d'erreur renvoy� par la fonction. La taille de ces messages n'ex�de pas 1024 caract�res.

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.         Dur�e en seconde   #) x     d    errorOccurred                    $' �    d    errorCode                        3ER    d    errorMsg                         4 > �    �    dSleep                          ���� ?_��                                            	            	            	            0.1    seconde    �    Printf de sBuffer

Utilise la fonction de windows.h : printf()

Parametres : sBuffer pointeur de chaine

Les retours d'erreurs sont conformes au format TestStand.     �    Indique si une erreur est apparue (pas d'erreur = FALSE = 0, erreur = TRUE = 1).

Remarque :

- Il s'agit d'un compl�ment au retour de la fonction (voir retour). Cette variable est pr�sente pour une utilisation de la biblioth�que via TESTSTAND.        Code d'erreur renvoy� par la fonction.

Remarque :

- La fonction RS232_MAIN_ErrorManager renvoie un message d'erreur en fonction du code d'erreur. Les codes d'erreurs sont les suivants :


RS232_BUF_CIBLE_TROPS_PETIT = -127 :
  "Le buffer cible est trops petit pour effectuer la r�cup�ration des informations du buffer cyclique de r�ception sur port COM%d.".


RS232_TAG_SUITE_TROPS_GRAND = -126 :
  "La taille du tag trouv�, lors de la recherche de tag sur port COM%d, d�passe la taille limite ; la chaine retourn�e est tronqu�e !".


RS232_PB_ALLOC_BUF_TEMP     = -125 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer temporaire pour la recherche de tag sur le port COM%d.".


RS232_TAG_NON_TROUVE        = -124 :
  "La recherche de tag n'a rien trouv�e dans le buffer cyclique de r�ception du port COM%d.".

       
RS232_PB_LECTURE_PORT       = -123 :
  "Probl�me de lecture sur port COM%d.".


RS232_PB_ALLOC_BUF_INTER    = -122 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer interm�diaire pour la r�ception sur le port COM%d.".


RS232_PB_SUPRESSION_TACHE   = -121 :
  "Probl�me lors de la suppression de la tache de r�ception du port COM%d.".


RS232_PB_SUPPRESSION_MUTEX  = -120 :
  "Probl�me lors de la suppression du mutex pour la fermeture du port COM%d.".

    
RS232_PB_CREATION_MUTEX     = -119 :
  "Probl�me lors de la cr�ation du mutex pour l'utilisation des param�tres du port COM%d.".

    
RS232_PB_TACHE_RECEPTION    = -118 :
  "Probl�me lors de la cr�ation de la tache de r�ception du port COM%d.".


RS232_PB_EVEN_PORT_RX_CAR   = -117 :
  "Probl�me lors du param�trage du masque d'�v�nements pour le port COM%d, la fonction \"SetCommMask\" (Windows SDK) a �chou�e.".


RS232_PB_ALLOC_BUF_CYCL     = -116 :
  "Une erreur est survenue lors de l'allocation m�moire du buffer logiciel cyclique pour la r�ception sur le port COM%d.".


RS232_GESTION_ASSYNCHRONE   = -115 :
  "Fonction non utilisable avec un port ouvert en mode assynchrone.".


RS232_PB_CONF_BUF_HARD      = -114 :
  "La configuration de la taille des buffers mat�riels TX et RX du port COM%d a echou�e, probl�me avec la fonction \"SetupComm\" (Windows SDK).".


RS232_PB_RAZ_BUFFER_RX      = -113 :
  "La raz du buffer RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

      
RS232_PB_RAZ_BUFFER_TX      = -112 :
  "La raz du buffer TX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

        
RS232_PB_RAZ_BUFFER_TX_RX   = -111 :
  "La raz des buffers TX et RX du port COM%d a echou�e, probl�me avec la fonction \"PurgeComm\" (Windows SDK).".

     
RS232_PB_ENVOI_CHAINE       = -110 :
  "Chaine non �crit ou tronqu�e sur port COM%d, la fonction \"WriteFile\" (Windows SDK) a �chou�e.".


RS232_PB_ECRITURE_PORT      = -109 :
  "Probl�me d'�criture sur port COM%d.".


RS232_PB_LIBERATION_MEM     = -108 :
  "Probl�me de lib�ration de la m�moire allou�e pour le COM%d lors de la fermeture de ce dernier.".


RS232_PB_ID                  = -107 :
  "Identifiant inconnu.".


RS232_PB_FERMETURE_PORT      = -106 :
  "Probl�me lors de la fermeture du port COM%d, la fonction \"CloseHandle\" (Windows SDK) a �chou�e.".


RS232_PB_PARAMETRAGE_PORT    = -105 :
  "Probl�me lors du param�trage du port COM%d, la fonction \"SetCommState\" (Windows SDK) a �chou�e. V�rifier les param�tres.".


RS232_PB_RECUP_INFO_PORT     = -104 :
"Probl�me lors de la r�cup�ration des param�tres du port COM%d, la fonction \"GetCommState\" (Windows SDK) a �chou�e.".


RS232_PB_OUVERTURE_PORT      = -103 :
  "Probl�me lors de l'ouverture du port COM%d, la fonction \"CreateFile\" (Windows SDK) a �chou�e.".


RS232_PORT_DEJA_OUVERT       = -102 :
  "Port COM%d d�ja ouvert.".


RS232_PB_ALLOC_DYNAMIQUE     = -101 :
  "Probl�me d'allocation m�moire lors de l'ouverture du port COM%d.".     �    Message d'erreur renvoy� par la fonction. La taille de ces messages n'ex�de pas 1024 caract�res.

Remarque :

- Pour connaitre les codes d'erreurs et les messages qui leur correspondent voir errorCode.     7    Adresse du buffer dans lequel on effectue la recopie.   6 x    d    errorOccurred                    7 �    d    errorCode                        F9R    d    errorMsg                         G W �     d    sBuffer                            	            	            	            	        ����         �  $y             K.        RS232_MAIN_OpenPort                                                                                                                     ����         %�  8O             K.        RS232_MAIN_ClosePort                                                                                                                    ����         9�  K             K.        RS232_MAIN_PurgeTxPort                                                                                                                  ����         LI  ]�             K.        RS232_MAIN_PurgeRxPort                                                                                                                  ����         _  p�             K.        RS232_MAIN_RazBufferCycliqueRx                                                                                                          ����         q�                  K.        RS232_MAIN_Nettoyage                                                                                                                    ����         r�  ��             K.        RS232_MAIN_ErrorManager                                                                                                                 ����         ��  �             K.        RS232_CONF_EcrirePort                                                                                                                   ����         ��  �/             K.        RS232_CONF_EcrirePortTestStand                                                                                                          ����         ��  �h             K.        RS232_CONF_EcrirePortDelaiInterCar                                                                                                      ����         �P  ��             K.        RS232_MEAS_RechercheTag                                                                                                                 ����         �d  �             K.        RS232_MEAS_RechercheTagTestStand                                                                                                        ����         �x �         	    K.        RS232_MEAS_LectureBuffer                                                                                                                ����        
           
    K.        RS232_MEAS_LectureBufPattern                                                                                                            ����        " 42             K.        RS232_MEAS_Tempo                                                                                                                        ����        5q GK             K.        RS232_MEAS_Printf                                                                                                                              �                                                                                    
DParam�trer                                                                           �Ouvrir port                                                                          �Fermer port                                                                          �Purge TX port                                                                        �Purge RX port                                                                        �Purge buffer cyclique RX                                                             �Nettoyage                                                                            �Gestion d'erreur                                                                    
�Ecrire                                                                               �Ecrire port                                                                          �Ecrire port Chaine compatible TestStand                                              �Ecrire port d�lai inter caract�re                                                   <Lire                                                                                 �Recherche de tag                                                                     �Recherche de tag compatible Test Stand                                               �Lecture buffer cyclique RX                                                           �Lecture buffer cyclique et cherche pattern                                           �Tempo                                                                                �Printf                                                                          