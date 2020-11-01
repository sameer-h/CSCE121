#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "Pixel.h"

class Image {
  Pixel** image;
  unsigned int width; // columns
  unsigned int height; // rows
  std::string filename;
  
public:
  Image();
  Image(std::string filename);
  Image(unsigned int width, unsigned int height);
  
  // Rule of Three
  ~Image();
  Image(const Image& objCopy); // copy const and assignment
  Image& operator=(const Image& objCopy);
  
  Pixel*& operator[](unsigned int column);
  const Pixel* operator[](unsigned int column) const;
  unsigned int getWidth() const;
  unsigned int getHeight() const;
  
  void makeGreyscale();
  void makeSepia();
  void addColor(Pixel p);
  
  void output(std::string filename);
  
private:
  void load(std::string filename);
  void allocateImage(unsigned int width, unsigned int height);
  void clear();
};

#endif