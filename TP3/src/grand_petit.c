#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>




int main()
{
    int tab_int[100];
    int *ptr_int = tab_int;
  
    int min;
    int max;
    srand(time(NULL));
    
    for (int i = 0; i < 100; i++)
    {
        *(ptr_int + i) = rand()%500;
       
    }
    
    max = *(ptr_int);
    min = *(ptr_int);
    
    for (int i = 0; i < 100; i++)
    {
        if (*(ptr_int + i) > max)
        {
            max = *(ptr_int + i);
        }
        if (*(ptr_int + i) < min)
        {
            min = *(ptr_int + i);
        }
        
    }

    for (int i = 0; i < 100; i++)
    {
        printf("%d\t",*(ptr_int + i));
    }
    printf("\n");
    printf("max: %d\tmin: %d", max, min);
    
    
    
    
    printf("\n");
    return 0;
    
}