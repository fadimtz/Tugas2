#include <stdio.h>
#include <stdlib.h>

int main() {
    /* KAMUS */
    int waktu;
    int proses;
    printf("jumlah proses: ");
    scanf("%d", &proses);
    int end = 0;

    int input [proses][3];

    int i;
    int j;

    int antrian [proses];


    waktu = 0;
    int nextQuantum = 100;
    int currentInput = -1;

    for (i=0; i<proses; i++) {
            antrian[i] = -1;

    }

    printf("Waktu datang & waktu eksekusi: \n"); /*masukkan selang seling*/
    for (i=0; i<proses; i++) {
        input[i][0] = i;
        for (j=1; j<3; j++) {
            scanf("%d", &input[i][j]);

        }
    }

    for (i=0; i<proses; i++) {
        if (input[i][1] == 0) {
            for (j=0; j<proses; j++) {
                if (antrian[j] == -1) {
                    antrian[j] = input[i][0];

                    currentInput += 1;

                    break;
                }
            }

        }

    printf("Waktu = %d \n", waktu);
    printf("next quantum = %d \n", nextQuantum);


    printf("\nAntrian: ");
     for (i=0; i<proses; i++) {
            if (antrian[i] != -1) {
           printf("P%d ", antrian[i]);
            }
    }

    printf("\np | in | sisa \n");
    for (i=0; i<proses; i++) {
        for (j=0; j<3; j++) {
            printf("%d ", input[i][j]);
            printf("|");
        }
        printf("\n");
    }

   if (antrian[0] == -1 && currentInput == proses-1) {
        end = 1;
    }
    printf("\n\n");
    }


    while (!end) {
    int index = antrian[0];
    int durasi = input[index][2];

    int a = nextQuantum;
    int b = input[index][2] + waktu;

    int p;

    int c;
    if (currentInput >= proses-1) {
        c = 99999;
        p = 0;
    }
    else {
    c = input[currentInput+1][1];
    p = input[currentInput+1][0];
    }

    if (a < b && a < c) {
        // Pengurangan waktu proses
        input[index][2] -= (nextQuantum - waktu);
        // update waktu
        waktu = nextQuantum;
        // update nextQuantum
        nextQuantum += 100;
        // Geser proses
        int pindah = antrian[0];
        for (i=0; i<proses; i++) {
            if (antrian[i+1] == -1) {
                antrian[i] = pindah;
                break;
            }
            else {
                antrian[i] = antrian[i+1];
            }
        }
    }

    else if (b <= a && b < c){
        input[index][2] = 0;
        waktu += durasi;
        nextQuantum = waktu + 100;

        for (i=0; i<proses; i++) {
            if ((antrian[i+1] == -1) || (i == proses-1)) {
                antrian[i] = -1;
                break;
            }
            else {
                antrian[i] = antrian[i+1];
            }
        }
    }

    else {
        input[index][2] -= (c - waktu); /*waktu proses dikurang*/
        waktu = c;

        for (i=0; i<proses; i++) {
            if (antrian[i] == -1) {
                antrian[i] = p;

                currentInput += 1;
                break;
            }
        }
    }

    printf("\n");
    printf("Waktu = %d \n", waktu);
    printf("Kuantum selanjutnya = %d \n", nextQuantum);

    printf("\n Antrian: ");
    for (i=0; i<proses; i++) {
            if (antrian[i] != -1) {
           printf("P%d ", antrian[i]);
            }
    }

    printf("\np | in | sisa \n");
    for (i=0; i<proses; i++) {
        for (j=0; j<3; j++) {
            printf("%d ", input[i][j]);
            printf("|");
        }
        printf("\n");
    }

    if (antrian[0] == -1 && currentInput == proses-1) {
        end = 1;
    }
    printf("\n\n");
    }


	return 0;
}