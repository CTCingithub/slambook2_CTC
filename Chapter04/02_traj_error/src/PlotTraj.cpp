#include <unistd.h>
#include <pangolin/pangolin.h>
#include "TrajType.h"

void DrawTraj(const TrajectoryType &groundtruth_data, const TrajectoryType &estimation_data)
{
    // Create Pangolin window
    pangolin::CreateWindowAndBind("Trajectory Viewer", 800, 600);
    // 启用深度测试
    glEnable(GL_DEPTH_TEST);
    // 启用混合
    glEnable(GL_BLEND);
    // 设置混合函数
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // 创建OpenGl渲染状态
    pangolin::OpenGlRenderState s_cam(
        // 设置投影矩阵
        pangolin::ProjectionMatrix(800, 600, 500, 500, 512, 389, 0.1, 1000),
        // 设置模型视图矩阵
        pangolin::ModelViewLookAt(0, -0.1, -1.8, 0, 0, 0, 0.0, -1.0, 0.0));
    // 创建视图
    pangolin::View &d_cam = pangolin::CreateDisplay()
                                // 设置视图边界
                                .SetBounds(0.0, 1.0, pangolin::Attach::Pix(175), 1.0, -800.0f / 600.0f)
                                // 设置视图处理器
                                .SetHandler(new pangolin::Handler3D(s_cam));

    while (pangolin::ShouldQuit() == false)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        d_cam.Activate(s_cam);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glLineWidth(2);

        // Draw ground truth trajectory
        for (std::size_t i = 0; i < groundtruth_data.size() - 1; i++)
        {
            glColor3f(0.0f, 0.0f, 1.0f); // Blue for ground truth data
            glBegin(GL_LINES);
            auto p1 = groundtruth_data[i].translation(), p2 = groundtruth_data[i + 1].translation();
            glVertex3f(p1[0], p1[1], p1[2]);
            glVertex3f(p2[0], p2[1], p2[2]);
            glEnd();
        }

        // Draw estimation trajectory
        for (std::size_t i = 0; i < estimation_data.size() - 1; i++)
        {
            glColor3f(1.0f, 0.0f, 0.0f); // Red for estimated data
            glBegin(GL_LINES);
            auto p1 = estimation_data[i].translation(), p2 = estimation_data[i + 1].translation();
            glVertex3f(p1[0], p1[1], p1[2]);
            glVertex3f(p2[0], p2[1], p2[2]);
            glEnd();
        }
        pangolin::FinishFrame();
        usleep(1000); // sleep 1 ms
    }
}