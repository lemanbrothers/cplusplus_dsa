#include <iostream>
#include <string>
using namespace std;

void nhap(int &n)
{
    do
    {
        cout << "\n Vui long nhap vao so luong sinh vien: ";
        cin >> n;
    } while (n <= 0);
}

int menu()
{
    int choice;
    cout << "\n ================================";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n 0. Thoat chuong trinh";
    cout << "\n 1. Nhap mang cac sinh vien: ";
    cout << "\n 2. Xuat thong tin cac sinh vien: ";
    cout << "\n 3. Xuat sinh vien co diem trung binh cao nhat: ";
    cout << "\n 4. Xuat sinh vien co diem trung binh >= 5: ";
    cout << "\n 5. Tim ten sinh vien: ";
    cout << "\n 6. Xoa sinh vien theo ma so:";
    cout << "\n 7. Chen sinh vien: ";

    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> choice;
    return choice;
}
struct SinhVien
{
    string HoTen;
    string MaSo;
    float DiemTrungBinh;
};

void Nhap(SinhVien &sv)
{
    fflush(stdin);
    cout << "\nNhap ho ten: ";
    getline(cin, sv.HoTen);
    cout << "\nNhap ma so: ";
    getline(cin, sv.MaSo);
    do
    {
        cout << "\nNhap diem trung binh: ";
        cin >> sv.DiemTrungBinh;
        if (sv.DiemTrungBinh < 0 || sv.DiemTrungBinh > 10)
        {
            cout << "\nDiem trung binh 0 <= DTB <= 10. Xin nhap lai!!!";
        }
    } while (sv.DiemTrungBinh < 0 || sv.DiemTrungBinh > 10);
}

void NhapMangSV(SinhVien *MangSV, int &n)
{
    for (int i = 0; i < n; i++)
    {
        while (getchar() != '\n')
            ;
        Nhap(MangSV[i]);
    }
}

void Xuat(SinhVien sv)
{
    cout << "\nHo ten: " << sv.HoTen;
    cout << "\nMa so: " << sv.MaSo;
    cout << "\nDiem trung binh: " << sv.DiemTrungBinh;
}

void XuatMangSV(SinhVien *MangSV, int n)
{
    for (int i = 0; i < n; i++)
    {
        Xuat(MangSV[i]);
    }
}

float TimDTBMax(SinhVien *MangSV, int n)
{
    float max = MangSV[0].DiemTrungBinh;
    for (int i = 1; i < n; i++)
    {
        if (MangSV[i].DiemTrungBinh > max)
        {
            max = MangSV[i].DiemTrungBinh;
        }
    }
    return max;
}

void XuatMaxDTB(SinhVien *MangSV, int n)
{
    float Max = TimDTBMax(MangSV, n);
    for (int i = 0; i < n; i++)
    {
        if (MangSV[i].DiemTrungBinh == Max)
        {
            Xuat(MangSV[i]);
        }
    }
}

void XuatDTBLonHon5(SinhVien *MangSV, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (MangSV[i].DiemTrungBinh >= 5)
        {
            count++;
        }
    }
    if (count == 0)
    {
        cout << "\nKhong ton tai sinh vien co DTB >=5.";
    }
    else
    {
        cout << "\nSo luong sinh vien co diem trung binh >= 5: " << count;
    }
}

void TimTenSV(SinhVien *MangSV, int n)
{
    cout << "\nNhap ten sinh vien can tim: ";
    //fflush(stdin);
    string Ten;
    int count = 0;
    while (getchar() != '\n') // https://stackoverflow.com/questions/37354909/why-does-my-fflush-not-work-skips-asking-for-string-in-loop
        ;
    getline(cin, Ten);

    for (int i = 0; i < n; i++)
    {
        if (MangSV[i].HoTen == Ten)
        {
            cout << "\nTim thay sinh vien " << Ten << " trong danh sach sinh vien.";
            count++;
        }
    }
    if (count == 0)
    {
        cout << "\nKhong tim that sinh vien " << Ten << " trong danh sach sinh vien.";
    }
}

void XoaSinhVien(SinhVien *MangSV, int &n)
{
    cout << "\nNhap ma so sinh vien can xoa: ";
    //fflush(stdin);
    string maso;
    int count = 0;
    // https://stackoverflow.com/questions/37354909/why-does-my-fflush-not-work-skips-asking-for-string-in-loop
    while (getchar() != '\n')
        ;
    getline(cin, maso);

    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (MangSV[i].MaSo == maso)
        {
            pos = i;
        }
    }

    if (pos != -1)
    {
        for (int j = pos; j < n - 1; j++)
        {
            MangSV[j] = MangSV[j + 1];
        }
        cout << "\nXoa thanh cong.";
        n--;
    }
    else
    {
        cout << "\nKhong tim thay ma so trong danh sach sinh vien.";
    }
}

void ChenSinhVien(SinhVien *MangSV, int &n)
{
    cout << "\nNhap thong tin sinh vien can them vao danh sach:";
    SinhVien sv;
    while (getchar() != '\n')
        ;
    Nhap(sv);

    int pos = 0;
    for(int i = 0; i < n; i++)
    {
        if(sv.DiemTrungBinh >= MangSV[i].DiemTrungBinh && sv.DiemTrungBinh <= MangSV[i+1].DiemTrungBinh)
        {
            pos = i + 1;
        }
    }
    n++;
    MangSV = (SinhVien *)realloc(MangSV, n * sizeof(sv));

    for(int j = n; j > pos; j--)
    {
        MangSV[j] = MangSV[j - 1];
    }
    MangSV[pos] = sv;
}

int main()
{
    int n;
    nhap(n);
    SinhVien *MangSV = new SinhVien[n];

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
            NhapMangSV(MangSV, n); // Nhap mang cac sinh vien
            break;
        case 2:
            XuatMangSV(MangSV, n); // Xuat mang cac sinh vien
            break;
        case 3:
            XuatMaxDTB(MangSV, n); // Xuat sv co diem trung binh cao nhat
            break;
        case 4:
            XuatDTBLonHon5(MangSV, n); // Xuat so sv co diem trung binh >= 5
            break;
        case 5:
            TimTenSV(MangSV, n); // Tim ten sinh vien
            break;
        case 6:
            XoaSinhVien(MangSV, n); // Xoa sinh vien theo ma so
            break;
        case 7:
            ChenSinhVien(MangSV, n); // Chen sinh vien vao mang.
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.\n";
            cin >> choice;
            break;
        }
    }

    cout << endl;
    //system("pause");
    delete[] MangSV;
    return 0;
}
