#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFSIZE 256

void printMatrix(int i,int j,int ** mat){
	for(int l=0;l<i;l++){
		for(int m=0;m<j;m++){
			printf("%d\t",mat[l][m]);
		}
		printf("\n");
	}
}


int * readDimensions(){
	char * dim1=(char*)malloc(sizeof(char)*3);
	char * dim2=(char*)malloc(sizeof(char)*3);
	int * dim=(int *)malloc(sizeof(int)*2);
	fgets(dim1,3,stdin);
	if(!validInput(dim1)){
		printf("dim 1 not valid");

	}
	fgets(dim2,3,stdin);
	if(!validInput(dim2)){

		printf("dim 2 not valid\n");

	}
	dim[0]=atoi(dim1);
	dim[1]=atoi(dim2);
	return dim;
	
}

int ** readMatrixValues(int dim1,int dim2){
	char * matInput=(char*)malloc(sizeof(char)*BUFFSIZE);
	int ** matrix=(int**)malloc(sizeof(int *) * dim1);
	for(int i=0;i<dim1;i++){
		matrix[i]=(int *)malloc(sizeof(int ) * dim2);
	}
	printf("Enter matrix [%dx%d] values\n",dim1,dim2);
	for(int i = 0;i < dim1;i++){
		for(int j = 0;j < dim2;j++){
			fgets(matInput,BUFFSIZE,stdin);
			if(validInput(matInput)){
				
					matrix[i][j]=atoi(matInput);
				
			}else{
			//TODO
			printf("Inside todo\n");
			}
		
		}
	}
	return matrix;
}

int ** multiplyMatrix(int m1d1,int m2d2,int m1d2,int ** m1,int **m2){
	int **result=(int**)malloc(sizeof(int *) * m1d1);
	for(int i=0;i<m1d1;i++){
		result[i]=(int *)malloc(sizeof(int ) * m2d2);
	}
	for(int i =0 ;i<m1d1;i++){
			for(int j = 0;j<m2d2;j++){
				int sum=0;
				for(int k=0;k<m1d2;k++){
					sum=sum+m1[i][k]*m2[k][j];
					
				}
				result[i][j]=sum;
			}
			
		}
	return result;
}