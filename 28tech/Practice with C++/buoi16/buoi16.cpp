#include<bits/stdc++.h>
#include<climits>
using namespace std;
using ll = long long;
/*Kiểm tra xem mảng cho trước có tăng dần hay không, mảng tăng dần được
định nghĩa là mảng có phần tử đứng sau lớn hơn phần tử đứng trước nó. Nếu mảng
tăng dần in ra YES, trường hợp ngược lại in ra NO.
Input
Dòng đầu tiên là số lượng phần tử trong mảng n. (1≤n≤106).
Dòng thứ 2 là các phần tử ai trong mảng . (-109≤ai≤109).
Output
In YES nếu mảng tăng dần. NO trong trường hợp ngược lại.
Ví dụ
Input Output
5
1 2 2 3 5 NO*/
void bai2Increasing(int n, int a[]){
    bool isIncreasing = false;

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] < a[i + 1]) {
            isIncreasing = true;
            break;
        }
    }
    if (isIncreasing) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

void bai2Decreasing(int n, int a[]){
    bool isDecreasing = false;
    for(int i = 0; i < n - 1; i++){
        if(a[i] > a[i + 1]){
            isDecreasing = true;
            break;
        }
    }
    if(isDecreasing) cout << "YES" << endl;
    else cout << "NO" << endl; 
}

/*Cho một dãy số nguyên dương có n phần tử. Hãy liệt kê số các phần tử trong dãy không
nhỏ hơn các số đứng trước nó (tính cả phần tử đầu tiên).
Input
Dòng đầu tiên là số lượng phần tử trong mảng n. (1≤n≤106).
Dòng thứ 2 là các phần tử ai trong mảng . (-109≤ai≤109).
Output
Kết quả của bài toán.   */
void bai3(int n, int a[]){
    int maxSoFar = a[0];
    for(int i = 0 ; i < n; i++){
        if(a[i] >= maxSoFar)
            cout << a[i] << " ";
            maxSoFar = a[i];
    }
    cout << endl;
}

/*Tất cả các thành phố của Lineland đều nằm trên trục tọa độ Ox. Do đó, mỗi
thành
phố được liên kết với vị trí xi - tọa độ trên trục Ox. Không có hai thành phố được
đặt tại một điểm.
Cư dân Lineland thích gửi thư cho nhau. Một người chỉ có thể gửi thư nếu người
nhận sống ở một thành phố khác.
Chi phí gửi thư chính xác bằng khoảng cách giữa thành phố của người gửi và thành
phố của người nhận.
Đối với mỗi thành phố, hãy tính hai giá trị mini và maxi, trong đó mini là chi phí tối
thiểu để gửi thư từ thành phố thứ i đến một thành phố khác và maxi là chi phí tối đa
để gửi thư từ thành phố thứ i đến một số thành phố khác
Input
Dòng đầu tiên của đầu vào chứa số nguyên n (2<= n ≤ 10^5) - số lượng thành phố
trong Lineland. Dòng thứ hai chứa chuỗi n số nguyên khác nhau x1, x2, ..., xn (-
10^9<= xi <=10^9), trong đó xi là tọa độ x của thành phố thứ i. Tất cả các xi là
khác biệt và theo thứ tự tăng dần.
Output
In n dòng, dòng thứ i phải chứa hai số nguyên mini, maxi, cách nhau bởi một
khoảng trắng, trong đó mini là chi phí tối thiểu để gửi thư từ thành phố thứ i và
maxi là chi phí tối đa để gửi thư từ thành phố thứ i.*/
void bai4(int n, int a[]){
    for(int i = 0; i < n; i++){
        if(i == 0){
            int mini = abs(a[0] - a[1]);
            int maxi = abs(a[0] - a[n - 1]);
        cout << mini << " " << maxi << endl;
        } else if(i == n - 1){
            int mini = abs(a[n - 1] - a[n - 2]);
            int maxi = abs(a[n - 1] - a[0]);
            cout << mini << " " << maxi << endl;
        } else {
            int mini = min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1]));
            int maxi = max(abs(a[i] - a[0]), abs(a[i] - a[n - 1]));
            cout << mini << " " << maxi << endl;
        }
    }   
}

/*Bộ phim "Die Hard" mới vừa được phát hành! Có n người tại phòng vé rạp chiếu
phim đứng thành một hàng lớn. Mỗi người trong số họ có một hóa đơn 100, 50
hoặc 25 rúp. Một vé "Die Hard" có giá 25 rúp. Nhân viên đặt phòng có thể bán vé
cho mỗi người và trả tiền thừa nếu ban đầu anh ta không có tiền và bán vé theo
đúng thứ tự mọi người trong hàng không?
Input
Dòng đầu tiên chứa số nguyên n (1 <= n<= 10^5) - số người trong hàng. Dòng tiếp
theo chứa n số nguyên, mỗi số bằng 25, 50 hoặc 100 - giá trị của các hóa đơn mà
mọi người có.
Output
In "YES" (không có dấu ngoặc kép) nếu nhân viên đặt phòng có thể bán vé cho mỗi
người và có thể trả tiền thừa. Nếu không thì in "NO".
Ví dụ
Input
8
4
25 25 50 50
Output
YES */
void bai5(int n, int a[]){
    int cnt25 = 0, cnt50 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 25) {
            cnt25++;
        } else if (a[i] == 50) {
            if (cnt25 >= 1) {
                cnt25--;
                cnt50++;
            } else {
                cout << "NO" << endl;
                return;
            }
        } else if (a[i] == 100) {
            if (cnt50 >= 1 && cnt25 >= 1) {
                cnt50--;
                cnt25--;
            } else if (cnt25 >= 3) {
                cnt25 -= 3;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

/*Cho một dãy số nguyên dương có n phần tử. Hãy đếm các cặp số nguyên tố cùng nhau
trong mảng.
Input
Dòng đầu tiên là số lượng phần tử trong mảng n. (1≤n≤106).
Dòng thứ 2 là các phần tử ai trong mảng . (1≤ai≤109).
Output
Kết quả của bài toán.*/

int gcd(int a, int b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

/*
void bai6(int n, int a[]){
    long long count = 0; // Use long long for large numbers
    vector<int> primes = {1}; // Start with an array of size at least 2 (all numbers are coprime to 1)
    for (int i = 0; i < n; ++i) {
        int gcdValue;

        // Check if the current number can be added as a new unique prime
        bool isNewPrime = true;
        for (int j = 0; j < primes.size(); ++j) {
            gcdValue = gcd(primes[j], a[i]);

            if (gcdValue == 1) { // They are coprime, increment count
                count += primes[j];
            }

            if (a[i] % primes[j] == 0) {
                isNewPrime = false; // It's not prime with respect to existing ones
                break;
            }
        }

        if (isNewPrime) {
    cout << count << endl;
}                               */

void bai6Map(int n, int a[]){
    map<int, long long> freq;
    for(int i = 0; i < n; ++i)
        freq[a[i]]++;
    long long result = 0;
    vector<int> keys;
    for(const auto &pair : freq){
        keys.push_back(pair.first);
    }

    for(size_t i = 0; i < keys.size(); ++i) {
        int x = keys[i];
        for (size_t j = i + 1; j < keys.size(); ++j) {
            int y = keys[j];
            if(gcd(x, y) == 1){
                result += freq[x] * freq[y];
            }
        }
    }
    cout << result << endl;
}

/*Cho một dãy số nguyên có n phần tử. Tìm tích lớn nhất của 2 số trong mảng.
Input
Dòng đầu tiên là số lượng phần tử trong mảng n. (1≤n≤106).
Dòng thứ 2 là các phần tử ai trong mảng . (-109≤ai≤109).
Output
Kết quả của bài toán.   */
void bai7MaxAndMinProduct(int n, int a[]){
    ll max1 = LLONG_MIN, max2 = LLONG_MIN;
    ll min1 = LLONG_MAX, min2 = LLONG_MAX;
    for(int i = 0; i < n; i++){
        if(a[i] > max1){
            max2 = max1;
            max1 = a[i];
        }
        else if(a[i] > max2){
            max2 = a[i];
        }
        if(a[i] < min1){
            min2 = min1;
            min1 = a[i];
        }
        else if(a[i] < min2){
            min2 = a[i];
        }
    }
    long long max_product = max(max1 * max2, min1 * min2);
    long long min_product = min(max1 * max2, min1 * min2);
    cout << max_product << " " << min_product << endl;
}

/*Cho một dãy số nguyên có n phần tử. Tìm dãy con liên tiếp có các phần tử liền kề khác
nhau có độ dài lớn nhất.
Input
Dòng đầu tiên là số lượng phần tử trong mảng n. (1≤n≤106).
Dòng thứ 2 là các phần tử ai trong mảng . (-109≤ai≤109).
Output
Kết quả của bài toán.   */
void bai8(int n, int a[]){        
    int maxDiffLen = 1, currDiffLen = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            currDiffLen++;
            maxDiffLen = max(maxDiffLen, currDiffLen);
        } else {
            currDiffLen = 1;
        }
    }
    cout << maxDiffLen << endl;

    // Phần 2: dãy con liên tiếp có phần tử liền kề GIỐNG nhau
    int maxSameLen = 1, currSameLen = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            currSameLen++;
            maxSameLen = max(maxSameLen, currSameLen);
        } else {
            currSameLen = 1;
        }
    }
    cout << maxSameLen << endl;

    // Tìm dãy con liên tiếp có 2 phần tử liền kề nhau trái dấu có độ dài lớn nhất.
    int maxDiffOpposite = 1, currentDiffOpposite = 1;
    for (int i = 1; i < n; ++i) {
        if(a[i] * a[i - 1] < 0){
            currentDiffOpposite++;
            maxDiffOpposite = max(maxDiffOpposite, currentDiffOpposite);
        } else {
            currentDiffOpposite = 1;
        }
    }
    cout << maxDiffOpposite << endl;

    //Tìm dãy con tăng liên tiếp có độ dài dài nhất.
    int maxIncreasing = 1; int currIncresing = 1;
    for(int i = 1; i < n ; i++){
        if(a[i] > a[i - 1]){
            currIncresing++;
            maxIncreasing = max(maxIncreasing, currIncresing);
        }
        else currIncresing = 1;
    }
    cout << maxIncreasing << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n; int a[1000];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    //bai2Increasing(n, a);
    //bai2Decreasing(n, a);
    //bai3(n, a);
    //bai4(n, a);
    //bai5(n, a);
    //bai6Map(n, a);
    //bai7MaxAndMinProduct(n, a);
    bai8(n, a);
    return 0;
}