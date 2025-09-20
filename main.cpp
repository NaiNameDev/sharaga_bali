#include <iostream>
#include <vector>
#include <cmath>

#include "matrix.cpp"

int main() {
	sq_matrix main_mat;
	main_mat.init();
	col_matrix col;
	col.init(main_mat.size);

	if (main_mat.size < 2) {
		std::cout << "matrix size need to be higher then 2, sorry mate" << std::endl;
		exit(0);
	}

	std::cout << "\n\nINFO: " <<std::endl;

	//equalation form
	main_mat.mat_equation_print(col);
	std::cout << '\n';

	//matrix form
	std::cout << "main matrix" << std::endl;
	main_mat.mat_print();
	for (int i = 0; i < main_mat.size; i++) {
		std::cout << "matrix mv" << i << std::endl;
		main_mat.replace_col(i, col).mat_print();
	}
	std::cout << '\n';
	
	//delta form
	float d = main_mat.get_delta();
	std::cout << "main delta = " << d << std::endl;
	if (d == 0) {
		std::cout << "delta cant be 0, sorry mate goodbye" << std::endl;
		exit(0);
	}
	for (int i = 0; i < main_mat.size; i++) {
		std::cout << "mv" << i << "-delta = " << main_mat.get_indexed_delta(i, col) << std::endl;
	}

	//answer (EASY YOOOOOO)
	std::cout << "\n\nANSWER: " <<std::endl;
	main_mat.print_vars(col);
	
	exit(0);
}
