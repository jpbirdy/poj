/**
大意分析，摩斯电码，规定了从A~Z的26个电码，同时还有4个标点符号为特殊电码，
电码表如morse_code数组表示
每个电码有一个长度，将所有电码放到一起，如果没有长度，解码的结果会有很多
我们将一个文本翻译为莫斯电码，将其对应的长度序列 倒序，再解码后得到一个加密的编码
简单
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <string>
using namespace std;

char morse_code[30][6] =
{
    ".-","-...","-.-.","-..",".","..-.","--.","....",//check
    "..",".---","-.-",".-..","--","-.","---",".--.",//
    "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",
    "..--","---.",".-.-","----"
};

char special[4] = {'_','.',',','?'};

int find_morse_num(char str[])
{
    int i;
    for(i=0;i<30;i++)
    {
        if(strcmp(str,morse_code[i])==0)
            return i;
    }
    return -1;
}

void ohaver(char str[110])
{
    int code_len[110];
    char morse[600];
    char buff[6];
    char *temp,*start;
    int i,x,j;
    int len = strlen(str);
    strcpy(morse,"");
    for(i=0; i<len ; i++)
    {
        if(str[i]>='A'&& str[i]<='Z')
            temp = morse_code[str[i]-'A'];
        else
        {
            for(j=0 ; j<4 ; j++)
                if(special[j] == str[i])
                {
                    temp = morse_code[26+j];
                    break;
                }
        }
        strcat(morse, temp);
        code_len[i] = strlen(temp);
    }
    start = morse;
    for(i=len-1 ; i>=0 ;i--)
    {
        strncpy(buff,start,code_len[i]);
        buff[code_len[i]] = '\0';
        start = start+code_len[i];
        x = find_morse_num(buff);
        if(x<26) printf("%c",'A'+x);
        else printf("%c",special[x-26]);
    }
    printf("\n");

}

int main()
{
    char str[110];
    int t;
    int cases = 1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        printf("%d: ",cases++);
        ohaver(str);
    }
    return 0;
}
