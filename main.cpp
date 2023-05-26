#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(int data[], int size){
  int i, j;
  for (i = 0; i < size-1; i++) {
    for (j = 0; j < size-i-1; j++) {
      if (data[j] > data[j+1]) {
        // proses pertukaran data
        int temp = data[j];
        data[j] = data[j+1];
        data[j+1] = temp;
      }
    }
  }
}
void selectionSort(int data[], int size) {
  int i, j, minIndex, temp;
  for (i = 0; i < size-1; i++) {
    minIndex = i;
    for (j = i+1; j < size; j++) {
      if (data[j] < data[minIndex])
        minIndex = j;
    }
    if (minIndex != i) {
      temp = data[i];
      data[i] = data[minIndex];
      data[minIndex] = temp;
    }
  }
}
void insertionSort(int data_master[], int data_length){
    int i, key, j;
    for (i = 1; i < data_length; i++) {
        key = data_master[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are 
        greater than key, to one position ahead 
        of their current position */
        while (j >= 0 && data_master[j] > key) {
            data_master[j + 1] = data_master[j];
            j = j - 1;
        }
        data_master[j + 1] = key;
    }
}







int main()
{
  int pilihan;
  int startTime, endTime;
  char ulang='y';
  
  while (ulang=='y')
  {
    const int NILAI_MAX=100000;
    int i,j, startTime, endTime;
	int data_master[NILAI_MAX], data_acak[NILAI_MAX];
    
    system("cls");
    cout << "##  MENU PILIHAN PERBANDINGAN METODE PENGURUTAN  ##" << endl;
    cout << "===================================================" << endl;
    cout << "1. Penyiapan Data Master (100rb Data Random)" << endl;
    cout << "2. Pengurutan dengan Metode Bubble-Sort" << endl;
    cout << "3. Pengurutan dengan Metode Selection-Sort" << endl;
    cout << "4. Pengurutan dengan Metode Insertion-Sort" << endl;
    cout << "5. Tabel Perbandingan Hasil Pengurutan" << endl;
    cout << "===================================================" << endl;
    cout << "Pilihan anda: ";
    cin >> pilihan;

    switch(pilihan){
    case 1:
        cout << "Penyiapan Data Master" << endl;
        //membangkitkan bilangan random
	srand(time(0));
	// mengisi array dengan bilangan random
	for (i=0;i<NILAI_MAX;i++) {
	  data_master[i] = (rand() % NILAI_MAX); //proses pengisian
	  cout << "Data_master["<<i <<"]=" <<data_master[i] << "\n"; //menampilkan di layar
	}
    	break;
    case 2:
        cout << "Pengurutan dengan Metode Bubble-Sort" << endl;
    startTime = time(0); // mencatat waktu mulai
    // proses bubble sort
    for (i = 0; i < NILAI_MAX - 1; i++) {
        for (j = 0; j < NILAI_MAX - i - 1; j++) {
            if (data_master[j] > data_master[j + 1]) {
                int temp = data_master[j];
                data_master[j] = data_master[j + 1];
                data_master[j + 1] = temp;
            }
        }
    }
    endTime = time(0); // mencatat waktu selesai
    cout << "Waktu yang diperlukan untuk melakukan bubble sort: " << endTime - startTime << " detik." << endl;
        break;
    case 3:
    cout << "Pengurutan dengan Metode Selection-Sort" << endl;
    startTime = time(0); // mencatat waktu mulai
    // proses selection sort
    for (i = 0; i < NILAI_MAX - 1; i++) {
        int minIndex = i;
        for (j = i + 1; j < NILAI_MAX; j++) {
            if (data_master[j] < data_master[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = data_master[i];
            data_master[i] = data_master[minIndex];
            data_master[minIndex] = temp;
        }
    }
    endTime = time(0); // mencatat waktu selesai
    cout << "Waktu yang diperlukan untuk melakukan selection sort: " << endTime - startTime << " detik." << endl;
    	break;
    case 4:
    cout << "Pengurutan dengan Metode Insertion-Sort" << endl;
    startTime = time(0); // mencatat waktu mulai
    // proses insertion sort
    for (i = 1; i < NILAI_MAX; i++) {
        int key = data_master[i];
        j = i - 1;
        while (j >= 0 && data_master[j] > key) {
            data_master[j + 1] = data_master[j];
            j = j - 1;
        }
        data_master[j + 1] = key;
    }
    endTime = time(0); // mencatat waktu selesai
    cout << "Waktu yang diperlukan untuk melakukan insertion sort: " << endTime - startTime << " detik." << endl;
    	break;
    case 5:
cout << "Tabel Perbandingan Hasil Pengurutan" << endl;
cout << "Metode\t\tWaktu (detik)" << endl;

startTime = time(0); // mencatat waktu mulai
bubbleSort(data_master, NILAI_MAX);
endTime = time(0); // mencatat waktu selesai
cout << "Bubble Sort\t" << endTime - startTime << endl;

startTime = time(0); // mencatat waktu mulai
selectionSort(data_master, NILAI_MAX);
endTime = time(0); // mencatat waktu selesai
cout << "Selection Sort\t" << endTime - startTime << endl;

startTime = time(0); // mencatat waktu mulai
insertionSort(data_master, NILAI_MAX);
endTime = time(0); // mencatat waktu selesai
cout << "Insertion Sort\t" << endTime - startTime << endl;
break;



	default :
        cout << "Menu tidak tersedia" << endl;
    }
    cout << endl;

    cout << "Ingin memilih menu lain (y/t)? ";
    cin >> ulang;
    cout << endl;
  }

  cout << "Terimakasih...";

  cout << endl;
  return 0;
}
