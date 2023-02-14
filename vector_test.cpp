#include <gtest/gtest.h>

#include "vector.h"

using namespace std;

class TestNode {
public:
    int val;
    TestNode() : val(42) {

    }

};

bool operator==(const TestNode &lhs, const TestNode &rhs) {
    return lhs.val == rhs.val;
}

// Constructors
TEST(Vector, ctor_empty)
{
	Vector<int> v;

	// Check size = 0, capacity = 0, no elements
	EXPECT_EQ(0, v.size());
	EXPECT_EQ(0, v.capacity());

	// Check size = 0, capacity = 0, no elements
    Vector<TestNode> vn;
    EXPECT_EQ(0, vn.size());
	EXPECT_EQ(0, vn.capacity());
}

TEST(Vector, ctor_size)
{
	Vector<int> v(10);

	// Check size = 10, capacity = 20, element default ctor'ed
	EXPECT_EQ(10, v.size());
	EXPECT_EQ(20, v.capacity());

    for (size_t i = 0; i < 10; i++) {
	    EXPECT_EQ(0, v[i]);
    }

    Vector<TestNode> vn(10);

    TestNode t;
    for (size_t i = 0; i < 10; i++) {
	    EXPECT_EQ(t, vn[i]);
    }

	// Check size = 10, capacity = 20, element default ctor'ed
	EXPECT_EQ(10, vn.size());
	EXPECT_EQ(20, vn.capacity());
}

TEST(Vector, vectorCopyCtor)
{
	Vector<char> v;
	v.push_back('a');
	v.push_back('z');
	v.push_back('x');
	v.push_back('r');
	v.push_back('e');

	Vector<char> copy = v;

	EXPECT_EQ(v.at(0), copy.at(0));
	EXPECT_EQ(v.at(1), copy.at(1));
	EXPECT_EQ(v.at(2), copy.at(2));
	EXPECT_EQ(v.at(3), copy.at(3));
	EXPECT_EQ(v.at(4), copy.at(4));
}

// Capacity
TEST(Vector, size)
{
	Vector<double> v;

	// Size should be 0 upon creation
	EXPECT_EQ(0, v.size());

	v.push_back(3.14);
	EXPECT_EQ(1, v.size());

	v.push_back(0);
	EXPECT_EQ(2, v.size());
}

TEST(Vector, capacity)
{
	Vector<int> v;
    EXPECT_EQ(0, v.capacity());

    for (int i = 0; i < 8; i++) {
        v.push_back(42);
        EXPECT_EQ(8, v.capacity());
    }

    for (int i = 0; i < 8 * 2 + 8 - 8; i++) {
        v.push_back(42);
        EXPECT_EQ(24, v.capacity());
    }

    v.push_back(42);
    EXPECT_EQ(56, v.capacity());
}

// Modifiers
TEST(Vector, push_back_ints)
{
	Vector<int> v;

	for (int i = 0; i < 10; ++i)
		v.push_back(i);

	for (int i = 0; i < 10; ++i)
		EXPECT_EQ(i, v[i]);

	v.push_back(1000);
	EXPECT_EQ(1000, v[v.size() - 1]);
}


// Accessors
TEST(Vector, accessAt)
{
	// Non-const vector
	Vector<int> v;

	EXPECT_THROW(v.at(0), out_of_range);
	EXPECT_THROW(v.at(-97), out_of_range);
	EXPECT_THROW(v.at(1), out_of_range);

	v.push_back(4);
	v.push_back(8);
	v.push_back(10);
	v.push_back(-19);
	v.push_back(0);

	EXPECT_EQ(4, v.at(0));
	EXPECT_EQ(8, v.at(1));
	EXPECT_EQ(10, v.at(2));
	EXPECT_EQ(-19, v.at(3));
	EXPECT_EQ(0, v.at(4));

	EXPECT_THROW(v.at(-1), out_of_range);
	EXPECT_THROW(v.at(5), out_of_range);


	// Const vector
	const Vector<int> cv = v;

	EXPECT_EQ(4, cv.at(0));
	EXPECT_EQ(8, cv.at(1));
	EXPECT_EQ(10, cv.at(2));
	EXPECT_EQ(-19, cv.at(3));
	EXPECT_EQ(0, cv.at(4));

	EXPECT_THROW(cv.at(-1), out_of_range);
	EXPECT_THROW(cv.at(5), out_of_range);
	EXPECT_THROW(cv.at(-2), out_of_range);
	EXPECT_THROW(cv.at(8), out_of_range);
}

TEST(Vector, accessBrackets)
{
	const int NUM_ELEMENTS = 50;

	Vector<double> v;

	for (int i = 0; i < NUM_ELEMENTS; ++i)
		v.push_back(i);

	for (int i = 0; i < NUM_ELEMENTS; ++i)
		EXPECT_EQ(i, v[i]);

	const Vector<double> cv = v;

	for (int i = 0; i < NUM_ELEMENTS; ++i)
		EXPECT_EQ(i, cv[i]);
}

TEST(Vector, accessFront)
{
	Vector<int> v;

	v.push_back(9);
	EXPECT_EQ(9, v.front());

	v.push_back(4);
	EXPECT_EQ(9, v.front());
}

TEST(Vector, accessBack)
{
	Vector<int> v;

	v.push_back(9);
	EXPECT_EQ(9, v.back());

	v.push_back(4);
	EXPECT_EQ(4, v.back());

	v.push_back(1);
	EXPECT_EQ(1, v.back());
}
