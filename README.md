# About
This repo contains examples of computer vision methods with OpenCV in c++, curated from OpenCV examples from `https://docs.opencv.org/4.x/d9/df8/tutorial_root.html` 

# Installation
Work environment: Ubuntu 22

### Option 1:
- install OpenCV
```
sudo apt install libopencv-dev
```
- check installation
```
dpkg -l libopencv-dev
```

### Option 2 (with contrib modules):
Install minimal prerequisites
```angular2html
sudo apt update && sudo apt install -y cmake g++ wget unzip libcanberra-gtk-module
```
Download and unpack sources
```angular2html
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.x.zip
unzip opencv.zip
unzip opencv_contrib.zip
```
Create build directory and switch into it
```angular2html
mkdir -p build && cd build
```
Configure (with contrib path and non-free modules enabled)
```angular2html
cmake -D OPENCV_EXTRA_MODULES_PATH=../opencv_contrib/modules/optflow\;../opencv_contrib/modules/sfm\;../opencv_contrib/modules/plot\;../opencv_contrib/modules/shape\;../opencv_contrib/modules/stereo\;../opencv_contrib/modules/viz\;../opencv_contrib/modules/ximgproc\;../opencv_contrib/modules/xobjdetect\;../opencv_contrib/modules/xfeatures2d\;../opencv_contrib/modules/xphoto -D OPENCV_ENABLE_NONFREE=ON ../opencv
```
Build
```
cmake --build . -j 5
```
Install
```angular2html
sudo make install
```