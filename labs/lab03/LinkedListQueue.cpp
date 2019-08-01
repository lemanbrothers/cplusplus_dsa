#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *pNext;
};

// Khoi tao Node
Node *InitNode(int x)
{
    Node *p = new Node();
    p->data = x;
    p->pNext = NULL;
    return p;
}

struct Queue
{
    Node *pFront;
    Node *pRear;
};

// Khoi tao Queue
void InitQueue(Queue &q)
{
    q.pFront = NULL;
    q.pRear = NULL;
}

// Kiem tra queue rong
bool IsEmpty(Queue q)
{
    if (q.pFront == NULL)
    {
        return true;
    }
    return false;
}

// Them phan tu
bool EnQueue(Queue &q, Node *p)
{
    if (IsEmpty(q) == true)
    {
        q.pFront = q.pRear = p;
    }
    else
    {
        q.pRear->pNext = p;
        q.pRear = p;
    }
    return true;
}

// Xoa phan tu
void DeQueue(Queue &q)
{
    if (IsEmpty(q) == true)
    {
        cout << "\nQueue rong";
        return;
    }
    else
    {
        Node *p = q.pFront;
        q.pFront = q.pFront->pNext;
    }
}

// Xuat queue
void PrintQueue(Queue q)
{
    if(IsEmpty(q))
    {
        cout << "\nQueue is empty!!!";
    }
    else
    {
        for(Node *p = q.pFront; p != NULL; p = p->pNext)
        {
            cout << p->data << " ";
        }
    }
    cout << endl;
}

void nhap(int &n)
{
    do
    {
        cout << "\n Nhap so luong phan tu cua queue: ";
        cin >> n;
    } while (n <= 0);
}

// Kich thuoc queue
int SizeOfQueue(Queue q)
{
    if(IsEmpty(q) == true)
    {
        return 0;
    }
    int size = 0;
    for(Node *p = q.pFront; p != NULL; p = p->pNext)
    {
        size++;
    }
    return size;
}

// Huy queue
void DeleteQueue(Queue &q)
{
    while(!IsEmpty(q))
    {
        DeQueue(q);
    }
}

void NhapQueue(Queue &q)
{
    int luachon, n;
    nhap(n);
    while (true)
    {
        cout << "\n ================================";
        cout << "\n Vui long chon chuc nang tuong ung";
        cout << "\n 0. Thoat chuong trinh";
        cout << "\n 1. EnQueue:";
        cout << "\n 2. DeQueue:";
        cout << "\n 3. Xuat Queue:";
        cout << "\n 4. IsEmpty:";
        cout << "\n 5. Count Elements:";
        cout << "\n 6. Delete Queue:";
        cout << "\n ================================";
        cout << "\n Lua chon cua ban: ";

        cout << "\nNhap lua chon: ";
        cin >> luachon;
        if (luachon == 1)
        {
            for (int i = 0; i < n; i++)
            {
                int x;
                x = rand() % 100;
                Node *p = InitNode(x);
                EnQueue(q, p);
            }
            PrintQueue(q);
        }
        else if (luachon == 2)
        {
            DeQueue(q);
            PrintQueue(q);
        }
        else if (luachon == 3)
        {
            PrintQueue(q);
        }
        else if(luachon == 4)
        {
            cout << "\nKiem tra queue empty: " << IsEmpty(q);
        }
        else if(luachon == 5)
        {
            cout << "\nKich thuoc queue: " << SizeOfQueue(q);
        }
        else if(luachon == 6)
        {
            DeleteQueue(q);
        }
        else
        {
            break;
        }
    }
}



int main()
{
    Queue q;
    InitQueue(q);

    NhapQueue(q);
    //PrintQueue(q);

    cout << "\nEnter any key to finish program!!!\n";
    getchar();
    return 0;
}