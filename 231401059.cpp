// TODO 1: Ubah nama file ini menjadi NIM Anda. Cth: 001.cpp, 042.cpp, 080.cpp

// TODO 2: Buat program anda di file ini. INGAT BERI KOMENTAR PADA SETIAP PROSES DALAM PROGRAM ANDA

// TODO 3: Selesaikan dan kumpulkan sebelum deadline yang telah ditentukan; Details ada dalam file README.md

// Tetap semangat walau sulit ;p

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
    string nomor_kartu, jenis;
    int check_sum, temp2;

    cout << "masukkan angka kartu : ";
    cin >> nomor_kartu;


    int panjang = nomor_kartu.size();                                    //mengetahui jumlah digit kartu
    long long nomor_kartu_val = stoll(nomor_kartu);                     //mengubah string menjadi nilai
    ///////////////////////Check sum////////////////////////////
    check_sum = 0;
                                 
        long long pembagi = 1000000000000000;
        int jumlah_angka_genap = 0;                                  //menghitung total angka yang tidak di kali 2
        int penentu = 3;                                          //penentu ganjil atau genap (kalau mulai dari <2, nilai akan diawal 0 sehinggu bug)
        while(pembagi > 0){
            int b = 0;                                                        //inisialisasi awal angka paling kiri
            int temp = nomor_kartu_val / pembagi;                   // mendapatkan angka paling kiri

            if (penentu % 2 != 0){
                b += temp * 2;                                        //Mengakali 2 urutan ganjil
                    if (b > 9){                                     //jika hasil perkalian ada dua digit, dipecah jadi digit berbeda
                        int temp3 = b / 10;                           //mendapatkan digit pertama (kiri)
                        int temp4 = temp3 + (b - (temp3 * 10));    //mendapatkan digit kedua (kanan)
                        check_sum += temp4;                     //menambagkan nilai ke total checksum
                    }
                    else{
                        check_sum += b;
                    }
            }

            else{
                jumlah_angka_genap += temp;                 //jika angka genap, maka nilainya disimpan agar bisa ditambahkan nanti       
            }
            nomor_kartu_val = nomor_kartu_val - temp * pembagi;     //menghilangkan angka paling kiri
            pembagi /= 10;                                      // mengurangi pembagi sesuai digit nomor kartu
            penentu++;
        }

    check_sum += jumlah_angka_genap;                                  //menambahkan total angka yang dikali 2 dengan angka yang tidak dikali

    string temp_jenis = nomor_kartu.substr(0,1);            //mengambil angka pertama dari kartu
    int temp2_jenis = stoi(temp_jenis);                 //mengubah angka yang diambil menjadi nilai int
    int validasi = check_sum % 10;                  //menentukan valid atau tidak valid
    int* validasi_ptr = &validasi;              //pointer agar bisa diambil nilainya
        
        if (*validasi_ptr == 0){
            switch (temp2_jenis){
                case 4:
                    if (panjang == 13 || panjang == 16){
                    jenis = "VISA";
                    }
                    else{
                        jenis = "TIDAK DIKETAHUI";
                    }
                    break;
                case 5:
                    if (panjang == 16){
                        string temp_jenis2 = nomor_kartu.substr(1,1);
                        int temp_jenis3 = stoi(temp_jenis2);
                        if (temp_jenis3 > 0 && temp_jenis3 < 6){
                            jenis = "MASTERCARD";
                        }
                        else{
                            jenis = "TIDAK DIKETAHUI";
                        }
                    }
                    else{
                        jenis = "TIDAK DIKETAHUI";
                    }
                    break;
                default:
                    jenis = "TIDAK DIKETAHUI";
                    break;
            }
        }
        else{
            jenis = "TIDAK VALID";
        }
    cout << "Nomor kartu anda: " << nomor_kartu << endl;
    cout << "Tipe kartu anda: " << jenis;
    cout << "\nChecksum: " << check_sum << endl;
}