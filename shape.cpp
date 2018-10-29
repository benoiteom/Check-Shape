#include "shape.hpp"

//Benoit Ortalo-Magne
/*
Wrote constructor and getName function for Shape, then implemented its subclasses and their functions
getArea,  getVolume, operator +, and operator -.
*/
//Base class
//Please implement Shape's member functions
//constructor, getName()
//
//Base class' constructor should be called in derived classes'
//constructor to initizlize Shape's private variable 
Shape::Shape(string name){		//Shape constructor
  name_ = name;
}
string Shape::getName(){		//Initialize getName()
  return name_;
}

//Rectangle
//Please implement the member functions of Rectangle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here
Rectangle::Rectangle(double width, double length): Shape("Rectangle") {		//Constructor
  width_ = width;		//Initialize variables
  length_ = length;
}
double Rectangle::getArea()const{	//Initialize getArea
  return length_ * width_;
}
double Rectangle::getVolume()const{	//Initialize getVolume
  return 0;
}
Rectangle Rectangle::operator + (const Rectangle& rec){		//Initialize Rectangle operator +
double suml = length_ + rec.getLength();	//add lengths
double sumw = width_ + rec.getWidth();		//add widths
return Rectangle(sumw, suml);
}
Rectangle Rectangle::operator - (const Rectangle& rec){		//Initalize Rectangle operator -
double diffl = length_ - rec.getLength();	//subtract lengths
double diffw = width_ - rec.getWidth();		//subtract widths
if (diffl < 0)		//if lengths are negative, pass 0 instead
diffl = 0;
if (diffw < 0)		//if widths are negative, pass 0 instead
diffw = 0;
return Rectangle(diffw, diffl);
}

double Rectangle::getWidth()const{return width_;}
double Rectangle::getLength()const{return length_;}


//Circle
//Please implement the member functions of Circle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

Circle::Circle(double radius): Shape("Circle"){		//Constructor for circle
  radius_ = radius;
}
double Circle::getArea()const{		//Initalize getArea
  return radius_ * radius_ * M_PI;
}
double Circle::getVolume()const{	//Initalize getVolume
  return 0;
}
Circle Circle::operator + (const Circle& cir){		//Initalize Circle operator +
double sumr = radius_ + cir.getRadius();
return Circle(sumr);
}
Circle Circle::operator - (const Circle& cir){		//Initialize Circle operator -
double diffr = radius_ - cir.getRadius();
if (diffr < 0)
diffr = 0;
return Circle(diffr);
}

double Circle::getRadius()const{return radius_;}

//Sphere
//Please implement the member functions of Sphere:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

Sphere::Sphere(double radius): Shape("Sphere"){		//Sphere constructor
  radius_ = radius;
}
double Sphere::getArea()const{		//Initalize sphere getArea()
  return 4 * radius_ * radius_ * M_PI;
}
double Sphere::getVolume()const{	//Initialize sphere getVolume()
  return (4.0/3.0) * radius_ * radius_ * radius_ * M_PI;
}

Sphere Sphere::operator + (const Sphere& sph){	//Initialize Sphere operator +
double sumr = radius_ + sph.getRadius();
return Sphere(sumr);
}
Sphere Sphere::operator - (const Sphere& sph){	//Initialize Sphere operator +
double diffr = radius_ - sph.getRadius();
if (diffr < 0)
diffr = 0;
return Sphere(diffr);
}

double Sphere::getRadius()const{return radius_;}

//Rectprism
//Please implement the member functions of RectPrism:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

RectPrism::RectPrism(double width, double length, double height): Shape("RectPrism"){		//RectPrism constructor
  width_ = width;
  length_ = length;
  height_ = height;
}
double RectPrism::getArea()const{	//Initailize getArea()
  return 2 * (width_ * length_ + length_ * height_ + height_ * width_);
}
double RectPrism::getVolume()const{	//Initialize getVolume()
  return length_ * width_ * height_;
}

RectPrism RectPrism::operator + (const RectPrism& rectp){	//Initialize RectPrism operator +
double suml = length_ + rectp.getLength();
double sumw = width_ + rectp.getWidth();
double sumh = height_ + rectp.getHeight();
return RectPrism(sumw, suml, sumh);
}
RectPrism RectPrism::operator - (const RectPrism& rectp){	//Initialize RectPrism operator -
double suml = length_ - rectp.getLength();
double sumw = width_ - rectp.getWidth();
double sumh = height_ - rectp.getHeight();
if (suml < 0)
suml = 0;
if (sumw < 0)
sumw = 0;
if (sumh < 0)
sumh = 0;
return RectPrism(sumw, suml, sumh);
}

double RectPrism::getWidth()const{return width_;}
double RectPrism::getHeight()const{return height_;}
double RectPrism::getLength()const{return length_;}


 
// Read shapes from test.txt and initialize the objects
// Return a vector of pointers that points to the objects 
vector<Shape*> CreateShapes(char* file_name){
	//Initialize
string name, strr = "Rectangle", strc = "Circle", strrp = "RectPrism", strs = "Sphere";
int numShapes, i;
vector<Shape*> values;
	//open file to read
ifstream ifs ("test1.txt", std::ifstream::in);
ifs >> numShapes;

while (numShapes > 0) {		//while still have shapes to read
ifs >> name;			//input the name string
if (strr.compare(name) == 0){		//if string is "Rectangle"
  double width, length;
  ifs >> width >> length;		//read width and length
  Shape* shape_ptr = new Rectangle(width, length);
  values.push_back (shape_ptr);		//pointer to shape vecotr
}
if (strc.compare(name) == 0){		//if strinnng is "Circle"
  double radius;		//set pointer to a circle with given radius
  ifs >> radius;
  Shape* shape_ptr = new Circle(radius);
  values.push_back (shape_ptr);
}
if (strrp.compare(name) == 0){		//if string is "RectPrism"
  double width, length, height;		//set pointer to a rectangular prism with given width, length, height
  ifs >> width >> length >> height;
  Shape* shape_ptr = new RectPrism(width, length, height);
  values.push_back (shape_ptr);
}
if (strs.compare(name) == 0){		//if string is "Sphere"
  double radius;			//set pointer to a sphere with given radius
  ifs >> radius;
  Shape* shape_ptr = new Sphere(radius);
  values.push_back (shape_ptr);
}
numShapes = numShapes - 1;		//decrement counter
}
return values;
}
//call getArea() of each object 
// return the max area
double MaxArea(vector<Shape*> shapes){
	double max_area = 0, x;
	int i;
	//Initializing
for (i = 0; i < shapes.size(); i++) {		//run through shapes vector
  x = shapes[i]->getArea();		//find each area value
  if (x > max_area)
    max_area = x;		//set max of area to max_area
}
	return max_area;
}


// call getVolume() of each object 
// return the max volume
double MaxVolume(vector<Shape*> shapes){
	double max_volume = 0, x;
	int i;
	//Initializing
for (i = 0; i < shapes.size(); i++) {		//iterate through shapes vector
  x = shapes[i]->getVolume();
  if (x > max_volume)			//find max volume
    max_volume = x;
}
	return max_volume;
}

