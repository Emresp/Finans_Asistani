#include "FinanceManager.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>


#include "Transaction.h"
using namespace std;

//Yapıcı metot tanımı.
//Oluşturlan anabkiye değişkenine listede yer açılıken kendi tipine göre default değert verdik
FinanceManager::FinanceManager()
{
    anaBakiye = 0;
}

void FinanceManager::setAktifKullanici(const string& isim)
{
    // Arayüzden gelen ismi, sınıfın kalıcı hafızasına kaydediyorum.
    aktifKullanici = isim;
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
    //Grafik çizmek için gerekli olan döngüler
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

void FinanceManager::maxharcama() const
{
    // Başlangıçta geçerli bir indeks olmadığı için -1 atanıyor.
    // Döngü sonunda bu değer değişmezse sistemde analiz edilecek bir harcama kaydı bulunmadığı anlaşılır.
    int maxIndex = -1;
    double maxTutar = -1.0;

    for (size_t i = 0; i < islemListesi.size(); i++)
    {
        // Analiz sadece giderler üzerinden yapılacağı için gelir işlemleri döngüde pas geçiliyor.
        if (islemListesi[i].getGelirMi() == true) {
            continue;
        }

        double anlikTutar = islemListesi[i].getTutar();

        // Okunan tutar, şu ana kadar tespit edilen en yüksek tutardan büyükse yeni maksimum değer ve indeksi güncelleniyor.
        if (anlikTutar > maxTutar) {
            maxTutar = anlikTutar;
            maxIndex = i;
        }
    }

    // Arama sonucu yazdırma işlemi. Geçerli bir indeks bulunduysa ilgili objenin detayları ekrana basılır.
    if (maxIndex != -1) {
        cout << "\n--- EN YUKSEK HARCAMA SORGUSU ---\n";
        islemListesi[maxIndex].bilgiyazdir();
    } else {
        cout << "Sistemde kayitli hicbir harcama bulunamadi.\n";
    }
}


void FinanceManager::minharcama() const
{
    int minIndex = -1;
    double minTutar = 0.0;

    for (size_t i = 0; i < islemListesi.size(); i++)
    {
        // Yine yalnızca giderlerin taranması için gelirler filtreleniyor.
        if (islemListesi[i].getGelirMi() == true) {
            continue;
        }

        double anlikTutar = islemListesi[i].getTutar();

        // minIndex -1 ise karşılaşılan ilk harcama direkt olarak minimum kabul ediliyor.
        // Sonraki iterasyonlarda ise mevcut minimumdan daha düşük bir değer gelirse güncelleme yapılıyor.
        if (minIndex == -1 || anlikTutar < minTutar) {
            minTutar = anlikTutar;
            minIndex = i;
        }
    }

    // Arama sonucu yazdırma işlemi.
    if (minIndex != -1) {
        cout << "\n--- EN DUSUK HARCAMA SORGUSU ---\n";
        islemListesi[minIndex].bilgiyazdir();
    } else {
        cout << "Sistemde kayitli hicbir harcama bulunamadi.\n";
    }
}


void FinanceManager::dosyayakaydet() const
{

    string dosyaAdi = aktifKullanici + "_islemler.txt";

    ofstream dosya(dosyaAdi);

    if (!dosya.is_open())
    {
        cout << "HATA: VERİLER KAYIT EDİLEMİYOR, DOSYA AÇILAMADI\n";
        return;
    }

    for (size_t i = 0; i < islemListesi.size(); i++)
    {
        dosya<<islemListesi[i].getTutar()<<","
        <<islemListesi[i].getKategori()<<","
        <<islemListesi[i].getAciklama()<<","
        <<islemListesi[i].getTarih()<<","
        <<islemListesi[i].getGelirMi()<<"\n"
        ;
    }
    dosya.close();
}
void FinanceManager::dosyadanYukle()
{
    string dosyaAdi=aktifKullanici + "_islemler.txt";

    ifstream dosya(dosyaAdi);

    if (!dosya.is_open())
    {
        cout<<"Bu isimde bir kullanıcı bulunamadı yeni kayıt açılıyor\n";
        return;
    }
    string text;

    while (getline(dosya, text))
    {
        if (text.empty()) {
            continue;
        }
        stringstream ss(text);

        string strTutar, geciciKategori, geciciAciklama, geciciTarih, strGelirMi;

        getline(ss, strTutar, ',');
        getline(ss, geciciKategori, ',');
        getline(ss, geciciAciklama, ',');
        getline(ss, geciciTarih, ',');
        getline(ss, strGelirMi, '\n');

        double gercekTutar = stod(strTutar);

        bool gercekGelirMi = (strGelirMi == "1");

        Transaction gecmisIslem(gercekTutar, geciciAciklama, geciciTarih, geciciKategori, gercekGelirMi);
        islemListesi.push_back(gecmisIslem);
    }
    dosya.close();
}