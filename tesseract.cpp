#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> images = {}; // List of image files
    
    int numpages;
	
	std::cout << "Number of pages desired to OCR: " << std::endl;
	
	std::cin >> numpages;
	
	for (int i = 0; i < numpages; i++) {
		images.emplace_back("image" + std::to_string(i+1) + ".png");
	}
	
    int fileCounter = 0; // Counter for file naming

    for (const auto& imagePath : images) {
        tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();
        if (ocr->Init(NULL, "hin")) {
            fprintf(stderr, "Could not initialize tesseract.\n");
            continue; // Skip to next image
        }

        Pix *image = pixRead(imagePath.c_str());
        ocr->SetImage(image);

        // Get OCR result
        char* text = ocr->GetUTF8Text();

        // Generate a unique file name
        std::string filename = "ocr_output_" + std::to_string(fileCounter++) + ".txt";
        std::ofstream outfile(filename);

        // Write the OCR result to the file
        if (outfile.is_open()) {
            outfile << text;
            outfile.close();
        } else {
            std::cerr << "Error opening file " << filename << " for writing.\n";
        }

        // Clean up
        ocr->End();
        delete [] text;
        pixDestroy(&image);
    }

    return 0;
}
