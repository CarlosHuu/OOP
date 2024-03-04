#include <iostream>
using namespace std;

int main()
{
        int a,b;

        while(1)
        {
                cin>>a;
                b=a;
                if(a==0)
                {
                        return 0;
                }
                else if(a==1)
                {
                        cout<<a<<endl;
                }
                else
                {
                        for(int i=2;i<=a;i++)
                        {
                                if(b%i==0)
                                {
                                        cout<<i;
                                        b/=i;
                                        if(b!=1)
                                        {
                                                cout<<"*";
                                        }
                                        i--;
                                }

                        }
                        cout<<endl;
                }
        }
}


