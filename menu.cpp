#include "menu.h"
#include <iostream>
using namespace std;

void Menu::baslat()
{
    int secim=-1;

    while (secim !=0)
    {
        cout <<"1-) İşlem Ekle \n";
        cout <<"2-) İşlem Geçmişini Gör \n";
        cout <<"3-) Kategori Bazlı Harcama Analizi \n";
        cout <<"4-) Geçmişe Dönük Arama / Filtreleme\n";
        cout <<"0-)Kaydet Çık \n";
        cout<<"Seçim:";
        cin >> secim;


        switch (secim)
        {
            case 1:
                {
                    double tutar;
                    string kategori;
                    string aciklama;
                    int veritip=false;
                    bool gelirMi;

                    cout<<"Tutar Giriniz\n";
                    cout<<"Tutar:";
                    cin >> tutar;

                    cout<<"\n\n";

                    int katsecim;
                    bool gecerliSecim = false;
                    do
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout<<"Geçerli Bir Kategori Seçimi Yapın\n";
                        cout<<"1-Market\n";
                        cout<<"2-Teknoloji\n";
                        cout<<"3-Ulaşım\n";
                        cout<<"4-Eğlence\n";
                        cout<<"5-Diğer\n";
                        cout<<"Kategori Seçimi:";
                        cin>>katsecim;
                        switch (katsecim)
                        {
                        case 1: kategori = "Market"; gecerliSecim = true; break;
                        case 2: kategori = "Teknoloji"; gecerliSecim = true; break;
                        case 3: kategori = "Ulaşım";gecerliSecim = true; break;
                        case 4: kategori = "Eğlence";gecerliSecim = true; break;
                        case 5: kategori = "Diğer";gecerliSecim = true; break;

                        default:
                            cout<<"Gecerli Bir Seçim Yapın";
                        }

                    }while (!gecerliSecim);

                    cin.ignore(); // Tamponu temizle ki getline düzgün çalışsın
                    cout << "Aciklama Giriniz: ";
                    getline(cin, aciklama);

                    cout << "Gelir ise 1, Gider ise 0 giriniz: ";
                    cin >> veritip;
                    gelirMi = (veritip == 1);

                    //kullanıcının yaptığı işlemleri tutabilmemiz için işlemler sınıfı altında kullanıcın girdiği değerlieri vererek yeni nesne oluşturduk
                    Transaction yeniIslem(tutar,aciklama,"14.06.2026",kategori,gelirMi);
                    hesapYoneticisi.islemEkle(yeniIslem);
                    cout<<"İşlem Başarıyla Eklendii\n\n";
                }

            break;

            case 2:
            cout << "\n--- GECMIS ISLEMLER GORUNTULENIYOR ---\n";

            hesapYoneticisi.gecmisiListele();


            break;

            case 3:
            break;

            case 4:
            break;

            default:
            cout<<"Lütfen Geçerli Bir Seçim Yapın\n";
            break;
        }

    }

}