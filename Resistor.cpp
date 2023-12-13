#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

// 'Resistor' is the parent class. It holds the common variables and functions,
// which we will need through out the whole program. We defined the common
// functionalities in this class, so that we don't have to write them again and
// again in the child classes.
class Resistor {
protected:
  // all of the needed variables or "Data members"
  double resistance = 0,       // total resistance
      current = 0,             // total current
      voltage = 0;             // supply voltage
  double resistorsArray[1000]; // array of resistance of resistors
  int n;                       // number of resistors

public:
  // member function for inputting the number of resistors and their values
  void inputResistors() {
    // getting input of number of resistors in variable 'n'
    cout << "Enter the number of resistors: ";
    cin >> n;
    cout << endl << endl;

    // getting input of the values of resistors in array named
    // 'resistorsArray[]' like this: R1 = 10, R2 = 20, R3 = 30, R4 = 40, R5 = 50
    // array 'resistorsArray[]' is defined in the protected section of this
    // class loop is running until 'n', where n is the number of resistors
    for (int i = 0; i < n; i++) {
      cout << "Enter R" << i + 1 << ": ";
      cin >> resistorsArray[i];
    }

    // getting input of supply voltage in variable 'voltage' from the user
    cout << endl << "Enter supply voltage: ";
    cin >> voltage;
    cout << endl;
  }

  // member function for printing out the equivalent resistance and current
  void outputEquivalentResistance() {
    cout << endl;
    cout << endl;
    // if resistance is greater than 1000, then it will print the value in
    // kilo-ohm unit, else ohm
    cout << "=========================================" << endl;
    if (resistance >= 1000) {
      cout << "Total resistance : " << setprecision(1) << resistance / 1000
           << " k-ohm" << endl;
    } else {
      cout << "Total resistance : " << fixed << setprecision(1) << resistance
           << " ohm" << endl;
      cout << "=========================================" << endl;
    }

    /* if voltage is greater than 0, it means user want to find the current
     * also. So, this 'if statement' will print the current if voltage is
     * greater than 0 */

    if (voltage > 0) {
      cout << "Total current: " << fixed << setprecision(1)
           << voltage / resistance << " A" << endl;
      cout << "=========================================" << endl;
    }
    cout << endl;
    cout << endl;

    /* resetting the values of resistance, voltage and current to 0, because
     * these variables are globals values and used by many child classes. If
     * it's not reset, then the values will be added up in the next child class
     * which will produce wrong output */
    resistance = 0;
    voltage = 0;
    current = 0;
  }
};

/* Child class "Series" is inheriting the properties of parent class "Resistor"
more specifically, it is inheriting the 'resistance' variable for summing up
the equivalent resistance and 'resistorsArray[]' array for storing the values
of resistors. like resistorsArray[]={10,20,30,40,50} */

class Series : public Resistor {
public:
  // member function for calculating the equivalent resistance in a series
  // circuit
  void calcSeries() {
    // loop is used for summing up the values of resistors which are stored in
    // the array 'resistorsArray[]' loop is running until 'n', where n is the
    // number of resistors
    for (int i = 0; i < n; i++) {
      resistance += resistorsArray[i];
    }
  }
};

// Child class "Parallel" is inheriting the properties of parent class
// "Resistor"
// more specifically, it is inheriting the 'resistance' variable for summing up
// the equivalent resistance and 'resistorsArray[]' array for storing the values
// of resistors. like resistorsArray[]={10,20,30,40,50}
class Parallel : public Resistor {
public:
  // member function 'calcParallel' for calculating the equivalent resistance in
  // a parallel circuit
  void calcParallel() {
    // loop is used for summing up the values of resistors which are stored in
    // the array 'resistorsArray[]' loop is running until 'n', where n is the
    // number of resistors
    for (int i = 0; i < n; i++) {
      resistance += 1 / resistorsArray[i];
    }
    resistance = 1 / resistance;
  }
};

class SeriesParallel : public Resistor {
public:
  void inputResistors() {
    resistance = 0;
    int a;
    double temp1, temp2;
    cout << "Enter the number of resistors: " << endl;
    cin >> a;
    cout << endl;
    cout << "Enter R1 : ";
    cin >> temp1;
    cout << endl;
    for (int i = 0; i < a - 1; i++) {
      int choice;
      cout << "In between connection: " << endl;
      cout << "1. Series" << endl;
      cout << "2. Parallel" << endl;
      cin >> choice;
      cout << endl;
      if (choice == 1) {
        cout << "Enter R" << i + 2 << " : ";
        cin >> temp2;
        cout << endl;
        resistance = temp1 + temp2;
      } else if (choice == 2) {
        cout << "Enter R" << i + 2 << " : ";
        cin >> temp2;
        cout << endl;
        resistance = 1 / ((1 / temp1) + (1 / temp2));
      } else {
        cout << "Invalid input. Try again." << endl << endl;
        i--;
        continue;
      }
      temp1 = resistance;
    }
    cout << endl << "Enter supply voltage: ";
    cin >> voltage;
    cout << endl;
  }
};

class Color : public Resistor {
public:
  double arr[4];
  void setColorCodes() {
    for (size_t i = 0; i < 4; i++) {
      cout << "=========================================" << endl;
      cout << "Enter the color code of band " << i + 1 << ": " << endl;
      cout << "=========================================" << endl;
      cout << endl;
      cout << 0 << ". Black" << endl;
      cout << 1 << ". Brown" << endl;
      cout << 2 << ". Red" << endl;
      cout << 3 << ". Orange" << endl;
      cout << 4 << ". Yellow" << endl;
      cout << 5 << ". Green" << endl;
      cout << 6 << ". Blue" << endl;
      cout << 7 << ". Violet" << endl;
      cout << 8 << ". Grey" << endl;
      cout << 9 << ". White" << endl;
      cout << 10 << ". Gold" << endl;
      cout << 11 << ". Silver" << endl;
      cout << 12 << ". No color" << endl;
      cout << endl;
      int choice;
      cin >> choice;
      cout << "Option selected: " << choice << endl;
      cout << endl;
      arr[i] = choice;
    }
  }
  void getResistance() {
    if (arr[2] == 10) {
      arr[2] = -1;
    } else if (arr[2] == 11) {
      arr[2] = -2;
    }
    if (arr[3] == 10) {
      arr[3] = 5;
    } else if (arr[3] == 11) {
      arr[3] = 10;
    } else if (arr[3] == 12) {
      arr[3] = 20;
    }
    resistance = (arr[0] * 10 + arr[1]) * pow(10, arr[2]);
  }
};

int main() {
  Series ser;
  Parallel par;
  SeriesParallel serpar;
  Color col;
  int n = 1;
  while (1) {
    int choice;
    cout << "=========================================" << endl;
    cout << "Calculate total Resistance & Current in : " << endl << endl;
    cout << "  1. Series Circuit" << endl;
    cout << "  2. Parallel Circuit" << endl;
    cout << "  3. Series-Parallel Circuit" << endl;
    cout << "  4. Resistance from color code" << endl << endl;
    cout << "0. Exit" << endl;
    cout << "=========================================" << endl;

    cin >> choice;
    system("cls");
    cout << endl;
    switch (choice) {

    case 1:
      cout << "Option selected : 1. Series" << endl << endl;
      ser.inputResistors();
      ser.calcSeries();
      ser.outputEquivalentResistance();
      break;

    case 2:
      cout << "Option selected : 2. Parallel" << endl << endl;
      par.inputResistors();
      par.calcParallel();
      par.outputEquivalentResistance();
      break;

    case 3:
      cout << "Option selected : 3. Series-Parallel" << endl << endl;
      serpar.inputResistors();
      serpar.outputEquivalentResistance();
      break;

    case 4:
      cout << "Option selected : 4. Color" << endl << endl;
      col.setColorCodes();
      col.getResistance();
      col.outputEquivalentResistance();
      break;

    case 0:
      exit(1);
      break;

    default:
      cout << "Invalid choice";
      cout << endl;
      cout << endl;
      break;
    }
  }
}
