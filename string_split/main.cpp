#include <stdio.h>
#include <string.h>

void split(char **arr, char *str, char *del)
{
    char *s = strtok(str, del);

    while(s != NULL)
    {
        *arr++ = s;
        s = strtok(NULL, del);
    }
}

int main()
{
    char str[20] = "10,20,30";
    char *arr[3];
    char *del = ",";
    int i = 0;
    split(arr, str, del);

    while(i<3)
        printf("%s\n", *(arr+i++));
}
