# obj2webgl
This is a tool that converts from an OBJ file to WebGL code.

## Usage
To use the tool, first compile it by running `make`. Next, you can run the
command `./obj2webgl <name>`, which will read an OBJ file from stdin, and write
javascript code to stdout. Since the program does not actually read the file,
you should use cat to read the file and pipe it to obj2webgl. Examples:
```
cat Cube.obj | ./obj2webgl Cube
```

```
cat Cube.obj | ./obj2webgl Cube > cube.js
```

Alternatively, you can run `./make_shapes.sh` to generate a `shapes.js` file
from all the OBJ files in the directory.

The name that comes after `./obj2webgl` is the name of the variable to be used
in the javascript code. This variable will be turned into an object with two
functions: `init()`, and `render(a_Position, a_Normal, a_TexCo)`. Call `init()`
after the WebGL context is setup, and `render()` to render the object. Note that
`a_Normal` and `a_TexCo` are optional. For example, if `Cube` was specified as
the name, the following code would be generated:
```
const Cube = {}
Cube.init = function() {}
Cube.render = function(a_Position, a_Normal, a_TexCo) {}
```

This program was tested with simple OBJ files exported from Blender 2.8. Enjoy!
