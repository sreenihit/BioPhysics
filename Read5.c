#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//Reading matrices

int main()
{
	FILE *f1 = fopen("1KTB.pdb","r");
	FILE *f2 = fopen("Mat.txt","w");
	FILE *f3 = fopen("Transl.txt","w");
	FILE *f4;

	float mat[3][3];
	float trans[3];	
	float ftmp;	
	float atom[3];	
	float result[3];

	int ia,ja,ka;
	char tmp1;
	int c=0;
	float sum;
	char ch[200];
	char tmp[200];
	int i,j,k,l,l1;
	float n;
	int la;
	i=0;

	while( fscanf(f1,"%s",ch) != EOF)
	{

		if( ch[0] == 'B' && ch[1] == 'I' && ch[2] == 'O' && ch[3] == 'M' && ch[4] == 'T' && strlen(ch)==6)
		{
			fscanf(f1,"%f",&n);
			
			for(j=0;j<3;j++)
			{
				fscanf(f1,"%f",&mat[i][j]);
				//printf("%f ",mat[i][j]);
				fprintf(f2,"%f ",mat[i][j]);
			}

			fscanf(f1,"%f",&trans[i]);
			fprintf(f3,"%f ",trans[i]);

			if(i==2)
			{
				i=0;
				//printf("\n");
				fprintf(f2,"\n");
				fprintf(f3,"\n");
			}
			else
			i++;

	
		}
		

	}


	fclose(f1);
	fclose(f2);
	fclose(f3);
/////////////////////////////////////////////////Reading ATOMS

	f1 = fopen("1KTB.pdb","r");
	f2 = fopen("Atom.txt","w");


	while( fscanf(f1,"%s",ch) != EOF)
	{

		if( ch[0] == 'A' && ch[1] == 'T' && ch[2] == 'O' && ch[3] == 'M' &&  strlen(ch)==4)
		{
			for(i=1;i<=5;i++)
			fscanf(f1,"%s",tmp);

			for(i=1;i<=3;i++)
			{
				fscanf(f1,"%f",&ftmp);
				fprintf(f2,"%f ",ftmp);

			}

			fprintf(f2,"\n");
		}
	}

	fclose(f1);
	fclose(f2);

///////////////////////////////////////////////

	f1 = fopen("Mat.txt","r");
	f2 = fopen("Atom.txt","r");
	l=0;
	la =0;

	while( ( tmp1 = fgetc(f2) )!= EOF )
	{
		if(tmp1=='\n')
		la++;
	}



	while( ( tmp1 = fgetc(f1) )!= EOF )
	{
		if(tmp1=='\n')
		l++;
	}

	//printf("No of lines: %d\n",l);
	//printf("And no of lies: %d\n",la);

	fclose(f2);
	fclose(f1);

////////////////////////////////////////////Reading line by line - operations.

	f1 = fopen("Mat.txt","r");
	f3 = fopen("Result.txt","w");
	f4 = fopen("Transl.txt","r");

	for(i=1;i<=l;i++)
	{

		printf("Matrix: \n");
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				fscanf(f1,"%f",&mat[i][j]);
				printf("%f ",mat[i][k]);
			}
			printf("\n");
		}
		printf("\n\n");



		f2 = fopen("Atom.txt","r");

		for(j=0;j<3;j++)
		fscanf(f4,"%f",&trans[j]);



		for(j=1;j<=6;j++)
		{

			printf("ATOM is:\n");
			for(k=0;k<3;k++)
			{
				fscanf(f2,"%f",&atom[k]);
				printf("%f ",atom[k]);
			}

			printf("\n");

			
			printf("New Coordinates:\n");

			for(ia =0;ia<3;ia++)
			{
				sum=0;
				for(ja=0;ja<3;ja++)
				{
						sum = sum + mat[ia][ja]*atom[ja];

				}
				
				fprintf(f3,"%f ",sum );//+ trans[ia]);
				printf("%f ",sum);
			}

			fprintf(f3,"\n");
			printf("\n");	
			
			
		}
		
		fprintf(f3,"\n\n\n\n");

		fclose(f2);   
	}

	


}
