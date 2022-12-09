#include <iostream>
#include <chrono>

#include "Image.h"
#include "Video.h"

using std::cout;
using std::cin;
using std::cerr;
using std::chrono;


void edge_detect_benchmark(){
    Image img1 = Image("sp500.png");
    auto totalTime = 0;
    for(int i=0; i<5000; i++){
        auto start = high_resolution_clock::now();
        img1 = img1.edge_detect(100,200); 
        auto end = chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        totalTime += time.count();
    }
     cout << "totalTime in ms" << (totalTime/5000.0)/1000.0 << std::endl;
}

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


// Image Functionalities


    // test load speeds
  }