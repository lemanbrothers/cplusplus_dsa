#include <iostream>
#include <algorithm>
using namespace std;

void InputArray(int *, int);
void OutputArray(int *, int);
int InterpolationSearch(int *arr, int, int);

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
        int result = InterpolationSearch(arr, n, x);
        cout << "Result of Interpolation Search: " << result << "\n\n";
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

int InterpolationSearch(int *arr, int n, int x)
{
    int mid, low = 0, high = n - 1;
    while ((arr[high] != arr[low]) && x >= arr[low] && x <= arr[high])
    {
        mid = low + (x - arr[low]) * (high - low) / (arr[high] - arr[low]);
        if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    if (x == arr[low])
    {
        return low;
    }
    return -1;
}