#include <ApprovalTests.hpp>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <fmt/ranges.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ApprovalTests::Approvals;
using ApprovalTests::StringUtils;
using namespace testing;

struct Custom {
  int value;
};

template <> std::string ApprovalTests::StringUtils::toString(const Custom& obj) {
  std::stringstream ss;
  ss << "Custom { .x = " << obj.value << " }";
  return ss.str();
}

TEST(Verify, FormatInt) {
  int x = 42;
  Approvals::verify(x);
}

TEST(Verify, FormatDouble) {
  double x = 3.14;
  Approvals::verify(x);
}

TEST(Verify, FormatCustom) {
  Custom x{.value = 42};
  Approvals::verify(x);
}

TEST(Verify, FormatVector) {
  std::vector<int> x{{1, 2, 3}};
  Approvals::verify(fmt::to_string(x));
}

TEST(VerifyAll, FormatAllInt) {
  std::vector<int> xs{{1, 2, 3}};
  Approvals::verifyAll(xs);
}

TEST(VerifyAll, FormatAllCustom) {
  std::vector<Custom> xs{{
      Custom{.value = 1},
      Custom{.value = 2},
      Custom{.value = 3},
  }};
  Approvals::verifyAll(xs);
}

TEST(VerifyAll, FormatVector) {
  std::vector<std::vector<int>> xs{{1, 2}, {3, 4}, {5, 6}};
  Approvals::verifyAll("", xs, [](const auto& contents, std::ostream& os) { fmt::print(os, "{}", contents); });
}