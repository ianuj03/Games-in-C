/*
* This Program is used to make a Puzzle Game in C
* Author: Anuj Jain
* @ianuj03
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
char a[4][4],best[255];
int invalid=0,count=0;
void print();
int check_sort();
int substitue(char);
void play();
void help();
void save();
void score();

main()
{
	int choice,i,x,choice_entry;
	char position,repeat;
	FILE *best_file=fopen("best.txt","r+");
	if(fscanf (best_file, "%s", &best)!=EOF)
		fscanf (best_file, "%s", &best);
	else
		best[0]='0';
	fclose(best_file);
	do{
	START:	
		a[0][0]=65;
		a[0][1]=68;
		a[0][2]=79;
		a[0][3]=71;
		a[1][0]=72;
		a[1][1]=74;
		a[1][2]=66;
		a[1][3]=75;
		a[2][0]=78;
		a[2][1]=67;
		a[2][2]=70;
		a[2][3]=77;
		a[3][0]=76;
		a[3][1]=73;
		a[3][2]=69;
		a[3][3]=32;
	START_PRINT:
		system("cls");
		printf("\tPuzzle  in C.");
		printf("\n\nA project by Anuj Jain\n\t@ianuj03\n");
		for(i=0;i<33;i++)
			printf("..");
		printf("\n");
		for(i=0;i<33;i++)
			printf("..");
		CHOICE:
			printf("\n");
			for(i=0;i<33;i++)
			printf("..");
			printf("\n");
			for(i=0;i<33;i++)
			printf("..");
			printf("\n\nPress '1' for New Game.\nPress '2' for High Score.\nPress '3' for Game Help.\nPress '4' Exit.\n\n\tEnter your choice: ");
			scanf("%d",&choice);
			for(i=0;i<33;i++)
			printf("..");
			printf("\n");
			for(i=0;i<33;i++)
			printf("..");
		switch(choice)
		{
			case 1:
				play();
				printf("\n\nYou have completed in %d move.\nFrom which  %d was invalid move.\n\tYour total correct move was %d.\n\n",count,invalid,count-invalid);
				save();
				break;				
			case 2:
				score();
				system("pause");
				break;				
			case 3:
				help();
				printf("\n");
				system("pause");
				break;				
			case 4:
				printf("\n\nDo you want to exit (Y/N): ");
				fflush(stdin);
				repeat=getchar();
				if(repeat=='Y'||repeat=='y')
					goto END;
				break;
			default:
				printf("\nEnter the correct choice: ");
				goto END;
		}
		goto START;
		END:
		printf("\n\n\tDo you really want to exit (Y/N): ");
		fflush(stdin);
		repeat=getchar();
	}while(repeat=='N'||repeat=='n');
	getch();
	return(0);
}
void play()
{
	char position;
	int check,check1;
	printf("\n\n\tArrange the boxes in Alphabetical order.\n\n");
	print();
		SUB:
		fflush(stdin);
		position=getch();
		//printf("\n");
		//system("pause");
		if((position!='W')&&(position!='A')&&(position!='S')&&(position!='D')&&(position!='w')&&(position!='a')&&(position!='s')&&(position!='d'))
		{
			printf("\n\tEnter the valid key: ");
			invalid++;
			goto SUB;
		}
		
		check1=substitue(position);
		if(check1==0)
		{
			printf("\n\tEnter a valid position.");
			invalid++;
			goto SUB;
		}
		print();
		count++;
		check=check_sort();
		if(check==1)
		goto SUB;				
}
void score(){
	FILE *best_file=fopen("best1.txt","r+");
	if(fscanf (best_file, "%s", &best)!=EOF)
		fscanf (best_file, "%s", &best);
	else
		best[0]='0';
	fclose(best_file);
	printf("\n\nYour higest socre is %s.\n",best);
}
void help()
{
	printf("\n\n\t\t\tHELP:\n\nUse left controller keys to change the position of blank box.\nW = Upper key;\nA = Left key;\nS = Down Key;\nD = Right Key.\n\n");
}
void print()
{
	int i,j;
	printf("\n\n\tBest: %s\t\t\t\tMove:%d\n",best,count-invalid);
	printf("\n\n\t\t");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%c\t",a[i][j]);
		printf("\n\t\t");
	}
	printf("\n");
}
int check_sort()
{
	int i,act[4][4],j; char count=65;
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	{
		act[i][j]=count;
		count++;
	}
	act[3][3]=32;
		
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if((a[i][j]!=act[i][j]))//&&(a[3][2]==32||a[3][2]==0))
			return 1;
		}
	}
	return 0;
}
int substitue(char position)
{
	int i,j;char temp=32;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[i][j]==32)
			{
				goto NEXT;
			}
		}
	}
	NEXT:
	Validate:
		if((i==0)&&((position=='W')||(position=='w')))
		return 0;
		if((i==3)&&((position=='S')||(position=='s')))
		return 0;
		if((j==0)&&((position=='A')||(position=='a')))
		return 0;
		if((j==3)&&((position=='D')||(position=='d')))
		return 0;
	
switch(position)
	{
		case 'A':
			a[i][j]=temp;
			a[i][j]=a[i][j-1];
			a[i][j-1]=temp;
			break;
		case 'a':
			a[i][j]=temp;
			a[i][j]=a[i][j-1];
			a[i][j-1]=temp;
			break;
		case 'D':
			a[i][j]=temp;
			a[i][j]=a[i][j+1];
			a[i][j+1]=temp;
			break;
		case 'd':
			a[i][j]=temp;
			a[i][j]=a[i][j+1];
			a[i][j+1]=temp;
			break;
		case 'W':
			a[i][j]=temp;
			a[i][j]=a[i-1][j];
			a[i-1][j]=temp;
			break;
		case 'w':
			a[i][j]=temp;
			a[i][j]=a[i-1][j];
			a[i-1][j]=temp;
			break;
		case 'S':
			a[i][j]=temp;
			a[i][j]=a[i+1][j];
			a[i+1][j]=temp;
			break;
		case 's':
			a[i][j]=temp;
			a[i][j]=a[i+1][j];
			a[i+1][j]=temp;
			break;
	}
	return 1;
}
void save()
{
	int x;
	int scr[255];
	FILE* check_file=fopen("best1.txt","w+");
	x=count-invalid;
	fscanf(check_file, "%s", &scr);
	if(scr>x)
		fprintf(check_file,"%d",x);
	fclose(check_file);
	system("pause");
}
