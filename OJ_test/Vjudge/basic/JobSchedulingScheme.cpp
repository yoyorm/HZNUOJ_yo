//https://www.luogu.com.cn/problem/P1065

#include <iostream>
#include <vector>
using namespace std;

void fillTable(vector<vector<int>> &machineTime, int job, int machine, int time, vector<int> &joblastTime);
bool enoughfill(const vector<vector<int>> &machineTime, int job, int machine, int time, int pos);
void fillit(vector<vector<int>> &machineTime, int job, int machine, int time, int pos);
int findLastTime(vector<vector<int>> &machineTime);
void showTable(vector<vector<int>> &machineTime);
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> timeConsume(n + 1, vector<int>(m + 1));//时间对应表
    vector<vector<int>> machineChoose(n + 1, vector<int>(m + 1));//机器对应表
    vector<int> jobstate(n + 1, 1);//每个零件状态
    vector<int> jobLastTime(n + 1, 0);//零件上个工序完成时间
    vector<int> order(m * n);//任务执行顺序

    //开始输入
    for (int i = 0; i < m * n; i++)
    {
        cin >> order[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> machineChoose[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> timeConsume[i][j];
        }
    }
    // 完成输入

    // 初始化所有机器的timetable时间线
    vector<vector<int>> machineTime(m + 1, vector<int>(n * m * 20, 0));

    // 开始逐个顺序执行
    for (int i = 0; i < m * n; i++)
    {
        int job = order[i];//找到对应任务所需机器和时间
        int mahine = machineChoose[job][jobstate[job]];
        int time = timeConsume[job][jobstate[job]];
        fillTable(machineTime, job, mahine, time, jobLastTime);
        jobstate[job]++;//做完一步更新目标工序状态
    }
    //showTable(machineTime);
    cout << findLastTime(machineTime) << endl; //输出完成时间
}

// 寻找填入位置主函数
void fillTable(vector<vector<int>> &machineTime, int job, int machine, int time, vector<int> &joblastTime)
{
    for (int i = joblastTime[job]+1; i < machineTime[machine].size(); i++) // 遍历找到放得下的位置
    {
        if (machineTime[machine][i] == 0 && enoughfill(machineTime, job, machine, time, i))
        {
            fillit(machineTime, job, machine, time, i); // 放得下就改timetable值为 job
            joblastTime[job] = i + time-1;//改完修改最后完成时间
            return;
        }
        else
        {
            continue;//不符合就继续
        }
    }
}

// 判断填不填下
bool enoughfill(const vector<vector<int>> &machineTime, int job, int machine, int time, int pos)
{
    for (int i = pos; i < pos + time; i++)
    {
        if (machineTime[machine][i] != 0)
        {
            return false;
        }
    }
    return true;
}

//填充表
void fillit(vector<vector<int>> &machineTime, int job, int machine, int time, int pos)
{
    for (int i = pos; i < pos + time; i++)
    {
        machineTime[machine][i] = job;
    }
}

//找到最后完成时间
int findLastTime(vector<vector<int>> &machineTime)
{
    int max = 0;
    for (int i = 0; i < machineTime.size(); i++)
    {
        for (int j = 0; j < machineTime[i].size(); j++)
        {
            if (machineTime[i][j] != 0)
            {
                if (j > max)
                {
                    max = j;
                }
            }
        }
    }
    return max;
}

//打印timetable 检查结果用
void showTable(vector<vector<int>> &machineTime)
{
    for (int i = 1; i < machineTime.size(); i++)
    {
        for (int j = 0; j < 15; j++)
        {
            cout << machineTime[i][j] << " ";
        }
        cout << endl;
    }
}
