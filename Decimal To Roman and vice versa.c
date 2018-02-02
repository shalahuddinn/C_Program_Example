#include <stdio.h>
#include <string.h>
#define MAX 10 //asumsi maksimal 10 karakter input


/**
Program untuk menkonversi bilangan romawi ke desimal dan sebaliknya. Pengguna tinggal
memasukan angka desimal atau romawi yang ingin dikonversikan secara langsung.
*/

//Fungsi untuk merubah bilangan desimal ke romawi
void decimalToRoman (int input) {
    int i; //variabel iterasi
    int answer; //hasil konversi

    //Konversi
    while(input>0) {
        if (input>=1000) {
            printf("M");
            input=input-1000;
        }
        else if (input>=100){
            if (input>=900) {
                printf("CM");
                input=input-900;
            }
            else {
                printf("C");
                input=input-100;
                printf("%ld  ",input);
            }
        }
        else if (input>=50){
            if (input>=90) {
                printf("XC");
                input=input-90;
            }
            else {
                printf("L");
                input=input-50;
            }
        }
        else if (input>=10){
            if (input>=40) {
                printf("XL");
                input=input-40;
            }
            else{
                printf("X");
                input=input-10;
            }
        }
        else if (input>=5){
            if (input>=9) {
                printf("IX");
                input=input-4;
            }
            else {
                printf("V");
                input=input-5;
            }
        }
        else if (input>=4) {
            printf("IV");
            input=input-4;
        }
        else {
            printf("I");
            input=input-1;
        }
    }
}

//Fungsi untuk merubah bilangan romawi ke desimal
void romanToDecimal (char input[MAX+1]) {
    int temp[MAX+1]; //Menyimpan sementara hasil konversi tiap angka
    int length_input; //panjang (banyaknya karakter) input
    int answer; //hasil konversi
    int i=0; //variabel iterasi

    //Mencari panjang input
    length_input = strlen(input);

    //Proses merubah tiap angka romawi ke bilangan desimal
    while (input[i]!='\0') {
        if (input[i]=='I') {
            temp[i]=1;
        }
        else if (input[i]=='V') {
            temp[i]=5;
        }
        else if (input[i]=='X') {
            temp[i]=10;
        }
        else if (input[i]=='L') {
            temp[i]=50;
        }
        else if (input[i]=='C') {
            temp[i]=100;
        }
        else if (input[i]=='D') {
            temp[i]=500;
        }
        else {
            temp[i]=1000;
        }
        i++;
    }

    //Proses mencari jawaban sebenarnya
    answer = temp[length_input-1];
    for (i=length_input-1;i>0;--i) {
        if (temp[i]<=temp[i-1]) {
            answer = answer + temp[i-1];
        }
        else {
            answer = answer - temp[i-1];
        }
    }
    //Menampilkan hasil
    printf("Hasil : %d", answer);
}

int main (void) {
    char input[MAX+1]; //array input
    int pangkat = 1; //variabel penyimpan pangkat 10
    //variabel iterasi
    int i = 0;
    int j = 1;

    int input_desimal=0; //hasil konversi char ke int

    //Meminta input. Asumsi input selalu benar. (Angka desimal atau angka romawi)
    scanf("%s",&input);
    //Mengecek apakah input berupa angka desimal atau bukan
    if (input[0]>=65 && input[0]<=90) {
        //Input berupa angka romawi
        romanToDecimal(input);
    }
    else {
        //input berupa angka desimal, konversi char ke int
        for (i=0;i<=strlen(input)-1;++i) {
            while (j<=(strlen(input)-1-i)) {
                pangkat = pangkat * 10;
                j = j + 1;
            }
            input_desimal = input_desimal + ((input[i]-'0')*pangkat);
            j = 1;
            pangkat = 1;
        }
        decimalToRoman(input_desimal);
    }
    return 0;
}


