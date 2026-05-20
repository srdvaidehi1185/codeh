#include <iostream>
using namespace std;

void swap(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}

void minHeapify(int arr[], int n, int i) {

    int smallest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if(left < n &&
       arr[left] < arr[smallest])

        smallest = left;

    if(right < n &&
       arr[right] < arr[smallest])

        smallest = right;

    if(smallest != i) {

        swap(arr[i], arr[smallest]);

        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {

    for(int i = n/2 - 1; i >= 0; i--)

        minHeapify(arr, n, i);
}

int main() {

    int n;

    cout << "Enter number of students: ";
    cin >> n;

    int *heap = new int[n];

    cout << "Enter marks of students:\n";

    for(int i = 0; i < n; i++) {

        cin >> heap[i];
    }

    buildMinHeap(heap, n);

    cout << "\nMinimum Marks = "
         << heap[0] << endl;

    delete[] heap;

    return 0;
}