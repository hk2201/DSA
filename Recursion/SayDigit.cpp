#include <iostream>
using namespace std;
// If 413 then ans should be four one three.

void sayDigit(int n, string arr[])
{
    if (n == 0)
    {
        return;
    }

    int digit = n % 10;
    n = n / 10;

    sayDigit(n, arr);
    cout << arr[digit] << " "; // If we add this above sayDigit then it will not print in same order.
}

int main()
{
    cout << "Enter No" << endl;
    int n;
    cin >> n;

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    sayDigit(n, arr);

    return 0;
}