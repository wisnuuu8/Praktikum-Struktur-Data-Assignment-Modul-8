**BAB 1**

**PENDAHULUAN**

**LATAR BELAKANG**

### Priority Queue
**Priority Queue** adalah struktur data yang mirip dengan queue atau antrian biasa, tetapi setiap elemen memiliki "prioritas". Elemen dengan prioritas lebih tinggi akan dilayani lebih dulu dibandingkan elemen dengan prioritas lebih rendah, tanpa memperhatikan urutan kedatangan. Dua operasi utama yang dilakukan pada priority queue adalah:
1. **Enqueue (Insert)**: Menambahkan elemen ke dalam antrian dengan prioritas tertentu.
2. **Dequeue (Remove)**: Menghapus elemen dengan prioritas tertinggi dari antrian.

Priority queue dapat diimplementasikan menggunakan berbagai struktur data seperti array, linked list, heap, atau balanced binary search tree. Salah satu implementasi yang efisien adalah dengan menggunakan heap.

### Heaps
**Heap** adalah jenis khusus dari binary tree yang memenuhi sifat heap. Terdapat dua jenis heap utama:
1. **Max-Heap**: Di mana setiap parent node memiliki nilai yang lebih besar atau sama dengan nilai dari anak-anaknya.
2. **Min-Heap**: Di mana setiap parent node memiliki nilai yang lebih kecil atau sama dengan nilai dari anak-anaknya.

Ciri-ciri utama heap:
- **Complete Binary Tree**: Semua level binary tree, kecuali mungkin level terakhir, terisi penuh. Level terakhir diisi dari kiri ke kanan.
- **Heap Property**: Dalam max-heap, parent node lebih besar atau sama dengan anak-anaknya. Dalam min-heap, parent node lebih kecil atau sama dengan anak-anaknya.

Heap banyak digunakan untuk mengimplementasikan priority queue karena operasi insert dan delete-min/max dapat dilakukan dengan efisien dalam O(log n) waktu.

### Hubungan Priority Queue dan Heaps
Heap sering digunakan untuk mengimplementasikan priority queue karena struktur heap memungkinkan operasi insert dan delete yang efisien. Dalam kasus priority queue yang diimplementasikan dengan min-heap, elemen dengan prioritas tertinggi (nilai terkecil) selalu berada di root dan dapat dihapus dengan cepat. Sebaliknya, dalam max-heap, elemen dengan prioritas tertinggi (nilai terbesar) yang berada di root bisa dihapus dengan cepat.

**RUMUSAN MASALAH**

a. Bagaimana cara mahasiswa dapat menjelaskan definisi dan konsep dari priority queue dan heaps?

b. Bagaimana mahasiswa dapat menerapkan operasi-operasi pada heaps secara efektif?

c. Bagaimana mahasiswa dapat mengimplementasikan konsep priority queue dan heaps pada contoh kasus nyata?

**TUJUAN PRAKTIKUM**

a. Mahasiswa mampu menjelaskan definisi dan konsep dari priority queue dan
heaps

b. Mahasiswa mampu menerapkan operasi-operasi pada heaps

c. Mahasiswa mampu mengimplementasikan konsep priority queue dan heaps pada
contoh kasus nyata

**BAB 2**

**PEMBAHASAN**

**DASAR TEORI**

Priority Queue adalah jenis antrian yang mengatur elemen berdasarkan nilai prioritasnya, di mana elemen dengan prioritas lebih tinggi akan diambil lebih dulu dibandingkan elemen dengan prioritas lebih rendah. Setiap elemen dalam priority queue memiliki nilai prioritas yang menentukan posisinya dalam antrian. Terdapat berbagai metode untuk mengimplementasikan priority queue, seperti menggunakan array, linked list, heap, atau binary search tree, masing-masing dengan kelebihan dan kekurangannya. Priority queue sering digunakan dalam sistem real-time dan algoritma yang memerlukan efisiensi tinggi, seperti algoritma Dijkstra dan pencarian jalur A*.

Heap adalah struktur data berbasis pohon biner dengan dua aturan utama:

Complete Binary Tree: Setiap level pohon terisi penuh, kecuali mungkin level terakhir yang terisi dari kiri ke kanan.
Order Property: Heap terbagi menjadi max-heap dan min-heap.
Max-Heap: Nilai parent selalu lebih besar atau sama dengan anak-anaknya.
Min-Heap: Nilai parent selalu lebih kecil atau sama dengan anak-anaknya.
Dalam heap, nilai terbesar (max-heap) atau terkecil (min-heap) selalu berada di root. Heap digunakan dalam algoritma sorting seperti heap sort dan untuk mengimplementasikan priority queue. Heap menawarkan kecepatan operasi yang efisien dengan waktu O(log N) untuk menambah atau menghapus elemen, dan waktu konstan O(1) untuk mencari elemen minimum atau maksimum.

**GUIDED**

**GUIDED 1**
```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

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

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority : " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }

    return 0;
}
```
**Bagian 1**
```C++
#include <iostream>
#include <algorithm>
```
Interpretasi :

include iostream: Mengizinkan program untuk melakukan operasi input dan output standar.
include algorithm: Mengizinkan penggunaan algoritma standar yang disediakan oleh C++ untuk manipulasi data.

**Bagian 2**
```C++

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

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

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}
```
Interpretasi : 

Pada implementasi ini, H adalah array yang menyimpan elemen-elemen heap dan heapSize menyimpan ukuran heap saat ini, yang diinisialisasi dengan -1 menandakan heap kosong.

Terdapat beberapa fungsi penting dalam kode ini. Fungsi parent, leftChild, dan rightChild digunakan untuk menentukan posisi parent dan anak dari sebuah elemen pada heap. Fungsi shiftUp memperbaiki struktur heap dengan memindahkan elemen ke atas sampai properti max-heap terpenuhi, yaitu elemen parent selalu lebih besar atau sama dengan elemen anaknya. Sebaliknya, fungsi shiftDown memperbaiki struktur heap dengan memindahkan elemen ke bawah sampai properti max-heap terpenuhi.

Fungsi insert menambahkan elemen baru ke dalam heap. Elemen baru ditempatkan di akhir array, kemudian shiftUp dipanggil untuk memastikan properti max-heap tetap terjaga. Fungsi extractMax menghapus dan mengembalikan elemen terbesar (root) dari heap. Elemen terakhir dipindahkan ke root, kemudian shiftDown dipanggil untuk memperbaiki heap.

Fungsi changePriority digunakan untuk mengubah prioritas (nilai) elemen pada indeks tertentu. Jika nilai baru lebih besar, shiftUp dipanggil, dan jika lebih kecil, shiftDown dipanggil untuk menyesuaikan posisi elemen. Fungsi getMax mengembalikan elemen terbesar (root) tanpa menghapusnya dari heap. Terakhir, fungsi remove menghapus elemen pada indeks tertentu dengan mengubah nilai elemen tersebut menjadi lebih besar dari elemen terbesar saat ini, kemudian memindahkannya ke root menggunakan shiftUp, dan akhirnya menghapusnya menggunakan extractMax.

**Bagian 3**
```C++

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority : " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }

    return 0;
}
```
Interpretasi : 

Pertama, beberapa elemen dimasukkan ke dalam heap menggunakan fungsi insert, yaitu elemen 45, 20, 14, 12, 31, 7, 11, 13, dan 7. Setelah semua elemen dimasukkan, heap dicetak untuk menampilkan isinya. Selanjutnya, elemen dengan prioritas tertinggi (nilai maksimum) diekstraksi menggunakan fungsi extractMax, dan hasilnya dicetak. Heap kemudian dicetak kembali untuk menunjukkan perubahan setelah ekstraksi. Setelah itu, prioritas elemen pada indeks ke-2 diubah menjadi 49 menggunakan fungsi changePriority, dan heap yang telah diperbarui dicetak. Terakhir, elemen pada indeks ke-3 dihapus menggunakan fungsi remove, dan isi heap dicetak lagi untuk menunjukkan keadaan akhir dari heap setelah penghapusan elemen. Fungsi-fungsi seperti insert, extractMax, changePriority, dan remove mengatur ulang heap untuk mempertahankan properti max-heap setelah setiap operasi, memastikan bahwa elemen dengan prioritas tertinggi selalu berada di root heap.

## Hasil output 
```C++
Priority Queue : 45 31 14 13 20 7 11 12 7
Node with maximum priority : 45
Priority queue after extracting maximum : 31 20 14 13 7 7 11 12
Priority queue after priority change : 49 20 31 13 7 7 11 12
Priority queue after removing the element : 49 20 31 12 7 7 11
--------------------------------
Process exited after 0.08754 seconds with return value 0
Press any key to continue . . .
```

**UNGUIDED**

**UNGUIDED 1**
```C++
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
```
**Bagian 1**
```C++
#include <iostream>
#include <algorithm>
```
Interpretasi : 

include iostream: Mengizinkan program untuk melakukan operasi input dan output standar.
include algorithm: Mengizinkan penggunaan algoritma standar yang disediakan oleh C++ untuk manipulasi data.

**Bagian 2**
```C++
int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

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

void buildHeap(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        H[i] = arr[i];
        heapSize++;
    }
    for (int i = (heapSize - 1) / 2; i >= 0; --i) {
        shiftDown(i);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}
```
Interpretasi : 

Heap ini merupakan max-heap, di mana elemen terbesar selalu berada di root. Fungsi-fungsi seperti insert, extractMax, dan changePriority memungkinkan pengguna untuk menambah, menghapus, dan mengubah prioritas elemen dalam heap. Selain itu, terdapat fungsi-fungsi bantu seperti parent, leftChild, dan rightChild untuk membantu navigasi dalam heap. Proses pembangunan heap dilakukan menggunakan fungsi buildHeap yang menginisialisasi heap dari sebuah array. Algoritma shiftUp dan shiftDown digunakan untuk memastikan bahwa sifat-sifat heap tetap terjaga setelah operasi-operasi seperti penambahan atau penghapusan elemen. Dengan demikian, struktur data heap ini dapat digunakan untuk berbagai keperluan seperti pengurutan data, pencarian elemen maksimum, atau pengelolaan antrian berdasarkan prioritas dalam aplikasi-alikasi yang memerlukan penanganan efisien terhadap urutan elemen.

**Bagian 3**
```C++

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
```
Interpretasi : 

Pertama, program meminta pengguna untuk memasukkan jumlah elemen yang akan dimasukkan ke dalam priority queue, serta elemen-elemen tersebut. Selanjutnya, heap dibangun menggunakan metode shiftDown untuk memastikan bahwa properti heap terpenuhi. Setelah heap terbentuk, isi antrian prioritas ditampilkan kepada pengguna. Kemudian, program mengekstrak nilai prioritas tertinggi dari heap dan menampilkannya. Pengguna juga diberikan opsi untuk mengubah prioritas suatu elemen dengan memasukkan indeks elemen yang ingin diubah dan nilai prioritas baru. Operasi penghapusan elemen dari heap juga tersedia, di mana pengguna diminta untuk memasukkan indeks elemen yang akan dihapus. Setiap kali terjadi modifikasi pada priority queue, baik itu melalui ekstraksi nilai tertinggi, perubahan prioritas, atau penghapusan elemen, hasilnya ditampilkan kembali kepada pengguna. Keseluruhan implementasi ini memberikan pemahaman yang baik tentang konsep-konsep dasar priority queue dan heap, serta operasi-operasi yang dapat dilakukan pada struktur data tersebut.

## Hasil output 
```C++
Masukkan jumlah elemen: 3
Masukkan elemen-elemen: 1 2 3
Antrian Prioritas: 3 2 1
Node dengan prioritas tertinggi: 3
Antrian prioritas setelah mengekstrak nilai tertinggi : 2 1
Masukkan indeks dan prioritas baru untuk diubah: 2
Antrian prioritas setelah perubahan prioritas : 2 1
Masukkan indeks untuk dihapus: 2
Antrian prioritas setelah menghapus elemen : 1
--------------------------------
Process exited after 41.35 seconds with return value 0
Press any key to continue . . .
```

**DAFTAR PUSTAKA**
