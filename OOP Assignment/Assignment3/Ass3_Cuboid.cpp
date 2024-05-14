#include <iostream>
using namespace std;
class Cuboid
{
    private:
        int length,width,height;
        int volume;
        int sArea , tSArea , baseArea;
        int perimeter;
        int diagonal;

    
    public:
        Cuboid(const int& l=0,const int& w=0 , const int& h=0)
        {
            this->length = l;
            this->width = w;
            this->height = h;
        }

        void setHeigth(const int& h=0)
        {
            this->height = h;
        }
        
        int getHeigth() const 
        {
            return this->height;
        }

        void setWidth(const int& w=0)
        {
            this->width = w;
        }
        
        int getWidth() const 
        {
            return this->width;
        }

        void setLength(const int& l=0)
        {
            this->length = l;
        }
        
        int getLength() const 
        {
            return this->length;
        }

        void computeVolume()
        {
            this->volume = this->height * this->width * this->length; // this->volume = this->height * 3 
        }
        int getVolume() const
        {
            return this->volume;
        }

        void computeSArea()
        {
            this->sArea = 2*this->height * (this->length + this->width);
        }
        int getSArea() const 
        {
            return this->sArea;
        }

        void computePerimeter()
        {
            this->perimeter = 4*(this->width + this->height + this->length);
        }

        int getPerimeter() const 
        {
            return this->perimeter;
        }

        void computeDiagonal()
        {
            this->diagonal = sqrt(pow(this->width,2) + pow(this->height,2) + pow(this->length,2));
        }

        int getDiagonal() const
        {
            return this->diagonal;
        }

        void computeTSArea()
        {
            this->tSArea = 2*(this->width*this->length + this->length*this->height + this->height*this->width); 
        }

        int getTSArea() const 
        {
            return this->tSArea;
        }

        void computeBaseArea()
        {
            this->baseArea = this->getVolume()/this->height; 
        }

        int getBaseArea() const 
        {
            return this->baseArea;
        }

        ~Cuboid() {}

        Cuboid(const Cuboid &T)
        {
            this->width = T.width;
            this->height = T.height;
            this->length = T.length;
            this->volume = T.volume;
            this->sArea = T.sArea;
            this->tSArea = T.tSArea;
            this->baseArea = T.baseArea;
            this->perimeter = T.perimeter;
            this->diagonal = T.diagonal;
        }

        bool operator <(const Cuboid& other) const
        {
   	        return volume < other.volume;
        }

        bool operator >(const Cuboid& other) const
        {
   	        return volume > other.volume;
        }


        friend ostream& operator <<(ostream& out,const Cuboid& c)
        {
            out << "The width , length and heigth of the Cuboid is : " << c.getWidth() << " " << c.getLength() << " " <<  c.getHeigth() << endl;
            out << "Have volume : " << c.getVolume();
            out << "Have surface area , total surface area and base area : " << c.getSArea() << " " << c.getTSArea() << " " << c.getBaseArea() << endl;
            out << "The perimete is : " << c.getPerimeter() << endl;
            out << "And the diagonal is :" << c.getDiagonal() << endl;

            return out;
        }

        friend istream& operator >> (istream& in ,  Cuboid& c)
        {
            int h , w, l;
            cout << "Please enter the width , length and height of the Cuboid : ";
            in >> w >> l >> h;
            c.setWidth(w); c.setLength(l); c.setHeigth(h);
            c.computeBaseArea(); c.computeDiagonal(); c.computePerimeter();
            c.computeSArea(); c.computeTSArea(); c.computeVolume();

            return in;
        }

};

struct nodeType
{
    Cuboid vdata;
    nodeType* link;
    nodeType(const Cuboid& c)
    {
        this->vdata = c;
        this->link = nullptr;
    }
};

class LinkedList
{
    private:
        nodeType* head;
        int count;
    
    public:
        LinkedList()
        {
            this->head =  nullptr;
            this->count = 0;
        }

        ~LinkedList()
        {
            nodeType* temp = this->head;
            while(temp!=nullptr)
            {
                this->head = this->head->link;
                delete temp;
                temp = this->head;
            }
            
        }

        void insert(const Cuboid& c)
        {
            nodeType* newNode = new nodeType(c);

            if(this->head == nullptr || c.getVolume() <= head->vdata.getVolume())
            {
                newNode->link = this->head;
                this->head = newNode;
                this->count++;
            }
            else{
                nodeType* cur = head;
                while(cur->link!=nullptr && cur->link->vdata.getVolume() < c.getVolume())
                    cur = cur->link;
                
                nodeType* newNode = new nodeType(c);
                newNode->link = cur->link;
                cur->link = newNode;
                this->count++;
            }
          
        }

        void display()
        {
            if(this->head == nullptr)
                cout << "The list is empty" << endl;
            else{
                nodeType* cur = head;
                cout << "Sorted list of the cuboid volume:- " << endl;
                while(cur!=nullptr)
                {
                    cout << cur->vdata.getVolume() << " ";
                    cur = cur->link;
                }
                cout << endl << endl;
            }
        }

        void search(Cuboid c)
        {
            bool found =0;
            nodeType* cur = head;
            if(this->head == nullptr)
                cout << "The list is empty" << endl;
            else{
                while(cur!=nullptr){
                    if(c.getVolume() == cur->vdata.getVolume())
                        found=1;
                    cur = cur->link;
                }
            }
            if(found==1)
                cout << "Cuboid found " << endl << endl;
            else
                cout << "Cuboid not found " << endl << endl;
        }

        void readCuboids()
        {
            int n,len,wid,heig;
            cout << "Enter the number of Cuboid you wants to insert it : ";
            cin >> n; 
            cout << "----------------------------------------------------------" << endl;
            for(int i=0;i<n;i++)
            {
                cout << "Enter length , width and height : ";
                cin >> len >> wid >> heig;
                Cuboid c(len,wid,heig);
                c.computeVolume();
                insert(c);
            }
            cout << endl;
        }

        float avgVolume()
        {
            float sum=0;
            if(head==nullptr)
                return 0;
            else{
                nodeType* cur = head;
                while(cur!=nullptr){
                    sum += cur->vdata.getVolume();
                    cur = cur->link;
                }
            }

            sum = sum / count;
            cout << "Avg volume of the cuboids is : ";
            return sum;
        }

};

int main()
{
    LinkedList l;
    l.readCuboids();

    l.display();

    int length,width,height;
    cout << "Enter length , width and height and search if it exsist : ";
    cin >> length >> width >> height;
    Cuboid c(length,width,height);
    c.computeVolume();
    l.search(c);

    cout << l.avgVolume() << endl << endl;

    
    return 0;
}