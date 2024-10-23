#include <pangolin/pangolin.h>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <unistd.h>

void DrawTrajectory(std::vector<Eigen::Isometry3d, Eigen::aligned_allocator<Eigen::Isometry3d>> poses)
{
    std::cout << "Start Ploting ..." << std::endl;
    // 创建Pangolin窗口
    pangolin::CreateWindowAndBind("Trajectory Viewer", 1024, 768);
    // 窗口设置
    // 启用深度测试
    glEnable(GL_DEPTH_TEST);
    // 启用混合
    glEnable(GL_BLEND);
    // 设置混合函数，源颜色与目标颜色的混合比例为源颜色的alpha值与(1-源颜色的alpha值)的乘积
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // 创建一个OpenGlRenderState对象，用于设置相机参数
    pangolin::OpenGlRenderState s_cam(
        // 设置投影矩阵，参数分别为：宽、高、焦距、焦距、图像中心点x、图像中心点y、近剪裁面、远剪裁面
        pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
        // 设置模型视图矩阵，参数分别为：相机位置、相机朝向、相机上方向
        pangolin::ModelViewLookAt(0, -0.1, -1.8, 0, 0, 0, 0.0, -1.0, 0.0));

    // 创建一个View对象，用于显示相机视图
    pangolin::View &d_cam = pangolin::CreateDisplay()
                                // 设置显示范围，参数分别为：左、右、下、上、宽高比
                                .SetBounds(0.0, 1.0, 0.0, 1.0, -1024.0f / 768.0f)
                                // 设置处理程序，参数为：相机参数
                                .SetHandler(new pangolin::Handler3D(s_cam));

    // 主循环，直到用户退出
    while (pangolin::ShouldQuit() == false)
    {
        // 清空颜色缓冲区和深度缓冲区
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // 激活相机
        d_cam.Activate(s_cam);
        // 设置背景颜色为白色
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        // 设置线宽为2
        glLineWidth(2);

        // 遍历所有姿态
        for (std::size_t i = 0; i < poses.size(); i++)
        {
            // 获取姿态的平移向量
            Eigen::Vector3d Ow = poses[i].translation();
            // 获取姿态的X轴向量
            Eigen::Vector3d Xw = poses[i] * (0.1 * Eigen::Vector3d(1, 0, 0));
            // 获取姿态的Y轴向量
            Eigen::Vector3d Yw = poses[i] * (0.1 * Eigen::Vector3d(0, 1, 0));
            // 获取姿态的Z轴向量
            Eigen::Vector3d Zw = poses[i] * (0.1 * Eigen::Vector3d(0, 0, 1));
            // 开始绘制线段
            glBegin(GL_LINES);
            // 绘制红色X轴向量
            glColor3f(1.0, 0.0, 0.0);
            glVertex3d(Ow[0], Ow[1], Ow[2]);
            glVertex3d(Xw[0], Xw[1], Xw[2]);
            // 绘制绿色Y轴向量
            glColor3f(0.0, 1.0, 0.0);
            glVertex3d(Ow[0], Ow[1], Ow[2]);
            glVertex3d(Yw[0], Yw[1], Yw[2]);
            // 绘制蓝色Z轴向量
            glColor3f(0.0, 0.0, 1.0);
            glVertex3d(Ow[0], Ow[1], Ow[2]);
            glVertex3d(Zw[0], Zw[1], Zw[2]);
            // 结束绘制线段
            glEnd();
        }

        // 遍历所有姿态
        for (std::size_t i = 0; i < poses.size(); i++)
        {
            // 设置颜色为黑色
            glColor3f(0.0, 0.0, 0.0);
            // 开始绘制线段
            glBegin(GL_LINES);
            // 获取两个姿态的平移向量
            auto p1 = poses[i], p2 = poses[i + 1];
            // 绘制线段
            glVertex3d(p1.translation()[0], p1.translation()[1], p1.translation()[2]);
            glVertex3d(p2.translation()[0], p2.translation()[1], p2.translation()[2]);
            // 结束绘制线段
            glEnd();
        }

        // 完成帧绘制
        pangolin::FinishFrame();
        usleep(5000);
    }
}