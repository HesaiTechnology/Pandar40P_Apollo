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

#ifndef SRC_LIDAR_CORRECTION_H_
#define SRC_LIDAR_CORRECTION_H_

#include <sstream>
#include <string>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

namespace apollo {
namespace drivers {
namespace hesai {

double degreeToRadian(double degrees);

struct PandarLaserCorrection {
  double azimuthCorrection;
  double verticalCorrection;
  double distanceCorrection;
  double verticalOffsetCorrection;
  double horizontalOffsetCorrection;
  double sinVertCorrection;
  double cosVertCorrection;
  double sinVertOffsetCorrection;
  double cosVertOffsetCorrection;
};

class LidarCorrection {
 public:
  LidarCorrection() : initialized(false) {}
  explicit LidarCorrection(const std::string& LidarCorrectionFile) {
    read(LidarCorrectionFile);
  }

  void read(const std::string& LidarCorrectionFile);
  PandarLaserCorrection laserCorrections[40];
  bool initialized;

 private:
  void setDefaultCorrections();
};

}  // namespace hesai
}  // namespace drivers
}  // namespace apollo

#endif  // SRC_LIDAR_CORRECTION_H_
