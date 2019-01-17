#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFSIZE 256
#include "structures.c"
#include "calculateResult.c"
#include "studentDetails.c"

/*
*Asks user to select any one of the 4 listed operations
*/
int selectOperation(){
	int option;
	do{
		printf("Select one of the below options:\n \
		1. Calculate result in batch mode\n \
		2. Update a record and get the new grade\n \
		3. Display result based on roll number\n \
		4. Display results based on grades\n");
		scanf("%d",&option);
	}while(!(option==1 ||option==2 ||option==3 ||option==4));
	return option;
}

/*
*Calls the functionality related functions based on the otion selected by user.
*/
int main(){
	StudentDetails*  details=getStudentDetails();
	switch(selectOperation()){
		case 1: calcResult(details);
			printResult(details);
			createOutputFile(details);
			break;
		case 2: createOutputFile(updateStudentDetails());
			break;
		case 3: resultOfRoll();
			break;
		case 4: resultBasedOnGrade();
			break;
	}
}
