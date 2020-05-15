# LeeJaeYong

알고리즘 공부용 레포 😄

## 목차

| 제목        | 내용                                      | 기간                  |
| :---------- | ----------------------------------------- | --------------------- |
| 정렬 (sort) | 선택, 버블, 삽입 정렬/ 합병 정렬/ 퀵 정렬 | 2020.5.10 ~ 2020.5.17 |
|             |                                           | 2020.5.17 ~ 2020.5.24 |
|             |                                           |                       |
|             |                                           |                       |



## 정렬 (sort)

- 선택 정렬(selection sort)

  : 가장 큰 수를 선택하여 맨 뒤와 위치를 바꾸는 작업을 반복하는 알고리즘  

  1. 가장 큰 수 선택
  2. 위치 바꿈
  3. 1,2번 반복

```c++
void selectionSort(int *array, int n) {
    for (int i = n - 1; i > 0; i--) {
        int maxIndex = 0;
        for (int j = 0; j <= i; j++) {
            if (array[maxIndex] < array[j]) {
                maxIndex = j;
            }
        }
        swap(array[maxIndex], array[i]);
    }
}
```

- 버블 정렬(bubble sort)

  : 바로 뒤에 있는 수와 비교하여 크다면 위치를 바꾸는 작업을 반복하는 알고리즘

  1. 바로 뒤 수와 크기 비교
  2. 위치 바꿈
  3. 1,2번 반복

```c++
void bubbleSort(int *array, int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}
```

- 삽입정렬(insertion sort)

  : 앞에서부터 차례로 수 하나를 선택하여 맨앞까지 알맞은 위치에 삽입하는 알고리즘

```c++
void insertSort(int *array, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (array[j-1] > array[j]) {
                swap(array[j-1], array[j]);
            }
        }
    }
}
```

- 합병정렬(merge sort)

  : 분할정복법으로 1개까지 쪼갠후 다시 두개씩 정렬하면서 합치는 알고리즘

  1. 2개의 배열의 값들을 처음부터 하나씩 비교하여 두개의 배열 값 중 더 작은 값을 새 배열로 옮김
  2. 둘 중에 하나가 끝날 때까지 되풀이
  3. 만약 둘 중 하나의 배열이 먼저 끝나면 나머지 배열의 값들도 전부 새로운 배열로 옮긴다.
  4. 1~3작업을 재귀함수로 반복한다.

```c++
void merge(int *array, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];
    
    for (int i = 0 ; i < n1; i++) {
        L[i] = array[p + i];
    }
    for (int i = 0 ; i < n2; i++) {
        R[i] = array[q + 1 + i];
    }
    
    int i = 0, j = 0, k = p;
    while(i < n1 && j < n2) {
        if (L[i] < R[i]) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }
    
    while(i < n1) {
        array[k++] = L[i++];
    }
    while(j < n2) {
        array[k++] = R[j++];
    }
    
}
void mergeSort(int *array, int p, int r) {
    if (p < r) {// p>=r일 경우 정렬할 필요가 없기 때문
        int q = (p + r) / 2;
        mergeSort(array, p, q);
        mergeSort(array, q+1, r);
        merge(array, p, q, r);
    }
}
```

