#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void win()
{
	printf(" \n  \\\O/    \n");
printf("   | \n");
printf("  / \\\ \n");
}

void hangman()
{
printf("\n=========\n");

printf("   O   \n");
printf("  /|\\\  \n");
printf("  / \\ \  \n");
printf("========= ");
}
int ran()
{
	int upper=9;
	int lower = 1;
	int num;
	srand(time(0));
	num=(rand()%(upper-lower+1))+lower;
	return num;
}
int main()
{
	FILE *file2=fopen("hint.txt","r");
char Word[10][15]={
	"\0",
	"Meeting",
"Kitchen",
"Chicken",
"Chess",
"Market",
"School",
"Collage",
"University",
"Office"
	
	};
char Hint[10][20];
char leter[15] ;
char w[15];
	int a,i,j;
	
	
	a=ran();
	if(file2 !=NULL)
	{
		for(i=0;i<10;i++)
		{
			fgets(Hint[i],20,file2);
			}
	}

	else
	{
		printf("\nprogram error");

	}
	
	

  i=strlen(Word[a]);
  printf("lets play a guess game.\n");
  printf("\t\t hint\n");
  puts(Hint[a]);
printf("the leter of word is =%d.",i);
	printf("\nenter:");
	scanf("%s",&w);
	  
int	value = strcmp(w,Word[a]);
	if (value==0)
	{
		win();
		printf("Congratulations...You won the game.");
		return 0;
}
else
{
hangman();
	printf("You loose");


	}
			
			
	fclose(file2);
	return 0;
	
}
