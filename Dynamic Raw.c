#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, *std;
    printf("Number of Students:");
    scanf("%d", &n);
    std = (int *)calloc(n, sizeof(int));
    printf("\n_Enter %d std Marks_\n\n", n);
    
    for (int a = 0; a < n; a++) 
    {
        printf("std[%d] = ", a + 1);
        scanf("%d", &std[a]);
    }
    
    printf("\n[_");
    for (int a = 0; a < n; a++) 
    {
        printf("%d_", std[a]);
    }
    printf("]");

    char choice[5];
    printf("\nYou Want Store More Marks?\n-");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0 || strcmp(choice, "YES") == 0) 
    {
        int n1;
        printf("Extended Number:");
        scanf("%d", &n1);
        std = (int *)realloc(std, n1 * sizeof(int));

        for (int a = n; a < n1+n; a++) 
        {
            printf("std[%d] = ", a + 1);
            scanf("%d", &std[a]);
        }
        
        printf("\nUpdated List:\n[_");
        for (int a = 0; a < n+n1; a++) 
        {
            printf("%d_", std[a]);
        }
        printf("]");
    }

    free(std);  
    return 0;
}