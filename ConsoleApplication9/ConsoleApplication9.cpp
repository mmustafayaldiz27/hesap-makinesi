#include <iostream>
#include <string>

using namespace std;

double sayi1, sayi2;
double sonuc = 0;
string secim = "";

typedef enum {
    ADDITION = 0,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
} TYPEOFPROCESS;

TYPEOFPROCESS CheckChoose()
{
    cout << "İslemi giriniz :  ";
    getline(cin, secim);

    if (secim == "yenile")
    {
        sayi1 = 0;
        sayi2 = 0;
        sonuc = 0;
        secim = "";
        cout << "birinci sayı : ";
        cin >> sayi1;
        return CheckChoose();
        
       
    }
    else if (secim=="tesekkur") {
        cout << "Hocam öncelikle sizi gerçekten çok seviyorum \n  Yazılım konusunda Birşeyler bildiğimi varsayıyordum ama bu süre zarfında gerçekten birşey bilmediğmi farkettim \n Ben bu alanda gerçekten ilerlemek istiyorum ve bu ders kendimin ne durumda olduğu gerçeğini maalesef  bana gösterdi. \n Size  bu ders özelinde ,bana kattığınız herşey için çok teşekkür ediyorum. \n Umarım mesajı görürsünüz :)  "<<endl;
        return CheckChoose();
    }
    else if (secim == "temizle")
    {
        system("cls");
        cout << "Temizlendi.\n";
        cout << "Sonuç: " << sonuc << endl;
        return CheckChoose();
    }
    else if (secim == "bitir")
    {
        exit(1);
    }
    else if (secim == "+")
    {
        return ADDITION;
    }
    else if (secim == "-")
    {
        return SUBTRACTION;
    }
    else if (secim == "*")
    {
        return MULTIPLICATION;
    }
    else if (secim == "/")
    {
        return DIVISION;
    }
    else
    {
        cout << "Hatalı işlem türü seçtiniz!\n";
        return CheckChoose();
    }
}

double Calculate(double value1, double value2, TYPEOFPROCESS process)
{
    switch (process)
    {
    case ADDITION:
        return value1 + value2;
    case SUBTRACTION:
        return value1 - value2;
    case MULTIPLICATION:
        return value1 * value2;
    case DIVISION:
        return value1 / value2;
    default:
        return 0;
    }
}

void CalculatorApp()
{
    cout << "Birinci sayi: ";
    cin >> sayi1;
    cout << "\n Yapmak istediğiniz işlemi giriniz: \n (Toplama işlemi için: '+')\t (Çıkarma işlemi için: '-')\n (Çarpma işmei için: '*') \t (Bölme işlemi için: '/') \t giriniz\n İşlem kısmına \"temizle\" yazarsanız son işlemin sonucuna kadar olan bütün sayıları ekrandan siler.\n İşlem kısmına \"yenile\" yazarsanız ilk sayıyı sıfırlar ve baştan birdaha birinci sayıyı girmenizi ister. \n İşlem kısmına \"bitir\" yazarsanız hesap makinesi programını sonlandırır \n İşlem kısmına \"tesekkur \" yazarsanız ..??   ";
    getline(cin, secim);
    cin.ignore();

    while (true)
    {
        TYPEOFPROCESS typeOfProcess = CheckChoose();

        if (typeOfProcess == ADDITION)
        {
            cout << "İkinci sayi: ";
            cin >> sayi2;
            cin.ignore();
        }
        else
        {
            cout << "İkinci sayi: ";
            cin >> sayi2;
            cin.ignore();

          
        }

        sonuc = Calculate(sayi1, sayi2, typeOfProcess);
        cout << "Sonuç: " << sonuc << endl;
        sayi1 = sonuc;
    }
}

int main()
{
    setlocale(LC_ALL,"Turkish");
    cout << "Hesap Makinesi\n";
    CalculatorApp();

    return 0;
}
