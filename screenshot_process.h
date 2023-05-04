#pragma once
#include <vector>
#include <stdint.h>
//#include <atlimage.h>
#include <iostream>
#include <Gdiplus.h>
#include <fstream>

using std::vector;

//SERVER FUNCTIONS
vector<uint8_t> capture_screenshot();
HRESULT VectorToStream(const std::vector<uint8_t>& buffer, IStream** ppStream);
//CLIENT FUNCTIONS
void display_jpeg_image(const vector<uint8_t>& buffer);
void save_to_jpeg(const std::vector<uint8_t>& buffer, const std::string& filename);
