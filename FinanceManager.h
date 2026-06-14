#ifndef FINANS_ASISTANI_FINANCEMANAGER_H
#define FINANS_ASISTANI_FINANCEMANAGER_H
#include <vector>
#include "Transaction.h"

class FinanceManager
{
    private:
        std::vector<Transaction> islemListesi;
        double anaBakiye;

    public:
        //Yapıcı metot
        FinanceManager();

    void islemEkle(const Transaction& yeniIslem);
    //Private kısmındaki bakiyeyi okuyabilmek için
    double getanaBakiye();
    //tüm işlemleri görebilmek için
    void gecmisiListele();
    //Kişinin yaptığı harcamları analiz edip grafiğe dökmek için
    void kategoriAnalizi()const;

    void maxharcama() const;
    void minharcama() const;

};

#endif //FINANS_ASISTANI_FINANCEMANAGER_H