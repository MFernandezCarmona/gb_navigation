// Copyright 2021 Intelligent Robotics Lab
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GB_PLANSYS2_COMMON_ACTIONS__BEHAVIOR_TREE_NODES__MOVE_HPP_
#define GB_PLANSYS2_COMMON_ACTIONS__BEHAVIOR_TREE_NODES__MOVE_HPP_

#include <string>
#include <map>

#include "geometry_msgs/msg/pose2_d.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"

#include "plansys2_bt_actions/BTActionNode.hpp"
#include "behaviortree_cpp_v3/behavior_tree.h"
#include "behaviortree_cpp_v3/bt_factory.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

#include "rclcpp_lifecycle/lifecycle_node.hpp"

namespace gb_navigation
{

class Move : public plansys2::BtActionNode<
    nav2_msgs::action::NavigateToPose>
{
public:
  explicit Move(
    const std::string & xml_tag_name,
    const std::string & action_name,
    const BT::NodeConfiguration & conf);

  void on_tick() override;
  BT::NodeStatus on_success() override;

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<std::string>("goal")
    };
  }

private:
  int goal_reached_;
  std::map<std::string, geometry_msgs::msg::Pose2D> waypoints_;
};

}  // namespace gb_plansys2_common_actions

#endif  // GB_PLANSYS2_COMMON_ACTIONS__BEHAVIOR_TREE_NODES__MOVE_HPP_
