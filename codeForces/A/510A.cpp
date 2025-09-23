#include <iostream>
#include <vector>
#include <stack>
#define MAX 55
using namespace std;

int n, m;
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

vector<int> graph[MAX];
vector<bool> visited[MAX];

struct Cell {
    int r, c;
};

bool isValid(int r, int c) {
    return r >= 0 && c >= 0 && r < n && c < m;
}

void DFS(Cell s) {
    stack<int> st;
    st.push(s);
}

int main() {

    return 0;
}