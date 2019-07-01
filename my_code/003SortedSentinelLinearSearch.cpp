#include <iostream>
#include <algorithm>
using namespace std;

void InputArray(int *, int);
void OutputArray(int *, int);
int SortedSentinelLinearSearch(int *, int, int);

int main()
{
    int n = 10;
    int *arr = new int[n];

    while (true)
    {
        InputArray(arr, n);
        OutputArray(arr, n);
        cout << "\nInput a value:";
        int x;
        cin >> x;
        if (x == 0)
        {
            break;
        }
        int result = SortedSentinelLinearSearch(arr, n, x);
        cout << "Result of sorted sentinel linear search: " << result << "\n\n";
    }

    cout << endl;
    //system("pause");
    return 0;
}

void InputArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

void OutputArray(int *arr, int n)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int SortedSentinelLinearSearch(int *a, int n, int x)
{
    int i = 0;
    a[n] = x + 1;
    while (a[i] < x)
    {
        i++;
    }
    if (a[i] == x)
    {
        return i;
    }

    return -1;
}
