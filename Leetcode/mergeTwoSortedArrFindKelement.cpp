#include <iostream>
#include <vector>
using namespace std;

int findKthElement(vector<int>& a, vector<int>& b, int k) {
    int i = 0, j = 0, count = 0;
    int n1 = a.size(), n2 = b.size();
    int kthElement = -1;

    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            kthElement = a[i];
            i++;
        } else {
            kthElement = b[j];
            j++;
        }
        count++;
        if (count == k) return kthElement;
    }

    while (i < n1) {
        kthElement = a[i];
        i++;
        count++;
        if (count == k) return kthElement;
    }

    while (j < n2) {
        kthElement = b[j];
        j++;
        count++;
        if (count == k) return kthElement;
    }

    return -1; 
}

int main() {
    vector<int> a = {2, 3, 6, 8};
    vector<int> b = {1, 4, 5, 7, 9, 10};
    int k = 5;

    int result = findKthElement(a, b, k);
    if (result != -1)
        cout << "The " << k << "-th element in the merged array is: " << result << endl;
    else
        cout << "Invalid k" << endl;

    return 0;
}
