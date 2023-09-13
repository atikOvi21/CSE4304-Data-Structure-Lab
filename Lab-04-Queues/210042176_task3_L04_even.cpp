    //210042176_task3_L04_even.cpp
    #include <iostream>
    #include <queue>

    using namespace std;


    queue<int> q;
   
    int ping(int t) {
        
        q.push(t);

        queue<int>temp = q;

        int count = 0, value = max(0,t-3000);

        while(!q.empty())
        {
            if( q.front() >= value  )
            {
                count++;
            }
            q.pop();
        }
        q = temp;

        return count;            
    }

    int main() { 

        cout << ping(1) << "\n";
        cout << ping(2) << "\n";
        cout << ping(3) << "\n";
        cout << ping(4) << "\n";
        cout << ping(3001) << "\n";
        cout << ping(3002) << "\n";
        cout << ping(3003) << "\n";
        cout << ping(6003) << "\n";
        cout << ping(10003) << "\n";
        
        return 0;
    }

