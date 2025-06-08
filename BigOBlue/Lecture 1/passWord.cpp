#include <iostream>
#include <vector>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3808/problems/1052?view=statement
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> lens(n);
    string pw;
    for (int i = 0; i < n; ++i) {
        cin >> pw;
        lens[i] = pw.length();
    }
    string correct_pw;
    cin >> correct_pw;
    int len_correct = correct_pw.length();

    int less = 0, equal = 0;
    for (int i = 0; i < n; ++i) {
        if (lens[i] < len_correct) less++;
        else if (lens[i] == len_correct) equal++;
    }

    int best = less;
    int worst = less + equal - 1;

    auto calc_time = [&](int attempts) {
        return attempts + 1 + (attempts / k) * 5;
    };

    cout << calc_time(best) << " " << calc_time(worst) << "\n";
    return 0;
}
