#include<iostream>
using namespace std;

class Deque
{
    private:
        int front;
        int rear;
        int size;
        int deque[5];
    public:
    Deque()  //constructor
    {
        size = 5;
        rear =-1;
        front = -1;
        for(int i=0;i<size;i++)  //initializing an empty queue
        {
            deque[i] = -1;
        }
    }

    void insert_at_front(int value)
    {
        if(front!=-1)
        {
            
            deque[front] = value;
            front--;
            cout<<value<<" added at index "<<front<<endl;
        }
        else{
            cout<<"Deque is full!!"<<endl;
        }
        display();
    }

    void insert_at_rear(int value)
    {
          
        if(rear!=size-1)
        {
            rear++;
            deque[rear] = value;
            cout<<value<<" added at index "<<rear<<endl;
        }
        else{
            cout<<"Deque is full!!"<<endl;
        }
        display();
    }

    void delete_at_front()
    {
        if(front!=rear)
        {
             front++;
            deque[front] = -1;
            cout<<"Element removed from index "<<front<<endl;
        }
        else{
            cout<<"Deque is empty!!"<<endl;
        }
        display();
    }

    void delete_at_rear()
    {
        if(front!=rear)
        {
            deque[rear] = -1;
            rear--;
           cout<<"Element removed from index "<<rear<<endl;
        }
        else{
            cout<<"Deque is empty!!"<<endl;
        }
        display();
    }

    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<"|"<<deque[i]<<"|"<<" ";
        }
        cout<<endl;
    }

};

int main(){
    Deque obj1;
    cout<<"Initial queue: "<<endl;
    obj1.display();

    int choice,flag = 0;
    while(flag == 0)
    {
    cout<<"1.Insert at rear  2.Delete from front  3.Insert from front  4.Delete from rear "<<endl;
    cin>>choice;
      int value;
    if(choice == 1)
    {
        cout<<"Enter value to be inserted"<<endl;
        cin>>value;
        obj1.insert_at_rear(value);
    }
    else if(choice == 2)
    {
        obj1.delete_at_front();
    }
    else if(choice == 3)
    {
        cout<<"Enter value to be inserted"<<endl;
        cin>>value;
        obj1.insert_at_front(value);
    }
    else if(choice == 4)
    {
                obj1.delete_at_rear();

    }
    cout<<"press 0 to continue and any other to end "<<endl;
    cin>>flag;
    }


    // obj1.insert_at_rear(1);
    // obj1.insert_at_rear(2);
    // obj1.insert_at_rear(3);
    // obj1.insert_at_rear(4);
    // obj1.insert_at_rear(5);  //rear=5
    // obj1.insert_at_rear(6);  //will show error

    // obj1.delete_at_front();
    // obj1.delete_at_front();
    // obj1.delete_at_front();
    // obj1.delete_at_front();
    // obj1.delete_at_front(); //front =4
    // obj1.delete_at_front(); //will show error
    
    
    // obj1.insert_at_front(5);
    // obj1.insert_at_front(4);
    // obj1.insert_at_front(3);
    // obj1.insert_at_front(2);
    // obj1.insert_at_front(1);  //front = 0
    // obj1.insert_at_front(0);  //shows error

    // obj1.delete_at_rear();   
    // obj1.delete_at_rear();
    // obj1.delete_at_rear();
    // obj1.delete_at_rear();
    // obj1.delete_at_rear();
    // obj1.delete_at_rear();


}
