#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>

class Collection {
public:
  Collection();
  Collection(int size);
  virtual int getSize() const;
  virtual int getCapacity() const;
  virtual void add(double item);
  virtual double get(int ndx) const;
  virtual int find(double needle) const;
  virtual double getFront() const;
  virtual double getEnd() const;
  virtual void removeFront();
  virtual void removeEnd();
  virtual void remove(double item);
  virtual double& operator[](int ndx);

  virtual Collection& operator-(int count);
  virtual Collection& operator+(double item);
  virtual Collection& operator+(const Collection& other);
  virtual Collection& operator<<(double item);
  friend std::ostream& operator<<(std::ostream& out, const Collection& other);

  ~Collection();
  Collection(const Collection& origObj);
  Collection& operator=(const Collection& objToCopy);

protected:
    double* dbl;
    int capacity;
    int size;
};
#endif
