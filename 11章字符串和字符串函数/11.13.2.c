#include <stdio.h>

char *s_gets(char *st,int leng);

int main(void)
{

    int leng = 10;
    char arr[leng];
    printf("enter your leng:");
    while(scanf("%d",&leng) != 1);
    printf("your leng is %d\n",leng);

    printf("enter your string(no longer than leng):\n");
    while(s_gets(arr,leng))
        printf("%s",arr);



}

char *s_gets(char *st,int leng)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(st,leng,stdin);
    if(ret_val)
    {
        while(st[i] != '\n' && st[i] != '\0' )
            i++;
        if(st[i] == '\n')
            st[i] = '\0';

       else
            while(getchar != '\n')
                continue;

    }
    return ret_val;
}
