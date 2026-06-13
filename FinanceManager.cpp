#include "FinanceManager.h"
#include "Transaction.h"

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

void FinanceManager::gecmisiListele()
{
    for (int i=0; i<islemListesi.size(); i++)
    {
        islemListesi[i].bilgiyazdir();
    }
}



double FinanceManager::getanaBakiye(){return anaBakiye;}
