#include <stdio.h>
#include <string.h>

void main()
{
    char s[1000];
    int count=0;
     while (gets(s))
        count += strlen(s);
    printf("%d\n",count);
}
