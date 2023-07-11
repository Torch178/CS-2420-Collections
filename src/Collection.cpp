#include "../inc/Collection.h"


//Default and Parameter Constructors
Collection::Collection(){
    this->capacity = 8;
    this->size = 0;
    this->dbl = new double[capacity];
}

Collection::Collection(int size){
    this->capacity = size;
    this->size = 0;
    this->dbl = new double[capacity];
}

//------------------------------------------------------------------------
//Getters, find, and Add functions
int Collection::getSize() const{
   return size;
}

int Collection::getCapacity() const{
   return capacity;
}

double Collection::get(int ndx) const{
    if (ndx > size) { throw  std::out_of_range("Error, Collection is empty"); }
   return dbl[ndx];
}

double Collection::getFront() const{
    if (size == 0) { throw  std::out_of_range("Error, Collection is empty"); }
    else {
        return dbl[0];
    }
}

double Collection::getEnd() const{
    if (size == 0) { throw  std::out_of_range("Error, Collection is empty"); }
    else {
        return dbl[size-1];
    }
}

int Collection::find(double needle) const{
    for (int i = 0; i < size; i++) {
        if (dbl[i] == needle) { return i; }
    }
   return -1;
}

void Collection::add(double item){
    size++;
    //check to see if the array capacity needs to be expanded, use tempArray to store contents of the dbl array while memory is being reallocated.
    if (size > capacity) {
        double* tempArray;
        capacity = 2 * capacity;
         tempArray = new double[capacity];
        for (int i = 0; i < size-1; i++) {
            tempArray[i] = this->dbl[i];
        }
        //Uses overloaded = operator to copy over data
        dbl = tempArray;
    }
    //adding instruction
    dbl[size - 1] = item;
}

//------------------------------------------------------------------------
//remove Functions
void Collection::removeFront(){
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            this->dbl[i] = this->dbl[i + 1];
        }
        size--;
    }
}

void Collection::removeEnd(){
    if (size > 0) {
        size--;
    }

}

void Collection::remove(double item){
    for (int i = 0; i < size; i++) {
        if (dbl[i] == item) {
            size--;
            for (int j = i; j < size; j++) {
                this->dbl[j] = this->dbl[j + 1];
            }
            break;
        }
    }
}

//------------------------------------------------------------------------
//Overloaded Operators
double& Collection::operator[](int ndx){
    if (ndx > size-1) { throw  std::out_of_range("Error, Collection is empty"); }
   return dbl[ndx];
}

Collection& Collection::operator-(int count){
    if (count >= size) {
        this->size = 0;
    }
    else {
        size = size - count;
    }
   return *this;
}

Collection& Collection::operator+(double item){
    this->add(item);
   return *this;
}

Collection& Collection::operator+(const Collection& other){
    for (int i = 0; i < other.size; i++) {
        this->add(other.dbl[i]);
    }
   return *this;
}

Collection& Collection::operator<<(double item){
    this->add(item);
   return *this;
}

std::ostream& operator<<(std::ostream& out, const Collection& other){
    for (int i = 0; i < other.size; i++) {
        if (i == other.size - 1) {
            out << other.dbl[i] << std::endl;
        }
        else {
            out << other.dbl[i] << " ";
        }
    }
   return out;
}

//------------------------------------------------------------------------
//Destructor, Copy Constructor, Additional Overloaded Operators for Class Objects
Collection::~Collection() {
    delete [] dbl;
}

Collection::Collection(const Collection& origObj) {
    this->size = origObj.size;
    this->capacity = origObj.capacity;
    delete[] this->dbl;
    this->dbl = new double[capacity];
    for (int i = 0; i < size; i++) {
        this->dbl[i] = origObj.dbl[i];
    }
}

Collection& Collection::operator=(const Collection& objToCopy) {
    if (this != &objToCopy) {
        delete this->dbl;
        this->size = objToCopy.size;
        this->capacity = objToCopy.capacity;
        this->dbl = new double[capacity];
        for (int i = 0; i < this->size; i++) {
            this->dbl[i] = objToCopy.dbl[i];
        }
    }

    return *this;

}
