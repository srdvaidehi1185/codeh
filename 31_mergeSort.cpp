#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {

    int n1 = mid - left + 1;

    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2) {

        if(L[i] <= R[j]) {

            arr[k] = L[i];
            i++;
        }

        else {

            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while(i < n1) {

        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {

        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {

    if(left < right) {

        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);

        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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

    mergeSort(credits, 0, n - 1);

    cout << "\nSorted Credits in Ascending Order:\n";

    for(int i = 0; i < n; i++) {

        cout << credits[i] << " ";
    }

    return 0;
}