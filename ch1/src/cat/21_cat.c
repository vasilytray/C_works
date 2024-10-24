#include <stdio.h>
#include "./common/file_rpm.h"

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) { 
        rp_file(argv[i]);           
    }
  return 0; 
}