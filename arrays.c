#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// ===== Задача 1: Отношение четных к положительным =====
void task1() {
    printf("=== Задача 1: Отношение четных к положительным ===\n");

#define NMAX 20  
#define MIN -50
#define MAX 50

    int arr[NMAX];
    int i;
    int positive_count = 0;
    int even_count = 0;
    double ratio;

    printf("Массив из %d элементов:\n", NMAX);
    for (i = 0; i < NMAX; i++) {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
        printf("%4d", arr[i]);
    }
    printf("\n\n");

    for (i = 0; i < NMAX; i++) {
        if (arr[i] > 0) {
            positive_count++;
        }
        if (arr[i] % 2 == 0) {
            even_count++;
        }
    }

    if (positive_count > 0) {
        ratio = (double)even_count / positive_count;
        printf("Количество положительных элементов: %d\n", positive_count);
        printf("Количество четных элементов: %d\n", even_count);
        printf("Отношение четных к положительным: %.3f\n", ratio);
    }
    else {
        printf("В массиве нет положительных элементов, отношение вычислить невозможно.\n");
    }
    printf("\n");
}

// ===== Функции для задачи 2 =====
void fillArray(int arr[], int size, int minVal, int maxVal) {
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

void printArray(int arr[], int size) {
    printf("Индексы: ");
    for (int i = 0; i < size; i++) {
        printf("%4d ", i);
    }
    printf("\nЗначения: ");
    for (int i = 0; i < size; i++) {
        printf("%4d ", arr[i]);
    }
    printf("\n");
}

int countInRange(int arr[], int size, int K, int L, int A, int B) {
    int count = 0;
    for (int i = K; i <= L; i++) {
        if (arr[i] < A || arr[i] > B) {
            count++;
        }
    }
    return count;
}

void task2() {
    printf("=== Задача 2: Элементы вне диапазона ===\n");

#define NMAX2 25 
#define MIN_VAL2 -100
#define MAX_VAL2 100

    int arr[NMAX2];
    int K, L;
    int A, B;
    int count;

    fillArray(arr, NMAX2, MIN_VAL2, MAX_VAL2);

    printf("Массив из %d элементов:\n", NMAX2);
    printArray(arr, NMAX2);

    printf("\nВведите границы диапазона индексов K и L (0 <= K <= L < %d):\n", NMAX2);
    printf("K = ");
    scanf("%d", &K);
    printf("L = ");
    scanf("%d", &L);

    if (K < 0 || L >= NMAX2 || K > L) {
        printf("Ошибка: некорректные границы индексов!\n");
        printf("Должно быть: 0 <= K <= L < %d\n", NMAX2);
        return;
    }

    printf("\nВведите границы диапазона значений A и B:\n");
    printf("A = ");
    scanf("%d", &A);
    printf("B = ");
    scanf("%d", &B);

    if (A > B) {
        printf("Ошибка: A должно быть меньше или равно B!\n");
        return;
    }

    count = countInRange(arr, NMAX2, K, L, A, B);

    printf("\nРезультаты:\n");
    printf("Диапазон индексов: [%d, %d]\n", K, L);
    printf("Диапазон значений: [%d, %d]\n", A, B);
    printf("Количество элементов с индексами от %d до %d,\n", K, L);
    printf("значения которых НЕ находятся в диапазоне [%d, %d]: %d\n", A, B, count);

    printf("\nЭлементы с индексами от %d до %d:\n", K, L);
    for (int i = K; i <= L; i++) {
        int value = arr[i];
        int isOutside = (value < A || value > B);
        printf("arr[%d] = %4d %s\n", i, value,
            isOutside ? "<- не в диапазоне" : "");
    }
    printf("\n");
}

// ===== Функции для задачи 3 =====
void fillArrayDouble(double arr[], int size, double minVal, double maxVal) {
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + (double)rand() / RAND_MAX * (maxVal - minVal);
    }
}

void printArrayDouble(double arr[], int size, const char* name) {
    printf("\nМассив %s[%d]:\n", name, size);
    printf("Индекс:  ");
    for (int i = 0; i < size; i++) {
        printf("%4d  ", i);
    }
    printf("\nЗначение: ");
    for (int i = 0; i < size; i++) {
        printf("%6.2f ", arr[i]);
    }
    printf("\n");
}

void processArrays(double a[], double b[], double c[], int n, int m, int k) {
    int i;

    printf("\n1. Обработка массива a (размер %d):\n", n);
    printf("   Дробные части элементов:\n");
    for (i = 0; i < n; i++) {
        double intPart, fracPart;
        fracPart = modf(fabs(a[i]), &intPart);
        if (a[i] < 0) fracPart = -fracPart;

        printf("   a[%d] = %6.2f -> дробная часть = %6.2f\n", i, a[i], fracPart);
        a[i] = fracPart;
    }

    printf("\n2. Обработка массива b (размер %d):\n", m);
    printf("   Целые части элементов:\n");
    for (i = 0; i < m; i++) {
        double intPart, fracPart;
        fracPart = modf(b[i], &intPart);

        printf("   b[%d] = %6.2f -> целая часть = %6.0f\n", i, b[i], intPart);
        b[i] = intPart;
    }

    printf("\n3. Обработка массива c (размер %d):\n", k);
    printf("   Отрицательные значения заменяются на их модули:\n");
    for (i = 0; i < k; i++) {
        if (c[i] < 0) {
            printf("   c[%d] = %6.2f -> модуль = %6.2f\n", i, c[i], fabs(c[i]));
            c[i] = fabs(c[i]);
        }
    }

    printf("\n4. Дополнительные вычисления:\n");

    double sumA = 0;
    for (i = 0; i < n; i++) sumA += a[i];
    double avgA = sumA / n;
    printf("   Среднее арифметическое массива a (дробных частей): %.4f\n", avgA);

    double sumB = 0;
    for (i = 0; i < m; i++) sumB += b[i];
    double avgB = sumB / m;
    printf("   Среднее арифметическое массива b (целых частей): %.2f\n", avgB);

    double sumPosC = 0;
    int countPosC = 0;
    for (i = 0; i < k; i++) {
        if (c[i] > 0) {
            sumPosC += c[i];
            countPosC++;
        }
    }
    printf("   Сумма положительных элементов массива c: %.2f (количество: %d)\n",
        sumPosC, countPosC);
}

void task3() {
    printf("=== Задача 3: Обработка массивов double ===\n");

#define N 15 
#define M 10  
#define K 12  
#define MIN_VAL3 -50.0
#define MAX_VAL3 50.0

    double a[N], b[M], c[K];

    fillArrayDouble(a, N, MIN_VAL3, MAX_VAL3);
    fillArrayDouble(b, M, MIN_VAL3, MAX_VAL3);
    fillArrayDouble(c, K, MIN_VAL3, MAX_VAL3);

    printf("ИСХОДНЫЕ МАССИВЫ:\n");
    printArrayDouble(a, N, "a");
    printArrayDouble(b, M, "b");
    printArrayDouble(c, K, "c");

    printf("\nОБРАБОТКА МАССИВОВ:\n");
    processArrays(a, b, c, N, M, K);

    printf("\nРЕЗУЛЬТИРУЮЩИЕ МАССИВЫ:\n");
    printArrayDouble(a, N, "a");
    printArrayDouble(b, M, "b");
    printArrayDouble(c, K, "c");
    printf("\n");
}

// ===== Функции сортировок для задачи 4 =====
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void cocktailSort(int arr[], int n) {
    int swapped = 1;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = 0;

        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped) break;

        swapped = 0;
        end--;

        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
        start++;
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

void testSort(void (*sortFunc)(int[], int), int arr[], int n, const char* name) {
    int* testArr = malloc(n * sizeof(int));
    copyArray(arr, testArr, n);

    clock_t start = clock();
    sortFunc(testArr, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%-15s: Время = %.6f секунд\n", name, time_taken);

    free(testArr);
}

void task4() {
    printf("=== Задача 4: Сравнение сортировок ===\n");

    printf("СРАВНЕНИЕ ПРОСТЫХ СОРТИРОВОК\n");
    printf("============================\n\n");

    int sizes[] = { 100, 1000, 10000 };
    int num_sizes = 3;

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        printf("РАЗМЕР МАССИВА: %d элементов\n", n);
        printf("--------------------------------\n");

        int* originalArr = malloc(n * sizeof(int));
        generateRandomArray(originalArr, n);

        testSort(selectionSort, originalArr, n, "Выбором");
        testSort(bubbleSort, originalArr, n, "Пузырьковая");
        testSort(cocktailSort, originalArr, n, "Коктейльная");
        testSort(insertionSort, originalArr, n, "Вставками");

        free(originalArr);
        printf("\n");
    }
}