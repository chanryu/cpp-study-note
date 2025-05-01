#include <gtest/gtest.h>

#include <ranges>
#include <vector>

TEST(ViewsTests, _) {
  auto const actual = std::views::iota(1)                                     // generated stream of ints from 1
                      | std::views::filter([](auto n) { return n % 2 == 0; }) // filter even numbers
                      | std::views::drop(1)                                   // drop the first -- 2
                      | std::views::take(3)                                   // take the next 3 -- 6, 8, 10
                      | std::ranges::to<std::vector>();                       // convert to vector

  auto const expected = std::vector{4, 6, 8};

  EXPECT_EQ(actual, expected);
}