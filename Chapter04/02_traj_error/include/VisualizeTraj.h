#ifndef VISUALIZETRAJ_H
#define VISUALIZETRAJ_H

#include <unistd.h>
#include <pangolin/pangolin.h>
#include "TrajType.h"

void DrawTraj(const TrajectoryType &groundtruth_data, const TrajectoryType &estimation_data);

#endif