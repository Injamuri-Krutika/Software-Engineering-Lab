#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFSIZE 256
#include "structures.c"
#include "calculateResult.c"
#include "studentDetails.c"



void testCreateAddress(){
	Address * expected=(Address *)malloc(sizeof(Address));
	expected->roomNo=101;
	expected->hostel="A";
	expected->place="UOH";


	Address * actual=createAddress(101,"A","UOH");
	if(expected->roomNo==actual->roomNo &&
	expected->hostel==actual->hostel &&
	expected->place==actual->place){
		printf("Create Address testing SUCCESS\n");

	}else{

		printf("Create Address testing FAILED\n");
	}

}

void testCreateStudent(){
	Student * expected=(Student *)malloc(sizeof(Student));
	expected->roll=1;
	expected->name="Siri";
	expected->marks1=90.5;
	expected->marks2=89.5;
	expected->marks3=88.5;
	expected->address=createAddress(101,"A","UOH");


	Student * actual=createStudent(1,"Siri",101,"A","UOH",90.5,89.5,88.5);
	if(expected->roll==actual->roll &&
		expected->name==actual->name &&
		expected->marks1==actual->marks1 &&
		expected->marks2==actual->marks2 &&
		expected->marks3==actual->marks3 &&
		expected->address->roomNo==actual->address->roomNo &&
		expected->address->hostel==actual->address->hostel &&
		expected->address->place==actual->address->place){
		printf("Create Student testing SUCCESS\n");
	}else{

		printf("Create Student testing FAILED\n");
	}	

}

int main(){

	testCreateAddress();
	testCreateStudent();	
	return 0;
}
