// Lab_Sort_GagulinaPolina.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


/*Quick Sort*/
template <typename T> // Объявление шаблонной функции с одним параметром 
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high]; // Выбор опорного элемента
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
int randomPartition(std::vector<T>& arr, int low, int high) {
    std::random_device rd;
    std::mt19937 gen(rd());// Генератор случайных чисел
    std::uniform_int_distribution<int> dis(low, high);
    int randomIndex = dis(gen);
    std::swap(arr[randomIndex], arr[high]);

    return partition(arr, low, high);
}

template <typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

template <typename T>
void printVector(const std::vector<T>& arr) { // Функция для вывода на экран
    for (const T& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

/*BubbleSort*/
template <typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/*BucketSort*/
template <typename T>
void bucketSort(std::vector<T>& arr) {
    int n = arr.size();

    std::vector<std::vector<T>> buckets(n);

    // Распределение элементов 
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];

        buckets[bucketIndex].push_back(arr[i]);
    }

    // Сортировка элементов в каждом bucket
    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // Слияние элементов из bucket в исходный массив
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

/*InsertionSort*/

template<typename T>
void insertionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {

    /*Quick Sort*/

    std::vector<int> intArr = { 64, 34, 25, 12, 22, 11, 90 };
    std::vector<double> doubleArr = { 3.14, 2.71, 1.618, 0.0, -1.0 };

    std::cout << "Original array (Quick Sort_int) : ";
    printVector(intArr);

    quickSort(intArr, 0, intArr.size() - 1);

    std::cout << "Sorted int array: Quick Sort  ";
    for (int i = 0; i < intArr.size(); i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << "\n" << std::endl;


    std::cout << "Original array (Quick Sort_double): ";
    printVector(doubleArr);

    quickSort(doubleArr, 0, doubleArr.size() - 1);

    std::cout << "Sorted double array: Quick Sort  ";
    for (int i = 0; i < doubleArr.size(); i++) {
        std::cout << doubleArr[i] << " ";
    }

    std::cout << "\n";
    std::cout << std::endl;


    /*BubbleSort*/
    std::vector<int> arr_bubble = { 64, 34, 25, 12, 22, 11, 90 };
    std::vector<double> doubleArrbubble = { 3.14, 2.71, 1.618, 0.0, -1.0 };

    std::cout << "Original array (BubbleSort_int): ";
    for (int num : arr_bubble) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    bubbleSort(arr_bubble);

    std::cout << "Sorted array (BubbleSort_int):  ";
    printVector(arr_bubble);
    std::cout << std::endl;

    std::cout << "Original array (BubbleSort_double):  ";
    printVector(doubleArrbubble);

    bubbleSort(doubleArrbubble);

    std::cout << "Sorted array: BubbleSort_double ";
    for (double num : doubleArrbubble) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "\n" << std::endl;


    /*BucketSort*/

    std::vector<float> arr_bucket1 = { 0.8, 0.2, 0.6, 0.3, 0.1, 0.9, 0.5, 0.7, 0.4 };

    std::cout << "Original array bucketSort: ";
    for (float num : arr_bucket1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    bucketSort(arr_bucket1);

    std::cout << "Sorted array bucketSort: ";

    for (int i = 0; i < arr_bucket1.size(); i++) {
        std::cout << arr_bucket1[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "\n" << std::endl;


    /*InsertionSort*/
    std::vector<int> arr_insertion = { 8, 2, 6, 3, 1, 9, 5, 7, 4 };

    std::cout << "Original array InsertionSort: ";
    for (int num : arr_insertion) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    insertionSort(arr_insertion);

    std::cout << "Sorted array InsertionSort: ";

    for (int i = 0; i < arr_insertion.size(); i++) {
        std::cout << arr_insertion[i] << " ";
    }

    std::cout << std::endl;


    return 0;
}
