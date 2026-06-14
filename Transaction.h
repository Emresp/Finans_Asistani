#ifndef FINANS_ASISTANI_TRANSACTION_H
#define FINANS_ASISTANI_TRANSACTION_H
#include <string>

//İşlmeler adında ana bir sınıf oluşturuyoruz kullanıcının işlemle değerlerini değişltirmek için bu sınıf kullanılcak
class Transaction
{
    //işlem esanında kullanılcak ve önemli bilgileri private yapıyoruz ki dışardan erişim olmasın. güvenlik için
    private:
        double tutar;
        std::string aciklama,tarih, kategori;
        bool gelirMi;


    public:
    //Constructor metot yani yapıcı metot bunu kullanmamızın sebebi bu class oluşturulduğu zaman otomatik şekilde yerlerine deafult değer atmaktır
    Transaction();
    //İşlemleri yönetecek ana metot. yapıcı metot ile işlemleri yönetecek metotların adı aynı olsada derleyici hangiğsini kullancağını parametrlerden kendi anlar
    Transaction(double tutar, std::string aciklama,std::string tarih,std::string kategori,bool gelirMi);

    //Program akışında herhangi bir yerde bu değerleri okumamız gerektiği zaman sadece okumamızı sağlayacak metotlar lazımdır.
    double getTutar()const;
    std::string getAciklama()const;
    std::string getTarih()const;
    std::string getKategori()const;
    bool getGelirMi()const;

    //Genel işlem bilgisini yazdırmak için metot
    void bilgiyazdir()const;

};


#endif //FINANS_ASISTANI_TRANSACTION_H