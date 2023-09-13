    //210042176_task4_L04_even.cpp
    #include <iostream>
    #include <queue>
    using ll = long long;

    using namespace std;

    queue<int> q,ans;

    // Push into the Stack
    void push_s(int x) {
       
        q.push(x);
        

    }

    // Removes the element on top of the stack.
    void pop_s()
    {   
        if( q.empty() ) return;
        queue<int>temp;
       
        while( !q.empty())
        {
           if( q.size() == 1) 
           {
                break;
           }

           temp.push(q.front());

            q.pop();
        }

        q = temp;
  
        
    }
    // Get the top element.
    int top_s() {
        
        queue<int>temp,t;
        temp = q;

        while( !temp.empty() )
        {
            if(temp.size()==1) cout<<temp.front()<<endl;
            temp.pop();
        }


    }
    // Return whether the stack is empty.
    bool empty_s() {

        if(!(q.size())) 
        {
            cout<<"1"<<endl;
        }
        else cout<<"0"<<endl;
    }
    

    int main() {

    init_code();

   

  

    push_s(10);
     top_s() ;
    push_s(20);
     top_s() ;
    pop_s();
     top_s() ;
    push_s(100);
     top_s() ;
    empty_s() ;
    pop_s();
    pop_s();
    empty_s();
    

    }
