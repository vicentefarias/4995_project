
#include <chrono>
#include "Image.h"
#include "Video.h"

// IMAGE BENCHMARKS

void load_benchmark(){
    Image img;
    auto totalTime = 0;
    for(int i=0; i<500; i++){
        auto start = std::chrono::high_resolution_clock::now();
        img = Image("sp500.png");
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        totalTime += time.count();
    }
     std::cout  << "Average image load time in ms: " << (totalTime/500.0)/1000.0 << std::endl;

}

//  benchmark blending two images
void alpha_blend_benchmark(){
    Image img1 = Image("sp500.png");
    Image img2 = Image("times-square.png");
    auto totalTime = 0;
    for(int i=0; i<500; i++){
        auto start = std::chrono::high_resolution_clock::now();
        img2.fit_to_size(img1);
        img1 = img1.alpha_blend(img2, 0.5); 
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        totalTime += time.count();
    }
     std::cout  << "Average image blend time in ms: " << (totalTime/500.0)/1000.0 << std::endl;
}

//  benchmark image detection for given set of thresholds
void edge_detect_benchmark(){
    Image img1 = Image("sp500.png");
    auto totalTime = 0;
    for(int i=0; i<500; i++){
        auto start = std::chrono::high_resolution_clock::now();
        img1 = img1.edge_detect(100,200); 
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        totalTime += time.count();
    }
     std::cout  << "Average image edge detect time in ms: " << (totalTime/500.0)/1000.0 << std::endl;
}

//  benchmark gaussian blurring for given blurring factor 15
//      number of iterations reduced to 500 due to convolutional computations at each pixel
void gaussian_blur_benchmark(){
    Image img1 = Image("sp500.png");
    auto totalTime = 0;
    for(int i=0; i<500; i++){
        auto start = std::chrono::high_resolution_clock::now();
        img1 = img1.gaussian_blur(15); 
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        totalTime += time.count();
    }
     std::cout  << "Average gaussian blurred image elapsed time in ms: " << (totalTime/500.0)/1000.0 << "\n";
}



//  
void threshold_benchmark(){
    Image img = Image("sp500.png");
    auto totalTime = 0;
    for(int i=0; i<500; i++){
        auto start = std::chrono::high_resolution_clock::now();
        img = img.threshold(1, 100); 
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        totalTime += time.count();
    }
     std::cout  << "Average thresholded image elapsed time (ms)" << (totalTime/500.0)/1000.0 << "";
}


void grayscale_benchmark(){
    Image img = Image("sp500.png");
    auto totalTime = 0;
    for(int i=0; i<500; i++){
        auto start = std::chrono::high_resolution_clock::now();
        img = img.grayscale(); 
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        totalTime += time.count();
    }
     std::cout  << "Average grayscale image elapsed time (ms): " << (totalTime/500.0)/1000.0 << "";
}


void detection_benchmark(){
    Image img = Image("sp500.png");
    auto totalTime = 0;
    for(int i=0; i<100; i++){
        auto start = std::chrono::high_resolution_clock::now();
        img = img.detection(); 
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        totalTime += time.count();
    }
     std::cout  << "Average image detection elapsed time (ms): " << (totalTime/100.0)/1000.0 << "";
}


// VIDEO BENCHMARKS

void video_edge_detection_benchmark(){

    Video video = Video("sample.mp4");
    auto start = std::chrono::high_resolution_clock::now();
    video.edge_detect(100, 200);
    auto end = std::chrono::high_resolution_clock::now();
     auto time = std::chrono::duration_cast<std::chrono::seconds> (end - start);
     std::cout  << "Edge detection execution time (s): " << time.count() << "\n";


}

void video_gaussian_blur_benchmark(){
    
    Video video = Video("sample.mp4");
    auto start = std::chrono::high_resolution_clock::now();
    video.gaussian_blur(15);
    auto end = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::seconds> (end - start);
     std::cout  << "Video blurring execution time (s): " << time.count() << "\n";

}


void video_threshold_benchmark(){
    
    Video video = Video("sample.mp4");
    auto start = std::chrono::high_resolution_clock::now();
    video.threshold(1, 100);
    auto end = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::seconds> (end - start);
    std::cout << "Video threshold execution time (s): " << time.count() << "\n";

}

int main() {

    // image benchmarks 
    load_benchmark();
    alpha_blend_benchmark();
    edge_detect_benchmark();
    gaussian_blur_benchmark();
   // threshold_benchmark();
   // grayscale_benchmark();
    detection_benchmark();


  //  create_homography_benchmark();
  //  project_image_benchmark();
    
    // video benchmarks 
    video_edge_detection_benchmark();
    video_gaussian_blur_benchmark();
    video_threshold_benchmark();


    return 0;
}