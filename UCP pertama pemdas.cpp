//no 1 jawaban adalah integer (bilangan bulat)
//integer adalah salah satu tipe data yang digunakan untuk menyimpan bilangan bulat
// int tambah (int , int b)
// {
//  return(a + b)
// }
//rentang nilainya tergantung pada platform tempat program di jalankan.
//floating (bilangan bulat)
//float tipe data float digunakan untuk menyimpan bilangan desimal dengan presisi yang lebih rendah
//string
// string tipe data string digunakan untuk menyimpan kumpulan karakter. dalam c++, string sebenarnya adalah objek yang terdapat dalam pusataka setandar
//Include the string library
//#include
// Create a string variable
//string greeting = "Hello";

// Output string value
//cout << greeting;

//no 2 
//for (kondisi awal, kondisi akhir, pengubah kondisi)
//{
//	proses yang di ulang
//}
// while (kondisi)
// {
//	proses yang di ulat
// }


//}
//no 3 
//struct DetailAlamat{
// string desa;
// string kota;
// }
//




//no 4
// switch (kondisi)
//{
//	case konstanta1:______________
//					break,
//	case konstanta2:______________
//					break,
//	case konstanta3:______________
//					break,
// default :__________
//			break
// }



// no 5
//	#include <iostream>
//	using namespace std;
//
//	int sisi;
//
//	void inputdata() {
//		cout << "MAsukan nilai sisi :";
//		cin >> sisi;
//	}
//	int hitungluas() {
//		return sisi * sisi;
//	}
// 
//	void display() {
//		cout << "Luas persegi :" << hitungluas() << endl;
//	}
//	int main() {

//		inputdata();
//	display();
//}



//no  6
//program a
#include <iostream>
using namespace std;

struct Node {
    int noMhs;
    string name;
    Node* next;
};


Node* START = NULL;

void addNode() {
    int nim;
    string nama;
    Node* nodeBaru = new Node();
    cout << "Masukkan NIM: ";
    cin >> nim;
    cout << "Masukkan Nama: ";
    cin >> nama;
    nodeBaru->noMhs = nim;
    nodeBaru->name = nama;

    if (START == NULL || nim <= START->noMhs) {
        if (START != NULL && nim == START->noMhs)
        {
            cout << "NIM sudah ada" << endl;
            return;
        }

        nodeBaru->next = START;
        START = nodeBaru;
        return;
    }

    Node* previous = START;
    Node* current = START;

    while ((current != NULL) && (nim >= current->noMhs))
    {
        if (nim == current->noMhs)
        {
            cout << "NIM sudah ada" << endl;
            return;
        }
        previous = current;
        current = current->next;
    }

    nodeBaru->next = current;
    previous->next = nodeBaru;
}

bool searchNode(int nim, Node* current, Node* previous) {
    previous = START;
    current = START;
    while (current != NULL && nim > current->noMhs)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        return false;
    }
    else if (current->noMhs == nim)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool deleteNode(int nim) {
    Node* current = START;
    Node* previous = START;
    if (searchNode(nim, previous, current) ==
        false)
        return false;
    previous->next = current->next;
    if (current == START)
        START = current->next;
    return true;
}

bool listEmpty() {
    if (START == NULL)
        return true;
    else
        return false;
}

void traverse() {
    if (listEmpty()) {
        cout << "List Kosong" << endl;
        system("pause");
        system("cls");
        return;
    }
    else {
        Node* currentNode = START;
        while (currentNode != NULL) {
            cout << "NIM: " << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
    }
}

void searchData() {
    if (listEmpty()) {
        cout << "List Kosong" << endl;
        system("pause");
        system("cls");
        return;
    }
    else {
        int nim;
        cout << "Masukkan NIM: ";
        cin >> nim;
        Node* currentNode = START;
        while (currentNode != NULL) {
            if (currentNode->noMhs == nim) {
                cout << "NIM: " << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
                return;
            }
            currentNode = currentNode->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }
}

int main()
{

	int  nilaiMatematika, nilaiBahasainggris, nRerata;
	string  status;

	cout << "Masukan Nilai Matematika = ";
	cin >> nilaiMatematika;

	cout << "Masukan Bahasa Inggris = ";
	cin >> nilaiBahasainggris;

	nRerata = (nilaiMatematika + nilaiBahasainggris) / 2;

	if (nRerata > 70) {
		status = "Lulus";
	}
	else if (nilaiMatematika > 80) {
		status = "Tidak Lulus";
	}
	else {
		status = "Tidak Lulus";
	}

	cout << "Nilai Matemarika = " << nilaiMatematika << endl;
	cout << "Nilai Bahasa Inggris = " << nilaiBahasainggris << endl;
	cout << "Statusnya Adalah " << status << endl;
	cout << "rata rata nilai = " << nRerata << endl;

    int pilihan;
    do
    {
        try
        {

            cout << "1. Tambah Data" << endl;
            cout << "2. Hapus Data" << endl;
            cout << "3. Tampilkan data" << endl;
            cout << "4. Cari Data" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;
            switch (pilihan)
            {
            case 1:
                addNode();
                cout << "Data Berhasil Ditambahkan" << endl;
                system("pause");
                system("cls");
                break;
            case 2:
                if (listEmpty())
                {
                    cout << "List kosong" << endl;
                    system("pause");
                    system("cls");
                    break;
                }

                int nim;
                cout << "Masukan NIM: ";
                cin >> nim;
                if (deleteNode(nim)) {
                    cout << "nim: " << nim << " berhasil dihapus" << endl;
                    system("pause");
                    system("cls");
                }
                else
                    cout << "Data tidak ditemukan" << endl;
                break;
            case 3:
                traverse();
                break;
            case 4:
                searchData();
                break;
            case 5:
                break;
            default:
                cout << "Pilihan tidak ada" << endl;
                break;
            }
        }
        catch (exception e)
        {
            cout << "Terjadi kesalahan" << endl;
        }

    } while (pilihan != 5);
	return (0);
}
