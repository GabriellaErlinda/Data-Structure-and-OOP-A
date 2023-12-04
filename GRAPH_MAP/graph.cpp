#include <iostream>
#include <list>
#include <stack> 
#include <stdio.h>

using namespace std;

class Peta {
private:
  // Property
  int jumlah_titik;
  list<int> *adjacency_list;
  int **adjacency_matrix;

public:
  // Constructor
  Peta(int jumlah_titik) {
    this->jumlah_titik = jumlah_titik;
    inisialisasiAdjList(jumlah_titik);
    inisialisasiAdjMatrix(jumlah_titik);
  }

  // Destructor
  ~Peta() {
    delete[] adjacency_list;
    for (int i = 0; i < jumlah_titik; i++) {
      delete[] adjacency_matrix[i];
    }
    delete[] adjacency_matrix;
  }


  // Fungsi untuk inisialisasi adjacency list
  void inisialisasiAdjList(int jumlah_titik) {
    adjacency_list = new list<int>[jumlah_titik];
  }

  void inisialisasiAdjMatrix(int jumlah_titik) {
    adjacency_matrix = new int *[jumlah_titik];
    for (int i = 0; i < jumlah_titik; i++) 
      {
        adjacency_matrix[i] = new int[jumlah_titik];
        for (int j = 0; j < jumlah_titik; j++) {
          adjacency_matrix[i][j] = 0; //Inisialisasi matriks dengan nilai 0(tidak ada edge
      }
    }
  }

  // Fungsi untuk menambahkan koneksi dari titik awal ke tujuan
  void tambahLintasan(int titik_awal, int titik_tujuan) {
    // Update adjacency list
    adjacency_list[titik_awal - 1].push_back(titik_tujuan - 1);
    // Update adjacency matrix
    adjacency_matrix[titik_awal - 1][titik_tujuan - 1] = 1;
    adjacency_matrix[titik_tujuan - 1][titik_awal - 1] = 1;
  }

  // Fungsi untuk menampilkan adjacency list
  void tampilkanAdjList() {
    list<int>::iterator i;

    for (int v = 0; v < jumlah_titik; v++) {
      cout << v + 1 << " -> ";
      for (i = adjacency_list[v].begin(); i != adjacency_list[v].end(); ++i) {
        cout << (*i) + 1;
        if (next(i, 1) != adjacency_list[v].end()) {
          cout << " -> ";
        }
      }
      cout << endl;
    }
  }

  // Fungsi untuk menampilkan adjacency matrix
  void tampilkanAdjMatrix() {
    for (int i = 0; i < jumlah_titik; i++) {
      for (int j = 0; j < jumlah_titik; j++) {
        cout << adjacency_matrix[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  cout << "Peta Kos" << endl;
  int jumlah_titik = 10;

  Peta petaKu(jumlah_titik);

  //vertex 1
    petaKu.tambahLintasan(1, 2);
    petaKu.tambahLintasan(1, 3);
    petaKu.tambahLintasan(1, 4);
    petaKu.tambahLintasan(1, 7);
    petaKu.tambahLintasan(1, 9);
  //vertex 2
    petaKu.tambahLintasan(2, 1);
    petaKu.tambahLintasan(2, 3);
    petaKu.tambahLintasan(2, 4);
    petaKu.tambahLintasan(2, 6);
  //vertex 3
    petaKu.tambahLintasan(3, 1);
    petaKu.tambahLintasan(3, 2);
    petaKu.tambahLintasan(3, 6);
  //vertex 4
    petaKu.tambahLintasan(4, 1);
    petaKu.tambahLintasan(4, 2);
    petaKu.tambahLintasan(4, 5);
  //vertex 5
    petaKu.tambahLintasan(5, 4);
    petaKu.tambahLintasan(5, 6);
  //vertex 6
    petaKu.tambahLintasan(6, 2);
    petaKu.tambahLintasan(6, 3);
    petaKu.tambahLintasan(6, 5);
    petaKu.tambahLintasan(6, 10);
  //vertex 7
    petaKu.tambahLintasan(7, 1);
    petaKu.tambahLintasan(7, 8);
  //vertex 8
    petaKu.tambahLintasan(8, 7);
    petaKu.tambahLintasan(8, 9);
    petaKu.tambahLintasan(8, 10);
  //vertex 9
    petaKu.tambahLintasan(9, 1);
    petaKu.tambahLintasan(9, 8);
    petaKu.tambahLintasan(9, 10);
  //vertex 10
    petaKu.tambahLintasan(10, 6);
    petaKu.tambahLintasan(10, 8);
    petaKu.tambahLintasan(10, 9);

  cout << endl;
  cout << "Adjacency List" << endl;
  petaKu.tampilkanAdjList();

  cout << endl;
  cout << "Adjacency Matrix" << endl;
  petaKu.tampilkanAdjMatrix();
}
