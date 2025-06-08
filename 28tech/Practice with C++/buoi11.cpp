#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*Nhập vào mảng số nguyên có n phần tử, tìm số lớn nhất và số lớn thứ 2
trong mảng vì in ra kết quả trên 2 dòng.
Input:
Dòng đầu là n (2<=n<=100) - số lượng phần tử của mảng
Dòng thứ 2 bao gồm n phần tử của mảng
Output:
Dòng đầu tiên : Giá trị của số lớn nhất.
Dòng thứ hai: Giá trị của số lớn thứ 2.
Ví dụ
Input
10
1 2 3 4 5 6 7 8 9 9
Ouput
9   */
void bai1(int a[100], int n){
    int max1_val = a[0];
    int max2_val = a[0];
    for(int i= 0 ; i < n ; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++){
        if(a[i] > max1_val){
            max2_val = max1_val;
            max1_val = a[i];
        }
        else if(a[i] > max2_val && a[i != max1_val]){
            max2_val = a[i];
        }
    }
    cout << max1_val << endl;
    if(max2_val != a[0])
        cout << max2_val << endl;
}

/*Nhập vào n số nguyên không âm, đếm số lượng số là số nguyên tố trong
dãy số vừa nhập.
Input:
Dòng đầu tiên là n (1<=n<=10000) - số lượng số nguyên trong dãy.
Dòng thứ 2 là n số nguyên trong dãy
Output:
Số lượng số nguyên tố trong dãy
Ví dụ
Input
10
1 2 3 4 5 6 7 8 9 11
Output
5   */

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void bai2(int n, int a[]){
    cin >> n;
    int count = 0;
    for(int i = 0; i < n ;i++){
        cin >> a[i];
        if(isPrime(a[i])){
            count++;
        }
    }
    cout << count << endl;
}

/*Nhập vào n số nguyên không âm, đếm và liệt kê các số thuận nghịch trong
dãy số vừa nhập, liệt kê theo thứ tự xuất hiện trong mảng.
Input:
Dòng đầu tiên là n (1<=n<=100000) - số lượng số trong dãy
Dòng thứ hai là n số trong dãy
Output:
Dòng đầu tiên là số lượng số thuận nghịch trong dãy
Dòng thứ 2 liệt kê các số thuận nghịch trong dãy
Ví dụ
Input
10
22 556 787 121 1 2 3 4 5 9899
Output
8
22 787 121 1 2 3 4 5    */

bool isPalindrome(int n) {
    int rev = 0, temp = n;
    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return rev == n;
}

void bai3(int n, int a[]){
    cin >> n; int count = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(isPalindrome(a[i])){
            cout << a[i] <<" ";
            count++;
        }
    }
    cout << endl;
    cout << count << endl;
}

/*Nhập một mảng gồm n số nguyên không âm, đếm số lượng chữ số chẵn, số
lẻ trong mảng.
Input:
Dòng đầu tiên là n (1<=n<=100000) - số lượng số trong dãy
Dòng thứ hai là n số trong dãy
Output:
Dòng đầu là số lượng chữ số chẵn trong mảng.
Dòng thứ hai là số lượng chữ số lẻ trong mảng.
Ví dụ
Input
6
1 98 13 24 76 8723
Ouput
3   */
void bai4(int n, int a[]){
    cin >> n; int countChan = 0; int countLe = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 2 == 0) countChan++;
        else countLe++;
    }
    cout << countChan << endl << countLe << endl;
}

/*Nhập vào mảng gồm n số nguyên, tính và in ra giá trị trung bình của các
phần tử trong mảng.
Input:
Dòng đầu tiên là n (1<=n<=100000) - số lượng số trong dãy
Dòng thứ hai là n số trong dãy
Ouput
Ví dụ
Giá trị trung bình của các số trong mảng
Input
4
1 2 3 4
Output
2.50    */
void bai5(int n, int a[]){
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    cout << setprecision(3) << (float)sum / n << endl;
}

/*Nhập vào mảng số nguyên không âm gồm n phần tử, đếm số lượng và liệt kê
các số chính phương trong mảng.
Input:
Dòng đầu tiên là n (1<=n<=100) - số lượng số trong dãy
Dòng thứ hai là n số trong dãy
Output:
Dòng đầu tiên là số lượng số chính phương trong mảng.
Dòng thứ 2 liệt ke các số chính phương trong mảng.
Ví dụ
Input
10
1 2 3 4 5 6 7 8 9 1000000000000
Output
4
2 4 9 1000000000000 */
bool isPerfectSquare(int n){
    int root = sqrt(n);
    return root * root == n;
}

void bai6(int n, int a[]){
    cin >> n;
    int count = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        count++;        
    }
    cout << count << endl;
    for(int i = 0; i < n; i++){
        if(isPerfectSquare(a[i])){
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

void bai7(int n, int a[], int x){
    cin >> n; int count = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> x;
    for(int i = 0; i < n;  i++){
        if(a[i] == x){
            count++;
        }
    }
    cout << count << endl;
}

/*Nhập vào một mảng gồm n số nguyên không âm và một số nguyên không
âm x, đếm số lượng số nguyên tố cùng nhau với x trong mảng và liệt kê các số đó.
Input:
Dòng đầu tiên là n (1<=n<=100000) - số lượng số trong dãy
Dòng thứ hai là n số trong dãy
Dòng thứ 3 là số nguyên x
Output
Dòng đầu tiên là số lượng số nguyên tố cùng nhau với x trong mảng.
Dòng thứ hai liệt kê các số nguyên tố cùng nhau với x.
Ví dụ
Input
10
46 2 3 4 5 6 7 8 9 10
23
Ouput
9
2 3 4 5 6 7 8 9 10  */

long long gcd(long long a, long b){
    while( b != 0){
        long long temp =  a % b;
        a = b;
        b = temp;
    }
    return a;
}

void bai8(int n, int a[], int x){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> x;

    int count = 0;
    for(int i = 0; i < n; i++){
        if(gcd(a[i], x) == 1){
            count++;
        }
    }
    cout << count << endl;

    for(int i = 0; i < n; i++){
        if(gcd(a[i], x) == 1){
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

/*Nhập vào mảng gồm n số nguyên, tìm số lớn nhất và nhỏ nhất trong mảng và
vị trí của chúng trong mảng, trường hợp có nhiều số lớn nhất hoặc nhỏ nhất thì in
ra vị trí xuất hiện cuối cùng.
Input:
Dòng đầu tiên là n (1<=n<=100000) - số lượng số trong dãy
Dòng thứ hai là n số trong dãy
Output
Dòng đầu tiên là số lớn nhất và vị trí của nó.
Dòng thứ hai là số nhỏ nhất và vị trí của nó.
Ví dụ
Input
8-
1 2 3 4 5 5 -1 5
Ouput
5 8
-1 7    */
void bai9(int n, int a[]){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    int max_val = a[0], min_val = a[0];
    int max_pos = 1, min_pos = 1;
    for(int i = 0; i < n; i++){
        if(a[i] >= max_val){ 
            max_val = a[i];
            max_pos = i + 1;
        }
        else if(a[i] <= min_val){ 
            min_val = a[i]; 
            min_pos = i + 1;
        }    
    }
    cout << max_val << " " << max_pos << endl;
    cout<< min_val << " " << min_pos << endl;
}

/*Bài 10. Tìm và in ra vị trí của số nhỏ nhất và nhỏ thứ 2 trong mảng các số nguyên
khác nhau.(Các phần tử trong mảng khác nhau đôi một).
Input:
Dòng đầu tiên là n (1<=n<=100000) - số lượng số trong dãy
Dòng thứ hai là n số trong dãy
Output
Dòng đầu tiên là vị trí của số nhỏ nhất
Dòng thứ hai là vị trí của số nhỏ thứ hai.
Ví dụ
Input
10
1 2 3 9 8 7 6 5 4 10
Output
12  */
void bai10(int n, int a[]){
    cin >> n;
    int min_val = a[0], min_pos = 1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < min_val){
            min_val = a[i];
            min_pos = i + 1;
        }
    }
    cout << min_pos << endl;
    if(min_pos < n){
       cout << min_pos + 1 << endl;
    }
    else cout << -1 << endl;
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
maxi là chi phí tối đa để gửi thư từ thành phố thứ i.
Ví dụ
Input
4-
5 -2 2 7
Ouput
3 12
3 9
4 7
5 12    */
void bai11(int n, long long x[]){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        long long min_cost, max_cost;

        // Tính min chi phí
        if (i == 0) {
            min_cost = abs(x[1] - x[0]);
        } else if (i == n - 1) {
            min_cost = abs(x[n - 1] - x[n - 2]);
        } else {
            min_cost = min(abs(x[i] - x[i - 1]), abs(x[i + 1] - x[i]));
        }

        // Tính max chi phí (so với đầu hoặc cuối)
        max_cost = max(abs(x[i] - x[0]), abs(x[i] - x[n - 1]));

        cout << min_cost << " " << max_cost << endl;
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
4
25 25 50 50
Output
YES     */
void bai12(int n, int a[]){
    cin >> n;
    int bill25 = 0, bill50 = 0;
    for (int i = 0; i < n; ++i) {
        int money;
        cin >> money;

        if (money == 25) {
            bill25++;
        } else if (money == 50) {
            if (bill25 > 0) {
                bill25--;
            } else {
                cout << "NO" << endl;
                return;
            }
            bill50++;
        } else if (money == 100) {
            if (bill50 > 0 && bill25 > 0) {
                bill50--;
                bill25--;
            } else if (bill25 >= 3) {
                bill25 -= 3;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

/*Một ngày nọ, ba người bạn thân nhất Petya, Vasya và Tonya quyết định thành lập
một nhóm và tham gia các cuộc thi lập trình. Những người tham gia thường được
cung cấp một số vấn đề trong các cuộc thi lập trình. Rất lâu trước khi bắt đầu,
những người bạn đã quyết định rằng họ sẽ giải một vấn đề nếu ít nhất hai người
trong số họ biết cách giải. Nếu không, bạn bè sẽ không viết lời giải cho vấn đề đó.
Cuộc thi này cung cấp n vấn đề cho những người tham gia. Đối với mỗi vấn đề
chúng ta biết, người bạn nào chắc chắn lời giải. Giúp bạn bè tìm ra số vấn đề mà họ
sẽ viết ra giải pháp.
Input
Dòng đầu vào đầu tiên chứa một số nguyên n (1 <=n <=1000) - số lượng vấn đề
trong cuộc thi. Sau đó, n dòng chứa ba số nguyên mỗi số nguyên, mỗi số nguyên là
0 hoặc 1. Nếu số đầu tiên trong dòng bằng 1, thì Petya chắc chắn về lời giải của vấn
đề, nếu 0 thì không chắc chắn về lời giải. Số thứ hai cho thấy quan điểm của Vasya
về giải pháp, số thứ ba cho thấy quan điểm của Tonya. Các số trên các dòng được
phân cách bằng dấu cách.
Output
In một số nguyên duy nhất - số lượng vấn đề mà 3 bạn trên sẽ thực hiện trong cuộc
thi.
Ví dụ
Input
31
1 0
1 1 1
1 0 0
Output
2   */
void bai13() {
    int n;
    cin >> n;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2) {
            count++;
        }
    }
    cout << count << endl;
}

void bai14(int n , int a[10000]){
    cin >> n; int count = 0;
    unordered_map<int, int> freq;
    
    for(int i= 0; i < n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }

    int max_freq = 0;
    int res = -1;

    for(auto pair : freq){
        if(pair.second > max_freq){
            max_freq = pair.second;
            res = pair.first;
        }
    }

    cout << res << " " << max_freq << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; int a; long long x[1000];
    //bai1(a,n);
    //bai2(n,a);
    //bai3(n,a);
    //bai4(n,a);
    //bai5(n, a);
    //bai6(n,a);
    //bai7(n,a,x);
    //bai8(n,a,x);
    //bai9(n,a);
    //bai10(n, a);
    //bai11(n, x);
    //bai12(n,a);
    int b,c;
    bai13();
    return 0;
}
