#include <iostream>
using namespace std;

const int MAX_SIZE = 1e5+1;

class MinHeap
{
    private:
        int *heap;
        int curSize;
        int capacity;

        int parent(int i) { return i/2; }
        int left(int i) { return 2*i; }
        int right (int i) { return 2*i+1; }

        void heapifyUp(int i)
        {
            while(i > 1 and heap[parent(i)] > heap[i])
            {
                swap(heap[parent(i)], heap[i]);
                i = parent(i);
            }
        }

        void heapifyDown(int i)
        {
            int l = left(i);
            int r = right(i);
            int smallest = i;

            if(l < curSize and heap[l] < heap[i])
            {
                smallest = l;
            }
            if(r < curSize and heap[r] < heap[smallest])
            {
                smallest = r;
            }

            if(smallest != i)
            {
                swap(heap[i], heap[smallest]);
                heapifyDown(smallest);
            }
        }
    public:
        MinHeap()
        {
            heap = new int[MAX_SIZE];
            capacity = MAX_SIZE;
            curSize = 1;
        }

        MinHeap(int *arr, int arrSz)
        {
            heap = new int[MAX_SIZE];
            capacity = MAX_SIZE;
            curSize = 1;

            for(int i = 0; i < arrSz; i++, curSize++)
            {
                heap[curSize] = arr[i];
            }

            for(int i = curSize/2; i >= 1; i--)
            {
                heapifyDown(i);
            }
        }
        
        void insert(int val)
        {
            if(curSize >= capacity) return;

            heap[curSize] = val;
            heapifyUp(curSize);
            curSize++;
        }

        int extractMin()
        {
            if(curSize <= 1) return -1e9+7;

            int val = heap[1];
            heap[1] = heap[curSize-1];
            curSize--;
            heapifyDown(1);

            return val;
        }

        int minimum()
        {
            if(curSize <= 1) return -1e9+7;
            return heap[1];
        }

        void decreaseKey(int p, int k)
        {
            heap[p]-= k;
            heapifyUp(p);
        }

        void increaseKey(int p, int k)
        {
            heap[p]+= k;
            heapifyDown(p);
        }

        void print()
        {
            for(int i = 1; i < curSize; i++)
            {
                cout << heap[i] << " ";
            }
            cout << endl;
        }
};

int main ()
{
    int arr[MAX_SIZE];

    int arrSz = 0, arrItem;
    while(true)
    {
        cin >> arrItem;
        if(arrItem == -1) break;
        arr[arrSz++] = arrItem;
    }

    MinHeap minhp(arr, arrSz);
    minhp.print();

    int funcId;
    while(cin >> funcId)
    {
        if(funcId == 1)
        {
            cout << minhp.minimum() << endl;
        }
        else if(funcId == 2)
        {
            cout << minhp.extractMin() << endl;
        }
        else if(funcId == 3)
        {
            int val;
            cin >> val;
            minhp.insert(val);
        }
        else if (funcId == 4)
        {
            int p, k;
            cin >> p >> k;
            minhp.decreaseKey(p, k);
        }
        else if(funcId == 5)
        {
            int p, k;
            cin >> p >> k;
            minhp.increaseKey(p, k);
        }

        minhp.print();
    }
    

    return 0;
}