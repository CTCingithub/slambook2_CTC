#include <pangolin/pangolin.h>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <unistd.h>

void DrawTrajectory(std::vector<Eigen::Isometry3d, Eigen::aligned_allocator<Eigen::Isometry3d>> poses)
{
    std::cout << "Start Ploting ..." << std::endl;
    // ����Pangolin����
    pangolin::CreateWindowAndBind("Trajectory Viewer", 1024, 768);
    // ��������
    // ������Ȳ���
    glEnable(GL_DEPTH_TEST);
    // ���û��
    glEnable(GL_BLEND);
    // ���û�Ϻ�����Դ��ɫ��Ŀ����ɫ�Ļ�ϱ���ΪԴ��ɫ��alphaֵ��(1-Դ��ɫ��alphaֵ)�ĳ˻�
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // ����һ��OpenGlRenderState�������������������
    pangolin::OpenGlRenderState s_cam(
        // ����ͶӰ���󣬲����ֱ�Ϊ�����ߡ����ࡢ���ࡢͼ�����ĵ�x��ͼ�����ĵ�y���������桢Զ������
        pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
        // ����ģ����ͼ���󣬲����ֱ�Ϊ�����λ�á������������Ϸ���
        pangolin::ModelViewLookAt(0, -0.1, -1.8, 0, 0, 0, 0.0, -1.0, 0.0));

    // ����һ��View����������ʾ�����ͼ
    pangolin::View &d_cam = pangolin::CreateDisplay()
                                // ������ʾ��Χ�������ֱ�Ϊ�����ҡ��¡��ϡ���߱�
                                .SetBounds(0.0, 1.0, 0.0, 1.0, -1024.0f / 768.0f)
                                // ���ô�����򣬲���Ϊ���������
                                .SetHandler(new pangolin::Handler3D(s_cam));

    // ��ѭ����ֱ���û��˳�
    while (pangolin::ShouldQuit() == false)
    {
        // �����ɫ����������Ȼ�����
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // �������
        d_cam.Activate(s_cam);
        // ���ñ�����ɫΪ��ɫ
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        // �����߿�Ϊ2
        glLineWidth(2);

        // ����������̬
        for (std::size_t i = 0; i < poses.size(); i++)
        {
            // ��ȡ��̬��ƽ������
            Eigen::Vector3d Ow = poses[i].translation();
            // ��ȡ��̬��X������
            Eigen::Vector3d Xw = poses[i] * (0.1 * Eigen::Vector3d(1, 0, 0));
            // ��ȡ��̬��Y������
            Eigen::Vector3d Yw = poses[i] * (0.1 * Eigen::Vector3d(0, 1, 0));
            // ��ȡ��̬��Z������
            Eigen::Vector3d Zw = poses[i] * (0.1 * Eigen::Vector3d(0, 0, 1));
            // ��ʼ�����߶�
            glBegin(GL_LINES);
            // ���ƺ�ɫX������
            glColor3f(1.0, 0.0, 0.0);
            glVertex3d(Ow[0], Ow[1], Ow[2]);
            glVertex3d(Xw[0], Xw[1], Xw[2]);
            // ������ɫY������
            glColor3f(0.0, 1.0, 0.0);
            glVertex3d(Ow[0], Ow[1], Ow[2]);
            glVertex3d(Yw[0], Yw[1], Yw[2]);
            // ������ɫZ������
            glColor3f(0.0, 0.0, 1.0);
            glVertex3d(Ow[0], Ow[1], Ow[2]);
            glVertex3d(Zw[0], Zw[1], Zw[2]);
            // ���������߶�
            glEnd();
        }

        // ����������̬
        for (std::size_t i = 0; i < poses.size(); i++)
        {
            // ������ɫΪ��ɫ
            glColor3f(0.0, 0.0, 0.0);
            // ��ʼ�����߶�
            glBegin(GL_LINES);
            // ��ȡ������̬��ƽ������
            auto p1 = poses[i], p2 = poses[i + 1];
            // �����߶�
            glVertex3d(p1.translation()[0], p1.translation()[1], p1.translation()[2]);
            glVertex3d(p2.translation()[0], p2.translation()[1], p2.translation()[2]);
            // ���������߶�
            glEnd();
        }

        // ���֡����
        pangolin::FinishFrame();
        usleep(5000);
    }
}