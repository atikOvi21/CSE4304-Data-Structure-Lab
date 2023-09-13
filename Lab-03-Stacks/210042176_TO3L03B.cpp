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

        stack<char>st;

        for (int i = 0; i < s.size(); ++i)
        {
          
          if( st.empty() ){ st.push(s[i]);  }

          else if( s[i]==st.top() )
          {
            st.pop();
          }
          else
          {
            st.push(s[i]);
          }
        }

        stack<char>ans;
        while(!st.empty())
        {
            ans.push(st.top());
            st.pop();
            //cout<<st.top()
        }
        
        cout<<"[";
        
        while(!ans.empty()){
            
            cout<<ans.top();
            ans.pop();
        }
        
        cout<<"]"<<endl;
        
    }

    int main()
    {
        
        init_code();

        int tt;    
        cin>>tt;
        cin.ignore();

        while(tt--)
        {
            solve();
        }

    }