#include "bits/stdc++.h"

constexpr double eps = 1e-6;

class Simplex
{
private:
    int rows, cols;
    std::vector<std::vector<double>> A; // coeff of constraints
    std::vector<double> B; // constants
    std::vector<double> C; // coeff of objective function

    double maximum;
    bool isUnbounded;

public:
    Simplex(std::vector<std::vector<double>> matrix, std::vector<double> b, std::vector<double> c)
    {
        maximum = 0;
        isUnbounded = false;
        rows = matrix.size();
        cols = matrix[0].size();

        A = matrix;
        B = b;
        C = c;
    }

    bool simplexAlgorithmCalculataion()
    {
        if (checkOptimality() == true)
            return true;

        // Find the column which has the pivot. 
        // The least coefficient of the objective function(C array).
        int pivotColumn = findPivotColumn();

        if (isUnbounded == true)
        {
            std::cout << "Error unbounded\n";
            return true;
        }

        // Find the row with the pivot value. 
        // The least value item's row in the B array
        int pivotRow = findPivotRow(pivotColumn);
        pivotAndUpdateRow(pivotRow, pivotColumn);
        return false;
    }

    bool checkOptimality()
    {
        for (int i = 0; i < C.size(); i++)
        {
            double value = C[i];
            if (value < 0)
                return false;
        }
        
        display();
        return true;
    }

    void pivotAndUpdateRow(int pivotRow, int pivotColumn)
    {

        double pivotVal = A[pivotRow][pivotColumn]; // Gets the pivot value
        std::vector<double> pivotRowVals(cols); // The column with the pivot
        std::vector<double> pivotColVals(rows); // The row with the pivot
        std::vector<double> nrow(cols); // The row after processing the pivot value

        maximum = maximum - (C[pivotColumn] * (B[pivotRow] / pivotVal));
        for (int i = 0; i < cols; i++)
            pivotRowVals[i] = A[pivotRow][i];
        for (int j = 0; j < rows; j++)
            pivotColVals[j] = A[j][pivotColumn];

        for (int k = 0; k < cols; k++)
            nrow[k] = pivotRowVals[k] / pivotVal;

        B[pivotRow] = B[pivotRow] / pivotVal;

        for (int m = 0; m < rows; m++)
        {
            if (m == pivotRow)
                continue;
            
            for (int p = 0; p < cols; p++)
            {
                double multiplyValue = pivotColVals[m];
                A[m][p] = A[m][p] - (multiplyValue * nrow[p]);
            }
        }

        // Process the values of the B array
        for (int i = 0; i < B.size(); i++)
        {
            if (i != pivotRow)
            {

                double multiplyValue = pivotColVals[i];
                B[i] = B[i] - (multiplyValue * B[pivotRow]);
            }
        }
        double multiplyValue = C[pivotColumn];
        for (int i = 0; i < C.size(); i++)
            C[i] -= multiplyValue * nrow[i];

        A[pivotRow] = nrow;
    }

    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                std::cout << A[i][j] << " \n"[j == cols - 1];
        }
    }

    int findPivotColumn()
    {
        int pos = 0;
        double min = C[0];

        for (int i = 1; i < std::size(C); i++)
        {
            if (C[i] < min)
            {
                min = C[i];
                pos = i;
            }
        }

        return pos;
    }

    int findPivotRow(int pivotColumn)
    {
        std::vector<double> positiveValues(rows);
        std::vector<double> result(rows);
        int negativeValueCount = 0;

        for (int i = 0; i < rows; i++)
        {
            if (A[i][pivotColumn] > 0)
                positiveValues[i] = A[i][pivotColumn];
            else
            {
                positiveValues[i] = 0;
                negativeValueCount += 1;
            }
        }

        if (negativeValueCount == rows)
            isUnbounded = true;
        else
        {
            for (int i = 0; i < rows; i++)
            {
                double value = positiveValues[i];
                if (value > 0)
                    result[i] = B[i] / value;
                else
                    result[i] = 0;
            }
        }
        
        double min = std::numeric_limits<double>::max();
        int pos = 0;
        for (int i = 0; i < std::size(result); i++)
        {
            if (result[i] > 0)
            {
                if (result[i] < min)
                {
                    min = result[i];
                    pos = i;
                }
            }
        }

        return pos;
    }

    void CalculateSimplex()
    {
        bool end = false;

        std::cout << "initial array(Not optimal)\n";
        display();

        std::cout << "\n";
        std::cout << "final array(Optimal solution)\n";

        while (!end)
        {
            bool result = simplexAlgorithmCalculataion();
            if (result == true)
                end = true;
        }
        
        std::cout << "Answers for the Constraints of variables\n";

        for (int i = 0; i < A.size(); i++)
        {
            int count0 = 0;
            int index = 0;
            for (int j = 0; j < rows; j++)
            {
                if (std::abs(A[j][i]) < eps)
                    count0 += 1;
                else if (A[j][i] == 1)
                    index = j;
            }

            if (count0 == rows - 1)
                std::cout << "variable" << index + 1 << ": " << B[index] << "\n";
            else
                std::cout << "variable" << index + 1 << ": " << 0 << "\n";
        }

        std::cout << "" << "\n";
        std::cout << "maximum value: " << maximum << "\n";
    }
};

int main()
{
    std::vector<double> c = {-6, -5, -4, 0, 0, 0}; 
    std::vector<double> b = {180, 300, 240}; 

    std::vector<std::vector<double>> a = {
                     {2, 1, 1, 1, 0, 0},
                     {1, 3, 2, 0, 1, 0},
                     {2, 1, 2, 0, 0, 1}};

    Simplex simplex(a, b, c);
    simplex.CalculateSimplex();

    return 0;
}