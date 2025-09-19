#include<stdio.h>
void visual(char s[],int count)
{
    for(int a=0;a<=count;a++)
    {
        if(s[a]=='\0')
        {
             printf("String[%d]=Null",a);
        }
        else
        printf("String[%d]=%c\n",a,s[a]);
        
    }
}    
int main()
{
    char name[20];
    printf("Enter Name:");
    
    int a=0;
    while(1)
    {
        scanf("%c",&name[a]);
        if(name[a]=='\n')
        {
            name[a]='\0';
            break;
        }
        a++;
    }
    
    for(int b=0;name[b]!='\0';b++)
    {
        printf("%c",name[b]);
    }
    printf("\n");
    
    visual(name,a);
    
    //printf("%s",name);
}
