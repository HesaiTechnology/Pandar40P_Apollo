/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
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

#include "pandar40p.h"
#include "pandar40p_internal.h"

namespace apollo {
namespace drivers {
namespace hesai {

Pandar40P::Pandar40P(
    std::string device_ip, unsigned short lidar_port, unsigned short gps_port,
    boost::function<void(boost::shared_ptr<PPointCloud>, double)> pcl_callback,
    boost::function<void(double)> gps_callback, unsigned short start_angle) {
  internal_ = new Pandar40P_Internal(device_ip, lidar_port, gps_port,
                                     pcl_callback, gps_callback, start_angle);
}

Pandar40P::~Pandar40P() { delete internal_; }

/**
 * @brief load the correction file
 * @param file The path of correction file
 */
int Pandar40P::LoadCorrectionFile(std::string file) {
  internal_->LoadCorrectionFile(file);
}

/**
 * @brief load the correction file
 * @param angle The start angle
 */
void Pandar40P::ResetStartAngle(unsigned short start_angle) {
  internal_->ResetStartAngle(start_angle);
}

int Pandar40P::Start() { internal_->Start(); }

void Pandar40P::Stop() { internal_->Stop(); }

}  // apollo
}  // drivers
}  // hesai