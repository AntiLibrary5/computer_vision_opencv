# About
This repo contains examples of computer vision methods mostly with OpenCV in C++, curated from 
- OpenCV examples `https://docs.opencv.org/4.x/d9/df8/tutorial_root.html` and
- the book `Visual SLAM: From Theory to Practice, by X. Gao et al.`

# Pre-requisites
Work environment: Ubuntu 22.0

## OpenCV
### Option 1 (core library):
- install OpenCV
```
sudo apt install libopencv-dev
```
- check installation
```
dpkg -l libopencv-dev
```

### Option 2 (with required contrib modules):
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

## Pangolin
Clone Pangolin along with it's submodules
```angular2html
git clone --recursive https://github.com/stevenlovegrove/Pangolin.git
cd Pangolin
```
Install Homebrew
```angular2html
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
Run these two commands in your terminal to add Homebrew to your PATH:
```angular2html
(echo; echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"') >> /home/varora/.bashrc
```
```angular2html
eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"
```
Install recommended packages for Pangolin
```angular2html
./scripts/install_prerequisites.sh -m brew recommended
```
Install Ninja
```angular2html
sudo apt install ninja-build
```
Configure and build (with Ninja for faster builds)
```angular2html
 cmake -B build -GNinja
```
```angular2html
cmake --build build
```

## Eigen
Install Eigen
```angular2html
sudo apt−get install libeigen3−dev
```