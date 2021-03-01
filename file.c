#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int correctAnswer[10] = {2,3,4,3,4,2,2,2,2,2};
int result[10];
char ch[100];
char *name;
int ans = 0;
void answerSheet()
{
	printf("\n\n\n");
	printf("\t\t\t\t____________________________\n");
	printf("\t\t\t\t\tANSWER SHEET \n");
	printf("\t\t\t\t____________________________\n\n");
	printf("\t\t\t\t Total Correct Answer : %d\n",ans);
	printf("\t\t\t\t Total Score is : %d\n",ans*4);
	printf("\t\t\t\tCorrect Answer\t.\tYour Answer\t.\tStatus\n");
	printf("\t\t\t\t_____________________________________________________\n");
	for(int i=0;i<10;i++)
	{
		if(correctAnswer[i] == result[i])
		printf("\t\t\t\t\t%d\t|\t\t%d\t|\t%c\n",
			correctAnswer[i],result[i],'Y');
	    else 
	    	printf("\t\t\t\t\t%d\t|\t\t%d\t|\t%c\n",
	    		correctAnswer[i],result[i],'N');
	printf("\t\t\t\t_____________________________________________________\n");
	}
}
void contact()
{
	FILE *f,*f1,*f2,*f3;
	char ch1,ch2[100];
	printf("\n\n");
	int cnt = 0,cnt1 = 0;
	int c4;
	f = fopen("details.txt","r+");
	while(1)
	{
		ch1 = fgetc(f);
		if(ch1 == EOF)
		{
		    f3 = fopen("quiz.txt","r+");
			while(1)
			{
              char c3 = fgetc(f3);
              if(c3 == ',')
              {
              	printf("\nEnter your Response : ");
              	scanf("%d",&c4);
              	result[cnt1++] = c4;
              }
              
              if(c3 == ',')
              	continue;
              if(c3 == EOF)
              	break;
              printf("%c",c3);
			}
			fclose(f3);
			break;
		}
		if(ch1 == '.' && cnt == 1)
		{
			scanf("%s",ch2);
			int cmpVal = strcmp(ch2,"512"); 
			if( cmpVal == 0)
             {
             	f1 = fopen("congrates.txt","r");
             	while(1)
             	{
             		char c = fgetc(f1);
             		if(c == EOF)
             			break;

             		printf("%c",c);
             	}
             	fclose(f1);
             }
             else 
             {
               f2 = fopen("regrete.txt","r");
               while(1)
               {
               	char c1 = fgetc(f2);
               	if(c1 == EOF)
               		exit(1);

               	printf("%c",c1);
               }
               fclose(f2);
             } 
		}
		if(ch1 == '.' && cnt != 1)
		{
            scanf("%s",ch2);
            if(cnt == 0)
             name = ch2;
		}
		if(ch1 == '.')
		{
			cnt++;
			continue;
		}
		printf("%c",ch1);
	}
	for(int i=0;i<10;i++)
	{
        if(result[i] == correctAnswer[i])
        	ans++;
	}
	printf("\n\n");
	printf("\t\t\t\t____________________________\t\t\t\t\n");
	printf("\t\t\t\t\t YOUR RESULT \t\t\t\t\n");
	printf("\t\t\t\t____________________________\t\t\t\t\n");
	if(ans >= 5)
	printf("\n\t\t\t\t!! CONGRATES !!\t\t\n");
    else
    	printf("\n\t\t\t\t!! REGRATES !!\t\t\n");

	printf("\t\t\t\tTotal Correct Answer is = %d\n",ans);
	printf("\t\t\t\tTotal Score is = %d\n",ans*4);
	if(ans >= 8 )
		printf("\t\t\t\tGrade %c\n",'A');
	else if(ans >= 6 && ans <8)
		printf("\t\t\t\tGrade %c\n",'B');
	else if(ans >= 4 && ans <6)
		printf("\t\t\t\tGrade %c\n",'C');
	else 
		printf("\t\t\t\tFail\n");
	printf("\t\t\t\t____________________________\n");
	fclose(f);
}
int main()
{
	FILE *fp,*f;
	char ch;
	printf("\n\n\n\n");
	fp = fopen("notice.txt","r");
	while(1)
	{
		ch = fgetc(fp);
		if(ch == EOF)
			break;
		printf("%c",ch);
	}
	fclose(fp);
	char choice;
	printf("\n");
	printf("\nEnter your Choice : ");
	while(true)
	{
	scanf("%c",&choice);
	switch(choice)
	{
		case 'I':contact();
		         break;
		case 'Y':answerSheet();
				break;
		case 'E':exit(1);
		default:printf("Enter the choice :");
	}
    }
    
	return 0;
}