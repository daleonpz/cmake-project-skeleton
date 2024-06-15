#include <gmock/gmock.h>
#include <gtest/gtest.h>

// Example class to be mocked
class MyClass
{
  public:
	virtual ~MyClass() = default;
	virtual int DoSomething(int value) = 0;
};

// Mock class
class MockMyClass : public MyClass
{
  public:
	MOCK_METHOD(int, DoSomething, (int value), (override));
};

// Test case using gmock
TEST(MockTest, DoSomethingTest)
{
	MockMyClass mock;
	EXPECT_CALL(mock, DoSomething(testing::Gt(0))).Times(1).WillOnce(testing::Return(1));

	EXPECT_EQ(mock.DoSomething(5), 1);
}
