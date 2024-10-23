#include <pangolin/pangolin.h>
#include <Eigen/Core>
#include "libVisualization.h"

std::string trajectory_data__file = "../Data/trajectory.txt";

int main(int argc, char **argv)
{
    std::vector<
        Eigen::Isometry3d, Eigen::aligned_allocator<Eigen::Isometry3d>>
        poses;
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
        // std::cout << "time: " << time << " x: " << x << " y: " << y << " z: " << z
        //           << " qx: " << qx << " qy: " << qy << " qz: " << qz
        //           << " qw: " << qw << std::endl;
        Eigen::Isometry3d Twr(Eigen::Quaterniond(qw, qx, qy, qz));
        Twr.pretranslate(Eigen::Vector3d(x, y, z));
        poses.push_back(Twr);
    }

    std::cout << "Data size " << poses.size() << std::endl;
    DrawTrajectory(poses);
    return 0;
}