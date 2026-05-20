#include <iostream>
using namespace std;

void swap(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {

    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j < high; j++) {

        if(arr[j] < pivot) {

            i++;

            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high) {

    if(low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);

        quickSort(arr, pi + 1, high);
    }
}

int main() {

    int n;

    cout << "Enter number of students: ";
    cin >> n;

    int credits[n];

    cout << "Enter student credits:\n";

    for(int i = 0; i < n; i++) {

        cin >> credits[i];
    }

    quickSort(credits, 0, n - 1);

    cout << "\nSorted Credits:\n";

    for(int i = 0; i < n; i++) {

        cout << credits[i] << " ";
    }

    return 0;
}