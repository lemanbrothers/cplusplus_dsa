#include <iostream>
using namespace std;

void InputArray(int *, int);
void OutputArray(int *, int);
int SentinelLinearSearch(int *, int, int);

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
        int result = SentinelLinearSearch(arr, n, x);
        cout << "Result of sentinel linear search: " << result << "\n\n";
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
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int SentinelLinearSearch(int *a, int n, int x)
{
    a[n] = x;
    int i = 0;
    while (a[i] != x)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    return -1;
}
