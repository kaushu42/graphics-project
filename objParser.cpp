#include "objParser.h"
//This function parses a obj file.
/*PARAMETERS:
  fileName : path of the .obj file to parse
  vertices : a 2d vector of floats which will contain all the vertices
  mappings : a 2d vector of ints which specifies which vertices to join with a triangle
*/
void parseFile(std::string fileName, std::vector<std::vector<float>>& vertices, std::vector<std::vector<int>>& mappings){
  std::ifstream file(fileName);
  std::string header;
  while(file){
    file >> header; //Read the first character of the line
    if(header[0] == 'v' and !isalpha(header[1])){ //If the first character is 'v', read vertex data from it
      std::string x, y, z;
      std::vector<float> temp;
      file >> x >> y >> z;
      temp.push_back(stof(y));
      temp.push_back(stof(x));
      temp.push_back(stof(z));
      vertices.push_back(temp);
    }
    else if(header[0] == 'f'){//If the first letter is 'f', it contains our mapping data
      std::string line;
      int x;
      std::vector<int> temp;
      for (size_t i = 0; i < 3; i++) {
        int a;
        file.ignore(100, ' ');
        file >> x;
        file.ignore(100, '/');
        file >> a;
        file.ignore(100, '/');
        file >> a;
        temp.push_back(x);
      }
      mappings.push_back(temp);
    }
  }
}
// int main(int argc, char const *argv[]){
//   std::vector<std::vector<float>> vertices;
//   std::vector<std::vector<int>> mappings;
//   parseFile("house.obj", vertices, mappings);
//   std::cout << "******VERTICES*********\n" ;
//   for(auto& i: vertices){
//     for(auto&j :i)
//       std::cout << j << ' ';
//     std::cout << std::endl;
//   }
//   std::cout << "*****************MAPPINGS*****************\n" ;
//   for(auto& i: mappings){
//     for(auto&j :i)
//       std::cout << j << ' ';
//     std::cout << std::endl;
//   }
//   std::cout << "****************" << '\n';
//   for(auto&f: mappings){
//     auto& v1 = vertices[f[0] - 1];
//     auto& v2 = vertices[f[1] - 1];
//     auto& v3 = vertices[f[2] - 1];
//     std::cout << v1[0] << ',' << v1[1] << ',' << v1[2] << '\n';
//     std::cout << v2[0] << ',' << v2[1] << ',' << v2[2] << '\n';
//     std::cout << v3[0] << ',' << v3[1] << ',' << v3[2] << '\n';
//     std::cout << "-----" << '\n';
//   }
//   return 0;
// }
