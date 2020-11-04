
EXE=obj2webgl

$(EXE) : main.cpp obj_parser.hpp
	$(CXX) main.cpp --std=c++17 -lm -o $@

clean:
	$(RM) *.o $(EXE)

