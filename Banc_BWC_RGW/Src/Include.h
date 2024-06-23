// ==============================================================================
//   COPYRIGHT (C) SAGEM COMMUNICATIONS
//   ALL RIGHTS RESERVED.
//  
// 
// ==============================================================================
//   PROJET			: Banc Personnalisation
//   MODULE			: Include
//   PROCESSEUR		: INTEL Pentium
//   ENVIRONNEMENT	: Windows XP Pro Service Pack 2 / Labwindows CVI 8.5
// ==============================================================================
//   DESCRIPTION	: Définition des fichiers Include du projet.
//            		  
// ==============================================================================
//   REMARQUES		:
// ==============================================================================
//   MODIFICATIONS	:   
//
// Version Rev X
// Date / Author
//
// V 1.4.0 
// 13-Octobre-2009	NCR (DT2E)
//		>>>	 Création
// ==============================================================================
#ifndef __INCLUDE_H__
#define __INCLUDE_H__


// ==============================================================================
// DECLARATION DES INCLUDE
// ==============================================================================
#include <windows.h>
#include "System.h"
#include <winsock2.h>

// System
//#include "nireport.h"
#include <cvirte.h> 
#include <utility.h>
#include <userint.h>
#include <formatio.h>
#include "cvidef.h"
#include <userint.h>
#include <rs232.h>
#include <visa.h>
#include <ansi_c.h>
#include "cvintwrk.h"

// Modules
#include "Multilangue.h" 
#include "inifile.h"
#include "RS232_Def.h"  
#include "IhmNFT.h"
#include "dllTracaCom.h"
#include "Thread.h"
#include "main.h" 
#include "ScProduction.h"
#include "TracaSCProduction.h"
#include "fil2lo.h"
#include "Mesures.h"
#include "Variables.h"

// Define, à l'origine c'est dans dio.h
#include "define.h"
#include "Globale.h"
#include "Ihm.h"
#include "Fonctions.h"
#include "Telnet.h"

//Define Pwermetter
//#include <rsnrpz.h>
//#include <rspwrmeter.h>

//Define IRTrans
#include "IRTransDLL.h"

/// gestion usb
//#include "CMD.h"									
//#include "usbioctl.h"
//#include "usbtree.h"
//#include "JMUsbSdk.h"
//#include "usb.h"
//#include <tcpsupp.h>
//#include "TCPIP.h"
#endif	// #ifndef __INCLUDE_H__




