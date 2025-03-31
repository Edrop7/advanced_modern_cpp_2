#include <ros/ros.h>

using std::string;

int main(int argc, char **argv) {
  ros::init(argc, argv, "lambda_basics_node");
  ros::NodeHandle _n("lambda_basics_ns");

  // We define the Lambda function merge_words
  auto merge_words = [](std::string a, std::string b) -> string {
    return a + "-" + b;
  };

  auto result = merge_words("Adventure", "Time");

  std::cout << "Result Merge: " << result << std::endl;

  return 0;
}