#include "screenshot_process.h"

using std::vector;

#define SCREENSHOT_PORT 5000



void streaming() {
    while (1) { //CO TIN HIEU DUNG GHI O DAY
        vector<uint8_t> data = capture_screenshot();

        //CO HAM GUI DATA QUA CHO CLIENT O DAY THAY VI DISPLAY (gui UDP)
        ////////////////////////////////////////////////////////////
        display_jpeg_image(data);
    }
}

void viewing_stream() { // Tham so dau vao la 1 cai socket
    while (true) { //CO TIN HIEU DUNG XEM O DAY (CUNG 1 TIN HIEU VOI DUNG STREAM)
        //vector<uint8_t> = .... //Nhan data gui den socket
        //display(data);
    }
}

int main() {
    streaming();
}