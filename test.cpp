#include <stdio.h>
#include <string>
#include <math.h>
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <array>
using namespace std;

float **matrixparser(string infile)
{
    ifstream fin;
    string col;
    string row;
    fin.open(infile);
    int col1;
    fin >> col1;
    int row1;
    fin >> row1;
    int leng = col1 + row1;
    float matrix[row1][col1];
    int j = 0;
    while (j < col1)
    {
        int i = 0;
        while (i < row1)
        {
            fin >> (matrix[i][j]);
            i++;
        }
        j++;
    }

    float **ma = new float *[col1];
    for (int j = 0; j < col1; j++)
    {
        ma[j] = new float[row1];
        for (int i = 0; i < row1; i++)
        {
            ma[j][i] = matrix[i][j];
        }
    }
    fin.close();
    return ma;
}
float *vectorparse(string infile)
{
    ifstream fin;
    fin.open(infile);
    int col1;
    fin >> col1;

    // converting string matrix to float
    float matrix[col1];
    for (int i = 0; i < col1; i++)
    {
        fin >> (matrix[i]);
    }
    float *arr = new float[col1];
    for (int i = 0; i < col1; i++)
    {

        arr[i] = matrix[i];
    }
    fin.close();
    return arr;
}

void matrixoutput(string outfile, float **arr, int row, int col)
{
    ofstream fo;
    fo.open(outfile);
    string a = to_string(row);
    string b = to_string(col);
    fo << b << endl;
    fo << a << endl;
    for (int j = 0; j < col; j++)
    {

        for (int i = 0; i < row; i++)
        {
            fo << arr[j][i] << endl;
        }
    }
    fo.close();
    return;
}

void vectoroutput(string outfile, float *arr, int col)
{
    ofstream fo;
    fo.open(outfile);
    string a = to_string(col);

    fo << a << endl;
    for (int j = 0; j < col; j++)
    {

        fo << arr[j] << endl;
    }
    fo.close();
    return;
}

float tanhype(float x)
{
    float x_1 = x;
    float x_2 = (0 - x);
    float a = (exp(x_1) - exp(x_2)) / (exp(x_1) + exp(x_2));
    return a;
}
float relu(float x)
{
    float x_1 = x;
    if (x > 0)
    {
        return x;
    }
    else
    {
        float b = 0;

        return b;
    }
}
float **fullyconnect(float **inputmatr, float **weight, float **bias, int inputmatrow, int inputmatrcol, int weigrow, int weicol, int biasrow, int biascol)
{
    if ((inputmatrcol == weigrow) && (inputmatrow == biasrow) && (weicol == biascol))
    {
        float **out = new float *[weicol];
        for (int j = 0; j < weicol; j++)
        {
            out[j] = new float[inputmatrow];
            for (int i = 0; i < inputmatrow; i++)
            {
                float sum = 0;
                for (int k = 0; k < inputmatrcol; k++)
                {
                    sum = sum + inputmatr[k][i] * weight[j][k];
                }
                out[j][i] = sum;
            }
        }
        float **a = new float *[weicol];
        for (int j = 0; j < weicol; j++)
        {
            a[j] = new float[inputmatrow];
            for (int i = 0; i < inputmatrow; i++)
            {
                a[j][i] = out[j][i] + bias[j][i];
            }
        }
        return a;
    }
    else
    {
        cout << "This multiplication can't take place";
        std::exit;
        return nullptr;
    }
}

float **relmat(float **input, int row, int col)
{
    int a = col;
    float **out = new float *[a];
    int b = row;
    for (int j = 0; j < a; j++)
    {
        out[j] = new float[b];
        for (int i = 0; i < b; i++)
        {
            float rela = relu(input[j][i]);

            out[j][i] = rela;
        }
    }
    return out;
}

float **tanmat(float **input, int row, int col)
{
    int a = col;
    float **out = new float *[a];
    int b = row;
    for (int j = 0; j < a; j++)
    {
        out[j] = new float[b];
        /* code */
        for (int i = 0; i < b; i++)
        {
            /* code */
            float tana = tanhype(input[j][i]);
            out[j][i] = tana;
        }
    }
    return out;
}

float *softmax1(float *vec, int col)
{
    int a = col;
    float sum = 0;
    for (int i = 0; i < a; i++)
    {
        sum = sum + exp(vec[i]);
    }
    float *out = new float[a];
    for (int i = 0; i < a; i++)
    {
        out[i] = exp(vec[i]) / sum;
    }

    return out;
}

float *sigmoid1(float *inp, int col)
{
    float *out = new float[col];
    for (int i = 0; i < col; i++)
    {

        out[i] = 1 / (1 + exp(0 - (inp[i])));
    }
    return out;
}

float **max_pool(float **inputmatrix, int stride, int row, int col)
{
    int row_count = 0;
    int col_count = 0;
    if (stride != 0)
    {

        float **outputmatrix = new float *[col / stride];
        for (int j = 0; j < col; j = j + stride)
        {
            outputmatrix[col_count] = new float[row / stride];

            row_count = 0;

            for (int i = 0; i < row; i = i + stride)
            {
                float max = inputmatrix[j][i];
                for (int k1 = j; k1 < j + stride; k1++)
                {
                    for (int k2 = i; k2 < i + stride; k2++)
                    {

                        if (max < inputmatrix[k1][k2])
                        {

                            max = inputmatrix[k1][k2];
                        }
                    }
                }

                outputmatrix[col_count][row_count] = max;

                row_count++;
            }
            col_count++;
        }

        return outputmatrix;
    }
    else
    {
        cout << "Stride can't be Zero";
        std::exit;
        return nullptr;
    }
}

float **avg_pool(float **inputmatrix, int stride, int row, int col)
{
    if (stride != 0)
    {
        int col_count = 0;
        int row_count = 0;
        float **outputmatrix = new float *[col / stride];
        for (int j = 0; j < col; j = j + stride)
        {
            outputmatrix[col_count] = new float[row / stride];
            row_count = 0;
            for (int i = 0; i < row; i = i + stride)
            {
                float sum = 0;
                float num = stride * stride;
                for (int k1 = j; k1 < j + stride; k1++)
                {
                    for (int k2 = i; k2 < i + stride; k2++)
                    {
                        sum = sum + inputmatrix[k1][k2];
                    }
                }
                outputmatrix[col_count][row_count] = sum / (num);

                row_count++;
            }
            col_count++;
        }
        return outputmatrix;
    }
    else
    {
        cout << "Stride can't be zero";
        std::exit;
        return nullptr;
    }
}

int main(int argc, char **argv)
{   
    
    if ((argc == 6) || (argc == 5))
    {
        if (argc == 6)
        {
            string op = argv[1];
            if (op.compare("fullyconnected") == 0)
            {
                string s1 = argv[2];
                string s2 = argv[3];
                string s3 = argv[4];
                string s4 = argv[5];
                float **inputmatrix = matrixparser(s1);
                float **weightmatrix = matrixparser(s2);
                float **biasmatrix = matrixparser(s3);
                ifstream fin;
                fin.open(s1);
                int icol;
                fin >> icol;
                int irow;
                fin >> irow;
                fin.close();

                fin.open(s2);
                int wcol;
                fin >> wcol;
                int wrow;
                fin >> wrow;
                fin.close();

                fin.open(s3);
                int bcol;
                fin >> bcol;
                int brow;
                fin >> brow;
                fin.close();

                float **outputmatrix = fullyconnect(inputmatrix, weightmatrix, biasmatrix, irow, icol, wrow, wcol, brow, bcol);
                matrixoutput(s4, outputmatrix, irow, wcol);
            }
            else if(op.compare("pooling") == 0)
            {
                string op2 = argv[2];
                if (op2.compare("max") == 0)
                {
                    string s1 = argv[3];
                    string s2 = argv[4];
                    string s3 = argv[5];
                    ifstream fin;
                    fin.open(s1);
                    int icol;
                    fin >> icol;
                    int irow;
                    fin >> irow;
                    fin.close();
                    float **inputmatrix = matrixparser(s1);
                    int strid = stoi(s2);
                    float **outputmatrix = max_pool(inputmatrix, strid, irow, icol);
                    matrixoutput(s3, outputmatrix, (irow / strid), (icol / strid));
                }
                else if (op2.compare("average") == 0)
                {
                    string s1 = argv[3];
                    string s2 = argv[4];
                    string s3 = argv[5];
                    ifstream fin;
                    fin.open(s1);
                    int icol;
                    fin >> icol;
                    int irow;
                    fin >> irow;
                    fin.close();
                    float **inputmatrix = matrixparser(s1);
                    int strid = stoi(s2);
                    float **outputmatrix = avg_pool(inputmatrix, strid, irow, icol);
                    matrixoutput(s3, outputmatrix, (icol / strid), (irow / strid));
                }
                else{
                    cout << "Sorry! it is average or max pooling";
                }
            }
            else{
                cout << "Sorry! I guess you want to use fullyconnected or pooling function";
            }
        }
        else if (argc == 5)
        {
            string opop = argv[1];
            if (opop.compare("activation") == 0)
            {
                string opop1 = argv[2];
                if (opop1.compare("relu") == 0)
                {
                    string s1 = argv[3];
                    string s2 = argv[4];
                    ifstream fin;
                    fin.open(s1);
                    int col;
                    fin >> col;
                    int row;
                    fin >> row;
                    fin.close();
                    float **inputmatrix = matrixparser(s1);
                    float **outputmatrix = relmat(inputmatrix, row, col);
                    matrixoutput(s2, outputmatrix, row, col);
                }
                else if (opop1.compare("tanh") == 0)
                {
                    string s1 = argv[3];
                    string s2 = argv[4];
                    ifstream fin;
                    fin.open(s1);
                    int col;
                    fin >> col;
                    int row;
                    fin >> row;
                    fin.close();
                    float **inputmatrix = matrixparser(s1);
                    float **outputmatrix = tanmat(inputmatrix, row, col);
                    matrixoutput(s2, outputmatrix, row, col);
                }
                else{
                    cout << "Sorry! It is relu or tanh";
                }
            }
            else if (opop.compare("probability") == 0)
            {
                string opop1 = argv[2];
                if (opop1.compare("softmax") == 0)
                {
                    string s1 = argv[3];
                    string s2 = argv[4];
                    ifstream fin;
                    fin.open(s1);

                    int col;
                    fin >> col;
                    fin.close();
                    float *inputmatrix = vectorparse(s1);
                    float *outputmatrix = softmax1(inputmatrix, col);
                    vectoroutput(s2, outputmatrix, col);
                }
                else if (opop1.compare("sigmoid") == 0)
                {
                    string s1 = argv[3];
                    string s2 = argv[4];
                    ifstream fin;
                    fin.open(s1);
                    int col;
                    fin >> col;
                    fin.close();
                    float *inputmatrix = vectorparse(s1);
                    float *outputmatrix = sigmoid1(inputmatrix, col);
                    vectoroutput(s2, outputmatrix, col);
                }
                else{
                    cout << "Sorry it is sigmoid or softmax function";
                }
            }
            else{
                cout << "Sorry! I guess you want to probability or an activation function";
            }
        }

        return 0;
    }
    else
    {
        cout << "Wrong input, please provide feasible input";
    }
}
