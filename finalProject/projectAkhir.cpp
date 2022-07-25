#include <stdio.h>
#include <string.h>

// Global $variable no touching - touching >:(
long int $tagihanListrik, $tagihanUtang, $topUp, $pajak;
long long int $saldo = 50000000;
int admin = 70;
long int hasilPajak;
float biayaTransaksi = 4.900;
double pajakTransaksi = 2.500;

// Function
int biayaAdmin(int n) // Biaya admin dalam setiap transaksi
{
    if (n > 0)
    {
        return admin + biayaAdmin(n - 1);
    }
    else
    {
        return 0;
    }
}

void looping() // untuk interface
{
    for (int i = 1; i <= 36; i++)
    {
        printf("*");
    }
}

void logo() // logo bank CommonWealth
{
    int i, j, rows = 5, space;
    for (i = 1; i <= rows; i++)
    {
        for (space = 1; space <= (rows - i); space++)
        {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (i = rows; i >= 1; i--)
    {
        for (space = 1; space <= (rows - i); space++)
        {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void functionListrik()
{
    printf("\n\n\n\n");
    logo();
    looping();
    printf("\nCommonWealth - Tagihan Listrik\n");
    looping();
    puts("\nMasukan nominal anda");
    printf("\nNominal: Rp. ");
    scanf("%ld", &$tagihanListrik);
    if ($tagihanListrik < 0)
    {
        puts("Angka yang dimasukkan tidak boleh di bawah nilai 0");
    }
    else
    {
        $saldo -= ($tagihanListrik + biayaAdmin(admin));
        printf("Anda membayar tagihan sebesar RP.%ld\n", $tagihanListrik);
    }
    printf("\nSisa saldo Anda adalah Rp.%ld", $saldo);
    puts(" \n");
}

void functionUtang()
{
    printf("\n\n\n\n");
    logo();
    looping();
    puts("\nCommonWealth - Bayar Utang");
    looping();
    puts("\nMasukan nominal anda");
    printf("\nNominal: Rp. ");
    scanf("%ld", &$tagihanUtang);
    if ($tagihanUtang < 0)
    {
        puts("Angka yang dimasukkan tidak boleh di bawah nilai 0");
    }
    else if ($tagihanUtang > 0)
    {
        $saldo -= ($tagihanUtang + biayaAdmin(admin));
        printf("Anda membayar tagihan sebesar Rp.%ld\n", $tagihanUtang);
    }
    printf("\nSisa saldo Anda adalah Rp.%ld", $saldo);
    puts(" \n");
}

void functionTopUp()
{
    printf("\n\n\n\n");
    logo();
    looping();
    puts("\nCommonWealth - Bayar Utang");
    looping();
    puts("\nMasukan nominal anda");
    printf("\nNominal: Rp. ");
    scanf("%ld", &$topUp);
    if ($topUp < 0)
    {
        puts("Angka yang dimasukkan tidak boleh di bawah nilai 0");
    }
    else
    {
        $saldo -= ($topUp + biayaAdmin(admin));
        printf("Anda membayar tagihan sebesar RP.%ld\n", $topUp);
    }
    printf("\nSisa saldo Anda adalah Rp.%ld", $saldo);
    puts(" \n");
}

void functionPajak()
{
    printf("\n\n\n\n");
    logo();
    looping();
    puts("\nCommonWealth - Bayar Utang");
    looping();
    puts("\nMasukan nominal anda");
    printf("\nNominal: Rp. ");
    scanf("%ld", &$pajak);
    if ($pajak < 0)
    {
        puts("Angka yang dimasukkan tidak boleh di bawah nilai 0");
    }
    else
    {
        $saldo -= ($pajak + biayaAdmin(admin));
        printf("Anda membayar tagihan sebesar Rp.%ld\n", $pajak);
        printf("\nSisa saldo Anda adalah Rp.%ld", $saldo);
        puts(" \n");
    }
}

void mainMenu() // tampilan main menu
{
    printf("\n\n");
    logo();
    looping();
    puts("\nCommonWealth - ATM");
    looping();

    puts("\nCek Saldo   (1)"); // cek jumlah saldo
    puts("Tarik Tunai (2)");   // tarik tunai
    puts("Deposit     (3)");   // Deposit untuk menambahkan saldo
    puts("Pembayaran  (4)");   // bayar tagihan
    puts("Selesai     (0)");

    printf("\nSilahkan pilih transaksi: ");
}

// main
int main()
{
    // deklarasi variable
    int choose;
    char pemilihanTagihan;
    long int tarikTunai, deposit;
    char nama[][50] = {"Anthony", "Jordan"};
    int pin[3] = {123456, 23456};
    char masukNama[50];
    int masukPin;
    const char *result;
    // nama bank
    char s1[20] = {"CommonWealth"};
    char s2[20];
    char bubar;
    memcpy(s2, s1, strlen(s1));

    // variable tagihan

    int transaksiLagi = 1;

    // variable to check apakah ingin bertransaksi lagi?;
    int check = 1;

    printf("Selamat datang di ATM CommonWealth!\nSilahkan melakukan login terlebih dahulu!\n");

    do
    {

        while (check == 1)
        {
            printf("\nMasukan nama anda: ");
            scanf("%s", masukNama);
            printf("\nMasukan PIN anda: ");
            scanf("%i", &masukPin);

            if (strcmp(masukNama, nama[0]) == 0 && pin[0])
            {
                printf("\n\n\n\nSelamat datang kembali Anthony! \nSelamat Melakukan Transaksi");
            }
            else if (strcmp(masukNama, nama[0]) == 1 && pin[1])
            {
                printf("\n\n\n\nSelamat datang kembali Jordan! \nSelamat Melakukan Transaksi");
            }

            check = 0;
            while (check != 1 && check != 2)
            {
                printf("\nApakah ini Anda? \n");
                printf("1. Ulang lagi \n2. Benar");
                printf("\n\nMasukan pilihan: ");
                scanf("%i", &check);
                if (check > 2 && check < 0)
                {
                    puts("Akun tidak terdaftar");
                }
            }
        }
        mainMenu();
        scanf("%i", &choose);
        printf("\n\n");

        if (choose == 1) // cek Saldo
        {
            printf("\n\n\n\n");
            logo();
            looping();
            printf("\n%s - Cek Saldo\n", s2);
            looping();
            printf("\nSaldo anda: Rp.%lld", $saldo);
            result = $saldo <= 0 ? "\nAnda dapat mengisi saldo di deposit\n" : "\nSaldo anda cukup\n";
            printf("%s", result);
        }
        else if (choose == 2) // Tarik tunai
        {
            int total_tarikan;
            printf("\n\n\n\n");
            logo();
            looping();
            printf("\n%s - Tarik Tunai\n", s2);
            looping();
            puts("\nMasukan nominal anda");
            printf("\nNominal: Rp. ");
            scanf("%ld", &tarikTunai);
            if (tarikTunai < 0)
            {
                puts("Angka yang dimasukkan tidak boleh di bawah nilai 0");
            }
            else
            {
                $saldo -= (tarikTunai);
                
                printf("Anda tarik tunai sebesar Rp. %d\n", tarikTunai);
                printf("\nSisa saldo Anda adalah Rp.%ld", $saldo);
                puts(" \n");
            }
        }
        else if (choose == 3) // Deposit
        {
            printf("\n\n\n\n");
            logo();
            looping();
            printf("\n%s - Deposit\n", s2);
            ;
            looping();
            puts("\nMasukan nominal anda");
            printf("\nNominal: Rp. ");
            scanf("%ld", &deposit);
            if (deposit < 0)
            {
                puts("Angka yang dimasukkan tidak boleh di bawah nilai 0");
            }
            else
            {
                $saldo += deposit;
                printf("Anda deposit sebesar Rp. %ld\n", deposit);
                printf("\nSisa saldo Anda adalah Rp.%ld", $saldo);
                puts(" \n");
            }
        }
        else if (choose == 4) // Pebayaran
        {
            printf("\n\n\n\n");
            logo();
            looping();
            printf("\n%s - Pembayaran\n", s2);
            looping();
            puts("\nTagihan Listrik    (A)");
            puts("Bayar Utang        (B)");
            puts("Top-Up             (C)");
            puts("Bayar Pajak        (D)");
            puts("Batal              (E)");
            printf("\nSetiap transaksi dipotong biaya admin sebesar: Rp. %.3f", biayaTransaksi);
            printf("\n\nPilih Transaksi: ");
            scanf("%s", &pemilihanTagihan);
            switch ((char)pemilihanTagihan)
            {
            case 'A':
                functionListrik();
                break;
            case 'B':
                functionUtang();
                break;
            case 'C':
                functionTopUp();
                break;
            case 'D':
                functionPajak();
                break;
            case 'a':
                functionListrik();
                break;
            case 'b':
                functionUtang();
                break;
            case 'c':
                functionTopUp();
                break;
            case 'd':
                functionPajak();
                break;
            default:
                printf("Pilihan A, B, C, D\n");
                break;
            }
        }

        transaksiLagi = 0;
        while (transaksiLagi != 1 && transaksiLagi != 2) // nested
        {
            printf("\nApakah ingin transaksi lagi? \n");
            printf("1. Transaksi lagi \n2. Akhiri transaksi");
            printf("\n\nMasukan pilihan: ");
            scanf("%i", &transaksiLagi);
            if (transaksiLagi > 2 && transaksiLagi < 0)
            {
                puts("Token yang Anda masukkan salah, silahkan masukkan token Anda kembali");
            }
        }
        puts("\n\n\n\n");
    } while (transaksiLagi == 1);
    printf("");
    logo();
    looping();
    printf("\n%s - ATM\n", s2);
    looping();
    printf("\nTerima Kasih!");

    return 0;
}
