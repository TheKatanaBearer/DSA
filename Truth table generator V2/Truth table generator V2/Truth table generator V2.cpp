#include<iostream>
#include<string>
using namespace std;

int AND(int a, int b) {
    return (a == 1 && b == 1) ? 1 : 0;
}

int OR(int a, int b) {
    return (a == 0 && b == 0) ? 0 : 1;
}

int Not_op(int a) {
    return (a == 1) ? 0 : 1;
}

int imply(int a, int b) {
    return (a == 1 && b == 0) ? 0 : 1;
}

int bicond(int a, int b) {
    return (a == b) ? 1 : 0;
}

void display(const string& label, int arr[8]) {
    cout << label << ": ";
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int p[8] = { 1,1,1,0,1,0,0,0 };
    int q[8] = { 1,1,0,0,0,1,0,1 };
    int r[8] = { 1,0,0,0,1,0,1,1 };
    int r1[8]; // For intermediate results
    int r2[8]; // For final results

    string proposition;
    cout << "Enter the compound proposition kindly: " << endl;
    cout << " & for ( AND ) " << endl;
    cout << " ^ for ( OR ) " << endl;
    cout << " e for ( imply ) " << endl;
    cout << " b for (bicond ) " << endl;
    getline(cin, proposition);



    




    // Space checker in proposition
    for (int i = 0; i < proposition.length(); i++) {
        if (proposition[i] == ' ') {
            cout << "The proposition is invalid as we cannot leave a space in between." << endl;
            return 0;
        }
    }

    // Initial display before negation
    cout << "Initial values before negation:" << endl;
    display("p", p);
    display("q", q);
    display("r", r);

    // Dealing with negation first
    for (int i = 0; i < proposition.length(); i++) {
        if (i + 1 < proposition.length() && proposition[i] == '!') {
            if (proposition[i + 1] == 'p') {
                for (int j = 0; j < 8; j++) {
                    p[j] = Not_op(p[j]);
                }
            }
            else if (proposition[i + 1] == 'q') {
                for (int j = 0; j < 8; j++) {
                    q[j] = Not_op(q[j]);
                }
            }
            else {
                for (int j = 0; j < 8; j++) {
                    r[j] = Not_op(r[j]);
                }
            }
        }
    }

    // Display after negation
    cout << "\nValues after negation (if applicable):" << endl;
    display("p", p);
    display("q", q);
    display("r", r);

    cout << "\nNegation evaluation completed." << endl;









    // Now evaluating for the first operation &

    for (int i = 0; i < proposition.length(); i++) {
        if (proposition[i] == '&' && i > 0 && i < proposition.length() - 1) {

            // combo 1: p & q
            if (proposition[i - 1] == 'p' && proposition[i + 1] == 'q' || proposition[i + 2] == 'q') {
                for (int j = 0; j < 8; j++) {
                    r1[j] = AND(p[j], q[j]);
                }

                // Display the result of p & q
                cout << "p & q: ";
                for (int j = 0; j < 8; j++) {
                    cout << r1[j] << " ";
                }
                cout << endl;

                // Internal combos
                if (proposition[i + 2] == '&' || proposition[i + 3] == '&') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = AND(r1[k], r[k]); // p & q & r
                    }

                    // Display the result of p & q & r
                    cout << "p & q & r: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
                else if (proposition[i + 2] == '^' || proposition[i + 3] == '^') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = OR(r1[k], r[k]); // p & q ^ r
                    }

                    // Display the result of p & q ^ r
                    cout << "p & q ^ r: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
                else if (proposition[i + 2] == 'e' || proposition[i + 3] == 'e') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = imply(r1[k], r[k]); // p & q e r
                    }

                    // Display the result of p & q e r
                    cout << "p & q e r: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
                else if (proposition[i + 2] == 'b' || proposition[i + 3] == 'b') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = bicond(r1[k], r[k]); // p & q b r
                    }

                    // Display the result of p & q b r
                    cout << "p & q b r: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
            }

            // combo 2: q & p
            if (proposition[i - 1] == 'q' && proposition[i + 1] == 'p' || proposition[i + 2] == 'p') {
                for (int j = 0; j < 8; j++) {
                    r1[j] = AND(q[j], p[j]);
                }

                // Display the result of q & p
                cout << "q & p: ";
                for (int j = 0; j < 8; j++) {
                    cout << r1[j] << " ";
                }
                cout << endl;

                // Internal combos
                if (proposition[i + 2] == '&' || proposition[i + 3] == '&') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = AND(r1[k], r[k]); // q & p & r
                    }

                    // Display the result of q & p & r
                    cout << "q & p & r: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
                else if (proposition[i + 2] == '^' || proposition[i + 3] == '^') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = OR(r1[k], r[k]); // q & p ^ r
                    }

                    // Display the result of q & p ^ r
                    cout << "q & p ^ r: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
                else if (proposition[i + 2] == 'e' || proposition[i + 3] == 'e') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = imply(r1[k], r[k]); // q & p e r
                    }

                    // Display the result of q & p e r
                    cout << "q & p e r: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
                else if (proposition[i + 2] == 'b' || proposition[i + 3] == 'b') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = bicond(r1[k], r[k]); // q & p b r
                    }

                    // Display the result of q & p b r
                    cout << "q & p b r: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
            }

            // combo 3: p & r
            if (proposition[i - 1] == 'p' && proposition[i + 1] == 'r' || proposition[i + 2] == 'r') {
                for (int j = 0; j < 8; j++) {
                    r1[j] = AND(p[j], r[j]);
                }

                // Display the result of p & r
                cout << "p & r: ";
                for (int j = 0; j < 8; j++) {
                    cout << r1[j] << " ";
                }
                cout << endl;

                // Internal combos
                if (proposition[i + 2] == '&' || proposition[i + 3] == '&') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = AND(r1[k], q[k]); // p & r & q
                    }

                    // Display the result of p & r & q
                    cout << "p & r & q: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
                else if (proposition[i + 2] == '^' || proposition[i + 3] == '^') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = OR(r1[k], q[k]); // p & r ^ q
                    }

                    // Display the result of p & r ^ q
                    cout << "p & r ^ q: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
                else if (proposition[i + 2] == 'e' || proposition[i + 3] == 'e') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = imply(r1[k], q[k]); // p & r e q
                    }

                    // Display the result of p & r e q
                    cout << "p & r e q: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
                else if (proposition[i + 2] == 'b' || proposition[i + 3] == 'b') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = bicond(r1[k], q[k]); // p & r b q
                    }

                    // Display the result of p & r b q
                    cout << "p & r b q: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
            }

            // combo 4: r & p
            if (proposition[i - 1] == 'r' && proposition[i + 1] == 'p' || proposition[i + 2] == 'p') {
                for (int j = 0; j < 8; j++) {
                    r1[j] = AND(r[j], p[j]);
                }

                // Display the result of r & p
                cout << "r & p: ";
                for (int j = 0; j < 8; j++) {
                    cout << r1[j] << " ";
                }
                cout << endl;

                // Internal combos
                if (proposition[i + 2] == '&' || proposition[i + 3] == '&') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = AND(r1[k], q[k]); // r & p & q
                    }

                    // Display the result of r & p & q
                    cout << "r & p & q: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
                else if (proposition[i + 2] == '^' || proposition[i + 3] == '^') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = OR(r1[k], q[k]); // r & p ^ q
                    }

                    // Display the result of r & p ^ q
                    cout << "r & p ^ q: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
                else if (proposition[i + 2] == 'e' || proposition[i + 3] == 'e') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = imply(r1[k], q[k]); // r & p e q
                    }

                    // Display the result of r & p e q
                    cout << "r & p e q: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
                else if (proposition[i + 2] == 'b' || proposition[i + 3] == 'b') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = bicond(r1[k], q[k]); // r & p b q
                    }

                    // Display the result of r & p b q
                    cout << "r & p b q: ";
                    for (int k = 0; k < 8; k++) {
                        cout << r2[k] << " ";
                    }
                    cout << endl;
                    break;
                }
            }
        }
    }

        










    // Now evaluating for the second operation ^
    for (int i = 0; i < proposition.length(); i++) {
        if (i - 1 >= 0 && i + 1 < proposition.length() && proposition[i] == '^') {

            // combo 1: p ^ q
            if (proposition[i - 1] == 'p' && proposition[i + 1] == 'q' || proposition[i + 2] == 'q') {
                for (int j = 0; j < 8; j++) {
                    r1[j] = OR(p[j], q[j]); // p ^ q
                }

                // Display results for p ^ q
                std::cout << "p ^ q: ";
                for (int j = 0; j < 8; j++) {
                    std::cout << r1[j] << " ";
                }
                std::cout << std::endl;

                // Internal combos
                if (proposition[i + 2] == '^' || proposition[i + 3] == '^') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = OR(r1[k], r[k]); // p ^ q ^ r
                    }
                    std::cout << "p ^ q ^ r: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
                else if (proposition[i + 2] == 'e' || proposition[i + 3] == 'e') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = imply(r1[k], r[k]); // p ^ q e r
                    }
                    std::cout << "p ^ q e r: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
                else if (proposition[i + 2] == 'b' || proposition[i + 3] == 'b') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = bicond(r1[k], r[k]); // p ^ q b r
                    }
                    std::cout << "p ^ q b r: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
            }

            // Treating cases ending with & separately
            if (proposition[i - 1] == 'p' && proposition[i + 1] == 'q' || proposition[i + 2] == 'q' && (proposition[i + 2] == '&' || proposition[i + 3] == '&')) {
                for (int j = 0; j < 8; j++) {
                    r1[j] = AND(q[j], r[j]); // q & r
                }
                for (int k = 0; k < 8; k++) {
                    r2[k] = OR(p[k], r1[k]); // p ^ (q & r)
                }
                std::cout << "p ^ (q & r): ";
                for (int k = 0; k < 8; k++) {
                    std::cout << r2[k] << " ";
                }
                std::cout << std::endl;
                break;
            }

            // combo 2: q ^ p
            if (proposition[i - 1] == 'q' && proposition[i + 1] == 'p' || proposition[i + 2] == 'p') {
                for (int j = 0; j < 8; j++) {
                    r1[j] = OR(q[j], p[j]); // q ^ p
                }

                std::cout << "q ^ p: ";
                for (int j = 0; j < 8; j++) {
                    std::cout << r1[j] << " ";
                }
                std::cout << std::endl;

                // Internal combos
                if (proposition[i + 2] == '^' || proposition[i + 3] == '^') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = OR(r1[k], r[k]); // q ^ p ^ r
                    }
                    std::cout << "q ^ p ^ r: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
                else if (proposition[i + 2] == 'e' || proposition[i + 3] == 'e') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = imply(r1[k], r[k]); // q ^ p e r
                    }
                    std::cout << "q ^ p e r: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
                else if (proposition[i + 2] == 'b' || proposition[i + 3] == 'b') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = bicond(r1[k], r[k]); // q ^ p b r
                    }
                    std::cout << "q ^ p b r: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
            }

            // Treating cases ending with & separately for q ^ p
            if (proposition[i - 1] == 'q' && proposition[i + 1] == 'p' || proposition[i + 2] == 'p' && (proposition[i + 2] == '&' || proposition[i + 3] == '&')) {
                for (int j = 0; j < 8; j++) {
                    r1[j] = AND(p[j], r[j]); // p & r
                }
                for (int k = 0; k < 8; k++) {
                    r2[k] = OR(q[k], r1[k]); // q ^ (p & r)
                }
                std::cout << "q ^ (p & r): ";
                for (int k = 0; k < 8; k++) {
                    std::cout << r2[k] << " ";
                }
                std::cout << std::endl;
                break;
            }

            // combo 3: p ^ r
            if (proposition[i - 1] == 'p' && proposition[i + 1] == 'r' || proposition[i + 2] == 'r') {
                for (int j = 0; j < 8; j++) {
                    r1[j] = OR(p[j], r[j]); // p ^ r
                }

                std::cout << "p ^ r: ";
                for (int j = 0; j < 8; j++) {
                    std::cout << r1[j] << " ";
                }
                std::cout << std::endl;

                // Internal combos
                if (proposition[i + 2] == '^' || proposition[i + 3] == '^') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = OR(r1[k], q[k]); // p ^ r ^ q
                    }
                    std::cout << "p ^ r ^ q: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
                else if (proposition[i + 2] == 'e' || proposition[i + 3] == 'e') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = imply(r1[k], q[k]); // p ^ r e q
                    }
                    std::cout << "p ^ r e q: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
                else if (proposition[i + 2] == 'b' || proposition[i + 3] == 'b') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = bicond(r1[k], q[k]); // p ^ r b q
                    }
                    std::cout << "p ^ r b q: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
            }

            // Treating cases ending with & separately for p ^ r
            if (proposition[i - 1] == 'p' && proposition[i + 1] == 'r' || proposition[i + 2] == 'r' && (proposition[i + 2] == '&' || proposition[i + 3] == '&')) {
                for (int j = 0; j < 8; j++) {
                    r1[j] = AND(q[j], r[j]); // q & r
                }
                for (int k = 0; k < 8; k++) {
                    r2[k] = OR(p[k], r1[k]); // p ^ (q & r)
                }
                std::cout << "p ^ (q & r): ";
                for (int k = 0; k < 8; k++) {
                    std::cout << r2[k] << " ";
                }
                std::cout << std::endl;
                break;
            }

            // combo 4: q ^ r
            if (proposition[i - 1] == 'q' && proposition[i + 1] == 'r' || proposition[i + 2] == 'r') {
                for (int j = 0; j < 8; j++) {
                    r1[j] = OR(q[j], r[j]); // q ^ r
                }

                std::cout << "q ^ r: ";
                for (int j = 0; j < 8; j++) {
                    std::cout << r1[j] << " ";
                }
                std::cout << std::endl;

                // Internal combos
                if (proposition[i + 2] == '^' || proposition[i + 3] == '^') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = OR(p[k], r1[k]); // q ^ r ^ p
                    }
                    std::cout << "q ^ r ^ p: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
                else if (proposition[i + 2] == 'e' || proposition[i + 3] == 'e') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = imply(p[k], r1[k]); // q ^ r e p
                    }
                    std::cout << "q ^ r e p: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
                else if (proposition[i + 2] == 'b' || proposition[i + 3] == 'b') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = bicond(p[k], r1[k]); // q ^ r b p
                    }
                    std::cout << "q ^ r b p: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
            }

            // combo 5: r ^ p
            if (proposition[i - 1] == 'r' && proposition[i + 1] == 'p' || proposition[i + 2] == 'p') {
                for (int j = 0; j < 8; j++) {
                    r1[j] = OR(r[j], p[j]); // r ^ p
                }

                std::cout << "r ^ p: ";
                for (int j = 0; j < 8; j++) {
                    std::cout << r1[j] << " ";
                }
                std::cout << std::endl;

                // Internal combos
                if (proposition[i + 2] == '^' || proposition[i + 3] == '^') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = OR(r1[k], q[k]); // r ^ p ^ q
                    }
                    std::cout << "r ^ p ^ q: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
                else if (proposition[i + 2] == 'e' || proposition[i + 3] == 'e') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = imply(r1[k], q[k]); // r ^ p e q
                    }
                    std::cout << "r ^ p e q: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
                else if (proposition[i + 2] == 'b' || proposition[i + 3] == 'b') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = bicond(r1[k], q[k]); // r ^ p b q
                    }
                    std::cout << "r ^ p b q: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
            }

            // combo 6: r ^ q
            if (proposition[i - 1] == 'r' && proposition[i + 1] == 'q' || proposition[i + 2] == 'q') {
                for (int j = 0; j < 8; j++) {
                    r1[j] = OR(r[j], q[j]); // r ^ q
                }

                std::cout << "r ^ q: ";
                for (int j = 0; j < 8; j++) {
                    std::cout << r1[j] << " ";
                }
                std::cout << std::endl;

                // Internal combos
                if (proposition[i + 2] == '^' || proposition[i + 3] == '^') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = OR(p[k], r1[k]); // r ^ q ^ p
                    }
                    std::cout << "r ^ q ^ p: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
                else if (proposition[i + 2] == 'e' || proposition[i + 3] == 'e') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = imply(p[k], r1[k]); // r ^ q e p
                    }
                    std::cout << "r ^ q e p: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
                else if (proposition[i + 2] == 'b' || proposition[i + 3] == 'b') {
                    for (int k = 0; k < 8; k++) {
                        r2[k] = bicond(p[k], r1[k]); // r ^ q b p
                    }
                    std::cout << "r ^ q b p: ";
                    for (int k = 0; k < 8; k++) {
                        std::cout << r2[k] << " ";
                    }
                    std::cout << std::endl;
                    break;
                }
            }

        }










        // Evaluating for the third operation e
        for (int i = 0; i < proposition.length(); i++) {
            if (proposition[i] == '&' && i > 0 && i < proposition.length() - 1) {
                // combo 1: p e q
                if ((proposition[i - 1] == 'p' && proposition[i + 1] == 'q') || (i + 2 < proposition.length() && proposition[i + 2] == 'q')) {
                    for (int j = 0; j < 8; j++) {
                        r1[j] = imply(p[j], q[j]); // p e q
                    }
                    std::cout << "p e q: ";
                    for (int j = 0; j < 8; j++) {
                        std::cout << r1[j] << " ";
                    }
                    std::cout << std::endl;

                    // Internal combos
                    if ((i + 2 < proposition.length() && proposition[i + 2] == 'e') || (i + 3 < proposition.length() && proposition[i + 3] == 'e')) {
                        for (int k = 0; k < 8; k++) {
                            r2[k] = imply(r1[k], r[k]); // (p e q) e r
                        }
                        std::cout << "(p e q) e r: ";
                        for (int k = 0; k < 8; k++) {
                            std::cout << r2[k] << " ";
                        }
                        std::cout << std::endl;
                    }

                    if ((i + 2 < proposition.length() && proposition[i + 2] == 'b') || (i + 3 < proposition.length() && proposition[i + 3] == 'b')) {
                        for (int k = 0; k < 8; k++) {
                            r2[k] = bicond(r1[k], r[k]); // (p e q) b r
                        }
                        std::cout << "(p e q) b r: ";
                        for (int k = 0; k < 8; k++) {
                            std::cout << r2[k] << " ";
                        }
                        std::cout << std::endl;
                    }
                    break; // Exit loop after processing this combo
                }

                // combo 2: q e p
                if ((proposition[i - 1] == 'q' && proposition[i + 1] == 'p') || (i + 2 < proposition.length() && proposition[i + 2] == 'p')) {
                    for (int j = 0; j < 8; j++) {
                        r1[j] = imply(q[j], p[j]); // q e p
                    }
                    std::cout << "q e p: ";
                    for (int j = 0; j < 8; j++) {
                        std::cout << r1[j] << " ";
                    }
                    std::cout << std::endl;

                    // Internal combos
                    if ((i + 2 < proposition.length() && proposition[i + 2] == 'e') || (i + 3 < proposition.length() && proposition[i + 3] == 'e')) {
                        for (int k = 0; k < 8; k++) {
                            r2[k] = imply(r1[k], r[k]); // (q e p) e r
                        }
                        std::cout << "(q e p) e r: ";
                        for (int k = 0; k < 8; k++) {
                            std::cout << r2[k] << " ";
                        }
                        std::cout << std::endl;
                    }

                    if ((i + 2 < proposition.length() && proposition[i + 2] == 'b') || (i + 3 < proposition.length() && proposition[i + 3] == 'b')) {
                        for (int k = 0; k < 8; k++) {
                            r2[k] = bicond(r1[k], r[k]); // (q e p) b r
                        }
                        std::cout << "(q e p) b r: ";
                        for (int k = 0; k < 8; k++) {
                            std::cout << r2[k] << " ";
                        }
                        std::cout << std::endl;
                    }
                    break; // Exit loop after processing this combo
                }

                // combo 3: p e r
                if ((proposition[i - 1] == 'p' && proposition[i + 1] == 'r') || (i + 2 < proposition.length() && proposition[i + 2] == 'r')) {
                    for (int j = 0; j < 8; j++) {
                        r1[j] = imply(p[j], r[j]); // p e r
                    }
                    std::cout << "p e r: ";
                    for (int j = 0; j < 8; j++) {
                        std::cout << r1[j] << " ";
                    }
                    std::cout << std::endl;

                    // Internal combos
                    if ((i + 2 < proposition.length() && proposition[i + 2] == 'e') || (i + 3 < proposition.length() && proposition[i + 3] == 'e')) {
                        for (int k = 0; k < 8; k++) {
                            r2[k] = imply(r1[k], q[k]); // (p e r) e q
                        }
                        std::cout << "(p e r) e q: ";
                        for (int k = 0; k < 8; k++) {
                            std::cout << r2[k] << " ";
                        }
                        std::cout << std::endl;
                    }

                    if ((i + 2 < proposition.length() && proposition[i + 2] == 'b') || (i + 3 < proposition.length() && proposition[i + 3] == 'b')) {
                        for (int k = 0; k < 8; k++) {
                            r2[k] = bicond(r1[k], q[k]); // (p e r) b q
                        }
                        std::cout << "(p e r) b q: ";
                        for (int k = 0; k < 8; k++) {
                            std::cout << r2[k] << " ";
                        }
                        std::cout << std::endl;
                    }
                    break; // Exit loop after processing this combo
                }

                // combo 4: r e p
                if ((proposition[i - 1] == 'r' && proposition[i + 1] == 'p') || (i + 2 < proposition.length() && proposition[i + 2] == 'p')) {
                    for (int j = 0; j < 8; j++) {
                        r1[j] = imply(r[j], p[j]); // r e p
                    }
                    std::cout << "r e p: ";
                    for (int j = 0; j < 8; j++) {
                        std::cout << r1[j] << " ";
                    }
                    std::cout << std::endl;

                    // Internal combos
                    if ((i + 2 < proposition.length() && proposition[i + 2] == 'e') || (i + 3 < proposition.length() && proposition[i + 3] == 'e')) {
                        for (int k = 0; k < 8; k++) {
                            r2[k] = imply(r1[k], q[k]); // (r e p) e q
                        }
                        std::cout << "(r e p) e q: ";
                        for (int k = 0; k < 8; k++) {
                            std::cout << r2[k] << " ";
                        }
                        std::cout << std::endl;
                    }

                    if ((i + 2 < proposition.length() && proposition[i + 2] == 'b') || (i + 3 < proposition.length() && proposition[i + 3] == 'b')) {
                        for (int k = 0; k < 8; k++) {
                            r2[k] = bicond(r1[k], q[k]); // (r e p) b q
                        }
                        std::cout << "(r e p) b q: ";
                        for (int k = 0; k < 8; k++) {
                            std::cout << r2[k] << " ";
                        }
                        std::cout << std::endl;
                    }
                    break; // Exit loop after processing this combo
                }

                // combo 5: q e r
                if ((proposition[i - 1] == 'q' && proposition[i + 1] == 'r') || (i + 2 < proposition.length() && proposition[i + 2] == 'r')) {
                    for (int j = 0; j < 8; j++) {
                        r1[j] = imply(q[j], r[j]); // q e r
                    }
                    std::cout << "q e r: ";
                    for (int j = 0; j < 8; j++) {
                        std::cout << r1[j] << " ";
                    }
                    std::cout << std::endl;

                    // Internal combos
                    if ((i + 2 < proposition.length() && proposition[i + 2] == 'e') || (i + 3 < proposition.length() && proposition[i + 3] == 'e')) {
                        for (int k = 0; k < 8; k++) {
                            r2[k] = imply(r1[k], p[k]); // (q e r) e p
                        }
                        std::cout << "(q e r) e p: ";
                        for (int k = 0; k < 8; k++) {
                            std::cout << r2[k] << " ";
                        }
                        std::cout << std::endl;
                    }

                    if ((i + 2 < proposition.length() && proposition[i + 2] == 'b') || (i + 3 < proposition.length() && proposition[i + 3] == 'b')) {
                        for (int k = 0; k < 8; k++) {
                            r2[k] = bicond(r1[k], p[k]); // (q e r) b p
                        }
                        std::cout << "(q e r) b p: ";
                        for (int k = 0; k < 8; k++) {
                            std::cout << r2[k] << " ";
                        }
                        std::cout << std::endl;
                    }
                    break; // Exit loop after processing this combo
                }

                // combo 6: r e q
                if ((proposition[i - 1] == 'r' && proposition[i + 1] == 'q') || (i + 2 < proposition.length() && proposition[i + 2] == 'q')) {
                    for (int j = 0; j < 8; j++) {
                        r1[j] = imply(r[j], q[j]); // r e q
                    }
                    std::cout << "r e q: ";
                    for (int j = 0; j < 8; j++) {
                        std::cout << r1[j] << " ";
                    }
                    std::cout << std::endl;

                    // Internal combos
                    if ((i + 2 < proposition.length() && proposition[i + 2] == 'e') || (i + 3 < proposition.length() && proposition[i + 3] == 'e')) {
                        for (int k = 0; k < 8; k++) {
                            r2[k] = imply(r1[k], p[k]); // (r e q) e p
                        }
                        std::cout << "(r e q) e p: ";
                        for (int k = 0; k < 8; k++) {
                            std::cout << r2[k] << " ";
                        }
                        std::cout << std::endl;
                    }

                    if ((i + 2 < proposition.length() && proposition[i + 2] == 'b') || (i + 3 < proposition.length() && proposition[i + 3] == 'b')) {
                        for (int k = 0; k < 8; k++) {
                            r2[k] = bicond(r1[k], p[k]); // (r e q) b p
                        }
                        std::cout << "(r e q) b p: ";
                        for (int k = 0; k < 8; k++) {
                            std::cout << r2[k] << " ";
                        }
                        std::cout << std::endl;
                    }
                    break; // Exit loop after processing this combo
                }
            }


                    //for the 4th operation b

                    for (int i = 0; i < proposition.length(); i++) {
                        if (proposition[i] == '&' && i > 0 && i < proposition.length() - 1) {

                            // Combo 1: p b q
                            if (proposition[i - 1] == 'p' && proposition[i + 1] == 'q' || proposition[i + 2] == 'q') {
                                for (int j = 0; j < 8; j++) {
                                    r1[j] = bicond(p[j], q[j]); // p b q
                                }
                                cout << "p b q results: ";
                                for (int j = 0; j < 8; j++) {
                                    cout << r1[j] << endl; // Display each result on a new line
                                }

                                // Case for p b q b r
                                if (proposition[i + 2] == 'b' || proposition[i + 3] == 'b') {
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(r1[k], r[k]); // (p b q) b r
                                    }
                                    cout << "(p b q) b r results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }

                                // Case for p b (q e r)
                                if (proposition[i + 2] == 'e' || proposition[i + 3] == 'e') {
                                    for (int k = 0; k < 8; k++) {
                                        r1[k] = imply(q[k], r[k]); // q e r
                                    }
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(p[k], r1[k]); // p b (q e r)
                                    }
                                    cout << "p b (q e r) results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }

                                // Case for p b (q & r)
                                if (proposition[i + 2] == '&' || proposition[i + 3] == '&') {
                                    for (int j = 0; j < 8; j++) {
                                        r1[j] = AND(q[j], r[j]); // q & r
                                    }
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(p[k], r1[k]); // p b (q & r)
                                    }
                                    cout << "p b (q & r) results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }

                                // Case for p b (q ^ r)
                                if (proposition[i + 2] == '^' || proposition[i + 3] == '^') {
                                    for (int j = 0; j < 8; j++) {
                                        r1[j] = OR(q[j], r[j]); // q ^ r
                                    }
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(p[k], r1[k]); // p b (q ^ r)
                                    }
                                    cout << "p b (q ^ r) results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }
                            }

                            // Combo 2: q b p
                            if (proposition[i - 1] == 'q' && proposition[i + 1] == 'p' || proposition[i + 2] == 'p') {
                                for (int j = 0; j < 8; j++) {
                                    r1[j] = bicond(q[j], p[j]); // q b p
                                }
                                cout << "q b p results: ";
                                for (int j = 0; j < 8; j++) {
                                    cout << r1[j] << endl; // Display each result on a new line
                                }

                                // Case for q b p b r
                                if (proposition[i + 2] == 'b' || proposition[i + 3] == 'b') {
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(r1[k], r[k]); // (q b p) b r
                                    }
                                    cout << "(q b p) b r results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }

                                // Case for q b (p e r)
                                if (proposition[i + 2] == 'e' || proposition[i + 3] == 'e') {
                                    for (int k = 0; k < 8; k++) {
                                        r1[k] = imply(p[k], r[k]); // p e r
                                    }
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(q[k], r1[k]); // q b (p e r)
                                    }
                                    cout << "q b (p e r) results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }

                                // Case for q b (p & r)
                                if (proposition[i + 2] == '&' || proposition[i + 3] == '&') {
                                    for (int j = 0; j < 8; j++) {
                                        r1[j] = AND(p[j], r[j]); // p & r
                                    }
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(q[k], r1[k]); // q b (p & r)
                                    }
                                    cout << "q b (p & r) results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }

                                // Case for q b (p ^ r)
                                if (proposition[i + 2] == '^' || proposition[i + 3] == '^') {
                                    for (int j = 0; j < 8; j++) {
                                        r1[j] = OR(p[j], r[j]); // p ^ r
                                    }
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(q[k], r1[k]); // q b (p ^ r)
                                    }
                                    cout << "q b (p ^ r) results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }
                            }

                            // Combo 3: p b r
                            if (proposition[i - 1] == 'p' && proposition[i + 1] == 'r' || proposition[i + 2] == 'r') {
                                for (int j = 0; j < 8; j++) {
                                    r1[j] = bicond(p[j], r[j]); // p b r
                                }
                                cout << "p b r results: ";
                                for (int j = 0; j < 8; j++) {
                                    cout << r1[j] << endl; // Display each result on a new line
                                }

                                // Case for p b r b q
                                if (proposition[i + 2] == 'b' || proposition[i + 3] == 'b') {
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(r1[k], q[k]); // (p b r) b q
                                    }
                                    cout << "(p b r) b q results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }

                                // Case for p b (r e q)
                                if (proposition[i + 2] == 'e' || proposition[i + 3] == 'e') {
                                    for (int k = 0; k < 8; k++) {
                                        r1[k] = imply(r[k], q[k]); // r e q
                                    }
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(p[k], r1[k]); // p b (r e q)
                                    }
                                    cout << "p b (r e q) results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }

                                // Case for p b (r & q)
                                if (proposition[i + 2] == '&' || proposition[i + 3] == '&') {
                                    for (int j = 0; j < 8; j++) {
                                        r1[j] = AND(r[j], q[j]); // r & q
                                    }
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(p[k], r1[k]); // p b (r & q)
                                    }
                                    cout << "p b (r & q) results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }

                                // Case for p b (r ^ q)
                                if (proposition[i + 2] == '^' || proposition[i + 3] == '^') {
                                    for (int j = 0; j < 8; j++) {
                                        r1[j] = OR(r[j], q[j]); // r ^ q
                                    }
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(p[k], r1[k]); // p b (r ^ q)
                                    }
                                    cout << "p b (r ^ q) results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }
                            }

                            // Combo 4: r b p
                            if (proposition[i - 1] == 'r' && proposition[i + 1] == 'p' || proposition[i + 2] == 'p') {
                                for (int j = 0; j < 8; j++) {
                                    r1[j] = bicond(r[j], p[j]); // r b p
                                }
                                cout << "r b p results: ";
                                for (int j = 0; j < 8; j++) {
                                    cout << r1[j] << endl; // Display each result on a new line
                                }

                                // Case for r b p b q
                                if (proposition[i + 2] == 'b' || proposition[i + 3] == 'b') {
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(r1[k], q[k]); // (r b p) b q
                                    }
                                    cout << "(r b p) b q results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }

                                // Case for r b (p e q)
                                if (proposition[i + 2] == 'e' || proposition[i + 3] == 'e') {
                                    for (int k = 0; k < 8; k++) {
                                        r1[k] = imply(p[k], q[k]); // p e q
                                    }
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(r[k], r1[k]); // r b (p e q)
                                    }
                                    cout << "r b (p e q) results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }

                                // Case for r b (q & p)
                                if (proposition[i + 2] == '&' || proposition[i + 3] == '&') {
                                    for (int j = 0; j < 8; j++) {
                                        r1[j] = AND(q[j], p[j]); // q & p
                                    }
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(r[k], r1[k]); // r b (q & p)
                                    }
                                    cout << "r b (q & p) results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }

                                // Case for r b (q ^ p)
                                if (proposition[i + 2] == '^' || proposition[i + 3] == '^') {
                                    for (int j = 0; j < 8; j++) {
                                        r1[j] = OR(q[j], p[j]); // q ^ p
                                    }
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(r[k], r1[k]); // r b (q ^ p)
                                    }
                                    cout << "r b (q ^ p) results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }
                            }

                            // Combo 5: q b r
                            if (proposition[i - 1] == 'q' && proposition[i + 1] == 'r' || proposition[i + 2] == 'r') {
                                for (int j = 0; j < 8; j++) {
                                    r1[j] = bicond(q[j], r[j]); // q b r
                                }
                                cout << "q b r results: ";
                                for (int j = 0; j < 8; j++) {
                                    cout << r1[j] << endl; // Display each result on a new line
                                }

                                // Case for q b r b p
                                if (proposition[i + 2] == 'b' || proposition[i + 3] == 'b') {
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(r1[k], p[k]); // (q b r) b p
                                    }
                                    cout << "(q b r) b p results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }

                                // Case for q b (r e p)
                                if (proposition[i + 2] == 'e' || proposition[i + 3] == 'e') {
                                    for (int k = 0; k < 8; k++) {
                                        r1[k] = imply(r[k], p[k]); // r e p
                                    }
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(q[k], r1[k]); // q b (r e p)
                                    }
                                    cout << "q b (r e p) results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }

                                // Case for q b (r & p)
                                if (proposition[i + 2] == '&' || proposition[i + 3] == '&') {
                                    for (int j = 0; j < 8; j++) {
                                        r1[j] = AND(r[j], p[j]); // r & p
                                    }
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(q[k], r1[k]); // q b (r & p)
                                    }
                                    cout << "q b (r & p) results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }

                                // Case for q b (r ^ p)
                                if (proposition[i + 2] == '^' || proposition[i + 3] == '^') {
                                    for (int j = 0; j < 8; j++) {
                                        r1[j] = OR(r[j], p[j]); // r ^ p
                                    }
                                    for (int k = 0; k < 8; k++) {
                                        r2[k] = bicond(q[k], r1[k]); // q b (r ^ p)
                                    }
                                    cout << "q b (r ^ p) results: ";
                                    for (int k = 0; k < 8; k++) {
                                        cout << r2[k] << endl; // Display each result on a new line
                                    }
                                }
                            }
                        }
                    }





                }



            }
        }
    

