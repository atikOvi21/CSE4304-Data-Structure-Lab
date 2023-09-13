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

void solve()
{
    string s;           getline(cin,s);
    
    //cout<<s<<endl;

        stack<char>st;

        for (int i = 0; i < s.size(); ++i)
        {
            if( s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
            }
            
            else if( s[i]==')')
            {   
                if(st.empty()) {cout<<"No\n";  return;}
                char c = st.top(); //cout<<"c--"<<c<<endl;
                
                if( c == '(' ){
                    st.pop();
                }
                
                else
                {
                    cout<<"No\n";   return;
                }
            }
            
            else if( s[i]==']')
            {   
                if(st.empty()) {cout<<"No\n";  return;}
                char c = st.top(); //cout<<"c--"<<c<<endl;
                
                if( c == '[' ){
                    st.pop();
                }
                
                else
                {
                    cout<<"No\n";  return;
                }
            }
            
            else if( s[i]=='}')
            {   
                if(st.empty()) {cout<<"No\n";  return;}
                char c = st.top(); //cout<<"c--"<<c<<endl;
                
                if( c == '{' ){
                    st.pop();
                }
                
                else
                {
                    cout<<"No\n";  return;
                }
            }
        }

        if((!st.empty()))  cout<<"NO\n";
        else cout<<"YES\n";
}

int main(){
    
    init_code();

    int tt;    cin>>tt;
    cin.ignore();

    while(tt--)
    {
        solve();
    }

}