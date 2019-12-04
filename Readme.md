# pybind11_opencv_numpy

An example of pybind11 for cv::Mat <-> np.array

support opencv3  
only test linux
```bash
/project folder
├── build
├── CMakeLists.txt
└── ...

### Compile

```bash
mkdir build
cd build
# configure make with vcpkg toolchain
cmake .. 
# generate the example.so library
make
# move example.so library in example folder
make install
```
### Run
```bash
python3 test.py
```
