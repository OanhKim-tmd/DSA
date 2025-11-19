/*
Exercise 2: Assume that a railway train has N railroad cars attached together
such as car1, car2, car3, ..., carN . A train can be considered as a list and each car
corresponds to a node in this list.
1
   - Each car carries a maximum capacity of passengers (int type) and has an id
(char type). Both variables are user-defined values.
   - Each car is reserved by a number of passengers (int type) (which should be
less than its capacity). If there are any cars that don’t have any passengers,
they should be removed from the train.
   - It is possible to add new cars to the train.
   - A function is available to display all cars’ information or the length of the
train.
Implement a program in C/C++ using Linked List to manage the train and test all
functions.*/
#include <stdio.h>
#include <stdlib.h>

// Cấu trúc dữ liệu Unbounded Int
typedef struct {
    int *data;      // Con trỏ quản lý mảng động
    int size;       // Kích thước hiện tại (bao gồm cả ô chứa dấu)
    int capacity;   // Tổng sức chứa của bộ nhớ hiện tại
} UnboundedInt;

// 1. Khởi tạo số nguyên lớn
// sign: 1 (dương) hoặc -1 (âm)
void init(UnboundedInt *list, int sign) {
    list->capacity = 10; // Sức chứa ban đầu
    list->data = (int *)malloc(list->capacity * sizeof(int));
    
    // Kiểm tra cấp phát bộ nhớ
    if (list->data == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }

    // Index 0 luôn là dấu
    list->data[0] = (sign < 0) ? -1 : 1; 
    list->size = 1; // Hiện tại chỉ có 1 phần tử là dấu
}

// Hàm hỗ trợ mở rộng bộ nhớ nếu đầy
void checkCapacity(UnboundedInt *list) {
    if (list->size >= list->capacity) {
        list->capacity *= 2; // Tăng gấp đôi sức chứa
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
        if (list->data == NULL) {
            printf("Lỗi: Không thể mở rộng bộ nhớ!\n");
            exit(1);
        }
    }
}

// 2. Add new digit (Thêm chữ số vào vị trí k)
// pos: Vị trí muốn chèn (phải >= 1 vì 0 là dấu)
// digit: Giá trị (0-9)
void addDigit(UnboundedInt *list, int pos, int digit) {
    if (pos < 1 || pos > list->size) {
        printf(">>> Lỗi: Vị trí chèn không hợp lệ (Phải từ 1 đến %d)\n", list->size);
        return;
    }
    if (digit < 0 || digit > 9) {
        printf(">>> Lỗi: Chữ số phải từ 0-9\n");
        return;
    }

    checkCapacity(list); // Đảm bảo đủ bộ nhớ

    // Dịch chuyển các phần tử từ cuối mảng về sau để tạo chỗ trống tại pos
    for (int i = list->size; i > pos; i--) {
        list->data[i] = list->data[i - 1];
    }

    list->data[pos] = digit;
    list->size++;
    printf(">>> Đã thêm chữ số %d vào vị trí %d.\n", digit, pos);
}

// 3. Remove a digit (Xóa chữ số tại vị trí k)
void removeDigit(UnboundedInt *list, int pos) {
    if (pos < 1 || pos >= list->size) {
        printf(">>> Lỗi: Vị trí xóa không hợp lệ!\n");
        return;
    }

    // Dịch chuyển các phần tử phía sau đè lên vị trí pos
    for (int i = pos; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
    printf(">>> Đã xóa chữ số tại vị trí %d.\n", pos);
}

// 4. Display (Hiển thị số)
void display(UnboundedInt *list) {
    printf("Giá trị hiện tại: ");
    if (list->size <= 1) {
        printf("(Rỗng)\n");
        return;
    }

    // Nếu là số âm thì in dấu trừ
    if (list->data[0] == -1) {
        printf("-");
    }

    // In các chữ số từ index 1
    for (int i = 1; i < list->size; i++) {
        printf("%d", list->data[i]);
    }
    printf("\n");
}

// 5. Calculate sum (Tính tổng các chữ số)
int sumDigits(UnboundedInt *list) {
    int sum = 0;
    // Duyệt từ 1 bỏ qua dấu
    for (int i = 1; i < list->size; i++) {
        sum += list->data[i];
    }
    return sum;
}

// Giải phóng bộ nhớ trước khi thoát
void freeList(UnboundedInt *list) {
    if (list->data != NULL) {
        free(list->data);
    }
}

// --- Main Program để Test ---
int main() {
    UnboundedInt myNum;
    int choice, val, pos, sign;

    printf("Nhập dấu cho số khởi tạo (1 là dương, -1 là âm): ");
    scanf("%d", &sign);
    init(&myNum, sign);

    while (1) {
        printf("\n--- QUẢN LÝ SỐ NGUYÊN LỚN ---\n");
        printf("1. Hiển thị số\n");
        printf("2. Thêm chữ số\n");
        printf("3. Xóa chữ số\n");
        printf("4. Tính tổng các chữ số\n");
        printf("0. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(&myNum);
                break;
            case 2:
                printf("Nhập vị trí cần chèn (>=1): ");
                scanf("%d", &pos);
                printf("Nhập chữ số (0-9): ");
                scanf("%d", &val);
                addDigit(&myNum, pos, val);
                break;
            case 3:
                printf("Nhập vị trí cần xóa: ");
                scanf("%d", &pos);
                removeDigit(&myNum, pos);
                break;
            case 4:
                printf(">>> Tổng các chữ số là: %d\n", sumDigits(&myNum));
                break;
            case 0:
                freeList(&myNum);
                printf("Thoát chương trình.\n");
                return 0;
            default:
                printf("Lựa chọn không hợp lệ.\n");
        }
    }
    return 0;
}