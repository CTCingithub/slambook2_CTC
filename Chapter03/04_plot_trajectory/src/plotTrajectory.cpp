#include <pangolin/pangolin.h>
#include <Eigen/Core>
#include <unistd.h>
#include "libVisualization.h"

std::string trajectory_data__file = "../Data/trajectory.txt";

int main(int argc, char **argv)
{
    std::ifstream fin(trajectory_data__file);

    // 查找轨迹数据文件
    if (!fin)
    {
        std::cout << "cannot find trajectory file at " << trajectory_data__file << std::endl;
        return 1;
    }

    // 导入轨迹数据
    while (!fin.eof())
    {
        double time, x, y, z, qx, qy, qz, qw;
        fin >> time >> x >> y >> z >> qx >> qy >> qz >> qw;
        // std::cout << "time: " << time << " x: " << x << " y: " << y << " z: " << z << " qx: " << qx << " qy: " << qy << " qz: " << qz << " qw: " << qw << std::endl;
    }
    return 0;
}