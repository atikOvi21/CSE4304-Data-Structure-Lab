#include <iostream>
#include <stack>
#include <vector>
using ll = long long;

using namespace std;


void init_code(){
    ios_base::sync_with_stdio(false);           cin.tie(NULL);
    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    #endif
}

int main(){

    init_code();

    int sz ;
    cin>>sz;

    int a[sz]={0},i=0;

    while(1){

        int n;
        cin>>n;

        if(  n == (-1) ) break;

        //push
        if( n == 1){

            int x;

            cin>>x;

            if(i==sz) cout<<"Overflow\n";
            else {


                a[i]=x;    if(i<sz) ++i;

                for( int k=0; k<i; k++)     cout<<a[k]<<" ";

                cout<<endl;
            }
        }

        //pop
        else if( n == 2){

            if( i == 0 ) cout<<"Underflow\n";

            else {
                if( i > 0 )--i;
                for(int k=0; k<i; k++) cout<<a[k]<<" ";         cout<<endl;
            }
        }

        //isEmpty
        else if( n == 3 ) {
            if( !i )   cout<<"True\n";     else cout<<"False\n";
        }

        //isFull
        else if( n == 4) {
            if( i == sz)    cout<<"True\n";     else cout<<"False\n";
        }

        //size
        else if( n == 5){
            cout<<i<<endl;
        }

        //top
        else{
            if(i>=1) {cout<<a[i-1]<<endl;}
            else cout<<"Underflow\n";
        }

    }

    return 0;


}
