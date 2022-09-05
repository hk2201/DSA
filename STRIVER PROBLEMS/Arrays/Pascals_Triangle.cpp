#include <bits/stdc++.h>
vector<vector<long long int>> printPascal(int n)
{
    for (int i = 1; i < n; i++)
    {
        printPascal[i].resize(i + 1);
        printPascal[i][0] = printPascal[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            printPascal[i + 1][j + 1] = printPascal[i][j] + printPascal[i][j + 1];
        }
    }
    return printPascal;
}
