#include <iostream>
using namespace std;

struct nodeType{
    int info;
    nodeType* link;
};
class LinkedStack
{
    private:
    nodeType* stackTop;
    void copy(const LinkedStack& o);

    public:
    LinkedStack();
    void initializeStack();
    bool isEmpty();
    bool isFull();
    void push(const int& item);
    void pop();
    int top()const;
    const LinkedStack& operator=(const LinkedStack& o);
    LinkedStack(const LinkedStack& o);
    ~LinkedStack();
    void convertToBinary (int X);
    void convertToOctal(int X);
    void convertToHexadecimal(int X);


};

LinkedStack::LinkedStack()
{
    this->stackTop = nullptr;
}

void LinkedStack::initializeStack()
{
    nodeType* temp;
    while(this->stackTop!=nullptr)
    {
        temp = this->stackTop;
        this->stackTop = this->stackTop->link;
        delete temp;
    }
}

bool LinkedStack::isEmpty()
{
    return (this->stackTop==nullptr);
}

void LinkedStack::push(const int& item)
{
    nodeType* newNode = new nodeType;
    newNode->info = item;
    newNode->link = this->stackTop;
    this->stackTop = newNode;
}



void LinkedStack::pop()
{
    if(this->stackTop==nullptr)
        cout << "The Stack Is Empty " << endl;
    else{
        nodeType* temp;
        temp = this->stackTop;
        this->stackTop = this->stackTop->link;
        delete temp;
    }
}

int LinkedStack::top()const
{
    assert(this->stackTop!=nullptr);
    return (this->stackTop->info);
}

void LinkedStack::copy(const LinkedStack& o)
{
    if(o.stackTop==nullptr)
        this->stackTop = nullptr;
    if(this->stackTop!=nullptr)
        initializeStack();
    else{
        nodeType* newNode , *current,*last;
        current = o.stackTop;
        this->stackTop = new nodeType;
        this->stackTop->info = current->info;
        this->stackTop->link = nullptr;
        last = this->stackTop;
        current = current->link;

        while(current!=nullptr)
        {
            newNode = new nodeType;
            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}


const LinkedStack& LinkedStack::operator=(const LinkedStack& o)
{
    if(this!=&o)
        copy(o);
    return *this;
}

LinkedStack::LinkedStack(const LinkedStack& o)
{
    this->stackTop=nullptr;
    copy(o);
}

LinkedStack::~LinkedStack()
{
    initializeStack();
}

void LinkedStack::convertToBinary(int X)
{
    int b;
    while(X!=0)
    {
        b=X%2;
        X/=2;
        push(b);
    }
    while(!isEmpty())
    {
        cout << top();
        pop();
    }
    cout << endl;
}

void LinkedStack::convertToOctal(int X)
{
    int b;
    while(X!=0)
    {
        b=X%8;
        X/=8;
        push(b);
    }
    while(!isEmpty())
    {
        cout << top();
        pop();
    }
    cout << endl;

}

void LinkedStack::convertToHexadecimal(int X)
{
    int b;
    while(X!=0)
    {
        b=X%16;
        X/=16;
        if(b<10)
            push(b);
        else
            push(b+55);
        
    }
    while(!isEmpty())
    {
        if(top()<10){
        cout << top();
        pop();
        }
        else{
            cout << char(top());
            pop();
        }
    }
    cout << endl;

}


int main()
{cout << "-------------------------------------------------------------------" << endl;
    LinkedStack x;
    int n;
    int X;
     do
    {
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Enter a positive integer:  ";
        cin >> X;
    } while (X <= 0);

    do{
        cout << "===================================================================" << endl;
        cout << "Press Number 1 If You Want To Convert The Number To Binary" << endl;
        cout << "Press Number 2 If You Want To Convert The Number To Hexadecimal" << endl;
        cout << "Press Number 3 If You Want To Convert The Number To Octal" << endl;
        cout << "Press Number 4 To Exit " << endl; 
        cout << "Choose The Operation From 1-4 : ";
        cin>>n; 
        switch(n)
        {
            case 1:{
                cout << "-------------------------------------------------------------------" << endl;
                cout << "The Result In Binary Num Is : " ;
                x.convertToBinary(X);
                cout << "-------------------------------------------------------------------" << endl;
                cout << endl;
                break;
            }
           
            case 2:{
                cout << "-------------------------------------------------------------------" << endl;
                cout << "The Result In Hexadecimal Num Is : " ;
                x.convertToHexadecimal(X);
                cout << "-------------------------------------------------------------------" << endl;
                cout << endl;
                break;
            }

            case 3:{
                cout << "-------------------------------------------------------------------" << endl;
                cout << "The Result In Octal Num Is : " ;
                x.convertToOctal(X);
                cout << "-------------------------------------------------------------------" << endl;
                cout << endl;
                break;
            }
            case 4: {
                cout << "-------------------------------------------------------------------" << endl;
                cout << "GoodBye :)" << endl;
                cout << "-------------------------------------------------------------------" << endl;
                break;
                }
            default :{
                cout << "-------------------------------------------------------------------" << endl;
                cout << "Non Valid Number , Please Try Again " << endl;
                cout << "-------------------------------------------------------------------" << endl << endl; 
                break;
                }
        }
    } while (n!=4);

    return 0;
}
    