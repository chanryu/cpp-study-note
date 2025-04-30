#include <gtest/gtest.h>

#include <ranges>
#include <vector>

TEST(ViewsTests, FilterView) {
  auto numbers = std::views::iota(0, 10) | std::views::filter([](auto n) { return n % 2 == 0; });

  auto const actual = std::ranges::to<std::vector>(numbers);
  auto const expected = std::vector{0, 2, 4, 6, 8};

  EXPECT_EQ(actual, expected);
}