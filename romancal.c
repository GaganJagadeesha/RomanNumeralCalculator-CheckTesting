#include "romancal.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH	4096
#define EQUAL	0
#define ELEVEN	11
#define TWELVE	12
#define	ONE	1
char* strwith[]= {"V","IV","X","IX","L","XL","C","XC","D","CD","M","CM"};
char* strrep[]={"IIIII","IIII","VV","VIV","XXXXX","XXXX","LL","LXL",
		"CCCCC","CCCC","DD","DCD"};
char* expand (char* strwith[],char* strrep[],char* strori) {
	int j;	
	for (j=ELEVEN;j>-ONE;j--){
	str_replace(strori, strrep[j], strwith[j]);
	}
	return strori ;
 }
char* compress(char* strwith[],char* strrep[],char* strori) {
	int i;
	for ( i=EQUAL;i<TWELVE;i++){
	str_replace(strori,strrep[i],strwith[i]);
	}
	return strori;
}
void str_replace(char * ori_string, char * rep_string, char * with_string) {
	char buffer[MAX_LENGTH];
        char * ch;
        if(!(ch = strstr(ori_string, rep_string))) //return if not present
        return;
        strncpy(buffer, ori_string, ch-ori_string); // copy the original string
        buffer[ch-ori_string] = EQUAL; //replace the characters
        sprintf(buffer+(ch - ori_string), "%s%s", with_string, ch + strlen(rep_string)); // concatenate the copied string with the replaced characters in the string
        ori_string[EQUAL] = EQUAL; 
        strcpy(ori_string, buffer); // copy the complete replaced string into the buffer
        return str_replace(ori_string, rep_string, with_string); // call recursively
 }
char* add(char* ori1, char* ori2) {		
	expand(strrep,strwith,ori1); // expand the first roman number
	expand(strrep,strwith,ori2); //expand the second roman number
	strcat(ori1, ori2);	// concatenate both the numbers	
	compress(strwith,strrep,ori1); // reduce the concatenated string to ROMAN Numeral form	
	return ori1;
}
