#include "Transaction.h"
#include <iostream>

//Yapıcı metot için default atamalar yapıldı
Transaction::Transaction()
{
    tutar=0;
    aciklama="";
    tarih="";
    kategori="";
    gelirMi=true;
}

//Yapıcı metot parameterleri şekilde çağırılırsa atamaların yapılması için
Transaction::Transaction(double tutar, std::string aciklama, std::string tarih, std::string kategori, bool gelirMi)
{
    this->tutar=tutar;
    this->aciklama=aciklama;
    this->tarih=tarih;
    this->kategori=kategori;
    this->gelirMi=gelirMi;
}

//Private kısmındaki değişkenleri sadece okuyabilmek içinb gerekli metotlar
double Transaction::getTutar()const{return tutar;}
std::string Transaction::getAciklama()const{return aciklama;}
std::string Transaction::getTarih()const{return tarih;}
std::string Transaction::getKategori()const{return kategori;}
bool Transaction::getGelirMi()const{return gelirMi;}


void Transaction::bilgiyazdir()
{
    //Bilgilerin hepsinni bir arada düzgün şekilde görebilmek için
    //Son değişkende Ternary operaötürü kullandım (kosul) ? "Doğruysa Çıkacak Sonuç" : "Yanlışsa Çıkacak Sonuç"
    //Beklenen örenk çıktıo formatı: [13.06.2026] Market - Gıda | Tutar: 250 TL | Tip: Gider
    std::cout<<"["<<getTarih()<<"]"<<" "<<getKategori()<<"-"<<getAciklama()<<"|"<<" "<<"Tutar:"<<" "<< getTutar()<<" TL"<<" | "<<"Tip: "<<(getGelirMi() ? "Gelir" : "Gider")<<"\n"<<std::endl;
}


