#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

int sequentialSearchIterative(const vector<int>& book, int target) {
    for (int i = 0; i < book.size(); ++i) {
        if (book[i] == target) {
            return i + 1;
        }
    }
    return -1;
}

int sequentialSearchRecursive(const vector<int>& book, int target, int index) {
    if (index >= book.size()) return -1;
    if (book[index] == target) return index + 1;
    return sequentialSearchRecursive(book, target, index + 1);
}

int main() {
    int totalPages, target;
    cout << "Masukkan jumlah halaman dalam buku: ";
    cin >> totalPages;
    if (totalPages <= 0) {
        cout << "Jumlah halaman harus lebih dari 0.\n";
        return 1;
    }

    vector<int> book(totalPages);
    for (int i = 0; i < totalPages; ++i) book[i] = i + 1;

    cout << "Masukkan nomor halaman yang ingin dicari: ";
    cin >> target;
    if (target < 1 || target > totalPages) {
        cout << "Nomor halaman harus antara 1 hingga " << totalPages << ".\n";
        return 1;
    }

    const int iterations = 1000; // Jumlah iterasi untuk meningkatkan akurasi pengukuran waktu
    auto startIterative = high_resolution_clock::now();
    for (int i = 0; i < iterations; i++) {
        sequentialSearchIterative(book, target);
    }
    auto endIterative = high_resolution_clock::now();
    duration<double, milli> durationIterative = endIterative - startIterative;

    auto startRecursive = high_resolution_clock::now();
    for (int i = 0; i < iterations; i++) {
        sequentialSearchRecursive(book, target, 0);
    }
    auto endRecursive = high_resolution_clock::now();
    duration<double, milli> durationRecursive = endRecursive - startRecursive;

    cout << fixed << setprecision(6) << "Waktu eksekusi per iterasi (iteratif): "
         << (durationIterative.count() / iterations) << " milliseconds.\n";
    cout << "Waktu eksekusi per iterasi (rekursif): "
         << (durationRecursive.count() / iterations) << " milliseconds.\n";

    return 0;
}
