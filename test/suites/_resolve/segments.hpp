#ifndef TEST_PATHS_SEGMENTS_H
#define TEST_PATHS_SEGMENTS_H

#include <string>
#include <vector>

struct SegmentsTestCase {
    std::string              path;
    std::vector<std::string> expected;
};

const std::vector<SegmentsTestCase> cases = {};

// TODO: Test that the drive is ignored

#endif
