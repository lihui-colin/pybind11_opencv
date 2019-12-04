import ReturnValue as rv
import numpy as np

obj = rv.get_data10(10)
print(obj.x, obj.y, obj.w, obj.h)
print(obj) 

func1 = rv.get_data(10)
print(func1) 

obj = rv.get_data2(10)
print(obj)
print(obj.x, obj.y, obj.w, obj.h)

# func3 = demo6.get_data3(20)
# print(func3)

# func4 = demo6.get_data4(10)
# print(func4)

# func5 = demo6.get_complex()
# print(func5)

func6 = rv.get_matrix_eigen()
print(func6)

func7 = rv.calc_mat_add(np.array([[1, 2, 3],
                                     [3, 2, 1],
                                     [4, 5, 6]]),
                           np.array([[3, 3, 1],
                                     [6, 4, 6],
                                     [7, 7, 9]]))

print(func7)

func8 = rv.create_mat_3x3([1, 2, 3, 4, 5, 6, 7, 8, 9])
print(func8)