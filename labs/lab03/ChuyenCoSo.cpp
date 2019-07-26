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

void Push(Stack &s, int x)
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
}

// void Pop(Stack &s)
// {
//     if (IsEmpty(s) == 1)
//     {
//         cout << "\nStack rong!!!";
//     }
//     else
//     {
//         s.pTop = s.pTop->pNext;
//     }
// }

void PrintStack(Stack s)
{
    if (IsEmpty(s) == 1)
    {
        cout << "\nStack rong !!!";
    }
    else
    {
        Node *p = s.pTop;
        while (p != NULL)
        {
            if (p->data < 10)
            {
                cout << p->data;
            }
            else if (p->data == 10)
            {
                cout << "A";
            }
            else if (p->data == 11)
            {
                cout << "B";
            }

            else if (p->data == 12)
            {
                cout << "C";
            }

            else if (p->data == 13)
            {
                cout << "D";
            }

            else if (p->data == 14)
            {
                cout << "E";
            }

            else if (p->data == 15)
            {
                cout << "F";
            }

            p = p->pNext;
        }
    }
    cout << endl;
}

void ConvertBase(Stack &s, int number, int base)
{
    while (number != 0)
    {
        int x = number % base;
        Node *p = InitNode(x);
        Push(s, (x));
        number /= base;
    }
}

void NhapSoThapPhan(int &n)
{
    do
    {
        cout << "\nNhap vao so thap phan: ";
        cin >> n;
        if (n < 0)
        {
            cout << "\nSo thap phan >= 0. Xin nhap lai!!!";
        }
    } while (n < 0);
}

int menu()
{
    int choice;
    cout << "\n ================================";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n 0. Thoat chuong trinh!!!";
    cout << "\n 1. Chuyen sang nhi phan.";
    cout << "\n 2. Chuyen sang bat phan.";
    cout << "\n 3. Chuyen sang thap luc phan.";
    cout << "\n Lua chon cua ban: ";
    cin >> choice;
    return choice;
}

int main()
{
    Stack s;
    int num, choice;
    bool flag = true;
    while (flag != false)
    {
        choice = menu();
        switch (choice)
        {
        case 0: // Thoat chuong trinh
            cout << "Bye bye.\n";
            flag = false;
            break;

        case 1: // Chuyen doi nhi phan
            NhapSoThapPhan(num);
            InitStack(s);
            ConvertBase(s, num, 2);
            PrintStack(s);
            break;

        case 2: // Chuyen doi bat phan
            NhapSoThapPhan(num);
            InitStack(s);
            ConvertBase(s, num, 8);
            PrintStack(s);
            break;

        case 3: // Chuyen doi thap luc phan
            NhapSoThapPhan(num);
            InitStack(s);
            ConvertBase(s, num, 16);
            PrintStack(s);
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