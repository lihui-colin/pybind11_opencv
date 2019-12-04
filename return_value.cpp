#include<iostream>
#include<pybind11/pybind11.h>
#include<pybind11/complex.h>
#include<pybind11/eigen.h>
#include<Eigen/Dense>

namespace py = pybind11;
struct MyData {
    int x;
    int y;
    int w;
    int h;
};

unsigned char* get_data(int length) {
    unsigned char* data = new unsigned char[length];

    for (int i = 0; i < length; i++) {
        data[i] = 255;
    }

    return data;
}

/*
返回自定义类型数据 MyData
*/
MyData* get_data2(int length) {
    MyData* data = new MyData();

    data->x = 10;
    data->y = 20;
    data->w = 30;
    data->h = 30;

    return data;

}

/*
返回python list
*/
py::list get_data3(int len) {
    py::list data;

    for (int i = 0; i < len; i++) {
        data.append<int>(255);
    }

    return data;
}

/*
返回python tuple
*/
py::tuple get_data4(int len) {
    py::tuple data(len);

    for (int i = 0; i < len; i++) {
        data[i] = 128;
    }

    return data;

}


/*
返回 python complex复数
*/
std::complex<float> get_complex() {
    py::list data;
    std::complex<float> item(1, 2);
    return item;

}

/*
https://blog.csdn.net/j_d_c/article/details/78903393
返回 Eigen::Matrix类型, 在python中表示为numpy.ndarray
*/
Eigen::Matrix<unsigned char, 32, 32> get_matrix_eigen() {

    Eigen::Matrix<unsigned char, 32, 32> mat;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            //索引元素
            mat(i, j) = 64;
        }
    }
    return mat;
}


/*
计算矩阵相加
Eigen::Matrix3f
*/
Eigen::Matrix3f calc_mat_add(Eigen::Matrix3f a, Eigen::Matrix3f b) {
    return a + b;
}

/*
创建3x3矩阵
输入： list,  size=9
返回：Eigen::Matrix3f,  python 中numpy.ndarray
*/
Eigen::Matrix3f create_mat_3x3(py::list in) {
    assert(in.size() == 9);
    Eigen::Matrix3f mat;
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat(i, j) = py::cast<float>(in[count]);
            count++;

        }
    }
    return mat;
}



/*
https://blog.csdn.net/u013701860/article/details/86313781
*/

PYBIND11_MODULE(ReturnValue, m) {
    m.doc() = "Simple demo";
    py::class_<MyData>(m, "MyData")
    .def_readwrite("x", &MyData::x)
    .def_readwrite("y", &MyData::y)
    .def_readwrite("w", &MyData::w)
    .def_readwrite("h", &MyData::h);
    m.def("get_data", &get_data, py::return_value_policy::reference);
    m.def("get_data2", &get_data2, py::return_value_policy::reference);
    m.def("get_data3", &get_data3, py::return_value_policy::reference);
    m.def("get_data4", &get_data4, py::return_value_policy::reference);
    m.def("get_complex", &get_complex, py::return_value_policy::reference);
    m.def("get_matrix_eigen", &get_matrix_eigen, py::return_value_policy::reference);
    m.def("calc_mat_add", &calc_mat_add, py::return_value_policy::reference);
    m.def("create_mat_3x3", &create_mat_3x3, py::return_value_policy::reference);
}
