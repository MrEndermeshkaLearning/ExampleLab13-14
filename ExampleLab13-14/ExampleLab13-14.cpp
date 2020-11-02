#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#define SmallSizeArray 10
#define MiddleSizeArray 500
#define bigSizeArray 10000
#define largeSizeArray 100000
//в этой лабе ознакомлю вас с тем, как создавать свои собственные функции
//вам нужно написать следуюющую струру
// тип возвращаемого результата|название функции|(аргумменти функции) 
//         тело функции
// например: тип возвращаемой функции void(ничего не возвращает), 
//название insertSortArray, в аргументах сортируемый масив и его размер
//тип аргумента нужно писать каждый раз.

//сортировка вставками
void insertSortArray(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int k = i;
		while (k>0 && arr[k-1]>arr[k])
		{
			int temp = arr[k - 1];
			arr[k - 1] = arr[k];
			arr[k] = temp;
			k -= 1;
		}
	}
}
// Функция сортировки прямым обменом (метод "пузырька")
void selectSort(int arr[], int size)
{
    int tmp, i, j, pos;
    for (i = 0; i < size; ++i) // i - номер текущего шага
    {
        pos = i;
        tmp = arr[i];
        for (j = i + 1; j < size; ++j) // цикл выбора наименьшего элемента
        {
            if (arr[j] < tmp)
            {
                pos = j;
                tmp = arr[j];
            }
        }
        arr[pos] = arr[i];
        arr[i] = tmp; // меняем местами наименьший с a[i]
    }
}
// Функция сортировки вибором
void SortByChoose(int arr[], int n) {		
    int minPosition, temp;
        for (int i = 0; i < n; i++)
        {
            minPosition = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[minPosition] > arr[j]) {
                    minPosition = j;
                }
            }
            temp = arr[minPosition];
            arr[minPosition] = arr[i];
            arr[i] = temp;
        }
}
//функция сортировки Шелла
void ShellSort(int arr[], int n) {
    int i, j, step;
    int temp;
    for (step = n / 2; step > 0; step /= 2) {
        for (i = step; i < n; i++)
        {
            temp = arr[i];
            for (j = i; j >= step; j -= step)
            {
                if (temp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = temp;
        }
    }
}
//функция рандомного генерирования масива
void generateIntArr(int arr[], int leftBorderValue, int rightBorderValue, int ArrayLenth) {
    srand(time(NULL));
    for (int i = 0; i < ArrayLenth; i++) {
        arr[i] = rand() % (leftBorderValue - rightBorderValue) + leftBorderValue;
    }
}
int getNumberFromLine() {
    int x;
    scanf_s("%d", &x);
    return x;
}
int printAboutLenthArray() {
    printf("\n1.SmallSizeArray\n2.MiddleSizeArray\n3.bigSizeArray\n4.largeSizeArray\n");
    return getNumberFromLine();
}
void outputArray() {

}


int main() {
    while (true)
    {
        printf("Choose sort type:\n1.InsertSort\n2.SelectSort\n3.SortByChoose\n4.ShellSort\n0.Exit\n");
        int swithcer = getNumberFromLine();
        if (swithcer != 0) {
            int typeSwitcher = printAboutLenthArray();

            int arr[SmallSizeArray];
            generateIntArr(arr, -100, 120, SmallSizeArray);
            int arr1[MiddleSizeArray];
            generateIntArr(arr1, -100, 120, MiddleSizeArray);
            int arr2[bigSizeArray];
            generateIntArr(arr2, -100, 120, bigSizeArray);
            int arr3[largeSizeArray];
            generateIntArr(arr3, -100, 120, largeSizeArray);
            clock_t start, finish;

            start = clock();
            switch (swithcer)
            {
            case 1: {
                switch (typeSwitcher)
                {
                case 1:
                    insertSortArray(arr, SmallSizeArray);
                    break;
                case 2:
                    insertSortArray(arr1, MiddleSizeArray);
                    break;
                case 3:
                    insertSortArray(arr2, bigSizeArray);
                    break;
                case 4:
                    insertSortArray(arr3, largeSizeArray);
                    break;
                }
            }
                  break;
            case 2: {
                switch (typeSwitcher)
                {
                case 1:
                    selectSort(arr, SmallSizeArray);
                    break;
                case 2:
                    selectSort(arr1, MiddleSizeArray);
                    break;
                case 3:
                    selectSort(arr2, bigSizeArray);
                    break;
                case 4:
                    selectSort(arr3, largeSizeArray);
                    break;
                }
            }
                  break;
            case 3: {
                switch (typeSwitcher)
                {
                case 1:
                    SortByChoose(arr, SmallSizeArray);
                    break;
                case 2:
                    SortByChoose(arr1, MiddleSizeArray);
                    break;
                case 3:
                    SortByChoose(arr2, bigSizeArray);
                    break;
                case 4:
                    SortByChoose(arr3, largeSizeArray);
                    break;
                }
            }
                  break;
            case 4:
            {
                switch (typeSwitcher)
                {
                case 1:
                    ShellSort(arr, SmallSizeArray);
                    break;
                case 2:
                    ShellSort(arr1, MiddleSizeArray);
                    break;
                case 3:
                    ShellSort(arr2, bigSizeArray);
                    break;
                case 4:
                    ShellSort(arr3, largeSizeArray);
                    break;
                }
            }
            break;
            }
            finish = clock();
            printf("\ntime from start: %lf\n", (double)finish - start);
        }
        else
        {
            break;
        }
    }
}
