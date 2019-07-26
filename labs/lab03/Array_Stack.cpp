#include <iostream>
using namespace std;
#define MAX 100

// Cau truc stack
struct Stack
{
    int arr[MAX];
    int t;
};

// Khoi tao stack
void CreateStack(Stack &s)
{
    s.t = 1;
}

// Kiem tra stack rong
int IsEmpty(Stack s)
{
    if(s.t == 0)
    {
        return 1;
    }
    return 0;
}

// Kiem tra stack full
int IsFull(Stack s)
{
    if(s.t >= MAX)
    {
        return 1;
    }
    return 0;
}

// Them phan tu vao stack
int Push(Stack &s, int x)
{
    if(!IsFull(s))
    {
        s.t++;
        s.arr[s.t] = x;
        return 1;
    }
    return 0;
}

// Lay 1 phan tu tu stack
int Pop(Stack &s, int &x)
{
    if(!IsEmpty(s))
    {
        x = s.arr[s.t];
        s.t--;
        return 1;
    }
    return 0;
}

void XuatStack(Stack s)
{
    while (s.t >= 0)
    {
        cout << s.arr[s.t] << " ";
        s.t--;
    }
    cout << endl;
}

int main(){

    Stack s;
    int x, tv, i;
    CreateStack(s);
    for(i = 0; i <= 5; i++){
        Push(s, i);
    }
    tv = Pop(s, x);
    if(tv == 1)
    {
        cout << "\nGia tri lay duoc tu stack: " << x;
    }
    XuatStack(s);
    
    cout << endl;
    cout << "\nPress any key to finish!!!";
    getchar();
    return 0;
}
