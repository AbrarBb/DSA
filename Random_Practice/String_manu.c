#include<stdio.h>

void name_d(char s[])
{
    for(int a=0;s[a]!='\0';a++)
    {
        printf("%c",s[a]);
    }
}

char name_cat()
{
    char name[25];
    int count=0;
    printf("Enter Your Name:");
    while(1)
    {
        scanf("%c",&name[count]);
        if(name[count]=='\n')
        {
            name[count]='\0';
            break;
        }
        count++;
    }
    name_d(name);
}

int main()
{
    name_cat();
}
