#include <stdio.h>
#include "def.h"
#include "two.h"


int main()
{
    initbase();
    printf("%d\n",g_base.id);
    modify();
    printf("%d\n",g_base.id);
    return 0;
}
