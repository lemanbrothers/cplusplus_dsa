#include <iostream>
using namespace std;

/* Bước 1: Khai báo cấu trúc dữ liệu danh sách liên kết */
struct Node
{
    int data;
    struct Node *pNext;
};


struct List
{
    Node *pHead, *pTail;
};

// Bước 2: Khởi tạo danh sách liên kết
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

// Bước 3: Tạo Node trong danh sách liên kết
Node *GetNode(int DATA)
{
    Node *p = new Node; // Khởi tạo con trỏ p
    p->data = DATA;
    p->pNext = NULL;
    return p;
}

// Bước 4: Thêm Node p vào đầu/Thêm Node p vào cuối trong danh sách liên kết
void AddHead(List &l, Node *p)
{
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

void AddTail(List &l, Node *p)
{
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

/* Bước 5: Viết hàm InPut/OutPut */
void InPut(List &l)
{
    Init(l); // Khoi tao danh sach
    int n;
    cout << "\nNhap vao so luong phan tu cua danh sach: ";
    cin >> n;
    cout << "\nData se nhan cac gia tri ngau nhien 1 => 100: ";
    for (int i = 0; i < n; i++)
    {
        int data = rand() % 100;
        //Nhap data vao Node
        Node *p = GetNode(data);
        AddTail(l, p);
    }
}

void OutPut(List l)
{
    cout << "\nXuat danh sach lien ket: ";
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

/* Bước 6: Những xử lý yêu cầu cần có trên danh sách liên kết */

// Tính tổng danh sách
int TinhTong(List l)
{
    int tong = 0;
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        tong += p->data;
    }
    return tong;
}

//Liet ke so chan/le trong danh sach
void LietKeSoChan(List l)
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data % 2 == 0)
        {
            cout << p->data << " ";
        }
    }
    cout << endl;
}


void SWAP(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SapXepTang(List &l)
{
    for (Node *p = l.pHead; p != l.pTail; p = p->pNext)
    {
        for (Node *q = p->pNext; q != NULL; q = q->pNext)
        {
            if (p->data > q->data)
            {
                SWAP(p->data, q->data);
            }
        }
    }
}

void SapXepGiam(List &l)
{
    for (Node *p = l.pHead; p != l.pTail; p = p->pNext)
    {
        for (Node *q = p->pNext; q != NULL; q = q->pNext)
        {
            if (p->data < q->data)
            {
                SWAP(p->data, q->data);
            }
        }
    }
}

// Thêm Node x = f vào đằng sau Node q = e: a b c d e '' h i
// them 69 vao sau 45 : 21 13 34 45 54 22
void ThemSauMotNode(List &l, Node *x, Node *q)
{   
    for(Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if(p->data == q->data)
        {
            Node *g = p->pNext;
            x->pNext = g;
            p->pNext = x;
            return;
        }
    }
}


int main()
{
    List l;
    InPut(l);
    OutPut(l);

    cout << "\nLiet ke so chan: ";
    LietKeSoChan(l);

    cout << "\nTinh tong: ";
    cout << TinhTong(l);

    cout << "\nSap xep tang: ";
    SapXepTang(l);
    OutPut(l);

    cout << "\nSap xep giam: ";
    SapXepGiam(l);
    OutPut(l);

    cout << "\nThem sau 1 Node:";
    Node *x = GetNode(77);
    cout << "\nx = " << x->data;
    Node *q = GetNode(69);
    ThemSauMotNode(l, x, q);
    OutPut(l);

    cout << endl;
    getchar();
    return 0;
}