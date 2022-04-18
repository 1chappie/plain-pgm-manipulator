//
// Created by chappie on 05.04.2022.
//

#ifndef LABORATORY4_1CHAPPIE_IMAGETESTS_H
#define LABORATORY4_1CHAPPIE_IMAGETESTS_H
#include "../Tests.h"

class ImageTests {
public:
    static void execute();
private:
    static void test_constructors();
    static void test_save_load();
    static void test_operators();
    static void test_roi();
    static void test_getters();
    static void test_utility();
};


#endif //LABORATORY4_1CHAPPIE_IMAGETESTS_H
