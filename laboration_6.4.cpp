#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void inputArray(vector<double>& arr) {
    int n;
    cout << "Input size of array: ";
    cin >> n;
    arr.resize(n);

    cout << "Input elem of array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void printArray(const vector<double>& arr) {
    cout << "Start array: ";
    for (double element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

int countElementsInRange(const vector<double>& arr, double A, double B) {
    int countInRange = 0;
    for (double element : arr) {
        if (element >= A && element <= B) {
            countInRange++;
        }
    }
    return countInRange;
}


double findMaxElement(const vector<double>& arr) {
    return *max_element(arr.begin(), arr.end());
}


double sumAfterMax(const vector<double>& arr) {
    double maxElement = findMaxElement(arr);
    double sum = 0;
    bool foundMax = false;

    for (double element : arr) {
        if (foundMax) {
            sum += element;
        }
        if (element == maxElement) {
            foundMax = true;
        }
    }
    return sum;
}

vector<int> sortEvenElementsByAbsoluteValue(const vector<double>& arr) {
    vector<int> indices;
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            indices.push_back(i);
        }
    }
    sort(indices.begin(), indices.end(), [&arr](int i, int j) {
        return abs(arr[i]) > abs(arr[j]);
        });
    return indices;
}

int main() {
    vector<double> arr;
    inputArray(arr);

    printArray(arr);

    double A, B;
    cout << "Input diapazon [A, B]:" << endl;
    cout << "A: "; cin >> A;
    cout << "B: "; cin >> B;

    int count = countElementsInRange(arr, A, B);
    cout << "Count elem in diapazon [" << A << ", " << B << "]: " << count << endl;

    double maxElement = findMaxElement(arr);
    double sum = sumAfterMax(arr);
    cout << "Sum elem after max elem: " << sum << endl;

    vector<int> sortedIndices = sortEvenElementsByAbsoluteValue(arr);

    int j = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            cout << arr[sortedIndices[j++]] << " ";
        }
        else {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
