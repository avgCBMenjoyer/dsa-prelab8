#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        int parentIndex = (index - 1) / 2;
        while (index > 0 && heap[index] < heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
            smallest = leftChild;
        if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() {}

    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        if (heap.empty()) {
            std::cerr << "Heap is empty!" << std::endl;
            return -1; // Or throw an exception
        }

        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return minValue;
    }

    bool empty() const {
        return heap.empty();
    }
};

int main() {
    MinHeap minHeap;

    minHeap.push(3);
    minHeap.push(2);
    minHeap.push(1);
    minHeap.push(4);

    std::cout << "Popping elements from the min heap: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}
