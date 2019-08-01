#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void NhapMang(int *arr, int &);
void XuatMang(int *arr, int);
void NhapN(int &);
void NhapX(int &);
int TimKiemTuanTu(int *arr, int, int);
int TimKiemNoiSuy(int *arr, int, int);

int main()
{
    int n, x;
    NhapN(n);
    int *arr = new int [n];
    NhapMang(arr, n);

    NhapX(x);
    clock_t tStart = clock();
    cout << "\nKet qua tim kiem tuan tu: " << TimKiemTuanTu(arr, n, x);
    double TimeTuanTu = (double)(clock() - tStart) / CLOCKS_PER_SEC;
    cout << "\nThoi gian tim kiem tuan tu: " << TimeTuanTu;

    NhapX(x);
    //clock_t tStart = clock();
    cout << "\nKet qua tim kiem noi suy: " << TimKiemNoiSuy(arr, n, x);
    double TimeNoiSuy = (double)(clock() - tStart) / CLOCKS_PER_SEC;
    cout << "\nThoi gian tim kiem noi suy: " << (TimeNoiSuy - TimeTuanTu);

    cout << "\nEnter any key to finish program!!!\n";
    return 0;
}

void NhapMang(int *arr, int &n)
{
    srand(time(NULL));
    arr[0] = rand() % 100000000;
    for (int i = 1; i < n; i++)
    {
        arr[i] = arr[i - 1] + rand() % 100;
    }
}

void XuatMang(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int TimKiemTuanTu(int *arr, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int TimKiemNoiSuy(int *arr, int n, int x)
{
    int low = 0, high = (n - 1);
    while (low <= high && x >= arr[low] && x <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == x)
            {
                return low;
            }
            return -1;
        }
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

        if (arr[pos] == x)
        {
            return pos;
        }

        if (arr[pos] < x)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }
    return -1;
}

void NhapN(int &n)
{
    do
    {
        cout << "\n Nhap so luong phan tu cua mang: ";
        cin >> n;
    } while (n <= 0);
}

void NhapX(int &x)
{
    cout << "\nNhap vao phan tu can tim kiem: ";
    cin >> x;
}