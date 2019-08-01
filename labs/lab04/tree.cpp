#include <iostream>
using namespace std;

struct TNode
{
    int data;
    TNode *pLeft, *pRight;
};

typedef TNode TNODE;

TNODE *CreateNode(int x)
{
    TNODE *p = new TNODE();
    p->data = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

typedef TNODE *Tree;

void CreateTree(Tree &t)
{
    t = NULL;
}

void AddToTree(Tree &t, int x)
{
    if (t != NULL)
    {
        if (t->data == x)
        {
            cout << "\nCay da co gia tri nay!!!";
            return;
        }
        else
        {
            if (t->data < x)
            {
                AddToTree(t->pLeft, x);
            }
            else
            {
                AddToTree(t->pRight, x);
            }
        }
    }
    else
    {
        t = CreateNode(x);
    }
}

void NLR(Tree t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}

void LRN(Tree t)
{
    if(t != NULL)
    {
        LRN(t->pLeft);
        LRN(t->pRight);
        cout << t->data << " ";
    }
}

int main()
{
    Tree t;
    CreateTree(t);
    int n;
    cout << "\nNhap so node cua cay: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "\nNhap node: ";
        cin >> x;
        AddToTree(t, x);
    }
    NLR(t);
    cout << endl;
    LRN(t);

    cout << "\nPress ENTER to finish program!!!\n";
    getchar();
    return 0;
}