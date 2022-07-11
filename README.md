t1_resize_img01:

Create a simple HTTP server application that listens on port 8080 to serves a
specific function: resizing a jpeg image, in the form of base 64 encoded binary input data
to the desired target dimension. The server only needs to serve exactly single API below:

HTTP://[host_address]:8080/resize_image [POST]

Input Payload:
Content-Type: application/json
{

"input_jpeg": "[base 64 encoding of jpeg binary]",
"target_width": [target_width],
"target_height": [target_height]

}

Output Payload:
If success:
HTTP 200
Content-Type: application/json
{
"code": 200,
"message": "success",
"output_jpeg": "[base 64 encoding of output jpeg binary]"
}


If failed:
HTTP 4XX/5XX
Content-Type: application/json
{
"code": 4xx/5xx,
"Message": "[output error description here]"
}

Requirements:
1. Drogon Framework 
    https://drogon.docsforge.com/master/installation/
2. OpenCV 4.xx
3. CMake 3.2.x


Environment
-------------------------------------------------------------------------
$ sudo apt install git
$ sudo apt install gcc
$ sudo apt install g++
$ sudo apt install cmake


jsoncpp
-------------------------------------------------------------------------
$ sudo apt install libjsoncpp-dev

uuid
-------------------------------------------------------------------------
$ sudo apt install uuid-dev

OpenSSL
-------------------------------------------------------------------------
$ sudo apt install openssl
$ sudo apt install libssl-dev

zlib
-------------------------------------------------------------------------
$ sudo apt install zlib1g-dev

Database Environment
-------------------------------------------------------------------------

PostgreSQL
-------------------------------------------------------------------------
$ sudo apt-get install postgresql-all

$ su postgres
# 

Sqlite3
-------------------------------------------------------------------------
$ sudo apt-get install libsqlite3-dev

Drogon Installation
-------------------------------------------------------------------------
Assuming that the above environment and library dependencies are all ready, the installation process is very simple;
Install by source in Linux

-------------------------------------------------------------------------
$cd $WORK_PATH
$ git clone https://github.com/an-tao/drogon
$ cd drogon
$ git submodule update --init
$ mkdir build
$ cd build
$ cmake ..
$ make && sudo make install
-------------------------------------------------------------------------

The default is to compile the debug version. If you want to compile the release version, the cmake command should take the following parameters:
cmake -DCMAKE_BUILD_TYPE=Release .. 

After the installation is complete, the following files will be installed in the system（One can change the installation location with the CMAKE_INSTALL_PREFIX option）:

    The header file of drogon is installed into /usr/local/include/drogon;
    The drogon library file libdrogon.a is installed into /usr/local/lib;
    Drogon's command line tool drogon_ctl is installed into /usr/local/bin;
    The trantor header file is installed into /usr/local/include/trantor;
    The trantor library file libtrantor.a is installed into /usr/local/lib;

Building OpenCV from Source on Linux ( Ubuntu 20.0 LTS )
----------------------------------------------------------------------------------------------------------------------------------
$ sudo apt update

$ wget -O opencv-4.5.5.zip https://github.com/opencv/opencv/archive/4.5.5.zip

$ unzip opencv-4.5.5.zip

$ cd opencv-4.5.5

$ mkdir build

$ cd build
----------------------------------------------------------------------------------------------------------------------------------


Below command is normally used for configuration of OpenCV library build (executed from build folder):
$ cmake ../

OpenCV defaults assume "Release" build type and installation path is "/usr/local". For additional information about CMake options refer to OpenCV C++ compilation guide:
----------------------------------------------------------------------------------------------------------------------------------
$ make

$ sudo make install

----------------------------------------------------------------------------------------------------------------------------------
Create symlink
Since OpenCV4 include file in /usr/local/include/opencv4/opencv2 . 
We create symlink:

$ sudo ln -s /usr/local/include/opencv4/opencv2 /usr/local/include/opencv2 

----------------------------------------------------------------------------------------------------------------------------------
This program is tested under Linux Ubuntu 20 LTS,running on VirtualBox Windows 10 Hosts

