#include <stdio.h>
#include <string.h>

int main() {
    int pas, car;
    char id[50];
    int i = 0;

    printf("Enter the number of cars: ");
    scanf("%d", &car);
    getchar();  // Xóa ký tự newline sau scanf

    while (i < car) {
        printf("Enter the id of car:\n");
        fgets(id, sizeof(id), stdin);

        // Loại bỏ ký tự newline '\n' ở cuối chuỗi nếu có


        printf("Enter the maximum capacity of passengers of car (id: %s ): ", id);
        scanf("%d", &pas);
        getchar();  // Xóa ký tự newline còn lại sau scanf

        // In lại thông tin vừa nhập
        printf("Car ID: %s | Capacity: %d\n", id, pas);

        i++;
    }

    return 0;
}
