#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

void split(const vector<int>& elements, vector<int>& a, vector<int>& b) {
    size_t size = elements.size();
    size_t m = size >> 1;
    for (size_t i = 0; i < size; ++i) {
        if (i < m)
            a.push_back(elements[i]);
        else
            b.push_back(elements[i]);
    }
}

vector<int> merge(const vector<int>& a, const vector<int>& b) {
    vector<int> v;
    size_t aIdx = 0;
    size_t bIdx = 0;
    while (aIdx < a.size() && bIdx < b.size()) {
        if (a[aIdx] < b[bIdx]) v.push_back(a[aIdx++]);
        else v.push_back(b[bIdx++]);
    }

    while (aIdx < a.size()) v.push_back(a[aIdx++]);
    while (bIdx < b.size()) v.push_back(b[bIdx++]);

    return v;
}

vector<int> sort(const vector<int>& elements) {
    if (elements.size() < 2) return elements;

    if (elements.size() == 2) {
        if (elements[0] < elements[1]) return elements;
        else return vector<int>({elements[1], elements[0]});
    }

    vector<int> a;
    vector<int> b;
    split(elements, a, b);
    return merge(sort(a), sort(b));
}

TEST_CASE("Sorting an empty vector") {
    vector<int> empty;
    REQUIRE(sort(empty) == vector<int>());
}

TEST_CASE("Sorting one element") {
    vector<int> v = {42};
    REQUIRE(sort(v) == vector<int>({42}));
}

TEST_CASE("Elements already sorted") {
    vector<int> v = {1, 2};
    REQUIRE(sort(v) == vector<int>({1, 2}));
}

TEST_CASE("Two unsorted elements") {
    vector<int> v = {2, 1};
    REQUIRE(sort(v) == vector<int>({1, 2}));
}

TEST_CASE("Two unsorted elements in bigger vector") {
    vector<int> v = {1, 3, 2, 4, 5, 6};
    REQUIRE(sort(v) == vector<int>({1, 2, 3, 4, 5, 6}));
}

TEST_CASE("Sequence of sorted elements between unsorted elements") {
    vector<int> v = {1, 3, 4, 2 };
    REQUIRE(sort(v) == vector<int>({1, 2, 3, 4}));
}

TEST_CASE("Multiple unsorted elements") {
    vector<int> v = {1, 3, 4, 2, 7, 6, 8, 5 };
    REQUIRE(sort(v) == vector<int>({1, 2, 3, 4, 5, 6, 7, 8}));
}

TEST_CASE("Sorted in opposite order") {
    vector<int> v = { 5, 4, 3, 2, 1 };
    REQUIRE(sort(v) == vector<int>({1, 2, 3, 4, 5}));
}

TEST_CASE("Wikipedia example") {
    vector<int> v = { 5, 1, 4, 2, 8  };
    REQUIRE(sort(v) == vector<int>({1, 2, 4, 5, 8}));
}