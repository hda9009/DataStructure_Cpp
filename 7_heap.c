#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class MinHeap
{
private:
    int *data;
    int capacity;
    int size;

    // Helpers to compute parent/child indices
    inline int parentIndex(int i) const { return (i - 1) / 2; }
    inline int leftIndex(int i) const { return 2 * i + 1; }
    inline int rightIndex(int i) const { return 2 * i + 2; }

    // Restore heap property by sifting down from index
    void siftDown(int index)
    {
        int smallest = index;
        int left = leftIndex(index);
        int right = rightIndex(index);

        if (left < size && data[left] < data[smallest])
            smallest = left;
        if (right < size && data[right] < data[smallest])
            smallest = right;

        if (smallest != index)
        {
            swap(data[index], data[smallest]);
            siftDown(smallest);
        }
    }

    // Restore heap property by sifting up from index
    void siftUp(int index)
    {
        while (index > 0)
        {
            int p = parentIndex(index);
            if (data[index] < data[p])
            {
                swap(data[index], data[p]);
                index = p;
            }
            else
            {
                // If no swap needed, ensure subtree below index is valid
                siftDown(index);
                break;
            }
        }
    }

public:
    explicit MinHeap(int capacity)
        : data(new int[capacity]), capacity(capacity), size(0) {}

    ~MinHeap() { delete[] data; }

    // Build heap from array arr of length n
    void buildFromArray(const int arr[], int n)
    {
        if (n > capacity)
        {
            cout << "Array size exceeds heap capacity\n";
            return;
        }
        for (int i = 0; i < n; ++i)
            data[i] = arr[i];
        size = n;
        for (int i = parentIndex(size - 1); i >= 0; --i)
            siftDown(i);
    }

    // Insert value into heap
    void insert(int value)
    {
        if (size == capacity)
        {
            cout << "Heap is full\n";
            return;
        }
        data[size] = value;
        ++size;
        siftUp(size - 1);
    }

    // Return minimum element without removing it
    int getMin() const
    {
        if (size == 0)
        {
            cout << "Heap is empty\n";
            return INT_MIN;
        }
        return data[0];
    }

    // Remove and return minimum element
    int extractMin()
    {
        if (size == 0)
        {
            cout << "Heap is empty\n";
            return INT_MIN;
        }
        int minVal = data[0];
        data[0] = data[size - 1];
        --size;
        if (size > 0)
            siftDown(0);
        return minVal;
    }

    // Decrease the value at index to newValue and fix heap
    void decreaseKey(int index, int newValue)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds\n";
            return;
        }
        data[index] = newValue;
        siftUp(index);
    }

    // Delete element at index
    void deleteAt(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds\n";
            return;
        }
        // Set to INT_MIN, sift up to root, then extract
        decreaseKey(index, INT_MIN);
        extractMin();
    }

    // Print heap array (level-order)
    void print() const
    {
        for (int i = 0; i < size; ++i)
            cout << data[i] << ' ';
        cout << '\n';
    }
};

class MaxHeap
{
private:
    int *data;
    int capacity;
    int size;

    inline int parentIndex(int i) const { return (i - 1) / 2; }
    inline int leftIndex(int i) const { return 2 * i + 1; }
    inline int rightIndex(int i) const { return 2 * i + 2; }

    // Sift down to maintain max-heap property
    void siftDown(int index)
    {
        int largest = index;
        int left = leftIndex(index);
        int right = rightIndex(index);

        if (left < size && data[left] > data[largest])
            largest = left;
        if (right < size && data[right] > data[largest])
            largest = right;

        if (largest != index)
        {
            swap(data[index], data[largest]);
            siftDown(largest);
        }
    }

    // Sift up to maintain max-heap property
    void siftUp(int index)
    {
        while (index > 0)
        {
            int p = parentIndex(index);
            if (data[index] > data[p])
            {
                swap(data[index], data[p]);
                index = p;
            }
            else
            {
                siftDown(index);
                break;
            }
        }
    }

public:
    explicit MaxHeap(int capacity)
        : data(new int[capacity]), capacity(capacity), size(0) {}

    ~MaxHeap() { delete[] data; }

    // Build max-heap from array
    void buildFromArray(const int arr[], int n)
    {
        if (n > capacity)
        {
            cout << "Array size exceeds heap capacity\n";
            return;
        }
        for (int i = 0; i < n; ++i)
            data[i] = arr[i];
        size = n;
        for (int i = parentIndex(size - 1); i >= 0; --i)
            siftDown(i);
    }

    // Insert value into max-heap
    void insert(int value)
    {
        if (size == capacity)
        {
            cout << "Heap is full\n";
            return;
        }
        data[size] = value;
        ++size;
        siftUp(size - 1);
    }

    // Get maximum element
    int getMax() const
    {
        if (size == 0)
        {
            cout << "Heap is empty\n";
            return INT_MIN;
        }
        return data[0];
    }

    // Extract maximum element
    int extractMax()
    {
        if (size == 0)
        {
            cout << "Heap is empty\n";
            return INT_MIN;
        }
        int maxVal = data[0];
        data[0] = data[size - 1];
        --size;
        if (size > 0)
            siftDown(0);
        return maxVal;
    }

    // Replace value at index and fix heap (for decreasing a key in max-heap)
    void replaceKey(int index, int newValue)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds\n";
            return;
        }
        data[index] = newValue;
        // If newValue is larger, sift up; otherwise sift down
        if (index > 0 && data[index] > data[parentIndex(index)])
            siftUp(index);
        else
            siftDown(index);
    }

    void print() const
    {
        for (int i = 0; i < size; ++i)
            cout << data[i] << ' ';
        cout << '\n';
    }
};

// Example usage
int main()
{
    int arr[8] = {30, 50, 25, 10, 70, 75, 5, 15};

    MinHeap minHeap(16);
    minHeap.buildFromArray(arr, 8);
    cout << "MinHeap: ";
    minHeap.print();

    cout << "Extracted Min: " << minHeap.extractMin() << '\n';
    cout << "MinHeap after extract: ";
    minHeap.print();

    cout << "Current Min: " << minHeap.getMin() << '\n';

    // Demonstrate decreaseKey and deleteAt
    minHeap.decreaseKey(1, 8); // decrease value at index 1 to 8
    cout << "MinHeap after decreaseKey at index 1 to 8: ";
    minHeap.print();

    minHeap.deleteAt(2); // delete element at index 2
    cout << "MinHeap after deleteAt index 2: ";
    minHeap.print();

    // MaxHeap demo
    MaxHeap maxHeap(16);
    maxHeap.buildFromArray(arr, 8);
    cout << "MaxHeap: ";
    maxHeap.print();

    cout << "Extracted Max: " << maxHeap.extractMax() << '\n';
    cout << "MaxHeap after extract: ";
    maxHeap.print();

    return 0;
}
