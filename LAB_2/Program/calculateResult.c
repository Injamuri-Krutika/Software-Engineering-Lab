/*
*Checks if the student has passed in all the subjects. 
*If passed, returns 1 else returns 0.
*/
int passedInAllSub(float m1,float m2,float m3){
	if(m1 > 50 && m2 > 50 && m3 >50)
		return 1;
	else 
		return 0;
}

/*
*returns grade (A,B,C,F) of the student bassed on marks
*/
char getGrade(float m1,float m2,float m3,float avg){
	if(passedInAllSub(m1 , m2 , m3) && avg>=50){
		if(avg > 85)
			return 'A';
		else if(avg > 65)
			return 'B';
		else if(avg >= 50)
			return 'C';
		
	}else
		return 'F';

}

/*
*Calculates total , grade and average of the student and sets the values
*/
void setAvgTotGrade(Student * student){

	int m1=student->marks1,m2=student->marks2,m3=student->marks3;
	student->total=m1+m2+m3;
	float avg=student->total/3;
	student->average=avg;
	student->result=getGrade(m1,m2,m3,avg);

}

/*
*To calculate result of all the students.
*/
void calcResult(StudentDetails * details){
	Student ** stuList=details->stuList;
	int numberOfStudents=details->numberOfStudents;
	for(int i=0;i<numberOfStudents;i++){
		setAvgTotGrade(stuList[i]);
	}
}

