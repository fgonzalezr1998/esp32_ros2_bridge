#include <rclcpp/rclcpp.hpp>
#include <rclcpp/executors/multi_threaded_executor.hpp>
#include <string>
#include <memory>
#include "esp32_ros2_bridge/ROS2Esp32Bridge.hpp"

class DownlinkComm : public rclcpp::Node
{
public:
  DownlinkComm(const std::string & node_name)
  : Node(node_name)
  {
  }
};

class UplinkComm : public rclcpp::Node
{
public:
  UplinkComm(const std::string & node_name)
  : Node(node_name)
  {
    ;
  }
};

int main(int argc, char ** argv)
{
  std::shared_ptr<DownlinkComm> downlinkcomm_node;
  std::shared_ptr<UplinkComm> uplinkcomm_node;

  rclcpp::init(argc, argv);

  rclcpp::executors::MultiThreadedExecutor executor;

  downlinkcomm_node = std::make_shared<DownlinkComm>("downlinkcomm_node");
  uplinkcomm_node = std::make_shared<UplinkComm>("uplinkcomm_node");

  executor.add_node(downlinkcomm_node->get_node_base_interface());
  executor.add_node(uplinkcomm_node->get_node_base_interface());
  executor.spin();

  printf("Hello\n");
  rclcpp::shutdown();
  exit(EXIT_SUCCESS);
}