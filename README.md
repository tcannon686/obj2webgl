# obj2webgl
This is a tool that converts from an OBJ file to WebGL code.

## Usage
To use the tool, first compile it by running the following commands:
```
git submodule update --init
make

```
This will output a program called `obj2webgl`. Run the program with this
command: `./obj2webgl -o OUTFILE INFILE...`, where `OUTFILE` is the name of the
file you want to write to, and INFILE is a list of OBJ input files. You don't
need to specify OUTFILE if you want to write directly to STDOUT. Run
`./obj2webgl` with no arguments for more details, and a full list of options.

## Prebuilt OBJs
There is a set of OBJ files in the `objs` folder. You can use these files
without downloading the program by downloading the `js/shapes.js` file, which
will be generated from these OBJs by running the command. To use these files,
add them to your webpage, then call `Shape.init()`, where `Shape` is the name of
a specific shape from the objs directory (for example `Cube.init()`). Then, call
`shape.render(a_Position, a_Normal, a_TexCo)` where you want to render the
shape. Note that `a_Normal` and `a_TexCo` are optional. Pass in `undefined` to
these values if you don't want to use them.

## Materials
There is currently no support for loading materials.

## Testing
This program was tested on Arch Linux, and CentOS, using a few simple OBJ models
exported with Blender 2.9.
