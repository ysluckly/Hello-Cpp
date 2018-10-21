/***********************************************************
*                      ³ÌÐòÃû³Æ£ºC/C++×¢ÊÍ×ª»»             *
*                      ±àÒë»·¾³£ºVS2013                    *
*                      ±àÖÆÈÕÆÚ£º2018.6.03                 *
*                                      -----by Hunter	   *
***********************************************************/

#ifndef  __COMMENTCONVERT_H__
#define  __COMMENTCONVERT_H__

#include <stdio.h>
#include <stdlib.h>

enum STATUS
{
	NUL_STATUS, //ÎÞ×¢ÊÍ×´Ì¬
	C_STATUS,   //CÓïÑÔ×¢ÊÍ×´Ì¬
	CPP_STATUS, //c++×¢ÊÍ×´Ì¬
	END_STATUS,	//½áÊø×¢ÊÍ×´Ì¬
	STR_STATUS	//×Ö·û´®×¢ÊÍ×´Ì¬
};


void CommentConvert(FILE* pfIn, FILE* pfOut);
void DoNulStatus(FILE* pfIn, FILE* pfOut);   //ÎÞ×¢ÊÍ×´Ì¬

void DoCStatus(FILE* pfIn, FILE* pfOut);	  //CÓïÑÔ×¢ÊÍ×´Ì¬
void DoCppStatus(FILE* pfIn, FILE* pfOut );	  //c++×¢ÊÍ×´Ì¬
void DoStrStatus(FILE* pfIn, FILE* pfOut);	   //×Ö·û´®×¢ÊÍ×´Ì¬


#endif  //__COMMENTCONVERT_H__