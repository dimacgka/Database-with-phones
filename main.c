#include "stdio.h"
#include <string.h>
#include <malloc.h>

#define FNAME "phones.txt\0"
int main()
{
    char fname[20] = FNAME;
    FILE *f;
    
    char fam[15];
    char name[15];
    char tel[9];
    
    int sum = 0;
    int *num;
    int count = 0;
    
    puts("\n Adding the new number to the phones book \n");
    if ((f = fopen(fname, "at")) == NULL)
    {
        printf("Error in file open operation! \n");
    }
    printf("Second name ->");
    scanf("%s", fam);
    printf("First name ->");
    scanf("%s", name);
    printf("Phone number ->");
    scanf("%s", tel);
    fprintf(f, "%s %s %s \n", fam, name, tel);
    puts("\n Data were added.");
    fclose(f);
    
    if ((f = fopen(fname, "rt")) == NULL)
    {
        printf("Error in file open operation! %s \n", fname);
    }

    printf("\nContent of file is following: \n");
    while(!feof(f))
    {
        fscanf(f, "%s %s %s \n", fam, name, tel);
        
        count++;
    }
    
    count = count;
    num = (int*)malloc(count*sizeof(int));
    int i = 0;
    
    printf("\nContent of file is following: \n");
    while(!feof(f))
    {
        fscanf(f, "%s %s %s \n", fam, name, tel);
        
        num[i] = (int) strol(tel, (char**)NULL, 10);
        
        printf("%s %s %s \n", fam, name, tel);
        i++;
    }
    
    for (i = 0; i <= sizeof(num); i++)
    {
        sum += num[i];
    }
    
    printf("%d", sum);
    
    fclose(f);
    
    printf("\n Press enter for finish <Enter>\n");

  return 0;
    
}