/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 *   @file
 **/

#pragma once

#include <string>
#include <vector>

#include "modules/common/configs/proto/vehicle_config.pb.h"
#include "modules/planning/proto/speed_bounds_decider_config.pb.h"

#include "modules/common/status/status.h"
#include "modules/planning/common/obstacle.h"
#include "modules/planning/common/path/path_data.h"
#include "modules/planning/common/path_decision.h"
#include "modules/planning/common/speed/st_boundary.h"
#include "modules/planning/common/speed_limit.h"
#include "modules/planning/reference_line/reference_line.h"

namespace apollo {
namespace planning {

class STObstaclesProcessor {
 public:
  STObstaclesProcessor();

  virtual ~STObstaclesProcessor() = default;

  common::Status MapObstaclesToSTBoundary(PathDecision* const path_decision);

  std::pair<double, double> GetRegularBoundaryFromObstacles(double t);

  std::pair<double, double> GetFallbackBoundaryFromObstacles(double t);

 private:
  double t_resolution_;
  STGuideLine* st_guide_line_ptr_;
  STDrivingLimits* st_driving_limits_ptr_;
};