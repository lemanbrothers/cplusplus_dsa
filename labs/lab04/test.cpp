#include<iostream>
using namespace std;
//// tạo 1 node 
struct node
{
	int data;
	struct node *pleft;
	struct node *pright;
};
typedef node* tree;
/// khởi tạo tree 
void init(tree &t)
{
	t = NULL;
}
// them node 
void insert(tree &t, int x)
{
	if (t == NULL)// nếu cây rỗng thì ....
	{
		node *p = new node;
		p->data = x;
		p->pleft = p->pright = NULL;
		t = p;
	}
	else
	{
		if (t->data > x)
		{
			insert(t->pleft, x);
		}
		else if (t->data < x)
		{
			insert(t->pright, x);
		}
	}
}
// tạo cây 
void createtree(tree &t)
{
	int chon;
	init(t);// khởi tạo cây
	do {
		cout << "\n1.Nhap du lieu cho cay!";
		cout << "\n2.Thoat";
		cout << "\nNhap lua chon!"; cin >> chon;
		if (chon == 1)
		{
			int x;
			cout << "\nNhap x: "; cin >> x;
			insert(t, x);// thêm giá trị x vào cây
		}
	} while (chon != 0);
}

void nlr(tree t)
{
	if (t != NULL)
	{
		cout << t->data << "    ";
		nlr(t->pleft);
		nlr(t->pright);
	}
}
// tìm node 
node* search(tree t, int x)// trả về 1 node  có thể trả về tre false cũng dk
{
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		if (t->data > x)
		{
			search(t->pleft, x);
		}
		else if (t->data < x)
		{
			search(t->pright, x);
		}
		else
		{
			return t;
		}
	}
}

void timphantuthemangtrainhatcayconphai(tree &p, tree &q)
{
	if (q->pleft != NULL)
	{
		timphantuthemangtrainhatcayconphai(p, q->pleft);
	}
	else
	{
		p->data = q->data;
		p = q;
		q=q->pright;
	}
}

// xóa 1 node là lá 
void timphantuthemangphainhatcaycontrai(tree &p, tree &q)
{
	if (q->pright != NULL)
	{
		timphantuthemangphainhatcaycontrai(p, q->pright);
	}
	else
	{
		p->data = q->data;
		p = q;
		q = q->pleft;
	}



}
void xoanode(tree &t, int x)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (t->data > x)
		{
			xoanode(t->pleft, x);
		}
		else if(t->data<x)
		{
			xoanode(t->pright, x);
		}
		else
		{
			node *p = t;
			if (t->pleft == NULL)
			{
				t = t->pright;
			}
			else if(t->pright==NULL)
			{
				t = t->pleft;
			}
			else
			{

				// cách 1 tìm phần tử trái nhất cây con phải 
				//timphantuthemangtrainhatcayconphai(p, t->pright);
				//cách 2 tìm pahn62 tử thế mạng phải nhất cây con trái
				timphantuthemangphainhatcaycontrai(p, t->pleft);
			}

			delete p;
       }
   }

}

////////////////Thêm 1 phần tử 
void them(tree &t, int x)
{
	if (t == NULL)
	{
		node *p = new node;
		p->data = x;
		p->pleft = p->pright=NULL;
		t = p;
	}
	else
	{
		if (t->data > x)
		{
			them(t->pleft, x);
		}
		else if(t->data<x)
		{
			them(t->pright, x);
		}
		else
		{
			node *l = new node;
			if (t->pleft == NULL)
			{
				t->data = x;
				t = t->pright;
				
			}
			else if(t->pright==NULL)
			{
				t->data = x;
				t = t->pleft;
			}
			

		}
	}

}




int main()
{
	tree t;
	createtree(t);
	cout << "\nDuyet theo nlr: \n";
	nlr(t);
	int x;
	cout << "\nNhap node can tim : "; cin >> x;
	node *u = search(t, x);
	if (u == NULL)
	{
		cout << "\nKhong tim thay node xin kiem tra lai!";
	}
	else
	{
		cout << "\nNo de ban can tim co trong cay cam on!";
	}
int g;
	cout << "\nNhap phan tu ban muon xoa!"; cin >> g;
	xoanode(t, g);
	cout << "\nCay sau khi xoa!\n";
	nlr(t);


d: int h;
	cout << "\nNhap phan tu ban them!"; cin >> h;
	them(t, h);
	cout << "\nCay sau khi them!\n";
	nlr(t);
    getchar();
	return 0;
}