#include <iostream>
using namespace std;

// Khai bao struct Node
struct Node
{
    int data;
    Node *pNext;
};

// Khoi tao 1 Node
Node *InitNode(int DATA)
{
    Node *p = new Node;
    p->data = DATA;
    p->pNext = NULL;
    return p;
}

// Khai bao struct List
struct List
{
    Node *pHead, *pTail;
};

// Khoi tao 1 List
void InitList(List &l)
{
    l.pHead = l.pTail = NULL;
}

//Them vao dau danh sach
void AddHead(List &l, int x)
{
    Node *p = InitNode(x);
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

//Them vao cuoi danh sach
void AddTail(List &l, int x)
{
    Node *p = InitNode(x);
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

// Nhap vao dau danh sach, nhan gia tri ngau nhien 1 - 100:
void InPutListHead(List &l, int n)
{
    InitList(l);
    for (int i = 0; i < n; i++)
    {
        int DATA = rand() % 100;
        Node *p = InitNode(DATA);
        AddHead(l, DATA);
    }
}

// Nhap vao cuoi danh sach, nhan gia tri ngau nhien 1 - 100:
void InPutListTail(List &l, int n)
{
    InitList(l);
    for (int i = 0; i < n; i++)
    {
        int DATA = rand() % 100;
        Node *p = InitNode(DATA);
        AddTail(l, DATA);
    }
}

// Xuat danh sach
void OutPutList(List l)
{
    cout << "\nXuat danh sach: ";
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

//Dao nguoc danh sach
void Reverse(List &l)
{
    if (l.pHead != NULL && l.pHead->pNext != NULL)
    {
        Node *Head = l.pHead;
        Node *Next = l.pHead->pNext;
        Node *Tail = NULL;

        if (Next->pNext != NULL)
        {
            Tail = Next->pNext;
        }
        Head->pNext = NULL;

        while (Tail->pNext != NULL)
        {
            Next->pNext = Head;
            Head = Next;
            Next = Tail;
            Tail = Tail->pNext;
        }

        Next->pNext = Head;
        l.pHead = Tail;
        Tail->pNext = Next;
    }
}

// Dem so node cua danh sach
int CountNode(List l)
{
    int dem = 0;
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        dem++;
    }
    return dem;
}

// Tim kiem x trong list
int SearchX(List l, int x)
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data == x)
        {
            return 1;
        }
    }
    return 0;
}

// Xoa phan tu dau dslk
void RemoveHead(List &l)
{
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
    }
}

// // Xoa phan tu cuoi dslk
// void RemoveTail(List &l)
// {
//     // Node *g;
//     // for (Node *p = l.pHead; p != NULL; p = p->pNext)
//     // {
//     //     if (p == l.pTail)
//     //     {
//     //         g->pNext = NULL;
//     //         l.pTail = g;
//     //         delete p;
//     //         return;
//     //     }
//     //     g = p;
//     // }
//     for (Node *p = l.pHead; p->pNext != NULL; p = p->pNext)
//     {
//         if (p->pNext->pNext == NULL)
//         {
//             p->pNext = NULL;
//             l.pTail = p->pNext;
//         }
//     }
// }
// void XoaCuoi(list &d) //Xóa phần tử cuối cùng của danh sách
// {
//     if (d.first == NULL)
//         return;        //Nếu danh sách rỗng thì thoát khỏi hàm
//     node *p = d.first; //khai báo con trỏ gán với node đầu của danh sách
//     node *r = d.last;  //khai báo con trỏ gán với node cuối của danh sách
//     if (p == r)        //Nếu danh sách chỉ có một node
//     {
//         d.first = d.last = NULL;
//         delete p;
//     }
//     else //Nếu không p chạy tới node cận cuối cùng
//     {
//         while (p->next != r)
//             p = p->next;
//         p->next = NULL; //p trỏ đến NULL
//         d.last = p;     //Node cận cuối p trở thành node cuối
//         delete r;       //Xóa node cuối ban đầu
//     }
// }

void RemoveTail(List &l)
{
    Node *g; // Node trước
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p == l.pTail)
        {
            g->pNext = NULL;
            l.pTail = g;
            delete p;
            return;
        }
        g = p;
    }
}

// Xoa phan tu sau 1 node cho truoc
void RemoveAfterNode(List &l, int x)
{
    Node *q = InitNode(x);
    for (Node *p = l.pHead; p != l.pTail; p = p->pNext)
    {
        if (p->pNext->data == q->data)
        {
            p->pNext = p->pNext->pNext;
            return;
        }
    }
}

// Xoa phan tu nhap tu ban phim
void RemoveFromInput(List &l, int x)
{
    Node *PrevNode = l.pHead;
    for (Node *p = l.pHead->pNext; p != l.pTail; p = p->pNext)
    {
        if (p->data == x)
        {
            Node *AfterNode;
            AfterNode = p->pNext;
            PrevNode->pNext = AfterNode;
            delete p;
            p = PrevNode;
        }
        PrevNode = p;
    }

    if (l.pHead->data == x)
    {
        RemoveHead(l);
    }

    if (l.pTail->data == x)
    {
        RemoveTail(l);
    }
}

void InsertToList(List &l, int x, int i)
{
    if(i == 0)
    {
        AddHead(l,x);
    }else if(i == CountNode(l) - 1)
    {
        AddTail(l, x);
    }
    else if(i > 0 && i < CountNode(l) - 1)// 21 49 92 35 '69' 93 15 77 83, chen 69 vao vi tri 4
    {                                                   //q
        int dem = 0;
        for(Node *p = l.pHead; p != NULL; p = p->pNext)
        {
            dem++;
            if(dem == i - 1)
            {
                Node *q = InitNode(x);
                q->pNext = p->pNext;
                p->pNext = q;
                delete q;
                return;
            }
        }
    }
}

int menu()
{
    int choice;
    cout << "\n ================================";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n 0. Thoat chuong trinh";
    cout << "\n 1. Nhap vao dau dslk: ";
    cout << "\n 2. Nhap vao cuoi dslk: ";
    cout << "\n 3. Xuat DSLK: ";
    cout << "\n 4. Them phan tu vao cuoi dslk: ";
    cout << "\n 5. Xuat DSLK tu cuoi: ";
    cout << "\n 6. Dem so nut trong DSLK: ";
    cout << "\n 7. Tim node co du lieu bang x: ";
    cout << "\n 8. Xoa node dau dslk: ";
    cout << "\n 9. Xoa node cuoi dslk: ";
    cout << "\n 10. Xoa node co du lieu bang x: ";
    cout << "\n 11. Chen node x vao sau node y: ";

    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> choice;
    return choice;
}

void nhap(int &n)
{
    do
    {
        cout << "\n Nhap so node cho dslk: ";
        cin >> n;
    } while (n <= 0);
}

void InputData(int &x)
{
    cout << "\nNhap du lieu cho node: ";
    cin >> x;
}

void InputX(int &x)
{
    cout << "\nNhap x: ";
    cin >> x;
}

int main()
{
    List l;
    int n, choice, x, i;
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
            break;
        case 2:
            InPutListTail(l, n);
            break;
        case 3:
            OutPutList(l);
            break;
        case 4:
            InputData(x);
            AddTail(l, x);
            break;
        case 5:
            Reverse(l);
            OutPutList(l);
            break;
        case 6:
            cout << "\nSo node trong dslk: " << CountNode(l);
            break;
        case 7:
            InputX(x);
            cout << SearchX(l, x);
            break;
        case 8:
            RemoveHead(l);
            OutPutList(l);
            break;
        case 9:
            RemoveTail(l);
            OutPutList(l);
            break;
        case 10:
            InputX(x);
            RemoveFromInput(l, x);
            OutPutList(l);
            break;
        case 11:
            cout << "\nNhap gia tri can chen: ";
            cin >> x;
            cout << "\nNhap vao vi tri can chen: ";
            cin >> i;
            InsertToList(l, x, i);
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