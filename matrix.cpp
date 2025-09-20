class col_matrix {
public:
	std::vector<int> mat;
	int size = 0;
	
	void init(int nsize) {
		size = nsize;

		for (int i = 0; i < size; i++) {
			std::cout << "answer " << i + 1 << " = ";
			int tmp = 0;
			std::cin >> tmp;
			mat.push_back(tmp);
		}
	}
};

class sq_matrix {
public:
	std::vector<std::vector<int>> mat;
	int size = 0;
	
	sq_matrix() {}
	sq_matrix(const sq_matrix& other) {
		mat = other.mat;
		size = other.size;
	}

	void init() {
		std::cout << "enter matrix size: ";
		std::cin >> size;

		for (int i = 0; i < size; i++) {
			mat.push_back({});
			std::cout << "row " << i + 1 << '\n';
			for (int j = 0; j < size; j++) {
				int tmp = 0;
				std::cout << "v" << j << " = ";
				std::cin >> tmp;
				mat[i].push_back(tmp);
			}
		}
	}
	void mat_print() {
		for (int i = 0; i < size; i++) {
			std::cout << "| ";
			for (int j = 0; j < size; j++) {
				std::cout << mat[i][j] << " ";
			}
			std::cout << "|";
			std::cout << '\n';
		}
	}
	void mat_equation_print(col_matrix col) {
		for (int i = 0; i < size; i++) {
			std::cout << "{ ";
			for (int j = 0; j < size; j++) {
				if(mat[i][j] >= 0 && j != 0) std::cout << "+ ";
				std::cout << mat[i][j] << "*" << "v" << i << " ";
			}
			std::cout << "= " << col.mat[i];
			std::cout << '\n';
		}
	}
	sq_matrix replace_col(int index, col_matrix col) {
		sq_matrix ret(*this);

		for (int i = 0; i < size; i++) {
			ret.mat[i][index] = col.mat[i];
		}
		return ret;
	}
	int get_overflow(int x) {
		if (x >= size) return get_overflow(x - size);
		if (x < 0) return get_overflow(x + size);
		return x;
	}
	float get_delta() {
		if (size == 2) return (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);

		float part_one = 0;
		for (int i = 0; i < size; i++) {
			float tmp = 1;
			for (int j = 0; j < size; j++) {
				tmp *= mat[j][get_overflow(j + i)];
			}
			part_one += tmp;
		}
		
		float part_two = 0;
		for (int i = size - 1; i > -1; i--) {
			float tmp = 1;
			for (int j = 0; j < size; j++) {
				tmp *= mat[j][get_overflow(i - j)];
			}
			part_two += tmp;
		}

		return part_one - part_two;
	}
	float get_indexed_delta(int index, col_matrix col) {
		return replace_col(index, col).get_delta();
	}
	void print_vars(col_matrix col) {
		for (int i = 0; i < size; i++) {
			std::cout << "v" << i << " = " << get_indexed_delta(i, col) / get_delta() << std::endl;
		}
	}
};
