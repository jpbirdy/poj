#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>

using namespace std;

const double PRECISION = 1E-6;
const int COUNT_OF_NUMBER = 4;
const int NUMBER_TO_BE_CAL = 24;
double number[COUNT_OF_NUMBER];
string expression[COUNT_OF_NUMBER];
bool Judgement = false;                    //�ж��Ƿ��н⡣
int count = 0;

map<string,bool> map_result;


void Search(int   n)
{
    if (n   ==   1)
    {
        if ( fabs(number[0] - NUMBER_TO_BE_CAL) <= PRECISION   ) //���ڳ�����ҪС��С���ľ�ȷλ��
        {
            map<string,bool>::iterator l_it;
            l_it=map_result.find(expression[0]);
            if(l_it==map_result.end())
            {
                 cout << ++count << ": " << expression[0] << "\n";
                 map_result.insert(pair<string,bool>(expression[0],true));
            }

            Judgement = true;
        }
        else
        {
        }

    }

    for(int i=0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double   a,   b;
            string   expa,   expb;

            a   =   number[i];
            b   =   number[j];
            number[j] = number[n - 1];   //�ݹ�֮��n����ǰСһλ�����Կ��Բ�ͣ��ǰ��ֵ

            expa   =   expression[i];
            expb   =   expression[j];
            expression[j] = expression[n - 1];   //�ݹ�֮��n����ǰСһλ�����Կ��Բ�ͣ��ǰ��ֵ

            expression[i]   =   '('   +   expa   +   '+'   +   expb   +   ')';   //�ӷ�����Ҫ��˳��
            number[i]   =   a   +   b;
            Search(n-1);

            expression[i]   =   '('   +   expa   +   '-'   +   expb   +   ')';   //����Ӧ�÷�˳�򣬼����Լ�������
            number[i]   =   a   -   b;
            Search(n-1);

            expression[i]   =   '('   +   expb   +   '-'   +   expa   +   ')';   //����Ӧ�÷�˳�򣬼����Լ�������
            number[i]   =   b   -   a;
            Search(n-1);


            expression[i]   =   '('   +   expa   +   '*'   +   expb   +   ')';   //�˷�����Ҫ��˳��
            number[i]   =   a   *   b;
            Search(n-1);

            if (b != 0)
            {
                expression[i]   =   '('   +   expa   +   '/'   +   expb   +   ')';   //����Ӧ�÷�˳�򣬳����Լ�������
                number[i] = a / b;
                Search(n-1);
            }
            if (a != 0)
            {
                expression[i]   =   '('   +   expb   +   '/'   +   expa   +   ')';   //����Ӧ�÷�˳�򣬳����Լ�������
                number[i]   =   b / a;
                Search(n-1);
            }

            number[i]   =   a;                  //��4�������Ϊ�˷�ֹ������漸�ֿ��ܶ�ʧ���˵Ļ�,
            number[j]   =   b;                  //�Ͱ�ԭ���ĸ�ֵ������ȥ,���޸��ŵ���ȷ�Ľ��뵽��һ��
            expression[i]   =   expa;           //forѭ�������С�
            expression[j]   =   expb;           //
        }
    }
}


int main()
{
    for (int i = 0; i < COUNT_OF_NUMBER; i++)
    {
        char buffer[20];
        cin>>number[i];
        itoa(number[i],buffer,10);   //itoa()�����������ǰѵ�һ������(��ֵ)���͵��ڶ�������(�ַ���)��ȥ��������
       //����(int��)�Ǹ���ֵ���ַ�������ʲô���ƴ�š�
        expression[i]   =   buffer;
    }
    Search(COUNT_OF_NUMBER) ;

    if(Judgement==true)
    {
        cout<<   "\nSuccess."<<endl;
        cout<<"The sum of the ways = "<<count<<endl;
    }
    else
    {
        cout   <<   "Fail."   <<   endl;
    }

    return 0;
}
