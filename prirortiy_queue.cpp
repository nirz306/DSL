#include<iostream>
using namespace std;

template <class T>
class Pri_que{
	private:
		int prirority;
		T number;
		int qsize=5;
	public:
		void enqueue(Pri_que arr[5]);
		T dequeue(Pri_que arr[5]);
		void display(Pri_que arr[5]);
		void sort(Pri_que arr[5]);
		bool empty(Pri_que arr[5]);
		bool full(Pri_que arr[5]);
};

int head=-1;
int tail=-1;

template <class T>
bool Pri_que<T>::full(Pri_que arr[5])
{
	if(tail==qsize-1)
	return 1;
	else
	return 0;
}

template <class T>
void  Pri_que<T>::enqueue(Pri_que arr[5])
{	
	tail++;
	while(tail!=qsize)
	{
		cout<<"Enter id: "; cin>>arr[tail].number;
		cout<<"Enter prirority: ";cin>>arr[tail].prirority;	
		tail++;
	}
}

template <class T>
void  Pri_que<T>::display(Pri_que arr[5])
{
	int i =0;
	while(i!=qsize)
	{
		cout<<arr[i].number<<"			"<<arr[i].prirority<<endl;
		i++;
	}
}

template <class T>
void Pri_que<T>::sort(Pri_que arr[5]) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5 - i - 1; j++) {
            if (arr[j].prirority > arr[j + 1].prirority) {
                swap(arr[j].prirority, arr[j + 1].prirority);
                swap(arr[j].number, arr[j + 1].number);
            }
        }
    }
}

template <class T>
T Pri_que<T>::dequeue(Pri_que arr[5]) 
{
	head++;
	qsize = 5;
	if(head==qsize)
	{
		cout<<"Queue is empty"<<endl;
		return 0;
	}
    else
    {
		return arr[head].number;   // Assuming 'number' is the element you want to dequeue
	}
}

int main()
{
Pri_que <int> intp[5];                //array of 5objects of pri_que class
Pri_que <float> floatp[5]; 

intp[0].enqueue(intp);

cout << "-------------------------Input Queue------------------------" << endl;
cout << "Number" << "			" << "Priority" << endl;									//displays the original queuq
intp[0].display(intp);

intp[0].sort(intp);                                                                        //will sort the queue
cout << "-------------------------Prirority Queue------------------------" << endl;
cout << "Number" << "			" << "Priority" << endl;									//displays the sorted queue
intp[0].display(intp);

cout<<"----------------Deque operation----------------"<<endl;                            
cout<<intp[0].dequeue(intp);
cout<<endl;
cout<<intp[0].dequeue(intp);
cout<<endl;
cout<<intp[0].dequeue(intp);
cout<<endl;
cout<<intp[0].dequeue(intp);
cout<<endl;
cout<<intp[0].dequeue(intp);
cout<<endl;
cout<<intp[0].dequeue(intp); //error



//simmilar operation can be performed on float data type also 



return 0;
}
