#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
void findfirst(char, int, int);
int count, n = 0;
char calc_first[10][100];
int k;
char production[10][10];
char first[10];
int m = 0;

int main(int argc, char **argv)
{
    int jm = 0;
    int i;
    char c;

    count = 8;

    strcpy(production[0], "E=TX");
    strcpy(production[1], "X=+TX");
    strcpy(production[2], "X=#");
    strcpy(production[3], "T=FY");
    strcpy(production[4], "Y=*FY");
    strcpy(production[5], "Y=#");
    strcpy(production[6], "F=(E)");
    strcpy(production[7], "F=i");
    strcpy(production[8], "F=a");
    strcpy(production[9], "F=b");

    int kay;
    char done[count];
    int ptr = -1;
    for (k = 0; k < count; k++)
    {
        for (kay = 0; kay < 100; kay++)
        {
            calc_first[k][kay] = '!';
        }
    }
    int point1 = 0, point2, x;

    for (k = 0; k < count; k++)
    {
        c = production[k][0];
        point2 = 0;
        x = 0;
        for (kay = 0; kay <= ptr; kay++)
            if (c == done[kay])
                x = 1;

        if (x == 1)
            continue;
        findfirst(c, 0, 0);
        ptr += 1;
        done[ptr] = c;
        cout << "\n First(" << c << ") = { ";
        calc_first[point1][point2++] = c;
        for (i = 0 + jm; i < n; i++)
        {
            int lark = 0, chk = 0;

            for (lark = 0; lark < point2; lark++)
            {

                if (first[i] == calc_first[point1][lark])
                {
                    chk = 1;
                    break;
                }
            }
            if (chk == 0)
            {
                cout << first[i] << ", ";
                calc_first[point1][point2++] = first[i];
            }
        }
        cout << "}\n";
        jm = n;
        point1++;
    }
    cout << "\n";
}

void findfirst(char c, int q1, int q2)
{
    int j;
    if (!(isupper(c)))
    {
        first[n++] = c;
    }
    for (j = 0; j < count; j++)
    {
        if (production[j][0] == c)
        {
            if (production[j][2] == '#')
            {
                if (production[q1][q2] == '\0')
                    first[n++] = '#';
                else if (production[q1][q2] != '\0' && (q1 != 0 || q2 != 0))
                {
                    findfirst(production[q1][q2], q1, (q2 + 1));
                }
                else
                    first[n++] = '#';
            }
            else if (!isupper(production[j][2]))
            {
                first[n++] = production[j][2];
            }
            else
            {
                findfirst(production[j][2], j, 3);
            }
        }
    }
}
