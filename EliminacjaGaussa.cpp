#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void elementMaksKolumna(int &wiersz, int kolumna, int liczbaR, double** macierz);
void eliminacjaKolumnaLiczenie(int liczbaM, int liczbaR, double **macierz);
void liczenieWynikow(double** macierz, int liczbaN, double* wyniki);
void wyswietlWynik(double* wyniki, int liczbaN);
void ustawienieTablicyWynikowej(double* wyniki, int* tablicaN, int liczbaN);
void uzupelnienieTabNiewiadomych(int *tab, int liczbaN);
void zamianaWierszy(int liczbaN, int wiersz1, int wierszMaks, double **macierz);
void zamianaKolumn(int liczbaR,int kolumna1, int kolumnaMaks, double** macierz, int* numerNiewiadomej);
void elementMaxPelna(int zakres, int &i, int &j, int liczbaN, int liczbaR, double** macierz);
void eliminacjaPelnaLiczenie(int liczbaN, int liczbaR, double** macierz);
bool czyZero(double p);
void eliminacjaPodstawowaLiczenie(int liczbaNiewiadomych, int liczbaRownan,double **macierz);
void rezerwacjaPamieci(int liczbaN, int liczbaR, double**& macierz);
void usuwaniePamieci(int liczbaN, int liczbaR, double**& macierz);
void daneStale(double** macierz);
void daneStalePodstawowa(double** macierz);
void wyswietlMacierz(int liczbaN, int liczbaR, double **macierz);
void wyswietlRownania(int liczbaN, int liczbaR, double** macierz);//wyscietla wprowadzona macierz jako rownania
void wczytajDane(int liczbaNiewiadomych, int liczbaRownan,double **&macierz);
void eliminacjaPodstawowa();
void eliminacjaKolumna();
void eliminacjaPelna();
void menuGlowne();

int main()
{
    cout<<setprecision(4);
    menuGlowne();
    return 0;
}
void liczenieWynikow(double** macierz, int liczbaN, double* wyniki)
{
    double temp;
    for(int i=liczbaN-1; i>=0; i--)
    {
        temp= macierz[i][liczbaN];
        for(int j=liczbaN-1; j>=i+1; j--)
        {
            temp-=macierz[i][j]*wyniki[j];
        }
        wyniki[i] = temp/macierz[i][i];
    }
}
void wyswietlWynik(double* wyniki, int liczbaN)
{
    cout<<"Rozwiazaniem ukladu rownan jest wektor x = [";
    for(int i=0; i<liczbaN; i++) cout<<" "<<wyniki[i];
    cout<<" ]T"<<endl;
}
void ustawienieTablicyWynikowej(double* wyniki, int* tablicaN, int liczbaN)
{
    for(int i=0; i<liczbaN; i++)
        for(int j=1; j<liczbaN-i; j++)
            if(tablicaN[j-1]>tablicaN[j])
            {
                swap(tablicaN[j-1],tablicaN[j]);
                swap(wyniki[j-1],wyniki[j]);
            }
}
void uzupelnienieTabNiewiadomych(int *tab, int liczbaN)
{
    for(int i=0; i<liczbaN; i++)
    {
        tab[i] = i;
    }
}
void zamianaWierszy(int liczbaN, int wiersz1, int wierszMaks, double **macierz)
{
    for(int i=0; i<liczbaN+1; i++)
    {
        swap(macierz[wiersz1][i], macierz[wierszMaks][i]);
    }
}
void zamianaKolumn(int liczbaR, int kolumna1, int kolumnaMaks, double** macierz, int* numerNiewiadomej)
{
    swap(numerNiewiadomej[kolumna1], numerNiewiadomej[kolumnaMaks]);
    for(int i=0; i<liczbaR+1; i++)
    {
        swap(macierz[i][kolumna1], macierz[i][kolumnaMaks]);
    }
}
bool czyZero(double p)
{
    if(p>=0&&p<exp(-8)) return true;
    else return false;
}
void rezerwacjaPamieci(int liczbaN, int liczbaR, double**& macierz)
{
    macierz= new double*[liczbaN+1];
    for(int i=0; i<liczbaN+1; i++)//+1 bo wiersz wynikowy
    {
        macierz[i] = new double[liczbaR];
    }
}
void usuwaniePamieci(int liczbaN, int liczbaR, double**& macierz)
{
    for(int i=0; i<liczbaN+1; i++)
    {
        delete [] macierz[i];
    }
    delete macierz;
}
void daneStale(double** macierz)
{
    macierz[0][0] = 2.25;
    macierz[0][1] = -2.5;
    macierz[0][2] = 4;
    macierz[0][3] = -5.25;
    macierz[0][4] = -1;
    macierz[1][0] = -3;
    macierz[1][1] = -7.5;
    macierz[1][2] = 6.5;
    macierz[1][3] = 0;
    macierz[1][4] = 17;
    macierz[2][0] = -6.25;
    macierz[2][1] = -12.5;
    macierz[2][2] = 0.25;
    macierz[2][3] = 5.25;
    macierz[2][4] = 24.25;
    macierz[3][0] = 9;
    macierz[3][1] = 10;
    macierz[3][2] = 7;
    macierz[3][3] = -21;
    macierz[3][4] = -33;
}
void daneStalePodstawowa(double** macierz)
{
    macierz[0][0] = 1;
    macierz[0][1] = 1;
    macierz[0][2] = 0;
    macierz[0][3] = -3;
    macierz[0][4] = 1;
    macierz[1][0] = 1;
    macierz[1][1] = 4;
    macierz[1][2] = -1;
    macierz[1][3] = -4;
    macierz[1][4] = -2;
    macierz[2][0] = 0.5;
    macierz[2][1] = 0.5;
    macierz[2][2] = -3;
    macierz[2][3] = -5.5;
    macierz[2][4] = 1.5;
    macierz[3][0] = 1.5;
    macierz[3][1] = 3;
    macierz[3][2] = -5;
    macierz[3][3] = -9;
    macierz[3][4] = -0.5;
}
void wyswietlMacierz(int liczbaN, int liczbaR, double **macierz)
{
    for(int i=0; i<liczbaR; i++)
    {
        for(int j=0; j<liczbaN+1; j++)
        {
            if(j==liczbaN) cout<<" | "<<setw(6)<<macierz[i][j];
            else cout<<setw(6)<<macierz[i][j]<<" ";
        }
        cout<<endl;
    }
}
void wyswietlRownania(int liczbaN, int liczbaR, double** macierz)
{
    for(int i=0; i<liczbaR; i++)
    {
        for(int j=0; j<liczbaN+1; j++)
        {
            if(j==liczbaN) cout<<setw(5)<<macierz[i][j];
            else if(j==liczbaN-1) cout<<setw(5)<<macierz[i][j]<<" *x"<<j+1<<" = ";
            else cout<<setw(5)<<macierz[i][j]<<" *x"<<j+1<<" + ";
        }
        cout<<endl;
    }
}
void wczytajDane(int liczbaNiewiadomych, int liczbaRownan,double **&macierz)
{
    cout<<"Liczony uklad rownan ma postac: "<<endl;
    for(int i=0; i<liczbaRownan; i++)
    {
        for(int j=0; j<liczbaNiewiadomych+1; j++)
        {
            if(j!=liczbaNiewiadomych)
            {
                cout<<"Podaj wspolczynnik przy x"<<j+1<<" w rownaniu "<<i+1<<": ";
                cin>>macierz[i][j];
            }
            else
            {
                cout<<"Podaj wynik rownania "<<i+1<<": ";
                cin>>macierz[i][j];
            }
        }
    }
}

void eliminacjaPodstawowa()
{
    char wyborDanych='0';
    cout<<"Jezeli chcesz samodzielnie wczytac dane wprowadz - [1](slownie: jeden)"<<endl
        <<"Jezeli chcesz skorzystac z danych zawartych w programie wprowadz dowolny inny znak"<<endl;
    cin>>wyborDanych;
    if(wyborDanych=='1')
    {
        int liczbaNiewiadomych, liczbaRownan;
        cout<<"Podaj liczbe niewiadomych: ";
        cin>>liczbaNiewiadomych;
        cout<<"Podaj liczbe rownan: ";
        cin>>liczbaRownan;
        double** macierz;
        rezerwacjaPamieci(liczbaNiewiadomych,liczbaRownan,macierz);
        wczytajDane(liczbaNiewiadomych, liczbaRownan, macierz);
        wyswietlRownania(liczbaNiewiadomych, liczbaRownan,macierz);
        eliminacjaPodstawowaLiczenie(liczbaNiewiadomych, liczbaRownan, macierz);
        usuwaniePamieci(liczbaNiewiadomych, liczbaRownan, macierz);
    }
    else
    {
        double** macierz;
        rezerwacjaPamieci(4,4,macierz);
        daneStalePodstawowa(macierz);
        wyswietlRownania(4,4,macierz);
        eliminacjaPodstawowaLiczenie(4, 4, macierz);
        usuwaniePamieci(4,4,macierz);
    }
}
void eliminacjaPodstawowaLiczenie(int liczbaNiewiadomych, int liczbaRownan,double **macierz)
{

    if(macierz[0][0]!=0)
    {
        double p;
        bool czyWynik=true;
        for(int k=0; k<liczbaNiewiadomych-1; k++)
        {
            if(!czyZero(macierz[k][k]))
            {
                for(int i=k+1; i<liczbaNiewiadomych; i++)
                {
                    p=macierz[i][k]/macierz[k][k];
                    //cout<<p<<endl;
                    for(int j=k; j<liczbaNiewiadomych+1; j++)
                    {
                        if(!czyZero(p))
                            macierz[i][j]-=p*macierz[k][j];
                    }
                }
            }
            else
            {
                cout<<" 0 na glownej przekatnej!!! Nie mozna rozwiazac macierzy postepowaniem Gaussa!"<<endl;
                czyWynik=false;
                break;
            }

            cout<<"Macierz powstala po "<<k+1<<" kroku eliminacji podstawowej Gaussa: "<<endl;
            wyswietlMacierz(liczbaNiewiadomych, liczbaRownan, macierz);
        }
        if(czyWynik&&macierz[liczbaRownan-1][liczbaNiewiadomych-1]!=0)
        {
            double wyniki[liczbaNiewiadomych];
            liczenieWynikow(macierz, liczbaNiewiadomych, wyniki);
            wyswietlWynik(wyniki, liczbaNiewiadomych);
        }
        else cout<<"sprzeczny uklad rownan!"<<endl;
    }
    else cout<<"Nie mozna rozwiac równanie postepowaniem Gaussa!"<<endl;
}
void eliminacjaKolumna()
{
    char wyborDanych='0';
    cout<<"Jezeli chcesz samodzielnie wczytac dane wprowadz - [1](slownie: jeden)"<<endl
        <<"Jezeli chcesz skorzystac z danych zawartych w programie wprowadz dowolny inny znak"<<endl;
    cin>>wyborDanych;
    if(wyborDanych=='1')
    {
        int liczbaNiewiadomych, liczbaRownan;
        cout<<"Podaj liczbe niewiadomych: ";
        cin>>liczbaNiewiadomych;
        cout<<"Podaj liczbe rownan: ";
        cin>>liczbaRownan;
        double** macierz;
        rezerwacjaPamieci(liczbaNiewiadomych,liczbaRownan,macierz);
        wczytajDane(liczbaNiewiadomych, liczbaRownan, macierz);
        wyswietlRownania(liczbaNiewiadomych, liczbaRownan,macierz);
        eliminacjaKolumnaLiczenie(liczbaNiewiadomych, liczbaRownan, macierz);
        usuwaniePamieci(liczbaNiewiadomych, liczbaRownan, macierz);
    }
    else
    {
        double** macierz;
        rezerwacjaPamieci(4,4,macierz);
        daneStale(macierz);
        wyswietlRownania(4,4,macierz);
        eliminacjaKolumnaLiczenie(4, 4, macierz);
        usuwaniePamieci(4,4,macierz);
    }

}
void elementMaksKolumna(int &wiersz, int kolumna, int liczbaR, double** macierz)
{
    double maks=macierz[kolumna][kolumna];
    int tempWiersz=kolumna;
    for(int i=kolumna+1; i<liczbaR; i++)
    {
        if(fabs(macierz[i][kolumna]>maks))
        {
            maks=fabs(macierz[i][kolumna]);
            tempWiersz = i;
        }
    }
    wiersz = tempWiersz;
    cout<<macierz[wiersz][kolumna]<<endl;
}
void eliminacjaKolumnaLiczenie(int liczbaN, int liczbaR, double **macierz)
{
    int wiersz;
    if(macierz[0][0]!=0)
    {
        double p;
        bool czyWynik=true;
        for(int k=0; k<liczbaN-1; k++)
        {
            if(!czyZero(macierz[k][k]))
            {
                elementMaksKolumna(wiersz,k,liczbaR, macierz);
                if(wiersz!=k) zamianaWierszy(liczbaN, k, wiersz, macierz);
                //wyswietlMacierz(liczbaN, liczbaR, macierz);
                for(int i=k+1; i<liczbaN; i++)
                {

                    p=macierz[i][k]/macierz[k][k];
                    //cout<<p<<endl;
                    for(int j=k; j<liczbaN+1; j++)
                    {
                        if(!czyZero(p)||p==-0)
                            macierz[i][j]-=p*macierz[k][j];
                    }
                }
            }
            else
            {
                cout<<" 0 na glownej przekatnej!!! Nie mozna rozwiazac macierzy postepowaniem Gaussa!"<<endl;
                czyWynik=false;
                break;
            }

            cout<<"Macierz powstala po "<<k+1<<" kroku eliminacji podstawowej Gaussa: "<<endl;
            wyswietlMacierz(liczbaN, liczbaR, macierz);
        }
        if(czyWynik&&macierz[liczbaR-1][liczbaN-1]!=0)
        {
            double wyniki[liczbaN];
            liczenieWynikow(macierz, liczbaN, wyniki);
            wyswietlWynik(wyniki, liczbaN);
            cout<<"kutas"<<endl;
        }
        else cout<<"sprzeczny uklad rownan!"<<endl;
    }
    else cout<<"Nie mozna rozwiac równanie postepowaniem Gaussa!"<<endl;
}
void eliminacjaPelna()
{
    char wyborDanych='0';
    cout<<"Jezeli chcesz samodzielnie wczytac dane wprowadz - [1](slownie: jeden)"<<endl
        <<"Jezeli chcesz skorzystac z danych zawartych w programie wprowadz dowolny inny znak"<<endl;
    cin>>wyborDanych;
    if(wyborDanych=='1')
    {
        int liczbaNiewiadomych, liczbaRownan;
        cout<<"Podaj liczbe niewiadomych: ";
        cin>>liczbaNiewiadomych;
        cout<<"Podaj liczbe rownan: ";
        cin>>liczbaRownan;
        double** macierz;
        rezerwacjaPamieci(liczbaNiewiadomych,liczbaRownan,macierz);
        wczytajDane(liczbaNiewiadomych, liczbaRownan, macierz);
        wyswietlRownania(liczbaNiewiadomych, liczbaRownan,macierz);
        eliminacjaPelnaLiczenie(liczbaNiewiadomych, liczbaRownan, macierz);
        usuwaniePamieci(liczbaNiewiadomych, liczbaRownan, macierz);
    }
    else
    {
        double** macierz;
        rezerwacjaPamieci(4,4,macierz);
        daneStale(macierz);
        wyswietlRownania(4,4,macierz);
        eliminacjaPelnaLiczenie(4, 4, macierz);
        usuwaniePamieci(4,4,macierz);
    }

}
void elementMaxPelna(int zakres,int &wiersz, int &kolumna, int liczbaN, int liczbaR, double** macierz)
{
    double maks = macierz[zakres][zakres];
    int w=zakres;
    int k=zakres;
    for(int i=zakres; i<liczbaR; i++)
    {
        for(int j=zakres; j<liczbaN; j++)
        {
            if(fabs(macierz[i][j])>=maks)
            {
                w=i;
                k=j;
                maks=fabs(macierz[i][j]);
            }
        }
    }
    cout<<macierz[w][k];
    wiersz=w;
    kolumna=k;
}
void eliminacjaPelnaLiczenie(int liczbaN, int liczbaR, double** macierz)
{
    int kolumna;
    int wiersz;
    int numerNiewiadomej[liczbaN];
    uzupelnienieTabNiewiadomych(numerNiewiadomej, liczbaN);
    if(macierz[0][0]!=0)
    {
        double p;
        bool czyWynik=true;
        for(int k=0; k<liczbaN-1; k++)
        {
            if(!czyZero(macierz[k][k]))
            {
                elementMaxPelna(k, wiersz, kolumna, liczbaN,liczbaR, macierz);
                if(wiersz!=k) zamianaWierszy(liczbaN,k,wiersz,macierz);
                if(kolumna!=k) zamianaKolumn(liczbaR,k,kolumna,macierz,numerNiewiadomej);
                //wyswietlMacierz(liczbaN, liczbaR, macierz);
                for(int i=k+1; i<liczbaN; i++)
                {

                    p=macierz[i][k]/macierz[k][k];
                    //cout<<p<<endl;
                    for(int j=k; j<liczbaN+1; j++)
                    {
                        if(!czyZero(p)||p==-0)
                            macierz[i][j]-=p*macierz[k][j];
                    }
                }
            }
            else
            {
                cout<<" 0 na glownej przekatnej!!! Nie mozna rozwiazac macierzy postepowaniem Gaussa!"<<endl;
                czyWynik=false;
                break;
            }

            cout<<"Macierz powstala po "<<k+1<<" kroku eliminacji podstawowej Gaussa: "<<endl;
            wyswietlMacierz(liczbaN, liczbaR, macierz);
        }
        if(czyWynik&&macierz[liczbaR-1][liczbaN-1]!=0)
        {
            double wyniki[liczbaN];
            liczenieWynikow(macierz, liczbaN, wyniki);
            ustawienieTablicyWynikowej(wyniki, numerNiewiadomej, liczbaN);
            wyswietlWynik(wyniki, liczbaN);
        }
        else cout<<"sprzeczny uklad rownan!"<<endl;
    }
    else cout<<"Nie mozna rozwiac równanie postepowaniem Gaussa!"<<endl;
}
void menuGlowne()
{

    short int wyborMenu=0;
    while(wyborMenu!=4)
    {
        //system("cls");
        cout<<setw(50)<<"-------Metody eliminacji Gaussa-------"<<endl;
        cout<<"1) Eliminacja podstawowa.........................................."<<endl
            <<"2) Eliminacja z wyborem elementu maksymalnego w kolumnie.........."<<endl
            <<"3) Eliminacja z pelnym wyborem elementu maksymalnego.............."<<endl
            <<"4) Wyjscie........................................................"<<endl
            <<"wybor:"<<endl;
        cin>>wyborMenu;
        switch(wyborMenu)
        {
        case 1:
        {
            system("cls");
            cout<<setw(50)<<"-----Metoda eliminacji podstawowej Gaussa-----"<<endl;
            eliminacjaPodstawowa();
            break;
        }
        case 2:
        {
            system("cls");
            cout<<setw(80)<<"-----Metoda eliminacji Gaussa z wyborem elementu maksymalnego w kolumnie-----"<<endl;
            eliminacjaKolumna();
            break;
        }
        case 3:
        {
            system("cls");
            cout<<setw(70)<<"-----Metoda eliminacji Gaussa z pelnym wyborem elementu maksymalnego-----"<<endl;
            eliminacjaPelna();
            break;
        }
        case 4:
        {
            system("cls");
            cout<<"Szymon Dudek - styczen 2023"<<endl;
            break;
        }
        default:
        {
            system("cls");
            cout<<"Wybierz z listy!!!!"<<endl;
        }
        }
    }
}

