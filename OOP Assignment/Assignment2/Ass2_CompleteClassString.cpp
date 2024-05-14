#include <iostream>
using namespace std;
class String
{
    private:
        char* name;
    
    public:
        String() : name(nullptr)
        {
           setString(""); 
        }

        String(const char* n) : name(nullptr)
        {
            setString(n);
        }

        String(const char n) : name(nullptr)
        {
            char T[2] ={n,'\0'};
            setString(T);
        }

        String(const int x) : name(nullptr)
        {
            char T[2] = {x,'\0'};
            setString(T);
        }

        String(const String &R) : name(nullptr) // member-wise copier ... deep copy ... copy constructer
        {
            //setString(R.name);
            this->setString(R.getString());
        }

        ~String()
        {
            if(this->name!=nullptr)
                delete [] this->name;
            this->name = nullptr;
        }

        inline void setString(const char *n="None")
        {
            this->~String();
           /* this->name = new char[strlen(n)+1];
            strcpy(this->name,n); */
            this->name = strdup(n); 
        }

        inline char* getString()const{
            return this->name;
        }

        friend ostream &operator<<(ostream &out,String &N)
        {
            out << "The string is : " << N.getString() << endl;
            return out;
        }

        friend istream &operator>>(istream &in,String &N)
        {
            char* n = new char[100];
            cout << "Enter the string : ";
            in >> n; // gets_s(n, 100);
            N.setString(n);
            delete []n;
            return in;
        }

        String &operator=(const String &R) // & in aple operator cascading like A = B = C; 
        {
            if(this!=&R)
                this->setString(R.getString());
            return *this;

        }

        String &operator=(const char* n)
        {
            this->setString(n);
            return *this;
        }

        String &operator=(const char n)
        {
            String temp = n;
            *this = temp; //this->setString(temp.getString());
            return *this;
        }

        String &operator=(const int n)
        {
            String temp = n;
            *this = temp;
            return *this;
        }

        String operator+(const String &T)
        {
            char *p = nullptr;
            p = new char[strlen(this->getString())+strlen(T.getString())+1];
            strcpy(p,this->getString());
            strcat(p,T.getString());

            String A = p;
            delete []p;
            return A;
            
        }

        String operator+(const char* R)
        {
            String T = R;
            T = *this + T;
            return T;
        }

        String operator+(const char R)
        {
            String T = R;
            T = *this + T;
            return T;
        }

        String operator+(const int R)
        {
            String T = R;
            T = *this + T;
            return T;
        }

        String operator+=(const String &T)
        {
            return *this = *this+T;
        }

        String operator+=(const char *T)
        {
            return *this = *this+T;
        }

        String operator+=(const char T)
        {
            return *this = *this+T;
        }

        String operator+=(const int T)
        {
            return *this = *this+T;
        }

        String operator -(const String &R)
        {
            /* char *p = new char[strlen(this->getString())+1];
            strcpy(p,this->getString()); */
            char *p = strdup(this->getString());
            char *m = R.getString();
            char *q = nullptr;
            while((q=strstr(p,m))!=nullptr )
            {
                char *z = q + strlen(m);
                strcpy(q,z);
            }

            String temp = p;
            delete[]p;

            return temp;
            
        }

        String operator -(const char* R)
        {
            String T = R;
            return T = *this - T;    
        }

        String operator -(const char R)
        {
            String T = R;
            return T = *this - T;    
        }

        String operator -(const int R)
        {
            String T = R;
            return T = *this - T;    
        }

        String operator-=(const String &R)
        {
            return *this = *this - R;
        }
        
        String operator-=(const char *R)
        {
            return *this = *this - R;
        }

        String operator-=(const char R)
        {
            return *this = *this - R;
        }

        String operator-=(const int R)
        {
            return *this = *this - R;
        }

        int operator==(const String &R)
        {
            return strcmp(this->getString() , R.getString()) == 0;
        }

        int operator==(const char *R)
        {
            String T = R;
            return *this==T;
            //return strcmp(this->getString() , T.getString()) == 0;
            
        }

        int operator==(const char R)
        {
            String T = R;
            return *this==T;
        }

        int operator==(const int R)
        {
            String T = R;
            return *this==T;
        }

        int operator !=(const String &R)
        {
            return !(*this==R);
        }

        int operator !=(const char *R)
        {
            return !(*this==R);
        }

        int operator !=(const char R)
        {
            return !(*this==R);
        }

        int operator !=(const int R)
        {
            return !(*this==R);
        }

        int operator>(const String &R)
        {
            return strcmp(this->getString() , R.getString()) > 0;
        }

        int operator>(const char *R)
        {
            String T = R;
            return strcmp(this->getString() , T.getString()) > 0;
        }

        int operator>(const char R)
        {
            String T = R;
            return strcmp(this->getString() , T.getString()) > 0;
        }

        int operator>(const int R)
        {
            String T = R;
            return strcmp(this->getString() , T.getString()) > 0;
        }

        int operator>=(const String &R)
        {
            return *this > R || *this == R;
        }

        int operator>=(const char *R)
        {
            return *this > R || *this == R;
        }

        int operator>=(const char R)
        {
            return *this > R || *this == R;
        }

        int operator>=(const int R)
        {
            return *this > R || *this == R;
        }

        int operator<=(const String &R)
        {
            return !(*this > R);
        }

        int operator<=(const char *R)
        {
            return !(*this > R);
        }

        int operator<=(const char R)
        {
            return !(*this > R);
        }

        int operator<=(const int R)
        {
            return !(*this > R);
        }

        char &operator[](const int index)
        {
            if(index>=0&&index<strlen(this->getString()))
                cout << "error ";
            else
                return *(this->getString()+index); // return this->getString()[index];
        }

};

/* void display(String* a)
{
    for(int i=0; a[0][i]!='\0';i++)
        cout << endl << a[0][i];

}
*/

void display(String* a , int count)
{
    for(int i=0; i<count;i++)
        cout << endl << *a++;
} 

void search(String *a , int count , String B)
{
    int i=0;
    for(i=0; i<count && *a!=B; i++,a++);
    if(i==count)
        cout << endl << "Not found..." << endl;
    else
        cout << endl << "found found found..." << endl;
}


void sort(String *a , int count)
{
    for(int i=0; i<count; i++)
        for(int j=i+1; j<count; j++)
            if(a[i]>a[j])
            {
                String temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

void merge(String *a ,int count)
{
    String M;
    for(int i=0;i<count;i++)
        M+=*a++;
        cout << M;
}

void max(String *a,int count)
{
    String max=a[0];
    for(int i=1; i<count; i++)
        if(strcmp(a[i].getString(),max.getString())>0)
            max = a[i];
    cout << "Max string according to ascci table is: " << max.getString() << endl << endl;

}

void min(String *a,int count)
{
    String min = a[0];
    for(int i=0; i<count; i++)
        if(strcmp(a[i].getString(),min.getString())<0)
            min = a[i];
    cout << "Min string according to ascci table is: " << min.getString() << endl << endl;

}

void replace(String &a ,String &b)
{
    String temp = a;
    a = b;
    b = temp;
}


int main()
{

    String arr[100];
    int count =0;

    String S = "";

    cout << endl << "plese enter words or <quit> to end.. : ";
    cin >> S;

    while(S!="quit" && count < 100)
    {
        arr[count++] = S;
        cout << endl << "plese enter words or <quit> to end.. : ";
        cin >> S;
    }
    cout << endl << "Merge:-" << endl << endl;
    merge(arr,count);

    cout << endl << "Sort and Display:-"<< endl;
    sort(arr,count);
    display(arr,count);

    cout << endl << "Search:- "  << endl;
    search(arr,count,"hello");
    cout << endl;
   
    max(arr,count);

    min(arr,count);

    String F = "Obada";
    String SA = "Dashuon";
    cout << "Before the switch :- " << endl;
    cout << "----------------------------------" << endl;
    cout  << "F= " << F.getString() << endl << "SA = " << SA.getString() << endl << endl;
    replace(F,SA);
    cout << "After the switch :- " << endl;
    cout << "----------------------------------" << endl;
    cout  << "F= " << F.getString() << endl << "SA = " << SA.getString() << endl;  

  


   /*  String A= "";
    for(int i=0; i<count; i++)
    {
        A+= arr[i] + " ";
    }

    cout << endl << A;
 */

    return 0;
}

/* int main()
{
    String A = 67;
    String B = 'r';
    String C = "aAbyterr Suiii ras dasdrasd";
    String D = "ras";
    String temp = A;

    // operator = 
    A = "hello";
    A = 'r';
    A = 65;
    A = B = temp;

    // operator +
    A = A + B; // calls 5 operators
    A = A + "hell";
    A = A + 'y';
    A = A + 78;

    // operator +=
    A+= B;
    A+= "dooo";
    B+= 'h';
    temp+= 80;

    // operator -
    C = C - D;
    C = C - "Sui";
    C = C - 'i';
    C = C - 65;

    // operator -=
    A-= B;
    A-= "dooo";
    B-= 'h';
    temp-= 80;

    String SS = "Obada";
    String MM = "Obada";
    if(SS==MM)
        cout << "Are equal " << endl;
    else if(SS!=MM)
        cout << "Are not equal " << endl; 
    else if(SS>MM)
        cout << "SS > MM " << endl;
    

    cout << "A : " << A << "B : " << B << "temp : " << temp << "C : " << C <<  endl;






    cout << endl << A << B;
    cin >> A >> B;
    cout << A << B << endl;

    cin >> temp;
    cin >> A;
 
    

    return 0;
} */