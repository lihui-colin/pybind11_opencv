import numpy as np
import AuxoCv as cv
import copy

# 点相加
a = (1, 2)
b = (3, -1)
c = cv.addpt(a, b)
print("{} + {} = {}".format(a, b, c))

# 矩形相加
a = (10, 20, 20, 10)  # lt(10, 20) => rb(30, 30)
b = (5, 5, 20, 20)  # lt(5, 5)   => rb(25, 25)
c = cv.addrect(a, b)  # lt(5, 5)   => rb(30, 30) => wh(25, 25)
print("a = \n", a)
print("b = \n", b)
print("c = \n", c)

# 矩阵相加
a = np.random.random((2, 3)).astype(np.float32)
b = np.ones((2, 3)).astype(np.float32)
c = cv.addmat(a, b)
print("a = \n", a)
print("b = \n", b)
print("c = \n", c)

# Read from c++
a = cv.read_image("test.png")
# print('init a: 0x%x' % id(a))
print(a.shape)

cv.imwrite('a.jpg', a)

# eb.show_image(a)  # work

# Check continuous problem from old version
# b = a[:, :, 0]
# eb.show_image(b)  # work no more continous problem
# print('diff b: 0x%x' % id(b))

# c = copy.deepcopy(b)
# eb.show_image(c)  # still works
# print('diff c: 0x%x' % id(c))

# # Proves that it's still the same thing
# d = eb.passthru(a)
# print('same d: 0x%x' % id(b))

# # Make a copy
# e = eb.clone(d)
# print('diff e: 0x%x' % id(e))

# # different allocator
# f = np.zeros(shape=(100, 100), dtype=np.uint8)
# print('\ninit e: 0x%x' % id(f))

# g = eb.passthru(f)
# print('same f: 0x%x' % id(g))
