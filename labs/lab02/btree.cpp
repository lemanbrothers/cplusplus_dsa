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
            if (x < t->data)
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

int TimKiemX(Tree t, int x)
{
    if (t == NULL)
        return 0;
 
	if (t->data == x)
	{
		return 1;
	}
	if (t->data > x)
	{
		TimKiemX(t->pLeft, x);
	}
	else
	{
		TimKiemX(t->pRight, x);
	}
    return 0;
}


int InsertNode(Tree &t, int x)
{
    if (t != NULL)
    {
        if (x == t->data)
            return 0;
        else
        {
            if (x < t->data)
                InsertNode(t->pLeft, x);
            else
                InsertNode(t->pRight, x);
        }
    }
    else
    {
        t = new TNode;
        if (t == NULL)
            return -1;
        t->data = x;
        t->pLeft = t->pRight = NULL;
        return 1;
    }
    return 0;
}

void SearchStandFor(Tree &pHuy, Tree &pTM)
{
    if (pTM->pLeft != NULL)
        SearchStandFor(pHuy, pTM->pLeft);
    else
    {
        pHuy->data = pTM->data;
        pHuy = pTM;
        pTM = pTM->pRight;
    }
    delete pHuy;
}

void Remove(Tree &t, int x)
{
    if (t != NULL)
    {
        if (x < t->data)
            Remove(t->pLeft, x);
        else if (x > t->data)
            Remove(t->pRight, x);
        else
        {
            TNode *pHuy = t;
            if (t->pLeft == NULL)
                t = t->pRight;
            else if (t->pRight == NULL)
                t = t->pLeft;
            else
                SearchStandFor(pHuy, t->pRight);
        }
    }
}

int DemNode(Tree t)
{
    int c = 1;
    if (t == NULL)
        return 0;
    else
    {
        c += DemNode(t->pLeft);
        c += DemNode(t->pRight);
        return c;
    }
}

int DemNode2CayCon(Tree t)
{
    if (t != NULL)
    {
        int a = DemNode2CayCon(t->pLeft);
        int b = DemNode2CayCon(t->pRight);
        if (t->pLeft != NULL && t->pRight != NULL)
            return 1 + a + b;
        return a + b;
    }
    return 0;
}

char IsLeaf(TNODE *p)
{
    return (p->pLeft == NULL) && (p->pRight == NULL);
}

int DemLa(Tree t)
{
    if (t == NULL)
        return 0;
    else if (IsLeaf(t))
        return 1;
    else
        return DemLa(t->pLeft) + DemLa(t->pRight);
}

int ChieuCao(Tree t)
{
    if (t != NULL)
    {
        int a = ChieuCao(t->pLeft);
        int b = ChieuCao(t->pRight);
        int max = (a > b) ? a : b;
        return 1 + max;
    }
    return 0;
}

void InNodeChan(Tree t)
{
    if (t != NULL)
    {
        if (t->pLeft != NULL)
            InNodeChan(t->pLeft);
        if (t->data % 2 == 0)
            cout << t->data;
        if (t->pRight != NULL)
            InNodeChan(t->pRight);
    }
}

void InRaNodeLonHonX(Tree t, int x)
{
    if (t != NULL)
    {
        if (t->pLeft != NULL)
            InRaNodeLonHonX(t->pLeft, x);
        if (t->data > x)
            cout << t->data;
        if (t->pRight != NULL)
            InRaNodeLonHonX(t->pRight, x);
    }
}

int FindMaxNode(Tree t)
{
    if (t->pRight == NULL)
        return t->data;
    else
        return FindMaxNode(t->pRight);
}

int DemNode1Con(Tree t)
{
    if (t != NULL)
    {
        int a = DemNode1Con(t->pLeft);
        int b = DemNode1Con(t->pRight);
        if ((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft == NULL && t->pRight != NULL))
            return 1 + a + b;
        return a + b;
    }
    return 0;
}

int DemNode1ConPhai(Tree t)
{
    if (t != NULL)
    {
        int b = DemNode1ConPhai(t->pRight);
        if (t->pLeft == NULL && t->pRight != NULL)
            return 1 + b;
        return b;
    }
    return 0;
}

int DemNode2Con(Tree t)
{
    if (t != NULL)
    {
        int a = DemNode2Con(t->pLeft);
        int b = DemNode2Con(t->pRight);
        if (t->pLeft != NULL && t->pRight != NULL)
            return 1 + a + b;
        return a + b;
    }
    return 0;
}

void XuatNodeInK(Tree t, int k)
{
    if (t != NULL)
    {
        k--;
        if (t->pLeft != NULL)
            XuatNodeInK(t->pLeft, k);
        if (k == 0)
            cout << t->data;
        if (t->pRight != NULL)
            XuatNodeInK(t->pRight, k);
    }
}

int TinhKhoangCach(Tree t, int x)
{
    if (t == NULL)
        return -1;

    int dist = -1;
    if ((t->data == x) ||
        (dist = TinhKhoangCach(t->pLeft, x)) >= 0 ||
        (dist = TinhKhoangCach(t->pRight, x)) >= 0)
        return dist + 1;

    return dist;
}

int menu()
{
    int choice;
    cout << "\n ================================";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n 0. Thoat chuong trinh";
    cout << "\n 1. Nhập vào cây nhị phân từ bàn phím: LNR, LRN, NLR, NRL, RNL, RLN.";
    cout << "\n 2. Tìm một nút có khoá bằng X trên cây.";
    cout << "\n 3. Xoá 1 nút có khoá bằng X trên cây.";
    cout << "\n 4. Đếm số nút trong cây.";
    cout << "\n 5. Đếm số nút có đầy đủ 2 cây con.";
    cout << "\n 6. Đến số nút lá.";
    cout << "\n 7. Tính chiều cao của cây.";
    cout << "\n 8. In ra các node có giá trị chẵn.";
    cout << "\n 9. In ra các node có giá trị lớn hơn x.";
    cout << "\n 10. Tìm node có giá trị lớn nhất.";
    cout << "\n 11. Tìm node có giá trị nhỏ nhất của cây con phải.";
    cout << "\n 12. Đếm số node có 1 cây con (node bậc 1).";
    cout << "\n 13. Đếm số node chỉ có 1 cây con phải.";
    cout << "\n 14. Đếm số node 2 cây con (node bậc 2).";
    cout << "\n 15. In các node trên từng mức của cây.";
    cout << "\n 16. Cho biết độ dài đường đi từ gốc đến node có giá trị X nhập vào từ bàn phím.";
    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> choice;
    return choice;
}

void nhap(int &n)
{
    do
    {
        cout << "\n Nhap so luong phan tu cua cay: ";
        cin >> n;
    } while (n <= 0);
}

int main()
{
    Tree t;
    CreateTree(t);
    int n;
    nhap(n);
    int choice, x;
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
            for (int i = 0; i < n; i++)
            {
                cout << "\nNhap node: ";
                cin >> x;
                AddToTree(t, x);
            }
            NLR(t);
            break;

        case 2:
            cout << "\nNhap x:";
            cin >> x;
            cout << "\nKet qua tim kiem: " << TimKiemX(t, x);
            break;

        case 3:
            cout << "\nNhap x:";
            cin >> x;
            Remove(t, x);
            NLR(t);
            break;

        case 4:
            cout << DemNode(t);
            break;

        case 5:
            cout << DemNode2CayCon(t);
            break;

        case 6:
            cout << DemLa(t);
            break;

        case 7:
            cout << ChieuCao(t);
            break;

        case 8:
            InNodeChan(t);
            break;

        case 9:
            cout << "\nNhap x:";
            cin >> x;
            InRaNodeLonHonX(t, x);
            break;

        case 10:
            cout << FindMaxNode(t);
            break;

        case 11:
            cout << FindMaxNode(t);
            break;

        case 12:
            cout << DemNode1Con(t);
            break;

        case 13:
            cout << DemNode1ConPhai(t);
            break;
        
        case 14: 
            cout << DemNode2CayCon(t);
            break;
        
        case 15:
            int k;
            cout << "\nNhap k: ";
            XuatNodeInK(t, k);
            break;
        
        case 16:
            cout << "\nNhap x: ";
            cin >> x;
            cout << TinhKhoangCach(t, x);
        default:
            cout << "Lua chon khong dung!!!.Xin long nhap lai: ";
            cin >> choice;
            break;
        }
    }

    cout << "\nPress ENTER to finish program!!!\n";
    getchar();
    return 0;
}