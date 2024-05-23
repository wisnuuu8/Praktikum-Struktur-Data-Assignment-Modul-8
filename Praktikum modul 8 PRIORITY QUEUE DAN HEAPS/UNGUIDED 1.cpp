#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

// Fungsi untuk mendapatkan indeks parent, kiri, dan kanan
int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

// Fungsi untuk memperbaiki heap ke atas (shift up)
void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

// Fungsi untuk memperbaiki heap ke bawah (shift down)
void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

// Fungsi untuk membangun heap dari sebuah array
void buildHeap(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        H[i] = arr[i];
        heapSize++;
    }
    for (int i = (heapSize - 1) / 2; i >= 0; --i) {
        shiftDown(i);
    }
}

// Fungsi untuk menyisipkan elemen baru ke dalam heap
void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

// Fungsi untuk mengekstrak elemen dengan prioritas tertinggi dari heap
int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

// Fungsi untuk mengubah prioritas sebuah elemen dalam heap
void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

// Fungsi untuk mendapatkan nilai prioritas tertinggi dalam heap
int getMax() {
    return H[0];
}

// Fungsi untuk menghapus elemen pada indeks tertentu dalam heap
void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n;
    std::cout << "Masukkan jumlah elemen: ";
    std::cin >> n;
    
    std::cout << "Masukkan elemen-elemen: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> H[i];
        heapSize++;
    }

    for (int i = (heapSize - 1) / 2; i >= 0; --i) {
        shiftDown(i);
    }

    std::cout << "Antrian Prioritas: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node dengan prioritas tertinggi: " << extractMax() << "\n";

    std::cout << "Antrian prioritas setelah mengekstrak nilai tertinggi : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    int index, priority;
    std::cout << "Masukkan indeks dan prioritas baru untuk diubah: ";
    std::cin >> index >> priority;
    changePriority(index, priority);

    std::cout << "Antrian prioritas setelah perubahan prioritas : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    int removeIndex;
    std::cout << "Masukkan indeks untuk dihapus: ";
    std::cin >> removeIndex;
    remove(removeIndex);

    std::cout << "Antrian prioritas setelah menghapus elemen : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }

    return 0;
}

