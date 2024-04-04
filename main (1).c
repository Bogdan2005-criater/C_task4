#include <stdio.h>

int sum_of_squares(int a, int b) {
    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum += i * i;
    }
    return sum;
}

char* has_exactly_three_digits(int number) {
    int count = 0;
    while (number != 0) {
        count++;
        number /= 10;
    }
    return count == 3 ? "YES" : "NO";
}

char* all_digits_even(int number) {
    while (number != 0) {
        int digit = number % 10;
        if (digit % 2 != 0) {
            return "NO";
        }
        number /= 10;
    }
    return "YES";
}

int reverse_number(int number) {
    int reversed = 0;
    while (number != 0) {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }
    return reversed;
}

int is_lucky(int number) {
    int sum_of_digits = 0;
    int product_of_digits = 1;

    int temp = number;
    while (temp != 0) {
        int digit = temp % 10;
        sum_of_digits += digit;
        product_of_digits *= digit;
        temp /= 10;
    }

    return sum_of_digits == product_of_digits;
}

int main() {
    int a, b;
    printf("Введите два целых числа a и b (a <= b): ");
    scanf("%d %d", &a, &b);

    printf("Сумма квадратов от %d до %d: %d\n", a, b, sum_of_squares(a, b));

    int number;
    printf("Введите целое число для проверки на ровно три цифры: ");
    scanf("%d", &number);
    printf("Верно ли, что в числе %d ровно три цифры? %s\n", number, has_exactly_three_digits(number));

    printf("Введите целое число для проверки, все ли его цифры четные: ");
    scanf("%d", &number);
    printf("Верно ли, что все цифры числа %d четные? %s\n", number, all_digits_even(number));

    printf("Введите целое неотрицательное число для переворачивания: ");
    scanf("%d", &number);
    printf("Число %d после переворачивания: %d\n", number, reverse_number(number));

    printf("Введите натуральное число для вывода всех 'счастливых' чисел до него: ");
    scanf("%d", &number);
    printf("Счастливые числа от 10 до %d: ", number);
    for (int i = 10; i <= number; i++) {
        if (is_lucky(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
