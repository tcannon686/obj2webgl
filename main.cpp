#include <iostream>
#include "obj_parser.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "Usage: " << argv[0] << " <name-of-object>" << endl;
        cout << "    This program will read an OBJ file and write " << endl
             << "    code to render/generate the object. name-of-object " << endl
             << "    is used to write the objects functions too." << endl
             << "    The OBJ file is read from stdin, and the output " << endl
             << "    is written to stdout. Therefore you will need to " << endl
             << "    use cat to read the actual file, and redirection " << endl
             << "    to write to the file." << endl;
        return -1;
    }
    ObjParser<istream> parser(cin);
    parser.parse();
    parser.writeWebGlCode(cout, argv[1]);
    return 0;
}

