#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
//https://bigocoder.com/courses/252/lectures/3825/problems/1071?view=statement
struct Job {
    int a, b, d;
};

bool wayToSort(const Job &x, const Job &y) {
    return x.d < y.d;
}

int main() {
    int t, N;
    cin >> t;

    while (t--) {
        cin >> N;
        Job job[MAX];
        for (int i = 0; i < N; i++) {
            cin >> job[i].a >> job[i].b >> job[i].d;
        }

        auto cmp = [](const Job &x, const Job &y) { return x.a < y.a; };
        priority_queue<Job, vector<Job>, decltype(cmp)> pq(cmp);

        sort(job, job + N, wayToSort);
        double money = 0;
        int time = 0;

        for (int i = 0; i < N; i++) {
            time += job[i].b;
            pq.push(job[i]);
            
            while (time > job[i].d) {
                Job top = pq.top();
                pq.pop();

                if (top.b > time - job[i].d) {
                    money += (time - job[i].d) * 1.0 / top.a;
                    top.b -= time - job[i].d;
                    pq.push(top);
                    time = job[i].d;
                }
                else {
                    money += top.b * 1.0 / top.a;
                    time -= top.b;
                    top.b = 0;
                }
            }
        }

        cout << fixed << setprecision(2) << money << endl;
        
        while (!pq.empty()) {
            pq.pop();
        }
    }
    return 0;
}