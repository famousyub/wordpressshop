//==============================================================================
//
// Title:		replacingall.h
// Purpose:		A short description of the interface.
//
// Created on:	21/02/2024 at 08:39:03 by .
// Copyright:	. All Rights Reserved.
//
//==============================================================================

#ifndef __replacingall_H__
#define __replacingall_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// External variables

//==============================================================================
// Global functions

char* replaceWord(const char* s, const char* oldW, 
                const char* newW) ;

int processId (int x);


#ifdef __cplusplus
    }
#endif

#endif  /* ndef __replacingall_H__ */
