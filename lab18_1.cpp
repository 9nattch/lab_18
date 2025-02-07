#include<iostream>
using namespace std;


struct Rect {
    double x, y, w, h; 
};

double overlap(Rect R1, Rect R2) {
    double R1_right = R1.x + R1.w;  
    double R1_bottom = R1.y - R1.h; 
    double R2_right = R2.x + R2.w;  
    double R2_bottom = R2.y - R2.h; 

    double overlap_left = max(R1.x, R2.x);
    double overlap_right = min(R1_right, R2_right);
    double overlap_top = min(R1.y, R2.y);
    double overlap_bottom = max(R1_bottom, R2_bottom);

    double overlap_w = overlap_right - overlap_left;
    double overlap_h = overlap_top - overlap_bottom;

  
    if (overlap_w <= 0 || overlap_h <= 0) {
        return 0;
    }

    return overlap_w * overlap_h;
}
