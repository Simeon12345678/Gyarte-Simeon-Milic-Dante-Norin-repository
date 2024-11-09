package Algorithms.Algorithm1Java;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class IntroSortCustom {
    private int arr[]; // acts as the array that will be sorted
    private int n; // size

    IntroSortCustom(int n) {
        arr = new int[n];
        this.n = 0;
    }

    private void append(int temp) {
        arr[n] = temp;
        n++;
    }

    // swaps between to elements
    private void swap(int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private void maxHeap(int i, int heapN, int begin) {
        int temp = arr[begin + i - 1];
        int child;

        while (i <= heapN / 2) {
            child = 2 * i;

            if (child <= heapN && arr[begin + child - 1] < arr[begin + child]) {
                child++;
            }

            if (temp >= arr[begin + child - 1]) {
                break;
            }

            arr[begin + i - 1] = arr[begin + child - 1];
            i = child;
        }
        arr[begin + i - 1] = temp;
    }

    private void createHeap(int begin, int end, int heapN) {
        for (int i = (heapN) / 2; i >= 1; i--) {
            maxHeap(i, heapN, begin);
        }
    }

    private void heapSort(int begin, int end) {
        int heapN = end - begin;

        this.createHeap(begin, end, heapN);

        for (int i = heapN; i >= 1; i--) {
            swap(begin, begin + i);
            maxHeap(1, i, begin);
        }
    }

    private void insertionSort(int left, int right) {
        for (int i = left; i <= right; i++) {
            int key = arr[i];
            int j = i;

            while(j > left && arr[j - 1] > key) {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = key;
        }
    }

    private int findPivot(int a, int b, int c) {
        int max = Math.max(Math.max(arr[a], arr[b]), arr[c]);
        int min = Math.min(Math.min(arr[a], arr[b]), arr[c]);
        int median = max ^ min ^ arr[a] ^ arr[b] ^ arr[c];
        if (median == arr[a]) {
            return a;
        }
        if (median == arr[b]) {
            return b;
        }
        return c;
    }

    private int partition(int low, int high) {
        int pivot = arr[high];

        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(i, j);
            }
        }
        swap(i + 1, high);
        return (i + 1);
    }

    private void introSortUtil(int begin, int end, int depthLimit) {
        if (end - begin > 16) {
            if (depthLimit == 0) {
                this.heapSort(begin, end);
                return;
            }

            depthLimit -= depthLimit;
            int pivot = findPivot(begin, begin + ((end - begin) / 2) + 1, end);
            swap(pivot, end);

            int p = partition(begin, end);

            introSortUtil(begin, p - 1, depthLimit);
            introSortUtil(p + 1, end, depthLimit);
        } else {
            insertionSort(begin, end);
        }
    }

    private void introSort() {
        int depthLimit = (int)(2 * Math.floor(Math.log(n) / Math.log(2)));

        this.introSortUtil(0, n - 1, depthLimit);
    }

        // creates the array
    static List<Integer> createArray(int size) {
        Random rand = new Random();
        List<Integer> arr = new ArrayList<Integer>();
        for (int i = 0; i < size - 1; i++) {
            arr.add(rand.nextInt(1000 + 1));
        }
        return arr;
    }
    public static void main(String[] args) {
        List<Integer> arr = createArray(10);;

        int array[] = new int[arr.size()];
        int size = arr.size();

        for (int i = 0; i < size; i++) {
            array[i] = arr.get(i);
        }

        long start = System.currentTimeMillis();
        IntroSortCustom introSort = new IntroSortCustom(size);
        for (int i = 0; i < size; i++) {
            introSort.append(array[i]);
        }

        introSort.introSort();
        long end = System.currentTimeMillis();
        float millisec = (end - start);
        System.out.println("Sorted array: ");
        for (int i : array) {
            System.out.println(" + " + array[i]);
        }
        System.out.println("Time taken " + millisec + "Ms");
    }
}
