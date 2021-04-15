#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

// Кубик, из которого состоит Кубик Рубик
class CubePiece
{
private:
    // Грани кубика. Видимые грани имеют цвет, а невидимые - чёрные
    string up_plane_piece = "black";
    string down_plane_piece = "black";
    string left_plane_piece = "black";
    string right_plane_piece = "black";
    string front_plane_piece = "black";
    string back_plane_piece = "black";
public:
    // Конструкторы
    CubePiece() = default;
    CubePiece(string up, string down, string left, string right, string front, string back)
    {
        this->up_plane_piece = up;
        this->down_plane_piece = down;
        this->left_plane_piece = left;
        this->right_plane_piece = right;
        this->front_plane_piece = front;
        this->back_plane_piece = back;
    }
    // Операторы
    void operator = (CubePiece cube_piece)
    {
        this->up_plane_piece = cube_piece.up_plane_piece;
        this->down_plane_piece = cube_piece.down_plane_piece;
        this->left_plane_piece = cube_piece.left_plane_piece;
        this->right_plane_piece = cube_piece.right_plane_piece;
        this->front_plane_piece = cube_piece.front_plane_piece;
        this->back_plane_piece = cube_piece.back_plane_piece;
    }

    // Гетеры
    string getUpPlane_piece() const
    {
        return this->up_plane_piece;
    }
    string getDownPlane_piece() const
    {
        return this->down_plane_piece;
    }
    string getLeftPlane_piece() const
    {
        return this->left_plane_piece;
    }
    string getRightPlane_piece() const
    {
        return this->right_plane_piece;
    }
    string getFrontPlane_piece() const
    {
        return this->front_plane_piece;
    }
    string getBackPlane_piece() const
    {
        return this->back_plane_piece;
    }

    // Сеттеры
    void setUpPlane_piece(string color)
    {
        this->up_plane_piece = color;
    }
    void setDownPlane_piece(string color)
    {
        this->down_plane_piece = color;
    }
    void setLeftPlane_piece(string color)
    {
        this->left_plane_piece = color;
    }
    void setRightPlane_piece(string color)
    {
        this->right_plane_piece = color;
    }
    void setFrontPlane_piece(string color)
    {
        this->front_plane_piece = color;
    }
    void setBackPlane_piece(string color)
    {
        this->back_plane_piece = color;
    }
};

// Кубик Рубик
class CubeRubik
{
private:
    // Мы храним сам куб в виде трёхмерного вектора ( Координаты (1, 1, 1) имеет центральный кубик,
    // координаты (0, 0, 0) имеет левый нижний задний кубик, координаты (2, 2, 2) имеет правый верхний передний кубик)
    vector<vector<vector<CubePiece>>> arr;
    // Грани кубика. В скобочках цвет при собранном положении Кубика Рубика
    vector<vector<CubePiece*>> UpPlane; // (белый)
    vector<vector<CubePiece*>> DownPlane; // (жёлтый)
    vector<vector<CubePiece*>> LeftPlane; // (красный)
    vector<vector<CubePiece*>> RightPlane; // (оранжевый)
    vector<vector<CubePiece*>> FrontPlane; // (зелёный)
    vector<vector<CubePiece*>> BackPlane; // (синий)

    // Функция наелась и спит (ломает программу)
    void ResizeCubeVector()
    {

//        this->UpPlane.resize(3, vector<CubePiece*>(3));
//        this->DownPlane.resize(3, vector<CubePiece*>(3));
//        this->LeftPlane.resize(3, vector<CubePiece*>(3));
//        this->RightPlane.resize(3, vector<CubePiece*>(3));
//        this->FrontPlane.resize(3, vector<CubePiece*>(3));
//        this->BackPlane.resize(3, vector<CubePiece*>(3));
    }

    // Распределение кубиков из трёхмерного вектора по граням
    void PushInPlaneVector()
    {
        for (int i = 0; i < 3; i++)
        {
            vector<CubePiece*> temp;
            for (int j = 0; j < 3; j++)
            {
                temp.push_back(&arr[i][2][j]);
            }
            UpPlane.push_back(temp);
        }
        for (int i = 0; i < 3; i++)
        {
            vector<CubePiece*> temp;
            for (int j = 0; j < 3; j++)
            {
                temp.push_back(&arr[i][0][j]);
            }
            DownPlane.push_back(temp);
        }
        for (int i = 0; i < 3; i++)
        {
            vector<CubePiece*> temp;
            for (int j = 0; j < 3; j++)
            {
                temp.push_back(&arr[0][i][j]);
            }
            LeftPlane.push_back(temp);
        }
        for (int i = 0; i < 3; i++)
        {
            vector<CubePiece*> temp;
            for (int j = 0; j < 3; j++)
            {
                temp.push_back(&arr[2][i][j]);
            }
            RightPlane.push_back(temp);
        }
        for (int i = 0; i < 3; i++)
        {
            vector<CubePiece*> temp;
            for (int j = 0; j < 3; j++)
            {
                temp.push_back(&arr[i][j][2]);
            }
            FrontPlane.push_back(temp);
        }
        for (int i = 0; i < 3; i++)
        {
            vector<CubePiece*> temp;
            for (int j = 0; j < 3; j++)
            {
                temp.push_back(&arr[i][j][0]);
            }
            BackPlane.push_back(temp);
        }
    }
public:

    // Конструктор
    CubeRubik()
    {
        this->arr.resize(3, vector<vector<CubePiece>>(3, vector<CubePiece>(3)));
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    arr[i][j][k] = CubePiece();
        PushInPlaneVector();
        CreateCubeRubik();
        PrintCubeRubik();
    }

    // Функция для расскраскки граней изночальными цветами
    void CreateCubeRubik()
    {
        arr[1][1][1] = CubePiece();
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                UpPlane[i][j]->setUpPlane_piece("white");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                DownPlane[i][j]->setDownPlane_piece("yellow");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                LeftPlane[i][j]->setLeftPlane_piece("red");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                RightPlane[i][j]->setRightPlane_piece("orange");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                FrontPlane[i][j]->setFrontPlane_piece("green");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                BackPlane[i][j]->setBackPlane_piece("blue");
    }

    // Геттеры граней
    vector<vector<CubePiece*>> getUpPlane() const
    {
        return this->UpPlane;
    }
    vector<vector<CubePiece*>> getDownPlane() const
    {
        return this->DownPlane;
    }
    vector<vector<CubePiece*>> getLeftPlane() const
    {
        return this->LeftPlane;
    }
    vector<vector<CubePiece*>> getRightPlane() const
    {
        return this->RightPlane;
    }
    vector<vector<CubePiece*>> getFrontPlane() const
    {
        return this->FrontPlane;
    }
    vector<vector<CubePiece*>> getBackPlane() const
    {
        return this->BackPlane;
    }

    // Повороты
    void LeftPlaneRotate()
    {

    }
    void Rotate(vector<vector<CubePiece*>> plane, char where)
    {
        string up_color_2_0 = plane[2][0]->getUpPlane_piece();
        string up_color_2_1 = plane[2][1]->getUpPlane_piece();
        string up_color_2_2 = plane[2][2]->getUpPlane_piece();

        string front_color_2_2 = plane[2][2]->getFrontPlane_piece();
        string front_color_1_2 = plane[1][2]->getFrontPlane_piece();
        string front_color_0_2 = plane[0][2]->getFrontPlane_piece();

        string down_color_0_2 = plane[0][2]->getDownPlane_piece();
        string down_color_0_1 = plane[0][1]->getDownPlane_piece();
        string down_color_0_0 = plane[0][0]->getDownPlane_piece();

        string back_color_0_0 = plane[0][0]->getBackPlane_piece();
        string back_color_1_0 = plane[1][0]->getBackPlane_piece();
        string back_color_2_0 = plane[2][0]->getBackPlane_piece();

        plane[2][0]->setUpPlane_piece(back_color_0_0);
        plane[2][1]->setUpPlane_piece(back_color_1_0);
        plane[2][2]->setUpPlane_piece(back_color_2_0);

        plane[2][2]->setFrontPlane_piece(up_color_2_0);
        plane[1][2]->setFrontPlane_piece(up_color_2_1);
        plane[0][2]->setFrontPlane_piece(up_color_2_2);

        plane[0][2]->setDownPlane_piece(front_color_2_2);
        plane[0][1]->setDownPlane_piece(front_color_1_2);
        plane[0][0]->setDownPlane_piece(front_color_0_2);

        plane[0][0]->setBackPlane_piece(down_color_0_2);
        plane[1][0]->setBackPlane_piece(down_color_0_1);
        plane[2][0]->setBackPlane_piece(down_color_0_0);
    }

    // Вывод
    // вывод всех цветов кусочка Кубика Рубика
    void PrintCubePiece(vector<vector<CubePiece*>> plane, int i, int j)
    {
        cout << plane[i][j]->getUpPlane_piece() << "    ";
        cout << plane[i][j]->getDownPlane_piece() << "    ";
        cout << plane[i][j]->getLeftPlane_piece() << "    ";
        cout << plane[i][j]->getRightPlane_piece() << "    ";
        cout << plane[i][j]->getFrontPlane_piece() << "    ";
        cout << plane[i][j]->getBackPlane_piece() << endl;
    }
    // вывод всех цветов кусочков одной грани Кубика Рубика
    void PrintAllCubePiece(vector<vector<CubePiece*>> plane)
    {
        cout << "       Up      Down     Left    Right    Front    Back" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "[" << i << ", " << j << "] ";
                PrintCubePiece(plane, i, j);
            }
        }
    }
    // Вывод развёртки в консоль
    void PrintCubeRubik()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "\t\t\t\t\t\t";
            for (int j = 0; j < 3; j++)
                cout << UpPlane[i][j]->getUpPlane_piece() << " ";
            cout << endl;
        }

        for (int j = 0; j < 3; j++)
            cout << RightPlane[0][j]->getRightPlane_piece() << " ";
        cout << " | ";

        for (int j = 0; j < 3; j++)
            cout << FrontPlane[0][j]->getFrontPlane_piece() << " ";
        cout << " | ";

        for (int j = 0; j < 3; j++)
            cout << LeftPlane[0][j]->getLeftPlane_piece() << " ";
        cout << " | ";

        for (int j = 0; j < 3; j++)
            cout << BackPlane[0][j]->getBackPlane_piece() << " ";
        cout << endl;

        for (int j = 0; j < 3; j++)
            cout << RightPlane[1][j]->getRightPlane_piece() << " ";
        cout << " | ";

        for (int j = 0; j < 3; j++)
            cout << FrontPlane[1][j]->getFrontPlane_piece() << " ";
        cout << " | ";

        for (int j = 0; j < 3; j++)
            cout << LeftPlane[1][j]->getLeftPlane_piece() << " ";
        cout << " | ";

        for (int j = 0; j < 3; j++)
            cout << BackPlane[1][j]->getBackPlane_piece() << " ";
        cout << endl;

        for (int j = 0; j < 3; j++)
            cout << RightPlane[2][j]->getRightPlane_piece() << " ";
        cout << " | ";

        for (int j = 0; j < 3; j++)
            cout << FrontPlane[2][j]->getFrontPlane_piece() << " ";
        cout << " | ";

        for (int j = 0; j < 3; j++)
            cout << LeftPlane[2][j]->getLeftPlane_piece() << " ";
        cout << " | ";

        for (int j = 0; j < 3; j++)
            cout << BackPlane[2][j]->getBackPlane_piece() << " ";
        cout << endl;

        for (int i = 0; i < 3; i++)
        {
            cout << "\t\t\t\t\t   ";
            for (int j = 0; j < 3; j++)
                cout << DownPlane[i][j]->getDownPlane_piece() << " ";
            cout << endl;
        }
        cout << endl;
    }
    void PrintCubeRubik1()
    {
        cout << "UpPlane" << endl;
        for (int i = 2; i >= 0; i--)
        {
            for (int j = 2; j >= 0; j--)
                cout << UpPlane[i][j]->getUpPlane_piece() << " ";
            cout << endl;
        }
        cout << "DownPlane" << endl;
        for (int i = 2; i >= 0; i--)
        {
            for (int j = 2; j >= 0; j--)
                cout << DownPlane[i][j]->getDownPlane_piece() << " ";
            cout << endl;
        }
        cout << "LeftPlane" << endl;
        for (int i = 2; i >= 0; i--)
        {
            for (int j = 2; j >= 0; j--)
                cout << LeftPlane[i][j]->getLeftPlane_piece() << " ";
            cout << endl;
        }
        cout << "RightPlane" << endl;
        for (int i = 2; i >= 0; i--)
        {
            for (int j = 2; j >= 0; j--)
                cout << RightPlane[i][j]->getRightPlane_piece() << " ";
            cout << endl;
        }
        cout << "FrontPlane" << endl;
        for (int i = 2; i >= 0; i--)
        {
            for (int j = 2; j >= 0; j--)
                cout << FrontPlane[i][j]->getFrontPlane_piece() << " ";
            cout << endl;
        }
        cout << "BackPlane" << endl;
        for (int i = 2; i >= 0; i--)
        {
            for (int j = 2; j >= 0; j--)
                cout << BackPlane[i][j]->getBackPlane_piece() << " ";
            cout << endl;
        }
        cout << endl;
    }
    // Вывод развёртки в файл
    void PrintInFileCubeRubik()
    {
        for (int i = 0; i < 3; i++)
        {
            fout << "\t\t\t\t\t\t";
            for (int j = 0; j < 3; j++)
                fout << UpPlane[i][j]->getUpPlane_piece() << " ";
            fout << endl;
        }

        for (int j = 0; j < 3; j++)
            fout << RightPlane[0][j]->getRightPlane_piece() << " ";
        fout << " | ";

        for (int j = 0; j < 3; j++)
            fout << FrontPlane[0][j]->getFrontPlane_piece() << " ";
        fout << " | ";

        for (int j = 0; j < 3; j++)
            fout << LeftPlane[0][j]->getLeftPlane_piece() << " ";
        fout << " | ";

        for (int j = 0; j < 3; j++)
            fout << BackPlane[0][j]->getBackPlane_piece() << " ";
        fout << endl;

        for (int j = 0; j < 3; j++)
            fout << RightPlane[1][j]->getRightPlane_piece() << " ";
        fout << " | ";

        for (int j = 0; j < 3; j++)
            fout << FrontPlane[1][j]->getFrontPlane_piece() << " ";
        fout << " | ";

        for (int j = 0; j < 3; j++)
            fout << LeftPlane[1][j]->getLeftPlane_piece() << " ";
        fout << " | ";

        for (int j = 0; j < 3; j++)
            fout << BackPlane[1][j]->getBackPlane_piece() << " ";
        fout << endl;

        for (int j = 0; j < 3; j++)
            fout << RightPlane[2][j]->getRightPlane_piece() << " ";
        fout << " | ";

        for (int j = 0; j < 3; j++)
            fout << FrontPlane[2][j]->getFrontPlane_piece() << " ";
        fout << " | ";

        for (int j = 0; j < 3; j++)
            fout << LeftPlane[2][j]->getLeftPlane_piece() << " ";
        fout << " | ";

        for (int j = 0; j < 3; j++)
            fout << BackPlane[2][j]->getBackPlane_piece() << " ";
        fout << endl;

        for (int i = 0; i < 3; i++)
        {
            fout << "\t\t\t\t\t   ";
            for (int j = 0; j < 3; j++)
                fout << DownPlane[i][j]->getDownPlane_piece() << " ";
            fout << endl;
        }
        fout << endl;
    }

};

int main()
{
    CubeRubik cube;
//    cube.PrintAllCubePiece(cube.getLeftPlane());
//    cube.PrintAllCubePiece(cube.getFrontPlane());
//    cube.PrintAllCubePiece(cube.getDownPlane());
//    cube.PrintAllCubePiece(cube.getBackPlane());
    cube.Rotate(cube.getLeftPlane(), '-');
    cube.PrintCubeRubik1();
//    cube.PrintAllCubePiece(cube.getLeftPlane());
//    cube.PrintAllCubePiece(cube.getFrontPlane());
//    cube.PrintAllCubePiece(cube.getDownPlane());
//    cube.PrintAllCubePiece(cube.getBackPlane());
    cube.PrintInFileCubeRubik();
    return 0;
}
