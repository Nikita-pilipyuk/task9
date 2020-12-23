#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int* a, int* b) {
        int t = *a;
        *a = *b;
        *b = t;
}
void zadanie1() {
        {
                int i, j, n, m, **mas;

                printf("Vvedite 2 chisla:\n");
                scanf("%d %d", &m, &n);

                mas = (int**)malloc(m * sizeof(int*));

                for (i = 0; i < m; i++)
                {
                        mas[i] = (int*)malloc(n * sizeof(int));
                }

                printf("Vvedite elementi massiva\n");

                for (i = 0; i < m; i++) {
                        for (j = 0; j < n; j++) {
                                scanf("%d", &mas[i][j]);
                        }
                }
                printf("Nachalniy massiv:\n");

                for (i = 0; i < m; i++ ) {
                        printf("\n");
                        for (j = 0; j < n; j++) {
                                printf("%d ", mas[i][j]);
                        }
                }
                int *b;
                b = (int*)malloc((m * n) * sizeof(int));


                for (i = 0; i < m; i++) {
                        for (j = 0; j < n; j++)
                        {
                                b[i * n + j] = mas[i][j];
                        }
                }

                printf("\nOtvet tuda:\n");

                for (i = 0; i < m * n; i++) {
                        printf("%d ", b[i]);
                }
                printf("\n");

                for (i = 0; i < m; i++) {
                        for (j = 0; j < n; j++) {
                                mas[i][j] = 0;
                        }
                }
                printf("Otvet obratno :\n");
                for (i = 0; i < m * n; i++){
                        mas[i / n][i % n] = b[i];

                }

                for (i = 0; i < m; i++) {
                        printf("\n");
                                for (j = 0; j < n; j++) {
                                        printf("%d ", mas[i][j]);
                                }
                }

        }
}
void zadanie2() {
        int n, m;
        printf("Vvedite razmer cherez probel");
        scanf("%d %d", &n, &m);

        int** mas;
        mas = (int**)malloc(n * sizeof(int*));
        int q;
        for ( q = 0; q < n; q++) {
                mas[q] = (int*)malloc(m * sizeof(int));
        }
        /*
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                        mas[i][j] = j + 1 - i;
                        if (mas[i][j] <= 0) {
                                mas[i][j] = 2 - mas[i][j];
                        }
                }
        }
        for (int i = 0; i < n; i++) { //vivod
                printf("\n");
                for (int j = 0; j < m; j++) {
                        printf("\t%d", mas[i][j]);
                        mas[i][j] = 0;
                }
        }
        printf("\n\n");
        */

        int sum = 1;

        if (n % 2 == 1 && m % 2 == 1) {
                mas[n / 2][m / 2] = n * m;

        }

        int krugov;
        if (n > m) {
                krugov = m / 2 + m % 2;

        }
        else{
                krugov = n / 2 + m % 2;
        }

     int i;
                for (i = 0; i < krugov; i++) {
                        if ( (krugov == i + 1 && n % 2 == 1) || (n % 2 == 0 )|| (krugov != i + 1 && n % 2 == 1)) {
                                int j;
                        for (j = i; j < (m - i); j++) {
                            mas[i][j] = sum;
                            sum++;
                        }
                }
                        if ((krugov == i + 1 && m % 2 == 1) || (m % 2 == 0) || (krugov != i + 1 && m % 2 == 1)) {
                                int j;
                                for (j = 1; j < (n - i - i); j++) {
                                    mas[(j + i)][m - i - 1] = sum;
                                    sum++;
                                }
                        }
                if (krugov != i + 1 && (m % 2 == 1 || n % 2 == 1)) {
                        int j;
                        for (j = m - 2 - i; j >= i; j--) {
                                mas[n - i - 1][(j)] = sum;
                                sum++;
                        }

                        for (j = ((n - i) - 2); j > i; j--) {
                                mas[j][i] = sum;
                                sum++;
                        }
                }
        }


        for (i = 0; i < n; i++) { //vivod
                printf("\n");
                int j;
                for (j = 0; j < m; j++) {
                        printf("\t%d", mas[i][j]);
                }
        }
}

void gauss(double** mas1, double** mas2, int n)
{
        int k = 0, ind;
        while (k < n)
        {
                double t = mas1[k][k];
                if (t == 0)
                {
                    int i;
                        for (i = 0; i < n; i++)
                                if (mas1[i][k] != 0)
                                {
                                        ind = i;
                                        break;
                                }

                        for (i = 0; i < n; i++)
                        {
                            double t = mas1[k][i], t1 = mas2[k][i];
                            mas1[k][i] = mas1[ind][i], mas2[k][i] = mas2[ind][i];
                            mas1[ind][i] = t, mas2[ind][i] = t1;
                        }
                        t = mas1[k][k];
                }
                int i;
                for (i = 0; i < n; i++)
                {
                        mas1[k][i] /= t;
                        mas2[k][i] /= t;
                }

                for (i = k + 1; i < n; i++)
                {
                        double t = mas1[i][k];
                        int j;
                        for ( j = 0; j < n; j++)
                        {
                                mas1[i][j] -= mas1[k][j] * t;
                                mas2[i][j] -= mas2[k][j] * t;
                        }
                }
                k++;
            }
            for (k = n - 1; k > 0; k--)
            {    int j;
                    for (j = k - 1; j >= 0; j--)
                    {
                            double t = mas1[j][k];
                            mas1[j][k] -= mas1[k][k] * t;
                            int i;
                            for (i = n - 1; i >= 0; i--)
                            {
                                    mas2[j][i] -= mas2[k][i] * t;
                            }
                    }
            }
}

void gaussMethod(
        int m,          // Chislo strok matritsi
        int n,          // Chislo stolbsov matritsi
        double* a,      // Adres massiva elementov matritsi
        double eps      // Tochnost vichisleniy
) {
        int i, j, k, l;
        double r;


        i = 0; j = 0;
        while (i < m && j < n) {
                // Invariant: minor matritsi v stolbsax 0..j-1
                // uje privedyon k stupenchatomu vidu, i stroka
                // s indeksom i-1 soderjit nenulevoy element
                // v stolbse nomerom menshim chem j

                // Ishem maksimalniy element v j-em stolbse,
                // nachinaya s i-iy stroki
                r = 0.0;
        for (k = i; k < m; ++k) {
                if (fabs(a[k * n + j]) > r) {
                        l = k;      // Zapomnim nomer stroki
                        r = fabs(a[k * n + j]); // i maksimalniy element
                }
        }
        if (r <= eps) {
                // Vse elementi j-go stolbsa po absolyutnoy
                // velichine ne prevoshodyat eps.
                // Obnulim stolbes, nachinaya s i-iy stroki
                for (k = i; k < m; ++k) {
                        a[k * n + j] = 0.0;
                }
                ++j; // Uvelichem indeks stolbza
                continue; // Perehodim k sleduyushey iterasii
        }

        if (l != i) {
                // Menyaem mestami i-uyu i l-uyu stroki
                for (k = j; k < n; ++k) {
                        r = a[i * n + k];
                        a[i * n + k] = a[l * n + k];
                        a[l * n + k] = (-r); // Menyaem znak stroki
                }
        }

        // Utverjdenie: fabs(a[i*n + k]) > eps

        // Obnulyaem j-iy stolbes, nachinaya so stroki i+1,
        // primenyaya element preobrazovaniya vtorogo roda
        for (k = i + 1; k < m; ++k) {
                r = (-a[k * n + j] / a[i * n + j]);

                // K k-é stroke pribavlyaem i-þ, umnojennyu na r
                a[k * n + j] = 0.0;
                for (l = j + 1; l < n; ++l) {
                        a[k * n + l] += r * a[i * n + l];
                }
        }   ++i; ++j; // Perehodim k sleduyushemu minoru
    }
}

void treug(int qwe,int n) {
        int m, i, j, rank;
        double* a;
        double eps, det;

        printf("Vvedite razmeri matritsi m, n: ");
        scanf("%d", &m);
        n=n+m; // Zaxvativaem pales pod elementi matritsi
        a = (double*)malloc(m * n * sizeof(double));

        printf("Vvedite elementi matritsi:\n");
        for (i = 0; i < m; ++i) {
                for (j = 0; j < n; ++j) {
                        // Vvodim element s indeksami i, j
                        scanf("%lf", &(a[i * n + j]));
                }
        }

        printf("Vvedite tochnost vichisleniy eps: ");
        scanf("%lf", &eps);

        // Vizivaem metod Gaussa
        gaussMethod(m, n, a, eps);

        // Pechataem stupenchatuyu matritsu
        printf("Treugolniy vid matritsi:\n");
        for (i = 0; i < m; ++i) {
                // Pechataem i-yu stroku matritsi
                for (j = 0; j < n; ++j) {
                        printf(        // Format %10.3lf oznachaet 10
                               "%10.3lf ", // poziqiy napechatat chisla,
                               a[i * n + j] // 3 znaka posle tochki
                        );
                }
                printf("\n"); // Perevesti stroku
        }



        if (qwe == 7) {
                det = 1.0;
                for (i = 0; i < m ; ++i) {
                        det = det * a[i * n + i];
                }
                printf("Opredelitel matritsi = %.3lf\n", det);
        }
        if (n != m )
        {
                j = 1;
                i = n * m - 2;
                while ( i>0 ) {


                        a[i + j] = a[i + j] / a[i];
                        a[i] = 1;
                        int k;
                        for (k = 0; k < m-j ; k++) {
                                a[i + j-n -n*k ] = a[i + j-n - n * k] - (a[i-n]* a[i + j - n * k]);
                                a[i-n - n * k] = 0;
                        }

                        j++;
                        i = i - n-1;
                }
                a[m] = a[m] / a[0];
                a[0] = 1;


                printf("Otvet:\n");
                for (i = 0; i < m; ++i) {
                        // Pechataem i-yu stroku matritsi
                        for (j = 0; j < n; ++j) {
                                printf(        // Format %10.3lf oznachaet 10
                                       "%10.3lf ", // poziqiy napechatat chisla,
                                       a[i * n + j] // 3 znaka posle tochki
                                );
                        }
                        printf("\n"); // Perevesti stroku
                }

        }


}

void zadanie5(){
      treug(0,1);
}
void zadanie6() {
        int n;
        double** mas1,** mas2,** mas3;

        printf("Vvedite razmer: ");
        scanf("%d", &n);

        mas1 = (double**)malloc(n * sizeof(double*));
        mas2 = (double**)malloc(n * sizeof(double*));
        mas3 = (double**)malloc(n * sizeof(double*));
        int i;
        for (i = 0; i < n; ++i) {
                mas1[i] = (double*)malloc(n * sizeof(double));
                mas2[i] = (double*)malloc(n * sizeof(double));
                mas3[i] = (double*)malloc(n * sizeof(double));
        }
        printf("Matritsa: \n");
        int j;
        for (i = 0; i < n; i++)

                for (j = 0; j < n; j++)

                {
                        if (i == j)
                                mas2[i][j] = 1;
                        else mas2[i][j] = 0;

                        scanf("%lf", &mas1[i][j]);
                        mas3[i][j] = mas1[i][j];
                }

        gauss(mas1,mas2,n);
        printf("\nOtvet: \n");

        for ( i = 0; i<n;i++)
        {
               for (j = 0;j<n;j++)
                       printf("%1f" ,mas2[i][j]);
               printf("\n");
        }

        double** mas4;
        mas4 = (double**)malloc(n * sizeof(double*));
        for (i = 0; i < n; i++)
        {
                mas4[i] = (double*)malloc(n * sizeof(double));

                for (j = 0; j < n; j++)

                {
                        mas4[i][j] = 0;
                   int k;
                        for (k = 0; k < n; k++)
                                mas4[i][j] += mas3[i][k] * mas2[k][j];

                        if (fabs(mas4[i][j]) < 0.000001)
                                mas4[i][j] = 0;
                }

        }

}

int main()
{


        int q = 1;

        //Task9

        printf("\n\n1) (1) Schitaem, chto dvumerniy massiv razmerom m na n preobrazuetsya v odnomerniy massiv razmera m* n putyom posledovatelnoy zapisi strok. (m i n zadani) Realizovat takoe preobrazovanie «tuda» i «obratno». ");
        printf("\n\n2) (2) Zapolnit dvumerniy massiv razmerom n x m tak, kak predstavleno v tablitse dlya 5õ5");
        printf("\n\n6) (2) Nayti obratnuyu matritsu metodom Gaussa (sdelat proverku)");
        printf("\n\n0) Viyti");
        while (q != 0){
                printf("\n\nVvedite nomer nujnogo zadaniya : ");
                scanf_s("%d", &q);
                switch (q){
                case 1: {
                        zadanie1();//Zadanie 1
                        break;
                }
                case 2:{
                        zadanie2();//Zadanie 2
                        break;
                }
                case 6: {
                        zadanie6();//Zadanie 6
                        break;
                }

                }

           }
           return 0;
}
