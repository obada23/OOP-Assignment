#include <iostream>
using namespace std;
class Shape
{
    private:
        string name;
        int location[3];
    public:
        virtual float getArea() const = 0;
        virtual float getSurfaceArea() const =0;
        virtual float getVolume() const = 0;
        virtual const char* isA() const = 0;
        Shape()
        {
            this->name = "\0";
            for(int i=0; i<3; i++)
            {
                this->location[i] = 0;
            }
        }

        Shape(int loc[3])
        {
            for(int i=0; i<3; i++)
            {
                this->location[i] = loc[i];
            }
        }

        Shape(int loc[3],string n)
        {
            this->name = n;
            for(int i=0; i<3; i++)
            {
                this->location[i] = loc[i];
            }
        }

        virtual void print() const 
        {
            cout << "Name is " << isA() << endl;
            cout << "location is (";
            for(int i=0; i<3; i++)
            {
                if(i<2)
                cout << this->location[i] << ",";
                else
                cout << this->location[i] << ")";
            }
            cout << endl;
            cout << "Area = " << this->getArea() << endl;
            cout << "Surface Area = " << this->getSurfaceArea() << endl;
            cout << "Volume = " << this->getVolume() << endl;
            cout << "------------------------------------" << endl;
        }
        virtual void read()
        {
            this->getArea();
            this->getSurfaceArea();
            this->getVolume();
            cout << "------------------------------------" << endl;
        }
        
};

 class Cube : public Shape
 {
 private:
    float side;
    int location[3];

 public:
    Cube() : Shape()
    {
        
        this->side = 0;
    }
    Cube(int loc[3]) : Shape(loc)
    {
        this->side = 0; 
    }
    Cube(int loc[3],float s) : Shape(loc, "Cube")
    {
        this->side = s;
    }

    float getArea() const
    {
        return this->side*this->side;
    }
    float getSurfaceArea() const
    {
        return 6*this->side*this->side;   
    }
    float getVolume() const
    {
        return this->side*this->side*this->side;
        
    }
    const char* isA() const
    {
        return "Cube";
    }

    void print() const
    {
        Shape::print();
    }
    virtual void read()
    {
        cout << "inside Read : " << this->isA() << endl;
        float s;
        cout << "Enter a side : "; 
        cin >> s;
        this->setSide(s);
        Shape::read();
    } 

    void setSide(float s)
    {
        this->side = s;
    }

 };

 class Cone : public Shape
 {
 private:
    float h,r,l;
    int location[3];

 public:
    Cone() : Shape()
    {
        this->h = this->r = this->l = 0;
    }

    Cone(int loc[3]) : Shape(loc)
    {
        this->h = this->r = this->l = 0;
    }

    Cone(int loc[3],float heig,float rad,float len) : Shape(loc, "Cone")
    {
        this->h = heig;
        this->r = rad;
        this->l = len;
    }

    float getArea() const
    {
        return 3.14*pow(this->r,2);
        
    }
    float getSurfaceArea() const
    {
        return sqrt(pow(this->r,2)+pow(this->h,2));
       
    }
    float getVolume() const
    {
        return 1.0/3*3.14*pow(this->r,2)*this->h;
    }
    const char* isA() const
    {
        return "Cone";
    }

    void print() const
    {
        Shape::print();
    }
    virtual void read()
    {
        cout << "inside Read : " << this->isA() << endl;
        float len,heig,rad;
        cout << "Enter a length , raduis and height : "; 
        cin >> len >> rad >> heig;
        this->setCone(len , rad , heig);
        Shape::read();
    } 

    void setCone(float len , float rad , float heig)
    {
        this->l = len;
        this->r = rad;
        this->h = heig;
    }
};

class Cuboid : public Shape
 {
 private:
    float h,w,l;
    int location[3];

 public:
    Cuboid() : Shape()
    {
        this->h = this->w = this->l = 0;
    }

    Cuboid(int loc[3]) : Shape(loc)
    {
        this->h = this->w = this->l = 0;
    }

    Cuboid(int loc[3],float heig,float wid,float len) : Shape(loc, "Cone")
    {
        this->h = heig;
        this->w = wid;
        this->l = len;
    }

    float getArea() const
    {
        return this->l * this->w;   
    }
    float getSurfaceArea() const
    {
        return 2 * (this->l * this->w + this->l * this->h + this->w * this->h);
    }
    float getVolume() const
    {
        return this->l * this->h * this->w;
    }
    const char* isA() const
    {
        return "Cuboid";
    }

    void print() const
    {
        Shape::print();
    }
    virtual void read()
    {
        cout << "inside Read : " << this->isA() << endl;
        float len,heig,wid;
        cout << "Enter a length , width and height : "; 
        cin >> len >> wid >> heig;
        this->setCube(len , wid , heig);
        Shape::read();
    } 

    void setCube(float len , float wid , float heig)
    {
        this->l = len;
        this->w = wid;
        this->h = heig;
    }
};

class Pyramid : public Shape
 {
 private:
    float bArea,h;
    int location[3];

 public:
    Pyramid() : Shape()
    {
        this->h = this->bArea = 0;
    }

    Pyramid(int loc[3]) : Shape(loc)
    {
        this->h = this->bArea = 0;
    }

    Pyramid(int loc[3],float heig,float bA) : Shape(loc, "Pyramid")
    {
        this->h = heig;
        this->bArea = bA;
    }

    float getArea() const
    {
        return this->bArea;
    }
    float getSurfaceArea() const
    {
        float slantHeight = sqrt(pow(this->h, 2) + (this->bArea / (4 * 3.14)) * (this->bArea / (4 * 3.14)));
        return this->bArea + (0.5 * this->bArea * slantHeight);
    }
    float getVolume() const
    {
        return  (1.0 / 3) * this->bArea * this->h;
        
    }
    const char* isA() const
    {
        return "Pyramid";
    }

    void print() const
    {
        Shape::print();
    }
    virtual void read()
    {
        cout << "inside Read : " << this->isA() << endl;
        float heig,barea;
        cout << "Enter a height and base area : "; 
        cin >> heig >> barea;
        this->setPyramid(heig , barea );
        Shape::read();
    } 

    void setPyramid(float heig , float barea)
    {
        this->h = heig;
        this->bArea = barea;
    }

 };

 class RegularTetrahedron : public Shape
 {
 private:
    float edgeLength;
    int location[3];

 public:
    RegularTetrahedron() : Shape()
    {
        this->edgeLength =  0;
    }

    RegularTetrahedron(int loc[3]) : Shape(loc)
    {
        this->edgeLength =  0;
    }

    RegularTetrahedron(int loc[3],float eL) : Shape(loc, "RegularTetrahedron")
    {
        this->edgeLength = eL;
    }

    float getArea() const 
    {
        return (sqrt(3) / 4) * pow(this->edgeLength, 2);
    }

    float getSurfaceArea() const
    {
        return sqrt(3) * pow(this->edgeLength, 2);
    }
    float getVolume() const
    {
        return (pow(this->edgeLength, 3) * sqrt(2)) / 12;
        
    }
    const char* isA() const
    {
        return "RegularTetrahedron";
    }

    void print() const
    {
        Shape::print();
    }
    virtual void read()
    {
        cout << "inside Read : " << this->isA() << endl;
        float eL;
        cout << "Enter a edge length : "; 
        cin >> eL;
        this->setR(eL);
        Shape::read();
    } 

    void setR(float eL)
    {
        this->edgeLength = eL;
    }

 };

 class Sphere : public Shape
 {
 private:
    float r;
    int location[3];

 public:
    Sphere() : Shape()
    {
        this->r =  0;
    }

    Sphere(int loc[3]) : Shape(loc)
    {
        this->r =  0;
    }

    Sphere(int loc[3],float rad) : Shape(loc, "Sphere")
    {
        this->r= rad;
    }

    float getArea() const 
    {
        return 2 * 3.14 * pow(this->r, 2);
    }

    float getSurfaceArea() const
    {
        return 4 * 3.14 * pow(this->r, 2);
    }
    float getVolume() const
    {
        return (4.0 / 3) * 3.14 * pow(this->r, 3);
    }
    const char* isA() const
    {
        return "Sphere";
    }

    void print() const
    {
        Shape::print();
    }
    virtual void read()
    {
        cout << "inside Read : " << this->isA() << endl;
        float rad;
        cout << "Enter a radius : "; 
        cin >> rad;
        this->setRad(rad);
        Shape::read();
    } 

    void setRad(float rad)
    {
        this->r = rad;
    }
};

class Cylinder : public Shape
 {
 private:
    float r,h;
    int location[3];

 public:
    Cylinder() : Shape()
    {
        this->r = 0;
        this->h = 0;
    }

    Cylinder(int loc[3]) :Shape(loc)
    {
        this->r =  0;
        this->h = 0;
    }

    Cylinder(int loc[3],float rad,float height) : Shape(loc, "Cylinder")
    {
        this->r= rad;
        this->h = height;
    }

    float getArea() const 
    {
        return 2 * 3.14 * this->r * this->h;
    }

    float getSurfaceArea() const
    {
        return 2 * 3.14 * this->r * (this->r + this->h);
    }
    float getVolume() const
    {
        return 3.14 * pow(this->r, 2) * this->h;
    }
    const char* isA() const
    {
        return "Cylinder";
    }

    void print() const
    {
        Shape::print();
    }
    virtual void read()
    {
        cout << "inside Read : " << this->isA() << endl;
        float rad, height;
        cout << "Enter a radius and height : "; 
        cin >> rad >> height;
        this->setCy(rad,height);
        Shape::read();
    } 

    void setCy(float rad,float height)
    {
        this->r = rad;
        this->h = height;
    }
};

int main()
{   
    int n;
    string shape;
    int shapeCount = 0;
    Shape **shapes = new Shape*[10];
    do{
        cout << "===================================================================" << endl;
        cout << "Press number 1 if you want to read information for every object." << endl;
        cout << "Press number 2 if you want to print information for every object." << endl;
        cout << "Press number 3 if you want to sort based on the surface area." << endl;
        cout << "Press number 4 if you want to find objects with min and max volume." << endl;
        cout << "Press number 5 if you want to add an object to the array." << endl;
        cout << "Press number 6 if you want to delete an object from an array." << endl;
        cout << "Press number 7 To Exit " << endl; 
        cout << "Choose The Operation From 1-7 : ";
        cin>>n;
        switch(n)
        {
            case 1:{
                cout << "-------------------------------------------------------------------" << endl;
                for(int i=0;i<shapeCount;i++)
                    shapes[i]->read();
                cout << "-------------------------------------------------------------------" << endl;
                cout << endl;
                break;
            }
           
            case 2:{
                cout << "-------------------------------------------------------------------" << endl;
                for(int i=0;i<shapeCount;i++)
                    shapes[i]->print();
                cout << "-------------------------------------------------------------------" << endl;
                cout << endl;
                break;
            }

            case 3:{
                cout << "-------------------------------------------------------------------" << endl;
                for(int i=0;i<shapeCount-1;i++)
                    for(int j=0;j<shapeCount-i-1;j++)
                        if(shapes[j]->getSurfaceArea()>shapes[j+1]->getSurfaceArea())
                        {
                            Shape *temp = shapes[j];
                            shapes[j] = shapes[j+1];
                            shapes[j+1] = temp; 
                        }
                        cout << "Shapes sorted based on surface area" << endl;
                        for(int i=0;i<shapeCount;i++)
                            cout << shapes[i]->getSurfaceArea() << " ";
                        cout << endl;
                cout << "-------------------------------------------------------------------" << endl;
                cout << endl;
                break;
            }
            case 4: {
                cout << "-------------------------------------------------------------------" << endl;
                Shape *max = shapes[0];
                Shape *min = shapes[0];
                for(int i=1;i<shapeCount;i++)
                {
                    if(shapes[i]->getVolume()>max->getVolume())
                    {
                        max = shapes[i];
                    }
                    else if(shapes[i]->getVolume()<min->getVolume())
                    {
                        min = shapes[i];
                    }
                
                }
                cout << " The object with max volume is " << max->isA() << " and his volume is " << max->getVolume() << endl;
                cout << " The object with min volume is " << min->isA() << " and his volume is " << min->getVolume() << endl;
                cout << "-------------------------------------------------------------------" << endl;
                break;
                }
            case 5: {
                cout << "-------------------------------------------------------------------" << endl;
                cout << "Choose a shape to add (Cube, Cone, Cuboid, Pyramid, Tetrahedron, Sphere, Cylinder): ";
                cin >> shape;
                if(shapeCount<10)
                {
                    if(shape == "Cube"||shape == "cube")
                    {
                        int x,y,z;
                        cout << "Enter the dimensions of the cube : ";
                        cin >> x >> y >> z;
                        int loc[3] = {x,y,z};
                        shapes[shapeCount] = new Cube(loc);
                        shapeCount++;
                        cout << "Cube added successfully " << endl;
                    }
                    else if(shape == "Cone"||shape == "cone")
                    {
                        int x,y,z;
                        cout << "Enter the dimensions of the cone : ";
                        cin >> x >> y >> z;
                        int loc[3] = {x,y,z};
                        shapes[shapeCount] = new Cone(loc);
                        shapeCount++;
                        cout << "Cone added successfully " << endl;
                    }
                    else if(shape == "Pyramid"||shape == "Pyramid")
                    {
                        int x,y,z;
                        cout << "Enter the dimensions of the pyramid : ";
                        cin >> x >> y >> z;
                        int loc[3] = {x,y,z};
                        shapes[shapeCount] = new Pyramid(loc);
                        shapeCount++;
                        cout << "Pyramid added successfully " << endl;
                    }
                    else if(shape == "Cuboid"||shape == "Cuboid")
                    {
                        int x,y,z;
                        cout << "Enter the dimensions of the cuboid : ";
                        cin >> x >> y >> z;
                        int loc[3] = {x,y,z};
                        shapes[shapeCount] = new Cuboid(loc);
                        shapeCount++;
                        cout << "Cuboid added successfully " << endl;
                    }
                    else if(shape == "Tetrahedron"||shape == "tetrahedron")
                    {
                        int x,y,z;
                        cout << "Enter the dimensions of the tetrahedron : ";
                        cin >> x >> y >> z;
                        int loc[3] = {x,y,z};
                        shapes[shapeCount] = new RegularTetrahedron(loc);
                        shapeCount++;
                        cout << "Tetrahedron added successfully " << endl;
                    }

                    else if(shape == "Sphere"||shape == "Sphere")
                    {
                        int x,y,z;
                        cout << "Enter the dimensions of the sphere : ";
                        cin >> x >> y >> z;
                        int loc[3] = {x,y,z};
                        shapes[shapeCount] = new Sphere(loc);
                        shapeCount++;
                        cout << "Sphere added successfully " << endl;
                    }
                    else if(shape == "Cylinder"||shape == "Cylinder")
                    {
                        int x,y,z;
                        cout << "Enter the dimensions of the cylinder : ";
                        cin >> x >> y >> z;
                        int loc[3] = {x,y,z};
                        shapes[shapeCount] = new Cylinder(loc);
                        shapeCount++;
                        cout << "Cylinder added successfully " << endl;
                    }
                    else 
                    {
                        cout << "Invalid shape name. Please try again." << endl;
                    }
                }
                else if(shapeCount==10)
                {
                    cout << "This array is full delete one if you want to add another shape " << endl;
                }
                cout << "-------------------------------------------------------------------" << endl;
                break;
                }
            case 6: {
                cout << "-------------------------------------------------------------------" << endl;
                    int index;
                    cout << "Enter the index of the shape to delete it : ";
                    cin >> index;
                    if(index>=0 && index <shapeCount && shapes[index]!=nullptr)
                    {
                        for(int i = index; i<shapeCount-1; i++)
                            shapes[i] = shapes[i+1];
                        shapes[shapeCount-1] = nullptr;
                        shapeCount--;
                        cout << "Shape at index " << index << " deleted successfully!" << endl;
                    }
                    else
                        cout << "Invalid index or shape does not exisit." << endl;
                
                cout << "-------------------------------------------------------------------" << endl;
                break;
                }   

            case 7: {
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
    } while (n!=7);

    delete []shapes;

    return 0;
}