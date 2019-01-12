#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool validInput(char * input){

	for(int i=0;input[i]!='\n'&&input[i]!='\0';i++){
		char c=input[i];
		if(!(c>='0'&&c<='9')){
			return false;
		}
	}

	return true;
}
