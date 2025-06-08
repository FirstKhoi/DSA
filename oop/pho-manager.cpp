#include <iostream>

int main() {
    const int smallPrice = 35000;
    const int mediumPrice = 55000;
    const int largePrice = 80000;

    std::cout << "Welcome to Pho Restaurant!" << std::endl;
    std::cout << "Please select the size of your bowl:" << std::endl;
    std::cout << "1. Small - " << smallPrice << " VND" << std::endl;
    std::cout << "2. Medium - " << mediumPrice << " VND" << std::endl;
    std::cout << "3. Large - " << largePrice << " VND" << std::endl;

    int bowlChoice;
    std::cin >> bowlChoice;

    const int bowlPrice = (bowlChoice == 1) ? smallPrice :
                          (bowlChoice == 2) ? mediumPrice :
                          (bowlChoice == 3) ? largePrice : -1;
    if (bowlPrice == -1) {
            std::cout << "Invalid choice. Please try again." << std::endl;
            return 0;
    }

    std::cout << "Please select the type of your bowl:" << std::endl;
    std::cout << "1. Reused" << std::endl;
    std::cout << "2. Paper" << std::endl;
    std::cout << "3. Bamboo" << std::endl;
    std::cout << "4. Wooden" << std::endl;
    std::cout << "5. Flowered bowl" << std::endl;

    int bowlTypeChoice;
    std::cin >> bowlTypeChoice;

    // You can add more code here to calculate the price of the bowl type
    std::cout << "Do you want to order Trứng trần (+8000 VND)? (y/n)";
    bool wantsTrungTran;
    std::cin >> wantsTrungTran;

    std::cout << "Do you want to add khăn lạnh (+3000 VND)? (y/n)";
    bool wantsKhainLanh;
    std::cin >> wantsKhainLanh;

    int totalBill = bowlPrice;
    if (wantsTrungTran) {
        totalBill += 8000;
    }
    if (wantsKhainLanh) {
        totalBill += 3000;
    }

    std::cout << "Total bill: " << totalBill << " VND" << std::endl;
}
