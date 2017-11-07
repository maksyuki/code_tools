/***********************************************
************************************************
@接口: A + B
@时间复杂度: O (n ^ 2)

@接口: A - B
@时间复杂度: O (n ^ 2)

@接口: A * B
@时间复杂度: O (n ^ 2)

************************************************/

const int maxn = 100 + 66;

struct Matrix
{
    int row, col;
    int m[maxn][maxn];

    void clear ()
    {
        row = col = 0;
        memset (m, 0, sizeof (m));
    }

    Matrix operator + (const Matrix &b) const {
        Matrix temp;
        temp.row = row, temp.col = col;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                temp.m[i][j] = m[i][j] + b.m[i][j];

        return temp;
    }

    Matrix operator - (const Matrix &b) const {
        Matrix temp;
        temp.row = row, temp.col = col;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                temp.m[i][j] = m[i][j] - b.m[i][j];

        return temp;
    }

    Matrix operator * (const Matrix &b) const {
        Matrix temp;
        temp.clear ();
        temp.row = row, temp.col = col;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < b.col; j++)
                for (int k = 0; k < col; k++)
                    temp.m[i][j] += m[i][k] * b.m[k][j];

        return temp;
    }
};
