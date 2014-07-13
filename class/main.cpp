#include <cstdio>
using namespace std;

int x = 0;
class f
{
public:
    int a;
    f()
    {
        a = x++;
        //printf("xxx%d\n",a);
    }
    ~f()
    {
        //printf("ggg%d\n",a);
    }
};


int main()
{
    f *a = new f[1230];

    printf("address%d\n",a);
    char *p = (char *) (a-1);
    printf("address%d\n",p);
    printf("%d\n",(unsigned char)(*(p+3))*256*256*256+(unsigned char)(*(p+2))*256*256 + (unsigned char)(*(p+1))*256+((unsigned char)*p));


    delete [] (a);
    return 0;
}

