#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <fstream>
#include <ctime>
#include <vector> 
using namespace std;
using ll = long long;
    /*Cho biết diện tích của ba mặt có chung đỉnh của hình hộp chữ nhật, 
    tính tổng độ dài 12 cạnh của hình hộp chữ nhật đó.
    Input
    3 số nguyên dương không vượt quá 10^4 là 
    diện tích của ba mặt có chung đỉnh.
    Output
    Tổng của tất cả các cạnh của hình hộp chữ nhật.*/
void bai1(long long S1, long long S2, long long S3){
    cin >> S1 >> S2 >> S3;
    double a = sqrt(1.0 * S1 * S3 / S2);
    double b = sqrt(1.0 * S1 * S2 / S3);
    double c = sqrt(1.0 * S2 * S3 / S1);
    long long P = 4 * (a + b + c);
    cout << P << endl;
}

/*Bài 2. 50A
Bạn được cung cấp một bảng hình chữ nhật có kích thước M × N hình vuông đơn
vị. Ngoài ra, bạn được cung cấp một số lượng không giới hạn các mảnh domino
tiêu chuẩn kích thước 2 × 1. Bạn được phép xoay các mảnh domino. Bạn được yêu
cầu đặt càng nhiều domino càng tốt trên bảng để đáp ứng các điều kiện sau:
1. Mỗi domino hoàn toàn bao gồm hai hình vuông đơn vị.
2. Không có hai domino trùng nhau.
3. Mỗi domino nằm hoàn toàn bên trong bảng. Nó được phép chạm vào các cạnh
của bảng.*/
void bai2(long long m, long long n){
    cin >> m >> n;
    long long maxDomino = (m*n)/2;
    cout << maxDomino << endl;
}
    
/*Quảng trường Nhà hát ở thủ đô Berland có hình chữ nhật với kích thước n × m mét.
Nhân dịp kỷ niệm thành phố, một quyết định đã được đưa ra để lát Quảng trường
bằng những viên bằng đá granit vuông. Mỗi viên đá hình vuông có kích thước a ×
a.
Số lượng viên đá ít nhất cần thiết để lát Quảng trường là bao nhiêu? Nó được phép
che phủ bề mặt lớn hơn Quảng trường Nhà hát. Nó không được phép phá vỡ các
viên đá. Các cạnh của viên đá phải song song với các cạnh của Quảng trường.
Input
Đầu vào chứa ba số nguyên dương trong dòng đầu tiên: n, m và a (1 ≤ n, m, a ≤
10^9).*/
void bai3(long long n, long long m, long long a){
    cin >> n >> m >> a;
    long long res = ((n + a - 1) / a) * ((m + a - 1) / a);
    cout << res << endl;
}

/*Một con ếch hiện đang ở điểm 0 trên trục tọa độ Ox. Nó nhảy theo thuật toán sau:
bước nhảy thứ nhất là a đơn vị về bên phải, bước nhảy thứ hai là b đơn vị về bên
trái, bước nhảy thứ ba là a đơn vị bên phải, bước nhảy thứ tư là b đơn vị bên trái,
v.v. .Nếu con ếch đã nhảy một số lần chẵn (trước lần nhảy hiện tại), nó nhảy từ vị
trí hiện tại x sang vị trí x + a, mặt khác, nó nhảy từ vị trí hiện tại x sang vị trí x − b.*/
void bai4(long long a, long long b, long long k){
    cin >> a >> b >> k;
    long long res = 0;
    if (k % 2 == 0) {
        res = (k / 2) * (a - b);
    } else {
        res = ((k + 1) / 2) * a - (k / 2) * b;
    }
    cout << res << endl;
}

/*Một ngày nào đó, Drazil muốn hẹn hò với Varda. Drazil và Varda sống trên máy
bay của Cartesian. Nhà của Drazil nằm ở điểm (0, 0) và nhà của Varda nằm ở điểm
(a, b). Trong mỗi bước, anh ta có thể di chuyển trong một khoảng cách 1 đơn vị
theo hướng ngang hoặc dọc. Nói cách khác, từ vị trí (x, y) anh ta có thể đi đến các
vị trí (x + 1, y), (x - 1, y), (x, y + 1) hoặc (x, y - 1).
Thật không may, Drazil không có ý thức về hướng di chuyển. Vì vậy, anh ta chọn
ngẫu nhiên hướng đi mà anh ta sẽ đi trong mỗi bước. Anh ta có thể vô tình trở về
nhà trong chuyến đi của mình. Drazil thậm chí có thể không nhận thấy rằng anh ấy
đã đến (a, b) và tiếp tục đi.
May mắn thay, Drazil đã đến vị trí (a, b) thành công. Drazil nói với Varda: "Tôi
phải mất chính xác một số để đi từ nhà tôi đến nhà bạn". Nhưng Varda bối rối về
lời nói của mình, cô không chắc chắn rằng có thể đi từ (0, 0) đến (a, b) trong các
bước cho trước. Bạn có thể tìm ra?*/
void bai5(long long a, long long b, long long s){
    cin >> a >> b >> s;
    if(s < a + b || (s - a - b) % 2 != 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

/*Polycarp muốn nấu một món súp. Để làm điều đó, anh ta cần mua chính xác n lít
nước.
Chỉ có hai loại chai nước trong cửa hàng gần đó - chai 1 lít và chai 2 lít. Có vô số
chai của hai loại này trong cửa hàng.
Chai loại thứ nhất có gía a burles và chai loại thứ hai có giá tương ứng b burles.
Polycarp muốn chi càng ít tiền càng tốt. Nhiệm vụ của bạn là tìm ra số tiền tối thiểu
(bằng burles) Polycarp cần mua chính xác n lít nước ở cửa hàng gần đó nếu chai
loại thứ nhất có giá a burles và chai loại thứ hai có giá b burles.
Input
3 số n,a,b (1<=n<=10^12, 1<=a,b<=1000) tương ứng với số lit nước cần mua, a và
b.*/
void bai6(long long n, long long a, long long b){
    cin >> n >> a >> b;
    long long res;
    if(2 * a <= b)
        res = n * a;
    else{
        long long num_2l = n / 2;
        long long num_1l = n % 2;
        res = num_2l * b + num_1l * a;
    }
    cout << res << endl;   
}

/*Bạn có số lượng xu không giới hạn với 
các giá trị 1,2,3,......n (từ 1 tới n). Bạn
muốn chọn một số bộ tiền có tổng giá trị S.
Nó được phép có nhiều đồng tiền có cùng giá trị trong tập hợp. 
Số lượng đồng xu tối thiểu cần thiết để có được tổng S là bao nhiêu?
Input
Dòng duy nhất của đầu vào chứa hai số nguyên n và S (1≤n≤100000, 1 ≤S≤10^9)
Output
In chính xác một số nguyên - số lượng xu tối thiểu cần thiết để có được tổng S.*/
void bai7(long long n, long long s){
    cin >> n >> s;
    long long res = s / n;
    if(s % n != 0)
        res++;
    cout << res << endl;
}
/*Allen có rất nhiều tiền. Anh ta có n đô la trong ngân hàng. Vì lý do bảo mật,
anh ta muốn rút tiền mặt (chúng tôi sẽ không tiết lộ lý do tại đây). Các mệnh giá
cho hóa đơn đô la là 1, 5, 10, 20, 100. Số hóa đơn tối thiểu mà Allen có thể nhận
được sau khi rút toàn bộ số dư của mình là bao nhiêu?
Input
Số nguyên dương n (1<=n<=1000 000 000).
Output
Số lượng hóa đơn nhỏ nhất mà Allen có thể nhận được*/
void bai8(long long n){
    cin >> n;
    long long res = 0;
    res += n / 100;
    n %= 100;
    res += n / 20;
    n %= 20;
    res += n / 10;
    n %= 10;
    res += n / 5;
    n %= 5;
    res += n / 1;
    cout << res << endl;
}

/*Dreamoon muốn leo lên một cầu thang gồm n bước. Anh ta có thể leo 1 hoặc
2 bước mỗi lần di chuyển. Dreamoon muốn số lần di chuyển là bội số của một số
nguyên m.
Số lượng di chuyển tối thiểu làm cho anh ta leo lên đỉnh cầu thang thỏa mãn điều
kiện của anh ta là gì?
Input
Dòng đơn chứa hai số nguyên cách nhau n, m (0 <n ≤ 10000, 1 <m<=10).
Output
In một số nguyên duy nhất - số lượng di chuyển tối thiểu là bội số của m. Nếu
không có cách nào anh ta có thể leo lên thỏa mãn điều kiện in - 1.*/
void bai9(long long n, long long m){
    cin >> n >> m;
    long long res = 0;
    if(n % m == 0)
        res = (n / m) + 1;
    else
        res = (n / m + 1) * m;
    cout << res << endl;
}

/*Hôm nay Patrick chờ đợi một chuyến thăm từ người bạn SpPal của mình. Để chuẩn
bị cho chuyến thăm, Patrick cần mua một số quà tặng ở hai cửa hàng gần nhà. Có
một con đường dài d1 mét giữa nhà anh ta và cửa hàng đầu tiên và một con đường
dài d2 mét giữa nhà anh ta và cửa hàng thứ hai. Ngoài ra, có một con đường dài d3
kết nối trực tiếp hai cửa hàng này với nhau. Giúp Patrick tính toán khoảng cách tối

7

thiểu mà anh ta cần đi bộ để đến cả hai cửa hàng và trở về nhà.
Patrick luôn bắt đầu tại nhà của mình. Anh ta nên ghé thăm cả hai cửa hàng chỉ di
chuyển dọc theo ba con đường hiện có và trở về nhà của anh ta. Anh ta không ngại
ghé thăm cùng một cửa hàng hoặc đi qua cùng một con đường nhiều lần. Mục tiêu
duy nhất là giảm thiểu tổng quãng đường đã đi.

Input
Dòng đầu tiên của đầu vào chứa ba số nguyên d1, d2, d3 (1 <=d1, d2, d3<= 10^8) -
độ dài của các đường dẫn.
d1 là chiều dài của con đường nối nhà Patrick và cửa hàng đầu tiên;
d2 là chiều dài của con đường nối nhà Patrick và cửa hàng thứ hai;
d3 là chiều dài của đường dẫn kết nối cả hai cửa hàng.
Output
In khoảng cách tối thiểu mà Patrick sẽ phải đi bộ để ghé thăm cả hai cửa hàng và
trở về*/
void bai10(long long d1,long long d2,long long d3){
    cin >> d1 >> d2 >> d3;
    int option1 = d1 + d2 + d3;
    int option2 = 2 * (d1 + d2);
    int option3 = 2 * (d1 + d3);
    int option4 = 2 * (d2 + d3);
    int result = min(option1, min(option2, min(option3, option4)));
    cout << result << endl;
}

/*Một người lính muốn mua w quả chuối trong cửa hàng. Anh ta phải trả k đô la cho
quả chuối đầu tiên, 2k đô la cho quả thứ hai và cứ thế (nói cách khác, anh ta phải
trả i · k đô la cho quả chuối thứ i).
Anh ta có n đô la. Anh ta phải vay bao nhiêu đô la từ người bạn lính của mình để
mua chuối?
Input
Dòng đầu tiên chứa ba số nguyên dương k, n, w (1 ≤ k, w ≤1000, 0 ≤n≤109
), chi phí
của quả chuối đầu tiên, số đô la ban đầu mà người lính có và số chuối anh ta muốn.
Output
Xuất ra một số nguyên - số đô la mà người lính phải vay từ bạn của mình. Nếu anh
ta không phải vay tiền, đầu ra là 0.*/
void bai11(long long k, long long n, long long w){
    cin >> k >> n >> w;
    long long totalCost = (w * (w + 1) / 2) * k;
    long long amountToBorrow = totalCost - n;
    if (amountToBorrow < 0) {
        amountToBorrow = 0;
    }
    cout << amountToBorrow << endl;
}

int main(){
    //long long m, n;
    //bai2(m,n);
    //long long n, m, a;
    //bai3(n,m,a);
    //long long a, b, k;
    //bai4(a,b,k);
    //int a, b, s;
    //bai5(a,b,s);
    //int n, a, b;
    //bai6(n,a,b);
    //long long n, s;
    //bai7(n, s);
    //long long n;
    //bai8(n);
    //long long n, m;
    //bai9(n,m);
    //long long d1, d2, d3;
    //bai10(d1,d2,d3);
    long long k, n, w;
    bai11(k,n,w);
    return 0;
}