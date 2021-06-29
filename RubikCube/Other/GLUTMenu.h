#ifndef RUBIKCUBE_GLUTMENU_H
#define RUBIKCUBE_GLUTMENU_H

// menu with actions in window
void createGLUTMenus() {
    glutCreateMenu(processMenu);

    glutAddMenuEntry("Read Cube from file", 1);
    glutAddMenuEntry("Print Cube in console", 2);
    glutAddMenuEntry("Print Cube in file", 3);
    glutAddMenuEntry("Shuffle", 4);
    glutAddMenuEntry("Find Solution", 5);
    glutAddMenuEntry("Print solving information in console", 6);
    glutAddMenuEntry("Solve Cube using only left and up rotates", 7);
    glutAddMenuEntry("Solve Cube using only right and up rotates", 8);
    glutAddMenuEntry("Create solved Cube", 9);
    glutAddMenuEntry("Start Cube-solver-MachineGun", 10);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Actions in menu
void processMenu(int action) {
    try {
        switch (action) {
            case 1:
                Cube.ReadRubikCube(inputStream);
                break;

            case 2:
                cout << "\nCube's unfolding:\n\n";
                Cube.PrintRubikCube();
                break;

            case 3:
                outputStream << "\nCube's unfolding:\n\n";
                Cube.PrintRubikCube(outputStream);
                break;

            case 4:
                Cube.Shuffle(false);
                // Suffle cube and print unfolding
                cout << "\n\nCube's unfolding after shuffling:\n\n";
                Cube.PrintRubikCube();
                break;

            case 5:
                Cube.FindSolution();
                outputStream << "\n\nCube's unfolding after solving:\n\n";
                Cube.PrintRubikCube(outputStream);
                break;

            case 6:
                Cube.PrintCubeInfo();
                break;

            case 7:
                Cube.LeftUpSolver(false);
                break;

            case 8:
                Cube.RightUpSolver(false);
                break;

            case 9:
                Cube.CreateRubikCube();
                Cube.setVisualCube(CUBE_SIZE, colors);
                break;

            case 10:
                // Trying to solve AmountOfTests (in CubeSettings) cubes
                SolveCubeArray(AMOUNT_OF_TESTS, false); // (10kk ~ 3 hours), (1kk ~ 20 minutes), (100k ~ 1,5 minutes)
                break;

            default:
                break;
        }

    } catch (exception &e) {
        cout << e.what();
    }
}


#endif //RUBIKCUBE_GLUTMENU_H
