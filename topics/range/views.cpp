#include <gtest/gtest.h>
#include <ranges>

TEST(ViewTests, FilterView) {
  auto numbers = std::vector{1, 2, 3, 4, 5};
  auto even_numbers = numbers | std::views::filter([](int n) { return n % 2 == 0; });
  std::vector actual(even_numbers.begin(), even_numbers.end());
  std::vector expected = {2, 4};
  EXPECT_EQ(actual, expected);
}