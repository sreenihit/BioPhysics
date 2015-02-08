#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main()
{
	int i,j,k,s;
	float sum;
	float mat[3][3];
	float trans[3],result[3];
	float atom[3];
	int l1 = 0,l2 = 0;
	char tmp;

	FILE *f1,*f2,*f3,*f4;

	f1 = fopen("Atom.txt","r");
	while( ( tmp = fgetc(f1) )!= EOF )
	{
		if(tmp=='\n')
		l1++;
	}

	fclose(f1);


	f2 = fopen("Mat.txt","r");
	while( ( tmp = fgetc(f2) )!= EOF )
	{
		if(tmp =='\n')
		l2++;
	}
		
	fclose(f2);

/////////////////////////////////////////////

	//f1 = fopen("Atom.txt","r");	
	f2 = fopen("Mat.txt","r");
	f3 = fopen("Transl.txt","r");
	f4 = fopen("Result.txt","w");

		
	for(i=1;i<=l2;i++)
	{

		// Read in transformaton Matrix - 
		printf("Matrix No: %d:\n",i);

		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				fscanf(f2,"%f",&mat[j][k]);
				printf("%f ",mat[j][k]);
			}
			printf("\n");
		}
		printf("\n");

				
		// Read in translation values
		printf("Translation matrix:\n");		

		for(k=0;k<3;k++)
		{
			fscanf(f3,"%f",&trans[k]);
			printf("%f ",trans[k]);
		}
		printf("\n\n");


		// Open Atom.txt 

		f1 = fopen("Atom.txt","r");	

		// Read Atom line by line - Multiply three coordinates by mat

		for(j=1;j<=l1;j++)
		{

			//Read ATOM coordinates line by line
			printf("Old Coordinates:\n");
			for(k=0;k<3;k++)
			{
				fscanf(f1,"%f",&atom[k]);
				printf("%f ",atom[k]);
			}
			printf("\n");

			//Multiply transformation matrix by atom
			

			printf("Transformed Matrix:\n");
			for(k=0;k<3;k++)
			{
				sum = 0;
				for(s=0;s<3;s++)
				{
					sum = sum + mat[k][s]*atom[s];
				}
				result[k] = sum + trans[k];
				fprintf(f4,"%f ",result[k]);
				printf("%f ",result[k]);
			}
			fprintf(f4,"\n");
			printf("\n");
		}

		// End this matrix - Move to Next transformation matrix
		fclose(f1);

		fprintf(f4,"\n\n\n");
		printf("\n\n\n Next Matrix: \n");
	}
		
				
}
			
		
		


