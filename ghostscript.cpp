#include <ghostscript/iapi.h>
#include <ghostscript/ierrors.h>
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <PDF file> <Output image base name>" << std::endl;
        return 1;
    }

    void *minst;
    int code;

    // Initialize Ghostscript
    code = gsapi_new_instance(&minst, NULL);
    if (code < 0) return 1;

    // Create the output file argument
    std::string outputFileArg = "-sOutputFile=";
    outputFileArg += argv[2];  // Append the base output file name
    outputFileArg += "%d.png"; // %d will be replaced by the page number

    // Arguments for Ghostscript
    const char *gsargv[] = {
        "gs",
        "-dNOPAUSE",
        "-dBATCH",
        "-dSAFER",
        "-sDEVICE=pngalpha",
        "-r300",
        "-dBackgroundColor=16#FFFFFF",
        outputFileArg.c_str(),
        argv[1]
    };
    int gsargc = sizeof(gsargv) / sizeof(gsargv[0]);

    // Execute Ghostscript
    code = gsapi_init_with_args(minst, gsargc, const_cast<char **>(gsargv));
    if (code == 0) { // 0 indicates successful execution
        code = gsapi_exit(minst);
    }

    gsapi_delete_instance(minst);

    return code;
}
