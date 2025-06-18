#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<long long> largest(3, -1);
    for (int i = 0; i < N; i++) {
        if (A[i] >= largest[0]) {
            largest[2] = largest[1];
            largest[1] = largest[0];
            largest[0] = A[i];
        } else if (A[i] >= largest[1]) {
            largest[2] = largest[1];
            largest[1] = A[i];
        } else if (A[i] >= largest[2]) {
            largest[2] = A[i];
        }
        if (i < 2) {
            cout << "-1" << endl;
        } else {
            cout << largest[0] * largest[1] * largest[2] << endl;
        }
    }

    return 0;
}


/*
We can use Heap-sort:

#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    priority_queue<long long> heap;
    
    for (int i = 0; i < N; i++) {
        heap.push(A[i]);
        
        if (i < 2) {
            cout << "-1" << endl;
        } else {
            long long first = heap.top(); heap.pop();
            long long second = heap.top(); heap.pop();
            long long third = heap.top(); heap.pop();
            cout << first * second * third << endl;
            
            heap.push(first);
            heap.push(second);
            heap.push(third);
        }
    }

    return 0;
}
*/