
#include<stdio.h>
#include<stdlib.h>
#define MAX_TERM 101
#define _K 4
#define _L 4
#define _M 4

typedef struct{
	
	int row;
	int column;        //The struct part in appendix 1 is used
	int value;
} non_zero_values;


int result[_K][_L]; //variable to save the transposed matrix


int main()
 {
 	
 
 	int count=1;
 	non_zero_values matrix1[MAX_TERM];
	non_zero_values matrix2[MAX_TERM];   //here we define matrix 1 and matrix 2
 	compact(matrix1,matrix2);
 	printf("\n");
    multiply(matrix1,matrix2);
 }

int transpose1(int trasnpose[_K][_L]) //transpose function
{
     int i,j;
	for(i=0;i<4;i++)
   {
   	for(j=0;j<4;j++)
   	{
   		result[j][i]=trasnpose[i][j]; //registers the transposed matrix in the result matrix
   	
   		
	   }
   }
   return result;  //Returns the return matrix
	
}



int compact(non_zero_values compact_matrix1[MAX_TERM],non_zero_values compact_matrix2[MAX_TERM]) //function that makes the given sparse matrices compact

{ int sparse_matrix_1[_K][_L] = { {0, 10 , 0 , 5 }, {0 , 2 , 4 , 0 }, {0 , 0 , 0 , 0 }, {3 , 0, 0 , 7 } }; //first sparse matrix
int sparse_matrix_2[_L][_M] = { {1 , 0 , 0, 2}, {0 , 0 , 3 , 0}, {0 , 8 , 0, 0 }, {5 , 0, 10, 0 } }; //second sparse matrix
	
	

	int count=0;
	int i,j;
	transpose1(sparse_matrix_2); //we tranpose the second matrix
	
	
		 for(i=0;i<4;i++) {
    	for( j=0;j<4;j++) {
    		if(sparse_matrix_1[i][j]!=0){
	               	compact_matrix1[count].row=i;     //The first matrix is compacted in this section.
	                compact_matrix1[count].column=j;
		            compact_matrix1[count].value=sparse_matrix_1[i][j];
		            count++;
 }
 }	}
                                 	
        printf("matrix 1:\n\nrow  column value\n");
        
        
	     for(i=0;i<count;i++){                                                                                         //Function that prints the 1st matrix
         	printf("%d  \t%d  \t%d\n",compact_matrix1[i].row+1,compact_matrix1[i].column+1,compact_matrix1[i].value);
}
    count=0;
		 		
				 
		for(i=0;i<4;i++){
    	for( j=0;j<4;j++){
    		if(result[i][j]!=0){
		         compact_matrix2[count].row=i;    //The second transposed matrix is being compacted
		         compact_matrix2[count].column=j;
	             compact_matrix2[count].value=result[i][j];
	            count++;}
	}}
	
	
	
		printf("\n\n2.matris (Transposed Matrix):\n\nrow  column value\n");
                   for(i=0;i<count;i++){                                                                              //prints the 2nd transposed matrix
         	printf("%d  \t%d  \t%d\n",compact_matrix2[i].row+1,compact_matrix2[i].column+1,compact_matrix2[i].value);}
         	
         	
         	
         	
	return compact_matrix1,compact_matrix2; //Returns compacted matrices 1 and 2
}
void multiply(non_zero_values compact_matrix1[MAX_TERM],non_zero_values compact_matrix2[MAX_TERM]) //function that multiplies 2 sparse matrices sent
{

   int count=0;
   int i=0,j=0,temp=0;
   int number_of_row_sparse1; //keeps the number of rows in the first sparse matrix
   int number_of_row_sparse2; //keeps the number of rows in the second sparse matrix

    
   
   non_zero_values result_matrix[MAX_TERM]; //variable that records the result of 2 sparse matrices multiplied
   
    while( i<5|| j<5) {
        number_of_row_sparse1 = compact_matrix1[i].row; //We calculate the number of rows of the first matrix
        number_of_row_sparse2 = compact_matrix2[j].row;//We calculate the number of rows of the second matrix
        int temp_variable1 = i; 
		int temp_variable2 = j;
		
            while( compact_matrix1[temp_variable1].row== number_of_row_sparse1 ) {
                temp_variable2=j;
                    while(compact_matrix2[temp_variable2].row == number_of_row_sparse2) {
                        if(compact_matrix1[temp_variable1].column ==compact_matrix2[temp_variable2].column ) {
                            temp = temp + (compact_matrix1[temp_variable1].value * compact_matrix2[temp_variable2].value);}  //Here we assign the product of the 1st matrix and the 2nd matrix, which is transpose, to the temp value.
							temp_variable2++;}
                            temp_variable1++; }


                  if(temp != 0) {
                           result_matrix[count].row=compact_matrix1[i].row;      //If the temp value is different from 0, we assign the row value of the 1st compact  
                           result_matrix[count].column=compact_matrix2[j].row;   //matrix to the row value of the result matrix, and the row value of the
                           result_matrix[count].value=temp;                      // 2nd compact matrix to the column value of the result matrix.
                           count++; 
}                                                                                //Finally, we assign the value in the temp variable to the value of the result matrix.
                           temp=0;
                        while(j<5 && number_of_row_sparse2==compact_matrix2[j].row) { 
                            j++;
}
                             if(number_of_row_sparse2==compact_matrix2[j].row) {
                              while(i<5 &&  number_of_row_sparse1==compact_matrix1[i].row) {
                             i++;
                             j=0;
}
                                if( number_of_row_sparse1==compact_matrix1[i].row){
                                   break;
}}}   
    printf("Result Matrix:\nRow  Column Value\n%d\t%d\t%d\n", number_of_row_sparse1+1,number_of_row_sparse2+1,count);
   for(i=0;i<count;i++)                                                                                        //here we print the row, column and value information of the result matrix
         {
         	printf("%d \t%d  \t%d\n",result_matrix[i].row+1,result_matrix[i].column+1,result_matrix[i].value);
		 }
                                                 //https://www.educba.com/sparse-matrix-multiplication/ 
}                                                //I used the source here as a reference to code the product of matrices


