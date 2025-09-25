// Description
// 我们的Loy，会分别在 6 级，11 级，16 级的时候习得她的 1 级，2 级，3 级大招。学长们并不知道Loy的等级，变矮光线的效果是释放若干道光线（不同等级释放数量不同），每道光线会使其中一个学长变矮300cm，释放光线的数量与技能等级关系如下：

// 等级 1 – 释放 4 道光线；
// 等级 2 – 释放 7 道光线；
//  等级 3 – 释放 10 道光线。
//  而当Loy拥有了“黑照”这件装备后，她的技能将会被加强，释放变矮光线的数量会增加。 加强后的技能效果如下：

//  等级 1 – 释放 5 道光线；
//  等级 2 – 释放 8 道光线；
//  等级 3 – 释放 12 道光线。
//  Loy犹如天神下凡，面对5个学长，开始放变矮光线（当然如果Loy的等级没有达到习得变矮光线的等级，她将放不了变矮光线），当学长的身高 <= 0，学长就会羞愧而死。所以，大家都想知道Loy能弄死几个学长。
//     Input
// 一个整数 T，表示有多少组测试数据。
//             接下来是 T 组数据，每组数据第一行有两个整数 L(1 <= L <= 25) ，K(0 <= K <= 1) ，其中L为Loy此时的等级， K 为 0 时表示Loy没有“黑照”，为 1 时表示Loy有“黑照”。
//     接下来 5 行，每行有一个整数 Xi(1 <= Xi <= 10 ^ 8) ，代表每个学长的身高（cm）， 数据保证学长身高单调递增。
//     output
//     每组数据之间有一个空行；
//     如果Loy弄死了零个学长，输出 "none" ；
//     如果Loy弄死了一个学长，输出 "first blood" ；
//     如果Loy弄死了二个学长，输出 "double kill" ；
//     如果Loy弄死了三个学长，输出 "triple kill" ；
//     如果Loy弄死了四个学长，输出 "ultra kill" ；
//     如果Loy弄死了五个学长，输出 "rampage"。

#include <stdio.h>
void skill_level(const int level, int *skill);
int ray_count(const int skill, const int K);
void kill_report(const int kill);
int main()
{
    int T, skill = 0;
    int *skill_p = &skill;
    scanf(" %d", &T);
    while (T--)
    {
        // 输入数据
        int level, K = 0, RAY = 0, kill = 0;
        scanf("%d%d", &level, &K);
        long long enemy[5];
        for (int i = 0; i < 5; i++)
        {
            scanf(" %lld", &enemy[i]);
        }
        skill_level(level, skill_p);
        RAY = ray_count(skill, K);
        int damage = RAY * 300;
        // 击杀人数计算
        for (int i = 0; i < 5; i++)
        {
            while (enemy[i] > 0 && damage > 0)
            {
                damage -= 300;
                enemy[i] -= 300;
            }
            if (enemy[i] <= 0)
            {
                kill++;
            }
        }
        kill_report(kill);
    }
}

// 计算技能等级
void skill_level(const int level, int *skill)
{
    if (level >= 16)
    {
        *skill = 3;
    }
    else if (level >= 11)
    {
        *skill = 2;
    }
    else if (level >= 6)
    {
        *skill = 1;
    }
    else
    {
        *skill = 0;
    }
}
// 计算光线数量
int ray_count(const int skill, const int K)
{
    int ray = 0;
    switch (skill)
    {
    case 0:
        ray = 0;
        break;
    case 1:
        ray = 4;
        break;
    case 2:
        ray = 7;
        break;
    case 3:
        ray = 10;
        break;
    }
    if (K == 1)
    {
        switch (skill)
        {
        case 0:
            break;
        case 1:
            ray += 1;
            break;
        case 2:
            ray += 1;
            break;
        case 3:
            ray += 2;
            break;
        }
    }
    return ray;
}
// 显示击杀播报
void kill_report(const int kill)
{
    switch (kill)
    {
    case 0:
        printf("none");
        break;
    case 1:
        printf("first blood");
        break;
    case 2:
        printf("double kill");
        break;
    case 3:
        printf("triple kill");
        break;
    case 4:
        printf("ultra kill");
        break;
    case 5:
        printf("rampage");
        break;
    }
    printf("\n\n");
}