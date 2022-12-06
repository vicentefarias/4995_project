#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>

using namespace cv;
using namespace std;

int main(){

    Ptr<TrackerKCF> tracker = TrackerKCF::create();

    string s; cin >> s;
    VideoCapture capture(s);
    if (!capture.isOpened()){
        cout << "Error: couldn't load video\n";
        return -1;
    }

    // init video frame and select bounding box
    Mat frame; 
    capture.read(frame);

    Rect box; 
    box = selectROI(frame, false);
    rectangle(frame, box, Scalar(255,0,0),2,1);
    imshow("Tracker Frame 1", frame);
    tracker->init(frame, box);


    cout << "Press x to exit the program\n";
    auto start = std::chrono::high_resolution_clock::now();
    int frame_count = 0;
    int total_frames = 0;
    float fps = -1;

    while(capture.read(frame)){

        frame_count++;
        total_frames++;
        
        bool updated = tracker->update(frame, box);
        if (updated){
            rectangle(frame, box, Scalar(255,0,0),2,1);
        }
        else{
            putText(frame, "Error: object tracking failed", Point(100, 80), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0,0,255),2);
        }

        if (frame_count >= 30){
            auto end = std::chrono::high_resolution_clock::now();
            fps = frame_count * 1000.0 / std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

            frame_count = 0;
            start = std::chrono::high_resolution_clock::now();
        }
        
        putText(frame, "FPS: " + to_string(fps) , Point(100, 50), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0,255,0),2);
        imshow("Tracking", frame);

        if (cv::waitKey(1) != -1){
            capture.release();
            std::cout << "finished by user\n";
            break;
        }
    }
    return 0;
}   