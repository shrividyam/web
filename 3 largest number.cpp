#include <stdio.h>

void find_three_largest(int numbers[], int size, int largest[]) {
    if (size < 3) {
        printf("Please enter at least 3 numbers.\n");
        return;
    }

    // Initialize the three largest numbers
    largest[0] = largest[1] = largest[2] = -2147483648; // Smallest possible int value

    for (int i = 0; i < size; i++) {
        if (numbers[i] > largest[0]) {
            largest[2] = largest[1];
            largest[1] = largest[0];
            largest[0] = numbers[i];
        } else if (numbers[i] > largest[1]) {
            largest[2] = largest[1];
            largest[1] = numbers[i];
        } else if (numbers[i] > largest[2]) {
            largest[2] = numbers[i];
        }
    }
}

int main() {
    int n;

    // User input for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];

    // User input for the numbers
    printf("Enter %d numbers separated by space: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int largest[3];
    find_three_largest(numbers, n, largest);

    if (n >= 3) {
        printf("The largest three numbers are: %d, %d, %d\n", largest[0], largest[1], largest[2]);
    }

    return 0;
}
