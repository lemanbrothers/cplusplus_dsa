#include <iostream>
using namespace std;
#define MAX 100
struct Queue
{
    int arr[MAX];
    int Front;
    int Rear;
};

void CreateQueue(Queue &q)
{
    q.Front = -1;
    q.Rear = -1;
}

int DeQueue(Queue &q, int &x)
{
    if(q.Front != -1)
    {
        x = q.arr[q.Front];
        if(q.Front > q.Rear) // Queue chi co 1 phan tu
        {
            q.Front = -1;
            q.Rear = -1;
        }
        return 1;
    }
    cout << "\nQueue rong!";
    return 0;
}

int EnQueue(Queue &q, int x)
{
    int i, f, r;
    if(q.Rear - q.Front + 1 == MAX)
    {
        cout << "\nQueue day, Khong them duoc";
        return 0;
    }

    if(q.Front == -1)// Truong hop queue chua co phan tu nao
    {
        q.Front = 0;
        q.Rear = -1;
        if(q.Rear == MAX - 1)//Queue đầy ảo
        {
            f = q.Front;
            r = q.Rear;
            for(i = f; i <= r; i++)
            {
                q.arr[i - f] = q.arr[i];
            }
            q.Front = 0;
            q.Rear = r -f;
        }
        q.Rear++;
        q.arr[q.Rear] = x;
    
    }
    return 1;
}

int main()
{
    Queue q;
    int tv, i, x;
    CreateQueue(q);
    for(i = 2; i <= 5; i++)
    {
        EnQueue(q, i);
    }
    tv = DeQueue(q, x);
    if(tv == 1)
    {
        cout << "\nGia tri lay duoc tu queue:" << x;
    }
    cout << "\nEnter any key to finish!!!";
    getchar();
    return 0;
}