
// #include <iostream>
// #include <sstream>
// #include "Graph.h"

// using namespace std;

// int main(int argc, char *argv[]){
//   graph g;
//   std::vector<graph::vertex_label> bfs_rpt;
//   std::vector<graph::vertex_label> extract_path_rpt;
//   std::vector<int> path;

//   if(argc != 5) {
//     std::cout << "usage:  ./cpath <filename> <source-vertex> <dest-vertex> <budget>\n";
//     return 0;
//   }
//   else {
//     if(!g.read_file(argv[1])){
//       std::cout << "could not open file '" << argv[1] << "'\n";
//       return 0;
//     }
//   }

//   // std::cout << "\nADJACENCY-LIST REPRESENTATION:\n\n";
//   // g.display();
//   // std::cout << "\nEND ADJACENCY LIST:\n\n";

//   int argv4 = stoi(argv[3]);
//   if(!g.bfs(argv[2], bfs_rpt)){
//     std::cout << "bfs failed -- bad source vertex name '" <<
//       argv[2] << "'\n";
//     return 0;
//   }
//   else {
//     std::cout << "\nBFS REPORT:\n\n";
//     g.disp_report(bfs_rpt, true);
//     std::cout << "\nEND BFS REPORT\n\n";
//   }
//   if(!g.extract_path(extract_path_rpt, argv4, path)){
//     std::cout << "extract path failed -- bad dest vertex name '" <<
//       argv[3] << "'\n";
//     return 0;
//   }
//   else{
//     std::cout << "\nEXTRACT PATH REPORT:\n\n";
//     g.disp_report(extract_path_rpt, true);
//     std::cout << "\nEND EXTRACT PATH REPORT\n\n";
//   }

//   return 0;
// }

#include <iostream>
#include <sstream>
#include "Graph.h"

using namespace std;

int main(int argc, char *argv[]){
  graph g;
  std::vector<graph::vertex_label> bfs_rpt;
  std::vector<graph::vertex_label> extract_path_rpt;
  std::vector<int> path;

  if(argc != 5) {
    std::cout << "usage:  ./cpath <filename> <source-vertex> <dest-vertex> <budget>\n";
    return 0;
  }
  else {
    if(!g.read_file(argv[1])){
      std::cout << "could not open file '" << argv[1] << "'\n";
      return 0;
    }
  }

  std::cout << "\nADJACENCY-LIST REPRESENTATION:\n\n";
  g.display();
  std::cout << "\nEND ADJACENCY LIST:\n\n";

  int argv4 = stoi(argv[3]);
  if(!g.bfs(argv[2], bfs_rpt)){
    std::cout << "bfs failed -- bad source vertex name '" <<
      argv[2] << "'\n";
    return 0;
  }
  else {
    std::cout << "\nBFS REPORT:\n\n";
    g.disp_report(bfs_rpt, true);
    std::cout << "\nEND BFS REPORT\n\n";
  }
  if(!g.extract_path(bfs_rpt, argv4, path)){
    std::cout << "extract path failed -- bad dest vertex name '" <<
      argv[3] << "'\n";
    return 0;
  }
  else{
    std::cout << "\nEXTRACT PATH REPORT:\n\n";
    g.disp_report(extract_path_rpt, true);
    std::cout << "\nEND EXTRACT PATH REPORT\n\n";
  }

  return 0;
}