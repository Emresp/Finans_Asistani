#include "FinanceManager.h"

#include <iostream>
#include <algorithm>


#include "Transaction.h"
using namespace std;

//Yapıcı metot tanımı.
//Oluşturlan anabkiye değişkenine listede yer açılıken kendi tipine göre default değert verdik
FinanceManager::FinanceManager()
{
    anaBakiye = 0;
}

//işlemleri verileri tutucak listenin içine verileri eklemek için
void FinanceManager::islemEkle(const Transaction& yeniIslem)
{
    //Listenin sonuna ekleme yapıyor
    islemListesi.push_back(yeniIslem);

    //Ekleme yaparken tutara ve gelir mi gider mi olduığuna zaten eklenmiş olan anabakiyede değişiklik yapıyor
    if (yeniIslem.getGelirMi()==true)
    {
        this->anaBakiye=this->anaBakiye+yeniIslem.getTutar();
    }
    else
    {
        this->anaBakiye=this->anaBakiye-yeniIslem.getTutar();
    }
}

//Geçmiş Listeyi görüntülemek için
void FinanceManager::gecmisiListele()
{
    //liste boşsa direk durması içğin kontrol
    if (islemListesi.empty()){cout<<"Listede Hiç bir veri bulunmuyor\n\n\n"; return;}
    //Listeyi yazdırmak için
    for (size_t i=0; i<islemListesi.size(); i++)
    {
        islemListesi[i].bilgiyazdir();
    }
}


//Anabakiyeyi görüntülemek için
double FinanceManager::getanaBakiye(){return anaBakiye;}

void FinanceManager::kategoriAnalizi() const
{
    double marketToplam = 0;
    double teknolojiToplam = 0;
    double ulasimToplam = 0;
    double eglenceToplam = 0;
    double digerToplam = 0;

    //Sırayla tüm değerleri toplamak için
    for (size_t i=0; i<islemListesi.size(); i++)
    {
        string anlikKategori = islemListesi[i].getKategori();
        double anlikTutar = islemListesi[i].getTutar();

        bool anlikIslemGelirMi = islemListesi[i].getGelirMi();

        if (anlikIslemGelirMi == true) {
            continue;
        }


        if (anlikKategori == "Market") {
            marketToplam += anlikTutar;
        }
        else if (anlikKategori == "Teknoloji") {
            teknolojiToplam += anlikTutar;
        }
        else if (anlikKategori == "Ulaşım") {
            ulasimToplam += anlikTutar;
        }
        else if (anlikKategori == "Eğlence") {
            eglenceToplam += anlikTutar;
        }
        else if (anlikKategori == "Diğer") {
            digerToplam += anlikTutar;
        }

    }
    //Değerleri normalize etmek için max değeri buluyoruz hazır algoritma ile
    double maxToplam = max({marketToplam, teknolojiToplam, ulasimToplam, eglenceToplam, digerToplam});
    //Eğer hiç bir değer yoksa direk fonksiyondan çıksın
    if (maxToplam==0){return;}

    int maksimumSutunGenisligi = 50;

    cout << "\n--- KATEGORI BAZLI HARCAMA ANALIZI ---\n";

    int marketSutunUzunlugu = static_cast<int>((marketToplam / maxToplam) * maksimumSutunGenisligi);

    cout << "Market    : ";

    for (int i = 0; i < marketSutunUzunlugu; i++) {
        cout << "█";
    }

    cout << " (" << marketToplam << " TL)\n";

    int teknolojiSutunUzunlugu = static_cast<int>((teknolojiToplam / maxToplam) * maksimumSutunGenisligi);

    cout << "Teknoloji : ";
    for (int i = 0; i < teknolojiSutunUzunlugu; i++) {
        cout << "█";
    }
    cout << " (" << teknolojiToplam << " TL)\n";

    int ulasimSutunUzunlugu = static_cast<int>((ulasimToplam / maxToplam) * maksimumSutunGenisligi);

    cout << "Ulaşım    : ";
    for (int i = 0; i < ulasimSutunUzunlugu; i++) {
        cout << "█";
    }
    cout << " (" << ulasimToplam << " TL)\n";

    int eglenceSutunUzunlugu = static_cast<int>((eglenceToplam / maxToplam) * maksimumSutunGenisligi);

    cout << "Eğlence   : ";
    for (int i = 0; i < eglenceSutunUzunlugu; i++) {
        cout << "█";
    }
    cout << " (" << eglenceToplam << " TL)\n";

    int digerSutunUzunlugu = static_cast<int>((digerToplam / maxToplam) * maksimumSutunGenisligi);

    cout << "Diğer     : ";
    for (int i = 0; i < digerSutunUzunlugu; i++) {
        cout << "█";
    }
    cout << " (" << digerToplam << " TL)\n";

    cout << "--------------------------------------\n\n";

}