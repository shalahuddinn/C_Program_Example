#include <stdio.h>
#include <math.h>
#include <string.h>

/**

Membuat program pesan rahasia sederhana.

Tono dan Tini mengembangkan metodo enkripsi khusus sehingga mereka dapat bertukar
pesan tanpa takut disadap. Berikut adalah caranya: L adalah panjang pesan asli, dan M
menjadi luas bujur sangkar terkecil yang lebih besar dari atau sama dengan L. Tambahkan
(M-L) dengan tanda bintang untuk pesan (jika memang masih ada ruang kosong),
memberikan pesan total dengan panjang M. Gunakan pesan total ini untuk mengisi tabel
ukuran K x K, di mana K x K = M.

Mengisi tabel mulai dari di baris atas ke baris bawah, kiri ke kolom kanan di setiap baris.
Putar tabel 90 derajat searah jarum jam. Pesan terenkripsi berasal dari membaca pesan mulai
dari baris pertama dari tabel diputar, dan menghilangkan setiap tanda bintang.
Misalnya, mengingat pesan asli 'akucintakamu', pangang pesan adalah L = 12. Dengan demikian
pesan total adalah 'akucintakamu****', dengan panjang M = 16. Berikut adalah 2
tabel sebelum dan setelah rotasi.

Sebelum             Setelah
a k u c             * k i a
i n t a             * a n k
k a m u             * m t u
* * * *             * u a c

Jadi pesan terenkripsinya adalah 'kiaankmtuuac'


*/

int main (void) {
    //Deklari Variabel
    char pesan[1001]; //Pesan yang diinput
    char pesanTemp [32][32]; //Penyimpan pesan yang diinput menjadi sebuah array persegi
    char pesanMod [32][32]; //Hasil modifikasi pesan

    float dummy;//Variabel pembantu untuk mencari bilangan kuadrat terdekat

    int panjang_pesan; //Panjang karakter dari pesan
    int luas_persegi; //Variabel penyimpan nilai dari luas array persegi yang dibutuhkan
    int panjang_sisi; //Variabel penyimpan panjang sisi array persegi
    int k=0, i,j;    //Variabel iterasi

    //Meminta pesan dari pengguna
    printf("Masukkan pesan : ");
    scanf("%s",&pesan);

    //Mencari bilangan kuadrat terdekat
    panjang_pesan = strlen(pesan);
    luas_persegi = panjang_pesan;
    dummy = sqrt(luas_persegi) - ((int) sqrt(luas_persegi));
    while (dummy !=0) {
        luas_persegi = luas_persegi + 1;
        dummy = sqrt(luas_persegi) - ((int) sqrt(luas_persegi));
    }
    panjang_sisi = sqrt(luas_persegi);

    //Memasukkan pesan kedalam array sementara
    for (i=0;i<=panjang_sisi-1;++i) {
        for (j=0;j<=panjang_sisi-1;++j) {
            if (k<=panjang_pesan-1) {
                pesanTemp[i][j] = pesan[k];
            }
            else {
                pesanTemp[i][j] ='*';
            }
            k = k + 1;
        }
    }
    //Melakukan enkripsi pesan
    for (i=0;i<=panjang_sisi-1;++i) {
        for (j=0;j<=panjang_sisi-1;++j) {
            pesanMod[j][panjang_sisi-i-1]=pesanTemp[i][j];
        }
    }
    //Menampilkan hasil enkripsi pesan
    printf("Pesan rahasia : ");
    for (i=0;i<=panjang_sisi-1;++i) {
        for (j=0;j<=panjang_sisi-1;++j) {
            if (pesanMod[i][j]!='*'){
                printf("%c",pesanMod[i][j]);
            }
        }
    }
    return 0;
}
