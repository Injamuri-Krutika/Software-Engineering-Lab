typedef struct address{
	int roomNo;
	char * hostel;
	char * place;

}Address;


typedef struct student{
	int roll;
	char * name;
	float marks1,marks2,marks3, average,total;
	char result;
	Address * address;
}Student;


typedef struct studentList{

	int numberOfStudents;
	Student ** stuList;

}StudentDetails;

/*
*Returns a new Address structure by setting all the input values
*/
Address * createAddress(int roomNo,char * hostel,char *place){
	Address * newAddress=(Address *)malloc(sizeof(Address));
	newAddress->roomNo=roomNo;
	newAddress->hostel=hostel;
	newAddress->place=place;
	return newAddress;
}


/*
*Returns a new Student structure by setting all the input values
*/
Student * createStudent(int roll,char *name,int roomNo,char *hostel,char *place,float marks1,float marks2,float marks3){
	Student * newStudent=(Student *)malloc(sizeof(Student));
	newStudent->roll=roll;
	newStudent->name=name;
	newStudent->marks1=marks1;
	newStudent->marks2=marks2;
	newStudent->marks3=marks3;
	newStudent->address=createAddress(roomNo,hostel,place);
	return newStudent;
}

