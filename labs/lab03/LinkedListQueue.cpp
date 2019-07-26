#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *pNext;
};

Node *InitNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->pNext = NULL;
    return p;
}

struct Queue
{
    Node *pHead, *pTail;
};

void InitQueue(Queue &q)
{
    q.pHead = NULL;
    q.pTail = NULL;
}


int IsEmpty(Queue q)
{
    if(q.pHead == NULL)
    {
        return 1;
    }
    return 0;
}

void XuatQueue(Queue q)
{
    // for(Node *p = q.pHead; p != NULL; p = p->pNext)
    // {
    //     cout << p->data << " ";
    // }
    // cout << endl;
    while (IsEmpty(q) == 0)
    {
        
    }
    
}

void Enqueue(Queue &q, int x)
{
    InitQueue(q);
    Node *p = InitNode(x);
    if(IsEmpty(q) == 1)
    {
        q.pHead = q.pTail = p;
    }
    else
    {
        q.pTail->pNext = p;
        q.pTail = p;
    }
}

void Dequeue(Queue &q)
{
    if(IsEmpty(q) == 1)
    {
        cout << "\nQueue rong!!!";
    }
    else
    {
        Node *p = q.pHead;
        q.pHead = q.pHead->pNext;
        delete p;
    }
}

int CountElements(Queue q)
{
    int count = 0;
    for(Node *p = q.pHead; p != NULL; p = p->pNext)
    {
        count++;
    }
    return count;
}

void DeleteAll(Queue &q)
{
    for(Node *p = q.pHead; p != NULL; p = p->pNext)
    {
        Dequeue(q);
    }
}


int menu()
{
    int choice;
    cout << "\n ================================";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n 0. Thoat chuong trinh";
    cout << "\n 1. Enqueue:";
    cout << "\n 2. Dequeue:";
    cout << "\n 3. IsEmpty:";
    cout << "\n 4. Count Elements:";
    cout << "\n 5. Delete all:";
    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> choice;
    return choice;
}

void nhap(int &n)
{
    do
    {
        cout << "\n Nhap so luong phan tu cua queue: ";
        cin >> n;
    } while (n <= 0);
}

int main()
{
    int n, choice, x;
    Queue q;
    //InitQueue(q);
    XuatQueue(q);
    cout << "\nNhap x: ";
    cin >> x;
    Enqueue(q, x);
    XuatQueue(q);
    // bool flag = true;
    // nhap(n);
    // while (flag != false)
    // {
    //     choice = menu();
    //     switch (choice)
    //     {
    //     case 0:
    //         cout << "Bye bye.\n"; // Thoat chuong trinh
    //         flag = false;
    //         break;

    //     case 1:
    //         for (int i = 0; i < n; i++)
    //         {
    //             //Enqueue(q, rand() % 100);
    //         }
    //         Enqueue(q, 69);
    //         XuatQueue(q);
    //         break;

    //     case 2:
    //         Dequeue(q);
    //         XuatQueue(q);
    //         break;

    //     case 3:
    //         cout << IsEmpty(q);
    //         break;

    //     case 4:
    //         cout << "\nSo luong phan tu cua queue: " << CountElements(q);
    //         break;

    //     case 5:
    //         DeleteAll(q);
    //         XuatQueue(q);
    //         break;

    //     default:
    //         cout << "Lua chon khong dung!!!.Xin long nhap lai: ";
    //         cin >> choice;
    //         break;
    //     }
    // }


    cout << "\nEnter any key to finish program!!!\n";
    getchar();
    return 0;
}