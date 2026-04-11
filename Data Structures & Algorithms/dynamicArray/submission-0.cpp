class DynamicArray {
    int size;
    int capacity;
    int* arr;
public:
    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (size >= capacity) resize();
        arr[size++] = n;
    }

    int popback() {
        size -= 1;
        return arr[size];
    }

    void resize() {
        int* temp = new int[capacity*2];
        for (int i = 0; i < size; ++i) temp[i] = arr[i];
        capacity *= 2;
        delete[] arr;
        arr = temp;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
