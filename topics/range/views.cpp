#include <gtest/gtest.h>

#include <ranges>
#include <vector>

TEST(ViewTests, FilterView) {
  auto numbers = std::vector{1, 2, 3, 4, 5};
  auto even_numbers = numbers | std::views::filter([](auto n) { return n % 2 == 0; });

  std::vector<int> actual(even_numbers.begin(), even_numbers.end());
  // std::ranges::copy(even_numbers, std::back_inserter(actual));

  auto const expected = std::vector{2, 4};

  EXPECT_EQ(actual, expected);
}