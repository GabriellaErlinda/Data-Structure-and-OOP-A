#include <iostream>
#include <list>
#include <string>
#include <graphics.h>
using namespace std;

class Titik {
public:
    int id;
    string nama_tempat;
    double x;
    double y;

    Titik() : id(0), nama_tempat(""), x(0.0), y(0.0) {}

    Titik(int id, string nama_tempat, double x, double y) {
        this->id = id;
        this->nama_tempat = nama_tempat;
        this->x = x;
        this->y = y;
    }
};

class Peta {
private:
    int jumlah_titik;
    list<int> *adjacency_list;
    int **adjacency_matrix;
    Titik *titik_array;

public:
    Peta(int jumlah_titik) {
        this->jumlah_titik = jumlah_titik;
        inisialisasiAdjList(jumlah_titik);
        inisialisasiAdjMatrix(jumlah_titik);
        titik_array = new Titik[jumlah_titik];
    }

    ~Peta() {
        delete[] adjacency_list;
        for (int i = 0; i < jumlah_titik; i++) {
            delete[] adjacency_matrix[i];
        }
        delete[] adjacency_matrix;
        delete[] titik_array;
    }

    void inisialisasiAdjList(int jumlah_titik) {
        adjacency_list = new list<int>[jumlah_titik];
    }

    void inisialisasiAdjMatrix(int jumlah_titik) {
        adjacency_matrix = new int *[jumlah_titik];
        for (int i = 0; i < jumlah_titik; i++) {
            adjacency_matrix[i] = new int[jumlah_titik];
            for (int j = 0; j < jumlah_titik; j++) {
                adjacency_matrix[i][j] = 0;
            }
        }
    }

    void tambahLintasan(int titik_awal, int titik_tujuan) {
        adjacency_list[titik_awal - 1].push_back(titik_tujuan - 1);
        adjacency_matrix[titik_awal - 1][titik_tujuan - 1] = 1;
        adjacency_matrix[titik_tujuan - 1][titik_awal - 1] = 1;
    }

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

    void tampilkanAdjMatrix() {
        for (int i = 0; i < jumlah_titik; i++) {
            for (int j = 0; j < jumlah_titik; j++) {
                cout << adjacency_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void tambahTitik(int id, string nama_tempat, double x, double y) {
        titik_array[id - 1] = Titik(id, nama_tempat, x, y);
    }

    void tampilkanTitik() {
        for (int i = 0; i < jumlah_titik; i++) {
            cout << "Titik: " << titik_array[i].id << endl;
            cout << "Nama Tempat: " << titik_array[i].nama_tempat << endl;
            cout << "Koordinat (x, y): (" << titik_array[i].x << ", " << titik_array[i].y << ")" << endl;
            cout << endl;
        }
    }
};

int main() {
    cout << "Peta Rumah" << endl;
    int jumlah_titik = 10;

    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");

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

    petaKu.tambahTitik(1, "Home", 0.0, 0.0);
    petaKu.tambahTitik(2, "Badminton Court", -1.0, 2.0);
    petaKu.tambahTitik(3, "Basketball Court", -2.0, 2.0);
    petaKu.tambahTitik(4, "Noodle House", -7.0, 0.0);
    petaKu.tambahTitik(5, "Coffee Shop", -5.0, 4.0);
    petaKu.tambahTitik(6, "Mall", -1.0, 4.0);
    petaKu.tambahTitik(7, "Chicken Palace", 3.0, 0.0);
    petaKu.tambahTitik(8, "Bus Stop", 4.0, 1.0);
    petaKu.tambahTitik(9, "Homestay", 3.0, 2.0);
    petaKu.tambahTitik(10, "ITS hall", 6.0, 3.0);

    cout << endl;
    cout << "Adjacency List" << endl;
    petaKu.tampilkanAdjList();

    cout << endl;
    cout << "Adjacency Matrix" << endl;
    petaKu.tampilkanAdjMatrix();

    cout << endl;
    cout << "Informasi Titik" << endl;
    petaKu.tampilkanTitik();

    closegraph();
    return 0;
}