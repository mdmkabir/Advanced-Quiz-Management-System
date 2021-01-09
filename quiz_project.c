#include<stdio.h>
#include<string.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    FILE* fq;
    FILE* fm;
    int nop;
    int k;
    printf("Enter the no of participants :\n 2 0r 3 0r 4\n");
    scanf("%d",&nop);

    fm = fopen("marks.txt","w");

    for(k = 1; k <= nop ; k++)
    {
    char filename[25] = "file";
    char temp2[2];
    char player[30] = "Player ";
    temp2[0] = k+'0';
    temp2[1] ='\0';
    strcat(filename,temp2);
    strcat(filename,".txt");
    strcat(player,temp2);
    //printf("%s",filename);
    printf("%s starts \n\n\n",player);
    fq = fopen(filename, "r");
    char str[1000];



    int i,j;
    int counter = 0;
    int total = 0;
    fgets(str, 1000, fq);
    int quesno = atoi(str);
    for(i = 1; i <= 6*quesno; i++)
    {
           fgets(str, 1000, fq);
        if(strlen(str) != 2)printf("%s\n", str);

        if(i%6 == 0)
        {
            //printf("%c\n",str[0]);
                printf("Insert your answer(A/B/C/D) : ");
                char op;
                char ans = str[0];
                fgets(str, 1000, fq);
                int mark = str[0] - '0';
                total+=mark;
                scanf(" %c",&op);
                if(op != ans)
                {
                   printf("Wrong!! Correct answer is '%c'\n",ans);
                }
                else
                {
                    printf("Correct answer!\n");
                    counter+= mark;
                }
                printf("---------------------------------------------------\n");
        }





    }

    printf("You get %d marks out of %d\n\n\n\n\n",counter,total);
    fprintf(fm,"%s\n",player);
    fprintf(fm, "%d%s%d\n", counter,"/",total);
    fclose(fq);

    }

    printf("----------------------------------------------------\n");
    printf("Quiz result is : \n");
     fclose(fm);
     fm = fopen("marks.txt","r");

    for(k = 1;k<=nop;k++)
    {
        char str1[1000];
        fgets(str1, 1000, fm);
        printf("%s", str1);
        fgets(str1, 1000, fm);
        printf("%s", str1);
    }


    fclose(fm);




}
