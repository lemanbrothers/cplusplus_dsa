#include <iostream>
using namespace std;

void InputArray(int *, int);
void OutputArray(int *, int);
int LinearSearch(int *, int, int);

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
        int result = LinearSearch(arr, n, x);
        cout << "Result of linear search: " << result << "\n\n";
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

int LinearSearch(int *a, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
    }
    return -1;
}
