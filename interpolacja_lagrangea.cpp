#include <iostream>

using namespace std;
void sortowanie(double *wezel, double *wartosc, int n);
void interpolacjaWielomian(double *wezel, double *wartosc, int liczbaWezlow, double *wynik);
int main()
{
    int liczbaWezlow;
    cout<<"Podaj liczbe wezlow: "<<endl;
    cin>>liczbaWezlow;
    double wartoscWezlow[liczbaWezlow], wartoscFunkcji[liczbaWezlow], punkt;
    for(int i=0; i<liczbaWezlow; i++)
    {
        cout<<"podaj "<<i+1<<" wezel: "<<endl;

        while(1)//petla uniemozliwiajaca powtarzanie sie wezlow
        {
            cin>>wartoscWezlow[i];
            int czyJest=0;
            for(int j=0; j<i; j++)
            {
                if(wartoscWezlow[i]==wartoscWezlow[j]) czyJest=1;
            }
            if(czyJest==1) cout<<"podany wezel juz istnieje!! podaj inny!!"<<endl;
            else break;
        }
        cout<<"podaj wartosc funkcji w wezle "<<wartoscWezlow[i]<<": "<<endl;
        cin>>wartoscFunkcji[i];
    }
    sortowanie(wartoscWezlow, wartoscFunkcji, liczbaWezlow);
    system("cls");
    double wielomian[liczbaWezlow];
    for(int i=0; i<liczbaWezlow; i++) wielomian[i]=0;
    interpolacjaWielomian(wartoscWezlow, wartoscFunkcji, liczbaWezlow,wielomian);
    //for(int i=liczbaWezlow; i>0; i--) cout<<wielomian[i]<<" ";
    return 0;
}
void sortowanie(double *wezel, double *wartosc, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<n-1; j++)
        {
            if(wezel[j-1]>wezel[j])
            {
                swap(wezel[j-1], wezel[j]);
                swap(wartosc[j-1], wartosc[j]);
            }
        }
    }
}
void interpolacjaWielomian(double *wezel, double *wartosc, int liczbaWezlow, double *wynik)
{
    double wynik1[liczbaWezlow],tempWyniki[liczbaWezlow], temp[liczbaWezlow], dwumian[2], mianownik;

    for(int k=0; k<liczbaWezlow; k++)
    {
        for(int i=0; i<liczbaWezlow; i++)
    {
        tempWyniki[i]=0;
        temp[i]=0;
    }
        mianownik=1.0;
        for(int j=0; j<liczbaWezlow; j++)
        {
            if(j!=k)
            {
                if((j==0&&k!=0)||(j==1&&k==0))
                {
                    tempWyniki[0]=-1.0*wezel[j];
                    tempWyniki[1]=1.0;
                }
                else
                {
                    dwumian[0]=-1.0*wezel[j];
                    dwumian[1]=1.0;
                    for(int i=0; i<liczbaWezlow; i++)
                        temp[i]=0.0;
                    for(int i=0; i<liczbaWezlow-1; i++)
                    {
                        for(int p=0; p<2; p++)
                        {
                            temp[i+p]+=tempWyniki[i]*dwumian[p];
                        }
                    }

                    for(int i=0; i<liczbaWezlow; i++)
                    {
                        tempWyniki[i]=temp[i];
                    }
                }
            }
            mianownik*=(wezel[k]-wezel[j]);
        }

        for(int i=0; i<liczbaWezlow; i++)
        {
            if(tempWyniki[i]!=0)
            {
                wynik1[i]+=(tempWyniki[i]*wartosc[k])/mianownik;
            }
        }
    }
    for(int i=liczbaWezlow; i>0; i--) cout<<wynik1[i]<<" ";
}
