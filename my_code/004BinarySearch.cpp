#include <iostream>
#include <algorithm>
using namespace std;

void InputArray(int *, int);
void OutputArray(int *, int);
int BinarySearch(int *, int, int, int);

int main()
{
    int n = 10;
    int *arr = new int[n];
    while (true)
    {
        InputArray(arr, n);
        OutputArray(arr, n);
        cout << "\nInput a target value:";
        int x;
        cin >> x;
        if (x == 0)
        {
            break;
        }
        int result = BinarySearch(arr, 0, n, x);
        cout << "Result of binary search: " << result << "\n\n";
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
    sort(arr, arr + n);
}

void OutputArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int BinarySearch(int *arr, int low, int high, int x)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[mid] < x)
        {
            return BinarySearch(arr, mid + 1, high, x);
        }

        if (arr[mid] > x)
        {
            return BinarySearch(arr, low, mid - 1, x);
        }
    }
    return -1;
}
