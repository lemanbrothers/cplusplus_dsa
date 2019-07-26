#include <iostream>
using namespace std;
#define MAX 100

void NhapMang(int a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
}

void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void HoanVi(int &X, int &Y)
{
    int temp = X;
    X = Y;
    Y = temp;
}

void SelectionSort(int a[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;
        HoanVi(a[min_idx], a[i]);
    }
}

void InterchangeSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

void InsertionSort(int a[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}


int menu()
{
    int choice;
    cout << "\n ================================";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n 0. Thoat chuong trinh";
    cout << "\n 1. Xuat mang:";
    cout << "\n 2. SelectionSort:";
    cout << "\n 3. InterchangeSort:";
    cout << "\n 4. InsertionSort:";
    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> choice;
    return choice;
}

void nhap(int &n)
{
    do
    {
        cout << "\n Nhap so luong phan tu cua mang: ";
        cin >> n;
    } while (n <= 0);
}

int main()
{
    int n, choice, a[MAX];
    bool flag = true;
    nhap(n);
    while (flag != false)
    {
        choice = menu();
        switch (choice)
        {
        case 0:
            cout << "Bye bye.\n"; // Thoat chuong trinh
            flag = false;
            break;

        case 1:
            NhapMang(a, n);
            XuatMang(a, n);
            break;

        case 2:
            NhapMang(a, n);
            XuatMang(a, n);
            SelectionSort(a, n);
            XuatMang(a, n);
            break;

        case 3:
            NhapMang(a, n);
            XuatMang(a, n);
            InterchangeSort(a, n);
            XuatMang(a, n);
            break;

        case 4:
            NhapMang(a, n);
            XuatMang(a, n);
            InsertionSort(a, n);
            XuatMang(a, n);
            break;

        default:
            cout << "Lua chon khong dung!!!.Xin long nhap lai: ";
            cin >> choice;
            break;
        }
    }

    cout << endl;
    getchar();
    return 0;
}