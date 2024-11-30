#include<stdio.h>
void CoinChange(int amount,int coins[],int size)
{
    for(int a=0;a<=size;a++)
    {
        int sum=0;
        int count=amount/coins[a];
        amount=amount-(count*coins[a]);
        sum=sum+(count*coins[a]);
        if(amount!=sum)
        {
            printf("%d X %d\n",coins[a],count);
        }
    }
}
int main()
{
    int amo;
    int coins[]={1,2,5,10};
    printf("Enter Amount:");
    scanf("%d",&amo);
    sortDescending(coins,SOA(coins));
    CoinChange(amo,coins,SOA(coins));
}

int SOA(int ar[]) //SOA = Size Of an Array
{
    int size=0,counter=0;
    while(1)
    {
        if(ar[counter]!='\0')
            size++;
        else
            break;
        counter++;
    }
    return size;
}

void sortDescending(int arr[], int size) 
{
    for (int a = 0; a < size; a++) 
    {
        for (int j = a + 1; j < size; j++) 
        {
            if (arr[a] < arr[j]) 
            {
                int temp = arr[a];
                arr[a] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
