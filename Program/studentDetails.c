/*
*Reads from input.txt file and returns pointer to 
*StudentDetails structure.
*/
StudentDetails* getStudentDetails(){
	FILE * in = fopen("input.txt","r");
	
	StudentDetails * studetails=(StudentDetails *)malloc(sizeof(StudentDetails));	
	int numberOfStudents;
	fscanf(in,"%d",&numberOfStudents);
	
	
	Student** stuList=(Student **)malloc(sizeof(Student*)*numberOfStudents);
	for(int i=0;i<numberOfStudents;i++){
		int roll,roomNo;
		char * name =(char *)malloc(sizeof(char)*BUFFSIZE);
		char * hostel =(char *)malloc(sizeof(char)*BUFFSIZE);
		char * place =(char *)malloc(sizeof(char)*BUFFSIZE);
		float marks1,marks2,marks3, average,total;
		char result;
		fscanf(in,"%d %s %d %s %s %f %f %f",&roll,name,&roomNo,hostel,place,&marks1,&marks2,&marks3);
		stuList[i]=createStudent(roll,name,roomNo,hostel,place,marks1,marks2,marks3);
		
	}
	studetails->numberOfStudents=numberOfStudents;
	studetails->stuList=stuList;
	fclose(in);
	return studetails;
}

/*
*Prints table heading labels in stdout
*/
void printTableHeadings(){
	printf("Roll\tName\tRoomNo\tHostel\tPlace\tMarks1\tMarks2\tMarks3\tTotal\tAverage\tGrade\n");
	printf("--------------------------------------------------------------------------------------\n");
}

/*
*Prints table heading labels in the file 'fp'
*/
void printTableHeadingsInFile(FILE* fp){
		printf("Hhere 1");
	fprintf(fp,"%s","Roll\tName\tTotal\tAverage\tGrade\n");
	fprintf(fp,"%s","---------------------------------------\n");
}

/*
*Prints Student's result (total, average, grade) in file
*/
void printStudentResultInFile(FILE* fp,Student * student){
	printf("Hhere 2");
	fprintf(fp,"%d\t%.2f\t%.2f\t%c\n",student->roll,student->total,student->average,student->result);
}

/*
*Prints all the details of a Student in stdout
*/
void printStudentDetails(Student * student){
	printf("%d\t%s\t%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%c\n",student->roll,
					student->name,student->address->roomNo,student->address->hostel,
					student->address->place,student->marks1,student->marks2,
					student->marks3,student->total,student->average,student->result);
}

/*
*Creates output file that consists of results
*/
void createOutputFile(StudentDetails * details){
	FILE * out = fopen("output.txt","w");
	StudentDetails * details1=getStudentDetails();
	fprintf(out,"%s","Roll\tTotal\tAverage\tGrade\n");
	fprintf(out,"%s","---------------------------------------\n");
	Student ** stuList=details->stuList;
	Student ** stuList1=details1->stuList;
	for(int i=0;i<details->numberOfStudents;i++){
		char * line =(char *)malloc(sizeof(char)*BUFFSIZE);
		sprintf(line,"%d\t%.2f\t%.2f\t%c\n",stuList[i]->roll,stuList[i]->total,stuList[i]->average,stuList[i]->result);
		fprintf(out,"%s\n",line);
	}
	fclose(out);
}

/*
*Takes the roll no. from user and prints the corresponding result
*/
void resultOfRoll(){
	StudentDetails* details= getStudentDetails();
	int roll,printHead=0;
	printf("Enter roll no. to be searched for\n");
	scanf("%d",&roll);
	Student ** stuList=details->stuList;
	for(int i=0;i<details->numberOfStudents;i++){
		if(stuList[i]->roll==roll){
			if(!printHead){
				printTableHeadings();
				printHead=1;
			}
			setAvgTotGrade(stuList[i]);
			printStudentDetails(stuList[i]);
			exit(0);
		}
	}
	printf("Student with Roll num %d does not exist\n",roll);
}

/*
*Takes the grade from user and prints the student details having the input grade
*/
void resultBasedOnGrade(){
	StudentDetails* details= getStudentDetails();
	char grade;
	int printHead=0;
	printf("Enter grade to be searched for\n");
	scanf(" %c",&grade);
	Student ** stuList=details->stuList;
	for(int i=0;i<details->numberOfStudents;i++){
		setAvgTotGrade(stuList[i]);
		if(stuList[i]->result==grade){
			if(!printHead){
				printTableHeadings();
				printHead=1;
			}
			printStudentDetails(stuList[i]);
		}
	}
	if(!printHead)
		printf("Students with grade \'%c\' do not exist\n",grade);
}

/*
*Updates the particlar line number record.
*/
void updateRecordInFile(int lineNumber,Student * student){
	FILE *fp1=fopen("input.txt","r");
	FILE *fp2=fopen("new.txt","w");
	int lineNo=1;
	char * line=(char *)malloc(sizeof(char)*BUFFSIZE);
	while(fgets(line,BUFFSIZE,fp1)!=NULL){
		if(lineNo++!=lineNumber){
			fputs(line,fp2);
		}else{
			fprintf(fp2,"%d %s %d %s %s %.2f %.2f %.2f\n",student->roll,
					student->name,student->address->roomNo,student->address->hostel,
					student->address->place,student->marks1,student->marks2,
					student->marks3);
		}
	}
	fclose(fp1);
	fclose(fp2);
	remove("input.txt");
	rename("new.txt","input.txt");
}

/*
*Prints result of all students in stdout
*/
void printResult(StudentDetails * details){
	Student ** stuList=details->stuList;
	int numberOfStudents=details->numberOfStudents;
	printf("Below is the result of all the students:\n");
	printTableHeadings();
	for(int i=0;i<numberOfStudents;i++){
		printStudentDetails(stuList[i]);
	}
}

/*
*Takes M1, M2, M3 values from user and updates then in the input file and updated result in output file.
*/

StudentDetails * updateStudentDetails(){
	StudentDetails* details= getStudentDetails();
	int roll,found=0;
	printf("Enter roll no. to be updated for\n");
	scanf("%d",&roll);
	Student ** stuList=details->stuList;
	for(int i=0;i<details->numberOfStudents;i++){
		setAvgTotGrade(stuList[i]);
		if(stuList[i]->roll==roll){
			
			printTableHeadings();
			printStudentDetails(stuList[i]);
			found=1;
			printf("Enter updated M1 M2 and M3\n");
			scanf("%f %f %f",&stuList[i]->marks1,&stuList[i]->marks2,&stuList[i]->marks3);
			setAvgTotGrade(stuList[i]);
			printf("\nBelow are the updated details of Roll No:%d\n",roll);
			printTableHeadings();
			printStudentDetails(stuList[i]);
			updateRecordInFile(i+2,stuList[i]);
			//break;
		}
	}
	return details;
}
