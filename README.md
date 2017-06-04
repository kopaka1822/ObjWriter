# Simple Obj Writer
Example:
```c++
#include "ObjWriter.hpp"

int main()
{
    std::fstream file;
	file.open("test.obj", std::ios::out);
	objwriter::ObjWriter w(file);
	// make a cube
	w.comment("my first obj");
	w.vertex(1.0 , -1.0, -1.0);
	w.vertex(1.0 , -1.0, 1.0 );
	w.vertex(-1.0, -1.0, 1.0 );
	w.vertex(-1.0, -1.0, -1.0);
	w.vertex(1.0 , 1.0 , -1.0);
	w.vertex(1.0 , 1.0 , 1.0 );
	w.vertex(-1.0, 1.0 , 1.0 );
	w.vertex(-1.0, 1.0 , -1.0);

	w.face(2, 3, 4);
	w.face(8, 7, 6);
	w.face(1, 5, 6);
	w.face(2, 6, 7);
	w.face(7, 8, 4);
	w.face(1, 4, 8);
	w.face(1, 2, 4);
	w.face(5, 8, 6);
	w.face(2, 1, 6);
	w.face(3, 2, 7);
	w.face(3, 7, 4);
	w.face(5, 1, 8);
	
	file.close();
	return 0;
}
```

Define custom output/input:
```c++
// template<class TVertex, class TIndex, class TString, class TStream>
// class ObjWriterT
// TVertex = vertex type (default = float)
// TIndex = vertex type (default = int)
// TString = vertex type (default = std::string)
// TStream = vertex type (default = std::fstream)
// this will print directly to cout
objwriter::ObjWriterT<float,int,std::string,decltype(std::cout)> coutPrinter(std::cout);
```
Limiations:
* TVertex, TIndex and TString must support the "<< operator" of TSTREAM (stream << vertex << std::endl)
* TStream must support "<< operator" with std::endl