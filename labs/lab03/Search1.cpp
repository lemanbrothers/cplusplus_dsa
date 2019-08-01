#include <iostream>
using namespace std;

void NhapMang(int *arr, int &);
void XuatMang(int *arr, int);
int TimKiemTuanTu(int *arr, int, int);
int TimKiemTuanTuLinhCanh(int *arr, int, int);
int TimMin(int *arr, int);
int TimMax(int *arr, int);
void TimKiemViTriMin(int *arr, int);
void TimKiemViTriMax(int *arr, int);
void NhapN(int &);
void NhapX(int &);
int menu();

int main()
{
    int n, x, choice;
    int *arr = new int [n];
    NhapN(n);
    bool flag = true;

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
            NhapMang(arr, n);
            break;

        case 2:
            XuatMang(arr, n);
            break;

        case 3:
            NhapX(x);
            cout << TimKiemTuanTu(arr, n, x);
            break;

        case 4:
            NhapX(x);
            cout << TimKiemTuanTuLinhCanh(arr, n, x);
            break;

        case 5:
            TimKiemViTriMin(arr, n);
            break;

        case 6: 
            TimKiemViTriMax(arr, n);
            break;

        default:
            cout << "Lua chon khong dung!!!.Xin long nhap lai: ";
            cin >> choice;
            break;
        }
    }

    cout << "\nEnter any key to finish program!!!\n";
    return 0;
}

void NhapMang(int *arr, int &n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

void XuatMang(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int TimKiemTuanTu(int *arr, int n, int x)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int TimKiemTuanTuLinhCanh(int *arr, int n, int x)
{
    arr[n] = x;
    int i = 0;
    // 1 7 2 4 6 8 9
    while(arr[i] != x)
    {
        i++;
    }
    if(i == n)
    {
        return -1;
    }
    return i;
}

int TimMin(int *arr, int n)
{
    int min = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}


int TimMax(int *arr, int n)
{
    int max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void TimKiemViTriMin(int *arr, int n)
{
    int Min = TimMin(arr, n);
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == Min)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void TimKiemViTriMax(int *arr, int n)
{
    int Max = TimMax(arr, n);
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == Max)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int menu()
{
    int choice;
    cout << "\n ================================";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n 0. Thoat chuong trinh";
    cout << "\n 1. Nhap mang.";
    cout << "\n 2. Xuat mang.";
    cout << "\n 3. Tim kiem tuan tu.";
    cout << "\n 4. Tim kiem tuan tu linh canh.";
    cout << "\n 5. Tim tat vi tri chua gia tri nho nhat.";
    cout << "\n 6. Tim tat vi tri chua gia tri lon nhat.";
    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> choice;
    return choice;
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