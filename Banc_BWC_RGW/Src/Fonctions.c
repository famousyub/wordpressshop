// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//
//
// ==============================================================================
//   PROJET			: Banc HDD
//   MODULE			: Fonctions
//   PROCESSEUR		: INTEL Pentium
//   ENVIRONNEMENT	: Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION	: Définition des fonctions utiles à l'application Perso.
//
// ==============================================================================
//   REMARQUES		:
// ==============================================================================
//   MODIFICATIONS	:
//
// Version Rev X
// Date / Author
//
// V 1.1.0
// 15-Décembre-2009			EAH
//		>>>	 Création issue du banc de personnalisation
// ==============================================================================

// ==============================================================================
// INCLUDE
// ==============================================================================
#include "Include.h"

char  python[2048];
static int FileHandle;
// ==============================================================================
// DECLARATION DES VARIABLES LOCALES
// ==============================================================================

const char CODE_HEXA[] =
{
	//       Décimal   Octal   Hex  Binaire   Caractère
	//       -------   -----   ---  --------    ------
	'\xff',  //         000      000    00   00000000      NUL    (Null char.)
	'\xff',  //         001      001    01   00000001      SOH    (Start of Header)
	'\xff',  //         002      002    02   00000010      STX    (Start of Text)
	'\xff',  //         003      003    03   00000011      ETX    (End of Text)
	'\xff',  //         004      004    04   00000100      EOT    (End of Transmission)
	'\xff',  //         005      005    05   00000101      ENQ    (Enquiry)
	'\xff',  //         006      006    06   00000110      ACK    (Acknowledgment)
	'\xff',  //         007      007    07   00000111      BEL    (Bell)
	'\xff',  //         008      010    08   00001000       BS    (Backspace)
	'\xff',  //         009      011    09   00001001       HT    (Horizontal Tab)
	'\xff',  //         010      012    0A   00001010       LF    (Line Feed)
	'\xff',  //         011      013    0B   00001011       VT    (Vertical Tab)
	'\xff',  //         012      014    0C   00001100       FF    (Form Feed)
	'\xff',  //         013      015    0D   00001101       CR    (Carriage Return)
	'\xff',  //         014      016    0E   00001110       SO    (Shift Out)
	'\xff',  //         015      017    0F   00001111       SI    (Shift In)
	'\xff',  //         016      020    10   00010000      DLE    (Data Link Escape)
	'\xff',  //         017      021    11   00010001      DC1    (XON)(Device Control 1)
	'\xff',  //         018      022    12   00010010      DC2    (Device Control 2)
	'\xff',  //         019      023    13   00010011      DC3    (XOFF)(Device Control 3)
	'\xff',  //         020      024    14   00010100      DC4    (Device Control 4)
	'\xff',  //         021      025    15   00010101      NAK    (Negative Acknowledgement)
	'\xff',  //         022      026    16   00010110      SYN    (Synchronous Idle)
	'\xff',  //         023      027    17   00010111      ETB    (End of Trans. Block)
	'\xff',  //         024      030    18   00011000      CAN    (Cancel)
	'\xff',  //         025      031    19   00011001       EM    (End of Medium)
	'\xff',  //         026      032    1A   00011010      SUB    (Substitute)
	'\xff',  //         027      033    1B   00011011      ESC    (Escape)
	'\xff',  //         028      034    1C   00011100       FS    (File Separator)
	'\xff',  //         029      035    1D   00011101       GS    (Group Separator)
	'\xff',  //         030      036    1E   00011110       RS    (Request to Send)(Record Separator)
	'\xff',  //         031      037    1F   00011111       US    (Unit Separator)
	'\xff',  //         032      040    20   00100000       SP    (Space)
	'\xff',  //         033      041    21   00100001        !    (exclamation mark)
	'\xff',  //         034      042    22   00100010        "    (double quote) //"
	'\xff',  //         035      043    23   00100011        #    (number sign)
	'\xff',  //         036      044    24   00100100        $    (dollar sign)
	'\xff',  //         037      045    25   00100101        %    (percent)
	'\xff',  //         038      046    26   00100110        &    (ampersand)
	'\xff',  //         039      047    27   00100111        '    (single quote)
	'\xff',  //         040      050    28   00101000        (    (left opening parenthesis)
	'\xff',  //         041      051    29   00101001        )    (right closing parenthesis)
	'\xff',  //         042      052    2A   00101010        *    (asterisk)
	'\xff',  //         043      053    2B   00101011        +    (plus)
	'\xff',  //         044      054    2C   00101100        ,    (comma)
	'\xff',  //         045      055    2D   00101101        -    (minus or dash)
	'\xff',  //         046      056    2E   00101110        .    (dot)
	'\xff',  //         047      057    2F   00101111        /    (forward slash)
	'\x00',  //         048      060    30   00110000        0
	'\x01',  //         049      061    31   00110001        1
	'\x02',  //         050      062    32   00110010        2
	'\x03',  //         051      063    33   00110011        3
	'\x04',  //         052      064    34   00110100        4
	'\x05',  //         053      065    35   00110101        5
	'\x06',  //         054      066    36   00110110        6
	'\x07',  //         055      067    37   00110111        7
	'\x08',  //         056      070    38   00111000        8
	'\x09',  //         057      071    39   00111001        9
	'\xff',  //         058      072    3A   00111010        :    (colon)
	'\xff',  //         059      073    3B   00111011        ;    (semi-colon)
	'\xff',  //         060      074    3C   00111100        <    (less than sign)
	'\xff',  //         061      075    3D   00111101        =    (equal sign)
	'\xff',  //         062      076    3E   00111110        >    (greater than sign)
	'\xff',  //         063      077    3F   00111111        ?    (question mark)
	'\xff',  //         064      100    40   01000000        @    (AT symbol)
	'\x0a',  //         065      101    41   01000001        A
	'\x0b',  //         066      102    42   01000010        B
	'\x0c',  //         067      103    43   01000011        C
	'\x0d',  //         068      104    44   01000100        D
	'\x0e',  //         069      105    45   01000101        E
	'\x0f',  //         070      106    46   01000110        F
	'\xff',  //         071      107    47   01000111        G
	'\xff',  //         072      110    48   01001000        H
	'\xff',  //         073      111    49   01001001        I
	'\xff',  //         074      112    4A   01001010        J
	'\xff',  //         075      113    4B   01001011        K
	'\xff',  //         076      114    4C   01001100        L
	'\xff',  //         077      115    4D   01001101        M
	'\xff',  //         078      116    4E   01001110        N
	'\xff',  //         079      117    4F   01001111        O
	'\xff',  //         080      120    50   01010000        P
	'\xff',  //         081      121    51   01010001        Q
	'\xff',  //         082      122    52   01010010        R
	'\xff',  //         083      123    53   01010011        S
	'\xff',  //         084      124    54   01010100        T
	'\xff',  //         085      125    55   01010101        U
	'\xff',  //         086      126    56   01010110        V
	'\xff',  //         087      127    57   01010111        W
	'\xff',  //         088      130    58   01011000        X
	'\xff',  //         089      131    59   01011001        Y
	'\xff',  //         090      132    5A   01011010        Z
	'\xff',  //         091      133    5B   01011011        [    (left opening bracket)
	'\xff',  //         092      134    5C   01011100        \    (back slash)
	'\xff',  //         093      135    5D   01011101        ]    (right closing bracket)
	'\xff',  //         094      136    5E   01011110        ^    (caret cirumflex)
	'\xff',  //         095      137    5F   01011111        _    (underscore)
	'\xff',  //         096      140    60   01100000        `
	'\x0a',  //         097      141    61   01100001        a
	'\x0b',  //         098      142    62   01100010        b
	'\x0c',  //         099      143    63   01100011        c
	'\x0d',  //         100      144    64   01100100        d
	'\x0e',  //         101      145    65   01100101        e
	'\x0f',  //         102      146    66   01100110        f
	'\xff',  //         103      147    67   01100111        g
	'\xff',  //         104      150    68   01101000        h
	'\xff',  //         105      151    69   01101001        i
	'\xff',  //         106      152    6A   01101010        j
	'\xff',  //         107      153    6B   01101011        k
	'\xff',  //         108      154    6C   01101100        l
	'\xff',  //         109      155    6D   01101101        m
	'\xff',  //         110      156    6E   01101110        n
	'\xff',  //         111      157    6F   01101111        o
	'\xff',  //         112      160    70   01110000        p
	'\xff',  //         113      161    71   01110001        q
	'\xff',  //         114      162    72   01110010        r
	'\xff',  //         115      163    73   01110011        s
	'\xff',  //         116      164    74   01110100        t
	'\xff',  //         117      165    75   01110101        u
	'\xff',  //         118      166    76   01110110        v
	'\xff',  //         119      167    77   01110111        w
	'\xff',  //         120      170    78   01111000        x
	'\xff',  //         121      171    79   01111001        y
	'\xff',  //         122      172    7A   01111010        z
	'\xff',  //         123      173    7B   01111011        {    (left opening brace)
	'\xff',  //         124      174    7C   01111100        |    (vertical bar)
	'\xff',  //         125      175    7D   01111101        }    (right closing brace)
	'\xff',  //         126      176    7E   01111110        ~    (tilde)
	'\xff',  //         127      177    7F   01111111      DEL    (delete)
};

const char CODE_ASCII[] =
{
	//       Décimal   Octal   Hex  Binaire   Caractère
	//       -------   -----   ---  --------    ------
	'\x00',  //         000      000    00   00000000      NUL    (Null char.)
	'\x00',  //         001      001    01   00000001      SOH    (Start of Header)
	'\x00',  //         002      002    02   00000010      STX    (Start of Text)
	'\x00',  //         003      003    03   00000011      ETX    (End of Text)
	'\x00',  //         004      004    04   00000100      EOT    (End of Transmission)
	'\x00',  //         005      005    05   00000101      ENQ    (Enquiry)
	'\x00',  //         006      006    06   00000110      ACK    (Acknowledgment)
	'\x00',  //         007      007    07   00000111      BEL    (Bell)
	'\x00',  //         008      010    08   00001000       BS    (Backspace)
	'\x00',  //         009      011    09   00001001       HT    (Horizontal Tab)
	'\x00',  //         010      012    0A   00001010       LF    (Line Feed)
	'\x00',  //         011      013    0B   00001011       VT    (Vertical Tab)
	'\x00',  //         012      014    0C   00001100       FF    (Form Feed)
	'\x00',  //         013      015    0D   00001101       CR    (Carriage Return)
	'\x00',  //         014      016    0E   00001110       SO    (Shift Out)
	'\x00',  //         015      017    0F   00001111       SI    (Shift In)
	'\x00',  //         016      020    10   00010000      DLE    (Data Link Escape)
	'\x00',  //         017      021    11   00010001      DC1    (XON)(Device Control 1)
	'\x00',  //         018      022    12   00010010      DC2    (Device Control 2)
	'\x00',  //         019      023    13   00010011      DC3    (XOFF)(Device Control 3)
	'\x00',  //         020      024    14   00010100      DC4    (Device Control 4)
	'\x00',  //         021      025    15   00010101      NAK    (Negative Acknowledgement)
	'\x00',  //         022      026    16   00010110      SYN    (Synchronous Idle)
	'\x00',  //         023      027    17   00010111      ETB    (End of Trans. Block)
	'\x00',  //         024      030    18   00011000      CAN    (Cancel)
	'\x00',  //         025      031    19   00011001       EM    (End of Medium)
	'\x00',  //         026      032    1A   00011010      SUB    (Substitute)
	'\x00',  //         027      033    1B   00011011      ESC    (Escape)
	'\x00',  //         028      034    1C   00011100       FS    (File Separator)
	'\x00',  //         029      035    1D   00011101       GS    (Group Separator)
	'\x00',  //         030      036    1E   00011110       RS    (Request to Send)(Record Separator)
	'\x00',  //         031      037    1F   00011111       US    (Unit Separator)
	'\x00',  //         032      040    20   00100000       SP    (Space)
	'\x00',  //         033      041    21   00100001        !    (exclamation mark)
	'\"',    //         034      042    22   00100010        "    (double quote)
	'\x00',  //         035      043    23   00100011        #    (number sign)
	'\x00',  //         036      044    24   00100100        $    (dollar sign)
	'\x00',  //         037      045    25   00100101        %    (percent)
	'\x00',  //         038      046    26   00100110        &    (ampersand)
	'\x00',  //         039      047    27   00100111        '    (single quote)
	'\x00',  //         040      050    28   00101000        (    (left opening parenthesis)
	'\x00',  //         041      051    29   00101001        )    (right closing parenthesis)
	'\x00',  //         042      052    2A   00101010        *    (asterisk)
	'\x00',  //         043      053    2B   00101011        +    (plus)
	'\x00',  //         044      054    2C   00101100        ,    (comma)
	'\x00',  //         045      055    2D   00101101        -    (minus or dash)
	'\x00',  //         046      056    2E   00101110        .    (dot)
	'\x00',    //         047      057    2F   00101111        /    (forward slash)
	'\x02',  //         048      060    30   00110000        0
	'\x02',  //         049      061    31   00110001        1
	'\x00',  //         050      062    32   00110010        2
	'\x00',  //         051      063    33   00110011        3
	'\x00',  //         052      064    34   00110100        4
	'\x00',  //         053      065    35   00110101        5
	'\x00',  //         054      066    36   00110110        6
	'\x00',  //         055      067    37   00110111        7
	'\x00',  //         056      070    38   00111000        8
	'\x00',  //         057      071    39   00111001        9
	'\x00',  //         058      072    3A   00111010        :    (colon)
	'\x00',  //         059      073    3B   00111011        ;    (semi-colon)
	'\x00',  //         060      074    3C   00111100        <    (less than sign)
	'\x00',  //         061      075    3D   00111101        =    (equal sign)
	'\x00',  //         062      076    3E   00111110        >    (greater than sign)
	'\x00',  //         063      077    3F   00111111        ?    (question mark)
	'\x00',  //         064      100    40   01000000        @    (AT symbol)
	'\x00',  //         065      101    41   01000001        A
	'\x00',  //         066      102    42   01000010        B
	'\x00',  //         067      103    43   01000011        C
	'\x00',  //         068      104    44   01000100        D
	'\x00',  //         069      105    45   01000101        E
	'\x00',  //         070      106    46   01000110        F
	'\x00',  //         071      107    47   01000111        G
	'\x00',  //         072      110    48   01001000        H
	'\x00',  //         073      111    49   01001001        I
	'\x00',  //         074      112    4A   01001010        J
	'\x00',  //         075      113    4B   01001011        K
	'\x00',  //         076      114    4C   01001100        L
	'\x00',  //         077      115    4D   01001101        M
	'\x00',  //         078      116    4E   01001110        N
	'\x00',  //         079      117    4F   01001111        O
	'\x00',  //         080      120    50   01010000        P
	'\x00',  //         081      121    51   01010001        Q
	'\x00',  //         082      122    52   01010010        R
	'\x00',  //         083      123    53   01010011        S
	'\x00',  //         084      124    54   01010100        T
	'\x00',  //         085      125    55   01010101        U
	'\x00',  //         086      126    56   01010110        V
	'\x00',  //         087      127    57   01010111        W
	'\x00',  //         088      130    58   01011000        X
	'\x00',  //         089      131    59   01011001        Y
	'\x00',  //         090      132    5A   01011010        Z
	'\x00',  //         091      133    5B   01011011        [    (left opening bracket)
	'\\',    //         092      134    5C   01011100        \    (back slash)
	'\x00',  //         093      135    5D   01011101        ]    (right closing bracket)
	'\x00',  //         094      136    5E   01011110        ^    (caret cirumflex)
	'\x00',  //         095      137    5F   01011111        _    (underscore)
	'\x00',  //         096      140    60   01100000        `
	'\a',    //         097      141    61   01100001        a
	'\b',    //         098      142    62   01100010        b
	'\x00',  //         099      143    63   01100011        c
	'\x00',  //         100      144    64   01100100        d
	'\x00',  //         101      145    65   01100101        e
	'\f',    //         102      146    66   01100110        f
	'\x00',  //         103      147    67   01100111        g
	'\x00',  //         104      150    68   01101000        h
	'\x00',  //         105      151    69   01101001        i
	'\x00',  //         106      152    6A   01101010        j
	'\x00',  //         107      153    6B   01101011        k
	'\x00',  //         108      154    6C   01101100        l
	'\x00',  //         109      155    6D   01101101        m
	'\n',    //         110      156    6E   01101110        n
	'\x00',  //         111      157    6F   01101111        o
	'\x00',  //         112      160    70   01110000        p
	'\x00',  //         113      161    71   01110001        q
	'\r',    //         114      162    72   01110010        r
	'\x00',  //         115      163    73   01110011        s
	'\t',    //         116      164    74   01110100        t
	'\x00',  //         117      165    75   01110101        u
	'\v',    //         118      166    76   01110110        v
	'\x00',  //         119      167    77   01110111        w
	'\x01',  //         120      170    78   01111000        x
	'\x00',  //         121      171    79   01111001        y
	'\x00',  //         122      172    7A   01111010        z
	'\x00',  //         123      173    7B   01111011        {    (left opening brace)
	'\x00',  //         124      174    7C   01111100        |    (vertical bar)
	'\x00',  //         125      175    7D   01111101        }    (right closing brace)
	'\x00',  //         126      176    7E   01111110        ~    (tilde)
	'\x00',  //         127      177    7F   01111111      DEL    (delete)
};

SOCKET irt_server;


// ==============================================================================
// FONCTION : 	  FCT_TracaBdd
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int FCT_TracaBdd (int nItfe)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - int nItfe	: Index du SLOT.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Fonction d'enregistrement en base du passage du décodeur sur
//				  le banc Perso pour un test OK.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  30/11/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================



//ViSession g_Session = 0;

int FCT_TracaBdd (int nItfe)
{
	int indexCle = -1;
	int                 error = 0;
	char                strMessageErreur[TAILLE_MSG_ERR_MAX] = {'\0'};
	char                strMessage[2048] = {'\0'};
	char    			chCodeProduitTMP[SCPROD_OBJET_LONG_MAX] = {'\0'};
	char				chNumSerieHddTMP[SCPROD_OBJET_LONG_MAX] = {'\0'};
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	T_VARIABLES         *ptrVariablesEtat = &(gSlot[nItfe].variablesEtat);
	T_MESURES           *ptrMesures = &(gSlot[nItfe].mesures);
	T_VARIABLES     	*ptrVariablesConf = &(gSlot[nItfe].variablesConf);

#ifndef NO_KEYS

	// ==================================
	// = Ecriture des propriétés en BDD =
	// ==================================
	// ====================================
	// = Affichage Sous Etape dans le log =
	// ====================================
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_SOUS_ETAPE, GET_MESSAGE(FCT_MSG_TRACABILITE_ASSEMBLE));

	// ======================================================================================
	// = Enregistrement des mesures (anciennement mesure par mesure, maintenant par tableau =
	// ======================================================================================
	//errChk ( MES_EnregistrerTableau (ptrMesures, nItfe, strMessageErreur ) );


	// ========================
	// = Collecte des Données =
	// ========================
	//errChk ( VAR_GestionTableau (nItfe, &gTcomBase, ptrVariablesEtat, ptrVariablesTraca->PfinSfcSAPME, ptrVariablesTraca->PersoSAPMERessource, SCPROD_STR_VIDE, VAR_SAPME_COLLECT, strMessageErreur) );

	// ===================================================
	// = Enregistrement du Complete (== Mvt de Test OK)  =
	// ===================================================

	if(VAR_GET_BOOL(ptrVariablesConf, VAR_CONF_GTW_BWC_FLAG_sfc, 0) ==1)
	{
		errChk ( SCPROD_AssemblageComposant ( 	nItfe,
												&gTcomBase,
												ptrVariablesTraca->CieSn,
												NULL,
												ptrVariablesTraca->CiuSfcSAPME,
												SCPROD_ASSEMBLAGE_INVENTORY_ID,
												SCPROD_OPERATION_DEFAUT,
												SCPROD_RESSOURCE_DEFAUT,
												strMessageErreur ));
	}


	errChk ( SCPROD_CompleteSnPFIN (	nItfe, &gTcomBase, NOM_OPERATION, ptrVariablesTraca->NomRessourceSAPME, strMessageErreur ));

	//essai validation
	//errChk ( SCPROD_CompleteSnPFIN (	nItfe, &gTcomBase, NOM_OPERATION,"GW_I03_TEST-BOUTON_01", strMessageErreur ));


	// On mémorise que le produit a été tracé
	// -------------------------------------
	ptrVariablesTraca->nFlagProduitTrace = 1;



	if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_Test_tampon,0))
	{


		errChk (SCPROD_StartSnCIE(    nItfe,
									  &gTcomBase,
									  "TAMPON_ATR",
									  "Default",
									  strMessageErreur ));

		errChk (SCPROD_CompleteSnPFIN(    nItfe,
										  &gTcomBase,
										  "TAMPON_ATR",
										  "Default",
										  strMessageErreur ));
	}

#endif

Error:
	if(error)
	{
		sprintf (strMessage, GET_MESSAGE(FCT_MSG_TRACABDD_STRING), strMessageErreur);
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "Erreur Traca", strMessage);
		return -1;
	}

	return 0;
}



// ==============================================================================
// FONCTION : 	  FCT_TracaBddKo
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int FCT_TracaBddKo (int nItfe)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - int nItfe	: Index du SLOT.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Fonction d'enregistrement en base du passage du décodeur sur
//				  le banc Perso pour un test KO.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  30/11/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_TracaBddKo(int nItfe)
{
	int                 error = 0;
	char                strMessageErreur[1024] = {'\0'};
	char                chMsg[1024] = {'\0'};
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	T_VARIABLES         *ptrVariablesEtat = &(gSlot[nItfe].variablesEtat);
	T_MESURES           *ptrMesures = &(gSlot[nItfe].mesures);
	//T_POSTE_PRODUIT     *ptrProduit = &gPosteProduits.produits[gSlot[nItfe].variablesTraca.idxProduit];

#ifndef NO_KEYS

	// ================================
	// = Enregistrement de passage KO =
	// ================================
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(FCT_MSG_PASS_KO_BDD_SNCIE), ptrVariablesTraca->CiuSfcSAPME);

	// ======================================================================================
	// = Enregistrement des mesures (anciennement mesure par mesure, maintenant par tableau =
	// ======================================================================================

	// errChk ( MES_Enregistrer (ptrMesures, nItfe, strMessageErreur ) );
	//errChk ( MES_EnregistrerTableau (ptrMesures, nItfe, strMessageErreur ) );

	// ========================
	// = Collecte des Données =
	// ========================
	// errChk ( VAR_Gestion (nItfe, &gTcomBase, ptrVariablesEtat, ptrVariablesTraca->PfinSfcSAPME, ptrVariablesTraca->PersoSAPMERessource, VAR_SAPME_COLLECT, strMessageErreur) );
	//errChk ( VAR_GestionTableau (nItfe, &gTcomBase, ptrVariablesEtat, ptrVariablesTraca->PfinSfcSAPME, ptrVariablesTraca->PersoSAPMERessource, SCPROD_STR_VIDE, VAR_SAPME_COLLECT, strMessageErreur) );

	// ================================================================================================
	// = Enregistrement de la non Conformité  (le complete (équivalent mouvement de test) est inclus) =
	// ================================================================================================
	//errChk ( SCPROD_LogNC (	nItfe, &gTcomBase, ptrVariablesTraca->PersoSAPMEOperation, ptrVariablesTraca->PersoSAPMERessource, strMessageErreur ));
	errChk ( SCPROD_LogNC (	nItfe, &gTcomBase,NOM_OPERATION,ptrVariablesTraca->NomRessourceSAPME, strMessageErreur ));


	// On mémorise que le produit a été tracé
	// -------------------------------------
	ptrVariablesTraca->nFlagProduitTrace = 1;

#endif

Error:
	if (error)
	{
		// En cas d'erreur sur le traitement de la traça KO, on retente un LOGNC avec message particulier
		// -----------------------------------------------------------------------------------------------
		sprintf (chMsg, GET_MESSAGE(FCT_MSG_TRACABDD_KO_STRING), strMessageErreur);
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Erreur Traca", chMsg);

		// On recopie le msg d'échec de la traca KO
		// ----------------------------------------
		strcpy(ptrVariablesTraca->chLibelleErreur,chMsg);
		SCPROD_LogNC (	nItfe, &gTcomBase, NOM_OPERATION, ptrVariablesTraca->NomRessourceSAPME, strMessageErreur );
		return -1;
	}
	return 0;
}

// ==============================================================================
// FONCTION : 	  FCT_AutorisationPassage
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int FCT_AutorisationPassage (int nItfe)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - int nItfe	: Index du SLOT.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Demande d'autorisation de passage à ce poste.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  23/11/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
FCT_AutorisationPassage (int nItfe, char *strErreurMessage )
{
	int		            error = 0;
	int					status = -1;
	int                 iExistenceSFC,iExistenceSFCFille;
	int					iFlagAssemblerSFCCiu=0;

	int					Index = -1;
	int		            iCompt = 0;
	char                chMessErreur[1024] = {'\0'};
	char    			chMessTemp[512] = {'\0'};
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	T_POSTE_PRODUIT     *ptrProduit = &(gPosteProduits.produits[gSlot[nItfe].variablesTraca.idxProduit]);
	T_VARIABLES         *ptrVariablesConf = &(gSlot[nItfe].variablesConf);
	//T_VARIABLES         *ptrVariablesEtat = &(gSlot[nItfe].variablesEtat);
	char    			*MessErreur = NULL;
	char    			chVariableCie[512] = {'\0'};
	char    			chVariableCieEnfant[512] = {'\0'};
	char    			sDFA[25] = {'\0'};
	static char inventoryId[255]="";
	int blnResultat=FALSE;
	static char *qtyOnHand;
	static char *originalQty;
	static char *itemRef;

	// INFO : 3 niveaux pour les messages dans cette fonction :
	// 1. chMessTemp pour l'affichage dans les logs + fenêtre de test
	// 2. chMessErreur Si non Vide : viendra être concaténé avec une message "Erreur" dans le log et "Retour autorisation de pass" dans la fenêtre
	// 3. strErreurMessage qui sera affichée dans le log et remontée en tracà. Message d'erreur par défaut si Vide

	// ===============================================
	// = RAZ des paramètres de sortie de la fonction =
	// ===============================================
	strErreurMessage[0] = '\0';


	// =========================================
	// = Controle de la validité des variables =
	// =========================================
	//errChk(FCT_VerificationVariables (nItfe,chMessErreur));




	// Interdiction de passer une carte de référence BAV/BFE au BPO
	// -------------------------------------------------------------
	/*if ( VAR_GET_BOOL(ptrVariablesConfSn,VAR_ETAT_ID_REFERENCE,0) == TRUE )
	{
		FIL2LO_PrintEtape (nItfe, GET_MESSAGE(FCT_MSG_FIL2LO));
		errChk(-1);
	}   */






	if (!VAR_GET_BOOL(ptrVariablesConf, VAR_CONF_GTW_BWC_FLAG_sfc, 0) == 1)
	{


		// Affichage du Numsérie CIE lu au démarrage
		// ------------------------------------------
		sprintf (chMessTemp, GET_MESSAGE(FCT_MSG_SN_CIE_STRING), ptrVariablesTraca->CieSn);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMessTemp );



		// ===================================================
		// = Récupération SnCIU sur SAP ME à partir du SNCIE =
		// ===================================================
		errChk(SCPROD_RecuperationSFCDepuisComposant ( nItfe,
				&gTcomBase,
				ptrVariablesTraca->CieSn,
				ptrVariablesTraca->CiuSfcSAPME,
				&iExistenceSFC,
				strErreurMessage ));




		// ============================================================
		// = Si le SNCIE n'admet aucun parent ou n'existe pas dans ME =
		// ============================================================
		if ( iExistenceSFC != 1)
		{
			sprintf (chMessTemp, GET_MESSAGE(FCT_LIBELLE_ERREUR_SFC_PARENT), ptrVariablesTraca->CieSn);
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMessTemp );

			sprintf (chMessTemp, "Retour DLL: %s", strErreurMessage);
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMessTemp );

			strErreurMessage[0] = '\0';    // Pour prendre le message d'erreur par défaut de la fonction

			errChk (-1);
		}

		// Affichage du Numsérie
		// ---------------------
		sprintf (chMessTemp, "SFC Trouvé pour ce SnCIE : %s", ptrVariablesTraca->CiuSfcSAPME);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMessTemp );


	}
	else
	{
		iExistenceSFC = 1;
	}

	// ======================================
	// = Récupération Infos SFC + Contrôles =
	// ======================================
	// Desactivé le 27/05/2016 demande ME & UF
	//errChk( FCT_VerificationSFC_MultiOF_CMS (nItfe,ptrVariablesTraca->CiuSfcSAPME, ptrProduit->cie.chVersion,ptrProduit->cie.chIndice, strErreurMessage));


	// Affichage du Numsérie
	// ---------------------
	//sprintf (chMessTemp, "SFC CIU associé aux Codes Produits : %s/%s et OF : %s - OK",  ptrProduit->cie.chVersion,ptrProduit->cie.chIndice, ptrVariablesTraca->chOrdreFabCMS);
	//FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMessTemp );



	// ======================================================
	// = Récupération SFC/PFIN sur SAP ME à partir du SnCIU =
	// ======================================================
	/*errChk ( SCPROD_RecuperationSFCDepuisComposant ( nItfe,
			 &gTcomBase,
			 ptrVariablesTraca->CiuSfcSAPME,
			 ptrVariablesTraca->PfinSfcSAPME,
			 &iExistenceSFC,
			 strErreurMessage ));
	*/


	// ==========================================================================
	// = Gestion du START : Si SnSFIN trouvé : Simple Start sur l'opération BPO =
	// ==========================================================================
	if ( iExistenceSFC == 1)
	{
		errChk (SCPROD_StartSnCIE(	nItfe,
									&gTcomBase,
									NOM_OPERATION,
									ptrVariablesTraca->NomRessourceSAPME,
									strErreurMessage ));



		// ========================================================================================
		// = Si le Start est ok sur Opération BPO, on bascule la variable de traca correspondante =
		// ========================================================================================
		ptrVariablesTraca->iStartOK = 1;
	}


	// =======================================================================
	// = Sinon, cas d'erreur (par exemple le SFC CIU n'a pas été "effectué") =
	// =======================================================================
	else
	{
		sprintf (chMessTemp, GET_MESSAGE(FCT_LIBELLE_ERREUR_RECUPERATION_SFC_PARENT), ptrVariablesTraca->CiuSfcSAPME);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMessTemp );
		errChk ( -1 );
	}

	// Affichage du Numsérie	  ==> On indique si généré ou si déjà existant
	// -----------------------------------------------------------------------
	sprintf (chMessTemp, "SFC PFIN : %s", ptrVariablesTraca->PfinSfcSAPME);
	if  (iFlagAssemblerSFCCiu == 1)
		strcat(chMessTemp," - Généré par StartByItem ou par Libération de Pfin");
	else
		strcat(chMessTemp," - Déjà Existant");
	FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMessTemp );




	// ========================================================
	// = Contrôles sur les codes produits SFC CIU et SFC PFIN =
	// ========================================================

	// On recopie l'OF dans la traça du SFC
	// ------------------------------------

	//strcpy(ptrVariablesTraca->chOrdreFabINTEG,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_REF_OF_INTEG,0));

	// Update le 27/05/2016 UF & me
	/* 12022019
	strcpy(ptrVariablesTraca->chOrdreFabINTEG,"");

	// On effectue le contrôle
	// -----------------------
	status = FCT_VerificationSFC (nItfe,ptrVariablesTraca->PfinSfcSAPME, ptrProduit->pfin.chVersion,ptrProduit->pfin.chIndice, ptrVariablesTraca->chOrdreFabINTEG,ptrVariablesTraca->chOrdreFabINTEG, strErreurMessage);

	// Si le contrôle échoue
	// ---------------------
	if (status < 0)
	{
		// Si le PFin vient juste d'être généré par StartByItem, on va essayer de Faire un Signoff dessus pour le remettre en stock
		// -----------------------------------------------------------------------------------------------------------------------
		if  (iFlagAssemblerSFCCiu == 1)
		{
			status  = SCPROD_SignoffSnPFIN (nItfe, &gTcomBase, SCPROD_OPERATION_DEFAUT, SCPROD_RESSOURCE_DEFAUT, chMessTemp );

			// Si le retour du SignOff est mauvais on loggue dans le bon buffer d'erreur pour remonter cette erreur en traça.
			// -------------------------------------------------------------------------------------------------------------
			if (status < 0)
			{
				strcpy (strErreurMessage, chMessTemp);

				// On affiche en plus un msg dans le log
				// -------------------------------------
				sprintf (chMessTemp, "SignOff Impossible sur SFC : %s - %s",  ptrVariablesTraca->PfinSfcSAPME, strErreurMessage);
				FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMessTemp );

			}
		}

		// On sort en erreur
		// -----------------
		errChk ( -1 );
	}

	// Affichage du Numsérie
	// ---------------------
	sprintf (chMessTemp, "SFC PFIN associé aux Codes Produits : %s/%s et OF : %s - OK",  ptrProduit->pfin.chVersion,ptrProduit->pfin.chIndice, ptrVariablesTraca->chOrdreFabINTEG);
	FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMessTemp );


	// ==================================================================================================
	// = Assemblage du SFC/CIU sur le SFC/PFIN seulement si on a généré un SnPFIN (sinon déjà assemblé) =
	// ==================================================================================================
	if (iFlagAssemblerSFCCiu == 1)
	{
		// On loggue l'info d'assemblage
		// -----------------------------
		sprintf (chMessTemp, "Assemblage du SFC CIU : %s sur le SFC PFIN : %s",ptrVariablesTraca->CiuSfcSAPME,ptrVariablesTraca->PfinSfcSAPME );
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMessTemp);


		// On assemble ici avec la ressource par défaut
		// --------------------------------------------
		errChk ( SCPROD_AssemblageComposant ( 	nItfe,
												&gTcomBase,
												ptrVariablesTraca->CiuSfcSAPME,
												NULL,
												ptrVariablesTraca->PfinSfcSAPME,
												SCPROD_ASSEMBLAGE_SFC,
												SCPROD_OPERATION_DEFAUT,
												SCPROD_RESSOURCE_DEFAUT,
												strErreurMessage ));

		// On fait un complete sur l'opération d'entrée du StartByItem (par défaut)
		// -----------------------------------------------------------
		errChk (SCPROD_CompleteSnPFIN(	nItfe,
									&gTcomBase,
									SCPROD_OPERATION_DEFAUT,
									SCPROD_RESSOURCE_DEFAUT,
									strErreurMessage ));


		// On fait un nouveau start sur l'opération du BPO
		// -----------------------------------------------
		errChk (SCPROD_StartSnPFIN(	nItfe,
									&gTcomBase,
									ptrVariablesTraca->PersoSAPMEOperation,
									ptrVariablesTraca->PersoSAPMERessource,
									strErreurMessage ));

		// ========================================================================================
		// = Si le Start est ok sur Opération BPO, on bascule la variable de traca correspondante =
		// ========================================================================================
		ptrVariablesTraca->iStartOK = 1;

	}

	else
	{
		// On loggue l'info déjà assemblé
		// -----------------------------
		sprintf (chMessTemp, "Le SFC CIU : %s est déjà assemblé sur le SFC PFIN : %s",ptrVariablesTraca->CiuSfcSAPME,ptrVariablesTraca->PfinSfcSAPME );
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, chMessTemp);
	}

	*/
	// ============================================================================================================
	// = Extraction des variables de configuration liées au numéro de série DFAB du STB [Specifique POUR SAP ME]  =
	// ============================================================================================================
	/*
	if ( VAR_Get_Proprietes_SFC_SAPME (nItfe, &gTcomBase, gVariablesProprietesSFCCie, gNbVariablesProprietesSFCCie, ptrVariablesPropCIU,  ptrVariablesTraca->CiuSfcSAPME, strErreurMessage) )
	{
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(IHM_STR_ERREUR), strErreurMessage);
		errChk(-1);
	}

	if ( VAR_Get_Proprietes_SFC_SAPME (nItfe, &gTcomBase, gVariablesProprietesSFCPfin, gNbVariablesProprietesSFCPfin, ptrVariablesPropPFIN, ptrVariablesTraca->PfinSfcSAPME, strErreurMessage) )
	{
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(IHM_STR_ERREUR), strErreurMessage);
		errChk(-1);
	}
	   */

	// =========================================
	// = On incrémente le Compteur de Passages =
	// =========================================
	FCT_VerificationSFC (nItfe,ptrVariablesTraca->CiuSfcSAPME, ptrProduit->cie.chVersion,ptrProduit->cie.chIndice, ptrVariablesTraca->chOrdreFabINTEG,ptrVariablesTraca->chOrdreFabINTEG, strErreurMessage);
	strcpy(strErreurMessage,"");
	gSlot[nItfe].nCompteurPassages++;


Error:

	if (error)
	{
		if ( strlen(chMessErreur) )
		{
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(FCT_MSG_TEST_AUTORISATION), chMessErreur);
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "Erreur traca", chMessErreur);
		}
		if ( strErreurMessage[0] == '\0')
			sprintf (strErreurMessage, GET_MESSAGE(FCT_MSG_PASSAGE_NON_AUTORISE));
		return -1;
	}

	return 0;


}

// ==============================================================================
// FONCTION : 	  FCT_PropietesEtatInit
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int FCT_PropietesEtatInit (int nItfe)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - int nItfe	: Index du SLOT.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Initialisation des propriétés état avant enregistrement en base.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  23/11/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_PropietesEtatInit ( int nItfe )
{
	T_VARIABLES			*ptrVariablesEtat = &(gSlot[nItfe].variablesEtat);
//	T_VARIABLES_TRACA	*ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);

	// MAJ du numéro de l'usine
	// ------------------------
	if (VAR_DEFINED (ptrVariablesEtat, VAR_ETAT_ID_NUM_CENTRE) == TRUE)
		VAR_SET_UINT32 (ptrVariablesEtat, VAR_ETAT_ID_NUM_CENTRE, 0) = gPosteInfos.numCentre;

	// Size HDD ==> Taille du Disque Dur
	// ---------------------------------
//	if (VAR_DEFINED (ptrVariablesEtat, VAR_ETAT_ID_HDD_SIZE) == TRUE)
//		if (VAR_SET_UINT32 (ptrVariablesEtat, VAR_ETAT_ID_HDD_SIZE, 0) == 0)
//			VAR_SET_UINT32 (ptrVariablesEtat, VAR_ETAT_ID_HDD_SIZE, 0) = 160;

	// Model HDD ==> Modèle du Disque Dur
	// Firmware HDD ==> Firmware du Disque Dur
	// Ceux lus dans via le TT
	// ----------------------------------

	return 0;
}

// ------------------------------------------------------------------------------
// FONCTIONS D'INTERFACE AVEC L'IHM
// ------------------------------------------------------------------------------

// ==============================================================================
// FONCTION : 	  FCT_AfficheInfo
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  void FCT_AfficheInfo (char nItfe,int mode, int codeErr, ...)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - int nItfe	: Index du SLOT,
//				  - int codeErr	: Code erreur à afficher,
//				  - ...			: Message à afficher.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Affichage d'information opérateur.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  01/12/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
void FCT_AfficheInfo (int nItfe,int mode, int codeErr, ...)
{
	int		nb;
	char	buffer[FCT_PRINT_TAILLE_MAX] = {'\0'};
	int		nbLigneTrace;
	va_list list;


	// Récupération du message d'erreur complet
	// ----------------------------------------
	va_start (list, codeErr);

	// Gestion des messages d'erreurs
	// ------------------------------
	switch (codeErr)
	{
		case ERROR_ALLOC_RESOURCE :
			strcpy (buffer, "Allocation des ressources systèmes impossibles");
			break;
		case OTHER_INSTANCE :
			strcpy (buffer, "Cette application est déjà ouverte");
			break;
		case LIB_NOT_FREE :
			strcpy (buffer, "Valeur de sortie sélectionnée en doublon dans le fichier INI");
			break;
		case BAD_LOG_SQL :
			strcpy (buffer, "Erreur de connexion à la base SQL");
			break;
		case MESS_VERIF_CODE__1 :
			vsprintf (buffer, "\nCarte OK, mais ne vient ni du poste précédent, ni du DEPANNAGE\n ***** Renvoyer au poste %s *****", list);
			break;
		case MESS_VERIF_CODE__2 :
			vsprintf (buffer, "\nCarte en Panne sur un autre type de poste\n ***** Renvoyer au poste %s *****", list);
			break;
		case MESS_VERIF_CODE__3 :
			vsprintf (buffer, "\nCarte en Panne ET le délai de repassage expiré\n ***** Renvoyer au poste %s *****", list);
			break;
		case MESS_VERIF_CODE__4 :
			strcpy (buffer, "\nLe code erreur est positif\n --->>> Contacter la maintenance");
			break;
		case TESTEUR_NON_TROUVE :
			vsprintf (buffer, "Testeur %s non trouvé dans la base de donnée", list);
			break;
		default :
			vsprintf (buffer, va_arg (list, char*), list);
			break;
	}

	// ====================================
	// = Affichage suivant le mode défini =
	// ====================================

	// Affichage d'une message d'information
	// -------------------------------------
	if ( (mode & IHM_MODE_POPUP_INFO) == IHM_MODE_POPUP_INFO )
	{
		IHM_ShowPopup (&gSlot[nItfe].ihmSlot, IHM_POPUP_TYPE_INFO, "INFORMATION", buffer);
	}

	// Affichage d'une message d'erreur
	// --------------------------------
	if ( (mode & IHM_MODE_POPUP_ERREUR) == IHM_MODE_POPUP_ERREUR )
	{
		IHM_ShowPopup ( &gSlot[nItfe].ihmSlot , IHM_POPUP_TYPE_ERREUR, "ERREUR", buffer );
	}

	// Affichage d'une trace sur IHM
	// -----------------------------
	if ( (mode & IHM_MODE_TRACE_TXTBOX) == IHM_MODE_TRACE_TXTBOX )
	{
		InsertTextBoxLine (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TRACE, -1, buffer);
		GetNumTextBoxLines (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TRACE, &nb);
		GetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TRACE, ATTR_VISIBLE_LINES, &nbLigneTrace);
		if (nb > nbLigneTrace)
			SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_TRACE, ATTR_FIRST_VISIBLE_LINE, nb-nbLigneTrace);
	}

	// Affichage d'une trace dans fichier LOG
	// --------------------------------------
	if ( (mode & IHM_MODE_TRACE_LOG) == IHM_MODE_TRACE_LOG )
	{
		FIL2LO_EcritTrace (TRUE, nItfe, buffer);
	}

	ProcessDrawEvents ();

	return;
}

// ==============================================================================
// FONCTION : 	  FCT_GetVersionInfo
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  void FCT_GetVersionInfo (char *filePath, char *strVersion)
// ------------------------------------------------------------------------------
// ARGUMENTS :
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Entrée : Nom fichier exe, maj Version.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  01/12/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
void FCT_GetVersionInfo (char *filePath, char *strVersion)
{
	void				*versionInfo = NULL;
	UINT				len;
	VS_FIXEDFILEINFO	*fixedVerInfoPtr;
	DWORD				infoSize, uselessParm;

	if ((infoSize = GetFileVersionInfoSize (filePath, &uselessParm)) == 0)
		goto Done;
	if ((versionInfo = malloc (infoSize)) == NULL)
		goto Done;
	if (GetFileVersionInfo (filePath, 0, infoSize, versionInfo) == 0)
		goto Done;
	if (!VerQueryValue (versionInfo, TEXT("\\"), (LPVOID*)&fixedVerInfoPtr, &len))
		goto Done;

	// Prend version produit
	sprintf ( strVersion, "V %d.%d.%d.%d",	(fixedVerInfoPtr->dwProductVersionMS & 0xffff0000) >> 16,
			  (fixedVerInfoPtr->dwProductVersionMS & 0xffff),
			  (fixedVerInfoPtr->dwProductVersionLS & 0xffff0000) >> 16,
			  (fixedVerInfoPtr->dwProductVersionLS & 0xffff));

Done:
	if (versionInfo)
		free (versionInfo);
}

// ==============================================================================
// FONCTION : 	  FCT_GetIdPoste
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  void FCT_GetIdPoste ( char *sIDPoste, int maxIdSize )
// ------------------------------------------------------------------------------
// ARGUMENTS :
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Donne l'identifiant d'un PC.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  01/12/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
void FCT_GetIdPoste ( char *sIDPoste, int maxIdSize )
{
	LPTSTR	lpszSystemInfo;		// pointer to system information string
	DWORD	cchBuff = 256;		// size of computer or user name
	TCHAR	tchBuffer[256+1];	// buffer for concatenated string

	if (maxIdSize)
	{
		lpszSystemInfo = tchBuffer ;
		GetComputerName (lpszSystemInfo, &cchBuff);	  // Id du Poste
		strncpy(sIDPoste,lpszSystemInfo,maxIdSize) ;
		sIDPoste[maxIdSize] = '\0' ;
	}
}

// ==============================================================================
// FONCTION : 	  FCT_AfficheVersionAppli
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  void FCT_AfficheVersionAppli(char *appName, int panelHnd)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - char *appName	: Nom de l'application à afficher,
//				  - int panelHnd	: Handle de la panel.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Affichage de la version et l'Identifiant du poste sur le panel.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  01/12/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
void FCT_AfficheVersionAppli(char *appName, int panelHnd)
{
	char strTitreAppli[100+1] ;											// titre de l'application

	sprintf (strTitreAppli, "%s %s %s", appName, gChNomPc, VERSION_SOFT);

	SetPanelAttribute (panelHnd, ATTR_TITLE, strTitreAppli);			// Affiche version ds titre
	return;
}

// ------------------------------------------------------------------------------
// FONCTIONS D'INTERFACE AVEC LE DECODEUR
// ------------------------------------------------------------------------------

// ==============================================================================
// FONCTION : 	  FCT_RecupCommandeTT
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int FCT_RecupCommandeTT(	int nItfe,
//				  						int idPort,
//				  						char *BufferAttendu,
//				  						char *chBufferLu,
//				  						unsigned long *taille_recu,
//				  						int TimeOut,
//				  						short *erreur,
//				  						long *codeErreur,
//				  						char *messagErreur	)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - int nItfe					: Index du SLOT.
//				  - int idPort					: Numéro du port COM.
//				  - char *BufferAttendu			: Tag à rechercher.
//				  - char *chBufferLu			: Buffer de réception.
//				  - unsigned long *taille_recu	: Taille du buffer de réception.
//				  - int TimeOut					: Time out de la réception.
//				  - short *erreur				: Flag erreur.
//				  - long *codeErreur			: Code de l'erreur.
//				  - char *messagErreur			: Message de l'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Lecture RS232 avec recherche de TAG et timeout.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  01/12/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_RecupCommandeTT(int nItfe, int idPort, char *BufferAttendu, char *chBufferLu, unsigned long *taille_recu, int TimeOut, short *erreur, long *codeErreur, char *messagErreur)
{
	int				status;
	double			time_out_debut;
	int				nbRetour;
	unsigned long	DimBuf;
	char			trace[9600] = {'\0'};


	// Effacer le buffer de reception
	// ------------------------------
	memset(chBufferLu, '\0', (sizeof(unsigned char) * TAILLE_MAX))  ;

	// Lancer le chrono ==> time OUT
	// -----------------------------
	time_out_debut = Timer();

	// Récupération de la réponse du décodeur
	// --------------------------------------
	while ( (status = FindPattern (chBufferLu, 0, -1, BufferAttendu, 0, 0) == -1) && ( (Timer()-time_out_debut)<TimeOut ) && (gNPAbort == FALSE) )
	{
		ProcessSystemEvents ();
		Sleep (100);

		memset(chBufferLu, '\0', (sizeof(unsigned char) * TAILLE_MAX));
		status = RS232_MEAS_LectureBuffer(idPort,
										  chBufferLu,
										  &nbRetour,
										  2048,
										  &DimBuf,
										  erreur,
										  codeErreur,
										  messagErreur);
		if(strlen(chBufferLu))
		{
			FIL2LO_PrintCom (nItfe, FIL2LO_COM_GTW_TX, trace);
		}

		ProcessSystemEvents ();

	}

	if( (Timer()-time_out_debut) >= TimeOut )
	{
		strcpy(messagErreur,"Time out");
		return -1;
	}

	return 0;
}

// ==============================================================================
// FONCTION : 	  FCT_RecupCommandeTT
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int FCT_EnvoiCommandeTT (	int nItfe,
//										int idPort,
//										char *BufferCommande,
//										int AffichageTrace,
//										short *erreur,
//										long *codeErreur,
//										char *messagErreur	)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - int nItfe				: Index du SLOT.
//				  - int idPort				: Numéro du port COM.
//				  - char *BufferCommande	: Commande à envoyer.
//				  - int AffichageTrace		: Flag indiquant si on trace la COM.
//				  - short *erreur			: Flag erreur.
//				  - long *codeErreur		: Code de l'erreur.
//				  - char *messagErreur		: Message de l'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Ecriture RS232.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  01/12/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_EnvoiCommandeTT (int nItfe, int idPort, char *BufferCommande, int AffichageTrace, short *erreur, long *codeErreur, char *messagErreur)
{
	unsigned char	Commande[TAILLE_MOY] = {"\0"};
	int				status;


	// RAZ
	RS232_MAIN_PurgeTxPort(idPort, erreur, codeErreur, messagErreur);
	if (*codeErreur < 0)
		return -1;
	RS232_MAIN_PurgeRxPort(idPort, erreur, codeErreur, messagErreur);
	if (*codeErreur < 0)
		return -1;

	ProcessSystemEvents ();

	Fmt (Commande, BufferCommande);

	if (AffichageTrace == AFFICHAGE_TRACE)
	{
		FIL2LO_PrintCom (nItfe, FIL2LO_COM_GTW_RX, Commande);
	}

	//Ecrire
	status = RS232_CONF_EcrirePort (idPort,
									Commande,
									strlen(Commande),
									erreur,
									codeErreur,
									messagErreur);

	return 0;
}

// ==============================================================================
// FONCTION : 	  FCT_EnvoiCommandeTTAvecVerifRetour
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int FCT_EnvoiCommandeTTAvecVerifRetour(	int nItfe,
//														int idPort,
//														char *BufferCommande,
//														char *BufferAttendu,
//														char *chBufferLu,
//														unsigned long *taille_recu,
//														int TimeOut,
//														int AffichageTrace,
//														short *erreur,
//														long *codeErreur,
//														char *messagErreur)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - int nItfe					: Index du SLOT.
//				  - int idPort					: Numéro du port COM.
//				  - char *BufferCommande		: Commande à envoyer.
//				  - char *BufferAttendu			: Tag à rechercher.
//				  - char *chBufferLu			: Buffer de réception.
//				  - unsigned long *taille_recu	: Taille du buffer de réception.
//				  - int TimeOut					: Time out de la réception.
//				  - int AffichageTrace			: Flag indiquant si on trace la COM.
//				  - short *erreur				: Flag erreur.
//				  - long *codeErreur			: Code de l'erreur.
//				  - char *messagErreur			: Message de l'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Ecriture et lecture RS232 avec recherche de TAG et timeout.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  01/12/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_EnvoiCommandeTTAvecVerifRetour(int nItfe, int idPort, char *BufferCommande, char *BufferAttendu, char *chBufferLu, unsigned long *taille_recu, int TimeOut, int AffichageTrace, short *erreur, long *codeErreur, char *messagErreur)
{
	int				status;
	int				flagTrouve;
	unsigned char	Commande[TAILLE_MOY] = {"\0"};
	double			time_out_debut;
	int				nbRetour;
	unsigned long	DimBuf;
	char			chBufferLuTmp[TAILLE_MAX]= {'\0'};


	// RAZ des buffer RX/TX de la COM
	RS232_MAIN_PurgeTxPort (idPort, erreur, codeErreur, messagErreur);
	if (*codeErreur < 0)
		return -1;
	RS232_MAIN_PurgeRxPort (idPort, erreur, codeErreur, messagErreur);
	if (*codeErreur < 0)
		return -1;

	// Effacer le buffer de reception
	memset (chBufferLu, '\0', (sizeof(unsigned char) * TAILLE_MAX));
	Fmt (Commande, BufferCommande);
	if (AffichageTrace == AFFICHAGE_TRACE)
	{
		FIL2LO_PrintCom (nItfe, FIL2LO_COM_GTW_RX, Commande);
	}

	// Ecrire vers COM
	status = RS232_CONF_EcrirePort (idPort,
									Commande,
									strlen(Commande),
									erreur,
									codeErreur,
									messagErreur);

	// lancer le chrono ==> time OUT
	time_out_debut = Timer ();

	flagTrouve = FALSE;

	// récupération de la réponse du décodeur
	memset (chBufferLu, '\0', (sizeof(unsigned char) * TAILLE_MAX));
	while ( (flagTrouve == FALSE) && ( (Timer()-time_out_debut) < TimeOut ) )// && (gNPAbort == FALSE) )
	{
		Sleep (200);

		memset (chBufferLuTmp, '\0', (sizeof(unsigned char) * TAILLE_MAX));
		status = RS232_MEAS_LectureBuffer(idPort,
										  chBufferLuTmp,
										  &nbRetour,
										  2048,
										  &DimBuf,
										  erreur,
										  codeErreur,
										  messagErreur);

		if ( strlen(chBufferLuTmp) )
		{
			if (AffichageTrace == AFFICHAGE_TRACE)
				FIL2LO_PrintCom (nItfe, FIL2LO_COM_GTW_TX, chBufferLuTmp);
			// On ajoute les données dans le buffer de retour
			strcat (chBufferLu, chBufferLuTmp);
		}

		// Recherche de la chaine souhaitée
		if (FindPattern (chBufferLu, 0, -1, BufferAttendu, 0, 0) > -1)
		{
			flagTrouve = TRUE;
		}
	}

	if ( (flagTrouve == FALSE) && (Timer()-time_out_debut) >= TimeOut )
	{
		strcpy (messagErreur, TIME_OUT_COMMUNICATION);
		return -1;
	}

	return 0;
}
// ==============================================================================
// FONCTION :     FCT_RecuperationVariableTraca
// ------------------------------------------------------------------------------
// PROTOTYPE :    int FCT_RecuperationVariableTraca (int nItfe)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe   : Index du SLOT.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Récuperer les informations extraites des traces de demarrage
//                du décodeur.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     V1.4.0
//  DATE :        30/11/2009
//  AUTEUR :      NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_RecuperationVariableTraca (int nItfe, char *strErreurMessage)
{
	int                 error = 0;
	char                chTrace[512]= {'\0'};
	char                *ptrStbTraceDemarrage = gSlot[nItfe].stbTraceDemarrage;
	T_VARIABLES         *ptrVariablesConf = &(gSlot[nItfe].variablesConf);
	T_VARIABLES         *ptrVariablesEtat = &(gSlot[nItfe].variablesEtat);
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	//  T_HDD_INFO          *ptrInfoHdd = &(gSlot[nItfe].infoHdd);
	char                SnBT1[50]= {"\0"};
	char                SnBT2[50]= {"\0"};
	char                SnClientBT[50]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	// Variables utilisées pour les TT avec 2 loaders
	// ---------------------------------------------
	int 				iLoader1 = -2;
	int 				iLoader2 = -2;
	int                 iExistenceSFC;
	char 				chGetLoader1[100] = {'\0'};
	char 				chGetLoader2[100] = {'\0'};

	// Initialisation des TAGS pour OS21
	// ---------------------------------
	char 				chTagCieIndice[30] = {"Indice:"};
	char 				chTagCieSn[30] = {"SN du CIE:"};
	char 				chTagCieCode[30] = {"Code produit:"};
	char 				chTagVersionTT[50] = {"TT:"};
	char 				chTagBoot[30] = {"Nomenclature Boot:"};
	char 				chTagLoader[30] = {"LD_VERSION = "};
	char 				chTagLoader1[30] = {"Loader Version : "};
	char 				chTagHardwareId[50] = {"HardwareId           : 0x"};
	char 				chTagUsageId[50] = {"UsageId              : 0x"};
	char 				chTagFirmwareVersion[50] = {"FW_VERSION = "};
	char 				chTagFirmwareVersion1[50] = {"FIRMWARE Version :"};
	char 				versionTT[50]= {'\0'} ;
	char 				Indice[50]= {'\0'} ;
	char 				SN_cie[50]= {'\0'} ;
	char 				cie_code[50]= {'\0'} ;
	char 				chversionTT[50]= {'\0'} ;
	char				chipsetid[50]= {'\0'} ;

	// Initialisation des TAGS communs
	// -------------------------------
	char				chTagNomenclatureHw[50] = {"Nomenclature Hw:"};
	char				chTagFullSalesTypes[50] = {"Full Sales Type:"};
	char				chTagPicVersion[50] = {"PIC Version : "};
	char				chTagRf4ceFirmware[50] = {"RF4CE Firmware Version : "};
	char				chTagChipsetIdentifier[50] = {"PHYS_ADDR:df8f0028 = "};
	char				chTagChipsetCutVersion[50] = {"CUT = "};
	char				chTagAppliNom[50] = {"Application Name:"};
	char				chTagAppliVersion[50] = {"Application Version:"};
	char                SnSFIN[50]= "";
	char 				chTagCustomerSn[30] = {"CUSTOMER_SN ="};
	int             status;
	char            chBuffLu[0x18000] = {"\0"};

	// Initialisation du message d'erreur
	// ----------------------------------
	strErreurMessage[0] = '\0';
	strcpy(SnClientBT ,"");
	strcpy(SnBT1 ,"");
	strcpy(SnBT2 ,"");

	// Tag spécial LINUX
	// -----------------

	sprintf( chTagCieIndice, "%s", "CIE_INDICE =");
	sprintf( chTagCieSn, "%s", "CIE_SN =");
	sprintf( chTagCieCode, "%s", "CIE_CODE =");
	sprintf( chTagVersionTT, "%s", "SagemTest Version : ");
	sprintf( chTagBoot, "%s", "BOOT Version :");
	sprintf( chTagLoader1, "%s", "Loader Version : ");
	sprintf( chTagLoader, "%s", "LD_VERSION = ");
	sprintf( chTagHardwareId, "%s", "HARDWARE_ID =");
	sprintf( chTagUsageId, "%s", "USAGE_ID =");
	sprintf( chTagFirmwareVersion1, "%s", "FIRMWARE Version :");
	sprintf( chTagFirmwareVersion, "%s", "FW_VERSION = ");
	sprintf( chTagCustomerSn, "%s", "CUSTOMER_SN =");

	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"===================Recuperation SN ========================") ;
	status = FCT_CmdComExecutionV3 (nItfe, AFFICHAGE_TRACE, VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_RECUP_SN,0), NULL, NULL, chBuffLu, 10);

	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"========================> SN ") ;
	// Core Board Indice ==> Indice
	// ----------------------------
	if (FCT_RechercheTag(chBuffLu, chTagCieIndice, ptrVariablesTraca->CieIndice)!= 1)
	{
		sprintf (strErreurMessage, GET_MESSAGE(FCT_MSG_CIE_INDICE_NON_REMONTE));
		errChk (-1);
	}
	sprintf (Indice , "CIE_INDICE : %s ",ptrVariablesTraca->CieIndice );
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,Indice );

	// Core Board Cie ==> Code produit
	// -------------------------------
	if (FCT_RechercheTag (chBuffLu, chTagCieCode, ptrVariablesTraca->CieVersion)!= 1)
	{
		sprintf (strErreurMessage, GET_MESSAGE(FCT_MSG_CIE_CODE_PRODUIT_NON_REMONTE));
		errChk (-1);
	}
	FCT_SupprimerTag ( ptrVariablesTraca->CieVersion, "-" );
	sprintf (cie_code , "CIE_CODE: %s ",ptrVariablesTraca->CieVersion );
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,cie_code );



	// Core Board SN ==> SN du CIE (DFAB)
	// ----------------------------------
	if(FCT_RechercheTag(chBuffLu, chTagCieSn, ptrVariablesTraca->CieSn)!= 1)
	{
		sprintf (strErreurMessage, GET_MESSAGE(FCT_MSG_CIE_SN_NON_REMONTE));
		errChk (-1);
	}
	sprintf (SN_cie , "CIE_SN  : %s ",ptrVariablesTraca->CieSn );
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,SN_cie );

	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"=================== Recuperation version TT ====================" );
	status = FCT_CmdComExecutionV3 (nItfe, AFFICHAGE_TRACE, VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_RECUP_TT,0), NULL, NULL, chBuffLu, 10);
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"========================> Version TT " ) ;
	// version TT
	// ----------------------------
	if (FCT_RechercheTag(chBuffLu, chTagVersionTT, versionTT)!= 1)
	{
		sprintf (strErreurMessage, GET_MESSAGE(FCT_MSG_CIE_INDICE_NON_REMONTE));
		errChk (-1);
	}
	sprintf (chversionTT , "Version TT : %s ",versionTT );
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,chversionTT );



	if((VAR_DEFINED(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_ChipID) == TRUE))
	{
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"================== Recuperation Chipset ID ==================" );
		status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_ChipID,0), &infos,&nbInfos ,NULL, 5);
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"==================>Chipset ID " );

		strncpy(ptrVariablesTraca->chChipsetSnHex,infos[0],26);

		sprintf (chipsetid , "Chipset ID : %s",ptrVariablesTraca->chChipsetSnHex );
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,chipsetid );

	}
	// HardwareId           : 0x3239			=> conf_DEC_BPO_sHardwareId
	// --------------------------------------------------------------------
	/* if ( FindPattern (ptrStbTraceDemarrage, 0, -1, chTagHardwareId, 0, 1) != -1 )
		if ( VAR_DEFINED(ptrVariablesConf,VAR_CONF_ID_HARDWARE_ID) == TRUE && VAR_DEFINED(ptrVariablesEtat,VAR_ETAT_ID_HARDWARE_ID) )
			if (FCT_RechercheTag (ptrStbTraceDemarrage, chTagHardwareId, VAR_SET_STRING(ptrVariablesEtat,VAR_ETAT_ID_HARDWARE_ID,0) ) == 0)
			{
				if ( strcmp ( VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_HARDWARE_ID,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_HARDWARE_ID,0) ) != 0)
				{
					sprintf (strErreurMessage, "HarwareId remonté par le TT:%s différent du HardwareId attendu:%s", VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_HARDWARE_ID,0), VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_HARDWARE_ID,0) );
					errChk (-1);
				}
			}
			else
				errChk (-1);
	*/



Error:
	// Gestion des erreurs
	// -------------------
	if (error)
	{
		if ( strErreurMessage[0] == '\0' )
			sprintf (strErreurMessage, GET_MESSAGE(FCT_MSG_ERR_RECUP_VAR_TRACA));
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(IHM_STR_ERREUR), GET_MESSAGE(FCT_MSG_ERR_RECUP_VAR_TRACA));
		return -1;
	}

	return 0;
}

// ------------------------------------------------------------------------------
// FONCTIONS DIVERS
// ------------------------------------------------------------------------------

// ==============================================================================
// FONCTION : 	  FCT_RechercheTag
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int FCT_RechercheTag (	char *chBuffer,
//											char *chTag,
//											char *chRetour	)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - char *chBuffer	: Buffer de recherche,
//				  - char *chTag		: Tag à rechercher,
//				  - char *chRetour	: Valeur trouvée
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Recherche un libellé et en récuperer la valeur (sous forme
//				  de chaine).
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  01/12/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
/*int FCT_RechercheTag (char *chBuffer, char *chTag, char *chRetour)
{
	int indicestart = 0;
	int indiceend = 0;
	int nStatusTrouve = -1;

	// Recherche du TAG dans le buffer
	nStatusTrouve = FindPattern (chBuffer, 0, -1, chTag, 0, 0);
	if (nStatusTrouve >= 0)
	{
		indicestart = nStatusTrouve + strlen(chTag);
		indiceend = FindPattern (chBuffer, indicestart, -1, "\r", 0, 0);
		if( ((indicestart >= 0) && (indiceend >= 0)) && (indiceend > indicestart) )
		{
			CopyString (chRetour, 0, chBuffer, indicestart, indiceend - indicestart);
		}
		else
			return 0;
	}
	else
		return 0;

	// Suppression des espaces, tabulations et retour charriot en début et fin de la valeur extraite
	RemoveSurroundingWhiteSpace (chRetour);
	if (strlen(chRetour) > 0)
	{
		if ( chRetour[strlen(chRetour)-1] < '\n' )
		{
			chRetour[strlen(chRetour)-1] = '\0';
			RemoveSurroundingWhiteSpace (chRetour);
		}
	}
	return 1;
}*/
int FCT_RechercheTag (char *chBuffer, char *chTag, char *chRetour)
{
	int indicestart = 0;
	int indiceend = 0;
	int nStatusTrouve = -1;

	// Recherche du TAG dans le buffer
	nStatusTrouve = FindPattern (chBuffer, 0, -1, chTag, 0, 0);
	if (nStatusTrouve >= 0)
	{
		indicestart = nStatusTrouve + strlen(chTag);
		indiceend = FindPattern (chBuffer, indicestart, -1, "\r", 0, 0);
		if( ((indicestart >= 0) && (indiceend >= 0)) && (indiceend > indicestart) )
		{
			CopyString (chRetour, 0, chBuffer, indicestart, indiceend - indicestart);
		}
		else
			return 0;
	}
	else
		return 0;

	// Suppression des espaces, tabulations et retour charriot en début et fin de la valeur extraite
	RemoveSurroundingWhiteSpace (chRetour);
	if (strlen(chRetour) > 0)
	{
		if ( chRetour[strlen(chRetour)-1] < '\n' )
		{
			chRetour[strlen(chRetour)-1] = '\0';
			RemoveSurroundingWhiteSpace (chRetour);
		}
	}
	return 1;
}

// ==============================================================================
// FONCTION : 	  FCT_MasqueValidation
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int FCT_MasqueValidation ( char *chMasque, char *chValeur )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//  			  - char *chMasque	 : Masque de vérification,
//  			  - char *chValeur	 : Donnée à vérifier.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Comparaison masque/donnée.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  01/12/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_MasqueValidation ( char *chMasque, char *chValeur )
{
	int ii = 0;

	while ( (ii<strlen(chMasque)) && (ii<strlen(chValeur)) )
	{
		if( (chMasque[ii]!='#') && (chMasque[ii]!='0') && (chMasque[ii]!=chValeur[ii]) )
		{
			// au moins un des caractère ne convient pas au masque
			return -1;
		}
		ii++;
	}

	return 0;
}

// ==============================================================================
// FONCTION : 	  FCT_SupprimerTag
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  void FCT_SupprimerTag(char *chValeur, char *chTag)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//  			  - char *chValeur	 : Valeur de corriger,
//  			  - char *chTag		 : Tag à supprimer.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Suppression d'un caractère.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  01/12/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
void FCT_SupprimerTag ( char *chValeur, char *chTag )
{
	FCT_RemplacerTag ( chValeur, strlen (chValeur)+1, chTag, "" );
}

// ==============================================================================
// FONCTION : 	  FCT_RemplacerTag
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  void FCT_RemplacerTag (	char *chValeur,
//											char *chTagOld,
//											char *chTagNew )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//  			  - char *chValeur	: Valeur de corriger,
//  			  - char *chTagOld	: Tag à remplacer.
//  			  - char *chTagNew	: Tag de remplacement.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Remplacement d'un Tag dans une chaine.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  01/12/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
void FCT_RemplacerTag ( char *chValeur, int nTaille, char *chTagOld, char *chTagNew )
{
	char    *ptrTag;
	char    *ptrValeur = chValeur;
	char    chValeurTmp[FCT_PRINT_TAILLE_MAX] = {'\0'};
	int     lenTagOld = strlen (chTagOld);


	// ==========================================================================================
	// = Si la chaine en entrée est plus grande que le buffer de travail on sort de la fonction =
	// ==========================================================================================
	if ( strlen(chValeur) >= FCT_PRINT_TAILLE_MAX )
		return;

	// ====================================================================
	// = Tant que le Tag à remplacer est trouvé dans la chaine on continu =
	// ====================================================================
	do
	{
		// Recherche du Tag
		// ----------------
		ptrTag = strstr ( ptrValeur, chTagOld );

		// Remplacement si Tag trouvé
		// --------------------------
		if( ptrTag != NULL )
		{
			strncat ( chValeurTmp, ptrValeur, (ptrTag - ptrValeur) );
			strcat (chValeurTmp, chTagNew );
			ptrValeur = ptrTag + lenTagOld;
		}

	}
	while( ptrTag != NULL );

	// ===================================================
	// = Si Tag trouvé on met à jour la chaine en sortie =
	// ===================================================
	if ( chValeur != ptrValeur )
	{
		strcat ( chValeurTmp, ptrValeur );
		if ( strlen (chValeurTmp) < nTaille )
			strcpy ( chValeur, chValeurTmp );
		else
		{
			strncpy (chValeur, chValeurTmp, nTaille-1);
			chValeur[nTaille-1] = '\0';
		}

	}
}

// ==============================================================================
// FONCTION : 	  FCT_ProduitPrint
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int FCT_ProduitPrint(	T_POSTE_PRODUIT *tPosteProduit,
//										char *strPrint,
//										char *strMessageErreur	)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_POSTE_PRODUIT *tPosteProduit	: Produit du poste,
//				  - char *strPrint					: Chaine formaté pour
//													  impression,
//				  - char *strErreurMessage			: Message de l'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Formatage pour affichage des infos produit.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  16/11/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_ProduitPrint( T_POSTE_PRODUIT *tPosteProduit, char *strPrint, char *strMessageErreur)
{
	char	chMess[512] = {'\0'};


	// ===============================================
	// = RAZ des paramètres de sortie de la fonction =
	// ===============================================
	strPrint[0] = '\0';
	strMessageErreur[0] = '\0';

	// ==================================
	// = Formatage des infos du produit =
	// ==================================
	sprintf (strPrint,  "<CIE>  Nom                                : %s\n", tPosteProduit->cie.chDesignation);
	sprintf (chMess,    "<CIE>  Référence                          : %s\n", tPosteProduit->cie.chVersion);
	strcat (strPrint, chMess);
	if (tPosteProduit->cie.chIndice[0] != '\0')
	{
		sprintf (chMess,    "<CIE>  Indice                             : %s\n", tPosteProduit->cie.chIndice);
		strcat (strPrint, chMess);
	}

	sprintf (chMess,    "<SFIN> Nom                                : %s\n", tPosteProduit->sfin.chDesignation);
	strcat (strPrint, chMess);
	sprintf (chMess,    "<SFIN> Référence                          : %s\n", tPosteProduit->sfin.chVersion);
	strcat (strPrint, chMess);
	if ( FCT_STRING_IS_EMPTY(tPosteProduit->sfin.chIndice) == FALSE )
	{
		sprintf (chMess,    "<SFIN> Indice                             : %s\n", tPosteProduit->sfin.chIndice);
		strcat (strPrint, chMess);
	}

	return 0;
}

// ------------------------------------------------------------------------------
// FONCTIONS DE GESTION DE LA STRUCTURE DE TRACA
// ------------------------------------------------------------------------------

// ==============================================================================
// FONCTION : 	  FCT_TracaInit
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int	FCT_TracaInit( T_VARIABLES_TRACA *tVariablesTraca )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_VARIABLES_TRACA *tVariablesTraca	: Variables de traça,
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Initialisation de la structure Traça.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  11/12/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int	FCT_TracaInit( T_VARIABLES_TRACA *tVariablesTraca )
{
	tVariablesTraca->idxProduit = 0;
	tVariablesTraca->idxProduitHdd = 0;
	tVariablesTraca->iStartOK = 0;
	strcpy ( tVariablesTraca->PfinSfcSAPME, "" );
	strcpy (tVariablesTraca->chChipsetSnDec, "");
	strcpy (tVariablesTraca->chChipsetSnHex, "");
	strcpy (tVariablesTraca->CieSn, "");
	strcpy (tVariablesTraca->CiuSfcSAPME, "");
	strcpy (tVariablesTraca->chOrdreFabCMS, "");
	strcpy (tVariablesTraca->chOrdreFabINTEG, "");
//	strcpy (tVariablesTraca->chTypeOrdreFabCMS, "");
//	strcpy (tVariablesTraca->chTypeOrdreFabINTEG, "");
	strcpy (tVariablesTraca->AddrCieSn, "");
	strcpy (tVariablesTraca->chLibelleErreur, "");
	tVariablesTraca->nFlagProduitTrace = 0;
	return 0;
}

// ==============================================================================
// FONCTION : 	  FCT_TracaRaz
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int	FCT_TracaRaz( T_VARIABLES_TRACA *tVariablesTraca )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_VARIABLES_TRACA *tVariablesTraca	: Variables de traça,
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Remise à zéro de la structure Traça.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  11/12/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int	FCT_TracaRaz( T_VARIABLES_TRACA *tVariablesTraca )
{
	tVariablesTraca->idxProduitHdd = 0;
	tVariablesTraca->iStartOK = 0;
	strcpy ( tVariablesTraca->PfinSfcSAPME, "" );
	strcpy (tVariablesTraca->chChipsetSnDec, "");
	strcpy (tVariablesTraca->chChipsetSnHex, "");
	strcpy (tVariablesTraca->CieSn, "");
	strcpy (tVariablesTraca->CiuSfcSAPME, "");
	strcpy (tVariablesTraca->chOrdreFabCMS, "");
	strcpy (tVariablesTraca->chOrdreFabINTEG, "");
//	strcpy (tVariablesTraca->chTypeOrdreFabCMS, "");
//	strcpy (tVariablesTraca->chTypeOrdreFabINTEG, "");
	strcpy (tVariablesTraca->AddrCieSn, "");
	strcpy (tVariablesTraca->chLibelleErreur, "");
	tVariablesTraca->nFlagProduitTrace = 0;

	return 0;
}

// ==============================================================================
// FONCTION : 	  FCT_TracaPrint
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int FCT_TracaPrint( 	T_VARIABLES_TRACA *tVariablesTraca,
//										char *strPrint,
//										char *strMessageErreur	)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - T_VARIABLES_TRACA *tVariablesTraca	: Variables de traça,
//				  - char *strPrint						: Chaine formaté pour
//														  impression,
//				  - char *strErreurMessage				: Message de l'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Formatage pour affichage des variables de traça.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.4.0
//  DATE :		  16/11/2009
//  AUTEUR :	  NCR (DT2E)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_TracaPrint( T_VARIABLES_TRACA *tVariablesTraca, char *strPrint, char *strMessageErreur)
{
	char	chValeur[TAILLE_MAX] = {'\0'};
	int		ii;


	// ===============================================
	// = RAZ des paramètres de sortie de la fonction =
	// ===============================================
	strPrint[0] = '\0';
	strMessageErreur[0] = '\0';

	// ==============================================
	// = Formatage de toutes les variables de traça =
	// ==============================================

	strcat (strPrint, chValeur);
	sprintf (chValeur, "Sn SFIN                                   : %s\n", tVariablesTraca->CiuSfcSAPME);
	strcat (strPrint, chValeur);
	sprintf (chValeur, "Sn CIE                                    : %s\n", tVariablesTraca->CieSn);
	strcat (strPrint, chValeur);
	if ( strlen (tVariablesTraca->chLibelleErreur) )
	{
		sprintf (chValeur, "Libelle erreur                            : %s\n", tVariablesTraca->chLibelleErreur);
		strcat (strPrint, chValeur);
	}
	if ( strlen (tVariablesTraca->chLibelleErreur) )
	{
		sprintf (chValeur, "Code erreur                               : %s\n", tVariablesTraca->chLibelleErreur);
		strcat (strPrint, chValeur);
	}
	/*if (tVariablesTraca->nbSnParents)
	{
		for ( ii=0 ; ii<tVariablesTraca->nbSnParents ; ii++ )
		{
			sprintf (chValeur, "Parent_%d Code produit                     : %s\n", ii, tVariablesTraca->tabSnParents[ii].chCodeProduit);
			strcat (strPrint, chValeur);
			sprintf (chValeur, "Parent_%d Indice produit                   : %s\n", ii, tVariablesTraca->tabSnParents[ii].chIndiceProduit);
			strcat (strPrint, chValeur);
			sprintf (chValeur, "Parent_%d SN                               : %s\n", ii, tVariablesTraca->tabSnParents[ii].chNumSerie);
			strcat (strPrint, chValeur);
			if (ii<tVariablesTraca->nbSnParents-1)
				strcat (strPrint, "\n");
		}
	}
	 */
	return 0;
}

// ==============================================================================
// FONCTION :     FCT_InfoMemoire
// ------------------------------------------------------------------------------
// PROTOTYPE :    int FCT_InfoMemoire (  )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe           : Index du SLOT en test (0 ou 1),
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Création d'une commande TT.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S08012CA40
//  DATE :        17/12/2010
//  AUTEUR :      GCX (APSIDE)
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
void FCT_InfoMemoire(int nItfe, char *step)
{
	int 	allocatedBlocks = 0;
	int 	allocatedBytes = 0;
	char 	strMessageInfo[100] = {"\0"};


	CVIDynamicMemoryInfo ("DynamicMemoryInfo", &allocatedBlocks, &allocatedBytes, DYNAMIC_MEMORY_SHOW_ALLOCATED_MEMORY_SUMMARY);
	sprintf (strMessageInfo, "%s %d\n", step, allocatedBytes);
	printf (strMessageInfo);
}

// ==============================================================================
// FONCTION :     FCT_ProduitsRaz
// ------------------------------------------------------------------------------
// PROTOTYPE :    int FCT_ProduitsRaz ( T_POSTE_PRODUITS *posteProduits )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - T_POSTE_PRODUITS *posteProduits : Tableau de produits,
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Suppression des produits.
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S08012CA38
//  DATE :        20/12/2010
//  AUTEUR :      MBH
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_ProduitsRaz ( T_POSTE_PRODUITS *posteProduits )
{
	int idxProduit;

	// ====================================
	// = Suppression des produits alloués =
	// ====================================
	for ( idxProduit=0 ; idxProduit<posteProduits->nbProduit ; idxProduit++ )
	{
		// ===========================
		// = Suppression des enfants =
		// ===========================

		// Libération mémoire seulement si allouée
		// ---------------------------------------
		if (posteProduits->produits[idxProduit].enfant != NULL)
		{
			// Libération de la mémoire allouée pour la variable
			// -------------------------------------------------
			free (posteProduits->produits[idxProduit].enfant);
			posteProduits->produits[idxProduit].enfant = NULL;
			posteProduits->produits[idxProduit].nbEnfant = 0;
		}


		// ===========================
		// = Suppression des parents =
		// ===========================

		// Libération mémoire seulement si allouée
		// ---------------------------------------
		if (posteProduits->produits[idxProduit].parent != NULL)
		{
			// Libération de la mémoire allouée pour la variable
			// -------------------------------------------------
			free (posteProduits->produits[idxProduit].parent);
			posteProduits->produits[idxProduit].parent = NULL;
			posteProduits->produits[idxProduit].nbParent = 0;
		}

	}

	/* Fait au BPO, dans le cas où le nombre de produit est dynamique
		// ==============================================
		// = Suppression du tableau de produits alloués =
		// ==============================================
		if (posteProduits->produits != NULL)
		{
			free (posteProduits->produits);
			posteProduits->produits = NULL;
			posteProduits->nbProduit = 0;
		}
	*/
	return 0;
}


// ==============================================================================
// FONCTION : 	  FCT_clean_atapi
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int FCT_clean_atapi(	int nItfe,
//										int AffichageTrace,
//										char *messagErreur)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - int nItfe					: Index du SLOT.
//				  - int AffichageTrace			: Flag indiquant si on trace la COM.
//				  - char *messagErreur			: Message de l'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 1  = toutes les sessions atapi sont fermées
//  			  - -1 = erreur
// ------------------------------------------------------------------------------
// DESRIPTION :   Ferme toutes les session ATAPI ouvertes
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.0.0
//  DATE :		  29/04/2011
//  AUTEUR :	  RMS
//  DESCRIPTION : Création.
// ==============================================================================
int FCT_clean_atapi(int nItfe, int AffichageTrace, char *messagErreur)
{
	int				status;
	int				flagTrouve;
	unsigned char	Commande[TAILLE_MOY] = {"\0"};
	double			time_out_debut;
	int				nbRetour;
	unsigned long	DimBuf;
	char			chBufferLuTmp[TAILLE_MAX]= {'\0'};
	int				idPort = gSlot[nItfe].comDecodeur.iHandle;
	int				TimeOut = 2;
	short 			erreur = 0;
	int				codeErreur = 0;
	int				compteur = 0;

	// RAZ des buffer RX/TX de la COM
	RS232_MAIN_PurgeTxPort (idPort, &erreur, &codeErreur, messagErreur);
	if (codeErreur < 0)
		return -1;
	RS232_MAIN_PurgeRxPort (idPort, &erreur, &codeErreur, messagErreur);
	if (codeErreur < 0)
		return -1;

	// Effacer le buffer
	memset (chBufferLuTmp, '\0', (sizeof(unsigned char) * TAILLE_MAX));

	Fmt (Commande, "ATAPI_CLOSE\r");
	if (AffichageTrace == AFFICHAGE_TRACE)
	{
		FIL2LO_PrintCom (nItfe, FIL2LO_COM_GTW_RX, Commande);
	}

	//valeur par défaut 99 = rien trouvé
	//valeur 0 = OK trouvé (il faut continuer)
	//valeur 1 = ERROR trouvé
	flagTrouve = 99;

	while ( (flagTrouve != 1) && strcmp(messagErreur,TIME_OUT_COMMUNICATION) && (gNPAbort == FALSE))
	{
		// Ecrire vers COM
		status = RS232_CONF_EcrirePort (idPort,
										Commande,
										strlen(Commande),
										&erreur,
										&codeErreur,
										messagErreur);

		// lancer le chrono ==> time OUT
		time_out_debut = Timer ();

		memset (chBufferLuTmp, '\0', (sizeof(unsigned char) * TAILLE_MAX));

		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, "..");

		// récupération de la réponse du décodeur
		Sleep (200);

		memset (chBufferLuTmp, '\0', (sizeof(unsigned char) * TAILLE_MAX));
		status = RS232_MEAS_LectureBuffer(idPort,
										  chBufferLuTmp,
										  &nbRetour,
										  2048,
										  &DimBuf,
										  &erreur,
										  &codeErreur,
										  messagErreur);

		if ( strlen(chBufferLuTmp) )
		{
			if (AffichageTrace == AFFICHAGE_TRACE)
				FIL2LO_PrintCom (nItfe, FIL2LO_COM_GTW_TX, chBufferLuTmp);

			// Recherche de la chaine OK
			if (FindPattern (chBufferLuTmp, 0, -1, "OK", 0, 0) > -1)
			{
				flagTrouve = 0;
			}
			// Recherche de la chaine ERROR
			if (FindPattern (chBufferLuTmp, 0, -1, "ERROR", 0, 0) > -1)
			{
				flagTrouve = 1;
			}
		}
		else
		{
			//pas de réponse du décodeur, on attend pour le laisser démarrer
			Sleep(3000);
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "##Pas de réponse du décodeur");
			//si troisième passage on sort en erreur
			compteur++;
			if (compteur >= 2) return -1;
		}



		if ( (flagTrouve == 99) && (Timer()-time_out_debut) >= TimeOut )
		{
			strcpy (messagErreur, TIME_OUT_COMMUNICATION);
			erreur = 1;
			return -1;
		}
	}

	return 1;
}
// ==============================================================================
// FONCTION : 	  FCT_ecoute_com
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int FCT_ecoute_com(	int nItfe,
//										int AffichageTrace,
//										char *messagErreur)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - int nItfe					: Index du SLOT.
//				  - int AffichageTrace			: Flag indiquant si on trace la COM.
//				  - char *messagErreur			: Message de l'erreur.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 1  = toutes les sessions atapi sont fermées
//  			  - -1 = erreur
// ------------------------------------------------------------------------------
// DESRIPTION :   Ferme toutes les session ATAPI ouvertes
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	  V1.0.0
//  DATE :		  29/04/2011
//  AUTEUR :	  RMS
//  DESCRIPTION : Création.
// ==============================================================================
int FCT_ecoute_com(int nItfe, int AffichageTrace, char *messagErreur)
{
	int				status;
	int				flagTrouve;
	unsigned char	Commande[TAILLE_MOY] = {"\0"};
	double			time_out_debut;
	int				nbRetour;
	unsigned long	DimBuf;
	char			chBufferLuTmp[TAILLE_MAX]= {'\0'};
	int				idPort = gSlot[nItfe].comDecodeur.iHandle;
	short 			erreur = 0;
	int				codeErreur = 0;
	int				compteur = 0;

	// RAZ des buffer RX/TX de la COM
	/*	RS232_MAIN_PurgeTxPort (idPort, &erreur, &codeErreur, messagErreur);
		if (codeErreur < 0)
			return -1;
		RS232_MAIN_PurgeRxPort (idPort, &erreur, &codeErreur, messagErreur);
		if (codeErreur < 0)
			return -1;
						 */
	// Effacer le buffer
	memset (chBufferLuTmp, '\0', (sizeof(unsigned char) * TAILLE_MAX));

	Fmt (Commande, "\r");
	if (AffichageTrace == AFFICHAGE_TRACE)
	{
		FIL2LO_PrintCom (nItfe, FIL2LO_COM_GTW_RX, Commande);
	}

	//valeur par défaut 99 = rien trouvé
	//valeur 0 = OK trouvé (il faut continuer)
	//valeur 1 = ERROR trouvé
	flagTrouve = 99;

	while ( (flagTrouve != 1) && strcmp(messagErreur,TIME_OUT_COMMUNICATION) && (gNPAbort == FALSE))
	{
		// Ecrire vers COM
		Sleep (200);
		time_out_debut = Timer ();

		memset (chBufferLuTmp, '\0', (sizeof(unsigned char) * TAILLE_MAX));
		status = RS232_MEAS_LectureBuffer(idPort,
										  chBufferLuTmp,
										  &nbRetour,
										  2048,
										  &DimBuf,
										  &erreur,
										  &codeErreur,
										  messagErreur);

		if ( strlen(chBufferLuTmp) )
		{
			if (AffichageTrace == AFFICHAGE_TRACE)
				FIL2LO_PrintCom (nItfe, FIL2LO_COM_GTW_TX, chBufferLuTmp);

			// Recherche de la chaine OK
			if (FindPattern (chBufferLuTmp, 0, -1, "SN =", 0, 0) > -1)
			{
				flagTrouve = 0;
			}
			// Recherche de la chaine ERROR
			if (FindPattern (chBufferLuTmp, 0, -1, "ERROR", 0, 0) > -1)
			{
				flagTrouve = 1;
			}
		}
		else
		{
			//pas de réponse du décodeur, on attend pour le laisser démarrer
			Sleep(3000);
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "##Pas de réponse du décodeur");
			//si troisième passage on sort en erreur
			compteur++;
			if (compteur >= 2) return -1;
		}



		/*if ( (flagTrouve == 99) && (Timer()-time_out_debut) >= TimeOut )
		{
			strcpy (messagErreur, TIME_OUT_COMMUNICATION);
			erreur = 1;
			return -1;
		} */
	}

	return 1;
}

//==========================================
/*
void FCT_Affiche_trace(int numSlot)
{

char bufferRS232[TAILLE_MAX_CHAINE]={'\0'};
	unsigned long lngMsg = 0;

	   ProcessSystemEvents();
	memset(bufferRS232, '\0', (sizeof(unsigned char) * TAILLE_MAX_CHAINE));
	   COM_LectureBufferRx(numSlot, bufferRS232, &lngMsg);
	   AFFICHAGE_AfficheRxRS232(numSlot, bufferRS232);
	COM_RazRxTxPorts(numSlot);
	ProcessSystemEvents();

}	 */

/*****************************************************************************
*
*      .NOM				: 	COM_RechercheTag
*
*      .DESCRIPTION  		:	Recherche de tag sur un port com
*
*		.TRACABILITE 		:
*
*      .ENTREES        	:   numSlot : numéro de slot
*								tag : tag à trouver
*								lngTag : longueur du tag à trouver (caractère fin de chaine carFinTag NON compris)
*								carFinTag : caractère de fin de chaine pour le tag et sa suite (exemple '\0', mais ça peut etre n'importe quoi d'autre !)
*								tagSuite : chaine comportant le tag et sa suite (si tag trouvé : cette chaine va du tag au caractere carFinTag)
*								lngTagSuite : longueur du tag et de sa suite (caractère fin de chaine carFinTag NON compris)
*								posTag : position du début du tag dans le buffer (compté à partir de 0)
*								tagTrouv : indicateur de tag trouvé (trouvé = OUI = 1, non trouvé = NON = 0)
*
*      .SORTIES      		:	Statut (ok = OK = 1, ko = KO = 0)
*
*      .VARIABLES GLOBALES :   GLOBALE_Slot1
*								GLOBALE_Slot2
*								GLOBALE_Slot3
*								GLOBALE_Slot4
*								GLOBALE_Slot5
*								GLOBALE_Slot6
*								GLOBALE_Slot7
*								GLOBALE_Slot8
*								GLOBALE_Slot9
*								GLOBALE_Slot10
*								GLOBALE_Slot11
*								GLOBALE_Slot12
*								GLOBALE_Slot13
*								GLOBALE_Slot14
*								GLOBALE_Slot15
*								GLOBALE_Slot16
*      .APPELS       		:   RS232_MEAS_RechercheTag
*
*      .REMARQUES    		:
*
*      .HISTORIQUE    		:
*
*      .CREATION     		:	12/09/2007
*****************************************************************************/
int COM_RechercheTag(int numSlot, unsigned char *tag, unsigned long lngTag, unsigned char carFinTag, unsigned char *tagSuite, unsigned long *lngTagSuite, unsigned long *posTag, int *tagTrouv)
{
	//int id = 0;
	unsigned long dimBuf = 0;

	short erreur = 0;
	long codeErreur = 0;
	char messagErreur[RS232_MSG_LEN] = {"\0"};
	int	 idPort = gSlot[numSlot].comDecodeur.iHandle;
	// Recup id
	/*
	switch(numSlot)
	{
		case SLOT_1 :
			id = GLOBALE_Slot1.idCom;
			break;

		case SLOT_2 :
			id = GLOBALE_Slot2.idCom;
			break;

		case SLOT_3 :
			id = GLOBALE_Slot3.idCom;
			break;

		case SLOT_4 :
			id = GLOBALE_Slot4.idCom;
			break;

		case SLOT_5 :
			id = GLOBALE_Slot5.idCom;
			break;

		case SLOT_6 :
			id = GLOBALE_Slot6.idCom;
			break;

		case SLOT_7 :
			id = GLOBALE_Slot7.idCom;
			break;

		case SLOT_8 :
			id = GLOBALE_Slot8.idCom;
			break;
		case SLOT_9 :
			id = GLOBALE_Slot9.idCom;
			break;
		case SLOT_10 :
			id = GLOBALE_Slot10.idCom;
			break;
		case SLOT_11 :
			id = GLOBALE_Slot11.idCom;
			break;
		case SLOT_12 :
			id = GLOBALE_Slot12.idCom;
			break;
		case SLOT_13 :
			id = GLOBALE_Slot13.idCom;
			break;
		case SLOT_14 :
			id = GLOBALE_Slot14.idCom;
			break;
		case SLOT_15 :
			id = GLOBALE_Slot15.idCom;
			break;
		case SLOT_16 :
			id = GLOBALE_Slot16.idCom;
			break;

	}

	// Lecture buffer
	RS232_MEAS_RechercheTag(idPort, tag, lngTag, carFinTag, tagSuite, lngTagSuite, TAILLE_MAX_CHAINE, posTag, &dimBuf, tagTrouv, &erreur, &codeErreur, messagErreur);
	// Adaptation de la réponse
	if (*tagTrouv == RS232_TROUV_OUI)
		*tagTrouv = OUI;
	else
		*tagTrouv = NON;
	// Gestion erreur
	if ((codeErreur != RS232_TAG_NON_TROUVE) && (codeErreur < 0))
		return KO;
	*/
	return OK;
}
// ==============================================================================
//  FONCTION     : FCT_AttenteFermetureCaisson
//  VERSION      : XXXXXXX
//  DATE         : 25/09/2012
//  AUTEUR       : NW
//  DESCRIPTION  : Fonction ChercherTag
//  MODIFICATION :
// ==============================================================================
int FCT_ChercherTag(int nItfe,char *Tag,int iTimeOut)
{
	short				erreur = 0;
	int                 status = -1;
	int					idPort = gSlot[nItfe].comDecodeur.iHandle;
	int				    flagTrouve;
	char                chRetour[100] = {"\0"};
	//unsigned char	Commande[TAILLE_MOY] = {"\0"};
	//double			time_out_debut;
	int				nbRetour;
	unsigned long	DimBuf;
	char			chBufferLuTmp[TAILLE_MAX]= {'\0'};
	long codeErreur;
	char messagErreur[1000];
	char chBufferLu[TAILLE_MAX];
	char sn_rs232[TAILLE_MAX] = {"\0"};
	int                  iLTimeOut=0;
	int                  bTimeOut;

	// RAZ des buffer RX/TX de la COM
	RS232_MAIN_PurgeTxPort (idPort, &erreur, &codeErreur, messagErreur);
	if (codeErreur < 0)
		return -1;
	RS232_MAIN_PurgeRxPort (idPort, &erreur, &codeErreur, messagErreur);
	if (codeErreur < 0)
		return -1;

	// Effacer le buffer de reception
	memset (chBufferLu, '\0', (sizeof(unsigned char) * TAILLE_MAX));

	flagTrouve = FALSE;
	bTimeOut = FALSE;

	while ((flagTrouve == FALSE)  && (gNPAbort == FALSE) && (bTimeOut==FALSE) )
	{
		Sleep (200);
		iLTimeOut=iLTimeOut+200;

		memset (chBufferLuTmp, '\0', (sizeof(unsigned char) * TAILLE_MAX));

		status = RS232_MEAS_LectureBuffer(idPort,
										  chBufferLuTmp,
										  &nbRetour,
										  2048,// à revoir
										  &DimBuf,
										  &erreur,
										  &codeErreur,
										  messagErreur);



		// ============================================
		// = On vérifie si des données ont été recues =
		// ============================================
		if ( nbRetour > 0 )
		{

			// Si le buffer de trace n'est pas plein on ajoute les données reçues
			// ------------------------------------------------------------------
			if ( ((strlen(chBufferLu) + strlen(chBufferLuTmp)) < 5000) && strlen(chBufferLuTmp) )
			{
				strcat (chBufferLu, chBufferLuTmp);
			}

			else if (strlen(chBufferLuTmp))
			{
				// On vide le buffer de réception
				// ------------------------------
				// Effacer le buffer de reception
				memset (chBufferLu, '\0', (sizeof(unsigned char) * 5000));
				// Ajoute les données reçues
				// -------------------------
				strcat (chBufferLu, chBufferLuTmp);
			}


		}

		// Recherche de la chaine souhaitée

		if (FindPattern (chBufferLu, 0, -1, Tag, 0, 0) > -1)
		{
			flagTrouve = TRUE;

			// RAZ des buffer RX/TX de la COM
			RS232_MAIN_PurgeTxPort (idPort, &erreur, &codeErreur, messagErreur);
			if (codeErreur < 0)
				return -1;
			RS232_MAIN_PurgeRxPort (idPort, &erreur, &codeErreur, messagErreur);
			if (codeErreur < 0)
				return -1;

			return 1;
		}
		// Si on dépasse le time Out
		if (iLTimeOut > iTimeOut)
			bTimeOut=TRUE;
	}

	/* il faut ajouter LA GESTION DES erreur RS232*/

	// caisson fermé ...
	return 0;//status;

}


// ==============================================================================
// FONCTION : 	  FCT_RecupSnSfin
// ------------------------------------------------------------------------------
// PROTOTYPE : 	  int FCT_RecupSnSfin (int nItfe)
// ------------------------------------------------------------------------------
// ARGUMENTS :
//				  - int nItfe	: Index du SLOT.
// ------------------------------------------------------------------------------
// RETOUR :
//				  - 0 = Sortie de fonction normale
//  			  - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Recupere le sn du produit
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :	 v1.0
//  DATE :		 26/09/2013
//  AUTEUR :	 NW
//  DESCRIPTION :  .
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_RecupSnSfin (int nItfe,char *Tag,char *Sn)
{
	int                 intStatusPassage = 1;
	int                 status = -1;
	int					flagErreur;
	char				chBuffLu[TAILLE_MAX] = {"\0"};
	char                chRetour[100+1] = {0};
	short				erreur = 0;
	int					idPort = gSlot[nItfe].comDecodeur.iHandle;
	int				    nbRetour;
	unsigned long	    DimBuf;
	char			    chBufferLuTmp[TAILLE_MAX]= {'\0'};
	long                codeErreur;
	int				    flagTrouve;
	char                messagErreur[1000];
	char                chBufferLu[TAILLE_MAX];
	char                sn_rs232[TAILLE_MAX] = {"\0"};
	char                sn[TAILLE_MAX] = {"\0"};

	char 				ETAT_DEC_BPO[50] = {"\0"};
	char 				sn_sc[TAILLE_MAX] = {"\0"};        // sn scanner
	char 				sn_client[TAILLE_MAX] = {"\0"};    // sn scanner
	char 				Ref_CIE[TAILLE_MAX] = {"\0"}; 	  //ref cie
	char 				Indice_CIE[TAILLE_MAX] = {"\0"};   //ref cie

	//===============================================
	char                **tabSN = NULL;
	char    			**tabVariables = NULL;
	int     			tabVariablesLength1;
	int     			tabVariablesLength2;
	int					blnErreurSurvenue;
	int					intErreurCode;
	char				*tcomErreur = NULL;
	char				*tcomErreurRequete = NULL;
	int					NbreEssais;
	//====== Variables TracaCom =====================



	// RAZ des buffer RX/TX de la COM
	RS232_MAIN_PurgeTxPort (idPort, &erreur, &codeErreur, messagErreur);
	if (codeErreur < 0)
		return -1;
	RS232_MAIN_PurgeRxPort (idPort, &erreur, &codeErreur, messagErreur);
	if (codeErreur < 0)
		return -1;

	// Effacer le buffer de reception
	memset (chBufferLu, '\0', (sizeof(unsigned char) * TAILLE_MAX));

	flagTrouve = FALSE;

	while ( (flagTrouve == FALSE)  && (gNPAbort == FALSE) )
	{
		Sleep (200);

		memset (chBufferLuTmp, '\0', (sizeof(unsigned char) * TAILLE_MAX));

		status = RS232_MEAS_LectureBuffer(idPort,
										  chBufferLuTmp,
										  &nbRetour,
										  2048,// à revoir
										  &DimBuf,
										  &erreur,
										  &codeErreur,
										  messagErreur);

		// ============================================
		// = On vérifie si des données ont été recues =
		// ============================================
		if ( nbRetour > 0 )
		{

			// Si le buffer de trace n'est pas plein on ajoute les données reçues
			// ------------------------------------------------------------------
			if ( ((strlen(chBufferLu) + strlen(chBufferLuTmp)) < 5000) && strlen(chBufferLuTmp) )
			{
				strcat (chBufferLu, chBufferLuTmp);
			}

			else if (strlen(chBufferLuTmp))
			{
				// On vide le buffer de réception
				// ------------------------------
				// Effacer le buffer de reception
				memset (chBufferLu, '\0', (sizeof(unsigned char) * 5000));
				// Ajoute les données reçues
				// -------------------------
				strcat (chBufferLu, chBufferLuTmp);
			}


		}

		// Recherche de la chaine souhaitée

		if (FindPattern (chBufferLu, 0, -1, Tag, 0, 0) > -1)
		{
			flagTrouve = TRUE;
			status = FCT_RechercheTag (chBufferLu, Tag, chRetour);

			if (status >= 0)
			{
				// nouveau système, récupère les 14 derniers caractères
				CopyString(sn_rs232, 0, chRetour, 0, 18);
				strcpy (ETAT_DEC_BPO,"etat_DEC_BPO_sClientSn");
				// Récupération SN CIE---------------------------------------------------------
				TracaCom_FonctionsMDT_FonctionsMDT_RecuperationNumSerieParProprieteNumSerie (gTcomBase.instSCProduction, ETAT_DEC_BPO,
						sn_rs232,
						&tabVariables,
						&tabVariablesLength1,
						&tabVariablesLength2,
						&blnErreurSurvenue,
						&intErreurCode,
						&tcomErreur,
						&tcomErreurRequete,
						NULL);

				// Recupération des prorités CIE
				strcpy (sn, tabVariables[1]);
				strcpy (Ref_CIE, tabVariables[2]);
				strcpy (Indice_CIE, tabVariables[3]);
				// Recupération des prorités SFIN
				TracaCom_FonctionsMDT_FonctionsMDT_RecuperationNumSeriesParents
				(gTcomBase.instSCProduction,
				 sn,
				 Ref_CIE,
				 Indice_CIE,
				 &tabVariables,
				 &tabVariablesLength1,
				 &tabVariablesLength2,
				 &blnErreurSurvenue,
				 &intErreurCode,
				 &tcomErreur,
				 &tcomErreurRequete,
				 NULL);
				// Recupération de SFIN
				strcpy (Sn, tabVariables[0]);


				//strncpy (chSnLu, (char*)(&chRetour[strlen(chRetour)-17]), 14);
				return 1;
			}

		}
	}
	return 0;
}
// ==============================================================================
// FONCTION :     FCT_VerificationSFC
// ------------------------------------------------------------------------------
// PROTOTYPE :    int FCT_VerificationSFC (int nItfe, char *strMessage  )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe           		: Index du SLOT ,
//                - char *SFC					: SFC à contrôler
//                - char *strMessage			: Message retour
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Vérifications sur le SFC en cours de test
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        06/03/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :Vérifie que le SFC en cours de test est affecté au bon code Produit
// 				 et au bon OF
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_VerificationSFC (int nItfe, char *SFC, char *CodeProduit, char *IndiceProduit, char *ReferenceOF, char *OF_SAPME, char *strMessage )
{

	int					error = 0;
	char				chCodeProduit_SAPME[SCPROD_OBJET_LONG_MAX];
	char				chIndiceProduit_SAPME[SCPROD_OBJET_LONG_MAX];
	char				chReferenceOF_SAPME[SCPROD_OBJET_LONG_MAX];
	char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'};

	char 				strErr[2040]= {'\0'};


	// Init variable
	// -------------
	sprintf(strMessage,"");


	// Appel de la fonction DLL sur l'OF
	// -----------------------------------
	errChk(SCPROD_InformationsSFC ( nItfe,
									&gTcomBase,
									SFC,
									chCodeProduit_SAPME,
									chIndiceProduit_SAPME,
									chReferenceOF_SAPME,
									strMessage));


	// Comparaison des Code/IND Produit  avec ceux Récupérés sur SAP ME
	// ----------------------------------------------------------------

	if (strcmp( chCodeProduit_SAPME,CodeProduit) != 0)
	{
		sprintf (strErr, "Le code produit du SFC: %s ne correspond pas à celui attendu : %s",chCodeProduit_SAPME,CodeProduit);

		MessagePopup("",strErr);

		sprintf (strMessage, "Le code produit du SFC: %s ne correspond pas à celui attendu : %s",chCodeProduit_SAPME,CodeProduit );
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, strMessage );
		errChk(-1);
	}

	if (strcmp( chIndiceProduit_SAPME,IndiceProduit) != 0)
	{

		sprintf (strErr, "L'indice produit du SFC : %s ne correspond pas à celui attendu : %s",chIndiceProduit_SAPME ,IndiceProduit);

		MessagePopup("",strErr);

		sprintf (strMessage, "L'indice produit du SFC : %s ne correspond pas à celui attendu : %s",chIndiceProduit_SAPME ,IndiceProduit);
		FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, strMessage );
		errChk(-1);
	}

	/*if (strcmp( chReferenceOF_SAPME,ReferenceOF) != 0)
	{
		sprintf (strMessage, "La référence de l'OF du SFC : %s ne correspond pas à celle attendue : %s",chReferenceOF_SAPME,ReferenceOF);
		errChk(-1);
	} */

	strcpy(OF_SAPME,chReferenceOF_SAPME);


Error:


	if (error)
	{
		// Affichage Dans le log
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{
			sprintf (chMsgInfo, "Erreur lors du contrôle du SFC : %s", strMessage );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
		return -1;
	}

	return 0;
}

// ==============================================================================
// FONCTION :     FCT_VerificationSFC_MultiOF_CMS
// ------------------------------------------------------------------------------
// PROTOTYPE :    int FCT_VerificationSFC_MultiOF_CMS (int nItfe, char *strMessage  )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe           		: Index du SLOT ,
//                - char *SFC					: SFC à contrôler
//                - char *strMessage			: Message retour
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Vérifications sur les OF autorisés pour le SFC en cours de test
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002BA01
//  DATE :        06/11/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :Vérifie que le SFC en cours de test est affecté sur un des OF configurés
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_VerificationSFC_MultiOF_CMS (int nItfe, char *SFC, char *CodeProduit, char *IndiceProduit, char *strMessage )
{

	/*int					error = 0;
	int					iCompteur = 0;
	//int					iFlagOFFound = -1;
	int					status ;
	char    			chMsgInfo [SCPROD_MSG_LONG_MAX] = {'\0'};
	T_VARIABLES         *ptrVariablesConf = &(gSlot[nItfe].variablesConf);
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);


	// Init variable
	// -------------
	sprintf(strMessage,"");
	status = -1;

	// On regarde si le SFC appartient à l'un des OF configurés
	// --------------------------------------------------------
	for (iCompteur = 0; iCompteur < VAR_NB_VAL(ptrVariablesConf,VAR_CONF_ID_REF_OF_CMS) ; iCompteur++)
	{
		status = FCT_VerificationSFC (nItfe,SFC, CodeProduit,IndiceProduit, VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_REF_OF_CMS,iCompteur),strMessage);

		// Si on a trouvé un OF on le recopie en valeur traça produit, et on sort de la boucle
		// -----------------------------------------------------------------------------------
		if (status == 0)
		{
			strcpy(ptrVariablesTraca->chOrdreFabCMS,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_REF_OF_CMS,iCompteur));
			break;
		}

	}

	// Si on n'a pas trouvé d'OF, on sort en erreur
	// -----------------------------------------
	if (status != 0)
		errChk (-1);


	Error:


	if (error)
	{
		// Affichage Dans le log
		// ----------------------
		if (gFlagLogSAPME == TRUE )
		{
			sprintf (chMsgInfo, "Erreur lors du contrôle du SFC : %s", strMessage );
			FCT_AfficheInfo ( nItfe, IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO_TRACA, chMsgInfo );
		}
		return -1;
	}

	return 0;*/


	return -1;
}

// ==============================================================================
// FONCTION :     FCT_VerificationVariables
// ------------------------------------------------------------------------------
// PROTOTYPE :    int FCT_VerificationVariables (int nItfe, char *strMessage  )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe           		: Index du SLOT ,
//                - char *strMessage			: Message retour
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
// ------------------------------------------------------------------------------
// DESRIPTION :   Vérifications sur les variables avant d'appeler l'autorisation de passage
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S13002AA00
//  DATE :        06/03/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_VerificationVariables( int nItfe, char *chMessErreur)
{
	short               error = 0;
	int                 ii;
	int 				yy;
	int					iErreurLocale;
	char                chIndiceCie[16] = {'\0'};
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	T_VARIABLES         *ptrVariablesConf = &(gSlot[nItfe].variablesConf);
	T_VARIABLES         *ptrVariablesEtat = &(gSlot[nItfe].variablesEtat);
	T_POSTE_PRODUIT     *ptrProduit = &(gPosteProduits.produits[gSlot[nItfe].variablesTraca.idxProduit]);

	char strCountryIdTemp[100] =  {'\0'};
	char strHardwareIdTemp[10] =  {'\0'};
	char strHardwareVersionTemp[100] =  {'\0'};
	char strProvVodaTemp[100] =  {'\0'};
	int		iHwVersionEnDecimal = 0;


	// ===============================================
	// = RAZ des paramètres de sortie de la fonction =
	// ===============================================
	chMessErreur[0] = '\0';


	// =========================================
	// = Controle de la validité des variables =
	// =========================================

	// Pour éviter que 2 SN CIE soient en meme temps sur 2 slots parmi le nbr de slot
	// ------------------------------------------------------------------------------
	for (ii = 0; ii < NBRE_INTERFACE; ii ++)
	{
		for (yy = 0; yy < NBRE_INTERFACE; yy ++)
		{
			if ( ii != yy && strlen (gSlot[ii].variablesTraca.CieSn) != 0 )
			{
				if (strcmp(gSlot[ii].variablesTraca.CieSn, gSlot[yy].variablesTraca.CieSn) == 0 )
				{
					sprintf (chMessErreur, GET_MESSAGE(FCT_MSG_SN_TESTENCOURS));
					errChk (-1);
				}
			}
		}
	}

	// Verification Version CIE
	// ------------------------
	if ( FCT_STRING_IS_EMPTY (ptrProduit->cie.chVersion) == FALSE )
	{
		if ( strstr ( ptrProduit->cie.chVersion, ptrVariablesTraca->CieVersion ) == NULL)
		{
			sprintf (chMessErreur, GET_MESSAGE(FCT_MSG_MAUVAISE_VERSION_CIE), ptrProduit->cie.chVersion, ptrVariablesTraca->CieVersion);
			errChk (-1);
		}
		if ( strlen(ptrVariablesTraca->CieVersion) == 0)
		{
			sprintf (chMessErreur, GET_MESSAGE(FCT_MSG_VERSION_CIE_PASENFLASH));
			errChk (-1);
		}
	}

	// Verification Indice CIE
	// -----------------------
	if ( FCT_STRING_IS_EMPTY (ptrProduit->cie.chIndice) == FALSE )
	{
		strcpy (chIndiceCie, ptrProduit->cie.chIndice);
		FCT_SupprimerTag ( chIndiceCie, "0" );
		if ( strstr ( chIndiceCie, ptrVariablesTraca->CieIndice ) == NULL )
		{
			sprintf (chMessErreur, GET_MESSAGE(FCT_MSG_MAUVAIS_INDICE_CIE), chIndiceCie, ptrVariablesTraca->CieIndice);
			errChk (-1);
		}
		if ( strlen(ptrVariablesTraca->CieIndice) == 0)
		{
			sprintf (chMessErreur, GET_MESSAGE(FCT_MSG_INDICE_CIE_PASENFLASH));
			errChk (-1);
		}
	}

	//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Controle indice skipé !!!!!!!");

	// Vérification masque du SN CIE (DFAB)
	// ------------------------------------
	/* for ( ii=0 ; ii<VAR_NB_VAL(ptrVariablesConf,VAR_CONF_ID_MASQUE_SN_CIE) ; ii++ )
	 {
		 FCT_SupprimerTag ( VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_MASQUE_SN_CIE,ii), "'" );
		 if ( FCT_MasqueValidation ( VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_MASQUE_SN_CIE,ii), ptrVariablesTraca->CieSn,MASQUE_ZERO_ACTIF ) == 0 )
		 {
			 break;
		 }
	 }
	 if ( (ii >= VAR_NB_VAL(ptrVariablesConf,VAR_CONF_ID_MASQUE_SN_CIE)) && (VAR_NB_VAL(ptrVariablesConf,VAR_CONF_ID_MASQUE_SN_CIE) > 0) )
	 {
		 sprintf (chMessErreur, GET_MESSAGE(FCT_MSG_MAUVAIS_MASQUE_CIE));
		 errChk (-1);
	 }
	if ( strlen(ptrVariablesTraca->CieSn) == 0)
	 {
		 sprintf (chMessErreur, GET_MESSAGE(FCT_MSG_SERIAL_CIE_PASENFLASH));
		 errChk (-1);
	 }
		*/

	// vérification du TT
	// ------------------
	/*if ( VAR_DEFINED(ptrVariablesConf,VAR_CONF_ID_TERM_TECH) == TRUE )
	{
		if ( strstr ( VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_TERM_TECH,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_TT_VERSION,0) ) == NULL )
		{
			sprintf (chMessErreur, "La version du TT (%s) en BDD est différente de celle du décodeur (%s)", VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_TERM_TECH,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_TT_VERSION,0));
			errChk (-1);
		}
	}

	// Verification de la version du Loader
	// ------------------------------------
	if ( VAR_DEFINED(ptrVariablesConf,VAR_CONF_ID_LOADER) == TRUE )
	{
		if ( strstr ( VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_LOADER,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_LOADER_VERSION,0) ) == NULL )
		{
			sprintf (chMessErreur, GET_MESSAGE(FCT_MSG_MAUVAIS_LOADER), VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_LOADER,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_LOADER_VERSION,0));
			errChk (-1);
		}
	}

	// Verification de la version du Pic
	// ------------------------------------
	if ( VAR_DEFINED(ptrVariablesConf,VAR_CONF_ID_PIC_VERSION) == TRUE )
	{
		if ( strstr ( VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_PIC_VERSION,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_PIC_VERSION,0) ) == NULL )
		{
			sprintf (chMessErreur, "La version du PIC (%s) en BDD est différente de celle du décodeur (%s)", VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_PIC_VERSION,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_PIC_VERSION,0));
			errChk (-1);
		}
	}

	// Verification de la version du RF4CE
	// ------------------------------------
	if ( VAR_DEFINED(ptrVariablesConf,VAR_CONF_ID_RF4CE_VERSION) == TRUE )
	{
		if ( strstr ( VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_RF4CE_VERSION,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_RF4CE_VERSION,0) ) == NULL )
		{
			sprintf (chMessErreur, "La version du RF4CE (%s) en BDD est différente de celle du décodeur (%s)", VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_RF4CE_VERSION,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_RF4CE_VERSION,0));
			errChk (-1);
		}
	}

	// Verification de la version du Usage ID
	// ---------------------------------------
	if ( VAR_DEFINED(ptrVariablesConf,VAR_CONF_ID_USAGE_ID) == TRUE )
	{
		if ( strstr ( VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_USAGE_ID,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_USAGE_ID,0) ) == NULL )
		{
			sprintf (chMessErreur, "La version du Usage ID (%s) en BDD est différente de celle du décodeur (%s)", VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_USAGE_ID,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_USAGE_ID,0));
			errChk (-1);
		}
	}

	// Verification de la version Nomenclature Hard
	// --------------------------------------------
	if ( VAR_DEFINED(ptrVariablesConf,VAR_CONF_ID_NOM_HARD) == TRUE )
	{
		if ( strstr ( VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_NOM_HARD,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_NOM_HARD_VERSION,0) ) == NULL )
		{
			sprintf (chMessErreur, GET_MESSAGE(FCT_MSG_MAUVAISE_NOMENCLATURE_HARD), VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_NOM_HARD,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_NOM_HARD_VERSION,0));
			errChk (-1);
		}
	}

	// Verification de la version Nomenclature Boot
	// --------------------------------------------
	if ( VAR_DEFINED(ptrVariablesConf,VAR_CONF_ID_NOM_BOOT) == TRUE )
	{
		if ( strstr ( VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_NOM_BOOT,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_NOM_BOOT_VERSION,0) ) == NULL )
		{
			sprintf (chMessErreur, GET_MESSAGE(FCT_MSG_MAUVAISE_NOMENCLATURE_BOOT), VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_NOM_BOOT,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_NOM_BOOT_VERSION,0));
			errChk (-1);
		}
	}

	// Verification Full Sales Type
	// ----------------------------
	if ( VAR_DEFINED(ptrVariablesEtat,VAR_ETAT_ID_FULL_SALES_TYPE) == TRUE )
	{
		if ( VAR_DEFINED(ptrVariablesConf,VAR_CONF_ID_FULL_SALES_TYPE) == TRUE)
		{
			for ( ii=0 ; ii<VAR_NB_VAL(ptrVariablesConf,VAR_CONF_ID_FULL_SALES_TYPE) ; ii++ )
			{
				if ( strstr ( VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_FULL_SALES_TYPE,ii), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_FULL_SALES_TYPE,0) ) != NULL )
				{
					break;
				}
			}
			if ( ii == VAR_NB_VAL(ptrVariablesConf,VAR_CONF_ID_FULL_SALES_TYPE) )
			{
				sprintf (chMessErreur, GET_MESSAGE(FCT_MSG_MAUVAISE_FULL_SALES_TYPE), VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_FULL_SALES_TYPE,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_FULL_SALES_TYPE,0));
				errChk (-1);
			}
		}
		else
		{
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(FCT_MSG_VARIABLE_STRING_NON_DEFINIE), ptrVariablesConf->variables[VAR_CONF_ID_FULL_SALES_TYPE].nom);
			errChk (-1);
		}
	}

	// Verification de la version d'appli  (origine Famille EGCI)
	// ----------------------------------------------------------
	if ( VAR_DEFINED(ptrVariablesConf,VAR_CONF_ID_APPLICATION_VERSION) == TRUE )
	{
		if ( strstr ( VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_APPLICATION_VERSION,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_APPLICATION_VERSION,0) ) == NULL )
		{
			sprintf (chMessErreur, "The BDD Application Version (%s) is different from the STB's one (%s)", VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_APPLICATION_VERSION,0), VAR_GET_STRING(ptrVariablesEtat,VAR_ETAT_ID_USAGE_ID,0));
			errChk (-1);
		}
	}
	*/


Error:
	if (error)
	{
		return -1;
	}
	return 0;
}

////







// ==============================================================================
//  FONCTION     : FCT_LectureNumserieGateWay
//  VERSION      :
//  DATE         :
//  AUTEUR       :
//  DESCRIPTION  :
//  MODIFICATION : Lecture DFA via Telnet
// ==============================================================================
int FCT_LectureNumserieGateWay(int nItfe, char *chMessageErreur)
{

	T_VARIABLES_TRACA	 *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	T_VARIABLES			 *ptrVariablesConf = &gSlot[nItfe].variablesConf;

	char            	 **infos = NULL;
	char 				 chTagDfa[20]="";

	int					 Status = 0;
	int             	 nbInfos = 0;
	int 				 nbredfa_mere = 0;

	Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_Lecture_DFA_MERE,0), &infos,&nbInfos ,NULL, 3000);

	if (Status != 0)
	{

		strcpy(chMessageErreur,"Erreur lecture DFA");
		return -1;

	}

	nbredfa_mere = VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_GTW_BWC_Nombre_Char_DFA_MERE,0);

	if(nbInfos > 0 && (strlen(infos[0]) == nbredfa_mere))
	{
		sprintf(chTagDfa,"%s%s",VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_TAG_DFA_MERE,0),infos[0]);
		strcpy(ptrVariablesTraca->CieSn,chTagDfa);

	}
	else
	{
		strcpy(chMessageErreur,"Erreur lecture DFA");
		return -1;
	}
	return Status;
}




////
/*
// ==============================================================================
//  FONCTION     : FCT_LectureNumserieGateWay
//  VERSION      :
//  DATE         :
//  AUTEUR       :
//  DESCRIPTION  :
//  MODIFICATION : Lecture DFA via Telnet
// ==============================================================================
int FCT_LectureNumserieGateWay(int nItfe, char *chMessageErreur)
{
T_VARIABLES_TRACA	*ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
char Response [2000]="";
int Status = 0;
int erreur = 0;
T_TAB_CMD cmdOut;
char cmd[1024]= {"\0"};
int             nbInfos = 0;
char            **infos = NULL;
char chTagDfa[12]="";
char chTagDfa_1[12]="";
char gchPointDfaFille[12] = "";
int nbredfa_mere = 0;


//Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_LECTURE_SN,0), &infos,&nbInfos ,NULL, 3000);

Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_LECTURE_SN,0), &infos,&nbInfos ,NULL, 3000);

if (Status != 0)
{

strcpy(chMessageErreur,GET_MESSAGE(FCT_LIBELLE_ERREUR_LECTURE_SN));
return -1;

}


if(nbInfos == 3)
{
strncpy(ptrVariablesTraca->chChipsetSnHex,infos[0],TAILLE_MAX-1);
FCT_SupprimerTag ( ptrVariablesTraca->CieVersion, "-" );
strncpy(ptrVariablesTraca->CieIndice,infos[1],TAILLE_MAX-1);
strncpy(ptrVariablesTraca->CieSn,infos[2],TAILLE_MAX-1);
}
else
{
strcpy(chMessageErreur,GET_MESSAGE(FCT_LIBELLE_ERREUR_LECTURE_SN));
return -1;
}

Status =FCT_VerificationVariables(nItfe,chMessageErreur);

if (Status != 0)
{
return -1;
}

return Status;
}
*/
/////
// ==============================================================================
//  FONCTION     : FCT_Verification_version_Firmware
//  VERSION      :
//  DATE         :
//  AUTEUR       :
//  DESCRIPTION  :
//  MODIFICATION : Verification version Firmware
// ==============================================================================
int FCT_Verification_version_Firmware(int nItfe, char *chMessageErreur)
{
	/*
	T_VARIABLES_TRACA	*ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	char chTagDfa[12]="";
	char chTagDfa_1[12]="";
	char gchPointDfaFille[12] = "";
	int nbredfa_mere = 0;


	Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_VERIF_VERSION_FIRMWARE,0), &infos,&nbInfos ,NULL,7);

	if (Status != 0)
	{

		strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_VERIF_VERSION_FIRMWARE_KO));
		return -1;

	}

	return Status;*/
}

/*********************************************************************************************************
											  Test button
*********************************************************************************************************/
int Test_button(int HandleTelnet,char cmd [1024], int TimeOut,char Tag [1024],char signal[64], char sMessage [50001] )
{
	int iDone = -1,Index=0 ;
	int iHandLeTelnet =0;

	char sBuffer[255]="";


	iDone= Telnet_Query (HandleTelnet,cmd,Tag,sMessage,signal,TimeOut)  ;
	if (iDone <0)return -1 ;
	return 0;
}

/*********************************************************************************************************
										   Ouverture Telnet
*********************************************************************************************************/
int OuvertureTelnet(char sIPDUT[255],char sLogin[255],char sPreFixLogin[255],char sSuFixLogin[255],char sPassword[255],char sSuFixPassword[255], int TimeOut)
{
	int iDone = -1 ;
	int iHandLeTelnet =0;

	char sMessage[255]="";
	char sBuffer[255]="";

	iHandLeTelnet = InetTelnetOpen (sIPDUT, 23, 0);
	if (iHandLeTelnet <0)  goto Exit;
	else iDone =0 ;

	if(strcmp(sLogin,"")!=0 ) iDone = InetTelnetReadUntil (iHandLeTelnet, sBuffer, sizeof(sBuffer), sPreFixLogin, 4000);
	if (iDone <0) goto Exit ;

	if(strcmp(sLogin,"") !=0 ) iDone= Telnet_Query (iHandLeTelnet,sLogin,sSuFixLogin,sMessage,"",TimeOut)  ;
	if (iDone <0) goto Exit ;

	if(strcmp(sPassword,"") !=0 ) iDone= Telnet_Query (iHandLeTelnet,sPassword,sSuFixPassword,sMessage,"",TimeOut)  ;
	if (iDone <0) goto Exit ;

Exit :

	return iDone <0 ? -1: iHandLeTelnet;
}

//==============================================================================
//==============================================================================
/*
* \file DefFonction.c
* \author Aymen.Charrada
* \version 1.0.0.0
* \date 28/11/2012
* \fn int LectureDFAviaTelnet (int HandleTelnet, char *SendCmd,int LengthDFA,
								int TimeOutms,  char *sDFALue ,char *sMessage)
* \return 0/1
* \brief Fonction a pour objet de : Lecture DFA VIA Telnet
*/
//==============================================================================
//==============================================================================
int LectureDFAviaTelnet (int HandleTelnet, char *SendCmd,int LengthDFA,int TimeOutms,  char *sDFALue ,char *sMessage)
{
	int iErreur=0;
	char sLecture[10000]="";
	char *strDFA ;
	int PosTag1=-1;
	int PosTag2=-1;



	iErreur = Telnet_Query (HandleTelnet,SendCmd,"#",sLecture,"", TimeOutms) ;

	if(iErreur==1)
	{

		PosTag1=FindPattern (sLecture, 0, sizeof(sLecture), "R", 0, 0);
		PosTag2=FindPattern (sLecture, 0, sizeof(sLecture), "RG", 0, 0);

		if( (PosTag1>=0) || (PosTag2>=0) )
		{

			if(PosTag1>=0)
			{
				CopyString (sDFALue, 0, sLecture, PosTag1,LengthDFA );
				sprintf(sMessage,"DFA lue:%s\n",sDFALue);
				//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, sMessage);

			}

			if(PosTag2>=0)
			{
				CopyString (sDFALue, 0, sLecture, PosTag2,LengthDFA );
				sprintf(sMessage,"DFA lue:%s\n",sDFALue);
				//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, sMessage);
			}

			if (strlen (sDFALue)!=11) iErreur=ERREUR_TELNET_LECTURE_DFA;
		}
		else
			iErreur=ERREUR_TELNET_LECTURE_DFA;

	}

	return ( iErreur); 	// 1 si OK
}

// ==============================================================================
//  FONCTION     : Test_button  RC
//  VERSION      : V1.01
//  DATE         :15/02/2019
//  AUTEUR       : Slimene Hamdi
//  DESCRIPTION  :
// ==============================================================================
int Test_button_RC (int HandleTelnet,char cmd [1024], int TimeOut,char Tag [1024],char signal[64],int IndiceCMMO, char sMessage [50001] )
{
	int iDone = -1,Index=0 ;
	int iHandLeTelnet =0;

	char sBuffer[255]="";


	iDone= Telnet_Query_Festo (HandleTelnet,cmd,Tag,sMessage,signal,IndiceCMMO,TimeOut)  ;
	if (iDone <0)return -1 ;
	return 0;
}

//==============================================================================
//==============================================================================
/**
* \file DefFonction.c
*.
* \author Aymen.Charrada
* \version 1.0.0.0
* \date 28/11/2012
*
* \fn int AFficheMsgErreur(int iErreur, char * sMessage )
*
* \return 0/1
*
* \brief Fonction a pour objet de :
* \brief Afficher les messages d'erreur
*
*/
//==============================================================================
//==============================================================================
int AFficheMsgErreur(int iErreur, char * sMessage )
{
	switch (iErreur)
	{
		case ERREUR_TELNET_OUVERTURE :
			sprintf(sMessage,"%d :Erreur Ouverture Telnet",iErreur);
			break;
	}

	return (iErreur!=1 ? 0:1);
}

int TelnetOpenSession ( int *HandleTelnet,char *IPFAST, int NumPort, char *Login, char *TagLogin, char *Psw, char * TagPassword , char *Response )
{
	int iErreur=1;// Mauvais par defaut
	int Done=0;
	int iFastPret =-2;
	char response[3000]="";
	char sTamp[100]="";
	int pos=-1;
	int essai=0;
	int iTempHandle = -1;
	int	iCpt = 0;

	// Pbroblème session telnet
	//SetBreakOnLibraryErrors (0);

	iCpt = 0;
	do
	{
		//InetTelnetClose(iTempHandle);


		// Lock Telnet
		//-------------
		//CmtGetLock (gLockTelnet);
		//SetBreakOnLibraryErrors (0);

		iTempHandle = InetTelnetOpen (IPFAST, NumPort, 0);

		//SetBreakOnLibraryErrors (1);
		// Unlock Telnet
		//--------------
		//CmtReleaseLock (gLockTelnet);



		if (iTempHandle >=0 )
		{
			iCpt = 4;
		}
		else
		{
			Sleep(200);
		}

	}
	while(++iCpt <3);



	if (iTempHandle >=0 )
	{
		*HandleTelnet =  iTempHandle;
		return 1;
	}
	else
		return -1;
}

// ==============================================================================
// FONCTION :		FCT_CloseConnexionTelnet
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			29/11/2011
//  AUTEUR :		TNI
//  DESCRIPTION : 	Fermeture de la connecxion Telnet
// ==============================================================================
int FCT_CloseConnexionTelnet (int nItfe, char	*chMessageErreur, int HandleTelnet )
{
	int iErreur=1;

	iErreur=!InetTelnetClose(HandleTelnet);
	if(iErreur!=1)
		iErreur=ERREUR_TELNET_FERMETURE;

	return iErreur;
}

int  TelnetCloseSession(int HandleTelnet,char *Response)
{
	int iErreur=1;

	iErreur=!InetTelnetClose(HandleTelnet);
	if(iErreur!=1)
		iErreur=ERREUR_TELNET_FERMETURE;

	return iErreur;
}

int  TelnetCloseSession_slot2(int HandleTelnet,char *Response)
{
	int iErreur=1;

	iErreur=!InetTelnetClose(HandleTelnet);
	if(iErreur!=1)
		iErreur=ERREUR_TELNET_FERMETURE;

	return iErreur;
}



/*********************************************************************************************************
								Fonction Attente Ping GateWay
*********************************************************************************************************/
/*int FCT_CMD_PingGateWay (int nItfe, char *messagErreur)
{
	int Ping=-1;
	int status=-1;
	int	idPort = gSlot[nItfe].comDecodeur.iHandle;
	char chBufferLuTmp[TAILLE_MAX]= {'\0'};
	long                codeErreur;
	short           erreur = 0;
	unsigned long   nbRetour;
	unsigned long   DimBuf;
	char            chMessErreur[TAILLE_MAX] = {"\0"};

	//char CMD_Commande[1000]={'\0'};

	/*	status = RS232_CONF_EcrirePort (idPort,
											"\n",
											2,
											&erreur,
											&codeErreur,
											messagErreur);

		 status = RS232_MEAS_LectureBufPattern (idPort, chBufferLuTmp, sizeof(chBufferLuTmp)-1, &DimBuf, "TT>", 2.5,&erreur , &codeErreur,messagErreur );   */
//FIL2LO_PrintCom (nItfe, FIL2LO_COM_GTW_RX, CMD_Commande);	// pour debug en local sans gateway ...
/*status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,"[\n{Pass:TT>}]", NULL,NULL ,NULL, 3000);


if (status<0)
{
	strcpy (messagErreur, "Demarrage KO !!!");
	return -1;
}					*/

//FIL2LO_PrintCom (nItfe, FIL2LO_COM_GTW_TX, CMD_Retour);


/*status = RS232_CONF_EcrirePort (idPort,
								"\n",
								2,
								&erreur,
								&codeErreur,
								chMessErreur);

Sleep (500);

status = RS232_MEAS_LectureBuffer ( idPort,
									chBufferLuTmp,
									&nbRetour,
									TAILLE_MAX,
									&DimBuf,
									&erreur,
									&codeErreur,
									chMessErreur);

status = FindPattern (chBufferLuTmp, 0,sizeof(chBufferLuTmp), "TT>", 0, 0);

//status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_PROMPT_DUT,0), NULL,NULL ,NULL, 3000);

if (status<0)
{
	strcpy (messagErreur, "Demarrage KO !!!");
	return -1;
}

return 0;
}
*/



/*********************************************************************************************************
								Fonction Attente Demarrage GateWay
*********************************************************************************************************/
int FCT_AttenteDemarrageGateWay (int nItfe, char *messagErreur)
{
	int iCpt=0;
	int status=-1;

	T_VARIABLES_TRACA	*ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	int                 idPort = gSlot[nItfe].comDecodeur.iHandle;
	short           erreur = 0;
	long            codeErreur = 0;
	char            chMessErreur[TAILLE_MAX] = {"\0"};
	unsigned long   nbRetour;
	unsigned long   DimBuf;
	char            chBufferLuTmp[TAILLE_MAX]= {'\0'};

	// =====================================
	// = RAZs des buffer RX/TX du port COM =
	// =====================================
	RS232_MAIN_PurgeTxPort(idPort, &erreur, &codeErreur, chMessErreur);
	if (codeErreur < 0)
		return -1;
	RS232_MAIN_PurgeRxPort(idPort, &erreur, &codeErreur, chMessErreur);



	if (codeErreur < 0)
		return -1;


	do
	{
		status = RS232_CONF_EcrirePort (idPort,
										"\n",
										2,
										&erreur,
										&codeErreur,
										chMessErreur);
		Sleep (500);
		status = RS232_MEAS_LectureBuffer ( idPort,
											chBufferLuTmp,
											&nbRetour,
											TAILLE_MAX,
											&DimBuf,
											&erreur,
											&codeErreur,
											chMessErreur);

		status = FindPattern (chBufferLuTmp, 0,sizeof(chBufferLuTmp), VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_PROMPT_DUT,0), 0, 0);

		ProcessDrawEvents ();
		//	VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_PROMPT_DUT,0)"TT>"


	}
	while ((++iCpt<20) && (status < 0) && (gNPAbort==FALSE));

	return (status<0) ?  -1 : 0;
}

/*********************************************************************************************************
								Fonction Attente Perte Ping GateWay
*********************************************************************************************************/
int FCT_AttentePertePingGateWay (int nItfe, char *messagErreur)
{
	int iCpt=0;
	int status=0;

	do
	{
		status = FCT_CMD_PingGateWay (nItfe, messagErreur);
	}
	while ((status!=-1) && (gNPAbort==FALSE));   //(++iCpt<10) &&

	return (status==-1) ?  0 : -1;
}

// ==============================================================================
// FONCTION :		FCT_Assemblage_fille_mere
// ------------------------------------------------------------------------------
//  VERSION :		V1.0.2
//  DATE :			25/04/2020
//  AUTEUR :		CH
//  DESCRIPTION :   Assemblage carte fille mére
// ==============================================================================

int FCT_Assemblage_fille_mere (int nItfe, char	*strErreurMessage )
{
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	int		            error = 0;


	errChk ( SCPROD_AssemblageComposant ( 	nItfe,
											&gTcomBase,
											ptrVariablesTraca->CiuSfcFilleSAPME,
											NULL,
											ptrVariablesTraca->PfinSfcSAPME,
											SCPROD_ASSEMBLAGE_SFC,
											NOM_OPERATION,
											ptrVariablesTraca->NomRessourceSAPME,
											strErreurMessage ));


Error:

	if (error)
	{
		if ( strErreurMessage[0] == '\0')
			strcpy (strErreurMessage, "Problème Assemblage carte fille mère");
		return -1;
	}

	return 0;
}

// ==============================================================================
// FONCTION :		FCT_Initialisation
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			19/08/2022
//  AUTEUR :		FZI
//  DESCRIPTION :   Initialisation
// ==============================================================================

int FCT_Initialisation (int nItfe, char	*chMessageErreur )
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0;


	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_INITIALISATION,0), &infos,&nbInfos ,NULL, 3);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur, "Erreur initialisation");
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));


	return Status;
}

// ==============================================================================
// FONCTION :		FCT_Finalisation
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			25/10/2019
//  AUTEUR :		FZI
//  DESCRIPTION :   Initialisation wifi 2GHz
// ==============================================================================

int FCT_Finalisation (int nItfe, char	*chMessageErreur )
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_FINALISATION,0), &infos,&nbInfos ,NULL, 10);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_FINALISATION_KO));
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));


	return Status;
}

// ==============================================================================
// FONCTION :		FCT_Config_Wifi_2G
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			25/10/2019
//  AUTEUR :		FZI
//  DESCRIPTION :   configuration wifi 2G
// ==============================================================================

int FCT_Config_Wifi_2G (int nItfe, char	*chMessageErreur )
{
	/*
		T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
		char Response [2000]="";
		int Status = 0;
		int erreur = 0;
		T_TAB_CMD cmdOut;
		char cmd[1024]= {"\0"};
		int iFlagRtray=0,inbreRetray=0;

		do
		{
			iFlagRtray = 0;
			Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_CMD_Config_Wifi_2G,0), NULL, NULL,NULL, 3);

			inbreRetray = inbreRetray +1;
			if ( (Status != 0) )
			{
				strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_Configuration_2G_KO));
				Sleep(2000);
				iFlagRtray = 1;
				if(inbreRetray > 2)
					return -1;
			}
		}
		while((inbreRetray <3) && (iFlagRtray ==1));


		return Status;*/
}

// ==============================================================================
// FONCTION :		FCT_Config_Wifi_5G
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			25/10/2019
//  AUTEUR :		FZI
//  DESCRIPTION :   configuration wifi 5G
// ==============================================================================

int FCT_Config_Wifi_5G (int nItfe, char	*chMessageErreur )
{
	/*

	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_CMD_Config_Wifi_5G,0), NULL, NULL,NULL, 3);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_Configuration_5G_KO));
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));

	return Status;*/
}

// ==============================================================================
// FONCTION :		FCT_Config_BT
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			24/06/2020
//  AUTEUR :		CH_BK
//  DESCRIPTION :   configuration Bluetooth
// ==============================================================================

int FCT_Config_BT (int nItfe, char	*chMessageErreur )
{
	/*

	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_CONFIG_BT,0), NULL, NULL,NULL, 3);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_Configuration_BT_KO));
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));

	return Status;*/
}


// ==============================================================================
// FONCTION :		FCT_Test_Bouton
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			01/10/2020
//  AUTEUR :		CH_BK
//  DESCRIPTION :   Test Bouton
// ==============================================================================

int FCT_Test_Bouton (int nItfe, char	*chMessageErreur )
{
	/*

	T_VARIABLES	 *ptrVariablesConf = &gSlot[nItfe].variablesConf;
	int          Status = 0;
	char         cmd[1024]= {"\0"};
	int          iFlagRtray=0,inbreRetray=0;
	int          iNbreBouton = 0;
	char 		 charNbreBouton[100]="";

	if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_Nombre_Bouton,0) > 0)
	{
		iNbreBouton = VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_Nombre_Bouton,0);


		for (int i = 0; i < iNbreBouton; i++)
		{

			inbreRetray = 0;
			Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_CMD_TEST_Bouton1,i*iNbreBouton), NULL, NULL,NULL, 3);

			do
			{
				iFlagRtray = 0;

				SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_Test_Bouton, ATTR_VISIBLE, TRUE);
				SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_Test_Bouton, ATTR_TEXT_POINT_SIZE, 30);

				sprintf(charNbreBouton,GET_MESSAGE(PNL_BOUTON_TXT_INFO_TEXT) ,i+1);
				ResetTextBox (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_Test_Bouton,charNbreBouton);

				Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_CMD_TEST_Bouton1,i*iNbreBouton+1), NULL, NULL,NULL, 3);

				inbreRetray = inbreRetray +1;
				if ( (Status != 0) )
				{
					strcpy(chMessageErreur,GET_MESSAGE(THR_LIBELLE_ERREUR_BOUTON));
					Sleep(2000);
					iFlagRtray = 1;
					if(inbreRetray > 4)
					{
						ResetTextBox (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_Test_Bouton, "");
						SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_Test_Bouton, ATTR_VISIBLE, FALSE);
						return -1;
					}
				}
			}
			while((inbreRetray <5) && (iFlagRtray ==1));

			Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_CMD_TEST_Bouton1,i*iNbreBouton+2), NULL, NULL,NULL, 3);


		}
	}
	else
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(IHM_BTN_MSG_POPUP_3));

	ResetTextBox (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_Test_Bouton, "");
	SetCtrlAttribute (gSlot[nItfe].ihmSlot.panelMain, PNL_MAIN_Test_Bouton, ATTR_VISIBLE, FALSE);


	return Status;*/
}

// ==============================================================================
// FONCTION :		FCT_Config_IR
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			25/09/2020
//  AUTEUR :		CH_BK
//  DESCRIPTION :   configuration IR
// ==============================================================================

int FCT_Config_IR (int nItfe, char	*chMessageErreur )
{
	/*

	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	int Status = 0;
	char cmd[1024]= {"\0"};
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_CMD_Config_IR,0), NULL, NULL,NULL, 3);


		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_Configuration_IR_KO ));
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));

	return Status;*/
}

// ==============================================================================
// FONCTION :		FCT_Test_IR
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			25/09/2020
//  AUTEUR :		CH_BK
//  DESCRIPTION :   Tester IR
// ==============================================================================

int FCT_Test_IR (int nItfe, char	*chMessageErreur )
{
	/*
		T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
		char Response [2000]="";
		int Status = 0;
		int erreur = 0;
		T_TAB_CMD cmdOut;
		char cmd[1024]= {"\0"};
		int iFlagRtray=0,inbreRetray=0;

		do
		{
			iFlagRtray = 0;
			Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_CMD_TEST_IR,0), NULL, NULL,NULL, 3);

			FCT_Send_IR(nItfe,chMessageErreur);
			FCT_Send_IR(nItfe,chMessageErreur);
			FCT_Send_IR(nItfe,chMessageErreur);

			Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_CMD_TEST_IR,1), NULL, NULL,NULL, 3);

			inbreRetray = inbreRetray +1;
			if ( (Status != 0) )
			{
				strcpy(chMessageErreur, GET_MESSAGE(TFC_MSG_TEST_IR_KO ) );
				Sleep(2000);
				iFlagRtray = 1;
				if(inbreRetray > 2)
					return -1;
			}
		}
		while((inbreRetray <3) && (iFlagRtray ==1));

		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_CMD_TEST_IR,2), NULL, NULL,NULL, 3);

		if ( (Status != 0) )
		{
			strcpy(chMessageErreur, GET_MESSAGE(TFC_MSG_TEST_IR_KO ) );
			return -1;
		}
		return Status;*/
}

// ==============================================================================
// FONCTION :		FCT_Send_IR
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			25/09/2020
//  AUTEUR :		CH_BK
//  DESCRIPTION :   Tester IR
// ==============================================================================

int FCT_Send_IR (int nItfe, char	*chMessageErreur )
{
	/*
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	SOCKET sock = 0;
	NETWORKRECV *stat;
	void *result;
	int  status = 0;


	status = ConnectIRTransServer ("localhost",&sock);

	status = SendRemoteCommand (sock, VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_Nom_Produit,0),"Zero",0,0,0);
	DisconnectIRTransServer (sock);
	*/
	return 0;
}
// ==============================================================================
// FONCTION :		FCT_reboot
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			24/06/2020
//  AUTEUR :		CH_BK
//  DESCRIPTION :   configuration Bluetooth
// ==============================================================================

int FCT_reboot (int nItfe, char	*chMessageErreur )
{

	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	int Status = 0;
	char cmd[1024]= {"\0"};
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,"[export PS1=#\n{Pass:#}][killall telnetd\n{Pass:#}][telnetd -l /bin#telnetd -l /bin/sh  killall udhcpc\n{Pass:#}][reboot\n{Pass:}]", NULL, NULL,NULL, 3);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"Erreur reboot");
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));

	return Status;
}


// ==============================================================================
// FONCTION :		FCT_Mesure_Wifi_2G
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			27/10/2019
//  AUTEUR :		FZI
//  DESCRIPTION :   Mesure wifi  sur un nombre definie d'antenne 2G
// ==============================================================================

int FCT_Mesure_Wifi_2G (int nItfe, char	*chMessageErreur )
{

	/*T_VARIABLES	 *ptrVariablesConf = &gSlot[nItfe].variablesConf;
	T_VARIABLES	 *ptrVariablesConfPoste = &gSlot[nItfe].variablesConfPoste;
	T_MESURES    *ptrMesures = &(gSlot[nItfe].mesures);
	ViReal64     result[100];
	ViInt32      count;
	ViStatus     error;
	ViChar       sensorName[256], sensorType[256], sensorSN[256];
	ViBoolean   measComplete = VI_FALSE;

	double      measValue = 0;

	char        cmd[TAILLE_MOY]= {"\0"};
	char        chResultatMesure[2];
	char        chTemoffset[TAILLE_MIN] = "";
	char        Temp[TAILLE_MIN] = "";
	char        chTemp1[TAILLE_MIN] = "";
	char        chTableauMesure[4][3] = {"0"};
	char        Tableau_num_antennes[4][3] = {"0"};
	char        NumPortSwitch[4][3] = {"0"};

	int         Status = 0;
	int         i = 0;
	int         iNbreAntenne = 0;
	int         iNbreOffset  = 0;
	int         idureeMesure = 0;
	int			VAR_LOCALE;
	int         inbreRetray = 0;
	int         iFlagRtray  = 0;
	int			iFlagRtraycmd = 0;
	int         inbreRetraycmd = 0 ;

	//Activation Antenne0 2G
	//=========================

	if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_Nombre_Antenne_2G,0) > 0)
	{
		iNbreAntenne = VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_Nombre_Antenne_2G,0);


		for (i = 0; i < iNbreAntenne; i++)
		{
			measValue = 0;
			strcpy(Temp,"");
			strcpy(chTemoffset,"");
			strcpy(chTemp1,"");
			iFlagRtray = 0;
			inbreRetray = 0;

			strcpy(Tableau_num_antennes[i],VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_Numero_Antennes_2G,i));
			sprintf(cmd,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_CMD_ACTIVE_ANNT_2G,0),Tableau_num_antennes[i],gnCanal2G);



			//===============================================================================================================
			// Swicth Port
			//===============================================================================================================

			if ((VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_FLAG_SWITCH,0)))
			{


				if (gSlot[nItfe].BNFTnteg.gFlagSP8T)
				{

					if (VAR_NB_VAL(ptrVariablesConf,VAR_CONF_ID_Numero_Switch_2G) != iNbreAntenne)
					{
						strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_Nbre_NUM_SWITCH_2G) );
						return -1;
					}
					strcpy(NumPortSwitch[i],VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_Numero_Switch_2G,i));
					Status = FCT_Switch_SP8T (nItfe, chMessageErreur,NumPortSwitch[i]);

				}

				if (Status<0)
				{
					return -1;
				}

			}
			//===============================================================================================================
			//Retry en cas de fail de la commande d'activation
			//===============================================
			inbreRetraycmd = 0;
			do
			{
				iFlagRtraycmd = 0;
				Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,cmd, NULL, NULL,NULL, 5);

				inbreRetraycmd = inbreRetraycmd +1;
				if ( (Status != 0) )
				{
					strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_ACTIVATION_2G));
					Sleep(2000);
					iFlagRtraycmd = 1;
					if(inbreRetraycmd > 2)
						return -1;
				}
			}
			while((inbreRetraycmd <3) && (iFlagRtraycmd ==1));


			Delay (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_Delay_2G,0));

			//Recupération Mesures via powermetter
			//=====================================

			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "============> Debut Analyse powermetter");
			//strcpy(chTableauMesure[i],VAR_GET_STRING(ptrVariablesConfPoste,VAR_LOCALE,i));
			do
			{
				iFlagRtray = 0;

				if(strcmp(gSlot[nItfe].BNFTnteg.gPwrmetterType,"ETH") ==0)
				{
					if(i<1)
						error = rspwrmeter_Autoset (gSlot[nItfe].g_Session, 1);

					error = rspwrmeter_InitiateAllAndWait (gSlot[nItfe].g_Session, 5000);//commencer les mesures et attndre la fin des mesures

					error = rspwrmeter_FetchMeasurement (gSlot[nItfe].g_Session, 1, 100, result, &count);//Lecture des messures

					if (error != 0)
					{
						strcpy(chMessageErreur,"Erreur Configuration powermetter");
						return -1;


					}

					if (count > 0)
					{
						measValue = 10 * log(fabs(result[0])) / log(10.0) + 30.0; //Watt to dBm
						sprintf(chTemoffset,"------------> Mesure 2G Sans offset = %f",measValue);
						measValue = measValue + atoi(Pathloss_2G[i]);

					}
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "====================== Détail Mesures ==================================");
					sprintf(Temp,"------------> Mesure 2G Antenne %d = %f",i,measValue);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Temp);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, chTemoffset);
					sprintf(chTemp1,"------------> Offset appliqué = %s",Pathloss_2G[i]);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, chTemp1);
					FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "========================================================================\n");


				}
				else if(strcmp(gSlot[nItfe].BNFTnteg.gPwrmetterType,"USB") ==0)
				{


					error = rsnrpz_GetSensorInfo(gSlot[nItfe].g_Session, 1, sensorName, sensorType, sensorSN);
					error = rsnrpz_chan_mode(gSlot[nItfe].g_Session, 1, RSNRPZ_SENSOR_MODE_TIMESLOT); //timeslot mode
					error = rsnrpz_chan_setCorrectionFrequency(gSlot[nItfe].g_Session, 1, 100E6); //correction frequency 100MHz
					error = rsnrpz_trigger_setSource(gSlot[nItfe].g_Session, 1, RSNRPZ_TRIGGER_SOURCE_IMMEDIATE); //trigger immediate
					error = rsnrpz_tslot_configureTimeSlot(gSlot[nItfe].g_Session, 1, 1, 577E-6); //timeslot count and width
					error = rsnrpz_timing_setTimingExcludeStop(gSlot[nItfe].g_Session, 1, 3E-6); //exclude stop time
					error = rsnrpz_trigger_setLevel(gSlot[nItfe].g_Session, 1, pow(10, -30.0 / 10.0) / 1000.0); //trigger level in Watts, calculate -30dBm to Watts
					error = rsnrpz_avg_configureAvgManual(gSlot[nItfe].g_Session, 1, 2); //average count 2 samples   */

	/*
						if (error != 0)
						{
							strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_CONFIGURATION_POWERMETER));
							return -1;


						}

						rsnrpz_chans_initiate(gSlot[nItfe].g_Session);

						//wait until the measurement is ready
						do
						{
							rsnrpz_chan_isMeasurementComplete(gSlot[nItfe].g_Session, 1, &measComplete);
						}
						while (!measComplete);

						if (measComplete)
						{
							rsnrpz_meass_fetchBufferMeasurement(gSlot[nItfe].g_Session, 1, 100, result, &count); //fetch the results in Watts
							if (count > 0)
							{
								measValue = 10 * log(fabs(result[0])) / log(10.0) + 30.0; //Watt to dBm
								sprintf(chTemoffset,"------------> Mesure 2G Sans offset = %f",measValue);
								measValue = measValue + atoi(Pathloss_2G[i]);

							}
							FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "====================== Détail Mesures ==================================");
							sprintf(Temp,"------------> Mesure 2G Antenne %d = %f",i,measValue);
							FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Temp);
							FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, chTemoffset);
							sprintf(chTemp1,"------------> Offset appliqué = %s",Pathloss_2G[i]);
							FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, chTemp1);
							FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "========================================================================\n");

						}


					}

					// Vérification Mesures
					// --------------------
					if ( MES_Capturer ( ptrMesures, MES_TYPE_ANTENNE0_2G+i, chResultatMesure, measValue, idureeMesure ) != 0 )
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_POPUP_ERREUR|IHM_MODE_TRACE_TXTBOX, MES_NON_DEFINIE, gMesuresBNFT[MES_TYPE_ANTENNE0_2G+i].nom);
						//errChk (-1);
						strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_CONFIGURATION_BDD));
						return -1;
					}
					inbreRetray = inbreRetray +1;
					if ( strcmp( chResultatMesure, MES_STATUS_OK) != 0 )
					{
						sprintf(chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_MESURE_2G), i);
						Sleep(2000);
						iFlagRtray = 1;
						if(inbreRetray > 4)
							return -1;
					}

				}
				while((inbreRetray <5) && (iFlagRtray ==1));
			}


		}
		else
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_NBRE_ANTENNES_2G));



		return Status;*/
}

// ==============================================================================
// FONCTION :		FCT_Mesure_Wifi_5G
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			27/10/2019
//  AUTEUR :		FZI
//  DESCRIPTION :   Mesure wifi  sur un nombre definie d'antenne 5G
// ==============================================================================

int FCT_Mesure_Wifi_5G (int nItfe, char	*chMessageErreur )
{
	/*
		T_VARIABLES	  *ptrVariablesConf = &gSlot[nItfe].variablesConf;
		T_VARIABLES	  *ptrVariablesConfPoste = &gSlot[nItfe].variablesConfPoste;
		ViChar        sensorName[256], sensorType[256], sensorSN[256];
		T_MESURES     *ptrMesures = &(gSlot[nItfe].mesures);
		ViBoolean     measComplete = VI_FALSE;
		ViReal64      result[100];
		ViInt32       count;
		ViStatus      error;
		double        measValue;

		char          cmd[TAILLE_MOY]= {"\0"};
		char          chResultatMesure[2];
		char          chTemoffset[TAILLE_MIN] = "";
		char          Temp[TAILLE_MIN] = "";
		char          chTemp1[TAILLE_MIN] = "";
		char          Tableau_num_antennes[16][3] = {"0"};
		char     	  NumPortSwitch[16][4] = {"0"};
		char          NomProduit[TAILLE_MIN]="";
		char          cmdBT[TAILLE_MOY]= {"\0"};

		int           inbreRetray = 0;
		int           iFlagRtray  =0;
		int           inbreRetraycmd = 0 ;
		int           iFlagRtraycmd =0 ;
		int           idureeMesure = 0;
		int           Status = 0;
		int           i = 0;
		int           iNbreAntenne = 0;

		//Activation Antenne0 5G
		//=========================

		 strcpy(NomProduit,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_Nom_Produit,0));

		if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_Nombre_Antenne_5G,0) > 0)
		{

			iNbreAntenne = VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_Nombre_Antenne_5G,0);



			for (i = 0; i < iNbreAntenne; i++)
			{
				measValue = 0;
				strcpy(Temp,"");
				strcpy(chTemoffset,"");
				strcpy(chTemp1,"");
				iFlagRtray = 0;
				inbreRetray = 0;

				strcpy(Tableau_num_antennes[i],VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_Numero_Antennes_5G,i));
				sprintf(cmd,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_CMD_ACTIVE_ANNT_5G,0),Tableau_num_antennes[i],gnCanal5G);

				if (strcmp(NomProduit,"BTELECOM") == 0 )
				{
					sprintf(cmdBT,"[bcm_start_tx_one_antenna_5g.sh -a %s -c %d -pwr 15 > /tmp/log.log 2>&1 >/dev/null &{Pass:null}]",Tableau_num_antennes[i],gnCanal5G);
					Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,cmdBT, NULL, NULL,NULL, 5);
				}


				//===============================================================================================================
				// Swicth Port
				//===============================================================================================================

				if ((VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_FLAG_SWITCH,0)))
				{


					if (gSlot[nItfe].BNFTnteg.gFlagSP8T)
					{

						if (VAR_NB_VAL(ptrVariablesConf,VAR_CONF_ID_Numero_Switch_5G) != iNbreAntenne)
						{
							strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_Nbre_NUM_SWITCH_5G));
							return -1;
						}
						strcpy(NumPortSwitch[i],VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_Numero_Switch_5G,i));
						Status = FCT_Switch_SP8T (nItfe, chMessageErreur,NumPortSwitch[i]);

					}

					if (Status<0)
					{
						return -1;
					}

				}
				//Retry en cas de fail de la commande d'activation
				//===============================================
					inbreRetraycmd = 0;
					do
					{
						iFlagRtraycmd = 0;
						Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,cmd, NULL, NULL,NULL, 5);

						inbreRetraycmd = inbreRetraycmd +1;
						if ( (Status != 0) )
						{
							strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_ACTIVATION_5G));
							Sleep(2000);
							iFlagRtraycmd = 1;
							if(inbreRetraycmd > 2)
								return -1;
						}
					}
					while((inbreRetraycmd <3) && (iFlagRtraycmd ==1));

				Delay (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_Delay_5G,0));

				//Recupération Mesures via powermetter
				//=====================================
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "============> Debut Analyse powermetter");
				do
				{
					iFlagRtray = 0;
					if(strcmp(gSlot[nItfe].BNFTnteg.gPwrmetterType,"ETH") ==0)
					{

						if(i<1)
							error = rspwrmeter_Autoset (gSlot[nItfe].g_Session, 1);

						error = rspwrmeter_InitiateAllAndWait (gSlot[nItfe].g_Session, 5000);//commencer les mesures et attndre la fin des mesures

						error = rspwrmeter_FetchMeasurement (gSlot[nItfe].g_Session, 1, 100, result, &count);//Lecture des messures

						if (error != 0)
						{
							strcpy(chMessageErreur,"Erreur Configuration powermetter");
							return -1;


						}


						if (count > 0)
						{
							measValue = 10 * log(fabs(result[0])) / log(10.0) + 30.0; //Watt to dBm
							sprintf(chTemoffset,"------------> Mesure 5G Sans offset = %f",measValue);
							measValue = measValue+ atoi(Pathloss_5G[i]);

						}

						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "====================== Détail Mesures ==================================");
						sprintf(Temp,"------------> Mesure 5G Antenne %d = %f",i,measValue);
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Temp);
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, chTemoffset);
						sprintf(chTemp1,"------------> Offset appliqué = %s",Pathloss_5G[i]);
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, chTemp1);
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "========================================================================\n");

					}
					else if(strcmp(gSlot[nItfe].BNFTnteg.gPwrmetterType,"USB") ==0)
					{

						error = rsnrpz_GetSensorInfo(gSlot[nItfe].g_Session, 1, sensorName, sensorType, sensorSN);
						error = rsnrpz_chan_mode(gSlot[nItfe].g_Session, 1, RSNRPZ_SENSOR_MODE_TIMESLOT); //timeslot mode
						error = rsnrpz_chan_setCorrectionFrequency(gSlot[nItfe].g_Session, 1, 100E6); //correction frequency 100MHz
						error = rsnrpz_trigger_setSource(gSlot[nItfe].g_Session, 1, RSNRPZ_TRIGGER_SOURCE_IMMEDIATE); //trigger immediate
						error = rsnrpz_tslot_configureTimeSlot(gSlot[nItfe].g_Session, 1, 1, 577E-6); //timeslot count and width
						error = rsnrpz_timing_setTimingExcludeStop(gSlot[nItfe].g_Session, 1, 3E-6); //exclude stop time
						error = rsnrpz_trigger_setLevel(gSlot[nItfe].g_Session, 1, pow(10, -30.0 / 10.0) / 1000.0); //trigger level in Watts, calculate -30dBm to Watts
						error = rsnrpz_avg_configureAvgManual(gSlot[nItfe].g_Session, 1, 2); //average count 2 samples   */

	/*
						if (error != 0)
						{
							strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_CONFIGURATION_POWERMETER));
							return -1;


						}

						rsnrpz_chans_initiate(gSlot[nItfe].g_Session);

						//wait until the measurement is ready
						do
						{
							rsnrpz_chan_isMeasurementComplete(gSlot[nItfe].g_Session, 1, &measComplete);
						}
						while (!measComplete);

						if (measComplete)
						{
							rsnrpz_meass_fetchBufferMeasurement(gSlot[nItfe].g_Session, 1, 100, result, &count); //fetch the results in Watts
							if (count > 0)
							{
								measValue = 10 * log(fabs(result[0])) / log(10.0) + 30.0; //Watt to dBm
								sprintf(chTemoffset,"------------> Mesure 5G Sans offset = %f",measValue);
								measValue = measValue + atoi(Pathloss_5G[i]);

							}
							FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "====================== Détail Mesures ==================================");
							sprintf(Temp,"------------> Mesure 5G Antenne %d = %f",i,measValue);
							FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Temp);
							FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, chTemoffset);
							sprintf(chTemp1,"------------> Offset appliqué = %s",Pathloss_5G[i]);
							FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, chTemp1);
							FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "========================================================================\n");
						}


					}



					// Vérification Mesures
					// --------------------
					if ( MES_Capturer ( ptrMesures, MES_TYPE_ANTENNE0_5G+i, chResultatMesure, measValue, idureeMesure ) != 0 )
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_POPUP_ERREUR|IHM_MODE_TRACE_TXTBOX, MES_NON_DEFINIE, gMesuresBNFT[MES_TYPE_ANTENNE0_5G+i].nom);
						strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_CONFIGURATION_BDD));
						return -1;
					}
					inbreRetray = inbreRetray +1;
					if ( strcmp( chResultatMesure, MES_STATUS_OK) != 0 )
					{
						sprintf(chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_MESURE_5G), i);
						Sleep(2000);
						iFlagRtray = 1;
						if(inbreRetray > 4)
							return -1;
					}
				}
				while((inbreRetray <5) && (iFlagRtray ==1));
			}




		}
		else
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_NBRE_ANTENNES_5G));




		return 0;*/
}

// ==============================================================================
// FONCTION :		FCT_Mesure_BT
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			24/06/2020
//  AUTEUR :		CH_BK
//  DESCRIPTION :   Mesure BT  sur un nombre definie d'antenne BT
// ==============================================================================

int FCT_Mesure_BT (int nItfe, char	*chMessageErreur )
{
	/*
		T_VARIABLES	 *ptrVariablesConf = &gSlot[nItfe].variablesConf;
		T_VARIABLES	 *ptrVariablesConfPoste = &gSlot[nItfe].variablesConfPoste;
		T_MESURES    *ptrMesures = &(gSlot[nItfe].mesures);
		ViChar       sensorName[256], sensorType[256], sensorSN[256];
		ViBoolean    measComplete = VI_FALSE;
		ViReal64     result[100];
		ViInt32      count;
		ViStatus     error;
		double       measValue;

		char         cmd[TAILLE_MOY]= {"\0"};
		char         chResultatMesure[2];
		char         chTemoffset[TAILLE_MIN] = "";
		char         Temp[TAILLE_MIN] = "";
		char         chTemp1[TAILLE_MIN] = "";
		char         Tableau_num_antennes[16][3] = {"0"};
		char         NumPortSwitch[16][4] = {"0"};

		int          inbreRetray = 0;
		int          iFlagRtray  =0;
		int          ant =0;
		int          Status = 0;
		int          i = 0;
		int          idureeMesure = 0;
		int          iNbreAntenne = 0;
		int           inbreRetraycmd = 0 ;
		int           iFlagRtraycmd =0 ;

		if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_Nombre_Antenne_BT,0) > 0)
		{

			iNbreAntenne = VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_Nombre_Antenne_BT,0);



			for (i = 0; i < iNbreAntenne; i++)
			{
				measValue = 0;
				strcpy(Temp,"");
				strcpy(chTemoffset,"");
				strcpy(chTemp1,"");
				iFlagRtray = 0;
				inbreRetray = 0;

				//===============================================================================================================
				// Swicth Port
				//===============================================================================================================

				if ((VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_FLAG_SWITCH,0)))
				{


					if (gSlot[nItfe].BNFTnteg.gFlagSP8T)
					{

						if (VAR_NB_VAL(ptrVariablesConf,VAR_CONF_ID_Numero_Switch_BT) != iNbreAntenne)
						{
							strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_Nbre_NUM_SWITCH_BT));
							return -1;
						}
						strcpy(NumPortSwitch[i],VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_Numero_Switch_BT,i));
						Status = FCT_Switch_SP8T (nItfe, chMessageErreur,NumPortSwitch[i]);

					}

					if (Status<0)
					{
						return -1;
					}

				}
				//Retry en cas de fail de la commande d'activation
					//===============================================
					inbreRetraycmd = 0;
					do
					{
						iFlagRtraycmd = 0;
						Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_CMD_ACTIVE_ANNT_BT,0), NULL, NULL,NULL, 5);

						inbreRetraycmd = inbreRetraycmd +1;
						if ( (Status != 0) )
						{
							strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_ACTIVATION_BT));
							Sleep(2000);
							iFlagRtraycmd = 1;
							if(inbreRetraycmd > 2)
								return -1;
						}
					}
					while((inbreRetraycmd <3) && (iFlagRtraycmd ==1));

				Delay (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_Delay_BT,0));
				//Recupération Mesures via powermetter
				//=====================================
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "============> Debut Analyse powermetter");
				do
				{
					iFlagRtray = 0;
					if(strcmp(gSlot[nItfe].BNFTnteg.gPwrmetterType,"ETH") ==0)
					{

						if(i<1)
							error = rspwrmeter_Autoset (gSlot[nItfe].g_Session, 1);

						error = rspwrmeter_InitiateAllAndWait (gSlot[nItfe].g_Session, 5000);//commencer les mesures et attndre la fin des mesures

						error = rspwrmeter_FetchMeasurement (gSlot[nItfe].g_Session, 1, 100, result, &count);//Lecture des messures

						if (error != 0)
						{
							strcpy(chMessageErreur,"Erreur Configuration powermetter");
							return -1;


						}


						if (count > 0)
						{
							measValue = 10 * log(fabs(result[0])) / log(10.0) + 30.0; //Watt to dBm
							sprintf(chTemoffset,"------------> Mesure BT Sans offset = %f",measValue);
							measValue = measValue+ atoi(Pathloss_5G[i]);

						}

						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "====================== Détail Mesures ==================================");
						sprintf(Temp,"------------> Mesure BT Antenne %d = %f",i,measValue);
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Temp);
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, chTemoffset);
						sprintf(chTemp1,"------------> Offset appliqué = %s",Pathloss_5G[i]);
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, chTemp1);
						FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "========================================================================\n");

					}
					else if(strcmp(gSlot[nItfe].BNFTnteg.gPwrmetterType,"USB") ==0)
					{

						error = rsnrpz_GetSensorInfo(gSlot[nItfe].g_Session, 1, sensorName, sensorType, sensorSN);
						error = rsnrpz_chan_mode(gSlot[nItfe].g_Session, 1, RSNRPZ_SENSOR_MODE_TIMESLOT); //timeslot mode
						error = rsnrpz_chan_setCorrectionFrequency(gSlot[nItfe].g_Session, 1, 100E6); //correction frequency 100MHz
						error = rsnrpz_trigger_setSource(gSlot[nItfe].g_Session, 1, RSNRPZ_TRIGGER_SOURCE_IMMEDIATE); //trigger immediate
						error = rsnrpz_tslot_configureTimeSlot(gSlot[nItfe].g_Session, 1, 1, 577E-6); //timeslot count and width
						error = rsnrpz_timing_setTimingExcludeStop(gSlot[nItfe].g_Session, 1, 3E-6); //exclude stop time
						error = rsnrpz_trigger_setLevel(gSlot[nItfe].g_Session, 1, pow(10, -30.0 / 10.0) / 1000.0); //trigger level in Watts, calculate -30dBm to Watts
						error = rsnrpz_avg_configureAvgManual(gSlot[nItfe].g_Session, 1, 2); //average count 2 samples   */

	/*
						if (error != 0)
						{
							strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_CONFIGURATION_POWERMETER));
							return -1;


						}

						rsnrpz_chans_initiate(gSlot[nItfe].g_Session);

						//wait until the measurement is ready
						do
						{
							rsnrpz_chan_isMeasurementComplete(gSlot[nItfe].g_Session, 1, &measComplete);
						}
						while (!measComplete);

						if (measComplete)
						{
							rsnrpz_meass_fetchBufferMeasurement(gSlot[nItfe].g_Session, 1, 100, result, &count); //fetch the results in Watts
							if (count > 0)
							{
								measValue = 10 * log(fabs(result[0])) / log(10.0) + 30.0; //Watt to dBm
								sprintf(chTemoffset,"------------> Mesure BT Sans offset = %f",measValue);
								measValue = measValue + atoi(Pathloss_BT[i]);

							}
							FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "====================== Détail Mesures ==================================");
							sprintf(Temp,"------------> Mesure BT Antenne %d = %f",i,measValue);
							FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Temp);
							FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, chTemoffset);
							sprintf(chTemp1,"------------> Offset appliqué = %s",Pathloss_BT[i]);
							FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, chTemp1);
							FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, "========================================================================\n");
						}


					}



					// Vérification Mesures
					// --------------------
					if ( MES_Capturer ( ptrMesures, MES_TYPE_ANTENNE0_BT+i, chResultatMesure, measValue, idureeMesure ) != 0 )
					{
						FCT_AfficheInfo (nItfe, IHM_MODE_POPUP_ERREUR|IHM_MODE_TRACE_TXTBOX, MES_NON_DEFINIE, gMesuresBNFT[MES_TYPE_ANTENNE0_BT+i].nom);
						strcpy(chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_CONFIGURATION_BDD));
						return -1;
					}
					inbreRetray = inbreRetray +1;
					if ( strcmp( chResultatMesure, MES_STATUS_OK) != 0 )
					{
						sprintf(chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_MESURE_BT), i);
						Sleep(2000);
						iFlagRtray = 1;
						if(inbreRetray > 4)
							return -1;
					}
				}
				while((inbreRetray <5) && (iFlagRtray ==1));
			}




		}
		else
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ERREUR_NBRE_ANTENNES_BT));




		return 0;*/
}



/*********************************************************************************************************
								Fonction Configuration Mode Pays
*********************************************************************************************************/
int FCT_ConfigMode (int nItfe, char *strErreurMessage)
{
	int				   iNumBytWritten = 0;
	//InetTelnetWrite (gSlot[nItfe].igHandleConnexion , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_CMD_Red,0), "\n", -1, &iNumBytWritten, 250);

	InetTelnetWrite (gSlot[nItfe].igHandleConnexion , "dfa", "\n", -1, &iNumBytWritten, 250);
	return 0;
}

/*********************************************************************************************************
						Fonction Configuration & Diffusion Wifi 2.4 Ghz
*********************************************************************************************************/
int FCT_ConfigSSID (int nItfe, char *strErreurMessage)
{


	return 0;
}

/*********************************************************************************************************
						Fonction Verification association avec le dongle
*********************************************************************************************************/
int FCT_VerifAssociationDongle (int nItfe, char *strErreurMessage)
{


	return 0;
}

/*********************************************************************************************************
						Fonction Recuperation RSSI Antenne Deportee
*********************************************************************************************************/
int FCT_RecupRSSI (int nItfe, char *strErreurMessage)
{


	return 0;
}


/*********************************************************************************************************
						Fonction Suspension de la Diffusion Wifi
*********************************************************************************************************/
int  FCT_SuspensionDiffusionWifi (int nItfe, char *strErreurMessage)
{


	return 0;
}

/*********************************************************************************************************
							 Fonction Extraction des commandes dans un tableau
*********************************************************************************************************/
int FCT_CmdTTExtract (char *cmdIn, T_TAB_CMD *cmdOut)
{
	int        i=0;
	int        etat=0;

	char       *ptrCmdIn=cmdIn;
	char       rep[TAILLE_MIN]="";

	// ==============================
	// = RAZ du tableau de commande =
	// ==============================
	cmdOut->nbCmd=0;
	for (i=0; i<10; i++)
	{
		cmdOut->cmd[i].nbPass = 0;
		cmdOut->cmd[i].nbFail = 0;
		cmdOut->cmd[i].nbInfo = 0;
		cmdOut->cmd[i].nbTags = 0;
		cmdOut->cmd[i].cmd[0] = '0';
	}

	// ============================
	// = Extraction des commandes =
	// ============================
	do
	{
		switch (etat)
		{
				// -----------------------------
				// - Attente début de commande -
				// -----------------------------
			case 0:
			default:
				while( ptrCmdIn[0] != '[' && ptrCmdIn[0] != '\0' ) ptrCmdIn++;
				if ( ptrCmdIn[0] == '[' )
					etat = 1;
				break;

				// --------------------------
				// - Extraction de commande -
				// --------------------------
			case 1:
				// Suppression de la balise de début de champ
				ptrCmdIn++;
				i = 0;
				// Enregistrement de la commande tant que les balises fin de commande ou début réponse et le fin de chaine ne sont pas atteint
				while( ptrCmdIn[0] != ']' && ptrCmdIn[0] != '{' && ptrCmdIn[0] != '\0' )
				{
					cmdOut->cmd[cmdOut->nbCmd].cmd[i++] = ptrCmdIn[0];
					cmdOut->cmd[cmdOut->nbCmd].cmd[i] = '\0';
					ptrCmdIn++;
				}
				if (ptrCmdIn[0] == ']')
				{
					etat = 0;  // on passe à la commande suivante
				}
				else if (ptrCmdIn[0] == '{')
				{
					etat = 3;   // on extrait les réponses de la commande
				}
				if (ptrCmdIn[0] != '\0')
				{
					// Suppression des espaces et tabulations en début et fin de chaine
					RemoveSurroundingWhiteSpace (cmdOut->cmd[cmdOut->nbCmd].cmd);
					// On ajoute le retour charriot à la commande
					//strcat (cmdOut->cmd[cmdOut->nbCmd].cmd, "\r"); ///////////////////////   RETOUR CHARRIOT ELIMINE MARWA
					// On incrémente le nombre de commande
					cmdOut->nbCmd++;
				}
				break;

				// ----------------------------
				// - Attente début de réponse -
				// ----------------------------
			case 2:
				// Attente début réponse ou fin commande
				while( ptrCmdIn[0] != ']' && ptrCmdIn[0] != '{' && ptrCmdIn[0] != '\0' ) ptrCmdIn++;
				if (ptrCmdIn[0] == ']')
					etat = 0;  	// on passe à la commande suivante
				else if (ptrCmdIn[0] == '{')
					etat = 3;	   // on extrait les réponses de la commande
				break;

				// ----------------------------
				// - Extraction d'une réponse -
				// ----------------------------
			case 3:
				// Suppression de la balise de début de champ
				ptrCmdIn++;
				i = 0;
				// Enregistrement de la commande tant que la balise fin de réponse et le fin de chaine ne sont pas atteint
				while( ptrCmdIn[0] != '}' && ptrCmdIn[0] != '\0' )
				{
					rep[i++] = ptrCmdIn[0];
					rep[i] = '\0';
					ptrCmdIn++;
				}
				if (ptrCmdIn[0] == '}')
				{
					// Traitement de la commande
					if (strstr(rep,"Pass:") != NULL)
					{
						// Extraction d'une réponse OK
						strcpy (cmdOut->cmd[cmdOut->nbCmd-1].pass[cmdOut->cmd[cmdOut->nbCmd-1].nbPass], rep+strlen("Pass:"));
						// Suppression des espaces et tabulations en début et fin de chaine
						RemoveSurroundingWhiteSpace (cmdOut->cmd[cmdOut->nbCmd-1].pass[cmdOut->cmd[cmdOut->nbCmd-1].nbPass]);
						cmdOut->cmd[cmdOut->nbCmd-1].nbPass++;
					}
					else if (strstr(rep,"Fail:") != NULL)
					{
						// Extraction d'une réponse KO
						strcpy (cmdOut->cmd[cmdOut->nbCmd-1].fail[cmdOut->cmd[cmdOut->nbCmd-1].nbFail], rep+strlen("Fail:"));
						// Suppression des espaces et tabulations en début et fin de chaine
						RemoveSurroundingWhiteSpace (cmdOut->cmd[cmdOut->nbCmd-1].fail[cmdOut->cmd[cmdOut->nbCmd-1].nbFail]);
						cmdOut->cmd[cmdOut->nbCmd-1].nbFail++;
					}
					else if (strstr(rep,"Tags:") != NULL)
					{
						// Extraction d'une réponse KO
						strcpy (cmdOut->cmd[cmdOut->nbCmd-1].Tags[cmdOut->cmd[cmdOut->nbCmd-1].nbTags], rep+strlen("Tags:"));
						// Suppression des espaces et tabulations en début et fin de chaine
						RemoveSurroundingWhiteSpace (cmdOut->cmd[cmdOut->nbCmd-1].Tags[cmdOut->cmd[cmdOut->nbCmd-1].nbTags]);
						cmdOut->cmd[cmdOut->nbCmd-1].nbTags++;
					}
					else
					{
						// Extraction d'une réponse Info
						strcpy (cmdOut->cmd[cmdOut->nbCmd-1].info[cmdOut->cmd[cmdOut->nbCmd-1].nbInfo], rep);
						cmdOut->cmd[cmdOut->nbCmd-1].nbInfo++;
					}
					// Recherche réponse suivante
					etat = 2;
				}
				break;
		}
	}
	while( ptrCmdIn[0] != '\0' );

	return 0;
}

/*********************************************************************************************************
						Fonction Exécution des commandes à partir un tableau
					   ======================================================
							NB :  La commande doit toujours avoir un TAG
*********************************************************************************************************/
int FCT_CmdExecution (int nItfe, int iHandleTelnet, T_CMD *cmdTT, char ***info, int *nbInfo, int timeout)
{
	int                 status=-1;
	int					i=0;
	short               erreur = 0;
	int                 error = 0;
	long                codeErreur = 0;
	char                chMessErreur[1000] = {"\0"};
	char                chBufferLu[TAILLE_MAX] = {"\0"};
	char                chBufferLuTmp[TAILLE_MAX] = {"\0"};
	long                countDeb=0.0;
	int                 nbRetour=0;

	int 				ByteWritten=0;
	int 				ByteRead=0;
	unsigned long   	DimBuf=0;
	int                 flagPatternFound=0;
	int					flagFailFound=0;
	int					flagPassFound=0;
	int 				flagInfoFound=0;
	int 				flagTagsFound=0;
	char                chMasque[512] = {"\0"};
	char                chVal[512] = {"\0"};
	char                chPattern[512] = {"\0"};
	char 				sObservation[255]="";
	char                *ptrPattern = NULL;
	int                 sizePattern=0;


	ClearBufferTelnet(iHandleTelnet);
	Delay(0.3);

	// ===============================
	// = RAZ des variables de retour =
	// ===============================
	if (nbInfo != NULL)
	{
		*nbInfo = 0;
		*info = NULL;
	}
	// ===========================
	// = Envoi de la commande TT =
	// ===========================
	FIL2LO_EcritTrace (TRUE, nItfe, cmdTT->cmd);
	status = InetTelnetWrite (iHandleTelnet, cmdTT->cmd, "\r\n", -1, &ByteWritten, timeout);

	// ===============================
	// = Verification du retour Tag =
	// ===============================
	countDeb = GetTickCount();
	for ( i=0 ; i<cmdTT->nbTags ; i++ )
	{
		flagTagsFound= FALSE;
		do
		{
			// Temporisation de 10ms
			Sleep (10);

			// Lecture du port Telnet
			memset (chBufferLuTmp, '\0', (sizeof(unsigned char) * TAILLE_MAX));
			status = InetTelnetRead (iHandleTelnet, chBufferLuTmp, sizeof (chBufferLuTmp) - 1, &ByteRead, timeout);
			FIL2LO_EcritTrace (TRUE, nItfe, chBufferLuTmp);

			// Concaténation des données reçues dans le buffer de réception, si le buffer n'est pas plein
			if ( (strlen(chBufferLu) + strlen(chBufferLuTmp)) < TAILLE_MAX )
				strcat (chBufferLu, chBufferLuTmp);

			// On vérifie si le retour pass attendu a été envoyé par le GTW
			if (strstr (chBufferLu, cmdTT->Tags[i]) != NULL)
			{
				sprintf(sObservation, " %s  => Tag trouvé ",  cmdTT->Tags[i]);
				FIL2LO_EcritTrace (TRUE, nItfe, sObservation);
				flagTagsFound= TRUE;
			}
		}
		while ( ((GetTickCount()-countDeb) < timeout) && (flagTagsFound == FALSE) );
	}

	// ===============================
	// = Verification du retour Fail =
	// ===============================
	if ( flagTagsFound == TRUE )
	{
		flagFailFound =  FALSE;
		for ( i=0 ; i<cmdTT->nbFail ; i++ )
		{
			// On vérifie si le retour fail attendu a été envoyé par le STB
			// Un seul FAIL suffit
			if (strstr (chBufferLu, cmdTT->fail[i]) != NULL)
			{
				sprintf(sObservation, " %s  => Pattern Fail trouvé ",  cmdTT->fail[i]);
				FIL2LO_EcritTrace (TRUE, nItfe, sObservation);
				flagFailFound = TRUE;
				break;
			}
		}
	}
	else
		errChk (-2);

	// ===============================
	// = Verification du retour Pass =
	// ===============================
	if ( (flagFailFound != TRUE) && (flagTagsFound == TRUE) )
	{
		flagPassFound = FALSE;

		if (cmdTT->nbPass==0)
			flagPassFound = TRUE;
		else
		{
			for ( i=0 ; i<cmdTT->nbPass ; i++ )
			{
				// On vérifie si le retour pass attendu a été envoyé par la carte
				// On doit chercher touuuuuuuuuut les PASS
				if (strstr (chBufferLu, cmdTT->pass[i]) != NULL)
				{
					sprintf(sObservation, " %s => Pattern Pass trouvé ",  cmdTT->pass[i]);
					FIL2LO_EcritTrace (TRUE, nItfe, sObservation);
					flagPassFound = TRUE;
					//break;
				}
				else
				{
					flagPassFound = FALSE;
					break;
				}
			}
		}
	}
	else
		errChk (-3);

	// ========================
	// = Extraction des infos =
	// ========================
	if ( flagTagsFound == TRUE )
	{
		flagInfoFound = FALSE;
		if (nbInfo != NULL)
		{
			*nbInfo = 0;
			*info = NULL;

			for ( i=0 ; i<cmdTT->nbInfo ; i++ )
			{
				// On vérifie le format du pattern à rechercher
				if ( strchr (cmdTT->info[i], '%') != NULL )
				{
					// Remplace le '%' par '%s' dans la chaine de recherche
					sizePattern = strchr (cmdTT->info[i], '%') - cmdTT->info[i];
					strncpy (chPattern, cmdTT->info[i], sizePattern);
					chPattern[sizePattern-1] = '\0';
					strcpy (chMasque, chPattern);
					strcat (chMasque, "%s");
					strcat (chMasque, strchr (cmdTT->info[i], '%')+1);

					// Recherche de l'index de la chaine à extraire
					ptrPattern = strstr (chBufferLu, chPattern);

					if (ptrPattern != NULL)
					{
						// Extraction de la chaine
						sscanf (ptrPattern, chMasque, chVal);

						// Si une chaine est extraite : enregistre cette chaine dans le buffer de retour
						if ( strlen (chVal) > 0 )
						{
							// On incrémente le nombre d'infos extrait
							(*nbInfo)++;

							// Allocation dynamique de mémoire pour le stockage des infos extraits
							(*info) = (char**) realloc( *info, sizeof(char*) * (*nbInfo) );
							(*info)[(*nbInfo)-1] = (char*) malloc( sizeof(char) * 512 );

							// Enregistrement de l'info extrait
							strcpy ( (*info)[(*nbInfo)-1], chVal);
							FIL2LO_EcritTrace (TRUE, nItfe, chVal);
						}
						else
						{
							FIL2LO_EcritTrace (TRUE, nItfe, "Problème d'extraction d'info : aucune chaine extraite");
							errChk (-4);
						}
					}
					else
					{
						FIL2LO_EcritTrace (TRUE, nItfe, "Problème d'extraction d'info : pattern de recherche non trouvé");
						errChk (-4);
					}
				}
				else
				{
					FIL2LO_EcritTrace (TRUE, nItfe, "Problème d'extraction d'info : format du pattern de recherche incorrect");
					errChk (-4);
				}
			}
		}
	}

	if ( flagPassFound == FALSE )
		errChk (-4);

Error:
	if(error)
	{
		if (error == -2)
			FIL2LO_EcritTrace (TRUE, nItfe, " ERREUR RETOUR TAG ! ");
		else if (error == -3)
			FIL2LO_EcritTrace (TRUE, nItfe, " RETOUR FAIL ! ");
		else if (error == -4)
			FIL2LO_EcritTrace (TRUE, nItfe, " ERREUR RETOUR PASS ! ");
		else
			FIL2LO_EcritTrace (TRUE, nItfe, " ERREUR RETOUR TAG ! ");

		return error;
	}
	return 1;
}




// ==============================================================================
int FCT_EnvoieLogBdd( int nItfe)
{
	//long            	iTime = GetTickCount();
	//int  				error = 0;
	//__int64 			iIdTrace;
	char        		strErreurMessage[1024] = {'\0'};
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	//long				iDuree;
	//FILE				*file_handle;
//	char    			chNomFichier[MAX_PATHNAME_LEN+1] = {"\0"};
	//char    			chMessage[100] = {"\0"};
	//int 				iSize;
	char 				chBuffer[3097152] = {"\0"};

	// Envoie du log en Bdd - Seulement si on a déjà effectué le start !
	// -----------------------------------------------------------------
	if ( ptrVariablesTraca->iStartOK != 1 )
		return 0;
	sprintf ( chBuffer, "%s", gSlot[nItfe].stbLog );
	SCPROD_EnregistrementLog (nItfe, &gTcomBase, chBuffer , strErreurMessage) ;


	// On log la durée d'envoie du log dans un .txt
	// --------------------------------------------
	/*
	iDuree = (GetTickCount()-iTime);
	sprintf ( chNomFichier, "TempsEnvoieTrace_%i.txt", nItfe);
	sprintf ( chMessage, "SnPfin: %s - TempsEnvoieTrace: %dms\n", ptrVariablesTraca->PfinSfcSAPME, iDuree);
	file_handle = fopen (chNomFichier, "a");

	// Si fichier > 10Ko on le reset 100000Bytes
	// ------------------------------------------
	GetFileSize (chNomFichier, &iSize);
	if ( iSize > 10000 )
	{
		fclose (file_handle);
		file_handle = fopen (chNomFichier, "w");
	}

	fwrite(chMessage, 1,strlen(chMessage) , file_handle);
	fclose (file_handle);  */

	/*
	Error:

		if (error)
		{
			return -1;
		}
	*/
	return 0;
}

// ==============================================================================
int FCT_CmdComExecutionV5 (int nItfe, int AffichageTrace, char *chCmdTT, char ***info, int *nbInfo, char *chTrace, int timeout)
{
	short           erreur = 0;
	int             status = -1;
	int				i = 0,j = 0;
	int             idPort = gSlot[nItfe].comDecodeur.iHandle;
	int             error = 0;
	int             flagPatternPassFound = FALSE;
	int             flagPatternFailFound = FALSE;
	int             sizePattern;
	int             nValTempo;
	int             nTypeMsg;
	int             idxCmd = 0;
	int 			iTailleBufferLu;
	long            codeErreur = 0;
	unsigned long   countDeb;
	unsigned long   nbRetour;
	unsigned long   DimBuf;
	char            chMessErreur[TAILLE_MAX] = {"\0"};
	char            chBufferLu[TAILLE_MAX] = {"\0"};
	char            chBufferLuTmp[TAILLE_MAX] = {"\0"};
	char            chVal[FCT_RECUP_INFO_TAILLE_MAX] = {"\0"};
	char            chPattern[512] = {"\0"};
	char            chCmd[TAILLE_MIN] = {"\0"};
	char            *ptrCmd = NULL;
	char            chDernierCaractCle[TAILLE_MIN+1] = {'\0'};
	char			*ptrPassMultiple = NULL;
	char			chTampon[TAILLE_MIN] = {'\0'} ;
	T_TAB_CMD       tabCmdTT;
	int iNumBytWritten=0;


	// ===============================
	// = RAZ des variables de retour =
	// ===============================
	if (nbInfo != NULL)
	{
		*nbInfo = 0;
		*info = NULL;
	}

	// ==========================================
	// = Extraction des commandes TT à exécuter =
	// ==========================================
	errChk (FCT_CmdComExtract (chCmdTT, &tabCmdTT));

	// ==============================
	// = Exécution des commandes TT =
	// ==============================
	for ( idxCmd=0 ; idxCmd<tabCmdTT.nbCmd ; idxCmd++ )
	{

		// Mise en casse inferieur de la commande
		// --------------------------------------
		i = 0;
		while (tabCmdTT.cmd[idxCmd].cmd[i] != '\0')
		{
			chCmd[i] = tolower (tabCmdTT.cmd[idxCmd].cmd[i]);
			i++;
		}
		chCmd[i] = '\0';

		// Mise à jour du Time Out si définis par la commande
		// --------------------------------------------------
		if (tabCmdTT.cmd[idxCmd].nTimeOut != -1)
			timeout = tabCmdTT.cmd[idxCmd].nTimeOut;

		// ==================================================================================
		// = GESTION DES COMMANDES TT                                                       =
		// ==================================================================================

		// =============================================
		// = Enregistrement d'une trace de la commande =
		// =============================================
		if ( chTrace != NULL )
			strcat (chTrace, tabCmdTT.cmd[idxCmd].cmd);


		// =================================================
		// = Vérification du retour STB ('Pass' ou 'Fail') =
		// =================================================
		countDeb = GetTickCount();
		for ( i=0 ; i<tabCmdTT.cmd[idxCmd].nbPass ; i++ )
		{
			flagPatternPassFound = FALSE;
			flagPatternFailFound = FALSE;
			do
			{

				// ===========================
				// = Envoi de la commande TT =
				// ===========================
				chBufferLu[0] = '\0';
				if ( AffichageTrace == AFFICHAGE_TRACE )
					FIL2LO_PrintCom (nItfe, FIL2LO_COM_GAT_RX, tabCmdTT.cmd[idxCmd].cmd);


				//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, tabCmdTT.cmd[idxCmd].cmd);
				RS232_MAIN_PurgeRxPort(idPort,  &erreur, &codeErreur,chMessErreur);
				RS232_MAIN_PurgeTxPort(idPort,  &erreur, &codeErreur,chMessErreur);

				status = RS232_CONF_EcrirePort (idPort,
												tabCmdTT.cmd[idxCmd].cmd,
												strlen(tabCmdTT.cmd[idxCmd].cmd),
												&erreur,
												&codeErreur,
												chMessErreur);

				errChk (codeErreur);




				// Temporisation de 5ms
				// ----------------------
				Sleep (500);



				// Lecture du port COM
				// -------------------
				memset (chBufferLuTmp, '\0', (sizeof(unsigned char) * TAILLE_MAX));

				status = RS232_MEAS_LectureBufPattern ( idPort,
														chBufferLuTmp,
														TAILLE_MAX,
														&nbRetour,
														tabCmdTT.cmd[idxCmd].pass[i],
														timeout,
														&erreur,
														&codeErreur,
														chMessErreur);

				errChk (codeErreur);
				// Concaténation des données reçues dans le buffer de réception, si le buffer n'est pas plein
				// ------------------------------------------------------------------------------------------
				if ( ((strlen(chBufferLu) + strlen(chBufferLuTmp)) < 67000/*TAILLE_MAX*/) && (strlen(chBufferLuTmp)) )
				{
					strcat (chBufferLu, chBufferLuTmp);
					if ( AffichageTrace == AFFICHAGE_TRACE )
						FIL2LO_PrintCom (nItfe, FIL2LO_COM_GAT_TX, chBufferLuTmp);


					//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, chBufferLuTmp);
					// Enregistrement d'une trace de la réponse
					// ----------------------------------------
					if ( chTrace != NULL )
						strcat (chTrace, chBufferLuTmp);
				}

				// On vérifie si le retour 'pass' attendu a été envoyé par le STB  ==> Avec gestion des pipes pour valeurs en OU dans un Pass. On passe par une chaine tampon
				// ----------------------------------------------------------------------------------------------------------------------------------------------------------
				strcpy(chTampon,tabCmdTT.cmd[idxCmd].pass[i]);
				ptrPassMultiple = strtok(chTampon,VAR_PASS_OR_SEPARATOR);

				// On boucle sur les valeurs séparées
				// ---------------------------------
				while ( ptrPassMultiple != NULL)
				{
					if (strstr (chBufferLu, ptrPassMultiple) != NULL)
						flagPatternPassFound = TRUE;

					// On passe à la valeur suivante
					// -----------------------------
					ptrPassMultiple = strtok(NULL,VAR_PASS_OR_SEPARATOR);
				}

				// On vérifie si le retour 'fail' attendu a été envoyé par le STB
				// --------------------------------------------------------------
				flagPatternFailFound = FALSE;
				for ( j=0 ; j<tabCmdTT.cmd[idxCmd].nbFail ; j++ )
				{
					// On vérifie si le retour fail attendu a été envoyé par le STB
					// ------------------------------------------------------------
					if (strstr (chBufferLu, tabCmdTT.cmd[idxCmd].fail[j]) != NULL)
					{
						flagPatternFailFound = TRUE;
						break;
					}
				}

			}
			while ( ((int)(GetTickCount()-countDeb) < timeout) && (flagPatternPassFound == FALSE) && (flagPatternFailFound == FALSE) );


			// Si on n'a pas trouvé le pass, on sort de la boucle ==> façon de mettre les Pass en ET
			// -------------------------------------------------------------------------------------
			if (flagPatternPassFound == FALSE)
				break;

		}

		// ========================
		// = Extraction des infos =
		// ========================
		if ( (flagPatternFailFound != TRUE) && (flagPatternPassFound == TRUE) )
		{
			flagPatternPassFound = FALSE;

			if (nbInfo != NULL)
			{
				for ( i=0 ; i<tabCmdTT.cmd[idxCmd].nbInfo ; i++ )
				{
					// On vérifie le format du pattern à rechercher
					// --------------------------------------------
					if ( strchr (tabCmdTT.cmd[idxCmd].info[i], '%') != NULL )
					{
						// Remplace le '%' par '%s' dans la chaine de recherche
						// ----------------------------------------------------
//GCX_DEBUG
						sizePattern = strchr (tabCmdTT.cmd[idxCmd].info[i], '%') - tabCmdTT.cmd[idxCmd].info[i] + 1;
						strncpy (chPattern, tabCmdTT.cmd[idxCmd].info[i], sizePattern);
						chPattern[sizePattern-1] = '\0';

						// extraction juusqu'au retour à la ligne
						// --------------------------------------
						if (FCT_RechercheTag ( chBufferLu, chPattern, chVal ) == 1)
						{
							// Si une chaine est extraite : enregistrer cette chaine dans le buffer de retour
							// ------------------------------------------------------------------------------
							if ( strlen (chVal) > 0 )
							{
								// On incrémente le nombre d'infos extraits
								// ----------------------------------------
								(*nbInfo)++;

								// Allocation dynamique de mémoire pour le stockage des infos extraits
								// -------------------------------------------------------------------
								(*info) = (char**) realloc( *info, sizeof(char*) * (*nbInfo) );
								(*info)[(*nbInfo)-1] = (char*) malloc( sizeof(char) * FCT_RECUP_INFO_TAILLE_MAX );

								// Enregistrement de l'info extrait
								// --------------------------------
								strcpy ( (*info)[(*nbInfo)-1], chVal);
							}
							else
							{
								// Problème d'extraction d'info : aucune chaine extraite
								// -----------------------------------------------------
								errChk (-4);
							}
						}
						else
						{
							// Problème d'extraction d'info : pattern de recherche non trouvé
							// --------------------------------------------------------------
							errChk (-4);
						}
					}

					// "Non Remonte"
					// -------------
					else if ( strstr (tabCmdTT.cmd[idxCmd].info[i], TAG_NON_REMONTE) != NULL )
					{
						// On incrémente le nombre d'infos extraits
						// ----------------------------------------
						(*nbInfo)++;

						// Allocation dynamique de mémoire pour le stockage des infos extraits
						// -------------------------------------------------------------------
						(*info) = (char**) realloc( *info, sizeof(char*) * (*nbInfo) );
						(*info)[(*nbInfo)-1] = (char*) malloc( sizeof(char) * FCT_RECUP_INFO_TAILLE_MAX );

						// L'info n'est pas renseignée
						// ---------------------------
						strcpy ( (*info)[(*nbInfo)-1], TAG_NON_REMONTE);
					}
					else
					{
						// Problème d'extraction d'info : format du pattern de recherche incorrect
						// -----------------------------------------------------------------------
						errChk (-4);
					}
				}
			}
		}
		else if (flagPatternFailFound == TRUE)
			// Reception d'une chaine 'Fail' => sort de la fonction avec un code d'erreur
			// --------------------------------------------------------------------------
			errChk (-3);
		else
			// Time out en réception => sort de la fonction avec un code d'erreur
			// ------------------------------------------------------------------
			errChk (-2);
	}

Error:
	if(error)
	{
		if ( (AffichageTrace & MASQUE_ERR) != MASQUE_ERR )
		{
			if (error == -2)
				sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_TIMEOUT), tabCmdTT.cmd[idxCmd].cmd);
			else if (error == -3)
				sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_FAIL), tabCmdTT.cmd[idxCmd].cmd);
			else if (error == -4)
				sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_NON_TROUVE_STRING), tabCmdTT.cmd[idxCmd].cmd, tabCmdTT.cmd[idxCmd].info[i]);
			else if (error == -5)
				sprintf (chBufferLu, chMessErreur);
			else
				sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_STRING), tabCmdTT.cmd[idxCmd].cmd, chMessErreur);
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "======>", chBufferLu);
		}
		return error;
	}

	return 0;
}



///
// ==============================================================================
int FCT_CmdComExecutionV3 (int nItfe, int AffichageTrace, char *chCmdTT, char ***info, int *nbInfo, char *chTrace, int timeout)
{
	short           erreur = 0;
	int             status = -1;
	int				i = 0,j = 0;
	//int             idPort = gSlot[nItfe].comDecodeur.iHandle;
	int             error = 0;
	int             flagPatternPassFound = FALSE;
	int             flagPatternFailFound = FALSE;
	int             sizePattern;
	int             nValTempo;
	int             nTypeMsg;
	int             idxCmd = 0;
	int 			iTailleBufferLu;
	long            codeErreur = 0;
	unsigned long   countDeb;
	unsigned long   nbRetour;
	unsigned long   DimBuf;
	char            chMessErreur[TAILLE_MAX] = {"\0"};
	char            chBufferLu[TAILLE_MAX] = {"\0"};
	char            chBufferLuTmp[TAILLE_MAX] = {"\0"};
	char            chVal[FCT_RECUP_INFO_TAILLE_MAX] = {"\0"};
	char            chPattern[512] = {"\0"};
	char            chCmd[13000] = {"\0"};
	char            *ptrCmd = NULL;
	char            chDernierCaractCle[TAILLE_MIN+1] = {'\0'};
	char			*ptrPassMultiple = NULL;
	char			chTampon[TAILLE_MIN] = {'\0'} ;
	T_TAB_CMD       tabCmdTT;
	int iNumBytWritten=0;


	// ===============================
	// = RAZ des variables de retour =
	// ===============================
	if (nbInfo != NULL)
	{
		*nbInfo = 0;
		*info = NULL;
	}

	// ==========================================
	// = Extraction des commandes TT à exécuter =
	// ==========================================
	errChk (FCT_CmdComExtract (chCmdTT, &tabCmdTT));

	// ==============================
	// = Exécution des commandes TT =
	// ==============================
	for ( idxCmd=0 ; idxCmd<tabCmdTT.nbCmd ; idxCmd++ )
	{

		// Mise en casse inferieur de la commande
		// --------------------------------------
		i = 0;
		while (tabCmdTT.cmd[idxCmd].cmd[i] != '\0')
		{
			chCmd[i] = tolower (tabCmdTT.cmd[idxCmd].cmd[i]);
			i++;
		}
		chCmd[i] = '\0';

		// Mise à jour du Time Out si définis par la commande
		// --------------------------------------------------
		if (tabCmdTT.cmd[idxCmd].nTimeOut != -1)
			timeout = tabCmdTT.cmd[idxCmd].nTimeOut;

		// ==================================================================================
		// = GESTION DES COMMANDES TT                                                       =
		// ==================================================================================

		// =============================================
		// = Enregistrement d'une trace de la commande =
		// =============================================
		if ( chTrace != NULL )
			strcat (chTrace, tabCmdTT.cmd[idxCmd].cmd);

		// ===========================
		// = Envoi de la commande TT =
		// ===========================




		chBufferLu[0] = '\0';
		if ( AffichageTrace == AFFICHAGE_TRACE )
			FIL2LO_PrintCom (nItfe, FIL2LO_COM_GAT_RX, tabCmdTT.cmd[idxCmd].cmd);
		ClearBufferTelnet(gSlot[nItfe].igHandleConnexion);
		RemoveSurroundingWhiteSpace (tabCmdTT.cmd[idxCmd].cmd);
		status = InetTelnetWrite (gSlot[nItfe].igHandleConnexion , tabCmdTT.cmd[idxCmd].cmd,  "\r\n", -1, &iNumBytWritten, 1000);
		errChk (status);


		/**/
		// =================================================
		// = Vérification du retour STB ('Pass' ou 'Fail') =
		// =================================================
		countDeb = GetTickCount();
		/*for ( i=0 ; i<tabCmdTT.cmd[idxCmd].nbPass ; i++ )
		{   */
		flagPatternPassFound = FALSE;
		flagPatternFailFound = FALSE;
		do
		{
			// Temporisation de 5ms
			// ----------------------
			Sleep (5000);

			// Lecture du port COM
			// -------------------
			memset (chBufferLuTmp, '\0', (sizeof(unsigned char) * TAILLE_MAX));
			status = InetTelnetReadUntil(gSlot[nItfe].igHandleConnexion, chBufferLuTmp, sizeof (chBufferLuTmp) - 1, tabCmdTT.cmd[idxCmd].pass[0], timeout);

			strncpy(gSlot[nItfe].Bufflu,chBufferLuTmp,TAILLE_MAX-1);
			RemoveSurroundingWhiteSpace (chBufferLuTmp);

			signal(SIGINT, gSlot[nItfe].igHandleConnexion);

			// Concaténation des données reçues dans le buffer de réception, si le buffer n'est pas plein
			// ------------------------------------------------------------------------------------------
			if ( ((strlen(chBufferLu) + strlen(chBufferLuTmp)) < TAILLE_MAX /*67000 TAILLE_MAX*/) && (strlen(chBufferLuTmp)) )
			{
				strcat (chBufferLu, chBufferLuTmp);
				if ( AffichageTrace == AFFICHAGE_TRACE )
					FIL2LO_PrintCom (nItfe, FIL2LO_COM_GAT_TX, chBufferLuTmp);

				// Enregistrement d'une trace de la réponse
				// ----------------------------------------
				if ( chTrace != NULL )
					strcat (chTrace, chBufferLuTmp);
			}

			errChk (status);
			for ( i=0 ; i<tabCmdTT.cmd[idxCmd].nbPass ; i++ )
			{
				// On vérifie si le retour 'pass' attendu a été envoyé par le STB  ==> Avec gestion des pipes pour valeurs en OU dans un Pass. On passe par une chaine tampon
				// ----------------------------------------------------------------------------------------------------------------------------------------------------------
				strcpy(chTampon,tabCmdTT.cmd[idxCmd].pass[i]);
				ptrPassMultiple = strtok(chTampon,VAR_PASS_OR_SEPARATOR);

				// On boucle sur les valeurs séparées
				// ---------------------------------
				while ( ptrPassMultiple != NULL)
				{
					if (strstr (chBufferLu, ptrPassMultiple) != NULL)
						flagPatternPassFound = TRUE;
					else
					{
						flagPatternPassFound = FALSE;
						errChk (-2);
					}
					// On passe à la valeur suivante
					// -----------------------------
					ptrPassMultiple = strtok(NULL,VAR_PASS_OR_SEPARATOR);
				}

				// On vérifie si le retour 'fail' attendu a été envoyé par le STB
				// --------------------------------------------------------------
				flagPatternFailFound = FALSE;
				for ( j=0 ; j<tabCmdTT.cmd[idxCmd].nbFail ; j++ )
				{
					// On vérifie si le retour fail attendu a été envoyé par le STB
					// ------------------------------------------------------------
					if (strstr (chBufferLu, tabCmdTT.cmd[idxCmd].fail[j]) != NULL)
					{
						flagPatternFailFound = TRUE;
						errChk (-2);
					}
				}

			}
			//while ( ((int)(GetTickCount()-countDeb) < timeout) && (flagPatternPassFound == FALSE) && (flagPatternFailFound == FALSE) );


			// Si on n'a pas trouvé le pass, on sort de la boucle ==> façon de mettre les Pass en ET
			// -------------------------------------------------------------------------------------
			if (flagPatternPassFound == FALSE)
				break;

		}
		while ( ((int)(GetTickCount()-countDeb) < timeout) && (flagPatternPassFound == FALSE) && (flagPatternFailFound == FALSE) );

		// ========================
		// = Extraction des infos =
		// ========================
		if ( (flagPatternFailFound != TRUE) && (flagPatternPassFound == TRUE) )
		{
			flagPatternPassFound = FALSE;

			if (nbInfo != NULL)
			{
				for ( i=0 ; i<tabCmdTT.cmd[idxCmd].nbInfo ; i++ )
				{
					// On vérifie le format du pattern à rechercher
					// --------------------------------------------
					if ( strchr (tabCmdTT.cmd[idxCmd].info[i], '%') != NULL )
					{
						// Remplace le '%' par '%s' dans la chaine de recherche
						// ----------------------------------------------------
//GCX_DEBUG
						sizePattern = strchr (tabCmdTT.cmd[idxCmd].info[i], '%') - tabCmdTT.cmd[idxCmd].info[i] + 1;
						strncpy (chPattern, tabCmdTT.cmd[idxCmd].info[i], sizePattern);
						chPattern[sizePattern-1] = '\0';

						// extraction juusqu'au retour à la ligne
						// --------------------------------------
						if (FCT_RechercheTag ( chBufferLu, chPattern, chVal ) == 1)
						{
							// Si une chaine est extraite : enregistrer cette chaine dans le buffer de retour
							// ------------------------------------------------------------------------------
							if ( strlen (chVal) > 0 )
							{
								// On incrémente le nombre d'infos extraits
								// ----------------------------------------
								(*nbInfo)++;

								// Allocation dynamique de mémoire pour le stockage des infos extraits
								// -------------------------------------------------------------------
								(*info) = (char**) realloc( *info, sizeof(char*) * (*nbInfo) );
								(*info)[(*nbInfo)-1] = (char*) malloc( sizeof(char) * FCT_RECUP_INFO_TAILLE_MAX );

								// Enregistrement de l'info extrait
								// --------------------------------
								strcpy ( (*info)[(*nbInfo)-1], chVal);
							}
							else
							{
								// Problème d'extraction d'info : aucune chaine extraite
								// -----------------------------------------------------
								errChk (-4);
							}
						}
						else
						{
							// Problème d'extraction d'info : pattern de recherche non trouvé
							// --------------------------------------------------------------
							errChk (-4);
						}
					}

					// "Non Remonte"
					// -------------
					else if ( strstr (tabCmdTT.cmd[idxCmd].info[i], TAG_NON_REMONTE) != NULL )
					{
						// On incrémente le nombre d'infos extraits
						// ----------------------------------------
						(*nbInfo)++;

						// Allocation dynamique de mémoire pour le stockage des infos extraits
						// -------------------------------------------------------------------
						(*info) = (char**) realloc( *info, sizeof(char*) * (*nbInfo) );
						(*info)[(*nbInfo)-1] = (char*) malloc( sizeof(char) * FCT_RECUP_INFO_TAILLE_MAX );

						// L'info n'est pas renseignée
						// ---------------------------
						strcpy ( (*info)[(*nbInfo)-1], TAG_NON_REMONTE);
					}
					else
					{
						// Problème d'extraction d'info : format du pattern de recherche incorrect
						// -----------------------------------------------------------------------
						errChk (-4);
					}
				}
			}
		}
		else if (flagPatternFailFound == TRUE)
			// Reception d'une chaine 'Fail' => sort de la fonction avec un code d'erreur
			// --------------------------------------------------------------------------
			errChk (-3);
		else
			// Time out en réception => sort de la fonction avec un code d'erreur
			// ------------------------------------------------------------------
			errChk (-2);
	}

Error:
	if(error)
	{
		if ( (AffichageTrace & MASQUE_ERR) != MASQUE_ERR )
		{
			if (error == -2)
				sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_TIMEOUT), tabCmdTT.cmd[idxCmd].cmd);
			else if (error == -3)
				sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_FAIL), tabCmdTT.cmd[idxCmd].cmd);
			else if (error == -4)
				sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_NON_TROUVE_STRING), tabCmdTT.cmd[idxCmd].cmd, tabCmdTT.cmd[idxCmd].info[i]);
			else if (error == -5)
				sprintf (chBufferLu, chMessErreur);
			else
				sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_STRING), tabCmdTT.cmd[idxCmd].cmd, chMessErreur);
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "======>", chBufferLu);
		}
		return error;
	}

	return 0;
}
// ~~~



/*

//////
int FCT_CmdComExecutionV3 (int nItfe, int AffichageTrace, char *chCmdTT, char ***info, int *nbInfo, char *chTrace, int timeout)
{
short           erreur = 0;
int             status = -1;
int				i = 0,j = 0;
int             idPort = gSlot[nItfe].comDecodeur.iHandle;
int             error = 0;
int             flagPatternPassFound = FALSE;
int             flagPatternFailFound = FALSE;
int             sizePattern;
int             nValTempo;
int             nTypeMsg;
int             idxCmd = 0;
int 			iTailleBufferLu;
long            codeErreur = 0;
unsigned long   countDeb;
unsigned long   nbRetour;
unsigned long   DimBuf;
char            chMessErreur[TAILLE_MAX] = {"\0"};
char            chBufferLu[TAILLE_MAX] = {"\0"};
char            chBufferLuTmp[TAILLE_MAX] = {"\0"};
char            chVal[FCT_RECUP_INFO_TAILLE_MAX] = {"\0"};
char            chPattern[512] = {"\0"};
char            chCmd[TAILLE_MIN] = {"\0"};
char            *ptrCmd = NULL;
char            chDernierCaractCle[TAILLE_MIN+1] = {'\0'};
char			*ptrPassMultiple = NULL;
char			chTampon[TAILLE_MIN] = {'\0'} ;
T_TAB_CMD       tabCmdTT;
int iNumBytWritten=0;
T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;


// ===============================
// = RAZ des variables de retour =
// ===============================
if (nbInfo != NULL)
{
	*nbInfo = 0;
	*info = NULL;
}

// ==========================================
// = Extraction des commandes TT à exécuter =
// ==========================================
errChk (FCT_CmdComExtract (chCmdTT, &tabCmdTT));

// ==============================
// = Exécution des commandes TT =
// ==============================
for ( idxCmd=0 ; idxCmd<tabCmdTT.nbCmd ; idxCmd++ )
{

	// Mise en casse inferieur de la commande
	// --------------------------------------
	i = 0;
	while (tabCmdTT.cmd[idxCmd].cmd[i] != '\0')
	{
		chCmd[i] = tolower (tabCmdTT.cmd[idxCmd].cmd[i]);
		i++;
	}
	chCmd[i] = '\0';

	// Mise à jour du Time Out si définis par la commande
	// --------------------------------------------------
	if (tabCmdTT.cmd[idxCmd].nTimeOut != -1)
		timeout = tabCmdTT.cmd[idxCmd].nTimeOut;

	// ==================================================================================
	// = GESTION DES COMMANDES TT                                                       =
	// ==================================================================================

	// =============================================
	// = Enregistrement d'une trace de la commande =
	// =============================================
	if ( chTrace != NULL )
		strcat (chTrace, tabCmdTT.cmd[idxCmd].cmd);
// ===========================
// = Envoi de la commande TT =
// ===========================

	chBufferLu[0] = '\0';

	if ( AffichageTrace == AFFICHAGE_TRACE )

		FIL2LO_PrintCom (nItfe, FIL2LO_COM_GAT_RX, tabCmdTT.cmd[idxCmd].cmd);

	if ( FindPattern (tabCmdTT.cmd[idxCmd].cmd,0, 6,"root", 0, 0)==0)

	{

	 //RemoveSurroundingWhiteSpace (tabCmdTT.cmd[idxCmd].cmd);	 ///ajouetr pour validation

	 status = InetTelnetWrite (gSlot[nItfe].igHandleConnexion , "root",  "\r\n", -1, &iNumBytWritten, 1000);

	 Sleep(200);

	//status = InetTelnetWrite (gSlot[nItfe].igHandleConnexion , "root",  "\r\n", -1, &iNumBytWritten, 1000);

	 errChk (status);

	}

	else{

		ClearBufferTelnet(gSlot[nItfe].igHandleConnexion);

		status = InetTelnetWrite (gSlot[nItfe].igHandleConnexion , tabCmdTT.cmd[idxCmd].cmd,  "\r\n", -1, &iNumBytWritten, 1000);

		errChk (status);

	}



// ~~~

	chBufferLu[0] = '\0';
if ( AffichageTrace == AFFICHAGE_TRACE )
FIL2LO_PrintCom (nItfe, FIL2LO_COM_GAT_RX, tabCmdTT.cmd[idxCmd].cmd);

//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, tabCmdTT.cmd[idxCmd].cmd);

//if  (VAR_TUINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_eth,0))
if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_eth,0))
{

	ClearBufferTelnet(gSlot[nItfe].igHandleConnexion);
	status = InetTelnetWrite (gSlot[nItfe].igHandleConnexion , tabCmdTT.cmd[idxCmd].cmd,  "\r\n", -1, &iNumBytWritten, 1000);
	//status = InetTelnetWrite (gSlot[nItfe].igHandleConnexion , "root",  "\r\n", -1, &iNumBytWritten, 1000);

	errChk (status);


}
else
{
RS232_MAIN_PurgeRxPort(idPort,  &erreur, &codeErreur,chMessErreur);
RS232_MAIN_PurgeTxPort(idPort,  &erreur, &codeErreur,chMessErreur);
			status = RS232_CONF_EcrirePort (idPort,
											tabCmdTT.cmd[idxCmd].cmd,
											strlen(tabCmdTT.cmd[idxCmd].cmd),
											&erreur,
											&codeErreur,
											chMessErreur);

			errChk (codeErreur);
}
// ~~~


////






	//
	// =================================================
	// = Vérification du retour STB ('Pass' ou 'Fail') =
	// =================================================
	countDeb = GetTickCount();
	for ( i=0 ; i<tabCmdTT.cmd[idxCmd].nbPass ; i++ )
	{
		flagPatternPassFound = FALSE;
		flagPatternFailFound = FALSE;
		do
		{
			// Temporisation de 5ms
			// ----------------------
			Sleep (500);






			// Lecture du port COM
		// -------------------
		memset (chBufferLuTmp, '\0', (sizeof(unsigned char) * TAILLE_MAX));
		status = InetTelnetReadUntil(gSlot[nItfe].igHandleConnexion, chBufferLuTmp, sizeof (chBufferLuTmp) - 1, tabCmdTT.cmd[idxCmd].pass[0], timeout);


		strncpy(gSlot[nItfe].Bufflu,chBufferLuTmp,TAILLE_MAX-1);
		RemoveSurroundingWhiteSpace (chBufferLuTmp);  ///ajouetr pour validation

		signal(SIGINT, gSlot[nItfe].igHandleConnexion);



			  // ~~~


			// Lecture du port COM
			// -------------------
			memset (chBufferLuTmp, '\0', (sizeof(unsigned char) * TAILLE_MAX));
			   if (VAR_GET_UINT8( ptrVariablesConf,VAR_CONF_DEC_BWC_FLAG_eth,0))
			   {
				//status = InetTelnetReadUntil(gSlot[nItfe].igHandleConnexion, chBufferLuTmp, sizeof (chBufferLuTmp) - 1, tabCmdTT.cmd[idxCmd].pass[0], timeout);

				   status = InetTelnetReadUntil(gSlot[nItfe].igHandleConnexion, chBufferLuTmp, sizeof (chBufferLuTmp) - 1,"root@f5359p:~#", timeout);
				strncpy(gSlot[nItfe].Bufflu,chBufferLuTmp,TAILLE_MAX-1);
				//RemoveSurroundingWhiteSpace (chBufferLuTmp);

				signal(SIGINT, gSlot[nItfe].igHandleConnexion);
			}
			else
			{
			status = RS232_MEAS_LectureBufPattern ( idPort,
													chBufferLuTmp,
													TAILLE_MAX,
													&nbRetour,
													tabCmdTT.cmd[idxCmd].pass[i],
													timeout,
													&erreur,
													&codeErreur,
													chMessErreur);

			errChk (codeErreur);
			}
				   // ~~~

			// Concaténation des données reçues dans le buffer de réception, si le buffer n'est pas plein
			// ------------------------------------------------------------------------------------------
			//////if ( ((strlen(chBufferLu) + strlen(chBufferLuTmp)) < 67000/*TAILLE_MAX...) && (strlen(chBufferLuTmp)) )
			{
				strcat (chBufferLu, chBufferLuTmp);
				if ( AffichageTrace == AFFICHAGE_TRACE )
					FIL2LO_PrintCom (nItfe, FIL2LO_COM_GAT_TX, chBufferLuTmp);


				//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, chBufferLuTmp);
				// Enregistrement d'une trace de la réponse
				// ----------------------------------------
				if ( chTrace != NULL )
					strcat (chTrace, chBufferLuTmp);
			}

			// On vérifie si le retour 'pass' attendu a été envoyé par le STB  ==> Avec gestion des pipes pour valeurs en OU dans un Pass. On passe par une chaine tampon
			// ----------------------------------------------------------------------------------------------------------------------------------------------------------
			strcpy(chTampon,tabCmdTT.cmd[idxCmd].pass[i]);
			ptrPassMultiple = strtok(chTampon,VAR_PASS_OR_SEPARATOR);

			// On boucle sur les valeurs séparées
			// ---------------------------------
			while ( ptrPassMultiple != NULL)
			{
				if (strstr (chBufferLu, ptrPassMultiple) != NULL)
					flagPatternPassFound = TRUE;

				// On passe à la valeur suivante
				// -----------------------------
				ptrPassMultiple = strtok(NULL,VAR_PASS_OR_SEPARATOR);
			}

			// On vérifie si le retour 'fail' attendu a été envoyé par le STB
			// --------------------------------------------------------------
			flagPatternFailFound = FALSE;
			for ( j=0 ; j<tabCmdTT.cmd[idxCmd].nbFail ; j++ )
			{
				// On vérifie si le retour fail attendu a été envoyé par le STB
				// ------------------------------------------------------------
				if (strstr (chBufferLu, tabCmdTT.cmd[idxCmd].fail[j]) != NULL)
				{
					flagPatternFailFound = TRUE;
					break;
				}
			}

		}
		while ( ((int)(GetTickCount()-countDeb) < timeout) && (flagPatternPassFound == FALSE) && (flagPatternFailFound == FALSE) );


		// Si on n'a pas trouvé le pass, on sort de la boucle ==> façon de mettre les Pass en ET
		// -------------------------------------------------------------------------------------
		if (flagPatternPassFound == FALSE)
			break;

	}

	// ========================
	// = Extraction des infos =
	// ========================
	if ( (flagPatternFailFound != TRUE) && (flagPatternPassFound == TRUE) )
	{
		flagPatternPassFound = FALSE;

		if (nbInfo != NULL)
		{
			for ( i=0 ; i<tabCmdTT.cmd[idxCmd].nbInfo ; i++ )
			{
				// On vérifie le format du pattern à rechercher
				// --------------------------------------------
				if ( strchr (tabCmdTT.cmd[idxCmd].info[i], '%') != NULL )
				{
					// Remplace le '%' par '%s' dans la chaine de recherche
					// ----------------------------------------------------
//GCX_DEBUG
					sizePattern = strchr (tabCmdTT.cmd[idxCmd].info[i], '%') - tabCmdTT.cmd[idxCmd].info[i] + 1;
					strncpy (chPattern, tabCmdTT.cmd[idxCmd].info[i], sizePattern);
					chPattern[sizePattern-1] = '\0';

					// extraction juusqu'au retour à la ligne
					// --------------------------------------
					if (FCT_RechercheTag ( chBufferLu, chPattern, chVal ) == 1)
					{
						// Si une chaine est extraite : enregistrer cette chaine dans le buffer de retour
						// ------------------------------------------------------------------------------
						if ( strlen (chVal) > 0 )
						{
							// On incrémente le nombre d'infos extraits
							// ----------------------------------------
							(*nbInfo)++;

							// Allocation dynamique de mémoire pour le stockage des infos extraits
							// -------------------------------------------------------------------
							(*info) = (char**) realloc( *info, sizeof(char*) * (*nbInfo) );
							(*info)[(*nbInfo)-1] = (char*) malloc( sizeof(char) * FCT_RECUP_INFO_TAILLE_MAX );

							// Enregistrement de l'info extrait
							// --------------------------------
							strcpy ( (*info)[(*nbInfo)-1], chVal);
						}
						else
						{
							// Problème d'extraction d'info : aucune chaine extraite
							// -----------------------------------------------------
							errChk (-4);
						}
					}
					else
					{
						// Problème d'extraction d'info : pattern de recherche non trouvé
						// --------------------------------------------------------------
						errChk (-4);
					}
				}

				// "Non Remonte"
				// -------------
				else if ( strstr (tabCmdTT.cmd[idxCmd].info[i], TAG_NON_REMONTE) != NULL )
				{
					// On incrémente le nombre d'infos extraits
					// ----------------------------------------
					(*nbInfo)++;

					// Allocation dynamique de mémoire pour le stockage des infos extraits
					// -------------------------------------------------------------------
					(*info) = (char**) realloc( *info, sizeof(char*) * (*nbInfo) );
					(*info)[(*nbInfo)-1] = (char*) malloc( sizeof(char) * FCT_RECUP_INFO_TAILLE_MAX );

					// L'info n'est pas renseignée
					// ---------------------------
					strcpy ( (*info)[(*nbInfo)-1], TAG_NON_REMONTE);
				}
				else
				{
					// Problème d'extraction d'info : format du pattern de recherche incorrect
					// -----------------------------------------------------------------------
					errChk (-4);
				}
			}
		}
	}
	else if (flagPatternFailFound == TRUE)
		// Reception d'une chaine 'Fail' => sort de la fonction avec un code d'erreur
		// --------------------------------------------------------------------------
		errChk (-3);
	else
		// Time out en réception => sort de la fonction avec un code d'erreur
		// ------------------------------------------------------------------
		errChk (-2);
		// On contrôle l'écho (pour chaque commande TT)
	// --------------------------------------------

}

Error:
if(error)
{
	if ( (AffichageTrace & MASQUE_ERR) != MASQUE_ERR )
	{
		if (error == -2)
			sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_TIMEOUT), tabCmdTT.cmd[idxCmd].cmd);
		else if (error == -3)
			sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_FAIL), tabCmdTT.cmd[idxCmd].cmd);
		else if (error == -4)
			sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_NON_TROUVE_STRING), tabCmdTT.cmd[idxCmd].cmd, tabCmdTT.cmd[idxCmd].info[i]);
		else if (error == -5)
			sprintf (chBufferLu, chMessErreur);
		else
			sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_STRING), tabCmdTT.cmd[idxCmd].cmd, chMessErreur);
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "======>", chBufferLu);
	}
	return error;
}

return 0;
}

*/
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_CmdComExtract (char *cmdIn, T_TAB_CMD *cmdOut)
{
	int     i;
	char    *ptrCmdIn = cmdIn;
	char    rep[TAILLE_MIN] = {"\0"};
	int     etat = 0;


	// ==============================
	// = RAZ du tableau de commande =
	// ==============================
	cmdOut->nbCmd = 0;
	for ( i=0 ; i<10 ; i++ )
	{
		cmdOut->cmd[i].nbPass = 0;
		cmdOut->cmd[i].nbFail = 0;
		cmdOut->cmd[i].nbInfo = 0;
		cmdOut->cmd[i].cmd[0] = '0';
		cmdOut->cmd[i].nTimeOut = -1;
	}

	// ============================
	// = Extraction des commandes =
	// ============================
	do
	{

		switch (etat)
		{
				// -----------------------------
				// - Attente début de commande -
				// -----------------------------
			case 0:
			default:

				while( ptrCmdIn[0] != '[' && ptrCmdIn[0] != '\0' ) ptrCmdIn++;

				if ( ptrCmdIn[0] == '[' )
					etat = 1;

				break;

				// --------------------------
				// - Extraction de commande -
				// --------------------------
			case 1:

				// Suppression de la balise de début de champ
				// ------------------------------------------
				ptrCmdIn++;
				i = 0;

				// Enregistrement de la commande tant que les balises fin de commande ou début réponse et le fin de chaine ne sont pas atteint
				// ---------------------------------------------------------------------------------------------------------------------------
				while( ptrCmdIn[0] != ']' && ptrCmdIn[0] != '{' && ptrCmdIn[0] != '\0' )
				{
					cmdOut->cmd[cmdOut->nbCmd].cmd[i++] = ptrCmdIn[0];
					cmdOut->cmd[cmdOut->nbCmd].cmd[i] = '\0';
					ptrCmdIn++;
				}

				if (ptrCmdIn[0] == ']')
				{
					// On passe à la commande suivante
					// -------------------------------
					etat = 0;
				}
				else if (ptrCmdIn[0] == '{')
				{
					// On extrait les réponses de la commande
					// --------------------------------------
					etat = 3;
				}

				if (ptrCmdIn[0] != '\0')
				{
					// Suppression des espaces et tabulations en début et fin de chaine
					// ----------------------------------------------------------------
					RemoveSurroundingWhiteSpace (cmdOut->cmd[cmdOut->nbCmd].cmd);

					// On ajoute le retour charriot à la commande
					// ------------------------------------------
					strcat (cmdOut->cmd[cmdOut->nbCmd].cmd, "\r");

					// On remplace les séquences escape dans la commande
					// -------------------------------------------------
					FCT_RemplacerEscapeSequence (cmdOut->cmd[cmdOut->nbCmd].cmd);

					// On incrémente le nombre de commande
					// -----------------------------------
					cmdOut->nbCmd++;
				}

				break;

				// ----------------------------
				// - Attente début de réponse -
				// ----------------------------
			case 2:

				// Attente début réponse ou fin commande
				// -------------------------------------
				while( ptrCmdIn[0] != ']' && ptrCmdIn[0] != '{' && ptrCmdIn[0] != '\0' ) ptrCmdIn++;

				if (ptrCmdIn[0] == ']')
					// on passe à la commande suivante
					// -------------------------------
					etat = 0;
				else if (ptrCmdIn[0] == '{')
					// on extrait les réponses de la commande
					// --------------------------------------
					etat = 3;

				break;

				// ----------------------------
				// - Extraction d'une réponse -
				// ----------------------------
			case 3:

				// Suppression de la balise de début de champ
				// ------------------------------------------
				ptrCmdIn++;
				i = 0;

				// Enregistrement de la commande tant que la balise fin de réponse et le fin de chaine ne sont pas atteint
				// -------------------------------------------------------------------------------------------------------
				while( ptrCmdIn[0] != '}' && ptrCmdIn[0] != '\0' )
				{
					rep[i++] = ptrCmdIn[0];
					rep[i] = '\0';
					ptrCmdIn++;
				}

				if (ptrCmdIn[0] == '}')
				{

					// Traitement de la commande
					// -------------------------
					if (strstr(rep,"Pass:") != NULL)
					{
						// Extraction d'une réponse OK
						// ---------------------------
						strcpy (cmdOut->cmd[cmdOut->nbCmd-1].pass[cmdOut->cmd[cmdOut->nbCmd-1].nbPass], rep+strlen("Pass:"));

						// Suppression des espaces et tabulations en début et fin de chaine
						// ----------------------------------------------------------------
						RemoveSurroundingWhiteSpace (cmdOut->cmd[cmdOut->nbCmd-1].pass[cmdOut->cmd[cmdOut->nbCmd-1].nbPass]);

						// On remplace les séquences escape dans la commande
						// -------------------------------------------------
						FCT_RemplacerEscapeSequence (cmdOut->cmd[cmdOut->nbCmd-1].pass[cmdOut->cmd[cmdOut->nbCmd-1].nbPass]);

						cmdOut->cmd[cmdOut->nbCmd-1].nbPass++;
					}
					else if (strstr(rep,"Fail:") != NULL)
					{
						// Extraction d'une réponse KO
						// ---------------------------
						strcpy (cmdOut->cmd[cmdOut->nbCmd-1].fail[cmdOut->cmd[cmdOut->nbCmd-1].nbFail], rep+strlen("Fail:"));

						// Suppression des espaces et tabulations en début et fin de chaine
						// ----------------------------------------------------------------
						RemoveSurroundingWhiteSpace (cmdOut->cmd[cmdOut->nbCmd-1].fail[cmdOut->cmd[cmdOut->nbCmd-1].nbFail]);

						// On remplace les séquences escape dans la commande
						// -------------------------------------------------
						FCT_RemplacerEscapeSequence (cmdOut->cmd[cmdOut->nbCmd-1].fail[cmdOut->cmd[cmdOut->nbCmd-1].nbFail]);

						cmdOut->cmd[cmdOut->nbCmd-1].nbFail++;
					}
					else if (strstr(rep,"TimeOut:") != NULL)
					{
						// Extraction du Time Out de la réponse
						// ------------------------------------
						sscanf (rep, "TimeOut:%d", &cmdOut->cmd[cmdOut->nbCmd-1].nTimeOut);
						cmdOut->cmd[cmdOut->nbCmd-1].nTimeOut *= 1000;
					}
					else
					{
						// Extraction d'une réponse Info
						// -----------------------------
						strcpy (cmdOut->cmd[cmdOut->nbCmd-1].info[cmdOut->cmd[cmdOut->nbCmd-1].nbInfo], rep);

						// On remplace les séquences escape dans la commande
						// -------------------------------------------------
						FCT_RemplacerEscapeSequence (cmdOut->cmd[cmdOut->nbCmd-1].info[cmdOut->cmd[cmdOut->nbCmd-1].nbInfo]);

						cmdOut->cmd[cmdOut->nbCmd-1].nbInfo++;
					}

					// Recherche réponse suivante
					// --------------------------
					etat = 2;
				}

				break;
		}

	}
	while( ptrCmdIn[0] != '\0' );

	if (cmdOut->nbCmd == 0)
	{
		// Si aucune commande n'est extraite alors on sort en erreur
		// ---------------------------------------------------------
		return -1;
	}

	return 0;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION : V.1.1.1
//  DATE : 19/06/20
//  AUTEUR : CH_BK
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_OuverturePortsCOM ( int nItfe )
{

	char            chMess[8192] = {'\0'};
	char            chMessInfo[TAILLE_MAX_CHAINE] = {"\0"};
	T_SLOT          *ptrSlot = &(gSlot[nItfe]);
	T_VARIABLES     *ptrVariablesConf = &(gSlot[nItfe].variablesConf);
	int             nbTentativeConnexion = 0;




	// =====================================
	// = Ouverture du Port COM du Decodeur =
	// =====================================


	// On boucle pour essayer de se reconnecter si port COM occupé
	// -----------------------------------------------------------
	do
	{
		DisableBreakOnLibraryErrors ();
		//ptrSlot->comDecodeur.tConfig.baud = VAR_GET_UINT32(&ptrSlot->variablesConf,VAR_CONF_ID_VITESSE_PORT_COM,0);
		ptrSlot->comDecodeur.iStatus = RS232_MAIN_OpenPort (   &ptrSlot->comDecodeur.iHandle,
									   ptrSlot->comDecodeur.tConfig,
									   &ptrSlot->comDecodeur.iErrorOccured,
									   &ptrSlot->comDecodeur.iErrorCode,
									   ptrSlot->comDecodeur.sErrorMsg);
		EnableBreakOnLibraryErrors ();
		if (ptrSlot->comDecodeur.iErrorOccured )
		{
			// On demande à fermer l'hyperterminal sur le port Com qui sort en erreur
			// --------------------------------------------------------------------
			if (nbTentativeConnexion < (STB_NB_TENTATIVE_CONNEXION - 1))
			{
				sprintf(chMessInfo, "Arrêter l'HyperTerminal (ou libérer le port) sur le port %d",ptrSlot->comDecodeur.tConfig.numPort);
				MessagePopup (GET_MESSAGE(IHM_COM_TTR_POPUP), chMessInfo);
			}
			// Sinon on sort en erreur
			// -----------------------
			else
			{
				Fmt (chMess, GET_MESSAGE(IHM_COM_MSG_POPUP_2), ptrSlot->comDecodeur.sErrorMsg, ptrSlot->comDecodeur.tConfig.numPort );
				ClipboardPutText (chMess);
				Fmt(chMess, GET_MESSAGE(GENERIQUE_MSG_POPUP_PRESSE_PAPIER), chMess);
				MessagePopup (GET_MESSAGE(IHM_COM_TTR_POPUP), chMess);
			}
			nbTentativeConnexion++;
		}

	}
	while ( ptrSlot->comDecodeur.iErrorOccured && nbTentativeConnexion < STB_NB_TENTATIVE_CONNEXION );

	if (nbTentativeConnexion == STB_NB_TENTATIVE_CONNEXION)
		return -1;


	// =======================================================================
	// = Ouverture du Port COM Generique (Wattemetre, Quantum Data, Ou PSOC) =
	// =======================================================================
	/*	if(VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_DEC_BNFT_FLAG_TEST_LED,0))
		{

			// On réinitialise le nombre de tentatives de connexion
			// ----------------------------------------------------
			nbTentativeConnexion = 0;

			// On boucle pour essayer de se reconnecter si port COM occupé
			// -----------------------------------------------------------
			do
			{
				DisableBreakOnLibraryErrors ();
				ptrSlot->comGenerique_A.iStatus = RS232_MAIN_OpenPort ( &ptrSlot->comGenerique_A.iHandle,
												  ptrSlot->comGenerique_A.tConfig,
												  &ptrSlot->comGenerique_A.iErrorOccured,
												  &ptrSlot->comGenerique_A.iErrorCode,
												  ptrSlot->comGenerique_A.sErrorMsg);
				EnableBreakOnLibraryErrors ();
				if (ptrSlot->comGenerique_A.iErrorOccured)
				{
					// On demande à fermer l'hyperterminal sur le port Com qui sort en erreur
					// --------------------------------------------------------------------
					if (nbTentativeConnexion < (COM_NB_TENTATIVE_CONNEXION - 1))
					{
						sprintf(chMessInfo, "Arrêter l'HyperTerminal (ou libérer le port) sur le port %d",ptrSlot->comGenerique_A.tConfig.numPort);
						MessagePopup (GET_MESSAGE(IHM_COM_TTR_POPUP), chMessInfo);
					}
					// Sinon on sort en erreur
					// -----------------------
					else
					{
						Fmt (chMess, GET_MESSAGE(GENERIQUE_MSG_POPUP_CODE), ptrSlot->comGenerique_A.iErrorCode, ptrSlot->comGenerique_A.sErrorMsg);
						Fmt (chMess, GET_MESSAGE(IHM_COM_MSG_POPUP_2), ptrSlot->comGenerique_A.sErrorMsg, ptrSlot->comGenerique_A.tConfig.numPort );
						ClipboardPutText (chMess);
						Fmt(chMess, GET_MESSAGE(GENERIQUE_MSG_POPUP_PRESSE_PAPIER), chMess);
						MessagePopup (GET_MESSAGE(IHM_COM_TTR_POPUP), chMess);
					}
					nbTentativeConnexion++;
				}

			}
			while ( ptrSlot->comGenerique_A.iErrorOccured && nbTentativeConnexion < COM_NB_TENTATIVE_CONNEXION );


			if (nbTentativeConnexion == COM_NB_TENTATIVE_CONNEXION)
				return -1;

		}*/

	// ============================================
	// = Ouverture du Port COM IR - Si Carte PIC  =
	// ============================================
	if (gnPresenceCartePicIr )
	{
		// On réinitialise le nombre de tentatives de connexion
		// ----------------------------------------------------
		nbTentativeConnexion = 0;

		// On boucle pour essayer de se reconnecter si port COM occupé
		// -----------------------------------------------------------
		do
		{
			DisableBreakOnLibraryErrors ();
			ptrSlot->comDecodeur.iStatus = RS232_MAIN_OpenPort (  &ptrSlot->comDecodeur.iHandle,
										   ptrSlot->comDecodeur.tConfig,
										   &ptrSlot->comDecodeur.iErrorOccured,
										   &ptrSlot->comDecodeur.iErrorCode,
										   ptrSlot->comDecodeur.sErrorMsg);
			EnableBreakOnLibraryErrors ();
			if (ptrSlot->comDecodeur.iErrorOccured)
			{
				// On demande à fermer l'hyperterminal sur le port Com qui sort en erreur
				// --------------------------------------------------------------------
				if (nbTentativeConnexion < (COM_NB_TENTATIVE_CONNEXION - 1))
				{
					sprintf(chMessInfo, "Arrêter l'HyperTerminal (ou libérer le port) sur le port %d",ptrSlot->comDecodeur.tConfig.numPort);
					MessagePopup (GET_MESSAGE(IHM_COM_TTR_POPUP), chMessInfo);
				}
				// Sinon on sort en erreur
				// -----------------------
				else
				{
					Fmt (chMess, GET_MESSAGE(GENERIQUE_MSG_POPUP_CODE), ptrSlot->comDecodeur.iErrorCode, ptrSlot->comDecodeur.sErrorMsg);
					Fmt (chMess, GET_MESSAGE(IHM_COM_MSG_POPUP_2), ptrSlot->comDecodeur.sErrorMsg, ptrSlot->comDecodeur.tConfig.numPort );
					ClipboardPutText (chMess);
					Fmt(chMess, GET_MESSAGE(GENERIQUE_MSG_POPUP_PRESSE_PAPIER), chMess);
					MessagePopup (GET_MESSAGE(IHM_COM_TTR_POPUP), chMess);
				}
				nbTentativeConnexion++;

			}
		}
		while ( ptrSlot->comDecodeur.iErrorOccured && nbTentativeConnexion < COM_NB_TENTATIVE_CONNEXION );

		if (nbTentativeConnexion == COM_NB_TENTATIVE_CONNEXION)
			return -1;

	}


	// =======================================================================================
	// = Ouverture du Port COM Zebra	- Sauf so Désactivé par variable de configuration    =
	// =======================================================================================
	/*	if ( VAR_GET_BOOL ( ptrVariablesConf,VAR_CONF_ID_DESACTIVER_IMPRESSION,0) != TRUE )
		{

			// On réinitialise le nombre de tentatives de connexion
			// ----------------------------------------------------
			nbTentativeConnexion = 0;

			// On boucle pour essayer de se reconnecter si port COM occupé
			// -----------------------------------------------------------
			do
			{
				DisableBreakOnLibraryErrors ();
				ptrSlot->comImprimante.iStatus = RS232_MAIN_OpenPort (  &ptrSlot->comImprimante.iHandle,
																		ptrSlot->comImprimante.tConfig,
																		&ptrSlot->comImprimante.iErrorOccured,
																		&ptrSlot->comImprimante.iErrorCode,
																		ptrSlot->comImprimante.sErrorMsg);
				EnableBreakOnLibraryErrors ();
				if (ptrSlot->comImprimante.iErrorOccured)
				{
					// On demande à fermer l'hyperterminal sur le port Com qui sort en erreur
					// --------------------------------------------------------------------
					if (nbTentativeConnexion < (COM_NB_TENTATIVE_CONNEXION - 1))
					{
						sprintf(chMessInfo, "Arrêter l'HyperTerminal (ou libérer le port) sur le port %d",ptrSlot->comImprimante.tConfig.numPort);
						MessagePopup (GET_MESSAGE(IHM_COM_TTR_POPUP), chMessInfo);
					}
					// Sinon on sort en erreur
					// -----------------------
					else
					{
						Fmt (chMess, GET_MESSAGE(GENERIQUE_MSG_POPUP_CODE), ptrSlot->comImprimante.iErrorCode, ptrSlot->comImprimante.sErrorMsg);
						Fmt (chMess, GET_MESSAGE(IHM_COM_MSG_POPUP_2), ptrSlot->comImprimante.sErrorMsg, ptrSlot->comImprimante.tConfig.numPort );
						ClipboardPutText (chMess);
						Fmt(chMess, GET_MESSAGE(GENERIQUE_MSG_POPUP_PRESSE_PAPIER), chMess);
						MessagePopup (GET_MESSAGE(IHM_COM_TTR_POPUP), chMess);
					}
					nbTentativeConnexion++;
				}
			} while ( ptrSlot->comImprimante.iErrorOccured && nbTentativeConnexion < COM_NB_TENTATIVE_CONNEXION );

			if (nbTentativeConnexion == COM_NB_TENTATIVE_CONNEXION)
				return -1;
		} */
	do
	{
		DisableBreakOnLibraryErrors ();
		ptrSlot->comCaisson.tConfig.baud = 9600;//115200;//;
		ptrSlot->comCaisson.iStatus = RS232_MAIN_OpenPort (    &ptrSlot->comCaisson.iHandle,
									  ptrSlot->comCaisson.tConfig,
									  &ptrSlot->comCaisson.iErrorOccured,
									  &ptrSlot->comCaisson.iErrorCode,
									  ptrSlot->comCaisson.sErrorMsg);
		EnableBreakOnLibraryErrors ();
		if (ptrSlot->comCaisson.iErrorOccured )
		{
			// On demande à fermer l'hyperterminal sur le port Com qui sort en erreur
			// --------------------------------------------------------------------
			if (nbTentativeConnexion < (STB_NB_TENTATIVE_CONNEXION - 1))
			{
				sprintf(chMessInfo, "Arrêter l'HyperTerminal (ou libérer le port) sur le port %d",ptrSlot->comCaisson.tConfig.numPort);
				MessagePopup (GET_MESSAGE(IHM_COM_TTR_POPUP), chMessInfo);
			}
			// Sinon on sort en erreur
			// -----------------------
			else
			{
				Fmt (chMess, GET_MESSAGE(IHM_COM_MSG_POPUP_2), ptrSlot->comCaisson.sErrorMsg, ptrSlot->comCaisson.tConfig.numPort );
				ClipboardPutText (chMess);
				Fmt(chMess, GET_MESSAGE(GENERIQUE_MSG_POPUP_PRESSE_PAPIER), chMess);
				MessagePopup (GET_MESSAGE(IHM_COM_TTR_POPUP), chMess);
			}
			nbTentativeConnexion++;
		}

	}
	while ( ptrSlot->comCaisson.iErrorOccured && nbTentativeConnexion < STB_NB_TENTATIVE_CONNEXION );

	if (nbTentativeConnexion == STB_NB_TENTATIVE_CONNEXION)
		return -1;





	return 0;

}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
void FCT_RemplacerEscapeSequence ( char *chValeur )
{
	char    *ptrTag;
	char    *ptrValeur = chValeur;
	char    chValeurTmp[4096] = {'\0'};
	char    idxHex;


	// ==========================================================================================
	// = Si la chaine en entrée est plus grande que le buffer de travail on sort de la fonction =
	// ==========================================================================================
	if ( strlen(chValeur) >= 4096 )
		return;

	// ====================================================================
	// = Tant que le Tag à remplacer est trouvé dans la chaine on continu =
	// ====================================================================
	do
	{
		// Recherche du Tag
		// ----------------
		ptrTag = strchr ( ptrValeur, '\\' );

		// Remplacement si Tag trouvé
		// --------------------------
		if( ptrTag != NULL )
		{
			switch ( CODE_ASCII[ptrTag[1]] )
			{
					// Code non reconnu => pas de remplacement
					// ---------------------------------------
				case 0x00:
					strncat ( chValeurTmp, ptrValeur, ((ptrTag+1) - ptrValeur) );
					ptrValeur = ptrTag+1;
					break;

					// Code en hexa
					// ------------
				case 0x01:
					strncat ( chValeurTmp, ptrValeur, (ptrTag - ptrValeur) );
					idxHex = (CODE_HEXA[ptrTag[2]] * 16) + CODE_HEXA[ptrTag[3]];
					if ( idxHex == -17 )
					{
						strcat ( chValeurTmp, "\\" );
						ptrValeur = ptrTag+1;
					}
					else
					{
						strncat ( chValeurTmp, &(idxHex), 1 );
						ptrValeur = ptrTag+4;
					}
					break;

					// Code en octal
					// -------------
				case 0x02:
					strncat ( chValeurTmp, ptrValeur, (ptrTag - ptrValeur) );
					if ( ((CODE_HEXA[ptrTag[2]] >= 0) && (CODE_HEXA[ptrTag[2]] <= 8)) &&
							((CODE_HEXA[ptrTag[3]] >= 0) && (CODE_HEXA[ptrTag[3]] <= 8))
					   )
					{
						idxHex = (CODE_HEXA[ptrTag[1]] * 64) + (CODE_HEXA[ptrTag[2]] * 8) + CODE_HEXA[ptrTag[3]];
						strncat ( chValeurTmp, &(idxHex), 1 );
						ptrValeur = ptrTag+4;
					}
					else
					{
						strcat ( chValeurTmp, "\\" );
						ptrValeur = ptrTag+1;
					}
					break;

					// Code spécial
					// ------------
				default:
					strncat ( chValeurTmp, ptrValeur, (ptrTag - ptrValeur) );
					strncat ( chValeurTmp, &(CODE_ASCII[ptrTag[1]]), 1 );
					ptrValeur = ptrTag+2;
					break;

			}

		}

	}
	while( ptrTag != NULL );

	// ===================================================
	// = Si Tag trouvé on met à jour la chaine en sortie =
	// ===================================================
	if ( chValeur != ptrValeur )
	{
		strcat ( chValeurTmp, ptrValeur );
		strcpy ( chValeur, chValeurTmp );
	}
}


// ==============================================================================
// FONCTION :		FCT_Controle_version
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			05/05/20
//  AUTEUR :		CH_BK
//  DESCRIPTION :   Controle version appli
// ==============================================================================

int FCT_ControleVersion (void)
{
	int  Status=0;
	T_VARIABLES			*ptrVariablesConf = &gSlot[0].variablesConf;

	strcpy(sVersionSoft, VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_Version,0));

	if (strcmp( VERSION_SOFT,sVersionSoft) != 0)

		return -1 ;


	return Status;
}

// ==============================================================================
// FONCTION :		FCT_Lecture_Version
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			11/05/2020
//  AUTEUR :		CH_BK
//  DESCRIPTION :   Lecture version TT
// ==============================================================================

int FCT_Lecture_Version (int nItfe, char	*chMessageErreur )
{

	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_LECTURE_VERSION,0), NULL, NULL,NULL, 3);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,GET_MESSAGE(FCT_LIBELLE_ERREUR_VERSION_TT));
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));


	return Status;
}

// ==============================================================================
// FONCTION :		FCT_TAMPON
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			30/11/2022
//  AUTEUR :		Sameh
//  DESCRIPTION :
// ==============================================================================

/* FCT_TAMPON (int nItfe )
{

	T_VARIABLES_TRACA		*ptrVariablesTraca = &gSlot[nItfe].variablesTraca;
	int error = 0;
	char strErreurMessage[256]= {"\0"};



	errChk (SCPROD_StartSnPFIN(    nItfe,
									&gTcomBase,
									"TAMPON",
									"Default",
									strErreurMessage ));

	errChk (SCPROD_CompleteSnPFIN(    nItfe,
									&gTcomBase,
									"TAMPON",
									"Default",
									strErreurMessage ));

Error:
	if(error)
	{
		if (strlen(strErreurMessage))
		{
			FCT_AfficheInfo (nItfe,IHM_MODE_TRACE_LOG,"Erreur tampon",strErreurMessage);
			FCT_AfficheInfo (nItfe,IHM_MODE_TRACE_TXTBOX,"Erreur tampon",strErreurMessage);
		}
		if(strErreurMessage[0]=='\0')
			sprintf(strErreurMessage,"PROBLEME PASSAGE TAMPON");
		return -1;

	}
	ptrVariablesTraca->iStartOK =1;



	return 0;
}
*/


// ==============================================================================
// FONCTION :     FCT_FermeturePortsCOM
// ------------------------------------------------------------------------------
// PROTOTYPE :    int FCT_FermeturePortsCOM ( int nItfe, char *strErreurMessage )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe   				: Index du SLOT.
//                - char *strErreurMessage   	: Message d'erreur
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Fonction de configuration des ports COM (déport depuis la création IHM)
//
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S08012DA73
//  DATE :        15/02/2013
//  AUTEUR :      MPT
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :
//  DATE :
//  AUTEUR :
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================


int FCT_FermeturePortsCOM ( int nItfe, char *strErreurMessage )

{

	char    chMess[1024];
	T_SLOT  *ptrSlot = &(gSlot[nItfe]);


	// Fermeture Port COM STB si ouvert
	// --------------------------------
	if ( ptrSlot->comDecodeur.iHandle != 0 )
	{
		ptrSlot->comDecodeur.iStatus = RS232_MAIN_ClosePort (   ptrSlot->comDecodeur.iHandle,
									   &ptrSlot->comDecodeur.iErrorOccured,
									   &ptrSlot->comDecodeur.iErrorCode,
									   ptrSlot->comDecodeur.sErrorMsg);

		if (ptrSlot->comDecodeur.iStatus == S_FALSE)
		{
			Fmt (chMess, GET_MESSAGE(IHM_COM_MSG_POPUP_1), ptrSlot->comDecodeur.sErrorMsg, ptrSlot->comDecodeur.tConfig );
			MessagePopup (GET_MESSAGE(IHM_COM_TTR_POPUP), chMess);
		}
	}
	/*
	  // Fermeture Port COM InfraRouge si ouvert
	  // ---------------------------------------
	  if ( ptrSlot->comIr.iHandle != 0 )
	  {
		  ptrSlot->comIr.iStatus = RS232_MAIN_ClosePort ( ptrSlot->comIr.iHandle,
														  &ptrSlot->comIr.iErrorOccured,
														  &ptrSlot->comIr.iErrorCode,
														  ptrSlot->comIr.sErrorMsg);
		  if (ptrSlot->comIr.iStatus == S_FALSE)
		  {
			  Fmt (chMess, GET_MESSAGE(IHM_COM_MSG_POPUP_1), ptrSlot->comIr.sErrorMsg, ptrSlot->comIr.iHandle );
			  MessagePopup (GET_MESSAGE(IHM_COM_TTR_POPUP), chMess);
		  }
	  }

	  // Fermeture Port COM Wattmetre si ouvert
	  // --------------------------------------
	  if ( ptrSlot->comGenerique_A.iHandle != 0 )
	  {
		  ptrSlot->comGenerique_A.iStatus = RS232_MAIN_ClosePort (ptrSlot->comGenerique_A.iHandle,
															  &ptrSlot->comGenerique_A.iErrorOccured,
															  &ptrSlot->comGenerique_A.iErrorCode,
															  ptrSlot->comGenerique_A.sErrorMsg);
		  if (ptrSlot->comGenerique_A.iStatus == S_FALSE)
		  {
			  Fmt (chMess, GET_MESSAGE(IHM_COM_MSG_POPUP_1), ptrSlot->comGenerique_A.sErrorMsg, ptrSlot->comGenerique_A.iHandle );
			MessagePopup (GET_MESSAGE(IHM_COM_TTR_POPUP), chMess);
		  }
	  }

	// Fermeture Port COM Zebra si ouvert
	  // ----------------------------------
	  if ( ptrSlot->comImprimante.iHandle != 0 )
	  {
		  ptrSlot->comImprimante.iStatus = RS232_MAIN_ClosePort (ptrSlot->comImprimante.iHandle,
															  &ptrSlot->comImprimante.iErrorOccured,
															  &ptrSlot->comImprimante.iErrorCode,
															  ptrSlot->comImprimante.sErrorMsg);
		  if (ptrSlot->comImprimante.iStatus == S_FALSE)
		  {
			  Fmt (chMess, GET_MESSAGE(IHM_COM_MSG_POPUP_1), ptrSlot->comImprimante.sErrorMsg, ptrSlot->comImprimante.iHandle );
			MessagePopup (GET_MESSAGE(IHM_COM_TTR_POPUP), chMess);
		  }
	  }
	  */

	return 0;
}
/*// ==============================================================================
// FONCTION :		FCT_VerifChipsetId
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			05/10/2020
//  AUTEUR :		CH_BK
//  DESCRIPTION :   Vérif ChipID
// ==============================================================================

int FCT_VerifChipsetId (int nItfe, char	*chMessageErreur )
{
	short               erreur = 0;
	int                 idPort = gSlot[nItfe].comDecodeur.iHandle;
	int                 i,ii;
	int                 error = 0;
	int                 timeout = 10;
	int                 iChipSecuriseHex;
	int             	nbInfos = 0;
	int                 iDeviceId = 0;
	int 				ilen;
	long                codeErreur = 0;
	long                iChipsetId;
	unsigned long       taille_recu;
	char                chMessErreur[TAILLE_MAX] = {"\0"};
	char                chTrace[TAILLE_MAX] = {'\0'};
	char                chBufferLu[TAILLE_MAX] = {"\0"};
	char				*BufferTemp = NULL;
	char            	**infos = NULL;
	char                chDeviceId[9] = {'\0'};
	char 				chChipsetSnTemp[17]= {"\0"};
	char 				chChipsetSn16[17]= {"\0"};
	char 				chChipsetKSV[17]= {"\0"};
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	T_VARIABLES         *ptrVariablesConf = &(gSlot[nItfe].variablesConf);
	T_VARIABLES         *ptrVariablesEtat = &(gSlot[nItfe].variablesEtat);


	char				chCaStbHex[100] = {"\0"};
	char 				chChipsetSnNds[9]= {"\0"};
	long                lChipsetHex4Bytes = 0X00;
	long                lCaStbIdHex = 0X00;
	char 				chChipsetSn_5a5a5a5a5a5a5a5a[17]= {"\0"};
	char 				chChipsetSnBase[128] = {"\0"};
	char 				chCiuBase[128] = {"\0"};
	int					iExistenceSFC;
	int                 nbInfos = 0;
	char                **infos = NULL;
	char                chChipID[TAILLE_MIN]="";


		// On vide le buffer
		// -----------------
		sprintf(chBufferLu,"");


		// Autres, exemples: 7109, ...
		// ---------------------------
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BNFT_CMD_ChipID,0), &infos,&nbInfos,NULL, 5);



		if (Status != 0)
		{

			strcpy(chMessageErreur,"Erreur lecture ChipsetID");
			return -1;

		}

		if(nbInfos > 0 && (strlen(infos[0]) == 18))
		{
			sprintf(chChipID,"%s%s",VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BNFT_TAG_DFA_MERE,0),infos[0]);
			strcpy(ptrVariablesTraca->CieSn,chTagDfa);
		}
		else
		{

			strcpy(chMessageErreur,"Erreur lecture ChipsetID");
			return -1;

		}



		// Read 0x20cf7ad6 (hex) = 550468310 (dec)
		// Traitement de la chaine de retour en hexa
		// -----------------------------------------
		BufferTemp = strstr(chBufferLu, "ID = ");
		if (BufferTemp != NULL)
			strcpy (chTrace, BufferTemp);
		else
		{
			sprintf (chMessErreur, GET_MESSAGE(FCT_MSG_ERREUR_DE_COM));
			return -1;
		}


		// On récupère le chipset ID depuis la trace ==> Peut faire 16, 8 ou moins de caractères...
		// ----------------------------------------------------------------------------------------
		sscanf (chTrace, "ID = 0x%s", ptrVariablesTraca->chChipsetSnHex );
		// ------------------------------------------
		// Vérification du ChipsetId assemblé en base
		// ------------------------------------------
		if (VAR_GET_BOOL(ptrVariablesConf,VAR_CONF_ID_CONTROLECHIPSETSN,0) == TRUE)
		{
			// Mise en forme du Composant
			// --------------------------
			sprintf(chChipsetSnBase,"ETAT_DEC_GEN_SCHIPSETID=0X%s",ptrVariablesTraca->chChipsetSnHex);
			StringUpperCase (chChipsetSnBase);

			// On récupere le ChipsetId assemblé en base
			// -----------------------------------------
			SCPROD_RecuperationSFCDepuisComposant ( nItfe,
													&gTcomBase,
													chChipsetSnBase,
													&chCiuBase,
													&iExistenceSFC,
													chMessErreur );

			// On compare le SFC parent et le SFC en cours de test
			// ---------------------------------------------------
			if(strcmp(chCiuBase,ptrVariablesTraca->CiuSfcSAPME)!=0)
			{
				sprintf (chMessErreur, GET_MESSAGE(FCT_MSG_ERR_CHIPSET_ID_SFC));
				return -1;
			}

		}
		// Si lg ptrVariablesTraca->chChipsetSnHex est inférieure à 8 digits, on complète pour pouvoir récupérer la clé cscd
		// ------------------------------------------------------------------------------------------------------------------
		if ((strlen ( ptrVariablesTraca->chChipsetSnHex  ) < 8 ))
		{
			sscanf (ptrVariablesTraca->chChipsetSnHex, "%x", &iChipsetId);
			sprintf (ptrVariablesTraca->chChipsetSnHex, "%08x", iChipsetId);

			// Verif 8 caractères
			// -------------------
			if ((strlen ( ptrVariablesTraca->chChipsetSnHex  ) != 8 ))
				return -1;
		}


		// On pourrait vérifier que le  Chipset SN a bien une longueur de 8 ou 16 caractères. ==> on ne le fait pas au cas où certains chipset SN de 16 caractères commencent par des 0.Pas genant pour les clés ni pour la remontée en base
		// ------------------------------------------------------------------------
		// if ((strlen ( ptrVariablesTraca->chChipsetSnHex  ) != 8 ) || (strlen ( ptrVariablesTraca->chChipsetSnHex  ) != 16 ))
		//	errChk (-1);


		// Pour la remontée en base, on utilise la variable  chChipsetSn16
		// ---------------------------------------------------------------
		strcpy ( chChipsetSn16, ptrVariablesTraca->chChipsetSnHex);

		// On complète par des zéros devant pour faire 16 caractères VAR_ETAT_ID_CHIPSET_SN
		// --------------------------------------------------------------------------------
		ilen = (TAILLE_CHIPSET_SN - strlen( chChipsetSn16 ) );
		for (ii = 0; ii < ilen; ii ++)
		{
			sprintf( chChipsetSnTemp, "0%s", chChipsetSn16);
			strcpy( chChipsetSn16, chChipsetSnTemp);

		}

		// Verif 16 caractères
		// -------------------
		if ((strlen ( chChipsetSn16  ) != 16 ))
			return -1;

		// Traitement specifique pour contourner le problème des chipset read
		//-------------------------------------------------------------------
		strcpy(chChipsetSn_5a5a5a5a5a5a5a5a,chChipsetSn16);

		if(strcmp(chChipsetSn_5a5a5a5a5a5a5a5a,"5a5a5a5a5a5a5a5a")== 0)
		{
			strcpy ( VAR_SET_STRING(ptrVariablesEtat,VAR_ETAT_ID_CHIPSET_SN,0), ptrVariablesTraca->PfinSfcSAPME );
		}
		else
		{
			strcpy ( VAR_SET_STRING(ptrVariablesEtat,VAR_ETAT_ID_CHIPSET_SN,0), chChipsetSn16 );
			//Enregistrement du chip sn comme dc sous SAPME pour imprission etiquette
			//-----------------------------------------------------------------------
			if ( VAR_DEFINED(ptrVariablesEtat,VAR_ETAT_ID_CHIPSET_SN_SAPME) == TRUE )
				strcpy ( VAR_SET_STRING(ptrVariablesEtat,VAR_ETAT_ID_CHIPSET_SN_SAPME,0), chChipsetSn16 );
		}


		// On contrôle que le chipset sn n'est pas égal à "0"
		// --------------------------------------------------
		if  ( strcmp(chChipsetSn16,"0000000000000000") == 0)
		{
			sprintf (chMessErreur, "Chipset ID = 0");
			return -1;
		}


		// On copie uniquement les 8 carcteres soit 4 premier bytes pour besoin provisionning
		//------------------------------------------------------------------------------------
		if ( VAR_DEFINED(ptrVariablesEtat,VAR_ETAT_ID_CHIPSET_SN_NDS) == TRUE )
		{
			strcpy ( chChipsetSnNds,"\0");
			strncpy ( chChipsetSnNds, chChipsetSn16,8 );
			StringUpperCase(chChipsetSnNds);
			strcpy (VAR_SET_STRING(ptrVariablesEtat,VAR_ETAT_ID_CHIPSET_SN_NDS,0), chChipsetSnNds);
		}

		// Calcule CA_STB_ID
		//------------------
		if ( VAR_DEFINED(ptrVariablesEtat,VAR_ETAT_ID_CA_STB_ID) == TRUE )
		{

			// Spec pour Vodafone + CAS NDS : CA STB ID = lChipsetHex4Bytes XOR 0x80000000;
			//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			strcpy ( chChipsetSnNds,"\0");
			strcpy(chCaStbHex,"\0");
			lChipsetHex4Bytes = 0x00;
			lCaStbIdHex = 0x00;
			strncpy ( chChipsetSnNds, chChipsetSn16,8 );
			sscanf (chChipsetSnNds, "%x", &lChipsetHex4Bytes );
			lCaStbIdHex = lChipsetHex4Bytes ^ 0x80000000;
			sprintf(chCaStbHex,"%x",lCaStbIdHex);
			StringUpperCase(chCaStbHex);

			// Remonté de la CA ID STB dans la variable etat_DEC_BTF_sCaStbId
			//----------------------------------------------------------------
			strcpy(VAR_SET_STRING(ptrVariablesEtat,VAR_ETAT_ID_CA_STB_ID,0),chCaStbHex);


			// TO DO : Mettre un systeme de calcule par produit ou extarnaliser les traitement .....
			//--------------------------------------------------------------------------------------
		}



	return 0;
}
*/
// ==============================================================================
// FONCTION :     TST_Leds_Feasa  Famille Voda
// ------------------------------------------------------------------------------
// PROTOTYPE :    int TST_Leds_Feasa (int nItfe,int *dureeTest )
// ------------------------------------------------------------------------------
// ARGUMENTS :
//                - int nItfe       	 : Index du SLOT en test
//                - int *dureeTest       : Durée du test.
// ------------------------------------------------------------------------------
// RETOUR :
//                - 0 = Sortie de fonction normale
//                - < 0 = Erreur rencontré durant la fonction
// ------------------------------------------------------------------------------
// DESRIPTION :   Fonction de test Led (Avec utilisation modeul FEASA.
// ------------------------------------------------------------------------------
// MODIFICATION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :     S15003AA44
//  DATE :        30/10/2017
//  AUTEUR :      FZI
//  DESCRIPTION : Création.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int TST_Leds_Feasa (int nItfe, char	*chMessageErreur )
{
	/*
	T_VARIABLES_TRACA  *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	T_VARIABLES        *ptrVariablesConf = &(gSlot[nItfe].variablesConf);
	T_MESURES          *ptrMesures = &(gSlot[nItfe].mesures);
	short 			   error = 0;
	short			   status = 0;
	char        	chBuffLu[TAILLE_MAX] = {"\0"};
	char			chResultatMesure[2] = {"0"};
	char 			chTableauMesure[5][30] = {"0"};
	char            chSeqCouleur[5][5] = {"0"};
	int 			idPortFeasa = gSlot[nItfe].comGenerique_A.iHandle;
	int				iBlanc = 0;
	int             idureeMesure = 0;
	int             iNbLeds =  0;


	// On vérifie la configuration
	// ---------------------------
	if (VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_ID_NBRE_LEDS,0) > 0)
	{
		iNbLeds = VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_ID_NBRE_LEDS,0);


		if (VAR_NB_VAL(ptrVariablesConf,VAR_CONF_ID_SEQ_COUL_LEDS) != iNbLeds)
		{
			strcpy(chMessageErreur,"The number of LED in TRACACOM is different from the number of LEDs!!");
			MessagePopup ("Error",chMessageErreur);
			return -1;
		}

		// Maj Temps intermédiaire pour calcul temps de mesure
		// ---------------------------------------------------

		chBuffLu[0] = '\0';
		status = FCT_CmdComExecutionInstSansRetour (nItfe, idPortFeasa, FIL2LO_COM_FEASA_LEDS_RX, FIL2LO_COM_FEASA_LEDS_TX,AFFICHAGE_TRACE, "[capture{Pass:OK}]", NULL, NULL, chBuffLu, 5000) ;

		// On envoie La commande au module FEASA après réinitialisation du Buffer de retour en sortant en timeout de manière voulue car pas de tags de pass!!
		// ------------------------------------------------------------------------------------------------------------------------------------------------------
		chBuffLu[0] = '\0';
		status = FCT_CmdComExecutionInstSansRetour (nItfe, idPortFeasa, FIL2LO_COM_FEASA_LEDS_RX, FIL2LO_COM_FEASA_LEDS_TX,AFFICHAGE_TRACE, "[getrgbi01{Pass:OK}]", NULL, NULL, chBuffLu,5000) ;

		// Si on sort en timeout, on l'accepte car c'est du au fait qu'il n'y ait pas de prompt
		// -----------------------------------------------------------------------------------
		if (status == -2)
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, "Timeout not considered as an error because the Feasa Module has no prompt");

		// On scanne le buffer de retour pour récupérer la valeur mesuré du Led
		// ----------------------------------------------------------------------
		if (strcmp(VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_SEQ_COUL_LEDS,0),"R") == 0)
		{

			status = sscanf(chBuffLu,"%*s %s",chTableauMesure[0]);
		}
		else if(strcmp(VAR_GET_STRING(ptrVariablesConf,VAR_CONF_ID_SEQ_COUL_LEDS,0),"V") == 0)
		{
			status = sscanf(chBuffLu,"%*s %*s %s",chTableauMesure[0]);
		}
		else
			status = sscanf(chBuffLu,"%*s %*s %*s %s",chTableauMesure[0]);

		//status = sscanf(chBuffLu,"%*s %s",chTableauMesure[0]);
		// On récupère les R à partir de la ligne de la led dans le tableau
		// -------------------------------------------------------------------
		status = sscanf(chTableauMesure[0],"%d",&iBlanc);


		// Test ROUGE - Enregistrement et vérification résultat
		// ----------------------------------------------------
		if ( MES_Capturer ( ptrMesures, MES_TYPE_TEST_LED_1, chResultatMesure, iBlanc, idureeMesure ) != 0 )
		{
			FCT_AfficheInfo (nItfe, IHM_MODE_POPUP_ERREUR|IHM_MODE_TRACE_TXTBOX, MES_NON_DEFINIE, gMesuresBNFT[MES_TYPE_TEST_LED_1].nom);
			errChk (-1);
		}
		if ( strcmp( chResultatMesure, MES_STATUS_OK) != 0 )
		{
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(IHM_STR_ERREUR), GET_MESSAGE(THR_LIBELLE_ERREUR_LED));
			strcpy (ptrVariablesTraca->chLibelleErreur, GET_MESSAGE(THR_LIBELLE_ERREUR_LED));
			errChk (-1);
		}

	}
	else
	{
		//a aaffichier erruer confif test led
		sprintf(ptrVariablesTraca->chLibelleErreur,GET_MESSAGE(FCT_LIBELLE_ERREUR_CONFIGURATION));
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, IHM_STR_INFO, ptrVariablesTraca->chLibelleErreur);
		errChk (-1);


	}

	Error:
	// =======================
	// = gestion des erreurs =
	// =======================
	if(error)
	{
		sprintf(chMessageErreur,GET_MESSAGE(THR_LIBELLE_ERREUR_LED));
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, chMessageErreur);
		return -1;
	}
	*/
	return 0;
}


int FCT_CmdComExecutionInstSansRetour (int nItfe, int idPort, int ParamRX, int ParamTX, int AffichageTrace, char *chCmdTT, char ***info, int *nbInfo, char *chTrace, int timeout)
{
	short           erreur = 0;
	int             status = -1;
	int				i = 0,j = 0;
	int             error = 0;
	int             flagPatternPassFound=0;
	int             flagPatternFailFound=0;
	int             sizePattern;
	int             nValTempo;
	int             nTypeMsg;
	long            codeErreur = 0;
	unsigned long   countDeb;
	unsigned long   nbRetour;
	unsigned long   DimBuf;
	char            chMessErreur[512] = {"\0"};
	char            chBufferLu[TAILLE_MAX] = {"\0"};
	char            chBufferLuTmp[TAILLE_MAX] = {"\0"};
	char            chVal[512] = {"\0"};
	char            chPattern[512] = {"\0"};
	char            chCmd[256] = {"\0"};
	char            *ptrCmd = NULL;
	int             idxCmd = 0;
	T_TAB_CMD       tabCmdTT;
	char            chDernierCaractCle[TAILLE_AFFICHAGE_CLE+1] = {'\0'};
	int 			iTailleBufferLu;


	// ===============================
	// = RAZ des variables de retour =
	// ===============================
	if (nbInfo != NULL)
	{
		*nbInfo = 0;
		*info = NULL;
	}

	// ==========================================
	// = Extraction des commandes TT à exécuter =
	// ==========================================
	errChk (FCT_CmdComExtract (chCmdTT, &tabCmdTT));

	// ==============================
	// = Exécution des commandes TT =
	// ==============================
	for ( idxCmd=0 ; idxCmd<tabCmdTT.nbCmd ; idxCmd++ )
	{

		// ==================================
		// = RAZ des buffer RX/TX de la COM =
		// ==================================
		RS232_MAIN_PurgeTxPort (idPort, &erreur, &codeErreur, chMessErreur);
		errChk (codeErreur);
		RS232_MAIN_PurgeRxPort (idPort, &erreur, &codeErreur, chMessErreur);
		errChk (codeErreur);

		// Mise en casse inferieur de la commande
		// --------------------------------------
		i = 0;
		while (tabCmdTT.cmd[idxCmd].cmd[i] != '\0')
		{
			chCmd[i] = tolower (tabCmdTT.cmd[idxCmd].cmd[i]);
			i++;
		}
		chCmd[i] = '\0';

		// Mise à jour du Time Out si définis par la commande
		// --------------------------------------------------
		if (tabCmdTT.cmd[idxCmd].nTimeOut != -1)
			timeout = tabCmdTT.cmd[idxCmd].nTimeOut;

		// ==================================================================================
		// = GESTION DES COMMANDES APPLI PERSO                                              =
		// ==================================================================================
		if ( strstr ( chCmd, CMD_PERSO_TYPE_WAIT ) != NULL )
		{
			// ==============================================================================
			// = Commande appli perso : cmd_wait x (x durée en seconde de la temporisation) =
			// ==============================================================================

			// Enregistrement d'une trace de la commande
			// -----------------------------------------
			if ( chTrace != NULL )
				strcat (chTrace, tabCmdTT.cmd[idxCmd].cmd);

			// Extraction de la durée de la temporisation
			// ------------------------------------------
			sscanf ( chCmd, CMD_PERSO_FORMAT_WAIT, &nValTempo);

			// Exécution de la temporisation
			// -----------------------------
			Sleep (nValTempo * 1000);
		}
		else if ( strstr ( chCmd, CMD_PERSO_TYPE_DISPLAY ) != NULL )
		{
			// ==============================================================================
			// = Commande appli perso : cmd_display t mmmmm (t => type d'affichage,         =
			// = mmmmm => message à afficher)                                               =
			// ==============================================================================

			// Enregistrement d'une trace de la commande
			// -----------------------------------------
			if ( chTrace != NULL )
				strcat (chTrace, tabCmdTT.cmd[idxCmd].cmd);

			// Extraction du type du message à afficher
			// ----------------------------------------
			sscanf ( chCmd, CMD_PERSO_FORMAT_DISPLAY, &nTypeMsg);

			// Extraction du message à afficher
			// --------------------------------
			ptrCmd = strstr ( chCmd, CMD_PERSO_TYPE_DISPLAY ) + strlen (CMD_PERSO_TYPE_DISPLAY) + 2;
			while ( ((ptrCmd[0] == '\t') || (ptrCmd[0] == ' ')) &&  (ptrCmd[0] != '\0') )
			{
				ptrCmd++;
			}

			// Affichage du message
			// --------------------
			if ( ((nTypeMsg&CMD_PERSO_TYPE_DISPLAY_T_IHM) == CMD_PERSO_TYPE_DISPLAY_T_IHM) && (ptrCmd[0] != '\0') )
			{
				// Message type : Trace IHM
				// ------------------------
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, ptrCmd);
			}
			if ( ((nTypeMsg&CMD_PERSO_TYPE_DISPLAY_T_LOG) == CMD_PERSO_TYPE_DISPLAY_T_LOG) && (ptrCmd[0] != '\0') )
			{
				// Message type : Trace fichier LOG
				// --------------------------------
				FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, ptrCmd);
			}
			if ( ((nTypeMsg&CMD_PERSO_TYPE_DISPLAY_T_BOX) == CMD_PERSO_TYPE_DISPLAY_T_BOX) && (ptrCmd[0] != '\0') )
			{
				// Message type : Fenêtre
				// ----------------------
				FCT_AfficheInfo (nItfe, IHM_MODE_POPUP_INFO, 999, ptrCmd);
			}
		}
		else
		{
			// ==================================================================================
			// = GESTION DES COMMANDES TT                                                       =
			// ==================================================================================

			// =============================================
			// = Enregistrement d'une trace de la commande =
			// =============================================
			if ( chTrace != NULL )
				strcat (chTrace, tabCmdTT.cmd[idxCmd].cmd);

			// ===========================
			// = Envoi de la commande TT =
			// ===========================
			chBufferLu[0] = '\0';
			if ( AffichageTrace == AFFICHAGE_TRACE )
				FIL2LO_PrintCom (nItfe, ParamRX, tabCmdTT.cmd[idxCmd].cmd);
			status = RS232_CONF_EcrirePort (idPort,
											tabCmdTT.cmd[idxCmd].cmd,
											strlen(tabCmdTT.cmd[idxCmd].cmd),
											&erreur,
											&codeErreur,
											chMessErreur);
			errChk (codeErreur);

			// =================================================
			// = Vérification du retour STB ('Pass' ou 'Fail') =
			// =================================================
			countDeb = GetTickCount();
			for ( i=0 ; i<tabCmdTT.cmd[idxCmd].nbPass ; i++ )
			{
				flagPatternPassFound = FALSE;
				flagPatternFailFound = FALSE;
				do
				{
					// Temporisation de 5ms
					// ----------------------
					Sleep (5);

					// Lecture du port COM
					// -------------------
					memset (chBufferLuTmp, '\0', (sizeof(unsigned char) * TAILLE_MAX));
					status = RS232_MEAS_LectureBuffer ( idPort,
														chBufferLuTmp,
														&nbRetour,
														TAILLE_MAX,
														&DimBuf,
														&erreur,
														&codeErreur,
														chMessErreur);
					errChk (codeErreur);

					// Concaténation des données reçues dans le buffer de réception, si le buffer n'est pas plein
					// ------------------------------------------------------------------------------------------
					if ( ((strlen(chBufferLu) + strlen(chBufferLuTmp)) < TAILLE_MAX) && (strlen(chBufferLuTmp)) )
					{
						strcat (chBufferLu, chBufferLuTmp);
						if ( AffichageTrace == AFFICHAGE_TRACE )
							FIL2LO_PrintCom (nItfe, ParamTX, chBufferLuTmp);

						// Enregistrement d'une trace de la réponse
						// ----------------------------------------
						if ( chTrace != NULL )
							strcat (chTrace, chBufferLuTmp);
					}

					// On vérifie si le retour 'pass' attendu a été envoyé par le STB
					// --------------------------------------------------------------
					if (strstr (chBufferLu, tabCmdTT.cmd[idxCmd].pass[i]) != NULL)
						flagPatternPassFound = TRUE;

					// On vérifie si le retour 'fail' attendu a été envoyé par le STB
					// --------------------------------------------------------------
					flagPatternFailFound = FALSE;
					for ( j=0 ; j<tabCmdTT.cmd[idxCmd].nbFail ; j++ )
					{
						// On vérifie si le retour fail attendu a été envoyé par le STB
						// ------------------------------------------------------------
						if (strstr (chBufferLu, tabCmdTT.cmd[idxCmd].fail[j]) != NULL)
						{
							flagPatternFailFound = TRUE;
							break;
						}
					}

				}
				while ( ((int)(GetTickCount()-countDeb) < timeout) && (flagPatternPassFound == FALSE) && (flagPatternFailFound == FALSE) );


				// Affichage des 50 derniers caractères du buffer de retour
				// --------------------------------------------------------
				if (AffichageTrace == AFFICHAGE_RETOUR_CLE)
				{
					iTailleBufferLu = strlen(chBufferLu);

					// Si Bufferlu > 50
					// ----------------
					if((iTailleBufferLu-TAILLE_AFFICHAGE_CLE) >0)
					{
						CopyString (chDernierCaractCle, 0, chBufferLu, (iTailleBufferLu-TAILLE_AFFICHAGE_CLE), TAILLE_AFFICHAGE_CLE);
						FIL2LO_PrintCom (nItfe, ParamTX, chDernierCaractCle);
					}
					// Si Bufferlu <= 50
					// -----------------
					else
						FIL2LO_PrintCom (nItfe, ParamTX, chBufferLu);
				}

				// Affichage seulement si retour OK
				// --------------------------------
				if ((AffichageTrace == (AFFICHAGE_RETOUR_OK|MASQUE_ERR)) && (flagPatternPassFound == TRUE) && (flagPatternFailFound != TRUE))
				{
					FIL2LO_PrintCom (nItfe, ParamRX, tabCmdTT.cmd[idxCmd].cmd);
					FIL2LO_PrintCom (nItfe, ParamTX, chBufferLu);
				}
			}

			// ========================
			// = Extraction des infos =
			// ========================
			if ( (flagPatternFailFound != TRUE) && (flagPatternPassFound == TRUE) )
			{
				flagPatternPassFound = FALSE;

				if (nbInfo != NULL)
				{
					for ( i=0 ; i<tabCmdTT.cmd[idxCmd].nbInfo ; i++ )
					{
						// On vérifie le format du pattern à rechercher
						// --------------------------------------------
						if ( strchr (tabCmdTT.cmd[idxCmd].info[i], '%') != NULL )
						{
							// Remplace le '%' par '%s' dans la chaine de recherche
							// ----------------------------------------------------
//GCX_DEBUG
							sizePattern = strchr (tabCmdTT.cmd[idxCmd].info[i], '%') - tabCmdTT.cmd[idxCmd].info[i] + 1;
							strncpy (chPattern, tabCmdTT.cmd[idxCmd].info[i], sizePattern);
							chPattern[sizePattern-1] = '\0';

							// extraction juusqu'au retour à la ligne
							// --------------------------------------
							if (FCT_RechercheTag ( chBufferLu, chPattern, chVal ) == 0)
							{
								// Si une chaine est extraite : enregistrer cette chaine dans le buffer de retour
								// ------------------------------------------------------------------------------
								if ( strlen (chVal) > 0 )
								{
									// On incrémente le nombre d'infos extraits
									// ----------------------------------------
									(*nbInfo)++;

									// Allocation dynamique de mémoire pour le stockage des infos extraits
									// -------------------------------------------------------------------
									(*info) = (char**) realloc( *info, sizeof(char*) * (*nbInfo) );
									(*info)[(*nbInfo)-1] = (char*) malloc( sizeof(char) * 512 );

									// Enregistrement de l'info extrait
									// --------------------------------
									strcpy ( (*info)[(*nbInfo)-1], chVal);
								}
								else
								{
									// Problème d'extraction d'info : aucune chaine extraite
									// -----------------------------------------------------
									errChk (-4);
								}
							}
							else
							{
								// Problème d'extraction d'info : pattern de recherche non trouvé
								// --------------------------------------------------------------
								errChk (-4);
							}
						}

						// "Non Remonte"
						// -------------
						else if ( strstr (tabCmdTT.cmd[idxCmd].info[i], TAG_NON_REMONTE) != NULL )
						{
							// On incrémente le nombre d'infos extraits
							// ----------------------------------------
							(*nbInfo)++;

							// Allocation dynamique de mémoire pour le stockage des infos extraits
							// -------------------------------------------------------------------
							(*info) = (char**) realloc( *info, sizeof(char*) * (*nbInfo) );
							(*info)[(*nbInfo)-1] = (char*) malloc( sizeof(char) * 512 );

							// L'info n'est pas renseignée
							// ---------------------------
							strcpy ( (*info)[(*nbInfo)-1], TAG_NON_REMONTE);
						}
						else
						{
							// Problème d'extraction d'info : format du pattern de recherche incorrect
							// -----------------------------------------------------------------------
							errChk (-4);
						}
					}
				}
			}
			else if (flagPatternFailFound == TRUE)
				// Reception d'une chaine 'Fail' => sort de la fonction avec un code d'erreur
				// --------------------------------------------------------------------------
				errChk (-3);
			else
				// Time out en réception => sort de la fonction avec un code d'erreur
				// ------------------------------------------------------------------
				errChk (-2);
		}
	}

Error:
	if(error)
	{
		if ( (AffichageTrace & MASQUE_ERR) != MASQUE_ERR )
		{
			if (error == -3)
				sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_FAIL), tabCmdTT.cmd[idxCmd].cmd);
			else if (error == -4)
				sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_NON_TROUVE_STRING), tabCmdTT.cmd[idxCmd].cmd, tabCmdTT.cmd[idxCmd].info[i]);
		}
		return -1;
	}

	return 0;
}

// ==============================================================================
// FONCTION :		Connect_Switch_SP8T
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			14/09/2020
//  AUTEUR :		CH_BK
//  DESCRIPTION :   Initialisation Switch SP8T
// ==============================================================================

int Connect_Switch_SP8T (int nItfe, char	*chMessageErreur )
{

	int    iNumBytWritten=0;
	int    status=-1;
	int    Ping=-1;
	time_t startSCOS=0;
	time_t stopSCOS=0 ;
	char   Buffer[2000]="";
	gSlot[nItfe].HandleTelnetSwitch_SP8T = -1;

	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999, GET_MESSAGE(TFC_MSG_ATTENTE_PING));
	time(&startSCOS);
	do
	{
		status = InetPing (gSlot[nItfe].BNFTnteg.gchAdressIPSwitchRFSP8T, &Ping, 5000);
		time(&stopSCOS);
	}
	while((Ping!=1)&& (difftime(stopSCOS,startSCOS)<5));

	if (Ping != 1)
	{

		strcpy (chMessageErreur,"Ping Switch KO !!!");
		return -1;

	}

	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "Ping Switch OK");


	return status;

}

// ==============================================================================
// FONCTION :		FCT_Switch
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			17/11/2020
//  AUTEUR :		CH_BK
//  DESCRIPTION :   Initialisation Switch
// ==============================================================================

int FCT_Switch (int nItfe, char	*chMessageErreur )
{

	int    iNumBytWritten=0;
	int    status=0;
	char   Buffer[TAILLE_MOY]="";
	char   cmd[TAILLE_MIN]="";

	if (gSlot[nItfe].BNFTnteg.gFlagSP8T)
	{

		gSlot[nItfe].HandleTelnetSwitch_SP8T = -1;

		gSlot[nItfe].HandleTelnetSwitch_SP8T = InetTelnetOpen ( gSlot[nItfe].BNFTnteg.gchAdressIPSwitchRFSP8T,23, 0);

		if (gSlot[nItfe].HandleTelnetSwitch_SP8T < 0)
		{

			sprintf (chMessageErreur,GET_MESSAGE(FCT_LIBELLE_ERREUR_CNX_TELNET_SWITCH) ,gSlot[nItfe].BNFTnteg.gchAdressIPSwitchRFSP8T);
			return -1;

		}
		status = FCT_CmdComExecutionV4 (nItfe, gSlot[nItfe].HandleTelnetSwitch_SP8T, AFFICHAGE_TRACE, "[PWD=123;{Pass:1}]", NULL, NULL, NULL, 3000);

		if (status != 0)
		{

			strcpy (chMessageErreur,GET_MESSAGE(FCT_LIBELLE_ERREUR_PASSWORD_SWITCH));
			return -1;

		}



	}
	return status;

}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  VERSION :V1.0.0
//  DATE : 15/09/20
//  AUTEUR : CH_BK
//  DESCRIPTION :
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ==============================================================================
int FCT_CmdComExecutionV4 (int nItfe,int HandleTelnet ,int AffichageTrace, char *chCmdTT, char ***info, int *nbInfo, char *chTrace, int timeout)
{
	short           erreur = 0;
	int             status = -1;
	int				i = 0,j = 0;
	int             idPort = gSlot[nItfe].comDecodeur.iHandle;
	int             error = 0;
	int             flagPatternPassFound = FALSE;
	int             flagPatternFailFound = FALSE;
	int             sizePattern;
	int             nValTempo;
	int             nTypeMsg;
	int             idxCmd = 0;
	int 			iTailleBufferLu;
	long            codeErreur = 0;
	unsigned long   countDeb;
	unsigned long   nbRetour;
	unsigned long   DimBuf;
	char            chMessErreur[TAILLE_MAX] = {"\0"};
	char            chBufferLu[67000] = {"\0"};
	char            chBufferLuTmp[TAILLE_MAX] = {"\0"};
	char            chVal[FCT_RECUP_INFO_TAILLE_MAX] = {"\0"};
	char            chPattern[512] = {"\0"};
	char            chCmd[TAILLE_MIN] = {"\0"};
	char            *ptrCmd = NULL;
	char            chDernierCaractCle[TAILLE_MIN+1] = {'\0'};
	char			*ptrPassMultiple = NULL;
	char			chTampon[TAILLE_MIN] = {'\0'} ;
	T_TAB_CMD       tabCmdTT;
	int iNumBytWritten=0;


	// ===============================
	// = RAZ des variables de retour =
	// ===============================
	if (nbInfo != NULL)
	{
		*nbInfo = 0;
		*info = NULL;
	}

	// ==========================================
	// = Extraction des commandes TT à exécuter =
	// ==========================================
	errChk (FCT_CmdComExtract (chCmdTT, &tabCmdTT));

	// ==============================
	// = Exécution des commandes TT =
	// ==============================
	for ( idxCmd=0 ; idxCmd<tabCmdTT.nbCmd ; idxCmd++ )
	{

		// Mise en casse inferieur de la commande
		// --------------------------------------
		i = 0;
		while (tabCmdTT.cmd[idxCmd].cmd[i] != '\0')
		{
			chCmd[i] = tolower (tabCmdTT.cmd[idxCmd].cmd[i]);
			i++;
		}
		chCmd[i] = '\0';

		// Mise à jour du Time Out si définis par la commande
		// --------------------------------------------------
		if (tabCmdTT.cmd[idxCmd].nTimeOut != -1)
			timeout = tabCmdTT.cmd[idxCmd].nTimeOut;

		// ==================================================================================
		// = GESTION DES COMMANDES TT                                                       =
		// ==================================================================================

		// =============================================
		// = Enregistrement d'une trace de la commande =
		// =============================================
		if ( chTrace != NULL )
			strcat (chTrace, tabCmdTT.cmd[idxCmd].cmd);

		// ===========================
		// = Envoi de la commande TT =
		// ===========================
		chBufferLu[0] = '\0';
		if ( AffichageTrace == AFFICHAGE_TRACE )
			FIL2LO_PrintCom (nItfe, FIL2LO_COM_GAT_RX, tabCmdTT.cmd[idxCmd].cmd);
		ClearBufferTelnet(HandleTelnet);
		status = InetTelnetWrite (HandleTelnet , tabCmdTT.cmd[idxCmd].cmd, "\n", -1, &iNumBytWritten, 1000);
		errChk (status);

		// =================================================
		// = Vérification du retour STB ('Pass' ou 'Fail') =
		// =================================================
		countDeb = GetTickCount();
		for ( i=0 ; i<tabCmdTT.cmd[idxCmd].nbPass ; i++ )
		{
			flagPatternPassFound = FALSE;
			flagPatternFailFound = FALSE;
			do
			{
				// Temporisation de 5ms
				// ----------------------
				Sleep (5);

				// Lecture du port COM
				// -------------------
				memset (chBufferLuTmp, '\0', (sizeof(unsigned char) * TAILLE_MAX));
				status = InetTelnetReadUntil(HandleTelnet, chBufferLuTmp, sizeof (chBufferLuTmp) - 1, tabCmdTT.cmd[idxCmd].pass[i], timeout);

				strncpy(gSlot[nItfe].Bufflu,chBufferLuTmp,TAILLE_MAX-1);
				//RemoveSurroundingWhiteSpace (chBufferLuTmp);


				// Concaténation des données reçues dans le buffer de réception, si le buffer n'est pas plein
				// ------------------------------------------------------------------------------------------
				if ( ((strlen(chBufferLu) + strlen(chBufferLuTmp)) < 67000/*TAILLE_MAX*/) && (strlen(chBufferLuTmp)) )
				{
					strcat (chBufferLu, chBufferLuTmp);
					if ( AffichageTrace == AFFICHAGE_TRACE )
						FIL2LO_PrintCom (nItfe, FIL2LO_COM_GAT_TX, chBufferLuTmp);

					// Enregistrement d'une trace de la réponse
					// ----------------------------------------
					if ( chTrace != NULL )
						strcat (chTrace, chBufferLuTmp);
				}

				errChk (status);
				// On vérifie si le retour 'pass' attendu a été envoyé par le STB  ==> Avec gestion des pipes pour valeurs en OU dans un Pass. On passe par une chaine tampon
				// ----------------------------------------------------------------------------------------------------------------------------------------------------------
				strcpy(chTampon,tabCmdTT.cmd[idxCmd].pass[i]);
				ptrPassMultiple = strtok(chTampon,VAR_PASS_OR_SEPARATOR);

				// On boucle sur les valeurs séparées
				// ---------------------------------
				while ( ptrPassMultiple != NULL)
				{
					if (strstr (chBufferLu, ptrPassMultiple) != NULL)
						flagPatternPassFound = TRUE;

					// On passe à la valeur suivante
					// -----------------------------
					ptrPassMultiple = strtok(NULL,VAR_PASS_OR_SEPARATOR);
				}

				// On vérifie si le retour 'fail' attendu a été envoyé par le STB
				// --------------------------------------------------------------
				flagPatternFailFound = FALSE;
				for ( j=0 ; j<tabCmdTT.cmd[idxCmd].nbFail ; j++ )
				{
					// On vérifie si le retour fail attendu a été envoyé par le STB
					// ------------------------------------------------------------
					if (strstr (chBufferLu, tabCmdTT.cmd[idxCmd].fail[j]) != NULL)
					{
						flagPatternFailFound = TRUE;
						break;
					}
				}

			}
			while ( ((int)(GetTickCount()-countDeb) < timeout) && (flagPatternPassFound == FALSE) && (flagPatternFailFound == FALSE) );


			// Si on n'a pas trouvé le pass, on sort de la boucle ==> façon de mettre les Pass en ET
			// -------------------------------------------------------------------------------------
			if (flagPatternPassFound == FALSE)
				break;

		}

		// ========================
		// = Extraction des infos =
		// ========================
		if ( (flagPatternFailFound != TRUE) && (flagPatternPassFound == TRUE) )
		{
			flagPatternPassFound = FALSE;

			if (nbInfo != NULL)
			{
				for ( i=0 ; i<tabCmdTT.cmd[idxCmd].nbInfo ; i++ )
				{
					// On vérifie le format du pattern à rechercher
					// --------------------------------------------
					if ( strchr (tabCmdTT.cmd[idxCmd].info[i], '%') != NULL )
					{
						// Remplace le '%' par '%s' dans la chaine de recherche
						// ----------------------------------------------------
//GCX_DEBUG
						sizePattern = strchr (tabCmdTT.cmd[idxCmd].info[i], '%') - tabCmdTT.cmd[idxCmd].info[i] + 1;
						strncpy (chPattern, tabCmdTT.cmd[idxCmd].info[i], sizePattern);
						chPattern[sizePattern-1] = '\0';

						// extraction juusqu'au retour à la ligne
						// --------------------------------------
						if (FCT_RechercheTag ( chBufferLu, chPattern, chVal ) == 1)
						{
							// Si une chaine est extraite : enregistrer cette chaine dans le buffer de retour
							// ------------------------------------------------------------------------------
							if ( strlen (chVal) > 0 )
							{
								// On incrémente le nombre d'infos extraits
								// ----------------------------------------
								(*nbInfo)++;

								// Allocation dynamique de mémoire pour le stockage des infos extraits
								// -------------------------------------------------------------------
								(*info) = (char**) realloc( *info, sizeof(char*) * (*nbInfo) );
								(*info)[(*nbInfo)-1] = (char*) malloc( sizeof(char) * FCT_RECUP_INFO_TAILLE_MAX );

								// Enregistrement de l'info extrait
								// --------------------------------
								strcpy ( (*info)[(*nbInfo)-1], chVal);
							}
							else
							{
								// Problème d'extraction d'info : aucune chaine extraite
								// -----------------------------------------------------
								errChk (-4);
							}
						}
						else
						{
							// Problème d'extraction d'info : pattern de recherche non trouvé
							// --------------------------------------------------------------
							errChk (-4);
						}
					}

					// "Non Remonte"
					// -------------
					else if ( strstr (tabCmdTT.cmd[idxCmd].info[i], TAG_NON_REMONTE) != NULL )
					{
						// On incrémente le nombre d'infos extraits
						// ----------------------------------------
						(*nbInfo)++;

						// Allocation dynamique de mémoire pour le stockage des infos extraits
						// -------------------------------------------------------------------
						(*info) = (char**) realloc( *info, sizeof(char*) * (*nbInfo) );
						(*info)[(*nbInfo)-1] = (char*) malloc( sizeof(char) * FCT_RECUP_INFO_TAILLE_MAX );

						// L'info n'est pas renseignée
						// ---------------------------
						strcpy ( (*info)[(*nbInfo)-1], TAG_NON_REMONTE);
					}
					else
					{
						// Problème d'extraction d'info : format du pattern de recherche incorrect
						// -----------------------------------------------------------------------
						errChk (-4);
					}
				}
			}
		}
		else if (flagPatternFailFound == TRUE)
			// Reception d'une chaine 'Fail' => sort de la fonction avec un code d'erreur
			// --------------------------------------------------------------------------
			errChk (-3);
		else
			// Time out en réception => sort de la fonction avec un code d'erreur
			// ------------------------------------------------------------------
			errChk (-2);
	}

Error:
	if(error)
	{
		if ( (AffichageTrace & MASQUE_ERR) != MASQUE_ERR )
		{
			if (error == -2)
				sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_TIMEOUT), tabCmdTT.cmd[idxCmd].cmd);
			else if (error == -3)
				sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_FAIL), tabCmdTT.cmd[idxCmd].cmd);
			else if (error == -4)
				sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_NON_TROUVE_STRING), tabCmdTT.cmd[idxCmd].cmd, tabCmdTT.cmd[idxCmd].info[i]);
			else if (error == -5)
				sprintf (chBufferLu, chMessErreur);
			else
				sprintf (chBufferLu, GET_MESSAGE(FCT_MSG_ERR_CMDTT_STRING), tabCmdTT.cmd[idxCmd].cmd, chMessErreur);
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "======>", chBufferLu);
		}
		return error;
	}

	return 0;
}


// ==============================================================================
// FONCTION :		FCT_Switch_SP8T
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			11/02/2020
//  AUTEUR :		CH_BK
//  DESCRIPTION :   Switch SP8T
// ==============================================================================

int FCT_Switch_SP8T (int nItfe, char	*chMessageErreur, char *PortSwitch )
{
	ssize_t iNumBytWritten=0;
	int status=-1;
	char cmd[100]="";
	char   Buffer[2000]="";


	sprintf(cmd,"[:SP8T:%s:STATE?]", gSlot[nItfe].BNFTnteg.gchAdressBlocSwitchRFSP8T);
	FCT_CmdComExecutionV4 (nItfe, gSlot[nItfe].HandleTelnetSwitch_SP8T, AFFICHAGE_TRACE, cmd, NULL, NULL, NULL, 500);
	Delay (gSlot[nItfe].BNFTnteg.gchTimeOutSwitchRF);

	strcpy(cmd,"");


	sprintf(cmd,"[:SP8T:%s:STATE:%s{Pass:1}]", gSlot[nItfe].BNFTnteg.gchAdressBlocSwitchRFSP8T, PortSwitch);

	status = FCT_CmdComExecutionV4 (nItfe, gSlot[nItfe].HandleTelnetSwitch_SP8T, AFFICHAGE_TRACE, cmd, NULL, NULL, NULL, 3000);


	if (status != 0)
	{
		strcpy (chMessageErreur,GET_MESSAGE(TFC_MSG_ERREUR_SWITCH_PORT_SP8T));
		return -1;
	}

	return 0;

}

// ==============================================================================
// FONCTION :     FCT_Comm_Attente_Fermeture_Caisson
// ------------------------------------------------------------------------------
// PROTOTYPE :    FCT_Comm_Attente_Fermeture_Caisson (int nItfe)
// ------------------------------------------------------------------------------


int FCT_Comm_Attente_Fermeture_Caisson (int nItfe)
{

	//int             status;
	int             idPortDec =gSlot[nItfe].comCaisson.iHandle;

	short           erreur = 0;
	long            codeErreur = 0;
	char            messagErreur[RS232_MSG_LEN] = {"\0"};
	T_VARIABLES     *ptrVariablesConf = &(gSlot[nItfe].variablesConf);
	char            chBuffLu[50000] = {"\0"};
	char			chPrompt[20] = {"\0"};
	int iCpt=0;
	int status=0;

	strcpy( chPrompt, "CLOSE");

	status = 0;
	/*
	// Boucle de détection de présence
	//--------------------------------
		do
	{
		// Attente du prompt
		// -----------------
		sprintf (chBuffLu, "");
		status = FCT_EnvoiCommandeTTAvecVerifRetour(nItfe, idPortDec, "STATUS\r", chPrompt, chBuffLu, NULL, 1, AUCUNE_TRACE/*AFFICHAGE_TRACE, &erreur, &codeErreur, messagErreur);
		// Mise en veille du thread de 50ms
		// ---------------------------------
		Sleep (50);
	}
	while ( status != 0);
	//	return 0;
	*/


	do
	{
		status = FCT_EnvoiCommandeTTAvecVerifRetour(nItfe, idPortDec, "STATUS\r", chPrompt, chBuffLu, NULL, 1, AUCUNE_TRACE/*AFFICHAGE_TRACE*/, &erreur, &codeErreur, messagErreur);
		ProcessDrawEvents ();
		Sleep(200);

	}
	while ((status!=0) && (gNPAbort==FALSE));   //(++iCpt<10) &&

	return status ;

}


// ==============================================================================
// FONCTION :     FCT_Comm_Caisson_Open
// ------------------------------------------------------------------------------
// PROTOTYPE :    FCT_Comm_Caisson_Open (int nItfe)
// ---
int FCT_Comm_Caisson_Open (int nItfe)
{

	int             status 	= 0;
	int             idPortDec = gSlot[nItfe].comCaisson.iHandle;;
	short           erreur = 0;
	long            codeErreur = 0;
	char            messagErreur[RS232_MSG_LEN] = {"\0"};

	T_VARIABLES     *ptrVariablesConf = &(gSlot[nItfe].variablesConf);
	char            chBuffLu[50000] = {"\0"};
	char			chPrompt[20] = {"\0"};
	int iFlagRtray=0,inbreRetray=0;
	strcpy( chPrompt, "OPEN");
	sprintf (chBuffLu,"");

	// Ouverture Port COM
	// ---------------------------------
	if ( FCT_OuverturePortsCOM ( nItfe ) != 0)
	{
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"Erreur ouverture port com !!!!!");
	}

	do
	{
		status = FCT_EnvoiCommandeTTAvecVerifRetour (nItfe, idPortDec, "OPEN\r", chPrompt, chBuffLu, NULL, 1, AUCUNE_TRACE/*AFFICHAGE_TRACE*/, &erreur, &codeErreur, messagErreur);
		status = FCT_EnvoiCommandeTTAvecVerifRetour (nItfe, idPortDec, "@0open\n\r", chPrompt, chBuffLu, NULL, 1, AUCUNE_TRACE/*AFFICHAGE_TRACE*/, &erreur, &codeErreur, messagErreur);
	}

	while ((status!=0) && (gNPAbort==FALSE));


	//	do
//	{
	//	iFlagRtray = 0;
	//	status = FCT_EnvoiCommandeTTAvecVerifRetour (nItfe, idPortDec, "@0open", chPrompt, chBuffLu, NULL, 1, AUCUNE_TRACE/*AFFICHAGE_TRACE*/, &erreur, &codeErreur, messagErreur);
	//status = FCT_EnvoiCommandeTTAvecVerifRetour (nItfe, idPortDec, "@0open\n\r", chPrompt, chBuffLu, NULL, 1, AUCUNE_TRACE/*AFFICHAGE_TRACE*/, &erreur, &codeErreur, messagErreur);
	//tatus = FCT_EnvoiCommandeTTAvecVerifRetour (nItfe, idPortDec, "OPEN\r", chPrompt, chBuffLu, NULL, 1, AUCUNE_TRACE/*AFFICHAGE_TRACE*/, &erreur, &codeErreur, messagErreur);
	//inbreRetray = inbreRetray +1;
	//if ( (status != 0) )
	//{
	/*	strcpy(messagErreur,"ERROR OPEN CAISSON !!!!");
		Sleep(2000);
		iFlagRtray = 1;
		if(inbreRetray > 4)
			return -1;
	}
	}
	while((inbreRetray <5) && (iFlagRtray ==1));


	 */


	return status ;

}
// ==============================================================================
// FONCTION :     FCT_Comm_Init_Caisson
// ------------------------------------------------------------------------------
// PROTOTYPE :    FCT_Comm_Init_Caisson (int nItfe)
// ---

int FCT_Comm_Init_Caisson(int nItfe)
{

	int             status 	= 0;
	int             idPortDec = gSlot[nItfe].comCaisson.iHandle;;
	short           erreur = 0;
	long            codeErreur = 0;
	char            messagErreur[RS232_MSG_LEN] = {"\0"};

	T_VARIABLES     *ptrVariablesConf = &(gSlot[nItfe].variablesConf);
	char            chBuffLu[50000] = {"\0"};
	char			chPrompt[20] = {"\0"};


	strcpy( chPrompt, " ");



	sprintf (chBuffLu, "");

	status = FCT_EnvoiCommandeTTAvecVerifRetour (nItfe, idPortDec, "OFF\r", chPrompt, chBuffLu, NULL, 1, AUCUNE_TRACE/*AFFICHAGE_TRACE*/, &erreur, &codeErreur, messagErreur);


	// Mise en veille du thread de 50ms
	// ---------------------------------
	Sleep (50);

	if (status =! 1)
	{
		return -1;
	}




	return 0;
}

// ==============================================================================
// FONCTION :		FCT_Check_Driver_wifi_2Ghz
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			23/08/2022
//  AUTEUR :		IHEB
//  DESCRIPTION :   Check_Driver_wifi_2Ghz
// ==============================================================================

int FCT_Check_Driver_wifi_2Ghz(int nItfe, char	*chMessageErreur )
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Check_Driver_2Ghz,0), &infos,&nbInfos ,NULL, 10);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"Check driver wifi 2Ghz KO !!!!");
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));


	return Status;
}
// ==============================================================================
// FONCTION :		FCT_Update_Driver_wifi_2Ghz
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			23/08/2022
//  AUTEUR :		IHEB
//  DESCRIPTION :   Update_Driver_wifi_2Ghz
// ==============================================================================

int FCT_Update_Driver_wifi_2Ghz(int nItfe, char	*chMessageErreur )
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Update_Driver_2Ghz,0), &infos,&nbInfos ,NULL, 5);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"Update driver wifi 2Ghz KO !!!!");
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));
	if ( (Status == 0) )
	{
		//FCT_AfficheInfo (nItfe, nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"====> Check Driver wifi 2Ghz");

		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "====> End Update 	Driver  wifi 2Ghz");
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "====>  Debut Check  Update Driver wifi 2Ghz");
		do
		{
			iFlagRtray = 0;
			Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Check_Update_Driver_2Ghz,0), &infos,&nbInfos ,NULL, 5);

			inbreRetray = inbreRetray +1;
			if ( (Status != 0) )
			{
				strcpy(chMessageErreur,"check Update driver wifi 2Ghz KO !!!!");
				Sleep(2000);
				iFlagRtray = 1;
				if(inbreRetray > 2)
					return -1;
			}
		}
		while((inbreRetray <3) && (iFlagRtray ==1));
	}
	return Status;
}
// ==============================================================================
// FONCTION :		FCT_Check_Driver_BT
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			01/09/2022
//  AUTEUR :		IHEB
//  DESCRIPTION :   Check_Driver_BT
// ==============================================================================

int FCT_Check_Driver_BT(int nItfe, char	*chMessageErreur )
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Check_Driver_BT,0), &infos,&nbInfos ,NULL, 10);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"Check driver BT KO !!!!");
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));


	return Status;
}
// ==============================================================================
// FONCTION :		FCT_Update_Driver_BT
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			01/09/2022
//  AUTEUR :		IHEB
//  DESCRIPTION :   Update_Driver_BT
// ==============================================================================

int FCT_Update_Driver_BT(int nItfe, char	*chMessageErreur )
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Update_Driver_BT,0), &infos,&nbInfos ,NULL, 5);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"Update driver BT KO !!!!");
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));
	if ( (Status == 0) )
	{
		//FCT_AfficheInfo (nItfe, nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"====> Check Driver wifi 2Ghz");
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "====> Check Driver BT");
		do
		{
			iFlagRtray = 0;
			Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Check_Update_Driver_BT,0), &infos,&nbInfos ,NULL, 5);

			inbreRetray = inbreRetray +1;
			if ( (Status != 0) )
			{
				strcpy(chMessageErreur,"check Update driver BT KO !!!!");
				Sleep(2000);
				iFlagRtray = 1;
				if(inbreRetray > 2)
					return -1;
			}
		}
		while((inbreRetray <3) && (iFlagRtray ==1));
	}
	return Status;
}
// ==============================================================================
// FONCTION :		FCT_UPDATE_IP_DUT
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			23/08/2022
//  AUTEUR :		IHEB
//  DESCRIPTION :   UPDATE_IP_DUT
// ==============================================================================

int FCT_UPDATE_IP_DUT(int nItfe, char	*chMessageErreur )
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Interface_Eth_DUT,0), &infos,&nbInfos ,NULL, 10);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"update IP DUT");
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));
	if ( (Status == 0) )
	{
		//FCT_AfficheInfo (nItfe, nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"====> Check DUT interface ");
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"====> Check DUT interface ");
		do
		{
			iFlagRtray = 0;
			Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Interface_IP_DUT,0), &infos,&nbInfos ,NULL, 10);

			inbreRetray = inbreRetray +1;
			if ( (Status != 0) )
			{
				strcpy(chMessageErreur,"Check DUT interface KO !!!!");
				Sleep(2000);
				iFlagRtray = 1;
				if(inbreRetray > 2)
					return -1;
			}
		}
		while((inbreRetray <3) && (iFlagRtray ==1));
	}


	return Status;
}
// ==============================================================================
// FONCTION :		FCT_TEST_wifi_2Ghz
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			23/08/2022
//  AUTEUR :		IHEB
//  DESCRIPTION :   FCT_TEST_wifi_2Ghz
// ==============================================================================

int FCT_TEST_wifi_2Ghz(int nItfe, char	*chMessageErreur )
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int Status1 = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0,inbreRetray1=0,iFlagRtray1=0,inbreRetray2=0,iFlagRtray3=0,inbreRetray3=0;
	char Pathscript2g[1024]="";
	char Pathlogcurrent[1024]="";
	char Pathlogoutput[1024]="";
	char Pathlogoutput_new[1024]="";
	char cheminlogscript[1024]="";
	char	cheminlogarchive[1024]="";
	char cheminlogarchivedate[1024]="";
	char Msg_Erreur[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char   Buffer[2097152]="";
	int taillebfr=0;
	static int FileHandle;
	static ssize_t size,FileSize;
	FILE* fichier = NULL;
	FILE* fichierEX = NULL;
	long				FileLength = 0;
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	char   chDate[80+1];
	char   chHeure[80+1];
	char   chHeureMili[80+1];
	char tabMesure ;
	T_MESURES           *ptrMesures = &(gSlot[nItfe].mesures);


	char  extractlogpy [1024] = "" ;
	/*
		if(FileExists ("C:\\Wav_File", 0)==0)
		MakeDir ("C:\\Wav_File");

	strcpy(Newpathwavfile,"");
	strcpy(Newnamewavfile,"");

	sprintf( Newpathwavfile,"C:\\Wav_File\\%s.wav" ,WavBouche);
	CopyFile (cheminwave,Newpathwavfile);
	sprintf( Newnamewavfile,"C:\\Wav_File\\%s_%s_%s_%s.wav" ,WavBouche,ptrVariablesTraca->CieSn,chDate,chHeure);
	Delay(0.5);
	rename( Newpathwavfile,Newnamewavfile);

	//----------------------------------------------------------------------------------------
	//Copy wave file from tftp folder to mic folder-------------------------------------------
	//----------------------------------------------------------------------------------------
	strcpy(pathWavefile,"");
	sprintf( pathWavefile,"%s\\Script_TEST\\Prod_1\\Mic\\%s.wav",gChCurrentDir ,WavBouche);
	CopyFile (cheminwave,pathWavefile);
	Delay(0.5);*/
	//----------------------------------------------------------------------------------------
	//start TEST WIFI -------------------------------------------
	//----------------------------------------------------------------------------------------
	/*
	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_CMD_TEST_2Ghz,0), &infos,&nbInfos ,NULL, 10);
		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"TEST WIFI KO !!!!");
			Sleep(5);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));	  */



	sprintf(Pathscript2g,"%s\\%s",VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_2GHZ,0),VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_2GHZ,1));
	sprintf(Pathlogcurrent,"%s\\Log\\logCurrent.txt",VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_2GHZ,0));
	sprintf(Pathlogoutput,"%s\\Log\\logOutput.txt",VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_2GHZ,0));
	char  pythonNEW[2048];
	char pytlog [1024];
	sprintf(pytlog,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_2GHZ,0)) ;
	//sprintf(pythonNEW,"app.exe %s %s 2G", pytlog,Pathlogoutput) ;
	sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 2G %s", pytlog,ptrVariablesTraca->CiuSfcSAPME) ;

	remove(Pathlogoutput);
	//char  cccommand[1024] ;
	//const char *command_2G_sleep  = "2G" ;
	//sprintf(cccommand , "mainn.exe %s", command_2G_sleep);

	system(pythonNEW);
	//LaunchExecutableEx(python,LE_SHOWNORMAL,NULL);
	sprintf( cheminlogarchive,"%s\\Archive" ,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_2GHZ,0));
	if ( !FileExists (cheminlogarchive, NULL) )
		MakeDir (cheminlogarchive);

	//Launch script Lancer_Test_Wi-Fi.bat -------------------------------------------
	//----------------------------------------------------------------------------------------
	do
	{
		iFlagRtray3 = 0;
		Status =LaunchExecutableEx (Pathscript2g, LE_SHOWNORMAL,&Handlescript );
		inbreRetray3 = inbreRetray3 +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"ERROR lancement script 2Ghz  !!!!");
			Sleep(5);
			iFlagRtray3 = 1;
			if(inbreRetray3 > 2)
				return -1;
		}
		//	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"------>");
	}
	while((inbreRetray3 <3) && (iFlagRtray3 ==1));

	//check File log_current -------------------------------------
	//------------------------------------------------------------
	do
	{
		inbreRetray1 = inbreRetray1 +1;
		if (!FileExists (Pathlogcurrent,0 ))
		{
			if ( inbreRetray1>9)
			{
				strcpy(chMessageErreur,"File log_current.txt not exist ");
				return -1;
			}
			Delay(5);
			//	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"------>");
		}
	}
	while((inbreRetray1 <10) && (!FileExists (Pathlogcurrent,0 )));
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"-----> Script started  ");

	//check File log_output.txt -------------------------------------
	//---------------------------------------------------------------
	do
	{
		inbreRetray2 = inbreRetray2 +1;
		if (!FileExists (Pathlogoutput,0 ))
		{
			if ( inbreRetray2>199)
			{
				strcpy(chMessageErreur,"File log_output.txt not exist ");
				return  -1;
			}
			ProcessDrawEvents ();
			Sleep(2000);
			//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"------>");
		}
	}
	while((inbreRetray2 <200) && (!FileExists (Pathlogoutput,0 )));
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->EndScript");


	char  pythonNEW1[2048];
	char pytlog1 [1024];
	sprintf(pytlog1,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_2GHZ,0)) ;
	//sprintf(pythonNEW,"app.exe %s %s 2G", pytlog,Pathlogoutput) ;
	sprintf(pythonNEW1,"app.exe %s  logOutput.txt 25G %s", Pathlogoutput,ptrVariablesTraca->CiuSfcSAPME) ;

	system(pythonNEW1);


	//strcpy(Pathlogoutput,"C:\\ayoubb\\Banc_BWC_RGW - V_09_01_2024-DFA\\resultfinale2G5G.txt-2G5G.txt");
	fichier = fopen(Pathlogoutput, "r");
	FileHandle = OpenFile (Pathlogoutput, VAL_READ_ONLY, VAL_OPEN_AS_IS, VAL_ASCII);
	GetFileInfo (Pathlogoutput, &FileSize );
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999,"------------------------>Results of Script test  WIFI 2GHZ<------------------------------");
	ReadFile (FileHandle,Buffer ,sizeof( Buffer) );




	GetFileSize(Pathlogoutput,&FileLength);
	taillebfr = sizeof( Buffer) ;
	Delay(2);
	FIL2LO_EcritTraceV2 (TRUE, nItfe,Buffer);
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999,"--------->Results");
	/////---------------------------------------------------------------
	///////////////////////////////////////	///////////////////////////////////////

	//Status= FCT_Rcup_Mesure_log(nItfe, fichier ,&tabMesure,chMessageErreur  ) ;




	if(gSlot[nItfe].BNFTnteg.gchFlagTraca)
	{
		//Status= 	MES_EnregistrerTableauV2 (ptrMesures,nItfe, fichier, chMessageErreur ) ;

		sprintf(extractlogpy,"%s-25G.txt",ptrVariablesTraca->CiuSfcSAPME);
		fichierEX = fopen(extractlogpy, "r");

		Status  = MES_EnregistrerTableauV2Log  ( ptrMesures,extractlogpy,nItfe ,fichierEX, chMessageErreur  );
		fclose(fichierEX);
	}

	fclose(fichier);
	sprintf(Pathlogoutput_new,"%s\\Log\\logOutput_saved.txt",VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_2GHZ,0));

	rename(Pathlogoutput,Pathlogoutput_new);
	//---------------------------------------------------------------
	///////////////////////////////////////////////////////////////
	CloseFile(FileHandle);
	FIL2LO_DateV2 (chDate);
	FIL2LO_HeureV2 (chHeure, chHeureMili);


	//check PASS /FAIL-----------------------------------------------
	//---------------------------------------------------------------
	Status=FindPattern (Buffer, 0,sizeof(Buffer), "P A S S", 0, 0) ;
	char  filename__  [1024] ;
	char logfolder [1024];
	char python[2048] ;

	if ( Status <0)
	{
		Status=-1;

		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->TEST WIFI 2Ghz UNKOWN results");
		strcpy(chMessageErreur,"TEST WIFI 2Ghz UNKOWN results !!!!");

	}

	else
	{
		Status=0;
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->TEST WIFI 2Ghz PASSED");

	}





	return Status;
}
// ==============================================================================
// FONCTION :		FCT_TEST_BT
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			30/08/2022
//  AUTEUR :		IHEB
//  DESCRIPTION :   FCT_TEST_BT
// ==============================================================================

int FCT_TEST_BT(int nItfe, char	*chMessageErreur )
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int Status1 = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0,inbreRetray1=0,iFlagRtray1=0,inbreRetray2=0,iFlagRtray3=0,inbreRetray3=0;
	char Pathscript2g[1024]="";
	char Pathlogcurrent[1024]="";
	char Pathlogoutput[1024]="";
	char cheminlogscript[1024]="";
	char	cheminlogarchive[1024]="";
	char cheminlogarchivedate[1024]="";
	char   Buffer[2097152]="";
	int taillebfr=0;
	static int FileHandle;
	static ssize_t size,FileSize;
	FILE* fichier = NULL;
	long				FileLength = 0;
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	char   chDate[80+1];
	char   chHeure[80+1];
	char   chHeureMili[80+1];
	T_MESURES           *ptrMesures = &(gSlot[nItfe].mesures);
	/*
		if(FileExists ("C:\\Wav_File", 0)==0)
		MakeDir ("C:\\Wav_File");

	strcpy(Newpathwavfile,"");
	strcpy(Newnamewavfile,"");

	sprintf( Newpathwavfile,"C:\\Wav_File\\%s.wav" ,WavBouche);
	CopyFile (cheminwave,Newpathwavfile);
	sprintf( Newnamewavfile,"C:\\Wav_File\\%s_%s_%s_%s.wav" ,WavBouche,ptrVariablesTraca->CieSn,chDate,chHeure);
	Delay(0.5);
	rename( Newpathwavfile,Newnamewavfile);

	//----------------------------------------------------------------------------------------
	//Copy wave file from tftp folder to mic folder-------------------------------------------
	//----------------------------------------------------------------------------------------
	strcpy(pathWavefile,"");
	sprintf( pathWavefile,"%s\\Script_TEST\\Prod_1\\Mic\\%s.wav",gChCurrentDir ,WavBouche);
	CopyFile (cheminwave,pathWavefile);
	Delay(0.5);*/
	//----------------------------------------------------------------------------------------
	//start TEST WIFI -------------------------------------------
	//----------------------------------------------------------------------------------------
	/*do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_CMD_TEST_BT,0), &infos,&nbInfos ,NULL, 10);
		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"TEST BT KO !!!!");
			Sleep(5);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));
	//Fermeture port com ---------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
	Status = FCT_FermeturePortsCOM ( nItfe, chMessageErreur );
			if ( (Status != 0) )
		{
			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"Erreur fermeture port com !!!!!");
			return -1;
		}
	*/
	//---------------------------------------------------------------------------------------
	sprintf(Pathscript2g,"%s\\%s",VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_BT,0),VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_BT,1));
	sprintf(Pathlogcurrent,"%s\\Log\\logCurrent.txt",VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_BT,0));
	sprintf(Pathlogoutput,"%s\\Log\\logOutput.txt",VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_BT,0));

	char pytlog1 [1024];
	sprintf(pytlog1,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_BT,0)) ;

	char  pythonNEW[2048];
	char pytlog [1024];
	sprintf(pytlog,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_BT,0)) ;


	//sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt BT", pytlog) ;
	sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt BT %s", pytlog,ptrVariablesTraca->CiuSfcSAPME) ;

	system(pythonNEW);

	//sprintf(python,"app.exe %s %s Bt", pytlog,Pathlogoutput) ;
	//system(python);
	sprintf( cheminlogarchive,"%s\\Archive" ,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_BT,0));
	if ( !FileExists (cheminlogarchive, NULL) )
		MakeDir (cheminlogarchive);
	if ( FileExists (Pathlogoutput, NULL) )
		DeleteFile (Pathlogoutput);
	if ( FileExists (Pathlogcurrent, NULL) )
		DeleteFile (Pathlogcurrent);


	//Launch script Lancer_Test_Wi-Fi.bat -------------------------------------------
	//----------------------------------------------------------------------------------------
	do
	{
		iFlagRtray3 = 0;
		Status =LaunchExecutableEx (Pathscript2g, LE_SHOWNORMAL,&Handlescript );;
		inbreRetray3 = inbreRetray3 +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"ERROR lancement script BT  !!!!");
			Sleep(5);
			iFlagRtray3 = 1;
			if(inbreRetray3 > 2)
				return -1;
		}
		//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"------>");
	}
	while((inbreRetray3 <3) && (iFlagRtray3 ==1));

	//check File log_current -------------------------------------
	//------------------------------------------------------------
	do
	{
		inbreRetray1 = inbreRetray1 +1;
		if (!FileExists (Pathlogcurrent,0 ))
		{
			if ( inbreRetray1>9)
			{
				strcpy(chMessageErreur,"File log_current.txt not exist ");
				return -1;
			}
			Delay(5);
			//	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"------>");
		}
	}
	while((inbreRetray1 <10) && (!FileExists (Pathlogcurrent,0 )));
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"-----> Script started  ");

	//check File log_output.txt -------------------------------------
	//---------------------------------------------------------------
	do
	{
		inbreRetray2 = inbreRetray2 +1;
		if (!FileExists (Pathlogoutput,0 ))
		{
			if ( inbreRetray2>199)
			{
				strcpy(chMessageErreur,"File log_output.txt not exist ");
				return -1;
			}
			ProcessDrawEvents ();
			Sleep(2000);
			//	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"------>");
		}
	}
	while((inbreRetray2 <200) && (!FileExists (Pathlogoutput,0 )));
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->EndScript");
	fichier = fopen(Pathlogoutput, "r");
	FileHandle = OpenFile (Pathlogoutput, VAL_READ_ONLY, VAL_OPEN_AS_IS, VAL_ASCII);
	GetFileInfo (Pathlogoutput, &FileSize );
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999,"------------------------>Results of Script test  BT <------------------------------");
	ReadFile (FileHandle,Buffer ,sizeof( Buffer) );
	GetFileSize(Pathlogoutput,&FileLength);
	taillebfr = sizeof( Buffer) ;
	Delay(2);
	FIL2LO_EcritTraceV2 (TRUE, nItfe,Buffer);
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999,"--------->Results");
	///////////////////////////////////////	///////////////////////////////////////

	if(gSlot[nItfe].BNFTnteg.gchFlagTraca)
	{
		Status= 	MES_EnregistrerTableauV3 (ptrMesures,nItfe, fichier, chMessageErreur ) ;
	}
	fclose(fichier);
	//---------------------------------------------------------------
	CloseFile(FileHandle);
	FIL2LO_DateV2 (chDate);
	FIL2LO_HeureV2 (chHeure, chHeureMili);
	//check PASS /FAIL-----------------------------------------------
	//---------------------------------------------------------------
	Status=FindPattern (Buffer, 0,sizeof(Buffer), "P A S S", 0, 0) ;
	if ( Status <0)
	{
		Status=FindPattern (Buffer, 0,sizeof(Buffer), "F A I L", 0, 0) ;
		if( Status < 0 )
		{

			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->TEST WIFI BT UNKOWN results");
			strcpy(chMessageErreur,"TEST WIFI BT UNKOWN results !!!!");
			sprintf( cheminlogscript,"%s\\Log\\%s_%s_%s_%s_BT.log" ,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_BT,0),"UNKOWN",ptrVariablesTraca->CieSn,chDate,chHeureMili);

		}
		else
		{
			Status=-1;
			//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->TEST WIFI BT FAILED");
			//strcpy(chMessageErreur,"TEST WIFI BT FAILLED !!!!");
			sprintf( cheminlogscript,"%s\\Log\\%s_%s_%s_%s_BT.log" ,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_BT,0),"FAILED",ptrVariablesTraca->CieSn,chDate,chHeureMili);


			char  pythonNEW[2048];
			char pytlog [1024];
			sprintf(pytlog,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_BT,0)) ;
			//sprintf(pythonNEW,"app.exe %s/logOutput.txt %s BT", pytlog,Pathlogoutput) ;

			sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt BT %s", pytlog,ptrVariablesTraca->CiuSfcSAPME) ;
			system(pythonNEW);
		}

	}
	else
	{
		Status=0;
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->TEST WIFI BT PASSED");
		sprintf( cheminlogscript,"%s\\Log\\%s_%s_%s_%s_BT.log" ,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_BT,0),"PASSED",ptrVariablesTraca->CieSn,chDate,chHeureMili);
		char  pythonNEW[2048];
		char pytlog [1024];
		sprintf(pytlog,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_BT,0)) ;
		//sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt BT", pytlog) ;
		sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 2G %s", pytlog,ptrVariablesTraca->CiuSfcSAPME) ;

		system(pythonNEW);
	}

	rename( Pathlogoutput,cheminlogscript);
	sprintf( cheminlogarchivedate,"%s\\log_%s\\" ,cheminlogarchive,chDate);
	if ( !FileExists (cheminlogarchivedate, NULL) )
		MakeDir (cheminlogarchivedate);
	CopyFile (cheminlogscript,cheminlogarchivedate);
	DeleteFile (cheminlogscript);



	return Status;
}
// ==============================================================================
// FONCTION :		FCT_PingSTB
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			30/08/2022
//  AUTEUR :		IHEB
//  DESCRIPTION :   FCT_PingSTB
// ==============================================================================




int FCT_PingSTB (int nItfe, char *messagErreur)
{
	int status=-1;
	char adress[1024]="";
	char Cmd[1024]="";
	int iFlagRtray=0,inbreRetray=0,iFlagRtray3=0,inbreRetray3=0,iFlagRtray2=0,inbreRetray2=0;
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Pathping[1024]="";
	char   Buffer[1024]="";
	static int FileHandle;
	do
	{
		iFlagRtray = 0;
		status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_PING_DUT,0), NULL, NULL,NULL, 10);

		inbreRetray = inbreRetray +1;
		if ( (status != 0) )
		{
			strcpy (messagErreur, "Erreur ping KO !!!");
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));
	//sprintf(Pathping,"%s\\Ping.bat",gChCurrentDir);
	sprintf(Pathping,"Ping.bat");
	//DeleteFile ("C:\\ping.txt");

	do
	{
		iFlagRtray3 = 0;

		status =LaunchExecutableEx (Pathping, LE_SHOWNORMAL,&Handlescript );
		inbreRetray3 = inbreRetray3 +1;
		if ( (status != 0) )
		{
			strcpy(messagErreur,"ERROR lancement ping.bat  !!!!");
			Sleep(5);
			iFlagRtray3 = 1;
			if(inbreRetray3 > 2)
				return -1;
		}
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"------>");
	}
	while((inbreRetray3 <3) && (iFlagRtray3 ==1));
	do
	{
		iFlagRtray2 = 0;
		Delay(5);

		FileHandle = OpenFile ("C:\\ping.txt", VAL_READ_ONLY, VAL_OPEN_AS_IS, VAL_ASCII);
		ReadFile (FileHandle,Buffer ,sizeof( Buffer) );
		status=FindPattern (Buffer, 0,sizeof(Buffer), "TEST_PING_ENDED", 0, 0) ;
		CloseFile(FileHandle);
		inbreRetray2 = inbreRetray2 +1;
		if ( (status <0) )
		{
			strcpy(messagErreur,"ERROR ping PC to STB  !!!!");

			iFlagRtray2 = 1;
			if(inbreRetray2 > 3)
			{
				FIL2LO_EcritTrace (TRUE, nItfe,Buffer);
				return -1;
			}
		}
	}
	while((inbreRetray2 <4) && (iFlagRtray2 ==1));
	//Delay(5);
//FileHandle = OpenFile ("C:\\ping.txt", VAL_READ_ONLY, VAL_OPEN_AS_IS, VAL_ASCII);
//ReadFile (FileHandle,Buffer ,sizeof( Buffer) );
	status=FindPattern (Buffer, 0,sizeof(Buffer), "perdus = 4 (perte 100%)", 0, 0) ;
	FIL2LO_EcritTrace (TRUE, nItfe,Buffer);
//CloseFile(FileHandle);
	DeleteFile ("C:\\ping.txt");
	if ( status <0)
	{
		status=0;
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->Ping verified");
	}
	return status;
}

// ==============================================================================
// FONCTION :		FCT_Check_Driver_wifi_5Ghz
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			06/09/2022
//  AUTEUR :		IHEB
//  DESCRIPTION :   Check_Driver_wifi_5Ghz
// ==============================================================================

int FCT_Check_Driver_wifi_5Ghz(int nItfe, char	*chMessageErreur )
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Check_Driver_5Ghz,0), &infos,&nbInfos ,NULL, 10);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"Check driver wifi 5Ghz KO !!!!");
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));


	return Status;
}
// ==============================================================================
// FONCTION :		FCT_Update_Driver_wifi_5Ghz
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			06/09/2022
//  AUTEUR :		IHEB
//  DESCRIPTION :   Update_Driver_wifi_5Ghz
// ==============================================================================

int FCT_Update_Driver_wifi_5Ghz(int nItfe, char	*chMessageErreur )
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Update_Driver_5Ghz,0), &infos,&nbInfos ,NULL, 5);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"Update driver wifi 5Ghz KO !!!!");
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));
	if ( (Status == 0) )
	{
		//FCT_AfficheInfo (nItfe, nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"====> Check Driver wifi 2Ghz");
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, "====> Check Driver wifi 5Ghz");
		do
		{
			iFlagRtray = 0;
			Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_DEC_BWC_CMD_Check_Update_Driver_5Ghz,0), &infos,&nbInfos ,NULL, 5);

			inbreRetray = inbreRetray +1;
			if ( (Status != 0) )
			{
				strcpy(chMessageErreur,"check Update driver wifi 5Ghz KO !!!!");
				Sleep(2000);
				iFlagRtray = 1;
				if(inbreRetray > 2)
					return -1;
			}
		}
		while((inbreRetray <3) && (iFlagRtray ==1));
	}
	return Status;
}

// ==============================================================================
// FONCTION :		FCT_TEST_wifi_5Ghz
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			06/09/2022
//  AUTEUR :		IHEB
//  DESCRIPTION :   FCT_TEST_wifi_5Ghz
// ==============================================================================

int FCT_TEST_wifi_5Ghz(int nItfe, char	*chMessageErreur )
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int Status1 = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0,inbreRetray1=0,iFlagRtray1=0,inbreRetray2=0,iFlagRtray3=0,inbreRetray3=0;
	char Pathscript2g[1024]="";
	char Pathlogcurrent[1024]="";
	char Pathlogoutput[1024]="";
	char cheminlogscript[1024]="";
	char	cheminlogarchive[1024]="";
	char cheminlogarchivedate[1024]="";
	char   Buffer[2097152]="";
	int taillebfr=0;
	static int FileHandle;
	static ssize_t size,FileSize;
	FILE* fichier = NULL;
	long				FileLength = 0;
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	char   chDate[80+1];
	char   chHeure[80+1];
	char   chHeureMili[80+1];
	T_MESURES           *ptrMesures = &(gSlot[nItfe].mesures);
	char python[2048];
	char  logfolder [2048];
	/*
		if(FileExists ("C:\\Wav_File", 0)==0)
		MakeDir ("C:\\Wav_File");

	strcpy(Newpathwavfile,"");
	strcpy(Newnamewavfile,"");

	sprintf( Newpathwavfile,"C:\\Wav_File\\%s.wav" ,WavBouche);
	CopyFile (cheminwave,Newpathwavfile);
	sprintf( Newnamewavfile,"C:\\Wav_File\\%s_%s_%s_%s.wav" ,WavBouche,ptrVariablesTraca->CieSn,chDate,chHeure);
	Delay(0.5);
	rename( Newpathwavfile,Newnamewavfile);

	//----------------------------------------------------------------------------------------
	//Copy wave file from tftp folder to mic folder-------------------------------------------
	//----------------------------------------------------------------------------------------
	strcpy(pathWavefile,"");
	sprintf( pathWavefile,"%s\\Script_TEST\\Prod_1\\Mic\\%s.wav",gChCurrentDir ,WavBouche);
	CopyFile (cheminwave,pathWavefile);
	Delay(0.5);*/
	//----------------------------------------------------------------------------------------
	//start TEST WIFI -------------------------------------------
	//----------------------------------------------------------------------------------------
	/*do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_CMD_TEST_5Ghz,0), &infos,&nbInfos ,NULL, 10);
		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"TEST WIFI KO !!!!");
			Sleep(5);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));   */
	sprintf(Pathscript2g,"%s\\%s",VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0),VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,1));
	sprintf(Pathlogcurrent,"%s\\Log\\logCurrent.txt",VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0));
	sprintf(Pathlogoutput,"%s\\Log\\logOutput.txt",VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0));
	char pytlog1 [1024];
	sprintf(pytlog1,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0)) ;

	char  pythonNEW[2048];
	char pytlog [1024];
	sprintf(pytlog,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0)) ;
	//sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 5G", pytlog) ;
	sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 5G %s", pytlog,ptrVariablesTraca->CiuSfcSAPME) ;
	system(pythonNEW);

	char  cccommand[1024] ;
	const char *GG  = "2G" ;
	sprintf(cccommand , "mainn.exe %s", GG);
	//sprintf(python,"app.exe %s %s", pytlog,Pathlogoutput) ;
	//system(python);
	sprintf( cheminlogarchive,"%s\\Archive" ,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0));
	if ( !FileExists (cheminlogarchive, NULL) )
		MakeDir (cheminlogarchive);

	//Launch script Lancer_Test_Wi-Fi.bat -------------------------------------------
	//----------------------------------------------------------------------------------------
	do
	{
		iFlagRtray3 = 0;
		Status =LaunchExecutableEx (Pathscript2g, LE_SHOWNORMAL,&Handlescript );
		inbreRetray3 = inbreRetray3 +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"ERROR lancement script 5Ghz  !!!!");
			Sleep(5);
			iFlagRtray3 = 1;
			if(inbreRetray3 > 2)
				return -1;
		}
		//	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"------>");
	}
	while((inbreRetray3 <3) && (iFlagRtray3 ==1));

	//check File log_current -------------------------------------
	//------------------------------------------------------------
	do
	{
		inbreRetray1 = inbreRetray1 +1;
		if (!FileExists (Pathlogcurrent,0 ))
		{
			if ( inbreRetray1>9)
			{
				strcpy(chMessageErreur,"File log_current.txt not exist ");
				return -1;
			}
			Delay(5);
			//	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"------>");
		}
	}
	while((inbreRetray1 <10) && (!FileExists (Pathlogcurrent,0 )));
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"-----> Script started  ");

	//check File log_output.txt -------------------------------------
	//---------------------------------------------------------------
	do
	{
		inbreRetray2 = inbreRetray2 +1;
		if (!FileExists (Pathlogoutput,0 ))
		{
			if ( inbreRetray2>199)
			{
				strcpy(chMessageErreur,"File log_output.txt not exist ");
				return -1;
			}
			ProcessDrawEvents ();
			Sleep(2000);
			//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"------>");
		}
	}
	while((inbreRetray2 <200) && (!FileExists (Pathlogoutput,0 )));
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->EndScript");
	fichier = fopen(Pathlogoutput, "r");
	FileHandle = OpenFile (Pathlogoutput, VAL_READ_ONLY, VAL_OPEN_AS_IS, VAL_ASCII);
	GetFileInfo (Pathlogoutput, &FileSize );
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999,"------------------------>Results of Script test  WIFI 5Ghz<------------------------------");
	ReadFile (FileHandle,Buffer ,sizeof( Buffer) );
	GetFileSize(Pathlogoutput,&FileLength);
	taillebfr = sizeof( Buffer) ;
	Delay(2);
	FIL2LO_EcritTraceV2 (TRUE, nItfe,Buffer);
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999,"--------->Results");
	///////////////////////////////////////	///////////////////////////////////////

	//Status= FCT_Rcup_Mesure_log(nItfe, fichier ,&tabMesure,chMessageErreur  ) ;

	if(gSlot[nItfe].BNFTnteg.gchFlagTraca)
	{
		//    Status= 	MES_EnregistrerTableauV2 (ptrMesures,nItfe, fichier, chMessageErreur ) ;
		Status  = MES_EnregistrerTableauV2Log  ( ptrMesures,"C:\\Users\\g702306\\Desktop\\HGHH\\Banc_BWC_RGW - V_09_01_2024\resultfinale-5G.txt",nItfe ,fichier, chMessageErreur  );
	}

	fclose(fichier);
	//---------------------------------------------------------------

	CloseFile(FileHandle);
	FIL2LO_DateV2 (chDate);
	FIL2LO_HeureV2 (chHeure, chHeureMili);
	//check PASS /FAIL-----------------------------------------------
	//---------------------------------------------------------------
	Status=FindPattern (Buffer, 0,sizeof(Buffer), "P A S S", 0, 0) ;

	if ( Status <0)
	{
		Status=FindPattern (Buffer, 0,sizeof(Buffer), "F A I L", 0, 0) ;
		if( Status < 0 )
		{

			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->TEST WIFI 5Ghz UNKOWN results");
			strcpy(chMessageErreur,"TEST WIFI 5Ghz UNKOWN results !!!!");
			sprintf( cheminlogscript,"%s\\Log\\%s_%s_%s_%s_5Ghz.log" ,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0),"UNKOWN",ptrVariablesTraca->CieSn,chDate,chHeureMili);
			sprintf( logfolder,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0) ) ;


			char  pythonNEW[2048];
			char pytlog [1024];
			sprintf(pytlog,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0)) ;
			//sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 5G", pytlog) ;
			sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 5G %s", pytlog,ptrVariablesTraca->CiuSfcSAPME) ;
			system(pythonNEW);
			char  cccommand[1024] ;
			const char *GG  = "2G" ;
			sprintf(cccommand , "mainn.exe %s", GG);
			//sprintf(python,"app.exe %s %s", logfolder,cheminlogscript) ;
			//system(python);
		}
		else
		{
			Status=-1;
			//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->TEST WIFI 5Ghz FAILED");
			//strcpy(chMessageErreur,"TEST WIFI 5Ghz FAILLED !!!!");
			sprintf( cheminlogscript,"%s\\Log\\%s_%s_%s_%s_5Ghz.log" ,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0),"FAILED",ptrVariablesTraca->CieSn,chDate,chHeureMili);
			sprintf( logfolder,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_2GHZ,0) ) ;
			char  pythonNEW[2048];
			char pytlog [1024];
			sprintf(pytlog,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0)) ;


			//sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 5G", pytlog) ;
			sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 5G %s", pytlog,ptrVariablesTraca->CiuSfcSAPME) ;
			system(pythonNEW);

			char  cccommand[1024] ;
			const char *GG  = "2G" ;
			sprintf(cccommand , "mainn.exe %s", GG);
			//sprintf(python,"app.exe %s %s", logfolder,cheminlogscript) ;
			//system(python);
		}
		sprintf( cheminlogscript,"%s\\Log\\%s_%s_%s_%s_5Ghz.log" ,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0),"FAILED",ptrVariablesTraca->CieSn,chDate,chHeureMili);
		sprintf( logfolder,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_2GHZ,0) ) ;
		char  pythonNEW[2048];
		char pytlog [1024];
		sprintf(pytlog,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0)) ;
		//sprintf(pythonNEW,"app.exe %s/logOutput.txt %s 5G", pytlog,Pathlogoutput) ;
		sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 5G %s", pytlog,ptrVariablesTraca->CiuSfcSAPME) ;
		system(pythonNEW);
		char  cccommand[1024] ;
		const char *GG  = "2G" ;
		sprintf(cccommand , "mainn.exe %s", GG);
//sprintf(python,"app.exe %s %s", logfolder,cheminlogscript) ;
		//system(python);
	}
	else
	{
		Status=0;
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->TEST WIFI 5Ghz PASSED");
		sprintf( cheminlogscript,"%s\\Log\\%s_%s_%s_%s_5Ghz.log" ,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0),"PASSED",ptrVariablesTraca->CieSn,chDate,chHeureMili);
		sprintf( logfolder,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0) ) ;
		//sprintf(python,"app.exe %s %s", logfolder,cheminlogscript) ;
		//system(python);

		char  pythonNEW[2048];
		char pytlog [1024];
		sprintf(pytlog,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_5GHZ,0)) ;
		//sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 5G", pytlog) ;

		sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 5G %s", pytlog,ptrVariablesTraca->CiuSfcSAPME) ;
		system(pythonNEW);

		char  cccommand[1024] ;
		const char *GG  = "2G" ;
		sprintf(cccommand , "mainn.exe %s", GG);
	}

	rename( Pathlogoutput,cheminlogscript);


	sprintf( cheminlogarchivedate,"%s\\log_%s\\" ,cheminlogarchive,chDate);
	if ( !FileExists (cheminlogarchivedate, NULL) )
		MakeDir (cheminlogarchivedate);
	CopyFile (cheminlogscript,cheminlogarchivedate);
	DeleteFile (cheminlogscript);
	Sleep(200);
//	FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,"[exit{Pass:TT>}]", NULL,NULL ,NULL,10);



	return Status;
}

// ==============================================================================
// FONCTION :		FCT_TEST_wifi_6Ghz
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			21/10/2022
//  AUTEUR :		Sameh
//  DESCRIPTION :   FCT_TEST_wifi_6Ghz
// ==============================================================================

int FCT_TEST_wifi_6Ghz(int nItfe, char	*chMessageErreur )
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int Status1 = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0,inbreRetray1=0,iFlagRtray1=0,inbreRetray2=0,iFlagRtray3=0,inbreRetray3=0;
	char Pathscript2g[1024]="";
	char Pathlogcurrent[1024]="";
	char Pathlogoutput[1024]="";
	char cheminlogscript[1024]="";
	char	cheminlogarchive[1024]="";
	char cheminlogarchivedate[1024]="";
	char   Buffer[2097152]="";
	int taillebfr=0;
	static int FileHandle;
	static ssize_t size,FileSize;
	FILE* fichier = NULL;
	long				FileLength = 0;
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	char   chDate[80+1];
	char   chHeure[80+1];
	char   chHeureMili[80+1];
	T_MESURES           *ptrMesures = &(gSlot[nItfe].mesures);
	char python[2048] ;
	char logfolder[2048];
	/*
		if(FileExists ("C:\\Wav_File", 0)==0)
		MakeDir ("C:\\Wav_File");

	strcpy(Newpathwavfile,"");
	strcpy(Newnamewavfile,"");

	sprintf( Newpathwavfile,"C:\\Wav_File\\%s.wav" ,WavBouche);
	CopyFile (cheminwave,Newpathwavfile);
	sprintf( Newnamewavfile,"C:\\Wav_File\\%s_%s_%s_%s.wav" ,WavBouche,ptrVariablesTraca->CieSn,chDate,chHeure);
	Delay(0.5);
	rename( Newpathwavfile,Newnamewavfile);

	//----------------------------------------------------------------------------------------
	//Copy wave file from tftp folder to mic folder-------------------------------------------
	//----------------------------------------------------------------------------------------
	strcpy(pathWavefile,"");
	sprintf( pathWavefile,"%s\\Script_TEST\\Prod_1\\Mic\\%s.wav",gChCurrentDir ,WavBouche);
	CopyFile (cheminwave,pathWavefile);
	Delay(0.5);*/
	//----------------------------------------------------------------------------------------
	//start TEST WIFI ------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
	/*do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_CMD_TEST_6Ghz,0), &infos,&nbInfos ,NULL, 10);
		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"TEST WIFI KO !!!!");
			Sleep(5);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1)); /*/
	sprintf(Pathscript2g,"%s\\%s",VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,0),VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,1));
	sprintf(Pathlogcurrent,"%s\\Log\\logCurrent.txt",VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,0));
	sprintf(Pathlogoutput,"%s\\Log\\logOutput.txt",VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,0));


	char pytlog1 [1024];
	sprintf(pytlog1,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,0)) ;
	//sprintf(python,"app.exe %s %s", pytlog,Pathlogoutput) ;
	//system(python);

	char  pythonNEW[2048];
	char pytlog [1024];
	sprintf(pytlog,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,0)) ;
	sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 6G %s", pytlog,ptrVariablesTraca->CiuSfcSAPME) ;
	//sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt  6G", pytlog) ;



	system(pythonNEW);
	sprintf( cheminlogarchive,"%s\\Archive" ,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,0));
	if ( !FileExists (cheminlogarchive, NULL) )
		MakeDir (cheminlogarchive);
	if ( FileExists (Pathlogoutput, NULL) )
		DeleteFile (Pathlogoutput);
	if ( FileExists (Pathlogcurrent, NULL) )
		DeleteFile (Pathlogcurrent);


	//Launch script Lancer_Test_Wi-Fi.bat -------------------------------------------
	//----------------------------------------------------------------------------------------
	do
	{
		iFlagRtray3 = 0;
		Status =LaunchExecutableEx (Pathscript2g, LE_SHOWNORMAL,&Handlescript );
		inbreRetray3 = inbreRetray3 +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"ERROR lancement script 5/2Ghz  !!!!");
			Sleep(5);
			iFlagRtray3 = 1;
			if(inbreRetray3 > 2)
				return -1;
		}
		//	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"------>");
	}
	while((inbreRetray3 <3) && (iFlagRtray3 ==1));

	//check File log_current -------------------------------------
	//------------------------------------------------------------
	do
	{
		inbreRetray1 = inbreRetray1 +1;
		if (!FileExists (Pathlogcurrent,0 ))
		{
			if ( inbreRetray1>9)
			{
				strcpy(chMessageErreur,"File log_current.txt not exist ");
				return -1;
			}
			Delay(5);
			//	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"------>");
		}
	}
	while((inbreRetray1 <10) && (!FileExists (Pathlogcurrent,0 )));
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"-----> Script started  ");

	//check File log_output.txt -------------------------------------
	//---------------------------------------------------------------
	do
	{
		inbreRetray2 = inbreRetray2 +1;
		if (!FileExists (Pathlogoutput,0 ))
		{
			if ( inbreRetray2>199)
			{
				strcpy(chMessageErreur,"File log_output.txt not exist ");
				return -1;
			}
			ProcessDrawEvents ();
			Sleep(2000);
			//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"------>");
		}
	}
	while((inbreRetray2 <200) && (!FileExists (Pathlogoutput,0 )));
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->EndScript");
	fichier = fopen(Pathlogoutput, "r");
	FileHandle = OpenFile (Pathlogoutput, VAL_READ_ONLY, VAL_OPEN_AS_IS, VAL_ASCII);
	GetFileInfo (Pathlogoutput, &FileSize );
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999,"------------------------>Results of Script test  WIFI 6Ghz<------------------------------");
	ReadFile (FileHandle,Buffer ,sizeof( Buffer) );
	GetFileSize(Pathlogoutput,&FileLength);
	taillebfr = sizeof( Buffer) ;
	Delay(2);
	FIL2LO_EcritTraceV2 (TRUE, nItfe,Buffer);
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_LOG, 999,"--------->Results");
	///////////////////////////////////////	///////////////////////////////////////

	//Status= FCT_Rcup_Mesure_log(nItfe, fichier ,&tabMesure,chMessageErreur  ) ;
	if(gSlot[nItfe].BNFTnteg.gchFlagTraca)
	{
		//  Status=MES_EnregistrerTableauV2 (ptrMesures,nItfe, fichier, chMessageErreur ) ;
		Status  = MES_EnregistrerTableauV2Log  ( ptrMesures,"resultfinale-6G.txt",nItfe ,fichier, chMessageErreur  );

	}

	fclose(fichier);
	//---------------------------------------------------------------

	CloseFile(FileHandle);
	FIL2LO_DateV2 (chDate);
	FIL2LO_HeureV2 (chHeure, chHeureMili);
	//check PASS /FAIL-----------------------------------------------
	//---------------------------------------------------------------
	Status=FindPattern (Buffer, 0,sizeof(Buffer), "P A S S", 0, 0) ;
	if ( Status <0)
	{
		Status=FindPattern (Buffer, 0,sizeof(Buffer), "F A I L", 0, 0) ;
		if( Status < 0 )
		{

			FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->TEST WIFI 6Ghz UNKOWN results");
			strcpy(chMessageErreur,"TEST WIFI 6Ghz UNKOWN results !!!!");
			sprintf( cheminlogscript,"%s\\Log\\%s_%s_%s_%s_6Ghz.log" ,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,0),"UNKOWN",ptrVariablesTraca->CieSn,chDate,chHeureMili);
			sprintf( logfolder,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,0) ) ;

			char  pythonNEW[2048];
			char pytlog [1024];
			sprintf(pytlog,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,0)) ;
			sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 6G %s", pytlog,ptrVariablesTraca->CiuSfcSAPME) ;
			//sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt  6G", pytlog) ;


			system(pythonNEW);
// sprintf(python,"app.exe %s %s", logfolder,cheminlogscript) ;
			//system(python);
		}
		else
		{
			Status=-1;
			//FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->TEST WIFI 5/2Ghz FAILED");
			//strcpy(chMessageErreur,"TEST WIFI 5/2Ghz FAILLED !!!!");
			sprintf( cheminlogscript,"%s\\Log\\%s_%s_%s_%s_6Ghz.log" ,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,0),"FAILED",ptrVariablesTraca->CieSn,chDate,chHeureMili);
			sprintf( logfolder,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_2GHZ,0) ) ;

			char  pythonNEW[2048];
			char pytlog [1024];
			sprintf(pytlog,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,0)) ;

			//sprintf(pythonNEW,"app.exe %s/logOutput.txt %s 6G", pytlog,Pathlogoutput) ;

			sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 6G %s", pytlog,ptrVariablesTraca->CiuSfcSAPME) ;
			system(pythonNEW);
//sprintf(python,"app.exe %s %s", logfolder,cheminlogscript) ;
			//system(python);
		}
		sprintf( cheminlogscript,"%s\\Log\\%s_%s_%s_%s_6Ghz.log" ,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,0),"FAILED",ptrVariablesTraca->CieSn,chDate,chHeureMili);
		sprintf( logfolder,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_2GHZ,0) ) ;
		// sprintf(python,"app.exe %s %s", logfolder,cheminlogscript) ;
		//system(python);

		char  pythonNEW[2048];
		char pytlog [1024];
		sprintf(pytlog,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,0)) ;
		//sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt  6G", pytlog) ;
		sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 6G %s", pytlog,ptrVariablesTraca->CiuSfcSAPME) ;
		system(pythonNEW);
	}
	else
	{
		Status=0;
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999,"----->TEST WIFI 6Ghz PASSED");
		sprintf( cheminlogscript,"%s\\Log\\%s_%s_%s_%s_6Ghz.log" ,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,0),"PASSED",ptrVariablesTraca->CieSn,chDate,chHeureMili);
		sprintf( logfolder,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_2GHZ,0) ) ;
		// sprintf(python,"app.exe %s %s", logfolder,cheminlogscript) ;
		//system(python);

		char  pythonNEW[2048];
		char pytlog [1024];
		sprintf(pytlog,"%s\\Log" , VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_PATH_SCRIPT_6GHZ,0)) ;
		//sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 6G", pytlog,Pathlogoutput) ;

		sprintf(pythonNEW,"app.exe %s/logOutput.txt logOutput.txt 6G %s", pytlog,ptrVariablesTraca->CiuSfcSAPME) ;
		system(pythonNEW);
	}

	rename( Pathlogoutput,cheminlogscript);


	sprintf( cheminlogarchivedate,"%s\\log_%s\\" ,cheminlogarchive,chDate);
	if ( !FileExists (cheminlogarchivedate, NULL) )
		MakeDir (cheminlogarchivedate);
	CopyFile (cheminlogscript,cheminlogarchivedate);
	DeleteFile (cheminlogscript);
	Sleep(200);
//	FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,"[exit{Pass:TT>}]", NULL,NULL ,NULL,10);



	return Status;
}


/*********************************************************************************************************
								Fonction Attente Demarrage GateWay
*********************************************************************************************************/
int FCT_AttenteDemarrageGateWay_telnet (int nItfe, char *messagErreur)
{
	int iCpt=0;
	int status=-1;

	do
	{
		status = FCT_CMD_PingGateWay (nItfe, messagErreur);

		ProcessDrawEvents ();

	}
	while ((++iCpt<20) && (status != 0) && (gNPAbort==FALSE));

	return status;
}
//--------------------------------------------------------------------------------------------------------------------------------


/*********************************************************************************************************
								Fonction Attente Ping GateWay
*********************************************************************************************************/
int FCT_CMD_PingGateWay (int nItfe, char *messagErreur)
{
	static int g_exeHandle;
	int Ping=-1;
	int status=-1;
	int iNumBytWritten=0;
	//char CMD_Retour[10000]={'\0'};
	//char CMD_Commande[1000]={'\0'};

	// system("C:\\Users\\G558412\\Desktop\\Tftpd64\\tftpd64.exe");

	//LaunchExecutable("C:\\Users\\G558412\\Desktop\\Tftpd64\\tftpd64.exe");
	//LaunchExecutableEx ("C:\\Tftpd64\\tftpd64.exe", LE_SHOWNORMAL,&g_exeHandle);
	//Sleep(2000);

	/*FIL2LO_PrintCom (nItfe, FIL2LO_COM_GAT_RX,"task
	kill /F /tftpd64.exe");
	status = InetTelnetWrite (gSlot[nItfe].igHandleConnexion , "taskkill /F /tftpd64.exe",  "\r\n", -1,&iNumBytWritten, 1000);*/


	//** status = InetPing ("1.1.1.2" , &Ping, 1000);


	status = InetPing ("192.168.5.1" , &Ping, 1000);
	//status = InetPing (gSlot[nItfe].BNFTnteg.gchAdressIP , &Ping, 1000);
	//FIL2LO_PrintCom (nItfe, FIL2LO_COM_GTW_RX, CMD_Commande);	// pour debug en local sans gateway ...
	if (Ping!=1)
	{
		strcpy (messagErreur, "Ping KO !!!");
		return -1;
	}

	//FIL2LO_PrintCom (nItfe, FIL2LO_COM_GTW_TX, CMD_Retour);

	return 0;
}








// ==============================================================================
// FONCTION :		FCT_TEST_wifi_5Ghz
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			06/09/2022
//  AUTEUR :		IHEB
//  DESCRIPTION :   FCT_TEST_wifi_5Ghz
// ==============================================================================
int FCT_Rcup_Mesure_log(int nItfe, FILE* fichier ,char*tabMesure,char*chMessageErreur  )
{
	char chLine[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char chMesure[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	char chCode[TAILLE_MAX] = ""; //chaine vide de TAILLE_MAX
	int lenchLine=0;
	int status=0;
	char find_1 = '(';
	char find_2 = ')';
	char find_3 = ',';
	int index_1;
	int index_2;
	int index_3;
	if(fichier != NULL)
	{
		while(fgets(chLine, TAILLE_MAX, fichier) != NULL)
		{
			lenchLine=strlen(chLine);
			if((lenchLine>3) )
			{
				status=0;
				status=    FindPattern (chLine, 0,sizeof(chLine), "_____", 0, 0) ;
				if (status>0)
				{
					CopyString (chCode,0 ,chLine,0 ,status);
					memset (chLine, '\0', sizeof( chLine));
				}

				if (chCode!="")
				{
					const char *ptr_1 = strchr(chLine, find_1);
					const char *ptr_2 = strchr(chLine, find_2);
					const char *ptr_3 = strchr(chLine, find_3);

					if((ptr_1)&&(ptr_2)&&(ptr_3))
					{
						int index_1 = ptr_1 - chLine;
						int index_2 = ptr_2 - chLine;
						int index_3 = ptr_3 - chLine;
						int index_4 = index_2 -index_1;
						int index_5 = index_2 -index_3;
						if (index_4>=5 && index_4<13 && index_5<8)
						{

							RemoveSurroundingWhiteSpace(chLine);
							sprintf( chMesure,"%s_%s" ,chCode,chLine);

							//   printf("%s\n",chMesure);

						}
					}
				}
			}
		}

//	FIL2LO_EcritTraceV2 (TRUE, nItfe,chMesure);
		getchar();
	}

	return 0;
}

// ==============================================================================
//  FONCTION     : FCT_OpenConnexionTelnet
//  VERSION      : S12001AA01
//  DATE         : 29/11/2012
//  AUTEUR       : TNI
//  DESCRIPTION  :
//  MODIFICATION :
// ==============================================================================
int FCT_OpenConnexionTelnet(int nItfe, char *messagErreur)
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;

	char Response [300]="";

	int Status=-1;
	int iErreur = -1;
	int iFlagRtray,inbreRetray=0;

	gSlot[nItfe].igHandleConnexion = -1;

	//Status = TelnetOpenSession (&gSlot[nItfe].igHandleConnexion, gSlot[nItfe].BNFTnteg.gchAdressIP, 23, "", "", "", "", Response);
	//**Status = TelnetOpenSession (&gSlot[nItfe].igHandleConnexion, "1.1.1.2", 23, "", "", "", "", Response);


	Status = TelnetOpenSession (&gSlot[nItfe].igHandleConnexion, "192.168.5.1", 23, "", "", "", "", Response);
	if (Status == 1)
	{
		Status = 0;
	}
	else
	{

		Status =  ERREUR_TELNET_OUVERTURE;
		AFficheMsgErreur(Status,messagErreur);
		return -1;
	}

	if((VAR_GET_UINT8(ptrVariablesConf,VAR_CONF_GTW_BWC_FLAG_LOGIN,0)) &&(Status == 0))
	{
		if(VAR_DEFINED(ptrVariablesConf,VAR_CONF_GTW_BWC_login) == TRUE)
		{
			do
			{
				iFlagRtray = 0;
				Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_login,0), NULL,NULL ,NULL, 7000);
				inbreRetray = inbreRetray +1;
				if ( (Status != 0) )
				{
					strcpy(messagErreur,"Erreur Ouverture telnet");
					Sleep(2000);
					iFlagRtray = 1;
					if(inbreRetray > 2)
						return -1;
				}
			}
			while((inbreRetray <3) && (iFlagRtray ==1));

		}
		else
		{
			strcpy (messagErreur, "Conf login n'esxiste pas");
			return -1;
		}


	}

	return Status;

}

//==============================================================================
//==============================================================================
/**
* \file DefFonction.c
*.
* \author Aymen.Charrada
* \version 1.0.0.0
* \date 28/11/2012
*
* \fn int AFficheMsgErreur(int iErreur, char * sMessage )
*
* \return 0/1
*
* \brief Fonction a pour objet de :
* \brief Afficher les messages d'erreur
*
*/
//==============================================================================
//==============================================================================
/*int AFficheMsgErreur(int iErreur, char * sMessage )
{
	switch (iErreur)
	{
		case ERREUR_TELNET_OUVERTURE :
			sprintf(sMessage,"%d :Erreur Ouverture Telnet",iErreur);
			break;
	}

	return (iErreur!=1 ? 0:1);
}*/

/*int TelnetOpenSession ( int *HandleTelnet,char *IPFAST, int NumPort, char *Login, char *TagLogin, char *Psw, char * TagPassword , char *Response )
{
	int iErreur=1;// Mauvais par defaut
	int Done=0;
	int iFastPret =-2;
	char response[3000]="";
	char sTamp[100]="";
	int pos=-1;
	int essai=0;
	int iTempHandle = -1;
	int	iCpt = 0;

	// Pbroblème session telnet
	//SetBreakOnLibraryErrors (0);

	iCpt = 0;
	do
	{
		//InetTelnetClose(iTempHandle);


		// Lock Telnet
		//-------------
		//CmtGetLock (gLockTelnet);
		//SetBreakOnLibraryErrors (0);

		iTempHandle = InetTelnetOpen (IPFAST, NumPort, 0);

		//SetBreakOnLibraryErrors (1);
		// Unlock Telnet
		//--------------
		//CmtReleaseLock (gLockTelnet);



		if (iTempHandle >=0 )
		{
			iCpt = 4;
		}
		else
		{
			Sleep(200);
		}

	}
	while(++iCpt <3);



	if (iTempHandle >=0 )
	{
		*HandleTelnet =  iTempHandle;
		return 1;
	}
	else
		return -1;
}*/

// ==============================================================================
// FONCTION :		FCT_CloseConnexionTelnet
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			29/11/2011
//  AUTEUR :		TNI
//  DESCRIPTION : 	Fermeture de la connecxion Telnet
// ==============================================================================
/*int FCT_CloseConnexionTelnet (int nItfe, char	*chMessageErreur, int HandleTelnet )
{
	int iErreur=1;

	iErreur=!InetTelnetClose(HandleTelnet);
	if(iErreur!=1)
		iErreur=ERREUR_TELNET_FERMETURE;

	return iErreur;
}*/

/*int  TelnetCloseSession(int HandleTelnet,char *Response)
{
	int iErreur=1;

	iErreur=!InetTelnetClose(HandleTelnet);
	if(iErreur!=1)
		iErreur=ERREUR_TELNET_FERMETURE;

	return iErreur;
}*/
// ==============================================================================
// FONCTION :		FCT_EnregistrementMesure
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			08/09/2022
//  AUTEUR :		IHEB
//  DESCRIPTION :   FCT_EnregistrementMesure
// ==============================================================================
int FCT_EnregistrementMesure (int nItfe)
{
	int 				CHAMPS_TAB = 10;
	char                chMess[SCPROD_MSG_LONG_MAX] = {'\0'};
	char                chValTMP[SCPROD_MSG_LONG_MAX] = {'\0'};
	char				**pTableauMesuresTemps  = NULL;
	//int 				Temps_Test;
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	int iResultatTest ;
	// On affiche le temps de test sur la fenêtre BPO
	// ----------------------------------------------
	//changement du calcul temps test ca etait comme la ligne commenté en bas==>
	//sprintf (chMess, GET_MESSAGE(FIL2LO_STR_DUREE_TEST), (gSlot[nItfe].nTempsFinTest - gSlot[nItfe].nTempsDebutTest));
	sprintf (chMess, GET_MESSAGE(FIL2LO_STR_DUREE_TEST), Temps_Test_intermediaire);
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, chMess);

	// On met en forme la remontée pour SAPME.
	// ----------------------------------------
	//modification calcul remonté par sameh
	//sprintf (chValTMP,"%ld ms",(gSlot[nItfe].nTempsFinTest - gSlot[nItfe].nTempsDebutTest));
	sprintf (chValTMP,"%ld s",Temps_Test_intermediaire );

	// On créee le tableau de mesures
	// ------------------------------
	pTableauMesuresTemps = (char**) malloc( sizeof(char*) * 2 * CHAMPS_TAB);

	// On alloue la mémoire sur le tableau pour chaque Champ
	// -----------------------------------------------------
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 0] = (char*) malloc( sizeof(char) * MES_NOM_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 1] = (char*) malloc( sizeof(char) * MES_STATUS_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 2] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 3] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 4] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 5] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 6] = (char*) malloc( sizeof(char) * MES_DESC_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 7] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 8] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 9] = (char*) malloc( sizeof(char) * SCPROD_MSG_LONG_MAX );

	// On alloue la mémoire sur le tableau pour chaque Champ
	// -----------------------------------------------------
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 0] = (char*) malloc( sizeof(char) * MES_NOM_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 1] = (char*) malloc( sizeof(char) * MES_STATUS_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 2] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 3] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 4] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 5] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 6] = (char*) malloc( sizeof(char) * MES_DESC_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 7] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 8] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 9] = (char*) malloc( sizeof(char) * SCPROD_MSG_LONG_MAX );

	// ========================================================
	// = Enregistrement des données dans le tableau de mesure =
	// ========================================================

	// Liste des Champs du Tableau :
	// ---------------------------
	/*
	0	code du type de test
	1	code du statut de test
	2	durée de la mesure
	3	valeur de mesure
	4	tolérance minimum de la mesure
	5	tolérance maximum de la mesure
	6	Description
	7	unité de mesure
	8	operation choisie
	9	commenteur
	*/

	if ( ptrVariablesTraca->iStartOK != 0 )
	{

		// On renseigne les différents champs de la mesure
		// ------------------------------------------------
		strcpy(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 0],SCPROD_DUREE_TEST_BTF) ;

		if(iResultatTest == TRUE)
		{
			strcpy(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 1],MES_STATUS_OK);
		}
		else
		{
			strcpy(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 1],MES_STATUS_KO);
		}

		sprintf(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 2],"%d",FALSE) ;
		//le calcul est changé par moi
		//sprintf (pTableauMesuresTemps[(0 * CHAMPS_TAB) + 3],"%f", (float) (gSlot[nItfe].nTempsFinTest - gSlot[nItfe].nTempsDebutTest)) ;
		sprintf (pTableauMesuresTemps[(0 * CHAMPS_TAB) + 3],"%f", (float)Temps_Test_intermediaire ) ;
		sprintf(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 4],"%f",(float) FALSE) ;
		sprintf(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 5],"%f",(float) FALSE);
		strcpy(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 6],SCPROD_DUREE_TEST_BTF) ;
		strcpy(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 7],"s" );
		strcpy(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 8],SCPROD_GROUPE_MESURE_BTF) ;
		strcpy(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 9],SCPROD_NOT_APPLICABLE) ;


		// On renseigne les différents champs de la mesure
		// ------------------------------------------------
		strcpy(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 0],SCPROD_DUREE_MANIP_BTF);

		if(iResultatTest == TRUE)
		{
			strcpy(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 1],MES_STATUS_OK) ;
		}
		else
		{
			strcpy(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 1],MES_STATUS_KO);
		}

		sprintf(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 2],"%d",FALSE) ;
		sprintf(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 3],"%f", FALSE) ;
		sprintf(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 4],"%f",(float) FALSE) ;
		sprintf(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 5],"%f",(float) FALSE) ;
		strcpy(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 6],SCPROD_DUREE_MANIP_BTF) ;
		strcpy(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 7],"s" );
		strcpy(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 8],SCPROD_GROUPE_MESURE_BTF) ;
		strcpy(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 9],SCPROD_NOT_APPLICABLE) ;



		// On appelle ici la fonction d'enregistrement du tableau
		// ------------------------------------------------------
		SCPROD_LogParametricDataTableau (nItfe, (char **) pTableauMesuresTemps, 2, CHAMPS_TAB, chMess);
	}

	// ===========================
	// = Libération des mémoires =
	// ===========================
	free ( pTableauMesuresTemps [0]);
	free ( pTableauMesuresTemps [1]);
	free ( pTableauMesuresTemps);

	return 1;

}
// ==============================================================================
// FONCTION :		FCT_EnregistrementMesure
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			08/09/2022
//  AUTEUR :		AYOUB 702306
//  DESCRIPTION :   FCT_EnregistrementMesureLOg mesure python
// ==============================================================================

int FCT_EnregistrementMesureLog (int nItfe,char ** pTableauMesuresTemps)
{

	int 				CHAMPS_TAB = 10;
	char                chMess[SCPROD_MSG_LONG_MAX] = {'\0'};
	char                chValTMP[SCPROD_MSG_LONG_MAX] = {'\0'};

	//int 				Temps_Test;
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	int iResultatTest ;
	// On affiche le temps de test sur la fenêtre BPO
	// ----------------------------------------------
	//changement du calcul temps test ca etait comme la ligne commenté en bas==>
	//sprintf (chMess, GET_MESSAGE(FIL2LO_STR_DUREE_TEST), (gSlot[nItfe].nTempsFinTest - gSlot[nItfe].nTempsDebutTest));
	sprintf (chMess, GET_MESSAGE(FIL2LO_STR_DUREE_TEST), Temps_Test_intermediaire);
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX, 999, chMess);

	// On met en forme la remontée pour SAPME.
	// ----------------------------------------
	//modification calcul remonté par sameh
	//sprintf (chValTMP,"%ld ms",(gSlot[nItfe].nTempsFinTest - gSlot[nItfe].nTempsDebutTest));
	sprintf (chValTMP,"%ld s",Temps_Test_intermediaire );

	// On créee le tableau de mesures
	// ------------------------------
	pTableauMesuresTemps = (char**) malloc( sizeof(char*) * 400 * CHAMPS_TAB);

	// On alloue la mémoire sur le tableau pour chaque Champ
	// -----------------------------------------------------
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 0] = (char*) malloc( sizeof(char) * MES_NOM_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 1] = (char*) malloc( sizeof(char) * MES_STATUS_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 2] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 3] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 4] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 5] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 6] = (char*) malloc( sizeof(char) * MES_DESC_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 7] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 8] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(0 * CHAMPS_TAB) + 9] = (char*) malloc( sizeof(char) * SCPROD_MSG_LONG_MAX );

	// On alloue la mémoire sur le tableau pour chaque Champ
	// -----------------------------------------------------
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 0] = (char*) malloc( sizeof(char) * MES_NOM_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 1] = (char*) malloc( sizeof(char) * MES_STATUS_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 2] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 3] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 4] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 5] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 6] = (char*) malloc( sizeof(char) * MES_DESC_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 7] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 8] = (char*) malloc( sizeof(char) * MES_UNITE_TAILLE_MAX );
	pTableauMesuresTemps[(1 * CHAMPS_TAB) + 9] = (char*) malloc( sizeof(char) * SCPROD_MSG_LONG_MAX );

	// ========================================================
	// = Enregistrement des données dans le tableau de mesure =
	// ========================================================

	// Liste des Champs du Tableau :
	// ---------------------------
	/*
	0	code du type de test
	1	code du statut de test
	2	durée de la mesure
	3	valeur de mesure
	4	tolérance minimum de la mesure
	5	tolérance maximum de la mesure
	6	Description
	7	unité de mesure
	8	operation choisie
	9	commenteur
	*/

	if ( ptrVariablesTraca->iStartOK != 0 )
	{

		// On renseigne les différents champs de la mesure
		// ------------------------------------------------
		strcpy(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 0],SCPROD_DUREE_TEST_BTF) ;

		if(iResultatTest == TRUE)
		{
			strcpy(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 1],MES_STATUS_OK);
		}
		else
		{
			strcpy(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 1],MES_STATUS_KO);
		}

		sprintf(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 2],"%d",FALSE) ;
		//le calcul est changé par moi
		//sprintf (pTableauMesuresTemps[(0 * CHAMPS_TAB) + 3],"%f", (float) (gSlot[nItfe].nTempsFinTest - gSlot[nItfe].nTempsDebutTest)) ;
		sprintf (pTableauMesuresTemps[(0 * CHAMPS_TAB) + 3],"%f", (float)Temps_Test_intermediaire ) ;
		sprintf(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 4],"%f",(float) FALSE) ;
		sprintf(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 5],"%f",(float) FALSE);
		strcpy(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 6],SCPROD_DUREE_TEST_BTF) ;
		strcpy(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 7],"s" );
		strcpy(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 8],SCPROD_GROUPE_MESURE_BTF) ;
		strcpy(pTableauMesuresTemps[(0 * CHAMPS_TAB) + 9],SCPROD_NOT_APPLICABLE) ;


		// On renseigne les différents champs de la mesure
		// ------------------------------------------------
		strcpy(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 0],SCPROD_DUREE_MANIP_BTF);

		if(iResultatTest == TRUE)
		{
			strcpy(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 1],MES_STATUS_OK) ;
		}
		else
		{
			strcpy(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 1],MES_STATUS_KO);
		}

		sprintf(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 2],"%d",FALSE) ;
		sprintf(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 3],"%f",(float) FALSE) ;
		sprintf(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 4],"%f",(float) FALSE) ;
		sprintf(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 5],"%f",(float) FALSE) ;
		strcpy(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 6],SCPROD_DUREE_MANIP_BTF) ;
		strcpy(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 7],"s" );
		strcpy(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 8],SCPROD_GROUPE_MESURE_BTF) ;
		strcpy(pTableauMesuresTemps[(1 * CHAMPS_TAB) + 9],SCPROD_NOT_APPLICABLE) ;



		// On appelle ici la fonction d'enregistrement du tableau
		// ------------------------------------------------------
		SCPROD_LogParametricDataTableau (nItfe, (char **) pTableauMesuresTemps, 400, CHAMPS_TAB, chMess);
	}

	// ===========================
	// = Libération des mémoires =
	// ===========================
	free ( pTableauMesuresTemps [0]);
	free ( pTableauMesuresTemps [1]);
	free ( pTableauMesuresTemps);

	return 1;

}


// ==============================================================================
// FONCTION :		FCT_Flachage
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			27/02/2024
//  AUTEUR :		Mejri Med Dhafer
//  DESCRIPTION :
// ==============================================================================

int FCT_Flachage (int nItfe, char	*chMessageErreur, char *SFC_Flache  )
{
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	int                 Status = 0;
	// char test[8000];
	do
	{
		strcpy (SFC_Flache,"")  ;
		ProcessDrawEvents ();
		PromptPopup ("Flashage" , "Flasher SFC",SFC_Flache ,27);

	}
	while (strlen(SFC_Flache) != 27 );
	strcpy (ptrVariablesTraca->CiuSfcSAPME,SFC_Flache)  ;

	SCPROD_InformationsSFC (nItfe,&gTcomBase,ptrVariablesTraca->CiuSfcSAPME, ptrVariablesTraca->chCodeProduit,ptrVariablesTraca->chIndiceNimCie,ptrVariablesTraca->chOrdreFabCMS, chMessageErreur );


	return 0;
}
// ==============================================================================
// FONCTION :		FCT_Generation_DFA
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			27/02/2024
//  AUTEUR :		Mejri Med Dhafer
//  DESCRIPTION :
// ==============================================================================
int FCT_GenerationDFA (int nItfe, char *strErreurMessage )
{
	int		            error = 0;
	int					Status = -1;
	int                 iExistenceSFC = 1;
	int					iFlagAssemblerSFCCiu=0;
	char                chMessErreur[1024] = {'\0'};
	char    			chMessTemp[512] = {'\0'};
	T_VARIABLES_TRACA   *ptrVariablesTraca = &(gSlot[nItfe].variablesTraca);
	T_POSTE_PRODUIT     *ptrProduit = &(gPosteProduits.produits[gSlot[nItfe].variablesTraca.idxProduit]);
	T_VARIABLES         *ptrVariablesConf = &(gSlot[nItfe].variablesConf);
	//T_VARIABLES         *ptrVariablesEtat = &(gSlot[nItfe].variablesEtat);
	char    			*MessErreur = NULL;
	char NomTest [200]="";
	int flag_flashageSFC=0 ;
	static char inventoryId[255]="";
	int blnResultat=FALSE;
	static char *qtyOnHand;
	static char *originalQty;
	static char *itemRef;
	char          Temp[TAILLE_MIN] = "";

	// INFO : 3 niveaux pour les messages dans cette fonction :
	// 1. chMessTemp pour l'affichage dans les logs + fenêtre de test
	// 2. chMessErreur Si non Vide : viendra être concaténé avec une message "Erreur" dans le log et "Retour autorisation de pass" dans la fenêtre
	// 3. strErreurMessage qui sera affichée dans le log et remontée en tracà. Message d'erreur par défaut si Vide

	// ===============================================
	// = RAZ des paramètres de sortie de la fonction =
	// ===============================================
	strErreurMessage[0] = '\0';

	// Affichage du Numsérie CIE lu au démarrage
	// ------------------------------------------
	sprintf ( NomTest, "Generation DFA");

	//IHM_GestCtrlPnl_V2 (nItfe,NomTest);



	Status=SAPME_GenerationDFA (nItfe, &gTcomBase,ptrVariablesTraca->CiuSfcSAPME, &iExistenceSFC,strErreurMessage );



	if ( (Status != 0) )
	{



		sprintf ( strErreurMessage,"Erreur: %s \n", NomTest);
		sprintf(strErreurMessage,"Test %i ==> %s \n", strErreurMessage);
		FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, strErreurMessage);

	}



	sprintf(Temp,"---------> DFA_Generer %s",ptrVariablesTraca->CieSn);
	FCT_AfficheInfo (nItfe, IHM_MODE_TRACE_TXTBOX|IHM_MODE_TRACE_LOG, 999, Temp);
	FIL2LO_PrintCom (nItfe, FIL2LO_COM_INFORMATION, Temp);

	sprintf ( strErreurMessage, "%s OK \n", NomTest);
	return Status;


}

// ==============================================================================
// FONCTION :		FCT_Generation_DFA_SAP
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			27/02/2024
//  AUTEUR :		Mejri Med Dhafer
//  DESCRIPTION :
// ==============================================================================
// ==============================================================================
int SAPME_GenerationDFA ( int nItfe, T_TCOM_BASE *tcomBase, char *REF, int *iExistenceSFC, char *strErreurMessage )
{
	int     			bResultSCProd = FALSE;
	int     			error = 0;
	int 				status;
	char    			*chMsgSCProd = NULL;
	char    			*chCodeRetour = NULL;
	char    			*chDFARetour = NULL;
	char    			chMsgTemp [TAILLE_MOY] = {'\0'};
	char    			chMsgInfo [TAILLE_MOY] = {'\0'};
	char    			chCodeRetourTemp [TAILLE_MOY] = {'\0'};
	char				*SFCRetour=NULL ;
	T_VARIABLES_TRACA	*ptrVariablesTraca = &gSlot[nItfe].variablesTraca;
	T_POSTE_PRODUIT     *ptrProduit = &(gPosteProduits.produits[gSlot[nItfe].variablesTraca.idxProduit]);

	// ==================
	// = Init Variables =
	// ==================

	strcpy(strErreurMessage,"");

	// ======================
	// = Appel Fonction DLL =
	// ======================
	sprintf(ptrVariablesTraca->chCodeProduit,"%s_SERIAL",ptrProduit->cie.chVersion);


	status = SCProduction_GestionProductions_GenerationSFC ( tcomBase->instSCProduction,
			 //"254046989_SERIAL",
			 ptrVariablesTraca->chCodeProduit,
			 "A",
			 &SFCRetour,
			 iExistenceSFC,
			 &strErreurMessage,NULL);

	strcpy(ptrVariablesTraca->CieSn,SFCRetour);


	return status;

}


// ==============================================================================
// FONCTION :		FCT_EcritureDFA
// ------------------------------------------------------------------------------
//  VERSION :		V1.0
//  DATE :			27/02/2024
//  AUTEUR :		Mejri Med Dhafer
//  DESCRIPTION :
// ==============================================================================

int FCT_EcritureDFA (int nItfe, char	*chMessageErreur )
{
	T_VARIABLES		*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	T_VARIABLES_TRACA	*ptrVariablesTraca = &gSlot[nItfe].variablesTraca;

	int 			Status = 0;
	int 			iFlagRtray,inbreRetray=0;
	char            cmd[255]="";
	char            Commande_1[255]="";
	char            Commande_2[255]="";
	char            Commande[255]="";
	char            DFA[255]="";

	int indicestart = 0;
	//int indiceend = 0;




	Status = FCT_GenerationDFA (nItfe, chMessageErreur);

	if (Status!=0)
	{
		return -1 ;
	}

	//  scos-manuf-data init -b eeprom  R788t
	sprintf(cmd,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_Gravage_DFA,0));
	indicestart = FindPattern (cmd, 0, -1, "{", 0, 0);
	CopyString(Commande_2,0,cmd,indicestart,strlen(cmd)+1);
	CopyString(Commande_1,0,cmd,0,indicestart);
	sprintf ( Commande, "%s %s %s ", Commande_1,ptrVariablesTraca->CieSn,Commande_2);


	;
	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,Commande, NULL,NULL ,NULL, 10000);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"Erreur Ecriture DFA");
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));



	return Status;
}



int FCT_Activation_DHCP(int nItfe, char	*chMessageErreur )
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_CMD_Activation_DHCP,0), &infos,&nbInfos ,NULL, 10000);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"Activation DHCP KO !!!!");
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));


	return Status;
}



int FCT_Desactivation_DHCP(int nItfe, char	*chMessageErreur )
{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_CMD_Desactivation_DHCP,0), &infos,&nbInfos ,NULL, 10000);

		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"Désactivation DHCP KO !!!!");
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));


	return Status;
}
int FCT_Remonte_SFTP(int nItfe, char	*chMessageErreur )

{
	T_VARIABLES			*ptrVariablesConf = &gSlot[nItfe].variablesConf;
	char Response [2000]="";
	int Status = 0;
	int erreur = 0;
	T_TAB_CMD cmdOut;
	char cmd[1024]= {"\0"};
	int             nbInfos = 0;
	char            **infos = NULL;
	int iFlagRtray=0,inbreRetray=0;

	do
	{
		iFlagRtray = 0;
		Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,VAR_GET_STRING(ptrVariablesConf,VAR_CONF_GTW_BWC_CMD_Rmonte_SFTP,0), &infos,&nbInfos ,NULL, 10000);
		if (Status==0)
		{
			Status = FCT_CmdComExecutionV3 (nItfe,AFFICHAGE_TRACE,"[scos-manuf-data -b eeprom dl_nvram_scp calsftpuser 10.153.249.8 /depot-sftp/ORION/{Pass:password:}][Xpaoce@332an{Pass:#}{Pass:SUCCESS: Calibration file}]", &infos,&nbInfos ,NULL, 10000);

		}
		inbreRetray = inbreRetray +1;
		if ( (Status != 0) )
		{
			strcpy(chMessageErreur,"Remonte SFTP KO !!!!");
			Sleep(2000);
			iFlagRtray = 1;
			if(inbreRetray > 2)
				return -1;
		}
	}
	while((inbreRetray <3) && (iFlagRtray ==1));


	return Status;
}










