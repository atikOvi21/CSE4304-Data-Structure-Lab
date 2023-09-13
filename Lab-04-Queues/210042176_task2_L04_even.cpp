//210042176_task2_L04_even.cpp


    #include <iostream>
    #include <queue>
    using ll = long long;

    using namespace std;



    queue<int> q,ans;
    int sz;
    
 
    // Push into the Stack
    void push_left(int x) {
       
       if( q.size() == sz) 
       {
        cout<<"The queue is full\n"; 
        return;
       }

       queue<int>temp;

       temp.push(x);

        while( !q.empty())
        {         
           temp.push(q.front());

           q.pop();
        }
        q = temp;
        

    }

    void push_right(int x)
    {
       
       if( q.size() == sz) 
       {
        cout<<"The queue is full\n"; 
        return;
       }

       queue<int>temp;
       
       temp = q;
       
       temp.push(x);
        
       q = temp;

    }

    void pop_right()
    {
        if( q.empty() )
        {
            cout<<"The queue is empty\n";
            return ;
        }

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

    void pop_left()
    {
        if( q.empty() )
        {
            cout<<"The queue is empty\n";
            return ;
        }

        q.pop();

    }
    



    int main() {

    int case_no;    
    cin>>case_no;

    int testcase;
    
    while(case_no--)
    {   

        cin>>sz>>testcase;


        push_left( 1);
        push_left(2);
        push_right(-1);
        push_right( 1);
        pop_left();
        pop_right();
        pop_left();
        pop_right();
    }

   

  

    

    }
