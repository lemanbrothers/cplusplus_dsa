#include <iostream>
#include <string>
using namespace std;

struct SinhVien
{
    string HoTen;
    string MaSo;
    int NamSinh;
    float DiemTB;
};

struct NodeSV
{
    SinhVien data;
    NodeSV *pNext;
};

NodeSV *AddNode(SinhVien x)
{
    NodeSV *p = new NodeSV;
    p->data = x;
    p->pNext = NULL;
    return p;
}

void NhapSV(SinhVien &sv)
{
    while (getchar() != '\n')
        ;
    cout << "\nNhap ho ten: ";
    getline(cin, sv.HoTen);
    cout << "\nNhap ma so: ";
    getline(cin, sv.MaSo);
    do
    {
        cout << "\nNhap nam sinh: ";
        cin >> sv.NamSinh;
        if (sv.NamSinh < 1900 || sv.NamSinh > 2020)
        {
            cout << "\n1900 <= Nam sinh <= 2020. Xin nhap lai!!!";
        }
    } while (sv.NamSinh < 1900 || sv.NamSinh > 2020);

    do
    {
        cout << "\nNhap diem trung binh: ";
        cin >> sv.DiemTB;
        if (sv.DiemTB < 0 || sv.DiemTB > 10)
        {
            cout << "\nDiem trung binh phai 0 <= DTB <= 10. Xin nhap lai.";
        }
    } while (sv.DiemTB < 0 || sv.DiemTB > 10);
}

void XuatSV(SinhVien sv)
{
    cout << "\nHo ten: " << sv.HoTen;
    cout << "\nMa so: " << sv.MaSo;
    cout << "\nNam sinh: " << sv.NamSinh;
    cout << "\nDiem trung binh: " << sv.DiemTB;
}

struct ListSV
{
    NodeSV *pHead, *pTail;
};

void InitList(ListSV &l)
{
    l.pHead = l.pTail = NULL;
}

void AddHead(ListSV &l, SinhVien x)
{
    NodeSV *p = AddNode(x);
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void AddTail(ListSV &l, SinhVien x)
{
    NodeSV *p = AddNode(x);
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void InPutListHead(ListSV &l, int n)
{
    InitList(l);
    SinhVien x;
    for (int i = 0; i < n; i++)
    {
        NhapSV(x);
        AddHead(l, x);
    }
}

void InPutListTail(ListSV &l, int n)
{
    InitList(l);
    SinhVien x;
    for (int i = 0; i < n; i++)
    {
        NhapSV(x);
        AddTail(l, x);
    }
}

void OutPutList(ListSV l)
{
    for (NodeSV *p = l.pHead; p != NULL; p = p->pNext)
    {
        XuatSV(p->data);
    }
}

void XuatSVDTBNhoHon5(ListSV l)
{
    for (NodeSV *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data.DiemTB < 5)
        {
            XuatSV(p->data);
        }
    }
}

void RemoveHead(ListSV &l)
{
    if (l.pHead != NULL)
    {
        NodeSV *p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
    }
}

void RemoveTail(ListSV &l)
{
    NodeSV *PrevNode;
    for (NodeSV *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p == l.pTail)
        {
            PrevNode->pNext = NULL;
            l.pTail = PrevNode;
            delete p;
            return;
        }
        PrevNode = p;
    }
}
void RemoveBefore2000(ListSV &l)
{
    NodeSV *PrevNode = l.pHead;
    for (NodeSV *p = l.pHead->pNext; p != l.pTail; p = p->pNext)
    {
        if (p->data.NamSinh < 2000)
        {
            NodeSV *AfterNode = p->pNext;
            PrevNode->pNext = AfterNode;
            delete p;
            p = PrevNode;
        }
    }

    if (l.pHead->data.NamSinh < 2000)
    {
        RemoveHead(l);
    }

    if (l.pTail->data.NamSinh < 2000)
    {
        RemoveTail(l);
    }
}

void SapXepTang(ListSV &l)
{
    ListSV ListNew;

    NodeSV *min, *p, *q, *MinPrev;

    ListNew.pHead = ListNew.pTail = NULL; 

    while (l.pHead != NULL)
    {

        p = l.pHead;
        q = p->pNext;
        min = p;
        MinPrev = NULL;
        while (q != NULL)
        {

            if (q->data.DiemTB < min->data.DiemTB)
            {

                min = q;
                MinPrev = p;
            }

            p = q;
            q = q->pNext;
        }
        if (MinPrev != NULL)

            MinPrev->pNext = min->pNext;

        else

            l.pHead = min->pNext;

        min->pNext = NULL;

        AddTail(ListNew, min->data);
    }

    l = ListNew;
}

void XoaSinhVien(ListSV &l)
{
    for(NodeSV *p = l.pHead; p != NULL; p = p->pNext)
    {
        XuatSV(p->data);
        cout << "\n------Deleted sinh vien " << p->data.HoTen << "-------\n";
        l.pHead = l.pHead->pNext;
    }
}

int menu()
{
    int choice;
    cout << "\n ================================";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n 0. Thoat chuong trinh";
    cout << "\n 1. Nhap vao dau va xuat dslk: ";
    cout << "\n 2. Nhap vao cuoi va xuat dslk: ";
    cout << "\n 3. Sinh vien co dtb < 5: ";
    cout << "\n 4. Xoa sinh vien co nam sinh < 2000: ";
    cout << "\n 5. Sap xep ds sinh vien tang dan theo diem trung binh: ";
    cout << "\n 6. In ra va xoa sinh vien: ";
    cout << "\n 7. Xuat danh sach tat ca sinh vien: ";
    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> choice;
    return choice;
}

void nhap(int &n)
{
    do
    {
        cout << "\n Nhap so luong sinh vien: ";
        cin >> n;
    } while (n <= 0);
}

int main()
{
    ListSV l;
    int n, choice, x;
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
            InPutListHead(l, n);
            OutPutList(l);
            break;
        case 2:
            InPutListTail(l, n);
            OutPutList(l);
            break;
        case 3:
            XuatSVDTBNhoHon5(l);
            break;
        case 4:
            RemoveBefore2000(l);
            OutPutList(l);
            break;
        case 5:
            SapXepTang(l);
            OutPutList(l);
            break;
        case 6:
            XoaSinhVien(l);
            break;
        case 7:
            OutPutList(l);
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