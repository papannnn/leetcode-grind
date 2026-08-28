class DynamicArray {
public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        length = 0;
        arr = reinterpret_cast<int*>(malloc(sizeof(int) * capacity));
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (length == capacity) {
            resize();
        }

        arr[length] = n;
        length++;
    }

    int popback() {
        int val = arr[--length];
        return val;
    }

    void resize() {
        int* temp = reinterpret_cast<int*>(malloc(sizeof(int) * capacity * 2));
        for (int i = 0; i < capacity; i++) {
            temp[i] = arr[i];
        }
        capacity *= 2;
        free(arr);
        arr = temp;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }

private:
    int* arr;
    int capacity;
    int length;
};
