/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2024. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL_CONF                       1
#define  PANEL_CONF_OKBUTTON              2       /* control type: command, callback function: OkCallback */
#define  PANEL_CONF_TEXTMSG               3       /* control type: textMsg, callback function: (none) */
#define  PANEL_CONF_RADIOGROUP            4       /* control type: tree, callback function: (none) */
#define  PANEL_CONF_TEXTMSG_2             5       /* control type: textMsg, callback function: (none) */
#define  PANEL_CONF_TEXTMSG_3             6       /* control type: textMsg, callback function: (none) */
#define  PANEL_CONF_TEXTMSG_4             7       /* control type: textMsg, callback function: (none) */
#define  PANEL_CONF_TEXTMSG_5             8       /* control type: textMsg, callback function: (none) */
#define  PANEL_CONF_TEXTMSG_7             9       /* control type: textMsg, callback function: (none) */
#define  PANEL_CONF_TEXTMSG_6             10      /* control type: textMsg, callback function: (none) */
#define  PANEL_CONF_TEXTMSG_8             11      /* control type: textMsg, callback function: (none) */

#define  PNL_INTIT                        2
#define  PNL_INTIT_ANNULER                2       /* control type: command, callback function: CB_IntitPalette */
#define  PNL_INTIT_INTIT                  3       /* control type: ring, callback function: CB_IntitPalette */
#define  PNL_INTIT_VALIDER                4       /* control type: command, callback function: CB_IntitPalette */
#define  PNL_INTIT_SLIDE                  5       /* control type: scale, callback function: (none) */
#define  PNL_INTIT_PICTURE                6       /* control type: picture, callback function: (none) */
#define  PNL_INTIT_FILTRE_PRODUIT         7       /* control type: string, callback function: (none) */
#define  PNL_INTIT_TXT_SLIDE              8       /* control type: textMsg, callback function: (none) */

#define  PNL_MAIN                         3
#define  PNL_MAIN_SLOT                    2       /* control type: textMsg, callback function: (none) */
#define  PNL_MAIN_TRACE                   3       /* control type: textBox, callback function: (none) */
#define  PNL_MAIN_TXT_INFO                4       /* control type: string, callback function: (none) */
#define  PNL_MAIN_LED                     5       /* control type: LED, callback function: (none) */
#define  PNL_MAIN_Temps_Test              6       /* control type: string, callback function: (none) */
#define  PNL_MAIN_Test_Bouton             7       /* control type: textBox, callback function: (none) */
#define  PNL_MAIN_RETEST                  8       /* control type: picture, callback function: (none) */
#define  PNL_MAIN_DEPANNAGE               9       /* control type: picture, callback function: (none) */
#define  PNL_MAIN_LED_6G                  10      /* control type: LED, callback function: (none) */
#define  PNL_MAIN_LED_5G                  11      /* control type: LED, callback function: (none) */
#define  PNL_MAIN_LED_2G                  12      /* control type: LED, callback function: (none) */

#define  PNL_PERE                         4
#define  PNL_PERE_TRACE_5G                2       /* control type: textBox, callback function: (none) */
#define  PNL_PERE_TRACE_6G                3       /* control type: textBox, callback function: (none) */
#define  PNL_PERE_TRACE_2G                4       /* control type: textBox, callback function: (none) */
#define  PNL_PERE_ACTIVE_LOG              5       /* control type: radioButton, callback function: (none) */
#define  PNL_PERE_COMMANDBUTTON           6       /* control type: command, callback function: Quiiter */
#define  PNL_PERE_DEFINITION              7       /* control type: string, callback function: (none) */
#define  PNL_PERE_PICTURE_2               8       /* control type: picture, callback function: (none) */
#define  PNL_PERE_TEST_CONFIG             9       /* control type: textMsg, callback function: (none) */
#define  PNL_PERE_LED_TRACA               10      /* control type: LED, callback function: (none) */
#define  PNL_PERE_PICTURE                 11      /* control type: picture, callback function: (none) */
#define  PNL_PERE_TEXTMSG_3               12      /* control type: textMsg, callback function: (none) */
#define  PNL_PERE_TEXTMSG                 13      /* control type: textMsg, callback function: (none) */
#define  PNL_PERE_TEXTMSG_2               14      /* control type: textMsg, callback function: (none) */

#define  PNL_POPUP                        5
#define  PNL_POPUP_CB_NON                 2       /* control type: command, callback function: CB_PopupNon */
#define  PNL_POPUP_CB_OUI                 3       /* control type: command, callback function: CB_PopupOui */
#define  PNL_POPUP_CB_OK                  4       /* control type: command, callback function: CB_PopupOk */
#define  PNL_POPUP_TXT_MSG                5       /* control type: textMsg, callback function: (none) */
#define  PNL_POPUP_DECO_GRILLE            6       /* control type: deco, callback function: (none) */

#define  PNL_SN                           6
#define  PNL_SN_TXT_SN                    2       /* control type: string, callback function: ValidationSnSlot */
#define  PNL_SN_PICTURE                   3       /* control type: picture, callback function: (none) */
#define  PNL_SN_PICTURE_2                 4       /* control type: picture, callback function: (none) */


     /* Control Arrays: */

#define  CTRLARRAY                        1

     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK CB_IntitPalette(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_PopupNon(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_PopupOk(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_PopupOui(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OkCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quiiter(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ValidationSnSlot(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
