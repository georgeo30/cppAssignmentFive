default:
	g++ -I /Eigen -std=c++11 values.hpp pca.cpp -o my_program
	./my_program