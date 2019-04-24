# BarcodeScanner

How to build?
--------
### Windows
1. Install opencv, put `opencv/` to `C:\`
2. add `C:\opencv\build\x64\vc14\bin` to [System Variable Path](https://www.computerhope.com/issues/ch000549.htm)
3. Use `cmake` to create Visual Studio Project
```sh
cd BarcodeScanner
mkdir build
cd build
cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=Release ..
```
4. Compile via `scene_text_recognition.sln`, you will find executable in `build/Release/`


### Linux 
1. Install opencv, refer to [OpenCV Installation in Linux](https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html)
2. Use `cmake` to create Makefile, and `make`
```sh
cd BarcodeScanner
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```