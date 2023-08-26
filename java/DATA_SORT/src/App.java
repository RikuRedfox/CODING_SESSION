import java.util.*;

// BubbleSort, SelectionSort, InsertSort, QuickSort, MergeSort, HeapSort 
// System.out.printf("Step %d. -> %s\n", i, Arrays.toString(arr));

public class App {
    private static int count;
    private static final byte LENGTH_OF_ARRAY = 10;

    static void BubbleSort(Integer[] arr) {
        int Length = arr.length;
        for (int i = 0; i < Length - 1; i++) {
            boolean swap = false;
            for (int j = 0; j < Length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;

                    swap = true;
                }
            }
            if (!swap)
                break;
            System.out.printf("Step %d. -> %s\n", i + 1, Arrays.toString(arr));
        }
    }

    static void SelectionSort(Integer[] arr) {
        int Length = arr.length;
        for (int i = 0; i < Length - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < Length; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            System.out.printf("Step %d. -> %s\n", i + 1, Arrays.toString(arr));
        }
    }

    static void InsertSort(Integer[] arr) {
        int Length = arr.length;
        for (int i = 1; i < Length; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
            System.out.printf("Step %d. -> %s\n", i, Arrays.toString(arr));
        }
    }

    static void QuickSort(Integer[] arr, int low, int high) {
        if (low < high) {
            int pivot = partition(arr, low, high);
            QuickSort(arr, low, pivot - 1);
            QuickSort(arr, pivot + 1, high);
        }
    }

    private static int partition(Integer[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        System.out.printf("Step %d. -> %s\n", count++, Arrays.toString(arr));
        return i + 1;
    }

    static void MergeSort(Integer[] arr, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            MergeSort(arr, left, mid);
            MergeSort(arr, mid + 1, right);
            Merge(arr, left, mid, right);
        }
    }

    private static void Merge(Integer[] arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        Integer[] L = new Integer[n1];
        Integer[] R = new Integer[n2];

        for (int i = 0; i < n1; i++) {
            L[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (i < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
        System.out.printf("Step %d. -> %s\n", count++, Arrays.toString(arr));
    }

    static void HeapSort(Integer[] arr) {
        final int Length = arr.length;
        for (int i = Length / 2 - 1; i >= 0; i--) {
            heapify(arr, Length, i);
        }

        for (int i = Length - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, Length, 0);
            System.out.printf("Step %d. -> %s\n", count++, Arrays.toString(arr));
        }
    }

    private static void heapify(Integer[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left].compareTo(arr[largest]) > 0) {
            largest = left;
        }
        if (right < n && arr[right].compareTo(arr[largest]) > 0) {
            largest = right;
        }

        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            heapify(arr, n, largest);
        }
    }

    private static Set<Integer> getRandom() {
        Random random = new Random();
        Set<Integer> SetOfRandomNumber = new HashSet<>(LENGTH_OF_ARRAY);
        while (SetOfRandomNumber.size() < LENGTH_OF_ARRAY)
            SetOfRandomNumber.add(random.nextInt(500) + 1);

        return SetOfRandomNumber;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Integer[] numbers = new Integer[LENGTH_OF_ARRAY];
        numbers = getRandom().toArray(numbers);

        final String[] OPERATIONS = { "1.) Bubble Sort", "2.) Selection Sort",
                "3.) Insert Sort", "4.) Quick Sort", "5.) Merge Sort",
                "6.) Heap Sort", "0.) Exit Program" };

        while (true) {
            System.out.printf("Original Array: %s\n", Arrays.toString(numbers));
            for (var items : OPERATIONS)
                System.out.println(items);

            int choose;
            try {
                System.out.print("\nEnter Operation: ");
                choose = scanner.nextInt();
            } catch (Exception e) {
                System.out.println(e);
                Terminal.pauseConsole();
                scanner.next();
                continue;
            }

            Terminal.clearConsole();
            System.out.printf("Original Array: %s\n", Arrays.toString(numbers));
            switch (choose) {
                case 1 -> {
                    System.out.println("Bubble Sort:");
                    BubbleSort(numbers.clone());
                }
                case 2 -> {
                    System.out.println("Selection Sort:");
                    SelectionSort(numbers.clone());
                }
                case 3 -> {
                    System.out.println("Insert Sort:");
                    InsertSort(numbers.clone());
                }
                case 4 -> {
                    count = 1;
                    System.out.println("Quick Sort:");
                    QuickSort(numbers.clone(), 0, numbers.length - 1);
                }
                case 5 -> {
                    count = 1;
                    System.out.println("Merge Sort:");
                    MergeSort(numbers.clone(), 0, numbers.length - 1);
                }
                case 6 -> {
                    count = 1;
                    System.out.println("Heap Sort:");
                    HeapSort(numbers.clone());
                }
                case 0 -> {
                    scanner.close();
                    System.exit(0);
                }
                default -> {
                    System.out.println("Invalid Input. Try again.");
                }
            }
            Terminal.pauseConsole();
        }
    }
}
