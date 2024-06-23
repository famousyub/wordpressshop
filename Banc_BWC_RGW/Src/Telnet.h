
void ResetIHM ( void);

int Telnet_Query_thread (int handletelnet,char *Question,char *Tag,char *reponse,int TimeOutms);

int DisconnectTelnetThread(int handle);

int saveLogFile(char *logFile,char * Numserie,int status,int Produit);

int Telnet_Query (int HandleTelnet,char *Question,char *Tag,char *Response,char *signal,int TimeOutms); 

int Telnet_Query_Festo (int handleTelnet, char *Question,char *Tag,char *reponse,char *signal,int IndiceCMMO,int TimeOutms) ; 

int ConnectTelnetThread(char * Ip,int *handleTelnet) ;

int ClearBufferTelnet_2G(int iFlagTelnet);

int Telnet_QueryThread_2G (int handleTelnet, char *Question,char *Tag,char *reponse,int TimeOutms);

int ClearBufferTelnet(int iFlagTelnet);

int ClearBufferTelnet_5G(int iFlagTelnet);

int Telnet_Query_Dect(char *Question,char *Tag,char *reponse,int TimeOutms);

int Telnet_QueryThread_BT (int handleTelnet, char *Question,char *Tag,char *reponse,int TimeOutms);

int Telnet_Query_TME(int handleTelnet,char *reponse,int TimeOutms);

int Telnet_Query_TBR6_FP(int handleTelnet, char *Question,char *Tag,char *reponse,int TimeOutms);

int Telnet_Query_GPIO(int handleTelnet, char *Question,char *Tag,char *reponse,int TimeOutms);
