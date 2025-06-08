#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*Fafa sở hữu một công ty làm việc trên các dự án lớn. Có n nhân viên trong công ty
của Fafa. Bất cứ khi nào công ty có một dự án mới để bắt đầu làm việc, Fafa phải
phân chia nhiệm vụ của dự án này cho tất cả các nhân viên.
Fafa thấy làm điều này mỗi lần là rất mệt mỏi đối với anh ta. Vì vậy, anh quyết
định chọn những nhân viên l giỏi nhất trong công ty của mình làm trưởng nhóm.
Bất cứ khi nào có một dự án mới, Fafa sẽ phân chia nhiệm vụ cho chỉ các trưởng
nhóm và mỗi trưởng nhóm sẽ chịu trách nhiệm về một số nhân viên tích cực để
giao cho họ các nhiệm vụ. Để làm cho quá trình này công bằng cho các trưởng
nhóm, mỗi người trong số họ phải chịu trách nhiệm cho cùng một số lượng nhân
viên. Hơn nữa, mỗi nhân viên, người không phải là trưởng nhóm, phải chịu trách
nhiệm của chính xác một trưởng nhóm và không có trưởng nhóm nào chịu trách
nhiệm cho một trưởng nhóm khác.
Dựa vào số lượng nhân viên n, hãy tìm xem có bao nhiêu cách Fafa có thể chọn số
lượng trưởng nhóm l theo cách có thể phân chia nhân viên giữa họ một cách đồng
đều.
Input
Đầu vào bao gồm một dòng duy nhất chứa số nguyên dương n (2<= n<= 10^5) - số
lượng nhân viên trong công ty của Fafa.
Output
In một số nguyên duy nhất đại diện cho câu trả lời cho vấn đề.
Ví dụ
Input
10
Output*/
void bai1(int nhanvien){
    int count = 0; 
    for(int i = 1; i < nhanvien; i++){
        if((nhanvien - i) % i == 0){
            count++;
        }
    }
    cout << count++ << endl;
}
/*Polycarp có ba chị em: Alice, Barbara và Cerene. Họ đang thu thập tiền xu. Hiện
tại, Alice có một đồng tiền, Barbara có tiền xu và Cerene có tiền xu. Gần đây
Polycarp đã trở về từ chuyến đi vòng quanh thế giới và mang theo n xu.
Anh ta muốn phân phối tất cả n xu này giữa các chị em của mình theo cách mà số
lượng tiền Alice có bằng số lượng tiền mà Barbara có và bằng với số lượng tiền mà
Cerene có. Nói cách khác, nếu Polycarp đưa A xu cho Alice, B xu cho Barbara và
C xu cho Cerene (A + B + C = n), thì a + A = b + B = c + C.
Lưu ý rằng A, B hoặc C (số lượng tiền mà Polycarp đưa cho Alice, Barbara và
Cerene tương ứng) có thể là 0.
Nhiệm vụ của bạn là tìm hiểu xem có thể phân phối tất cả n xu giữa các chị em theo
cách được mô tả ở trên không.
Bạn phải trả lời t trường hợp kiểm tra độc lập.
Input
Dòng đầu tiên của đầu vào chứa một số nguyên t (1≤t≤10^4) - số lượng trường hợp
kiểm tra.
Các dòng t tiếp theo mô tả các trường hợp thử nghiệm. Mỗi trường hợp thử nghiệm
được đưa ra trên một dòng mới và bao gồm bốn số nguyên cách nhau không gian a,
b, c và n (1≤a, b, c, n≤10^8) - số lượng tiền Alice có, số lượng tiền Barbara có, số
lượng tiền mà Cerene có và số lượng tiền mà Polycarp có.
Output
Đối với mỗi trường hợp thử nghiệm, hãy in "YES" nếu Polycarp có thể phân phối
tất cả n xu giữa các chị em của mình và "NO" nếu không.
Ví dụ
Input
5
5 3 2 8
100 101 102 105
3 2 1 100000000
10 20 15 14
101 101 101 3
Output
YES
YES
NO
NO
YES*/
void bai2(int t,int a, int b , int c, int n){
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> n;
        int max_val = max({a,b,c});
        int need = (max_val - a) + (max_val - b) + (max_val - c);
        if( n >= need && ( n - need ) % 3 == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}

/*Mahmoud và Ehab chơi một trò chơi gọi là trò chơi chẵn. Ehab chọn số
nguyên n yêu thích của mình và sau đó họ thay phiên nhau, bắt đầu từ Mahmoud.
Trong lượt của mỗi người chơi, anh ta phải chọn một số nguyên a và lấy n trừ a sao
cho: 1 ≤ a ≤ n.
Nếu đến lượt của Mahmoud, thì phải là chẵn, nhưng nếu đến lượt của Ehab, thì
phải là số lẻ.
Nếu người chơi hiện tại không thể chọn bất kỳ số nào thỏa mãn điều kiện, anh ta sẽ
thua. Bạn có thể xác định người chiến thắng nếu cả hai chơi tối ưu?
Input
Dòng duy nhất chứa một số nguyên n (1<=n<=10^9), số ở đầu trò chơi.
Output
Xuất "Mahmoud" (không có dấu ngoặc kép) nếu Mahmoud thắng và "Ehab"
(không có dấu ngoặc kép) nếu không.
Ví dụ
Input
2
Output
Mahmoud*/
void bai3(int n){
    if(  n % 2 == 0 ){
        cout << "Mahmoud" << endl;
    }
    else cout << "Ehab" << endl;
}

/*Có năm người chơi một trò chơi gọi là "Sự hào phóng". Mỗi người đưa ra
một số lượng tiền xu khác không b như một lần đặt cược ban đầu. Sau khi tất cả
người chơi đặt cược tiền xu của họ, thao tác sau được lặp lại nhiều lần: một đồng
xu được chuyển từ người chơi này sang người chơi khác.
Nhiệm vụ của bạn là viết một chương trình có thể, với số lượng xu mà mỗi người
chơi có vào cuối trò chơi, xác định kích thước b của lần đặt cược ban đầu hoặc chỉ
ra rằng kết quả của trò chơi không thể đạt được.
Input
Đầu vào bao gồm một dòng duy nhất chứa năm số nguyên c1, c2, c3, c4 và c5 - số
lượng đồng xu mà người chơi thứ nhất, thứ hai, thứ ba, thứ tư và thứ năm có ở cuối
trò chơi (0 ≤ c1, c2 , c3, c4, c5 <=100).
Output
In dòng duy nhất chứa một số nguyên dương b duy nhất - số xu trong đặt cược ban
đầu của mỗi người chơi. Nếu không có giá trị b như vậy, thì hãy in giá trị duy nhất
"
-1" (trích dẫn cho rõ ràng).
Ví dụ
Input
2 5 4 0 4
Output
3*/
void bai4(){
    int c[5];
    int sum = 0;
    for(int i = 0 ; i < 5; i++){
        cin >> c[i];
        sum += c[i];
    }
    if( sum % 5 == 0 && sum != 0 ){
        cout << sum / 5 << endl;
    }
    else
        cout << -1 << endl;
}

void bai5(int k2, int k3, int k4, int k5, int k6){
    int count256 = min({k2, k5, k6});
    k2 -= count256;
    int count32 = min(k2, k3);
    int result = count256 * 256 + count32 * 32;
    cout << result << endl;
}

/*Bizon the Champion được gọi là Champion vì một lý do.
Bizon the Champion gần đây đã có một món quà - một tủ kính mới với n kệ và anh
quyết định đặt tất cả những món quà của mình ở đó. Tất cả các món quà có thể
được chia thành hai loại: huy chương và cúp. Bizon the Champion có a1 cúp giải
nhất, a2 cúp giải nhì và a3 cúp giải ba. Bên cạnh đó, anh có b1 huy chương giải
nhất, b2 huy chương giải nhì và b3 huy chương giải ba.
Đương nhiên, phần thưởng trong tủ phải sắp xếp cho thật đẹp, đó là lý do Bizon the
Champion quyết định tuân theo các quy tắc:
bất kỳ kệ nào cũng không thể chứa cả cốc và huy chương cùng một lúc;
không có kệ có thể chứa nhiều hơn năm cốc;
không có kệ có thể có hơn mười huy chương.
Giúp Bizon the Champion tìm hiểu xem chúng tôi có thể đặt tất cả các phần thưởng
để tất cả các điều kiện được đáp ứng hay không.
Input
Dòng đầu tiên chứa các số nguyên a1, a2 và a3 (0 ≤ a1, a2, a3<= 100). Dòng thứ
hai chứa các số nguyên b1, b2 và b3 (0 ≤ b1, b2, b3<= 100). Dòng thứ ba chứa số
nguyên n (1 <=n <=100).
Các số trong các dòng được phân tách bằng khoảng trắng đơn.
Output
In "YES" (không có dấu ngoặc kép) nếu tất cả các phần thưởng có thể được đưa lên
kệ theo cách được mô tả. Nếu không, hãy in "NO" (không có dấu ngoặc kép).
Ví dụ
Input
1 1 1
1 1 1
4
Output
YES*/
void bai6(){
    int a[3];
    int b[3];
    int sumCups = 0;
    int sumMedals = 0;
    for(int i = 0; i < 3;i++){
        cin >> a[i];
        sumCups += a[i];
    }
    for(int j = 0 ; j < 3; j++){
        cin >> b[j];
        sumMedals += b[j];
    }
    int  n;
    cin >> n;
    int CupsOnSelf = (sumCups + 4 ) / 5;
    int MedalsOnSelf = (sumMedals + 9) / 10;
    int totalCupAndMedals = CupsOnSelf + MedalsOnSelf;
    if(totalCupAndMedals <= n){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}

/*Ngày lễ đã kết thúc. Nhờ sự giúp đỡ của hacker Leha, Noora đã tìm được cơ hội
vào trường đại học trong mơ của cô nằm ở thị trấn Pavlopolis. Người ta biết rằng
các trường đại học cung cấp cho sinh viên ký túc xá trong thời gian học đại học. Do
đó, Noora phải rời Vičkopolis và chuyển đến Pavlopolis. Do đó, Leha bị bỏ lại một
mình hoàn toàn trong một thị trấn yên tĩnh Vičkopolis. Anh gần như thậm chí rơi
vào trầm cảm vì buồn chán!
Leha nghĩ ra một nhiệm vụ cho bản thân để thư giãn một chút. Anh ta chọn hai số
nguyên A và B và sau đó tính ước số chung lớn nhất của các số nguyên "A giai
thừa" và "giai thừa B". Leha muốn tìm ra GCD (A!, B!). Người ta biết rằng giai
thừa của một số nguyên x là tích của tất cả các số nguyên dương nhỏ hơn hoặc
bằng x. Như vậy x! = 1 · 2 · 3 · ... · (x - 1) · x. Ví dụ 4! = 1 · 2 · 3 · 4 = 24. Hãy
nhớ rằng GCD (x, y) là số nguyên dương lớn nhất q chia hết bởi (không có phần
dư) cả x và y.
Leha đã học được cách giải quyết nhiệm vụ này rất hiệu quả. Bạn có thể đối phó
với nó, phải không?
Input
Dòng đầu tiên và dòng đơn chứa hai số nguyên A và B (1<=A, B <=10^9, min (A,
B)<=12).
Output
In một số nguyên duy nhất biểu thị ước số chung lớn nhất của số nguyên A! và B!.
Ví dụ
Input
4 3
Output
6   */
void bai7(long long A, long long B){
    long long result = 1;
    long long minAB = min(A,B);
    for(long long i = 1 ; i <= minAB; i++){
        result *= i;
    }
    cout << result << endl;
}

/*Năm mới sắp đến và bạn rất hào hứng muốn biết còn lại bao nhiêu phút trước Tết.
Bạn biết rằng hiện tại đồng hồ hiển thị h giờ và m phút, trong đó 0≤hh <24 và
0≤mm <60. Chúng tôi sử dụng định dạng thời gian 24 giờ!
Nhiệm vụ của bạn là tìm số phút trước Tết. Bạn biết rằng năm mới đến khi đồng hồ
hiển thị 0 giờ và 0 phút.
Bạn phải trả lời t trường hợp kiểm tra độc lập.
Input
kiểm tra.
Dòng đầu tiên của đầu vào chứa một số nguyên t (1≤t≤1439) - số lượng trường hợp
Các dòng t sau đây mô tả các trường hợp thử nghiệm. Dòng thứ i chứa thời gian là
hai số nguyên h và m (0≤h <24, 0≤m <60). Đảm bảo rằng thời gian này không phải
là nửa đêm, tức là hai điều kiện sau đây không thể được đáp ứng cùng một lúc: h =
0 và m = 0. Nó được đảm bảo rằng cả h và m được đưa ra mà không có số 0 đứng
đầu.
Output
Đối với mỗi trường hợp kiểm tra, hãy in câu trả lời trên đó - số phút trước Tết.
Ví dụ
Input
5
23 55
23 0
0 1
4 20
23 59
Output
5
60
1439
1180
1*/
void bai8() {
    int t;
    cin >> t;
    while (t--) {
        int h, m;
        cin >> h >> m;
        int minutesBeforeNewYear = (24 * 60) - (h * 60 + m);
        cout << minutesBeforeNewYear << endl;
    }
}

/*Yakko, Wakko và Dot chơi xúc xắc.
Yakko ném xúc xắc và nhận được điểm Y, điểm Wakko là W. Đến lượt của Dot.
Nhưng cô không vội. Dot muốn biết chắc chắn cơ hội chiến thắng của cô là bao
nhiêu.
Được biết, Yakko và Wakko là những quý ông đích thực, đó là lý do tại sao nếu họ
có cùng số điểm với Dot, họ sẽ để Dot giành chiến thắng.
Input
Dòng duy nhất của tệp đầu vào chứa hai số tự nhiên Y và W - kết quả của các lần
tung xung xắc của Yakko và Wakko.
Output
Đưa ra xác suất cần thiết dưới dạng phân số không thể thay đổi theo định dạng «A /
B», trong đó A - tử số và B - mẫu số. Nếu xác suất yêu cầu bằng 0, xuất ra «0/1».
Nếu xác suất yêu cầu bằng 1, xuất ra «1/1».
Ví dụ
Input
4 2
Ouput
1/2 */
int gcd(int a, int b){
    while( b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void bai9(){
    int y, w;
    cin >> y >> w;
    int highest = max(y, w);
    int favorable = 6 - highest + 1; 
    int winRate = gcd(favorable,6);
    cout << favorable / winRate << "/" << 6 / winRate << endl;
}

/*Pashmak đã yêu một cô gái hấp dẫn tên là Parmida từ một năm trước ...
Hôm nay, Pashmak đã tạo một hẹn với đối tác của mình trong một khu vườn lãng
mạn. Thật không may, Pashmak đã quên mất khu vườn. Nhưng anh ta nhớ rằng khu
vườn trông giống như một hình vuông với các cạnh song song với các trục tọa độ.
Ông cũng nhớ rằng có chính xác một cây trên mỗi đỉnh của hình vuông. Bây giờ,
Pashmak biết vị trí của chỉ hai cây. Giúp anh ta tìm vị trí của hai người còn lại.
Input
Dòng đầu tiên chứa bốn số nguyên x1, y1, x2, y2 (- 100 ≤ x1, y1, x2, y2 <=100)
cách nhau không gian, trong đó x1 và y1 là tọa độ của cây thứ nhất và x2 và y2 là
tọa độ của cây thứ hai cây. Nó được đảm bảo rằng các điểm đã cho là khác biệt.
Output
Nếu không có giải pháp cho vấn đề, hãy in -1. Mặt khác in bốn số nguyên cách
nhau không gian x3, y3, x4, y4 tương ứng với tọa độ của hai cây khác. Nếu có một
số giải pháp bạn có thể xuất ra bất kỳ giải pháp nào.
Lưu ý rằng x3, y3, x4, y4 phải nằm trong phạm vi (- 1000 ≤ x3, y3, x4, y4
<=1000).
Ví dụ
Input
0 0 0 1
Output
1 0 1 1 */
void bai10(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {

        int d = abs(y2 - y1);
        cout << x1 + d << " " << y1 << " " << x2 + d << " " << y2 << endl;
    }
    else if (y1 == y2) {
        int d = abs(x2 - x1);
        cout << x1 << " " << y1 + d << " " << x2 << " " << y2 + d << endl;
    }
    else if (abs(x2 - x1) == abs(y2 - y1)) {
        
        cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
    }
    else {
        cout << -1 << endl;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //bai1(10);
    //int t,a,b,c,n;
    //bai2(t,a,b,c,n);
    //bai3(2);
    //bai4();
    //int k2, k3, k4, k5, k6;
    //cin >> k2 >> k3 >> k5 >>k6;
    //bai5(k2,k3,k4,k5,k6);
    //bai6();
    //bai7(4,3);
    //bai8();
   //bai9();
   bai10(); 
   return 0;
}