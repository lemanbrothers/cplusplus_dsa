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

struct Stack
{
    Node *pTop;
};

void InitStack(Stack &s)
{
    s.pTop = NULL;
}

int IsEmpty(Stack s)
{
    if (s.pTop == NULL)
    {
        return 1;
    }
    return 0;
}

int Push(Stack &s, int x)
{
    Node *p = InitNode(x);
    if (s.pTop == NULL)
    {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
    //delete p;
    return 1;
}

int Pop(Stack &s)
{
    if (IsEmpty(s) == 1)
    {
        return 0;
    }
    s.pTop = s.pTop->pNext;
    return 1;
}

int Top(Stack s)
{
    if (IsEmpty(s) == 1)
    {
        return 0;
    }
    return s.pTop->data;
}

void XuatStack(Stack s)
{
    if (IsEmpty(s) == 1)
    {
        cout << "\nStack rong!!!";
    }
    else
    {
        Node *temp = s.pTop;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->pNext;
        }
    }
    cout << endl;
}

int DemPhanTu(Stack s)
{
    int dem = 0;
    Node *temp = s.pTop;
    while (temp != NULL)
    {
        dem++;
        temp = temp->pNext;
    }
    return dem;
}

void DeleteAll(Stack &s)
{
    while (s.pTop != NULL)
    {
        Pop(s);
    }
}

int menu()
{
    int choice;
    cout << "\n ================================";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n 0. Thoat chuong trinh";
    cout << "\n 1. Push:";
    cout << "\n 2. Pop:";
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
        cout << "\n Nhap so luong phan tu cua stack: ";
        cin >> n;
    } while (n <= 0);
}

int main()
{
    int n, choice;
    Stack s;
    bool flag = true;
    nhap(n);
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
            for (int i = 0; i < n; i++)
            {
                Push(s, rand() % 100);
            }
            XuatStack(s);
            break;

        case 2:
            Pop(s);
            XuatStack(s);
            break;

        case 3:
            cout << IsEmpty(s);
            break;

        case 4:
            cout << "\nSo luong phan tu cua stack: " << DemPhanTu(s);
            break;

        case 5:
            DeleteAll(s);
            XuatStack(s);
            break;

        default:
            cout << "Lua chon khong dung!!!.Xin long nhap lai: ";
            cin >> choice;
            break;
        }
    }

    cout << "\nEnter any key to finish program!!!\n";
    getchar();
    return 0;
}