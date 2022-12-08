#include <iostream>
#include <chrono>

#include "Image.h"
#include "Video.h"

using std::cout;
using std::cin;
using std::cerr;
using std::chrono;


int main() {

    // time each individual image and video processing function
    // need control images and videos 

    // how to test?
    // Image
    //      read in image -> end.
    //      blend
    //      blur -> end
    //      .. 
    // Video
    //      Load video -> end
    //      ..

    Image img1 = Image("control_img1.jpeg");
    Image img2 = Image("control_img2.jpeg");

    // test Edge 
    auto start = high_resolution_clock::now();
    Image ED = img1.edge_detect(100, 200);
    auto stop = high_resolution_clock::now();

    auto start = high_resolution_clock::now();
    Image ED = img1.gaussian_blur(100);
    auto stop = high_resolution_clock::now();

    Video cap = Video("control_cap1.jpeg")

}