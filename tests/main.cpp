#define APPROVALS_GOOGLETEST

#include <ApprovalTests.hpp>
#include <memory>

using namespace ApprovalTests;

 auto defaultReporterDisposer = Approvals::useAsDefaultReporter(std::make_shared<AutoApproveReporter>());