#include <iostream>
#include <math.h>
using namespace std;

int menu();
void nhap(int &);
void NhapMang(int *, int &);
void XuatMang(int *, int);
int TimMin(int *, int);
int TimMax(int *, int);
void XuatMinMax(int *, int);
void DemPhanTuAm(int *, int);
void TimMaxAm(int *, int);
void TimMinDuong(int *, int);
int TimSoNguyenTo(int);
void XuatSoNguyenTo(int *, int);
int TimSoChinhPhuong(int);
void XuatSoChinhPhuong(int *, int);
int TimSoHoanThien(int);
void XuatSoHoanThien(int *, int);
void DemPhanTuBangX(int *, int);
void XoaPhanTu(int *, int &);

int main()
{
    int n;
    nhap(n);
    int *arr = new int[n];
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
            NhapMang(arr, n); //Nhap mang
            break;
        case 2:
            XuatMang(arr, n); // Liet ke cac so vua nhap
            break;
        case 3:
            XuatMinMax(arr, n); // Xuat cac vi tri nho nhat, lon nhat
            break;
        case 4:
            DemPhanTuAm(arr, n); // Dem so luong phan tu am
            break;
        case 5:
            TimMaxAm(arr, n); // Phan tu am lon nhat
            break;
        case 6:
            TimMinDuong(arr, n); // Tim min duong
            break;
        case 7:
            XuatSoNguyenTo(arr, n); // Xuat so nguyen to trong mang.
            break;
        case 8:
            XuatSoChinhPhuong(arr, n); // Xuat so chinh phuong trong mang.
            break;
        case 9:
            XuatSoHoanThien(arr, n); // Xuat so hoan thien trong mang.
            break;
        case 10:
            DemPhanTuBangX(arr, n);
            break;
        case 11:
            XoaPhanTu(arr, n);
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.\n";
            cin >> choice;
            break;
        }
    }
    return 0;
}
/**
 funtion: for select the menu
 @para: No
 @result: the id of selected menu
**/

int menu()
{
    int choice;
    cout << "\n ================================";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n 0. Thoat chuong trinh";
    cout << "\n 1. Nhap mang (mang duoc tao ngau nhien -20 => 20)";
    cout << "\n 2. Liet ke cac so vua nhap";
    cout << "\n 3. Xuat vi tri nho nhat, lon nhat:";
    cout << "\n 4. So phan tu am trong mang: ";
    cout << "\n 5. Phan tu am lon nhat trong mang: ";
    cout << "\n 6. Phan tu duong nho nhat trong mang:";
    cout << "\n 7. Xuat so nguyen to trong mang:";
    cout << "\n 8. Xuat so chinh phuong trong mang:";
    cout << "\n 9. Xuat so hoan thien trong mang:";
    cout << "\n 10. Dem phan tu x trong mang:";
    cout << "\n 11. Xoa phan tu trong mang:";

    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> choice;
    return choice;
}
/**
 funtion: input a value 
 @para: input from keyboard
 @result: 
**/

void nhap(int &n)
{
    do
    {
        cout << "\n Vui long nhap vao so luong phan tu cua mang: ";
        cin >> n;
    } while (n <= 0);
}

void NhapMang(int *arr, int &n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = -20 + rand() % 41;
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

int TimMin(int *arr, int n)
{
    int Min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < Min)
        {
            Min = arr[i];
        }
    }
    return Min;
}

int TimMax(int *arr, int n)
{
    int Max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > Max)
        {
            Max = arr[i];
        }
    }
    return Max;
}

void XuatMinMax(int *arr, int n)
{
    int min = TimMin(arr, n);
    int max = TimMax(arr, n);

    cout << "\nGia tri nho nhat trong mang: " << min;
    cout << "\nCac vi tri co gia tri nho nhat: ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == min)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "\nGia tri lon nhat trong mang: " << max;
    cout << "\nCac vi tri co gia tri lon nhat: ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == max)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void DemPhanTuAm(int *arr, int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            dem++;
        }
    }
    cout << "\nSo phan tu am trong mang: " << dem;
}

void TimMaxAm(int *arr, int n)
{
    int min = TimMin(arr, n);
    int MaxAm = min;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > MaxAm && arr[i] < 0)
        {
            MaxAm = arr[i];
        }
    }
    cout << "\nPhan tu am lon nhat: " << MaxAm << endl;
}

void TimMinDuong(int *arr, int n)
{
    int max = TimMax(arr, n);
    int MinDuong = max;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < MinDuong && arr[i] > 0)
        {
            MinDuong = arr[i];
        }
    }
    cout << "\nPhan tu duong nho nhat: " << MinDuong << endl;
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

void XuatSoNguyenTo(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (TimSoNguyenTo(arr[i]))
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int TimSoChinhPhuong(int x)
{
    if (pow((int)sqrt(x), 2) == x)
    {
        return 1;
    }
    return 0;
}

void XuatSoChinhPhuong(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (TimSoChinhPhuong(arr[i]))
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int TimSoHoanThien(int x)
{
    int sum = 0;
    for (int i = 1; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            sum += i;
        }
    }

    if (sum == x)
    {
        return 1;
    }
    return 0;
}

void XuatSoHoanThien(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (TimSoHoanThien(arr[i]))
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void DemPhanTuBangX(int *arr, int n)
{
    int x;
    cout << "\nNhap x:";
    cin >> x;

    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            dem++;
        }
    }

    if (dem == 0)
    {
        cout << "\nKhong ton tai " << x << " trong mang.";
    }
    else
    {
        cout << "\nSo luong phan tu bang " << x << " trong mang: " << dem << endl;
    }
}

void XoaPhanTu(int *arr, int &n)
{
    int k;
    do
    {
        cout << "\nNhap vao vi tri can xoa:";
        cin >> k;
        if (k < 0 || k >= n)
        {
            cout << "\nVi tri xoa khong hop le. Xin nhap lai";
        }
    } while (k < 0 || k >= n);

    for (int i = k; i < n - 1; i++) //xoa vi tri 3 trong mang 3, 2, 6, 7, 8, 9, 1, 4 => 3, 2, 6, 8, 9, 1, 4
    {
        arr[i] = arr[i + 1];
    }
    n--;
}