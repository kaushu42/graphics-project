#ifndef OBJPARSER_H
#define OBJPARSER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//This function parses a obj file.
/*PARAMETERS:
  fileName : path of the .obj file to parse
  vertices : a 2d vector of floats which will contain all the vertices
  mappings : a 2d vector of ints which specifies which vertices to join with a triangle
*/
void parseFile(std::string fileName, std::vector<std::vector<float>>& vertices, std::vector<std::vector<int>>& mappings);
#endif
