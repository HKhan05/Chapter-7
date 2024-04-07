// pharmacyProds.txt (Input file)

A1010 Strawberry Shampoo 7.99
C3940 Liquid Vitamins 10.12
C9304 Diaper Rash Cream 6.58
C9854 Cleansing Wipes 4.15
D2901 Nutritional Chocolate Shake 8.00
F3743 Flashlight 6.21
F4484 Dryer Clothes 4.20
G3384 Smile Toothpaste 3.93
H1192 Bath Bench 51.53
H2324 Blood Pressure Monitor 34.61
Z3445 Rejuvenating Serum 19.74

==============================

int main() {
    ifstream dataIn;
    string line;
    int index;
    string code;
    string name;
    double price;

    dataIn.open("pharmacyProds.txt");
    if (dataIn.fail()) {
        cout << "** File Not Found **";
        return 1;
    } else {
        while (getline(dataIn, line)) {
            index = line.find(" ");
            if (index == string::npos) {
                continue; // skip this line if no space is found
            }
            code = line.substr(0, index);
            line = line.substr(index + 1);
            index = line.find(" ");
            if (index == string::npos) {
                continue; // skip this line if no space is found
            }
            name = line.substr(0, index);
            price = stod(line.substr(index + 1));
            if (code.at(0) == 'C' || code.at(0) == 'D' || code.at(0) == 'H') {
                cout << code << " " << name << " " << price << " -- Qualified Expense" << endl;
            } else {
                cout << code << " " << name << " " << price << endl;
            }
        }
    }
    return 0;
}