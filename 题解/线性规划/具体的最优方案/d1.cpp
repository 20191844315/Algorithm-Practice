#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

/*
 * Simplex 类：求解标准型线性规划（最大化）
 *
 *   maximize:     c^T x
 *   subject to:   A x <= b
 *                 x >= 0
 *
 * 使用松弛变量将不等式转为等式，然后使用单纯形法解。
 */
class Simplex {
public:
    int n;  // 约束个数
    int m;  // 变量总数（含 slack）
    vector<int> B, N;              // 基变量集合 B，非基变量集合 N
    vector<vector<double>> a;      // 单纯形表 tableau

    /**
     * 构造函数
     * A: m×n 的约束系数矩阵（每行对应一个限制）
     * b: m 维向量（右端项）
     * c: n 维向量（目标函数）
     *
     * 自动添加 m 个松弛变量，使矩阵变为：
     * A | I | b
     */
    Simplex(const vector<vector<double>>& A, const vector<double>& b,
            const vector<double>& c) {
        n = (int)A.size();          // 限制个数
        int orig = (int)A[0].size(); // 原始变量个数

        // tableau 大小：(n + 1) 行, (orig + n + 1) 列（含 slack 和 RHS）
        a.assign(n + 1, vector<double>(orig + n + 1, 0.0));

        // ---------- 构造单纯形表 ----------
        // 前 n 行是约束
        for (int i = 0; i < n; i++) {
            // 原始变量系数
            for (int j = 0; j < orig; j++)
                a[i][j] = A[i][j];

            // slack 变量
            a[i][orig + i] = 1.0;

            // 右端项
            a[i][orig + n] = b[i];
        }

        // 最后一行目标函数（只填 c，slack 为 0）
        for (int j = 0; j < orig; j++)
            a[n][j] = c[j];

        // ---------- 初始化变量列表 ----------
        B.resize(n);           // 基变量：初始是 slack
        N.resize(orig + n);    // 非基变量：初始是所有原始变量 + slack

        for (int i = 0; i < n; i++)
            B[i] = orig + i;   // slack 变量

        for (int j = 0; j < orig + n; j++)
            N[j] = j;

        m = orig + n; // 总变量 = 原始变量 + slack
    }

    /**
     * pivot 操作：使 a[r][c] 成为主元
     * 更新整张单纯形表，交换基变量与非基变量
     */
    void pivot(int r, int c) {
        double inv = 1.0 / a[r][c];

        // 行 r 归一化，使 pivot = 1
        for (int j = 0; j <= m; j++)
            if (j != c) a[r][j] *= inv;
        a[r][c] = inv;

        // 消元：让其他行的该列为 0
        for (int i = 0; i <= n; i++)
            if (i != r) {
                double factor = a[i][c];
                if (fabs(factor) > 0) {
                    for (int j = 0; j <= m; j++)
                        if (j != c) a[i][j] -= factor * a[r][j];
                    a[i][c] = -factor * a[r][c];
                }
            }

        // pivot 后交换基变量和非基变量
        swap(B[r], N[c]);
    }

    /**
     * 求解线性规划
     * origVar: 原始变量数量（结果只取前 origVar 个）
     */
    pair<double, vector<double>> solve(int origVar) {
        while (true) {
            int enter = -1;

            // 在目标行中寻找正系数的变量（最大化）
            for (int j = 0; j < m; j++) {
                if (a[n][j] > EPS) {
                    enter = j;
                    break;
                }
            }

            if (enter == -1)
                break; // 找不到正系数 → 达到最优解

            // 最小比值法选择离开基变量
            double best = 1e100;
            int leave = -1;

            for (int i = 0; i < n; i++) {
                if (a[i][enter] > EPS) {
                    double ratio = a[i][m] / a[i][enter];
                    if (ratio < best - 1e-15) {
                        best = ratio;
                        leave = i;
                    }
                }
            }

            if (leave == -1) {
                // 无界
                return {numeric_limits<double>::infinity(), {}};
            }

            pivot(leave, enter);
        }

        // ---------- 读取原始变量解 ----------
        vector<double> x(origVar, 0.0);
        for (int i = 0; i < n; i++) {
            if (B[i] < origVar)
                x[B[i]] = a[i][m];
        }

        double opt = a[n][m];
        return {opt, x};
    }
};

int main() {

    int n, m;
    while(cin>>n>>m){
        vector<double> profit(n);
        vector<double> invest(m);
        vector<vector<double>> cost(m, vector<double>(n));
        for(int i=0;i<n;i++){
            cin>>profit[i];
        }
        
        for(int j=0;j<m;j++){
            cin>>invest[j];
        }
        
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                cin>>cost[j][i];
            }
        }
        Simplex simplex(cost, invest, profit);
        // 求解
        auto result = simplex.solve(n);
        vector<double> x = result.second;

        // 输出格式
        cout.setf(std::ios::fixed);
        cout << setprecision(8);

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            double v = x[i];
            if (fabs(v) < 1e-10) v = 0; // 微小误差设为 0
            cout << v;
        }
        cout << "\n";

    }

    
    return 0;
}
