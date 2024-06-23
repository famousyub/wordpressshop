//==============================================================================
//
// Title:		replacingall.c
// Purpose:		A short description of the implementation.
//
// Created on:	21/02/2024 at 08:39:03 by .
// Copyright:	. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#include "replacingall.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

/// HIFN  What does your function do?
/// HIPAR x/What inputs does your function expect?
/// HIRET What does your function return?

char* replaceWord(const char* s, const char* oldW, 
                const char* newW) 
{
	char *result  ;
	int i , cnt=0  ;
	int newlen = strlen(newW ) ;
	int oldlen =strlen(oldW);
	// ayoub va a l'ecole  ayoub , 
	for(i = 0 ; s[i]!='\0';i++) {
		if(strstr(&s[i] , oldW  )==&s[i])  {
			cnt++ ;
			i+=oldlen -1;
		}
		
	}
	int _m = abs(newlen-oldlen);
	result = (char* ) malloc(sizeof(char) *  (i+cnt * _m + 1)) ;
	
	i = 0;
	
	while(*s) {
	   if(strstr(s,oldW) == s) {
		   strcpy(result[i], newW);
		   i+= newlen ;
		   s+= oldlen;
	   }
	   else result[i++] = *s++;
	   
	   
	   result[i] = '\0';
	   
	   
	   return result;
	}
}

int processId (int x)
{
	return x;
}
