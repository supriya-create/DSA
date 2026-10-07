#include <iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;
        while(index>1){
            int parent =index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }
    //TC = O(log n)

    void deletefromheap(){
        if(size==0){
            cout<<"Nothing to delete";
        }
        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i<size){
            int leftindex = 2*i;
            int rightindex = 2*i+1;

            if(leftindex<size && arr[i]<arr[leftindex]){
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }else if(rightindex<size && arr[i]<arr[rightindex]){
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

    int main(){
        heap h;
        h.insert(50);
        h.insert(20);
        h.insert(30);
        h.insert(25);
        h.insert(10);
        h.print();

        h.deletefromheap();

        h.print();
        return 0;
    }

