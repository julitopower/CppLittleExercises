import numpy as np
import cpp_matrix as cpp

cpp.info()
matrix_double = np.array([[1.0, 2.2, 3.4], [2.3, 2.23, -2.44]], dtype=np.float64)
matrix_int = np.array([[1, 2, 3], [2, 2, 2]])

cpp.array(matrix_double)
cpp.array(matrix_int)
