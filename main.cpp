#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
    ifstream f("date.in");


    int n,m,i,j;
    int w;
    f>>n>>m;
    char alfa[m+1];
    for(i=1; i<=m; i++)
        f>>alfa[i];
    int stareinit;
    f>>stareinit;
    int k;
    f>>k;
    int starifin[k+1];
    for(i=1; i<=k; i++)
        f>>starifin[i];
    int l;
    f>>l;
    int trans1[l+1],trans3[l+1];
    char trans2[l+1];
    for(i=1; i<=l; i++)
        f>>trans1[i]>>trans2[i]>>trans3[i];
    /*
    cout<<n<<endl;
    cout<<m<<endl;
    for(i=1;i<=m;i++)
        cout<<alfa[i]<<" ";
    cout<<endl;
    cout<<stareinit<<endl;
    cout<<k<<endl;
    for(i=1;i<=k;i++)
    cout<<starifin[i]<<" ";
    cout<<endl;
    cout<<l<<endl;
    for(i=1;i<=l;i++)
        cout<<trans1[i]<<" "<<trans2[i]<<" "<<trans3[i]<<endl;
    */

    int drumuri[n+1][m+1][n+1];
    int lambda[n+1][n+1];
    for(i=0; i<n; i++)
        for(j=1; j<=m; j++)
            for(w=0; w<n; w++)
                drumuri[i][j][w]=-1;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            lambda[i][j]=-1;

    for(i=0; i<=l; i++)
        for(j=1; j<=m; j++)
        {
            if(alfa[j]==trans2[i])
            {
                for(w=0; w<n; w++)
                    if(drumuri[trans1[i]][j][w]==-1)
                    {

                        drumuri[trans1[i]][j][w]=trans3[i];
                        break;
                    }
            }
            else
            {
                if (trans2[i]=='$')
                    lambda[trans1[i]][trans3[i]]=1;
            }
        }
    /*for(i=0;i<n;i++)
    {for(j=0;j<n;j++)
    cout<<lambda[i][j]<<" ";
    cout<<endl;
    }

    /* for(i=0;i<n;i++)
        {for(j=1;j<=m;j++)
        {for(w=0;w<n;w++)
        cout<<drumuri[i][j][w]<<" ";
        cout<<endl;}
        cout<<endl;}
    */
    ifstream g("teste.in");
    char nfa[100];
    while(g>>nfa)
    {

//cout<<nfa;

        int curent[strlen(nfa)+1];
        int poz=1;
        curent[poz]=stareinit;
        poz++;
        int curent2[strlen(nfa)+1];
        int poz2=1;

        for(w=0; w<strlen(nfa); w++)
        {
            // cout<<nfa[w]<<endl;

            int start=1;
            int flag=1;
            while(flag==1)
            {


                flag=0;
                for(i=start; i<poz; i++)
                {
                    flag=1;
                    for(j=0; j<n; j++)
                    {

                        if (lambda[curent[i]][j]==1)
                        {
                            //cout<<"="<<j<<endl;

                            curent[poz]=j;
                            poz++;
                        }
                    }
                    start++;
                }
            }
            /*or(i=1;i<poz;i++)
                            cout<<curent[i]<<" ";
                        cout<<poz<<endl;
                        cout<<endl;*/
            /* for(i=1;i<poz;i++)
                 cout<<curent[i]<<" ";
             cout<<poz<<endl;
             cout<<endl;*/

            for(i=1; i<poz; i++)
            {
                for(j=1; j<=m; j++)
                    if(alfa[j]==nfa[w])
                    {
                        int r=0;
                        while(drumuri[curent[i]][j][r]&&drumuri[curent[i]][j][r]!=-1)
                        {
                            //cout<<drumuri[curent[i]][j][r]<<" "<<curent[i]<<" "<<j<<" "<<r<<endl;

                            curent2[poz2]=drumuri[curent[i]][j][r];
                            poz2++;
                            r++;
                        }
                    }

            }


            for(i=1; i<=poz2; i++)
                curent[i]=curent2[i];
            poz=poz2;
            poz2=1;
            /* for(i=1;i<poz;i++)
                           cout<<curent[i]<<" ";
                        cout<<poz<<endl;
                        cout<<endl;*/
        }


        cout<<nfa<<" "<<"-"<<" ";
        int flag=0;
        for(i=1; i<=k; i++)
        {
            for(j=1; j<poz; j++)
                if(starifin[i]==curent[j])
                {
                    cout<<"DA"<<endl;
                    flag=1;
                    break;
                }
            if(flag==1)
                break;
        }
        if(flag==0)
            cout<<"NU"<<endl;

    }




}
