#include <iostream>
#include <math.h>
using namespace std;

int menu();
void NhapN(int &);
void TaoMaTran(int **, int &);
void XuatMaTran(int **, int);
void XuatSoDuong(int **, int);
void TimMin(int **, int);
void TimMax(int **, int);
int TimSoNguyenTo(int);
void XuatSoNguyenTo(int **, int);

int main()
{
    int n;
    NhapN(n);
    int **arr = new int *[n];
    int choice;
    bool flag = true;

    while (flag != false)
    {
        choice = menu();
        switch (choice)
        {
        case 0:
            cout << "Xin chao.\n"; // Thoat chuong trinh
            flag = false;
            break;
        case 1:
            TaoMaTran(arr, n); //Nhap ma tran ngau nhien
            break;
        case 2:
            XuatMaTran(arr, n); //Xuat ma tran
            break;
        case 3:
            XuatSoDuong(arr, n); //Xuat so duong
            break;
        case 4:
            TimMin(arr, n); //Tim min tren duong cheo chinh
            break;
        case 5:
            TimMax(arr, n); // Tim max tren duong cheo chinh
            break;
        case 6:
            XuatSoNguyenTo(arr, n); // Xuat so nguyen to tren duong cheo phu
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.\n";
            cin >> choice;
            break;
        }
    }

    cout << endl;
    //system("pause");
    delete arr;
    return 0;
}

int menu()
{
    int choice;
    cout << "\n ================================";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n 0. Thoat chuong trinh!!!";
    cout << "\n 1. Nhap ma tran (mang duoc tao ngau nhien -20 => 20):";
    cout << "\n 2. Xuat ma tran:";
    cout << "\n 3. Xuat so duong cua ma tran:";
    cout << "\n 4. Tim min tren duong cheo chinh:";
    cout << "\n 5. Tim max tren duong cheo chinh:";
    cout << "\n 6. Tim so nguyen to tren duong cheo phu:";

    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> choice;
    return choice;
}
void NhapN(int &n)
{
    do
    {
        cout << "\nNhap vao so hang(cot) cua mang (>=2):";
        cin >> n;
        if (n < 2)
        {
            cout << "\nSo hang(cot) >= 2. Xin nhap lai!!!";
        }
    } while (n < 2);
}

void TaoMaTran(int **arr, int &n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n]; // https://stackoverflow.com/questions/16001803/pointer-to-pointer-dynamic-two-dimensional-array
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = -20 + rand() % 41;
        }
    }
}

void XuatMaTran(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void XuatSoDuong(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > 0)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
}

void TimMin(int **arr, int n)
{
    int min = arr[0][0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i][i] < min)
        {
            min = arr[i][i];
        }
    }
    cout << "\nPhan tu nho nhat tren duong cheo chinh: " << min;
}

void TimMax(int **arr, int n)
{
    int max = arr[0][0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i][i] > max)
        {
            max = arr[i][i];
        }
    }
    cout << "\nPhan tu lon nhat tren duong cheo chinh: " << max;
}

int TimSoNguyenTo(int x)
{
    if (x < 2)
    {
        return 0;
    }

    if (x == 2)
    {
        return 1;
    }

    int count = 0;
    for (int i = 2; i < sqrt(x); i++)
    {
        if (x % i == 0)
        {
            count++;
        }
    }

    if (count == 0)
    {
        return 1;
    }

    return 0;
}

void XuatSoNguyenTo(int **arr, int n)
{
    cout << "\nXuat so nguyen to duong cheo phu:";
    for (int i = n - 1; i >= 0; i--)
    {
        if (TimSoNguyenTo(arr[i][n - 1 - i]))
        {
            cout << arr[i][n - 1 - i] << " ";
        }
    }
}