#include <iostream>
#include <string>
using namespace std;

// Định nghĩa cấu trúc để lưu thông tin về các loại phòng
struct Room {
    string type;
    int baseRate;       // Giá cho giờ đầu
    int additionalRate; // Giá cho mỗi giờ tiếp theo
    int overnightRate;  // Giá qua đêm nếu có
};

// Hàm tính toán giá phòng
double calculatePrice(const Room& room, int hours, bool overnight) {
    double total = 0;

    // Tính giá cho giờ đầu
    total += room.baseRate;

    // Tính giá cho các giờ tiếp theo
    if (hours > 1) {
        total += (hours - 1) * room.additionalRate;
    }

    // Tính giá qua đêm nếu có
    if (overnight) {
        total += room.overnightRate;
    }

    return total;
}

int main() {
    // Khai báo các loại phòng
    Room svip = {"S-VIP", 120000, 50000, 250000};
    Room vip = {"VIP", 100000, 40000, 250000};
    Room medium = {"Medium", 80000, 30000, 250000};
    Room normal = {"Thường", 60000, 20000, 250000};

    // Display room types to user
    cout << "Select room type:\n";
    cout << "1. S-VIP\n2. VIP\n3. Medium\n4. Normal\n";
    int choice = 0;
    cout << "Enter number from 1 to 4: ";
    cin >> choice;

    Room selectedRoom;
    switch (choice) {
        case 1: selectedRoom = svip; break;
        case 2: selectedRoom = vip; break;
        case 3: selectedRoom = medium; break;
        case 4: selectedRoom = normal; break;
        default: 
            cout << "Lua chon khong hop le!" << endl;
            return 0;
    }

    // Nhập số giờ sử dụng
    int hours;
    cout << "Nhap so gio su dung: ";
    cin >> hours;

    // Nhập yêu cầu qua đêm
    char overnightChoice;
    cout << "Co muon qua dem (y/n)? ";
    cin >> overnightChoice;
    bool overnight = (overnightChoice == 'y' || overnightChoice == 'Y');

    // Tính giá và in ra kết quả
    double totalPrice = calculatePrice(selectedRoom, hours, overnight);
    cout << "Tong tien cho " << selectedRoom.type << ": " << totalPrice << " VND" << endl;

    return 0;
}
