#include <stdio.h>
typedef struct foo
{
    long a;
    char b;
    int c;
} ff;
int main()
{
    ff* p=0;
    printf("&(p->c)= %p \n",&(p->c));
    return 0;
}
