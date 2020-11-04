#include <vector>
#include <iostream>
#include <fstream>
#include "obj_parser.hpp"

using namespace std;

const char *usage = R"(
    Reads the given Wavefront OBJ files and converts them to JavaScript.
    When -o is not specified, writes to STDOUT.

Options:
    -o FILE    Specify an output file to write to instead of STDOUT.

    Note that all options must come before the list of files.

Summary:
    For each file specified, an object with an init() and render(a_Position,
    a_Normal, a_TexCo) function is created. The name of the object is the base
    name of the file with the file extension stripped away. For example, if the
    input file is Cube.obj, the following code would be generated:

        const Cube = {}
        Cube.init = function() { ... }
        Cube.render = function(a_Position, a_Normal, a_TexCo) { ... }

    Your program should call init() after the WebGL context is created, and
    render() when you want to render the object, specifying a_Position as the
    vertex attribute location of the vertex in the shader.

Examples:
)";

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cout << "Usage: " << argv[0] << " [OPTION]... [FILE].obj..." << endl;
        cout << usage;
        cout << "    " << argv[0] << " objs/Cube.obj" << endl;
        cout << "    " << argv[0] << " -o Cube.js objs/Cube.obj" << endl;
        cout << "    " << argv[0] << " -o shapes.js objs/*" << endl;
        return -1;
    }

    string outpath;
    /* Parse arguments. */
    int index;
    for(index = 1; index < argc; index ++)
    {
        string arg(argv[index]);
        if(arg.rfind("-o", 0) == 0)
        {
            auto split = arg.find("=", 0);
            if(split != string::npos)
                outpath = arg.substr(split + 1, arg.size() - split - 1);
            else
            {
                if(index + 1 < argc)
                {
                    outpath = argv[++ index];
                }
            }
        }
        else
            break;
    }

    ofstream outfile;
    if(outpath.size())
        outfile.open(outpath);

    ostream &out(outpath.size() ? outfile : cout);

    /* Write header. */
    out << "/*" << std::endl
        << " * This code was generated using the obj2webgl tool:" << std::endl
        << " * https://github.com/tcannon686/obj2webgl" << std::endl
        << " */" << std::endl << std::endl;

    /* Read the files. */
    for(int i = index; i < argc; i ++)
    {
        string path(argv[i]);
        /* Figure out a name for it. */
        auto base = path.rfind('/');
        if(base == string::npos)
            base = path.rfind('\\');
        if(base != string::npos)
            base ++;
        else
            base = 0;
        auto extension = path.find('.', base);
        if(extension == string::npos)
            extension = path.size();

        string name(path.substr(base, extension - base));

        /* Open the file. */
        ifstream input(path);
        ObjParser<ifstream> parser(input);
        parser.parse();
        parser.writeWebGlCode(out, name);
    }
    return 0;
}

