#include <iostream>
using namespace std;
#define MAX 100

void NhapMang(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

void XuatMang(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void LietKeCapPhanTu(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

void LietKeCapPhanTuKeNhau(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << "(" << arr[i] << "," << arr[i + 1] << ") ";
    }
    cout << endl;
}

void InterChangeSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void SelectionSort(int a[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)

            if (a[j] < a[min])
                min = j;
        swap(a[min], a[i]);
    }
}

void ThemPhanTuTangDan(int arr[], int &n, int x)
{
    int i = n - 1;
    while ((x <= arr[i]) && (i >= 0))
    {
        arr[i + 1] = arr[i];
        --i;
    }
    arr[i + 1] = x;
    ++n;
}

void TachMang(int arr[], int n, int b[], int &j, int c[], int &k, int x)
{
    j = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < x)
        {
            b[j++] = arr[i];
        }
        else
        {
            c[k++] = arr[i];
        }
    }
}

void TronHaiMangTangDan(int arr1[], int n1, int arr2[], int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    while (i < n1)
        arr3[k++] = arr1[i++];

    while (j < n2)
        arr3[k++] = arr2[j++];
}
void HoanVi(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void BubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                HoanVi(&arr[j], &arr[j + 1]);
}

void InsertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[high];
//     int i = (low - 1);

//     for (int j = low; j <= high - 1; j++)
//     {
//         if (arr[j] <= pivot)
//         {
//             i++;
//             HoanVi(&arr[i], &arr[j]);
//         }
//     }
//     HoanVi(&arr[i + 1], &arr[high]);
//     return (i + 1);
// }

// void QuickSort(int arr[], int low, int high)
// {
//     if (low < high)
//     {
//         int pi = partition(arr, low, high);
//         QuickSort(arr, low, pi - 1);
//         QuickSort(arr, pi + 1, high);
//     }
// }

void QuickSort(int arr[], int l, int r)
{
    if (l <= r)
    {
        int key = arr[(l + r) / 2];
        int i = l;
        int j = r;

        while (i <= j)
        {
            while (arr[i] < key)
                i++;
            while (arr[j] > key)
                j--;

            if (i <= j)
            {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (l < j)
            QuickSort(arr, l, j);
        if (r > i)
            QuickSort(arr, i, r);
    }
}

void Merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);

        Merge(arr, l, m, r);
    }
}

int menu()
{
    int choice;
    cout << "\n ================================";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n 0. Thoat chuong trinh";
    cout << "\n 1. Liet Ke Cap Phan Tu";
    cout << "\n 2. Liet Ke Cap Phan Tu Ke Nhau";
    cout << "\n 3. Selection Sort";
    cout << "\n 4. Them Phan Tu Tang Dan";
    cout << "\n 5. Tach Mang";
    cout << "\n 6. Tron Hai Mang Tang Dan";
    cout << "\n 7. Tim node co du lieu bang x: ";
    cout << "\n 8. Selection Sort";
    cout << "\n 9. Bubble Sort";
    cout << "\n 10. Insertion Sort";
    cout << "\n 11. Quick Sort";
    cout << "\n 12. Merge Sort";

    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> choice;
    return choice;
}

void nhap(int &n)
{
    do
    {
        cout << "\n Nhap phan tu cho mang: ";
        cin >> n;
    } while (n <= 0);
}

int main()
{
    int n = 5, j, k, arr[MAX], b[MAX], c[MAX];
    int choice, x;
    bool flag = true;
    nhap(n);

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
            NhapMang(arr, n);
            XuatMang(arr, n);
            LietKeCapPhanTu(arr, n);
            break;

        case 2:
            NhapMang(arr, n);
            XuatMang(arr, n);
            LietKeCapPhanTuKeNhau(arr, n);
            break;

        case 3:
            NhapMang(arr, n);
            XuatMang(arr, n);
            SelectionSort(arr, n);
            XuatMang(arr, n);
            break;

        case 4:
            NhapMang(arr, n);
            XuatMang(arr, n);
            ThemPhanTuTangDan(arr, n, 69);
            XuatMang(arr, n);
            break;

        case 5:
            NhapMang(arr, n);
            XuatMang(arr, n);
            cout << "\nNhap phan tu de tach mang:";
            cin >> x;
            TachMang(arr, n, b, j, c, k, x);
            XuatMang(b, j);
            XuatMang(c, k);
            break;

        case 6:
            int arr1[MAX], arr2[MAX], arr3[MAX];
            int u, v;
            cout << "\nNhap so phan tu cua mang 1(u): ";
            cin >> u;
            cout << "\nNhap so phan tu cua mang 2(v): ";
            cin >> v;
            NhapMang(arr1, u);
            NhapMang(arr2, v);
            SelectionSort(arr1, u);
            XuatMang(arr1, u);
            SelectionSort(arr2, v);
            XuatMang(arr2, v);
            TronHaiMangTangDan(arr1, u, arr2, v, arr3);
            XuatMang(arr3, (u + v));
            break;

        case 7:
            NhapMang(arr, n);
            XuatMang(arr, n);
            InterChangeSort(arr, n);
            XuatMang(arr, n);
            break;

        case 8:
            NhapMang(arr, n);
            XuatMang(arr, n);
            SelectionSort(arr, n);
            XuatMang(arr, n);
            break;

        case 9:
            NhapMang(arr, n);
            XuatMang(arr, n);
            BubbleSort(arr, n);
            XuatMang(arr, n);
            break;

        case 10:
            NhapMang(arr, n);
            XuatMang(arr, n);
            InsertionSort(arr, n);
            XuatMang(arr, n);
            break;

        case 11:
            NhapMang(arr, n);
            XuatMang(arr, n);
            QuickSort(arr, 0, n - 1);
            XuatMang(arr, n);
            break;

        case 12:
            NhapMang(arr, n);
            XuatMang(arr, n);
            MergeSort(arr, 0, n -1);
            XuatMang(arr, n);
            break;

        default:
            cout << "Lua chon khong dung!!!.Xin long nhap lai: ";
            cin >> choice;
            break;
        }
    }

    cout << "\nPress ENTER to finish program!!!\n";
    getchar();
    return 0;
}