#include "image.h"
#include "block.h"
#include "ctest.h"


void test_bread(void){
    unsigned char testBlock[4096]={1,1,1,1,1,1};
    CTEST_ASSERT(bread(2,testBlock)==testBlock, "test for block read");
}
void test_bwrite(void){
    unsigned char testBlock[4096] = {1,1,1,1,1,0};
    bwrite(1,testBlock);
    CTEST_ASSERT(bread(1,testBlock)==testBlock, "test  for block write(write, then assert read)");
}

void test_open_img(void){
    CTEST_ASSERT(image_open("test_open_img.txt",1) == 4, "test for image_open to be open fd #4");
}

void test_img_close(void){
    CTEST_ASSERT(image_close()==0, "test for image_close");
}

void test_img_fd_init(void){
    CTEST_ASSERT(image_fd==-1, "test for image_fd to be set to -1");
}

void test_img_fd_gets_set(void){
    CTEST_ASSERT(image_fd!=-1, "test to see if image_fd is set");
}

#ifdef CTEST_ENABLE
int main(){
    CTEST_VERBOSE(1);

    test_img_fd_init();
    image_open("test_open_img.txt",0);
    test_img_fd_gets_set();
    test_open_img();
    test_img_close();
    test_bread();
    test_bwrite();

    CTEST_RESULTS();
    CTEST_EXIT();

    return 0;
}

#else
int main(){
    printf("If im here its not testing i think?");
}
#endif